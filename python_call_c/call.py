#https://docs.python.org/3/library/ctypes.html
#c_uint
#c_char_p

from ctypes import *
from func import *
    

so_file = "./functions.so"
my_functions = CDLL(so_file)

my_functions.set_tmp_value(10)
print(my_functions.get_tmp_value())

my_functions.hello()



print(my_functions.cal(50))
name = "" * 64
name = "ares"

show_string_flow(my_functions, name)

array = [1] * 16

array_change (my_functions, array)

print ("RESULT")

for i in range (0,4):
    for j in range (0,4):
        print (str(i) + " " + str(j) + " " + str(array[i * 4 + j]))
