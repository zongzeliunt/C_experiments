#https://docs.python.org/3/library/ctypes.html
#c_uint
#c_char_p

from ctypes import *


so_file = "./functions.so"
my_functions = CDLL(so_file)

my_functions.set_tmp_value(10)
print(my_functions.get_tmp_value())

my_functions.hello()

print(my_functions.cal(50))
name = "" * 64
name = "ares"

s=c_char_p()
s.value = b"ares"

my_functions.show_string(s)
