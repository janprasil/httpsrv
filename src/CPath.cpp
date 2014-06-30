/* 
 * File:   CPath.cpp
 * Author: janprasil
 * 
 * Created on 2. červen 2014, 10:55
 */

#include "CPath.h"

CPath::CPath( const string & file ):m_fileName(""),m_MIMEType(""),m_isFile(false),m_exists(true),m_isStatic(true),m_isDir(false){
    //Gettting the complete path to a file on a server.
    string completePath = CConfig::FOLDER + file;
    //Determinating the type of the goal.
    
    m_isFile = isFile(completePath);
    m_isDir  = isDir (completePath);

    if (!(m_isFile || m_isDir)) {
        m_exists = false;
        return;
    }
    
    if (m_isDir) {
        
        if (completePath[completePath.length()-1] == '/') completePath.erase(completePath.end()-1, completePath.end());
        m_path = completePath;
        //we are checking default files - index etc. 
        string defaultFile = findIndex(completePath);
        
        if (defaultFile.empty()) return;
        m_isDir  = false;
        m_isFile = true;
        m_exists = true;
        completePath += "/" + defaultFile;
        
    }
  
    //Getting the filename, the location
    int position = completePath.find_last_of("/");
    m_fileName   = completePath.substr(position+1);
    m_path       = completePath.substr(0, position);
    //Getting the extension of the file.
    position         = completePath.find_last_of(".");
    string extension = completePath.substr(position+1);
    m_isStatic      = !(m_isDynamic = CConfig::isDynamic( extension ));
    m_MIMEType      = determineMIMEType( extension );
    
    
}
CPath::CPath( const CPath & orig ) {
    
    m_fileName = orig.m_fileName;
    m_isFile   = orig.m_isFile;
    m_exists   = orig.m_exists;
    m_path     = orig.m_path;
    m_MIMEType = orig.m_MIMEType;
    m_isStatic = orig.m_isStatic;
    m_isDynamic = orig.m_isDynamic;
    
}
CPath::~CPath() {}

string CPath::getMIMEType() const {
   return m_MIMEType;
}
string CPath::determineMIMEType( const string & ext ) const {
    
    string type;
    
    type = "text/html";
    if (ext == "jpg") type = "image/jpeg";
    if (ext == "jpeg")type = "image/jpeg";
    if (ext == "png") type = "image/png";
    if (ext == "gif") type = "image/gif"; 
    if (ext == "mp3") type = "audio/mpeg";
    if (ext == "pdf") type = "application/pdf";
    if (ext == "css") type = "text/css" ;
    if (ext == "js")  type = "text/javascript";
       
    return type;
    
}

int CPath::getResult() const {

    if (!m_exists)        return -1;
    if (m_isDir)          return  0;
    if (m_isStatic)       return  1;
    if (m_isDynamic)      return  2;
    return -2;

}

vector<string> CPath::getFileInfo() const {

    vector<string> toReturn;
    toReturn.push_back(m_path);
    toReturn.push_back(m_fileName);
    return toReturn;

}  
bool CPath::isFile(const string & path) const {
    struct stat buffer;
    stat(path.c_str(), &buffer);
    return S_ISREG(buffer.st_mode);
}
bool CPath::isDir(const string & path) const {
    struct stat buffer;
    stat(path.c_str(), &buffer);
    return S_ISDIR(buffer.st_mode);
}
string CPath::findIndex(const string & completePath) const {
    
    vector<string> defaultFiles = CConfig::getDefaultFiles();

    for (int i=0; i<defaultFiles.size(); i++) {
        if (isFile(completePath + "/" + defaultFiles.at(i))) 
                return defaultFiles.at(i);
    }
    
    return "";
    
}
vector< pair<string,string> > CPath::processVariables( const string & x ) const {
    
    vector< pair<string,string> > toReturn;
    return toReturn;
    
}