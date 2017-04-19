#ifndef BST_H
#define BST_H

#include <iterator>

//#define nullptr 0

template <typename T>
class BinSearchTree
{
	class TreeNode
	{
		TreeNode(const TreeNode & other);
		TreeNode & operator=(const TreeNode & other);
	public:
		TreeNode * parent, *left, *right;
		T data;
		TreeNode(): parent(nullptr), left(nullptr), right(nullptr), data(T()){};
		TreeNode(T x): parent(nullptr), left(nullptr), right(nullptr), data(x){};
		TreeNode(TreeNode * parent, T x): parent(parent), left(nullptr), right(nullptr), data(x){};
		TreeNode(TreeNode * parent, TreeNode * left, TreeNode * right, T x):
		parent(parent), left(left), right(right), data(x){};
		~TreeNode()
		{
			if (left)
				delete left;
			if (right)
				delete right;
			if (parent && parent->left == this)
				parent->left = nullptr;
			if (parent && parent->right == this)
				parent->right = nullptr;
		}
	};
	class BSTIterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		friend class TreeNode;
		TreeNode * p;
	public:
		BSTIterator(TreeNode * p) : p(p) {};
		BSTIterator(const BSTIterator & other) : p(other.p) {};
		bool operator!=(const BSTIterator & other) const
		{
			return p != other.p;
		}
		bool operator==(const BSTIterator & other) const
		{
			return p == other.p;
		}
		BSTIterator & operator++()
		{

		}
		BSTIterator & operator--()
		{

		}
		T & operator*()
		{
			return &p->data;
		}
	};
	TreeNode * root;
	BinSearchTree(const BinSearchTree & other);
	BinSearchTree & operator=(const BinSearchTree & other);
	void push_(TreeNode * & r, T x, TreeNode * par = nullptr)
	{
		if (!r)
		{
			r = new TreeNode(par, x);
			return;
		}
		if (x < r->data)
		{
			push_(r->left, x, r->parent);
		}
		else
		{
			push_(r->right, x, r->parent);
		}
	}
	bool contains_(TreeNode * r, const T & x) const
	{
		if (!r) {
			return false;
		}
		if (r->data == x) {
			return true;
		}
		else if (r->data <= x) {
			return contains_(r->right, x);
		}
		else {
			return contains_(r->left, x);
		}
	}
	void erase_(const T & x, TreeNode * r)
	{
		if (!r) {
			return;
		}
		else if (x > r->data) {
			erase_(x, r->right);
		}
		else if (x < r->data) {
			erase_(x, r->left);
		}
		else {

		}
	}
public:
	BinSearchTree(): root(nullptr){};
	~BinSearchTree()
	{
		delete root;
	}
	void push(T x)
	{
		push_(root, x);
	}
	bool contains(const T & x) const
	{
		return contains_(root, x);
	}
	const T & max() const
	{
		TreeNode * p = root;
		while (p->right)
			p = p->right;
		return p->data;
	}
	const T & min() const
	{
		TreeNode * p = root;
		while (p->left)
			p = p->left;
		return p->data;
	}
	const T & gte(const T & x) const
	{
		TreeNode * p = root;
		while (p->right)
		{
			if (p->data >= x)
				return p->data;
			p = p->right;
		}
		return p->data;
	}
	const T & lte(const T & x) const
	{
		TreeNode * p = root;
		while (p->left)
		{
			if (p->data <= x)
				return p->data;
			p = p->left;
		}
		return p->data;
	}
	void erase(const T & x)
	{
		erase_(x, root);
	}
};

#endif