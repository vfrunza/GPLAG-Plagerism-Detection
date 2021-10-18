#include <iostream>
#include <utility>
#include <stdexcept>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm>
typedef std::pair<double, double> Tacka;
class Trougao{
  Tacka t1, t2, t3;
  static bool JesuLiJednaki(double x, double y, double Eps=1e-10){
      return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
  }
  public:
   Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
   void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
   void Postavi(int indeks, const Tacka &t);
   static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
   Tacka DajTjeme(int indeks) const;
   double DajStranicu(int indeks) const;
   double DajUgao(int indeks) const;
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
   void Rotiraj(double ugao);
   void Skaliraj(double faktor);
   friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
   friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
   friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
     Trougao::t1=std::make_pair(t1.first,t1.second);
     Trougao::t2=std::make_pair(t2.first,t2.second);
     Trougao::t3=std::make_pair(t3.first,t3.second);
     int uslov{Orijentacija(t1,t2,t3)};
     if(uslov==0) throw std::domain_error("Nekorektne pozicije tjemena");
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    Trougao::t1=std::make_pair(t1.first, t1.second);
    Trougao::t2=std::make_pair(t2.first, t2.second);
    Trougao::t3=std::make_pair(t3.first, t3.second);
    int uslov{Orijentacija(t1,t2,t3)};
    if(uslov==0) throw std::domain_error("Nekorektne pozicije tjemena");
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(!(indeks==1 || indeks==2 || indeks==3)) throw std::range_error("Nekorektan indeks");
    if(indeks==1) Trougao::t1=std::make_pair(t.first,t.second);
    if(indeks==2) Trougao::t2=std::make_pair(t.first,t.second);
    if(indeks==3) Trougao::t3=std::make_pair(t.first,t.second);
    int uslov{Orijentacija(t1,t2,t3)};
    if(uslov==0) throw std::domain_error("Nekorektne pozicije tjemena");
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
 double rezultat{0};
 rezultat=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
 if(rezultat>0) return 1;
 else if(JesuLiJednaki(rezultat,0)) return 0;
 return -1;
}
Tacka Trougao::DajTjeme(int indeks) const{
    if(!(indeks==1 || indeks==2 || indeks==3)) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return Trougao::t1;
    else if(indeks==2) return Trougao::t2;
    return Trougao::t3;
}
double Trougao::DajStranicu(int indeks) const{
 double duzina{0};   
 if(!(indeks==1 || indeks==2  || indeks==3)) throw std::range_error("Nekorektan indeks");
 if(indeks==1) duzina=std::sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
 else if(indeks==2) duzina=std::sqrt((t3.first-t1.first)*(t3.first-t1.first)+(t3.second-t1.second)*(t3.second-t1.second));
  else duzina=std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
 return duzina; 
}
double Trougao::DajUgao(int indeks) const{
    double a{0}, b{0}, c{0};
    if(!(indeks==1 || indeks==2 || indeks==3)) throw std::range_error("Nekorektan indeks");
    a=std::sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
    b=std::sqrt((t3.first-t1.first)*(t3.first-t1.first)+(t3.second-t1.second)*(t3.second-t1.second));
    c=std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    if(indeks==1) return std::acos((b*b+c*c-a*a)/(2*b*c));
    else if(indeks==2) return std::acos((a*a+c*c-b*b)/(2*a*c));
    return std::acos((b*b+a*a-c*c)/(2*a*b));
}
Tacka Trougao::DajCentar()const{
    Tacka t;
    t=std::make_pair((t1.first+t2.first+t3.first)/3,(t1.second+t2.second+t3.second)/3);
    return t;
}
double Trougao::DajObim() const{
    double a{0}, b{0}, c{0};
    a=std::sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
    b=std::sqrt((t3.first-t1.first)*(t3.first-t1.first)+(t3.second-t1.second)*(t3.second-t1.second));
    c=std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    return a+b+c;
}
double Trougao::DajPovrsinu() const{
    double povrsina{0};
    povrsina=0.5*std::abs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    return povrsina;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const{
    int uslov{Orijentacija(t1,t2,t3)};
    if(uslov==1) return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
 double p1{0}, p2{0}, p3{0}, p{0};
 p=0.5*std::abs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
 p1=0.5*std::abs(t1.first*(t2.second-t.second)-t2.first*(t1.second-t.second)+t.first*(t1.second-t2.second));
 p2=0.5*std::abs(t2.first*(t3.second-t.second)-t3.first*(t2.second-t.second)+t.first*(t2.second-t3.second));
 p3=0.5*std::abs(t1.first*(t3.second-t.second)-t3.first*(t1.second-t.second)+t.first*(t1.second-t3.second));
 if(JesuLiJednaki(p,p1+p2+p3)) return true;
 return false;
}
void Trougao::Transliraj(double delta_x, double delta_y){
    Trougao::t1=std::make_pair(t1.first+delta_x, t1.second+delta_y);
    Trougao::t2=std::make_pair(t2.first+delta_x, t2.second+delta_y);
    Trougao::t3=std::make_pair(t3.first+delta_x, t3.second+delta_y);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
 int ind1{0}, ind2{0}, ind3{0};
 if(Trougao::JesuLiJednaki(t1.Trougao::t1.first,t2.Trougao::t1.first) && Trougao::JesuLiJednaki(t1.Trougao::t1.second,t2.Trougao::t1.second)) ind1=1;
 if(Trougao::JesuLiJednaki(t1.Trougao::t1.first, t2.Trougao::t2.first) && Trougao::JesuLiJednaki(t1.Trougao::t1.second,t2.Trougao::t2.second)) ind1=1;
 if(Trougao::JesuLiJednaki(t1.Trougao::t1.first, t2.Trougao::t3.first) && Trougao::JesuLiJednaki(t1.Trougao::t1.second, t2.Trougao::t3.second)) ind1=1;
 if(Trougao::JesuLiJednaki(t1.Trougao::t2.first, t2.Trougao::t1.first) && Trougao::JesuLiJednaki(t1.Trougao::t2.second, t2.Trougao::t1.second)) ind2=1;
 if(Trougao::JesuLiJednaki(t1.Trougao::t2.first, t2.Trougao::t2.first) && Trougao::JesuLiJednaki(t1.Trougao::t2.second, t2.Trougao::t2.second)) ind2=1;
 if(Trougao::JesuLiJednaki(t1.Trougao::t2.first, t2.Trougao::t3.first) && Trougao::JesuLiJednaki(t1.Trougao::t2.second, t2.Trougao::t3.second)) ind2=1;
 if(Trougao::JesuLiJednaki(t1.Trougao::t3.first, t2.Trougao::t1.first) && Trougao::JesuLiJednaki(t1.Trougao::t3.second, t2.Trougao::t1.second)) ind3=1;
 if(Trougao::JesuLiJednaki(t1.Trougao::t3.first, t2.Trougao::t2.first) && Trougao::JesuLiJednaki(t1.Trougao::t3.second, t2.Trougao::t2.second)) ind3=1;
 if(Trougao::JesuLiJednaki(t1.Trougao::t3.first, t2.Trougao::t3.first) && Trougao::JesuLiJednaki(t1.Trougao::t3.second, t2.Trougao::t3.second)) ind3=1;
 if(ind1==1 && ind2==1 && ind3==1) return true;
 return false;
}
void Trougao::Centriraj(const Tacka &t){
 Tacka teziste;
 double duzina_x{0}, duzina_y{0};
 teziste=std::make_pair((t1.first+t2.first+t3.first)/3,(t1.second+t2.second+t3.second)/3);
 duzina_x=t.first-teziste.first;
 duzina_y=t.second-teziste.second;
 Trougao::t1=std::make_pair(t1.first+duzina_x, t1.second+duzina_y);
 Trougao::t2=std::make_pair(t2.first+duzina_x, t2.second+duzina_y);
 Trougao::t3=std::make_pair(t3.first+duzina_x, t3.second+duzina_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
 Trougao::t1=std::make_pair(t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao), t.second+(t1.first-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao));
 Trougao::t2=std::make_pair(t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao), t.second+(t2.first-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao));
 Trougao::t3=std::make_pair(t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao), t.second+(t3.first-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao));
}
void Trougao::Rotiraj(double ugao){
    Tacka t;
    t=std::make_pair((t1.first+t2.first+t3.first)/3, (t1.second+t2.second+t3.second)/3);
    double pomoc_x1, pomoc_y1, pomoc_x2, pomoc_y2, pomoc_x3, pomoc_y3;
    pomoc_x1=t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao);
    pomoc_y1=t.second+(t1.first-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao);
    t1=std::make_pair(pomoc_x1, pomoc_y1);
    pomoc_x2=t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao);
    pomoc_y2=t.second+(t2.first-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao);
    t2=std::make_pair(pomoc_x2, pomoc_y2);
    pomoc_x3=t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao);
    pomoc_y3=t.second+(t3.first-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao);
    t3=std::make_pair(pomoc_x3, pomoc_y3);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
 if(JesuLiJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
 Trougao::t1=std::make_pair(t.first+faktor*(t1.first-t.first), t.second+faktor*(t1.second-t.second));
 Trougao::t2=std::make_pair(t.first+faktor*(t2.first-t.first), t.second+faktor*(t2.second-t.second));
 Trougao::t3=std::make_pair(t.first+faktor*(t3.first-t.first), t.second+faktor*(t3.second-t.second));
}
void Trougao::Skaliraj(double faktor){
    if(JesuLiJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja"); 
    Tacka t;
    t=std::make_pair((t1.first+t2.first+t3.first)/3, (t1.second+t2.second+t3.second)/3);
    Trougao::t1=std::make_pair(t.first+faktor*(t1.first-t.first), t.second+faktor*(t1.second-t.second));
    Trougao::t2=std::make_pair(t.first+faktor*(t2.first-t.first), t.second+faktor*(t2.second-t.second));
    Trougao::t3=std::make_pair(t.first+faktor*(t3.first-t.first), t.second+faktor*(t3.second-t.second));
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    double niz1[3]{0}, niz2[3]{0};
    int ind1{0}, ind2{0}, ind3{0};
    niz1[0]=std::sqrt((t1.Trougao::t3.first-t1.Trougao::t2.first)*(t1.Trougao::t3.first-t1.Trougao::t2.first)+(t1.Trougao::t3.second-t1.Trougao::t2.second)*(t1.Trougao::t3.second-t1.Trougao::t2.second));
    niz1[1]=std::sqrt((t1.Trougao::t3.first-t1.Trougao::t1.first)*(t1.Trougao::t3.first-t1.Trougao::t1.first)+(t1.Trougao::t3.second-t1.Trougao::t1.second)*(t1.Trougao::t3.second-t1.Trougao::t1.second));
    niz1[2]=std::sqrt((t1.Trougao::t2.first-t1.Trougao::t1.first)*(t1.Trougao::t2.first-t1.Trougao::t1.first)+(t1.Trougao::t2.second-t1.Trougao::t1.second)*(t1.Trougao::t2.second-t1.Trougao::t1.second));
    niz2[0]=std::sqrt((t2.Trougao::t3.first-t2.Trougao::t2.first)*(t2.Trougao::t3.first-t2.Trougao::t2.first)+(t2.Trougao::t3.second-t2.Trougao::t2.second)*(t2.Trougao::t3.second-t2.Trougao::t2.second));
    niz2[1]=std::sqrt((t2.Trougao::t3.first-t2.Trougao::t1.first)*(t2.Trougao::t3.first-t2.Trougao::t1.first)+(t2.Trougao::t3.second-t2.Trougao::t1.second)*(t2.Trougao::t3.second-t2.Trougao::t1.second));
    niz2[2]=std::sqrt((t2.Trougao::t2.first-t2.Trougao::t1.first)*(t2.Trougao::t2.first-t2.Trougao::t1.first)+(t2.Trougao::t2.second-t2.Trougao::t1.second)*(t2.Trougao::t2.second-t2.Trougao::t1.second));
    std::sort(niz1,niz1+3);
    std::sort(niz2, niz2+3);
    for(int i=0; i<3; i++)
      if(!(Trougao::JesuLiJednaki(niz1[i], niz2[i]))) return false;
    if(Trougao::JesuLiJednaki(t1.Trougao::t1.first,t2.Trougao::t1.first) && Trougao::JesuLiJednaki(t1.Trougao::t1.second, t2.Trougao::t1.second)) ind1=1;
    if(Trougao::JesuLiJednaki(t1.Trougao::t1.first,t2.Trougao::t2.first) && Trougao::JesuLiJednaki(t1.Trougao::t1.second, t2.Trougao::t2.second)) ind1=1;
    if(Trougao::JesuLiJednaki(t1.Trougao::t1.first,t2.Trougao::t3.first) && Trougao::JesuLiJednaki(t1.Trougao::t1.second, t2.Trougao::t3.second)) ind1=1;
    if(Trougao::JesuLiJednaki(t1.Trougao::t2.first,t2.Trougao::t1.first) && Trougao::JesuLiJednaki(t1.Trougao::t2.second, t2.Trougao::t1.second)) ind2=1;
    if(Trougao::JesuLiJednaki(t1.Trougao::t2.first,t2.Trougao::t2.first) && Trougao::JesuLiJednaki(t1.Trougao::t2.second, t2.Trougao::t2.second)) ind2=1;
    if(Trougao::JesuLiJednaki(t1.Trougao::t2.first,t2.Trougao::t3.first) && Trougao::JesuLiJednaki(t1.Trougao::t2.second, t2.Trougao::t3.second)) ind2=1;
    if(Trougao::JesuLiJednaki(t1.Trougao::t3.first,t2.Trougao::t1.first) && Trougao::JesuLiJednaki(t1.Trougao::t3.second, t2.Trougao::t1.second)) ind3=1;
    if(Trougao::JesuLiJednaki(t1.Trougao::t3.first,t2.Trougao::t2.first) && Trougao::JesuLiJednaki(t1.Trougao::t3.second, t2.Trougao::t2.second)) ind3=1;
    if(Trougao::JesuLiJednaki(t1.Trougao::t3.first,t2.Trougao::t3.first) && Trougao::JesuLiJednaki(t1.Trougao::t3.second, t2.Trougao::t3.second)) ind3=1;
    if(ind1==1 && ind2==1 && ind3==1) return true;
    if(ind1==0 && ind2==0 && ind3==0) return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double niz1[3]{0}, niz2[3]{0};
    niz1[0]=std::sqrt((t1.Trougao::t3.first-t1.Trougao::t2.first)*(t1.Trougao::t3.first-t1.Trougao::t2.first)+(t1.Trougao::t3.second-t1.Trougao::t2.second)*(t1.Trougao::t3.second-t1.Trougao::t2.second));
    niz1[1]=std::sqrt((t1.Trougao::t3.first-t1.Trougao::t1.first)*(t1.Trougao::t3.first-t1.Trougao::t1.first)+(t1.Trougao::t3.second-t1.Trougao::t1.second)*(t1.Trougao::t3.second-t1.Trougao::t1.second));
    niz1[2]=std::sqrt((t1.Trougao::t2.first-t1.Trougao::t1.first)*(t1.Trougao::t2.first-t1.Trougao::t1.first)+(t1.Trougao::t2.second-t1.Trougao::t1.second)*(t1.Trougao::t2.second-t1.Trougao::t1.second));
    niz2[0]=std::sqrt((t2.Trougao::t3.first-t2.Trougao::t2.first)*(t2.Trougao::t3.first-t2.Trougao::t2.first)+(t2.Trougao::t3.second-t2.Trougao::t2.second)*(t2.Trougao::t3.second-t2.Trougao::t2.second));
    niz2[1]=std::sqrt((t2.Trougao::t3.first-t2.Trougao::t1.first)*(t2.Trougao::t3.first-t2.Trougao::t1.first)+(t2.Trougao::t3.second-t2.Trougao::t1.second)*(t2.Trougao::t3.second-t2.Trougao::t1.second));
    niz2[2]=std::sqrt((t2.Trougao::t2.first-t2.Trougao::t1.first)*(t2.Trougao::t2.first-t2.Trougao::t1.first)+(t2.Trougao::t2.second-t2.Trougao::t1.second)*(t2.Trougao::t2.second-t2.Trougao::t1.second));
    std::sort(niz1,niz1+3);
    std::sort(niz2, niz2+3);
   return Trougao::JesuLiJednaki(niz1[0]/niz2[0], niz1[1]/niz2[1]) && Trougao::JesuLiJednaki(niz1[0]/niz2[0], niz1[2]/niz2[2]);
}
void Trougao::Ispisi() const{
    std::cout <<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}
int main (){
    int n{0};
    double x1, y1, x2, y2, x3, y3,a,b,c;
    double delta_x, delta_y, ugao{0}, faktor{0};
    Tacka t1, t2, t3, t;
    for(;;){
     std::cout <<"Koliko zelite kreirati trouglova: ";
     std::cin >>n;
     if(n>0) break;
    }
    std::vector<std::shared_ptr<Trougao>> v;
    v.resize(n);
    try{
        for(int i=0; i<n; i++){
            for(;;){
             std::cout <<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
             std::cin >>x1>>y1;
             t1=std::make_pair(x1,y1);
             std::cin >>x2>>y2;
             t2=std::make_pair(x2,y2);
             std::cin >>x3>>y3;
             t3=std::make_pair(x3,y3);
             a=std::sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
             b=std::sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
             c=std::sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
             if(a+b<=c || a+c<=b || b+c<=a) std::cout <<"Nekorektne pozicije tjemena, ponovite unos!"<<std::endl;
             else break;
            }
            try{
              v[i]=std::make_shared<Trougao>(t1,t2,t3);
             }
             catch(std::domain_error izuzetak1){
                std::cout <<izuzetak1.what()<<std::endl;
                i--;
             }
        }
      std::cout <<"Unesite vektor translacije (dx dy): ";
      std::cin >>delta_x>>delta_y;
      std::cout <<"Unesite ugao rotacije: ";
      std::cin >>ugao;
      std::cout <<"Unesite faktor skaliranja: ";
      std::cin >>faktor;
     std::cout <<"Trouglovi nakon obavljenih transformacija: "<<std::endl; 
    std::transform(std::begin(v), std::end(v), std::begin(v), [&] (std::shared_ptr<Trougao>p){p->Transliraj(delta_x, delta_y); return p;});
    std::transform(std::begin(v), std::end(v), std::begin(v), [&] (std::shared_ptr<Trougao>p){p->Rotiraj(ugao); return p;});
    std::transform(std::begin(v), std::end(v), std::begin(v), [&](std::shared_ptr<Trougao>p){ p->Skaliraj(p->DajTjeme(1), faktor); return p;});
    std::sort(std::begin(v), std::end(v), [](std::shared_ptr<Trougao>p1, std::shared_ptr<Trougao>p2)->bool{return p1->DajPovrsinu()<p2->DajPovrsinu();});
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao>p){p->Ispisi(); std::cout <<std::endl;});
    std::shared_ptr<Trougao> najmanji(*std::min_element(std::begin(v), std::end(v), [](std::shared_ptr<Trougao>p1, std::shared_ptr<Trougao>p2)->bool{return p1->DajObim()<p2->DajObim();}));
    std::cout <<"Trougao sa najmanjim obimom: "; 
    najmanji->Ispisi();
    std::cout <<std::endl;
    int brojac1{0}, brojac2{0}, brojac3{0}, pokaz1{0}, pokaz2{0}, pokaz3{0};
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuIdenticni(*v[i], *v[j])){ 
                if(pokaz1==0){std::cout <<"Parovi identicnih trouglova:"<<std::endl; pokaz1=1;}
                v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi(); std::cout<<std::endl; 
                brojac1++; 
            }
        }
    }
    if(brojac1==0) std::cout <<"Nema identicnih trouglova!"<<std::endl;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuPodudarni(*v[i],*v[j])){
                if(pokaz2==0){std::cout <<"Parovi podudarnih trouglova:"<<std::endl; pokaz2=1;}
                v[i]->Ispisi(); std::cout <<" i "; v[j]->Ispisi(); std::cout <<std::endl;
                brojac2++; 
            }
        }
    }
    if(brojac2==0) std::cout <<"Nema podudarnih trouglova!"<<std::endl;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuSlicni(*v[i],*v[j])){
                if(pokaz3==0){std::cout <<"Parovi slicnih trouglova:"<<std::endl; pokaz3=1;}
                v[i]->Ispisi(); std::cout <<" i "; v[j]->Ispisi(); std::cout <<std::endl;
                brojac3++;
            }
        }
    }
    if(brojac3==0) std::cout <<"Nema slicnih trouglova!"<<std::endl;
     }
    catch(std::range_error izuzetak2){
        std::cout <<izuzetak2.what()<<std::endl;
    }
    catch(std::domain_error izuzetak3){
        std::cout <<izuzetak3.what()<<std::endl;
    }
    catch(...){
        std::cout <<"Problemi sa memorijom!\n";
    }
	return 0;
}