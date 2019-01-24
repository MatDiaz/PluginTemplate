/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

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
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginAudioProcessorEditor::~PluginAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText (CharPointer_UTF8 ("Este es el proyecto de prueba, recuerden que deben de configurar:\n"
"-Los SDK de VST\n"
"-El nombre del proyecto\n"
"-Los formatos del plugin\n"
"-El nombre del plugin\n"
"-Las configuraciones de canales\n"
"-Las categorias de plugins\n"
"Si se est\xc3\xa1 en windows se debe configurar el SDK correspondiente.\n"
"\n"
"        .-\"\"\"\".\n"
"       /       \\\n"
"   __ /   .-.  .\\\n"
"  /  `\\  /   \\/  \\\n"
"  |  _ \\/   .==.==.\n"
"  | (   \\  /____\\__\\\n"
"   \\ \\      (_()(_()\n"
"    \\ \\            \'---._\n"
"     \\                   \\______\n"
"  /\\ |`       (__)________/\n"
" /  \\|     /\\___/\n"
"|    \\     \\||VV\n"
"|     \\     \\|\"\"\"\",\n"
"|      \\     ______)\n"
"\\       \\  /`\n"
"jgs      \\("), getLocalBounds(), Justification::topLeft, 1);
    //[/UserPaint]
}

void PluginAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
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
                 fixedSize="1" initialWidth="400" initialHeight="400">
  <BACKGROUND backgroundColour="ff000000"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
