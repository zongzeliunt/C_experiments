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
    T getA(){ return a ;} //���ڶ���   
    void setA(T c);  
};  
  
template <class T>   //ģ��������Ķ���   
void  Base<T>::setA(T c)  
{  
    a = c ;  
}  
