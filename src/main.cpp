//
//  HTTP-SERVER PROJECT
//  
//
//  Created by Jan Prášil on 19.05.14.
//  Copyright (c) 2014 Jan Prášil. All rights reserved.
//

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
#include "CServer.h"
#include "CStatic.h"
#include "CLog.h"

using namespace std;

int main()
{
    
    string inFile = "config.ini";
    CConfig configuration( inFile );

    CLog ( CConfig::SERVER_NAME + ".log" );
    
    CServer server;
    server.run();
    
    
    return 0;
}

