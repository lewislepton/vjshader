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
  
  viewer.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
  viewer.update();
  
  if (future->uiAction){
    float time = 0;
    
    time = ofMap(future->uiActionSpeed, 0.0, 1.0, 0.001, 0.06);
    
    viewer.color.x = ofLerp(viewer.color.x, future->uiColor->x, time);
    viewer.color.y = ofLerp(viewer.color.y, future->uiColor->y, time);
    viewer.color.z = ofLerp(viewer.color.z, future->uiColor->z, time);
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
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
  viewer.windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}
