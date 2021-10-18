/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>


typedef std::pair<double, double> Tacka;

const double PI=4*atan(1);


class Trougao {
    Tacka tacka1, tacka2, tacka3;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Postavi(t1, t2, t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        else { tacka1=t1; tacka2=t2; tacka3=t3; }
    }
    
    void Postavi(int indeks, const Tacka &t) {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) tacka1=t;
        if(indeks==2) tacka2=t;
        if(indeks==3) tacka3=t;
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first*(t1.second - t2.second)>0) return 1;
        if(t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) + t3.first*(t1.second - t2.second)<0) return -1;
        else return 0;
    }
    
    Tacka DajTjeme(int indeks) const {
        if(indeks==1) return tacka1;
        if(indeks==2) return tacka2;
        if(indeks==3) return tacka3;
        else { throw std::range_error("Nekorektan indeks"); }
    }
    
    double DajStranicu(int indeks) const {
        if(indeks==1) return sqrt((tacka2.second-tacka2.first)*(tacka2.second-tacka2.second) + (tacka3.second-tacka3.first)*(tacka3.second-tacka3.second));
        if(indeks==2) return sqrt((tacka1.second-tacka1.first)*(tacka1.second-tacka1.second) + (tacka3.second-tacka3.first)*(tacka3.second-tacka3.second));
        if(indeks==3) return sqrt((tacka2.second-tacka2.first)*(tacka2.second-tacka2.second) + (tacka1.second-tacka1.first)*(tacka1.second-tacka1.second));
        else { throw std::range_error("Nekorektan indeks"); }
        return 0;
    }
    double DajUgao(int indeks) const {
        if(indeks==1) return acos(-((DajStranicu(1)-DajStranicu(2)-DajStranicu(3))/2*DajStranicu(2)*DajStranicu(3)))*PI/180;
        if(indeks==2) return acos(-((DajStranicu(2)-DajStranicu(1)-DajStranicu(3))/2*DajStranicu(1)*DajStranicu(3)))*PI/180;
        if(indeks==3) return acos(-((DajStranicu(3)-DajStranicu(2)-DajStranicu(1))/2*DajStranicu(1)*DajStranicu(2)))*PI/180;
        else throw std::range_error("Nekorektan indeks");
        return 0;
    }
    Tacka DajCentar() const {
        Tacka centar;
        centar.first=(tacka1.first+tacka2.first+tacka3.first)/3;
        centar.second=(tacka1.second+tacka2.second+tacka3.second)/3;
        
        return centar;
    }
    
    double DajObim() const {
        return
        sqrt((tacka2.second-tacka2.first)*(tacka2.second-tacka2.second) + (tacka3.second-tacka3.first)*(tacka3.second-tacka3.second)) +
        sqrt((tacka1.second-tacka1.first)*(tacka1.second-tacka1.second) + (tacka3.second-tacka3.first)*(tacka3.second-tacka3.second)) +
        sqrt((tacka2.second-tacka2.first)*(tacka2.second-tacka2.second) + (tacka1.second-tacka1.first)*(tacka1.second-tacka1.second));
    }
    double DajPovrsinu() const {
       return abs(tacka1.first * (tacka2.second - tacka3.second) - tacka2.first * (tacka1.second - tacka3.second) + tacka3.first*(tacka1.second - tacka2.second))/2;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(tacka1.first * (tacka2.second - tacka3.second) - tacka2.first * (tacka1.second - tacka3.second) + tacka3.first*(tacka1.second - tacka2.second)>0 return true;
        else return false;
    }
    
    void Ispisi() const {
        std::cout << "((" << tacka1.first << "," << tacka1.second << ") , (" << tacka2.first << "," << tacka2.second << ") , (" << tacka3.first << "," << tacka3.second << "))";
    }
    void Transliraj(double delta_x, double delta_y) {
        tacka1.first=tacka1.first+delta_x;
        tacka1.seconf=tacka1.second +delta_y;
        tacka2.first=tacka2.first+delta_x;
        tacka2.second=tacka2.second+delta_y;
        tacka3.first=tacka3.first+delta_x;
        tacka3.second=tacka3.second+delta_y;
    }
    void Centriraj(const Tacka &t) {
        
    }
    
    void Rotiraj(const Tacka &t, double ugao) {
    
    }
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);


        
};
int main ()
{
    Tacka p1,p2,p3;
    int n=-1;
    while(n<=0) {
        std::cin >> n;
    }
    
    std::vector<std::shared_ptr<Trougao>> vektor;
    vektor.resize(n);
   
    
    for(int i=0; i<n; i++) {
        std::cout << "Unesite prvu koordinatu: ";
        std::cin >> p1.first >> p1.second;
        std::cout << "Unesite drugu koordinatu: ";
        std::cin >> p2.first >> p2.second;
        std::cout << "Unesite trecu koordinatu: ";
        std::cin >> p3.first >> p3.second;
        if(p1.first * (p2.second - p3.second) - p2.first * (p1.second - p3.second) + p3.first*(p1.second - p2.second)==0) {
            std::cout << "Nekorektan unos, unesite ponovo" << std::endl;
            i--;
        }
        else 
        vektor[i]=std::shared_ptr<Trougao> (new Trougao({p1.first, p1.second}, {p2.first, p2.second}, {p3.first, p3.second}) );
       
    }
    vektor[0]->Ispisi();
	return 0;
}