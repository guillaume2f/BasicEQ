/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
BasicEq2AudioProcessor::BasicEq2AudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

BasicEq2AudioProcessor::~BasicEq2AudioProcessor()
{
}

//==============================================================================
const String BasicEq2AudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool BasicEq2AudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool BasicEq2AudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool BasicEq2AudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double BasicEq2AudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int BasicEq2AudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int BasicEq2AudioProcessor::getCurrentProgram()
{
    return 0;
}

void BasicEq2AudioProcessor::setCurrentProgram (int index)
{
}

const String BasicEq2AudioProcessor::getProgramName (int index)
{
    return {};
}

void BasicEq2AudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void BasicEq2AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    lastSampleRate = sampleRate;
    
    dsp::ProcessSpec spec;
    spec.sampleRate = sampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumInputChannels();
    
    lowShelvingFilter.prepare(spec);
    lowShelvingFilter.reset();
    midShelvingFilter.prepare(spec);
    midShelvingFilter.reset();
    highShelvingFilter.prepare(spec);
    highShelvingFilter.reset();
}

void BasicEq2AudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool BasicEq2AudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void BasicEq2AudioProcessor::updateFilter()
{
    *lowShelvingFilter.state = *dsp::IIR::Coefficients<float>::makeLowShelf(lastSampleRate, lowFrequency, lowBW, lowGain);
    *midShelvingFilter.state = *dsp::IIR::Coefficients<float>::makePeakFilter(lastSampleRate, midFrequency, midBW, midGain);
    *highShelvingFilter.state = *dsp::IIR::Coefficients<float>::makeHighShelf(lastSampleRate, highFrequency, highBW, highGain);
}

void BasicEq2AudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    dsp::AudioBlock<float> block (buffer);
    
    updateFilter();
    lowShelvingFilter.process(dsp::ProcessContextReplacing<float> (block));
    midShelvingFilter.process(dsp::ProcessContextReplacing<float> (block));
    highShelvingFilter.process(dsp::ProcessContextReplacing<float> (block));
}

//==============================================================================
bool BasicEq2AudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* BasicEq2AudioProcessor::createEditor()
{
    return new BasicEq2AudioProcessorEditor (*this);
}

//==============================================================================
void BasicEq2AudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void BasicEq2AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BasicEq2AudioProcessor();
}
