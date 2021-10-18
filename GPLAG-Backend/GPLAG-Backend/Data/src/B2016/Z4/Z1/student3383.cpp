/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
const double Epsilon{1E-10};

typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka x;
    Tacka y;
    Tacka z;
    static bool poredi(const Tacka x, const Tacka y){
        if(fabs(x.first - y.first) < Epsilon && fabs(x.second - y.second) < Epsilon) return true;
        return false;
    }
    static double udaljenost(const Tacka a, const Tacka b){
        return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3) == 0)throw std::domain_error("Nekorektne pozicije tjemena");
        x=t1;
        y=t2;
        z=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3) == 0)throw std::domain_error("Nekorektne pozicije tjemena");
        x=t1;
        y=t2;
        z=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) { if(Orijentacija(t,y,z) == 0)throw std::domain_error("Nekorektne pozicije tjemena"); x=t; }
        else if(indeks == 2) { if(Orijentacija(x,t,z) == 0)throw std::domain_error("Nekorektne pozicije tjemena"); y=t; }
        else if(indeks == 3) { if(Orijentacija(x,y,t) == 0)throw std::domain_error("Nekorektne pozicije tjemena"); z=t; }
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double vrati{ t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)-t3.first*(t1.second-t2.second) };
        if(vrati > 0) return 1;
        if(vrati < 0) return -1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const { 
        if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) return x;
        if(indeks == 2) return y;
        return z;
    }
    double DajStranicu(int indeks) const {
        if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) return sqrt((z.first-y.first)*(z.first-y.first) + (z.second-y.second)*(z.second-y.second));
        if(indeks == 2) return sqrt((x.first-z.first)*(x.first-z.first) + (x.second-z.second)*(x.second-z.second));
        return sqrt((y.first-x.first)*(y.first-x.first) + (y.second-x.second)*(y.second-x.second));
    }
    double DajUgao(int indeks) const {
        if(indeks != 1 && indeks!= 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
        if(indeks == 1) return std::acos( (DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1)) / (2*DajStranicu(2)*DajStranicu(3)) );
        if(indeks == 2) return std::acos( (DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2)) / (2*DajStranicu(1)*DajStranicu(3)) );
        return std::acos( (DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3)) /(2*DajStranicu(1)*DajStranicu(2)) );
    }
    Tacka DajCentar() const {
        Tacka vrati;
        vrati.first=(x.first+y.first+z.first)/3;
        vrati.second=(x.second+y.second+z.second)/3;
        return vrati;
    }
    double DajObim() const { return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); }
    double DajPovrsinu() const { return (fabs(x.first*(y.second-z.second)-y.first*(x.second-z.second)-z.first*(x.second-y.second)))/2; }
    bool DaLiJePozitivnoOrjentiran() const { if(Orijentacija(x, y, z) == 1) return true; return false; }
    bool DaLiJeUnutra(const Tacka &t) const {
        if(Orijentacija(x,y,z)==Orijentacija(x,y,t) && Orijentacija(x,y,z)==Orijentacija(x,z,t) && Orijentacija(x,y,z)==Orijentacija(y,z,t)) return true;
        return false;
    }
    void Ispisi() const { std::cout << "((" << x.first << "," << x.second << ") , (" << y.first << "," << y.second << ") , (" << z.first << "," << z.second << "))"; }
    void Transliraj(double delta_x, double delta_y) { 
        x.first+=delta_x;
        y.first+=delta_x;
        z.first+=delta_x;
        x.second+=delta_y;
        y.second+=delta_y;
        z.second+=delta_y;
    }
    void Centriraj(const Tacka &t) {
        Tacka pomoc{DajCentar()};
        double a{t.first - pomoc.first}, b{t.second - pomoc.second};
        x.first+=a;
        y.first+=a;
        z.first+=a;
        x.second+=b;
        y.second+=b;
        z.second+=b;
    }
    void Rotiraj(const Tacka &t, double ugao) {
        x.first = t.first + (x.first - t.first)*cos(ugao) - (x.second - t.second)*sin(ugao);
        y.first = t.first + (y.first - t.first)*cos(ugao) - (y.second - t.second)*sin(ugao);
        z.first = t.first + (z.first - t.first)*cos(ugao) - (z.second - t.second)*sin(ugao);
        x.second = t.second + (x.first - t.first)*sin(ugao) + (x.second - t.second)*cos(ugao);
        y.second = t.second + (y.first - t.first)*sin(ugao) + (y.second - t.second)*cos(ugao);
        z.second = t.second + (z.first - t.first)*sin(ugao) + (z.second - t.second)*cos(ugao);
    }
    void Skaliraj(const Tacka &t, double faktor) {
        if(fabs(faktor) < Epsilon)throw std::domain_error("Nekorektan faktor skaliranja");
        x.first = t.first + faktor*(x.first - t.first);
        y.first = t.first + faktor*(y.first - t.first);
        z.first = t.first + faktor*(z.first - t.first);
        x.second = t.second + faktor*(x.second - t.second);
        y.second = t.second + faktor*(y.second - t.second);
        z.second = t.second + faktor*(z.second - t.second);
    }
    void Rotiraj(double ugao) { Rotiraj(DajCentar(), ugao); }
    void Skaliraj(double faktor) { Skaliraj(DajCentar(), faktor); }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
        if( (poredi(t1.x,t2.x) && poredi(t1.y,t2.y) && poredi(t1.z,t2.z)) || (poredi(t1.x,t2.y) && poredi(t1.y,t2.z) && poredi(t1.z,t2.x)) || 
        (poredi(t1.x,t2.z) && poredi(t1.y,t2.x) && poredi(t1.z,t2.y)) ) return true;
        return false;
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
        if((((fabs(udaljenost(t1.x, t2.x) - udaljenost(t1.y,t2.y)) < Epsilon) && (fabs(udaljenost(t1.x, t2.x) - udaljenost(t1.z, t2.z)) < Epsilon)) ||
        ((fabs(udaljenost(t1.x, t2.y) - udaljenost(t1.y, t2.z)) < Epsilon) && (fabs(udaljenost(t1.x, t2.y) - udaljenost(t1.z, t2.x)) < Epsilon)) ||
        ((fabs(udaljenost(t1.x, t2.z) - udaljenost(t1.y, t2.x)) < Epsilon) && (fabs(udaljenost(t1.x, t2.z) - udaljenost(t1.z, t2.y)) < Epsilon))) && 
        (fabs(udaljenost(t1.x, t1.y) + udaljenost(t1.y, t1.z) + udaljenost(t1.z, t1.x) - udaljenost(t2.x, t2.y) - udaljenost(t2.y, t2.z) - udaljenost(t2.z, t2.x)) < Epsilon)) return true;
        return false;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
        double a1{udaljenost(t1.x, t1.y) / udaljenost(t1.y, t1.z)};
        double b1{udaljenost(t1.y, t1.z) / udaljenost(t1.z, t1.x)};
        double c1{udaljenost(t1.z, t1.x) / udaljenost(t1.x, t1.y)};
        double a2{udaljenost(t2.x, t2.y) / udaljenost(t2.y, t2.z)};
        double b2{udaljenost(t2.y, t2.z) / udaljenost(t2.z, t2.x)};
        double c2{udaljenost(t2.z, t2.x) / udaljenost(t2.x, t2.y)};
        if((fabs(a1-a2)<Epsilon && fabs(b1-b2)<Epsilon && fabs(c1-c2)<Epsilon) || 
        (fabs(a1-b2)<Epsilon && fabs(b1-c2)<Epsilon && fabs(c1-a2)<Epsilon) || 
        (fabs(a1-c2)<Epsilon && fabs(b1-a2)<Epsilon && fabs(c1-b2)<Epsilon)) return true;
        return false;
    }
};

int main (){
    std::cout << "Unesi prirodan broj n: ";
    int n;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> VPPT(n, nullptr);
/*    for(int i{0}; i<n; i++){
        Trougao vrati;
        std::cout << "Unesite koordinate tjemena x: ";
        std::cin >> vrati.x.first >> vrati.x.second;
        std::cout << "Unesite koordinate tjemena y: ";
        std::cin >> vrati.y.first >> vrati.y.second;
        std::cout << "Unesite koordinate tjemena z: ";
        std::cin >> vrati.z.first >> vrati.z.second;
        VPPT[i]=std::make_shared<Trougao> (new Trougao(vrati));
    }*/
	return 0;
}