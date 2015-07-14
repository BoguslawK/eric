#include <iostream>

#include "zadanie3.hpp"

using namespace std;

int main()
{
    Lista l = Lista();

    dodaj_glowe(&l, 77);

    print(&l);

    dodaj_glowe(&l, 66);

    print(&l);


}
