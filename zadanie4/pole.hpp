#ifndef pole_hpp
#define pole_hpp

#include <string>
#include "statki.hpp"

class Statki;
class Statek;

class Pole {
    private:
        int status;
        Statek* ship;
    public:
        Pole();
        int hit(Statki *);
        bool add_ship(Statek*);
        std::string str();
        std::string str_reveal();
        int get_status();
        bool mark_destroyed(Statek*);
        void mark_fired(Statek*);
};

#endif