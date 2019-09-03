#include <iostream>
using namespace std;

int main () {
	//using int_array = int[4];
	typedef int int_array[4]; 
	//the above two are same

	int i = 0;
	int ia[4];
	for (i=0;i<4;i++) {
		ia[i] = i * 10;
	}	
		
	int_array *p = &ia;
	int *q = *p;
	for (i=0;i<4;i++) {
		cout<<*(q+i)<<endl;
	}
}
