#include "MainComponent.h"

MainComponent::MainComponent()
{
    // Configuration du label
    message.setText("Salut je suis ici", juce::dontSendNotification);
    message.setJustificationType(juce::Justification::centred);
    message.setColour(juce::Label::textColourId, juce::Colours::black);
    addAndMakeVisible(message);


    setSize(400, 300);
}

MainComponent::~MainComponent()
{
}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::white);
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    message.setBounds(area.removeFromTop(100));
    testButton.setBounds(area.reduced(50).removeFromTop(30));
}
