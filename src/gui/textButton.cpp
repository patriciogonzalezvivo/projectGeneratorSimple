//
//  textButton.cpp
//  projectGenerator
//
//  Created by Patricio Gonzalez Vivo on 11/30/12.
//
//

#include "textButton.h"

textButton::textButton(){
    bSelectable = true;
    bMouseOver = false;
    bDrawLong = true;
    
    deliminater = "/";
}

void textButton::setText(string _newText){
    
    text = _newText;
    
    _newText = prefix + _newText;
    vector < string > breakUp;
    breakUp = ofSplitString(_newText, deliminater);
    
    ofPoint pos;
    pos.set(0,0);
    
    displayText = "";
    
    for (int i = 0; i < breakUp.size(); i++){
        string text = breakUp[i];
        if (i != breakUp.size() -1) text += deliminater;

        ofRectangle rect = font->getStringBoundingBox(text, pos.x, pos.y);
        ofRectangle rectSecText = secondFont->getStringBoundingBox(secondaryText, 0, 0);
        if ((pos.x + rect.width) > ((ofGetWidth() - x*2) - rectSecText.width)){
            displayText += "\n";
            displayText += text;
            pos.x = rect.width;
        } else {
            displayText+= text;
            pos.x += rect.width;
        }
    }
}

void textButton::calculateRect() {
    
    //  Update
    //
    setText(text);
    
    this->set(font->getStringBoundingBox( displayText, topLeftAnchor.x, topLeftAnchor.y));
    
    x -= 12;
    y -= 12;
    width += 23;
    height += 23;
    
}

void textButton::checkMousePressed(ofPoint mouse){
    if (bSelectable == false){ bMouseOver = false; return;}
    if (inside(mouse)){
        bMouseOver = true;
    } else {
        bMouseOver = false;
    }
}

void textButton::draw() {
    ofPushStyle();
    ofFill();
    
    if (bDrawLong == true){
        ofSetColor(220,220,220);
        ofFill();
        ofRect(x, y, ofGetWidth() - x*2, height);
        
        ofRectangle rectString = secondFont->getStringBoundingBox(secondaryText, 0, 0);
        rectString.y = (y + height/2) + (rectString.height)/2;
        rectString.x = (x + ofGetWidth() - x*2) - rectString.width - 10;
        
        ofFill();
        ofSetColor(0,0,0);
        secondFont->drawString(secondaryText, rectString.x, rectString.y);
    }
    
    
    if( bSelectable ){
        if (bMouseOver == true) ofSetColor(140,140,140);
        else ofSetColor(0,0,0);
    }else{
        ofSetColor(160, 160, 160);
    }
    ofRect(*this);
    
    ofSetColor(74,255,203);
    font->drawString(displayText, topLeftAnchor.x, topLeftAnchor.y);
    
    
    ofPopStyle();
}