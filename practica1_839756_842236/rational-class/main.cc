#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational a, b, r;
	char op;

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
		switch (op)
		{
		case '+':
			r = a.add(b);
			break;
		case '-':
			r = a.subtract(b);
			break;
		case '*':
			r = a.multiply(b);
			break;
		case '/':
			r = a.divide(b);
			break;
		}

		// Escritura del resultado
		r.write(cout);
	}

	return 0;
}
