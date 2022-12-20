#include "func.h"
#include "define.h"
int global_val;

void print_hello ()
{
    global_val = 10;
    printf ("hello func ARES: %d, global_val = %d \n", CONST, global_val);
    
    global_val = 15;
}

