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

void add_head(Lista*,int skrzynka);

void print(Lista*);
void print(Element*);
void printnext(Element*);

Lista init();
#endif