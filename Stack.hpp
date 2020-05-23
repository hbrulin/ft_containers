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

	}

	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

	}

	template <class T, class Container>
  	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

	}

	template <class T, class Container>
  	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

	}

	template <class T, class Container>
 	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

	}

	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {

	  }

	/*Member functions */

	template <typename T, typename C>
	stack<T, C>::stack (const container_type& ctnr) {

	}

	template <typename T, typename C>
	bool stack<T, C>::empty() const {

	}

	template <typename T, typename C>
	typename stack<T, C>::size_type stack<T, C>::size() const {

	}

	template <typename T, typename C>
	typename stack<T, C>::value_type& stack<T, C>::top() {

	}

	template <typename T, typename C>
	const typename stack<T, C>::value_type& stack<T, C>::top() const {

	}

	template <typename T, typename C>
	void stack<T, C>::push (const value_type& val) {

	}

	template <typename T, typename C>
	void stack<T, C>::pop() {

	}


}; //fin ft

#endif