#include <iostream>
using namespace std;

class chain_node {
	public:
		chain_node *next;
		int val;
		chain_node (int v);
};

class chain {
	public:
		chain_node *head;
		chain_node *chain_rear;
		void connect (int v);
		void insert (int pos, int v);
		void delete_v (int v);
		void show ();
		chain();
};
