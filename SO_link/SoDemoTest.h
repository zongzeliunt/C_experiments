#ifndef __SO_DEMO_TEST_HEADER__
#define __SO_DEMO_TEST_HEADER__
#include <iostream>
using namespace std;
class ares_class {
    public:
         void print_hello ();   

};

#ifndef PUREC 
extern "C" { //如果用python flow， 必须把它暴露成C类型函数。但是用g++直接编译就不能这样了，所以要加PUREC这个-D
#endif
    void one();
    void two();
    void three();
    ares_class* gen_class_obj(); 
    void ares_class_call_print_hello (ares_class* class_obj);

    
#ifndef PUREC
}
#endif




#endif
