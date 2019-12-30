#include <iostream>
using namespace std;

class chain_node {
	public:
		chain_node *next;
		int val;
		chain_node (int v) {val = v;}
};

int main () {
	chain_node head(0);
	chain_node *chain_this;
	chain_this = &head;
	for (int i = 1; i < 4; i ++) {
		chain_node *node = new chain_node(i * 2);
		chain_this->next = node;
		chain_this = node;
		cout<<chain_this->val<<endl;	
	}

	chain_this = &head;
	while (1) {
		cout<<chain_this->val<<endl;
		chain_this = chain_this->next;
		if (chain_this == NULL) {
			break;
		}

	}
	return 0;
}


