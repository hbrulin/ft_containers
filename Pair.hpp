#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {

	template <typename T1, typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() : first(), second() {} //call constructors for types
		~pair() {}
		pair(const T1 &x, const T2 &y) : first(x), second(y) {}
		pair(const pair &c) : first(c.first), second(c.second) {}
		//template <class U, class V>
		//pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {};
		pair &operator=(const pair &c)
		{
			first = c.first;
			second = c.second;
			return *this;
		}
	};
	//needed?
	template <typename T1, typename T2>
	pair<T1, T2> make_pair(const T1 t, const T2 u)
	{
		return pair<T1, T2>(t, u);
	}

	template <typename T1, typename T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
		;
	}

	template <typename T1, typename T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first && lhs.second < rhs.second;
	}

	template <typename T1, typename T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T1, typename T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs > rhs);
	}

	template <typename T1, typename T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return rhs > lhs;
	}

	template <typename T1, typename T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	}




};