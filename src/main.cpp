//  vjshader
//
//  main.cpp
//
//  Created by Lewis Lepton on 24/04/2020.
//  lewislepton.com
//

#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
  ofGLFWWindowSettings settings;
  
  settings.setSize(1280, 720);
  settings.setGLVersion(3, 2);
  settings.resizable = true;
  shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
  
  settings.setSize(640, 360);
  settings.setGLVersion(3, 2);
  settings.resizable = true;
  shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
  
  shared_ptr<ofApp> mainApp(new ofApp);
  shared_ptr<settingWindow> guiApp(new settingWindow);
  mainApp->future = guiApp;
  
  ofRunApp(guiWindow, guiApp);
  ofRunApp(mainWindow, mainApp);
  ofRunMainLoop();
}
