/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

using std::cout;
using std::cin;
using std::pair;
using std::domain_error;
using std::range_error;
using std::abs;
using std::make_pair;
using std::endl;
using std::sort;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::transform;
using std::for_each;
using std::min_element;

const double Eps = 1E-10;

typedef pair<double, double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    
    public :
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
        void Rotiraj(const Tacka &t, double faktor);
        void Skaliraj(const Tacka &t, double ugao);
        void Rotiraj(double ugao);
        void Skaliraj(double faktor);
        
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

// JesuLiJednaki
bool JLJ(double x, double y) {
    if ((x < 0 && y > 0) || (x > 0 && y < 0))
        return false;
    return (abs(x - y) <= Eps * (abs(x) + abs(y)));
}

bool Jednake(const Tacka &t1, const Tacka &t2)
{
    return (JLJ(t1.first, t2.first) && JLJ(t1.second, t2.second));
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    Postavi(t1, t2, t3);
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if (!Orijentacija(t1, t2, t3))
        throw domain_error("Nekorektne pozicije tjemena");
    Trougao::t1 = t1; Trougao::t2 = t2; Trougao::t3 = t3;
}

void Trougao::Postavi(int indeks, const Tacka &t)
{
    if (indeks == 1)
        Postavi(t, t2, t3);
    else if(indeks == 2)
        Postavi(t1, t, t3);
    else if(indeks == 3)
        Postavi(t1, t2, t);
    else
        throw range_error("Nekorektan indeks");
}

// TODO: zapisati da smo DetVrhova morali implementirati iznad Orijentacija?
double DetVrhova(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    return t1.first*(t2.second - t3.second) + t2.first*(t3.second - t1.second) +
        t3.first*(t1.second - t2.second);
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double determinanta(DetVrhova(t1, t2, t3));
    return (determinanta > 0) - (determinanta < 0);
}

Tacka Trougao::DajTjeme(int indeks) const
{
    if (indeks == 1)
        return t1;
    else if(indeks == 2)
        return t2;
    else if(indeks == 3)
        return t3;
    else
        throw range_error("Nekorektan indeks");
}

// Racuna duzinu (neusmjerene) duzi t1-t2
double Duzina(const Tacka &t1, const Tacka &t2) {
    return sqrt(pow(t1.first - t2.first, 2) + pow(t1.second - t2.second, 2));
}

double Trougao::DajStranicu(int indeks) const
{
    if (indeks == 1)
        return Duzina(t2, t3);
    else if(indeks == 2)
        return Duzina(t1, t3);
    else if(indeks == 3)
        return Duzina(t1, t2);
    else
        throw range_error("Nekorektan indeks");
}

// Racuna ugao bac
double Ugao(const Tacka &a, const Tacka &b, const Tacka &c)
{
    Tacka ab = make_pair(b.first - a.first, b.second - a.second);
    Tacka ac = make_pair(c.first - a.first, c.second - a.second);
    double duz_b = Duzina(ab, make_pair<double, double>(0, 0));
    double duz_c = Duzina(ac,  make_pair<double, double>(0, 0));
    
    return acos((ab.first*ac.first + ab.second*ac.second) / (duz_b * duz_c)); // (ab1/duzb)*(ac1/duzc) + (ab2...
}

double Trougao::DajUgao(int indeks) const
{
    if (indeks == 1)
        return Ugao(t1, t2, t3);
    else if(indeks == 2)
        return Ugao(t2, t1, t3);
    else if(indeks == 3)
        return Ugao(t3, t1, t2);
    else
        throw range_error("Nekorektan indeks");
}

// TODO: upisati u predavanje 8b ako ne moramo eksplicitno specificirati tipove para
Tacka Trougao::DajCentar() const {
    return make_pair((t1.first + t2.first + t3.first) / 3,
        (t1.second + t2.second + t3.second) / 3);
}

double Trougao::DajObim() const {
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}

double Trougao::DajPovrsinu() const {
    return abs(DetVrhova(t1, t2, t3) / 2);
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
    return Orijentacija(t1, t2, t3) > 0;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    int broj(Orijentacija(t1, t2, t));
    return (broj != 0 && broj == Orijentacija(t2, t3, t) && 
        broj == Orijentacija(t3, t1, t));
}

void Trougao::Ispisi() const {
    cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," <<
        t2.second << "),(" << t3.first << "," << t3.second << "))";
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    t1.first += delta_x; t2.first += delta_x; t3.first += delta_x;
    t1.second += delta_y; t2.second += delta_y; t3.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{
    Tacka centar(DajCentar());
    Transliraj(t.first - centar.first, t.second - centar.second);
}

void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    double x(t.first), y(t.second);
    t1.first = (x + (t1.first - x)*cos(ugao) - (t1.second - y)*sin(ugao));
    t1.second = (y + (t1.second - y)*cos(ugao) + (t1.first - x)*sin(ugao));
    t2.first = (x + (t2.first - x)*cos(ugao) - (t2.second - y)*sin(ugao));
    t2.second = (y + (t2.second - y)*cos(ugao) + (t2.first - x)*sin(ugao));
    t3.first = (x + (t3.first - x)*cos(ugao) - (t3.second - y)*sin(ugao));
    t3.second = (y + (t3.second - y)*cos(ugao) + (t3.first - x)*sin(ugao));
}

void Trougao::Rotiraj(double ugao) {
    Rotiraj(DajCentar(), ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if (!faktor)
        throw domain_error("Nekorektan faktor skaliranja");
    t1 = make_pair(t.first + faktor*(t1.first - t.first), 
        t.second + faktor*(t1.second - t.second));
    t2 = make_pair(t.first + faktor*(t2.first - t.first), 
        t.second + faktor*(t2.second - t.second));
    t3 = make_pair(t.first + faktor*(t3.first - t.first), 
        t.second + faktor*(t3.second - t.second));
}

void Trougao::Skaliraj(double faktor)
{
    if (!faktor)
        throw domain_error("Nekorektan faktor skaliranja");
    Skaliraj(DajCentar(), faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if (Jednake(t1.t1, t2.t1)) {
        if (Jednake(t1.t2, t2.t2)) {
            if (Jednake(t1.t3, t2.t3)) {
                return true;
            }
        } else if (Jednake(t1.t2, t2.t3)) {
            if (Jednake(t1.t3, t2.t2)) {
                return true;
            }
        }
    } else if (Jednake(t1.t1, t2.t2)) {
        if (Jednake(t1.t2, t2.t1)) {
            if (Jednake(t1.t3, t2.t3)) {
                return true;
            }
        } else if (Jednake(t1.t2, t2.t3)) {
            if (Jednake(t1.t3, t2.t1)) {
                return true;
            }
        }
    } else if (Jednake(t1.t1, t2.t3)) {
        if (Jednake(t1.t2, t2.t1)) {
            if (Jednake(t1.t3, t2.t2)) {
                return true;
            }
        } else if (Jednake(t1.t2, t2.t2)) {
            if (Jednake(t1.t3, t2.t1)) {
                return true;
            }
        }
    }

    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    double duzine1[3] = {Duzina(t1.t1, t1.t2), Duzina(t1.t2, t1.t3), 
        Duzina(t1.t3, t1.t1)};
    double duzine2[3] = {Duzina(t2.t1, t2.t2), Duzina(t2.t2, t2.t3),
        Duzina(t2.t3, t2.t1)};
    sort(duzine1, duzine1 + 3);
    sort(duzine2, duzine2 + 3);
    
    if (JLJ(duzine1[0], duzine2[0]) && JLJ(duzine1[1], duzine2[1]) &&
        JLJ(duzine1[2], duzine1[2])) {
        if (JLJ(duzine1[0], duzine1[1]) || JLJ(duzine1[0], duzine1[2]) ||
            JLJ(duzine1[1], duzine1[2]))
                return true;
        else {
            double duz1 = Duzina(t1.t1, t1.t2), duz2 = Duzina(t1.t2, t1.t3);
            bool cond = (Trougao::Orijentacija(t1.t1, t1.t2, t1.t3) == 
                Trougao::Orijentacija(t2.t1, t2.t2, t2.t3));
            duzine2[0] = Duzina(t2.t1, t2.t2);
            duzine2[1] = Duzina(t2.t2, t2.t3);
            duzine2[2] = Duzina(t2.t3, t2.t1);
            
         
            if (JLJ(duz1, duzine2[0])) {
                if (JLJ(duz2, duzine2[1])) {
                    return cond;
                } else if (JLJ(duz2, duzine2[2])) {
                    return !cond;
                }
            } else if(JLJ(duz1, duzine2[1])) {
                if (JLJ(duz2, duzine2[2])) {
                    return cond;
                } else if(JLJ(duz2, duzine2[0])) {
                    return !cond ;
                }
            } else if (JLJ(duz1, duzine2[2])) {
                if (JLJ(duz2, duzine2[0])) {
                    return cond;
                } else {
                    return !cond;
                }
            }
        }
    }
    
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    double duzine1[3] = {Duzina(t1.t1, t1.t2), Duzina(t1.t2, t1.t3), 
        Duzina(t1.t3, t1.t1)};
    double duzine2[3] = {Duzina(t2.t1, t2.t2), Duzina(t2.t2, t2.t3),
        Duzina(t2.t3, t2.t1)};
    sort(duzine1, duzine1 + 3);
    sort(duzine2, duzine2 + 3);
    
    double prop(duzine1[0] / duzine2[0]);
    if (JLJ(prop, duzine1[1] / duzine2[1]) && JLJ(prop, duzine1[2] / duzine2[2])) {
        Tacka druga1(t2.t1), druga2(t2.t2), druga3(t2.t3);
        return DaLiSuPodudarni(t1, {make_pair(druga1.first * prop, druga1.second * prop),
            make_pair(druga2.first * prop, druga2.second * prop), 
            make_pair(druga3.first * prop, druga3.second * prop)});
    }
    
    return false;
}

int main ()
{
    int n;
    cout << "Koliko zelite kreirati trouglova: ";
    cin >> n;
    vector<shared_ptr<Trougao>> trouglovi(n);
    
    for(int i = 0; i < n; i++) {
        bool cond(true);
        double x1, y1, x2, y2, x3, y3;
        while (cond) {
            cout << "Unesite podatke za " << i + 1 <<". trougao (x1 y1 x2 y2 x3 y3): ";
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            try {
                trouglovi[i] = make_shared<Trougao>(Trougao(make_pair(x1, y1), 
                    make_pair(x2, y2), make_pair(x3, y3)));
                cond = false;
            } catch(domain_error &e) {
                cout << e.what() << ", ponovite unos!" << std::endl;
            }
        }
    }
    
    double dx, dy, ugao, faktor; 
    cout << "Unesite vektor translacije (dx dy): ";
    cin >> dx >> dy;
    cout << "Unesite ugao rotacije: ";
    cin >> ugao;
    cout << "Unesite faktor skaliranja: ";
    cin >> faktor;
    
    try {    
        transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [dx, dy, ugao, faktor](shared_ptr<Trougao> p) {
            p->Transliraj(dx, dy);
            p->Rotiraj(p->DajCentar(), ugao);
            p->Skaliraj(p->DajTjeme(1), faktor);
            return p;
        });
    } catch(domain_error &ex) {
        cout << ex.what();
        return 0;
    }
    
    sort(trouglovi.begin(), trouglovi.end(), [](shared_ptr<Trougao> p1, shared_ptr<Trougao> p2) {
        return p1->DajPovrsinu() < p2->DajPovrsinu();
    });
    cout << "Trouglovi nakon obavljenih transformacija:" << endl;
    for_each(trouglovi.begin(), trouglovi.end(), [](shared_ptr<Trougao> p) {
        p->Ispisi();
        cout << endl;
    });
    
    cout << "Trougao sa najmanjim obimom: ";
    (*(min_element(trouglovi.begin(), trouglovi.end(), [](shared_ptr<Trougao> p1, shared_ptr<Trougao> p2) {
        return p1->DajObim() < p2->DajObim();
    })))->Ispisi();

    // Ispisujemo sve identicne parove trouglova.
    cout << endl;
    bool cond(true);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (DaLiSuIdenticni(*trouglovi[i], *trouglovi[j])) {
                if (cond) {
                    cout << "Parovi identicnih trouglova:" << endl;
                    cond = false;
                }
                trouglovi[i]->Ispisi();
                cout << " i ";
                trouglovi[j]->Ispisi();
                cout << endl;
            }
        }
    }
    if (cond)
        cout << "Nema identicnih trouglova!" << endl;

    // Ispisujemo sve podudarne parove trouglova.    
    cond =true;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (DaLiSuPodudarni(*trouglovi[i], *trouglovi[j])) {
                if (cond) {
                    cout << "Parovi podudarnih trouglova:" << endl;
                    cond = false;
                }
                trouglovi[i]->Ispisi();
                cout << " i ";
                trouglovi[j]->Ispisi();
                cout << endl;
            }
        }
    }
    if (cond)
        cout << "Nema podudarnih trouglova!" << endl;

    // Ispisujemo sve slicne parove trouglova.    
    cond =true;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (DaLiSuSlicni(*trouglovi[i], *trouglovi[j])) {
                if (cond) {
                    cout << "Parovi slicnih trouglova:" << endl;
                    cond = false;
                }
                trouglovi[i]->Ispisi();
                cout << " i ";
                trouglovi[j]->Ispisi();
                cout << endl;
            }
        }
    }
    if (cond)
        cout << "Nema slicnih trouglova!";

	return 0;
}