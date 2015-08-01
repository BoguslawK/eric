
#ifndef obiektLista_hpp
#define obiektLista_hpp

#include <iostream>

struct Element
{

    int skrzynka;
    Element* next;

    void print();

    ~Element()
    {
        std::cout << "  ~ usuwam element: ";
        print();

        if(next) delete next; // usuniecie nastepnego elementu do ogona
    }
};


class Lista //struct Lista
{
private:
    void sort(Element**);

public:
    int ilosc;
    Element *glowa, *ogon;

    Lista()
    {
    glowa = NULL;
    ogon = NULL;
    ilosc=0;
    }

    ~Lista()
    {
        std::cout << "  ~ usuwam listę: " << this << std::endl;
        delete glowa; // ogon powinien byc usuniety przez destruktor w strukturze Element
    }

void dodaj_glowe(int);
void dodaj_ogon(int);

Element* znajdz_element(int);
bool usun_element(Element*);

void print();
void sort();



};
#endif
