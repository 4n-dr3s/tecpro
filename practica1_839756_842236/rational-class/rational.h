#pragma once

#include <iostream>

// Solucion con atributos privados.

class Rational
{
	// Miembros
	int num, den;

	// Funciones auxiliares
	static int mcd(int a, int b);
	void reduce();

public:
	// Constructores
	Rational();
	Rational(int num, int den);

	// Entrada - salida
	void write(std::ostream &os) const;
	void read(std::istream &is);

	// Operadores aritmeticos
	Rational add(const Rational &that) const;
	Rational add(int i) const;
	...
};

// Operadores aritmeticos
Rational add(int i, const Rational &r);
...
