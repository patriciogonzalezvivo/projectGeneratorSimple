#pragma once

//#define COMMAND_LINE_ONLY

#include "ofMain.h"
#include "CBLinuxProject.h"
#include "CBWinProject.h"
#include "visualStudioProject.h"
#include "xcodeProject.h"
#include <Poco/Path.h>

#include "ofxGui.h"
#include "ofAddon.h"
#include "ofxXmlSettings.h"
#include "textButton.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
 
    //  Project
    //
    string  setupForTarget(int targ);
    void    loadProject(string _path);
    void    generateProject();
    
    bool    isAddonCore(string addon);
    bool    bInited;
    vector<string> coreAddons;
    
    string  appToRoot;
    string  defaultLoc;
    string  addonsPath;
    
    baseProject *project;
    
    //  GUI
    //
    int mode;
    enum { MODE_NORMAL, MODE_ADDON, MODE_PLATFORM };
    
    ofxPanel        panelPlatforms;
    ofxToggle       osxToggle, iosToggle, wincbToggle, winvsToggle, linuxcbToggle, linux64cbToggle;
    
    ofxPanel        panelCoreAddons;
    ofxPanel        panelOtherAddons;
    bool            bHaveNonCoreAddons;
    
    vector<textButton> buttons;
    textButton      addonButton;
    textButton      generateButton;
    
    //  Status
    //
    string  status;
    float   statusSetTime;
    float   statusEnergy;
    void    setStatus(string newStatus);
    
    //  Design
    //
    ofImage logo;
    ofTrueTypeFont font;
    ofTrueTypeFont titleFont;
    ofTrueTypeFont secondFont;
		
    float uiLeftX;
};
