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
        Element* e = l->ogon;


        for(int i=0;i<l->ilosc;i++)
        {
            print(e);
            e = e->next;
        }

        std::cout << "]" << std::endl ;
    }else{
        std::cout << std::endl<< "Lista[-pusta-]" << std::endl;
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

