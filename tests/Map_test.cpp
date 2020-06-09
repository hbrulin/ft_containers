#include "../Map.hpp"
#include "../Pair.hpp"
#include "iostream"
#include <map>

#define PRINT(string) std::cout << (string) << std::endl;
#define ENDL() std::cout << std::endl;
#define PRINT_M(map) print_map(map);
#define PRINT_M_CONST(map) print_map_const(map);
#define	PRINT_REV(map) print_rev(map);
#define	PRINT_REV_CONST(map) print_rev_const(map);

template <class map>
void print_map(map m)
{
	typename map::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		std::cout << "[" << it->first << ", " << it->second << "]"
			<< " ";
	}
	ENDL()
}

template <class map>
void print_map_const(map m)
{
	typename map::const_iterator it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		std::cout << "[" << it->first << ", " << it->second << "]"
			<< " ";
	}
	ENDL()
}

template <class map>
void print_rev(map m)
{
	typename map::reverse_iterator it;
	for (it = m.rbegin(); it != m.rend(); ++it)
	{
		std::cout << "[" << it->first << ", " << it->second << "]"
				  << " ";
	}
	ENDL()
}

template <class map>
void print_rev_const(map m)
{
	typename map::const_reverse_iterator it;
	for (it = m.rbegin(); it != m.rend(); ++it)
	{
		std::cout << "[" << it->first << ", " << it->second << "]"
			<< " ";
	}
	ENDL()
}


int main(void)
{
	PRINT("### Testing constructors + assignments ###")
	std::map<int, char> real;
	ft::map<int, char> mine;
	PRINT_M(real)
	PRINT_M(mine)
	ENDL()

	std::pair<int, char> rp[] = {
		std::make_pair(1, 'a'),
		std::make_pair(2, 'b'),
		std::make_pair(3, 'c'),
		std::make_pair(4, 'd'),
		std::make_pair(5, 'e')};
	ft::pair<int, char> mp[] = {
		ft::make_pair(1, 'a'),
		ft::make_pair(2, 'b'),
		ft::make_pair(3, 'c'),
		ft::make_pair(4, 'd'),
		ft::make_pair(5, 'e')};

	PRINT("# Range constructor :as many elements as the range [first, last)")
	std::map<int, char> real2(rp, rp + 5);
	ft::map<int, char> mine2(mp, mp + 5);
	PRINT_M(real2)
	PRINT_M(mine2)
	ENDL()

	PRINT("# Copy constructor")
	std::map<int, char> real3(real2);
	ft::map<int, char> mine3(mine2);
	PRINT_M(real3)
	PRINT_M(mine3)
	ENDL()

	PRINT("# = operator ")
	std::map<int, char> real4 = real3;
	ft::map<int, char> mine4 = mine3;
	PRINT_M(real4)
	PRINT_M(mine4)

	ENDL()

	PRINT("### Testing const iterator ###")
	PRINT("STD CONST : ")
	PRINT_M_CONST(real4)
	PRINT("CUSTOM CONST: ")
	PRINT_M_CONST(mine4)
	ENDL()

	PRINT("### Testing rev iterator ###")
	PRINT("STD REV : ")
	PRINT_REV(real4)
	PRINT("CUSTOM REV: ")
	PRINT_REV(mine4)
	PRINT("STD REV CONST : ")
	PRINT_REV_CONST(real4)
	PRINT("CUSTOM REV CONST: ")
	PRINT_REV_CONST(mine4)
	ENDL()

	PRINT("### Capacity Tests ###")
	PRINT("CUSTOM EMPTY :")
	PRINT(mine.empty());
	PRINT(mine4.empty());
	PRINT("CUSTOM SIZE FUNCTIONS:")
	PRINT(mine4.size());
	PRINT(mine4.max_size());
	ENDL()

	PRINT("### Element access - operator[] - map[key] = val###")
	PRINT(real4[3])
	PRINT(mine4[3])
	ENDL()

	PRINT("### Element access - operator[] - new key ###")
	PRINT(real4[6])
	PRINT(mine4[6])
	PRINT(mine4.size());
	real4[6] = 'f';
	mine4[6] = 'f';
	PRINT_M(real4);
	PRINT_M(mine4);

	PRINT("### Inserting ###")

}