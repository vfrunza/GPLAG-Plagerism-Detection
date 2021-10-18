/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <set>
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::pair<double, double> Tacka;

bool JesuLiJednaki(double x, double y, double Eps=1e-10)
{
    return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
}

double DuzinaStranice(const Tacka &t1, const Tacka &t2)
{
    double duzina(std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second)));
    return duzina;
}
double UgaoIzmedjuStranica(double a, double b, double c)
{
    double ugao;
    ugao=acos((b*b+c*c-a*a)/(2*b*c));
    ugao=ugao*180/(4*atan(1));
    return ugao;
}
double PomocniIzraz(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double rezultat(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    return rezultat;
}

void UvecajKoordinate(Tacka &t1, Tacka &t2, Tacka &t3, double delta_x, double delta_y)
{
    t1.first+=delta_x;
    t1.second+=delta_y;
    t2.first+=delta_x;
    t2.second+=delta_y;
    t3.first+=delta_x;
    t3.second+=delta_y;
}
Tacka TjemePomocna(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double x((t1.first+t2.first+t3.first)/3.);
    double y((t1.second+t2.second+t3.second)/3.);
    return std::make_pair(x,y);
}

void KoordinataRotiraj(const Tacka &t, Tacka &a, Tacka &b, Tacka &c, double ugao)
{
    double ugao_sin,ugao_cos;
    ugao_cos=std::cos(ugao);
    ugao_sin=std::sin(ugao);
    double x1(a.first),y1(b.first),z1(c.first),x2(a.second),y2(b.second),z2(c.second);
    a.first=t.first+(x1-t.first)*ugao_cos-(x2-t.second)*ugao_sin;
    b.first=t.first+(y1-t.first)*ugao_cos-(y2-t.second)*ugao_sin;
    c.first=t.first+(z1-t.first)*ugao_cos-(z2-t.second)*ugao_sin;
    a.second=t.second+(x1-t.first)*ugao_sin+(x2-t.second)*ugao_cos;
    b.second=t.second+(y1-t.first)*ugao_sin+(y2-t.second)*ugao_cos;
    c.second=t.second+(z1-t.first)*ugao_sin+(z2-t.second)*ugao_cos;
}

void KoordinataSkaliraj(const Tacka &t, Tacka &a, Tacka &b, Tacka &c, double faktor)
{
    a.first=t.first+faktor*(a.first-t.first);
    b.first=t.first+faktor*(b.first-t.first);
    c.first=t.first+faktor*(c.first-t.first);
    a.second=t.second+faktor*(a.second-t.second);
    b.second=t.second+faktor*(b.second-t.second);
    c.second=t.second+faktor*(c.second-t.second);
}

class Trougao
{
    Tacka a,b,c;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        else { a=t1; b=t2; c=t3; }
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        else { a=t1; b=t2; c=t3; }
    }
    void Postavi(int indeks, const Tacka &t1)
    {
        if(indeks==1)
        {
            a=t1; if(Orijentacija(t1,b,c)==0) throw std::domain_error("Nekorektne pozicije tjemena"); 
        }
        else if (indeks==2)
        {
            b=t1; if(Orijentacija(a,t1,c)==0) throw std::domain_error("Nekorektne pozicije tjemena"); 
        }
        else if(indeks==3) 
        {
            c=t1; if(Orijentacija(a,b,t1)==0) throw std::domain_error("Nekorektne pozicije tjemena"); 
        }
        else throw std::range_error("Nekorektan indeks");
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        int rezultat(PomocniIzraz(t1,t2,t3));
        if(rezultat>0) rezultat=1;
        else if(rezultat<0) rezultat=-1;
        else rezultat=0;
        return rezultat;
    }
    Tacka DajTjeme(int indeks) const { if(indeks==1) return a; else if(indeks==2) return b; else if(indeks==3) return c; else
    throw std::range_error("Nekorektan ispis"); }
    double DajStranicu(int indeks) const { if(indeks==1) return DuzinaStranice(b,c); else if(indeks==2) return DuzinaStranice(a,c); else
    if(indeks==3) return DuzinaStranice(a,b); else throw std::range_error("Nekorektan indeks"); }
    double DajUgao(int indeks) const { if(indeks==1) return UgaoIzmedjuStranica(DuzinaStranice(b,c),DuzinaStranice(a,c),DuzinaStranice(a,b));
    else if(indeks==2) return UgaoIzmedjuStranica(DuzinaStranice(a,c),DuzinaStranice(a,b),DuzinaStranice(b,c)); 
    else if(indeks==3) return UgaoIzmedjuStranica(DuzinaStranice(a,b),DuzinaStranice(b,c),DuzinaStranice(a,c));
    else throw std::range_error("Nekorektan indeks"); }
    Tacka DajCentar() const { return TjemePomocna(a,b,c); }
    double DajObim() const { return DuzinaStranice(a,b)+DuzinaStranice(b,c)+DuzinaStranice(a,c); }
    double DajPovrsinu() const { return fabs(PomocniIzraz(a,b,c))/2.; }
    bool DaLiJePozitivnoOrijentiran() const { if(Orijentacija(a,b,c)==1) return true; else return false;  }
    bool DaLiJeUnutra(const Tacka &t) const { if(Orijentacija(a,b,c)==1 && Orijentacija(a,b,t)==1 && Orijentacija(b,c,t)==1 && Orijentacija(c,a,t)==1)
    return true; else return false; }
    void Ispisi() const { std::cout << "((" << a.first << "," << a.second << "),(" << b.first << "," << b.second << "),(" << c.first << "," << 
    c.second << "))"; }
    void Transliraj(double delta_x, double delta_y) { UvecajKoordinate(a,b,c,delta_x,delta_y); }
    void Centriraj(const Tacka &t)
    { 
        Tacka teziste(TjemePomocna(a,b,c));
        double prva, druga;
        prva=t.first-teziste.first;
        druga=t.second-teziste.second;
        UvecajKoordinate(a,b,c,prva,druga);
    }
    void Rotiraj(const Tacka &t, double ugao) 
    { 
        KoordinataRotiraj(t,a,b,c,ugao);
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        KoordinataSkaliraj(t,a,b,c,faktor);
        if(faktor<0) 
        {
            KoordinataRotiraj(t,a,b,c,4*atan(1));
        }
        else if(JesuLiJednaki(faktor,0)==true) throw std::domain_error("Nekorektan faktor skaliranja");
    }
    void Rotiraj(double ugao) { KoordinataRotiraj(TjemePomocna(a,b,c),a,b,c,ugao); }
    void Skaliraj(double faktor) { KoordinataSkaliraj(TjemePomocna(a,b,c),a,b,c,faktor); }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    std::set<Tacka> skup1;
    std::set<Tacka> skup2;
    for(int i(1); i<=3; i++)
    {
        skup1.insert(t1.DajTjeme(i));
        skup2.insert(t2.DajTjeme(i));
    }
    if(skup1==skup2) return true; else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) 
{
    std::set<double> skup1, skup2;
    for(int i(0); i<3; i++)
    {
        skup1.insert(t1.DajStranicu(i+1));
        skup2.insert(t2.DajStranicu(i+1));
    }
    if(skup1!=skup2) return false;
    Tacka a1(t1.DajTjeme(1)),b1(t1.DajTjeme(2)),c1(t1.DajTjeme(3)),a2(t2.DajTjeme(1)),b2(t2.DajTjeme(2)),c2(t2.DajTjeme(3));
    if(t1.Orijentacija(a1,b1,c1)==t2.Orijentacija(a2,b2,c2) || t1.Orijentacija(a1,b1,c1)==t2.Orijentacija(a2,c2,b2) ||
    t1.Orijentacija(a1,b1,c1)==t2.Orijentacija(b2,c2,a2) || t1.Orijentacija(a1,b1,c1)==t2.Orijentacija(c2,b2,a2) ||
    t1.Orijentacija(a1,b1,c1)==t2.Orijentacija(c2,a2,b2) || t1.Orijentacija(a1,b1,c1)==t2.Orijentacija(b2,a2,c2)) return true;
    else return false;
}
bool Pomocna(double a, double b, double c)
{
    if(JesuLiJednaki(a,b)==true && JesuLiJednaki(b,c)==true) return true;
    else return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    bool stranice(true);
    double x1(t1.DajStranicu(1)),y1(t1.DajStranicu(2)),z1(t1.DajStranicu(3));
    double x2(t2.DajStranicu(1)),y2(t1.DajStranicu(2)),z2(t2.DajStranicu(3));
    if(Pomocna(x1/x2,y1/y2,z1/z2)==true || Pomocna(x1/z2,y1/x2,z1/y2)==true || Pomocna(x1/x2,y1/z2,z1/y2)==true || Pomocna(x1/z2,y1/y2,z1/x2)==true
    || Pomocna(x1/y2,y1/z2,z1/x2)==true || Pomocna(x1/y2,y1/x2,z1/z2)) stranice=true;
    else return false;
    
    std::set<double> skup1, skup2;
    for(int i(0); i<3; i++)
    {
        skup1.insert(t1.DajUgao(i+1));
        skup2.insert(t2.DajUgao(i+1));
    }
    auto it(skup1.begin());
    auto it2(skup2.begin());
    int br(0);
    while(it!=skup1.end())
    {
        double prvi(*it);
        while(it2!=skup2.end())
        {
            if(prvi==*it2) { br++; break; }
            it2++;
        }
        it++;
    }
    if(br>=2) return true;
    else return false;
}

typedef std::shared_ptr<Trougao> pametni;

bool ProvjeraParova(bool f(const Trougao &,const Trougao &), std::vector<pametni> &v, int n)
{
    bool rezultat(true);
    for(int i(0); i<n; i++)
    {
        for(int j(i+1); j<n; j++)
        {
            if(f(*v[i],*v[j])==true)
            {
                rezultat=false;
                break;
            }
            else rezultat=true;
        }
        if(rezultat==false) break; 
    }
    return rezultat;
}

int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    try
    { 
        std::vector<pametni> v(n);
        for(int i(0); i<n; i++)
        {
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka a,b,c;
            std::cin >> a.first >> a.second;
            std::cin >> b.first >> b.second;
            std::cin >> c.first >> c.second;
            try
            {
                v[i]=std::make_shared<Trougao>(a,b,c); 
            }
            catch(std::domain_error izuzetak) 
            {
                std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
                i--;
            }
        }
        std::cout << "Unesite vektor translacije (dx dy): ";
        double delta_x,delta_y;
        std::cin >> delta_x >> delta_y;
        std::cout << "Unesite ugao rotacije: ";
        double ugao;
        std::cin >> ugao;
        std::cout << "Unesite faktor skaliranja: ";
        double faktor;
        std::cin >> faktor;
        std::transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y,ugao,faktor] (pametni a)
        { 
            a->Transliraj(delta_x,delta_y);
            a->Rotiraj(a->DajCentar(),ugao);
            a->Skaliraj(a->DajTjeme(1),faktor);
            return a;
        }
        ); 
        std::sort(v.begin(),v.end(),[](pametni a, pametni b)
        {
            return a->DajPovrsinu()<b->DajPovrsinu();
        }
        );
        std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
        std::for_each(v.begin(),v.end(),[] (pametni a){ a->Ispisi(); std::cout << std::endl; });
        auto p(std::min_element(v.begin(),v.end(),[](pametni a, pametni b) {  return a->DajObim()<b->DajObim(); }));
        pametni pom;
        pom=*p;
        std::cout << "Trougao sa najmanjim obimom: ";
        pom->Ispisi();
        
        if(ProvjeraParova(DaLiSuIdenticni,v,n)==true) std::cout << std::endl << "Nema identicnih trouglova!" << std::endl;
        else
        {
        std::cout << std::endl << "Parovi identicnih trouglova:" << std::endl;
        for(int i(0); i<n; i++)
        {
            for(int j(i+1); j<n; j++)
            {
                if(DaLiSuIdenticni(*v[i],*v[j])==true) 
                {
                    v[i]->Ispisi();
                    std::cout << " i ";
                    v[j]->Ispisi();
                    std::cout << std::endl;
                }
            }
        }
        }
        
        if(ProvjeraParova(DaLiSuPodudarni,v,n)==true) std::cout << "Nema podudarnih trouglova!" << std::endl;
        else
        {
        std::cout << "Parovi podudarnih trouglova:" << std::endl;
        for(int i(0); i<n; i++)
        {
            for(int j(i+1); j<n; j++)
            {
                if(DaLiSuPodudarni(*v[i],*v[j])==true)
                {
                    v[i]->Ispisi();
                    std::cout << " i ";
                    v[j]->Ispisi();
                    std::cout << std::endl;
                }
            }
        }
        }
        
        if(ProvjeraParova(DaLiSuSlicni,v,n)==true) std::cout << "Nema slicnih trouglova!" << std::endl;
        else
        {
        std::cout << "Parovi slicnih trouglova:" << std::endl;
        for(int i(0); i<n; i++)
        {
            for(int j(i+1); j<n; j++)
            {
                if(DaLiSuSlicni(*v[i],*v[j])==true)
                {
                    v[i]->Ispisi();
                    std::cout << " i ";
                    v[j]->Ispisi();
                    std::cout << std::endl;
                }
            }
        }
        }
    }
    catch(std::domain_error izuzetak)
    {
        std::cout << izuzetak.what();
    }
    catch(std::range_error izuzetak)
    {
        std::cout << izuzetak.what();
    }
    catch(...)
    {
        std::cout << "Problemi sa memorijom...";
    }
	return 0;
}