#include <iostream>
#include <stdlib.h>
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
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    cout << "Author is " << AUTHOR << endl ;
    cout << "First  num : " << a << endl ;
    cout << "Second num : " << b << endl ;
    myswap(a, b);
    cout << " < after swap > " << endl;
    cout << "First  num : " << a << endl ;
    cout << "Second num : " << b << endl ; 

    return 0 ;
}
