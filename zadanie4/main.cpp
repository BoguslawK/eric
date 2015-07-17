#include <iostream>

#include "statki.hpp"

using namespace std;

int main()
{
    Statki bs;

    bs.add_ship(4);

    int x,y;
    int proby=1;

    //bs.reveal();

    bs.print();
    bool won = false;
    while(!won){
        cout << endl << "Podaj wspolrzedne x i y oddzielone spacja:";
        cin >> y >> x;
        bs.shoot(x,y);
        bs.print();

        if(bs.won()){
            cout << endl << "!GRATULACJE! Wygrał(a|e)ś w " << proby << " próbach!"<< endl;
            won=true;
        }
        proby++;
    }
}
