#include "statek.hpp"


Statek::Statek(int s)
{
    size=s;
}

int Statek::get_size()
{
    return size;
}

bool Statek::is_hit()
{
    return hit_fields >0;
}

int Statek::hit()
{
    hit_fields++;
    if(hit_fields == size){
        destroyed = true;
        return FIELD_SHIP_DESTROYED;
    }
    return FIELD_SHIP_HIT;
}