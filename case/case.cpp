#include <iostream>
using namespace std;

int main () {
	int case_num = 2;
	switch (case_num) {
		case 0: cout<<"num is 0" <<endl;
			break;	
		case 1: cout<<"num is 1"<<endl;
			break;
		case 2: cout<<"num is 2"<<endl;
			break;
		default: cout<<"defalut"<<endl;
	}
	cout<<"case num"<<case_num<<endl;
	
	/*
	char case_num = '0';
	switch (case_num) {
		case '0': cout<<"num is 0" <<endl;
			break;	
		case '1': cout<<"num is 1"<<endl;
			break;
		case '2': cout<<"num is 2"<<endl;
			break;
		default: cout<<"defalut"<<endl;
	}
	cout<<"case num"<<case_num<<endl;
	*/
	return 0;

}
