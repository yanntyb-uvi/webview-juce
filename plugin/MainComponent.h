#pragma once
#include <juce_gui_extra/juce_gui_extra.h>

class MainComponent : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override;

    void resized() override
    {
        browser.setBounds(getLocalBounds());
    }


private:
    juce::WebBrowserComponent browser{
        juce::WebBrowserComponent::Options{}
            .withBackend(juce::WebBrowserComponent::Options::Backend::webview2)
            .withNativeIntegrationEnabled()
            .withNativeFunction("ping", [](auto args, auto complete)
            {
                complete("Pong !");
            })
    };
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
