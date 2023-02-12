#pragma once

#include <iostream>

using namespace std;

// Solucion con atributos publicos.

struct Rational
{
    int num, den;
};

int mcd(int a, int b);
void reduce(Rational &r);

void init(Rational &r);
void init(Rational &r, int num, int den);

// Entrada - salida
void write(const Rational &r, std::ostream &os);
void read(Rational &r, std::istream &is);

// Operaciones aritmeticas
Rational add(const Rational &r1, const Rational &r2);
Rational add(const Rational &r, int i);
Rational add(int i, const Rational &r);

// sub
Rational subtract(const Rational &r1, const Rational &r2);
Rational subtract(const Rational &r, int i);
Rational subtract(int i, const Rational &r);

// mul
Rational multiply(const Rational &r1, const Rational &r2);
Rational multiply(const Rational &r, int i);
Rational multiply(int i, const Rational &r);

// div
Rational divide(const Rational &r1, const Rational &r2);
Rational divide(const Rational &r, int i);
Rational divide(int i, const Rational &r);