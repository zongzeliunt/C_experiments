#include <iostream>
#include <string>
#include "data_opt.h"

using namespace std;

int main () {
	float float_data = 1.6;
	int int_data = 14;

	char int_data_list[4];
	char float_data_list[4];

	bool int_data_bit_list[32];
	bool float_data_bit_list[32];

	cout<<"float============="<<endl;
	//float	
	float_to_char_list(float_data, float_data_list);
	cout<<"float char list: "<<endl;
	//show_char_list(float_data_list);
	
	float_to_bit_list(float_data, float_data_bit_list);
	cout<<"float bit list: ";
	show_bit_list(float_data_bit_list);

	cout<<"char list to float: "<<char_list_to_float(float_data_list)<<endl;
	cout<<"bit list to float: "<<bit_list_to_float(float_data_bit_list)<<endl;



	cout<<endl;
	cout<<"int  ============="<<endl;
	//int
	int_to_char_list(int_data, int_data_list);
	cout<<"int char list: "<<endl;
	//show_char_list(int_data_list);
	
	int_to_bit_list(int_data, int_data_bit_list);
	cout<<"int bit list: ";
	show_bit_list(int_data_bit_list);
	cout<<"char list to int: "<<char_list_to_int(int_data_list)<<endl;
	cout<<"bit list to int: "<<bit_list_to_int(int_data_bit_list)<<endl;

	return 0;
}
