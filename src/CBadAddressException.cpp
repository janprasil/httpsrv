/* 
 * File:   CBadAddressException.cpp
 * Author: janprasil
 * 
 * Created on 9. červen 2014, 12:26
 */

#include "CBadAddressException.h"

CBadAddressException::CBadAddressException() {
        print ("Badd Address.");
}

void CBadAddressException::print( const string & x ) {
        cout << x << endl;
}