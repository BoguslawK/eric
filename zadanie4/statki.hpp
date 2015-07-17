#ifndef statki_hpp
#define statki_hpp

#include "pole.hpp"
#include "statek.hpp"

#define BOARD_SIZE 15
#define FIELD_EMPTY 0
#define FIELD_SHIP  1
#define FIELD_FIRED 2
#define FIELD_SHIP_HIT 3
#define FIELD_SHIP_DESTROYED 4

class Statek;
class Pole;

class Statki {
    private:
        Pole* board[BOARD_SIZE][BOARD_SIZE];
        int total_ships;
        int ships_destroyed;
        /**
         * Sprawdz czy pole jest wolne i mozna postawic element statku.
         */
        bool check_field(int,int);
    public:
        /**
         * Dodaj statek o podanej wielkosci
         */
        void add_ship(int size);
        /**
         * Sproboj ustrzelic statek
         */
        int shoot(int x,int y);
        /**
         * sprawdz czy wszystkie statki ustrzelone
         */
        bool won();

        void print();
        void print(bool);
        void reveal();

        /**
         * Zaznacz wszystkie pola danego statku jako 'zatopiony' jesli 
         * ustrzelony zostal ostatni jego element
         */
        void mark_destroyed(Statek*);

        Statki();
};
#endif