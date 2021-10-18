/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <vector>
const double eps (1e-10);

typedef std::pair<double, double> Tacka;
class Trougao{
      
    Tacka tacka1,tacka2,tacka3;
      
    public:
      
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tacka1=std::make_pair(t1.first,t1.second);
        tacka2=std::make_pair(t2.first,t2.second);
        tacka3=std::make_pair(t3.first,t3.second);
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tacka1=std::make_pair(t1.first,t1.second);
        tacka2=std::make_pair(t2.first,t2.second);
        tacka3=std::make_pair(t3.first,t3.second);
    }
    
    void Postavi(int indeks, const Tacka &t){
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1){
            if(Orijentacija(t,tacka2,tacka3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            tacka1=std::make_pair(t.first,t.second);
        }else if(indeks==2){
            if(Orijentacija(tacka1,t,tacka3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            tacka2=std::make_pair(t.first,t.second);
        }else{
            if(Orijentacija(tacka1,tacka2,t)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            tacka3=std::make_pair(t.first,t.second);
        }
        
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double b(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        if(b<eps) return -1;
        else if(b>eps) return 1;
        else return 0;
        
    }
    
    Tacka DajTjeme(int indeks) const{
         if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
         if(indeks==1) return tacka1;
         else if(indeks==2) return tacka2;
         else return tacka3;
    }
    
    double DajStranicu(int indeks) const{
         if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
         if(indeks==1) return std::sqrt((tacka2.first-tacka3.first)*(tacka2.first-tacka3.first)+(tacka2.second-tacka3.second)*(tacka2.second-tacka3.second));
         else if(indeks==2) return std::sqrt((tacka1.first-tacka3.first)*(tacka1.first-tacka3.first)+(tacka1.second-tacka3.second)*(tacka1.second-tacka3.second));
         else return std::sqrt((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+(tacka2.second-tacka1.second)*(tacka2.second-tacka1.second));;
    }
    
    double DajUgao(int indeks) const{
         if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
         double a(DajStranicu(1)),b(DajStranicu(2)),c(DajStranicu(3));
         if(indeks==1) return acos((c*c+b*b-a*a)/(2*c*b));
         else if(indeks==2) return acos((c*c+a*a-b*b)/(2*c*a));
         else return acos((a*a+b*b-c*c)/(2*a*b));
    }
    
    Tacka DajCentar() const{
        return std::make_pair((tacka1.first+tacka2.first+tacka3.first)/3,(tacka1.second+tacka2.second+tacka3.second)/3);
        
    }
    
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    
    double DajPovrsinu() const{
        if((tacka1.first*(tacka2.second-tacka3.second)-tacka2.first*(tacka1.second-tacka3.second)+tacka3.first*(tacka1.second-tacka2.second))<0)
        return -(tacka1.first*(tacka2.second-tacka3.second)-tacka2.first*(tacka1.second-tacka3.second)+tacka3.first*(tacka1.second-tacka2.second));
        
        return (tacka1.first*(tacka2.second-tacka3.second)-tacka2.first*(tacka1.second-tacka3.second)+tacka3.first*(tacka1.second-tacka2.second));
    }
    
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(tacka1,tacka2,tacka3)==1) return true;
        else return false;
    }
    
    bool DaLiJeUnutra(const Tacka &t) const{
        
    }
    void Ispisi() const{
        std::cout << "(("<<tacka1.first<<","<<tacka1.second<<"),("<<tacka2.first<<","<<tacka2.second<<"),("<<tacka3.first<<","<<tacka3.second <<"))" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y){
        tacka1.first+=delta_x;
        tacka2.first+=delta_x;
        tacka3.first+=delta_x;
        tacka1.second+=delta_y;
        tacka2.second+=delta_y;
        tacka3.second+=delta_y;
    }
    /*void Centriraj(const Tacka &t);*/
    void Rotiraj(const Tacka &t, double ugao){
        
        tacka1.first=(t.first+(tacka1.first-t.first)*std::cos(ugao) -(tacka1.second-t.second)*std::sin(ugao));
        tacka1.second=(t.second+(tacka1.first-t.first)*std::cos(ugao) +(tacka1.second-t.second)*std::sin(ugao));
        tacka2.first=(t.first+(tacka2.first-t.first)*std::cos(ugao) -(tacka2.second-t.second)*std::sin(ugao));
        tacka2.second=(t.second+(tacka2.first-t.first)*std::cos(ugao) +(tacka2.second-t.second)*std::sin(ugao));
        tacka3.first=(t.first+(tacka3.first-t.first)*std::cos(ugao) -(tacka3.second-t.second)*std::sin(ugao));
        tacka3.second=(t.second+(tacka3.first-t.first)*std::cos(ugao) +(tacka3.second-t.second)*std::sin(ugao));
        
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(std::abs(faktor)<eps)throw std::domain_error("Nekorektan faktor skaliranja");
        if(t.first==tacka1.first && t.second==tacka1.second){
            tacka2.first=t.first+faktor*(tacka2.first-t.first);
            tacka3.first=t.first+faktor*(tacka3.first-t.first);
            tacka2.second=t.second+faktor*(tacka2.second-t.second);
            tacka3.second=t.second+faktor*(tacka3.second-t.second);
            
        }else if(t.first==tacka1.first && t.second==tacka1.second){
            tacka1.first=t.first+faktor*(tacka1.first-t.first);
            tacka3.first=t.first+faktor*(tacka3.first-t.first);
            tacka1.second=t.second+faktor*(tacka1.second-t.second);
            tacka3.second=t.second+faktor*(tacka3.second-t.second);
            
        }
        else{
            tacka2.first=t.first+faktor*(tacka2.first-t.first);
            tacka1.first=t.first+faktor*(tacka1.first-t.first);
            tacka2.second=t.second+faktor*(tacka2.second-t.second);
            tacka1.second=t.second+faktor*(tacka1.second-t.second);
        }
    }
    void Rotiraj(double ugao){
        Tacka t(DajCentar());
        std::cout << "Prva tacka" <<t.first<< " Druga tacka "<<t.second<< std::endl;
        tacka1.first=(t.first+(tacka1.first-t.first)*std::cos(ugao) -(tacka1.second-t.second)*std::sin(ugao));
        tacka1.second=(t.second+(tacka1.first-t.first)*std::cos(ugao) +(tacka1.second-t.second)*std::sin(ugao));
        tacka2.first=(t.first+(tacka2.first-t.first)*std::cos(ugao) -(tacka2.second-t.second)*std::sin(ugao));
        tacka2.second=(t.second+(tacka2.first-t.first)*std::cos(ugao) +(tacka2.second-t.second)*std::sin(ugao));
        tacka3.first=(t.first+(tacka3.first-t.first)*std::cos(ugao) -(tacka3.second-t.second)*std::sin(ugao));
        tacka3.second=(t.second+(tacka3.first-t.first)*std::cos(ugao) +(tacka3.second-t.second)*std::sin(ugao));
    }
    void Skaliraj(double faktor){
        Tacka t(DajCentar());
        if(std::abs(faktor)<eps)throw std::domain_error("Nekorektan faktor skaliranja");
        if(t.first==tacka1.first && t.second==tacka1.second){
            tacka2.first=t.first+faktor*(tacka2.first-t.first);
            tacka3.first=t.first+faktor*(tacka3.first-t.first);
            tacka2.second=t.second+faktor*(tacka2.second-t.second);
            tacka3.second=t.second+faktor*(tacka3.second-t.second);
            
        }else if(t.first==tacka1.first && t.second==tacka1.second){
            tacka1.first=t.first+faktor*(tacka1.first-t.first);
            tacka3.first=t.first+faktor*(tacka3.first-t.first);
            tacka1.second=t.second+faktor*(tacka1.second-t.second);
            tacka3.second=t.second+faktor*(tacka3.second-t.second);
            
        }
        else{
            tacka2.first=t.first+faktor*(tacka2.first-t.first);
            tacka1.first=t.first+faktor*(tacka1.first-t.first);
            tacka2.second=t.second+faktor*(tacka2.second-t.second);
            tacka1.second=t.second+faktor*(tacka1.second-t.second);
        }
    }
   /* friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
      */
    
};



int main ()
{   
    int broj;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> broj;
    std::vector<Trougao> trouglovi;
    for(int i(1);i<=broj;i++){
    std::cout << "Unesite podatke za "<<i<<". trougao (x1 y1 x2 y2 x3 y3): " << std::endl;
    double x1,x2,x3,y1,y2,y3;
    std::cin >> x1>>y1>>x2>>y2>>x3>>y3;
    Tacka t1(std::make_pair(x1,y1)),t2(std::make_pair(x2,y2)),t3(std::make_pair(x3,y3));
    Trougao tr(t1,t2,t3);
    trouglovi.push_back(tr);
    }
    
   /* for(int i(0);i<trouglovi.size();i++){
        trouglovi[i].Ispisi();
        std::cout << "Povrsina trouglova: "<< trouglovi[i].DajPovrsinu() << std::endl;
    }*/
    
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin >> dx>>dy;
    for(int i(0);i<trouglovi.size();i++){
        trouglovi[i].Transliraj(dx,dy);
    }
   
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin >> ugao;
    for(int i(0);i<trouglovi.size();i++){
        trouglovi[i].Rotiraj(ugao);
    }
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin >> faktor;
    for(int i(0);i<trouglovi.size();i++){
        trouglovi[i].Skaliraj(faktor);
    }
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    for(int i(0);i<trouglovi.size();i++){
        trouglovi[i].Ispisi();
    }
	return 0;
}