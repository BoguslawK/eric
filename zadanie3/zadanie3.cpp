#include "zadanie3.hpp"
#include <iostream>

void dodaj_glowe(Lista* l,int skrzynka)
{

    Element *e = new Element;

    e->next = NULL;
    e->skrzynka = skrzynka;

    if(l->ilosc > 0){
        e->next = l->glowa;
    }
    l->glowa = e;

    if(l->ogon == NULL)
    {
        l->ogon = e;
    }

    l->ilosc++;
}


void dodaj_ogon(Lista* l,int skrzynka)
{
    Element *e = new Element;

    e->skrzynka = skrzynka;
    e->next = NULL;

    if(l->ilosc > 0 && l->ogon){
        Element* tail = l->ogon;
        if(tail->next == NULL){
            tail->next = e;
        }else{
            std::cerr << "ERR: next ogona powinno byc NULL!";
        }
    }
    l->ogon = e;

    if(l->glowa == NULL){
        l->glowa = e;
    }

    l->ilosc++;

}

Element* znajdz_element(Lista* l,int x)
{
    Element* e = l->glowa;

    while(e != NULL)
    {
        if(e->skrzynka == x) return e;
        e = e->next;
    }
    std::cout << std::endl << "Nie znaleziono elementu: " << x << std::endl;
    return NULL;
}

bool usun_element(Lista* l, Element* usun)
{
	Element *e = l->glowa;

	if(usun == l->glowa) {
		l->glowa = e->next;
		delete usun;
		l->ilosc--;
		return true;
	}

	while(e != NULL) {
		if(e->next == usun) {
			e->next = usun->next;
			delete usun;
			l->ilosc--;
			return true;
		}
		e = e->next;
	}
	return false;
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
