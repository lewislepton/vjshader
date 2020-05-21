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
    future->button.addListener(this, &ofApp::actionClickerino);
    viewer.setup();
}

//----------------------- ---------------------------------------
void ofApp::update(){
    viewer.update();
}

//---------------------------------------
void ofApp::actionClickerino(){
    float time = 0;
    
    time = ofMap(future->uiActionSpeed, 0.0, 1.0, 0.001, 0.06);
    
    viewer.color.x = ofLerp(viewer.color.x, future->uiColor->x, time);
    viewer.color.y = ofLerp(viewer.color.y, future->uiColor->y, time);
    viewer.color.z = ofLerp(viewer.color.z, future->uiColor->z, time);
    
    
    if (future->cross.crossSwitch) {
        viewer.cross.uiAmont = future->cross.uiAmont;
        viewer.cross.uiSpeed = future->cross.uiSpeed;
    }
    else
    {
        viewer.cross.uiAmont = 0;
        viewer.cross.uiSpeed = 0.0;
    }
    
    if (!future->cross.turnSide) {
        viewer.cross.crossSide = future->cross.crossSide;
    }
//    else
//    {
//        viewer.cross.crossSide = future->cross.crossSide;
//    }
    
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
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    viewer.windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------





