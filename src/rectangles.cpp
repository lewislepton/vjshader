//
//  rectangles.cpp
//  vjshader
//
//  Created by eloi on 24.05.20.
//

#include "rectangles.hpp"


void rectangles::setup(){
    
}


//--------------------------------------------------------------

void rectangles::update(){
    
    
}

//--------------------------------------------------------------
void rectangles::draw(){
    if (toggleSpiral) {
        ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
        ofNoFill();
        ofSetLineWidth(50);
        ofSetRectMode(OF_RECTMODE_CENTER);
        
        for (int i = 0; i < 30; i++) {
            ofSetColor(ofRandom(50, 100), ofRandom(0, 20), ofRandom(150, 240));
            ofRotateDeg(ofGetElapsedTimef() * 5);
            ofScale(0.9);
            ofDrawRectangle(0, 0, 500, 500);
        }
    }
}

