#include <iostream>
#include "test_class.h"
using namespace std;

int main ()
{

	cout<<"B"<<endl;
	test_heri b(float(11.4));
	b.change_double_data(double(14.3));
	b.change_int_data(int(8));
	
	cout<<"C"<<endl;
	test_heri c(float(7.4));
	c.change_int_data(int(7));
	c.change_double_data(double(1.7));

	test_heri result(0);

	result = c+b;
	
	/*
	可以定义一个基类指针指向继承类，这样就可以call基类的函数了：
	*/
	test_base *p;
	p = &result;
	cout<<p->get_int_data()<<endl;
	cout<<p->get_float_data()<<endl;
	//p 是一个基类指针，但是指向了继承类，由于继承类覆盖了基类的函数，所以p其实call的是继承类定义的函数
	p->class_classify();

	
	cout<<result.get_double_data()<<endl;
	result.class_classify();
	cout<<c + 100 <<endl;

	return 0;
}
