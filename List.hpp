#ifndef LIST_HPP
# define LIST_HPP

#include <memory>
#include "Iterators.hpp"
#include "Utils.hpp"

namespace ft { //utilisation ft::list

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
			ListNode<T> *_li; //son prv c'est le dernier node, son nxt c'est le premier. Boucle. Permet de retourner l'iterateur end, qui est past-the-end element.
			size_type _size;

		public:
		/* bidirectional iterators */
			class iterator : public ListIter<T> // list::iterator
			{
				public :

				typedef typename A::difference_type difference_type;
				typedef typename A::value_type value_type;
				typedef typename A::reference reference;
				typedef typename A::pointer pointer;
				typedef std::bidirectional_iterator_tag iterator_category;

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

					reference operator*() const { return this->_p->element; };
					pointer operator->() const { return &(this->_p->element); };
			}; 

			class const_iterator : public ListIter<T> // list::const_iterator
			{
				typedef typename A::difference_type difference_type;
				typedef typename A::value_type value_type;
				typedef const T& reference;
				typedef const T* pointer;
				typedef std::random_access_iterator_tag iterator_category;

				public:

					const_iterator() : ListIter<T>(NULL){};
					const_iterator(const const_iterator &it) : ListIter<T>(it._p){};
					const_iterator(const iterator &it) : ListIter<T>(it.getP()){}; //pour choper le resultat de begin
					const_iterator(ListNode<T> *p) : ListIter<T>(p){};
					virtual ~const_iterator(){};

					const_iterator &operator=(const const_iterator &rhs) { this->_p = rhs._p; return (*this); };		
					const_iterator &operator++() { this->_p = this->_p->nxt; return *this; }; // ++it
					const_iterator operator++(int) { const_iterator it(this->_p); this->_p = this->_p->nxt; return it; }; // it++
					const_iterator &operator--() { this->_p = this->_p->prv; return *this; }; // --it
					const_iterator operator--(int) { const_iterator it(this->_p); this->_p = this->_p->prv; return it; }; // it--

					reference operator*() const { return this->_p->element; };
					pointer operator->() const { return &(this->_p->element); };
			};

		/* reverse iterators */
			typedef ReverseIterator<iterator> reverse_iterator; 
			typedef ConstReverseIterator<iterator> const_reverse_iterator; 

		/* Constructors, destructor, assign */
			/*default*/
			explicit list (const allocator_type& alloc = allocator_type());	
			/* Fill with n elements */
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			/*Range*/
			template <class InputIterator>
			list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator());
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
		
		/*Assign modifiers*/
		/*Les surcharges de la méthode assign se comportent un peu comme les deux derniers constructeurs, 
		à ceci près qu'elles ne prennent pas d'allocateur en paramètre. La première méthode permet donc 
		de réinitialiser la liste et de la remplir avec un certain nombre de copies d'un objet donné, 
		et la deuxième permet de réinitialiser la liste et de la remplir avec une séquence d'objets 
		définie par deux itérateurs.*/
		template <class InputIterator>
  		void assign(InputIterator first, InputIterator last,
			typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator());
		void assign(size_type n, const value_type& val);

		/*Other modifiers */
		void push_front(const value_type& val);
		void pop_front();
		void push_back(const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
    	void insert (iterator position, size_type n, const value_type& val);	
		template <class InputIterator>
    	void insert(iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator());
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (list& x);
		void resize (size_type n, value_type val = value_type());
		void clear();

		/*Operations */
		void splice (iterator position, list& x);
		void splice (iterator position, list& x, iterator i);	
		void splice (iterator position, list& x, iterator first, iterator last);	
		void remove (const value_type& val);
		template <class Predicate>
  		void remove_if (Predicate pred);
		void unique();
		template <class BinaryPredicate>
  		void unique (BinaryPredicate binary_pred);
		void merge (list& x);
		template <class Compare>
  		void merge (list& x, Compare comp);
		void sort();
		template <class Compare>
  		void sort (Compare comp);
		void reverse();

	};

	/* Non-member functions */
	template <class T, class A>
	bool operator== (const list<T,A>& lhs, const list<T,A>& rhs) {
		if (lhs.size() != rhs.size())
		return false;
		typename list<T, A>::const_iterator lit = lhs.begin();
		typename list<T, A>::const_iterator rit = rhs.begin();
		for (; lit != lhs.end() && rit != rhs.end(); ++lit, ++rit)
		{
			if (*lit != *rit)
				return false;
		}
		return true;
	}

	template <class T, class A>
	bool operator!= (const list<T,A>& lhs, const list<T,A>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class A>
	bool operator<(const list<T,A>& lhs, const list<T,A>& rhs) {
		typename list<T, A>::const_iterator itl = lhs.begin();
		typename list<T, A>::const_iterator itr = rhs.begin();

		for (; itl != lhs.end() && itr != rhs.end(); ++itl, ++itr)
		{
			if (*itl != *itr)
				return *itl < *itr;
		}
		if (lhs.size() == rhs.size())
			return false;
		return lhs.size() < rhs.size();
	}

	template <class T, class A>
	bool operator<=(const list<T,A>& lhs, const list<T,A>& rhs) {
		return !(lhs > rhs);
	}

	template <class T, class A>
	bool operator>(const list<T,A>& lhs, const list<T,A>& rhs) {
		typename list<T, A>::const_iterator itl = lhs.begin();
		typename list<T, A>::const_iterator itr = rhs.begin();

		for (; itl != lhs.end() && itr != rhs.end(); ++itl, ++itr)
		{
			if (*itl != *itr)
				return *itl > *itr;
		}
		if (lhs.size() == rhs.size())
			return false;
		return lhs.size() > rhs.size();
	}

	template <class T, class A>
	bool operator>=(const list<T,A>& lhs, const list<T,A>& rhs) {
		return !(lhs < rhs);
	}

	template <class T, class A>
  	void swap (list<T,A>& x, list<T,A>& y) {
		  x.swap(y);
	}

	template <typename T, typename A>
	list<T, A>::list(const allocator_type &alloc) : _allocator(alloc), _size(0) {
		_li = new ListNode<T>(NULL, NULL, value_type());
		_li->prv = _li;
		_li->nxt = _li;
	}

	template <typename T, typename A>
	list<T, A>::list(size_type n, const value_type &val, const allocator_type &alloc) : _allocator(alloc), _size(0) {
		_li = new ListNode<T>(NULL, NULL, value_type());
		_li->prv = _li;
		_li->nxt = _li;
		insert(begin(), n, val);
	}

	template <typename T, typename A>
	template <class InputIterator>
	list<T, A>::list(InputIterator first, InputIterator last, const allocator_type& alloc,
		typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter) : _allocator(alloc), _size(0) //pour qu'utilisation seulement si Iterator, pas de int
	{
		_li = new ListNode<T>(NULL, NULL, value_type());
		_li->prv = _li;
		_li->nxt = _li;
		insert(begin(), first, last);
	}

	template <typename T, typename A>
	list<T, A>::list(const list &x) : _allocator(x._allocator), _size(0)
	{
		_li = new ListNode<T>(NULL, NULL, value_type());
		_li->prv = _li;
		_li->nxt = _li;
		insert(begin(), x.begin(), x.end());
	}

	template <typename T, typename A>
	list<T, A>::~list()
	{
		clear();
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
		return iterator(_li->nxt);
	}

	template <typename T, typename A>
	typename list<T, A>::const_iterator list<T, A>::begin() const {
		return const_iterator(_li->nxt);
	}

	/*Returns an iterator referring to the past-the-end element in the list container.*/
	template <typename T, typename A>
	typename list<T, A>::iterator list<T, A>::end() {
		return iterator(_li);
	}
	template <typename T, typename A>
	typename list<T, A>::const_iterator list<T, A>::end() const {
		return const_iterator(_li);
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
		/*Max size = maximun valeur de size_type divise par taille de list node
		Size_type est toujour positive, donc il y a under flow
		-1 devient max*/
		return static_cast<size_type>(-1 / sizeof(ListNode<T>));
	}

	template <typename T, typename A>
	typename list<T, A>::reference list<T, A>::front() {
		return _li->nxt->element;
	}

	template <typename T, typename A>
	typename list<T, A>::const_reference list<T, A>::front() const {
		return _li->nxt->element;
	}

	template <typename T, typename A>
	typename list<T, A>::reference list<T, A>::back() {
		return _li->prv->element; //le dernier node pointe sur type. Boucle.
	}

	template <typename T, typename A>
	typename list<T, A>::const_reference list<T, A>::back() const {
		return _li->nxt->element;
	}

	
	template <typename T, typename A>
	template <class InputIterator>
	void list<T, A>::assign(InputIterator first, InputIterator last,
	typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter) {
		clear();
		insert(begin(), first, last);
	}	

	template <typename T, typename A>
	void list<T, A>::assign (size_type n, const value_type& val) {
		clear();
		insert(begin(), n, val);
	}

	template <typename T, typename A>
	void list<T, A>::push_front (const value_type& val) {
		insert(begin(), val);
	}

	template <typename T, typename A>
	void list<T, A>::pop_front() {
		erase(begin());
	}

	template <typename T, typename A>
	void list<T, A>::push_back (const value_type& val) {
		insert(end(), val);
	}

	template <typename T, typename A>
	void list<T, A>::pop_back() {
		iterator it(end());
		erase(--it);
	}

	template <typename T, typename A>
	typename list<T, A>::iterator list<T, A>::insert(typename list<T, A>::iterator position, const value_type& val) {
		insert(position, 1, val);
		return --position;
	}

	template <typename T, typename A>
    void list<T, A>::insert(typename list<T, A>::iterator position, size_type n, const value_type& val) {
		ListNode<T> *start;
		ListNode<T> *cur;
		ListNode<T> *nxt;

		if (n > max_size() || n < 0)
			return ; 
		/*Make sublist*/
		for (size_type i = 0; i < n; i++)
		{
			if (i == 0)
			{					
				start = new ListNode<T>(NULL, NULL, val);
				cur = start;
				nxt = cur;
			}
			else
			{	
				nxt = new ListNode<T>(cur, NULL, val);
				cur->nxt = nxt;
				cur = cur->nxt;
			}
		}
		if (_size == 0) 
		{
			_li->nxt = start;
			start->prv = _li;
			nxt->nxt = _li; // A ce stade nxt c'est le dernier node.
			_li->prv = nxt;
		} 
		else 
		{
			//stock existing state of list
			ListNode<T> *pos_node = position.getP();
			ListNode<T> *prev = position.getP()->prv;
			// Plug prev to start of sublist
			prev->nxt = start;
			start->prv = prev;
			// Plug tail to node initially in position
			nxt->nxt = pos_node;
			pos_node->prv = nxt;
		}
	_size += n;
	}

	template <typename T, typename A>
	template <class InputIterator>
    void list<T, A>::insert(iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter) {
		ListNode<T> *start;
		ListNode<T> *cur;
		ListNode<T> *nxt;
		size_type nb = 0;

		// create sublist
		int i = 0;
		for (InputIterator it = first; it != last; ++it, ++i)
		{
			if (i == 0)
			{
				start = new ListNode<T>(NULL, NULL, *it);
				cur = start;
				nxt = cur;
			}
			else
			{
				nxt = new ListNode<T>(cur, NULL, *it);
				cur->nxt = nxt;
				cur = cur->nxt;
			}
			nb++;
		}
		if (!nb)
			return ;

		if (_size == 0)
		{
			_li->nxt = start;
			start->prv = _li;
			nxt->nxt = _li; // last point to _tip
			_li->prv = nxt;
		}
		else
		{
			//stock existing state of list
			ListNode<T> *pos_node = position.getP();
			ListNode<T> *prev = position.getP()->prv;
			// Plug prev to start of sublist
			prev->nxt = start;
			start->prv = prev;
			// Plug tail to node initially in position
			nxt->nxt = pos_node;
			pos_node->prv = nxt;
		}
		_size += nb;
	}

	template <typename T, typename A>
	typename list<T, A>::iterator list<T, A>::erase (typename list<T, A>::iterator position) {
		iterator it(position);
		return erase(position, ++it);
	}

	template <typename T, typename A>
	typename list<T, A>::iterator list<T, A>::erase (typename list<T, A>::iterator first, typename list<T, A>::iterator last) {
		ListNode<T> *fst = first.getP();
		ListNode<T> *lst = last.getP();
		ListNode<T> *prev = fst->prv;
		size_type nb = 0;
		
		while (fst != lst)
		{
			ListNode<T> *tmp = fst->nxt;
			if (fst != _li) {
				delete fst;
				nb++;
			}
			fst = tmp;
		}
		_size -= nb;
		prev->nxt = lst; /*Last is not to be erased*/
		lst->prv = prev;
		return iterator(lst);
	}

	template <typename T, typename A>
	void list<T, A>::swap (list& x) {
		std::swap(_size, x._size); //swap ft template de std
		std::swap(_li, x._li);
	}

	template <typename T, typename A>
	void list<T, A>::resize (size_type n, value_type val) {
		if (n < size())
		{
			iterator it = begin();
			for (size_t i = 0; i < n; i++)
				++it;
			erase(it, end());
		}
		else if (n > size())
			insert(end(), n - size(), val);
	}

	template <typename T, typename A>
	void list<T, A>::clear() {
		erase(begin(), end());
	}

	template <typename T, typename A>
	void list<T, A>::splice (typename list<T, A>::iterator position, list& x) {
		this->insert(position, x.begin(), x.end());
		x.clear();
	}

	/*Single element transferred*/
	template <typename T, typename A>
	void list<T, A>::splice (typename list<T, A>::iterator position, list& x, typename list<T, A>::iterator i) {
		this->insert(position, *i);
		x.erase(i);
	}

	template <typename T, typename A>
	void list<T, A>::splice (typename list<T, A>::iterator position, list& x, typename list<T, A>::iterator first, typename list<T, A>::iterator last) {
		this->insert(position, first, last);
		x.erase(first, last);
	}	

	//remove by value
	template <typename T, typename A>
	void list<T, A>::remove (const value_type& val) {
		for (iterator it = begin(); it != end();)
		{
			if (*it == val)
				it = erase(it);
			else
				++it;
		}
	}

	/*Removes from the container all the elements for which Predicate pred returns true.
	This calls the destructor of these objects and reduces the container size by the number of elements removed.
	The function calls pred(*i) for each element (where i is an iterator to that element). 
	Any of the elements in the list for which this returns true, are removed from the container.*/
	template <typename T, typename A>
	template <class Predicate>
  	void list<T, A>::remove_if (Predicate pred) {
		  for (iterator it = begin(); it != end();)
		{
			if (pred(*it))
				it = erase(it);
			else
				++it;
		}
	}

	/*removes all but the first element from every consecutive group of equal elements in the container.*/
	/*an element is only removed from the list container if it compares equal to the element immediately 
	preceding it. Thus, this function is especially useful for sorted lists.*/
	template <typename T, typename A>
	void list<T, A>::unique() {
		iterator start = begin();
		++start;
		for (iterator it = start; it != end();)
		{
			iterator tmp = it;
			--tmp;
			if (*tmp == *it) //tester avec *(it - 1)
				it = erase(it);
			else
				++it;
		}
	}

	/*Binary predicate that, taking two values of the same type than those contained in the list,
	returns true to remove the element passed as first argument from the container, and false otherwise.
	This shall be a function pointer or a function object.	*/
	template <typename T, typename A>
	template <class BinaryPredicate>
  	void list<T, A>::unique (BinaryPredicate binary_pred) {
		iterator start = begin();
		++start;
		for (iterator it = start; it != end();)
		{
			iterator tmp = it;
			--tmp;
			if (binary_pred(*it, *tmp)) //tester avec *(it - 1)
				it = erase(it);
			else
				++it;
		}
	}

/*This effectively removes all the elements in x (which becomes empty), 
and inserts them into their ordered position within container 
(which expands in size by the number of elements transferred). 
The operation is performed without constructing nor destroying any element: they are transferred,*/
	template <typename T, typename A>
	void list<T, A>::merge (list& x) {
		ListNode<T> *og = begin().getP(); // original
		ListNode<T> *xp = x.begin().getP(); // other
		ListNode<T> *xnxt;
		ListNode<T> *bef;
		while (xp != x._li)
		{
			if (og == end().getP() || xp->element < og->element) //soit on plug à la fin, soit on plug one by one a l'endroit aproprié
			{
				xnxt = xp->nxt;
				bef = og->prv;
				// link bef - x
				bef->nxt = xp;
				xp->prv = bef;
				// link x - og
				xp->nxt = og;
				og->prv = xp;
				// move x
				xp = xnxt;
			} 
			else
				og = og->nxt;
		}
		_size += x._size;
		//Elements removal from x, without destroying them
		x._size = 0;
		ListNode<T> *xli = x._li;
		xli->nxt = xli;
		xli->prv = xli;
	}

	template <typename T, typename A>
	template <class Compare>
  	void list<T, A>::merge (list& x, Compare comp) {
		ListNode<T> *og = begin().getP();	// original
		ListNode<T> *xp = x.begin().getP(); // other
		ListNode<T> *xnxt;
		ListNode<T> *bef;
		while (xp != x._li)
		{
			if (og == end().getP() || comp(xp->element, og->element))
			{
				xnxt = xp->nxt;
				bef = og->prv;
				// link bef - x
				bef->nxt = xp;
				xp->prv = bef;
				// link x - og
				xp->nxt = og;
				og->prv = xp;
				// move x
				xp = xnxt;
			}
			else
				og = og->nxt;
		}
		_size += x._size;
		//Elements removal from x, without destroying them
		x._size = 0;
		ListNode<T> *xli = x._li;
		xli->nxt = xli;
		xli->prv = xli;
	}

	template <typename T, typename A>
	void list<T, A>::sort() {
		ListNode<T> *a = _li->nxt;
		ListNode<T> *b = a->nxt;
		ListNode<T> *bef;
		ListNode<T> *aft;
		while (b != _li)
		{ 	// bef -> a -> b -> aft
			if (b->element < a->element) 
			{
				bef = a->prv;
				aft = b->nxt;
				// link bef -> b
				bef->nxt = b;
				b->prv = bef;
				// link b -> a
				b->nxt = a;
				a->prv = b;
				// link a-> aft
				a->nxt = aft;
				aft->prv = a;
				// retun to begin
				a = _li->nxt;
				b = a->nxt;
			} 
			else 
			{
				a = a->nxt;
				b = b->nxt;
			}
		}
	}

	template <typename T, typename A>
	template <class Compare>
  	void list<T, A>::sort (Compare comp) {
		ListNode<T> *a = _li->nxt;
		ListNode<T> *b = a->nxt;
		ListNode<T> *bef;
		ListNode<T> *aft;
		while (b != _li)
		{ 	// bef -> a -> b -> aft
			if (comp(b->element, a->element))
			{
				bef = a->prv;
				aft = b->nxt;
				// link bef -> b
				bef->nxt = b;
				b->prv = bef;
				// link b -> a
				b->nxt = a;
				a->prv = b;
				// link a-> aft
				a->nxt = aft;
				aft->prv = a;
				// retun to begin
				a = _li->nxt;
				b = a->nxt;
			} 
			else 
			{
				a = a->nxt;
				b = b->nxt;
			}
		}
	}

	template <typename T, typename A>
	void list<T, A>::reverse() {
		ListNode<T> *cur = _li->nxt;
		ListNode<T> *next;
		ListNode<T> *tmp;

		while (cur != _li)
		{
			next = cur->nxt;
			/*swap a->nxt and a->prv */
			tmp = cur->nxt;
			cur->nxt = cur->prv;
			cur->prv = tmp;
			/*go to next node*/
			cur = next;
		}
		// swap dernier node
		tmp = cur->nxt;
		cur->nxt = cur->prv;
		cur->prv = tmp;
	}

}; //fin de namespace ft


#endif