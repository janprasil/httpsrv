/* 
 * File:   CConfigException.h
 * Author: janprasil
 *
 * Created on 9. červen 2014, 12:39
 */

#ifndef CCONFIGEXCEPTION_H
#define	CCONFIGEXCEPTION_H

#include <iostream>
using namespace std;

class CConfigException {
public:
    CConfigException( const string & err );
    void print ( const string & x ) const;
private:

};

#endif	/* CCONFIGEXCEPTION_H */

