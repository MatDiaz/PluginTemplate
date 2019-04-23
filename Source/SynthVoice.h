/*
  ==============================================================================

    SynthVoice.h
    Created: 11 Feb 2019 10:59:29pm
    Author:  Mateo Yepes

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"

struct Oscillator
{
    int type = 1;
    float gain = 1;
    float attack = 250;
    float decay = 250;
    float sustain = 0.8;
    float release = 1000;
    int LFOType = 1;
    float LFOFrequency = 0;
    int filterType = 0;
    float cutoff = 0;
};

class SynthVoice : public SynthesiserVoice
{
public:
    
    SynthVoice()
    {
        
    }
    
    bool canPlaySound (SynthesiserSound* sound) override
    {
        return dynamic_cast<SynthSound*>(sound) != nullptr;
    }
    
    //========================================================
    
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentWheelPosition) override
    {
        envOne.trigger = 1;
        envTwo.trigger = 1;
        frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        level = velocity;
    }

    //========================================================
    
    void stopNote (float velocity, bool allowTailOff) override
    {
        envOne.trigger = 0;
        envTwo.trigger = 0;
        if (!velocity)
            clearCurrentNote();
    }
    
    //========================================================
    
    void pitchWheelMoved (int newPitchWheelValue) override
    {
        
    }
    
    //========================================================
    
    void controllerMoved (int controllerNumber, int newControllerValue) override
    {
        
    }
    
    //========================================================
    
    void updateSound(Oscillator oscN, int OscNumber)
    {
        if (OscNumber == 1)
            structOne = oscN;
        else
            structTwo = oscN;
    }
    
    float returnSound(Oscillator structX, maxiOsc& oscX, maxiOsc& lfoX, maxiEnv& envX, maxiFilter& filterX)
    {
        envX.setAttack(structX.attack);
        envX.setDecay(structX.decay);
        envX.setSustain(structX.sustain);
        envX.setRelease(structX.release);
        
        float Sound = 0, LFO = 0;
        
        if (structX.type == 1)
            Sound = oscX.sinewave(frequency);
        else if (structX.type == 2)
            Sound = oscX.square(frequency);
        else if (structX.type == 3)
            Sound = oscX.triangle(frequency);
        else if (structX.type == 4)
            Sound = oscX.saw(frequency);
        
        if (structX.type == 1)
            LFO = lfoX.sinewave(structX.LFOFrequency);
        else if (structX.type == 2)
            LFO = lfoX.square(structX.LFOFrequency);
        else if (structX.type == 3)
            LFO = lfoX.triangle(structX.LFOFrequency);
        else if (structX.type == 4)
            LFO = lfoX.triangle(structX.LFOFrequency);
        
        Sound = structX.LFOFrequency > 0 ? Sound * LFO : Sound;
        
        if (structX.filterType == 1)
            Sound = filterX.hipass(Sound, structX.cutoff);
        else if (structX.filterType == 2)
            Sound = filterX.lopass(Sound, structX.cutoff);
        
        Sound = envX.adsr(Sound, envX.trigger);
        
        return Sound * structX.gain;
    }
    
    //========================================================
    
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override
    {
        for (auto sample = 0; sample < numSamples; ++sample)
        {
            float Sound = returnSound(structOne, oscOne, lfoOne, envOne, filterOne);
            float SoundTwo = returnSound(structTwo, oscTwo, lfoTwo, envTwo, filterTwo);
            
            Sound = ((Sound + SoundTwo) / 2) * 0.7;
            
            for (auto channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, Sound);
            }
            ++startSample;
        }
    }

private:
    
    float frequency = 0, level = 0;
    Oscillator structOne, structTwo;
    maxiOsc oscOne, oscTwo, lfoOne, lfoTwo;
    maxiEnv envOne, envTwo;
    maxiFilter filterOne, filterTwo;
};
