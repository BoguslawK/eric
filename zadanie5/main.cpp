//nazwa
//autor
//sprawdzil

#include <iostream>
#include "paczka.hpp"

using namespace std;

int main() {

    // Paczka *p1 = new Paczka();
    // Paczka *p2 = new Paczka();
    Paczka p1,p2;
    int input,menu;

    while(menu != 11) {
        cout << endl << "-----------------------------------------------------------" << endl;
        cout << "1) Wyswietlenie paczki 1" << endl;
        cout << "2) Wyswietlenie paczki 2" << endl;
        cout << "3) Dodawanie elementu o podanej wartosci do paczki 1" << endl;
        cout << "4) Dodawanie elementu o podanej wartosci do paczki 2" << endl;
        cout << "5) Wypisanie sumy paczek 1 i 2" << endl;
        cout << "6) Przypisanie paczki 2 do 1 (konstruktor kopiujacy p1=p2)" << endl;
        cout << "7) Przypisanie paczki 1 do 2 (konstruktor kopiujacy p2=p1)" << endl;
        cout << "8) Porównanie paczek 1 i 2 (p1==p2)" << endl;
        cout << "9) Wypisanie ilości instancji paczek (zmienna statyczna)" << endl;
        cout << "10) Wypisanie ilości instancji towarów (zmienna statyczna)" << endl;
        cout << "11) Wyjście" << endl;
        cout << "===========================================================" << endl;

        cin >> menu;

        switch(menu){
            case 1:
                p1.wypis();
                break;
            case 2:
                p2.wypis();
                break;
            case 3:
                cout  << "  > Wartość: ";

                cin >> input;
                p1.dodaj(input);
                break;
            case 4:
                cout  << "  > Wartość: ";

                cin >> input;
                p2.dodaj(input);
                break;
            case 5:
                cout << "  Suma paczek 1 i 2: " << endl;
                (p1 + p2).wypis();
                break;
            case 6:
                p1 = p2;
                break;
            case 7:
                p2 = p1;
                break;
            case 8:
                cout << "  Paczka 1 == 2 ?: " << (p1 == p2) << endl;
                break;
            case 9:
                cout << "  Ilość instancji clasy Paczka: " << Paczka::ile << endl;;
                break;
            case 10:
                cout << "  Ilość instancji clasy Towar: " << Towar::ile << endl;;
                break;
        }
    }
}


