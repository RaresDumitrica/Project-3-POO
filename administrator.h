#ifndef ADMINISTRATOR_H_INCLUDED
#define ADMINISTRATOR_H_INCLUDED

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
    administrator() : angajat<T>()
    {
        sectie = -1;
    }
    administrator(char* n , T sal, int sec) : angajat<T>(n, sal)
    {
        sectie = sec;
    }
    administrator(administrator <T> &obiect) : angajat<T>(obiect)
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
        in>>(*(dynamic_cast<angajat<T>*>(&obiect)));
        cout<< "\n sectia angajatului: ";
        in>>obiect.sectie;

        return in;
    }

    template <class U>
    friend ostream& operator << (ostream& out, administrator <U> &obiect)
    {
        out << (*(dynamic_cast<angajat<T>*>(&obiect)));
        out <<", sectia: "<< obiect.sectie;
        out << "\n";
    }

    //  Bunicu::afisare();
    //cout<<"TheBeatles\n"
     //afisare()


};

#endif // ADMINISTRATOR_H_INCLUDED
