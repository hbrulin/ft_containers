#ifndef ITERATORS_HPP
# define ITERATORS_HPP

#include "List.hpp"

template <typename T>
class ListIter
{
private:
	ListIter();

protected:
	ListNode<T> *_p;

public:
	ListIter(ListNode<T> *p) : _p(p){};
	virtual ~ListBaseIter(){};
	bool operator==(const ListIter &other) const { return _p == other._p; };
	bool operator!=(const ListIter &other) const { return _p != other._p; };
	ListNode<T> *getP() const { return this->_p; };
};

#endif