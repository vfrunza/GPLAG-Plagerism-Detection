/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>

typedef std::pair<double,double> Tacka;

class Trougao{
  private:
  Tacka x,y,z;
  public:
  //Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); x=t1; y=t2; z=t3; }
  
  //void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {x=t1; y=t2; z=t3;}
  
  /*void Postavi(int indeks, const Tacka &t) {
    if(indeks!=1 || indeks!=2 || indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) x=t;
    if(indeks==2) y=t;
    z=t;
  }*/
  
  /*static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if ((x.first*(y.second-z.second)-y.first(x.second-z.second)+z.first(x.second-y.second))>0) return 1;
    if ((x.first*(y.second-z.second)-y.first(x.second-z.second)+z.first(x.second-y.second))<0) return -1;
    return 0;
  }*/
  
  //Tacka DajTjeme(int indeks) const {if(indeks!=1 || indeks!=2 || indeks!=3) throw std::range_error("Nekorektan indeks"); if(indeks==1) return x; if(indeks==2) return y; return z;}
  
  /*double DajStranicu(int indeks) const {
    if(indeks!=1 || indeks!=2 || indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return std::sqrt((y.first-z.first)*(y.first-z.first)+(y.second-z.second)*(y.second-z.second));
    if(indeks==2) return std::sqrt((x.first-z.first)*(x.first-z.first)+(x.second-z.second)*(x.second-z.second));
    return std::sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
    }*/
  
  /*double DajUgao(int indeks) const {
    if(indeks!=1 || indeks!=2 || indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return(acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
    if(indeks==2) return(acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
    return(acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
  }*/
  
  //Tacka DajCentar() const {Tacka t; t.first=(x.first+y.first+z.first)/3; t.second=(x.second+y.second+z.second)/3; return t; }
  
  //double DajObim() const {return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);}
  
  //double DajPovrsinu() const {double s(DajObim()/2); return std::sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3))); }
  
  //bool DaLiJePozitivnoOrijentiran() const {if(Orijentacija==1) return true; return false; }
  
  bool DaLiJeUnutra(const Tacka &t) const;
  
  //void Ispisi() const {std::cout<<"(("<<x.first<<","<<x.second<<") , ("<<y.first<<","<<y.second<<") , ("<<z.first<<","<<z.second<<"))"<<std::endl; }
  
  void Transliraj(double delta_x, double delta_y);
  
  void Centriraj(const Tacka &t);
  
  /*void Rotiraj(const Tacka &t, double ugao){
    x.first=(t.first+(x.first-t.first))*std::cos(DajUgao(1))-(x.second-t.second)*std::sin(DajUgao(1));
    y.first=(t.first+(y.first-t.first))*std::cos(DajUgao(2))-(y.second-t.second)*std::sin(DajUgao(2));
    z.first=(t.first+(z.first-t.first))*std::cos(DajUgao(3))-(z.second-t.second)*std::sin(DajUgao(3));
    x.second=t.second+(x.first-t.first)*std::sin(DajUgao(1))+(x.second-t.second)*std::cos(DajUgao(1));
    y.second=t.second+(y.first-t.first)*std::sin(DajUgao(2))+(y.second-t.second)*std::cos(DajUgao(2));
    z.second=t.second+(z.first-t.first)*std::sin(DajUgao(3))+(z.second-t.second)*std::cos(DajUgao(3));
  }*/
  
  /*void Skaliraj(const Tacka &t, double faktor){
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    x.first=(t.first+faktor*(x.first-t.first));
    y.first=(t.first+faktor*(y.first-t.first));
    z.first=(t.first+faktor*(z.first-t.first));
    x.second=(t.second+faktor*(x.second-t.second));
    y.second=(t.second+faktor*(y.second-t.second));
    z.second=(t.second+faktor*(z.second-t.second));
  }*/
  
  /*void Rotiraj(double ugao){
    Tacka t(DajCentar());
    x.first=(t.first+(x.first-t.first))*std::cos(DajUgao(1))-(x.second-t.second)*std::sin(DajUgao(1));
    y.first=(t.first+(y.first-t.first))*std::cos(DajUgao(2))-(y.second-t.second)*std::sin(DajUgao(2));
    z.first=(t.first+(z.first-t.first))*std::cos(DajUgao(3))-(z.second-t.second)*std::sin(DajUgao(3));
    x.second=t.second+(x.first-t.first)*std::sin(DajUgao(1))+(x.second-t.second)*std::cos(DajUgao(1));
    y.second=t.second+(y.first-t.first)*std::sin(DajUgao(2))+(y.second-t.second)*std::cos(DajUgao(2));
    z.second=t.second+(z.first-t.first)*std::sin(DajUgao(3))+(z.second-t.second)*std::cos(DajUgao(3));
  }*/
  
  /*void Skaliraj(double faktor){
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka t(DajCentar());
    x.first=(t.first+faktor*(x.first-t.first));
    y.first=(t.first+faktor*(y.first-t.first));
    z.first=(t.first+faktor*(z.first-t.first));
    x.second=(t.second+faktor*(x.second-t.second));
    y.second=(t.second+faktor*(y.second-t.second));
    z.second=(t.second+faktor*(z.second-t.second));
  }*/
  
  friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  
  friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
  
  friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if((t1.x.first==t2.x.first && t1.x.second==t2.x.second && t1.y.first==t2.y.first && t1.y.second==t2.y.second && t1.z.first==t2.z.first && t1.z.second==t2.z.second)
    || (t1.x.first==t2.y.first && t1.x.second==t2.y.second && t1.y.first==t2.z.first && t1.y.second==t2.z.second && t1.z.first==t2.x.first && t1.z.second==t2.x.second)
    || (t1.x.first==t2.z.first && t1.x.second==t2.z.second && t1.y.first==t2.x.first && t1.y.second==t2.x.second && t1.z.first==t2.y.first && t1.z.second==t2.y.second))
    return true;
    return false;
  }

int main (){
	return 0;
}