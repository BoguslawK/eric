#include"paczka.hpp"

int Paczka::ile = 0;

Paczka::Paczka()
    {
        Paczka::ile++;
        a = b = c = 1;
        pudlo = new Towar(0);
         std::cout << "paczka gotowa " << std::endl;

    }

Paczka::Paczka(const Paczka &p)
    {
        Paczka::ile++;
        a = p.a;
        b = p.b;
        c = p.c;

        pudlo = new Towar(*p.pudlo);
    }

void Paczka::dodaj(int n)
    {
        Towar *dodany = new Towar(n);
        pudlo->dodaj(dodany);
    }

void Paczka::wypis()
    {
        std::cout << "moj adres to: " << this <<  std::endl;
        std::cout << "wymiary: " << a << 'x' << b << 'x' << c << "\nzawartosc od adresu:\t\t\t" << pudlo << std:: endl;
        int i = pudlo->wypiszwszystko();
        std::cout << "razem " << i << " pudla/el w paczce" <<  std::endl;
    }

Paczka Paczka::operator+(Paczka &p)
    {
        // kopia obecnej klasy:
        Paczka *pp = new Paczka(*this);

        // suma rozmiarow:
        pp->a += p.a;
        pp->b += p.b;
        pp->c += p.c;

        // kopia listy towarow z klasy dodawanej:
        Towar *nowepudlo = new Towar(*(p.pudlo));

        pp->pudlo->dodaj(nowepudlo);

        return *pp;
    }

Paczka Paczka::operator=(const Paczka &p)
    {
        if (this != &p)
        {
            a = p.a;
            b = p.b;
            c = p.c;

            delete pudlo;
            pudlo = new Towar(*(p.pudlo));
        }
        return *this;
    }

bool Paczka::operator==(const Paczka &p)
    {

        //cout << "Paczka: custom operator ==...";

        if (a != p.a) return false;
        if (b != p.b) return false;
        if (c != p.c) return false;

        if (*pudlo != *(p.pudlo)) return false;

        return true;
    }

bool Paczka::operator!=(const Paczka &p)
    {
        //cout << "Paczka: custom operator !=...";
        return !(*this == p);
    }


