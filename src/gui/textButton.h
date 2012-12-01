//
//  textButton.h
//  projectGenerator
//
//  Created by molmol on 9/17/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef projectGenerator_textButton_h
#define projectGenerator_textButton_h

#include "ofMain.h"

class textButton : public ofRectangle {
public:

    textButton();
    
    void setText( string newText );
    void calculateRect();
    void checkMousePressed(ofPoint mouse);
    void draw();
    
    ofTrueTypeFont * font;
    ofTrueTypeFont * secondFont;
    
    ofPoint topLeftAnchor;
    
    string  prefix;
    string  text;
    string  secondaryText;
    string  deliminater;
    
    bool    bSelectable;
    bool    bDrawLong;
    bool    bMouseOver;
    
private:
    string  displayText;
};

#endif
