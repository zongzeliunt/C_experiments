#include <iostream> 
#include "template_declare.h"
using namespace std ;  
  
int main(void)  
{  
    Base <int>b(4);  
    cout<<b.getA()<<endl;   
  
    Base <double> bc(4);  
    bc.setA(4.3);  
    cout<<bc.getA()<<endl;   
    return 0 ;      
}
