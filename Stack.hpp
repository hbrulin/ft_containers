#ifndef STACK_HPP
# define STACK_HPP

# include "List.hpp"

namespace ft
{
	/*Heritage protected : 'stack' utilisera les méthodes de 'std::list' (public et protected) en interne 
	pour implémenter ses propres fonctions, c'est une sorte de spécialisation mais avec une 
	nouvelle interface - les ft de list ne seront pas accessibles dans un main via un stack*/
	template <typename T, typename Container = list<T> >
	class stack : protected list<T>
	{
		public:
			typedef T value_type;
			typedef list<T> container_type;
			typedef typename list<T>::size_type size_type;

		private:
			container_type _c;

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

	};

/* Non member functions */

	template <class T, class Container>
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

	/*Member functions */

	//pas besoin d'un appel explicite au constructeur de la liste?
	template <typename T, typename C>
	stack<T, C>::stack (const container_type& ctnr): _c(ctnr) {
	}

	//deep copy necessaire? ou appel au constructeur de la list?
	template <typename T, typename C>
	stack<T, C>::stack(stack const &other): _c(other._c) {
	}

	//deep copy necessaire?
	template <typename T, typename C>
	stack<T, C> &stack<T, C>::operator=(stack const &other) {
		_c = other._c;
		return *this;	
	}

	//appel destructeur list auto
	template <typename T, typename C>
	stack<T, C>::~stack() {
	}

	template <typename T, typename C>
	bool stack<T, C>::empty() const {
		return _c.empty();
	}

	template <typename T, typename C>
	typename stack<T, C>::size_type stack<T, C>::size() const {
		return _c.size();
	}

	template <typename T, typename C>
	typename stack<T, C>::value_type& stack<T, C>::top() {
		return _c.back();
	}

	template <typename T, typename C>
	const typename stack<T, C>::value_type& stack<T, C>::top() const {
		return _c.back();
	}

	template <typename T, typename C>
	void stack<T, C>::push (const value_type& val) {
		_c.push_back(val);
	}

	template <typename T, typename C>
	void stack<T, C>::pop() {
		_c.pop_back();
	}

}; //fin ft

#endif