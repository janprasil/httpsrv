/* 
 * File:   CConnection.cpp
 * Author: janprasil
 * 
 * Created on 6. červen 2014, 13:18
 */

#include "CConnection.h"

CConnection::CConnection( int listenFD ):m_listenFD(listenFD) {
   char                buffer[CConfig::BUFFER_SIZE];
   struct sockaddr     remote;
   socklen_t           remoteLen = sizeof ( remote );
  
   m_dataFD     = accept ( m_listenFD, &remote, &remoteLen );
   int l        = read   ( m_dataFD, buffer, sizeof ( buffer ));
   
   if ( ! l ) return;

   m_name = getFileNameFromRequest( buffer );
   getProcessedRequest();
   
}
CConnection::CConnection(const CConnection& orig) {}
CConnection::~CConnection() {
    close ( m_dataFD );
}
string CConnection::getFileNameFromRequest( char request[] ) const {
    
    char c;
    int i = 0;
    string word = "", lastWord = "", file = "", preFile = "";
    while (i < CConfig::BUFFER_SIZE) {
        
        c = request[i++];
        if (c==' ' ||c == '\n') {
            
            if (lastWord == "GET") {
                file = word;
                break;
            }
                        
            lastWord = word;
            word.erase(word.begin(), word.end());
            continue;
        }
        word.push_back(c);
        
    }
    
    if (file[file.length()-1] != '/' && CPath(file).getResult() == FOLDER_STATE) 
    {
        
        string data = "";
        data  = "HTTP/1.1 302 Found\r\n";
        data += "Location: "+file + "/";

        send(m_dataFD, data.c_str(), data.length() ,0);
        close ( m_dataFD );
        
    }
    
    return file;
    
}
void CConnection::getProcessedRequest(  ) {
    
    CPath path(m_name);
    
    if ( path.getResult() == STATIC ) {
        CStatic request( path );
        request.process();
        writeToClient(request);
    } else if ( path.getResult() == DYNAMIC ) { 
        CDynamic request( path, vector<pair<string,string> >() );
        request.process();
        writeToClient(request);
    } else if ( path.getResult() == FOLDER_STATE) {
        CFolder request( path );
        request.process();
        writeToClient(request);
    }
    
    
}
void CConnection::writeToClient( const CRequest & request ) const {
    
   string data;
   data  = request.getHead();
   data += "\r\n";
   data += request.getBody();
   
   send(m_dataFD, data.c_str(), data.length() ,0);
   
}
