#include "cuenta.h"
#include <iostream>
#include <cmath>

using namespace std;

// CUENTA GENERAL
Cuenta::Cuenta(double _capital, double _interes, int _plazo)
	: capital(_capital), interes(_interes), plazo(_plazo) {}

double Cuenta::valor(int t) const
{
	return 0.0;
}

double Cuenta::tae() const
{
	return 100.0 * (valor(12) / valor(0) - 1);
}

// CUENTA CORRIENTE
Corriente::Corriente(double _capital, double _interes)
	: Cuenta(_capital, _interes) {}

double Corriente::valor(int t) const
{
	return capital * pow(1 + (interes / 100.0), t);
}

// CUENTA A PLAZO FIJO
Plazo::Plazo(double _capital, double _interes, int _plazo)
	: Cuenta(_capital, _interes, _plazo) {}

double Plazo::valor(int t) const
{
	return (t < plazo ? capital : capital * (1 + (interes / 100.0)));
}

// CUENTA NÓMINA
Nomina::Nomina(double _capital, double _N)
	: Cuenta(_capital), N(_N) {}

double Nomina::valor(int t) const
{
	return capital + t * N;
}

// CUENTA DIVISA
Divisa::Divisa(Cuenta *_c, double _r)
	: Cuenta(r), c(_c), r(_r) {} // Cuenta(r) es para evitar errores al ser divisa un hijo de cuenta

double Divisa::valor(int t) const
{
	return r * c->valor(t);
}

double Divisa::tae() const
{
	return c->tae();
}