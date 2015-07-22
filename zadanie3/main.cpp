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

    Element *e66 = znajdz_element(&l, 66);

    cout << "szukam 66";
    print(e66);

    znajdz_element(&l, 66666);


    cout << "usuwam 66.";
    if(usun_element(&l,e66)){
        cout << " Po usunieciu:";
        print(&l);
    }else{
        cerr << "Blad podczas usuwania elementu z listy!";
    }

    cout << "Dodaje elementy w randomowej kolejnosci:";

    dodaj_ogon(&l,1231);
    dodaj_ogon(&l,2);
    dodaj_ogon(&l,13);
    dodaj_ogon(&l,8);
    dodaj_ogon(&l,4);
    dodaj_ogon(&l,18);

    print(&l);

    cout << "Sortuje:";

    sort(&l);
    print(&l);
}
