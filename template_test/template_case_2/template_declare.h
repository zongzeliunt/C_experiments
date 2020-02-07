using namespace std;

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
