//
//  checkList.cpp
//  projectGenerator
//
//  Created by Patricio Gonzalez Vivo on 12/1/12.
//
//

#include "checkList.h"

checkList::checkList(){
    elementHeight = 35;
}

void checkList::addElement(string _value){
    checkButton *newElement = new checkButton();
    newElement->set(x, y+height, width, elementHeight);
    newElement->text = _value;
    newElement->font = font;
    elements.push_back(newElement);
}

void checkList::clear(){
    for(int i = 0; i < elements.size(); i++){
        delete elements[i];
    }
    elements.clear();
}

void checkList::reset(){
    for(int i = 0; i < elements.size(); i++){
        *(elements[i]) = false;
    }
}

bool checkList::select(string _value){
    for(int i = 0; i < elements.size(); i++){
        if ( elements[i]->text == _value){
            (*elements[i]) = true;
            return true;
        }
    }
    return false;
}

vector<string> checkList::getSelected(){
    vector<string> list;
    
    for(int i = 0; i < elements.size(); i++){
        if ( *elements[i] ){
            list.push_back( elements[i]->text );
        }
    }
    
    return list;
}

void checkList::checkMousePressed(ofPoint _mouse){
    if (inside(_mouse)){
        for(int i = 0; i < elements.size(); i++){
            if (elements[i]->checkMousePressed(_mouse))
                break;
        }
    }
}

void checkList::update(){
    float offSetY = 0;
    for(int i = 0; i < elements.size(); i++){
        elements[i]->x = x;
        elements[i]->y = y + offSetY;
        elements[i]->width = width;
        
        offSetY += elements[i]->height;
    }
    height = offSetY;
}

void checkList::draw(){
    for(int i = 0; i < elements.size(); i++){
        elements[i]->draw();
    }
}