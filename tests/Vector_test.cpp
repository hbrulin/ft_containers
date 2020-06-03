#include "../Vector.hpp"
#include "iostream"

#define PRINT(string) std::cout << (string) << std::endl;
#define ENDL() std::cout << std::endl;
#define PRINT_V(list) print_vec(list);
#define PRINT_V_CONST(list) print_vec_const(list);
#define	PRINT_REV(list) print_rev(list);
#define	PRINT_REV_CONST(list) print_rev_const(list);

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
void print_vec_const(vec v)
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
////
	ENDL()

	PRINT("### Testing const iterator ###")
	
	ENDL()

	PRINT("### Testing rev iterator ###")

	ENDL()

	PRINT("### Capacity Tests ###")
///
	ENDL()

	PRINT("### Element access ###" << std::endl;
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