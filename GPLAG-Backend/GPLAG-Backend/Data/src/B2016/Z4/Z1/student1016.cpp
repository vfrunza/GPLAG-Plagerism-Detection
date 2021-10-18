/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;

class Trougao
{
    std::vector<Tacka> t;
    static int Test(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return t1.first*(t2.second-t3.second)- t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    };
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &tac);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Test(t1,t2,t3)<0) return -1;
        else if(Test(t1,t2,t3)>0) return 1;
        else return 0;
    };
    static bool TestirajJednakost (double x, double y) {
        return fabs(x-y)<0.00001;
    }
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
    void Rotiraj(const Tacka &tac, double ugao);
    void Skaliraj(const Tacka &tac, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(Orijentacija(t1, t2, t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    t.push_back(t1);
    t.push_back(t2);
    t.push_back(t3);
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(Orijentacija(t1, t2, t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    t.push_back(t1);
    t.push_back(t2);
    t.push_back(t3);
}
void Trougao::Postavi(int indeks, const Tacka &tac)
{
    if(indeks>3 or indeks<1) throw std::range_error ("Nekorektan indeks");
    t[indeks-1]=tac;
    if(Orijentacija(t[0], t[1], t[2])==0) throw std::domain_error ("Nekorektne pozicije tjemena");
}

Tacka Trougao::DajTjeme(int indeks) const
{
    if(indeks>3 or indeks<1) throw std::range_error ("Nekorektan indeks");
    return t[indeks-1];
};
double Trougao::DajStranicu(int indeks) const
{
    if(indeks>3 or indeks<1) throw std::range_error ("Nekorektan indeks");
    double sumax(0), sumay(0);
    for(int i=0; i<3; i++) {
        if(i==indeks-1) continue;
        if(TestirajJednakost(sumax,0)) sumax+=t[i].first;
        else sumax-=t[i].first;
        if(TestirajJednakost(sumay,0)) sumay+=t[i].second;
        else sumay-=t[i].second;
    }
    return sqrt(sumax*sumax+sumay*sumay);
};
double Trougao::DajUgao(int indeks) const
{
    if(indeks>3 or indeks<1) throw std::range_error ("Nekorektan indeks");
    double a[2], x;
    int br(0);
    for(int i=0; i<3; i++) {
        if(i==indeks-1) {
            x=this->DajStranicu(i+1);
            continue;
        }
        a[br]=this->DajStranicu(i+1);
        br++;
    }
    return acos((x*x-a[0]*a[0]-a[1]*a[1])/((-2)*a[0]*a[1]));
};
Tacka Trougao::DajCentar() const
{
    return std::make_pair((t[0].first+t[1].first+t[2].first)/3,(t[0].second+t[1].second+t[2].second)/3 );
};
double Trougao::DajObim() const
{
    return this->DajStranicu(1)+this->DajStranicu(2)+this->DajStranicu(3);
};
double Trougao::DajPovrsinu() const
{
    return std::abs(Test(t[0],t[1],t[2]))/2;
};
bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    if(Orijentacija(t[0],t[1],t[2])==-1) return false;
    return Orijentacija(t[0],t[1],t[2]);
};
bool Trougao::DaLiJeUnutra(const Tacka &tac) const
{
    return (Orijentacija(t[0], t[1], t[2]) and Orijentacija(t[0], t[1], tac) and Orijentacija(t[1], t[2], tac) and Orijentacija(t[2], t[0], tac));
};
void Trougao::Ispisi() const
{
    std::cout << "((" << t[0].first << "," << t[0].second << "),(" << t[1].first << "," << t[1].second << "),(" << t[2].first <<"," << t[2].second << "))";
}
void Trougao::Transliraj(double delta_x, double delta_y)
{
    for(int i=0; i<3; i++) {
        t[i].first+=delta_x;
        t[i].second+=delta_y;
    }
};
void Trougao::Centriraj(const Tacka &t)
{
    double delta_x(t.first-(this->DajCentar()).first), delta_y(t.second-(this->DajCentar()).second);
    Transliraj(delta_x, delta_y);
};
void Trougao::Rotiraj(const Tacka &tac, double ugao)
{
    for(int i=0; i<3; i++) {
        double x=tac.first+(t[i].first-tac.first)*cos(ugao)-(t[i].second-tac.second)*sin(ugao);
        t[i].second=tac.second+(t[i].first-tac.first)*sin(ugao)+(t[i].second-tac.second)*cos(ugao);
        t[i].first=x;
    }
};
void Trougao::Skaliraj(const Tacka &tac, double faktor)
{
    if(TestirajJednakost(faktor,0)) throw std::domain_error ("Nekorektan faktor skaliranja");
    for(int i=0; i<3; i++) {
        t[i].first=tac.first+faktor*(t[i].first-tac.first);
        t[i].second=tac.second+faktor*(t[i].second-tac.second);
    }
};
void Trougao::Rotiraj(double ugao)
{
    Tacka tac(this->DajCentar());
    for(int i=0; i<3; i++) {
        double x=tac.first+(t[i].first-tac.first)*cos(ugao)-(t[i].second-tac.second)*sin(ugao);
        t[i].second=tac.second+(t[i].first-tac.first)*sin(ugao)+(t[i].second-tac.second)*cos(ugao);
        t[i].first=x;
    }
};
void Trougao::Skaliraj(double faktor)
{
    Tacka tac(this->DajCentar());
    if(TestirajJednakost(faktor,0)) throw std::domain_error ("Nekorektan faktor skaliranja");
    for(int i=0; i<3; i++) {
        t[i].first=tac.first+faktor*(t[i].first-tac.first);
        t[i].second=tac.second+faktor*(t[i].second-tac.second);
    }
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    for(int i=0; i<3; i++) {
        int j;
        for(j=0; j<3; j++) {
            if(t1.DajTjeme(i+1)==t2.DajTjeme(j+1)) break;
        }
        if(j==3) return false;
    }
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    if(!(Trougao::TestirajJednakost(t1.DajObim(),t2.DajObim()) and Trougao::TestirajJednakost(t1.DajStranicu(1)*t1.DajStranicu(2)*t1.DajStranicu(3),t2.DajStranicu(1)*t2.DajStranicu(2)*t2.DajStranicu(3)))) return false;
    int i, j, k;
    for(i=0; i<3; i++) if(Trougao::TestirajJednakost(t2.DajUgao(i+1),t1.DajUgao(1))) break;
    for(j=0; j<3; j++) if(Trougao::TestirajJednakost(t2.DajUgao(j+1),t1.DajUgao(2)) and j!=i) break;
    for(k=0; k<3; k++) if(Trougao::TestirajJednakost(t2.DajUgao(k+1),t1.DajUgao(3)) and k!=i and k!=j) break;
    if(i>2 or j>2 or k>2) return false;
    if(Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))!=Trougao::Orijentacija(t2.DajTjeme(i+1), t2.DajTjeme(j+1), t2.DajTjeme(k+1))) return false;
    return true;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    int i, j, k;
    for(i=0; i<3; i++) if(Trougao::TestirajJednakost(t2.DajUgao(i+1),t1.DajUgao(1))) break;
    for(j=0; j<3; j++) if(Trougao::TestirajJednakost(t2.DajUgao(j+1),t1.DajUgao(2)) and j!=i) break;
    for(k=0; k<3; k++) if(Trougao::TestirajJednakost(t2.DajUgao(k+1),t1.DajUgao(3)) and k!=i and k!=j) break;
    if(i>2 or j>2 or k>2) return false;
    if(Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))!=Trougao::Orijentacija(t2.DajTjeme(i+1), t2.DajTjeme(j+1), t2.DajTjeme(k+1))) return false;
    return true;
}



using std::cout ;
using std::cin;

int main ()
{
    cout << "Koliko zelite kreirati trouglova: ";
    int n;
    cin >> n;
    std::vector<std::shared_ptr<Trougao>> v;
    for(int i=0; i<n; i++) {
        cout << "Unesite podatke za "<< i+1<< ". trougao (x1 y1 x2 y2 x3 y3): ";
        double a, b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >>f;
        try {
            v.push_back(std::make_shared<Trougao>(Trougao(std::make_pair(a,b), std::make_pair(c,d), std::make_pair(e,f))));
        } catch(std::domain_error izuz) {
            std::cout << izuz.what() <<", ponovite unos!"<< std::endl;
            i--;
        }
    }
    double dx, dy;
    cout << "Unesite vektor translacije (dx dy): ";
    cin >> dx >> dy;
    cout << "Unesite ugao rotacije: ";
    double alfa, fak;
    cin >> alfa;
    cout << "Unesite faktor skaliranja: ";
    cin >> fak;
    cout << "Trouglovi nakon obavljenih transformacija: \n";
    std::transform(v.begin(), v.end(), v.begin(), [dx,dy](std::shared_ptr<Trougao> x) {
        (*x.get()).Transliraj(dx,dy);
        return x;
    });
    std::transform(v.begin(), v.end(), v.begin(), [alfa](std::shared_ptr<Trougao> x) {
        (*x.get()).Rotiraj(alfa);
        return x;
    });
    std::transform(v.begin(), v.end(), v.begin(), [fak] (std::shared_ptr<Trougao> x) {
        (*x.get()).Skaliraj((*x.get()).DajTjeme(1), fak);
        return x;
    });
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y) {
        if((*x.get()).DajPovrsinu()<(*y.get()).DajPovrsinu()) return true;
        else return false;
    });
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> x) {
        (*x).Ispisi();
        std::cout<<std::endl;
    });
    cout << "Trougao sa najmanjim obimom: ";
    auto it=min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
        return t1->DajObim()<t2->DajObim();
    });
    (*it)->Ispisi();
    cout << std::endl;
    bool ima_pod(false), ima_ide(false), ima_sl(false);
    for(int i=0; i<n ; i++) {
        for(int j=i+1; j<n; j++) {
            if(DaLiSuIdenticni(*v[i],*v[j])) ima_ide=true;
            if(DaLiSuPodudarni(*v[i],*v[j])) ima_pod=true;
            if(DaLiSuSlicni(*v[i],*v[j])) ima_sl=true;
        }
    }
    if(ima_ide) {
        cout << "Parovi identicnih trouglova: \n";
        for(int i=0; i<n ; i++) {
            for(int j=i+1; j<n; j++) {
                if(DaLiSuIdenticni(*v[i],*v[j])) {
                    v[i]->Ispisi();
                    cout << " i ";
                    v[j]->Ispisi();
                    cout << std::endl;
                }
            }
        }
    } else std::cout << "Nema identicnih trouglova!\n";
    if(ima_pod) {
        cout <<  "Parovi podudarnih trouglova: \n";
        for(int i=0; i<n ; i++) {
            for(int j=i+1; j<n; j++) {
                if(DaLiSuPodudarni(*v[i],*v[j])) {
                    v[i]->Ispisi();
                    cout << " i ";
                    v[j]->Ispisi();
                    cout << std::endl;
                }
            }
        }
    } else std::cout << "Nema podudarnih trouglova!\n";
    if(ima_sl) {
        cout<< "Parovi slicnih trouglova: \n";
        for(int i=0; i<n ; i++) {
            for(int j=i+1; j<n; j++) {
                if(DaLiSuSlicni(*v[i],*v[j])) {
                    v[i]->Ispisi();
                    cout << " i ";
                    v[j]->Ispisi();
                    cout << std::endl;
                }
            }
        }
    } else std::cout << "Nema slicnih trouglova!\n";
    return 0;
}