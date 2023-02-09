#pragma once

#include <iostream>

// Solucion con atributos publicos.

struct Rational
{
    int num, den;
};

int mcd(int a, int b);
void reduce(Rational& r);

void init(Rational& r);
void init(Rational& r, int num, int den);

// Entrada - salida
void write(const Rational& r, std::ostream& os);
void read(Rational& r, std::istream& is);

// Operaciones aritmeticas

Rational add(const Rational& r1, const Rational& r2);
Rational add(const Rational& r, int i);
Rational add(int i, const Rational& r);

// sub
// mul
// div


