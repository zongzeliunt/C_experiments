//ѧϰ�ʼǣ�
//ģ�庯�������ڶ���û���⣬�����ⶨ�壬ֻҪ��һ���ļ���Ҳû���⡣
//��������ļ��ṹ��main.cpp, function.h������function.cpp���庯���ͻ����
//������ͼ���
//https://blog.csdn.net/dfq12345/article/details/78212002
//����ģ�岻�Ǻ�����ֻ��һЩC++������ָ�˵�������������ͳ�Ա�������壬�޷����������obj�ļ�����˲��ܽ�ģ���Ա�������ڶ�����ʵ���ļ��С�ģ��������ض���ģ��ʵ��������һ��ʹ�ã���򵥵ķ����ǽ����е�ģ����Ϣ����һ��ͷ�ļ��У�����Ҫʹ����Щģ����ļ��а�����ͷ�ļ���

//���ؽ���һ��case_2��ֻҪ��ģ�庯���Ͷ���������һ���ļ������ͨ���ˣ�


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
    T getA(){ return a ;} //���ڶ���   
    void setA(T c);  
};  
  
template <class T>   //ģ��������Ķ���   
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
