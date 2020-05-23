#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "List.hpp"

namespace ft
{

	template <typename T, typename Container = list<T> >
	class queue : protected list<T>
	{
		public:
			typedef T value_type;
			typedef list<T> container_type;
			typedef typename list<T>::size_type size_type;

		private:
			container_type _c;

		public:
			explicit queue (const container_type& ctnr = container_type());
			queue(queue const &other);
			queue &operator=(queue const &other);
			~queue();
			bool empty() const;
			size_type size() const;
			value_type& front();
			const value_type& front() const;
			value_type& back();
			const value_type& back() const;
			void push (const value_type& val);
			void pop();

	};

	/*Non member functions */

	template <class T, class Container>
  	bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		  return lhs._c == rhs._c;
	}

	template <class T, class Container>
  	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._c != rhs._c;
	}

	template <class T, class Container>
  	bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._c < rhs._c;
	}

	template <class T, class Container>
  	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._c <= rhs._c;
	}

	template <class T, class Container>
  	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._c > rhs._c;
	}

	template <class T, class Container>
  	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {
		return lhs._c >= rhs._c;
	}

/*Member functions*/
	template <typename T, typename C>
	queue<T, C>::queue (const container_type& ctnr): _c(ctnr){
	}

	template <typename T, typename C>
	queue<T, C>::queue(queue const &other) : _c(other._c) {
	}

	template <typename T, typename C>
	queue<T, C> &queue<T, C>::operator=(queue const &other) {
		_c = other._c;
		return *this;
	}

	template <typename T, typename C>
	queue<T, C>::~queue() {
	}

	template <typename T, typename C>
	bool queue<T, C>::empty() const {
		return _c.empty();
	}

	template <typename T, typename C>
	typename queue<T, C>::size_type queue<T, C>::size() const {
		return _c.size();
	}

	template <typename T, typename C>
	typename queue<T, C>::value_type& queue<T, C>::front() {
		return _c.front();
	}

	template <typename T, typename C>
	const typename queue<T, C>::value_type& queue<T, C>::front() const {
		return _c.front();
	}

	template <typename T, typename C>
	typename queue<T, C>::value_type& queue<T, C>::back() {
		return _c.back();
	}

	template <typename T, typename C>
	const typename queue<T, C>::value_type& queue<T, C>::back() const {
		return _c.back();
	}

	template <typename T, typename C>
	void queue<T, C>::push (const value_type& val) {
		_c.push_back(val);
	}

	template <typename T, typename C>
	void queue<T, C>::pop() {
		_c.pop_front();
	}

}; //fin namespace


#endif