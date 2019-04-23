/*
  ==============================================================================

    SynthSound.h
    Created: 11 Feb 2019 10:59:15pm
    Author:  Mateo Yepes

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
class SynthSound : public SynthesiserSound
{
public:
    bool appliesToNote (int midiNoteNumber) override
    {
        return true;
    }
    
    bool appliesToChannel (int midiChannel) override
    {
        return true;
    }
};

