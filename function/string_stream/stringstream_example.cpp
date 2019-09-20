#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main() {

	stringstream ss;
	fstream fl_in, fl_out;
	fl_in.open("1.txt", ios::in);
	fl_out.open("2.txt", ios::out);
	/*	
	char fl_in_char[16];
	fl_in.getline(fl_in_char, 16, '\n');
	ss<<fl_in_char;
	*/

	string fl_in_string;
	getline(fl_in, fl_in_string, '\n');
	ss<<fl_in_string;


	int a, b, c;
	ss >> a >> b;
	c = a + b;

	cout<<"c = "<<c<<endl;
	fl_out<<"c = "<<c<<endl;


	fl_in.close();
	fl_out.close();
	return 0;
}
