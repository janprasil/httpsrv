//
//  CConfig.h
//  http-server
//
//  Created by Jan Prášil on 19.05.14.
//  Copyright (c) 2014 Jan Prášil. All rights reserved.
//

#ifndef __http_server__CConfig__
#define __http_server__CConfig__

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include "CConfigException.h"

using namespace std;

class CConfig {
    
public:
    
    CConfig ( const string & inFile );
    CConfig ( const CConfig & src );
    ~CConfig();
    
    static vector<string> getDefaultFiles();
    static bool           isDynamic( const string & path );
    
    static bool   VALID_FILE;
    static bool   CREATE_LOG;
    static int    BUFFER_SIZE;
    static string SERVER_NAME;
    static string PORT;
    static string FOLDER;
    static string PAGE404;
    static vector<string> defaultStatic;
    static vector<string> defaultDynamic;
    static vector<string> defaultFile;
    
        
private:
    
    void           parseLine            ( const string & x );
    int            stringToInt          ( const string & x ) const;
    vector<string> processMultipleChoice( const string & x ) const;
    
    
};

#endif /* defined(__http_server__CConfig__) */
