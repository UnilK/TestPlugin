/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"
#include "PluginProcessor.h"
#include "Palette.h"

//==============================================================================
TestPluginAudioProcessorEditor::TestPluginAudioProcessorEditor (TestPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (1200, 800);
    setResizable(true, true);

    testbtn1.setRadioGroupId(123);
    testbtn2.setRadioGroupId(123);

    testbtn1.onClick = [this]{ updateToggleState(&testbtn1, "Test 1"); };
    testbtn2.onClick = [this]{ updateToggleState(&testbtn2, "Test 2"); };

    testbtn1.setClickingTogglesState(true);
    testbtn2.setClickingTogglesState(true);

    addAndMakeVisible(&testbtn1);
    addAndMakeVisible(&testbtn2);
    addAndMakeVisible(&graph);
}

TestPluginAudioProcessorEditor::~TestPluginAudioProcessorEditor()
{
}

//==============================================================================

void TestPluginAudioProcessorEditor::updateToggleState(juce::Button *btn, juce::String name){

    auto state = btn->getToggleState();
    juce::String stateString    = state ? "ON" : "OFF";
    juce::String selectedString = state ? " (selected)" : "";

    juce::Logger::outputDebugString (name + " Button changed to " + stateString);
    btn->setButtonText (name + selectedString);
}

void TestPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(palette.bg);

    g.setColour (palette.red);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void TestPluginAudioProcessorEditor::resized()
{
    juce::FlexBox fb0, fb1, fb2;

    using juce::FlexBox;
    using juce::FlexItem;

    fb0.flexDirection = FlexBox::Direction::column;
    fb0.items.add(FlexItem(fb1).withMinHeight(50).withMaxHeight(50).withFlex(1, 1, 0));
    fb0.items.add(FlexItem(fb2).withFlex(1, 1, 0));

    const auto buttons = {&testbtn1, &testbtn2};

    for (auto* b : buttons){
        fb1.items.add(FlexItem(*b).withFlex(1, 1, 0));
    }

    fb2.items.add(FlexItem(graph).withFlex(1, 1, 0));

    fb0.performLayout(getLocalBounds());
}
