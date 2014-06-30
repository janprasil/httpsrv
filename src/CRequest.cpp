/* 
 * File:   CRequest.cpp
 * Author: janprasil
 * 
 * Created on 29. květen 2014, 12:25
 */

#include "CRequest.h"
#define SERVER_STRING "Server: jdbhttpd/0.1.0\r\n"


CRequest::CRequest( const CPath & path  ):m_path(path) {}
CRequest::CRequest(const CRequest& orig):m_path(orig.m_path) {
    m_status = orig.m_status;
    m_output = orig.m_output;
}
CRequest::~CRequest() {}

void CRequest::setStat(int stat) {
    
    switch (stat) {
        
        case 200:
            m_status = 200;
            break;
        case 400:
            m_status = 400;
            break;
        default:
            m_status = 500;
            m_output = "<html><head><title>ERROR</title></head><body><h1>SERVER ERROR 500</h1></body>";
    }
    
}
string CRequest::getHead() const { 
    
    string toReturn;
    switch (m_status) {
        
        case 200:
            toReturn = "HTTP/1.1 200 OK\r\n";
            break;
        case 400:
            toReturn = "HTTP/1.1 200 OK\r\n";
            break;
        case 500:
            toReturn = "HTTP/1.1 500 INTERNAL SERVER ERROR\r\n";
    }
    
   toReturn += SERVER_STRING;
   toReturn += "Content-Type: ";
   toReturn += m_path.getMIMEType();
   toReturn +="\r\n";
   return toReturn;

}
string CRequest::getBody() const { 
    
    return m_output;

}

