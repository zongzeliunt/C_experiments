#include <iostream>
using namespace std;

int change_b () {
	static int b = 10;
	return b--;
}

int main () {
	const int a = 10;
	//a = 2; //error
	cout<<a<<endl;

	for (int i = 0; i < 5; i ++) {
		cout<<i<<" "<<change_b()<<endl;
	
	}
}
