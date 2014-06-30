/* 
 * File:   CSocketException.cpp
 * Author: janprasil
 * 
 * Created on 9. červen 2014, 12:34
 */

#include "CSocketException.h"

CSocketException::CSocketException() {
    print("A socket error.");
}

void CSocketException::print( const string & x ) {
        cout << x << endl;
}
