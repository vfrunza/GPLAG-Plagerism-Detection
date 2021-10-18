/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
#define EPS 0.0000000001

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    bool MogucnostTrougla(const Tacka &t1, const Tacka &t2, const Tacka &t3) {return abs(t1.first*t2.second + t2.first*t3.second + t3.first*t1.second - t1.first*t3.second - t3.first*t2.second -t2.first*t1.second)<EPS;}
    double Udaljenost(const Tacka &t1, const Tacka &t2) const {return sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));}
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) { if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3; }
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double orijent(t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second));
        if(orijent > 0) return 1; else if(orijent < 0) return -1; else return 0;
    }
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const{
        return {(t1.first+t2.first+t3.first)/3, (t1.second+t2.second+t3.second)/3};
    }
    double DajObim() const{
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    double DajPovrsinu() const{
        return (t1.first*t2.second + t2.first*t3.second + t3.first*t1.second - t1.first*t3.second - t3.first*t2.second -t2.first*t1.second)/2;
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(t1, t2, t3)>0) return true; return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const { std::cout << "(("<<t1.first <<","<<t1.second<<"),("<<t2.first <<","<<t2.second<<"),("<<t3.first <<","<<t3.second<<"))"; }
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
void Trougao::Skaliraj(double faktor){
    if(!faktor) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka t(DajCentar());
    t1.first = t.first + faktor*(t1.first - t.first);
    t1.second = t.second + faktor*(t1.second - t.first);
    
    t2.first = t.first + faktor*(t2.first - t.first);
    t2.second = t.second + faktor*(t2.second - t.first);
    
    t3.first = t.first + faktor*(t3.first - t.first);
    t3.second = t.second + faktor*(t3.second - t.first);
}
void Trougao::Rotiraj(double ugao){
    Tacka t(DajCentar());
    t1.first = t.first + (t1.first - t.first)*cos(ugao) - (t1.second - t.second)*sin(ugao);
    t1.second = t.second + (t1.first - t.first)*sin(ugao) + (t1.second - t.second)*cos(ugao);
    
    t2.first = t.first + (t2.first - t.first)*cos(ugao) - (t2.second - t.second)*sin(ugao);
    t2.second = t.second + (t2.first - t.first)*sin(ugao) + (t2.second - t.second)*cos(ugao);
    
    t3.first = t.first + (t3.first - t.first)*cos(ugao) - (t3.second - t.second)*sin(ugao);
    t3.second = t.second + (t3.first - t.first)*sin(ugao) + (t3.second - t.second)*cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(!faktor) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first = t.first + faktor*(t1.first - t.first);
    t1.second = t.second + faktor*(t1.second - t.first);
    
    t2.first = t.first + faktor*(t2.first - t.first);
    t2.second = t.second + faktor*(t2.second - t.first);
    
    t3.first = t.first + faktor*(t3.first - t.first);
    t3.second = t.second + faktor*(t3.second - t.first);
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    int Orijent = Orijentacija(t1, t2, t3);
    if(Orijent == Orijentacija(t1, t2, t) && Orijent == Orijentacija(t2, t3, t) && Orijent == Orijentacija(t3, t1, t)) return true;
    return false;
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    t1.first = t.first + (t1.first - t.first)*cos(ugao) - (t1.second - t.second)*sin(ugao);
    t1.second = t.second + (t1.first - t.first)*sin(ugao) + (t1.second - t.second)*cos(ugao);
    
    t2.first = t.first + (t2.first - t.first)*cos(ugao) - (t2.second - t.second)*sin(ugao);
    t2.second = t.second + (t2.first - t.first)*sin(ugao) + (t2.second - t.second)*cos(ugao);
    
    t3.first = t.first + (t3.first - t.first)*cos(ugao) - (t3.second - t.second)*sin(ugao);
    t3.second = t.second + (t3.first - t.first)*sin(ugao) + (t3.second - t.second)*cos(ugao);
}
void Trougao::Centriraj(const Tacka &t){
    Tacka centar(this->DajCentar());
    double delta_x = t.first - centar.first;
    double delta_y = t.second - centar.second;
    t1.first += delta_x; t2.first += delta_x; t3.first += delta_x;
    t1.second += delta_y; t2.second += delta_y; t3.second += delta_y;
}
void Trougao::Transliraj(double delta_x, double delta_y){
    t1.first += delta_x; t2.first += delta_x; t3.first += delta_x;
    t1.second += delta_y; t2.second += delta_y; t3.second += delta_y;
}
double Trougao::DajUgao(int indeks) const{
    switch(indeks){
        case 1: return acos((Udaljenost(t1, t2)*Udaljenost(t1, t2) + Udaljenost(t1, t3)*Udaljenost(t1, t3) - Udaljenost(t2, t3)*Udaljenost(t2, t3)) / (2 * Udaljenost(t1, t2) * Udaljenost(t1, t3)));
        case 2: return acos((Udaljenost(t1, t2)*Udaljenost(t1, t2) + Udaljenost(t2, t3)*Udaljenost(t2, t3) - Udaljenost(t1, t3)*Udaljenost(t1, t3)) / (2 * Udaljenost(t1, t2) * Udaljenost(t2, t3)));
        case 3: return acos((Udaljenost(t1, t3)*Udaljenost(t1, t3) + Udaljenost(t2, t3)*Udaljenost(t2, t3) - Udaljenost(t2, t1)*Udaljenost(t2, t1)) / (2 * Udaljenost(t1, t3) * Udaljenost(t2, t3)));
           default: throw std::range_error("Nekorektan indeks");
    }
}
double Trougao::DajStranicu(int indeks) const{
    switch(indeks){
        case 1: return Udaljenost(t2, t3);
        case 2: return Udaljenost(t1, t3);
        case 3: return Udaljenost(t1, t2);
           default: throw std::range_error("Nekorektan indeks");
    }
}
Tacka Trougao::DajTjeme(int indeks) const{
    switch(indeks){
        case 1: return t1;
        case 2: return t2;
        case 3: return t3;
           default: throw std::range_error("Nekorektan indeks");
    }
}
void Trougao::Postavi(int indeks, const Tacka &t) {
    switch(indeks){
        case 1: t1 = t; break;
        case 2: t2 = t; break;
        case 3: t3 = t; break;
           default: throw std::range_error("Nekorektan indeks");
    }
}
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1 = t1; Trougao::t2 = t2; Trougao::t3 = t3;
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if(!((t1.DajTjeme(1) == t2.DajTjeme(1)) || (t1.DajTjeme(1) == t2.DajTjeme(2)) || (t1.DajTjeme(1) == t2.DajTjeme(3)))) return false;
    if(!((t1.DajTjeme(2) == t2.DajTjeme(1)) || (t1.DajTjeme(2) == t2.DajTjeme(2)) || (t1.DajTjeme(2) == t2.DajTjeme(3)))) return false;
    if(!((t1.DajTjeme(3) == t2.DajTjeme(1)) || (t1.DajTjeme(3) == t2.DajTjeme(2)) || (t1.DajTjeme(3) == t2.DajTjeme(3)))) return false;
    return true;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::vector<double> stranice_prvog{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)};
    std::vector<double> stranice_drugog{t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
    std::sort(stranice_prvog.begin(), stranice_prvog.end());
    std::sort(stranice_drugog.begin(), stranice_drugog.end());
    if(!(stranice_prvog[0]-stranice_drugog[0]<EPS && stranice_prvog[1]-stranice_drugog[1]<EPS && stranice_prvog[2]-stranice_drugog[2]<EPS)) return false;
    if(Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)) == Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3))) return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::vector<double> stranice_prvog{t1.DajUgao(1), t1.DajUgao(2), t1.DajUgao(3)};
    std::vector<double> stranice_drugog{t2.DajUgao(1), t2.DajUgao(2), t2.DajUgao(3)};
    std::sort(stranice_prvog.begin(), stranice_prvog.end());
    std::sort(stranice_drugog.begin(), stranice_drugog.end());
    if(!(stranice_prvog[0]-stranice_drugog[0]<EPS && stranice_prvog[1]-stranice_drugog[1]<EPS && stranice_prvog[2]-stranice_drugog[2]<EPS)) return false;
    if(Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)) == Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3))) return true;
    return false;
}

int main ()
{
    std::cout << "Koliko zelite kreirati trouglova: ";
    int broj_trouglova(0); std::cin >> broj_trouglova;
    std::vector<std::shared_ptr<Trougao>> trouglovi(broj_trouglova);
    int x1, y1, x2, y2, x3, y3;
    for(int i=0; i<broj_trouglova; i++){
        try{
            std::cout << "Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> x1 >>y1 >>x2 >>y2 >>x3 >>y3;
        trouglovi.at(i) = std::make_shared<Trougao> (Trougao({x1, y1}, {x2, y2}, {x3, y3}));
        }catch(std::domain_error izuzetak){
            std::cout << izuzetak.what();
            i--;
        }
    }
    std::cout << "Unesite vektor translacije (dx dy): " << std::endl;
	return 0;
}