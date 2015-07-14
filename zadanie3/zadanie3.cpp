#include "zadanie3.hpp"
#include <iostream>
//void add_head(Lista*,Element*);

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
    if(e->next == NULL)
    {
        print(e);
    }else{
        printnext(e->next);
    }
}


void add_head(Lista* l,Element* e)
{
    if(l->glowa != NULL){
        Element* head = l->glowa;
        head->next = e;
    }
    l->glowa = e;

    if(l->ogon == NULL){
        l->ogon = e;
    }

    l->ilosc++;
}

