/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <set>
#include <algorithm>
#include <vector>
#include <memory>
typedef std::pair<double, double> Tacka;

class Trougao {
    
    private:
    Tacka T[3];
    static bool equals(double x, double y);
    static double udaljenost(const Tacka& t1, const Tacka& t2);
    static Tacka rotirana(Tacka x, Tacka c, double ugao);
    
    public:
    Trougao(const Tacka& t1, const Tacka& t2, const Tacka& t3);
    void Postavi(const Tacka& t1, const Tacka& t2, const Tacka& t3);
    void Postavi(int indeks, const Tacka& t);
    static int Orijentacija(const Tacka& t1, const Tacka& t2, const Tacka& t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka& t) const;
    void Ispisi() const;
    void Transliraj(double dx, double dy);
    void Centriraj(const Tacka& t);
    void Rotiraj(const Tacka& t, double ugao);
    void Skaliraj(const Tacka& t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao& t1, const Trougao& t2);
    friend bool DaLiSuPodudarni(const Trougao& t1, const Trougao& t2);
    friend bool DaLiSuSlicni(const Trougao& t1, const Trougao& t2);
};

bool Trougao::equals(double x, double y) {
    return std::fabs(x-y) < 1e-10;
}
double Trougao::udaljenost(const Tacka& t1, const Tacka& t2)
{
    return std::sqrt((t1.first-t2.first) * (t1.first-t2.first) + (t1.second-t2.second) * (t1.second-t2.second));
}
Tacka Trougao::rotirana(Tacka x, Tacka c, double ugao)
{
    return {c.first + (x.first - c.first)*std::cos(ugao) - (x.second-c.second)*std::sin(ugao), 
    c.second + (x.first - c.first) * std::sin(ugao) + (x.second-c.second)*std::cos(ugao)};
}
Trougao::Trougao(const Tacka& t1, const Tacka& t2, const Tacka& t3)
{
    if(Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    T[0] = t1; T[1] = t2; T[2] = t3;
}
void Trougao::Postavi(const Tacka& t1, const Tacka& t2, const Tacka& t3)
{
    if(Orijentacija(t1, t2, t3) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
    T[0] = t1; T[1] = t2; T[2] = t3;
}
void Trougao::Postavi(int indeks, const Tacka& t)
{
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    auto aux = T[indeks - 1];
    T[indeks - 1] = t;
    if(Orijentacija(T[0], T[1], T[2]) == 0) 
    {
        T[indeks - 1] = aux;
        throw std::domain_error("Nekorektne pozicije tjemena");
    }
}
int Trougao::Orijentacija(const Tacka& t1, const Tacka& t2, const Tacka& t3)
{
    double rey = t1.first*(t2.second - t3.second) + t2.first * (t3.second - t1.second) + t3.first * (t1.second - t2.second);
    if(Trougao::equals(rey, 0)) return 0;
    if(rey < 0) return -1;
    return 1;
}
Tacka Trougao::DajTjeme(int indeks) const
{
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    return T[indeks - 1];
}
double Trougao::DajStranicu(int indeks) const
{
    if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
    std::set<int> s = {1,2,3};
    s.erase(indeks);
    return udaljenost(T[*s.begin() - 1], T[*s.rbegin() - 1]);
}
double Trougao::DajUgao(int indeks) const
{
     if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
     std::set<int> s = {1,2,3};
     s.erase(indeks);
     double a = DajStranicu(indeks), b = DajStranicu(*s.rbegin()), c = DajStranicu(*s.begin());
     return std::acos( (b*b + c*c - a*a) / (2*a*b));
}
Tacka Trougao::DajCentar() const
{
    return {(T[0].first + T[1].first + T[2].first)/3, (T[0].second + T[1].second + T[2].second)/3};
}
double Trougao::DajObim() const
{
    return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
}
double Trougao::DajPovrsinu() const
{
    return std::fabs(T[0].first*(T[1].second - T[2].second) + T[1].first * (T[2].second - T[0].second) + T[2].first * (T[0].second - T[1].second))/2;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    return Orijentacija(T[0], T[1], T[2]) == 1;
}
bool Trougao::DaLiJeUnutra(const Tacka& t) const
{
    int o1 = Orijentacija(T[0], T[1], T[2]);
    return (Orijentacija(T[0], T[1], t) == o1 && Orijentacija(T[1], T[2], t) == o1 && Orijentacija(T[2], T[0], t) == o1 );
}
void Trougao::Ispisi() const
{
    std::cout<< "(("<<T[0].first<<","<<T[0].second<<"),("<<T[1].first<<","<<T[1].second<<"),("<<T[2].first<<","<<T[2].second<<"))";
}
void Trougao::Transliraj(double dx, double dy)
{
    T[0] = {T[0].first + dx, T[0].second + dy};
    T[1] = {T[1].first + dx, T[1].second + dy};
    T[2] = {T[2].first + dx, T[2].second + dy};
}
void Trougao::Centriraj(const Tacka& t)
{
    auto C = DajCentar();
    Transliraj(t.first - C.first, t.second - C.second);
}
void Trougao::Rotiraj(const Tacka& t, double ugao)
{
    T[0] = rotirana(T[0],t,ugao);
    T[1] = rotirana(T[1],t,ugao);
    T[2] = rotirana(T[2],t,ugao);
}
void Trougao::Skaliraj(const Tacka& t, double k)
{
    if(k == 0) throw std::domain_error("Nekorektan faktor skaliranja");
    T[0] = {t.first + k*(T[0].first-t.first), t.second + k*(T[0].second-t.second)};
    T[1] = {t.first + k*(T[1].first-t.first), t.second + k*(T[1].second-t.second)};
    T[2] = {t.first + k*(T[2].first-t.first), t.second + k*(T[2].second-t.second)};
}
void Trougao::Rotiraj(double ugao)
{
    Rotiraj(DajCentar(), ugao);
}
void Trougao::Skaliraj(double faktor)
{
    Skaliraj(DajCentar(), faktor);
}
bool DaLiSuIdenticni(const Trougao& t1, const Trougao& t2)
{
    auto s1 = std::set<Tacka>{t1.T[0], t1.T[1], t1.T[2]};
    auto s2 = std::set<Tacka>{t2.T[0], t2.T[1], t2.T[2]};
    auto it = s1.begin();
    for(auto e: s2) 
        if(!Trougao::equals(it->first, e.first) || !Trougao::equals(it->second, e.second)) return false;
        else it++;
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    std::vector<std::pair<double, Tacka> > p1, p2;
    for(int i=1; i<=3; i++)
    {
        p1.push_back({t1.DajStranicu(i), t1.DajTjeme(i)});
        p2.push_back({t2.DajStranicu(i), t2.DajTjeme(i)});
    }
    std::sort(p1.begin(), p1.end());
    std::sort(p2.begin(), p2.end());
    bool ok = true;
    for(int i=0; i<3; i++)
    {
        ok = ((Trougao::equals(p1[i].first, p2[i].first)) && ok);
    }
    if(ok && ( Trougao::equals(p1[0].first, p1[1].first) || Trougao::equals(p1[1].first, p1[2].first))) ok = true;
    else if(Trougao::Orijentacija(p1[0].second, p1[1].second, p1[2].second) != Trougao::Orijentacija(p2[0].second,p2[1].second,p2[2].second)) ok = false;
    return ok;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    std::vector<std::pair<double, Tacka> > p1, p2;
    for(int i=1; i<=3; i++)
    {
        p1.push_back({t1.DajStranicu(i), t1.DajTjeme(i)});
        p2.push_back({t2.DajStranicu(i), t2.DajTjeme(i)});
    }
    std::sort(p1.begin(), p1.end());
    std::sort(p2.begin(), p2.end());
    bool ok = true;
    double k = p1[0].first / p2[0].first;
    for(int i=0; i<3; i++)
        ok = (Trougao::equals(k, p1[i].first/ p2[i].first) && ok);
    if(ok && ( Trougao::equals(p1[0].first/p2[0].first, p1[1].first/p2[0].first) || Trougao::equals(p1[1].first/p2[0].first, p1[2].first/p2[0].first))) ok = true;
    else if(Trougao::Orijentacija(p1[0].second, p1[1].second, p1[2].second) != Trougao::Orijentacija(p2[0].second,p2[1].second,p2[2].second)) ok = false;
    return ok;
}

int main ()
{
    std::cout<< "Koliko zelite kreirati trouglova: ";
    int N;
    double x1,y1,x2,y2,x3,y3;
    std::cin>>N;
    std::vector<std::shared_ptr<Trougao> > v(N);
    for(int i=0; i<N; i++)
    {
        std::cout<< "Unesite podatke za "<< i+1 <<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>> x1>> y1>> x2>> y2>> x3>> y3;
        try
        {
            v[i] = std::make_shared<Trougao>(Trougao{{x1,y1}, {x2,y2}, {x3,y3}});
        }
        catch(std::domain_error e)
        {
            std::cout<< e.what()<<", ponovite unos!\n";
            i--;
        }
    }
    double dx, dy, alpha, k;
    std::cout<< "Unesite vektor translacije (dx dy): ";
    std::cin>> dx>> dy;
    std::cout<< "Unesite ugao rotacije: ";
    std::cin>> alpha;
    std::cout<< "Unesite faktor skaliranja: ";
    std::cin>> k;
    std::cout << "Trouglovi nakon obavljenih transformacija:\n";
    std::transform(v.begin(), v.end(),v.begin(), [dx,dy,alpha,k](std::shared_ptr<Trougao> p1){
        p1->Transliraj(dx, dy);
        p1->Rotiraj(alpha);
        p1->Skaliraj(p1->DajTjeme(1), k);
        return p1;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
        return p1->DajPovrsinu() < p2->DajPovrsinu();
    });
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1){
       p1->Ispisi(); std::cout<< "\n"; 
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
        return p1->DajObim() < p2->DajObim();
    }))->Ispisi();
    std::cout<<"\n";
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> vpsi, vpsp, vpss;
    for(int i=0;i<N;i++)
    {
        for(int j = i+1; j<N; j++)
        {
            if(DaLiSuIdenticni(*v[i], *v[j])) vpsi.push_back({v[i], v[j]});
            if(DaLiSuPodudarni(*v[i], *v[j])) vpsp.push_back({v[i], v[j]});
            if(DaLiSuSlicni(*v[i], *v[j])) vpss.push_back({v[i], v[j]});
        }
    }
    if(vpsi.size() == 0) std::cout<<"Nema identicnih trouglova!\n";
    else 
    {
        std::cout<<"Parovi identicnih trouglova:\n";
        std::for_each(vpsi.begin(), vpsi.end(), [](std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao> > p1){
        p1.first->Ispisi(); std::cout<< " i "; p1.second->Ispisi(); std::cout<< "\n"; 
        });
    }
    if(vpsp.size() == 0) std::cout<<"Nema podudarnih trouglova!\n";
    else
    {
        std::cout<< "Parovi podudarnih trouglova:\n";
       std::for_each(vpsp.begin(), vpsp.end(), [](std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao> > p1){
       p1.first->Ispisi(); std::cout<< " i "; p1.second->Ispisi(); std::cout<< "\n"; 
       });
    }
    if(vpss.size() == 0) std::cout<<"Nema slicnih trouglova!\n";
    else
    {
        std::cout<< "Parovi slicnih trouglova:\n";
        std::for_each(vpss.begin(), vpss.end(), [](std::pair<std::shared_ptr<Trougao>,std::shared_ptr<Trougao> > p1){
        p1.first->Ispisi(); std::cout<< " i "; p1.second->Ispisi(); std::cout<< "\n"; 
        });
    }
	return 0;
}