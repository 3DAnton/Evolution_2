#ifndef DOMAIN_H
#define DOMAIN_H

template <typename T>
union Pair
{
	struct
	{
		T i, j;
	};
	struct
	{
		T x, y;
	};
	struct
	{
		T first, second;
	};

	Pair()
	{
		i = j = 0;
	}
	Pair(const T iInit, const T jInit) :
		i(iInit),
		j(jInit)
	{}

	T& operator[] (const int num)
	{
		return num ? j : i;
	}

	void operator+= (const Pair& n)
	{
		i += n.i;
		j += n.j;
	}
	void operator-= (const Pair& n)
	{
		i -= n.i;
		j -= n.j;
	}

	Pair operator+ (const Pair& n) const
	{
		Pair ret;
		ret.i = i + n.i;
		ret.j = j + n.j;
		return ret;
	}
	Pair operator- (const Pair& n) const
	{
		Pair ret;
		ret.i = i - n.i;
		ret.j = j - n.j;
		return ret;
	}

	bool operator< (const Pair& n) const
	{
		if (i != n.i) return i < n.i;
		return j < n.j;
	}
	bool operator>(const Pair& n) const
	{
		if (i != n.i) return i > n.i;
		return j > n.j;
	}
	bool operator== (const Pair& n) const
	{
		return i == n.i && j == n.j;
	}
	bool operator!= (const Pair& n) const
	{
		return i != n.i || j != n.j;
	}
};

#endif // DOMAIN_H