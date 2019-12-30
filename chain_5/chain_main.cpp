#include <iostream>
#include "chain_node.h"

using namespace std;


int main () {
	chain c;
	cout<<"init"<<endl;
	c.show();
	for (int i = 1; i <= 6; i ++) {
		c.connect(i * 2);
	}
	cout<<"done"<<endl;
	c.show();
	
	c.insert(10, 20);
	c.insert(3, 5);

	cout<<"after insert"<<endl;
	c.show();
	
	c.delete_v(6);
	cout<<"after delete"<<endl;
	c.show();

	return 0;
}


