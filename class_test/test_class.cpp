#include <iostream>
#include "test_class.h"
using namespace std;

//###############################################################
//基类：
//构造函数和重载
//{{{
test_base::test_base(int data) {
	int_data = data;
	float_data = 0;
}

test_base::test_base(float data) {
	//这个是构造函数重载
	int_data = 0;
	float_data = data;
}
//}}}

//两种类型的修改和输出函数
//{{{
void test_base::change_int_data (int data) {
	int_data = data;
}

int test_base::get_int_data () {
	return int_data;
}

void test_base::change_float_data (float data) {
	float_data = data;
}

float test_base::get_float_data () {
	return float_data;
}
//}}}

//函数重载
//{{{
int test_base::add_data(int data)
{
	return data + int_data;
}

float test_base::add_data(float data)
{
	return data + float_data;
}
//}}}

//###############################################################
//继承类
//构造函数和对基类函数的重载
//{{{
test_heri::test_heri(int data): test_base(data) {
	//手动赋值，其实可以赋值成任何值
	change_int_data(data);
}

test_heri::test_heri(float data): test_base(data) {
	//什么也不干，就是调用test_base 的构造函数把float型的data写到float_data
}

test_heri::test_heri(double data): test_base(int(0)) {
	//继承类必须手动调用父类的构造函数。
	//我的基类里有两个构造函数，我这里是指定成调用int类型的构造函数。
	double_data = data;
}
//}}}

//数据修改函数和输出函数
//{{{
void test_heri::change_double_data(double data) {	
	double_data = data;
}

double test_heri::get_double_data() {
	return double_data;
}
//}}}

//运算符重载
//重载对象可以是对象，也可以是某一种数据类型。
//{{{
test_heri test_heri::operator+(test_heri data) {
	test_heri result(int(0));
	result.change_int_data(this->get_int_data() + data.get_int_data());
	result.change_float_data(this->get_float_data() + data.get_float_data());
	result.change_double_data(this->get_double_data() + data.get_double_data());

	return result;
}

int test_heri::operator+(int data) {
	return this->get_int_data() + data;
}
//}}}




