/* 
 * File:   CFolder.cpp
 * Author: janprasil
 * 
 * Created on 29. květen 2014, 12:54
 */

#include "CFolder.h"

CFolder::CFolder( const CPath & path, int styleType ):CRequest( path ) {}
CFolder::CFolder(const CFolder& orig):CRequest(orig.m_path) {}
CFolder::~CFolder() {}

void CFolder::process() {
    
    this->setStat(200);
    m_output = "<html><head><title>The list of directory" + m_path.getFileInfo().at(0) + "</title></head><body>";
    
    m_output += "<h1>The list of content in directory "+ m_path.getFileInfo().at(0) +"</h1>";
    m_output += "<ul>";
    
    for (string x : getFolderContent()) {
        
        m_output += "<li><a href=\"./"+ x +"\">"+ x +"</a></li>";
        
    }
    
    m_output += "</ul></body></html>";
    
}

vector<string> CFolder::getFolderContent() const {
    
    vector<string> toReturn;
    
    string path = m_path.getFileInfo().at(0);
    path += "/";
    path += m_path.getFileInfo().at(1);
    
    DIR *dir;
    struct dirent *ent;
    
    if ((dir = opendir (path.c_str())) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
        toReturn.push_back(ent->d_name);
      }
      closedir (dir);
    } 
    
    return toReturn;
    
    
}

