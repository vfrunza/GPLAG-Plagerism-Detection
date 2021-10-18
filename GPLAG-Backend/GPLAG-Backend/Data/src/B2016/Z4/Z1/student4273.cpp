/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility> //Zbog pair
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

using std::cin; using std::cout; using std::endl;

typedef std::pair<double, double> Tacka;

const double Eps(1e-10); 

class Trougao {
    Tacka T1, T2, T3;
    static bool Jednaki(double x, double y);
    static double Pomocna (Tacka t1, Tacka t2, Tacka t3);
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
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

bool Trougao::Jednaki(double x, double y) {
    return std::fabs(x-y) <= Eps * (std::fabs(x) + std::fabs(y));
}
double Trougao::Pomocna (Tacka t1, Tacka t2, Tacka t3) {
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Orijentacija(t1, t2, t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    T1=t1; T2=t2; T3=t3;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Orijentacija(t1, t2, t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    T1=t1; T2=t2; T3=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t) {
    if (indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    if (indeks==1) {
        if (Orijentacija(t, T2, T3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        T1=t; 
    }
    else if (indeks==2) {
        if (Orijentacija(T1, t, T3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        T2=t; 
    }
    else {
        if (Orijentacija(T1, T2, t)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        T3=t; 
    }
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    auto rez(Pomocna(t1, t2, t3));
    if (Trougao::Jednaki(rez,0)) return 0; //Kolinearne su
    if (rez>0) return 1; //Kretanje od prve do posljdnje tacke u smjeru suprotnom od kazaljke na satu
    return -1;
}
Tacka Trougao::DajTjeme(int indeks) const {
    if (indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    if (indeks==1) return T1;
    if (indeks==2) return T2;
    return T3;
}
double Trougao::DajStranicu(int indeks) const {
    if (indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    double rez(0);
    if (indeks==1) {
        rez=std::sqrt((T2.first-T3.first)*(T2.first-T3.first)+(T2.second-T3.second)*(T2.second-T3.second));
        return rez;
    }
    if (indeks==2) {
        rez=std::sqrt((T1.first-T3.first)*(T1.first-T3.first)+(T1.second-T3.second)*(T1.second-T3.second));
        return rez;
    }
    rez=std::sqrt((T2.first-T1.first)*(T2.first-T1.first)+(T2.second-T1.second)*(T2.second-T1.second));
    return rez;
}
double Trougao::DajUgao(int indeks) const {
    if (indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    //Iznos ugla koji se nalazi u tjemenu u radijanim
    double rez(0);
    double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
    if (indeks==1) {
        rez=std::acos((b*b+c*c-a*a)/(2*b*c));
        return rez;
    }
    if (indeks==2) {
        rez=std::acos((a*a+c*c-b*b)/(2*a*c));
        return rez;
    }
    rez=std::acos((a*a+b*b-c*c)/(2*a*b));
    return rez;
}
Tacka Trougao::DajCentar() const {
    //Teziste - koordinate aritmeticke sredine koordinata tjemena
    Tacka T;
    T.first=(T1.first+T2.first+T3.first)/3;
    T.second=(T1.second+T2.second+T3.second)/3;
    return T;
}
double Trougao::DajObim() const {
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu() const {
    return 0.5*std::fabs(Pomocna(T1, T2, T3));
}
bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if (Orijentacija(this->T1, this->T2, this->T3)) return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if (Orijentacija(T1, T2, T3)==Orijentacija(T1, t, T3) && Orijentacija(T1, T2, t)==Orijentacija(T2, T3, t) && Orijentacija(T2, T3, t)==Orijentacija(T1, t, T3))
    return true;
    return false;
}
void Trougao::Ispisi() const {
    cout << "((" << T1.first << "," << T1.second << "),(" << T2.first << "," << T2.second << "),(" << T3.first << "," << T3.second << "))";
}
void Trougao::Transliraj(double delta_x, double delta_y) {
    T1.first+=delta_x; T2.first+=delta_x; T3.first+=delta_x;
    T1.second+=delta_y; T2.second+=delta_y; T3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t) {
    auto delta_x(t.first-DajCentar().first);
    auto delta_y(t.first-DajCentar().second);
    Transliraj(delta_x, delta_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    auto x1(T1.first), x2(T2.first), x3(T3.first);
    T1.first=t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao); 
    T1.second=t.second+(x1-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao);
    T2.first=t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao);
    T2.second=t.second+(x2-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao);
    T3.first=t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao);
    T3.second=t.second+(x3-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if (Trougao::Jednaki(faktor, 0)) throw std::domain_error ("Nekorektan faktor skaliranja");
    T1.first=t.first+faktor*(T1.first-t.first);
    T1.second=t.second+faktor*(T1.second-t.second);
    T2.first=t.first+faktor*(T2.first-t.first);
    T2.second=t.second+faktor*(T2.second-t.second);
    T3.first=t.first+faktor*(T3.first-t.first);
    T3.second=t.second+faktor*(T3.second-t.second);
}
void Trougao::Rotiraj(double ugao) {
    Rotiraj(DajCentar(), ugao);
}
void Trougao::Skaliraj(double faktor) {
    Skaliraj(DajCentar(), faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
     std::vector<Tacka> v1, v2;
     for (int i=0; i<3; i++) {
         v1.push_back(t1.DajTjeme(i+1)); v2.push_back(t2.DajTjeme(i+1)); //Vektori tjemena trougla
     }
     for (int i=0; i<3; i++) {
         for (int j=0; j<v2.size(); j++) {
             if (Trougao::Jednaki(v1[i].first,v2[j].first) && Trougao::Jednaki(v1[i].second,v2[j].second)) 
             v2.erase(v2.begin()+j);
         }
     }
     if (v2.size()==0) return true;
     return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    //Trouglovi su podudarni ukoliko se mogu dovesti na poklapanje translacijom i rotacijom
    //Da bi bili podudarni moraju biti jednake odgovarajuce stranice i ista orijentacija?
    auto orijentacija_prvi(Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)));
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(2)) && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(3)))
        return true;
    }
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(3), t2.DajTjeme(2)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(1)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(3)) && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(2)))
        return true;
    }
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(2), t2.DajTjeme(1), t2.DajTjeme(3)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(2)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(1)) && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(3)))
        return true;
    }
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(2), t2.DajTjeme(3), t2.DajTjeme(1)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(2)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(3)) && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(1)))
        return true;
    }
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(3), t2.DajTjeme(1), t2.DajTjeme(2)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(3)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(1)) && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(2)))
        return true;
    }
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(3), t2.DajTjeme(2), t2.DajTjeme(1)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1), t2.DajStranicu(3)) && Trougao::Jednaki(t1.DajStranicu(2), t2.DajStranicu(2)) && Trougao::Jednaki(t1.DajStranicu(3), t2.DajStranicu(1)))
        return true;
    }
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    auto orijentacija_prvi(Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3)));
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(1),t1.DajStranicu(2)/t2.DajStranicu(2)) && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(2), t1.DajStranicu(3)/t2.DajStranicu(3)))
        return true;
    }
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(1), t2.DajTjeme(3), t2.DajTjeme(2)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(1), t1.DajStranicu(2)/t2.DajStranicu(3) ) && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(3), t1.DajStranicu(3)/t2.DajStranicu(2)))
        return true;
    }
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(2), t2.DajTjeme(1), t2.DajTjeme(3)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(2), t1.DajStranicu(2)/t2.DajStranicu(1)) && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(1), t1.DajStranicu(3)/t2.DajStranicu(3)))
        return true;
    }
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(2), t2.DajTjeme(3), t2.DajTjeme(1)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(2), t1.DajStranicu(2)/t2.DajStranicu(3)) && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(3), t1.DajStranicu(3)/t2.DajStranicu(1)))
        return true;
    }
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(3), t2.DajTjeme(1), t2.DajTjeme(2)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(3), t1.DajStranicu(2)/t2.DajStranicu(1) ) && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(1), t1.DajStranicu(3)/t2.DajStranicu(2)))
        return true;
    }
    if (Trougao::Jednaki(orijentacija_prvi, Trougao::Orijentacija(t2.DajTjeme(3), t2.DajTjeme(2), t2.DajTjeme(1)))) {
        //Ispitaj stranice
        if (Trougao::Jednaki(t1.DajStranicu(1)/t2.DajStranicu(3), t1.DajStranicu(2)/t2.DajStranicu(2)) && Trougao::Jednaki(t1.DajStranicu(2)/t2.DajStranicu(2), t1.DajStranicu(3)/t2.DajStranicu(1)))
        return true;
    }
    return false;
}

int main ()
{
    int n(0);
    cout << "Koliko zelite kreirati trouglova: ";
    cin >> n;
    std::vector<std::shared_ptr<Trougao>> vek(n);
    for (int i=0; i<n; i++) {
        cout << "Unesite podatke za "<< i+1 <<". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Tacka t1=std::make_pair(x1,y1);
        Tacka t2=std::make_pair(x2,y2);
        Tacka t3=std::make_pair(x3,y3);
        try {
            vek[i]=std::make_shared<Trougao>(t1, t2, t3); //din. alociramo trougao
        }
        catch (std::domain_error izuzetak) {
            cout << izuzetak.what() << ", ponovite unos!" << endl;
            i--;
        }
    }
    double d_x, d_y;
    cout << "Unesite vektor translacije (dx dy): ";
    cin >> d_x >> d_y;
    std::transform(vek.begin(), vek.end(), vek.begin(), [d_x, d_y] (std::shared_ptr<Trougao> pnt)->std::shared_ptr<Trougao> { pnt->Transliraj(d_x, d_y); return pnt; });
	cout << "Unesite ugao rotacije: ";
	//Rotiramo oko centra
	double ugao;
	cin >> ugao;
	std::transform(vek.begin(), vek.end(), vek.begin(), [ugao] (std::shared_ptr<Trougao> pnt)->std::shared_ptr<Trougao> { pnt->Rotiraj(ugao); return pnt; });
	cout << "Unesite faktor skaliranja: ";
	double faktor;
	cin >> faktor;
	//Uzimamo prvo tjeme kao centar skaliranja!!
	std::transform(vek.begin(), vek.end(), vek.begin(), [faktor] (std::shared_ptr<Trougao> pnt)->std::shared_ptr<Trougao> { pnt->Skaliraj(pnt->DajTjeme(1), faktor); return pnt; });
	//Sortirajmo sve trouglove
	std::sort(vek.begin(), vek.end(), [] (std::shared_ptr<Trougao> pnt1, std::shared_ptr<Trougao> pnt2) { return (pnt1->DajPovrsinu())<(pnt2->DajPovrsinu()); });
	cout << "Trouglovi nakon obavljenih transformacija:" << endl;
	std::for_each(vek.begin(), vek.end(), [] (std::shared_ptr<Trougao> pnt) {  pnt->Ispisi(); cout << endl; } );
	cout << "Trougao sa najmanjim obimom: ";
	auto p(std::min_element(vek.begin(), vek.end(), [] (std::shared_ptr<Trougao> pnt1, std::shared_ptr<Trougao> pnt2) { return (pnt1->DajObim())<(pnt2->DajObim()); }));
	(*p)->Ispisi(); cout << endl;
	bool prvi(true);
	for (int i=0; i<n; i++) {
	    for (int j=i+1; j<n; j++) {
	        if (DaLiSuIdenticni(*vek[i], *vek[j])) {
	            if (prvi) { cout << "Parovi identicnih trouglova:" << endl; prvi=false; }
	            vek[i]->Ispisi(); cout << " i "; vek[j]->Ispisi(); cout << endl;
	        }
	    }
	}
	if (prvi) { cout << "Nema identicnih trouglova!" << endl; }
	prvi=true;
	for (int i=0; i<n; i++) {
	    for (int j=i+1; j<n; j++) {
	        if (DaLiSuPodudarni(*vek[i], *vek[j])) {
	            if (prvi) { cout << "Parovi podudarnih trouglova:" << endl; prvi=false; }
	            vek[i]->Ispisi(); cout << " i "; vek[j]->Ispisi(); cout << endl;
	        }
	    }
	}
	if (prvi) { cout << "Nema podudarnih trouglova!" << endl; }
	prvi=true;
	for (int i=0; i<n; i++) {
	    for (int j=i+1; j<n; j++) {
	        if (DaLiSuSlicni(*vek[i], *vek[j])) {
	            if (prvi) { cout << "Parovi slicnih trouglova:" << endl; prvi=false; }
	            vek[i]->Ispisi(); cout << " i "; vek[j]->Ispisi(); cout << endl;
	        }
	    }
	}
	if (prvi) { cout << "Nema slicnih trouglova!" << endl; }
	return 0;
}