#include <iostream>
using namespace std;

class tree_node {
	public:
		int val;
		tree_node *left;
		tree_node *right;
		tree_node(int v);
};

class tree {
	public:
		tree_node *root;
		void insert (int v);
		void rec_insert (int v, tree_node *node);
		void pre_traversal (tree_node *node);
		void in_traversal (tree_node *node);
		void post_traversal (tree_node *node);
		void BST_traversal ();
		tree();
};

class depth_tree_node: public tree_node  {
	public:
		depth_tree_node(int v, int d);
		int depth;
};

class depth_tree: public tree {
	public:
		int total_depth;
		void insert (int v);
		void rec_insert(int v, tree_node *node, int last_depth);
		depth_tree();
};
