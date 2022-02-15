#include <stdio.h>
#include <string.h>
#include "DATA_TYPE/DATA_TYPE_DEFINE.h"
#include "local_lib.h"


void hello() 
{
    uint32 tmp = 0xff;
    printf ("hello ares %x\n", tmp);
}


uint32 cal (uint32 input)
{
    return input + tmp_value;
}

void show_string(char name[64])
{
    char name_1[64];
    strcpy(name_1, "ares_1"); 
    
    char name_2[64];
    strcpy(name_2, name); 

    printf ("show string: %s, %s\n", name, name_1);
}

