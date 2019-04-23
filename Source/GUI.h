/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "filmStrip.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginAudioProcessorEditor  : public AudioProcessorEditor,
                                    public Slider::Listener
{
public:
    //==============================================================================
    PluginAudioProcessorEditor (PluginAudioProcessor& p);
    ~PluginAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    PluginAudioProcessor& processor;
    OwnedArray<FilmStripKnob> knobArray;

    enum {OscOneType, OscOneOctave, OscOneLevel, LFOOneType, LFOOneRate, OscOneA, OscOneD, OscOneS, OscOneR, OscOneFilterType, OscOneFreq, OscOneQ, OscTwoType, OscTwoOctave, OscTwoLevel, LFOTwoType, LFOTwoRate, OscTwoA, OscTwoD, OscTwoS, OscTwoR, OscTwoFilterType, OscTwoFreq, OscTwoQ, Mix};

    Image knobImage = ImageFileFormat::loadFrom(BinaryData::synthknob_png, BinaryData::synthknob_pngSize);

    TooltipWindow newToolTip;

    std::unique_ptr<FilmStripKnob> newKnob;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Slider> slider;
    std::unique_ptr<Drawable> drawable1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

