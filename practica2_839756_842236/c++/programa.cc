// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "programa.h"

void Programa::ejecutar()
{
    // Creamos la pila
    stack<int> *s = new stack<int>;
    cout << "Ejecución:" << endl;
    int counter = 0;
    // Iteramos por cada una de las instrucciones
    while (counter >= 0 && counter < len)
    {
        // Ejecutamos la instrucción
        instrucciones[counter]->ejecutar(s, counter);
    }
}

void Programa::listar()
{
    cout << "Programa:" << endl;
    // Iteramos por cada una de las instrucciones
    for (int i = 0; i < len; i++)
    {
        // Listamos la instrucción
        cout << i << "  ";
        instrucciones[i]->listar();
    }
}