#pragma once

#include <JuceHeader.h>

struct Palette {
    juce::Colour bg, lbg;
    juce::Colour red, lred;
    juce::Colour green, lgreen;
    juce::Colour yellow, lyellow;
    juce::Colour blue, lblue;
    juce::Colour violet, lviolet;
    juce::Colour cyan, lcyan;
    juce::Colour white, lwhite;
};

extern Palette palette;
