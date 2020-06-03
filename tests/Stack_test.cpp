#include "../Stack.hpp"
#include "iostream"
#include <stack>
#include <list>
#include <deque>
#include "../List.hpp"

#define PRINT(value) std::cout << (value) << std::endl;
#define ENDL() std::cout << std::endl;
#define PRINT_S(stack) print_stack(stack);

template <class stack>
void print_stack(stack s)
{
	stack save;
	size_t size = s.size();

	for (size_t i = 0; i < size; i++)
	{
		typename stack::value_type tmp = s.top();
		std::cout << tmp << " ";
		s.pop(); // I have to remove top to get to next element
		save.push(tmp); //I save it
	}
	//Then copy elements back in s
	for (size_t i = 0; i < size; i++)
	{
		typename stack::value_type tmp = save.top();
		s.push(tmp);
	}
	ENDL()
}

int main(void)
{
	PRINT("### Testing constructor ###")
	std::stack<int> empt;
	ft::stack<int> empttt;
	PRINT_S(empt)
	PRINT_S(empttt)
	ENDL()

	PRINT("### Testing constructor with container type ###")
	int array[] = {1, 2, 3, 4, 5};
	std::deque<int> base_std(array, array + 5);
	ft::list<int> base(array, array + 5);
	std::stack<int> standard(base_std);
	ft::stack<int> custom(base);
	PRINT_S(standard)
	PRINT_S(custom)
	ENDL()

	PRINT("### Testing copy constructor & =operator ###")
	std::stack<int> std2(standard);
	ft::stack<int> cus2(custom);
	PRINT_S(std2)
	PRINT_S(cus2)
	ENDL()

	std::stack<int> std3 = standard;
	ft::stack<int> cus3 = custom;
	PRINT_S(std3)
	PRINT_S(cus3)
	ENDL()

	PRINT("### Testing member functions ###")

	PRINT(empttt.empty())
	PRINT(cus3.empty())
	PRINT(cus3.size())
	PRINT(cus3.top())

	ENDL()

	cus3.push(10);
	PRINT_S(cus3)
	cus3.pop();
	PRINT_S(cus3)

	ENDL()

	PRINT("### Relational operators ###")
	cus3.pop();
	std3.pop();
	PRINT(std2 == std3)
	PRINT(cus2 == cus3)
	PRINT(std2 != std3)
	PRINT(cus2 != cus3)
	PRINT(std2 > std3)
	PRINT(cus2 > cus3)
	PRINT(std2 >= std3)
	PRINT(cus2 >= cus3)
	PRINT(std2 < std3)
	PRINT(cus2 < cus3)
	PRINT(std2 <= std3)
	PRINT(cus2 <= cus3)

	ENDL()

	return 0;

}