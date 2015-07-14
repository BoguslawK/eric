#include <iostream>

#include "zadanie3.hpp"

using namespace std;

int main()
{
    Lista l = Lista();
    l.glowa = NULL;
    l.ogon = NULL;
    l.ilosc = 0;

    dodaj_glowe(&l, 77);

    print(&l);

    dodaj_glowe(&l, 66);
    dodaj_glowe(&l, 55);
    print(&l);

    dodaj_ogon(&l, 44);

    print(&l);

    Element *e55 = znajdz_element(&l, 55);

    cout << "szukam 55";
    print(e55);

    Element *s2 = znajdz_element(&l, 66666);


    cout << "usuwam 55.";
    if(usun_element(&l,e55)){
        cout << "Po usunieciu:";
        print(&l);
    }else{
        cerr << "Blad podczas usuwania elementu z listy!";
    }

}
