#include <iostream>
#include <list>
#include "tree.h"
using namespace std;


tree_node::tree_node(int v)
{	
	val = v;
}

tree::tree ()
{
	root = NULL;
}

void tree::insert (int v) 
{
	if (root == NULL) {
		tree_node *node = new tree_node(v);
		root = node;	
	} else {
		rec_insert (v, root);
	}
}

void tree::rec_insert (int v, tree_node *node)
{
	int node_val = node->val;
	if (v <= node_val) {
		if (node->left == NULL) {
			tree_node *new_node = new tree_node(v);
			node->left = new_node;		
		} else {
			rec_insert (v, node->left);
		}
	} else {
		if (node->right == NULL) {
			tree_node *new_node = new tree_node(v);
			node->right = new_node;		
		} else {
			rec_insert (v, node->right);
		}
	}

}

void tree::pre_traversal(tree_node *node)
{
	if (node != NULL) {
		pre_traversal(node->left);
		cout<<node->val<<endl;
		pre_traversal(node->right);
	}
}

void tree::in_traversal(tree_node *node)
{
	if (node != NULL) {
		cout<<node->val<<endl;
		in_traversal(node->left);
		in_traversal(node->right);
	}
}

void tree::post_traversal(tree_node *node)
{
	if (node != NULL) {
		post_traversal(node->left);
		post_traversal(node->right);
		cout<<node->val<<endl;
	}
}

void tree::BST_traversal()
{
	list<tree_node> queue;
	queue.push_back(*root);
	while (!queue.empty()) {
		tree_node this_node = queue.front();
		queue.pop_front();
		cout<<this_node.val<<endl;
		if (this_node.left != NULL) {
			queue.push_back(*this_node.left);
		}
		if (this_node.right != NULL) {
			queue.push_back(*this_node.right);
		}
	}	
}

depth_tree_node::depth_tree_node(int v, int d):tree_node(v)
{
	//由于父类定义了有参数的构造函数，子类的构造函数必须用这种方式显式调用父类的有参数的构造函数，否则出错。
	//可以在字类的构造函数里对父类的构造函数进行功能颠覆
	//在这个程序里这个node类型我用不上
	depth = d;
	//val = 25;
}

depth_tree::depth_tree():tree()
{
	total_depth = 0;
}

void depth_tree::insert(int v)
{
	if (root == NULL) {
		tree_node *node = new tree_node(v);
		root = node;
		total_depth = 1;	
	}
	else {
		rec_insert (v, root, 1);
	}
}

void depth_tree::rec_insert (int v, tree_node *node, int last_depth)
{
	int node_val = node->val;
	int current_depth = last_depth + 1;
	if (v <= node_val) {
		if (node->left == NULL) {
			tree_node *new_node = new tree_node(v);
			node->left = new_node;	
			if (current_depth > total_depth) {
				total_depth = current_depth;
			}	
		} else {
			rec_insert (v, node->left, current_depth);
		}
	} else {
		if (node->right == NULL) {
			tree_node *new_node = new tree_node(v);
			node->right = new_node;		
			if (current_depth > total_depth) {
				total_depth = current_depth;
			}	
		} else {
			rec_insert (v, node->right, current_depth);
		}
	}

}
