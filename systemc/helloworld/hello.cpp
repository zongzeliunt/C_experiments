#if 1

#include "hello.h"

#else
#include "systemc.h"

class hello : public sc_module{
public:
        hello(sc_module_name name) : sc_module(name){
                cout<<"Hello,SystemC!"<<endl;
        }
};
#endif

int sc_main(int argc,char** argv){
        hello h("hello");
        return 0;
}
