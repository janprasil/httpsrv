/* 
 * File:   CStatic.cpp
 * Author: janprasil
 * 
 * Created on 29. květen 2014, 12:53
 */

#include "CStatic.h"

CStatic::CStatic( const CPath & path ):CRequest( path ) {}
CStatic::CStatic(const CStatic& orig):CRequest(orig.m_path) {}
CStatic::~CStatic() {}

void CStatic::process() {
    
    fstream file;
    string path = m_path.getFileInfo().at(0);
    path += "/";
    path += m_path.getFileInfo().at(1);
    
    file.open( path.c_str() );
    string s;
    
    if (file.is_open()) {
        while (getline(file, s)) m_output.append(s+"\n");
        file.close();
        this->setStat(200);
    } else {
        this->setStat(400);
    }
    
}

