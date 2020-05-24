//
//  musicIn.cpp
//  vjshader
//
//  Created by eloi on 08.05.20.
//

#include "musicIn.hpp"

void musicIn::setup(){
    sound.load("wakeme.mp3");
    sound.play();
    sound.setLoop(true);
}

//-------------------------------------------------------
void musicIn::update(){
    ofSoundUpdate();
    sound.setVolume(volume);
    
    if (!audio)
    {
        sound.setPaused(true);
    }
    else
    {
        sound.setPaused(false);
    }
}

