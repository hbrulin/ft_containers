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
	
		/*Define iterators - Maps automatically store values in sort-order, so iterating will go through order in key.*/
		class iterator : public BSTIter<T, Compare, isMulti>
		{
		public:
			typedef T value_type;
			typedef T *pointer;
			typedef T &reference;
			typedef std::ptrdiff_t difference_type;
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef BSTNode<T> Node;

			iterator() : BSTIter<T, Compare, isMulti>(NULL, NULL) {}
			iterator(BST *tree) : BSTIter<T, Compare, isMulti>(tree, NULL) {}
			iterator(BST *tree, Node *node) : BSTIter<T, Compare, isMulti>(tree, node) {}
			iterator(const iterator &other) : BSTIter<T, Compare, isMulti>(other) {}
			~iterator() {}
			iterator &operator=(const iterator &other)
			{
				this->_node = other._node;
				this->_tree = other._tree;
				return (*this);
			}
			/*Keys that are less than parent go to left, keys that are bigger than to the right.*/
			iterator &operator++()
			{
				Node *root = this->_tree->getR();
				Node *tmp;

				// empty
				if (!root)
				{
					this->_node = this->_tree->getInit();
					return *this;
				}
				//end of tree
				if (!this->_node || this->_node == this->_tree->getInit())
				{
					tmp = root;
					while (tmp->left)
						tmp = tmp->left;
					this->_node = tmp;
					return *this; // first node
				}
				// move right, but if right has less, then it is closer up to cur node.
				if (this->_node->right)
				{
					this->_node = this->_node->right;
					while (this->_node->left)
						this->_node = this->_node->left;
					return *this;
				}
				// Sinon :
				tmp = this->_node->parent;
				while (tmp && tmp->right == this->_node) { //on remonte tant que le node à droite n'est pas celui sur lequel on est
					this->_node = tmp;
					tmp = this->_node->parent;
				}
				this->_node = tmp;
				if (!tmp) // no upper node exist
					this->_node = this->_tree->getInit();
				return *this;
			}
			iterator operator++(int)
			{
				iterator it(*this);
				operator++();
				return it;
			}
			iterator &operator--()
			{
				Node *root = this->_tree->getR();
				Node *tmp;


				if (!root)
				{
					this->_node = this->_tree->getInit();
					return *this;
				}

				if (!this->_node || this->_node == this->_tree->getInit())
				{
					tmp = root;
					while (tmp->right)
						tmp = tmp->right;
					this->_node = tmp;
					return *this; // last node
				}

				if (this->_node->left)
				{
					this->_node = this->_node->left;
					while (this->_node->right)
						this->_node = this->_node->right;
					return *this;
				}

				tmp = this->_node->parent;
				while (tmp && tmp->left == this->_node)
				{
					this->_node = tmp;
					tmp = this->_node->parent;
				}
				this->_node = tmp;
				if (!tmp) // no lower
					this->_node = this->_tree->getInit();
				return *this;
			}
			iterator operator--(int)
			{
				iterator it(*this);
				operator--();
				return it;
			}
			reference operator*() const { return this->_node->element; }
			pointer operator->() const { return &this->_node->element; }
		};

		/* const_iterator */
		class const_iterator : public BSTIter<T, Compare, isMulti>
		{
		public:
			typedef T value_type;
			typedef const T *pointer;
			typedef const T &reference;
			typedef std::ptrdiff_t difference_type;
			typedef std::bidirectional_iterator_tag iterator_category;
			typedef BSTNode<T> Node;

			const_iterator() : BSTIter<T, Compare, isMulti>(NULL, NULL) {}
			const_iterator(BST *tree, Node *node) : BSTIter<T, Compare, isMulti>(tree, node) {}
			const_iterator(const const_iterator &other) : BSTIter<T, Compare, isMulti>(other) {}
			const_iterator(const iterator &other) : BSTIter<T, Compare, isMulti>(other) {}
			~const_iterator() {}
			const_iterator &operator=(const const_iterator &other)
			{
				this->_node = other._node;
				this->_tree = other._tree;
				return (*this);
			}
			const_iterator &operator++()
			{
				Node *root = this->_tree->getR();
				Node *tmp;

		
				if (!root)
				{
					this->_node = this->_tree->getInit();
					return *this;
				}
			
				if (!this->_node || this->_node == this->_tree->getInit())
				{
					tmp = root;
					while (tmp->left)
						tmp = tmp->left;
					this->_node = tmp;
					return *this; 
				}
		
				if (this->_node->right)
				{
					this->_node = this->_node->right;
					while (this->_node->left)
						this->_node = this->_node->left;
					return *this;
				}
			
				tmp = this->_node->parent;
				while (tmp && tmp->right == this->_node)
				{
					this->_node = tmp;
					tmp = this->_node->parent;
				}
				this->_node = tmp;
				if (!tmp) 
					this->_node = this->_tree->getInit();
				return *this;
			}
			const_iterator operator++(int)
			{
				const_iterator it(*this);
				operator++();
				return it;
			}
			const_iterator &operator--()
			{
				Node *root = this->_tree->getR();
				Node *tmp;

	
				if (!root)
				{
					this->_node = this->_tree->getInit();
					return *this;
				}
		
				if (!this->_node || this->_node == this->_tree->getInit())
				{
					tmp = root;
					while (tmp->right)
						tmp = tmp->right;
					this->_node = tmp;
					return *this; 
				}
			
				if (this->_node->left)
				{
					this->_node = this->_node->left;
					while (this->_node->right)
						this->_node = this->_node->right;
					return *this;
				}
		
				tmp = this->_node->parent;
				while (tmp && tmp->left == this->_node)
				{
					this->_node = tmp;
					tmp = this->_node->parent;
				}
				this->_node = tmp;
				if (!tmp)
					this->_node = this->_tree->getInit();
				return *this;
			}
			const_iterator operator--(int)
			{
				const_iterator it(*this);
				operator--();
				return it;
			}
			reference operator*() const { return this->_node->element; }
			pointer operator->() const { return &this->_node->element; }
		}; 

/* reverse iterator */
	typedef ReverseIterator<iterator> reverse_iterator;
	typedef ConstReverseIterator<iterator> const_reverse_iterator;



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

	/*the insertion operation checks whether each inserted element has a key equivalent to the one of an 
	element already in the container, and if so, the element is not inserted, returning an iterator to this
	existing element (if the function returns a value).
	Keys that are less than parent go to left, keys that are bigger than to the right.*/
	template <typename T, typename Compare, bool isMulti>
	pair<typename BST<T, Compare, isMulti>::iterator, bool> BST<T, Compare, isMulti>::insert(iterator position, const value_type &val) {
		Node *pos = position.getP();
		Node *newNode;

		if (!_root)
		{
			_root = new Node(val, NULL, NULL, NULL);
			_size++;
			return make_pair(iterator(this, _root), true);
		}
		/*return a pair, with its member pair::first set to an iterator pointing to either the newly inserted 
		element or to the element with an equivalent key in the map. The pair::second element in the pair is set 
		to true if a new element was inserted or false if an equivalent key already existed.*/

		while (true)
		{
			if (!isMulti && pos->element == val)
				return make_pair(iterator(this, pos), false);
			if (_cmp(val, pos->element)) //pas besoin de check le first element de val, c'est cmp() qui le fait.
			{
				if (pos->left)
					pos = pos->left; // je vais à gauche et à la deuxieme iteration je vais reevaluer si on a un node inf à gauche ou non
				else
				{
					newNode = new Node(val, pos, NULL, NULL);
					pos->left = newNode;
					break;
				}
			}
			else
			{
				if (pos->right)
					pos = pos->right; //idem ci dessus
				else
				{
					newNode = new Node(val, pos, NULL, NULL);
					pos->right = newNode;
					break;
				}
			}
		}
		_size++;
		return make_pair(iterator(this, newNode), true);

	}

	template <typename T, typename Compare, bool isMulti>
	bool BST<T, Compare, isMulti>::map_erase(const value_type &val) { //pass value itself or dereference iterator
		Node *del = NULL;
		Node *delp = NULL;
		Node *cdd = NULL;
		Node *cddp = NULL;
		Node *tmp = NULL;

		if (!_root)
			return false;
		tmp = _root;
		while (tmp)
		{
			if (val.first == tmp->element.first)
			{
				del = tmp;
				break;
			}
			if (_cmp(val, tmp->element))
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		if (!del)
			return false; // nothing to delete
		
		//Before deleting, reorg the BST
		delp = del->parent;
		if (!del->right) // case1. no right node of del
			cdd = del->left;
		else if (!del->right->left) // case2. right node of del has no left child
		{
			cdd = del->right;
			cdd->left = del->left;
			del->left->parent = cdd;
		}
		else // case3
		{
			cddp = del;
			cdd = del->right;
			while (cdd->left)
			{
				cddp = cdd;
				cdd = cdd->left;
			}
			cddp->left = cdd->right;
			if (cdd->right)
				cdd->right->parent = cddp;

			cdd->left = del->left;
			if (del->left)
				del->left->parent = cdd;

			cdd->right = del->right;
			del->right->parent = cdd;
		}
		// make cdd as child of delp
		if (delp)
		{
			Node **delpLR = (delp->left == del) ? &delp->left : &delp->right;
			*delpLR = cdd;
		}
		else
		{
			_root = cdd;
		}
		if (cdd) // if del is not leaf node
			cdd->parent = delp;

		//Finally delete
		delete del;
		_size--;
		return true;
	}


};

#endif
