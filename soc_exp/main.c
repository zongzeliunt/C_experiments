#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char uint8;
typedef unsigned int uint32;

struct bit {
    int a:3;
    int b:2;
    int c:3;
};

int main ()
{
    int *a, *c;
    int b;
    uint32 d,e; 
    
    struct bit bit_obj = {0x2, 0x2, 0x2};
    
    c = &b;

    a = malloc (sizeof(int) * 2);
    printf ("a size: %ld\n", sizeof(a)); //8
    printf ("b size: %ld\n", sizeof(b)); //4
    
    a[0] = 1;
    *(a + 1) = 2;
    *c = 3;
    printf ("a[0]: %d, a[1]: %d\n", a[0], a[1]); 
    printf ("b: %d\n", b); 
   
 
    d = 0xfedcba98;
    e = d & 0x0f000000; //&：与，| 或，^ 异或，~ 反。
    printf ("e: %x, e move: %x\n", e, e >> 24);


    printf ("bit obj size: %ld\n", sizeof(bit_obj)); //4
    printf ("bit.a: %d\n", bit_obj.a);//2
    printf ("bit.b: %d\n", bit_obj.b);//-2
    printf ("bit.c: %d\n", bit_obj.c);//2

    return 0;
}


