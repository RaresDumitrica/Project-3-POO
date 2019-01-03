#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <iostream>
#include <typeinfo>
#include <string.h>

using namespace std;

template <class T> class administrator;

template <class T>
class angajat
{
protected:
    char* nume;
    T salariu;
public:
    angajat()
    {
        nume = NULL;
        salariu = 0;
    }
    angajat(char* n, T sal)
    {
        nume = new char[strlen(n) + 1];
        nume = n;
        salariu = sal;
    }
    angajat(angajat <T> &obiect)
    {
        nume = new char[strlen(obiect.nume)];
        salariu = obiect.salariu;
    }
    ~angajat()
    {
        free(nume);
    }

    T getSalariu()
    {
         return salariu;
    }

    void setSalariu(T sal)
    {
        salariu = sal;
    }

    char* getNume()
    {
        return nume;
    }


    template <class U>
    friend istream& operator>> (istream &in, angajat <U> &obiect)
    {
        char *n = new char[100];
        in>>n;
        obiect.nume = n;
        in>>obiect.salariu;

        return in;
    }

    template <class U>
    friend ostream& operator<< (ostream &out, angajat <U> &obiect)
    {
        out << obiect.nume;
        out << " ";
        out << obiect.salariu;

        return out;
    }

    angajat<T>& operator = (const angajat <T> &ob)
    {
        if (this == &ob)
            return *this;

        if (ob.nume != NULL)
        {
            if (nume != NULL)
                delete[] nume;

            nume = new char [strlen(ob.nume) + 1];
            strcpy (nume, ob.nume);
        }

        salariu = ob.salariu;

        return *this;
    }

    virtual void afisare()
    {
        cout << nume;
        cout << salariu;
    }

};



#endif // ANGAJAT_H

