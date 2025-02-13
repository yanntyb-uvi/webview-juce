#include <juce_core/juce_core.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include "MainComponent.h"

class SimpleApplication : public juce::JUCEApplication
{
public:
    const juce::String getApplicationName() override { return "Simple JUCE App"; }
    const juce::String getApplicationVersion() override { return "1.0.0"; }

    void initialise(const juce::String&) override
    {
        mainWindow.reset(new MainWindow(getApplicationName()));
    }

    void shutdown() override
    {
        mainWindow = nullptr;
    }

    class MainWindow : public juce::DocumentWindow
    {
    public:
        MainWindow(juce::String name)
           : DocumentWindow(name,
               juce::Desktop::getInstance().getDefaultLookAndFeel()
               .findColour(juce::ResizableWindow::backgroundColourId),
               DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar(true);
            setContentOwned(new MainComponent(), true);
            setResizable(true, true);
            centreWithSize(getWidth(), getHeight());

            // Configuration Always on Top
            setAlwaysOnTop(true);

            // Option supplémentaire pour s'assurer que la fenêtre reste visible
            setBroughtToFrontOnMouseClick(true);

            setVisible(true);
            setSize(400, 500);
        }

        void closeButtonPressed() override
        {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }
    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION(SimpleApplication)