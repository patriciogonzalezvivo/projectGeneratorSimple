#pragma once

#include "ofMain.h"

#include "ofAddon.h"
#include "CBLinuxProject.h"
#include "CBWinProject.h"
#include "visualStudioProject.h"
#include "xcodeProject.h"
#include <Poco/Path.h>

#include "ofxGui.h"
#include "ofxXmlSettings.h"

#include "textButton.h"
#include "checkList.h"

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
    void    loadProject(string _path);
    string  setTarget(int targ);
    void    generateProject();
    
    string  appToRoot;
    string  defaultLoc;
    string  addonsPath;
    
    baseProject *project;
    
    //  Addons
    //
    void    loadAddons();
    bool    selectAddon(string _addonName);
    bool    isAddonCore(string _addonName);
    vector<string> coreAddons;
    
    //  GUI
    //
    int mode;
    enum { MODE_NORMAL, MODE_ADDON, MODE_PLATFORM };
    
    ofxPanel        panelPlatforms;
    ofxToggle       osxToggle, iosToggle, wincbToggle, winvsToggle, linuxcbToggle, linux64cbToggle;
    
//    ofxPanel        panelCoreAddons;
//    ofxPanel        panelOtherAddons;
    checkList       coreAddonsList;
    checkList       otherAddonsList;
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
