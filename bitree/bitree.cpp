#include <iostream>
#include "tree.h"
using namespace std;


int main ()
{
	/*
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
	*/

	/*
	depth_tree_node dt(50, 0);
	cout<<dt.val<<endl;	
	cout<<dt.depth<<endl;
	dt.depth = 150;
	cout<<dt.depth<<endl;
	*/
	depth_tree dt;
	dt.insert(5);
	dt.insert(20);
	dt.insert(1);	
	dt.insert(10);
	dt.insert(15);
	dt.insert(3);
	cout<<"total_depth "<<dt.total_depth<<endl;	
	cout<<"pre"<<endl;
	dt.pre_traversal(dt.root);
	cout<<"in"<<endl;
	dt.in_traversal(dt.root);
	cout<<"post"<<endl;
	dt.post_traversal(dt.root);
	
	cout<<"BST"<<endl;
	dt.BST_traversal();

	return 0;
}

