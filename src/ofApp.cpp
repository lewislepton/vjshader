//  vjshader
//
//  ofApp.cpp
//
//  Created by Lewis Lepton on 24/04/2020.
//  lewislepton.com
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
    ofSetWindowTitle("VJshader");
    ofSetFrameRate(60);
    future->sender.addListener(this, &ofApp::actionClick);
    viewer.setup();
}

//----------------------- ---------------------------------------
void ofApp::update(){
    viewer.update();
}

//---------------------------------------
void ofApp::actionClick(){
    float time = 0;
    time = ofMap(future->uiActionSpeed, 0.0, 1.0, 0.001, 0.06);
    
    viewer.color.x = ofLerp(viewer.color.x, future->uiColor->x, time);
    viewer.color.y = ofLerp(viewer.color.y, future->uiColor->y, time);
    viewer.color.z = ofLerp(viewer.color.z, future->uiColor->z, time);
    viewer.cross.turnSide = future->cross.turnSide;
    viewer.rect.toggleSpiral = future->rect.toggleSpiral;
    
    
    if (future->cross.crossLoader) {
        viewer.cross.crossAmount = future->cross.crossAmount;
        viewer.cross.crossSpeed = future->cross.crossSpeed;
    }
    else
    {
        viewer.cross.crossAmount = 0;
        viewer.cross.crossSpeed = 0.0;
    }
        
}

//--------------------------------------------------------------
void ofApp::draw(){
    viewer.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    viewer.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    viewer.windowResized(w, h);
}





