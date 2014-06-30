/* 
 * File:   CLog.cpp
 * Author: janprasil
 * 
 * Created on 27. květen 2014, 15:58
 */

#include "CLog.h"

FILE * CLog::logFile = NULL;
string CLog::fileName = "log.log";

CLog::CLog(const string & file) {        

    fileName = file;
    if (fopen(fileName.c_str(), "r") == NULL) {
        logFile = fopen(fileName.c_str(), "w"); 
        fputs("Time\t\tAction",logFile);
    }
    

}
CLog::CLog(const CLog & x) {}
CLog::~CLog() {}

void CLog::addAction(const string & action) {
    
    if (CConfig::CREATE_LOG) {
        logFile = fopen(fileName.c_str(), "a+");
        fputs(string(action+"\n").c_str(),logFile);
        fclose(logFile);
    }
    
  
}


