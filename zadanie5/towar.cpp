
#include"towar.hpp"

int Towar::ile = 0;

int Towar::ilosc_towaru() const
    {
        int i = 1;
        const Towar *t = this;
        while (t->next)
        {
            i++;
            t = t->next;
        }
        return i;
    }

Towar::Towar(const Towar &t)
    {
        Towar::ile++;
        nr = t.nr;

        if (t.next)
        {
            next = new Towar(*t.next);
        }
        else
        {
            next = NULL;
        }

    }

Towar::Towar(int n)
    {
        Towar::ile++;
        nr = n;
        next = NULL;
        std::cout << "zrobione pudlo " << n <<  std::endl;
    }

void Towar::dodaj(Towar *nowy)
    {
        Towar *tmp = this;
        while (tmp->next) tmp = tmp->next;
        tmp->next = nowy;
    }

void Towar::wypis()
    {
         std::cout << "jestem pudlo nr. " << nr << "\tmoj adres to:\t" << this <<  std::endl;
    }

int Towar::wypiszwszystko()
    {
        int i = 0;
        Towar *tmp = this;
        while (tmp) {
            tmp->wypis();
            tmp = tmp->next;
            ++i;
        }
        return i;
    }

bool Towar::operator==(const Towar &t)
    {


        if(nr != t.nr) return false;
        if(ilosc_towaru() != t.ilosc_towaru()) return false;

        const Towar *t1 = next;
        const Towar *t2 = t.next;
        //sa tego samego rozmiaru:
        while(t1 && t2)
        {
            if(t1->nr != t2->nr) return false;

            t1 = t1->next;
            t2 = t2->next;
        }
        return true;
    }

bool Towar::operator!=(const Towar &t)
    {
        return !(*this == t);
    }

