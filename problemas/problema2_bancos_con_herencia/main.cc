// Autores: Andrei Gabriel Vlasceanu [839756] & Andrés Yubero Segura [842236]

#include "cuenta.h"
#include <iostream>
#include <iomanip>

using namespace std;

double total(Cuenta *cuentas[], int n, int t);
void mostrar_taes(Cuenta *cuentas[], int n);

int main()
{
	Cuenta *cuentas[4];

	// Creamos cuentas
	cuentas[0] = new Corriente(1000, 1.2);
	cuentas[1] = new Plazo(5000, 60.0, 12);
	cuentas[2] = new Nomina(2000, 2.5);
	cuentas[3] = new Divisa(cuentas[0], 2);

	// Mostramos TAEs
	mostrar_taes(cuentas, 4);
	cout << endl;

	// Tabla de valores a lo largo del tiempo
	cout << "Mes |  Valor cuentas                           |  Total      " << endl;
	cout << "=============================================================" << endl;
	for (int t = 0; t <= 10; t++)
	{
		cout << setw(3) << t;
		cout << " | ";
		for (int i = 0; i < 4; i++)
			cout << fixed << setw(10) << setprecision(2) << cuentas[i]->valor(t);
		cout << " | ";
		cout << fixed << setw(10) << setprecision(2) << total(cuentas, 4, t);
		cout << " €" << endl;
	}

	// Probamos que la función actualiza() funciona
	cout << setw(3) << " ";
	cout << " | ";
	for (int i = 0; i < 4; i++)
	{
		cuentas[i]->actualiza();
		cout << fixed << setw(10) << setprecision(2) << "Act.";
	}
	cout << " | ";
	cout << fixed << setw(10) << setprecision(2);
	cout << "" << endl;

	// Segunda parte de la tabla de valores tras la actualización
	for (int t = 11; t <= 24; t++)
	{
		cout << setw(3) << t;
		cout << " | ";
		for (int i = 0; i < 4; i++)
			cout << fixed << setw(10) << setprecision(2) << cuentas[i]->valor(t);
		cout << " | ";
		cout << fixed << setw(10) << setprecision(2) << total(cuentas, 4, t);
		cout << " €" << endl;
	}

	// Eliminar cuentas
	for (int i = 0; i < 4; i++)
		delete cuentas[i];

	return 0;
}

// Calcular el total, resultante de la suma de los valores de cada cuenta
double total(Cuenta *cuentas[], int n, int t)
{
	double sol = 0.0;
	for (int i = 0; i < n; i++)
		sol += cuentas[i]->valor(t);
	return sol;
}

// Mostrar TAEs
void mostrar_taes(Cuenta *cuentas[], int n)
{
	cout << "TAEs: ";
	for (int i = 0; i < n; i++)
		cout << cuentas[i]->tae() << " ";
}
