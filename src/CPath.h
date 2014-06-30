/* 
 * File:   CPath.h
 * Author: janprasil
 *
 * Created on 2. červen 2014, 10:55
 */

#ifndef CPATH_H
#define	CPATH_H

#include <sys/stat.h>
#include <iostream>
#include <vector>
#include "CConfig.h"

using namespace std;

class CPath {
public:
    CPath( const string & file  );
    CPath( const CPath&  orig );
    ~CPath();
    
    int            getResult  () const;
    vector<string> getFileInfo() const;
    string         getMIMEType() const;
    
private:
    
    bool                          isFile            ( const string & path ) const;
    bool                          isDir             ( const string & path ) const;
    string                        findIndex         ( const string & file ) const;
    string                        determineMIMEType ( const string & ext  ) const;
    vector< pair<string,string> > processVariables  ( const string & x    ) const;
    
    bool                          m_exists;
    bool                          m_isFile;
    bool                          m_isDir;
    bool                          m_isStatic;
    bool                          m_isDynamic;
    string                        m_MIMEType;
    string                        m_path;
    string                        m_fileName;
    vector< pair<string,string> > variables;
    
};

#endif	/* CPATH_H */

