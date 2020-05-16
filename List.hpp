#ifndef LIST_HPP
# define LIST_HPP

#include <memory>
#include <Iterators.hpp>

namespace ft { //utilisation ft::list

	template <typename T>
	struct ListNode {
		/*Constructor for structure */
		ListNode(ListNode<T> *prv, ListNode<T> *nxt, const T &element) : prv(prv), nxt(nxt),
			element(element) {}
		ListNode<T> *prv;
		ListNode<T> *nxt;
		T element;
	};

	template <typename T, class A = std::allocator<T> >
	class list {

		public:
		/* member type */
			typedef T value_type; //on peut réutiliser value_type de manière générique dès qu'on veut déclarer un nouvel élément
			typedef A allocator_type;
			typedef typename A::reference reference; //reference to element
			typedef typename A::const_reference const_reference;
			typedef typename A::pointer pointer; //pointer to element
			typedef typename A::const_pointer const_pointer;
			typedef typename A::difference_type difference_type;
			typedef typename A::size_type size_type; //quantities of elements
			
		private:
		/*Attributes*/
			allocator_type _allocator; //default to allocator value_type
			ListNode<T> *_li;
			ListNode<T> *_tail;
			size_type _size;

		public:
		/* iterators */
			class iterator : public ListIter<T> // list::iterator
			{

				typedef typename A::reference reference;
				typedef typename A::pointer pointer;

				public:
					iterator() : ListIter<T>(NULL){};
					iterator(const iterator &copy) : ListIter<T>(copy._p){};
					iterator(ListNode<T> *p) : ListIter<T>(p){}; //on peut créer un it == à un endroit
					virtual ~iterator(){};

					iterator &operator=(const iterator &rhs) { this->_p = rhs._p; return (*this); };
					iterator &operator++() { this->_p = this->_p->nxt; return *this; }; // ++it
					iterator operator++(int) { iterator it(this->_p); this->_p = this->_p->nxt; return it; }; // it++
					iterator &operator--() { this->_p = this->_p->prv; return *this; }; // --it
					iterator operator--(int) { iterator it(this->_p); this->_p = this->_p->prv; return it; }; // it--

					reference operator*() const { return this->_p->el; };
					pointer operator->() const { return &(this->_p->el); };
			}; 

			class const_iterator : public ListIter<T> // list::const_iterator
			{
				typedef typename A::reference reference;
				typedef typename A::pointer pointer;

				public:

					const_iterator() : ListIter<T>(NULL){};
					const_iterator(const const_iterator &it) : ListIter<T>(it._p){};
					const_iterator(ListNode<T> *p) : ListBaseIter<T>(p){};
					virtual ~const_iterator(){};

					const_iterator &operator=(const const_iterator &rhs) { this->_p = rhs._p; return (*this); };		
					const_iterator &operator++() { this->_p = this->_p->nxt; return *this; }; // ++it
					const_iterator operator++(int) { const_iterator it(this->_p); this->_p = this->_p->nxt; return it; }; // it++
					const_iterator &operator--() { this->_p = this->_p->prv; return *this; }; // --it
					const_iterator operator--(int) { const_iterator it(this->_p); this->_p = this->_p->prv; return it; }; // it--

					reference operator*() const { return this->_p->el; };
					pointer operator->() const { return &(this->_p->el); };
			};

		/* reverse iterators */
			typedef ReverseIterator<iterator> reverse_iterator; //SYNTAXE??
			typedef ConstReverseIterator<iterator> const_reverse_iterator; //SYNTAXE??

		/* Constructors, destructor, assign */
			/*default*/
			explicit list (const allocator_type& alloc = allocator_type());	
			/* Fill with n elements */
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			/*Range*/
			template <class InputIterator>
			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			/* Copy */
			list (const list& x);
			/*Destructor*/
			~list();
			/*Assign*/
			list& operator= (const list& x);

		/*Iterator functions */
			iterator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

		/*Capacity */
			bool empty() const;
			size_type size() const;
			size_type max_size() const;

		/*Element access */
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;
	};

	template <typename T, typename A>
	list<T, A>::list(const allocator_type &alloc) : _allocator(alloc), _size(0) {
		_li = new ListNode<T>(NULL, NULL, value_type());
	}

	template <typename T, typename A>
	list<T, A>::list(size_type n, const value_type &val, const allocator_type &alloc) : _allocator(alloc), _size(0) {
		_li = new ListNode<T>(NULL, NULL, value_type());
		_tail = _li;
		insert(begin(), n, val); //implement BOTH - assigner tail dans la ft?
	}

	template <typename T, typename A>
	template <class InputIterator>
	list<T, A>::list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) 
	{
		_li = new ListNode<T>(NULL, NULL, value_type());
		insert(begin(), first, last); //a different insert overload - ici il faudra assigner tail
	}

	template <typename T, typename A>
	list<T, A>::list(const list &x) : _allocator(other._allocator), _size(0)
	{
		_li = new ListNode<T>(NULL, NULL, value_type());
		insert(begin(), x.begin(), x.end()); //OTHER OVERLOAD OF INSERT - ici il faudra assigner tail
	}

	template <typename T, typename A>
	list<T, A>::~list()
	{
		clear(); //To be implemented
		delete[] _li;
	}

	template <typename T, typename A>
	list<T, A> &list<T, A>::operator=(const list &x) //Besoin de préciser le type de retour avec template
	{
		clear();
		insert(begin(), x.begin(), x.end());
		return *this;
	}

	template <typename T, typename A>
	typename list<T, A>::iterator list<T, A>::begin() {
		return iterator(_li);
	}

	template <typename T, typename A>
	typename list<T, A>::const_iterator list<T, A>::begin() const {
		return const_iterator(_li);
	}

	template <typename T, typename A>
	typename list<T, A>::iterator list<T, A>::end() {
		return iterator(_tail);
	}
	template <typename T, typename A>
	typename list<T, A>::const_iterator list<T, A>::end() const {
		return const_iterator(_tail);
	}

	template <typename T, typename A>
	typename list<T, A>::reverse_iterator list<T, A>::rbegin() {
		return reverse_iterator(end());
	}

	template <typename T, typename A>
	typename list<T, A>::const_reverse_iterator list<T, A>::rbegin() const {
		return const_reverse_iterator(end());
	}

	template <typename T, typename A>
	typename list<T, A>::reverse_iterator list<T, A>::rend() {
		return reverse_iterator(begin());
	}

	template <typename T, typename A>
	typename list<T, A>::const_reverse_iterator list<T, A>::rend() const {
		return const_reverse_iterator(begin());
	}

	template <typename T, typename A>
	bool list<T, A>::empty() const {
		if (_size)
			return false;
		return true;
	}

	template <typename T, typename A>
	typename list<T, A>::size_type list<T, A>::size() const {
		return _size;
	}

	template <typename T, typename A>
	typename list<T, A>::size_type list<T, A>::max_size() const {
		//TO IMPLEMENT
	}

	template <typename T, typename A>
	typename list<T, A>::reference list<T, A>::front() {
		return _li->element;
	}

	template <typename T, typename A>
	typename list<T, A>::const_reference list<T, A>::front() const {
		return _li->element;
	}

	template <typename T, typename A>
	typename list<T, A>::reference list<T, A>::back() {
		return _tail->element;
	}

	template <typename T, typename A>
	typename list<T, A>::const_reference list<T, A>::back() const {
		return _tail->element;
	}

}; //fin de namespace ft


#endif