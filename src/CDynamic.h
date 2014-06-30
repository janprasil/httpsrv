/* 
 * File:   CDynamic.h
 * Author: janprasil
 *
 * Created on 29. květen 2014, 12:53
 */

#ifndef CDYNAMIC_H
#define	CDYNAMIC_H

#include "CRequest.h"
#include "CPath.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class CDynamic : public CRequest{
public:
    
    CDynamic( const CPath & path, vector< pair<string,string> > = vector< pair<string,string> >() );
    CDynamic(const CDynamic& orig);
    ~CDynamic();
    
    void process();
    
private:
    
    string shell(const string & x) const;
    
};

#endif	/* CDYNAMIC_H */

