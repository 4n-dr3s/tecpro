#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational /*a,*/ b, r;
	int a;
	char op;

	while (true)
	{
		cout << "? " << flush;
		cin >> a;
		// a.read(cin);
		if (cin.fail())
			break;

		cin >> op;
		b.read(cin);
		// cin >> b;
		if (cin.fail())
			break;

		// Calculo del resultado
		switch (op)
		{
		case '+':
			r = add(a, b); // a.add(b);
			break;
		case '-':
			r = subtract(a, b); // a.subtract(b);
			break;
		case '*':
			r = multiply(a, b); // a.multiply(b);
			break;
		case '/':
			r = divide(a, b); // a.divide(b);
			break;
		}

		// Escritura del resultado
		r.write(cout);
	}

	return 0;
}
