#include "zadanie3.hpp"
#include <iostream>

void dodaj_glowe(Lista* l,int skrzynka)
{

    Element *e = new Element;

    e->skrzynka = skrzynka;

    if(l->ilosc > 0){
        e->next = l->glowa;
    }
    l->glowa = e;

    l->ilosc++;
}


void dodaj_ogon(Lista* l,int skrzynka)
{
    Element *e = new Element;

    e->skrzynka = skrzynka;
    e->next = NULL;

    if(l->ilosc > 0){
        Element* tail = l->ogon;
        if(tail->next == NULL){
            head->next = e;
        }
    }
    l->tail = e;

    if(l->glowa == NULL){
        l->glowa = e;
    }

    l->ilosc++;

}

Element* znajdz_wartosc(Lista* l,int x)
{
    Element* e = l->glowa;

}


/* ------ PRINT ------ */

void print(Element* e)
{
    std::cout << " Element[skrzynka='" << e->skrzynka << "']" << std::endl;
}

void print(Lista* l)
{
    if(l->glowa != NULL){
        std::cout << std::endl<< "Lista("<< l->ilosc <<")[" << std::endl;

        Element* e = l->glowa;

        while(e != NULL)
        {
            print(e);
            e = e->next;
        }

        std::cout << "]" << std::endl ;
    }else{
        std::cout << std::endl<< "Lista[-pusta-]" << std::endl;
    }

}
