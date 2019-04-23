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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "GUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginAudioProcessorEditor::PluginAudioProcessorEditor (PluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    newToolTip.setColour(TooltipWindow::ColourIds::backgroundColourId, Colour(Colours::black));

    //[/Constructor_pre]

    slider.reset (new Slider ("new slider"));
    addAndMakeVisible (slider.get());
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::LinearHorizontal);
    slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    slider->addListener (this);

    slider->setBounds (840, 368, 150, 24);

    drawable1.reset (Drawable::createFromImageData (BinaryData::background_jpg, BinaryData::background_jpgSize));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (1000, 400);


    //[Constructor] You can add your own custom stuff here..
    slider->setVisible(false);
    for (auto i = 0; i < 25; ++i)
    {
        knobArray.add(new FilmStripKnob(knobImage, 128, false));
        addAndMakeVisible(knobArray[i]);
        knobArray[i]->addListener(this);

        if (i == OscOneType || i == OscTwoType)
        {
            int x = 21, y = 59;
            String name = "OscOneType";

            if (i == OscTwoType) { y = 187; name = "OscTwoType"; }

            knobArray[i]->setRange (1, 4, 1);
            knobArray[i]->setName (name);
            knobArray[i]->setBounds (x, y, 50, 50);
            knobArray[i]->setTooltip ("Seno");
        }
        else if (i == OscOneOctave || i == OscTwoOctave)
        {
            int x = 109, y = 59;
            String name = "OscOneOctave";

            if (i == OscTwoOctave) { y = 187; name = "OscTwoOctave"; }

            knobArray[i]->setRange (-8, 8, 1);
            knobArray[i]->setValue (0, dontSendNotification);
            knobArray[i]->setName (name);
            knobArray[i]->setBounds (x, y, 50, 50);
        }
        else if (i == OscOneLevel || i == OscTwoLevel)
        {
            int x = 197, y = 59;
            String name = "OscOneLevel";

            if (i == OscTwoLevel){ y = 187; name = "OscTwoLevel"; }

            knobArray[i]->setRange(0, 1, 0);
            knobArray[i]->setValue(0.5, dontSendNotification);
            knobArray[i]->setName(name);
            knobArray[i]->setBounds(x, y, 50, 50);
        }
        else if (i == LFOOneType || i == LFOTwoType)
        {
            int x = 293, y = 59;
            String name = "LFOOneType";

            if (i == LFOTwoType) { y = 187; name = "LFOTwoType"; }

            knobArray[i]->setRange(1, 4, 1);
            knobArray[i]->setName("LFOOneType");
            knobArray[i]->setBounds(x, y, 50, 50);
        }
        else if (i == LFOOneRate || i == LFOTwoRate)
        {
            int x = 368, y = 32;
            String name = "LFOOneRate";

            if (i == LFOTwoRate){ y = 152; name = "LFOTwoRate"; }

            knobArray[i]->setRange(0, 20, 0);
            knobArray[i]->setName(name);
            knobArray[i]->setBounds(x, y, 50, 50);
        }
        else if (i == OscOneA || i == OscTwoA)
        {
            int x = 542, y = 80;
            String name = "OscOneAttack";

            if (i == OscTwoA){ y = 177; name = "OscTwoAttack"; }

            knobArray[i]->setRange (0.1, 500, 0);
            knobArray[i]->setName (name);
            knobArray[i]->setBounds (x, y, 50, 50);
        }
        else if (i == OscOneD || i == OscTwoD)
        {
            int x = 593, y = 80;
            String name = "OscOneDecay";

            if (i == OscTwoD) { y = 207; name = "OscTwoDecay"; }

            knobArray[i]->setRange(0.1, 500, 0);
            knobArray[i]->setName(name);
            knobArray[i]->setBounds(x, y, 50, 50);
        }
        else if (i == OscOneS || i == OscTwoS)
        {
            int x = 645, y = 50;
            String name = "OscOneSustain";

            if ( i == OscTwoS) { y = 177; name = "OscTwoSustain"; }

            knobArray[i]->setRange(0, 1, 0);
            knobArray[i]->setName(name);
            knobArray[i]->setBounds(x, y, 50, 50);
        }
        else if (i == OscOneR || i == OscTwoR)
        {
            int x = 696, y = 80;
            String name = "OscOneRelease";

            if (i == OscTwoR) { y = 207; name = "OscTwoRelease"; }

            knobArray[i]->setRange(0.1, 2000, 0);
            knobArray[i]->setName(name);
            knobArray[i]->setBounds (x, y, 50, 50);
        }
        else if (i == OscOneFilterType || i == OscTwoFilterType)
        {
            int x = 779, y = 55;
            String name = "OscOneFilterType";

            if (i == OscTwoFilterType) { y = 183; name = "OscTwoFilterType"; }

            knobArray[i]->setRange(0, 2, 1);
            knobArray[i]->setName(name);
            knobArray[i]->setBounds(x, y, 50, 50);
        }
        else if (i == OscOneFreq || i == OscTwoFreq)
        {
            int x = 849, y = 56;
            String name = "OscOneFilterFreq";

            if ( i == OscTwoFreq ) { y = 184; name = "OscTwoFilterFreq"; }

            knobArray[i]->setRange(100, 4000, 0);
            knobArray[i]->setName(name);
            knobArray[i]->setBounds(x, y, 50, 50);
        }
        else if (i == OscOneQ || i == OscTwoQ)
        {
            int x = 919, y = 56;
            String name = "OscOneQ";

            if (i == OscTwoQ)  { y = 184; name = "OscTwoQ"; }

            knobArray[i]->setRange(0.1, 10, 0);
            knobArray[i]->setName(name);
            knobArray[i]->setBounds(x, y, 50, 50);
        }
        else if (i == Mix)
        {
            knobArray[i]->setRange(0, 1, 0);
            knobArray[i]->setName("Mix");
            knobArray[i]->setBounds(445, 130, 50, 50);
        }

    }
    //[/Constructor]
}

PluginAudioProcessorEditor::~PluginAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;
    drawable1 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    {
        int x = 0, y = 0, width = 1000, height = 400;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black);
        jassert (drawable1 != 0);
        if (drawable1 != 0)
            drawable1->drawWithin (g, Rectangle<float> (x, y, width, height),
                                   RectanglePlacement::stretchToFit, 1.000f);
    }

    {
        float x = 10.0f, y = 20.0f, width = 510.0f, height = 110.0f;
        Colour fillColour1 = Colour (0x5cc3c3c3), fillColour2 = Colour (0xd10b5868);
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (ColourGradient (fillColour1,
                                       16.0f - 10.0f + x,
                                       24.0f - 20.0f + y,
                                       fillColour2,
                                       528.0f - 10.0f + x,
                                       144.0f - 20.0f + y,
                                       false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 1.000f);
    }

    {
        float x = 10.0f, y = 275.0f, width = 510.0f, height = 110.0f;
        Colour fillColour = Colour (0xd10b5868);
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 1.000f);
    }

    {
        float x = 10.0f, y = 147.0f, width = 510.0f, height = 110.0f;
        Colour fillColour1 = Colour (0x5cc3c3c3), fillColour2 = Colour (0xd10b5868);
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (ColourGradient (fillColour1,
                                       16.0f - 10.0f + x,
                                       240.0f - 147.0f + y,
                                       fillColour2,
                                       528.0f - 10.0f + x,
                                       144.0f - 147.0f + y,
                                       false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 1.000f);
    }

    {
        float x = 430.0f, y = 86.0f, width = 78.0f, height = 113.0f;
        Colour fillColour = Colour (0xff0b5868);
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 1.000f);
    }

    {
        float x = 540.0f, y = 20.0f, width = 210.0f, height = 110.0f;
        Colour fillColour1 = Colour (0x5cc3c3c3), fillColour2 = Colour (0xd10b5868);
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (ColourGradient (fillColour1,
                                       976.0f - 540.0f + x,
                                       16.0f - 20.0f + y,
                                       fillColour2,
                                       528.0f - 540.0f + x,
                                       144.0f - 20.0f + y,
                                       false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 1.000f);
    }

    {
        int x = 12, y = 21, width = 200, height = 30;
        String text (TRANS(" Oscillator One"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 20.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 12, y = 149, width = 108, height = 30;
        String text (TRANS(" Oscillator Two"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 20.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 560, y = 93, width = 12, height = 30;
        String text (TRANS("A"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 612, y = 60, width = 12, height = 30;
        String text (TRANS("D"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 665, y = 93, width = 12, height = 30;
        String text (TRANS("S"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 715, y = 60, width = 12, height = 30;
        String text (TRANS("R"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 544, y = 20, width = 200, height = 30;
        String text (TRANS(" Oscillator One Envelope"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 435, y = 85, width = 76, height = 30;
        String text (TRANS("Mix"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 20.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        float x = 540.0f, y = 148.0f, width = 210.0f, height = 110.0f;
        Colour fillColour1 = Colour (0x5cc3c3c3), fillColour2 = Colour (0xd10b5868);
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (ColourGradient (fillColour1,
                                       976.0f - 540.0f + x,
                                       16.0f - 148.0f + y,
                                       fillColour2,
                                       528.0f - 540.0f + x,
                                       144.0f - 148.0f + y,
                                       false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 1.000f);
    }

    {
        float x = 770.0f, y = 20.0f, width = 210.0f, height = 110.0f;
        Colour fillColour1 = Colour (0x5cc3c3c3), fillColour2 = Colour (0xd10b5868);
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (ColourGradient (fillColour1,
                                       976.0f - 770.0f + x,
                                       16.0f - 20.0f + y,
                                       fillColour2,
                                       528.0f - 770.0f + x,
                                       144.0f - 20.0f + y,
                                       false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 1.000f);
    }

    {
        float x = 770.0f, y = 148.0f, width = 210.0f, height = 110.0f;
        Colour fillColour1 = Colour (0x5cc3c3c3), fillColour2 = Colour (0xd10b5868);
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (ColourGradient (fillColour1,
                                       976.0f - 770.0f + x,
                                       16.0f - 148.0f + y,
                                       fillColour2,
                                       528.0f - 770.0f + x,
                                       144.0f - 148.0f + y,
                                       false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 1.000f);
    }

    {
        int x = 544, y = 149, width = 200, height = 30;
        String text (TRANS(" Oscillator Two Envelope"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 772, y = 21, width = 200, height = 30;
        String text (TRANS(" Oscillator One Filter"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 772, y = 149, width = 200, height = 30;
        String text (TRANS(" Oscillator Two Filter"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 560, y = 221, width = 12, height = 30;
        String text (TRANS("A"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 612, y = 188, width = 12, height = 30;
        String text (TRANS("D"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 665, y = 221, width = 12, height = 30;
        String text (TRANS("S"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 715, y = 188, width = 12, height = 30;
        String text (TRANS("R"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 19.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 786, y = 100, width = 36, height = 30;
        String text (TRANS("Type"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 858, y = 100, width = 36, height = 30;
        String text (TRANS("Freq."));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 16, y = 277, width = 496, height = 35;
        String text (TRANS("Master"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 22.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        float x = 280.0f, y = 20.0f, width = 150.0f, height = 110.0f;
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 1.000f);
    }

    {
        int x = 284, y = 21, width = 140, height = 30;
        String text (TRANS("LFO One"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 20.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 922, y = 100, width = 36, height = 30;
        String text (TRANS("Q"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        float x = 280.0f, y = 147.0f, width = 150.0f, height = 110.0f;
        Colour strokeColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRoundedRectangle (x, y, width, height, 10.000f, 1.000f);
    }

    {
        int x = 284, y = 149, width = 140, height = 30;
        String text (TRANS("LFO Two"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 20.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centredLeft, true);
    }

    {
        int x = 786, y = 228, width = 36, height = 30;
        String text (TRANS("Type"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 858, y = 228, width = 36, height = 30;
        String text (TRANS("Freq."));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 922, y = 228, width = 36, height = 30;
        String text (TRANS("Q"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 300, y = 98, width = 36, height = 30;
        String text (TRANS("Type"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 372, y = 69, width = 36, height = 30;
        String text (TRANS("Rate"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 364, y = 189, width = 36, height = 30;
        String text (TRANS("Rate"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 28, y = 98, width = 36, height = 30;
        String text (TRANS("Type"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 116, y = 98, width = 36, height = 30;
        String text (TRANS("Octave"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 204, y = 98, width = 36, height = 30;
        String text (TRANS("Level"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 28, y = 226, width = 36, height = 30;
        String text (TRANS("Type"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 116, y = 226, width = 36, height = 30;
        String text (TRANS("Octave"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 204, y = 226, width = 36, height = 30;
        String text (TRANS("Level"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 300, y = 225, width = 36, height = 30;
        String text (TRANS("Type"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font ("American Typewriter", 15.00f, Font::plain).withTypefaceStyle ("Regular").withExtraKerningFactor (-0.075f));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    {
//        int x = 21, y  = 59, width = 50, height = 50;
//        Rectangle<int> area(0, 0, 50, 50);
//        RectanglePlacement rectanglePosition(RectanglePlacement::centred);
//        g.drawImageWithin(knobImage.getClippedImage(area), x, y, width, height, rectanglePosition);

    }
    //[/UserPaint]
}

void PluginAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    int oscNumber = 1;
    for (auto i = 0; i < 25; ++i)
    {
        if (sliderThatWasMoved == knobArray[i])
        {
            if (i == OscOneType || i == OscTwoType)
            {
                int type = (int)knobArray[i]->getValue();
                if (i == OscTwoType)
                {
                    oscNumber = 2;
                    processor.oscTwo.type = type;
                }
                else
                {
                    oscNumber = 1;
                    processor.oscOne.type = type;
                }
            }
            else if (i == OscOneA || i == OscTwoA)
            {
                float attack = knobArray[i]->getValue();
                if (i == OscTwoA)
                {
                    oscNumber = 2;
                    processor.oscTwo.attack = attack;
                }
                else
                {
                    oscNumber = 1;
                    processor.oscOne.attack = attack;
                }
            }
            else if ( i == OscOneS || i == OscTwoS)
            {
                float sustain = knobArray[i]->getValue();
                if (i == OscTwoS)
                {
                    oscNumber = 2;
                    processor.oscTwo.sustain = sustain;
                }
                else
                {
                    oscNumber = 1;
                    processor.oscOne.sustain = sustain;
                }
            }
            else if (i == OscOneD || i == OscTwoD)
            {
                float decay = knobArray[i]->getValue();
                if (i == OscTwoD)
                {
                    oscNumber = 2;
                    processor.oscTwo.decay = decay;
                }
                else
                {
                    oscNumber = 1;
                    processor.oscOne.decay = decay;
                }
            }
            else if (i == OscOneR || i == OscTwoR)
            {
                float release = knobArray[i]->getValue();
                if (i == OscTwoR)
                {
                    oscNumber = 2;
                    processor.oscTwo.release = release;
                }
                else
                {
                    oscNumber = 1;
                    processor.oscOne.release = release;
                }
            }
            else if ( i == LFOOneRate || i == LFOTwoRate)
            {
                float rate = knobArray[i]->getValue();
                if ( i == LFOTwoRate)
                {
                    oscNumber = 2;
                    processor.oscTwo.LFOFrequency = rate;
                }
                else
                {
                    oscNumber = 1;
                    processor.oscOne.LFOFrequency = rate;
                }
            }
            else if ( i == LFOOneType || i == LFOTwoType)
            {
                float type = knobArray[i]->getValue();
                if ( i == LFOTwoType)
                {
                    oscNumber = 2;
                    processor.oscTwo.LFOType = type;
                }
                else
                {
                    oscNumber = 1;
                    processor.oscOne.LFOType = type;
                }
            }
            else if (i == OscOneLevel || i == OscTwoLevel)
            {
                float currentLevel = knobArray[i]->getValue();
                if (i == OscTwoLevel)
                {
                    oscNumber = 2;
                    processor.oscTwo.gain = currentLevel;
                }
                else
                {
                    oscNumber = 1;
                    processor.oscOne.gain = currentLevel;
                }
            }
            else if (i == OscOneFilterType || i == OscTwoFilterType)
            {
                int filterType = (int) knobArray[i]->getValue();
                if (i == OscTwoFilterType)
                {
                    oscNumber = 2;
                    processor.oscTwo.filterType = filterType;
                }
                else
                {
                    oscNumber = 1;
                    processor.oscOne.filterType = filterType;
                }
            }
            else if (i == OscOneFreq || i == OscTwoFreq)
            {
                float cutoff = (knobArray[i]->getValue() - 100) / 3900;
                if (i == OscOneFreq)
                {
                    oscNumber = 2;
                    processor.oscTwo.cutoff = cutoff;
                }
                else
                {
                    oscNumber = 1;
                    processor.oscOne.cutoff = cutoff;
                }
            }
            processor.updateVoice(oscNumber);
        }
    }
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider.get())
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="PluginAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="1000" initialHeight="400">
  <BACKGROUND backgroundColour="ff000000">
    <IMAGE pos="0 0 1000 400" resource="BinaryData::background_jpg" opacity="1"
           mode="0"/>
    <ROUNDRECT pos="10 20 510 110" cornerSize="1e1" fill="linear: 16 24, 528 144, 0=5cc3c3c3, 1=d10b5868"
               hasStroke="1" stroke="1, mitered, butt" strokeColour="solid: ffffffff"/>
    <ROUNDRECT pos="10 275 510 110" cornerSize="1e1" fill="solid: d10b5868"
               hasStroke="1" stroke="1, mitered, butt" strokeColour="solid: ffffffff"/>
    <ROUNDRECT pos="10 147 510 110" cornerSize="1e1" fill="linear: 16 240, 528 144, 0=5cc3c3c3, 1=d10b5868"
               hasStroke="1" stroke="1, mitered, butt" strokeColour="solid: ffffffff"/>
    <ROUNDRECT pos="430 86 78 113" cornerSize="1e1" fill="solid: ff0b5868" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ffffffff"/>
    <ROUNDRECT pos="540 20 210 110" cornerSize="1e1" fill="linear: 976 16, 528 144, 0=5cc3c3c3, 1=d10b5868"
               hasStroke="1" stroke="1, mitered, butt" strokeColour="solid: ffffffff"/>
    <TEXT pos="12 21 200 30" fill="solid: ffffffff" hasStroke="0" text=" Oscillator One"
          fontname="American Typewriter" fontsize="2e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="12 149 108 30" fill="solid: ffffffff" hasStroke="0" text=" Oscillator Two"
          fontname="American Typewriter" fontsize="2e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="560 93 12 30" fill="solid: ffffffff" hasStroke="0" text="A"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="612 60 12 30" fill="solid: ffffffff" hasStroke="0" text="D"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="665 93 12 30" fill="solid: ffffffff" hasStroke="0" text="S"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="715 60 12 30" fill="solid: ffffffff" hasStroke="0" text="R"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="544 20 200 30" fill="solid: ffffffff" hasStroke="0" text=" Oscillator One Envelope"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="435 85 76 30" fill="solid: ffffffff" hasStroke="0" text="Mix"
          fontname="American Typewriter" fontsize="2e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <ROUNDRECT pos="540 148 210 110" cornerSize="1e1" fill="linear: 976 16, 528 144, 0=5cc3c3c3, 1=d10b5868"
               hasStroke="1" stroke="1, mitered, butt" strokeColour="solid: ffffffff"/>
    <ROUNDRECT pos="770 20 210 110" cornerSize="1e1" fill="linear: 976 16, 528 144, 0=5cc3c3c3, 1=d10b5868"
               hasStroke="1" stroke="1, mitered, butt" strokeColour="solid: ffffffff"/>
    <ROUNDRECT pos="770 148 210 110" cornerSize="1e1" fill="linear: 976 16, 528 144, 0=5cc3c3c3, 1=d10b5868"
               hasStroke="1" stroke="1, mitered, butt" strokeColour="solid: ffffffff"/>
    <TEXT pos="544 149 200 30" fill="solid: ffffffff" hasStroke="0" text=" Oscillator Two Envelope"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="772 21 200 30" fill="solid: ffffffff" hasStroke="0" text=" Oscillator One Filter"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="772 149 200 30" fill="solid: ffffffff" hasStroke="0" text=" Oscillator Two Filter"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="560 221 12 30" fill="solid: ffffffff" hasStroke="0" text="A"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="612 188 12 30" fill="solid: ffffffff" hasStroke="0" text="D"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="665 221 12 30" fill="solid: ffffffff" hasStroke="0" text="S"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="715 188 12 30" fill="solid: ffffffff" hasStroke="0" text="R"
          fontname="American Typewriter" fontsize="1.9e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="786 100 36 30" fill="solid: ffffffff" hasStroke="0" text="Type"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="858 100 36 30" fill="solid: ffffffff" hasStroke="0" text="Freq."
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="16 277 496 35" fill="solid: ffffffff" hasStroke="0" text="Master"
          fontname="American Typewriter" fontsize="2.2e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <ROUNDRECT pos="280 20 150 110" cornerSize="1e1" fill="linear: 16 24, 528 144, 0=c3c3c3, 1=b5868"
               hasStroke="1" stroke="1, mitered, butt" strokeColour="solid: ffffffff"/>
    <TEXT pos="284 21 140 30" fill="solid: ffffffff" hasStroke="0" text="LFO One"
          fontname="American Typewriter" fontsize="2e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="922 100 36 30" fill="solid: ffffffff" hasStroke="0" text="Q"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <ROUNDRECT pos="280 147 150 110" cornerSize="1e1" fill="linear: 16 24, 528 144, 0=c3c3c3, 1=b5868"
               hasStroke="1" stroke="1, mitered, butt" strokeColour="solid: ffffffff"/>
    <TEXT pos="284 149 140 30" fill="solid: ffffffff" hasStroke="0" text="LFO Two"
          fontname="American Typewriter" fontsize="2e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="33"/>
    <TEXT pos="786 228 36 30" fill="solid: ffffffff" hasStroke="0" text="Type"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="858 228 36 30" fill="solid: ffffffff" hasStroke="0" text="Freq."
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="922 228 36 30" fill="solid: ffffffff" hasStroke="0" text="Q"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="300 98 36 30" fill="solid: ffffffff" hasStroke="0" text="Type"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="372 69 36 30" fill="solid: ffffffff" hasStroke="0" text="Rate"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="364 189 36 30" fill="solid: ffffffff" hasStroke="0" text="Rate"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="28 98 36 30" fill="solid: ffffffff" hasStroke="0" text="Type"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="116 98 36 30" fill="solid: ffffffff" hasStroke="0" text="Octave"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="204 98 36 30" fill="solid: ffffffff" hasStroke="0" text="Level"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="28 226 36 30" fill="solid: ffffffff" hasStroke="0" text="Type"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="116 226 36 30" fill="solid: ffffffff" hasStroke="0" text="Octave"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="204 226 36 30" fill="solid: ffffffff" hasStroke="0" text="Level"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
    <TEXT pos="300 225 36 30" fill="solid: ffffffff" hasStroke="0" text="Type"
          fontname="American Typewriter" fontsize="1.5e1" kerning="-7.5e-2"
          bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="new slider" id="43b599d5ca0cf72e" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="840 368 150 24" min="0" max="1e1"
          int="0" style="LinearHorizontal" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

