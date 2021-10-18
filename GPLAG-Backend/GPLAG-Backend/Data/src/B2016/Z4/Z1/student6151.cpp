/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <memory>
typedef std::pair<double,double> Tacka;

class Trougao{
    Tacka t1,t2,t3;
    
    public:
Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
void Postavi(int indeks, const Tacka &t);
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
Tacka DajTjeme (int indeks) const;
double DajStranicu (int indeks) const;
double DajUgao (int indeks) const;
Tacka DajCentar() const;
double DajObim() const;
double DajPovrsinu() const;
bool DaLiJePozitivnoOrijentiran();
bool DaLiJeUnutra() const;
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
    Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
  //  if(orijentacija) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
}

void Trougao::Postavi(int indeks, const Tacka &t){
 //   if(orijentacija...) throw std::domain_error("Nekorektne pozicije tjemena");
   if(indeks<0 || indeks>4) throw std::range_error("Nekorektan indeks");
}

double pomocna(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return abs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
}

int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(pomocna(t1,t2,t3)>0) return 1;
    else if(pomocna(t1,t2,t3)<0) return -1;
    return 0;
}

Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks<0 || indeks>4) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return t1;
    else if(indeks==2) return t2;
    else return t3;
}

double Trougao::DajStranicu(int indeks) const{
   if(indeks<0 || indeks>4) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
    else if(indeks==2) return sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
    else return sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
}

double Trougao::DajUgao(int indeks) const{
    if(indeks<0 || indeks>4) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return acos(((DajStranicu(2)*DajStranicu(2))+
    (DajStranicu(3)*DajStranicu(3))-(DajStranicu(1)*DajStranicu(1)))/(2*DajStranicu(2)*DajStranicu(3)));
    else if(indeks==2) return acos(((DajStranicu(1)*DajStranicu(1))+
    (DajStranicu(3)*DajStranicu(3))-(DajStranicu(2)*DajStranicu(2)))/(2*DajStranicu(1)*DajStranicu(3)));
    else return acos(((DajStranicu(2)*DajStranicu(2))+
    (DajStranicu(1)*DajStranicu(1))-(DajStranicu(3)*DajStranicu(3)))/(2*DajStranicu(2)*DajStranicu(1)));
}

Tacka Trougao::DajCentar() const{
    Tacka centar;
     centar.first=(t1.first+t2.first+t3.first)/3;
    centar.second=(t1.second+t2.second+t2.second)/3;
    return centar;
}

double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}

double Trougao::DajPovrsinu() const{
    double x=pomocna(t1,t2,t3);
    return x;
} 

bool Trougao::DaLiJePozitivnoOrijentiran(){
   if(Orijentacija(t1,t2,t3)>0) return true;
    return false;
}

//bool DaLiJeUnutra() const{
//}

void Trougao::Ispisi()const{
    std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y){
    t1.first=t1.first+delta_x; t2.first=t2.first+delta_x; t3.first=t3.first+delta_x;
    t1.second=t1.second+delta_y; t2.second=t2.second+delta_y; t3.second=t3.second+delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    
} 

void Trougao::Rotiraj(const Tacka &t, double ugao){
    t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
    t1.second=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
    t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
    t2.second=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
    t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
    t3.second=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first=t.first+faktor*(t1.first-t.first);
    t1.second=t.second+faktor*(t1.second-t.first);
    t2.first=t.first+faktor*(t2.first-t.first);
    t2.second=t.second+faktor*(t2.second-t.first);
    t3.first=t.first+faktor*(t3.first-t.first);
    t3.second=t.second+faktor*(t3.second-t.first);
}
/*
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    for(int i=0;i<3;i++){
        
    }
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    if(Trougao::DajStranicu(1)==Trougao::DajStranicu(1) && Trougao::DajStranicu(2)==Trougao::DajStranicu() 
    && Trougao::DajStranicu(3)==Trougao::DajStranicu(3))
    //uslovi za uglove
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    
}
*/
int main ()
{

   /* int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    
    std::vector<std::shared_ptr<Trougao>> vektor(n);
    std::vector<Tacka>vekt[n];
    for(int i=0;i<n;i++){
        std::cout<<"Unesite podatke za "<<n+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        for(int j=0;j<3;j++)
        std::cin>>vekt[j].first>>vekt[j].second;
        std::vector<Tacka> *vekt= new std::vector<Tacka>(3);
        vektor.push_back(*vekt);
    }
    
    double deltax,deltay,faktor,ugao;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>deltax>>deltay;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::cout<<"Trouglovi nakon obavljenih transformacija: ";
    std::cout<<"Trougao sa najmanjim obimom: ";
    std::cout<<"Parovi identicnih trouglova: ";
    std::cout<<"Parovi podudarnih trouglova: ";
    std::cout<<"Parovi slicnih trouglova: ";
    */
	return 0;
}