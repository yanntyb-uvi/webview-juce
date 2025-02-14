#pragma once
#include <juce_gui_extra/juce_gui_extra.h>

class MainComponent : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void resized() override
    {
        webBrowser.setBounds(getLocalBounds());
    }


private:
    juce::WebBrowserComponent webBrowser;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
