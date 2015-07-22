//nazwa
//autor
//sprawdzil

#include "chest.h"
#include <iostream>

using namespace std;
/*
int main() {
	Item item[3];
	Chest chest[3];
	chest[0].set(&item[1]);
	chest[1].set(&item[2]);
	chest[2].set(&item[0]);

	for(int c = 0; c<3;c++)
	{
		for(int i=0; i<3; i++)
		{
			bool belong = item[i].doIBelong(chest[c]);
			if ( belong )
			{
				cout<<"Item "<<i<<" belongs to chest "<<c<<endl;
				break;
			}
		}
	}

	return 0;
}

*/

class Towar{
  int nr;
  Towar *next;

public:
  Towar(int n)
  {
    nr=n;
    next=NULL;
    cout << "zrobione pudlo "<< n <<endl;
  }

  ~Towar()
   {
     cout << "usuwam pudlo nr. " << this->nr;
       delete this;
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

    pp.wypis();

    Paczka qq=pp;
    qq.wypis();

    qq.dodaj(11);
    pp.wypis();
	return 0;
}


