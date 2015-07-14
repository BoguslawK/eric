#include <iostream>

#include "zadanie3.hpp"

using namespace std;

int main()
{
    Lista l;
    l.glowa = NULL;
    l.ogon = NULL;
    l.ilosc=0;


    add_head(&l, 777);
    cout << "JEDEN ELEMENT (777): " << endl;
    //print(&l);
    //print(&l);

    add_head(&l, 666);

    cout << "DWA: 777,666: " << endl;

    print(&l);

}
