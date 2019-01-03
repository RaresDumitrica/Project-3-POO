include <iostream>
#include<typeinfo>
#include "angajat.h"

using namespace std;

int main()
{
    angajat <double> ob1("Alin", 20.35), ob2, ob3;
    ob2 = ob3 = ob1;
    //cout << ob1 << endl << ob2 << endl << ob3;
   ob1.afisare();
ob2.afisare();}

