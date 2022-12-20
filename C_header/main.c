
#include "func.h"
#include "define.h"

extern int global_val;

int main (void) 
{
    print_hello();
    printf ("hello main ARES: %d, global_val = %d \n", CONST, global_val);

    return 0;
}
