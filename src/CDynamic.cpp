/* 
 * File:   CDynamic.cpp
 * Author: janprasil
 * 
 * Created on 29. květen 2014, 12:53
 */

#include "CDynamic.h"

CDynamic::CDynamic( const CPath & path, vector< pair<string,string> >  ):CRequest( path ) {}
CDynamic::CDynamic( const CDynamic& orig ):CRequest(orig.m_path) {}
CDynamic::~CDynamic() {}

void CDynamic::process() {
    
    this->setStat(200);
    string completePath = m_path.getFileInfo().at(0) + "/" + m_path.getFileInfo().at(1);
    string v = completePath + "  2>&1 1>/dev/null";
    if (!shell(v).empty()) {
        this->setStat(500);
        return;
    }
    
    m_output = shell(completePath);
    
}

string CDynamic::shell( const string & v ) const {
    
    string toReturn;

    FILE * p = popen(v.c_str(), "r");
    char buffer[256];
    
    while(fgets(buffer, sizeof(buffer), p) != NULL)
        toReturn += string(buffer).substr(0, string(buffer).size() - 1);

    pclose(p);
    return toReturn;
    
    
}

