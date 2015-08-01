
#include "obiektLista.hpp"
#include <iostream>

void Lista::dodaj_glowe(int skrzynka)
{

    Element *e = new Element;

    e->next = NULL;
    e->skrzynka = skrzynka;

    if(this->ilosc > 0)
    {
        e->next = this->glowa;
    }
    this->glowa = e;

    if(this->ogon == NULL)
    {
        this->ogon = e;
    }

    this->ilosc++;
}


void Lista::dodaj_ogon(int skrzynka)
{
    Element *e = new Element;

    e->skrzynka = skrzynka;
    e->next = NULL;

    if(this->ilosc > 0 && this->ogon)
    {
        //Element* tail = this->ogon;
        if(this->ogon->next == NULL)
        {
            this->ogon->next = e;
        }
        else
        {
            std::cerr << "ERR: next ogona powinno byc NULL!";
        }
    }
    this->ogon = e;

    if(this->glowa == NULL)
    {
        this->glowa = e;
    }

    this->ilosc++;

}

Element* Lista::znajdz_element(int x)
{
    Element* e = this->glowa;

    while(e != NULL)
    {
        if(e->skrzynka == x) return e;
        e = e->next;
    }
    //std::cout << std::endl << "Nie znaleziono elementu: " << x << std::endl;
    return NULL;
}

bool Lista::usun_element(Element* usun)
{
	Element *e = this->glowa;

	if(usun == this->glowa)
	{
        this->glowa = e->next;
        usun->next = NULL; //bez NULL destruktor mogłby usuwać losowe el. wskaznika
		delete usun;
        this->ilosc--;
		return true;
	}

	while(e != NULL)
	{
		if(e->next == usun)
		{
			e->next = usun->next;
            usun->next = NULL;
			delete usun;
            this->ilosc--;
			return true;
		}
		e = e->next;
	}
	return false;
}

void Lista::sort()
{
    sort(&(this->glowa));
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

void Element::print()
{
    std::cout << " Element[adres="<< this <<" skrzynka='" << this->skrzynka << "' next="<< this->next<<"]" << std::endl;
}

void Lista::print()
{
    if(this->glowa != NULL){
        std::cout << std::endl<< "Lista("<< this->ilosc <<")[" << std::endl;

        Element* e = this->glowa;

        while(e != NULL)
        {
            e->print();
            e = e->next;
        }

        std::cout << "]" << std::endl ;
    }else{
        std::cout << std::endl<< "Lista[-pusta-]" << std::endl;
    }

}
