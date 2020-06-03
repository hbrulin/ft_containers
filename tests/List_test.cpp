#include "../List.hpp"
#include "iostream"
#include <list>

#define PRINT(value) std::cout << (value) << std::endl;
#define ENDL() std::cout << std::endl;
#define PRINT_L(list) print_list(list);
#define PRINT_L_CONST(list) print_list_const(list);
#define	PRINT_REV(list) print_rev(list);
#define	PRINT_REV_CONST(list) print_rev_const(list);

template <class list>
void print_list(list l)
{
	typename list::iterator it;
	for (it = l.begin(); it != l.end(); ++it)
	{
		std::cout << *it << " ";
	}
	ENDL()
}

template <class list>
void print_list_const(list l)
{
	typename list::const_iterator it;
	for (it = l.begin(); it != l.end(); ++it)
	{
		std::cout << *it << " ";
	}
	ENDL()
}

template <class list>
void print_rev(list l)
{
	typename list::reverse_iterator it;
	for (it = l.rbegin(); it != l.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	ENDL()
}

template <class list>
void print_rev_const(list l)
{
	typename list::const_reverse_iterator it;
	for (it = l.rbegin(); it != l.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	ENDL()
}

int main(void)
{
	PRINT("### Testing 4 constructors + = Operator ###")

	PRINT("Constructor list()")
	std::list<int> real;
	ft::list<int> mine;
	PRINT_L(real)
	PRINT_L(mine)

	PRINT("Fill constructor : constructs with n element, each a copy of val")
	std::list<int> real2(3);
	ft::list<int> mine2(3);
	PRINT_L(real2)
	PRINT_L(mine2)

	PRINT("Fill constructor : val is defined")
	std::list<int> real3(3, 50);
	ft::list<double> mine3(3, 50.6);
	PRINT_L(real3)
	PRINT_L(mine3)

	PRINT("Range constructor :as many elements as the range [first, last)")
	std::list<int> real4(real3.begin(), real3.end());
	ft::list<int> mine4(mine3.begin(), mine3.end());
	PRINT_L(real4)
	PRINT_L(mine4)

	PRINT("Range constructor array")
	int array[] = {1, 2, 3, 4, 5};
	std::list<int> real5(array, array + 5);
	ft::list<int> mine5(array, array + 5);
	PRINT_L(real5)
	PRINT_L(mine5)

	PRINT("Copy constructor")
	std::list<int> real6(real5);
	std::list<int> mine6(real5);
	PRINT_L(real6)
	PRINT_L(mine6)

	PRINT("= Operator")
	std::list<int> real7 = real5;
	ft::list<int> mine7 = mine5;
	PRINT_L(real7)
	PRINT_L(mine7)

	ENDL()

	PRINT("### Testing const iterator ###")
	PRINT_L_CONST(real5)
	PRINT_L_CONST(mine5)

	ENDL()

	PRINT("### Testing rev iterator ###")
	PRINT_REV(real5)
	PRINT_REV(mine5)
	PRINT_REV_CONST(real5)
	PRINT_REV_CONST(mine5)

	ENDL()

	PRINT("### Capacity Tests ###")
	PRINT(mine.empty());
	PRINT(mine5.empty());
	PRINT(mine5.size());
	PRINT(mine5.max_size());
	ENDL()

	PRINT("### Element access ###")
	PRINT(real5.front());
	PRINT(real5.back());
	PRINT(mine5.front());
	PRINT(mine5.back());
	ENDL()

	PRINT("### Modifiers - Assign ###")
	std::list<int> standard(10, 8);
	ft::list<int> custom(10, 8);
	standard.assign(array, array +5);
	custom.assign(array, array + 5);
	PRINT_L(standard)
	PRINT_L(custom)
	standard.assign(10, 10);
	custom.assign(10, 10);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	PRINT("### Modifiers - Push & pop ###")
	standard.push_front(3);
	custom.push_front(3);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	standard.pop_front();
	custom.pop_front();
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	standard.push_back(3);
	custom.push_back(3);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	standard.pop_back();
	custom.pop_back();
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL();

	PRINT("### Modifiers - Inserts ###")
	std::list<int>::iterator its;
	its = standard.begin();
	ft::list<int>::iterator itc;
	itc = custom.begin();
	for (size_t i = 0; i < 5; i++)
	{
		its++;
		itc++;
	}
	standard.insert(its, 5);
	custom.insert(itc, 5);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL();

	standard.insert(its, 3, 5);
	custom.insert(itc, 3, 5);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL();

	standard.insert(its, array, array + 5);
	custom.insert(itc, array, array + 5);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL();

	PRINT("### Modifiers - Erase ###")
	standard.erase(its);
	custom.erase(itc);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL();

	its = standard.begin();
	itc = custom.begin();
	for (size_t i = 0; i < 5; i++)
	{
		its++;
		itc++;
	}
	standard.erase(standard.begin(), its);
	custom.erase(custom.begin(), itc);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL();

	PRINT("### Modifiers - Swap ###")
	standard.swap(real5);
	custom.swap(mine5);
	PRINT_L(standard)
	PRINT_L(custom)
	PRINT_L(real5)
	PRINT_L(mine5)
	ENDL();

	PRINT("### Modifiers - Resize ###")
	standard.resize(2);
	custom.resize(2);
	PRINT_L(standard)
	PRINT_L(custom)
	standard.resize(10);
	custom.resize(10);
	PRINT_L(standard)
	PRINT_L(custom)

	PRINT("### Modifiers - Clear ###")
	standard.clear();
	custom.clear();
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	PRINT("### Operations ###")
///
	ENDL()

	PRINT("### Non-member functions ###")
///
	ENDL()

}