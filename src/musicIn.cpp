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
    
        fft = new float[128];
        for (int i = 0; i< 128; i++) {
            fft[i] = 0;
        }
    
        bands = 64;
}

//-------------------------------------------------------
void musicIn::update(){
    ofSoundUpdate();
    
    sound.setVolume(volume);
    
    soundSpectrum = ofSoundGetSpectrum(bands);
    
        for (int i = 0; i < bands; i++) {
            fft[i] *= decay;
            if (fft[i] < soundSpectrum[i]) {
                fft[i] = soundSpectrum[i];
            }
        }
    
    if (!audio)
    {
        sound.setPaused(true);
    }
    else
    {
        sound.setPaused(false);
    }
}

//-------------------------------------------------------
void musicIn::draw(){
    
    
}

//-------------------------------------------------------
