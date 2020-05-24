//
//  crosser.cpp
//  vjshader
//
//  Created by eloi on 03.05.20.
//

#include "crosser.hpp"

void crosser::setup(){
    ofEnableSmoothing();
}

//-------------------------------------------

void crosser::update(){
    
}
//-------------------------------------------

void crosser::draw(){
    for (int i = 0; i < crossAmount; i++) {
        for (int j = 0; j < crossSpeed; j++) {
            ofPushMatrix();
            ofTranslate(i * 90, j * 90);
            if (turnSide) {
                ofRotateDeg(ofGetElapsedTimef() * crossSpeed);
            } else {
                ofRotateDeg(ofGetElapsedTimef() * crossSpeed * -1);
            }
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofSetColor(ofRandom(50, 100), ofRandom(0, 20), ofRandom(150, 240));
            ofDrawRectangle(0, 0, 30, 90);
            ofDrawRectangle(0, 0, 90, 30);
            ofPopMatrix();
        }
    }
}


