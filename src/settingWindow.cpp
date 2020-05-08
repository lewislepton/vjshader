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
    
    
    bHide = true;
    cross.setup();
    mySong.setup();
  gui.setup();
  gui.add(uiAction.set("action", false));
  gui.add(uiActionSpeed.set("action speed", 0, 0, 1));
  gui.add(uiColor.set("color", ofVec3f(0), ofVec3f(0), ofVec3f(1)));
    
    gui.add(cross.crossSwitch.set("Cross switch", false));
    gui.add(cross.uiAmont.set("Cross amount", 1, 1, 25));
    gui.add(cross.uiSpeed.set("Cross speed", 0, 1, 80));
    gui.add(mySong.audio.set("Audio switch", false));
    gui.add(mySong.volume.set("Volune",0.5,0.0,1.0));
//    gui.add(cross.edgeA.set("Cross X", 15.0, 10.0, 30.0));
//    gui.add(cross.edgeB.set("Cross Y", 40.0, 10.0, 90.0));
    
  
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
    
    if (cross.crossSwitch)
    {
        fbo.begin();
        cross.draw();
        fbo.end();
    }
    
    mySong.update();
            
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
