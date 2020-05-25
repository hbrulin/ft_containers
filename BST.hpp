#ifndef BST_HPP
# define BST_HPP

#include "Iterators.hpp"
#include "Pair.hpp"

namespace ft
{

	template <typename T, typename Compare, bool isMulti>
	class BST
	{
	public:
		typedef T value_type;
		typedef BSTNode<T> Node;
		typedef size_t size_type;
		typedef BST<T, Compare, isMulti> Tree;
	
		/*Define iterators */
	
	private:
		Compare _cmp;
		Node *_root;
		Node *_init;
		size_t _size;
		BST(){};
		void deep_free(Node *root);
		Node *deep_copy(Node *parent, Node *n);

	public:
		BST(Compare cmp) : _cmp(cmp), _root(NULL), _size(0) {
			_init = new Node(T(), NULL, NULL, NULL);
		};

		BST(const BST &other) : _cmp(other._cmp), _size(other._size) {
			_root = deep_copy(NULL, other._root);
			_init = new Node(T(), NULL, NULL, NULL);
		};

		BST &operator=(const BST &other) {
			deep_free(_root);
			_root = deep_copy(NULL, other._root);
			_cmp = other._cmp;
			_size = other._size;		
			return (*this);
		};
		virtual ~BST() { deep_free(_root); delete _init; };
		Node *getR() { return this->_root; };
		Node *getInit() { return this->_init; };
		size_type getSize() const { return this->_size; };
		pair<iterator, bool> insert(iterator position, const value_type &val);
		bool map_erase(const value_type &val);
		
	};

	/* private functions */
	template <typename T, typename Compare, bool isMulti>
	void BST<T, Compare, isMulti>::deep_free(Node *root)
	{
		if (!root)
			return;
		deep_free(root->left);
		deep_free(root->right);
		delete root;
	}

	template <typename T, typename Compare, bool isMulti>
	typename BST<T, Compare, isMulti>::Node *BST<T, Compare, isMulti>::deep_copy(Node *parent, Node *n)
	{
		if (!n)
			return NULL;
		Node *cpy = new Node(n->element, parent, NULL, NULL);
		cpy->left = deep_copy(cpy, n->left);
		cpy->right = deep_copy(cpy, n->right);
		return cpy;
	}

	/* public functions */	
	//AJOUTER TYPENAMES
	template <typename T, typename Compare, bool isMulti>
	pair<iterator, bool> BST<T, Compare, isMulti>::insert(iterator position, const value_type &val) {

	}

	template <typename T, typename Compare, bool isMulti>
	bool BST<T, Compare, isMulti>::map_erase(const value_type &val) {

	}


};

#endif
