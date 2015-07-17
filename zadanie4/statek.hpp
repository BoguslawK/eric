#ifndef statek_hpp
#define statek_hpp

#include "statki.hpp"

class Statek{
    private:
        int size;
        bool destroyed;
        int hit_fields;
    public:
        int get_size();
        int hit();
        bool is_hit();
        Statek(int);
};

#endif