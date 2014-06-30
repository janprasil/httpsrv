/* 
 * File:   CFolder.h
 * Author: janprasil
 *
 * Created on 29. květen 2014, 12:54
 */

#ifndef CFOLDER_H
#define	CFOLDER_H

#include "CRequest.h"
#include <dirent.h>
#include <iostream>

using namespace std;

class CFolder : public CRequest {
public:
    
    CFolder( const CPath & path, int styleType = 0 );
    CFolder(const CFolder& orig);
    ~CFolder();
    
    void process();
    
private:
    
    vector<string> getFolderContent() const;

};


#endif	/* CFOLDER_H */

