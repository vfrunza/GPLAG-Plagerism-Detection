#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

#define EPS 0.00000000001

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka a, b, c;
    static double Izraz(Tacka a, Tacka b, Tacka c) { 
        return a.first*(b.second-c.second)-b.first*(a.second-c.second)+c.first*(a.second-b.second);
    }
    static double DuzinaStranice(Tacka t1, Tacka t2) { 
        return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
    static double Ugao(Tacka A, Tacka B, Tacka C) { 
        return std::acos((DuzinaStranice(A,C)*DuzinaStranice(A,C)+DuzinaStranice(A, B)*DuzinaStranice(A, B)
        -DuzinaStranice(B, C)*DuzinaStranice(B, C))/(2*DuzinaStranice(A, C)*DuzinaStranice(A,B)));
    }
    static bool Jednaki(double a, double b) {
        return std::fabs(a-b)<EPS;
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { 
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        a=t1; b=t2; c=t3; 
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        a=t1; b=t2; c=t3;
    }
    
    void Postavi(int indeks, const Tacka &t) { 
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) a=t; if(indeks==2) b=t; if(indeks==3) c=t; 
        if(Orijentacija(a, b, c)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Izraz(t1, t2, t3)>0) return 1;
        if(Izraz(t1, t2, t3)<0) return -1;
        else return 0; 
    }
    
    Tacka DajTjeme(int indeks) const { 
        if(indeks==1) return a; if(indeks==2) return b; if(indeks==3) return c; 
        throw std::range_error("Nekorektan indeks"); 
    }
    
    double DajStranicu(int indeks) const { 
        if(indeks==1) return DuzinaStranice(b, c); 
        if(indeks==2) return DuzinaStranice(a, c);
        if(indeks==3) return DuzinaStranice(a, b); 
        throw std::range_error("Nekorektan indeks"); 
    }
    
    double DajUgao(int indeks) const { 
        if(indeks==1) return Ugao(a, b, c); 
        if(indeks==2) return Ugao(b, a, c);
        if(indeks==3) return Ugao(c, a, b); 
        throw std::range_error("Nekorektan indeks"); 
    }
                                        
    Tacka DajCentar() const { 
        return {(a.first+b.first+c.first)/3, (a.second+b.second+c.second)/3}; 
    }
    
    double DajObim() const { return DuzinaStranice(a, b)+DuzinaStranice(a, c)+DuzinaStranice(c, b); }
    
    double DajPovrsinu() const { return std::fabs(Izraz(a, b, c))/2; }
    
    bool DaLiJePozitivnoOrijentiran() const { if(Orijentacija(a, b, c)==1) return true; return false; }
    
    bool DaLiJeUnutra(const Tacka &t) const {
        return Orijentacija(a, b, c)==Orijentacija(a, b, t) && Orijentacija(a, b, t)==Orijentacija(b, c, t) 
               && Orijentacija(b, c, t)==Orijentacija(c, a, t);
    }
    
    void Ispisi() const { 
        std::cout << "((" << a.first << "," << a.second << "),(" << b.first << "," 
                  << b.second << "),(" << c.first << "," << c.second << "))"; 
    }
    
    void Transliraj(double delta_x, double delta_y) { 
        a.first+=delta_x; b.first+=delta_x; c.first+=delta_x;
        a.second+=delta_y; b.second+=delta_y; c.second+=delta_y; 
    }
    
    void Centriraj(const Tacka &t) {
        double x(t.first-(this->DajCentar()).first);
        double y(t.second-(this->DajCentar()).second);
        Transliraj(x, y);
    }
                                
    void Rotiraj(const Tacka &t, double ugao) {
        double x(a.first), y(a.second);
        a.first=(t.first+(x-t.first)*std::cos(ugao)-(y-t.second)*std::sin(ugao));
        a.second=(t.second+(x-t.first)*std::sin(ugao)+(y-t.second)*std::cos(ugao));
        x=b.first; y=b.second;
        b.first=(t.first+(x-t.first)*std::cos(ugao)-(y-t.second)*std::sin(ugao));
        b.second=(t.second+(x-t.first)*std::sin(ugao)+(y-t.second)*std::cos(ugao));
        x=c.first; y=c.second;
        c.first=(t.first+(x-t.first)*std::cos(ugao)-(y-t.second)*std::sin(ugao));
        c.second=(t.second+(x-t.first)*std::sin(ugao)+(y-t.second)*std::cos(ugao));
    }
    
    void Skaliraj(const Tacka &t, double faktor) {
        if(Jednaki(faktor, 0)) throw std::domain_error ("Nekorektan faktor skaliranja");
        a.first=t.first+faktor*(a.first-t.first);
        a.second=t.second+faktor*(a.second-t.second);
        b.first=t.first+faktor*(b.first-t.first);
        b.second=t.second+faktor*(b.second-t.second);
        c.first=t.first+faktor*(c.first-t.first);
        c.second=t.second+faktor*(c.second-t.second);
    }
    
    void Rotiraj(double ugao) { Rotiraj(DajCentar(), ugao); }
    
    
    void Skaliraj(double faktor) { Skaliraj(DajCentar(), faktor); }
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if(!(t1.a==t2.a || t1.a==t2.b || t1.a==t2.c)) return false;
    if(!(t1.b==t2.a || t1.b==t2.b || t1.b==t2.c)) return false;
    if(!(t1.c==t2.a || t1.c==t2.b || t1.c==t2.c)) return false;
    return true;
}
    
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    if(!(Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(1)) || Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(2)) 
        || Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(3)))) return false; 
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.a, t2.b, t2.c)) {
        if(Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(2)) 
        && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(3))) return true;
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.a, t2.c, t2.b)) {
        if(Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(3)) 
        && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(2))) return true;
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.b, t2.a, t2.c)) {
        if(Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(2)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(1)) 
        && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(3))) return true;
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.b, t2.c, t2.a)) {
        if(Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(2)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(3)) 
        && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(1))) return true;
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.c, t2.a, t2.b)) {
        if(Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(3)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(1)) 
        && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(2))) return true;
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.c, t2.b, t2.a)) {
        if(Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(3)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(2)) 
        && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(1))) return true;
    }
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    if(!(Trougao::Jednaki(t1.DajUgao(1), t2.DajUgao(1)) || Trougao::Jednaki(t1.DajUgao(1), t2.DajUgao(2)) 
    || Trougao::Jednaki(t1.DajUgao(1), t2.DajUgao(3)))) return false;
    
    if(!(Trougao::Jednaki(t1.DajUgao(2), t2.DajUgao(1)) || Trougao::Jednaki(t1.DajUgao(2), t2.DajUgao(2)) 
    || Trougao::Jednaki(t1.DajUgao(2), t2.DajUgao(3)))) return false;
    
    if(!(Trougao::Jednaki(t1.DajUgao(3), t2.DajUgao(1)) || Trougao::Jednaki(t1.DajUgao(3), t2.DajUgao(2)) 
    || Trougao::Jednaki(t1.DajUgao(3), t2.DajUgao(3)))) return false;    
    
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.a, t2.b, t2.c)) {
        if(Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(1), t1.DajStranicu(2)/t2.DajStranicu(2)) 
        && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(2),t1.DajStranicu(3)/t2.DajStranicu(3))) 
        return true;
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.a, t2.c, t2.b)) {
        if(Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(1), t1.DajStranicu(2)/t2.DajStranicu(3)) 
        && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(3),t1.DajStranicu(3)/t2.DajStranicu(2))) 
        return true;
        
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.b, t2.a, t2.c)) {
        if(Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(2), t1.DajStranicu(2)/t2.DajStranicu(1)) 
        && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(1),t1.DajStranicu(3)/t2.DajStranicu(3))) 
        return true;
        
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.b, t2.c, t2.a)) {
        if(Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(2), t1.DajStranicu(2)/t2.DajStranicu(3)) 
        && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(3),t1.DajStranicu(3)/t2.DajStranicu(1))) 
        return true;
        
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.c, t2.a, t2.b)) {
        if(Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(3), t1.DajStranicu(2)/t2.DajStranicu(1)) 
        && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(1),t1.DajStranicu(3)/t2.DajStranicu(2))) 
        return true;
    }
    if(Trougao::Orijentacija(t1.a, t1.b, t1.c)==Trougao::Orijentacija(t2.c, t2.b, t2.a)) {
        if(Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(3), t1.DajStranicu(2)/t2.DajStranicu(2)) 
        && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(2),t1.DajStranicu(3)/t2.DajStranicu(1))) 
        return true;
    }
    return false;
}


int main () {
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i=0; i<n; i++) {
        try {
            double x1, x2, x3, y1, y2, y3;
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            v[i]=std::make_shared<Trougao>(Trougao({x1, y1}, {x2, y2}, {x3, y3}));
        } catch(std::domain_error e) {
            std::cout << e.what() << ", ponovite unos!\n"; 
            i--;
        }
    }
    std::cout << "Unesite vektor translacije (dx dy): ";
    {  double x, y, z, w;
       std::cin >> x >> y;
       std::cout << "Unesite ugao rotacije: ";
       std::cin >> z;
       std::cout << "Unesite faktor skaliranja: ";
       std::cin >> w;
       std::transform(v.begin(), v.end(), v.begin(), [x,y,z,w] (std::shared_ptr<Trougao> p) {
                                                       p->Transliraj(x, y);
                                                       p->Rotiraj(z);
                                                       p->Skaliraj(p->DajTjeme(1), w);
                                                       return p; } );
    }
    
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
        return (p1->DajPovrsinu()) < (p2->DajPovrsinu()); });
        
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;    
    std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Trougao> p) { p->Ispisi(); std::cout << std::endl; }); 
{    auto p(std::min_element(v.begin(), v.end(), [] (std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
        return p1->DajObim() < p2->DajObim();
    }));
    std::cout << "Trougao sa najmanjim obimom: ";
    (*p)->Ispisi();
}
{    int brojac(0);
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(DaLiSuIdenticni(*v[i], *v[j])) {
                brojac++;
                break;
            }
        }
        if(brojac>0) break;
    }
    if(brojac==0) std::cout << "\nNema identicnih trouglova!" << std::endl;
    else std::cout << "\nParovi identicnih trouglova:" << std::endl;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(DaLiSuIdenticni(*v[i], *v[j])) {
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
}
{   int brojac(0);
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(DaLiSuPodudarni(*v[i], *v[j])) {
                brojac++;
                break;
            }
        }
        if(brojac>0) break;
    }
    if(brojac==0) std::cout << "Nema podudarnih trouglova!" << std::endl;
    else std::cout << "Parovi podudarnih trouglova:" << std::endl;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(DaLiSuPodudarni(*v[i], *v[j])) {
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
}
{   int brojac(0);
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(DaLiSuSlicni(*v[i], *v[j])) {
                brojac++;
                break;
            }
        }
        if(brojac>0) break;
    }
    if(brojac==0) std::cout << "Nema slicnih trouglova!" << std::endl;
    else std::cout << "Parovi slicnih trouglova:" << std::endl;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(DaLiSuSlicni(*v[i], *v[j])) {
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
} 
	return 0;
}