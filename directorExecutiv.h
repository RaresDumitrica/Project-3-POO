#ifndef DIRECTOREXECUTIV_H_INCLUDED
#define DIRECTOREXECUTIV_H_INCLUDED

#include <iostream>
#include "angajat.h"
#include "manager.h"
#include "administrator.h"
#

template <class T>
class directorExecutiv : public administrator, public manager
{

public:
    directorExecutiv() : administrator<T>(), manager<T>(){}
    directorExecutiv(char* n, T sal, int sec, char* dep)
    {
        n = new char [strlen(n) + 1];
        nume = n;
        salariu = sal;
        sectie = sec;
        dep = new char[strlen(dep) + 1];
        departament = dep;
    }
    directorExecutiv(directorExecutiv<T> &obiect)
    {
        nume = new char [strlen(obiect.nume)];
        departament = new char [strlen(obiect.departament)];
        salariu = obiect.salariu;
        sectie = obiect.sectie;
    }
    ~directorExecutiv()
    {
        free(nume);
        free(departament);
    }

    template <class U>
    friend istream& operator >> (istream& in, directorExecutiv<U> &obiect)
    {
        char* n = new char[100];
        in>>n;
        obiect.nume = n;
        in>>obiect.salariu;
        char* dep = new char[100];
        in>>dep;
        obiect.departament = dep;
        in>>obiect.sectie;

        return in;
    }

    template <class U>
    friend ostream& operator << (ostream& out, directorExecutiv<U> &obiect)
    {
        out << "Nume: " << obiect.nume << ", ";
        out << " ";
        out <<"salariu: "<< obiect.salariu;
        out << ", departament: " << obiect.departament;
        out <<", sectia: "<< obiect.sectie;
        out << "\n";

        return out;
    }

};

#endif // DIRECTOREXECUTIV_H_INCLUDED
