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

		/*def iterators*/

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

	}

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	}

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {

	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		
	}


/*AJOUTER TYPENAM OU NECESSAIRE*/

	template <class T, class Alloc>
  	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {

	}

	template <typename T, typename A>
	list<T, A>::vector (const allocator_type& alloc = allocator_type()) {

	}		
	
	template <typename T, typename A>
	list<T, A>::vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {

	}

	template <typename T, typename A>
	template <class InputIterator>
	list<T, A>::vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {

	}
	
	template <typename T, typename A>
	list<T, A>::vector (const vector& x) {

	}
		
	template <typename T, typename A>
	list<T, A>::~vector() {

	}
			
	template <typename T, typename A>
	list<T, A>::vector& list<T, A>::operator= (const list<T, A>::vector& x) {

	}

	template <typename T, typename A>
	iterator list<T, A>::begin() {

	}
	
	template <typename T, typename A>
	const_iterator list<T, A>::begin() const {

	}

	template <typename T, typename A>
	iterator list<T, A>::end() {

	}

	template <typename T, typename A>
	const_iterator list<T, A>::end() const {

	}

	template <typename T, typename A>
	reverse_iterator list<T, A>::rbegin() {

	}

	template <typename T, typename A>
	const_reverse_iterator list<T, A>::rbegin() const {

	}

	template <typename T, typename A>
	reverse_iterator list<T, A>::rend() {

	}

	template <typename T, typename A>
	const_reverse_iterator list<T, A>::rend() const {

	}

	template <typename T, typename A>
	size_type list<T, A>::size() const {

	}

	template <typename T, typename A>
	size_type list<T, A>::max_size() const {

	}

	template <typename T, typename A>
	void list<T, A>::resize (size_type n, value_type val = value_type()) {

	}

	template <typename T, typename A>
	size_type list<T, A>::capacity() const {

	}

	template <typename T, typename A>
	bool list<T, A>::empty() const {

	}

	template <typename T, typename A>
	void list<T, A>::reserve (size_type n) {

	}

	template <typename T, typename A>
	reference list<T, A>::operator[] (size_type n) {

	}

	template <typename T, typename A>
	const_reference list<T, A>::operator[] (size_type n) const {

	}

	template <typename T, typename A>
	reference list<T, A>::at (size_type n) {

	}

	template <typename T, typename A>
	const_reference list<T, A>::at (size_type n) const {

	}

	template <typename T, typename A>
	reference list<T, A>::front() {

	}

	template <typename T, typename A>
	const_reference list<T, A>::front() const {

	}

	template <typename T, typename A>
	reference list<T, A>::back() {

	}

	template <typename T, typename A>
	const_reference list<T, A>::back() const {

	}

	template <typename T, typename A>
	template <class InputIterator>
  	void list<T, A>::assign (InputIterator first, InputIterator last) {

	}

	template <typename T, typename A>
	void list<T, A>::assign (size_type n, const value_type& val) {

	}

	template <typename T, typename A>
	void list<T, A>::push_back (const value_type& val) {

	}

	template <typename T, typename A>
	void list<T, A>::pop_back() {

	}

	template <typename T, typename A>
	iterator list<T, A>::insert (iterator position, const value_type& val) {

	}

	template <typename T, typename A>
    void list<T, A>::insert (iterator position, size_type n, const value_type& val) {

	}

	template <typename T, typename A>
	template <class InputIterator>
    void list<T, A>::insert (iterator position, InputIterator first, InputIterator last) {

	}

	template <typename T, typename A>
	iterator list<T, A>::erase (iterator position) {

	}

	template <typename T, typename A>
	iterator list<T, A>::erase (iterator first, iterator last) {

	}
	
	template <typename T, typename A>
	void list<T, A>::swap (vector& x) {

	}

	template <typename T, typename A>
	void list<T, A>::clear() {

	}

};

#endif