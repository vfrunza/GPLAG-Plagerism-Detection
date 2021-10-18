/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>

typedef std::pair<double, double> Tacka;

class Trougao{
    std::pair<double,double> tacka1;
    std::pair<double,double> tacka2;
    std::pair<double,double> tacka3;
        
public:
    
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tacka1=t1;
        tacka2=t2;
        tacka3=t3;
        }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
       this->tacka1=t1; this->tacka2=t2; this->tacka3=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        if(indeks>3 || indeks<1) throw std::range_error("Nekorektan unos");
        if(indeks==1) this->tacka1=t; this->tacka2=tacka2; this->tacka3=tacka3;
        if(indeks==2) this->tacka2=t; this->tacka1=tacka1; this->tacka3=tacka3;
        if(indeks==3) this->tacka3=t; this->tacka2=tacka2; this->tacka1=tacka1;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double x(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        if(x>0) return 1;
        else if(x<0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const{
       if(indeks==1) return tacka1;
       if(indeks==2) return tacka2;
       if(indeks==3) return tacka3;
    }
    double DajStranicu(int indeks) const{
       if(indeks==1) return(sqrt((tacka2.first-tacka3.first)*(tacka2.first-tacka3.first)+(tacka2.second-tacka3.second)*(tacka2.second-tacka3.second))); //a
       if(indeks==2) return(sqrt((tacka1.first-tacka3.first)*(tacka1.first-tacka3.first)+(tacka1.second-tacka3.second)*(tacka1.second-tacka3.second))); //b
       if(indeks==3) return(sqrt((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+(tacka2.second-tacka1.second)*(tacka2.second-tacka1.second))); //c
    }
    double DajUgao(int indeks) const{
       if(indeks==1) return(acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/2*DajStranicu(2)*DajStranicu(3)));
       if(indeks==2) return(acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/2*DajStranicu(1)*DajStranicu(3)));
       if(indeks==3) return(acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(1)*DajStranicu(1)-DajStranicu(3)*DajStranicu(3))/2*DajStranicu(2)*DajStranicu(1)));
       
    }
    Tacka DajCentar() const{
        
    }
    double DajObim() const{
        return(DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
        
    }
    double DajPovrsinu() const{
       return abs(tacka1.first*(tacka2.second-tacka3.second)-tacka2.first*(tacka1.second-tacka3.second)+tacka3.first*(tacka1.second-tacka2.second))/2;
    }
    bool DaLiJePozitivnoOrijentiran() const{
       bool a(true);
       if(Orijentacija(tacka1, tacka2, tacka3)<0) return false;
       else return a;
     }
    bool DaLiJeUnutra(const Tacka &t) const{
        
    }
    void Ispisi() const{
        std::cout<<"(("<<tacka1.first<<","<<tacka1.second<<") , ("<<tacka2.first<<","<<tacka2.second<<") , ("<<tacka3.first<<","<<tacka3.second<<"))";
    }
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


int main ()
{
    std::cout<<"Koliko zelite unijeti trouglova: ";
    int n;
    
	return 0;
}