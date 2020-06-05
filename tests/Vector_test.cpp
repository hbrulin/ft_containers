#include "../Vector.hpp"
#include "iostream"
#include <vector>

#define PRINT(string) std::cout << (string) << std::endl;
#define ENDL() std::cout << std::endl;
#define PRINT_V(vector) print_vec(vector);
#define PRINT_V_CONST(vector) print_vec_const(vector);
#define	PRINT_REV(vector) print_rev(vector);
#define	PRINT_REV_CONST(vector) print_rev_const(vector);

template <class vector>
void print_vec(vector v)
{
	typename vector::iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	ENDL()
}

template <class vector>
void print_vec_const(vector v)
{
	typename vector::const_iterator it;
	for (it = v.begin(); it != v.end(); ++it)
	{
		std::cout << *it << " ";
	}
	ENDL()
}

template <class vector>
void print_rev(vector v)
{
	typename vector::reverse_iterator it;
	for (it = v.rbegin(); it != v.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	ENDL()
}

template <class vector>
void print_rev_const(vector v)
{
	typename vector::const_reverse_iterator it;
	for (it = v.rbegin(); it != v.rend(); ++it)
	{
		std::cout << *it << " ";
	}
	ENDL()
}

int main(void)
{
	PRINT("### Testing constructors + assignments ###")
	std::vector<int> real;
	ft::vector<int> mine;
	PRINT_V(real);
	PRINT_V(mine);

	PRINT("# Fill constructor : constructs with n element, each a copy of val")
	std::vector<int> real2(3);
	ft::vector<int> mine2(3);
	PRINT("STD : ")
	PRINT_V(real2)
	PRINT("CUSTOM : ")
	PRINT_V(mine2)

	PRINT("# Fill constructor : val is defined")
	std::vector<int> real3(3, 50);
	ft::vector<int> mine3(3, 50);
	PRINT("STD : ")
	PRINT_V(real3)
	PRINT("CUSTOM : ")
	PRINT_V(mine3)

	PRINT("# Range constructor :as many elements as the range [first, last)")
	std::vector<int> real4(real3.begin(), real3.end());
	ft::vector<int> mine4(mine3.begin(), mine3.end());
	PRINT("STD : ")
	PRINT_V(real4)
	PRINT("CUSTOM : ")
	PRINT_V(mine4)

	PRINT("# Range constructor array")
	int array[] = {1, 2, 3, 4, 5};
	std::vector<int> real5(array, array + 5);
	ft::vector<int> mine5(array, array + 5);
	PRINT("STD : ")
	PRINT_V(real5)
	PRINT("CUSTOM : ")
	PRINT_V(mine5)

	PRINT("# Copy constructor")
	std::vector<int> real6(real5);
	std::vector<int> mine6(real5);
	PRINT("STD : ")
	PRINT_V(real6)
	PRINT("CUSTOM : ")
	PRINT_V(mine6)

	PRINT("# = Operator")
	std::vector<int> real7 = real5;
	ft::vector<int> mine7 = mine5;
	PRINT("STD : ")
	PRINT_V(real7)
	PRINT("CUSTOM : ")
	PRINT_V(mine7)

	ENDL()

	PRINT("### Testing const iterator ###")
	PRINT("STD CONST : ")
	PRINT_V_CONST(real5)
	PRINT("CUSTOM CONST: ")
	PRINT_V_CONST(mine5)
	ENDL()

	PRINT("### Testing rev iterator ###")
	PRINT("STD REV : ")
	PRINT_REV(real5)
	PRINT("CUSTOM REV: ")
	PRINT_REV(mine5)
	PRINT("STD REV CONST : ")
	PRINT_REV_CONST(real5)
	PRINT("CUSTOM REV CONST: ")
	PRINT_REV_CONST(mine5)
	ENDL()

	PRINT("### Capacity Tests ###")
	PRINT("CUSTOM SIZE FUNCTIONS: \n")
	PRINT(mine5.size());
	PRINT(mine5.max_size());
	PRINT(mine5.capacity());
	ENDL();

	PRINT("CUSTOM RESIZE : \n")
	mine5.resize(3);
	PRINT_V(mine5)
	mine5.resize(5);
	PRINT_V(mine5)
	mine5.resize(7, 10);
	PRINT_V(mine5)
	ENDL();

	PRINT("CUSTOM RESERVE : \n")
	PRINT(mine5.capacity())
	mine5.reserve(2);
	PRINT(mine5.capacity())
	mine5.reserve(20);
	PRINT(mine5.capacity())
	ENDL();

	PRINT("CUSTOM EMPTY : \n")
	PRINT(mine.empty())
	PRINT(mine5.empty())
	ENDL()

	PRINT("### Element access - operator[] ###")
	std::vector<int> standard(array, array + 5);
	ft::vector<int> custom(array, array + 5);

	PRINT(standard[3])
	PRINT(custom[3])
	ENDL()

	PRINT("### Element access - at() ###")
	PRINT(standard.at(3))
	PRINT(custom.at(3))
	ENDL()

	PRINT("### at exception ###")
	try
	{
		standard.at(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		custom.at(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	PRINT("### Element access - front & back ###")
	PRINT(standard.front())
	PRINT(custom.front())

	PRINT(standard.back())
	PRINT(custom.back())
	ENDL()

	PRINT("### Modifiers - Assign ###")
	std::vector<int> std2(10, 8);
	ft::vector<int> cus2(10, 8);
	std2.assign(array, array +5);
	cus2.assign(array, array + 5);
	PRINT("STD ASSIGN ITERATORS : ")
	PRINT_V(std2)
	PRINT("CUSTOM ASSIGN ITERATORS : ")
	PRINT_V(cus2)
	ENDL()

	std2.assign(10, 10);
	cus2.assign(10, 10);
	PRINT("STD ASSIGN n values : ")
	PRINT_V(std2)
	PRINT("CUSTOM ASSIGN n values : ")
	PRINT_V(cus2)
	ENDL()

	PRINT("### Modifiers - Push & pop back ###")
	standard.push_back(3);
	custom.push_back(3);
	PRINT("STD Push back 3: ")
	PRINT_V(standard)
	PRINT("CUSTOM Push back 3: ")
	PRINT_V(custom)
	ENDL()

	standard.pop_back();
	custom.pop_back();
	PRINT("STD Pop Back : ")
	PRINT_V(standard)
	PRINT("CUSTOM Pop Back : ")
	PRINT_V(custom)
	ENDL();

	PRINT("### Modifiers - Insert ###")
	std::vector<int>::iterator its;
	its = standard.begin();
	ft::vector<int>::iterator itc;
	itc = custom.begin();
	for (size_t i = 0; i < 2; i++)
	{
		its++;
		itc++;
	}
	standard.insert(its, 5);
	custom.insert(itc, 5);
	PRINT("STD Insert val 5 at position 2 : ")
	PRINT_V(standard)
	PRINT("CUSTOM Insert val 5 at position 2 : ")
	PRINT_V(custom)
	ENDL();

	standard.insert(its, 3, 5);
	custom.insert(itc, 3, 5);
	PRINT("STD Insert 3 times val 5 : ")
	PRINT_V(standard)
	PRINT("CUSTOM Insert 3 times val 5 : ")
	PRINT_V(custom)
	ENDL();

	PRINT("### Range insert : ###")
	std::vector<int> std3(array, array + 5);
	ft::vector<int> cus3(array, array + 5);
	std::vector<int>::iterator its3;
	its3 = std3.begin();
	ft::vector<int>::iterator itc3;
	itc3 = cus3.begin();
	for (size_t i = 0; i < 2; i++)
	{
		its3++;
		itc3++;
	}
	std3.insert(its3, array, array + 5);
	cus3.insert(itc3, array, array + 5);
	PRINT("STD Insert range : ")
	PRINT_V(std3)
	PRINT("CUSTOM Insert range : ")
	PRINT_V(cus3)
	ENDL();

	PRINT("### Modifiers - Erase ###")
	its3 = std3.begin();
	itc3 = cus3.begin();
	std3.erase(its3);
	cus3.erase(itc3);
	PRINT("STD Erase position : ")
	PRINT_V(std3)
	PRINT("CUSTOM Erase position : ")
	PRINT_V(cus3)
	ENDL();

	its3 = std3.begin();
	itc3 = cus3.begin();
	for (size_t i = 0; i < 5; i++)
	{
		its3++;
		itc3++;
	}
	std3.erase(std3.begin(), its3);
	cus3.erase(cus3.begin(), itc3);
	PRINT("STD Erase range : ")
	PRINT_V(std3)
	PRINT("CUSTOM Erase range: ")
	PRINT_V(cus3)
	ENDL();

	PRINT("### Modifiers - Swap ###")
	std3.swap(real4);
	cus3.swap(mine4);
	PRINT("STD 1st list : ")
	PRINT_V(std3)
	PRINT("Custom 1st list : ")
	PRINT_V(cus3)
	PRINT("STD 2nd list : ")
	PRINT_V(real4)
	PRINT("CUSTOM 2nd list : ")
	PRINT_V(mine4)
	ENDL();

	PRINT("### Modifiers - Clear ###")
	std3.clear();
	cus3.clear();
	PRINT("STD clear : ")
	PRINT_V(std3)
	PRINT("CUSTOM clear: ")
	PRINT_V(cus3)
	ENDL()


	PRINT("### relational operators ###")
	int array2[] = {1, 2, 3, 4, 5, 6};
	standard.assign(array, array + 5);
	std2.assign(array2, array2 + 6);
	custom.assign(array, array + 5);
	cus2.assign(array2, array2 + 6);

	PRINT(standard == std2)
	PRINT(custom == cus2)
	PRINT(standard != std2)
	PRINT(custom != cus2)
	PRINT(standard > std2)
	PRINT(custom > cus2)
	PRINT(standard >= std2)
	PRINT(custom >= cus2)
	PRINT(standard < std2)
	PRINT(custom < cus2)
	PRINT(standard <= std2)
	PRINT(custom <= cus2)
	ENDL()

	PRINT("Swap")
	std::swap(standard, std2);
	ft::swap(custom, cus2);
	PRINT_V(standard)
	PRINT_V(custom)
	PRINT_V(std2)
	PRINT_V(cus2)

}