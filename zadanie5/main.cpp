//nazwa
//autor
//sprawdzil

#include <iostream>

using namespace std;

class Towar {

private:
    int nr;
    Towar *next;


    int ilosc_towaru() const {
        int i = 1;
        const Towar *t = this;
        while (t->next) {
            i++;
            t = t->next;
        }
        return i;
    }

public:
    Towar(const Towar &t) {
        nr = t.nr;

        if (t.next) {
            next = new Towar(*t.next);
        } else {
            next = NULL;
        }

    }

    Towar(int n) {
        nr = n;
        next = NULL;
        cout << "zrobione pudlo " << n << endl;
    }

    ~Towar() {
        cout << "  ~usuwam pudlo nr. " << this->nr << " pod adresem " << this << endl;
        if (next) {
            delete next;
        }
    }

    void dodaj(Towar *nowy) {
        Towar *tmp = this;
        while (tmp->next) tmp = tmp->next;
        tmp->next = nowy;
    }

    void wypis() {
        cout << "jestem pudlo nr. " << nr << "\tmoj adres to:\t" << this << endl;
    }

    int wypiszwszystko() {
        int i = 0;
        Towar *tmp = this;
        while (tmp) {
            tmp->wypis();
            tmp = tmp->next;
            ++i;
        }
        return i;
    }

    bool operator==(const Towar &t){
        int s1 = ilosc_towaru();
        int s2 = t.ilosc_towaru();
//        cout << ",rozmiar t1 " << s1;
//        cout << ",rozmiar t2 "<< s2;

        if(nr != t.nr) return false;
        if(ilosc_towaru() != t.ilosc_towaru()) return false;

        const Towar *t1 = next;
        const Towar *t2 = t.next;
        //sa tego samego rozmiaru:
        while(t1 && t2){
            if(t1->nr != t2->nr) return false;

            t1 = t1->next;
            t2 = t2->next;
        }
        return true;
    }

    bool operator!=(const Towar &t) {
        return !(*this == t);
    }

};

class Paczka {
    unsigned a, b, c;

    Towar *pudlo;


public:
    Paczka() {
        a = b = c = 1;
        pudlo = new Towar(0);
        cout << "paczka gotowa " << endl;

    }

    Paczka(const Paczka &p) {
        a = p.a;
        b = p.b;
        c = p.c;

        pudlo = new Towar(*p.pudlo);
    }

    ~Paczka() {
        delete pudlo;
    }

    void dodaj(int n) {
        Towar *dodany = new Towar(n);
        pudlo->dodaj(dodany);
    }

    void wypis() {
        cout << "moj adres to: " << this << endl;
        cout << "wymiary: " << a << 'x' << b << 'x' << c << "\nzawartosc od adresu:\t\t\t" << pudlo << endl;
        int i = pudlo->wypiszwszystko();
        cout << "razem " << i << "pudel w paczce" << endl;


    }

    Paczka operator+(Paczka &p) {
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

    Paczka &operator=(const Paczka &p) {
        if (this != &p) {
            a = p.a;
            b = p.b;
            c = p.c;

            delete pudlo;
            pudlo = new Towar(*(p.pudlo));
        }
        return *this;
    }

    bool operator==(const Paczka &p) {

        //cout << "Paczka: customory operator ==...";

        if (a != p.a) return false;
        if (b != p.b) return false;
        if (c != p.c) return false;

        if (*pudlo != *(p.pudlo)) return false;

        return true;
    }

    bool operator!=(const Paczka &p) {
        //cout << "Paczka: customory operator !=...";
        return !(*this == p);
    }
};


int main() {

    Paczka pp;
    pp.dodaj(2);
    pp.dodaj(5);
    pp.dodaj(-3);

    cout << endl << ">>> pierwsza paczka 'pp' 2,5,-3:" << endl;
    pp.wypis();

    Paczka qq = pp;

    cout << endl << ">>> druga paczka 'qq', kopia 2,5,-3:" << endl;
    qq.wypis();

    qq.dodaj(11);

    cout << endl << ">>> pierwsza paczka pp po dodaniu 11 do qq:" << endl;
    pp.wypis();


    Paczka p1;
    p1.dodaj(2);
    p1.dodaj(3);

    cout << endl << ">>> paczka p1:" << endl;
    p1.wypis();

    Paczka p2;
    p2.dodaj(5);
    p2.dodaj(6);

    cout << endl << ">>> paczka p2:" << endl;
    p2.wypis();

    Paczka p1plus2 = p1 + p2;
    cout << endl << ">>> paczka p1 + p2:" << endl;
    p1plus2.wypis();


    cout << endl << ">>> Porownujemy p1==p2 " << endl;
    cout << ( p1 == p2) << endl;

    p1 = p2;
    cout << endl << ">>> paczka p1 po przypisaniu do niej wartosci z p2" << endl;
    p1.wypis();

    cout << endl << ">>> Porownujemy p1==p2 po przypisaniu p2 do p1" << endl;
    cout << ( p1 == p2) << endl;

    return 0;
}


