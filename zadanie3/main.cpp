#include <iostream>

#include "zadanie3.hpp"

int main()
{
    Element e1;
    e1.skrzynka = 666;

    Element e2;
    e2.skrzynka = 777;

    Lista l;

    std::cout << "ADD_HEAD: 777,666: " << std::endl;
    add_head(&l, &e2);
    add_head(&l, &e1);

    print(&l);
}
