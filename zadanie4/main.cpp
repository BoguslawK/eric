#include <iostream>

#include "statki.hpp"

using namespace std;

int main()
{
    Statki bs;

    bs.add_ship(4);
    bs.add_ship(3);
    bs.add_ship(2);
    bs.add_ship(2);
    bs.add_ship(1);
    bs.add_ship(1);
    bs.add_ship(1);

    int x,y;
    int proby=1;

    //bs.reveal();

    bs.print();
    bool won = false;
    int result;
    while(!won){
        cout << endl << "Podaj wspolrzedne x i y oddzielone spacja:";
        cin >> y >> x;
        result = bs.shoot(x,y);
        bs.print();

        if(result == FIELD_SHIP_HIT){
            cout << endl << " -- TRAFIONY! -- " << endl;
        }else if (result == FIELD_SHIP_DESTROYED){
            cout << endl << " -- ZATOPIONY! -- " << endl;
        }else {
            cout << endl << endl;
        }

        if(bs.won()){
            cout << endl << "!GRATULACJE! Wygrał(a|e)ś w " << proby << " próbach!"<< endl;
            won=true;
        }
        proby++;
    }
}
