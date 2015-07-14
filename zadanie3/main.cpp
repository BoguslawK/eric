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
}
