/* 
 * File:   CLog.h
 * Author: janprasil
 *
 * Created on 27. květen 2014, 15:58
 */

#ifndef CLOG_H
#define	CLOG_H

#include <iostream>
#include <stdio.h>
#include "CConfig.h"


using namespace std;


class CLog {
public:
    
    CLog(const string & file);
    CLog(const CLog & src);
    ~CLog();
    
    static void addAction( const string & action );
    
    static string fileName;
    static FILE * logFile;
    
private:
    
    
    
};

#endif	/* CLOG_H */

