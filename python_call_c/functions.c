#include <stdio.h>
#include <string.h>
#include "DATA_TYPE/DATA_TYPE_DEFINE.h"

void hello() 
{
    uint32 tmp = 0xff;
    printf ("hello ares %x\n", tmp);
}

uint32 cal (uint32 input)
{
    return input + 10;
}



