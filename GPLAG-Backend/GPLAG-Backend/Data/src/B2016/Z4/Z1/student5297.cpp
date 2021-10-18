/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <map>
#include <algorithm>

typedef std::pair<double, double> Tacka;

const double EPS(1e-10);

class Trougao {
    Tacka tjeme1, tjeme2, tjeme3;
public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tjeme1=t1; tjeme2=t2; tjeme3=t3; 
    }
    void Postavi (int indeks, const Tacka &t) {
        if(!(indeks>=1 && indeks<=3)) throw std::range_error("Nekorektan indeks");
        if(indeks==1) { if(Orijentacija(t, tjeme2, tjeme3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); tjeme1=t; }
        else if(indeks==2) { if(Orijentacija(tjeme1, t, tjeme3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); tjeme2=t; }
        else if(indeks==3) { if(Orijentacija(tjeme1, tjeme2, t)==0) throw std::domain_error("Nekorektne pozicije tjemena"); tjeme3=t; }
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double orijentacija(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        if(orijentacija>0) return 1;
        else if(orijentacija<0) return -1;
        /*else if(orijentacija==0)*/ else return 0;
    }
    Tacka DajTjeme (int indeks) const {  
        if(indeks==1) return tjeme1;
        else if(indeks==2) return tjeme2;
        /*else if(indeks==3)*/ return tjeme3;
    }
    double DajStranicu (int indeks) const {
        if(indeks==1) return(std::sqrt(std::pow((tjeme2.first-tjeme3.first), 2)+std::pow((tjeme2.second-tjeme3.second), 2)));
        else if(indeks==2) return(std::sqrt(std::pow((tjeme1.first-tjeme3.first), 2)+std::pow((tjeme2.second-tjeme3.second), 2)));
        /*else if(indeks==3)*/ return(std::sqrt(std::pow((tjeme1.first-tjeme2.first), 2)+std::pow((tjeme1.second-tjeme2.second), 2)));
    }
    double DajUgao (int indeks) const {
        if(indeks==1) return std::acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(3)*DajStranicu(2)))*(180./(4*std::atan(1)));
        else if(indeks==2) return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)))*(180./(4*std::atan(1)));
        /*else if(indeks==3)*/ return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)))*(180./(4*std::atan(1)));
    }
    Tacka DajCentar() const {
        return std::make_pair((tjeme1.first+tjeme2.first+tjeme3.first)/3, (tjeme1.second+tjeme2.second+tjeme3.second)/3);
    }
    double DajObim() const {
        return (DajStranicu(1)+DajStranicu(2)+DajStranicu(2));
    }
    double DajPovrsinu() const {
        double s=DajObim()/2.;
        return (std::sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3))));
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(tjeme1, tjeme2, tjeme3)==1) return true;
        return false;
    }
    bool DaLiJeUnutra (const Tacka &t) const;
    void Ispisi() const {
        std::cout << "((" << tjeme1.first << "," << tjeme1.second << "),(" << tjeme2.first << "," << tjeme2.second << "),(" << tjeme3.first << "," << tjeme3.second << "))" << std::endl;
    }
    void Transliraj (double delta_x, double delta_y);
    void Centriraj (const Tacka &t);
    void Rotiraj (const Tacka &t, double ugao);
    void Skaliraj (const Tacka &t, double faktor);
    void Rotiraj (double ugao) {
        Tacka teziste(DajCentar());
        Rotiraj(teziste, ugao);
    }
    void Skaliraj (double faktor) {
        Tacka teziste(DajCentar());
        Skaliraj(teziste, faktor);
    }
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};

bool Trougao::DaLiJeUnutra (const Tacka &t) const {
    if(Orijentacija(tjeme1, tjeme2, tjeme3)==1) {
        if(Orijentacija(tjeme1, tjeme2, t)==1 && Orijentacija(tjeme2, tjeme3, t)==1 && Orijentacija(tjeme3, tjeme1, t)==1) return true;
        else return false;
    }
    else if(Orijentacija(tjeme1, tjeme2, tjeme3)==-1) {
        if(Orijentacija(tjeme1, tjeme2, t)==-1 && Orijentacija(tjeme2, tjeme3, t)==-1 && Orijentacija(tjeme3, tjeme1, t)==-1) return true;
        else return false;
    }
    return false;
}

void Trougao::Transliraj (double delta_x, double delta_y) {
    tjeme1.first+=delta_x; tjeme1.second+=delta_y;
    tjeme2.first+=delta_x; tjeme2.second+=delta_y;
    tjeme3.first+=delta_x; tjeme3.second+=delta_y;
}

void Trougao::Centriraj (const Tacka &t) {
    Tacka teziste(DajCentar());
    double delta_x(t.first-teziste.first), delta_y(t.second-teziste.second);
    Transliraj(delta_x, delta_y);
}

void Trougao::Rotiraj (const Tacka &t, double ugao) {
    tjeme1.first=t.first+(tjeme1.first-t.first)*std::cos(ugao)-(tjeme1.second-t.second)*std::sin(ugao);
    tjeme1.second=t.second+(tjeme1.first-t.first)*std::sin(ugao)+(tjeme1.second-t.second)*std::cos(ugao);
    tjeme2.first=t.first+(tjeme2.first-t.first)*std::cos(ugao)-(tjeme2.second-t.second)*std::sin(ugao);
    tjeme2.second=t.second+(tjeme2.first-t.first)*std::sin(ugao)+(tjeme2.second-t.second)*std::cos(ugao);
    tjeme3.first=t.first+(tjeme3.first-t.first)*std::cos(ugao)-(tjeme3.second-t.second)*std::sin(ugao);
    tjeme3.second=t.second+(tjeme3.first-t.first)*std::sin(ugao)+(tjeme3.second-t.second)*std::cos(ugao);
}

void Trougao::Skaliraj (const Tacka &t, double faktor) {
    if(std::fabs(faktor-0)<EPS) throw std::domain_error("Nekorektan faktor skaliranja");
    tjeme1.first=t.first+faktor*(tjeme1.first-t.first); tjeme1.second=t.second+faktor*(tjeme1.second-t.second);
    tjeme2.first=t.first+faktor*(tjeme2.first-t.first); tjeme2.second=t.second+faktor*(tjeme2.second-t.second);
    tjeme3.first=t.first+faktor*(tjeme3.first-t.first); tjeme3.second=t.second+faktor*(tjeme3.second-t.second);
    if(faktor<0) {
        Rotiraj(t, 180);
    }
}

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2) {
    if((t1.tjeme1==t2.tjeme1 || t1.tjeme1==t2.tjeme2 || t1.tjeme1==t2.tjeme3) && (t1.tjeme2==t2.tjeme1 || t1.tjeme2==t2.tjeme2 || t1.tjeme2==t2.tjeme3) && 
                            (t1.tjeme3==t2.tjeme1 || t1.tjeme3==t2.tjeme2 || t1.tjeme3==t2.tjeme3)) return true;
    return false;
}

bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2) {
    double a1=t1.DajStranicu(1), b1=t1.DajStranicu(2), c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1), b2=t2.DajStranicu(2), c2=t2.DajStranicu(3);
    if((a1==a2 || a1==b2 || a1==c2) && (b1==a2 || b1==b2 || b1==c2) && (c1==a2 || c1==b2 || c1==c2)) {
        double delta_x=t1.tjeme1.first-t2.tjeme1.first;
        double delta_y=t1.tjeme1.second-t2.tjeme1.second;
        Trougao tpomocni1=t1;
        tpomocni1.Transliraj(delta_x, delta_y);
        if(DaLiSuIdenticni(tpomocni1, t2)) {
            Trougao tpomocni2=t1;
            tpomocni2.Rotiraj(360);
            if(DaLiSuIdenticni(tpomocni2, t2)) {
                Trougao tpomocni3=t1;
                tpomocni3.Skaliraj()
            }
        }
    }
    return false;
}

bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2) {
    double a1=DajStranicu(1), b1=DajStranicu(2), c1=DajStranicu(3);
    double a2=DajStranicu(1), b2=DajStranicu(2), c2=DajStranicu(3);
    if((c1/c2)==(b1/b2) && (b1/b2)==(a1/a2)) {
        double delta_x=t1.tjeme1.first-t2.tjeme1.first;
        double delta_y=t1.tjeme1.second-t2.tjeme1.second;
        Trougao t=t1;
        t.Transliraj(delta_x, delta_y);
        if(DaLiSuIdenticni(t, t2)) {
            t.Rotiraj(360);
            if(DaLiSuIdenticni())
        }
    }
    return false;
}

int main () {
    std::cout << "Koliko zelite kreirati trouglova: ";
    double n;
    std::cin >> n;
    try {
        std::vector<std::shared_ptr<Trougao>> vektor(n);
        for(int i(0); i<10; i++) {
            std::cout << "Unesite podatke za " << i+1 << " trougao (x1 y1 x2 y2 x3 y3):";
            std::vector<double> tjemena;
            for(int j(0); j<3; j++) {
                double x, y;
                std::cin >> x >> y;
                
                tjemena.push_back(x);
                tjemena.push_back(y);
            }
            Tacka t1, t2, t3;
            t1.first=tjemena[0]; t1.second=tjemena[1];
            t2.first=tjemena[2]; t2.second=tjemena[3];
            t3.first=tjemena[4]; t3.second=tjemena[5];
            try {
                vektor[i]=std::make_shared<Trougao>(t1, t2, t3);
            } catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
                i--;
            } catch(...) {
                throw;
            }
        }
        double ugao, faktor, deltax, deltay;
        std::cout << "Unesite vektor translacije (dx dy): "; std::cin >> deltax >> deltay;
        std::cout << "Unesite ugao rotacije: "; std::cin >> ugao;
        std::cout << "Unesite faktor skaliranja: "; std::cin >> faktor;
        std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
        std::transform(vektor.begin(), vektor.end(), vektor.begin(), [=] (std::shared_ptr<Trougao> t){
            t->Transliraj(deltax, deltay);
            t->Rotiraj(ugao);
            try {
                t->Skaliraj(t->DajTjeme(1), faktor);
            } catch (std::domain_error izuzetak) {
                std::cout << izuzetak.what() << std::endl;
            }
            return t;
        });
        std::sort(vektor.begin(), vektor.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
           return (t1->DajPovrsinu()<t2->DajPovrsinu());
        });
        std::for_each(vektor.begin(), vektor.end(), [] (std::shared_ptr<Trougao> t) {
            std::cout << "((" << t->DajTjeme(1).first << "," << t->DajTjeme(1).second << "),(" << t->DajTjeme(2).first << "," << t->DajTjeme(2).second << "),(" << t->DajTjeme(3).first << "," << t->DajTjeme(3).second << "))" << std::endl;
        });
        std::shared_ptr<Trougao> najmanji= *(std::min_element(vektor.begin(), vektor.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
           return t1->DajObim()<t2->DajObim(); 
        }));
        std::cout << "Trougao sa najmanjim obimom: ((" << najmanji->DajTjeme(1).first << "," << najmanji->DajTjeme(1).second << "),(" << najmanji->DajTjeme(2).first << "," << najmanji->DajTjeme(2).second << "),(" << najmanji->DajTjeme(3).first << "," << najmanji->DajTjeme(3).second << "))" << std::endl;
    } catch (...) {
        std::cout << "bla" << std::endl;
    }
  	return 0;
}