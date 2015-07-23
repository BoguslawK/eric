#include <iostream>

#include "zadanie3.hpp"

using namespace std;

int main()
{
    Lista l = Lista();
    l.glowa = NULL;
    l.ogon = NULL;
    l.ilosc = 0;

    int menu=0;
    int input;
    Element *e;

    while(menu != 7) {
        cout << endl << "-----------------------------------------------------------" << endl;
        cout << "1) Wyswietlenie listy" << endl;
        cout << "2) Dodawanie elementu o podanej wartosci na koniec listy" << endl;
        cout << "3) Dodawanie elementu o podanej wartosci na poczatek listy" << endl;
        cout << "4) Znalezienie elementu o zadanej zawartosci" << endl;
        cout << "5) Posortowanie" << endl;
        cout << "6) Usuniecie elementu" << endl;
        cout << "7) Wyjście" << endl;
        cout << "===========================================================" << endl;


        cin >> menu;
        e = nullptr;

        switch(menu){
            case 1:
                print(&l);
                break;
            case 2:
                cout  << "  > Podaj wartość elementu do dodania: ";

                cin >> input;
                dodaj_ogon(&l,input);
                cout  << "  > Dodano." << endl;
                break;
            case 3:
                cout  << "  > Podaj wartość elementu do dodania: ";

                cin >> input;
                dodaj_glowe(&l,input);
                cout  << "  > Dodano." << endl;
                break;
            case 4:
                cout  << "  > Podaj wartość elementu do znalezienia: ";

                cin >> input;
                e = znajdz_element(&l, input);
                if(e){
                    cout  << "  > Znaleziony element to: " << endl;
                    print(e);
                }else{
                    cout  << "  > Nie znaleziono elementu dla wartosci " << input << endl;
                }
                break;
            case 5:
                sort(&l);
                cout  << "  > Posortowano." << endl;
                break;
            case 6:
                cout  << "  > Podaj wartość elementu do usunięcia: ";

                cin >> input;
                e = znajdz_element(&l, input);

                if(e){
                    if(usun_element(&l, e)){
                        cout  << "  > Usunieto." << endl;
                    }else{
                        cerr  << "  ! Wystąpił błąd podczas usuwania elementu "<< input << endl;
                    }
                }else{
                    cout  << "  > Nie znaleziono elementu dla wartosci " << input << endl;
                }
                break;
        }


    }
}
