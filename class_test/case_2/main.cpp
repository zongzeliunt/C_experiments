#include <iostream>
#include "class.h"


using namespace std;

int main () {
	cout<<"helloworld"<<endl;
	int int_data = 10;
	float float_data = 12.1; 
	char char_data = 'a';

	//假如base是抽象类，就不能实例化了，否则出错
	//base base_obj;
	//base_obj.class_classify();


	heir1 heir1_obj(int_data);
	//cout<<heir1_obj.get_data()<<endl;


	heir2 heir2_obj(float_data);
	heir2_obj.change_int_data(int_data + 1);
	heir2_obj.change_char_data(char_data);
	
	cout<<heir2_obj.get_float_data()<<endl;
	cout<<heir2_obj.get_int_data()<<endl;
	cout<<heir2_obj.get_char_data()<<endl;

	base *pointer;
	pointer = &heir1_obj;
	//pointer-> class_classify();

	pointer = &heir2_obj;
	//pointer-> class_classify();
	
	return 0;
}

