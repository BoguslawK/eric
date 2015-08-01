
#ifndef obiektLista_hpp
#define obiektLista_hpp

#include <iostream>

struct Element
{

    int skrzynka;
    Element* next;

    ~Element()
    {
        if(next) delete next; // usuniecie nastepnego elementu do ogona
    }
};


class Lista //struct Lista
{
    public:
    int ilosc;
    Element *glowa, *ogon;

    Lista()
    {
    glowa = NULL;
    ogon = NULL;
    }

    ~Lista()
    {
        delete glowa; // ogon powinien byc usuniety przez destruktor w strukturze Element
    }

void dodaj_glowe(Lista*,int);
void dodaj_ogon(Lista*,int);

// Element* znajdz_element(Lista*,int);
bool usun_element(Lista*, Element*);

void print(Lista*);
void print(Element*);
void sort(Lista*);
void sort(Element**);


};
Element* znajdz_element(Lista*,int);

/*
void dodaj_glowe(Lista*,int);
void dodaj_ogon(Lista*,int);

Element* znajdz_element(Lista*,int);
bool usun_element(Lista*, Element*);

void print(Lista*);
void print(Element*);
void sort(Lista*);
void sort(Element**);

Lista init();
*/
#endif
