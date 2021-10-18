/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <memory>
#include <utility>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const double eps = 1e-10;
typedef pair<double, double> Tacka;

class Trougao {
    Tacka t1, t2, t3;
    //pomocne funkcije
    void TestIndeksa(int indeks) const {
        if(indeks != 1 && indeks != 2 && indeks != 3) throw range_error("Nekorektan indeks");
    }
    double DaLiSuKolinearne(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return ((t1.first)*(t2.second - t3.second) - (t2.first)*(t1.second - t3.second) + t3.first*(t1.second - t2.second));
         //   throw domain_error("Nekorektne pozicije tjemena");
    }
    double DuzinaStranice(const Tacka &t1, const Tacka &t2) const {
        return sqrt(((t1.first - t2.first)*(t1.first - t2.first)) + (t1.second - t2.second)*(t1.second - t2.second));
    }
    static int za_orijentaciju(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return ((t1.first)*(t2.second - t3.second) - (t2.first)*(t1.second - t3.second) + (t3.first)*(t1.second - t2.second));
    }
    static bool DaLiSuJednaki(const double &x, const double &y) {
        return abs(x - y) <= eps*(abs(x) + abs(y));
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (DaLiSuKolinearne(t1, t2, t3) == 0.0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::t1 = t1;
        Trougao::t2 = t2;
        Trougao::t3 = t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(DaLiSuKolinearne(t1,t2,t3) == 0.0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::t1 = t1;
        Trougao::t2 = t2;
        Trougao::t3 = t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        TestIndeksa(indeks);
        if (DaLiSuKolinearne(t1, t2, t3) == 0.0) throw std::domain_error ("Nekorektne pozicije tjemena");
        if(indeks == 1) {
            Trougao::t1 = t;
        }
        else if(indeks == 2) {
           
            Trougao::t2 = t;
        }
        else if(indeks == 3) {
            
            Trougao::t3 = t; 
        }
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(za_orijentaciju(t1, t2, t3) > 0) return 1;
        else if(za_orijentaciju(t1, t2, t3) < 0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const {
        TestIndeksa(indeks);
        if(indeks == 1) return t1;
        else if(indeks == 2) return t2;
        else return t3;
    }
    double DajStranicu(int indeks) const {
        TestIndeksa(indeks);
        if(indeks == 1) { 
            return DuzinaStranice(t2, t3);
        }
        else if(indeks == 2) {
            return DuzinaStranice(t1, t3);
        }
        else return DuzinaStranice(t1, t2);
    }
    double DajUgao(int indeks) const {
        TestIndeksa(indeks);
        double a = DuzinaStranice(t2, t3);
        double b = DuzinaStranice(t1, t3);
        double c = DuzinaStranice(t1, t2);
        if(indeks == 1) {
            return acos((b*b + c*c - a*a)/(2*b*c));
        }
        else if(indeks == 2) {
            return acos((a*a + c*c - b*b)/(2*a*c));
        }
        else return acos((a*a + b*b - c*c)/(2*a*b));
    }
    Tacka DajCentar() const {
        Tacka centar;
        centar.first = (t1.first + t2.first + t3.first)/3;
        centar.second = (t1.second + t2.second + t3.second)/3;
        return centar;
    }
    double DajObim() const {
        double a = DuzinaStranice(t2, t3);
        double b = DuzinaStranice(t1, t3);
        double c = DuzinaStranice(t1, t2);
        return a + b + c;
    }
    double DajPovrsinu() const {
        return (abs(za_orijentaciju(t1, t2, t3)))/2;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(za_orijentaciju(t1, t2, t3) > 0) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        int q=Orijentacija(t1,t2,t3);
        if((Orijentacija(t1, t2, t)==q || Orijentacija(t1,t2,t)==0) && (Orijentacija(t2, t3, t)==q || Orijentacija(t2,t3,t)==0) && (Orijentacija(t3, t1, t)==q || Orijentacija(t3,t1,t)==0)) return true;
    return false;
    }
    
    void Ispisi() const {
        cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";
    }
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
//////////////////////////////////////////////////////IMPLEMENTACIJE///////////////////////////////////////////////////////
void Trougao::Transliraj(double delta_x, double delta_y) {
    Tacka a1 = t1; Tacka a2 = t2; Tacka a3 = t3;
    t1.first = a1.first + delta_x;
    t1.second = a1.second + delta_y;
    t2.first = a2.first + delta_x;
    t2.second = a2.second + delta_y;
    t3.first = a3.first + delta_x;
    t3.second = a3.second + delta_y;
}
void Trougao::Centriraj(const Tacka &t) {
    auto centar = DajCentar();
    double delta_x = t.first - centar.first;
    double delta_y = t.second - centar.second;
    Transliraj(delta_x, delta_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    Tacka r1 = t1; Tacka r2 = t2; Tacka r3 = t3;
    t1.first = t.first + (r1.first - t.first)*cos(ugao) - (r1.second - t.second)*sin(ugao);
    t1.second = t.second + (r1.first - t.first)*sin(ugao) + (r1.second - t.second)*cos(ugao);
    t2.first = t.first + (r2.first - t.first)*cos(ugao) - (r2.second - t.second)*sin(ugao);
    t2.second = t.second + (r2.first - t.first)*sin(ugao) + (r2.second - t.second)*cos(ugao);
    t3.first = t.first + (r3.first - t.first)*cos(ugao) - (r3.second - t.second)*sin(ugao);
    t3.second = t.second + (r3.first - t.first)*sin(ugao) + (r3.second - t.second)*cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(faktor == 0.0) throw domain_error("Nekorektan faktor skaliranja");
    Tacka s1 = t1; Tacka s2 = t2; Tacka s3 = t3;
    t1.first = t.first + faktor*(s1.first - t.first);
    t1.second = t.second + faktor*(s1.second - t.second);
    t2.first = t.first + faktor*(s2.first - t.first);
    t2.second = t.second + faktor*(s2.second - t.second);
    t3.first = t.first + faktor*(s3.first - t.first);
    t3.second = t.second + faktor*(s3.second - t.second);
}
void Trougao::Rotiraj(double ugao) {
    Tacka r1 = t1; Tacka r2 = t2; Tacka r3 = t3;
    t1.first = r1.first*cos(ugao) - r1.second*sin(ugao);
    t1.second =r1.first*sin(ugao) - r1.second*cos(ugao);
    t2.first = r2.first*cos(ugao) - r2.second*sin(ugao);
    t2.second =r2.first*sin(ugao) - r2.second*cos(ugao);
    t3.first = r3.first*cos(ugao) - r3.second*sin(ugao);
    t3.second = r3.first*sin(ugao) - r3.second*cos(ugao);
}
void Trougao::Skaliraj(double faktor) {
    if(faktor == 0.0) throw domain_error("Nekorektan faktor skaliranja");
    Tacka s1 = t1; Tacka s2 = t2; Tacka s3 = t3;
    t1.first = faktor*s1.first;
    t1.second = faktor*s1.second;
    t2.first = faktor*s2.first;
    t2.second = faktor*s2.second;
    t3.first = faktor*s3.first;
    t3.second = faktor*s3.second;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    vector<Tacka> prvi, drugi;
    prvi.push_back(t1.t1);
    prvi.push_back(t1.t2);
    prvi.push_back(t1.t3);
    drugi.push_back(t2.t1);
    drugi.push_back(t2.t2);
    drugi.push_back(t2.t3);
    sort(prvi.begin(), prvi.end(), [](Tacka x, Tacka y) {
        return x.second > y.second;
    });
    sort(drugi.begin(), drugi.end(), [](Tacka x, Tacka y) {
        return x.second > y.second;
    }); 
    if(prvi == drugi) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    vector<pair<Tacka, double>> prvi, drugi;
    auto a1 = t1.DajStranicu(1);
    auto b1 = t1.DajStranicu(2);
    auto c1 = t1.DajStranicu(3);
    auto a2 = t2.DajStranicu(1);
    auto b2 = t2.DajStranicu(2);
    auto c2 = t2.DajStranicu(3);
    prvi.push_back(make_pair(t1.t1, a1));
    prvi.push_back(make_pair(t1.t2, b1));
    prvi.push_back(make_pair(t1.t3, c1));
    drugi.push_back(make_pair(t2.t1, a2));
    drugi.push_back(make_pair(t2.t2, b2));
    drugi.push_back(make_pair(t2.t3, c2));
    
    sort(prvi.begin(), prvi.end(), [](pair<Tacka, double> x, pair<Tacka, double> y) {
       return x.second < y.second; 
    });
    sort(drugi.begin(), drugi.end(), [](pair<Tacka, double> x, pair<Tacka, double> y) {
        return  x.second < y.second;
    });
    
    if(Trougao::Orijentacija(prvi[0].first, prvi[1].first, prvi[2].first) != Trougao::Orijentacija(drugi[0].first, drugi[1].first, drugi[2].first)) 
        return false;
    else {
        for(int i = 0; i <= 2; i++) {
            if(!Trougao::DaLiSuJednaki(prvi[i].second, drugi[i].second))
                return false;
        }
    }
    return true;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    vector<pair<Tacka, double>> prvi, drugi;
    double alfa1 = t1.DajUgao(1);
    double beta1 = t1.DajUgao(2);
    double gama1 = t1.DajUgao(3);
    double alfa2 = t2.DajUgao(1);
    double beta2 = t2.DajUgao(2);
    double gama2 = t2.DajUgao(3);
    prvi.push_back(make_pair(t1.t1, alfa1));
    prvi.push_back(make_pair(t1.t2, beta1));
    prvi.push_back(make_pair(t1.t3, gama1));
    drugi.push_back(make_pair(t2.t1, alfa2));
    drugi.push_back(make_pair(t2.t2, beta2));
    drugi.push_back(make_pair(t2.t3, gama2));
    
    sort(prvi.begin(), prvi.end(), [](pair<Tacka, double> x, pair<Tacka, double> y) {
       return x.second < y.second; 
    });
    
    sort(drugi.begin(), drugi.end(), [](pair<Tacka, double> x, pair<Tacka, double> y) {
       return x.second < y.second;
    });
    if(Trougao::Orijentacija(prvi[0].first, prvi[1].first, prvi[2].first) != Trougao::Orijentacija(drugi[0].first, drugi[1].first, drugi[2].first))
        return false;
    else {
        for(int i = 0; i <= 2; i++) {
            if(!Trougao::DaLiSuJednaki(prvi[i].second, drugi[i].second))
                return false;
        }
    }
    return true;
}
int main() {
    int n;
    cout << "Koliko zelite kreirati trouglova: ";
    cin >> n;
    vector<shared_ptr<Trougao>> trouglovi;
    double x1, y1, x2, y2, x3, y3;
    for(int i{0}; i < n; i++) {
        cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        try {
            trouglovi.push_back(make_shared<Trougao>(Trougao(Tacka(x1, y1), Tacka(x2, y2), Tacka(x3, y3))));
            }
        catch(domain_error poruka) {
            cout << poruka.what();
            cout << ", ponovite unos!" << endl;
            i--;
        }
        
    }
    double delta_x, delta_y;
    cout << "Unesite vektor translacije (dx dy): ";
    cin >> delta_x >> delta_y;
    double ugao_rotacije;
    cout << "Unesite ugao rotacije: ";
    cin >> ugao_rotacije;
    double faktor_skaliranja;
    cout << "Unesite faktor skaliranja: ";
    cin >> faktor_skaliranja;
    cout << "Trouglovi nakon obavljenih transformacija:" << endl;
    transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [=](shared_ptr<Trougao> original) {
        original->Transliraj(delta_x, delta_y);
        original->Rotiraj(original->DajCentar(), ugao_rotacije);
        original->Skaliraj(original->DajTjeme(1), faktor_skaliranja);
        return original;
    });
    sort(trouglovi.begin(), trouglovi.end(), [](shared_ptr<Trougao> t1, shared_ptr<Trougao> t2) {
        return t1->DajPovrsinu() < t2->DajPovrsinu();
    });
    for_each(trouglovi.begin(), trouglovi.end(), [](shared_ptr<Trougao> t) {
        t->Ispisi(); 
        cout << endl; 
    });
    cout << "Trougao sa najmanjim obimom: ";
    auto p = min_element(trouglovi.begin(), trouglovi.end(), [](shared_ptr<Trougao> t1, shared_ptr<Trougao> t2) {
        return t1->DajObim() < t2->DajObim();
    });
    shared_ptr<Trougao> najmanji;
    najmanji = *p;
    najmanji->Ispisi();
    cout << endl;
    
    int ima_li_identicnih = 0;
    for(int i{0}; i < n; i++) {
        for(int j{i+1}; j < n; j++) {
            if(DaLiSuIdenticni(*trouglovi[i], *trouglovi[j])) {
                if(ima_li_identicnih == 0) cout << "Parovi identicnih trouglova: " << endl;
                ima_li_identicnih++;
                trouglovi[i]->Ispisi();
                cout << " i ";
                trouglovi[j]->Ispisi();
                cout << endl;
            }
        }
    }
    if(ima_li_identicnih == 0) cout << "Nema identicnih trouglova!" << endl;
    
    int ima_li_podudarnih = 0;
    for(int i{0}; i < n; i++) {
        for(int j{i+1}; j < n; j++) {
            if(DaLiSuPodudarni(*trouglovi[i], *trouglovi[j])) {
                if (ima_li_podudarnih == 0) cout << "Parovi podudarnih trouglova: " << endl;
                ima_li_podudarnih++;
                trouglovi[i]->Ispisi();
                cout << " i ";
                trouglovi[j]->Ispisi();
                cout << endl;
            }
        }
    }
    if(ima_li_podudarnih == 0) cout << "Nema podudarnih trouglova!" << endl;
    
   
    int ima_li_slicnih = 0;
    for(int i{0}; i < n; i++) {
        for(int j{i+1}; j < n; j++) {
            if(DaLiSuSlicni(*trouglovi[i], *trouglovi[j])) {
                if(ima_li_slicnih == 0) cout << "Parovi slicnih trouglova: " << endl;
                ima_li_slicnih++;
                trouglovi[i]->Ispisi();
                cout << " i ";
                trouglovi[j]->Ispisi();
                cout << endl;
            }
        }
    }
    if(ima_li_slicnih == 0) cout << "Nema slicnih trouglova!";
    return 0;
}










