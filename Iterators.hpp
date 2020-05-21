#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include "List.hpp"
//#include "Vector.hpp"

namespace ft
{

	template <typename T>
	class Iter
	{
	private:
		Iter();

	protected:
		T *_p;

	public:
		Iter(T *p) : _p(p){};
		virtual ~Iter() {};
		bool operator==(const Iter &rhs) const { return _p == rhs._p; };
		bool operator!=(const Iter &rhs) const { return _p != rhs._p; };
		bool operator<(const Iter &rhs) const { return _p < rhs._p; };
		bool operator>(const Iter &rhs) const { return _p > rhs._p; };
		bool operator<=(const Iter &rhs) const { return _p <= rhs._p; };
		bool operator>=(const Iter &rhs) const { return _p >= rhs._p; };
		T* getP() const { return this->_p; };
	};

	template <typename T>
	struct ListNode {
		/*Constructor for structure */
		ListNode(ListNode<T> *prv, ListNode<T> *nxt, const T &element) : prv(prv), nxt(nxt),
			element(element) {}
		ListNode<T> *prv;
		ListNode<T> *nxt;
		T element;
	};

	template <typename T>
	class ListIter
	{
	private:
		ListIter();

	protected:
		ListNode<T> *_p;

	public:
		ListIter(ListNode<T> *p) : _p(p){};
		virtual ~ListIter(){};
		bool operator==(const ListIter &other) const { return _p == other._p; };
		bool operator!=(const ListIter &other) const { return _p != other._p; };
		ListNode<T> *getP() const { return this->_p; };
	};


	template <typename Iter>
	class ReverseIter
	{
	private:
		ReverseIter();

	protected:
		Iter _base;

	public:
		ReverseIter(Iter base) : _base(base){};
		virtual ~ReverseIter(){};
		bool operator==(const ReverseIter &rhs) const { return _base == rhs._base; };
		bool operator!=(const ReverseIter &rhs) const { return _base != rhs._base; };
		bool operator<(const ReverseIter &rhs) const { return _base > rhs._base; };
		bool operator>(const ReverseIter &rhs) const { return _base < rhs._base; };
		bool operator<=(const ReverseIter &rhs) const { return _base >= rhs._base; };
		bool operator>=(const ReverseIter &rhs) const { return _base <= rhs._base; };
		Iter getB() const { return this->_base; };
	};

	template <typename Iter>
	class ReverseIterator : public ReverseIter<Iter>
	{
	public:
		typedef ReverseIterator<Iter> reverse_iterator;
		typedef Iter iterator_type;
		typedef typename Iter::iterator_category iterator_category;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;

		ReverseIterator() : ReverseIter<Iter>(NULL){};
		explicit ReverseIterator(iterator_type base) : ReverseIter<Iter>(base){};
		ReverseIterator(const reverse_iterator &other) : ReverseIter<Iter>(other._base){};
		reverse_iterator &operator=(const reverse_iterator &other) { this->_base = other._base; return (*this); };
		virtual ~ReverseIterator(){};
		iterator_type base() const { return (this->_base); };
		value_type &operator*() const { Iter it(this->_base); --it; return *(it); };
		reverse_iterator operator+(difference_type n) const { return reverse_iterator(this->_base - n); };
		reverse_iterator &operator++() { --this->_base; return *this; }; // ++it
		reverse_iterator operator++(int) { reverse_iterator it = *this; --this->_base; return it; }; // it++
		reverse_iterator &operator+=(difference_type n) { this->_base -= n; return (*this); };
		reverse_iterator operator-(difference_type n) const { return reverse_iterator(this->_base + n); };
		reverse_iterator &operator--() { ++this->_base; return *this; }; // --it
		reverse_iterator operator--(int) { reverse_iterator it = *this; ++this->_base; return it; }; // it--
		reverse_iterator &operator-=(difference_type n) { this->_base += n; return (*this); };
		difference_type operator-(const ReverseIter<Iter> &rhs) { return rhs.getB() - this->base(); };
		pointer operator->() const { return &(this->operator*()); };
		reference operator[](difference_type n) const { Iter it(this->_base - n); --it; return *(it); };
	};

	template <typename Iter>
	class ConstReverseIterator : public ReverseIter<Iter>
	{
	public:
		typedef ReverseIterator<Iter> reverse_iterator;
		typedef ConstReverseIterator<Iter> const_reverse_iterator;
		typedef Iter iterator_type;
		typedef typename Iter::iterator_category iterator_category;
		typedef typename Iter::value_type value_type;
		typedef typename Iter::difference_type difference_type;
		typedef typename Iter::pointer pointer;
		typedef typename Iter::reference reference;

		ConstReverseIterator() : ReverseIter<Iter>(NULL){};
		ConstReverseIterator(const iterator_type base) : ReverseIter<Iter>(base){};
		ConstReverseIterator(const const_reverse_iterator &other) : ReverseIter<Iter>(other._base){};
		virtual ~ConstReverseIterator(){};

		const_reverse_iterator &operator=(const const_reverse_iterator &other) { this->_base = other._base; return (*this); };
		iterator_type base() const { return (this->_base); };
		const value_type &operator*() const { Iter it(this->_base); --it; return *(it); };
		const_reverse_iterator operator+(difference_type n) const { return const_reverse_iterator(this->_base - n); };
		const_reverse_iterator &operator++() { --this->_base; return *this; }; // ++it
		const_reverse_iterator operator++(int) { const_reverse_iterator it = *this; --this->_base; return it; }; // it++
		const_reverse_iterator &operator+=(difference_type n) { this->_base -= n; return (*this); };
		const_reverse_iterator operator-(difference_type n) const { return const_reverse_iterator(this->_base + n); };
		const_reverse_iterator &operator--() { ++this->_base; return *this; }; // --it
		const_reverse_iterator operator--(int) { const_reverse_iterator it = *this; ++this->_base; return it; }; // it--
		const_reverse_iterator &operator-=(difference_type n) { this->_base += n; return (*this); };
		difference_type operator-(const ReverseIter<Iter> &rhs) { return rhs.getB() - this->base(); };
		const value_type *operator->() const { return &(this->operator*()); };
		const value_type &operator[](difference_type n) const { Iter it(this->_base - n); --it; return *(it); };
	};
	template <typename Iter>
	ReverseIterator<Iter> operator+(typename ReverseIterator<Iter>::difference_type n, const ReverseIterator<Iter> &rev_it)
	{
		return rev_it + n;
	};

	template <typename Iter>
	ConstReverseIterator<Iter> operator+(typename ConstReverseIterator<Iter>::difference_type n, const ConstReverseIterator<Iter> &rev_it)
	{
		return rev_it + n;
	};


}; //end namespace

#endif