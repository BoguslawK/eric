#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "statki.hpp"


Statki::Statki()
{
    ships_destroyed=0;
    total_ships=0;
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            board[i][j] = new Pole();
        }
    }
}


bool Statki::check_field(int x,int y)
{
    //std::cout << x<<":"<<y<<std::endl;
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if(i>=0&& i<BOARD_SIZE  && j>=0 && j< BOARD_SIZE){
                if(board[i][j]->get_status() != FIELD_EMPTY) return false;
            }
        }
    }
    return true;
}

bool Statki::check_placement(int x, int y, int size, Statek *s)
{
    if(board[x][y]->get_status() == FIELD_EMPTY){
        bool ok_x = true;
        bool ok_y = true;

        for(int i=0;i < size; i++){
            ok_x = ok_x && check_field(x+i,y);
            ok_y = ok_y && check_field(x,y+i);
        }

        if(ok_x) {
            for(int j=0;j< size;j++){
                board[x+j][y]->add_ship(s);
            }
            return true;
        }else if(ok_y) {
            for(int j=0;j< size;j++){
                board[x][y+j]->add_ship(s);
            }
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}

void Statki::add_ship(int size)
{
    Statek *s = new Statek(size);
    bool added = false;
    int attempt=0;
    std::cout << "Generuję losowy statek o rozmiarze: " << size <<"...";
    while(added==false)
    {
        int x,y;
        attempt++;

        if(attempt > RANDOM_SHIP_GENERATOR_MAX_ATTEMPTS){
            std::cout << std::endl << "Nie udalo sie umiescic statku po " << RANDOM_SHIP_GENERATOR_MAX_ATTEMPTS << " losowych próbach! Szukam wolnych pol po kolei..." << std::endl;

            for(int i=0;i < BOARD_SIZE-size;i++){
                for(int j=0;j < BOARD_SIZE-size; j++){
                    if(check_placement(i,j,size, s)){
                        added=true;
                        std::cout << "ok";
                        goto exit_loop;
                    }
                }
            }

            exit_loop:
                if(!added){
                    std::cerr << std::endl << "Nie udalo sie znalezc miejsca dla statku! Zwieksz rozmiar planszy lub zmniejsz ilosc statkow!" << std::endl ;
                    exit(1);    
                }
        }else{
            srand(time(0));
            int x = rand() % (BOARD_SIZE-size);
            srand(time(0));
            int y = rand() % (BOARD_SIZE-size);

            added = check_placement(x,y,size,s);
        }

        //std::cout<< "size: "<<size<<", rand: x:" <<x<<", y:"<<y<<std::endl;
        
    }
    std::cout << "ok" << std::endl;
    total_ships++;
}

void Statki::mark_destroyed(Statek *s)
{
    ships_destroyed++;
    for(int i=0;i<BOARD_SIZE;i++){
        for(int j=0;j<BOARD_SIZE;j++){
            if(board[i][j]->mark_destroyed(s) == FIELD_SHIP_DESTROYED){
                // zaznacz pola dookola statku jako strzelone, bo nie moga sie stykac:
                for(int ii=i-1;ii<=i+1;ii++){
                    for(int jj=j-1;jj<=j+1;jj++){
                        board[ii][jj]->mark_fired(s);
                    }
                }
            }
        }
    }
}

bool Statki::won(){
    return ships_destroyed == total_ships;
}


int Statki::shoot(int x,int y){
    if(x > BOARD_SIZE +1 || y > BOARD_SIZE+1 || x<1 || y<1){
        std::cerr << std::endl<< "Niepoprawne koordynaty: " << x << " " << y << ". Musza sie zawierac pomiedzy 1 a " << BOARD_SIZE+1 << std::endl;
        return -1;
    }
    return board[x-1][y-1]->hit(this);
}

void Statki::print()
{
    print(false);
}

void Statki::reveal()
{
    print(true);
}

void Statki::print(bool reveal)
{
    std::cout << "    ";
    //
    for(int i=1;i<=BOARD_SIZE;i++)
    {
        std::cout << std::setw(3) << i ;
    }
    std::cout << std::endl << "   ┌";
    for(int i=1;i<=BOARD_SIZE;i++)
    {
        std::cout << "---";
    }
    std::cout << "-┐";

    for(int i=0;i<BOARD_SIZE;i++)
    {
        // std::setw z <iomanip> ustawia padding zeby sie nie przesuwal output
        std::cout << std::endl <<  std::setw(3) << (i+1) << "|";

        for(int j=0;j<BOARD_SIZE;j++){
            if(reveal){
                std::cout  << "  " << board[i][j]->str_reveal();
            }else{
                std::cout  << "  " << board[i][j]->str();
            }

        }
        std::cout << " |";
    }
    std::cout << std::endl << "   └";


    for(int i=0;i<BOARD_SIZE;i++){
        std::cout << "---";
    }
    std::cout << "-┘" << std::endl << std::endl;
}