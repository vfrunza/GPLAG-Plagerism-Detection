/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;
const double eps = 1e-10;
class Trougao {
    Tacka T1,T2,T3;
    static double Kosinusna(double a, double b, double c) { return acos((a*a+b*b-c*c)/2*a*b); }
    static double Povrsina(const Tacka &t1, const Tacka &t2, const Tacka &t3) { 
        return (t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
    }
    static bool Test1(Tacka T, Tacka t1, Tacka t2, Tacka t3) {
        if(Orijentacija(t1,t2,t3)==1 && Orijentacija(t1,t2,T)==1 && Orijentacija(t2,t3,T)==1 && Orijentacija(t3,t1,T)==1) return true;
        return false;
    }
    static bool Test2(Tacka t1, Tacka t2) {
        if((fabs(t1.first-t2.first)<eps) && (fabs(t1.second-t2.second)<eps)) return true;
        return false;
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("“Nekorektne pozicije tjemena");
        T1=t1; T2=t2; T3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        T1=t1; T2=t2; T3=t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
        if(indeks==1) T1=t;
        else if(indeks==2) T2=t;
        else if(indeks==3) T3=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const {
        if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return T1;
        if(indeks==2) return T2;
        return T3;
    }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const {
        if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return Kosinusna(DajStranicu(2),DajStranicu(3),DajStranicu(1));
        if(indeks==2) return Kosinusna(DajStranicu(1),DajStranicu(3),DajStranicu(2));
        return Kosinusna(DajStranicu(1),DajStranicu(2),DajStranicu(3));
    }
    Tacka DajCentar() const {
        Tacka centar;
        centar.first=(T1.first+T2.first+T3.first)/3;
        centar.second=(T1.second+T2.second+T3.second)/3;
        return centar;
    }
    double DajObim() const { return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); }
    double DajPovrsinu() const { return fabs(Povrsina(T1,T2,T3))/2; }
    bool DaLiJePozitivnoOrijentiran() const { if(Orijentacija(T1,T2,T3)==1) return true; return false; }
    bool DaLiJeUnutra(const Tacka &t) const { return Test1(t,T1,T2,T3); }
    void Ispisi() const { std::cout << "((" << T1.first << "," << T1.second << "),(" << T2.first << "," << T2.second << "),(" << T3.first << "," << T3.second << "))"; }
    void Transliraj(double delta_x, double delta_y) {
        T1.first+=delta_x; T2.first+=delta_x; T3.first+=delta_x;
        T1.second+=delta_y; T2.second+=delta_y; T3.second+=delta_y;
    }
    void Centriraj(const Tacka &t) {
        Tacka centar(DajCentar());
        double delta(sqrt(pow((centar.first-t.first),2)+pow((centar.second-t.second),2)));
        Transliraj(delta,delta);
    }
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double test(Povrsina(t1,t2,t3));
    if(test==0) return test;
    if(test>0) return 1;
    return -1;
}
double Trougao::DajStranicu(int indeks) const {
    if(indeks>3 || indeks<1) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return sqrt(pow((T3.first-T2.first),2)+pow((T3.second-T2.second),2));
    if(indeks==2) return sqrt(pow((T3.first-T1.first),2)+pow((T3.second-T1.second),2));
    return sqrt(pow((T2.first-T1.first),2)+pow((T2.second-T1.second),2));
}
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    T1.first=t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao);
    T1.second=t.second+(T1.first-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao);
    T2.first=t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao);
    T2.second=t.second+(T2.first-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao);
    T3.first=t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao);
    T3.second=t.second+(T3.first-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(fabs(faktor-0)<eps) throw std::domain_error("Nekorektan faktor skaliranja");
    T1.first=t.first+faktor*(T1.first-t.first);
    T1.second=t.second+faktor*(T1.second-t.second);
    T2.first=t.first+faktor*(T2.first-t.first);
    T2.second=t.second+faktor*(T2.second-t.second);
    T3.first=t.first+faktor*(T3.first-t.first);
    T3.second=t.second+faktor*(T3.second-t.second);
}
void Trougao::Rotiraj(double ugao) {
    Rotiraj(DajCentar(),ugao);
}
void Trougao::Skaliraj(double faktor) {
    Skaliraj(DajCentar(),faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    std::vector<Tacka> v1,v2;
    v1.push_back(t1.T1); v1.push_back(t1.T2); v1.push_back(t1.T3);
    v2.push_back(t2.T1); v2.push_back(t2.T2); v2.push_back(t2.T3);
    int brojac(0);
    for(int i=0;i<v1.size();i++) {
        for(int j=0;j<v2.size();j++) {
            if(Trougao::Test2(v1[i],v2[j])) brojac++;
        }
    }
    if(brojac==3) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> stranice1,stranice2;
    for(int i=0;i<3;i++) {
        stranice1.push_back(t1.DajStranicu(i+1));
        stranice2.push_back(t2.DajStranicu(i+1));
    }
    std::sort(stranice1.begin(),stranice1.end());
    std::sort(stranice2.begin(),stranice2.end());
    for(int i=0;i<3;i++) {
        if(stranice1[i]!=stranice2[i]) return false;
    }
    std::vector<std::pair<double,Tacka>> tjeme_stranica1(3), tjeme_stranica2(3);
    for(int i=0;i<3;i++) {
        tjeme_stranica1[i].first=t1.DajStranicu(i+1);
        tjeme_stranica1[i].second=t1.DajTjeme(i+1);
        tjeme_stranica2[i].first=t2.DajStranicu(i+1);
        tjeme_stranica2[i].second=t2.DajTjeme(i+1);
    }
    std::sort(tjeme_stranica1.begin(),tjeme_stranica1.end());
    std::sort(tjeme_stranica2.begin(),tjeme_stranica2.end());
    if(fabs(Trougao::Orijentacija(tjeme_stranica1[0].second,tjeme_stranica1[1].second,tjeme_stranica1[2].second) - Trougao::Orijentacija(tjeme_stranica2[0].second,tjeme_stranica2[1].second,tjeme_stranica2[2].second))-0<eps) return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    std::vector<double> stranice1,stranice2;
    for(int i=0;i<3;i++) {
        stranice1.push_back(t1.DajStranicu(i+1));
        stranice2.push_back(t2.DajStranicu(i+1));
    }
    std::sort(stranice1.begin(),stranice1.end());
    std::sort(stranice2.begin(),stranice2.end());
    for(int i=0;i<3;i++) {
        if(stranice1[i]/stranice2[i]!=stranice2[i]/stranice1[i]) return false;
    }
    std::vector<std::pair<double,Tacka>> tjeme_stranica1(3), tjeme_stranica2(3);
    for(int i=0;i<3;i++) {
        tjeme_stranica1[i].first=t1.DajStranicu(i+1);
        tjeme_stranica1[i].second=t1.DajTjeme(i+1);
        tjeme_stranica2[i].first=t2.DajStranicu(i+1);
        tjeme_stranica2[i].second=t2.DajTjeme(i+1);
    }
    std::sort(tjeme_stranica1.begin(),tjeme_stranica1.end());
    std::sort(tjeme_stranica2.begin(),tjeme_stranica2.end());
    if(fabs(Trougao::Orijentacija(tjeme_stranica1[0].second,tjeme_stranica1[1].second,tjeme_stranica1[2].second) - Trougao::Orijentacija(tjeme_stranica2[0].second,tjeme_stranica2[1].second,tjeme_stranica2[2].second))-0<eps) return true;
    return false;
}

int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    Tacka T1,T2,T3;
    double x1,y1,x2,y2,x3,y3;
    std::vector<std::shared_ptr<Trougao>> vektor;
    for(int i=0;i<n;i++) {
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        T1.first=x1; T1.second=y1;
        T2.first=x2; T2.second=y2;
        T3.first=x3; T3.second=y3;
        try {
            Trougao trougao(T1,T2,T3);
        }
        catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
            i--;
            continue;
        }
        std::shared_ptr<Trougao> pomocni=std::make_shared<Trougao>(T1,T2,T3);
        vektor.push_back(pomocni);
    }
    double delta_x, delta_y, ugao, faktor;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> delta_x >> delta_y;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor;
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [delta_x,delta_y] (std::shared_ptr<Trougao> t1) {
        
        t1->Transliraj(delta_x,delta_y);
        return t1;
    });
    std::transform(vektor.begin(), vektor.end(), vektor.begin(), [ugao] (std::shared_ptr<Trougao> t1) {
        t1->Rotiraj(ugao);
        return t1;
    });
    try {
        std::transform(vektor.begin(), vektor.end(), vektor.begin(), [faktor] (std::shared_ptr<Trougao> t1) {
            Tacka t(t1->DajTjeme(1));
            t1->Skaliraj(t,faktor);
            return t1;
        });
    }
    catch(std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
        return 0;
    }
    std::sort(vektor.begin(),vektor.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
        return(t1->DajPovrsinu()<t2->DajPovrsinu());
    });
    std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
    std::for_each(vektor.begin(),vektor.end(), [] (std::shared_ptr<Trougao> t1) { t1->Ispisi(); std::cout << std::endl; });
    std::shared_ptr<Trougao> najmanji(*std::min_element(vektor.begin(),vektor.end(), [] (std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
        return(t1->DajObim()<t2->DajObim());    
    }));
    std::cout << "Trougao sa najmanjim obimom: ";
    najmanji->Ispisi();
    int br_identicni(0),br_podudarni(0),br_slicni(0);
    for(int i=0;i<vektor.size();i++) {
        for(int j=i+1;j<vektor.size();j++) {
            if(DaLiSuIdenticni(*vektor[i],*vektor[j])) {
                br_identicni++;
            }
        }
    }
    for(int i=0;i<vektor.size();i++) {
        for(int j=i+1;j<vektor.size();j++) {
            if(DaLiSuPodudarni(*vektor[i],*vektor[j])) {
                br_podudarni++;
            }
        }
    }
    for(int i=0;i<vektor.size();i++) {
        for(int j=i+1;j<vektor.size();j++) {
            if(DaLiSuSlicni(*vektor[i],*vektor[j])) {
                br_slicni++;
            }
        }
    }
    if(br_identicni==0) std::cout << std::endl <<"Nema identicnih trouglova!" << std::endl;
    if(br_identicni!=0) std::cout  << std::endl << "Parovi identicnih trouglova:" << std::endl;
    for(int i=0;i<vektor.size();i++) {
        for(int j=i+1;j<vektor.size();j++) {
            if(DaLiSuIdenticni(*vektor[i],*vektor[j])) {
                vektor[i]->Ispisi(); std::cout << " i "; vektor[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
    if(br_podudarni==0) std::cout <<"Nema podudarnih trouglova!" << std::endl;
    if(br_podudarni!=0) std::cout << "Parovi podudarnih trouglova:" << std::endl;
    for(int i=0;i<vektor.size();i++) {
        for(int j=i+1;j<vektor.size();j++) {
            if(DaLiSuPodudarni(*vektor[i],*vektor[j])) {
                vektor[i]->Ispisi(); std::cout << " i "; vektor[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
    if(br_slicni==0) std::cout <<"Nema slicnih trouglova!" << std::endl;
    if(br_slicni!=0) std::cout << "Parovi slicnih trouglova:" << std::endl;
    for(int i=0;i<vektor.size();i++) {
        for(int j=i+1;j<vektor.size();j++) {
            if(DaLiSuSlicni(*vektor[i],*vektor[j])) {
                vektor[i]->Ispisi(); std::cout << " i "; vektor[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
	return 0;
}