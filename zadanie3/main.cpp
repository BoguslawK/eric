#include <iostream>

#include "zadanie3.hpp"

using namespace std;

int main()
{
    Element e1;
    e1.skrzynka = 666;

    Element e2;
    e2.skrzynka = 777;

    Lista l;

    add_head(&l, &e2);

    print(&l);

    add_head(&l, &e1);

    print(&l);
}
