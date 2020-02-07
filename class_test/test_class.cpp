#include <iostream>
#include "test_class.h"
using namespace std;

//###############################################################
//���ࣺ
//���캯��������
//{{{
test_base::test_base(int data) {
	int_data = data;
	float_data = 0;
}

test_base::test_base(float data) {
	//����ǹ��캯������
	int_data = 0;
	float_data = data;
}
//}}}

//�������͵��޸ĺ��������
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

//��������
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
//�̳���
//���캯���ͶԻ��ຯ��������
//{{{
test_heri::test_heri(int data): test_base(data) {
	//�ֶ���ֵ����ʵ���Ը�ֵ���κ�ֵ
	change_int_data(data);
}

test_heri::test_heri(float data): test_base(data) {
	//ʲôҲ���ɣ����ǵ���test_base �Ĺ��캯����float�͵�dataд��float_data
}

test_heri::test_heri(double data): test_base(int(0)) {
	//�̳�������ֶ����ø���Ĺ��캯����
	//�ҵĻ��������������캯������������ָ���ɵ���int���͵Ĺ��캯����
	double_data = data;
}
//}}}

//�����޸ĺ������������
//{{{
void test_heri::change_double_data(double data) {	
	double_data = data;
}

double test_heri::get_double_data() {
	return double_data;
}
//}}}

//���������
//���ض�������Ƕ���Ҳ������ĳһ���������͡�
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




