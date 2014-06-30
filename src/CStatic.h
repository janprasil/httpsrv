/* 
 * File:   CStatic.h
 * Author: janprasil
 *
 * Created on 29. květen 2014, 12:53
 */

#ifndef CSTATIC_H
#define	CSTATIC_H

#include "CRequest.h"

class CStatic : public CRequest {
public:
    
    CStatic( const CPath & path );
    CStatic( const CStatic& orig );
    ~CStatic();
    
    void process();
    
};

#endif	/* CSTATIC_H */

