#include <iostream>
#include <string>
#include "chain_node.h"

using namespace std;

chain_node::chain_node(int input_data) {
	data = input_data;
	next = NULL;
}

chain_node *chain_node::get_next_pointer () {
	return next;
}

void chain_node::connect_next(chain_node *next_node) {
	next = next_node;
}

void chain_node::show_data() {
	cout<<data<<endl;
}
void chain_node::modify_data(int modify_data) {
	data = modify_data;
}

chain_node_adv::chain_node_adv(float input_float_data): chain_node(0) {
	float_data = input_float_data;
	//next = NULL;
}

void chain_node_adv::show_float_data() {
	cout<<float_data<<endl;
}
