#ifndef LIST_HPP
# define LIST_HPP

#include <memory>

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
		
		//TYPEDEF ITERATORS MISSING

	private:
		allocator_type _allocator; //default to allocator value_type
		ListNode<T> *_li;
		size_type _size;

	public:
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
	insert(begin(), n, val); //implement BOTH
}

template <typename T, typename A>
template <class InputIterator>
list<T, A>::list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) 
{
	_li = new ListNode<T>(NULL, NULL, value_type());
	insert(begin(), first, last); //a different insert overload
}

template <typename T, typename A>
list<T, A>::list(const list &x) : _allocator(other._allocator), _size(0)
{
	_li = new ListNode<T>(NULL, NULL, value_type());
	insert(begin(), x.begin(), x.end()); //OTHER OVERLOAD OF INSERT
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

}

template <typename T, typename A>
typename list<T, A>::const_iterator list<T, A>::begin() const {

}

template <typename T, typename A>
typename list<T, A>::iterator list<T, A>::end() {

}
template <typename T, typename A>
typename list<T, A>::const_iterator list<T, A>::end() const {

}

template <typename T, typename A>
typename list<T, A>::reverse_iterator list<T, A>::rbegin() {

}

template <typename T, typename A>
typename list<T, A>::const_reverse_iterator list<T, A>::rbegin() const {

}

template <typename T, typename A>
typename list<T, A>::reverse_iterator list<T, A>::rend() {

}

template <typename T, typename A>
typename list<T, A>::const_reverse_iterator list<T, A>::rend() const {
	
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

}

template <typename T, typename A>
typename list<T, A>::const_reference list<T, A>::front() const {

}

template <typename T, typename A>
typename list<T, A>::reference list<T, A>::back() {
	//implement
}

template <typename T, typename A>
typename list<T, A>::const_reference list<T, A>::back() const {
	//implement
}


#endif