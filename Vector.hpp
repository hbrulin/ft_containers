#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "Iterators.hpp"

namespace ft
{
	template <typename T, class A = std::allocator<T> >
	class vector
	{
		public:
			typedef T value_type;
			typedef A allocator_type;
			typedef typename A::reference reference;
			typedef typename A::const_reference const_reference;
			typedef typename A::pointer pointer;
			typedef typename A::const_pointer const_pointer;
			typedef typename A::difference_type difference_type;
			typedef typename A::size_type size_type;

		/*Random access iterators */
		class iterator : public Iter<T>
		{
		public:
			typedef typename A::difference_type difference_type;
			typedef typename A::value_type value_type;
			typedef typename A::reference reference;
			typedef typename A::pointer pointer;
			typedef std::random_access_iterator_tag iterator_category;

			iterator() : Iter<T>(NULL){};
			iterator(const iterator &it) : Iter<T>(it._p){};
			iterator(pointer p) : Iter<T>(p){}; // it = &(arr[0]);
			virtual ~iterator() {};

			iterator &operator=(const iterator &rhs) { this->_p = rhs._p; return (*this); };
			iterator &operator++() { this->_p++; return *this; }; // ++it
			iterator operator++(int) { iterator it = *this; this->_p++; return it; }; // it++
			iterator &operator--() { this->_p--; return *this; }; // --it
			iterator operator--(int) { iterator it = *this; this->_p--; return it; }; // it--
			iterator &operator+=(difference_type n) { this->_p += n; return (*this); };
			iterator operator+(difference_type n) const { return iterator(this->_p + n); };
			friend iterator operator+(difference_type n, const iterator &it) { return iterator(it._p + n); };
			iterator &operator-=(difference_type n) { this->_p -= n; return (*this); };
			iterator operator-(difference_type n) const { return iterator(this->_p - n); };
			difference_type operator-(const BaseIter<T> &other) { return this->_p - other.getP(); };

			reference operator*() const { return *this->_p; };
			pointer operator->() const { return this->_p; };
			reference operator[](difference_type n) const { return *(this->_p + n); };
		};

	/* const iterator */
		class const_iterator : public Iter<T>
		{
		public:
			typedef typename A::difference_type difference_type;
			typedef typename A::value_type value_type;
			typedef const T& reference;
			typedef const T* pointer;
			typedef std::random_access_iterator_tag iterator_category;

			const_iterator() : Iter<T>(NULL){};
			const_iterator(const const_iterator &it) : Iter<T>(it._p){};
			const_iterator(T* p) : Iter<T>(p){}; // it = &(arr[0]);
			virtual ~const_iterator() {};

			const_iterator &operator=(const const_iterator &rhs) { this->_p = rhs._p; return (*this); };		
			const_iterator &operator++() { this->_p++; return *this; }; // ++it
			const_iterator operator++(int) { const_iterator it = *this; this->_p++; return it; }; // it++
			const_iterator &operator--() { this->_p--; return *this; }; // --it
			const_iterator operator--(int) { const_iterator it = *this; this->_p--; return it; }; // it--
			const_iterator &operator+=(difference_type n) { this->_p += n; return (*this); };
			const_iterator operator+(difference_type n) const { return const_iterator(this->_p + n); };
			friend const_iterator operator+(difference_type n, const const_iterator &it) { return const_iterator(it._p + n); };
			const_iterator &operator-=(difference_type n) { this->_p -= n; return (*this); };
			const_iterator operator-(difference_type n) const { return const_iterator(this->_p - n); };
			difference_type operator-(const BaseIter<T> &other) const { return this->_p - other.getP(); };

			reference operator*() const { return *this->_p; };
			pointer operator->() const { return this->_p; };
			reference operator[](difference_type n) const { return *(this->_p + n); };

		};

		typedef ReverseIterator<iterator> reverse_iterator;
		typedef ConstReverseIterator<iterator> const_reverse_iterator;


		private: //other attributes needed?
			allocator_type _allocator;
			pointer _arr; 
			size_type _size;

		public:
			/*Constructors, destructor, assign content*/
			explicit vector (const allocator_type& alloc = allocator_type());		
			explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());	
			vector (const vector& x);
			~vector();
			vector& operator= (const vector& x);

			/*Iterator functions*/
			terator begin();
			const_iterator begin() const;
			iterator end();
			const_iterator end() const;
			reverse_iterator rbegin();
			const_reverse_iterator rbegin() const;
			reverse_iterator rend();
			const_reverse_iterator rend() const;

			/*Capacity*/
			size_type size() const;
			size_type max_size() const;
			void resize (size_type n, value_type val = value_type());
			size_type capacity() const;
			bool empty() const;
			void reserve (size_type n);

			/*Element access */
			reference operator[] (size_type n);
			const_reference operator[] (size_type n) const;
			reference at (size_type n);
			const_reference at (size_type n) const;
			reference front();
			const_reference front() const;
			reference back();
			const_reference back() const;

			/*Assign*/
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last);	
			void assign (size_type n, const value_type& val);

			/*Modifiers*/
			void push_back (const value_type& val);
			void pop_back();
			iterator insert (iterator position, const value_type& val);	
    		void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last);
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap (vector& x);
			void clear();

	};

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		for (typename vector<T, A>::size_type i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		for (typename vector<T, A>::size_type i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return lhs[i] < rhs[i];
		}
		if (lhs.size() == rhs.size())
			return false;
		return lhs.size() < rhs.size();
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs > rhs);
	}

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		for (typename vector<T, A>::size_type i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return lhs[i] > rhs[i];
		}
		if (lhs.size() == rhs.size())
			return false;
		return lhs.size() > rhs.size();
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}


/*AJOUTER TYPENAM OU NECESSAIRE*/

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		  x.swap(y);
	}

	template <typename T, typename A>
	vector<T, A>::vector (const allocator_type& alloc = allocator_type()) {

	}		
	
	template <typename T, typename A>
	vector<T, A>::vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {

	}

	template <typename T, typename A>
	template <class InputIterator>
	vector<T, A>::vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {

	}
	
	template <typename T, typename A>
	vector<T, A>::vector (const vector& x) {

	}
		
	template <typename T, typename A>
	vector<T, A>::~vector() {

	}
			
	template <typename T, typename A>
	vector<T, A>::vector& vector<T, A>::operator= (const vector<T, A>::vector& x) {

	}

	template <typename T, typename A>
	iterator vector<T, A>::begin() {

	}
	
	template <typename T, typename A>
	const_iterator vector<T, A>::begin() const {

	}

	template <typename T, typename A>
	iterator vector<T, A>::end() {

	}

	template <typename T, typename A>
	const_iterator vector<T, A>::end() const {

	}

	template <typename T, typename A>
	reverse_iterator vector<T, A>::rbegin() {

	}

	template <typename T, typename A>
	const_reverse_iterator vector<T, A>::rbegin() const {

	}

	template <typename T, typename A>
	reverse_iterator vector<T, A>::rend() {

	}

	template <typename T, typename A>
	const_reverse_iterator vector<T, A>::rend() const {

	}

	template <typename T, typename A>
	size_type vector<T, A>::size() const {

	}

	template <typename T, typename A>
	size_type vector<T, A>::max_size() const {

	}

	template <typename T, typename A>
	void vector<T, A>::resize (size_type n, value_type val = value_type()) {

	}

	template <typename T, typename A>
	size_type vector<T, A>::capacity() const {

	}

	template <typename T, typename A>
	bool vector<T, A>::empty() const {

	}

	template <typename T, typename A>
	void vector<T, A>::reserve (size_type n) {

	}

	template <typename T, typename A>
	reference vector<T, A>::operator[] (size_type n) {

	}

	template <typename T, typename A>
	const_reference vector<T, A>::operator[] (size_type n) const {

	}

	template <typename T, typename A>
	reference vector<T, A>::at (size_type n) {

	}

	template <typename T, typename A>
	const_reference vector<T, A>::at (size_type n) const {

	}

	template <typename T, typename A>
	reference vector<T, A>::front() {

	}

	template <typename T, typename A>
	const_reference vector<T, A>::front() const {

	}

	template <typename T, typename A>
	reference vector<T, A>::back() {

	}

	template <typename T, typename A>
	const_reference vector<T, A>::back() const {

	}

	template <typename T, typename A>
	template <class InputIterator>
  	void vector<T, A>::assign (InputIterator first, InputIterator last) {

	}

	template <typename T, typename A>
	void vector<T, A>::assign (size_type n, const value_type& val) {

	}

	template <typename T, typename A>
	void vector<T, A>::push_back (const value_type& val) {

	}

	template <typename T, typename A>
	void vector<T, A>::pop_back() {

	}

	template <typename T, typename A>
	iterator vector<T, A>::insert (iterator position, const value_type& val) {

	}

	template <typename T, typename A>
    void vector<T, A>::insert (iterator position, size_type n, const value_type& val) {

	}

	template <typename T, typename A>
	template <class InputIterator>
    void vector<T, A>::insert (iterator position, InputIterator first, InputIterator last) {

	}

	template <typename T, typename A>
	iterator vector<T, A>::erase (iterator position) {

	}

	template <typename T, typename A>
	iterator vector<T, A>::erase (iterator first, iterator last) {

	}
	
	template <typename T, typename A>
	void vector<T, A>::swap (vector& x) {

	}

	template <typename T, typename A>
	void vector<T, A>::clear() {

	}

};

#endif