/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>
using std::sort;
using std::vector;
using std::pair;
using std::cout;
using std::cin;
typedef std::pair<double, double> Tacka; 
double epsilon=pow(10,-10);
class Trougao
{
    Tacka t1,t2,t3;
    static bool Isti(double a,double b) 
    {
        return (fabs(a-b)<=epsilon*(fabs(a)+fabs(b)));
    }
    public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3)
    {
        if(Isti((t1.first*(t2.second-t3.second)-t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second)),0))
        throw std::domain_error("“Nekorektne pozicije tjemena");
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Isti((t1.first*(t2.second-t3.second)-t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second)),0))
        throw std::domain_error("“Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if(indeks==1)
        {
            if(Isti(t.first*(t2.second-t3.second)-t2.first*(t3.second-t.second)+t3.first*(t.second-t2.second),0))
            throw std::domain_error("“Nekorektne pozicije tjemena");
            t1=t;
        }
        else if(indeks==2)
        {
            if(Isti(t1.first*(t.second-t3.second)-t.first*(t3.second-t1.second)+t3.first*(t1.second-t.second),0))
            throw std::domain_error("“Nekorektne pozicije tjemena");
            t2=t;
        }
        else if(indeks==3)
        {
            if(Isti(t1.first*(t2.second-t.second)-t2.first*(t.second-t1.second)+t.first*(t1.second-t2.second),0))
            throw std::domain_error("“Nekorektne pozicije tjemena");
            t3=t;
        }
        else
        {
            throw std::range_error("Nekorektan indeks");
        }
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)  
    {
        if(t1.first*(t2.second-t3.second)-t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second)>0)
        return 1;
        else if(t1.first*(t2.second-t3.second)-t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second)<0)
        return -1;
        else
        return 0;
    }
    Tacka DajTjeme(int indeks) const
    {
        if(indeks==1)
            return t1;
        else if(indeks==2)
            return t2;
        else if(indeks==3)
            return t3;
        else 
            throw std::range_error("Nekorektan indeks");
    }
    double DajStranicu(int indeks) const
    {
        if(indeks==1)
        {
            return std::sqrt(pow((t2.first-t3.first),2)+pow((t2.second-t3.second),2));
        }
        else if(indeks==2)
        {
            return std::sqrt(pow((t1.first-t3.first),2)+pow((t1.second-t3.second),2));
        }
        else if(indeks==3)
        {
            return std::sqrt(pow((t2.first-t1.first),2)+pow((t2.second-t1.second),2));
        }
        else
        {
             throw std::range_error("Nekorektan indeks");
        }
    }
    double DajUgao(int indeks) const
    {
        if(indeks==1)
        {
            return acos((pow(DajStranicu(1),2)-pow(DajStranicu(2),2)-pow(DajStranicu(3),2))/(2*DajStranicu(2)*DajStranicu(3)));
        }
        if(indeks==2)
        {
            return acos((pow(DajStranicu(2),2)-pow(DajStranicu(1),2)-pow(DajStranicu(3),2))/(2*DajStranicu(1)*DajStranicu(3)));
        }
        if(indeks==3)
        {
            return acos((pow(DajStranicu(3),2)-pow(DajStranicu(2),2)-pow(DajStranicu(1),2))/(2*DajStranicu(2)*DajStranicu(1)));
        }
        else
        throw std::range_error("Nekorektan indeks");
    }
    Tacka DajCentar() const  
    {
        Tacka T;
        T.first=(t1.first+t2.first+t3.first)/3;
        T.second=(t1.second+t2.second+t3.second)/3;
        return T;
    }
    double DajObim() const
    {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const 
    {
        return t1.first*(t2.second-t3.second)-t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
    }
    bool DaLiJePozitivnoOrijentiran() const
    {
        return t1.first*(t2.second-t3.second)-t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second)>0;
    }
    bool DaLiJeUnutra(const Tacka &t) const
    {
        if(Orijentacija(t1,t2,t3)==Orijentacija(t1,t2,t) && Orijentacija(t1,t2,t)==Orijentacija(t2,t3,t) && Orijentacija(t2,t3,t)==Orijentacija(t3,t1,t))
        return true;
        return false;
    }
    void Ispisi() const
    {
        cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y)
    {
        t1.first+=delta_x;
        t2.first+=delta_x;
        t3.first+=delta_x;
        t1.second+=delta_y;
        t2.second+=delta_y;
        t3.second+=delta_y;
    }
    void Centriraj()
    {
        Tacka T=DajCentar();
        Transliraj(T.first-(DajCentar()).first,T.second-(DajCentar()).second);
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        t1.first=(t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao));
        t2.first=(t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao));
        t3.first=(t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao));
        t1.second=(t.second+(t1.first-t.first)*sin(ugao)-(t1.second-t.second)*cos(ugao));
        t2.second=(t.second+(t2.first-t.first)*sin(ugao)-(t2.second-t.second)*cos(ugao));
        t3.second=(t.second+(t3.first-t.first)*sin(ugao)-(t3.second-t.second)*cos(ugao));
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        if(Isti(faktor,0))
        throw std::domain_error("Nekorektan faktor skaliranja");
        t1.first=t.first+faktor*(t1.first-t.first);
        t2.first=t.first+faktor*(t2.first-t.first);
        t3.first=t.first+faktor*(t3.first-t.first);
        t1.second=t.second+faktor*(t1.second-t.second);
        t2.second=t.second+faktor*(t2.second-t.second);
        t3.second=t.second+faktor*(t3.second-t.second);
    }
    void Rotiraj(double ugao)
    {
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(double faktor) 
    {
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
    {
        vector<pair<double,double>> a{t1.Trougao::t1,t1.Trougao::t2,t1.Trougao::t3};
        vector<pair<double,double>> b{t2.Trougao::t1,t2.Trougao::t2,t2.Trougao::t3};
        sort(a.begin(),a.end(),[] (pair<double,double> c,pair<double,double> d)
        {
            if(!Isti(c.first,d.first))
            return c.first>d.first;
            return c.second>d.second;
        }
        );
        sort(b.begin(),b.end(),[] (pair<double,double> c,pair<double,double> d)
        {
            if(!Isti(c.first,d.first))
            return c.first>d.first;
            return c.second>d.second;
        }
        );
        if(Isti(a[0].first,b[0].first) && Isti(a[1].first,b[1].first) && Isti(a[2].first,b[2].first) && Isti(a[0].second,b[0].second) && Isti(a[1].second,b[1].second) && Isti(a[2].second,b[2].second))
        return true;
        return false;
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
    {
        int br(0);
        if(Isti(t1.DajStranicu(1),t1.DajStranicu(2)) || Isti(t1.DajStranicu(2),t1.DajStranicu(3)) || Isti(t1.DajStranicu(1),t1.DajStranicu(3)))
        br++;
        vector<pair<Tacka,double>> a{{t1.Trougao::t1,t1.DajStranicu(1)},{t1.Trougao::t2,t1.DajStranicu(2)},{t1.Trougao::t3,t1.DajStranicu(3)}};
        vector<pair<Tacka,double>> b{{t2.Trougao::t1,t2.DajStranicu(1)},{t2.Trougao::t2,t2.DajStranicu(2)},{t2.Trougao::t3,t2.DajStranicu(3)}};
        sort(a.begin(),a.end(),[] (pair<Tacka,double> c,pair<Tacka,double> d)
        {
            return c.second>d.second;
        });
        sort(b.begin(),b.end(),[] (pair<Tacka,double> e,pair<Tacka,double> f)
        {
            return e.second>f.second;
        });
        Trougao t3(a[0].first,a[1].first,a[2].first);
        Trougao t4(b[0].first,b[1].first,b[2].first);
        if(Isti(t3.DajStranicu(1),t4.DajStranicu(1)) && Isti(t3.DajStranicu(2),t4.DajStranicu(2)) && Isti(t3.DajStranicu(3),t4.DajStranicu(3)) && br>0)
        return true;
        if(Isti(t3.DajStranicu(1),t4.DajStranicu(1)) && Isti(t3.DajStranicu(2),t4.DajStranicu(2)) && Isti(t3.DajStranicu(3),t4.DajStranicu(3)) && Orijentacija(a[0].first,a[1].first,a[2].first)==Orijentacija(b[0].first,b[1].first,b[2].first))
        return true;
        return false;
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
    {
        vector<pair<Tacka,double>> a{{t1.Trougao::t1,t1.DajStranicu(1)},{t1.Trougao::t2,t1.DajStranicu(2)},{t1.Trougao::t3,t1.DajStranicu(3)}};
        vector<pair<Tacka,double>> b{{t2.Trougao::t1,t2.DajStranicu(1)},{t2.Trougao::t2,t2.DajStranicu(2)},{t2.Trougao::t3,t2.DajStranicu(3)}};
        sort(a.begin(),a.end(),[] (pair<Tacka,double> c,pair<Tacka,double> d)
        {
            return c.second>d.second;
        });
        sort(b.begin(),b.end(),[] (pair<Tacka,double> e,pair<Tacka,double> f)
        {
            return e.second>f.second;
        });
        Trougao t3(t2.Trougao::t1,t2.Trougao::t2,t2.Trougao::t3);
        t3.Skaliraj(a[0].second/b[0].second);
        if(DaLiSuPodudarni(t1,t3))
        return true;
        return false;
    }
};
int main ()
{
	return 0;
}