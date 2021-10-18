/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <utility>
#include <stdexcept>
#include <memory>
#include <vector>
#include <cmath>
#include <algorithm>
const double E = 1e-10;
typedef std::pair<double, double> Tacka;
class Trougao {
        Tacka t1, t2, t3;
        static double PI;
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); }   //mozda bi bilo dobro konstruktor uradit bez postavi
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi(int indeks, const Tacka &t);
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
            int test;
            test=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
            if(test>0) return 1;
            else if(test==0) return 0;
            else return -1;                                                     //test<0
        }
        Tacka DajTjeme(int indeks) const;
        double DajStranicu(int indeks) const;
        double DajUgao(int indeks) const;
        Tacka DajCentar() const;
        double DajObim() const;
        double DajPovrsinu() const;
        bool DaLiJePozitivnoOrijentiran() const;
        bool DaLiJeUnutra(const Tacka &t) const;
        void Ispisi() const { std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";}
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
double Trougao::PI(4*atan(1.));
double Povrsina(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double P;
    P=(fabs(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second)))/2;
    return P;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    int testkolinearnosti=Orijentacija(t1, t2, t3);
    if(testkolinearnosti==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t) {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) {
        int testkolinearnosti=Orijentacija(t, t2, t3);
        if(testkolinearnosti==0) throw std::domain_error("Nekorektne pozicije tjemena");
        t1=t;
    }
    if(indeks==2) {
        int testkolinearnosti=Orijentacija(t1, t, t3);
        if(testkolinearnosti==0) throw std::domain_error("Nekorektne pozicije tjemena");
        t2=t;
    }
    if(indeks==3) {
        int testkolinearnosti=Orijentacija(t1, t2, t);
        if(testkolinearnosti==0) throw std::domain_error("Nekorektne pozicije tjemena");
        t3=t;
    }
}
Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return t1;
    else if(indeks==2) return t2;
    else return t3;                                                             //indeks==3
}
double Trougao::DajStranicu(int indeks) const {
    double d;
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) {
        d=std::sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
        return d;
    }
    else if(indeks==2) {
        d=std::sqrt((t3.first-t1.first)*(t3.first-t1.first)+(t3.second-t1.second)*(t3.second-t1.second));
        return d;
    }
    else {                                                                      //indeks==3
        d=std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
        return d;
    }
}
double Trougao::DajUgao(int indeks) const {
    double ugao;
    double a, b, c;
    a=DajStranicu(1);
    b=DajStranicu(2);
    c=DajStranicu(3);
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) {
        ugao=(acos((a*a - b*b - c*c)/-(2*b*c)))*180/PI;
        return ugao;
    }
    else if(indeks==2) {
        ugao=(acos((b*b - a*a - c*c)/-(2*a*c)))*180/PI;
        return ugao;
    }
    else {                                                                      //indeks==3
        ugao=(acos((c*c - a*a - b*b)/-(2*a*b)))*180/PI;
        return ugao;
    }
}
Tacka Trougao::DajCentar() const {
    Tacka T;
    double x, y;
    x=(t1.first+t2.first+t3.first)/3;
    y=(t1.second+t2.second+t3.second)/3;
    T=std::make_pair(x,y);
    return T;
}
double Trougao::DajObim() const {
    double a, b, c;
    a=DajStranicu(1);
    b=DajStranicu(2);
    c=DajStranicu(3);
    return a+b+c;
}
double Trougao::DajPovrsinu() const {
    double P;
    P=(fabs(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second)))/2;
    return P;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const {
    int broj;
    broj=Orijentacija(t1, t2, t3);
    if(broj==1) return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    double P, p1, p2, p3;
    P=Povrsina(t1, t2, t3);
    p1=Povrsina(t1, t2, t);
    p2=Povrsina(t1, t, t3);
    p3=Povrsina(t, t2, t3);
    if(fabs(P-(p1+p2+p3))<E) return true;
    return false;
}
void Trougao::Transliraj(double delta_x, double delta_y) {
    t1.first+=delta_x;
    t2.first+=delta_x;
    t3.first+=delta_x;
    t1.second+=delta_y;
    t2.second+=delta_y;
    t3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t) {
    double delta_x, delta_y;
    Tacka T = DajCentar();
    delta_x = t.first-T.first;
    delta_y = t.second-T.second;
    Transliraj(delta_x, delta_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    Tacka T1(DajTjeme(1));
    Tacka T2(DajTjeme(2));
    Tacka T3(DajTjeme(3));
    if(fabs(t1.first-t.first)<E && fabs(t1.second-t.second)<E) {  //rotira oko t1
        t2.first=t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao);
        t3.first=t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao);
        t2.second=t.second+(T2.first-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao);
        t3.second=t.second+(T3.first-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao);
    }
    else if(fabs(t2.first-t.first)<E && fabs(t2.second-t.second)<E) {//rotira oko t2
        t1.first=t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao);
        t3.first=t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao);
        t1.second=t.second+(T1.first-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao);
        t3.second=t.second+(T3.first-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao);
    }
    else if(fabs(t3.first-t.first)<E && fabs(t3.second-t.second)<E) {//rotira oko t3
        t1.first=t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao);
        t2.first=t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao);
        t1.second=t.second+(T1.first-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao);
        t2.second=t.second+(T2.first-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao);
    }
    else {                                                                      //inace
        t1.first=t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao);
        t2.first=t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao);
        t3.first=t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao);
        t1.second=t.second+(T1.first-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao);
        t2.second=t.second+(T2.first-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao);
        t3.second=t.second+(T3.first-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao);
    }
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    Tacka T1(DajTjeme(1));
    Tacka T2(DajTjeme(2));
    Tacka T3(DajTjeme(3));
    if(fabs(0-faktor)<E) throw std::domain_error("Nekorektan faktor skaliranja");
    if(fabs(t.first-t1.first)<E && fabs(t.second-t1.second)<E) {  //ukoliko je t tjeme t1
        t2.first=t.first+faktor*(T2.first-t.first);
        t2.second=t.second+faktor*(T2.second-t.second);
        t3.first=t.first+faktor*(T3.first-t.first);
        t3.second=t.second+faktor*(T3.second-t.second);
    }
    else if(fabs(t.first-t2.first)<E && fabs(t.second-t2.second)<E) { //ukoliko je t tjeme t2
        t1.first=t.first+faktor*(T1.first-t.first);
        t1.second=t.second+faktor*(T1.second-t.second);
        t3.first=t.first+faktor*(T3.first-t.first);
        t3.second=t.second+faktor*(T3.second-t.second);
    }
    else if(fabs(t.first-t3.first)<E && fabs(t.second-t3.second)<E) { //ukoliko je t tjeme t3
        t1.first=t.first+faktor*(T1.first-t.first);
        t1.second=t.second+faktor*(T1.second-t.second);
        t2.first=t.first+faktor*(T2.first-t.first);
        t2.second=t.second+faktor*(T2.second-t.second);
    }                                                                           // da li treba ako se tacka nalazi bilo gdje "na" trouglu
    else{                                                                       //dodao ovdje za slucaj da je tacka "oko" koje se skalira bilo "gdje"
        t1.first=t.first+faktor*(T1.first-t.first);
        t1.second=t.second+faktor*(T1.second-t.second);
        t2.first=t.first+faktor*(T2.first-t.first);
        t2.second=t.second+faktor*(T2.second-t.second);
        t3.first=t.first+faktor*(T3.first-t.first);
        t3.second=t.second+faktor*(T3.second-t.second);
    }
}
void Trougao::Rotiraj(double ugao) {
    Tacka T(DajCentar());
    Rotiraj(T,ugao);
}
void Trougao::Skaliraj(double faktor) {
    if(fabs(0-faktor)<E) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka T=DajCentar();
    Skaliraj(T,faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    std::vector<Tacka> vt1{t1.t1, t1.t2, t1.t3};
    std::vector<Tacka> vt2{t2.t1, t2.t2, t2.t3};
    int brojac(0);
    for(int i(0); i<vt1.size(); i++) {
        for(int j(0); j<vt2.size(); j++) {
            if(fabs(vt1[i].first-vt2[j].first)<E && fabs(vt1[i].second-vt2[j].second)<E)  {
                brojac++;
                break;
            }
        }
    }
    if(brojac==3) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    double a, b, c, d, e, f;
    Tacka T21, T22, T23, T11, T12, T13;
    a=t1.DajStranicu(1);
    b=t1.DajStranicu(2);
    c=t1.DajStranicu(3);
    d=t2.DajStranicu(1);
    e=t2.DajStranicu(2);
    f=t2.DajStranicu(3);
    std::vector<double> vs1{a, b, c};
    std::vector<double> vs2{d, e, f};
    std::vector<int> prvitrougao{1, 2, 3};
    std::vector<int> dt(3);
    int brojac(0);
    for(int i(0); i<vs1.size(); i++) {
        for(int j(0); j<vs2.size(); j++) {
            if(fabs(vs1[i]-vs2[j])<E) {                                    //vazi ako su sve stranice jednog trougla razlicitih duzina
                    brojac++;
                    dt[i]=j+1;
                    break;
            }
        }
    }
    Trougao drugi(t2.t1, t2.t2, t2.t3);
    if(dt[0]==1 && dt[1]==3 && dt[2]==2) drugi.Postavi(t2.t1, t2.t3, t2.t2);
    if(dt[0]==2 && dt[1]==3 && dt[2]==1) drugi.Postavi(t2.t2, t2.t3, t2.t1);
    if(dt[0]==2 && dt[1]==1 && dt[2]==3) drugi.Postavi(t2.t2, t2.t1, t2.t3);
    if(dt[0]==3 && dt[1]==1 && dt[2]==2) drugi.Postavi(t2.t3, t2.t1, t2.t2);
    if(dt[0]==3 && dt[1]==2 && dt[2]==1) drugi.Postavi(t2.t3, t2.t2, t2.t1);
    Trougao prvi(t1.t1, t1.t2, t1.t3);
    int orjentacija1 = prvi.Orijentacija(prvi.t1, prvi.t2, prvi.t3);
    int orjentacija2 = drugi.Orijentacija(drugi.t1, drugi.t2, drugi.t3);
    if(brojac==3 && orjentacija2==orjentacija1) return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {                       // za slicnost trouglova preko O:O1=m:n; P:P1=m^2:n^2 valjda moze
    double O, O1;
    O=t1.DajObim();
    O1=t2.DajObim();
    double odnos;
    odnos=O/O1;
    double a, b, c, d, e, f;
    a=t1.DajStranicu(1);
    b=t1.DajStranicu(2);
    c=t1.DajStranicu(3);
    d=t2.DajStranicu(1);
    e=t2.DajStranicu(2);
    f=t2.DajStranicu(3);
    std::vector<double> vs1{a, b, c};
    std::vector<double> vs2{d, e, f};
    std::vector<int> prvitrougao{1, 2, 3};
    std::vector<int> dt(3);
    int brojac(0);
    for(int i(0); i<vs1.size(); i++) {
        for(int j(0); j<vs2.size(); j++) {
            if(fabs(vs1[i]/vs2[j]-odnos)<E) {
                brojac++;
                dt[i]=j+1;
                break;
            }
        }
    }
    Trougao drugi(t2.t1, t2.t2, t2.t3);
    if(dt[0]==1 && dt[1]==3 && dt[2]==2) drugi.Postavi(t2.t1, t2.t3, t2.t2);
    if(dt[0]==2 && dt[1]==3 && dt[2]==1) drugi.Postavi(t2.t2, t2.t3, t2.t1);
    if(dt[0]==2 && dt[1]==1 && dt[2]==3) drugi.Postavi(t2.t2, t2.t1, t2.t3);
    if(dt[0]==3 && dt[1]==1 && dt[2]==2) drugi.Postavi(t2.t3, t2.t1, t2.t2);
    if(dt[0]==3 && dt[1]==2 && dt[2]==1) drugi.Postavi(t2.t3, t2.t2, t2.t1);
    Trougao prvi(t1.t1, t1.t2, t1.t3);
    int orjentacija1 = prvi.Orijentacija(prvi.t1, prvi.t2, prvi.t3);
    int orjentacija2 = drugi.Orijentacija(drugi.t1, drugi.t2, drugi.t3);
    if(brojac==3 && orjentacija2==orjentacija1) return true;
    return false;
}
int main (){
    int n(0);
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> pametni(n);
    for(int i(0); i<n; i++) pametni[i]=nullptr;
    for(int i(0); i<n; i++) {
        try {
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka t1, t2, t3;
            std::cin >> t1.first >> t1.second >> t2.first >> t2.second >> t3.first >> t3.second;
            pametni[i]=std::make_shared<Trougao>(t1, t2, t3);
        }
        catch(std::domain_error e) {
            std::cout << e.what() << ", ponovite unos!" << std::endl;
            i--;
        }
        catch(std::bad_alloc) {
            std::cout << "Nema memorije" << std::endl;
        }
    }
    double delta_x, delta_y, faktor, ugao;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> delta_x >> delta_y;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor;
    std::transform(pametni.begin(), pametni.end(), pametni.begin(), [delta_x, delta_y, ugao, faktor](std::shared_ptr<Trougao> p) {
        p->Transliraj(delta_x, delta_y);
        p->Rotiraj(ugao);
        p->Skaliraj(p->DajTjeme(1), faktor);
        return p;
    });
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::sort(pametni.begin(), pametni.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {return p1->DajPovrsinu()<p2->DajPovrsinu();});
    std::for_each(pametni.begin(), pametni.end(), [](std::shared_ptr<Trougao> p) {p->Ispisi(); std::cout << std::endl;});
    std::cout << "Trougao sa najmanjim obimom: ";
    Trougao koliko(**(std::min_element(pametni.begin(), pametni.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) {
        return p1->DajObim()<p2->DajObim();
    })));
    koliko.Ispisi();
    std::cout << std::endl;
    int BIdenticnih(0), BPodudarnih(0), BSlicnih(0);
    for(int i(0); i<pametni.size()-1; i++) {
        for(int j(i+1); j<pametni.size(); j++) {
            if(DaLiSuIdenticni(*pametni[i], *pametni[j])) BIdenticnih++;
            if(DaLiSuPodudarni(*pametni[i], *pametni[j])) BPodudarnih++;
            if(DaLiSuSlicni(*pametni[i], *pametni[j])) BSlicnih++;
        }
    }
    if(BIdenticnih!=0) {
        std::cout << "Parovi identicnih trouglova:" << std::endl;
        for(int i(0); i<pametni.size()-1; i++) {
            for(int j(i+1); j<pametni.size(); j++) {
                if(DaLiSuIdenticni(*pametni[i], *pametni[j])){ 
                    pametni[i]->Ispisi();
                    std::cout << " i "; 
                    pametni[j]->Ispisi();
                    std::cout << std::endl;
                }
            }
        }
    }
    else std::cout <<"Nema identicnih trouglova!" << std::endl;
    if(BPodudarnih!=0) {
        std::cout << "Parovi podudarnih trouglova:" << std::endl;
        for(int i(0); i<pametni.size()-1; i++) {
            for(int j(i+1); j<pametni.size(); j++) {
                if(DaLiSuPodudarni(*pametni[i], *pametni[j])) {
                    pametni[i]->Ispisi();
                    std::cout << " i "; 
                    pametni[j]->Ispisi();
                    std::cout << std::endl;
                }
            }
        }
    }
    else std::cout << "Nema podudarnih trouglova!" << std::endl;
    if(BSlicnih!=0) {
        std::cout << "Parovi slicnih trouglova:" << std::endl;
        for(int i(0); i<pametni.size()-1; i++) {
            for(int j(i+1); j<pametni.size(); j++) {
                if(DaLiSuSlicni(*pametni[i], *pametni[j])) {
                    pametni[i]->Ispisi();
                    std::cout << " i ";
                    pametni[j]->Ispisi();
                    std::cout << std::endl;
                }
            }
        }
    }
    else std::cout << "Nema slicnih trouglova!";
	return 0;
}