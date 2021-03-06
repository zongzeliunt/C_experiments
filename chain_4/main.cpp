#include <iostream>
#include <string>
#include "chain_node.h"

using namespace std;

int main() {
	chain_node *head_pointer;
	chain_node *current_pointer;
	chain_node *next_pointer;

	for (int i = 0; i< 5; i ++) {
		chain_node *new_node = new chain_node(i*2);
		if (head_pointer == NULL) {
			head_pointer = new_node;
		}

		if (current_pointer != NULL) {
			current_pointer->connect_next(new_node);
		}
		current_pointer = new_node;
		if (i == 3) {
 			current_pointer->modify_data(111);

		}
	}



	chain_node_adv adv_node(1.5);
	adv_node.show_float_data();
	adv_node.modify_data(150);
	adv_node.show_data();

	adv_node.connect_next(head_pointer);
	head_pointer=&adv_node;




	cout<<"show whole list"<<endl;
	current_pointer = head_pointer;

	while (true) {
		current_pointer->show_data();	
		next_pointer = current_pointer->get_next_pointer();
		if (next_pointer == NULL) {
			break;
		} else {
			current_pointer = next_pointer;
		}

	}

}
