/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <memory>

typedef std::pair<double, double> Tacka;
const double eps (10e-10);

class Trougao 
{
    std::vector<Tacka> tacka;
    
    static double Izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3) { return t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second); }
    static void ProvjeriIndex(int i) { if(i <0 || i>3) throw std::range_error("Nekorektan indeks"); }
    static void OdrediOstaleIndexe(int indeks, int &a, int &b) 
    { 
        if(indeks == 1) { a = 2; b = 3; }
        if(indeks == 2) { a = 1; b = 3; }
        if(indeks == 3) { a = 1; b = 2; }
    }
    static bool PD(double d1, double d2) { return fabs(d1-d2) < eps; }
    static double Modul(const Tacka &t) { return sqrt(t.first*t.first + t.second*t.second); }
    static double Produkt(const Tacka &t1, const Tacka &t2) { return t1.first * t2.first + t1.second * t2.second; }
    static bool ProvjeriTrougao(const Trougao &t1, const Trougao &t2)
    { if( PD(t1.DajUgao(1),t2.DajUgao(1)) && PD(t1.DajUgao(2),t2.DajUgao(2)) && PD(t1.DajUgao(3),t2.DajUgao(3))) return true; return false; }
    static void NasteliTrougao(const Trougao &t1,const Trougao &t2, Trougao &T)
    {
        for(int i=0;i<6;i++)
        {
            if(Trougao::ProvjeriTrougao(t1, T)) break;
            if(i==0) T.Postavi(t2.tacka[0], t2.tacka[1], t2.tacka[2]);
            if(i==1) T.Postavi(t2.tacka[0], t2.tacka[2], t2.tacka[1]);
            if(i==2) T.Postavi(t2.tacka[2], t2.tacka[1], t2.tacka[0]);
            if(i==3) T.Postavi(t2.tacka[1], t2.tacka[0], t2.tacka[2]);
            if(i==4) T.Postavi(t2.tacka[1], t2.tacka[2], t2.tacka[0]);
            if(i==5) T.Postavi(t2.tacka[2], t2.tacka[0], t2.tacka[1]);
        }
    }
    static bool ProvjeriTrougao(std::vector<double> &tr1, std::vector<double> &tr2)
    { 
        std::sort(tr1.begin(), tr1.end()); std::sort(tr2.begin(), tr2.end());
        for(int i=0,j=0; i<3; i++, j++) if(!Trougao::PD(tr1[i], tr2[j])) return false;
        return true;
    }
    
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

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    tacka.resize(3);
    Postavi(t1,t2,t3);
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(!Orijentacija(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
    tacka[0] = t1; tacka[1] = t2; tacka[2] = t3;
}

void Trougao::Postavi(int indeks, const Tacka &t)
{
    ProvjeriIndex(indeks);
    if(indeks==1) Postavi(t,tacka[1],tacka[2]);
    else if(indeks==2) Postavi(tacka[0],t,tacka[2]);
    else if(indeks==3) Postavi(tacka[0],tacka[1],t);
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double x(Izraz(t1,t2,t3));
    if(PD(x, 0)) return 0; else if(x<0) return -1; else return 1;
}

Tacka Trougao::DajTjeme(int indeks) const
{
    ProvjeriIndex(indeks);
    return tacka[indeks-1];
}

double Trougao::DajStranicu(int indeks) const
{
    ProvjeriIndex(indeks);
    int a,b;
    OdrediOstaleIndexe(indeks, a, b);
    return sqrt( ((tacka[a-1].first - tacka[b-1].first) * (tacka[a-1].first - tacka[b-1].first)) + ((tacka[a-1].second - tacka[b-1].second) * (tacka[a-1].second - tacka[b-1].second)) );
}

double Trougao::DajUgao(int indeks) const
{
    ProvjeriIndex(indeks);
    int A,B;
    OdrediOstaleIndexe(indeks, A, B);
    double a(DajStranicu(A)), b(DajStranicu(B)), c(DajStranicu(indeks));
    return acos( (a*a + b*b -c*c) / (2*a*b) );
}

Tacka Trougao::DajCentar() const
{
    double x(0),y(0);
    for(int i=0; i<tacka.size(); i++) { x += tacka[i].first; y += tacka[i].second; }
    x/=3; y/=3;
    return Tacka(x,y);
}

double Trougao::DajObim() const
{
    double obim(0);
    for(int i=1; i<=tacka.size(); i++) obim += DajStranicu(i);
    return obim;
}

double Trougao::DajPovrsinu() const
{
    return fabs(Izraz(tacka[0],tacka[1],tacka[2])/2);
}

bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    return Orijentacija(tacka[0], tacka[1], tacka[2]) == 1;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    bool smjer(DaLiJePozitivnoOrijentiran());
    for(int i=3; i!= 0; i--) 
    {
        int a,b;
        OdrediOstaleIndexe(i, a, b);
        if(Orijentacija(tacka[a-1], tacka[b-1], t) != smjer) return false;
    }
    return true;
}

void Trougao::Ispisi() const
{
    std::cout << "((" << tacka[0].first << "," << tacka[0].second << "),(" << tacka[1].first << "," << tacka[1].second << "),(" << tacka[2].first << "," << tacka[2].second << "))";
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    tacka[0].first += delta_x; tacka[0].second += delta_y;
    tacka[1].first += delta_x; tacka[1].second += delta_y;
    tacka[2].first += delta_x; tacka[2].second += delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{
    Tacka ts (DajCentar());
    double dx(t.first - ts.first), dy(t.second - ts.second);
    Transliraj(dx,dy);
}

void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    std::vector<Tacka> a{ DajTjeme(1), DajTjeme(2), DajTjeme(3) };
    std::vector<Tacka> n(3);
    for(int i=0; i<3; i++)
    {
        n[i].first = t.first + (a[i].first-t.first)*cos(ugao)-(a[i].second-t.second)*sin(ugao);
        n[i].second = t.second + (a[i].first-t.first)*sin(ugao)+(a[i].second-t.second)*cos(ugao);
    }
    Postavi(n[0], n[1], n[2]);
}

void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(PD(faktor, 0.)) throw std::domain_error("Nekorektan faktor skaliranja");
    std::vector<Tacka> a{ DajTjeme(1), DajTjeme(2), DajTjeme(3) };
    std::vector<Tacka> n(3);
    for(int i=0; i<3; i++)
    {
        n[i].first = t.first + (a[i].first-t.first)*faktor;
        n[i].second = t.second + (a[i].second-t.second)*faktor;
    }
    Postavi(n[0], n[1], n[2]);
}

void Trougao::Rotiraj(double ugao)
{
    Rotiraj(DajCentar(), ugao);
}

void Trougao::Skaliraj(double faktor)
{
    Skaliraj(DajCentar(), faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if(Trougao::PD(t1.tacka[0].first, t2.tacka[0].first) && Trougao::PD(t1.tacka[1].first, t2.tacka[1].first) && Trougao::PD(t1.tacka[2].first, t2.tacka[2].first) && Trougao::PD(t1.tacka[0].second, t2.tacka[0].second) && Trougao::PD(t1.tacka[1].second, t2.tacka[1].second) && Trougao::PD(t1.tacka[2].second, t2.tacka[2].second)) return true;
    if(Trougao::PD(t1.tacka[0].first, t2.tacka[0].first) && Trougao::PD(t1.tacka[1].first, t2.tacka[2].first) && Trougao::PD(t1.tacka[2].first, t2.tacka[1].first) && Trougao::PD(t1.tacka[0].second, t2.tacka[0].second) && Trougao::PD(t1.tacka[1].second, t2.tacka[2].second) && Trougao::PD(t1.tacka[2].second, t2.tacka[1].second)) return true;
    if(Trougao::PD(t1.tacka[1].first, t2.tacka[1].first) && Trougao::PD(t1.tacka[0].first, t2.tacka[2].first) && Trougao::PD(t1.tacka[2].first, t2.tacka[0].first) && Trougao::PD(t1.tacka[1].second, t2.tacka[1].second) && Trougao::PD(t1.tacka[0].second, t2.tacka[2].second) && Trougao::PD(t1.tacka[2].second, t2.tacka[0].second)) return true;
    if(Trougao::PD(t1.tacka[2].first, t2.tacka[2].first) && Trougao::PD(t1.tacka[0].first, t2.tacka[1].first) && Trougao::PD(t1.tacka[1].first, t2.tacka[0].first) && Trougao::PD(t1.tacka[2].second, t2.tacka[2].second) && Trougao::PD(t1.tacka[0].second, t2.tacka[1].second) && Trougao::PD(t1.tacka[1].second, t2.tacka[0].second)) return true;
    
    for(int i=1; i<=3; i++)
    {
        int a,b;
        Trougao::OdrediOstaleIndexe(i, a, b);
        if(Trougao::PD(t1.tacka[0].first, t2.tacka[i-1].first) && Trougao::PD(t1.tacka[1].first, t2.tacka[a-1].first) && Trougao::PD(t1.tacka[2].first, t2.tacka[b-1].first)       &&        Trougao::PD(t1.tacka[0].second, t2.tacka[i-1].second) && Trougao::PD(t1.tacka[1].second, t2.tacka[a-1].second) && Trougao::PD(t1.tacka[2].second, t2.tacka[b-1].second) ) return true;
    }
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    if(DaLiSuIdenticni(t1,t2)) return true;
    std::vector<double> tr1{t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)};
    std::vector<double> tr2{t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
    if(!Trougao::ProvjeriTrougao(tr1, tr2)) return false;
    if(Trougao::PD(tr1[0], tr1[1]) || Trougao::PD(tr1[0], tr1[2]) || Trougao::PD(tr1[1], tr1[2])) return true;
    Trougao T(t2); Trougao::NasteliTrougao(t1, t2, T);
    return (Trougao::Orijentacija(t1.tacka[0], t1.tacka[1], t1.tacka[2]) == Trougao::Orijentacija(T.tacka[0], T.tacka[1], T.tacka[2]));
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    if(DaLiSuIdenticni(t1,t2)) return true;
    std::vector<double> tr1{t1.DajUgao(1),t1.DajUgao(2),t1.DajUgao(3)};
    std::vector<double> tr2{t2.DajUgao(1),t2.DajUgao(2),t2.DajUgao(3)};
    if(!Trougao::ProvjeriTrougao(tr1, tr2)) return false;
    if(Trougao::PD(tr1[0], tr1[1]) || Trougao::PD(tr1[0], tr1[2]) || Trougao::PD(tr1[1], tr1[2])) return true;
    Trougao T(t2); Trougao::NasteliTrougao(t1, t2, T);
    return (Trougao::Orijentacija(t1.tacka[0], t1.tacka[1],t1.tacka[2]) == Trougao::Orijentacija(T.tacka[0], T.tacka[1],T.tacka[2]));
}

int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> pok_v(n);
    std::vector<std::pair<double, double>> tjemena(3);
    for(int i=0; i<n; i++)
    {
        std::cout << "Unesite podatke za "<< i+1 << ". trougao (x1 y1 x2 y2 x3 y3): "; 
        for(int j=0; j<3; j++)
        {
            std::cin >> tjemena[j].first >>  tjemena[j].second; 
        }
        try { pok_v[i] = std::make_shared<Trougao>(tjemena[0], tjemena[1], tjemena[2]); }
        catch (std::bad_alloc) {std::cout << "Problemi sa memorijom."; return 0; }
        catch (std::domain_error a) {std::cout << a.what() << ", ponovite unos!" << std::endl; i--; }
    }
    
    double dx(0), dy(0);
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> dx >> dy;
    std::transform(pok_v.begin(), pok_v.end(), pok_v.begin(), [dx,dy] (std::shared_ptr<Trougao> &p_t) { p_t->Transliraj(dx,dy); return p_t;});
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> dx;
    std::transform(pok_v.begin(), pok_v.end(), pok_v.begin(), [dx] (std::shared_ptr<Trougao> &p_t) { p_t->Rotiraj(dx); return p_t;});
    
    double faktor(0);
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor;
    std::transform(pok_v.begin(), pok_v.end(), pok_v.begin(), [faktor] (std::shared_ptr<Trougao> &p_t) { p_t->Skaliraj(p_t->DajTjeme(1), faktor); return p_t;});
    
    std::cout << "Trouglovi nakon obavljenih transformacija: \n";
    std::sort(pok_v.begin(), pok_v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
    return t1->DajPovrsinu() < t2->DajPovrsinu(); });
   
    std::for_each(pok_v.begin(), pok_v.end(), [](std::shared_ptr<Trougao> t) { t->Ispisi(); std::cout << std::endl; });
    std::cout << "Trougao sa najmanjim obimom: ";
    auto a (*std::min_element(pok_v.begin(), pok_v.end(), [] (std::shared_ptr<Trougao> t1 , std::shared_ptr<Trougao> t2) { return t1->DajObim() < t2->DajObim() ;}));
    a->Ispisi(); std::cout << std::endl;
    {
    std::vector<bool> bul(pok_v.size(), false);
    bool poruka(false);
    for(int i=0; i<pok_v.size(); i++)
    for(int j=0; j<pok_v.size(); j++)
    {
        bool ima(false); 
        if(bul[j] != true && i!=j && DaLiSuIdenticni(*pok_v[i], *pok_v[j]))
        {
            if(poruka == false) { std::cout << "Parovi identicnih trouglova: \n"; poruka = true; } 
            pok_v[i]->Ispisi(); std::cout << " i "; pok_v[j]->Ispisi(); std::cout << std::endl;
            ima = true;
        }
        if(ima) bul[i] = true;
    }
    if(!poruka) std::cout << "Nema identicnih trouglova!" << std::endl;
    }
    
    {
    bool poruka(false);
    std::vector<bool> bul(pok_v.size(), false);
    for(int i=0; i<pok_v.size(); i++)
    for(int j=0; j<pok_v.size(); j++)
    {
        bool ima(false);
        if(bul[j] != true && i!=j && DaLiSuPodudarni(*pok_v[i], *pok_v[j]))
        {
            if(poruka == false) { std::cout << "Parovi podudarnih trouglova: \n"; poruka = true; } 
            pok_v[i]->Ispisi(); std::cout << " i "; pok_v[j]->Ispisi(); std::cout << std::endl;
            ima = true;
        }
        if(ima) bul[i] = true;
    }
    if(!poruka) std::cout << "Nema podudarnih trouglova!" << std::endl;
    }
    
    {
    bool poruka(false);
    std::vector<bool> bul(pok_v.size(), false);
    for(int i=0; i<pok_v.size(); i++)
    for(int j=0; j<pok_v.size(); j++)
    {
        bool ima(false);
        if(bul[j] != true && i!=j && DaLiSuSlicni(*pok_v[i], *pok_v[j]))
        {
            if(poruka == false) { std::cout << "Parovi slicnih trouglova: \n"; poruka = true; } 
            pok_v[i]->Ispisi(); std::cout << " i "; pok_v[j]->Ispisi(); std::cout << std::endl;
            ima = true;
        }
        if(ima) bul[i] = true;
    }
    if(!poruka) std::cout << "Nema slicnih trouglova!" << std::endl;
    }
	return 0;
}