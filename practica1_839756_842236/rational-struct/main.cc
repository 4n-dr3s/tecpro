#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational a, b, c, r;
	char op;

	while (true)
	{
		cout << "? " << flush;

		read(a, cin);
		if (cin.fail())
			break;

		cin >> op;

		read(b, cin);
		if (cin.fail())
			break;

		// Calculo del resultado
		switch (op)
		{
		case '+':
			r = add(a, b);
			break;
		case '-':
			r = subtract(a, b);
			break;
		case '*':
			r = multiply(a, b);
			break;
		case '/':
			r = divide(a, b);
			break;
		}

		// Escritura del resultado
		write(r, cout);
	}

	return 0;
}