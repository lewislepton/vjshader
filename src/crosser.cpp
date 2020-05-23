//
//  crosser.cpp
//  vjshader
//
//  Created by eloi on 03.05.20.
//

#include "crosser.hpp"

void crosser::setup(){
    crossSide = true;
}

//-------------------------------------------

void crosser::update(){
    
}
//-------------------------------------------

void crosser::draw(){
    for (int i = 0; i < uiAmont; i++) {
        for (int j = 0; j < uiSpeed; j++) {
            ofPushMatrix();
            ofTranslate(i * 90, j * 90);
            if (crossSide) {
                ofRotateDeg(ofGetElapsedTimef() * uiSpeed);
            } else {
                ofRotateDeg(ofGetElapsedTimef() * uiSpeed * -1);
            }
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofSetColor(ofRandom(50, 100), ofRandom(0, 20), ofRandom(150, 240));
            ofDrawRectangle(0, 0, 30, 90);
            ofDrawRectangle(0, 0, 90, 30);
            ofPopMatrix();
        }
    }
}


