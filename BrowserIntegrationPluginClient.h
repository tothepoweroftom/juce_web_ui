/**
 BrowserIntegrationPluginClient is intended as a base class for a JUCE
 PluginEditor which wants to communicate with a web UI inside a
 BrowserComponent.

 It takes a reference to the plugin's AudioProcessorValueTreeState, and
 takes care of synchronising state changes to JS and handling state changes
 from JS.
 */
#pragma once

namespace webui
{
namespace BrowserIntegration
{
    class BrowserIntegrationPluginClient : public BrowserIntegrationClient
    {
    public:
        BrowserIntegrationPluginClient (BrowserIntegration& browserIntegration,
                                        juce::AudioProcessorValueTreeState& parameterValueTree,
                                        juce::String pluginEditorFilePath,
                                        juce::String clientName = "Plugin");

        void setupBrowserPluginIntegration();

    protected:
        juce::AudioProcessorValueTreeState& parameterValueTree;
        BrowserValueTreeSynchroniser valueTreeSynchroniser;

        juce::File pluginEditorSourceFile;

        void sendParameterMetadata();
        void writeParameterConfigForTs (juce::Array<juce::var> parameterInfos);
    };
}
}
