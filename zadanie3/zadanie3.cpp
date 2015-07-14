#include "zadanie3.hpp"
#include <iostream>

void dodaj_glowe(Lista* l,int skrzynka)
{
    Element *e = new Element;

    e->skrzynka = skrzynka;
    e->next = NULL;

    if(l->ilosc > 0){
        Element* head = l->glowa;
        if(head->next == NULL){
            head->next = e;
        }
    }
    l->glowa = e;

    if(l->ogon == NULL){
        l->ogon = e;
    }

    l->ilosc++;
}


/* ------ PRINT ------ */

void print(Element* e)
{
    std::cout << " Element[skrzynka='" << e->skrzynka << "']" << std::endl;
}

void print(Lista* l)
{
    if(l->ogon != NULL){
        std::cout << std::endl<< "Lista("<< l->ilosc <<")[" << std::endl;

        printnext(l->ogon);

        std::cout << "]" << std::endl ;
    }else{
        std::cout << std::endl<< "Lista[-pusta-]" << std::endl;
    }

}

void printnext(Element* e)
{
    if(e == NULL){
        std::cout << " Element[NULL]";
    }else if(e->next == NULL){
        print(e);
    }else{
        print(e);
        printnext(e->next);
    }
}


