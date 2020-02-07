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

	cout<<result.get_int_data()<<endl;
	cout<<result.get_float_data()<<endl;
	cout<<result.get_double_data()<<endl;
	cout<<c + 100 <<endl;

	return 0;
}
