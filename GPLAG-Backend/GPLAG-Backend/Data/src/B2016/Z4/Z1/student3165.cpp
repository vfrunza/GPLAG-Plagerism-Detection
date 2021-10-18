/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

typedef std::pair<double, double> Tacka;
class Trougao {
   Tacka t1, t2, t3;
   Tacka RotiranaTacka(Tacka &t, const Tacka &tacka_rotacije, double ugao) {
       double kosinus=std::cos(ugao), sinus=std::sin(ugao);
       Tacka a;
       a.first=tacka_rotacije.first+(t.first-tacka_rotacije.first)*kosinus-(t.second-tacka_rotacije.second)*sinus;
       a.second=tacka_rotacije.second+(t.first-tacka_rotacije.first)*sinus+(t.second-tacka_rotacije.second)*kosinus;
       return a;
   }
   static bool Poredi(double x, double y, double Eps=1e-10) {
       if((x>0 && y<0) || (x<0 && y>0)) return false;
       return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
   }
   Tacka SkaliranaTacka(Tacka &t, const Tacka &centar_skaliranja, double faktor) {
       Tacka a;
       a.first=centar_skaliranja.first+faktor*(t.first-centar_skaliranja.first);
       a.second=centar_skaliranja.second+faktor*(t.second-centar_skaliranja.second);
       return a;
   }
   static bool IsteTacke(const Tacka &t1, const Tacka &t2) {
       if(Poredi(t1.first, t2.first) && Poredi(t1.second, t2.second)) return true;
       return false;
   }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); 
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const {return std::make_pair((t1.first+t2.first+t3.first)/3,(t1.second+t2.second+t3.second)/3);}
    double DajObim() const {
        double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
        return a+b+c;
    }
    double DajPovrsinu() const {return (1./2)*std::abs(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));}
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(t1, t2, t3)==1) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        int n=Orijentacija(t1,t2,t3);
        if(n==Orijentacija(t1,t2,t) && n==Orijentacija(t2,t3,t) && n==Orijentacija(t3,t1,t)) return true;
        return false;
    }
    void Ispisi() const {
        std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) {
        t1.first+=delta_x; t1.second+=delta_y;
        t2.first+=delta_x; t2.second+=delta_y;
        t3.first+=delta_x; t3.second+=delta_y;
    }
    void Centriraj(const Tacka &t) {
        Tacka centar=DajCentar();
        Transliraj(t.first-centar.first, t.second-centar.second);
    }
    void Rotiraj(const Tacka &t, double ugao) {
        t1=RotiranaTacka(t1, t, ugao);
        t2=RotiranaTacka(t2, t, ugao);
        t3=RotiranaTacka(t3, t, ugao);
    }
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao) {
        Tacka tacka_rotacije=DajCentar();
        Rotiraj(tacka_rotacije, ugao);
    }
    void Skaliraj(double faktor) {
        Tacka centar=DajCentar();
        Skaliraj(centar, faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
void Trougao::Postavi(int indeks, const Tacka &t) {
    if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
    if(indeks==1) t1=t;
    else if(indeks==2) t2=t;
    else t3=t;
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double pom=t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
    if(pom>0) return 1;
    if(pom<0) return -1;
    return 0;
}
Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return t1;
    if(indeks==2) return t2;
    return t3;
}
double Trougao::DajStranicu(int indeks) const {
    if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return std::sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
    if(indeks==2) return std::sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
    return std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
}
double Trougao::DajUgao(int indeks) const {
    double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
    if(indeks==1) return std::acos((a*a-b*b-c*c)/(-2*b*c));
    if(indeks==2) return std::acos((b*b-a*a-c*c)/(-2*a*c));
    return std::acos((c*c-b*b-a*a)/(-2*b*a));
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(Poredi(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    t1=SkaliranaTacka(t1, t, faktor);
    t2=SkaliranaTacka(t2, t, faktor);
    t3=SkaliranaTacka(t3, t, faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    std::vector<Tacka> a={t1.t1, t1.t2, t1.t3}, b={t2.t1, t2.t2, t2.t3};
    int brojac(0);
    for(int i(0); i<3; i++) {
        for(int j(0); j<3; j++) {
            if(Trougao::IsteTacke(a[i], b[j])) {
                brojac++;
                break;
            }
        }
        if(brojac<=i) return false;
    }
    return true;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> a={t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)}, b={t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
    int brojac(0);
    std::vector<int> c;
    for(int i(0); i<3; i++) {
        for(int j(0); j<3; j++) {
            if(Trougao::Poredi(a[i], b[j])) {
                c.push_back(j+1); //u vektoru c pamtimo poziciju tjemena 2. trougla, koji su odgovarajuci tjemenima 1. trougla 
                brojac++;           //to će nam posluziti kako bi funkcija orijentacija imala isti redoslijed odg tjemena kod oba trougla 
                break;
            }
        }
        if(brojac<=i) return false;
    }
    if(Trougao::Orijentacija(t1.t1, t1.t2, t1.t3)==Trougao::Orijentacija(t2.DajTjeme(c[0]), t2.DajTjeme(c[1]), t2.DajTjeme(c[2]))) return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> a={t1.DajUgao(1), t1.DajUgao(2), t1.DajUgao(3)}, b={t2.DajUgao(1), t2.DajUgao(2), t2.DajUgao(3)};
    std::vector<int> c;
    int brojac(0);
    for(int i(0); i<3; i++) {
        for(int j(0); j<3; j++) {
            if(Trougao::Poredi(a[i], b[j])) {
                c.push_back(j+1);
                brojac++;
                break;
            }
        }
        if(brojac<=i) return false;
    }
    if(Trougao::Poredi(t1.DajStranicu(1),t2.DajStranicu(c[0])) && Trougao::Poredi(t1.DajStranicu(2), t2.DajStranicu(c[1])) && Trougao::Poredi(t1.DajStranicu(3), t2.DajStranicu(c[2])) && !DaLiSuPodudarni(t1, t2)) return false;
    return true;
}

int main ()
{
    try {
        int n(0);
        std::cout<<"Koliko zelite kreirati trouglova: ";
        std::cin>>n;
        std::vector<std::shared_ptr<Trougao>> p(n);
        for(int i(0); i<n; i++) {
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka a,b,c;
            std::cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
            try {
                p[i]=std::make_shared<Trougao> (a,b,c);
            }
            catch(std::domain_error e) {
                std::cout<<e.what()<<", ponovite unos!"<<std::endl;
                i--;
            }
        }
        std::cout<<"Unesite vektor translacije (dx dy): ";
        double dx, dy;
        std::cin>>dx>>dy;
        std::cout<<"Unesite ugao rotacije: ";
        double ugao;
        std::cin>>ugao;
        std::cout<<"Unesite faktor skaliranja: ";
        double faktor;
        std::cin>>faktor;
        std::transform(p.begin(), p.end(), p.begin(), [dx,dy] (std::shared_ptr<Trougao> t) {t->Transliraj(dx,dy); return t;});
        std::transform(p.begin(), p.end(), p.begin(), [ugao] (std::shared_ptr<Trougao> t) {t->Rotiraj(ugao); return t;});
        std::transform(p.begin(), p.end(), p.begin(), [faktor] (std::shared_ptr<Trougao> t) {t->Skaliraj(t->DajTjeme(1), faktor); return t;});
        std::sort(p.begin(), p.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {return t1->DajPovrsinu()<t2->DajPovrsinu();});
        std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
        std::for_each(p.begin(), p.end(), [] (std::shared_ptr<Trougao> t) {t->Ispisi(); std::cout<<std::endl;});
        auto min=std::min_element(p.begin(), p.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {return t1->DajObim()<t2->DajObim();});
        std::cout<<"Trougao sa najmanjim obimom: ";
        if(n!=0) (*min)->Ispisi();
        std::vector<std::pair<Trougao, Trougao>> vektor;
        for(int i=0; i<p.size(); i++) 
            for(int j=i+1; j<p.size(); j++) 
                if(DaLiSuIdenticni(*p[i],*p[j])) {vektor.push_back(std::make_pair(*p[i], *p[j]));}
        if(vektor.size()==0) std::cout<<"\nNema identicnih trouglova!\n";
        else {
            std::cout<<"\nParovi identicnih trouglova:\n";
            for(int i(0); i<vektor.size(); i++) {
                vektor[i].first.Ispisi();
                std::cout<<" i ";
                vektor[i].second.Ispisi();
                std::cout<<std::endl;
            }
        }
        std::vector<std::pair<Trougao, Trougao>> vektor2;
        for(int i=0; i<p.size(); i++) 
            for(int j=i+1; j<p.size(); j++) 
                if(DaLiSuPodudarni(*p[i],*p[j])) {vektor2.push_back(std::make_pair(*p[i], *p[j]));}
        if(vektor2.size()==0) std::cout<<"Nema podudarnih trouglova!\n";
        else {
            std::cout<<"Parovi podudarnih trouglova:\n";
            for(int i(0); i<vektor2.size(); i++) {
                vektor2[i].first.Ispisi();
                std::cout<<" i ";
                vektor2[i].second.Ispisi();
                std::cout<<std::endl;
            }
        }
        std::vector<std::pair<Trougao, Trougao>> vektor3;
        for(int i=0; i<p.size(); i++) 
            for(int j=i+1; j<p.size(); j++) 
                if(DaLiSuSlicni(*p[i],*p[j])) {vektor3.push_back(std::make_pair(*p[i], *p[j]));}
        if(vektor3.size()==0) std::cout<<"Nema slicnih trouglova!\n";
        else {
            std::cout<<"Parovi slicnih trouglova:\n";
            for(int i(0); i<vektor3.size(); i++) {
                vektor3[i].first.Ispisi();
                std::cout<<" i ";
                vektor3[i].second.Ispisi();
                std::cout<<std::endl;
            }
        }
    }
    catch(std::domain_error poruka) {
        std::cout<<poruka.what();
    }
    catch(std::range_error e) {
        std::cout<<e.what();
    }
    catch(std::bad_alloc){
        std::cout<<"Nema memorije!";
    }
    return 0;
}