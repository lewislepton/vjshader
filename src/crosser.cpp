//
//  crosser.cpp
//  vjshader
//
//  Created by eloi on 03.05.20.
//

#include "crosser.hpp"


void crosser::setup(){
    
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
            ofRotateDeg(ofGetElapsedTimef() * uiSpeed);
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofSetColor(100, 20, 40);
            ofDrawRectangle(0, 0, 30, 90);
            ofDrawRectangle(0, 0, 90, 30);
            ofPopMatrix();
        }
    }
}
//-------------------------------------------

void crosser::keyPressed(int key){
    
//    if (key == 'c') {
//        crossHide = !crossHide;
//    }
}

