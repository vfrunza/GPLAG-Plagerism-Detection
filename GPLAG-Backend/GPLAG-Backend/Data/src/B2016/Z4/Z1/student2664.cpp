/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>

typedef std::pair<double,double> Tacka;

class Trougao {
  double x,y;
  public:
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
      if( Orijentacija(t1,t2,t3) = 0) throw std::domain_error("Nekorektne pozicije tjemena");
  }
  void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
      
  }
  void Postavi(int indeks, const Tacka &t1) {
      if (indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
  }
  static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
  Tacka DajTjeme(int indeks) const;
  double DajStranicu(int indeks) const;
  double DajUgao (int indeks) const;
  Tacka DajCentar() const;
  double DajObim() const;
  double DajPovrsinu() const;
  bool DaLiJePozitivnoOrijentiran() const;
  bool DaLiJeUnutra(const Tacka &t) const;
  void Ispisi() const;
  void Transliraj(double delta_x, double delta_y);
  void Centriraj(const Tacka &t);
  void Rotiraj(const Tacka &t, double ugao);
  void Skaliraj(const Tacka &t, double faktor);
  friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double x1,y1,x2,y2,x3,y3;
    if (( x1*(y2 - y3) - x2*(y1 - y3) - x3*(y1 - y2)) > 0) return 1;
    else if ( (x1*(y2 - y3) - x2*(y1 - y3) - x3*(y1 - y2)) < 0) return -1;
    //else if ( (x1*(y2 - y3) - x2*(y1 - y3) - x3*(y1 - y2)) = 0) return 0;  //greska
}
int main ()
{
	return 0;
}