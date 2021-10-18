#include <iostream>
#include <string>
#include "config.h"
#ifdef USE_MYLIB
#include "mylib.h"
#endif
using namespace std;

int
main(int argc, char** argv) {
    if ( argc < 3 ) {
        return -1;
    }

    int a = stoi(argv[1]);
    int b = stoi(argv[2]);
    cout << MYNAME << endl ;
    cout << "this is a : " << a << endl ;
    cout << "this is b : " << b << endl ; 
#ifdef USE_MYLIB
    myswap(a, b);
#else
    int tmp = a ; a = b ; b = tmp;
#endif
    cout << "< after swap >" << endl ;
    cout << "this is a : " << a << endl ;
    cout << "this is b : " << b << endl ; 

#ifdef USE_MYLIB
    int c = mygcd(a, b) ;
    cout << "Their gcd is " << c << endl ;
#endif

    return 0 ;

}
