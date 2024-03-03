#pragma once

#include <JuceHeader.h>

class Graph : public juce::Component
{
public:

    Graph();
    ~Graph();
 
    void paint (juce::Graphics&) override;
    void resized() override;
 
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Graph)
};