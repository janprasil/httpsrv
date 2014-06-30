/* 
 * File:   CRequest.h
 * Author: janprasil
 *
 * Created on 29. květen 2014, 12:25
 */

#ifndef CREQUEST_H
#define	CREQUEST_H

#include <iostream>
#include "CPath.h"

using namespace std;

class CRequest {
public:
    
    CRequest( const CPath& path);
    CRequest(const CRequest& orig);
    virtual ~CRequest();
    
    virtual void process() = 0;
    
    string getHead() const;
    string getBody() const;
    
protected:
    
    void setStat(int state); //200 - v případě, že je output prázdný
    
    CPath  m_path;
    int    m_status;
    string m_type;
    string m_output;
    
};

#endif	/* CREQUEST_H */
