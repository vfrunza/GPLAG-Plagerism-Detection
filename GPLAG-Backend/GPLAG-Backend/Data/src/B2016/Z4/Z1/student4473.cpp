/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <algorithm>
typedef std::pair<double,double> Tacka;
class Trougao{
    std::vector<Tacka> t;
    static int Test(const Tacka &t1, const Tacka &t2, const Tacka &t3){
      return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);  
    };
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        //iskoristiti Orijentaciju
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije");
        Postavi(t1,t2,t3);}
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije");
        t.push_back(t1);
        t.push_back(t2);
        t.push_back(t3);
    }
    void Postavi(int indeks, const Tacka &tt){
        if(indeks<1 or indeks>3) throw std::domain_error("Nekorektan indeks");
        t[indeks-1]=tt;
        if(Orijentacija(t[0],t[1],t[2])==0) throw std::domain_error("Nekorektne pozicije");
        
    }
    static int Orijentacija ( const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const{
        if(indeks<1 or indeks>3) throw std::domain_error("Nekorektan indeks");
        return t[indeks-1];
    }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const{
        return std::make_pair((t[0].first+t[1].first+t[2].first)/3,(t[0].second+t[1].second+t[2].second)/3);
    }
    double DajObim() const{
        return this->DajStranicu(1)+this->DajStranicu(2)+this->DajStranicu(3);
    }
    double DajPovrsinu() const{
        
    }
    bool DaLiJePozitivnoOrijentiran () const{
        if(Orijentacija(t[0],t[1],t[2])==-1) return false;
        else return Orijentacija(t[0],t[1],t[2]);
    }
    bool DaLiJeUnutra(const Tacka &t);
    void Ispisi() const;
    void Transliraj(double delta_x,double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t,double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
    
};
int main ()
{
	return 0;
}