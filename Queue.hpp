#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "List.hpp"

namespace ft
{

	template <typename T >
	class queue : protected list<T>
	{
		public:
			typedef T value_type;
			typedef list<T> container_type;
			typedef typename list<T>::size_type size_type;


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

			friend bool operator==(const queue<T> &lhs, const queue<T> &rhs)
			{
				return lhs._c == rhs._c;
			}
			friend bool operator!=(const queue<T> &lhs, const queue<T> &rhs)
			{
				return lhs._c != rhs._c;
			}
			friend bool operator<(const queue<T> &lhs, const queue<T> &rhs)
			{
				return lhs._c < rhs._c;
			}
			friend bool operator<=(const queue<T> &lhs, const queue<T> &rhs)
			{
				return lhs._c <= rhs._c;
			}
			friend bool operator>(const queue<T> &lhs, const queue<T> &rhs)
			{
				return lhs._c > rhs._c;
			}
			friend bool operator>=(const queue<T> &lhs, const queue<T> &rhs)
			{
				return lhs._c >= rhs._c;
			}

		private:
			container_type _c;

	};

/*Member functions*/
	template <typename T>
	queue<T>::queue (const container_type& ctnr): _c(ctnr){
	}

	template <typename T>
	queue<T>::queue(queue const &other) : _c(other._c) {
	}

	template <typename T>
	queue<T> &queue<T>::operator=(queue const &other) {
		_c = other._c;
		return *this;
	}

	template <typename T>
	queue<T>::~queue() {
	}

	template <typename T>
	bool queue<T>::empty() const {
		return _c.empty();
	}

	template <typename T>
	typename queue<T>::size_type queue<T>::size() const {
		return _c.size();
	}

	template <typename T>
	typename queue<T>::value_type& queue<T>::front() {
		return _c.front();
	}

	template <typename T>
	const typename queue<T>::value_type& queue<T>::front() const {
		return _c.front();
	}

	template <typename T>
	typename queue<T>::value_type& queue<T>::back() {
		return _c.back();
	}

	template <typename T>
	const typename queue<T>::value_type& queue<T>::back() const {
		return _c.back();
	}

	template <typename T>
	void queue<T>::push (const value_type& val) {
		_c.push_back(val);
	}

	template <typename T>
	void queue<T>::pop() {
		_c.pop_front();
	}

}; //fin namespace


#endif