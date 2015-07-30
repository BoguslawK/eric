
#ifndef TOWAR_HPP
#define TOWAR_HPP

#include <iostream>

class Towar
{
private:

    int nr;
    Towar *next;
    int ilosc_towaru() const;

public:

    Towar(const Towar &t);
    Towar(int n);

    ~Towar()
    {
        std::cout << "  ~usuwam pudlo nr. " << this->nr << " pod adresem " << this <<  std::endl;
        if (next)
        {
            delete next;
        }
    }

    void dodaj(Towar *nowy);
    void wypis();
    int wypiszwszystko();
    bool operator==(const Towar &t);
    bool operator!=(const Towar &t);
};
#endif
