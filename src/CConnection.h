/* 
 * File:   CConnection.h
 * Author: janprasil
 *
 * Created on 6. červen 2014, 13:18
 */

#ifndef CCONNECTION_H
#define	CCONNECTION_H

#define FOLDER_STATE 0
#define DYNAMIC 2
#define STATIC 1
#define DOWNLOADABLE 3
#define DOESNOTEXIST -1

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>

#include "CRequest.h"
#include "CStatic.h"
#include "CDynamic.h"
#include "CFolder.h"


using namespace std;

class CConnection {
public:
    
    CConnection ( int listenFD );             
    CConnection ( const CConnection& orig );
    ~CConnection();
        
    void getProcessedRequest ( ) ;
    void writeToClient       ( const CRequest & request) const;
    
private:
    
    string   getFileNameFromRequest ( char x[] ) const;
    
    string   m_name;
    int      m_listenFD;
    int      m_dataFD;
};

#endif	/* CCONNECTION_H */

