#ifndef ADMINISTRATOR_H
#include ADMINISTRATOR_H

#include <iostream>
#include "angajat.h"

using namespace std;

template <class T> class angajat;

template <class T>
class administrator : virtual public angajat<T>
{
protected:
    int sectie;
public:
    administrator() : angajat()
    {
        sectie = -1;
    }
    administrator(char* n , T sal, int sec) : angajat(n, sal)
    {
        sectie = sec;
    }
    administrator(administrator <T> &obiect) : angajat (obiect)
    {
        sectie = obiect.sectie;
    }
    ~administrator()
    {
        //cout << "Exista";
    }

    template <class U>
    friend istream& operator >> (istream& in, administrator <U> &obiect)
    {
        in >> *(dynamic_cast<angajat*>(&obiect));
        in >> obiect.sectie;
    }

    template <class U>
    friend ostream& operator << (ostream& out, administrator <U> &obiect)
    {
        out << *(dynamic_cast<angajat*>(&obiect));
        out << " ";
        out << obiect.sectie;
        out << "\n";
    }
};

#endif // ADMINISTRATOR_H
