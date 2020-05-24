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
    showGui = true;
    cross.setup();
    mySong.setup();
    rect.setup();
    
    gui.setup();
    gui.add(uiActionSpeed.set("action speed", 0, 0, 1));
    gui.add(uiColor.set("color", ofVec3f(0), ofVec3f(0), ofVec3f(1)));
    gui.add(cross.turnSide.set("Cross direction", false));
    gui.add(cross.crossLoader.set("Cross loader", false));
    gui.add(cross.crossAmount.set("Cross amount", 1, 1, 25));
    gui.add(cross.crossSpeed.set("Cross speed", 10, 1, 200));
    gui.add(rect.toggleSpiral.set("Spiral toggle", false));
    gui.add(mySong.audio.set("Audio loader", false));
    gui.add(mySong.volume.set("Volume",0.5,0.0,1.0));
    gui.add(sender.setup("Sender!"));
    
    
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
    
    fbo.begin();
    rect.draw();
    fbo.end();

    
    if (cross.crossLoader)
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
    
    if (showGui){
        gui.draw();
    }
    
}

//--------------------------------------------------------------
void settingWindow::keyPressed(int key){
    if (key == 'h'){
        showGui = !showGui;
    }
}

//--------------------------------------------------------------
void settingWindow::windowResized(int w, int h){
    shader.allocate(w, h);
    fbo.allocate(w, h);
}

