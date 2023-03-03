// Autores: Andrei Vlasceanu [839756] & Andres Yubero [842236]

#include "programaSuma.h"
#include "programaCuentaAtras.h"
#include "programaFactorial.h"

using namespace std;

int main()
{
    // Simulamos programa suma
    ProgramaSuma programa0;
    programa0.listar();
    cout << endl;
    programa0.ejecutar();
    cout << endl;

    // Simulamos programa cuenta atrás
    ProgramaCuentaAtras programa1;
    programa1.listar();
    cout << endl;
    programa1.ejecutar();
    cout << endl;

    // Simulamos programa factorial
    ProgramaFactorial programa2;
    programa2.listar();
    cout << endl;
    programa2.ejecutar();

    return 0;
}