//
//  musicIn.hpp
//  vjshader
//
//  Created by eloi on 08.05.20.
//

#ifndef musicIn_hpp
#define musicIn_hpp

#include "ofMain.h"
#include "crosser.hpp"

class musicIn : public ofBaseApp {
    
public        :
    void setup();
    void update();
    void draw();
    
     ofParameter<bool> audio;
    ofParameter<float> volume;
       ofParameter<float> decay;

    
    
    ofSoundPlayer sound;
    
               float *fft;
    float *soundSpectrum;
    int bands;
};

#endif /* musicIn_hpp */
