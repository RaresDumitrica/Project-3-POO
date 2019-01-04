#ifndef ANGAJAT_H
#define ANGAJAT_H

#include <iostream>
#include <typeinfo>
#include <string.h>

using namespace std;

//template <class T> class administrator;

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



    friend istream& operator>> (istream &in, angajat <T> &obiect)
    {
        cout<<"Numele anagajatului: ";
        char* n = new char[100];
        in>>n;
        obiect.nume = n;
        cout << "\n salariul angajatului: ";
        in>>obiect.salariu;

        return in;
    }


    friend ostream& operator<< (ostream &out, angajat <T> &obiect)
    {
        out << "Nume: " << obiect.nume << ", ";
        out << " ";
        out <<"salariu: "<< obiect.salariu;

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
