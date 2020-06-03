#include "../List.hpp"
#include "iostream"
#include <list>

#define PRINT(value) std::cout << (value) << std::endl;
#define ENDL() std::cout << std::endl;
#define PRINT_L(list) print_list(list);
#define PRINT_L_CONST(list) print_list_const(list);
#define	PRINT_REV(list) print_rev(list);
#define	PRINT_REV_CONST(list) print_rev_const(list);

bool above_five(const int &value) { return (value > 5); }

bool above_eight(int a, int b) //will test (*i,*(i-1))
{
	if (a + b > 8)
		return true;
	return false;
}

bool comp(int first, int second)
{
	return (first > second); //will check if element from merged_list is superior. If yes, it will merge here. Otherwise increment.
}

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
	ENDL()

	PRINT("# Constructor list()")
	std::list<int> real;
	ft::list<int> mine;
	PRINT("STD : ")
	PRINT_L(real)
	PRINT("CUSTOM : ")
	PRINT_L(mine)

	PRINT("# Fill constructor : constructs with n element, each a copy of val")
	std::list<int> real2(3);
	ft::list<int> mine2(3);
	PRINT("STD : ")
	PRINT_L(real2)
	PRINT("CUSTOM : ")
	PRINT_L(mine2)

	PRINT("# Fill constructor : val is defined")
	std::list<int> real3(3, 50);
	ft::list<double> mine3(3, 50.6);
	PRINT("STD : ")
	PRINT_L(real3)
	PRINT("CUSTOM : ")
	PRINT_L(mine3)

	PRINT("# Range constructor :as many elements as the range [first, last)")
	std::list<int> real4(real3.begin(), real3.end());
	ft::list<int> mine4(mine3.begin(), mine3.end());
	PRINT("STD : ")
	PRINT_L(real4)
	PRINT("CUSTOM : ")
	PRINT_L(mine4)

	PRINT("# Range constructor array")
	int array[] = {1, 2, 3, 4, 5};
	std::list<int> real5(array, array + 5);
	ft::list<int> mine5(array, array + 5);
	PRINT("STD : ")
	PRINT_L(real5)
	PRINT("CUSTOM : ")
	PRINT_L(mine5)

	PRINT("# Copy constructor")
	std::list<int> real6(real5);
	std::list<int> mine6(real5);
	PRINT("STD : ")
	PRINT_L(real6)
	PRINT("CUSTOM : ")
	PRINT_L(mine6)

	PRINT("# = Operator")
	std::list<int> real7 = real5;
	ft::list<int> mine7 = mine5;
	PRINT("STD : ")
	PRINT_L(real7)
	PRINT("CUSTOM : ")
	PRINT_L(mine7)

	ENDL()

	PRINT("### Testing const iterator ###")
	PRINT("STD CONST : ")
	PRINT_L_CONST(real5)
	PRINT("CUSTOM CONST: ")
	PRINT_L_CONST(mine5)

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
	PRINT("CUSTOM EMPTY : \n")
	PRINT(mine.empty());
	PRINT(mine5.empty());
	PRINT("CUSTOM SIZE FUNCTIONS: \n")
	PRINT(mine5.size());
	PRINT(mine5.max_size());
	ENDL()

	PRINT("### Element access ###")
	PRINT("STD FRONT : ")
	PRINT(real5.front());
	PRINT("STD BACK : ")
	PRINT(real5.back());
	PRINT("CUSTOM FRONT : ")
	PRINT(mine5.front());
	PRINT("CUSTOM BACK: ")
	PRINT(mine5.back());
	ENDL()

	PRINT("### Modifiers - Assign ###")
	std::list<int> standard(10, 8);
	ft::list<int> custom(10, 8);
	standard.assign(array, array +5);
	custom.assign(array, array + 5);
	PRINT("STD ASSIGN ITERATORS : ")
	PRINT_L(standard)
	PRINT("CUSTOM ASSIGN ITERATORS : ")
	PRINT_L(custom)
	ENDL()

	standard.assign(10, 10);
	custom.assign(10, 10);
	PRINT("STD ASSIGN n values : ")
	PRINT_L(standard)
	PRINT("CUSTOM ASSIGN n values : ")
	PRINT_L(custom)
	ENDL()

	PRINT("### Modifiers - Push & pop ###")
	standard.push_front(3);
	custom.push_front(3);
	PRINT("STD Push front 3 : ")
	PRINT_L(standard)
	PRINT("CUSTOM Push front 3 : ")
	PRINT_L(custom)
	ENDL()

	standard.pop_front();
	custom.pop_front();
	PRINT("STD Pop front 3 : ")
	PRINT_L(standard)
	PRINT("CUSTOM Pop front 3 : ")
	PRINT_L(custom)
	ENDL()

	standard.push_back(3);
	custom.push_back(3);
	PRINT("STD Push back 3: ")
	PRINT_L(standard)
	PRINT("CUSTOM Push back 3: ")
	PRINT_L(custom)
	ENDL()

	standard.pop_back();
	custom.pop_back();
	PRINT("STD Pop Back : ")
	PRINT_L(standard)
	PRINT("CUSTOM Pop Back : ")
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
	PRINT("STD Insert val 5 at position 5 : ")
	PRINT_L(standard)
	PRINT("CUSTOM Insert val 5 at position 5 : ")
	PRINT_L(custom)
	ENDL();

	standard.insert(its, 3, 5);
	custom.insert(itc, 3, 5);
	PRINT("STD Insert 3 times val 5 : ")
	PRINT_L(standard)
	PRINT("CUSTOM Insert 3 times val 5 : ")
	PRINT_L(custom)
	ENDL();

	standard.insert(its, array, array + 5);
	custom.insert(itc, array, array + 5);
	PRINT("STD Insert range : ")
	PRINT_L(standard)
	PRINT("CUSTOM Insert range : ")
	PRINT_L(custom)
	ENDL();

	PRINT("### Modifiers - Erase ###")
	standard.erase(its);
	custom.erase(itc);
	PRINT("STD Erase position : ")
	PRINT_L(standard)
	PRINT("CUSTOM Erase position : ")
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
	PRINT("STD Erase range : ")
	PRINT_L(standard)
	PRINT("CUSTOM Erase range: ")
	PRINT_L(custom)
	ENDL();

	PRINT("### Modifiers - Swap ###")
	standard.swap(real5);
	custom.swap(mine5);
	PRINT("STD 1st list : ")
	PRINT_L(standard)
	PRINT("Custom 1st list : ")
	PRINT_L(custom)
	PRINT("STD 2nd list : ")
	PRINT_L(real5)
	PRINT("CUSTOM 2nd list : ")
	PRINT_L(mine5)
	ENDL();

	PRINT("### Modifiers - Resize ###")
	standard.resize(2);
	custom.resize(2);
	PRINT("STD resize down : ")
	PRINT_L(standard)
	PRINT("CUSTOM resize down : ")
	PRINT_L(custom)
	standard.resize(10);
	custom.resize(10);
	PRINT("STD resize up : ")
	PRINT_L(standard)
	PRINT("CUSTOM resize up : ")
	PRINT_L(custom)

	PRINT("### Modifiers - Clear ###")
	standard.clear();
	custom.clear();
	PRINT("STD clear : ")
	PRINT_L(standard)
	PRINT("CUSTOM clear: ")
	PRINT_L(custom)
	ENDL()

	PRINT("### Operations - Splice ###")
	standard.assign(array, array +5);
	custom.assign(array, array + 5);
	std::list<int> std2(10, 8);
	ft::list<int> cus2(10, 8);
	its = standard.begin();
	itc = custom.begin();
	for (size_t i = 0; i < 3; i++)
	{
		its++;
		itc++;
	}
	standard.splice(its, std2);
	custom.splice(itc, cus2);
	PRINT_L(standard)
	PRINT_L(custom)
	PRINT_L(std2)
	PRINT_L(cus2)
	ENDL()
	
	std2.assign(10, 11);
	cus2.assign(10, 11);
	std::list<int>::iterator is;
	is = std2.begin();
	ft::list<int>::iterator ic;
	ic = cus2.begin();
	standard.splice(its, std2, is);
	custom.splice(itc, cus2, ic);
	PRINT_L(standard)
	PRINT_L(custom)
	PRINT_L(std2)
	PRINT_L(cus2)
	ENDL()

	its = standard.begin();
	itc = custom.begin();
	standard.splice(its, std2, std2.begin(), --(std2.end()));
	custom.splice(itc, cus2, cus2.begin(), --(cus2.end()));
	PRINT_L(standard)
	PRINT_L(custom)
	PRINT_L(std2)
	PRINT_L(cus2)
	ENDL()

	PRINT("### Operations - Remove ###")
	standard.remove(11);
	custom.remove(11);
	standard.remove(18);
	custom.remove(18);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	standard.remove_if(above_five);
	custom.remove_if(above_five);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	PRINT("### Operations - Unique ###")
	standard.push_front(1);
	custom.push_front(1);
	PRINT_L(standard)
	PRINT_L(custom)
	standard.unique();
	custom.unique();
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	standard.unique(above_eight); //removes i if i + i-1 > 8
	custom.unique(above_eight);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	PRINT("### Operations - Merge ###")
	std::list<int> merged_std(array, array + 5);
	ft::list<int> merged_cus(array, array + 5);
	standard.merge(merged_std);
	custom.merge(merged_cus);
	PRINT_L(standard)
	PRINT_L(custom)
	PRINT_L(merged_std)
	PRINT_L(merged_cus)
	ENDL()

	merged_std.assign(array, array + 5);
	merged_cus.assign(array, array + 5);
	standard.merge(merged_std, comp);
	custom.merge(merged_cus, comp);
	PRINT_L(standard)
	PRINT_L(custom)
	PRINT_L(merged_std)
	PRINT_L(merged_cus)
	ENDL()

	merged_std.assign(3, 10);
	merged_cus.assign(3, 10);
	standard.merge(merged_std, comp);
	custom.merge(merged_cus, comp);
	PRINT_L(standard)
	PRINT_L(custom)
	PRINT_L(merged_std)
	PRINT_L(merged_cus)
	ENDL()

	PRINT("### Operations - Sort ###")
	standard.sort();
	custom.sort();
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	standard.sort(comp);
	custom.sort(comp);
	PRINT_L(standard)
	PRINT_L(custom)
	ENDL()

	PRINT("### Operations - Reverse ###")
	standard.reverse();
	custom.reverse();
	PRINT_L(standard)
	PRINT_L(custom)
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

	std::swap(standard, std2);
	ft::swap(custom, cus2);
	PRINT_L(standard)
	PRINT_L(custom)
	PRINT_L(std2)
	PRINT_L(cus2)

	return 0;
}