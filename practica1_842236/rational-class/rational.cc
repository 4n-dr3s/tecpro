#include "rational.h"

// Helper methods -----------------------
int Rational::mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b,a%b));
}

void Rational::reduce() {
   ...
}

// Constructor -----------------------
Rational::Rational() {
	...
}

Rational::Rational(int num, int den) {
   ...
}

// Input/output ---------------------------------
void Rational::write(std::ostream& os) const {
 	...
}

void Rational::read(std::istream& is) {
	...
}

// Add -----------------------
Rational Rational::add(const Rational& that) const {
	...
}

Rational Rational::add(int i) const {
	...
}

Rational add(int i, const Rational& r) {
   ...
}

// Subtract -----------------------
...

// Multiply -------------------------
...

// Divide ------------------------------
...




