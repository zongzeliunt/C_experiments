from ctypes import *
import os

class test:
    so_file = "./libtest.so"
    func_lib = None
    def __init__(self):
        if os.path.exists(self.so_file):
            self.func_lib = CDLL(self.so_file)
            print ("ARES init " + self.so_file)
            self.ares_class_obj = self.func_lib.gen_class_obj()
     
test = test()
test.func_lib.one()
#test.func_lib.two()
#test.func_lib.three()

test.func_lib.ares_class_call_print_hello (test.ares_class_obj)

