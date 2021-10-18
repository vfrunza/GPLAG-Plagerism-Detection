/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

typedef std::pair<double, double> Tacka;

const double EPS(pow(1, -10));

class Trougao
{
    Tacka t1, t2, t3;
public:
    static bool Poredi(double x, double y)
    {
        return fabs(x - y) <= EPS;
    }
    
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        return t1.first * (t2.second - t3.second) - t2.first * (t1.second - t3.second) - t3.first * (t1.second - t2.second);
    }
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const
    {
        Tacka m((1. / 3) * (t1.first + t2.first + t3.first), (1. / 3) * (t1.second + t2.second + t3.second));
        return m;
    }
    double DajObim() const { return DajStranicu(1) + DajStranicu(2) + DajStranicu(3); }
    double DajPovrsinu() const { return fabs(Orijentacija(t1, t2, t3)) / 2; }
    bool DaLiJePozitivnoOrijentiran() const { return Orijentacija(t1, t2, t3) > 0; }
    bool DaLiJeUnutra(const Tacka &t) const
    {
        
    }
    void Ispisi() const;
    
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Rotiraj(double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Skaliraj(double faktor);
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarini(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if((t1.first == t2.first && t1.first == t3.first) || (t1.second == t2.second && t1.second == t3.second))
      throw std::domain_error("Nekorektne pozicije tjemena");
    
    Trougao::t1 = t1;
    Trougao::t2 = t2;
    Trougao::t3 = t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if((t1.first == t2.first && t1.first == t3.first) || (t1.second == t2.second && t1.second == t3.second))
      throw std::domain_error("Nekorektne pozicije tjemena");
    
    Trougao::t1 = t1;
    Trougao::t2 = t2;
    Trougao::t3 = t3;
}

void Trougao::Postavi(int indeks, const Tacka &t)
{
    if(indeks < 1 || indeks > 3)
      throw std::range_error("Nekorektan indeks");
    else if(indeks == 1) Trougao::t1 = t1;
    else if(indeks == 2) Trougao::t2 = t2;
    else Trougao::t3 = t3;
}


Tacka Trougao::DajTjeme(int indeks) const
{
    if(indeks == 1) return t1;
    else if(indeks == 2) return t2;
    else return t3;
}

double Trougao::DajStranicu(int indeks) const
{
    if(indeks == 1)
    {
        return sqrt(pow(t2.first - t3.first, 2) + pow(t2.second - t3.second, 2));
    }
    else if(indeks == 2)
    {
        return sqrt(pow(t1.first - t3.first, 2) + pow(t1.second - t3.second, 2));
    }
    else
    {
        return sqrt(pow(t1.first - t2.first, 2) + pow(t1.second - t2.second, 2));
    }
}

double Trougao::DajUgao(int indeks) const
{
    double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
    if(indeks == 1)
    {
        return acos((b * b + c * c - a * a) / (2 * b * c));
    }
    else if(indeks == 2)
    {
        return acos((a * a + c * c - b * b) / (2 * a * c));
    }
    else
    {
        return acos((a * a + b * b - c * c) / (2 * a * b));
    }
}


void Trougao::Ispisi() const
{
    std::cout << "((" << t1.first << "," << t1.second << "), "
              << "(" << t2.first << "," << t2.second << "), "
              << "(" << t3.first << "," << t3.second << "))" 
              << std::endl;
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    t1.first += delta_x; t2.first += delta_x; t3.first += delta_x;
    t1.second += delta_y; t2.second += delta_y; t3.second += delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{
    
}

void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    t1.first = (t.first + (t1.first - t.first) * cos(ugao) - (t1.second - t.second) * sin(ugao));
    t1.second = (t.second + (t1.second - t.second) * sin(ugao) + (t1.second - t.second) * cos(ugao));
    t2.first = (t.first + (t2.first - t.first) * cos(ugao) - (t2.second - t.second) * sin(ugao));
    t2.second = (t.second + (t2.second - t.second) * sin(ugao) + (t2.second - t.second) * cos(ugao));
    t3.first = (t.first + (t3.first - t.first) * cos(ugao) - (t3.second - t.second) * sin(ugao));
    t3.second = (t.second + (t3.second - t.second) * sin(ugao) + (t3.second - t.second) * cos(ugao));
}

void Trougao::Rotiraj(double ugao) { Rotiraj(DajCentar(), ugao); }

void Trougao::Skaliraj(const Tacka &t, double k)
{
    if(Poredi(k, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    
    t1.first = (t.first + k * (t1.first - t.first));
    t1.second = (t.second + k * (t1.second - t.second));
    t2.first = (t.first + k * (t2.first - t.first));
    t2.second = (t.second + k * (t2.second - t.second));
    t3.first = (t.first + k * (t3.first - t.first));
    t3.second = (t.second + k * (t3.second - t.second));
}

void Trougao::Skaliraj(double k) { Skaliraj(DajCentar(), k); }

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    short i(0);
    if(t1.t1 == t2.t1 || t1.t1 == t2.t2 || t1.t1 == t2.t3) i++;
    if(t1.t2 == t2.t1 || t1.t2 == t2.t2 || t1.t2 == t2.t3) i++;
    if(t1.t3 == t2.t1 || t1.t3 == t2.t2 || t1.t3 == t2.t3) i++;
    return i == 3;
}

bool DaLiSuPodudarini(const Trougao &t1, const Trougao &t2)
{
    return true;
}



int main ()
{
    int vel;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> vel;
    std::vector<std::shared_ptr<Trougao>> tr(vel);
    
    for(int i(0); i < tr.size(); i++)
    {
        try
        {
            Tacka t1, t2, t3;
            std::cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> t1.first >> t1.second >> t2.first >> t2.second >> t3.first >> t3.second;
            
            tr[i] = std::make_shared<Trougao>(t1, t2, t3);
        }
        catch(const std::exception &e)
        {
            std::cout << "Nekorektne pozicije tjemena, ponovite unos!" << std::endl;
            i--;
        }
    }
   
    
    double dx, dy;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> dx >> dy;
    
    double ugao;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    
    double k;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> k;
    
    for(int i(0); i < tr.size(); i++)
    {
        tr[i]->Transliraj(dx, dy);
        tr[i]->Rotiraj(ugao);
        tr[i]->Skaliraj(k);
    }
    
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    for(int i(0); i < tr.size(); i++)
    {
        tr[i]->Ispisi(); std::cout << " ";
    }
	return 0;
}