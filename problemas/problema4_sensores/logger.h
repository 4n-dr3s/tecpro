// Autores: Andrei Gabriel Vlasceanu [839756] & Andrés Yubero Segura [842236]

#include "store.h"
#include <iostream>
#include <list>

using namespace std;

template <typename T>
ostream &operator<<(ostream &stream, const std::vector<T> &v)
{
    for (auto i : v)
    {
        stream << i << " ";
    }
    return stream;
}

template <typename T>
ostream &operator<<(ostream &stream, const std::pair<T, T> &p)
{
    stream << p.first << ", " << p.second;
    return stream;
}

template <typename T>
class Logger
{
private:
    // Etiqueta que identifica al sensor e.g. "temperatura","posicion",...
    string etiqueta;
    // Lista de acumuladores
    list<Store<T> *> stores;

public:
    // Constructor
    Logger(const string _etiqueta, list<Store<T> *> _stores) : etiqueta(_etiqueta), stores(_stores) {}

    // Destructor
    ~Logger()
    {
        stores.clear();
    }

    // Recibe un valor y lo guarda en todos los almacenes
    void push(list<T> values)
    {
        for (auto v : values)
        {
            for (auto s : stores)
            {
                s->push(v);
            }
        }
    }

    // Recibe un valor y lo guarda en todos los almacenes
    void push(T v)
    {
        for (auto s : stores)
        {
            s->push(v);
        }
    }

    void log()
    {
        cout << etiqueta << ":" << endl;
        for (auto s : stores)
        {
            cout << "\t" << s->name() << ": ";
            StoreRange<T> *sr = dynamic_cast<StoreRange<T> *>(s);
            if (sr)
            {
                cout << sr->values();
            }
            else
            {
                cout << s->value();
            }
            cout << endl;
        }
    }
};