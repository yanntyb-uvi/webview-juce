#include "MainComponent.h"

MainComponent::MainComponent()
{
    addAndMakeVisible(webBrowser);
    // const juce::File file = juce::File::getCurrentWorkingDirectory().getChildFile("front/index.html");
    // webBrowser.goToURL("file://" + file.getFullPathName());
    webBrowser.goToURL("http://localhost:5173/");
    webBrowser.setAlwaysOnTop(true);
}

MainComponent::~MainComponent() {}
