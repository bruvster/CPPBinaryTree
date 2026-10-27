#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Deque.hpp"

#include <iostream>
	using std::string;

/**
 * BinaryTree is a basic (recursive) binary tree to hold generic elements.
 * Definition: A BinaryTree is either empty or contains a root node with
 * two subtrees that are binary trees.
 * Because of its highly recursive nature, if a BinaryTree is constructed
 * with BinaryTree objects as its subtrees, these are deep copied as a tree
 * structure and attached, so the deletion of trees involves only those
 * nodes associated with that tree.
 * @author B.Bultena
 * @version 1.0.1
 */

class BinaryTree {

	protected :
		// Because the BinaryTree will likely be subclassed,
		// everything that is inherited is protected as opposed
		// to private.

		/** 
		 * The TreeNode class is the definition of a node in a binary
		 * tree that contains string elements.
		 * This class is only accessible to BinaryTree.
		 */
		class TreeNode {
			public:
				string element;
				TreeNode * lchild;
				TreeNode * rchild;
			
				TreeNode(const string &value, TreeNode* left=nullptr, TreeNode * right=nullptr) {
					element = value;
					lchild =left;
					rchild = right;
				}
		};

		// attributes
		TreeNode * root;
		int m_size;

	private :
		// The only members that are private are the recursive helper functions
		/**
 		 * Each of these three recursive functions implements an ordering
	 	 * of the elements in the tree.
		 * The pre, in, and post determines the order of when the root is processed.
		 * The left and right subtrees are always in left right order.
		 * @param Q, a queue that will hold the elements in a linear order.
		 * @param node, the current root of the subtree that is being processed.
		 */
		void gen_preorder(Deque<string> & Q, TreeNode * node) const;
		void gen_inorder(Deque<string> & Q, TreeNode * node) const;
		void gen_postorder(Deque<string>& Q, TreeNode * node) const;
		
		/**
 		 * A recursive function that builds a subtree structure,
		 * that is a deep copy of the subtree rooted at node.
	 	 * @param node The root of the subtree to copy.
		 * @return The new root.
		 */
		TreeNode * build_subtree(const TreeNode * node);

		/**
		 * A recursive function that deletes the entire subtree rooted
		 * at node.
 		 * @param node The root of the subtree to delete.
	 	 * @return A TreeNode that has been set to nullptr
		 */
		TreeNode * delete_subtree(TreeNode * node);

		/**
		 * A private recursive function for determining the height of a subtree
		 * starting at the given node.
		 * @param root_of_subtree The node that is the root of a tree or subtree.
		 * @return The length of the path from this node to the furthest leaf node.
		 */
		int get_height(TreeNode * subroot) const;

	public:
		/*******************  Constructors / Destructors ***************/
		/**
		 * Creates a BinaryTree whose root contains the element, and its
		 * left and right subtrees are copied from the BinaryTree inputs.
		 * @param element The element to put into the root node.
		 * @param leftTree The BinaryTree that is copied to become the left subtree of root.
		 * @param rightTree The BinaryTree that is copied to become the right subtree of root.
		 */
		BinaryTree(string element, BinaryTree left_tree, BinaryTree right_tree); 

		/**
		 * Creates a tree with a single root node.
		 * @param element The element to put into the root node.,
		 */
		BinaryTree(string element);

		/**
		 * Default constructor: creates an empty tree.
		 */
		BinaryTree();

		/**
	 	 * Copy constructor: Creates a tree that is the same as the one
		 * 	to be copied.
		 * @param copy The one to be copied.
	 	 */
		BinaryTree( const BinaryTree &copy);

		/**
 		 * Removes any dynamically allocated memory.
		 */
		~BinaryTree();

		/******************  gets and sets  *****************/
		/**
		 * @return the number of elements / nodes in the tree.
		 */
		int size() const;

		/**
		 * @return True if the tree is empty, false if it is not.
		 */
		bool is_empty() const;

		/**
		 * The height of the tree is the maximum number of nodes in a path
		 * from the root to a leaf of the BinaryTree.
		 * @return the height.
		 */
		int height() const;

		/**
		 * This provides a list of elements of the tree in preorder.
		 * @return A Deque of string elements.
		 */
		void pre_order(Deque<string>& Q) const;

		/**
		 * This provides a list of elements of the tree inorder.
		 * @return A Deque of string elements.
		 */
		void in_order(Deque<string> & Q) const;

		/**
		 * This provides a list of elements of the tree in postorder.
		 * @return A Deque of string elements.
		 */
		void post_order(Deque<string> & Q) const;
		/******************  visualization  *****************/
		/**/
		void DOT_translation();

		void doDotPrint(BinaryTree::TreeNode * node);
};
#endif
