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

	PRINT("CUSTOM RESIZE : \n")
	mine5.resize(3);
	PRINT_V(mine5);
	mine5.resize(5);
	PRINT_V(mine5);
	mine5.resize(7, 10);
	PRINT_V(mine5);

	PRINT("CUSTOM RESERVE : \n")
	PRINT(mine5.capacity());
	mine5.reserve(2);
	PRINT(mine5.capacity());
	mine5.reserve(20);
	PRINT(mine5.capacity());

	PRINT("CUSTOM EMPTY : \n")
	PRINT(mine.empty());
	PRINT(mine5.empty());
	ENDL()

	PRINT("### Element access ###")
///
	ENDL()

	PRINT("### Modifiers ###")
///
	ENDL()

	PRINT("### Operations ###")
///
	ENDL()

	PRINT("### Non-member functions ###")
///
	ENDL()

}