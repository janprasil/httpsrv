/* 
 * File:   CConfigException.cpp
 * Author: janprasil
 * 
 * Created on 9. červen 2014, 12:39
 */

#include "CConfigException.h"

CConfigException::CConfigException( const string & err ) {
    
    print("There is an error in configuration file: " + err + ".");
    
}

void CConfigException::print ( const string & x) const {
    cout << x << endl;
}
