#include "../Queue.hpp"
#include "iostream"
#include <queue>
#include <list>
#include <deque>
#include "../List.hpp"

#define PRINT(value) std::cout << (value) << std::endl;
#define ENDL() std::cout << std::endl;
#define PRINT_S(queue) print_stack(queue);

template <class queue>
void print_stack(queue q)
{
	for (size_t i = 0; i < q.size(); i++)
	{
		typename queue::value_type tmp = q.front();
		std::cout << tmp << " ";
		q.pop(); //remove oldest element
		q.push(tmp); //reinsert at end
	}
	ENDL()
}

int main(void)
{
	PRINT("### Testing constructor ###")
	std::queue<int> empt;
	ft::queue<int> empttt;
	PRINT_S(empt)
	PRINT_S(empttt)
	ENDL()

	PRINT("### Testing constructor with container type ###")
	int array[] = {1, 2, 3, 4, 5};
	std::deque<int> base_std(array, array + 5);
	ft::list<int> base(array, array + 5);
	std::queue<int> standard(base_std);
	ft::queue<int> custom(base);
	PRINT_S(standard)
	PRINT_S(custom)
	ENDL()

	PRINT("### Testing copy constructor & =operator ###")
	std::queue<int> std2(standard);
	ft::queue<int> cus2(custom);
	PRINT_S(std2)
	PRINT_S(cus2)
	ENDL()

	std::queue<int> std3 = standard;
	ft::queue<int> cus3 = custom;
	PRINT_S(std3)
	PRINT_S(cus3)
	ENDL()

	PRINT("### Testing member functions ###")

	PRINT(empttt.empty())
	PRINT(cus3.empty())
	PRINT(cus3.front())
	PRINT(cus3.back())

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