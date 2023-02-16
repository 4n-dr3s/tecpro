#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational a, b, r;
	char op;

	while (true)
	{
		/*cout << "? " << flush;
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
		cout << "= ";
		r.write(cout);*/

		Rational a, b, c, r;
		cin >> a >> b >> c;
		r = a + b * c;
		cout << r << endl;
	}

	return 0;
}
