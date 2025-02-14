#include "MainComponent.h"

MainComponent::MainComponent()
{
    addAndMakeVisible(browser);
    // const juce::File file = juce::File::getCurrentWorkingDirectory().getChildFile("front/index.html");
    // browser.goToURL("file://" + file.getFullPathName());
    browser.goToURL("http://localhost:5173/");
    browser.setAlwaysOnTop(true);
    browser.setSize(400, 500);

}

MainComponent::~MainComponent() {}
