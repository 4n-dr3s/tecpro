#include "rational.h"

// Helper methods -----------------------
int Rational::mcd(int a, int b)
{
	return (b == 0 ? a : mcd(b, a % b));
}

int Rational::mcm(int a, int b)
{
	int ab = a * b;
	ab = ab < 0 ? -ab : ab;
	return ab / mcd(a, b);
}

void Rational::reduce()
{
	int MCD = mcd(num, den);
	num /= MCD;
	den /= MCD;
}

// Constructor -----------------------
Rational::Rational()
{
	num = 0;
	den = 1;
}

Rational::Rational(int num, int den)
{
	this->num = num;
	this->den = den;
}

// Input/output ---------------------------------
void Rational::write(std::ostream &os) const
{
	os << num << "/" << den << endl;
}

void Rational::read(std::istream &is)
{
	is >> num;
	is.ignore();
	is >> den;
}

// Add -----------------------
Rational Rational::add(const Rational &that) const
{
	int numerador = this->num * (MCM / this->den) + that.num * (MCM / that.den);
	int MCM = this->mcm(this->den, that.den); // Máximo comun divisor
	int denominador = MCM;
	Rational res(numerador, denominador);
	res.reduce();
	return res;
}

Rational Rational::add(int i) const
{
	int numerador = this->num + i * this->den;
	int denominador = this->den;
	Rational res(numerador, denominador);
	res.reduce();
	return res;
}

Rational add(int i, const Rational &r)
{
	return r.add(i);
}

// Subtract -----------------------
Rational Rational::subtract(const Rational &that) const
{
	int numerador = this->num * (MCM / this->den) - that.num * (MCM / that.den);
	int MCM = this->mcm(this->den, that.den); // Máximo comun divisor
	int denominador = MCM;
	Rational res(numerador, denominador);
	res.reduce();
	return res;
}

Rational Rational::subtract(int i) const
{
	int numerador = this->num - i * this->den;
	int denominador = this->den;
	Rational res(numerador, denominador);
	res.reduce();
	return res;
}

Rational subtract(int i, const Rational &r)
{
	return r.subtract(i);
}

// Multiply -------------------------
Rational Rational::multiply(const Rational &that) const
{
	int numerador = this->num * that.num;
	int denominador = this->den * that.den;
	Rational res(numerador, denominador);
	res.reduce();
	return res;
}
Rational Rational::multiply(int i) const
{
	int numerador = this->num * i;
	int denominador = this->den;
	Rational res(numerador, denominador);
	res.reduce();
	return res;
}
Rational multiply(int i, const Rational &r)
{
	return r.multiply(i);
}

// Divide ------------------------------
Rational Rational::divide(const Rational &that) const
{
	int numerador = this->num * that.den;
	int denominador = this->den * that.num;
	Rational res(numerador, denominador);
	res.reduce();
	return res;
}

Rational Rational::divide(int i) const
{
	int numerador = this->num;
	int denominador = this->den * i;
	Rational res(numerador, denominador);
	res.reduce();
	return res;
}

Rational divide(int i, const Rational &r)
{
	Rational q(i, 1);
	return q.divide(r);
}