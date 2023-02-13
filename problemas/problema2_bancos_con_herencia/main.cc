#include "cuenta.h"
#include <iostream>
#include <iomanip>

using namespace std;

double total(Cuenta *cuentas[], int n, int t);
void mostrar_taes(Cuenta *cuentas[], int n);

int main()
{
	Cuenta *cuentas[4];

	cuentas[0] = new Corriente(1000, 1.2);
	cuentas[1] = new Plazo(5000, 60.0, 12);
	cuentas[2] = new Nomina(2000, 2.5);
	cuentas[3] = new Divisa(cuentas[0], 2);

	mostrar_taes(cuentas, 4);
	cout << endl;

	cout << "Mes |  Valor cuentas                           |  Total      " << endl;
	cout << "=============================================================" << endl;
	for (int t = 0; t <= 24; t++)
	{
		cout << setw(3) << t;
		cout << " | ";
		for (int i = 0; i < 4; i++)
			cout << fixed << setw(10) << setprecision(2) << cuentas[i]->valor(t);
		cout << " | ";
		cout << fixed << setw(10) << setprecision(2) << total(cuentas, 4, t);
		cout << " €" << endl;
	}

	for (int i = 0; i < 4; i++)
		delete cuentas[i];

	return 0;
}

double total(Cuenta *cuentas[], int n, int t)
{
	double sol = 0.0;
	for (int i = 0; i < n; i++)
		sol += cuentas[i]->valor(t);
	return sol;
}

void mostrar_taes(Cuenta *cuentas[], int n)
{
	cout << "TAEs: ";
	for (int i = 0; i < n; i++)
		cout << cuentas[i]->tae() << " ";
}
