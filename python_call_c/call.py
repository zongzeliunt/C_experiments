from ctypes import *
so_file = "./functions.so"
my_functions = CDLL(so_file)

my_functions.hello()

print(my_functions.cal(50))

