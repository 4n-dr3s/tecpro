#pragma once
#include <algorithm>
#include <string>
#include <complex>
#include <vector>
#include <list>

using namespace std;

template <typename T>
bool operator<(complex<T> a, complex<T> b)
{
	return abs(a) < abs(b);
}

template <typename T>
bool operator>(complex<T> a, complex<T> b)
{
	return abs(a) > abs(b);
}

template <typename T>
T magnitude(vector<T> v)
{
	T mag = 0;
	for (auto i : v)
	{
		mag += pow(i, 2);
	}
	return sqrt(mag);
}

template <typename T>
bool operator<(vector<T> a, vector<T> b)
{
	return magnitude(a) < magnitude(b);
}

template <typename T>
bool operator>(vector<T> a, vector<T> b)
{
	return magnitude(a) > magnitude(b);
}

// Operación suma que hemos pensado para vectores
template <typename T>
vector<T> operator+(vector<T> a, vector<T> b)
{
	return {magnitude(a) + magnitude(b)};
}

// Operación división que hemos pensado para vectores
template <typename T>
vector<T> operator/(vector<T> a, vector<T> b)
{
	return {magnitude(a) / magnitude(b)};
}

template <typename T>
class Store
{
protected:
	T val;

public:
	virtual string name() const = 0;

	virtual void push(const T &v) = 0;
	virtual T value() const { return val; }
};

template <typename T>
class StoreLast : public Store<T>
{
private:
	using Store<T>::val;

public:
	string name() const override { return "last"; }

	void push(const T &v) override
	{
		val = v;
	}
};

template <typename T>
class StoreMax : public Store<T>
{
private:
	using Store<T>::val;
	bool first;

public:
	StoreMax() : first(true) {}

	string name() const override { return "max"; }

	using Store<T>::push;
	void push(const T &v) override
	{
		if (first)
		{
			val = v;
			first = false;
		}
		else
		{
			val = (v > val) ? v : val; // max(val, v);
		}
	}
};

template <typename T>
class StoreMin : public Store<T>
{
private:
	using Store<T>::val;
	bool first;

public:
	StoreMin() : first(true) {}

	string name() const override { return "min"; }

	using Store<T>::push;
	void push(const T &v) override
	{
		if (first)
		{
			val = v;
			first = false;
		}
		else
		{
			val = (v < val) ? v : val; // min(val, v);
		}
	}
};

template <typename T>
class StoreRange : public Store<T>
{
private:
	pair<T, T> valor; // <min, max>

public:
	StoreRange(const T &ini)
	{
		valor.first = ini;
		valor.second = ini;
	}
}

template <typename T>
class StoreAvg : public Store<T>
{
private:
	using Store<T>::val;
	int count;

public:
	StoreAvg(const T &ini) : count(0) { val = ini; }

	string name() const override { return "average"; }

	using Store<T>::push;
	void push(const T &v) override
	{
		count++;
		val = val + v;
	}

	T value() const override
	{
		return (count > 0 ? val / T(count) : val);
	}
};
