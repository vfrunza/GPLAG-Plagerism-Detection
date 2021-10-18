/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>

typedef std::pair<double, double> Tacka;

class Trougao {
  Tacka a,b,c;
  public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
      if (na istom pravcu) throw std::domain_error("Nekorektne pozicije tjemena");
        a=t1; b=t2; c=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
      if (na istom pravcu) throw std::domain_error("Nekorektne pozicije tjemena");
        a=t1; b=t2; c=t3;
    }
  void Postavi(int indeks, const Tacka &t){
        
  }
  
  
  
  
};

int main ()
{
	return 0;
}