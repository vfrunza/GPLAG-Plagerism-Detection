/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka a, b, c;
    int DajVisinu(int indeks) const {
        if(indeks>=1 && indeks<=3) {
            double s((DajStranicu(1)+DajStranicu(2)+DajStranicu(3))/2.);
            if(indeks==1) return (2*std::sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3)))) / DajStranicu(1);
            if(indeks==2) return (2*std::sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3)))) / DajStranicu(2);
            if(indeks==3) return (2*std::sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3)))) / DajStranicu(3);
        }
        else throw std::range_error("Nekorektan indeks");
    }
    static bool Uporedi(double a, double b){
        return fabs(a-b)<0.0001;
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        else{
           a=t1; b=t2; c=t3;
        }
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        else{
            a=t1; b=t2; c=t3;
        }
    }
    void Postavi(int indeks, const Tacka &t){
        if(indeks>=1 && indeks<=3){
            if(indeks==1) a=t;
            if(indeks==2) b=t;
            if(indeks==3) c=t;
        }
        else throw std::range_error("Nekorektan indeks");
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        int funkcija(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        if(funkcija>0) return 1;
        if(funkcija<0) return -1;
        if(funkcija==0) return 0;
    }
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const {
        return 0.5 * ((a.first - c.first) * (b.second - a.second) - (a.first - b.first)* (c.second - a.second));
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(a, b, c)>0) return true;
        else return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const {
        std::cout << "((" << a.first << "," << a.second << "),(" << b.first << "," << b.second << "),(" << c.first << "," << c.second << "))";
    }
    void Transliraj(double delta_x, double delta_y);
    
    void Centriraj(const Tacka &t){
        Transliraj(t.first - DajCentar().first, t.second - DajCentar().second);
    }
    
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao) { //tacka oko koje se rotira je centar
        Rotiraj(DajCentar(), ugao);
    }
    void Skaliraj(double faktor){
        Skaliraj(DajCentar(), faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);//iste koordinate
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks>=1 && indeks<=3) {
        if(indeks==1) return a;
        if(indeks==2) return b;
        if(indeks==3) return c;
    }
    else throw std::range_error("Nekorektan indeks");
}

double Trougao::DajStranicu(int indeks) const {
    if(indeks>=1 && indeks<=3){
        if(indeks==1) return std::sqrt((c.first-b.first)*(c.first-b.first)+(c.second-b.second)*(c.second-b.second));
        if(indeks==2) return std::sqrt((c.first-a.first)*(c.first-a.first)+(c.second-a.second)*(c.second-a.second));
        if(indeks==3) return std::sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
    } 
    else throw std::range_error("Nekorektan indeks");
}

double Trougao::DajUgao(int indeks) const {
    if(indeks>=1 && indeks<=3) {
        if(indeks==1) return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
        if(indeks==2) return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
        if(indeks==3) return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
    }
    else throw std::range_error("Nekorektan indeks");
}
    
Tacka Trougao::DajCentar() const {
    Tacka centar;
    centar.first=(a.first+b.first+c.first)/3.;
    centar.second=(a.second+b.second+c.second)/3.;
    return centar;
}

void Trougao::Transliraj(double delta_x, double delta_y){
    a.first=a.first+delta_x;
    a.second=a.second+delta_y;
    b.first=b.first+delta_x;
    b.second=b.second+delta_y;
    c.first=c.first+delta_x;
    c.second=c.second+delta_y;
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    a.first=t.first+(a.first-t.first)*cos(ugao) - (a.second-t.second)*sin(ugao);
    a.second=t.second+(a.first-t.first)*sin(ugao) + (a.second-t.second)*cos(ugao);
    b.first=t.first+(b.first-t.first)*cos(ugao) - (b.second-t.second)*sin(ugao);
    b.second=t.second+(b.first-t.first)*sin(ugao) + (b.second-t.second)*cos(ugao);
    c.first=t.first+(c.first-t.first)*cos(ugao) - (c.second-t.second)*sin(ugao);
    c.second=t.second+(c.first-t.first)*sin(ugao) + (c.second-t.second)*cos(ugao);
}
    
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    a.first = t.first + faktor * (a.first - t.first);
    a.second = t.second + faktor * (a.second - t.second);
    b.first = t.first + faktor * (b.first - t.first);
    b.second = t.second + faktor * (b.second - t.second);
    c.first = t.first + faktor * (c.first - t.first);
    c.second = t.second + faktor * (c.second - t.second);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if(Trougao::Uporedi(t1.DajTjeme(1).first, t2.DajTjeme(1).first) && Trougao::Uporedi(t1.DajTjeme(1).second, t2.DajTjeme(1).second)){
        if(Trougao::Uporedi(t1.DajTjeme(2).first, t2.DajTjeme(2).first) && Trougao::Uporedi(t1.DajTjeme(2).second, t2.DajTjeme(2).second)){
            if(Trougao::Uporedi(t1.DajTjeme(3).first, t2.DajTjeme(3).first) && Trougao::Uporedi(t1.DajTjeme(3).second, t2.DajTjeme(3).second))
                return true;
            return false;
        }
        if(Trougao::Uporedi(t1.DajTjeme(2).first, t2.DajTjeme(2).first) && Trougao::Uporedi(t1.DajTjeme(3).second, t2.DajTjeme(3).second)){
            if(Trougao::Uporedi(t1.DajTjeme(3).first, t2.DajTjeme(3).first) && Trougao::Uporedi(t1.DajTjeme(2).second, t2.DajTjeme(2).second))
                return true;
            return false;
        }
        return false;
    }
}

int main () {
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    Tacka a, b, c;
    std::vector<std::shared_ptr<Trougao>> trouglovi(n);
    try{
        for(int i(0); i<n; i++) {
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
            try{
                Trougao* t=new Trougao(a, b, c);
                trouglovi[i]=std::make_shared<Trougao> (*t);
            }
            catch(std::domain_error d) {
                std::cout << d.what() << std::endl;
                i--;
            }
            
        }
        std::cout << "Unesi delta_x i delta_y: ";
        double delta_x, delta_y;
        std::cin >> delta_x >> delta_y;
        double ugao, faktor;
        std::cout << "Unesite ugao rotacije: ";
        std::cin >> ugao;
        std::cout << "Unesite faktor skaliranja: ";
        std::cin >> faktor;
        
        std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [=](std::shared_ptr<Trougao> pok) {
           pok->Transliraj(delta_x, delta_y);
           pok->Rotiraj(ugao);
           pok->Skaliraj(pok->DajTjeme(1), faktor);
           return pok;
        });
        std::sort(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
            return t1->DajPovrsinu() < t2->DajPovrsinu();
        });
        std::for_each(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> t) { t->Ispisi(); std::cout << std::endl; });
    }
    catch(std::range_error r){
        std::cout << r.what() << std::endl;
    }
    
	return 0;
}