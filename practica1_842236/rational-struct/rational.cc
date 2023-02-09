#include "rational.h"

// Helper functions -----------------------
int mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b,a%b));
}

void reduce(Rational& r) {
   ...
}

// Constructor -----------------------
void init(Rational& r) {
   ...
}
void init(Rational& r,int num, int den) {
   ...
}

// Input/output ---------------------------------
void write(const Rational& r, std::ostream& os) {
 	...
}

void read(Rational& r, std::istream& is) {
	...
}

// Add -----------------------
Rational add(const Rational& r1, const Rational& r2) {
	Rational res;
	...
	return res;
}

Rational add(const Rational& r, int i) {
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
