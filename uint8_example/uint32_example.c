#include <stdio.h>
#include <string.h>

typedef unsigned char uint8;
typedef unsigned int uint32;

int main ()
{
    //uint32 a;
    int a;
    int b;
    a = 0xffff0000;
       
    b = a >> 16;

    printf ("a 1: %x\n", a);
    printf ("a 2: %d\n", a);
    
    printf ("b 1: %x\n", b);
    printf ("b 2: %d\n", b);

}
