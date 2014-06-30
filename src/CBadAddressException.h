/* 
 * File:   CBadAddressException.h
 * Author: janprasil
 *
 * Created on 9. červen 2014, 12:26
 */

#ifndef CBADADDRESSEXCEPTION_H
#define	CBADADDRESSEXCEPTION_H

#include <iostream>
using namespace std;

class CBadAddressException {
    
public:
    
    CBadAddressException();
    void print( const string & x );
    
};


#endif	/* CBADADDRESSEXCEPTION_H */

