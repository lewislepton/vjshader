//
//  crosser.hpp
//  vjshader
//
//  Created by eloi on 03.05.20.
//

#ifndef crosser_hpp
#define crosser_hpp

#include "ofMain.h"
#include "ofxGui.h"

class crosser : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    ofxPanel gui;
    ofParameter <bool> turnSide;
    ofParameter<bool> crossLoader;
    ofParameter<int> uiAmont;
    ofParameter<float> uiSpeed;
    ofParameter<float> edgeA;
    ofParameter<float> edgeB;
    
    bool crossSide;
};

#endif /* crosser_hpp */
