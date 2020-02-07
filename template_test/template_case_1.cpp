//学习笔记：
//模板函数在类内定义没问题，在类外定义，只要在一个文件里也没问题。
//但是如果文件结构是main.cpp, function.h声明，function.cpp定义函数就会出错
//具体解释见：
//https://blog.csdn.net/dfq12345/article/details/78212002
//由于模板不是函数，只是一些C++编译器指令，说明了如何生成类和成员函数定义，无法单独编译成obj文件，因此不能将模板成员函数放在独立的实现文件中。模板必须与特定的模板实例化请求一起使用，最简单的方法是将所有的模板信息放在一个头文件中，并在要使用这些模板的文件中包含该头文件。

//我重建了一个case_2，只要把模板函数和定义的类放在一个文件里就能通过了，


#include <iostream>  
using namespace std ;  
template <class T>  
class Base  
{  
public :      
    T a ;  
    Base(T b)  
    {  
        a = b ;      
    }     
    T getA(){ return a ;} //类内定义   
    void setA(T c);  
};  
  
template <class T>   //模板在类外的定义   
void  Base<T>::setA(T c)  
{  
    a = c ;  
}  
  
int main(void)  
{  
    Base <int>b(4);  
    cout<<b.getA()<<endl;   
  
    Base <double> bc(4);  
    bc.setA(4.3);  
    cout<<bc.getA()<<endl;   
    return 0 ;      
}
