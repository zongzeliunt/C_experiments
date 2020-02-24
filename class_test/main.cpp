#include <iostream>
#include "test_class.h"
using namespace std;

int main ()
{
	//p是一个基类指针
	test_base *p;

	//首先声明个base类对象
	test_base base (0);
	p = &base;
	//这里出现的就是说我是基类
	cout<<"这是通过基类的指针调用基类的虚函数"<<endl;
	p->class_classify();





	//继承类b c
	cout<<"定义 B"<<endl;
	test_heri b(float(11.4));
	b.change_double_data(double(14.3));
	b.change_int_data(int(8));
	
	cout<<"定义 C"<<endl;
	test_heri c(float(7.4));
	c.change_int_data(int(7));
	c.change_double_data(double(1.7));
	
	//继承类 result
	cout<<"定义继承类 "<<endl;
	test_heri result(0);
	//测试运算符重载
	result = c+b;

	p = &result;
	//get_int_data 和 get_float_data函数是在基类里定义的
	cout<<"继承类的int "<<p->get_int_data()<<endl;
	cout<<"继承类的float "<<p->get_float_data()<<endl;
	
	//p 是一个基类指针，但是指向了继承类，由于继承类覆盖了基类的函数，所以p其实call的是继承类定义的函数
	
	cout<<"这是通过基类的指针调继承类的虚函数"<<endl;
	p->class_classify();

	//get_double_data 是在继承类里定义的，所以不能通过基类的指针来调用。
	
	cout<<"继承类的double "<<result.get_double_data()<<endl;
	cout<<"这是通过继承类的对象调用继承类的虚函数"<<endl;
	result.class_classify();
	//这是在继承类里的第二次定义运算符重载
	cout<<"继承类运算符重载 "<<c + 100 <<endl;

	return 0;
}
