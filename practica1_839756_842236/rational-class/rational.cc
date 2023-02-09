#include "rational.h"

// Helper methods -----------------------
int Rational::mcd(int a, int b)
{
	return (b == 0 ? a : mcd(b, a % b));
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
	...
}

void Rational::read(std::istream &is){
	...}

// Add -----------------------
Rational Rational::add(const Rational &that) const
{
	Rational res;
	int MCM = mcm(r1.den, r2.den); // Máximo comun divisor
	res.den = MCM;
	res.num = r1.num * (MCM / r1.den) + r2.num * (MCM / r2.den);
	reduce(res);
	return res;
}

Rational Rational::add(int i) const {
	...}

Rational add(int i, const Rational &r){
	...}

// Subtract -----------------------
...

	// Multiply -------------------------
	...

	// Divide ------------------------------
	...
