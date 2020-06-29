 // reading a text file
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

void read_text_case () {
	char buffer[256];
	ifstream in("read_text.txt");

	while (!in.eof() )
	{
		//in.getline (buffer,100);
		in >> buffer;
		if (buffer != "") {
			cout << buffer << endl;
		}
	}
}


void read_number_case () {
	float f_n;
	int i_n;
	
	ifstream in("read_number.txt");

	while (!in.eof() )
	{
		cout<<"round"<<endl;
		in >> f_n;
		in >> i_n;
		cout << f_n <<" "<<i_n<<endl;
	}
}

void write_number_case() {
	ofstream out;
	//out.open("write_number.txt", ios::app ); //追加
	out.open("write_number.txt", ios::out ); //从头写 

	for (int i = 0; i < 10; i ++) {
		out<<i<<" "<<endl;

	}

}


int main () {
	read_number_case();

	write_number_case();
	return 0;
}
