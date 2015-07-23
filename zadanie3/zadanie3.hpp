#ifndef zadanie3_hpp
#define zadanie3_hpp

struct Element {
    int skrzynka;
    Element* next;

    ~Element(){
        if(next) delete next;
    }
};

struct Lista {
    int ilosc;
    Element *glowa, *ogon;

    ~Lista(){
        delete glowa; // ogon powinien byc usuniety przez destruktor w strukturze Element
    }

};

void dodaj_glowe(Lista*,int);
void dodaj_ogon(Lista*,int);

Element* znajdz_element(Lista*,int);
bool usun_element(Lista*, Element*);

void print(Lista*);
void print(Element*);
void sort(Lista*);
void sort(Element**);

Lista init();
#endif