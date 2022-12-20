#include <stdio.h>
#include <string.h>

typedef unsigned char uint8;

typedef char int8;

int main ()
{
    uint8 a;
    a = 0xff;
    printf ("a: %x\n", a);
    
    int8 b;
    b = -128;
    printf ("b: %x, %d, %d\n", b, b, b + 128);

}
