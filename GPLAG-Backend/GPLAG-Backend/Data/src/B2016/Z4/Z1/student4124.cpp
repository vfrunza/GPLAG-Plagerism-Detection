#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

static const double PI(4*std::atan(1));
typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    void TestIndeksa(int indeks) const {
        if(indeks!=1 and indeks!=2 and indeks!=3)
            throw std::range_error("Nekorektan indeks");
    }
    void Stranice (double &a, double &b, double &c) const {
        a = std::sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
        b = std::sqrt((t3.first-t1.first)*(t3.first-t1.first)+(t3.second-t1.second)*(t3.second-t1.second));
        c = std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    }
    double Izraz (const Tacka &t1, const Tacka &t2, const Tacka &t3) const {
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    void RotirajTacku(Tacka &t, const Tacka &tc, double ugao) {
        //ugao*=180/PI;
        Tacka t2(t);
        t.first = tc.first+(t2.first-tc.first)*std::cos(ugao)-(t2.second-tc.second)*std::sin(ugao);
        t.second = tc.second+(t2.first-tc.first)*std::sin(ugao)+(t2.second-tc.second)*std::cos(ugao);
    }
    void SkalirajTacku(Tacka &t, const Tacka &tc, double faktor) {
        Tacka t2(t);
        t.first = tc.first+faktor*(t2.first-tc.first);
        t.second = tc.second+faktor*(t2.second-tc.second);
    }
    static bool Jednaki(double x, double y, double Eps = 1e-10) {
        return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Postavi(t1, t2, t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const {return {(t1.first+t2.first+t3.first)/3, (t1.second+t2.second+t3.second)/3};}
    double DajObim() const {double a, b, c; Stranice(a,b,c); return a+b+c;}
    double DajPovrsinu() const {return std::fabs(Izraz(t1,t2,t3))/2;}
    bool DaLiJePozitivnoOrijentiran() const {int i(Orijentacija(t1,t2,t3)); if(i>0) return true; return false;}
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
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

void Trougao::Postavi(int indeks, const Tacka &t) {
        TestIndeksa(indeks);
        if(indeks==1) {
            if(Orijentacija(t,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            t1=t;
        } else if(indeks==2) {
            if(Orijentacija(t1,t,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            t2=t;
        } else if(indeks==3) {
            if(Orijentacija(t1,t2,t)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            t3=t;
        }
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double temp(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    if(temp>0) return 1; if(temp<0) return -1; return 0; 
}

Tacka Trougao::DajTjeme(int indeks) const {
    TestIndeksa(indeks);
    if(indeks==1) return t1;
        else if(indeks==2) return t2;
    return t3;
}

double Trougao::DajStranicu(int indeks) const {
    TestIndeksa(indeks);
    double a, b, c;
    Stranice(a,b,c);
    if(indeks==1) return a;
        else if(indeks==2) return b;
    return c;
}

double Trougao::DajUgao(int indeks) const {
    TestIndeksa(indeks);
    double a, b, c;
    Stranice(a,b,c);
    if(indeks==1) return acos((a*a-b*b-c*c)/((-2)*b*c));
        else if(indeks==2) return acos((b*b-a*a-c*c)/((-2)*a*c));
    return acos((c*c-a*a-b*b)/((-2)*a*b));
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if(DaLiJePozitivnoOrijentiran()) {
        if(Orijentacija(t1,t2,t)==1 and Orijentacija(t2,t3,t)==1 and Orijentacija(t3,t1,t)==1)
            return true;
    } else {
        if(Orijentacija(t1,t2,t)==-1 and Orijentacija(t2,t3,t)==-1 and Orijentacija(t3,t1,t)==-1)
            return true;
    }
    return false;
}

void Trougao::Ispisi() const {
    std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    t1.first+=delta_x; t2.first+=delta_x; t3.first+=delta_x;
    t1.second+=delta_y; t2.second+=delta_y; t3.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t) {
    Tacka t4(DajCentar());
    double delta_x(t.first-t4.first), delta_y(t.second-t4.second);
    Transliraj(delta_x, delta_y);
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    RotirajTacku(t1, t, ugao);
    RotirajTacku(t2, t, ugao);
    RotirajTacku(t3, t, ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(Jednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    SkalirajTacku(t1, t, faktor);
    SkalirajTacku(t2, t, faktor);
    SkalirajTacku(t3, t, faktor);
}

void Trougao::Rotiraj(double ugao) {
    Tacka t(DajCentar());
    RotirajTacku(t1, t, ugao);
    RotirajTacku(t2, t, ugao);
    RotirajTacku(t3, t, ugao);
}

void Trougao::Skaliraj(double faktor) {
    if(Jednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka t(DajCentar());
    SkalirajTacku(t1, t, faktor);
    SkalirajTacku(t2, t, faktor);
    SkalirajTacku(t3, t, faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if(t1.DajCentar() != t2.DajCentar()) return false;
    if(!Trougao::Jednaki(t1.DajObim(), t2.DajObim())) return false;
    if(!Trougao::Jednaki(t1.DajPovrsinu(), t2.DajPovrsinu())) return false;
    if(t1.DajTjeme(1)==t2.DajTjeme(1) or t1.DajTjeme(1)==t2.DajTjeme(2) or t1.DajTjeme(1)==t2.DajTjeme(3))
        return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    if(Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(1))) {
        if(Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(3)) and Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(2)) and t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
        if(Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(2)) and Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(3)) and t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
    } else if(Trougao::Jednaki(t1.DajStranicu(1),t2.DajStranicu(2))) {
        if(Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(1)) and Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(3)) and t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
        if(Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(3)) and Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(1)) and t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
    } else if(Trougao::Jednaki(t1.DajStranicu(1),t2.DajStranicu(3))) {
        if(Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(1)) and Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(2)) and t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
        if(Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(2)) and Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(1)) and t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
    }
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    double temp1(t1.DajStranicu(1)/t2.DajStranicu(1));
    double temp2(t1.DajStranicu(1)/t2.DajStranicu(2));
    double temp3(t1.DajStranicu(1)/t2.DajStranicu(3));
    if(Trougao::Jednaki(temp1, t1.DajStranicu(2)/t2.DajStranicu(2)) or Trougao::Jednaki(temp1, t1.DajStranicu(2)/t2.DajStranicu(3))) {
        if(Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(3)) and Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(2)) and t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
        if(Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(2)) and Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(3)) and t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
    } else if(Trougao::Jednaki(temp2, t1.DajStranicu(2)/t2.DajStranicu(1)) or Trougao::Jednaki(temp2, t1.DajStranicu(2)/t2.DajStranicu(3))) {
        if(Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(1)) and Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(3)) and t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
        if(Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(3)) and Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(1)) and t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
    } else if(Trougao::Jednaki(temp3, t1.DajStranicu(2)/t2.DajStranicu(1)) or Trougao::Jednaki(temp3, t1.DajStranicu(2)/t2.DajStranicu(2))) {
        if(Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(1)) and Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(2)) and t1.DaLiJePozitivnoOrijentiran()!=t2.DaLiJePozitivnoOrijentiran()) return true;
        if(Trougao::Jednaki(t1.DajUgao(3),t2.DajUgao(2)) and Trougao::Jednaki(t1.DajUgao(2),t2.DajUgao(1)) and t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) return true;
    }
    return false;
}

int main ()
{
    
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> vp(n);
    for(int i(0); i<n; i++) {
        double a, b, c, d, e, f;
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> a >> b >> c >> d >> e >> f;
        if((std::fabs(a*(d-f)-c*(b-f)+e*(b-d))/2.)-0<=1e-10) {
            i--;
            std::cout << "Nekorektne pozicije tjemena, ponovite unos!" << std::endl;
            continue;
        }
        Tacka t1(a,b), t2(c,d), t3(e,f);
        vp[i]=std::make_shared<Trougao>(Trougao(t1,t2,t3));
    }
    double x, y;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> x >> y;
    double ugao, faktor;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor;
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::transform(vp.begin(), vp.end(), vp.begin(), [x,y](std::shared_ptr<Trougao> p) {p->Transliraj(x,y); return p;});
    std::transform(vp.begin(), vp.end(), vp.begin(), [ugao](std::shared_ptr<Trougao> p) {p->Rotiraj(ugao); return p;});
    std::transform(vp.begin(), vp.end(), vp.begin(), [faktor](std::shared_ptr<Trougao> p) {p->Skaliraj(p->DajTjeme(1), faktor); return p;});
    std::sort(vp.begin(), vp.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {return p1->DajPovrsinu()<p2->DajPovrsinu();});
    std::for_each(vp.begin(), vp.end(), [](std::shared_ptr<Trougao> p) {p->Ispisi(); std::cout << std::endl;});
    std::cout << "Trougao sa najmanjim obimom: ";
    auto p1 = std::min_element(vp.begin(), vp.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {return p1->DajObim()<p2->DajObim();});
    (*p1)->Ispisi(); std::cout << std::endl;
    bool identicni(false), podudarni(false), slicni(false);
    for(int i(0); i<n; i++)
        for(int j(i+1); j<n; j++)
            if(DaLiSuIdenticni(*vp[i],*vp[j])) {
                if(!identicni) std::cout << "Parovi identicnih trouglova:" << std::endl;
                identicni=true;
                vp[i]->Ispisi(); std::cout << " i "; vp[j]->Ispisi(); std::cout << std::endl;
            }
    if(!identicni) std::cout << "Nema identicnih trouglova!" << std::endl;
    for(int i(0); i<n; i++)
        for(int j(i+1); j<n; j++)
            if(DaLiSuPodudarni(*vp[i],*vp[j])) {
                if(!podudarni) std::cout << "Parovi podudarnih trouglova:" << std::endl;
                podudarni=true;
                vp[i]->Ispisi(); std::cout << " i "; vp[j]->Ispisi(); std::cout << std::endl;
            }
    if(!podudarni) std::cout << "Nema podudarnih trouglova!" << std::endl;
    for(int i(0); i<n; i++)
        for(int j(i+1); j<n; j++)
            if(DaLiSuSlicni(*vp[i],*vp[j])) {
                if(!slicni) std::cout << "Parovi slicnih trouglova:" << std::endl;
                slicni=true;
                vp[i]->Ispisi(); std::cout << " i "; vp[j]->Ispisi(); std::cout << std::endl;
            }
    if(!slicni) std::cout << "Nema slicnih trouglova!" << std::endl;
	return 0;
}