/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <iomanip>
#include <algorithm>
typedef std::pair<double, double> Tacka;
class Trougao{
Tacka  t1, t2, t3;
public:
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double Ut1=(atan(t1.second/t1.first));
    double Ut2=(atan(t2.second/t2.second));
    double Ut3=(atan(t3.second/t3.first));
    if(Ut1==Ut2 || Ut2==Ut3) throw std::domain_error ("Nekorektne pozicije");
}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    *this=Trougao(t1,t2,t3);
}
void TestirajIndeks(int indeks) const {
    if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
}
void Postavi(int indeks, const Tacka &t){
    TestirajIndeks(indeks);
    if(indeks==1) *this=Trougao(t,t2,t3);
    if(indeks==2) *this=Trougao(t1,t,t3);
    if(indeks==3) *this=Trougao(t1,t2,t);
}

static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double x=(t1.first*(t2.second-t3.second)+t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    if(x>0) return 1;
    if(x<0) return -1;
    if(x==0) return 0;
}
Tacka DajTjeme(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    if(indeks==1) return t1;
    if(indeks==2) return t2;
    if(indeks==3) return t3;
}
double DajStranicu(int indeks) const {
    TestirajIndeks(indeks);
    double stranica;
    if(indeks==1) stranica=(sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second))); return stranica;
    if(indeks==2) stranica=(sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second))); return stranica;
    if(indeks==3) stranica=(sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second))); return stranica;
}
/*double DajUgao(int indeks){
    TestirajIndeks(indeks);
    double Fi1,Fi2;

}*/
Tacka DajCentar() const{
    return Tacka((t1.first+t2.first+t3.first)/3,(t1.second+t2.second+t3.second)/3);
}
double DajObim() const{
    double obim=DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    return obim;
}
double DajPovrsinu() const{
  double s=DajObim()/2;
  double povrsina=sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3)));
  return povrsina;
}
bool DaLiJePozitivnoOrjentiran() const{
    return Orijentacija(t1,t2,t3);
}
/*bool DaLiJeUnutra(const Tacka &t) const{
    
}*/
void Ispisi() const{
 std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))"; 
}
void Transliraj(double delta_x, double delta_y){
t1.first+=delta_x;
t1.second+=delta_y;
t2.first+=delta_x;
t2.second+=delta_y;
t3.first+=delta_x;
t3.second+=delta_y;
}
void Centriraj(const Tacka &t){
  Tacka c=DajCentar();
  int dx=t.first-c.first;
  int dy=t.second-c.second;
  Transliraj(dx,dy);
}
void Rotiraj(const Tacka &t, double ugao){
    Tacka c=DajCentar();
    Tacka nova;
    nova.first=(c.first+(t.first-c.first)*cos(ugao)-(t.second-c.second)*sin(ugao));
    nova.second=c.second+(t.first-c.first)*sin(ugao)+(t.second-c.second)*cos(ugao);
}
/*void Skaliraj(const Tacka &t, double faktor){
    if(faktor=0) throw std::domain_error ("Nekorektan faktor skaliranja");
    
}
void Skaliraj(double faktor){
    if(faktor=0) throw std::domain_error ("Nekorektan faktor skaliranja");
}*/
};

int main (){
   int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    try{
        std::vector<std::shared_ptr<Trougao>>Trouglovi(n);
        for(int i=0; i<n; i++){
        Tacka t1,t2,t3;
        std::cout<<"Unesite podatake za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
        Trouglovi[i]=std::make_shared<Trougao>(Trougao(t1,t2,t3));
        Trouglovi[i]->Ispisi();
    }
    }catch(...){
        std::cout<<"Problemi sa memorijom";
    }
	return 0;
}