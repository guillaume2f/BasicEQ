/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
BasicEq2AudioProcessorEditor::BasicEq2AudioProcessorEditor (BasicEq2AudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (575, 205);
    
    // SLIDERS DISPLAY
    // Low Shelving
    lowShelvingGainDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    lowShelvingGainDial.setRange(-20.0, 20.0);
    lowShelvingGainDial.setValue(0.0);
    lowShelvingGainDial.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    lowShelvingGainDial.setPopupDisplayEnabled(true, true, this);
    lowShelvingCutOffDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    lowShelvingCutOffDial.setRange(31.0, 4000.0);
    lowShelvingCutOffDial.setValue(300.0);
    lowShelvingCutOffDial.setSkewFactorFromMidPoint(300.0);
    lowShelvingCutOffDial.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    lowShelvingCutOffDial.setPopupDisplayEnabled(true, true, this);
    lowShelvingBWDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    lowShelvingBWDial.setRange(0.25, 4.0);
    lowShelvingBWDial.setValue(1.0);
    lowShelvingBWDial.setSkewFactorFromMidPoint(1.0);
    lowShelvingBWDial.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    lowShelvingBWDial.setPopupDisplayEnabled(true, true, this);
    
    // Mid Shelving
    midShelvingGainDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    midShelvingGainDial.setRange(-20.0, 20.0);
    midShelvingGainDial.setValue(0.0);
    midShelvingGainDial.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    midShelvingGainDial.setPopupDisplayEnabled(true, true, this);
    midShelvingCutOffDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    midShelvingCutOffDial.setRange(62.0, 8000.0);
    midShelvingCutOffDial.setValue(600.0);
    midShelvingCutOffDial.setSkewFactorFromMidPoint(600.0);
    midShelvingCutOffDial.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    midShelvingCutOffDial.setPopupDisplayEnabled(true, true, this);
    midShelvingBWDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    midShelvingBWDial.setRange(0.25, 4.0);
    midShelvingBWDial.setValue(1.0);
    midShelvingBWDial.setSkewFactorFromMidPoint(1.0);
    midShelvingBWDial.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    midShelvingBWDial.setPopupDisplayEnabled(true, true, this);
    
    // High Shelving
    highShelvingGainDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    highShelvingGainDial.setRange(-20.0, 20.0);
    highShelvingGainDial.setValue(0.0);
    highShelvingGainDial.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    highShelvingGainDial.setPopupDisplayEnabled(true, true, this);
    highShelvingCutOffDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    highShelvingCutOffDial.setRange(125.0, 16000.0);
    highShelvingCutOffDial.setValue(1200.0);
    highShelvingCutOffDial.setSkewFactorFromMidPoint(1200.0);
    highShelvingCutOffDial.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    highShelvingCutOffDial.setPopupDisplayEnabled(true, true, this);
    highShelvingBWDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    highShelvingBWDial.setRange(0.25, 4.0);
    highShelvingBWDial.setValue(1.0);
    highShelvingBWDial.setSkewFactorFromMidPoint(1.0);
    highShelvingBWDial.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    highShelvingBWDial.setPopupDisplayEnabled(true, true, this);
    
    // ADD LISTENERS
    // Low Shelving
    lowShelvingGainDial.addListener(this);
    lowShelvingCutOffDial.addListener(this);
    lowShelvingBWDial.addListener(this);
    // Mid Shelving
    midShelvingGainDial.addListener(this);
    midShelvingCutOffDial.addListener(this);
    midShelvingBWDial.addListener(this);
    // High Shelving
    highShelvingGainDial.addListener(this);
    highShelvingCutOffDial.addListener(this);
    highShelvingBWDial.addListener(this);
    
    // ADD AND DISPLAY COMPONENTS
    addAndMakeVisible(&lowShelvingGainDial);
    addAndMakeVisible(&lowShelvingCutOffDial);
    addAndMakeVisible(&lowShelvingBWDial);
    addAndMakeVisible(&midShelvingGainDial);
    addAndMakeVisible(&midShelvingCutOffDial);
    addAndMakeVisible(&midShelvingBWDial);
    addAndMakeVisible(&highShelvingGainDial);
    addAndMakeVisible(&highShelvingCutOffDial);
    addAndMakeVisible(&highShelvingBWDial);
}

BasicEq2AudioProcessorEditor::~BasicEq2AudioProcessorEditor()
{
}

//==============================================================================
void BasicEq2AudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // Creation of the containers
    Rectangle<float> lowShelvingContainer(15, 15, 175, 175);
    Rectangle<float> midShelvingContainer(200, 15, 175, 175);
    Rectangle<float> highShelvingContainer(385, 15, 175, 175);
    
    // Locate and size the components
    // Low Shelving
    lowShelvingBWDial.setBounds(25, 125, 70, 70);
    lowShelvingGainDial.setBounds(105, 125, 70, 70);
    lowShelvingCutOffDial.setBounds(65, 15, 70, 70);
    // Mid Shelving
    midShelvingBWDial.setBounds(210, 125, 70, 70);
    midShelvingGainDial.setBounds(295, 125, 70, 70);
    midShelvingCutOffDial.setBounds(255, 15, 70, 70);
    // High Shelving
    highShelvingBWDial.setBounds(395, 125, 70, 70);
    highShelvingGainDial.setBounds(475, 125, 70, 70);
    highShelvingCutOffDial.setBounds(435, 15, 70, 70);
    
    // Write dial names
    g.setColour(Colours::white);
    g.setFont (11.0f);
    g.drawText("FREQUENCY Hz", 65, 75, 70, 15, Justification::centred);
    g.drawText("WIDTH Oct", 25, 115, 70, 15, Justification::centred);
    g.drawText("HEIGHT dB", 105, 115, 70, 15, Justification::centred);
    g.drawText("FREQUENCY Hz", 255, 75, 70, 15, Justification::centred);
    g.drawText("WIDTH Oct", 210, 115, 70, 15, Justification::centred);
    g.drawText("HEIGHT dB", 295, 115, 70, 15, Justification::centred);
    g.drawText("FREQUENCY Hz", 435, 75, 70, 15, Justification::centred);
    g.drawText("WIDTH Oct", 395, 115, 70, 15, Justification::centred);
    g.drawText("HEIGHT dB", 475, 115, 70, 15, Justification::centred);
    g.setFont (15.0f);
    g.drawText("LOW", 65, 90, 70, 25, Justification::centred);
    g.drawText("MID", 255, 90, 70, 25, Justification::centred);
    g.drawText("HIGH", 435, 90, 70, 25, Justification::centred);
    
    // Draw the containers
    g.setColour(Colours::orange);
    g.drawRoundedRectangle(lowShelvingContainer, 12.0, 1.5);
    g.drawRoundedRectangle(midShelvingContainer, 12.0, 1.5);
    g.drawRoundedRectangle(highShelvingContainer, 12.0, 1.5);
}

void BasicEq2AudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void BasicEq2AudioProcessorEditor::sliderValueChanged (Slider *slider)
{
    if (slider == &lowShelvingGainDial)
    {
        processor.lowGain = pow(10, lowShelvingGainDial.getValue()/20);
    }
    if (slider == &lowShelvingCutOffDial)
    {
        processor.lowFrequency = lowShelvingCutOffDial.getValue();
    }
    if (slider == &lowShelvingBWDial)
    {
        processor.lowBW = sqrt(pow(2.0, lowShelvingBWDial.getValue()))/(pow(2.0, lowShelvingBWDial.getValue())-1);
    }
    if (slider == &midShelvingGainDial)
    {
        processor.midGain = pow(10, midShelvingGainDial.getValue()/20);
    }
    if (slider == &midShelvingCutOffDial)
    {
        processor.midFrequency = midShelvingCutOffDial.getValue();
    }
    if (slider == &midShelvingBWDial)
    {
        processor.midBW = sqrt(pow(2.0, midShelvingBWDial.getValue()))/(pow(2.0, midShelvingBWDial.getValue())-1);
    }
    if (slider == &highShelvingGainDial)
    {
        processor.highGain = pow(10, highShelvingGainDial.getValue()/20);
    }
    if (slider == &highShelvingCutOffDial)
    {
        processor.highFrequency = highShelvingCutOffDial.getValue();
    }
    if (slider == &highShelvingBWDial)
    {
        processor.highBW = sqrt(pow(2.0, highShelvingBWDial.getValue()))/(pow(2.0, highShelvingBWDial.getValue())-1);
    }
}
