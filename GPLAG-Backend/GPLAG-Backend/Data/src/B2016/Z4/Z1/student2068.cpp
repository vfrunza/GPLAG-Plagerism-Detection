#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <memory>

#define eps 1E-10

typedef std::pair<double, double> Tacka;

inline double Kvadrat(double x) { return x*x; }

class Trougao {
    Tacka tacke[3];
    static double pomocna(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    static void TestIndeksa(int indeks) { if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks"); }
public :
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); } //
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3); //
    void Postavi(int indeks, const Tacka &t); //
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3); //
    Tacka DajTjeme(int indeks) const { TestIndeksa(indeks); return tacke[indeks-1]; } //
    double DajStranicu(int indeks) const; //
    double DajUgao(int indeks) const; //
    Tacka DajCentar() const; //
    double DajObim() const { return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); } //
    double DajPovrsinu() const { return 0.5 * fabs(pomocna(tacke[0], tacke[1], tacke[2])); } //
    bool DaLiJePozitivnoOrijentiran() const { return pomocna(tacke[0], tacke[1], tacke[2]) > 0; } //
    bool DaLiJeUnutra(const Tacka &t) const; //
    void Ispisi() const { std::cout << "((" << tacke[0].first << "," << tacke[0].second << "),(" << tacke[1].first << "," << tacke[1].second << "),(" << tacke[2].first << "," << tacke[2].second << "))"; }
    void Transliraj(double delta_x, double delta_y); //
    void Centriraj(const Tacka &t); // 
    void Rotiraj(const Tacka &t, double ugao); //
    void Skaliraj(const Tacka &t, double faktor); //
    void Rotiraj(double ugao) { Rotiraj(DajCentar(), ugao); } //
    void Skaliraj(double faktor) { Skaliraj(DajCentar(), faktor); } //
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2); //
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double o=pomocna(t1, t2, t3);
    if(fabs(o)<eps) return 0;
    if(o>0) return 1;
    return -1;
}

double Trougao::pomocna(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(!Orijentacija(t1, t2, t3)) throw std::domain_error("Nekorektne pozicije tjemena");
    tacke[0]=t1; tacke[1]=t2; tacke[2]=t3;
}

void Trougao::Postavi(int indeks, const Tacka &t) {
    TestIndeksa(indeks);
    tacke[indeks-1]=t;
    if(!Orijentacija(tacke[0], tacke[1], tacke[2])) throw std::domain_error("Nekorektne pozicije tjemena");
}

double Trougao::DajStranicu(int indeks) const {
    TestIndeksa(indeks);
    Tacka t1, t2;
    if(indeks==1) t1=tacke[1], t2=tacke[2];
    else if(indeks==2) t1=tacke[0], t2=tacke[2];
    else { t1=tacke[0], t2=tacke[1]; }
    return std::sqrt( Kvadrat(t1.first-t2.first) + Kvadrat(t1.second-t2.second) );
}

double Trougao::DajUgao(int indeks) const {
    TestIndeksa(indeks);
    double c=DajStranicu(indeks), a, b;
    if(indeks==1) {
        a=DajStranicu(2); b=DajStranicu(3);
    }
    else if(indeks==2) {
        a=DajStranicu(1); b=DajStranicu(3);
    }
    else {
        a=DajStranicu(1); b=DajStranicu(2);
    }
    return acos( (Kvadrat(a)+Kvadrat(b)-Kvadrat(c)) / (2*a*b) );
}

Tacka Trougao::DajCentar() const {
    return { (tacke[0].first+tacke[1].first+tacke[2].first)/3 , (tacke[0].second+tacke[1].second+tacke[2].second) /3 };
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    int a=Orijentacija(tacke[0], tacke[1], tacke[2]);
    if(a!=Orijentacija(tacke[0], tacke[1], t)) return false;
    if(a!=Orijentacija(tacke[1], tacke[2], t)) return false;
    if(a!=Orijentacija(tacke[2], tacke[0], t)) return false;
    return true;
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    tacke[0].first+=delta_x; tacke[0].second+=delta_y;
    tacke[1].first+=delta_x; tacke[1].second+=delta_y;
    tacke[2].first+=delta_x; tacke[2].second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t) {
    Tacka tez=DajCentar();
    double delta_x=tez.first, delta_y=tez.second;
    Transliraj(-1*delta_x, -1*delta_y);
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    std::for_each(tacke, tacke+3, [t, ugao](Tacka &x) {
        double a=t.first+(x.first-t.first)*cos(ugao)-(x.second-t.second)*sin(ugao);
        x.second=t.second+(x.first-t.first)*sin(ugao)+(x.second-t.second)*cos(ugao);
        x.first=a;
    });
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(fabs(faktor)<eps) throw std::domain_error("Nekorektan faktor skaliranja");
    std::for_each(tacke, tacke+3, [t, faktor](Tacka &x) {
        x.first=t.first+faktor*(x.first-t.first);
        x.second=t.second+faktor*(x.second-t.second);
    });
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    for(int i=0; i<3; i++) {
        bool nadjen=false;
        for(int j=0; j<3; j++) 
            if(t1.tacke[i]==t2.tacke[j]) { nadjen=true; break; }
        if(!nadjen) return false;
    }
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    if(!DaLiSuSlicni(t1, t2)) return false;
    double a[3]={t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)};
    double b[3]={t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
    for(int i=0; i<3; i++) {
        bool nadjen=false;
        for(int j=0; j<3; j++)
            if(fabs(a[i]-b[j])<eps) { nadjen=true; break; }
        if(!nadjen) return false;
    }
    return true;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    double a[3]={t1.DajUgao(1), t1.DajUgao(2), t1.DajUgao(3)}; 
    double b[3]={t2.DajUgao(1), t2.DajUgao(2), t2.DajUgao(3)}; //std::cout << b[0] << " " << b[1] << " " << b[2] << "\n";
    if(Trougao::Orijentacija(t1.tacke[0], t1.tacke[1], t1.tacke[2])!=Trougao::Orijentacija(t2.tacke[0], t2.tacke[1], t2.tacke[2])) {
        double p=a[0];
        a[0]=a[2]; a[2]=p;
    }
    //std::cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    for(int i=0; i<3; i++) {
        bool nadjen=false;
        for(int j=0; j<3; j++) {
            if(fabs(a[i]-b[j])<eps) { nadjen=true; break; }
        }
        if(!nadjen) return false;
    }
    if(fabs(a[0]-b[0])<eps) return fabs(a[1]-b[1])<eps;
    if(fabs(a[0]-b[1])<eps) return fabs(a[1]-b[2])<eps;
    return fabs(a[1]-b[0])<eps;
    // return Trougao::Orijentacija(t1.tacke[0], t1.tacke[1], t1.tacke[2])==Trougao::Orijentacija(t2.tacke[0], t2.tacke[1], t2.tacke[2]);
}

int main () {
    std::cout << "Koliko zelite kreirati trouglova: ";
	int n; std::cin >> n;
	std::vector<std::shared_ptr<Trougao>>v;
	for(int i=0; i<n; i++) {
	    std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
	    double x1, y1, x2, y2, x3, y3; std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	    try { v.emplace_back(std::make_shared<Trougao>(Trougao({x1,y1}, {x2,y2}, {x3,y3}))); }
	    catch(std::domain_error izuzetak) {
	        std::cout << izuzetak.what() << ", ponovite unos!\n";
	        i--;
	    }
	}
	std::cout << "Unesite vektor translacije (dx dy): ";
	double dx, dy; std::cin >> dx >> dy;
	std::cout << "Unesite ugao rotacije: ";
    double ugao; std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    double faktor; std::cin >> faktor; if(fabs(faktor)<eps) std::cout << "Nekorektan faktor skaliranja!\n";
	else std::transform(v.begin(), v.end(), v.begin(), [dx, dy, ugao, faktor](std::shared_ptr<Trougao>p1) {
	    p1->Transliraj(dx, dy);
	    p1->Rotiraj(ugao);
	    p1->Skaliraj(p1->DajTjeme(1), faktor);
	    return p1;
	});
	std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao>p1, std::shared_ptr<Trougao>p2) {
	   return p1->DajPovrsinu() < p2->DajPovrsinu(); 
	});
	std::cout << "Trouglovi nakon obavljenih transformacija:";
	std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao>p1) {
	    std::cout << "\n"; p1->Ispisi(); 
	});
	auto i=std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao>p1, std::shared_ptr<Trougao>p2) {
	    return p1->DajObim() < p2->DajObim(); 
	});
	std::cout << "\nTrougao sa najmanjim obimom: ";
	(*i)->Ispisi();
	bool ispisan=false;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(DaLiSuIdenticni(*v[i], *v[j])) {
                if(!ispisan) std::cout << "\nParovi identicnih trouglova:\n";
                ispisan=true;
                v[i]->Ispisi(); std::cout << " i "; v[j]->Ispisi();
                std::cout << "\n";
            }
        }
    }
    if(!ispisan) std::cout << "\nNema identicnih trouglova!\n";
    ispisan=false;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(DaLiSuPodudarni(*v[i], *v[j])) {
                if(!ispisan) std::cout << "Parovi podudarnih trouglova:\n";
                ispisan=true;
                v[i]->Ispisi(); std::cout << " i "; v[j]->Ispisi();
                std::cout << "\n";
            }
        }
    }
    if(!ispisan) std::cout << "Nema podudarnih trouglova!\n";
    ispisan=false;
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(DaLiSuSlicni(*v[i], *v[j])) {
                if(!ispisan) std::cout << "Parovi slicnih trouglova:\n";
                ispisan=true;
                v[i]->Ispisi(); std::cout << " i "; v[j]->Ispisi();
                std::cout << "\n";
            }
        }
    }
    if(!ispisan) std::cout << "Nema slicnih trouglova!";
    return 0;
}