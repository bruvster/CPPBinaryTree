/*
    Author : Mia Murray
    Date   : March 14th 2020
    Title  : CSCI 161 - Assignment 8

    A Program that can build a binary tree that stores
    any simple element with the utilization of templates. 
    The program stores the elements of the tree in a deque
    when one of the order functions is called and prints them
    in that specified order. I have added a print out representation
    of the binary tree so that we can visualize the different orders
    and confirm that they work.
*/
#include "BinaryTree.hpp"
#include "Deque.hpp"
using std::cout;
using std::string;
using std::endl;


//********************************CONSTRUCTORS/DESTRUCTOR***************************************

	//CONSTRUCTOR/INSERT
	BinaryTree::BinaryTree(string element, BinaryTree left_tree, BinaryTree right_tree) 
	{
		m_size = 1; //root node
		m_size += left_tree.size(); //adding size of left 
		m_size += right_tree.size(); //and right
		TreeNode * left_subtree = build_subtree(left_tree.root);
		TreeNode * right_subtree = build_subtree(right_tree.root);
		root = new TreeNode(element, left_subtree, right_subtree);
	}

	//CONSTRUCTOR FOR 1 ELEMENT
	BinaryTree::BinaryTree(string element) 
	{
		root = new TreeNode(element);
		m_size = 1; //a tree with no child nodes has a size of 1
	}

	//CONSTRUCTOR FOR EMPTY BINARY TREE
	BinaryTree::BinaryTree() 
	{
		root = nullptr;
		m_size = 0; //a binary tree with no elements still exists
	}

	//RECURSIVE HELPER FOR CONSTRUCTOR
	BinaryTree::TreeNode * BinaryTree::build_subtree(const TreeNode * node) 
	{
		if (node == nullptr) 
		{
			return nullptr;
		}
			return new TreeNode(node->element,build_subtree(node->lchild),
					build_subtree(node->rchild));
	}

	//COPY CONSTRUCTOR		 
	BinaryTree::BinaryTree( const BinaryTree & copy) 
	{
		root = build_subtree(copy.root);
	}


	//DESTRUCTOR
	BinaryTree::~BinaryTree() 
	{
		delete_subtree(root);
	}

	//RECURSIVE HELPER FOR DESTRUCTOR
	BinaryTree::TreeNode * BinaryTree::delete_subtree( TreeNode * node ) 
	{
		if (node == nullptr) 
		{
			return nullptr;
		}
		if (node->lchild != nullptr) 
		{
			node->lchild = delete_subtree(node->lchild);
		}
		if (node->rchild != nullptr) 
		{
			node->rchild = delete_subtree(node->rchild);
		}
		delete node;
		return nullptr;
	}

//**********************************GETTERS AND SETTERS*****************************************

	int BinaryTree::size() const 
	{
		//we build a new deque for the purposes of counting
		//the number of elements in "this" binary tree
		Deque<string> test;
		gen_preorder(test, root);
		int count = 0;
		while (!test.is_empty())
		{
			test.pop();
			count ++;
		}
		return count;
	}

	bool BinaryTree::is_empty() const 
	{
		if (m_size == 0)
		{
			//empty tree
			return true;
		}
		return false;
	}

	int BinaryTree::height() const 
	{
		if (root == nullptr)
		{
			return 1;
		}
		int h = get_height(root) - 1; 
		return h;
	}

	//RECURSIVE HELPER FOR HEIGHT FUNCTION
	int BinaryTree::get_height(TreeNode * subroot) const 
	{
		int largest = 0;
		int current = 0;
		if (subroot == nullptr)
		{
			return 1; //we made it to the end of a path
		}
		current = get_height(subroot->lchild);
		if (current>largest)
		{
			largest = current;
		}
		current = get_height(subroot->rchild);
		if (current>largest)
		{
			largest = current;
		}
		return largest + 1; //returns the longest path
	}

//*************************************TRAVERSALS***********************************************

	void BinaryTree::pre_order(Deque<string>& Q) const 
	{
		gen_preorder(Q, root);
		Q.print_queue();
		cout << endl;
		return;
	}

	// recursive helper function
	void BinaryTree::gen_preorder(Deque<string> & Q, TreeNode * node) const 
	{
		if (node != nullptr)
		{
			Q.enqueue(node->element);
			gen_preorder(Q, node->lchild);
			gen_preorder(Q, node->rchild);
		}
		return;
	}

	void BinaryTree::in_order(Deque<string> & Q) const 
	{
		gen_inorder(Q, root);
		Q.print_queue();
		cout << endl;
		return;
	}

	// recursive helper function
	void BinaryTree::gen_inorder(Deque<string> & Q, TreeNode * node) const 
	{
		if (node != nullptr)
		{
			gen_inorder(Q, node->lchild);
			Q.enqueue(node->element);
			gen_inorder(Q, node->rchild);
		}
		return;
	}

	void BinaryTree::post_order(Deque<string> & Q) const 
	{
		gen_postorder(Q, root);
		Q.print_queue();
		cout << endl;
		return;
	}

	// recursive helper function
	void BinaryTree::gen_postorder(Deque<string>& Q, TreeNode * node) const 
	{
		if (node != nullptr)
		{
			gen_postorder(Q, node->lchild);
			gen_postorder(Q, node->rchild);
			Q.enqueue(node->element);
		}
		return;
	}

//VISUALIZATION
void BinaryTree::DOT_translation() 
{
	cout << "DOT translation begins:"<<endl;
	cout<<"digraph BST {"<<endl;
	cout<<"\tnode [fontname=\"Arial\"];"<<endl;
	if (root) 
	{
		doDotPrint(root);
	}
	cout<<"}"<<endl;
	cout << "DOT translation ends:"<<endl;
}

void BinaryTree::doDotPrint(BinaryTree::TreeNode * node) 
{
	if (node->lchild) 
	{
		cout<<"\t"<<node->element
		<<" -> "<<node->lchild->element
		<<";"<<endl;
		doDotPrint(node->lchild);
	}
	if (node->rchild) 
	{
		cout <<"\t"<<node->element
		<<" -> "<<node->rchild->element
		<<";"<<endl;
		doDotPrint(node->rchild);
	}
}
