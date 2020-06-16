#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept> 
/*This header defines a set of standard exceptions that both 
the library and programs can use to report common errors. I don't need to make classes to use length error, it is already defined*/
# include "Iterators.hpp"
# include "Utils.hpp"

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
			iterator &operator-=(difference_type n) { this->_p -= n; return (*this); };
			iterator operator-(difference_type n) const { return iterator(this->_p - n); };

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
			const_iterator(const iterator &it) : Iter<T>(it.getP()){};
			const_iterator(T* p) : Iter<T>(p){}; // it = &(arr[0]);
			virtual ~const_iterator() {};

			const_iterator &operator=(const const_iterator &rhs) { this->_p = rhs._p; return (*this); };		
			const_iterator &operator++() { this->_p++; return *this; }; // ++it
			const_iterator operator++(int) { const_iterator it = *this; this->_p++; return it; }; // it++
			const_iterator &operator--() { this->_p--; return *this; }; // --it
			const_iterator operator--(int) { const_iterator it = *this; this->_p--; return it; }; // it--
			const_iterator &operator+=(difference_type n) { this->_p += n; return (*this); };
			const_iterator operator+(difference_type n) const { return const_iterator(this->_p + n); };
			const_iterator &operator-=(difference_type n) { this->_p -= n; return (*this); };
			const_iterator operator-(difference_type n) const { return const_iterator(this->_p - n); };

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
			size_type _cap;

		public:
			/*Constructors, destructor, assign content*/
			explicit vector (const allocator_type& alloc = allocator_type());		
			explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
				typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator());
			vector (const vector& x);
			~vector();
			vector& operator= (const vector& x);

			/*Iterator functions*/
			iterator begin();
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
  			void assign(InputIterator first, InputIterator last,
				typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator());
			void assign (size_type n, const value_type& val);

			/*Modifiers*/
			void push_back (const value_type& val);
			void pop_back();
			iterator insert (iterator position, const value_type& val);	
    		void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
    		void insert(iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter = InputIterator());
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);
			void swap (vector& x);
			void clear();

	};

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++)
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
		for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size() && i < rhs.size(); i++)
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
		for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size() && i < rhs.size(); i++)
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


	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		  x.swap(y);
	}

	template <typename T, typename A>
	vector<T, A>::vector (const allocator_type& alloc): _allocator(alloc), _arr(NULL), _size(0), _cap(0) {

	}		
	
	template <typename T, typename A>
	vector<T, A>::vector (size_type n, const value_type& val, const allocator_type& alloc): _allocator(alloc), _size(n), _cap(n) {
		_arr = _allocator.allocate(n);
		for (size_type i = 0; i < n; i++) 
		{	/*Constructs an object of type T in allocated uninitialized storage pointed to by p, using placement-new*/
			_allocator.construct(_arr + i, val);
		}
	}

	template <typename T, typename A>
	template <class InputIterator>
	vector<T, A>::vector(InputIterator first, InputIterator last, const allocator_type &alloc,
		typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter) {
		_size = last - first;
		_cap = _size;
		_arr = _allocator.allocate(_size);
		int i = 0;
		for (InputIterator it = first; it != last; ++it, ++i)
		{
			_allocator.construct(_arr + i, *it);
		}
	}
	
	template <typename T, typename A>
	vector<T, A>::vector (const vector& x): _allocator(x._allocator), _size(x._size), _cap(x._cap) {
		if (x._arr) 
		{
			_arr = _allocator.allocate(_cap);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_arr + i, x._arr[i]);
		}
	}
		
	template <typename T, typename A>
	vector<T, A>::~vector() {
		if (_cap) 
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_arr + i);
			_allocator.deallocate(_arr, _cap);
		}
	}
			
	template <typename T, typename A>
	vector<T, A> &vector<T, A>::operator= (const vector& x) {
		if (_arr) 
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_arr + i);
			_allocator.deallocate(_arr, _cap);
		}
		// deep copy
		if (x._arr) {
			_arr = _allocator.allocate(x._cap);
			for (size_type i = 0; i < x._size; i++)
				_allocator.construct(_arr + i, x._arr[i]);
		}
		_size = x._size;
		_cap = x._cap;
	}

	template <typename T, typename A>
	typename vector<T, A>::iterator vector<T, A>::begin() {
		return (iterator(_arr));
	}
	
	template <typename T, typename A>
	typename vector<T, A>::const_iterator vector<T, A>::begin() const {
		return (const_iterator(_arr));
	}

	/*Returns an iterator referring to the past-the-end element in the vector container.*/
	template <typename T, typename A>
	typename vector<T, A>::iterator vector<T, A>::end() {
		return (iterator(_arr + _size));
	}

	template <typename T, typename A>
	typename vector<T, A>::const_iterator vector<T, A>::end() const {
		return (const_iterator(_arr + _size));
	}

	template <typename T, typename A>
	typename vector<T, A>::reverse_iterator vector<T, A>::rbegin() {
		return reverse_iterator(end());
	}

	template <typename T, typename A>
	typename vector<T, A>::const_reverse_iterator vector<T, A>::rbegin() const {
		return const_reverse_iterator(end());
	}

	template <typename T, typename A>
	typename vector<T, A>::reverse_iterator vector<T, A>::rend() {
		return reverse_iterator(begin());
	}

	template <typename T, typename A>
	typename vector<T, A>::const_reverse_iterator vector<T, A>::rend() const {
		return const_reverse_iterator(begin());
	}

	template <typename T, typename A>
	typename vector<T, A>::size_type vector<T, A>::size() const {
		return (_size);
	}

	/*même calcul que pour listes*/
	template <typename T, typename A>
	typename vector<T, A>::size_type vector<T, A>::max_size() const {
		return static_cast<size_type>(-1 / sizeof(T));
	}

	/*If n is also greater than the current container capacity, 
	an automatic reallocation of the allocated storage space takes place -> insert() uses reserve()*/
	template <typename T, typename A>
	void vector<T, A>::resize (size_type n, value_type val) {
		if (n < size())
		{
			erase(begin() + n, end());
		}
		else if (n > size())
		{
			insert(end(), n - size(), val);
	}
	}

	template <typename T, typename A>
	typename vector<T, A>::size_type vector<T, A>::capacity() const {
		return (_cap);
	}

	template <typename T, typename A>
	bool vector<T, A>::empty() const {
		return (_size == 0);
	}

	/*This function has no effect on the vector size and cannot alter its elements.*/
	template <typename T, typename A>
	void vector<T, A>::reserve (size_type n) {
		if (n > max_size()) 
			throw std::length_error("lenght error");
		else if (n > _cap) 
		{
			T *newArr = _allocator.allocate(n);
			for (size_t i = 0; i < _size; i++)
			{
				_allocator.construct(&newArr[i], _arr[i]);
				_allocator.destroy(&_arr[i]);
			}
			_allocator.deallocate(_arr, _cap);
			_arr = newArr;
			_cap = n;
		}
	}
	
	/*No out of bound check*/
	template <typename T, typename A>
	typename vector<T, A>::reference vector<T, A>::operator[] (size_type n) {
		return _arr[n];
	}

	template <typename T, typename A>
	typename vector<T, A>::const_reference vector<T, A>::operator[] (size_type n) const {
		return _arr[n];
	}

	/*Returns a reference to the element at position n in the vector.
	The function automatically checks whether n is within the bounds of valid elements in the vector*/
	template <typename T, typename A>
	typename vector<T, A>::reference vector<T, A>::at (size_type n) {
		if (n >= size())
			throw std::out_of_range("out of range");
		return _arr[n];
	}

	template <typename T, typename A>
	typename vector<T, A>::const_reference vector<T, A>::at (size_type n) const {
		if (n >= size())
			throw std::out_of_range("out of range");
		return _arr[n];
	}

	template <typename T, typename A>
	typename vector<T, A>::reference vector<T, A>::front() {
		return (*begin()); //if empty, undefined behavior so no exception
	}

	template <typename T, typename A>
	typename vector<T, A>::const_reference vector<T, A>::front() const {
		return (*begin());
	}

	template <typename T, typename A>
	typename vector<T, A>::reference vector<T, A>::back() {
		return (*--end());
	}

	template <typename T, typename A>
	typename vector<T, A>::const_reference vector<T, A>::back() const {
		return (*--end());
	}

	template <typename T, typename A>
	template <class InputIterator>
  	void vector<T, A>::assign(InputIterator first, InputIterator last,
		typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter) {
		clear();
		insert(begin(), first, last);
	}

	template <typename T, typename A>
	void vector<T, A>::assign (size_type n, const value_type& val) {
		clear();
		insert(begin(), n, val);
	}

	template <typename T, typename A>
	void vector<T, A>::push_back (const value_type& val) {
		insert(end(), val);
	}

	template <typename T, typename A>
	void vector<T, A>::pop_back() {
		erase(--end());
	}

	template <typename T, typename A>
	typename vector<T, A>::iterator vector<T, A>::insert (iterator position, const value_type& val) {
		insert(position, 1, val);
		return position;
	}

	template <typename T, typename A>
    void vector<T, A>::insert (iterator position, size_type n, const value_type& val) {	
		size_type pos = ft::distance(begin(), position);
		size_type newSize = _size + n;
		if (newSize > _cap)
			reserve(newSize);
		if (_size)
		{
			// copy from end down to pos
			size_type times = _size - pos;
			for (size_type last = (_size - 1), i = 0; i < times; --last, i++)
			{
				_allocator.construct(_arr + last + n, *(_arr + last));
				_allocator.destroy(_arr + last);
			}
			//insert n vals
			for (size_type i = 0; i < n; ++i, ++pos)
				_allocator.construct(_arr + pos, val);
		} 
		else 
		{
			for (size_type i = 0; i < n; ++i)
				_allocator.construct(_arr + i, val);
		}	
		_size += n;	
	}

	template <typename T, typename A>
	template <class InputIterator>
    void vector<T, A>::insert(iterator position, InputIterator first, InputIterator last,
		typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type isIter) {
		
		size_type pos = ft::distance(begin(), position);
		size_type n = ft::distance(first, last);
		size_type newSize = _size + n;
		if (newSize > _cap)
			reserve(newSize * 1.5f);
		if (_size)
		{
			// copy from end down to pos
			size_type times = _size - pos;
			for (size_type last = (_size - 1), i = 0; i < times; --last, i++)
			{
				_allocator.construct(_arr + last + n, *(_arr + last));
				_allocator.destroy(_arr + last);
			}
			//insert n vals from *first up, starting at position
			for (size_type i = 0; first != last; ++i, ++first)
				_allocator.construct(_arr + pos + i, *first);
		} 
		else 
		{
			for (size_type i = 0; first != last; ++i, ++first)
				_allocator.construct(_arr + i, *first);
		}	
		_size += n;	
	}

	template <typename T, typename A>
	typename vector<T, A>::iterator vector<T, A>::erase (iterator position) {
		return erase(position, position + 1);
	}

	template <typename T, typename A>
	typename vector<T, A>::iterator vector<T, A>::erase (iterator first, iterator last) {
		iterator it;
		size_type times = ft::distance(first, last);

		for (it = first; it != last; ++it) 
		{
			_allocator.destroy(&*it); //SYNTAXE
		}

		if (last < end())
		{
			for (it = first; last != end(); ++it, ++last)
			{
				_allocator.construct(&*it, *last);	//SYNTAXE
				_allocator.destroy(&*last); //SYNTAXE
			}
		}
		_size -= times;
		return (first);
	}
	
	template <typename T, typename A>
	void vector<T, A>::swap (vector& x) {
		std::swap(_allocator, x._allocator);
		std::swap(_size, x._size);
		std::swap(_cap, x._cap);
		std::swap(_arr, x._arr);
	}

	template <typename T, typename A>
	void vector<T, A>::clear() {
		erase(begin(), end());
	}

};

#endif