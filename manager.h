#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include <iostream>
#include "angajat.h"
#include <typeinfo>

template <class T> class angajat;

template <class T>
class manager : virtual public angajat<T>
{
protected:
    char* departament;
public:
    manager() : angajat<T>()
    {
        departament = NULL;
    }
    manager(char* n, T sal, char* dep) : angajat<T>(n, sal)
    {
        dep = new char [strlen(dep) + 1];
        departament = dep;
    }
    manager(manager<T> &obiect) : angajat<T>(obiect)
    {
        departament = new char [strlen(obiect.departament)];
    }
    ~manager()
    {
        free(departament);
    }

    template <class U>
    friend istream& operator >> (istream& in, manager<U> &obiect)
    {
        in >> (*(dynamic_cast<angajat<T>*>(&obiect)));
        cout << "\n departamentul angajatului: ";
        char *dep = new char[100];
        in>>dep;
        obiect.departament = dep;

        return in;
    }

    template <class U>
    friend ostream& operator << (ostream& out, manager<U> &obiect)
    {
        out << (*(dynamic_cast<angajat<T>*>(&obiect)));
        out << ", departament: " << obiect.departament;

        return out;
    }


};



#endif // MANAGER_H_INCLUDED
