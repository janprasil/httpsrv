/* 
 * File:   CListenException.cpp
 * Author: janprasil
 * 
 * Created on 9. červen 2014, 12:34
 */

#include "CListenException.h"

CListenException::CListenException() {
    print("Initializing listen error.");
}

void  CListenException::print( const string & x ) {
        cout << x << endl;
}
