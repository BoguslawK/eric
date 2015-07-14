//#include "Ch6_proby.hpp"

#include <iostream>
#include <sstream>
#include <regex>

float Suma(float a,float b)
{
    return(a+b);
}
float Roznica(float a,float b)
{
    return(a-b);
}
float Iloczyn(float a,float b)
{
    return(a*b);
}
void Modulo(int a,int b,int* wynik,int* reszta)
{

     if(b!=0)
    {
        *wynik = a/b;
        *reszta = a%b;
    }
    else
    {
    std::cerr<<"Modulo  "<<"Dzielnik nie może być zerem"<<std::endl;
    }
}
float Min(float a,float b,float c)
{
        if(a <= b)
        {
          if(a <= c)
          {
            return a;
          }
          else
          {
            return c;
          }
        }
        else if(b <= c)
        {
            return b;
        }
        else
        {
            return c;
        }
}
float Max(float a,float b,float c)
{
        if(a >= b)
        {
            if(a >= c)
            {
                return a;
            }
            else
            {
                return c;
            }
        }
        else if(b >= c)
        {
            return b;
        }
        else
        {
            return c;
        }
}

void Swap(float* a,float* b)
{
        float tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
}

void Swap(int* a,int* b)
{
        int tmp;
        tmp = *a;
        *a = *b;
        *b = tmp;
}

void Sort2(float* a,float* b)
{
        if(*a > *b) Swap(a, b);

}
        void Sort3(float* a,float* b,float* c)
{
        Sort2(a, b);
        Sort2(a, c);
        Sort2(b, c);
}
void Sort4(float* a,float* b,float* c,float* d)
{
        Sort3(a, b, c);
        Sort2(c, d);
        Sort3(a, b, c);
}



bool sprawdz(std::string line,float* out)
{
    std::regex input_validator_regexp = std::regex("[0-9\\-\\.]+");

    if(std::regex_match(line,input_validator_regexp)){
        std::stringstream ss;
        float x;
        ss << line;
        ss >> x;

        if(ss.fail()){
            std::cerr << std::endl << "Błąd!! Niepoprawny format danych wejściowych: '" << line << "'" << std::endl;
            return false;
        }else{
            Swap(out,&x);
            return true;
        }
    }{
        std::cerr << std::endl << "Błąd!! Niepoprawny format danych wejściowych: '" << line << "'" << std::endl;
        return false;
    }
}

bool sprawdz(std::string line,int* out)
{
    std::regex input_validator_regexp = std::regex("[0-9\\-]+");

    if(std::regex_match(line,input_validator_regexp)){
        std::stringstream ss;
        int x;
        ss << line;
        ss >> x;

        if(ss.fail()){
            std::cerr << std::endl << "Błąd!! Niepoprawny format danych wejściowych, tylko liczby całkowite: '" << line << "'" << std::endl;
            return false;
        }else{
            Swap(out,&x);
            return true;
        }
    }{
        std::cerr << std::endl << "Błąd!! Niepoprawny format danych wejściowych, tylko liczby całkowite: '" << line << "'" << std::endl;
        return false;
    }
}

bool sprawdz(std::string a,std::string b,float* fa,float* fb)
{
    return sprawdz(a,fa) && sprawdz(b,fb);
}

bool sprawdz(std::string a,std::string b,std::string c, float* fa,float* fb,float* fc)
{
    return sprawdz(a,fa) && sprawdz(b,fb) && sprawdz(c,fc);
}

bool sprawdz(std::string a,std::string b,int* fa,int* fb)
{
    return sprawdz(a,fa) && sprawdz(b,fb);
}