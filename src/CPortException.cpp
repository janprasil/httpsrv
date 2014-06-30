/* 
 * File:   CPortException.cpp
 * Author: janprasil
 * 
 * Created on 9. červen 2014, 12:35
 */

#include "CPortException.h"

CPortException::CPortException() {
    print("This port is occupied.");
}

void CPortException::print( const string & x ) {
        cout << x << endl;
}