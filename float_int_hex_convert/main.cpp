/*
	Note:
	float 要先用float_to_int_hex_conv转成int,再写进fpga
	fpga 那端出来数据以后，用int_hex_to_float_conv转成float

*/
#include <iostream>
#include <string>

using namespace std;

int float_to_int_hex_conv (float data) {
	return 	*((int *)&data);
}

float int_hex_to_float_conv (int data) {
	//这是把十六进制的int数转成float的
	return *((float *)&data);
}

int main () {
	float float_data = 1.6;

	int tmp;
	tmp = float_to_int_hex_conv(float_data);

	cout<<"sizeof float "<<sizeof (float_data) <<endl;

	printf ("float data hex: %x \n", tmp);
	printf ("float data float: %f \n", int_hex_to_float_conv(tmp));
	printf ("float data dec: %d \n", tmp);


	int int_data_hex = 0x3fc00000; // 1.5

	printf ("int data hex: %x \n", int_data_hex);
	printf ("int data float: %f \n", int_hex_to_float_conv(int_data_hex));
	printf ("int data dec: %d \n", int_data_hex);


	float float_data_1 = 2.7;

	int tmp_1;
	tmp_1 = float_to_int_hex_conv(float_data_1);

	cout<<"float data 1 float: "<<float_data_1<<endl;
	cout<<"float data 1 hex: "<<hex<<tmp_1<<endl;
	cout<<"float data 1 int conv to float: "<<int_hex_to_float_conv(tmp_1)<<endl;
	cout<<"float data 1 dec: "<<dec<<tmp_1<<endl;


}
