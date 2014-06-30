//
//  CConfig.cpp
//  http-server
//
//  Created by Jan Prášil on 19.05.14.
//  Copyright (c) 2014 Jan Prášil. All rights reserved.
//

#include "CConfig.h"

string         CConfig::PORT           = "8080";
string         CConfig::FOLDER         = "htdocs";
bool           CConfig::CREATE_LOG     = true;
string         CConfig::SERVER_NAME    = "localhost";
string         CConfig::PAGE404        = "404.html";
int            CConfig::BUFFER_SIZE    = 1024;
bool           CConfig::VALID_FILE     = false;
vector<string> CConfig::defaultStatic  = vector<string>();
vector<string> CConfig::defaultDynamic = vector<string>();
vector<string> CConfig::defaultFile    = vector<string>(); 

CConfig::CConfig ( const string  & inFile ) {
    
    ifstream configFile ( inFile.c_str() );
    string line = "";
    
    if (configFile.is_open())
    {
        while ( getline (configFile, line) ) parseLine( line );
        VALID_FILE = true;
        configFile.close();
    } 
    
}
CConfig::CConfig ( const CConfig & src    ) {
    
    PORT           = src.PORT;                       
    FOLDER         = src.FOLDER;
    CREATE_LOG     = src.CREATE_LOG;
    SERVER_NAME    = src.SERVER_NAME;
    PAGE404        = src.PAGE404;
    BUFFER_SIZE    = src.BUFFER_SIZE;
    VALID_FILE     = src.VALID_FILE;
    defaultStatic  = src.defaultStatic;
    defaultDynamic = src.defaultDynamic;
    defaultFile    = src.defaultFile;
    
}
CConfig::~CConfig( ) {}

void           CConfig::parseLine            ( const string & x ) {
    
    string  name;
    string  value;
    bool    sign = false;
    char    c;
    
    for (int i = 0; i<x.length(); i++ ) {
        
        c = x[i];
        if (c == '=') {
            sign = true;
            c = x[++i];
        }
        if (c == ' ') continue;
        
        if (sign) {
            value.push_back(c);
        } else {
            name.push_back(c);
        }
        
    }
   
    if (name == "DEFAULT_STATIC")  defaultStatic  = processMultipleChoice( value );
    if (name == "DEFAULT_DYNAMIC") defaultDynamic = processMultipleChoice( value );
    if (name == "DEFAULT_FILE")    defaultFile    = processMultipleChoice( value );
    
    if (name == "SERVER_NAME")    SERVER_NAME     = value;
    if (name == "BUFFER_SIZE")    BUFFER_SIZE     = stringToInt(value);
    if (name == "PORT")           PORT            = value;
    if (name == "FOLDER" )        FOLDER          = value;
    if (name == "PAGE404" )       PAGE404         = value;
    if (name == "LOG" )           CREATE_LOG      = (value == "TRUE")?true:false;
    
}
bool           CConfig::isDynamic            ( const string & ext ) {
    return (find(defaultDynamic.begin(), defaultDynamic.end(), ext) == defaultDynamic.end())?false:true;
}
int            CConfig::stringToInt          ( const string & x ) const {
    
    int  toReturn = 0;
    char c;
    
    for ( int i = 0; i<x.length(); i++ ) {
        
        c = x[i];
        if ( ((int) c - 48) > 9 || ((int) c - 48) < 0 ) {
            //throw CConfigException("Number expected");
            return 1024;
        }
        toReturn += (((int) c) - 48) * pow(10, x.length()-i-1);
        
    }
    return toReturn;
    
}
vector<string> CConfig::getDefaultFiles      ( ) {
    return defaultFile;
}
vector<string> CConfig::processMultipleChoice( const string & value ) const {
    
    vector<string> toReturn; 
    string         word;
    char           c;
    
    for(int i=0; i<value.length(); i++)  {
        
        c = value[i];
        if (c==',') {
            toReturn.push_back(word);
            word.erase(word.begin(),word.end());
            continue;
        }
        word.push_back(c);
    }
    
    if (word != "")
        toReturn.push_back(word);
    
    return toReturn;
    
}