//  vjshader
//
//  viewer.hpp
//
//  Created by Lewis Lepton on 24/04/2020.
//  lewislepton.com
//

#ifndef viewer_hpp
#define viewer_hpp

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxShaderFilter.h"

class viewer : public ofBaseApp {
public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void windowResized(int w, int h);
  
  ofxShaderFilter shader;
  
  ofVec3f color;
  
  ofFbo fbo;
  
  bool action;
  float actionSpeed;
};

#endif /* viewer_hpp */
