
#include "local_lib.h"


void set_tmp_value(uint32 value)
{
    tmp_value = value;
}

uint32 get_tmp_value(uint32 value)
{
    return tmp_value;
}

void array_change (uint8 array[4][4], int add)
{
    for (int i = 0; i < 4; i ++) {
        for (int j = 0; j < 4; j ++) {
            array[i][j] += add + i * 4 + j;
        }
    }
}
