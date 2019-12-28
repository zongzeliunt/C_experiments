#include <iostream>
#include "tree.h"
using namespace std;


int main ()
{
	tree t;
	t.insert(5);
	t.insert(20);
	t.insert(1);	
	t.insert(10);
	t.insert(15);
	t.insert(3);
	cout<<"pre"<<endl;
	t.pre_traversal(t.root);
	cout<<"in"<<endl;
	t.in_traversal(t.root);
	cout<<"post"<<endl;
	t.post_traversal(t.root);
	
	cout<<"BST"<<endl;
	t.BST_traversal();


	return 0;
}

