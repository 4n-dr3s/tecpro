// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#pragma once

#include <iostream>
#include <stack>

using namespace std;

class Instruccion
{
public:
    virtual void ejecutar(stack<int> *s) = 0;
    virtual void listar() = 0;
};