//  vjshader
//
//  settingWindow.hpp
//
//  Created by Lewis Lepton on 24/04/2020.
//  lewislepton.com
//

#ifndef settingWindow_hpp
#define settingWindow_hpp

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxShaderFilter.h"
#include "crosser.hpp"
#include "musicIn.hpp"
#include "rectangles.hpp"

class settingWindow : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void windowResized(int w, int h);
    void toggleDirection();
    
    ofxPanel gui;
    ofParameter <bool> uiAction;
    ofParameter <float> uiActionSpeed;
    ofParameter <ofVec3f> uiColor;
    
    ofxShaderFilter shader;
    ofFbo fbo;
    ofxButton sender;
    
    crosser cross;
    musicIn mySong;
    rectangles rect;
    
    bool showGui;
};

#endif /* settingWindow_hpp */
