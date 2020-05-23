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

	}

	template <class T, class Container>
  	bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {

	}

	template <class T, class Container>
  	bool operator<  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {

	}

	template <class T, class Container>
  	bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {

	}

	template <class T, class Container>
  	bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {

	}

	template <class T, class Container>
  	bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs) {

	}

/*Member functions*/
	template <typename T, typename C>
	queue<T, C>::queue (const container_type& ctnr) {

	}

	template <typename T, typename C>
	bool queue<T, C>::empty() const {

	}

	template <typename T, typename C>
	typename queue<T, C>::size_type queue<T, C>::size() const {

	}

	template <typename T, typename C>
	typename queue<T, C>::value_type& queue<T, C>::front() {

	}

	template <typename T, typename C>
	const typename queue<T, C>::value_type& queue<T, C>::front() const {

	}

	template <typename T, typename C>
	typename queue<T, C>::value_type& queue<T, C>::back() {

	}

	template <typename T, typename C>
	const typename queue<T, C>::value_type& queue<T, C>::back() const {

	}

	template <typename T, typename C>
	void queue<T, C>::push (const value_type& val) {

	}

	template <typename T, typename C>
	void queue<T, C>::pop() {

	}

}; //fin namespace


#endif