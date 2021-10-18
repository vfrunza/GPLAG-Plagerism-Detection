/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <vector>
#include <memory>
#include <stdexcept>
#include <utility>
typedef std::pair<double, double> Tacka;
const double EPSILON(1e-10);
const double PI(4*std::atan(1));
class Trougao{
    Tacka tacka1,tacka2,tacka3;
    static bool Poredjenje( double x, double y) { if(std::abs(x-y)<EPSILON) return true; else return false;};
    public:    
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tacka1=t1; tacka2=t2; tacka3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tacka1=t1; tacka2=t2; tacka3=t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if( indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) tacka1=t;
        else if(indeks==2) tacka2=t;
        else tacka3=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(std::abs(t1.first*(t2.second - t3.second)-t2.first*(t1.second -t3.second)-t3.first*(t1.second-t2.second))<EPSILON) return 0;
        else if((t1.first*(t2.second - t3.second)-t2.first*(t1.second -t3.second)+t3.first*(t1.second-t2.second))<0) return -1;
        else return 1;
    }
    
    Tacka DajTjeme(int indeks) const{
        if( indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return tacka1;
        if(indeks==2) return tacka2;
        else return tacka3;
    }
    
    double DajStranicu(int indeks) const
    {
        if( indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1){
            return std::sqrt((tacka2.first-tacka3.first)*(tacka2.first-tacka3.first)+ (tacka2.second-tacka3.second)*(tacka2.second-tacka3.second));
        }
        else if(indeks==2){
            return std::sqrt((tacka1.first-tacka3.first)*(tacka1.first-tacka3.first)+ (tacka1.second-tacka3.second)*(tacka1.second-tacka3.second));
        }
        else{
            return std::sqrt((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+ (tacka2.second-tacka1.second)*(tacka2.second-tacka1.second));
        }
    }
    double DajUgao(int indeks) const{
        double stepeni;
        if( indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1)
        {
            stepeni=std::acos((DajStranicu(2)*DajStranicu(2) + DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/ (2*DajStranicu(2)*DajStranicu(3)));
        }
        if(indeks==2)
        {
            stepeni=std::acos((DajStranicu(1)*DajStranicu(1) + DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/ (2*DajStranicu(1)*DajStranicu(3)));
        }
        else
        {
            stepeni=std::acos((DajStranicu(2)*DajStranicu(2) + DajStranicu(1)*DajStranicu(1)-DajStranicu(3)*DajStranicu(3))/ (2*DajStranicu(2)*DajStranicu(1)));
        }
        return (180/PI)*stepeni;
    }
    
    Tacka DajCentar() const
    {
        Tacka t4;
        t4.first=(tacka1.first+tacka2.first+ tacka3.first)/3;
        t4.second=(tacka1.second+tacka2.second+tacka3.second)/3;
        return t4;
    };
    double DajObim() const
    {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const
    {
        return std::abs(tacka1.first*(tacka2.second - tacka3.second)-tacka2.first*(tacka1.second -tacka3.second)-tacka3.first*(tacka1.second-tacka2.second))/2;
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(tacka1,tacka2,tacka3)==1) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        if(Orijentacija(tacka1,tacka2,tacka3)==1 && Orijentacija(tacka1,tacka2,t)==1 && Orijentacija(tacka2,tacka3,t)==1 && Orijentacija(tacka1,t,tacka3)==1) return true;
        else if(Orijentacija(tacka1,tacka3,tacka2)==1 && Orijentacija(tacka1,tacka3,t)==1 && Orijentacija(tacka3,tacka2,t)==1 && Orijentacija(tacka1,t,tacka2)==1) return true;
        return false;
    }
    void Ispisi() const{
        std::cout<<"(("<<tacka1.first<<","<<tacka1.second<<"),("<<tacka2.first<<","<<tacka2.second<<"),("<<tacka3.first<<","<<tacka3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y){
        tacka1.first+=delta_x;
        tacka2.first+=delta_x;
        tacka3.first+=delta_x;
        tacka1.second+=delta_y;
        tacka2.second+=delta_y;
        tacka3.second+=delta_y;
    }
    void Centriraj(const Tacka &t){
        auto centar=DajCentar();
        double delta_x=t.first-centar.first;
        double delta_y=t.second-centar.second;
        Transliraj(delta_x,delta_y);
    }
    void Rotiraj(const Tacka &t, double ugao){
        tacka1.first= t.first+(tacka1.first-t.first)*std::cos(ugao)-(tacka1.second-t.second)*std::sin(ugao);
        tacka1.second=t.second+(tacka1.first-t.first)*std::sin(ugao)+(tacka1.second-t.second)*std::cos(ugao);
        tacka2.first= t.first+(tacka2.first-t.first)*std::cos(ugao)-(tacka2.second-t.second)*std::sin(ugao);
        tacka2.second=t.second+(tacka2.first-t.first)*std::sin(ugao)+(tacka2.second-t.second)*std::cos(ugao);
        tacka3.first= t.first+(tacka3.first-t.first)*std::cos(ugao)-(tacka3.second-t.second)*std::sin(ugao);
        tacka3.second=t.second+(tacka3.first-t.first)*std::sin(ugao)+(tacka3.second-t.second)*std::cos(ugao);
    }
    
    void Skaliraj(const Tacka &t, double faktor){
        if(std::abs(faktor)<EPSILON) throw std::domain_error("Nekorektan faktor skaliranja");
         tacka1.first=t.first+faktor*( tacka1.first-t.first);
         tacka1.second=t.second+faktor*( tacka1.second-t.second);
        tacka2.first=t.first+faktor*( tacka2.first-t.first);
         tacka2.second=t.second+faktor*( tacka2.second-t.second);
        tacka3.first=t.first+faktor*( tacka3.first-t.first);
         tacka3.second=t.second+faktor*( tacka3.second-t.second);
    
    if(faktor<0) Rotiraj(t,180);
    }
    void Rotiraj(double ugao);
    
    void Skaliraj(double faktor);
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
void Trougao::Rotiraj(double ugao)
    {
        Tacka t=this->DajCentar();
         tacka1.first= t.first+(tacka1.first-t.first)*std::cos(ugao)-(tacka1.second-t.second)*std::sin(ugao);
        tacka1.second=t.second+(tacka1.first-t.first)*std::sin(ugao)+(tacka1.second-t.second)*std::cos(ugao);
        tacka2.first= t.first+(tacka2.first-t.first)*std::cos(ugao)-(tacka2.second-t.second)*std::sin(ugao);
        tacka2.second=t.second+(tacka2.first-t.first)*std::sin(ugao)+(tacka2.second-t.second)*std::cos(ugao);
        tacka3.first= t.first+(tacka3.first-t.first)*std::cos(ugao)-(tacka3.second-t.second)*std::sin(ugao);
        tacka3.second=t.second+(tacka3.first-t.first)*std::sin(ugao)+(tacka3.second-t.second)*std::cos(ugao);
    }
    void Trougao::Skaliraj(double faktor){
        if(std::abs(faktor)<EPSILON) throw std::domain_error("Nekorektan faktor skaliranja");
        auto t=this->DajCentar();
         tacka1.first=t.first+faktor*( tacka1.first-t.first);
         tacka1.second=t.second+faktor*( tacka1.second-t.second);
        tacka2.first=t.first+faktor*( tacka2.first-t.first);
         tacka2.second=t.second+faktor*( tacka2.second-t.second);
        tacka3.first=t.first+faktor*( tacka3.first-t.first);
         tacka3.second=t.second+faktor*( tacka3.second-t.second);
    
    if(faktor<0) Rotiraj(t,180);
    }
   bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
   {
       if(Trougao::Poredjenje(t1.tacka1.first,t2.tacka1.first)==true && Trougao::Poredjenje(t1.tacka1.second,t1.tacka1.second)==true)
       {
           if((Trougao::Poredjenje(t1.tacka2.first,t2.tacka2.first)==true && Trougao::Poredjenje(t1.tacka2.second,t2.tacka2.second)==true && Trougao::Poredjenje(t1.tacka3.first,t2.tacka3.first)==true && Trougao::Poredjenje(t1.tacka3.second,t2.tacka3.second)==true) ||
           (Trougao::Poredjenje(t1.tacka2.first,t2.tacka3.first)==true && Trougao::Poredjenje(t1.tacka2.second,t2.tacka3.second)==true && Trougao::Poredjenje(t1.tacka3.first,t2.tacka2.first)==true && Trougao::Poredjenje(t1.tacka3.second,t2.tacka2.second)==true)) return true;
       }
       else if(Trougao::Poredjenje(t1.tacka2.first,t2.tacka2.first)==true && Trougao::Poredjenje(t1.tacka2.second,t1.tacka2.second)==true)
       {
           if((Trougao::Poredjenje(t1.tacka1.first,t2.tacka1.first)==true && Trougao::Poredjenje(t1.tacka1.second,t2.tacka1.second)==true && Trougao::Poredjenje(t1.tacka3.first,t2.tacka3.first)==true && Trougao::Poredjenje(t1.tacka3.second,t2.tacka3.second)==true) ||
           (Trougao::Poredjenje(t1.tacka1.first,t2.tacka3.first)==true && Trougao::Poredjenje(t1.tacka1.second,t2.tacka3.second)==true && Trougao::Poredjenje(t1.tacka3.first,t2.tacka1.first)==true && Trougao::Poredjenje(t1.tacka3.second,t2.tacka1.second)==true)) return true;
       }
       else if(Trougao::Poredjenje(t1.tacka3.first,t2.tacka3.first)==true && Trougao::Poredjenje(t1.tacka3.second,t1.tacka3.second)==true)
       {
           if((Trougao::Poredjenje(t1.tacka1.first,t2.tacka1.first)==true && Trougao::Poredjenje(t1.tacka1.second,t2.tacka1.second)==true && Trougao::Poredjenje(t1.tacka2.first,t2.tacka2.first)==true && Trougao::Poredjenje(t1.tacka2.second,t2.tacka2.second)==true) ||
           (Trougao::Poredjenje(t1.tacka1.first,t2.tacka2.first)==true && Trougao::Poredjenje(t1.tacka1.second,t2.tacka2.second)==true && Trougao::Poredjenje(t1.tacka2.first,t2.tacka1.first)==true && Trougao::Poredjenje(t1.tacka2.second,t2.tacka1.second)==true)) return true;
       }
      return false; 
   }
   bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
   
   bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

int main ()
{
    int n;
    std::cout<<"Unesite prirodan broj n: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> vektor;
    double x1,x2,x3,y1,y2,y3;

    for(int i=0; i<n; i++)
    {
        std::cout<<"Unesite x koordinatu prvog tjemena: ";
        std::cin>>x1;
        std::cout<<"Unesite y koordinatu prvog tjemena: ";
        std::cin>>y1;
        std::cout<<"Unesite x koordinatu drugog tjemena: ";
        std::cin>>x2;
        std::cout<<"Unesite y koordinatu drugog tjemena: ";
        std::cin>>y2;
        std::cout<<"Unesite x koordinatu treceg tjemena: ";
        std::cin>>x3;
        std::cout<<"Unesite y koordinatu treceg tjemena: ";
        std::cin>>y3;
        Tacka prva=std::make_pair(x1,y1);
        Tacka druga=std::make_pair(x2,y2);
        Tacka treca=std::make_pair(x3,y3); 
       std::shared_ptr<Trougao> p(new Trougao(prva,druga,treca));
        vektor.push_back(p);
    }
    
    
    
    return 0;
}