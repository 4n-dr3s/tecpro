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
	if (r.den < 0)
	{
		r.num = -r.num;
		r.den = -r.den;
	}
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
	os << r.num << "/" << r.den << endl;
}

void read(Rational &r, std::istream &is)
{
	is >> r.num;
	is.get(); // Ignorar el símbolo "/" que separa el numerador del denominador
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
Rational subtract(const Rational &r1, const Rational &r2)
{
	Rational res;
	int MCM = mcm(r1.den, r2.den); // Máximo comun divisor
	res.den = MCM;
	res.num = r1.num * (MCM / r1.den) - r2.num * (MCM / r2.den);
	reduce(res);
	return res;
}

Rational subtract(const Rational &r, int i)
{
	Rational res;
	res.num = r.num - i * r.den;
	res.den = r.den;
	reduce(res);
	return res;
}

Rational subtract(int i, const Rational &r)
{
	Rational res;
	res.num = i * r.den - r.num;
	res.den = r.den;
	reduce(res);
	return res;
}

// Multiply -------------------------
Rational multiply(const Rational &r1, const Rational &r2)
{
	Rational res;
	res.num = r1.num * r2.num;
	res.den = r1.den * r2.den;
	reduce(res);
	return res;
}

Rational multiply(const Rational &r, int i)
{
	Rational res;
	res.num = r.num * i;
	res.den = r.den;
	reduce(res);
	return res;
}

Rational multiply(int i, const Rational &r)
{
	Rational res;
	res.num = r.num * i;
	res.den = r.den;
	reduce(res);
	return res;
}

// Divide ------------------------------
Rational divide(const Rational &r1, const Rational &r2)
{
	Rational res;
	res.num = r1.num * r2.den;
	res.den = r1.den * r2.num;
	reduce(res);
	return res;
}

Rational divide(const Rational &r, int i)
{
	Rational res;
	res.num = r.num;
	res.den = r.den * i;
	reduce(res);
	return res;
}

Rational divide(int i, const Rational &r)
{
	Rational res;
	res.num = i * r.den;
	res.den = r.num;
	reduce(res);
	return res;
}

// Operaciones de suma -------------------------
Rational operator+(const Rational &r1, const Rational &r2)
{
	return add(r1, r2);
}

Rational operator+(const int i, const Rational &r2)
{
	return add(i, r2);
}

Rational operator+(const Rational &r1, int i)
{
	return add(r1, i);
}

// Operaciones de resta -------------------------
Rational operator-(const Rational &r1, const Rational &r2)
{
	return subtract(r1, r2);
}

Rational operator-(const int i, const Rational &r2)
{
	return subtract(i, r2);
}

Rational operator-(const Rational &r1, int i)
{
	return subtract(r1, i);
}

// Operaciones de multiplicación -------------------------
Rational operator*(const Rational &r1, const Rational &r2)
{
	return multiply(r1, r2);
}

Rational operator*(const int i, const Rational &r2)
{
	return multiply(i, r2);
}

Rational operator*(const Rational &r1, int i)
{
	return multiply(r1, i);
}

// Operaciones de división -------------------------
Rational operator/(const Rational &r1, const Rational &r2)
{
	return divide(r1, r2);
}

Rational operator/(const int i, const Rational &r2)
{
	return divide(i, r2);
}

Rational operator/(const Rational &r1, int i)
{
	return divide(r1, i);
}

// Escritura -------------------------
ostream &operator<<(ostream &stream, const Rational &r)
{
	write(r, stream);
	return stream;
}

// Lectura -------------------------
istream &operator>>(istream &stream, Rational &r)
{
	read(r, stream);
	return stream;
}