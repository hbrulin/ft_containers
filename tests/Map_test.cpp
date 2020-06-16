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
	ENDL()

	PRINT("### Inserting one pair ###")
	real4.insert(std::make_pair(7, 'g'));
	mine4.insert(ft::make_pair(7, 'g'));
	PRINT_M(real4);
	PRINT_M(mine4);
	ENDL()

	PRINT("### Inserting one pair at position ###")

	std::map<int, char>::iterator its = real4.insert(real4.begin(), std::make_pair(26, 'z'));
	ft::map<int, char >::iterator itc = mine4.insert(mine4.begin(), ft::make_pair(26, 'z'));
	its = real4.insert(its, std::make_pair(25, 'y'));
	itc = mine4.insert(itc, ft::make_pair(25, 'y'));
	PRINT_M(real4);
	PRINT_M(mine4);
	ENDL()

	PRINT("### Range - same keys ###")
	real4.insert(rp, rp + 5);
	mine4.insert(mp, mp + 5);
	PRINT_M(real4);
	PRINT_M(mine4);
	ENDL()

	PRINT("### Range - new keys ###")
	std::pair<int, char> rp2[] = {
		std::make_pair(10, 'a'),
		std::make_pair(20, 'b'),
		std::make_pair(30, 'c'),
		std::make_pair(40, 'd'),
		std::make_pair(50, 'e')};
	ft::pair<int, char> mp2[] = {
		ft::make_pair(10, 'a'),
		ft::make_pair(20, 'b'),
		ft::make_pair(30, 'c'),
		ft::make_pair(40, 'd'),
		ft::make_pair(50, 'e')};

	real4.insert(rp2, rp2 + 5);
	mine4.insert(mp2, mp2 + 5);
	PRINT_M(real4);
	PRINT_M(mine4);
	ENDL()

	PRINT("### erase position ###")
	real4.erase(its);
	mine4.erase(itc);
	PRINT_M(real4);
	PRINT_M(mine4);
	ENDL()

	PRINT("### erase with key ###") // ne marche pas avec tous les chiffres
	real4.erase(5);
	mine4.erase(5);
	real4.erase(123);
	mine4.erase(123);
	PRINT_M(real4);
	PRINT_M(mine4);
	ENDL()

	PRINT("### Range erase ###")
	its = real4.begin();
	itc = mine4.begin();
	std::advance(its, 5);
	std::advance(itc, 5);
	real4.erase(its, real4.end());
	mine4.erase(itc, mine4.end());
	PRINT_M(real4);
	PRINT_M(mine4);
	ENDL()

	PRINT("### swap ###")
	real4.swap(real3);
	mine4.swap(mine3);
	PRINT_M(real4);
	PRINT_M(mine4);
	ENDL()

	PRINT("### clear ###")
	real4.clear();
	mine4.clear();
	PRINT_M(real4);
	PRINT_M(mine4);
	ENDL()

	PRINT("### OBSERVERS - key_comp ###")
	std::map<int, char> real5(rp, rp + 5);
	ft::map<int, char> mine5(mp, mp + 5);
	its = real5.begin();
	itc = mine5.begin();
	std::advance(its, 1);
	std::advance(itc, 1);
	PRINT(real5.key_comp()(real5.begin()->first, its->first));
	PRINT(mine5.key_comp()(mine5.begin()->first, itc->first));
	PRINT(real5.key_comp()(its->first, real5.begin()->first));
	PRINT(mine5.key_comp()(itc->first, mine5.begin()->first));
	ENDL()

	PRINT("### OBSERVERS - value_comp ###")
	PRINT(real5.value_comp()(*its, *real5.begin()));
	PRINT(mine5.value_comp()(*itc, *mine5.begin()));
	PRINT(real5.value_comp()(*real5.begin(), *its));
	PRINT(mine5.value_comp()(*mine5.begin(), *itc));
	ENDL()

	PRINT("### OPERATIONS - find ###")
	its = real5.find(2);
	itc = mine5.find(2);
	PRINT(its->first)
	PRINT(itc->first)
	its = real5.find(19);
	itc = mine5.find(19);
	PRINT(its->first)
	PRINT(itc->first)

	std::map<int, char>::const_iterator cits = real5.find(2);
	ft::map<int, char>::const_iterator citc = mine5.find(2);
	PRINT(cits->first)
	PRINT(citc->first)
	cits = real5.find(19);
	citc = mine5.find(19);
	PRINT(cits->first)
	PRINT(citc->first)
	ENDL()

	PRINT("### OPERATIONS - count ###")
	PRINT(real5.count(2));
	PRINT(mine5.count(2));
	PRINT(real5.count(19));
	PRINT(mine5.count(19));
	ENDL()

	PRINT("### OPERATIONS - lower bound ###")
	its = real5.lower_bound(3);
	itc = mine5.lower_bound(3);
	PRINT(its->first)
	PRINT(itc->first)
	its = real5.lower_bound(19);
	itc = mine5.lower_bound(19);
	PRINT(its->first)
	PRINT(itc->first)

	cits = real5.lower_bound(3);
	citc = mine5.lower_bound(3);
	PRINT(cits->first)
	PRINT(citc->first)
	cits = real5.lower_bound(19);
	citc = mine5.lower_bound(19);
	PRINT(cits->first)
	PRINT(citc->first)

	PRINT("### OPERATIONS - upper bound ###")
	its = real5.upper_bound(3);
	itc = mine5.upper_bound(3);
	PRINT(its->first)
	PRINT(itc->first)
	its = real5.upper_bound(19);
	itc = mine5.upper_bound(19);
	PRINT(its->first)
	PRINT(itc->first)

	cits = real5.upper_bound(3);
	citc = mine5.upper_bound(3);
	PRINT(cits->first)
	PRINT(citc->first)
	cits = real5.upper_bound(19);
	citc = mine5.upper_bound(19);
	PRINT(cits->first)
	PRINT(citc->first)

	PRINT("### OPERATIONS - equal range ###")
	std::pair<std::map<int, char>::iterator, std::map<int, char>::iterator> rets = real5.equal_range(3);
	ft::pair<ft::map<int, char>::iterator, ft::map<int, char>::iterator> retc = mine5.equal_range(3);
	PRINT(rets.first->first)
	PRINT(retc.first->first)
	PRINT(rets.second->first)
	PRINT(retc.second->first)

	rets = real5.equal_range(33);
	retc = mine5.equal_range(33);
	PRINT(rets.first->first)
	PRINT(retc.first->first)
	PRINT(rets.second->first)
	PRINT(retc.second->first)

	std::pair<std::map<int, char>::const_iterator, std::map<int, char>::const_iterator> crets = real5.equal_range(3);
	ft::pair<ft::map<int, char>::const_iterator, ft::map<int, char>::const_iterator> cretc = mine5.equal_range(3);
	PRINT(crets.first->first)
	PRINT(cretc.first->first)
	PRINT(crets.second->first)
	PRINT(cretc.second->first)

	crets = real5.equal_range(33);
	cretc = mine5.equal_range(33);
	PRINT(crets.first->first)
	PRINT(cretc.first->first)
	PRINT(crets.second->first)
	PRINT(cretc.second->first)
} 