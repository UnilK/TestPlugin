/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"
#include "PluginProcessor.h"

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

    testbtn1.setClickingTogglesState (true);
    testbtn2.setClickingTogglesState (true);

    addAndMakeVisible(&testbtn1);
    addAndMakeVisible(&testbtn2);
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
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void TestPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    testbtn1.setBounds (40, 40, 200, 40);
    testbtn2.setBounds (40, 100, 200, 40);
}
