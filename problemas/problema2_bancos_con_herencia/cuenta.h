// Autores: Andrei Gabriel Vlasceanu [839756] & Andrés Yubero Segura [842236]

#pragma once

class Cuenta
{
protected:
	// Capital inicial
	double capital;
	// Si es cuenta corriente, tipo de interes mensual en %.
	// Si es plazo fijo, tipo de interes en % cuando se acaba el plazo.
	double interes;
	// Si es plazo fijo, tiempo (en meses) pendiente
	// hasta que venza el plazo (no da dinero antes)
	int plazo;

public:
	//  Constructor general
	Cuenta(double _capital, double _interes = 0, int _plazo = 0);

	virtual double valor(int t) const;
	virtual double tae() const;
	virtual void actualiza();
};

/*--------------------------------------------------*/
// CUENTA CORRIENTE
class Corriente : public Cuenta
{
public:
	// Constructor para una cuenta corriente (no hay parámetro plazo)
	Corriente(double _capital, double _interes);

	double valor(int t) const;
};

/*--------------------------------------------------*/
// CUENTA A PLAZO FIJO
class Plazo : public Cuenta
{
public:
	// Constructor para una cuenta de plazo fijo (hay parámetro plazo)
	Plazo(double _capital, double _interes, int _plazo);

	double valor(int t) const;
	double tae() const;
	void actualiza();
};

/*--------------------------------------------------*/
// CUENTA DE NÓMINA
class Nomina : public Cuenta
{
private:
	double N;

public:
	// Constructor para una cuenta de plazo fijo (hay parámetro plazo)
	Nomina(double _capital, double _N);

	double valor(int t) const;
};

/*--------------------------------------------------*/
// CUENTA EN DIVISA
class Divisa : public Cuenta
{
private:
	Cuenta *c;
	double r; // Factor de conversión entre divisas

public:
	// Constructor para una cuenta de plazo fijo (hay parámetro plazo)
	Divisa(Cuenta *_c, double _r);

	double valor(int t) const;
	double tae() const;
	void actualiza();
};