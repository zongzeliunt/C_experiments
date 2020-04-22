#include "class.h"

heir1::heir1(char init_data) {
	char_data = init_data;
}

heir1::heir1(int init_data) {
	int_data = init_data;
}

int heir1::get_int_data (){
	return int_data;
}

char heir1::get_char_data (){
	return char_data;
}

void heir1::change_int_data(int data) {
	int_data = data;
}

void heir1::change_char_data(char data) {
	char_data = data;
}












heir2::heir2(float init_data): heir1(int(0)) {
//继承类必须手动调用父类的构造函数。
//我的基类里有两个构造函数，我这里是指定成调用int类型的构造函数。
	float_data = init_data;
}

heir2::heir2(char init_data): heir1(init_data) {
	change_char_data(init_data);
}

heir2::heir2(int init_data): heir1(init_data) {
	change_int_data(init_data);
}

void heir2::change_float_data (float data) {
	float_data = data;
}

float heir2::get_float_data (){
	return float_data;
}
