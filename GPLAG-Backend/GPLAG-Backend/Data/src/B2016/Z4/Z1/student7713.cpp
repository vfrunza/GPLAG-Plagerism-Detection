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

const double PI = 4*atan(1);

class Trougao {
    Tacka ta1;
    Tacka ta2;
    Tacka ta3;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        ta1 = t1;
        ta2 = t2;
        ta3 = t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        ta1 = t1;
        ta2 = t2;
        ta3 = t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks>3 || indeks<0) throw std::range_error("Nekorektan indeks");
        else if(indeks == 1) ta1 = t;
        else if(indeks == 2) ta2 = t;
        else if(indeks == 3) ta3 = t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double orijent = t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second);
        if(orijent==0.) return 0;
        else if(orijent<0) return -1;
        else if(orijent>0) return 1;
        return 0;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks>3 || indeks<0) throw std::range_error("Nekorektan indeks");
        else if(indeks == 1) return ta1;
        else if(indeks == 2) return ta2;
        else if(indeks == 3) return ta3;
        return ta1;
    }
    double DajStranicu(int indeks) const {
        if(indeks>3 || indeks<0) throw std::range_error("Nekorektan indeks");
        double d(0);
        if(indeks == 1) {
            d = std::sqrt((ta2.first - ta3.first)*(ta2.first - ta3.first) + (ta2.second - ta3.second)*(ta2.second - ta3.second));   
        }
        else if(indeks == 2) {
            d = std::sqrt((ta1.first - ta3.first)*(ta1.first - ta3.first) + (ta1.second - ta3.second)*(ta1.second - ta3.second));   
        }
        else if(indeks == 3) {
            d = std::sqrt((ta2.first - ta1.first)*(ta2.first - ta1.first) + (ta2.second - ta1.second)*(ta2.second - ta1.second));   
        }
        return d;
    }
    double DajUgao(int indeks) const {
        if(indeks>3 || indeks<0) throw std::range_error("Nekorektan indeks");
        double ugao(0);
        if(indeks == 1) {
            ugao = acos((std::pow(DajStranicu(2),2) + std::pow(DajStranicu(3),2) - std::pow(DajStranicu(1),2))/(2*(std::pow(DajStranicu(2),2)) *(std::pow(DajStranicu(3),2))));
        }
        else if(indeks == 2) {
            ugao = acos((std::pow(DajStranicu(3),2) + std::pow(DajStranicu(1),2) - std::pow(DajStranicu(2),2))/(2*(std::pow(DajStranicu(3),2)) *(std::pow(DajStranicu(1),2))));
        }
        else if(indeks == 3) {
            ugao = acos((std::pow(DajStranicu(2),2) + std::pow(DajStranicu(1),2) - std::pow(DajStranicu(3),2))/(2*(std::pow(DajStranicu(2),2)) *(std::pow(DajStranicu(1),2))));
        }
        ugao*=(PI/180.);
        return ugao;
    }
    Tacka DajCentar() const {
        Tacka T;
        T.first = (ta1.first + ta2.first + ta3.first)/3.;
        T.second = (ta1.second + ta2.second + ta3.second)/3.;
        return T;
    }
    double DajObim() const {
        double obim = DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
        return obim;
    }
    double DajPovrsinu() const {
        double povrsina = std::abs(ta1.first*(ta2.second - ta3.second) - ta2.first*(ta1.second - ta3.second) + ta3.first*(ta1.second - ta2.second))/2;
        return povrsina;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(ta1,ta2,ta3) == 1) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if((Orijentacija(ta1,ta2,ta3)==1) && (Orijentacija(ta1,ta2,t)==1) && (Orijentacija(ta2,ta3,t)==1) && (Orijentacija(ta3,ta1,t)==1)) return true;
        else if((Orijentacija(ta1,ta2,ta3)==-1) && (Orijentacija(ta1,ta2,t)==-1) && (Orijentacija(ta2,ta3,t)==-1) && (Orijentacija(ta3,ta1,t)==-1)) return true;
        return false;
    }
    void Ispisi() const {
        std::cout << "((" <<ta1.first<<","<<ta1.second<<"),("<<ta2.first<<","<<ta2.second<<"),("<<ta3.first<<","<<ta3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) {
        ta1.first+=delta_x;
        ta2.first+=delta_x;
        ta3.first+=delta_x;
        
        ta1.second+=delta_y;
        ta2.second+=delta_y;
        ta3.second+=delta_y;
    }
    void Centriraj(const Tacka &t) {
        Tacka centar = DajCentar();
        double po_x = t.first - centar.first;
        double po_y = t.second - centar.second;
        Transliraj(po_x,po_y);
    }
    void Rotiraj(const Tacka &t, double ugao) {
        double tacka1 = ta1.first;
        double tacka2 = ta2.first;
        double tacka3 = ta3.first;
        
        ta1.first = t.first + (tacka1 - t.first)*cos(ugao) - (ta1.second - t.second)*sin(ugao);
        ta2.first = t.first + (tacka2 - t.first)*cos(ugao) - (ta2.second - t.second)*sin(ugao);
        ta3.first = t.first + (tacka3 - t.first)*cos(ugao) - (ta3.second - t.second)*sin(ugao);
        
        ta1.second = t.second + (tacka1 - t.first)*sin(ugao) + (ta1.second - t.second)*cos(ugao);
        ta2.second = t.second + (tacka2 - t.first)*sin(ugao) + (ta2.second - t.second)*cos(ugao);
        ta3.second = t.second + (tacka3 - t.first)*sin(ugao) + (ta3.second - t.second)*cos(ugao);
        
        
    }
    void Skaliraj(const Tacka &t, double faktor) {
        if(faktor == 0.) throw std::domain_error("Nekorektan faktor skaliranja");
        
        ta1.first = t.first + faktor*(ta1.first - t.first);
        ta1.second = t.second + faktor*(ta1.second - t.second);
        
        ta2.first = t.first + faktor*(ta2.first - t.first);
        ta2.second = t.second + faktor*(ta2.second - t.second);
        
        ta3.first = t.first + faktor*(ta3.first - t.first);
        ta3.second = t.second + faktor*(ta3.second - t.second);
    }
    void Rotiraj(double ugao) {
        Tacka t = DajCentar();
        
        double tacka1 = ta1.first;
        double tacka2 = ta2.first;
        double tacka3 = ta3.first;
        
        ta1.first = t.first + (tacka1 - t.first)*cos(ugao) - (ta1.second - t.second)*sin(ugao);
        ta2.first = t.first + (tacka2 - t.first)*cos(ugao) - (ta2.second - t.second)*sin(ugao);
        ta3.first = t.first + (tacka3 - t.first)*cos(ugao) - (ta3.second - t.second)*sin(ugao);
        
        ta1.second = t.second + (tacka1 - t.first)*sin(ugao) + (ta1.second - t.second)*cos(ugao);
        ta2.second = t.second + (tacka2 - t.first)*sin(ugao) + (ta2.second - t.second)*cos(ugao);
        ta3.second = t.second + (tacka3 - t.first)*sin(ugao) + (ta3.second - t.second)*cos(ugao);
    }
    void Skaliraj(double faktor) {
        if(faktor == 0.) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t = DajCentar();
        ta1.first = t.first + faktor*(ta1.first - t.first);
        ta1.second = t.second + faktor*(ta1.second - t.second);
        
        ta2.first = t.first + faktor*(ta2.first - t.first);
        ta2.second = t.second + faktor*(ta2.second - t.second);
        
        ta3.first = t.first + faktor*(ta3.first - t.first);
        ta3.second = t.second + faktor*(ta3.second - t.second);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool JesuLiJednaki(double x, double y, double Eps = 1e-10) {
    return std::fabs(x-y) <= Eps * (std::fabs(x) + std::fabs(y));
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    bool koordinata1=false,koordinata2=false,koordinata3=false;
    if((t1.ta1 == t2.ta1) || (t1.ta1 == t2.ta2) || (t1.ta1 == t2.ta3)) {
        koordinata1=true;
        if((t1.ta2 == t2.ta1) || (t1.ta2 == t2.ta2) || (t1.ta2 == t2.ta3)) {
            koordinata2=true;
            if((t1.ta3 == t2.ta1) || (t1.ta3 == t2.ta2) || (t1.ta3 == t2.ta3)) koordinata3=true;
        }
    }
    if(koordinata3==true && koordinata2 == true && koordinata1==true) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    double prva1, druga1, treca1;
    double prva2, druga2, treca2;
    
    double a1=t1.DajStranicu(1),b1=t1.DajStranicu(2),c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1),b2=t2.DajStranicu(2),c2=t2.DajStranicu(3);
    
    if(a1>b1 && a1>c1) {
        prva1 = a1;
        if(b1>c1) {
            druga1 = b1;
            treca1 = c1;
        }
        else {
            druga1 = c1;
            treca1 = b1;
        }
    }
    else if(b1>a1 && b1>c1) {
        prva1 = b1;
        if(a1>c1) {
            druga1 = a1;
            treca1 = c1;
        }
        else {
            druga1 = c1;
            treca1 = a1;
        }
    }
    else if(c1>b1 && c1>a1) {
        prva1 = c1;
        if(b1>a1) {
            druga1 = b1;
            treca1 = a1;
        }
        else {
            druga1 = a1;
            treca1 = b1;
        }
    }
    
    else if(JesuLiJednaki(a1,b1) && c1>a1) {
        prva1 = c1; druga1 = a1; treca1 = b1;
    }
    else if(JesuLiJednaki(a1,c1) && b1>a1) {
        prva1 = b1; druga1 = a1; treca1 = c1;
    }
    else if(JesuLiJednaki(c1,b1) && a1>c1) {
        prva1 = a1; druga1 = b1; treca1 = c1;
    }
    
    else if(JesuLiJednaki(a1,b1) && c1<a1) {
        prva1 = b1; druga1 = a1; treca1 = c1;
    }
    else if(JesuLiJednaki(a1,c1) && b1<a1) {
        prva1 = c1; druga1 = a1; treca1 = b1;
    }
    else if(JesuLiJednaki(c1,b1) && a1<c1) {
        prva1 = c1; druga1 = b1; treca1 = a1;
    }
    else {
        prva1 = c1; druga1 = a1; treca1 = b1;
    }
    
    if(a2>b2 && a2>c2) {
        prva2 = a2;
        if(b2>c2) {
            druga2 = b2;
            treca2 = c2;
        }
        else {
            druga2 = c2;
            treca2 = b2;
        }
    }
    else if(b2>a2 && b2>c2) {
        prva2 = b2;
        if(a2>c2) {
            druga2 = a2;
            treca2 = c2;
        }
        else {
            druga2 = c2;
            treca2 = a2;
        }
    }
    else if(c2>b2 && c2>a2) {
        prva2 = c2;
        if(b2>a2) {
            druga2 = b2;
            treca2 = a2;
        }
        else {
            druga2 = a2;
            treca2 = b2;
        }
    }
    
    else if(JesuLiJednaki(a2,b2) && c2>a2) {
        prva2 = c2; druga2 = a2; treca2 = b2;
    }
    else if(JesuLiJednaki(a2,c2) && b2>a2) {
        prva2 = b2; druga2 = a2; treca2 = c2;
    }
    else if(JesuLiJednaki(c2,b2) && a2>c2) {
        prva2 = a2; druga2 = b2; treca2 = b2;
    }
    
    else if(JesuLiJednaki(a2,b2) && c2<a2) {
        prva2 = b2; druga2 = a2; treca2 = c2;
    }
    else if(JesuLiJednaki(a2,c2) && b2<a2) {
        prva2 = c2; druga2 = a2; treca2 = b2;
    }
    else if(JesuLiJednaki(c2,b2) && a2<c2) {
        prva2 = c2; druga2 = b2; treca2 = a2;
    }
    else {
        prva2 = c2; druga2 = a2; treca2 = b2;
    }
    
    Tacka e1,f1,g1;
    Tacka e2,f2,g2;
    
    if(JesuLiJednaki(t1.DajStranicu(1), prva1)) e1=t1.DajTjeme(1);
    if(JesuLiJednaki(t1.DajStranicu(2), prva1)) e1=t1.DajTjeme(2);
    if(JesuLiJednaki(t1.DajStranicu(3), prva1)) e1=t1.DajTjeme(3);
    
    if(JesuLiJednaki(t1.DajStranicu(1), druga1)) f1=t1.DajTjeme(1);
    if(JesuLiJednaki(t1.DajStranicu(2), druga1)) f1=t1.DajTjeme(2);
    if(JesuLiJednaki(t1.DajStranicu(3), druga1)) f1=t1.DajTjeme(3);
    
    if(JesuLiJednaki(t1.DajStranicu(1), treca1)) g1=t1.DajTjeme(1);
    if(JesuLiJednaki(t1.DajStranicu(2), treca1)) g1=t1.DajTjeme(2);
    if(JesuLiJednaki(t1.DajStranicu(3), treca1)) g1=t1.DajTjeme(3);
    
    if(JesuLiJednaki(t2.DajStranicu(1), prva2)) e2=t2.DajTjeme(1);
    if(JesuLiJednaki(t2.DajStranicu(2), prva2)) e2=t2.DajTjeme(2);
    if(JesuLiJednaki(t2.DajStranicu(3), prva2)) e2=t2.DajTjeme(3);
    
    if(JesuLiJednaki(t2.DajStranicu(1), druga2)) f2=t2.DajTjeme(1);
    if(JesuLiJednaki(t2.DajStranicu(2), druga2)) f2=t2.DajTjeme(2);
    if(JesuLiJednaki(t2.DajStranicu(3), druga2)) f2=t2.DajTjeme(3);
    
    if(JesuLiJednaki(t2.DajStranicu(1), treca2)) g2=t2.DajTjeme(1);
    if(JesuLiJednaki(t2.DajStranicu(2), treca2)) g2=t2.DajTjeme(2);
    if(JesuLiJednaki(t2.DajStranicu(3), treca2)) g2=t2.DajTjeme(3);
    
    if(JesuLiJednaki(prva1,prva2) && JesuLiJednaki(druga1,druga2) && JesuLiJednaki(treca1,treca2)) {
        if(t1.Orijentacija(e1,f1,g1) == t2.Orijentacija(e2,f2,g2)) return true;
    }
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    double prva1, druga1, treca1;
    double prva2, druga2, treca2;
    
    double a1=t1.DajStranicu(1),b1=t1.DajStranicu(2),c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1),b2=t2.DajStranicu(2),c2=t2.DajStranicu(3);
    
    if(a1>b1 && a1>c1) {
        prva1 = a1;
        if(b1>c1) {
            druga1 = b1;
            treca1 = c1;
        }
        else {
            druga1 = c1;
            treca1 = b1;
        }
    }
    else if(b1>a1 && b1>c1) {
        prva1 = b1;
        if(a1>c1) {
            druga1 = a1;
            treca1 = c1;
        }
        else {
            druga1 = c1;
            treca1 = a1;
        }
    }
    else if(c1>b1 && c1>a1) {
        prva1 = c1;
        if(b1>a1) {
            druga1 = b1;
            treca1 = a1;
        }
        else {
            druga1 = a1;
            treca1 = b1;
        }
    }
    
    else if(JesuLiJednaki(a1,b1) && c1>a1) {
        prva1 = c1; druga1 = a1; treca1 = b1;
    }
    else if(JesuLiJednaki(a1,c1) && b1>a1) {
        prva1 = b1; druga1 = a1; treca1 = c1;
    }
    else if(JesuLiJednaki(c1,b1) && a1>c1) {
        prva1 = a1; druga1 = b1; treca1 = c1;
    }
    
    else if(JesuLiJednaki(a1,b1) && c1<a1) {
        prva1 = b1; druga1 = a1; treca1 = c1;
    }
    else if(JesuLiJednaki(a1,c1) && b1<a1) {
        prva1 = c1; druga1 = a1; treca1 = b1;
    }
    else if(JesuLiJednaki(c1,b1) && a1<c1) {
        prva1 = c1; druga1 = b1; treca1 = a1;
    }
    else {
        prva1 = c1; druga1 = a1; treca1 = b1;
    }
    
    if(a2>b2 && a2>c2) {
        prva2 = a2;
        if(b2>c2) {
            druga2 = b2;
            treca2 = c2;
        }
        else {
            druga2 = c2;
            treca2 = b2;
        }
    }
    else if(b2>a2 && b2>c2) {
        prva2 = b2;
        if(a2>c2) {
            druga2 = a2;
            treca2 = c2;
        }
        else {
            druga2 = c2;
            treca2 = a2;
        }
    }
    else if(c2>b2 && c2>a2) {
        prva2 = c2;
        if(b2>a2) {
            druga2 = b2;
            treca2 = a2;
        }
        else {
            druga2 = a2;
            treca2 = b2;
        }
    }
    
    else if(JesuLiJednaki(a2,b2) && c2>a2) {
        prva2 = c2; druga2 = a2; treca2 = b2;
    }
    else if(JesuLiJednaki(a2,c2) && b2>a2) {
        prva2 = b2; druga2 = a2; treca2 = c2;
    }
    else if(JesuLiJednaki(c2,b2) && a2>c2) {
        prva2 = a2; druga2 = b2; treca2 = b2;
    }
    
    else if(JesuLiJednaki(a2,b2) && c2<a2) {
        prva2 = b2; druga2 = a2; treca2 = c2;
    }
    else if(JesuLiJednaki(a2,c2) && b2<a2) {
        prva2 = c2; druga2 = a2; treca2 = b2;
    }
    else if(JesuLiJednaki(c2,b2) && a2<c2) {
        prva2 = c2; druga2 = b2; treca2 = a2;
    }
    else {
        prva2 = c2; druga2 = a2; treca2 = b2;
    }
    
    Tacka e1,f1,g1;
    Tacka e2,f2,g2;
    
    if(JesuLiJednaki(t1.DajStranicu(1), prva1)) e1=t1.DajTjeme(1);
    if(JesuLiJednaki(t1.DajStranicu(2), prva1)) e1=t1.DajTjeme(2);
    if(JesuLiJednaki(t1.DajStranicu(3), prva1)) e1=t1.DajTjeme(3);
    
    if(JesuLiJednaki(t1.DajStranicu(1), druga1)) f1=t1.DajTjeme(1);
    if(JesuLiJednaki(t1.DajStranicu(2), druga1)) f1=t1.DajTjeme(2);
    if(JesuLiJednaki(t1.DajStranicu(3), druga1)) f1=t1.DajTjeme(3);
    
    if(JesuLiJednaki(t1.DajStranicu(1), treca1)) g1=t1.DajTjeme(1);
    if(JesuLiJednaki(t1.DajStranicu(2), treca1)) g1=t1.DajTjeme(2);
    if(JesuLiJednaki(t1.DajStranicu(3), treca1)) g1=t1.DajTjeme(3);
    
    if(JesuLiJednaki(t2.DajStranicu(1), prva2)) e2=t2.DajTjeme(1);
    if(JesuLiJednaki(t2.DajStranicu(2), prva2)) e2=t2.DajTjeme(2);
    if(JesuLiJednaki(t2.DajStranicu(3), prva2)) e2=t2.DajTjeme(3);
    
    if(JesuLiJednaki(t2.DajStranicu(1), druga2)) f2=t2.DajTjeme(1);
    if(JesuLiJednaki(t2.DajStranicu(2), druga2)) f2=t2.DajTjeme(2);
    if(JesuLiJednaki(t2.DajStranicu(3), druga2)) f2=t2.DajTjeme(3);
    
    if(JesuLiJednaki(t2.DajStranicu(1), treca2)) g2=t2.DajTjeme(1);
    if(JesuLiJednaki(t2.DajStranicu(2), treca2)) g2=t2.DajTjeme(2);
    if(JesuLiJednaki(t2.DajStranicu(3), treca2)) g2=t2.DajTjeme(3);
    
    double razlika = std::fabs(prva1 - prva2);
    if((std::fabs(druga1 - druga2) == razlika) && (std::fabs(treca1 - treca2) == razlika)) {
        if(t1.Orijentacija(e1,f1,g1) == t2.Orijentacija(e2,f2,g2))
            return true;
    }
    
    return false;
}

int main ()
{
    try {
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i(0); i<n; i++) {
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1,t2,t3;
        double a,b;
        std::cin >> a >> b;
        t1.first = a;
        t1.second = b;
        std::cin >> a >> b;
        t2.first = a;
        t2.second = b;
        std::cin >> a >> b;
        t3.first = a;
        t3.second = b;
        try {
        Trougao pom(t1,t2,t3);
        v[i] = std::make_shared<Trougao>(pom);
        }
        catch(std::domain_error e) {
            std::cout << e.what()<<std::endl;
            i--;
        }
        
    }
    double x,y;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> x >> y;
    std::transform(v.begin(), v.end(), v.begin(), [x,y] (std::shared_ptr<Trougao> tr){
        tr->Transliraj(x,y);
        return tr;
    });
    double ugao;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    std::transform(v.begin(), v.end(), v.begin(), [ugao] (std::shared_ptr<Trougao> tr){
        tr->Rotiraj(ugao);
        return tr;
    });
    double faktor;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor;
    std::transform(v.begin(), v.end(), v.begin(), [faktor] (std::shared_ptr<Trougao> tr){
        tr->Skaliraj(tr->DajTjeme(1),faktor);
        return tr;
    });
  
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Trougao> tr1, std::shared_ptr<Trougao> tr2){
       if(tr1->DajPovrsinu() < tr2->DajPovrsinu()) return true;
       return false;
    });
    std::cout <<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Trougao> tr) {
        tr->Ispisi();
        std::cout << std::endl;
    });
    auto p = *(std::min_element(v.begin(), v.end(), [] (std::shared_ptr<Trougao> tr1, std::shared_ptr<Trougao> tr2){
        if(tr1->DajObim() < tr2->DajObim()) return true;
        return false;
    }));
    std::cout << "Trougao sa najmanjim obimom: ";
    p->Ispisi();
    std::cout << std::endl;
    bool identicni=false, podudarni=false, slicni=false;
    for(int i(0); i<n; i++) {
        Trougao a(v[i]->DajTjeme(1), v[i]->DajTjeme(2), v[i]->DajTjeme(3));
        for(int j(i+1); j<n; j++) {
            Trougao b(v[j]->DajTjeme(1), v[j]->DajTjeme(2), v[j]->DajTjeme(3));
            if(DaLiSuIdenticni(a,b)) identicni=true;
        }
    }
      for(int i(0); i<n; i++) {
        Trougao a(v[i]->DajTjeme(1), v[i]->DajTjeme(2), v[i]->DajTjeme(3));
        for(int j(i+1); j<n; j++) {
            Trougao b(v[j]->DajTjeme(1), v[j]->DajTjeme(2), v[j]->DajTjeme(3));
            if(DaLiSuPodudarni(a,b)) podudarni=true;
        }
    }
    for(int i(0); i<n; i++) {
        Trougao a(v[i]->DajTjeme(1), v[i]->DajTjeme(2), v[i]->DajTjeme(3));
        for(int j(i+1); j<n; j++) {
            Trougao b(v[j]->DajTjeme(1), v[j]->DajTjeme(2), v[j]->DajTjeme(3));
            if(DaLiSuSlicni(a,b)) slicni=true;
        }
    }
    
    if(identicni) {
        std::cout << "Parovi identicnih trouglova:"<<std::endl;
        for(int i(0); i<n; i++) {
            Trougao a(v[i]->DajTjeme(1), v[i]->DajTjeme(2), v[i]->DajTjeme(3));
            for(int j(i+1); j<n; j++) {
                Trougao b(v[j]->DajTjeme(1), v[j]->DajTjeme(2), v[j]->DajTjeme(3));
                if(DaLiSuIdenticni(a,b)) {
                    a.Ispisi();
                    std::cout << " i ";
                    b.Ispisi();
                    std::cout << std::endl;
                }
            }
        }
    }
    else std::cout << "Nema identicnih trouglova!" << std::endl;
    if(podudarni) {
    std::cout << "Parovi podudarnih trouglova:"<<std::endl;
    for(int i(0); i<n; i++) {
        Trougao a(v[i]->DajTjeme(1), v[i]->DajTjeme(2), v[i]->DajTjeme(3));
        for(int j(i+1); j<n; j++) {
            Trougao b(v[j]->DajTjeme(1), v[j]->DajTjeme(2), v[j]->DajTjeme(3));
            if(DaLiSuPodudarni(a,b)) {
                a.Ispisi();
                std::cout << " i ";
                b.Ispisi();
                std::cout << std::endl;
            }
        }
    }
    }
    else std::cout << "Nema podudarnih trouglova!" << std::endl;
    if(slicni) {
    std::cout << "Parovi slicnih trouglova:"<<std::endl;
    for(int i(0); i<n; i++) {
        Trougao a(v[i]->DajTjeme(1), v[i]->DajTjeme(2), v[i]->DajTjeme(3));
        for(int j(i+1); j<n; j++) {
            Trougao b(v[j]->DajTjeme(1), v[j]->DajTjeme(2), v[j]->DajTjeme(3));
            if(DaLiSuSlicni(a,b)) {
                a.Ispisi();
                std::cout << " i ";
                b.Ispisi();
                std::cout << std::endl;
            }
        }
    }
    }
    else std::cout << "Nema slicnih trouglova!" << std::endl;
    }
    catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    catch(std::range_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
	return 0;
}   