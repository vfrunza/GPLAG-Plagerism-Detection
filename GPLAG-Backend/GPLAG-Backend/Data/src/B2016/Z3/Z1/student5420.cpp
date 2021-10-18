/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    public:
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
  void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3; }
  void Postavi(int indeks, const Tacka &t); 
  static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) { if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)-t3.first*(t1.second-t2.second))>0) return 1; else return -1; }
  Tacka DajTjeme(int indeks) const;
  double DajStranicu(int indeks) const;
  double DajUgao(int indeks) const;
  Tacka DajCentar() const {    return std::make_pair((t1.first+t2.first+t3.first)/3, (t1.second+t2.second+t3.second)/3); }
  double DajObim() const { double a=DajStranicu(1), b=DajStranicu(2), c=DajStranicu(3); return a+b+c; }
  double DajPovrsinu() const; //{ return fabs(Orijentacija(Trougao::t1, Trougao::t2, Trougao::t3)); }
  bool DaLiJePozitivnoOrijentiran() const { return Orijentacija(Trougao::t1, Trougao::t2, Trougao::t3); }
 // bool DaLiJeUnutra(const Tacka &t) const;
  void Ispisi() const { std::cout << "((" << t1.first << "," << t1.second << ") , (" << t2.first << "," << t2.second << ") , (" << t3.first << "," << t3.second <<"))"; }
  void Transliraj(double delta_x, double delta_y) {Trougao::t1.first+=delta_x; Trougao::t1.second+=delta_y; Trougao::t2.first+=delta_x; Trougao::t2.second+=delta_y; Trougao::t3.first+=delta_x; Trougao::t3.second+=delta_y; }
  void Centriraj(const Tacka &t) { Tacka tjeme=DajCentar(); double delta_x=t.first-tjeme.first, delta_y=t.second-tjeme.second; Transliraj(delta_x, delta_y); }
  void Rotiraj(const Tacka &t, double ugao);
  void Skaliraj(const Tacka &t, double faktor);
  void Rotiraj(double ugao);
  void Skaliraj(double faktor);
  friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
  friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if((t1.first == t2.first && t1.first == t3.first) || (t1.second == t2.second && t2.second == t3.second)) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
}

void Trougao::Postavi(int indeks, const Tacka &t) {
    if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
    else if(indeks==1) Trougao::t1=t;
    else if(indeks==2) Trougao::t2=t;
    else Trougao::t3=t;
}

Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
    else if(indeks==3) return Trougao::t3;
    else if(indeks==2) return Trougao::t2;
    else return Trougao::t1;
}

double Trougao::DajStranicu(int indeks) const {
    if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
    if(indeks==1) {
        return std::sqrt(std::pow((t3.first-t2.first), 2) + std::pow((t3.second-t2.second),2));
    }
    else if(indeks==2) {
        return std::sqrt(std::pow((t3.first-t1.first), 2) + std::pow((t3.second-t1.second),2));

    }
    else {
        return std::sqrt(std::pow((t1.first-t2.first), 2) + std::pow((t1.second-t2.second),2));
    }
    return 0;
}

double Trougao::DajUgao(int indeks) const {
    if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
    double a=std::sqrt(std::pow((t3.first-t2.first), 2) + std::pow((t3.second-t2.second),2));
    double b=std::sqrt(std::pow((t3.first-t1.first), 2) + std::pow((t3.second-t1.second),2));
    double c=std::sqrt(std::pow((t1.first-t2.first), 2) + std::pow((t1.second-t2.second),2));
    if(indeks==1) {
        return std::acos((b*b+c*c-a*a)/(2*b*c));
    }
    else if(indeks==2) {
        return std::acos((a*a+c*c-b*b)/(2*a*c));
    }
    else return std::acos((a*a+b*b-c*c)/(2*a*b));
}


int main ()
{
    std::cout << "valja";
	return 0;
}



