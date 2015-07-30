#include <iostream>
#include <string>
#include "pole.hpp"



Pole::Pole()
{
    status = FIELD_EMPTY;
    ship = NULL;
}

int Pole::get_status()
{
    return status;
}

bool Pole::add_ship(Statek* s)
{
    if(status == FIELD_EMPTY){
        ship = s;
        status = FIELD_SHIP;
        return true;
    }

    std::cerr<<"Proboje dodac statek to nie pustego pola!";
    return false;
}

std::string Pole::str()
{
    switch(status){
        case FIELD_FIRED:
            return "○";
        case FIELD_SHIP_HIT:
            return "◉";
        case FIELD_SHIP_DESTROYED:
            return "▣";
    }
    return "░";
}

std::string Pole::str_reveal()
{
    switch(status){
        case FIELD_FIRED:
            return "○";
        case FIELD_SHIP_HIT:
            return "◉";
        case FIELD_SHIP:
            return "□";
        case FIELD_SHIP_DESTROYED:
            return "▣";

    }
    return "░";
}

int Pole::hit(Statki *bs)
{
    if(status == FIELD_SHIP){
        status = ship->hit();

        if(status == FIELD_SHIP_DESTROYED){
            bs->mark_destroyed(ship);
        }
    }else if(status == FIELD_EMPTY){
        status = FIELD_FIRED;
    }

    return status;
}

int Pole::mark_destroyed(Statek *s)
{
    if(ship == s){
        status = FIELD_SHIP_DESTROYED;
    }
    return status;
}

void Pole::mark_fired(Statek *s)
{
    if(status == FIELD_EMPTY || status == FIELD_FIRED){
        status = FIELD_FIRED;
    }else if(ship != s){
        std::cerr << "Błąd! Pole powinno byc puste!" << status << std::endl;
    }
}

