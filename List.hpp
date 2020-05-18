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
			ListNode<T> *_li; //son prv c'est le dernier node, son nxt c'est le premier. Boucle. Permet de retourner l'iterateur end, qui est past-the-end element.
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
					const_iterator(ListNode<T> *p) : ListIter<T>(p){};
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
		
		/*Assign modifiers*/
		/*Les surcharges de la méthode assign se comportent un peu comme les deux derniers constructeurs, 
		à ceci près qu'elles ne prennent pas d'allocateur en paramètre. La première méthode permet donc 
		de réinitialiser la liste et de la remplir avec un certain nombre de copies d'un objet donné, 
		et la deuxième permet de réinitialiser la liste et de la remplir avec une séquence d'objets 
		définie par deux itérateurs.*/
		template <class InputIterator>
  		void assign (InputIterator first, InputIterator last);	
		void assign (size_type n, const value_type& val);

		/*Other modifiers */
		void push_front(const value_type& val);
		void pop_front();
		void push_back(const value_type& val);
		void pop_back();
		iterator insert (iterator position, const value_type& val);
    	void insert (iterator position, size_type n, const value_type& val);	
		template <class InputIterator>
    	void insert (iterator position, InputIterator first, InputIterator last);
		iterator erase (iterator position);
		iterator erase (iterator first, iterator last);
		void swap (list& x);
		void resize (size_type n, value_type val = value_type());
		void clear();

		/*Operations */
	};

	template <typename T, typename A>
	list<T, A>::list(const allocator_type &alloc) : _allocator(alloc), _size(0) {
		_li = new ListNode<T>(NULL, NULL, value_type());
	}

	template <typename T, typename A>
	list<T, A>::list(size_type n, const value_type &val, const allocator_type &alloc) : _allocator(alloc), _size(0) {
		_li = new ListNode<T>(NULL, NULL, value_type());
		_tail = _li;
		insert(begin(), n, val);
	}

	template <typename T, typename A>
	template <class InputIterator>
	list<T, A>::list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) 
	{
		_li = new ListNode<T>(NULL, NULL, value_type());
		insert(begin(), first, last);
	}

	template <typename T, typename A>
	list<T, A>::list(const list &x) : _allocator(other._allocator), _size(0)
	{
		_li = new ListNode<T>(NULL, NULL, value_type());
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
		//TO IMPLEMENT
	}

	template <typename T, typename A>
	typename list<T, A>::reference list<T, A>::front() {
		return _tip->nxt->el;
	}

	template <typename T, typename A>
	typename list<T, A>::const_reference list<T, A>::front() const {
		return _tip->nxt->el;
	}

	template <typename T, typename A>
	typename list<T, A>::reference list<T, A>::back() {
		return _tip->prv->el; //le dernier node pointe sur type. Boucle.
	}

	template <typename T, typename A>
	typename list<T, A>::const_reference list<T, A>::back() const {
		return _tip->nxt->el;
	}

	template <class InputIterator>
	template <typename T, typename A>
	void list<T, A>::assign (InputIterator first, InputIterator last) {
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
			ListNode<T> *_prev = position.getP()->prv;
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
    void list<T, A>::insert(typename list<T, A>::iterator position, InputIterator first, InputIterator last) {
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
			ListNode<T> *_prev = position.getP()->prv;
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
	void swap (list& x) {
		//TO IMPLEMENT
	}

	template <typename T, typename A>
	void resize (size_type n, value_type val = value_type()) {
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
	void clear() {
		erase(begin(), end());
	}


}; //fin de namespace ft


#endif