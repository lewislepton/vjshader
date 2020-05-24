//
//  rectangles.hpp
//  vjshader
//
//  Created by eloi on 24.05.20.
//

#ifndef rectangles_hpp
#define rectangles_hpp

#include "ofMain.h"

class rectangles : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    ofParameter <bool> toggleSpiral;
};


#endif /* rectangles_hpp */
