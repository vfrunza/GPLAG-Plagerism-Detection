/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <new>
#include <memory>
#include <algorithm>
#include <set>

typedef std::pair<double, double> Tacka;

class Trougao
{
    Tacka t1, t2, t3;
    bool TestIndeksa(int indeks) const;
    static double Izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    double UdaljenostTacaka(const Tacka &t1, const Tacka &t2) const;
    static bool JesuLiJednaki(double x, double y, const double Eps=1e-10) { return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y)); }
    static bool JesuLiTackeJednake(const Tacka &t1, const Tacka &t2);
    static bool TalesovaTeorema(double a1, double a2, double b1, double b2, double c1, double c2);
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

bool Trougao::TestIndeksa(int indeks) const
{
    if (indeks==1 or indeks==2 or indeks==3) return true;
    return false;
}

bool Trougao::JesuLiTackeJednake(const Tacka &t1, const Tacka &t2)
{ return (JesuLiJednaki(t1.first, t2.first) and JesuLiJednaki(t1.second, t2.second)); }

double Trougao::Izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{ return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second); }

double Trougao::UdaljenostTacaka(const Tacka &t1, const Tacka &t2) const
{ return sqrt(((t1.first-t2.first)*(t1.first-t2.first))+((t1.second-t2.second)*(t1.second-t2.second))); }

bool Trougao::TalesovaTeorema(double a1, double a2, double b1, double b2, double c1, double c2)
{
    if (JesuLiJednaki((a1*b1)/(a2*b2), (a1*c1)/(a2*c2)) and JesuLiJednaki((a1*c1)/(a2*c2), (b1*c1)/(b2*c2))) return true;
    return false;
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if (Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3; }
void Trougao::Postavi(int indeks, const Tacka &t)
{
    if (!TestIndeksa(indeks)) throw std::logic_error("Nekorektan indeks");
    if (indeks==1) Trougao::t1=t;
    else if (indeks==2) Trougao::t2=t;
    else Trougao::t3=t;
    if (Orijentacija(Trougao::t1, Trougao::t2, Trougao::t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if (Izraz(t1, t2, t3)>0) return 1;
    else if (Izraz(t1, t2, t3)<0) return -1;
    return 0;
}

Tacka Trougao::DajTjeme(int indeks) const
{ 
    if (!TestIndeksa(indeks)) throw std::logic_error("Nekorektan indeks");
    if (indeks==1) return t1; else if (indeks==2) return t2; else return t3;
}

double Trougao::DajStranicu(int indeks) const
{
    if (!TestIndeksa(indeks)) throw std::logic_error("Nekorektan indeks");
    if (indeks==1) return UdaljenostTacaka(t2, t3);
    else if (indeks==2) return UdaljenostTacaka(t1, t3);
    else return UdaljenostTacaka(t1, t2);
}

double Trougao::DajUgao(int indeks) const
{
    if (!TestIndeksa(indeks)) throw std::domain_error("Nekorektan indeks");
    if (indeks==1) 
    {
        double arg1=-((UdaljenostTacaka(t2, t3)*UdaljenostTacaka(t2, t3))-(UdaljenostTacaka(t1, t3)*UdaljenostTacaka(t1, t3))-
                        (UdaljenostTacaka(t1, t2)*UdaljenostTacaka(t1, t2)));
        arg1/=2*UdaljenostTacaka(t1, t3)*UdaljenostTacaka(t1, t2);
        return acos(arg1);
    }
    else if (indeks==2)
    {
        double arg2=-((UdaljenostTacaka(t1, t3)*UdaljenostTacaka(t1, t3))-(UdaljenostTacaka(t2, t3)*UdaljenostTacaka(t2, t3))-
                        (UdaljenostTacaka(t1, t2)*UdaljenostTacaka(t1, t2)));
        arg2/=2*UdaljenostTacaka(t2, t3)*UdaljenostTacaka(t1, t2);
        return acos(arg2);
    }
    else 
    {
        double arg3=-((UdaljenostTacaka(t1, t2)*UdaljenostTacaka(t1, t2))-(UdaljenostTacaka(t2, t3)*UdaljenostTacaka(t2, t3))-
                        (UdaljenostTacaka(t1, t3)*UdaljenostTacaka(t1, t3)));
        arg3/=2*UdaljenostTacaka(t2, t3)*UdaljenostTacaka(t1, t3);
        return acos(arg3);
    }
}

Tacka Trougao::DajCentar() const
{
    Tacka centar;
    centar.first=(t1.first+t2.first+t3.first)/3;
    centar.second=(t1.second+t2.second+t3.second)/3;
    return centar;
}

double Trougao::DajObim() const { return UdaljenostTacaka(t1, t2)+UdaljenostTacaka(t2, t3)+UdaljenostTacaka(t1, t3); }

double Trougao::DajPovrsinu() const { return (std::fabs(Izraz(Trougao::t1, Trougao::t2, Trougao::t3)))/2; }

bool Trougao::DaLiJePozitivnoOrijentiran() const { return Orijentacija(this->t1, this->t2, this->t3); }

void Trougao::Ispisi() const { std::cout << "((" << Trougao::t1.first << "," << Trougao::t1.second << "),(" << Trougao::t2.first << "," 
                            << Trougao::t2.second << "),(" << Trougao::t3.first << "," << Trougao::t3.second << "))"; }
                            
bool Trougao::DaLiJeUnutra(const Tacka &t) const
{ return (Orijentacija(t1, t2, t3)==Orijentacija(t1, t2, t) and Orijentacija(t1, t2, t3)==Orijentacija(t2, t3, t) and Orijentacija(t1, t2, t3)==Orijentacija(t3, t1, t)); }

void Trougao::Transliraj(double delta_x, double delta_y)
{
    t1.first+=delta_x; t2.first+=delta_x; t3.first+=delta_x;
    t1.second+=delta_y; t2.second+=delta_y; t3.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{
    double dx=t.first-DajCentar().first;
    t1.first+=dx; t2.first+=dx; t3.first+=dx;
    double dy=t.second-DajCentar().second;
    t1.second+=dy; t2.second+=dy; t3.second+=dy;
}

void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    double x1, x2, x3, y1, y2, y3;
    x1=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
    x2=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
    x3=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
    
    y1=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
    y2=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
    y3=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
    
    t1.first=x1; t2.first=x2; t3.first=x3; t1.second=y1; t2.second=y2; t3.second=y3;
}

void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if (JesuLiJednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first=t.first+(faktor*(t1.first-t.first));
    t2.first=t.first+(faktor*(t2.first-t.first));
    t3.first=t.first+(faktor*(t3.first-t.first));
   
    t1.second=t.second+(faktor*(t1.second-t.second));
    t2.second=t.second+(faktor*(t2.second-t.second));
    t3.second=t.second+(faktor*(t3.second-t.second));
}

void Trougao::Rotiraj(double ugao)
{
    double x1, x2, x3, y1, y2, y3;
    x1=DajCentar().first+(t1.first-DajCentar().first)*cos(ugao)-(t1.second-DajCentar().second)*sin(ugao);
    x2=DajCentar().first+(t2.first-DajCentar().first)*cos(ugao)-(t2.second-DajCentar().second)*sin(ugao);
    x3=DajCentar().first+(t3.first-DajCentar().first)*cos(ugao)-(t3.second-DajCentar().second)*sin(ugao);
  
    y1=DajCentar().second+(t1.first-DajCentar().first)*sin(ugao)+(t1.second-DajCentar().second)*cos(ugao);
    y2=DajCentar().second+(t2.first-DajCentar().first)*sin(ugao)+(t2.second-DajCentar().second)*cos(ugao);
    y3=DajCentar().second+(t3.first-DajCentar().first)*sin(ugao)+(t3.second-DajCentar().second)*cos(ugao);
    
    t1.first=x1; t2.first=x2; t3.first=x3; t1.second=y1; t2.second=y2; t3.second=y3;
}

void Trougao::Skaliraj(double faktor)
{
    if (JesuLiJednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first=DajCentar().first+(faktor*(t1.first-DajCentar().first));
    t2.first=DajCentar().first+(faktor*(t2.first-DajCentar().first));
    t3.first=DajCentar().first+(faktor*(t3.first-DajCentar().first));
   
    t1.second=DajCentar().second+(faktor*(t1.second-DajCentar().second));
    t2.second=DajCentar().second+(faktor*(t2.second-DajCentar().second));
    t3.second=DajCentar().second+(faktor*(t3.second-DajCentar().second));
}


bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    bool prvo(false), drugo(false), trece(false);
    if (Trougao::JesuLiTackeJednake(t1.DajTjeme(1), t2.DajTjeme(1)) or Trougao::JesuLiTackeJednake(t1.DajTjeme(1), t2.DajTjeme(2)) or Trougao::JesuLiTackeJednake(t1.DajTjeme(1), t2.DajTjeme(3))) prvo=true;
    if (Trougao::JesuLiTackeJednake(t1.DajTjeme(2), t2.DajTjeme(1)) or Trougao::JesuLiTackeJednake(t1.DajTjeme(2), t2.DajTjeme(2)) or Trougao::JesuLiTackeJednake(t1.DajTjeme(2), t2.DajTjeme(3))) drugo=true;
    if (Trougao::JesuLiTackeJednake(t1.DajTjeme(3), t2.DajTjeme(1)) or Trougao::JesuLiTackeJednake(t1.DajTjeme(3), t2.DajTjeme(2)) or Trougao::JesuLiTackeJednake(t1.DajTjeme(3), t2.DajTjeme(3))) trece=true;
    if (prvo and drugo and trece) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    bool prvi_uslov(false), drugi_uslov(false);
    auto min1=t1.DajStranicu(1); auto max1=t1.DajStranicu(1);
    auto min2=t2.DajStranicu(1); auto max2=t2.DajStranicu(1);
    int min_indeks1(1), max_indeks1(1), min_indeks2(1), max_indeks2(1);
    int sr_indeks1, sr_indeks2;
    for (int i=1; i<=3; i++)
    {
        if (t1.DajStranicu(i)>max1) max1=t1.DajStranicu(i), max_indeks1=i;
        if (t1.DajStranicu(i)<min1) min1=t1.DajStranicu(i), min_indeks1=i;
        if (t2.DajStranicu(i)>max2) max2=t2.DajStranicu(i), max_indeks2=i;
        if (t2.DajStranicu(i)<min2) min2=t2.DajStranicu(i), min_indeks2=i;
    }
    for (int i=1; i<=3; i++)
    {
        if (i!=max_indeks1 and i!=min_indeks1) sr_indeks1=i;
        if (i!=max_indeks2 and i!=min_indeks2) sr_indeks2=i;
    }
    if (Trougao::Orijentacija(t1.DajTjeme(min_indeks1), t1.DajTjeme(sr_indeks1), t1.DajTjeme(max_indeks1))==Trougao::Orijentacija(t2.DajTjeme(min_indeks2), t2.DajTjeme(sr_indeks2), t2.DajTjeme(max_indeks2))) prvi_uslov=true;
    if (Trougao::JesuLiJednaki(t1.DajStranicu(min_indeks1), t2.DajStranicu(min_indeks2)) and Trougao::JesuLiJednaki(t1.DajStranicu(sr_indeks1), t2.DajStranicu(sr_indeks2)) and Trougao::JesuLiJednaki(t1.DajStranicu(max_indeks1), t2.DajStranicu(max_indeks2))
    and Trougao::JesuLiJednaki(t1.DajUgao(min_indeks1), t2.DajUgao(min_indeks2)) and Trougao::JesuLiJednaki(t1.DajUgao(sr_indeks1), t2.DajUgao(sr_indeks2)), Trougao::JesuLiJednaki(t1.DajUgao(max_indeks1), t2.DajUgao(max_indeks2))) drugi_uslov=true;
    if (prvi_uslov and drugi_uslov) return true;
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    bool prvi_uslov(false), drugi_uslov(false);
    if (DaLiSuPodudarni(t1, t2)) return true;
    auto min1=t1.DajStranicu(1); auto max1=t1.DajStranicu(1);
    auto min2=t2.DajStranicu(1); auto max2=t1.DajStranicu(1);
    int min_indeks1(1), max_indeks1(1), min_indeks2(1), max_indeks2(1);
    int sr_indeks1, sr_indeks2;
    for (int i=1; i<=3; i++)
    {
        if (t1.DajStranicu(i)>max1) max1=t1.DajStranicu(i), max_indeks1=i;
        if (t1.DajStranicu(i)<min1) min1=t1.DajStranicu(i), min_indeks1=i;
        if (t2.DajStranicu(i)>max2) max2=t2.DajStranicu(i), max_indeks2=i;
        if (t2.DajStranicu(i)<min2) min2=t2.DajStranicu(i), min_indeks2=i;
    }
    for (int i=1; i<=3; i++)
    {
        if (i!=max_indeks1 and i!=min_indeks1) sr_indeks1=i;
        if (i!=max_indeks2 and i!=min_indeks2) sr_indeks2=i;
    }
    if (Trougao::Orijentacija(t1.DajTjeme(min_indeks1), t1.DajTjeme(sr_indeks1), t1.DajTjeme(max_indeks1))==Trougao::Orijentacija(t2.DajTjeme(min_indeks2), t2.DajTjeme(sr_indeks2), t2.DajTjeme(max_indeks2))) prvi_uslov=true;
    if (Trougao::JesuLiJednaki(t1.DajUgao(min_indeks1), t2.DajUgao(min_indeks2)) and Trougao::JesuLiJednaki(t1.DajUgao(sr_indeks1), t2.DajUgao(sr_indeks2)) and Trougao::JesuLiJednaki(t1.DajUgao(max_indeks1), t2.DajUgao(max_indeks2)) 
    and Trougao::TalesovaTeorema(t1.DajStranicu(min_indeks1), t2.DajStranicu(min_indeks2), t1.DajStranicu(sr_indeks1), t2.DajStranicu(sr_indeks2), t1.DajStranicu(max_indeks1), t2.DajStranicu(max_indeks2))) drugi_uslov=true;
    if (prvi_uslov and drugi_uslov) return true;
    return false;
}

int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v;
    try
    {
        for (int i=0; i<n; i++)
        {
            Tacka t1, t2, t3;
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> t1.first >> t1.second;
            std::cin >> t2.first >> t2.second;
            std::cin >> t3.first >> t3.second;
            try
            {
                std::shared_ptr<Trougao> p(new Trougao(t1, t2, t3));
                v.push_back(p);
            }
            catch(std::domain_error izuzetak)
            {
                std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
                i--;
            }
        }
    }
    catch(std::bad_alloc)
    {
        std::cout << "Problemi s memorijom!\n";
    }
    try
    {
        double dx, dy;
        std::cout << "Unesite vektor translacije (dx dy): ";
        std::cin >> dx >> dy;
        std::transform(v.begin(), v.end(), v.begin(), [dx, dy] (std::shared_ptr<Trougao> p) { p->Transliraj(dx, dy); return p; });
        double ugao;
        std::cout << "Unesite ugao rotacije: ";
        std::cin >> ugao;
        std::transform(v.begin(), v.end(), v.begin(), [ugao] (std::shared_ptr<Trougao> p) { p->Rotiraj(ugao); return p; });
        double faktor; 
        std::cout << "Unesite faktor skaliranja: ";
        std::cin >> faktor;
        std::transform(v.begin(), v.end(), v.begin(), [faktor] (std::shared_ptr<Trougao> p) { p->Skaliraj(p->DajTjeme(1), faktor); return p; }); 
        std::sort(v.begin(), v.end(), [] (std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) { return p1->DajPovrsinu()<p2->DajPovrsinu(); });
        std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
        std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Trougao> p) { p->Ispisi(); std::cout << std::endl; });  
        std::cout << "Trougao sa najmanjim obimom: ";
        auto p=std::min_element(v.begin(), v.end(), [] (std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2) { return p1->DajObim()<p2->DajObim(); });
        (*p)->Ispisi();
        std::cout << std::endl;
        std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> skup_identicnih;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)  if (DaLiSuIdenticni(*v[i], *v[j])) skup_identicnih.push_back(std::make_pair(v[i], v[j]));
        }
        std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> skup_podudarnih;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++) if (DaLiSuPodudarni(*v[i], *v[j])) skup_podudarnih.push_back(std::make_pair(v[i], v[j]));
        }
        std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> skup_slicnih;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++) if (DaLiSuSlicni(*v[i], *v[j])) skup_slicnih.push_back(std::make_pair(v[i], v[j]));
        }

        if (!skup_identicnih.empty()) 
        {
            std::cout << "Parovi identicnih trouglova:" << std::endl;
            for (auto it=skup_identicnih.begin(); it!=skup_identicnih.end(); it++)
            {
                (it->first)->Ispisi(); std::cout << " i "; (it->second)->Ispisi(); std::cout << std::endl;
            }
        } 
        else std::cout << "Nema identicnih trouglova!" << std::endl;
        if (!skup_podudarnih.empty()) 
        {
            std::cout << "Parovi podudarnih trouglova:" << std::endl;
            for (auto it=skup_podudarnih.begin(); it!=skup_podudarnih.end(); it++)
            {
                (it->first)->Ispisi(); std::cout << " i "; (it->second)->Ispisi(); std::cout << std::endl;
            }
        }
        else std::cout << "Nema podudarnih trouglova!" << std::endl;
        if (!skup_slicnih.empty()) 
        {
            std::cout << "Parovi slicnih trouglova:" << std::endl;
            for (auto it=skup_slicnih.begin(); it!=skup_slicnih.end(); it++)
            {
                (it->first)->Ispisi(); std::cout << " i "; (it->second)->Ispisi(); std::cout << std::endl;
            }
        }
        else std::cout << "Nema slicnih trouglova!" << std::endl;
    }
    catch(std::domain_error izuzetak)
    {
        std::cout << izuzetak.what() << std::endl;
    }
	return 0;
}