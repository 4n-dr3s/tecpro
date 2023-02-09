#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational	a,b,r;
	char		op;

	while (true)
	{
		cout << "? " << flush;
		a.read(cin);
		if (cin.fail())
			break;

		cin >> op;
		b.read(cin);
		if (cin.fail())
			break;

		// Calculo del resultado
		...

		// Escritura del resultado
		...
	}

	return 0;
}

