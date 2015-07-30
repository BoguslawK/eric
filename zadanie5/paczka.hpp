
#ifndef PACZKA_HPP
#define PACZKA_HPP

#include <iostream>
#include "towar.hpp"

class Paczka
{
    unsigned a, b, c;
    Towar *pudlo;
    

public:
    static int ile;
    Paczka();
    Paczka(const Paczka &p);

    ~Paczka()
    {
        ile--;
        delete pudlo;
    }

    void dodaj(int n);
    void wypis();
    Paczka operator+(Paczka &p);
    Paczka operator=(const Paczka &p);
    bool operator==(const Paczka &p);
    bool operator!=(const Paczka &p);

};

#endif
