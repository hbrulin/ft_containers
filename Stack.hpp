#ifndef STACK_HPP
# define STACK_HPP

# include "List.hpp"

namespace ft
{
	/*Heritage protected : 'stack' utilisera les méthodes de 'std::list' (public et protected) en interne 
	pour implémenter ses propres fonctions, c'est une sorte de spécialisation mais avec une 
	nouvelle interface - les ft de list ne seront pas accessibles dans un main via un stack*/
	template <typename T >
	class stack : protected list<T>
	{
		public:
			typedef T value_type;
			typedef list<T> container_type;
			typedef typename list<T>::size_type size_type;

		public:
			explicit stack (const container_type& ctnr = container_type());
			stack(stack const &other);
			stack &operator=(stack const &other);
			~stack();
			bool empty() const;
			size_type size() const;
			value_type& top();
			const value_type& top() const;
			void push (const value_type& val);
			void pop();

			friend bool operator==(const stack<T> &lhs, const stack<T> &rhs)
			{
				return lhs._c == rhs._c;
			}
			friend bool operator!=(const stack<T> &lhs, const stack<T> &rhs)
			{
				return lhs._c != rhs._c;
			}
			friend bool operator<(const stack<T> &lhs, const stack<T> &rhs)
			{
				return lhs._c < rhs._c;
			}
			friend bool operator<=(const stack<T> &lhs, const stack<T> &rhs)
			{
				return lhs._c <= rhs._c;
			}
			friend bool operator>(const stack<T> &lhs, const stack<T> &rhs)
			{
				return lhs._c > rhs._c;
			}
			friend bool operator>=(const stack<T> &lhs, const stack<T> &rhs)
			{
				return lhs._c >= rhs._c;
			}

		private:
			container_type _c;
	};

/* Non member functions */
/*
	template <typename T, typename Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._c == rhs._c;
	}

	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._c != rhs._c;
	}

	template <class T, class Container>
  	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._c < rhs._c;
	}

	template <class T, class Container>
  	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._c <= rhs._c;
	}

	template <class T, class Container>
 	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._c > rhs._c;
	}

	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return lhs._c >= rhs._c;
	}
*/
	/*Member functions */

	//pas besoin d'un appel explicite au constructeur de la liste?
	template <typename T>
	stack<T>::stack (const container_type& ctnr): _c(ctnr) {
	}

	//deep copy necessaire? ou appel au constructeur de la list?
	template <typename T>
	stack<T>::stack(stack const &other): _c(other._c) {
	}

	//deep copy necessaire?
	template <typename T>
	stack<T> &stack<T>::operator=(stack const &other) {
		_c = other._c;
		return *this;	
	}

	//appel destructeur list auto
	template <typename T>
	stack<T>::~stack() {
	}

	template <typename T>
	bool stack<T>::empty() const {
		return _c.empty();
	}

	template <typename T>
	typename stack<T>::size_type stack<T>::size() const {
		return _c.size();
	}

	template <typename T>
	typename stack<T>::value_type& stack<T>::top() {
		return _c.back();
	}

	template <typename T>
	const typename stack<T>::value_type& stack<T>::top() const {
		return _c.back();
	}

	template <typename T>
	void stack<T>::push (const value_type& val) {
		_c.push_back(val);
	}

	template <typename T>
	void stack<T>::pop() {
		_c.pop_back();
	}

}; //fin ft

#endif