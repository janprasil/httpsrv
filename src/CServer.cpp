/* 
 * File:   CServer.cpp
 * Author: janprasil
 * 
 * Created on 24. květen 2014, 11:41
 */

#include "CServer.h"

CServer::CServer(){
}
CServer::CServer(const CServer& orig){}
CServer::~CServer() {}

void CServer::run()  {
    
   int fd = openSocket ();
   
   if ( fd < 0 ) return; 
   
   CLog::addAction("The server was started.");
   CLog::addAction("The server '"+ CConfig::SERVER_NAME +"' is running on port: "+ CConfig::PORT);
   
   while ( 1 ) {
      
       CConnection conn(fd);
       //CLog::addAction(conn);
       //cout << conn << endl;
       
   }
   close ( fd );
   
}


int CServer::openSocket() const{
    
   struct addrinfo * ai;
   char name[10] = "localhost";

   if ( getaddrinfo ( name, CConfig::PORT.c_str(), NULL, &ai ) )
    {
      //throw CBadAddressException();
      return -1;
    }

   int fd = socket ( ai->ai_family, SOCK_STREAM, 0 );
   if ( fd == -1 )
    {
      freeaddrinfo ( ai );
      //throw CSocketException();
      return -1;
    }

   if ( bind ( fd, ai -> ai_addr, ai -> ai_addrlen ) == -1 )
    {
      close ( fd );
      freeaddrinfo ( ai );
      //throw CPortException();
      return -1;
    }
   freeaddrinfo ( ai );

   if ( listen ( fd, 10 ) == -1 )
    {
      close ( fd );
      //throw CListenException();
      return -1;
    }

   return fd;
    
}

