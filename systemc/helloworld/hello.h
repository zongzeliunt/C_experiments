#ifndef _HELLO_H
#define _HELLO_H
#include "systemc.h"

SC_MODULE(hello){
        SC_CTOR(hello){
                cout<<"Hello,SystemC!"<<endl;
        }
};
#endif
