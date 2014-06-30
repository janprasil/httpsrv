#ifndef CSERVER_H
#define	CSERVER_H

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>

#include "CConfig.h"
#include "CPath.h"
#include "CRequest.h"
#include "CStatic.h"
#include "CFolder.h"
#include "CDynamic.h"
#include "CConnection.h"
#include "CLog.h"

#include "CBadAddressException.h"
#include "CListenException.h"
#include "CPortException.h"
#include "CSocketException.h"

using namespace std;

class CServer {
public:
    
    CServer  ( );
    CServer  ( const CServer& src );
    ~CServer ( );
    
    void run ( );
    
private:            
    
    int openSocket ( ) const;

};

#endif	/* CSERVER_H */
