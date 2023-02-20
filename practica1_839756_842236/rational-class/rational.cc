// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

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
	if (den < 0)
	{
		num = -num;
		den = -den;
	}
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
	int MCM = this->mcm(this->den, that.den); // Máximo comun divisor
	int numerador = this->num * (MCM / this->den) + that.num * (MCM / that.den);
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

Rational Rational::operator+(const Rational &that)
{
	return this->add(that);
}

Rational Rational::operator+(int i)
{
	return this->add(i);
}

Rational operator+(int i, const Rational &r)
{
	return add(i, r);
}

// Subtract -----------------------
Rational Rational::subtract(const Rational &that) const
{
	int MCM = this->mcm(this->den, that.den); // Máximo comun divisor
	int numerador = this->num * (MCM / this->den) - that.num * (MCM / that.den);
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
	Rational j(i, 1);
	return j.subtract(r);
}

Rational Rational::operator-(const Rational &that)
{
	return this->subtract(that);
}

Rational Rational::operator-(int i)
{
	return this->subtract(i);
}

Rational operator-(int i, const Rational &r)
{
	return subtract(i, r);
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

Rational Rational::operator*(const Rational &that)
{
	return this->multiply(that);
}

Rational Rational::operator*(int i)
{
	return this->multiply(i);
}

Rational operator*(int i, const Rational &r)
{
	return multiply(i, r);
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

Rational Rational::operator/(const Rational &that)
{
	return this->divide(that);
}

Rational Rational::operator/(int i)
{
	return this->divide(i);
}

Rational operator/(int i, const Rational &r)
{
	return divide(i, r);
}

// Operadores de escritura y lectura
ostream &operator<<(ostream &stream, const Rational &r)
{
	r.write(stream);
	return stream;
}

istream &operator>>(istream &stream, Rational &r)
{
	r.read(stream);
	return stream;
}