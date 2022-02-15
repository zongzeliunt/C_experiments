from ctypes import *
so_file = "./functions.so"
my_functions = CDLL(so_file)

my_functions.set_tmp_value(10)
print(my_functions.get_tmp_value())

my_functions.hello()

print(my_functions.cal(50))

