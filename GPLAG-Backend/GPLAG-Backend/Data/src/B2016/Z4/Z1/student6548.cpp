/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <cmath>
typedef std::pair<double, double> Tacka;
class Trougao
{
    std::pair<double, double> a, b, c;
    public: 
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        a.first = t1.first;
        a.second = t1.second;
        b.first = t2.first;
        b.second = t2.second;
        c.first = t3.first;
        c.second = t3.second;
    };
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        a.first = t1.first;
        a.second = t1.second;
        b.first = t2.first;
        b.second = t2.second;
        c.first = t3.first;
        c.second = t3.second;
    };
    void Postavi(int indeks, constant Tacka &t1);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double d = t1.first*(t2.second - t3.second) - t2.first(t1.second - t3.second) + t3.first(t1.second - t2.second);
        if (d > 0) return 1;
        if (d < 0) return -1;
        if(d == 0) return 0;
    };
    Tacka DajTjeme(int indeks) const;
    {
        if(indeks < 0 || indeks > 3) throw std::domain_error("Nekorektan indeks")
        if(indeks == 1) return a;
        if(indeks == 2) return b;
        if (indeks == 3) return c;
    }    
    double DajStranicu(int indeks)
    {
        if(indeks < 0 || indeks > 3) throw std::domain_error("Nekorektan indeks")
        if(indeks == 1) return sqrt(pow(b.first - c.first, 2) -pow(b.second - c.second, 2));
        if(indeks == 2) return sqrt(pow(a.first - c.first, 2) -pow(a.second - c.second, 2));
        if(indeks == 3) return sqrt(pow(b.first - a.first, 2) -pow(b.second - a.second, 2));
    }
    double DajUgao(int indeks) const;
    {
        if(indeks < 0 || indeks > 3) throw std::domain_error("Nekorektan indeks")
        if(indeks == 1) 
        {
            int 
        }
        if(indeks == 2) return sqrt(pow(a.first - c.first, 2) -pow(a.second - c.second, 2));
        if(indeks == 3) return sqrt(pow(b.first - a.first, 2) -pow(b.second - a.second, 2)); 
    }
};


void Trougao::Postavi(int indeks, constant Tacka &t1)
{
     if(indeks == 1)
    {
        a.first = t1.first;
        a.second = t1.second;
    }
    if(indeks == 2)
    {
        b.first = t1.first;
        b.second = t1.second;
    }
    if(indeks == 3)
    {
        c.first = t1.first;
        c.second = t1.second;
    }
    if(indeks < 0 || indeks > 3) throw std::domain_error("Nekorektan indeks")
    
}

int main ()



{
    std::pair<double, double> tjeme;
    int x, y;
    std::cin>> x >> y;
    tjeme = std::make_pair<double, double>(x, y);
    
	return 0;
}