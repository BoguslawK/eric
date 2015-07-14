#include <iostream>

#include "Ch6_proby.hpp"

using namespace std;

int main()
{
    char const *FINISH = "quit";
    string line;

    do{
        cout << endl << "Wpisz wybraną operację:" << endl;
        cout << "'Min','Max','Suma','Roznica','Iloczyn','Modulo','Sort2','Sort3','Sort4''Swap' lub '"<< FINISH <<"' aby zakończyć!" << endl;

        cin >> line;

        if(line == "Min")
        {
            float a,b,c;
            cout <<"Min"<<"Podaj trzy liczby oddzielone spacją: ";
            cin >> a >> b >> c;
            cout <<"Najmniejsza liczba to: "<<Min(a,b,c);
        }
        else if(line == "Max")
        {
            float a,b,c;
            cout <<"Max "<<" Podaj trzy liczby oddzielone spacją: ";
            cin >> a >> b >> c;
            cout <<"Najwieksza liczba to: "<<Max(a,b,c);
        }
        else if(line == "Suma")
        {
            float a,b;
            string sa,sb;
            cout <<"Suma.  "<<"Podaj dwie liczby oddzielone spacją: ";
            cin >> sa >> sb;

            if(sprawdz(sa,sb,&a,&b)){
                cout<< endl << "Suma podanych liczb to: " << Suma(a,b)<<endl;
            }
        }
        else if(line == "Roznica")
        {
            float a,b;
            cout <<"Roznica.  "<<"Podaj dwie liczby oddzielone spacją: ";
            cin >> a >> b;
            cout<< endl << "Roznica podanych liczb to: " << Roznica(a,b)<<endl;
        }
        else if(line == "Iloczyn")
        {
            float a,b;
            cout <<"Iloczyn.  "<<"Podaj dwie liczby oddzielone spacją: ";
            cin >> a >> b;
            cout<< endl << "Iloczyn podanych liczb to: " << Iloczyn(a,b)<<endl;
        }
        else if(line == "Modulo")
        {
            int a,b,wynik,reszta;
            cout <<"Modulo.  "<<"Podaj dwie liczby CAŁKOWITE! oddzielone spacją: ";
            cin >> a >> b;
            Modulo(a,b,&wynik,&reszta);
            cout << "Wynik to: "<<wynik<<" Reszta to: "<<reszta;
        }
        else if(line == "Sort2")
        {
            float a,b;
            cout <<"Sort2.  "<<"Podaj dwie liczby oddzielone spacją: ";
            cin >> a >> b;
            Sort2(&a,&b);
            cout<<"Posortowane liczby, od najmniejszej do największej: " << a <<","<< b <<endl;
        }
        else if(line == "Sort3")
        {
            float a,b,c;
            cout <<"Sort3.  "<<"Podaj trzy liczby oddzielone spacją: ";
            cin >> a >> b >> c;
            Sort3(&a,&b,&c);
            cout<<"Posortowane liczby, od najmniejszej do największej: " << a <<","<< b <<","<<c<<endl;
        }
        else if(line == "Sort4")
        {
            float a,b,c,d;
            cout <<"Sort4.  "<<"Podaj cztery liczby oddzielone spacją: ";
            cin >> a >> b >> c >> d;
            Sort4(&a,&b,&c,&d);
            cout<<"Posortowane liczby, od najmniejszej do największej: " << a <<","<< b <<","<< c <<","<< d <<endl;
        }
        else if(line == "Swap")
        {
            float a,b;
            cout <<"Swap.  "<<"Podaj dwie liczby oddzielone spacją: ";
            cin >> a >> b;
            Swap(&a,&b);
            cout<<"Liczby zamienione wartościami, pierwsza: "  << a <<", druga: "<< b <<endl;
        }
        else if(line == FINISH)
        {
            cout << endl << "Bye!" << endl;
        }
        else
        {
            cerr << endl << "!! Nieprawidłowa komenda: '" << line << "'" << endl;
        }

    }
    while(line != FINISH);

    return 0;
}
