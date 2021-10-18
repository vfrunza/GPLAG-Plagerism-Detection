#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>


typedef std::pair<double, double> Tacka;

const double PI = 4*std::atan(1);

class Trougao
{
  Tacka t1;
  Tacka t2;
  Tacka t3;
  double Izraz_za_funkcije (const Tacka &t1, const Tacka &t2, const Tacka &t3) const;
  void Testiraj_kolinearnost (const Tacka &t1, const Tacka &t2, const Tacka &t3);
  bool Testiraj_indeks (int indeks) const;
  bool DaLiSuJednaki (double x, double y) const;
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

double Trougao::Izraz_za_funkcije (const Tacka &t1, const Tacka &t2, const Tacka &t3) const
{
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}

void Trougao::Testiraj_kolinearnost (const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if (Orijentacija(t1,t2,t3) == 0)
        throw std::domain_error ("Nekorektne pozicije tjemena");
}

bool Trougao::Testiraj_indeks (int indeks) const
{
    bool rezultat;
    if (indeks == 1)
        rezultat = true;
    else if (indeks == 2)
        rezultat = true;
    else if (indeks == 3)
        rezultat = true;
    else
        rezultat = false;
    
    return rezultat;
}

bool Trougao::DaLiSuJednaki (double x, double y) const
{
    const double Eps = 1e-10;
    return std::fabs(x-y) <= Eps*(std::fabs(x)+std::fabs(y));
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    Postavi(t1,t2,t3);
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    Testiraj_kolinearnost(t1,t2,t3);
        
    Trougao::t1 = t1;
    Trougao::t2 = t2;
    Trougao::t3 = t3;
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double rezultat = t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    if (rezultat>0)
        return 1;
    else if (rezultat<0)
        return -1;

    return 0;
}

void Trougao::Postavi(int indeks, const Tacka &t)
{
    if (indeks == 1)
        t1 = t;
    else if (indeks == 2)
        t2 = t;
    else if (indeks == 3)
        t3 = t;
    else
        throw std::range_error ("Nekorektan indeks");
        
    Testiraj_kolinearnost(t1,t2,t3);
}

Tacka Trougao::DajTjeme(int indeks) const
{
    if (Testiraj_indeks(indeks) == false)
        throw std::range_error ("Nekorektan indeks");
    
    Tacka rezultat;
    if (indeks == 1)
        rezultat = t1;
    else if (indeks == 2)
        rezultat = t2;
    else
        rezultat = t3;
        
    return rezultat;
}

double Trougao::DajStranicu(int indeks) const
{
    Testiraj_indeks(indeks);
    
    Tacka t1, t2;
    if (indeks == 1)
        {
            t1 = Trougao::t2;
            t2 = Trougao::t3;
        }
    else if (indeks == 2)
        {
            t1 = Trougao::t1;
            t2 = Trougao::t3;
        }
    else
        {
            t1 = Trougao::t1;
            t2 = Trougao::t2;
        }
        
    return std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
}

double Trougao::DajUgao(int indeks) const
{
    Testiraj_indeks(indeks);
    
    int in_1, in_2;
    if (indeks == 1)
        {
            in_1 = 2;
            in_2 = 3;
        }
    else if (indeks == 2)
        {
            in_1 = 1;
            in_2 = 3;
        }
    else
        {
            in_1 = 1;
            in_2 = 2;
        }
        
    double duzina_kvadrata = std::pow<double>(DajStranicu(in_1),2)+std::pow<double>(DajStranicu(in_2),2)-std::pow<double>(DajStranicu(indeks),2);
    double proizvod_stranica = 2*DajStranicu(in_1)*DajStranicu(in_2);
    double pomocna = duzina_kvadrata/proizvod_stranica;
    return std::acos(pomocna);
}

Tacka Trougao::DajCentar() const
{
    Tacka centar;
    centar.first = t1.first+t2.first+t3.first;
    centar.first /= 3.;
    centar.second = t1.second+t2.second+t3.second;
    centar.second /= 3.;
    
    return centar;
}

double Trougao::DajObim() const
{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}

double Trougao::DajPovrsinu() const
{
    return ((double)1/(double)2)*std::fabs(Izraz_za_funkcije(t1,t2,t3));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    if (Orijentacija(t1,t2,t3) == 1)
        return true;
        
    return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    int smjer_orjentacije = Orijentacija(t1,t2,t3);
    
    if (smjer_orjentacije == 1)
        {
            if (Orijentacija(t1,t2,t) == 1 && Orijentacija(t2,t3,t) == 1 && Orijentacija(t3,t1,t) == 1)
                return true;
        }
    else if (smjer_orjentacije == -1)
        {
            if (Orijentacija(t1,t2,t) == -1 && Orijentacija(t2,t3,t) == -1 && Orijentacija(t3,t1,t) == -1)
                return true;
        }
        
    return false;    
    
}

void Trougao::Ispisi() const
{
    std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    t1.first += delta_x;
    t1.second += delta_y;
    t2.first += delta_x;
    t2.second += delta_y;
    t3.first += delta_x;
    t3.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{
    Tacka centar = DajCentar();
    double delta_x = t.first - centar.first;
    double delta_y = t.second - centar.second;
    
    Transliraj(delta_x,delta_y);
}

void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    double x = t1.first;
    t1.first = t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao);
    t1.second = t.second+(x-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao);
    
    x = t2.first;
    t2.first = t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao);
    t2.second = t.second+(x-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao);
    
    x = t3.first;
    t3.first = t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao);
    t3.second = t.second+(x-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if (DaLiSuJednaki(faktor,0) == true)
        throw std::domain_error ("Nekorektan faktor skaliranja");
        
    t1.first = t.first+faktor*(t1.first-t.first);
    t1.second = t.second+faktor*(t1.second-t.second);
    
    t2.first = t.first+faktor*(t2.first-t.first);
    t2.second = t.second+faktor*(t2.second-t.second);
    
    t3.first = t.first+faktor*(t3.first-t.first);
    t3.second = t.second+faktor*(t3.second-t.second);
}

void Trougao::Rotiraj(double ugao)
{
    Rotiraj(DajCentar(),ugao);
}

void Trougao::Skaliraj(double faktor)
{
    Skaliraj(DajCentar(),faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    Tacka centar_1 = t1.DajCentar();
    Tacka centar_2 = t2.DajCentar();
    
    if (t1.DaLiSuJednaki(centar_1.first,centar_2.first) == true && t1.DaLiSuJednaki(centar_1.second,centar_2.second) == true)
        {
            int brojac = 0;
            Tacka T1 = t1.DajTjeme(1);
            Tacka T2 = t1.DajTjeme(2);
            Tacka T3 = t1.DajTjeme(3);
            Tacka T4 = t2.DajTjeme(1);
            Tacka T5 = t2.DajTjeme(2);
            Tacka T6 = t2.DajTjeme(3);
            
            if (T1 == T4 || T1 == T5 || T1 == T6)
                brojac++;
                
            if (T2 == T4 || T2 == T5 || T2 == T6)
                brojac++;
            
            if (T3 == T4 || T3 == T5 || T3 == T6)
                brojac++;
            
            if (brojac == 3)
                return true;
        }
        
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    std::vector<double> stranice_1;
    stranice_1.push_back(t1.DajStranicu(1));
    stranice_1.push_back(t1.DajStranicu(2));
    stranice_1.push_back(t1.DajStranicu(3));
    
    std::vector<double> stranice_2;
    stranice_2.push_back(t2.DajStranicu(1));
    stranice_2.push_back(t2.DajStranicu(2));
    stranice_2.push_back(t2.DajStranicu(3));
    
    std::vector<double> prvi = stranice_1;
    std::vector<double> drugi = stranice_2;
    
    std::sort(stranice_1.begin(),stranice_1.end());
    std::sort(stranice_2.begin(),stranice_2.end());
    
    int brojac = 0;
    for (int i{};i<3;i++)
        {
            if (t1.DaLiSuJednaki(stranice_1[i],stranice_2[i]) == true)
                brojac++;
        }
        
    bool uslov = false;
    if (t1.DaLiSuJednaki(t1.DajPovrsinu(),t2.DajPovrsinu()) == true)
        uslov = true;
        
    if (brojac == 3 && uslov == true)
        {
            if (Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)))
                {
                    auto it = std::find(drugi.begin(),drugi.end(),prvi[0]);
                    int pozicija = it-drugi.begin();
                    if (t1.DaLiSuJednaki(prvi[1],drugi[(pozicija+1)%3]))
                        return true;
                }
            else
                {
                    auto it = std::find(drugi.begin(),drugi.end(),prvi[0]);
                    int pozicija = it-drugi.begin();
                    if (t1.DaLiSuJednaki(prvi[2],drugi[(pozicija+1)%3]))
                        return true;
                }
        }
    
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    std::vector<double> v1 = {t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)};
    std::vector<double> v2 = {t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
    
    std::sort(v1.begin(),v1.end());
    std::sort(v2.begin(),v2.end());
    
    double faktor = v1[0]/v2[0];
    if (t1.DaLiSuJednaki(faktor,v1[1]/v2[1]) == true && t1.DaLiSuJednaki(faktor,v1[2]/v2[2]))
        {
            Trougao kopija (t2);
            kopija.Skaliraj(faktor);
            
            if (DaLiSuPodudarni(t1,kopija) == true)
                return true;
        }
        
    return false;
}









int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::cin.ignore(10000, '\n');
    
    std::vector<std::shared_ptr<Trougao>> v;
    for (int i{};i<n;i++)
        {
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            double x1, x2, x3;
            double y1, y2, y3;
            
            std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
            std::cin.ignore(100000, '\n');
            
            Tacka t1 (x1,y1);
            Tacka t2 (x2,y2);
            Tacka t3 (x3,y3);
            try
            {
                std::shared_ptr<Trougao> pomocni = std::make_shared<Trougao> (t1,t2,t3);
                v.push_back(pomocni);
            }
            catch (std::domain_error e)
            {
                std::cout<<e.what()<<", ponovite unos!"<<std::endl;
                i--;
            }
        }
        
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin>>dx>>dy;
    std::cin.ignore(10000, '\n');
    Tacka translacija (dx,dy);
    
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cin.ignore(10000, '\n');
    
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor_skaliranja;
    std::cin>>faktor_skaliranja;
    std::cin.ignore(10000, '\n');
    
    std::transform(v.begin(),v.end(), v.begin(), [translacija,ugao,faktor_skaliranja] (std::shared_ptr<Trougao> pok)
    {
        pok->Transliraj(translacija.first,translacija.second);
        pok->Rotiraj(ugao);
        pok->Skaliraj(pok->DajTjeme(1),faktor_skaliranja);
        return pok;
    });
    
   
    
    std::sort(v.begin(),v.end(), [] (std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2)
    {
        
        return p1->DajPovrsinu() < p2->DajPovrsinu();
        
    });
    
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    
    std::for_each(v.begin(),v.end(), [] (std::shared_ptr<Trougao> p)
    {
        p->Ispisi();
        std::cout<<std::endl;
    });
    
    std::shared_ptr<Trougao> najmanji = *std::min_element(v.begin(),v.end(), [] (std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2)
    {
        return p1->DajObim() < p2->DajObim();
        
    });
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    najmanji->Ispisi();
    std::cout<<std::endl;
    
    int brojac = 0;
    for (int i{};i<v.size()-1;i++)
        {
            for (int j{i+1};j<v.size();j++)
                {
                    if (DaLiSuIdenticni(*v[i],*v[j]) == true)
                        brojac++;
                }
        }
        
    if (brojac == 0)
        std::cout<<"Nema identicnih trouglova!";
    else
        {
            std::cout<<"Parovi identicnih trouglova:"<<std::endl;
            for (int i{};i<v.size()-1;i++)
        {
            for (int j{i+1};j<v.size();j++)
                {
                    if (DaLiSuIdenticni(*v[i],*v[j]) == true)
                        {
                            v[i]->Ispisi();
                            std::cout<<" i ";
                            v[j]->Ispisi();
                            std::cout<<std::endl;
                        }
                }
        }
            
        }
        
    brojac = 0;
    for (int i{};i<v.size()-1;i++)
        {
            for (int j{i+1};j<v.size();j++)
                {
                    if (DaLiSuPodudarni(*v[i],*v[j]) == true)
                        brojac++;
                }
        }
        
    if (brojac == 0)
        std::cout<<std::endl<<"Nema podudarnih trouglova!";
    else
        {
            std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
            for (int i{};i<v.size()-1;i++)
        {
            for (int j{i+1};j<v.size();j++)
                {
                    if (DaLiSuPodudarni(*v[i],*v[j]) == true)
                        {
                            v[i]->Ispisi();
                            std::cout<<" i ";
                            v[j]->Ispisi();
                            std::cout<<std::endl;
                        }
                }
        }
            
        }
        
    brojac = 0;
    for (int i{};i<v.size()-1;i++)
        {
            for (int j{i+1};j<v.size();j++)
                {
                    if (DaLiSuSlicni(*v[i],*v[j]) == true)
                        brojac++;
                }
        }
        
    if (brojac == 0)
        std::cout<<std::endl<<"Nema slicnih trouglova!";
    else
        {
            std::cout<<"Parovi slicnih trouglova:"<<std::endl;
            for (int i{};i<v.size()-1;i++)
        {
            for (int j{i+1};j<v.size();j++)
                {
                    if (DaLiSuSlicni(*v[i],*v[j]) == true)
                        {
                            v[i]->Ispisi();
                            std::cout<<" i ";
                            v[j]->Ispisi();
                            std::cout<<std::endl;
                        }
                }
        }
            
        }
    
	return 0;
}