//nazwa
//autor
//sprawdzil

#include <iostream>

using namespace std;

class Towar{
  int nr;
  Towar *next;

public:
    Towar(const Towar &t)
    {
        nr = t.nr;

        if(t.next){
            next = new Towar(*t.next);
        }else{
            next = NULL;
        }

    }

  Towar(int n)
  {
    nr=n;
    next=NULL;
    cout << "zrobione pudlo "<< n <<endl;
  }

  ~Towar()
   {
     cout << "usuwam pudlo nr. " << this->nr << endl;
       if(next){
           delete next;
       }
   }

  void dodaj(Towar *nowy)
  {
      Towar *tmp = this;
      while (tmp->next) tmp = tmp->next;
      tmp->next = nowy;
  }

   void wypis()
   {
       cout <<"jestem pudlo nr. " << nr << "\tmoj adres to:\t" << this<< endl;
   }

   int wypiszwszystko()
   {
       int i=0;
      Towar *tmp = this;
      while (tmp)
      {
        tmp->wypis();
        tmp = tmp->next;
        ++i;
      }
      return i;
   }

};

class Paczka{
 unsigned a,b,c;

 Towar *pudlo;

 public:
 Paczka()
   {
     a=b=c=1;
     pudlo = new Towar(0);
     cout << "paczka gotowa " <<endl;

   }

    Paczka(const Paczka &p)
    {
        a = p.a;
        b = p.b;
        c = p.c;

        pudlo = new Towar(*p.pudlo);
    }

    ~Paczka()
    {
        delete pudlo;
    }

  void dodaj(int n)
  {
      Towar *dodany = new Towar(n);
      pudlo->dodaj(dodany);
  }

  void wypis()
  {
      cout << "moj adres to: " << this << endl;
      cout << "wymiary: " << a <<'x'<< b << 'x' << c  << "\nzawartosc od adresu:\t\t\t" << pudlo <<endl;
      int i= pudlo->wypiszwszystko();
      cout << "razem " << i << "pudel w paczce" << endl;


  }
};


int main() {

    Paczka pp;
    pp.dodaj(2);
    pp.dodaj(5);
    pp.dodaj(-3);

    cout << endl << ">>> pierwsza paczka 'pp' 2,5,-3:" << endl;
    pp.wypis();

    Paczka qq=pp;

    cout << endl << ">>> druga paczka 'qq', kopia 2,5,-3:" << endl;
    qq.wypis();

    qq.dodaj(11);

    cout << endl << ">>> pierwsza paczka pp po dodaniu 11 do qq:" << endl;
    pp.wypis();
	return 0;
}


