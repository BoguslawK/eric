#ifndef zadanie3_hpp
#define zadanie3_hpp

struct Element {
    int skrzynka;
    Element* next;
};

struct Lista {
    int ilosc;
    Element *glowa, *ogon;
};

void dodaj_glowe(Lista*,int);
void dodaj_ogon(Lista*,int);

Element* znajdz_wartosc(Lista*,int);

void print(Lista*);
void print(Element*);
void printnext(Element*);

Lista init();
#endif