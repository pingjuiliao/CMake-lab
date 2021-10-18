#include "mylib.h"

int
mygcd(int a, int b) {
    if ( b == 0 ) return a;
    return mygcd(b, a % b) ;
}
