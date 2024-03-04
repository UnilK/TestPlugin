#include "Graph.h"

#include "Palette.h"

Graph::Graph(){

}

Graph::~Graph(){

}
 
void Graph::paint (juce::Graphics &g){
    auto c = juce::Colour(0x33, palette.bg.getRed(), palette.bg.getGreen(), palette.bg.getBlue());
    g.fillAll(palette.red);
}

void Graph::resized(){

}
