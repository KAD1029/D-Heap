#include <iostream>
#include <vector>

using namespace std;

class element
{
public:
	int key;
	int val;

	element()
	{
		key = 0;
		val = 0;
	}

	element(int k, int v)
	{
		key = k;
		val = v;
	}

	friend bool operator<(element a, element b)
	{
		return a.key < b.key;
	}

	friend ostream& operator<<(ostream& out, element a)
	{
		out << "(" << a.key << " ; " << a.val << ")";
		return out;
	}
};



class D_heap
{
private:

	const unsigned int D;
	vector<element> v;
	int size;

	void go_up(int i)
	{
		while (i > D && v[i] < v[(i - 1) / D])
		{
			swap(v[i], v[(i - 1) / D]);
			i = (i - 1) / D;
		}
		for (; i > ((i - 1) / D) * D + 1; i--)
		{
			if (v[i] < v[i - 1])
				swap(v[i], v[i - 1]);
		}
	}

	int min_child(int index)
	{
		int res = v[index * D + 1].key;
		for (int i = index * D + 1; i <= i * D * D; i++)
		{
			if (v[i].key < res)
				res = v[i].key;
		}
		return res;
	}

	void go_down(int i)
	{
		while ((i * D + 1 < size || i == 0) && v[i * D + 1] < v[i])
		{
			swap(v[i], v[i * D + 1]);
			i = i * D + 1;
		}
		for (int j = i; j < size && j < i + D - ((i - 1) % D) - 2; j++)
		{
			if (v[j + 1] < v[i])
				swap(v[j], v[j + 1]);
		}
	}


public:

	D_heap(int d) : D(d)
	{
		v.resize(D + 1);
		size = 0;
	}

	void insert(int key, int val)
	{
		size++;

		if (size == v.size())
		{
			v.resize(size * 1.3 + 2);
		}

		v[size] = { key, val };
		go_up(size);
	}

	void erase(int index)
	{
		swap(v[index], v[size]);
		size--;
		go_down(index);
	}


	friend ostream& operator<<(ostream& out, D_heap a)
	{
		out << "{";
		for (int i = 1; i <= a.size; i++)
		{
			out << " (" << a.v[i].key << " ; " << a.v[i].val << ")";
		}
		out << " }";
		return out;
	}

};