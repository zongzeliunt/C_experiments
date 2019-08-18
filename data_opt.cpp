#include <iostream>
#include <string>

using namespace std;

void float_to_char_list(float data, char list[4]) {
//{{{
	int i = 0;
	char tmp;
	for (i = 0; i < 4; i++) {
		tmp = *((char *)&data + i);
		list[i] = tmp;
	}
}
//}}}

float char_list_to_float(char list[4]) {
//{{{
	int i = 0;
	float data;
	for (i = 0; i < 4; i++) {
		*((char *)&data + i) = list[i];
	}
	return data;
}
//}}}

void int_to_char_list(int data, char list[4]) {
//{{{
	int i = 0;

	char tmp;
	for (i = 0; i < 4; i++) {
		tmp = *((char *)&data + i);
		list[i] = tmp;
	}
}
//}}}

int char_list_to_int(char list[4]) {
//{{{
	int i = 0;
	int data;
	for (i = 0; i < 4; i++) {
		*((char *)&data + i) = list[i];
	}
	return data;
}
//}}}

void int_to_bit_list(int data, bool list[32]) {
//{{{
	int i=0;
	if (data < 0) {
		list[31] = 1;
	} else {
		list[31] = 0;
	}

	int remainder =0;
	for (i=0; i < 31; i ++) {
		remainder = data%2;
		if (remainder == 0) {
			list[i] = 0;
		} else {
			list[i] = 1;

		}

		data=data/2;
		/*
		if (data == 0) {
			break;
		}
		*/
	}
}
//}}}

void show_char_list(char data_list[4]) {
//{{{
	for (int i = 0 ; i < 4; i++) {
		printf("byte: %d, value: %d\n", i, data_list[i]);
	}
}
//}}}

void show_bit_list(bool data_list[32]) {
//{{{
	int i;
	/*
	for (i = 31 ; i >= 0 ; i--) {
		cout<<int_data_bit_list[i];
		if (i%4 == 0) {
			cout<<"_";
		}
	}
	cout<<endl;
	*/
	for (i = 31 ; i >= 0 ; i--) {
		printf("%d",data_list[i]);
		if (i%4 == 0 && i != 0) {
			cout<<"_";
		}
	}
	cout<<endl;
}
//}}}

void float_to_bit_list(float data, bool list[32]) {
//{{{
	char float_data_list[4];
	int i, j, total_count;
	float_to_char_list(data, float_data_list);
	int tmp = char_list_to_int(float_data_list);	
	int_to_bit_list(tmp, list);
}
//}}}

int bit_list_to_int (bool list[32]) {
//{{{
	int i;
	int total = 0;
	for (i = 30; i >= 0; i --) {
		total += list[i];
		if (i != 0) {
			total *= 2;	
		}
	}
	if (list[31] == 1) total *= -1;
	return total;
}
//}}}

float bit_list_to_float (bool list[32]) {
//{{{
	int i;
	int tmp;
	float total;
	char char_list[4];
	
	tmp = bit_list_to_int(list);
	int_to_char_list(tmp, char_list);

	total = char_list_to_float(char_list);
	
	return total;
}
//}}}






