
#include "obiektLista.hpp"
#include <iostream>

void Lista::dodaj_glowe(Lista* l,int skrzynka)
{

    Element *e = new Element;

    e->next = NULL;
    e->skrzynka = skrzynka;

    if(l->ilosc > 0)
    {
        e->next = l->glowa;
    }
    l->glowa = e;

    if(l->ogon == NULL)
    {
        l->ogon = e;
    }

    l->ilosc++;
}


void Lista::dodaj_ogon(Lista* l,int skrzynka)
{
    Element *e = new Element;

    e->skrzynka = skrzynka;
    e->next = NULL;

    if(l->ilosc > 0 && l->ogon)
    {
        //Element* tail = l->ogon;
        if(l->ogon->next == NULL)
        {
            l->ogon->next = e;
        }
        else
        {
            std::cerr << "ERR: next ogona powinno byc NULL!";
        }
    }
    l->ogon = e;

    if(l->glowa == NULL)
    {
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
    //std::cout << std::endl << "Nie znaleziono elementu: " << x << std::endl;
    return NULL;
}

bool Lista::usun_element(Lista* l, Element* usun)
{
	Element *e = l->glowa;

	if(usun == l->glowa)
	{
		l->glowa = e->next;
        usun->next = NULL; //bez NULL destruktor mogłby usuwać losowe el. wskaznika
		delete usun;
		l->ilosc--;
		return true;
	}

	while(e != NULL)
	{
		if(e->next == usun)
		{
			e->next = usun->next;
            usun->next = NULL;
			delete usun;
			l->ilosc--;
			return true;
		}
		e = e->next;
	}
	return false;
}

void Lista::sort(Lista* l)
{
    sort(&(l->glowa));
}


/**
 * W przeciwieństwie do poprzedniej wersji, zamiast zamieniac wskazniki,
 * zamieniam wskazniki do wskaznikow
 * metoda 'bubble' : http://www.sorting-algorithms.com/
 */
void Lista::sort(Element** pp)
{
    // p zawsze wskazuje na glowe/head
    Element *p = *pp;
    *pp = NULL; //nullptr może być porównywane z dowolnymi typami wskaźnikowymi

    while (p)
    {
        Element **lhs = &p;
        Element **rhs = &p->next;
        bool swapped = false;

        // dopoki nie dojdziemy do konca listy (*rhs bedzie nullptr)
        while (*rhs)
        {
            if ((*rhs)->skrzynka < (*lhs)->skrzynka)
            {
                // najpierw zamieniamy elementy listy
                std::swap(*lhs, *rhs);
                // a potem zamieniamy z powrotem wskazniki do 'nastepnych'
                std::swap((*lhs)->next, (*rhs)->next);

                // przechodzimy do nastepnego:
                lhs = &(*lhs)->next;
                swapped = true;
            }
            else
            {
                // bez zmian, obydwa wskazniki o 1 w przod:
                lhs = rhs;
                rhs = &(*rhs)->next;
            }
        }

        // ostatni element do posortowanego segmentu:
        *rhs = *pp;

        // jesli zamienione, odlaczamy ostatni element, konczymy liste i przechodzimy dalej:
        if (swapped)
        {
            // bierzemy ostatni element z listy i dodajemy do wyniku:
            *pp = *lhs;
            *lhs = NULL;
        }
        else
        {
            // a jak nie zamienione, to zrobione. Nie bylo zamian, wiec lista jest posortowana
            // przypisujemy wynik i konczymy petle:
            *pp = p;
            break;
        }
    }
}

/* ------ PRINT ------ */

void Lista::print(Element* e)
{
    std::cout << " Element[adres="<<e<<" skrzynka='" << e->skrzynka << "' next="<< e->next<<"]" << std::endl;
}

void Lista::print(Lista* l)
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