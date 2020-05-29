#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include "Pair.hpp"
# include "BST.hpp"
# include "Iterators.hpp"

/*COMPARE : A binary predicate that takes two element keys as arguments and returns a bool. 
The expression comp(a,b), where comp is an object of this type and a and b are key values, 
shall return true if a is considered to go before b in the strict weak ordering the function defines.
The map object uses this expression to determine both the order the elements follow in 
the container and whether two element keys are equivalent (by comparing them reflexively: 
they are equivalent if !comp(a,b) && !comp(b,a)). No two elements in a map container can have equivalent keys.
This can be a function pointer or a function object (see constructor for an example). 
This defaults to less<T>, which returns the same as applying the less-than operator (a<b).
Aliased as member type map::key_compare.*/


namespace ft
{
	//Function object for performing comparisons. Unless specialized, invokes operator< on type T.
	template <class T>
	struct less : std::binary_function<T, T, bool>
	{
		bool operator()(const T &x, const T &y) const { return x < y; }
	};

	template <class Key, class T, class Compare = ft::less<Key>, class A = std::allocator<pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare; //	The third template parameter (Compare), defaults to: less<key_type>
		//Nested function class to compare elements
		class value_compare
		{
			private:
				Compare _cmp;
				value_compare(){};

			public:
				typedef bool result_type;
				typedef pair<const Key, T> first_argument_type;
				typedef pair<const Key, T> second_argument_type;
				~value_compare() {}
				value_compare(const Compare &c) : _cmp(c) {} //prend key_compare() en paramètre - va utiliser la ft key_compare, soit less def ci-dessus
				value_compare(const value_compare &o) : _cmp(o._cmp) {}
				value_compare &operator=(const value_compare &o) 
				{
					_cmp = o._cmp;
					return (*this);
				}
				bool operator()(const pair<const Key, T> &x, const pair<const Key, T> &y) const { return _cmp(x.first, y.first); }
		};

		typedef A allocator_type;
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::pointer pointer;
		typedef typename A::const_pointer const_pointer;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;

		typedef typename BST<value_type, value_compare, false>::iterator iterator;
		typedef typename BST<value_type, value_compare, false>::const_iterator const_iterator;
		typedef typename BST<value_type, value_compare, false>::reverse_iterator reverse_iterator;
		typedef typename BST<value_type, value_compare, false>::const_reverse_iterator const_reverse_iterator;
		
		typedef BSTNode<pair<const Key, T> > Node;

	private:
		BST<pair<const Key, T>, value_compare, false> _tree;
		allocator_type _alloc;
		
	public:
		/*Constructors, destructor, assignation*/
		explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type());
		
		template <class InputIterator>
		map (InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type());
		
		map (const map& x);
		~map();
		map& operator= (const map& x);

		/*Iterators*/
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;

		/*Capacity*/
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		/*Element access*/
		mapped_type& operator[] (const key_type& k);

		/*Modifiers*/
		pair<iterator,bool> insert (const value_type& val);
		iterator insert (iterator position, const value_type& val);
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last);
		void erase (iterator position);
		size_type erase (const key_type& k);
    	void erase (iterator first, iterator last);
		void swap (map& x);
		void clear();

		/*Observers*/
		key_compare key_comp() const;
		value_compare value_comp() const;

		/*Operations*/
		iterator find (const key_type& k);
		const_iterator find (const key_type& k) const;
		size_type count (const key_type& k) const;
		iterator lower_bound (const key_type& k);
		const_iterator lower_bound (const key_type& k) const;
		iterator upper_bound (const key_type& k);
		const_iterator upper_bound (const key_type& k) const;
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
		pair<iterator,iterator> equal_range (const key_type& k);

	};

	template <class Key, class T, class Compare, class A>
	map<Key, T, Compare, A>::map (const key_compare& comp, const allocator_type& alloc): _tree(value_compare(comp)), _alloc(alloc) {

	}
	
	template <class Key, class T, class Compare, class A>
	template <class InputIterator>
	map<Key, T, Compare, A>::map (InputIterator first, InputIterator last, const key_compare& comp,const allocator_type& alloc)
		: _tree(value_compare(comp)), _alloc(alloc) {
		for (InputIterator it = first; it != last; ++it)
		{
			_tree.insert(iterator(&_tree, _tree.getR()), *it);
		}
	}
	
	template <class Key, class T, class Compare, class A>
	map<Key, T, Compare, A>::map (const map& x) {
		: _tree(x._tree), _alloc(x._alloc) //deep copy?
	}

	template <class Key, class T, class Compare, class A>
	~map<Key, T, Compare, A>::map() {
	}

	template <class Key, class T, class Compare, class A>
	map<Key, T, Compare, A> &map<Key, T, Compare, A>::operator= (const map& x) {
		_tree = x._tree; //idem deep copy?
		_alloc = x._alloc;
		return *this; 
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::iterator map<Key, T, Compare, A>::begin() {
		Node *n = _tree.getR();
		if (!n)
			return iterator(&_tree, _tree.getD());
		while (n && n->left) //car on parle du premier element selon key, pas selon si parent ou enfant
			n = n->left;
		return iterator(&_tree, n);
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::const_iterator map<Key, T, Compare, A>::begin() const {
		Node *n = _tree.getR();
		if (!n)
			return const_iterator(&_tree, _tree.getInit());
		while (n && n->left)
			n = n->left;
		return const_iterator(&_tree, n);
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::iterator map<Key, T, Compare, A>::end() {
		return iterator(&_tree, _tree.getInit());
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::const_iterator map<Key, T, Compare, A>::end() const {
		return const_iterator(&_tree, _tree.getInit());
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::reverse_iterator map<Key, T, Compare, A>::rbegin() {
		return reverse_iterator(end());
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::const_reverse_iterator map<Key, T, Compare, A>::rbegin() const {
		return const_reverse_iterator(end());
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::reverse_iterator map<Key, T, Compare, A>::rend() {
		return reverse_iterator(begin());
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::const_reverse_iterator map<Key, T, Compare, A>::rend() const {
		return const_reverse_iterator(begin());
	}

	template <class Key, class T, class Compare, class A>
	bool map<Key, T, Compare, A>::empty() const {
		return _tree.getSize() == 0;
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::size_type map<Key, T, Compare, A>::size() const {
		return _tree.getSize();
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::size_type map<Key, T, Compare, A>::max_size() const {
		return static_cast<size_type>(-1 / sizeof(Node));
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::mapped_type& map<Key, T, Compare, A>::operator[] (const key_type& k) {
		//TO IMPLEMENT
	}

	template <class Key, class T, class Compare, class A>
	pair<map<Key, T, Compare, A>::iterator,bool> map<Key, T, Compare, A>::insert (const value_type& val) {
		return _tree.insert(iterator(&_tree, _tree.getR()), val); //on commence au début du tree
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::iterator map<Key, T, Compare, A>::insert (iterator position, const value_type& val) {
		key_compare cmp = key_comp();
		if (cmp(position->first, val.first) //il faut check avant car si position trop avancée, pas mandatory
			&& upper_bound(position->first) == upper_bound(val.first))
			return _tree.insert(position, val).first; 
		return _tree.insert(iterator(&_tree, _tree.getR()), val).first; //on return un iterator et pas un iterator paired avec un bool comme au-dessus. 
	}
		
	template <class Key, class T, class Compare, class A>
	template <class InputIterator>
	void map<Key, T, Compare, A>::insert (InputIterator first, InputIterator last) {
		for (InputIterator it = first; it != last; ++it)
			insert(*it);
	}

	template <class Key, class T, class Compare, class A>
	void map<Key, T, Compare, A>::erase (iterator position) {

	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::size_type map<Key, T, Compare, A>::erase (const key_type& k) {

	}

	template <class Key, class T, class Compare, class A>
    void map<Key, T, Compare, A>::erase (iterator first, iterator last) {

	}

	template <class Key, class T, class Compare, class A>
	void map<Key, T, Compare, A>::swap (map& x) {
		std::swap(_alloc, x._alloc);
		std::swap(_tree, x._tree);
	}

	template <class Key, class T, class Compare, class A>
	void map<Key, T, Compare, A>::clear() {
		erase(begin(), end());
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::key_compare map<Key, T, Compare, A>::key_comp() const {
		return key_compare();
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::value_compare map<Key, T, Compare, A>::value_comp() const {
		return value_compare(key_compare());
	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::iterator map<Key, T, Compare, A>::find (const key_type& k) {

	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::const_iterator map<Key, T, Compare, A>::find (const key_type& k) const {

	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::size_type map<Key, T, Compare, A>::count (const key_type& k) const {

	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::iterator map<Key, T, Compare, A>::lower_bound (const key_type& k) {

	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::const_iterator map<Key, T, Compare, A>::lower_bound (const key_type& k) const {

	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::iterator map<Key, T, Compare, A>::upper_bound (const key_type& k) {

	}

	template <class Key, class T, class Compare, class A>
	typename map<Key, T, Compare, A>::const_iterator map<Key, T, Compare, A>::upper_bound (const key_type& k) const {

	}

	template <class Key, class T, class Compare, class A>
	pair<typename map<Key, T, Compare, A>::const_iterator, typename map<Key, T, Compare, A>::const_iterator> map<Key, T, Compare, A>::equal_range (const key_type& k) const {

	}

	template <class Key, class T, class Compare, class A>
	pair<typename map<Key, T, Compare, A>::iterator, typename map<Key, T, Compare, A>::iterator> map<Key, T, Compare, A>::equal_range (const key_type& k) {

	}

}; //end namespace

#endif
