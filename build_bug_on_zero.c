#include <stdio.h>
 
#define BUILD_BUG_ON_ZERO(e)    (sizeof(struct { int:-!!(e); }))
 
int main(void)
{
        int a = 2;
 
        //run time     才知道 error: bit-field '<anonymous>' width not an integer constant
        //BUILD_BUG_ON_ZERO(a==2);
        //compile time 就知道 error: negative width in bit-field '<anonymous>'
        //BUILD_BUG_ON_ZERO(2 == 2);
 
        return 0;
}