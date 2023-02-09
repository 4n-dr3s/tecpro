#include "rational.h"

// Helper functions -----------------------
int mcd(int a, int b)
{
	return (b == 0 ? a : mcd(b, a % b));
}

int mcm(int a, int b)
{
	int ab = a * b;
	ab = ab < 0 ? -ab : ab;
	return ab / mcd(a, b);
}

void reduce(Rational &r)
{
	int MCD = mcd(r.num, r.den);
	r.num /= MCD;
	r.den /= MCD;
}

// Constructor -----------------------
void init(Rational &r)
{
	r.num = 0;
	r.den = 1;
}
void init(Rational &r, int num, int den)
{
	r.num = num;
	r.den = den;
}

// Input/output ---------------------------------
void write(const Rational &r, std::ostream &os)
{
	os << r.num << "/" << r.den;
}

void read(Rational &r, std::istream &is)
{
	is >> r.num;
	is >> r.den;
}

// Add -----------------------
Rational add(const Rational &r1, const Rational &r2)
{
	Rational res;
	int MCM = mcm(r1.den, r2.den); // Máximo comun divisor
	res.den = MCM;
	res.num = r1.num * (MCM / r1.den) + r2.num * (MCM / r2.den);
	reduce(res);
	return res;
}

Rational add(const Rational &r, int i)
{
	Rational res;
	res.num = r.num + i * r.den;
	res.den = r.den;
	reduce(res);
	return res;
}

Rational add(int i, const Rational &r)
{
	Rational res;
	res.num = r.num + i * r.den;
	res.den = r.den;
	reduce(res);
	return res;
}

// Subtract -----------------------
Rational subtract(const Rational &r1, const Rational &r2){

}

// Multiply -------------------------
...

	// Divide ------------------------------
	...
