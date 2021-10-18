#include "mylib.h"
#include <stdio.h>
int
mygcd(int a, int b) {

#if defined(HAVE_PUTS) 
    puts("Calculating...") ;    
#endif
    if ( b == 0 ) return a;
    return mygcd(b, a % b) ;
}
