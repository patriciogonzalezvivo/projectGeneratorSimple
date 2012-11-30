//
//  ofxPugiXml.h
//  projectGenerator
//
//  Created by Patricio Gonzalez Vivo on 11/29/12.
//
//

#ifndef OFXPUGIXML_H_
#define OFXPUGIXML_H_

#include "pugixml.hpp"


//  Not sure about this.
//
typedef pugi::xml_document      ofxDocument;
typedef pugi::xml_node          ofxNode;
typedef pugi::xml_node_type     ofxNodeType;

typedef pugi::xpath_node        ofxPathNode;
typedef pugi::xpath_node_set    ofxPathNodeSet;

typedef pugi::xml_parse_result  ofxParserResult;
typedef pugi::xml_parse_status  ofxParserStatus;

#endif
