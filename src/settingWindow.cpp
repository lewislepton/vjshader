//  vjshader
//
//  settingWindow.cpp
//
//  Created by Lewis Lepton on 24/04/2020.
//  lewislepton.com
//

#include "settingWindow.hpp"

//--------------------------------------------------------------
void settingWindow::setup(){
  ofSetWindowTitle("controls");
  
  gui.setup();
  gui.add(uiAction.set("action", false));
  gui.add(uiActionSpeed.set("action speed", 0, 0, 1));
  gui.add(uiColor.set("color", ofVec3f(0), ofVec3f(0), ofVec3f(1)));
  
  fbo.allocate(640, 360);
  fbo.begin();
  ofClear(255);
  shader.allocate(fbo.getWidth(), fbo.getHeight());
  shader.load("color.frag");
  fbo.end();
}

//--------------------------------------------------------------
void settingWindow::update(){
  fbo.begin();
  shader.setUniform3f("u_color", uiColor->x, uiColor->y, uiColor->z);
  fbo.end();
  
  fbo.begin();
  shader.render();
  shader.draw(0, 0);
  fbo.end();
}

//--------------------------------------------------------------
void settingWindow::draw(){
  fbo.draw(0, 0);
  
  if (bHide){
    gui.draw();
  }
}

//--------------------------------------------------------------
void settingWindow::keyPressed(int key){
  if (key == 'h'){
    bHide = !bHide;
  }
}

//--------------------------------------------------------------
void settingWindow::windowResized(int w, int h){
  shader.allocate(w, h);
  fbo.allocate(w, h);
}
