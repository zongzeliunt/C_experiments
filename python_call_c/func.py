
from ctypes import *

def show_string_flow(my_functions, string):
    s=c_char_p()
    s.value = bytes(string, 'utf-8')

    my_functions.show_string(s)

def array_change (my_functions, array):
    array_p = (c_uint8 * 16)(*array)
    my_functions.array_change (array_p, 0)
    #my_functions.array_change (*array, 5)
    
    for i in range (0,4):
        for j in range (0,4):
            print (str(i) + " " + str(j) + " " + str(array_p[i * 4 + j]))
            array[i * 4 + j] = array_p[i * 4 + j]


