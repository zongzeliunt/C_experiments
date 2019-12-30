#include <iostream>
#include "chain_node.h"

using namespace std;

chain_node::chain_node (int v)
{
	val = v;
}

chain::chain ()
{
	head = new chain_node(0);
	chain_rear = head;
}

void chain::connect(int v)
{
	chain_node *node = new chain_node(v);
	chain_rear->next = node;
	chain_rear = node;
}

void chain::show()
{
	chain_node *chain_this;
	chain_this = head->next;
	while (1) {
		if (chain_this == NULL) {
			break;
		}
		cout<<chain_this->val<<endl;
		chain_this = chain_this->next;
	}
}

void chain::insert (int pos, int v)
{
	chain_node *chain_this;
	chain_this = head->next;
	int pass = 1;
	while (1) {
		if (chain_this == NULL) {
			break;
		}
		if (pass == pos) {
			break;
		}
		chain_this = chain_this->next;
		pass++;
	}
	if (chain_this == NULL) {
		connect(v);
	} else {
		chain_node *chain_next = chain_this->next;
		chain_node *node = new chain_node(v);
		chain_this->next = node;
		node->next = chain_next;
	}
}

void chain::delete_v (int v) 
{
	chain_node *chain_this = head->next;
	chain_node *chain_last = head;
	while (1) {
		if (chain_this == NULL) {
			break;
		}
		if (chain_this->val == v) {
			break;
		}
		chain_this = chain_this->next;
		chain_last = chain_last->next;
	}
	if (chain_this != NULL) {
		chain_last->next = chain_this->next;
		delete(chain_this);
	}

}


