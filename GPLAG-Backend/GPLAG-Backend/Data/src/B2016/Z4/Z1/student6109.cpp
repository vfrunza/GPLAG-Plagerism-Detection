/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>

typedef std::pair<double, double> Tacka;

class Trougao
{
    Tacka t1a, t2b, t3c;
    
public:
    Trougao(const Tacka &t1, const Tacka &t2,const  Tacka &t3) ;
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const
    {
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        else if(indeks==1) return std::sqrt(std::pow((t2b.first-t3c.first),2)+std::pow((t2b.second-t3c.second),2));
        else if(indeks==2) return std::sqrt(std::pow((t1a.first-t3c.first),2)+std::pow((t1a.second-t3c.second),2));
        return std::sqrt(std::pow((t1a.first-t2b.first),2)+std::pow((t1a.second-t2b.second),2));
    }
    double DajUgao(int indeks) const
    {                                                                         //
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks"); //TREBA ISPAVITI!!!!
        else if(indeks==1) return 1;                                          //
        return 23;
    }
    Tacka DajCentar() const
    {
        Tacka a;
        a.first=(t1a.first+t2b.first+t3c.first)/3;
        a.second=(t1a.second+t2b.second+t3c.second)/3;
        return a;
    }
    double DajObim() const{ return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);}
    double DajPovrsinu() const{ return (DajStranicu(2)+DajStranicu(1))*std::sin(DajStranicu(1)/DajStranicu(2))/2;}
    bool DaLiJePozitivnoOrijentisan() const
    {
        if(Orijentacija(t1a, t2b, t3c)==1) return true;
        return false;
    }
    bool DaLiJEUnutra(const Tacka &t) const;
    void Ispisi() const{ std::cout<<"(("<<t1a.first<<","<<t1a.second<<") , ("<<t2b.first<<","<<t2b.second<<") , ("<<t3c.first<<","<<t3c.second<<"))"<<std::endl;}
    void Translatiraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
    
};

Trougao::Trougao(const Tacka &t1,const Tacka &t2,const  Tacka &t3) 
{
    
    //if(std::abs(t1.first-t2.first)<0.00001 && std::abs(t1.first-t2.first)<0.00001 && std::abs(t1.second-t2.second)<0.00001 && std::abs(t1.second-t3.second)<0.00001) 
        //throw std::domain_error("Nekorektne pozicije tjemena");
    
    {
        t1a.first=t1.first;
        t1a.second=t1.second;
        t2b.first=t2.first;
        t2b.second=t2.second;
        t3c.first=t3.first;
        t3c.second=t3.second;
    }
}
    
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    t1a.first=t1.first;
    t1a.second=t1.second;
    t2b.first=t2.first;
    t2b.second=t2.second;
    t3c.first=t3.first;
    t3c.second=t3.second;
}

void Trougao::Postavi(int indeks, const Tacka &t)
{
    if(indeks!=1 || indeks!=2 || indeks!=3) throw std::range_error("Nekorektan indeks");
    else if(indeks==1)
    {
        t1a.first=t.first;
        t1a.second=t.second;
    }
    else if(indeks==2)
    {
        t2b.first=t.first;
        t2b.second=t.second;
    }
    else if(indeks==3)
    {
        t3c.first=t.first;
        t3c.second=t.second;
    }
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double rezultat(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)-t3.first*(t1.second-t2.second));
    if(rezultat>0.0) return 1;
    if(rezultat<0.0) return -1;
    return 0;
}

Tacka Trougao::DajTjeme(int indeks) const
{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    else if(indeks==1) return t1a;
    else if(indeks==2) return t2b;
    return t3c;
}

void Trougao::Translatiraj(double delta_x, double delta_y)
{
    t1a.first=t1a.first+delta_x;
    t1a.second=t1a.second+delta_y;
    t2b.first+=delta_x;
    t2b.second+=delta_y;
    t3c.first+=delta_x;
    t3c.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{
    t1a.first=t.first+t1a.first-DajCentar().first;
    t1a.second=t.second+t1a.second-DajCentar().second;
    t2b.first=t.first+t2b.first-DajCentar().first;
    t2b.second=t.second+t2b.second-DajCentar().second;
    t3c.first=t.first+t3c.first-DajCentar().first;
    t3c.second=t.second+t3c.second-DajCentar().second;
}

void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    t1a.first=t.first+(t1a.first-t.first)*std::cos(ugao)-(t1a.second-t.second)*std::sin(ugao);
    t1a.second=t.second+(t1a.first-t.first)*std::sin(ugao)+(t1a.second-t.second)*std::cos(ugao);
    t2b.first=t.first+(t2b.first-t.first)*std::cos(ugao)-(t2b.second-t.second)*std::sin(ugao);
    t2b.second=t.second+(t2b.first-t.first)*std::sin(ugao)+(t2b.second-t.second)*std::cos(ugao);
    t3c.first=t.first+(t3c.first-t.first)*std::cos(ugao)-(t3c.second-t.second)*std::sin(ugao);
    t3c.second=t.second+(t3c.first-t.first)*std::sin(ugao)+(t3c.second-t.second)*std::cos(ugao);
}

void Trougao::Rotiraj(double ugao)
{
    t1a.first=DajCentar().first+(t1a.first-DajCentar().first)*std::cos(ugao)-(t1a.second-DajCentar().second)*std::sin(ugao);
    t1a.second=DajCentar().second+(t1a.first-DajCentar().first)*std::sin(ugao)+(t1a.second-DajCentar().second)*std::cos(ugao);
    t2b.first=DajCentar().first+(t2b.first-DajCentar().first)*std::cos(ugao)-(t2b.second-DajCentar().second)*std::sin(ugao);
    t2b.second=DajCentar().second+(t2b.first-DajCentar().first)*std::sin(ugao)+(t2b.second-DajCentar().second)*std::cos(ugao);
    t3c.first=DajCentar().first+(t3c.first-DajCentar().first)*std::cos(ugao)-(t3c.second-DajCentar().second)*std::sin(ugao);
    t3c.second=DajCentar().second+(t3c.first-DajCentar().first)*std::sin(ugao)+(t3c.second-DajCentar().second)*std::cos(ugao);
}

void Trougao::Skaliraj(double faktor)
{
    if(faktor==0.0) throw std::domain_error("Nekorektan faktor skaliranja");
    t1a.first=DajCentar().first+faktor*(t1a.first-DajCentar().first);
    t1a.second=DajCentar().second+faktor*(t1a.second-DajCentar().first);
    t2b.first=DajCentar().first+faktor*(t2b.first-DajCentar().first);
    t2b.second=DajCentar().second+faktor*(t2b.second-DajCentar().second);
    t3c.first=DajCentar().first+faktor*(t3c.first-DajCentar().first);
    t3c.second=DajCentar().second+faktor*(t3c.second-DajCentar().second);
    
}

void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(faktor==0.0) throw std::domain_error("Nekorektan faktor skaliranja");
    t1a.first=t.first+faktor*(t1a.first-t.first);
    t1a.second=t.second+faktor*(t1a.second-t.second);
    t2b.first=t.first+faktor*(t2b.first-t.first);
    t2b.second=t.second+faktor*(t2b.second-t.second);
    t3c.first=t.first+faktor*(t3c.first-t.first);
    t3c.second=t.second+faktor*(t3c.second-t.second);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if((t1.t1a==t2.t1a && t1.t2b==t2.t2b && t1.t3c==t2.t3c) || (t1.t1a==t2.t2b && t1.t2b==t2.t3c && t1.t3c==t2.t1a) || (t1.t1a==t2.t3c && t1.t2b==t2.t1a && t1.t3c==t2.t2b)) return true;
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    Trougao t3=t2;
    t3.Centriraj(t1.DajCentar());
    if(DaLiSuIdenticni(t1, t3)) return true;
    t3.Rotiraj(90);
    if(DaLiSuIdenticni(t1, t3)) return true;
    t3.Rotiraj(180);
    if(DaLiSuIdenticni(t1, t3)) return true;
    t3.Rotiraj(270);
    if(DaLiSuIdenticni(t1, t3)) return true;
    return false;

}










int main ()
{
    Tacka t1(0,0), t2(0,3), t3(3,0), t4(1,3), t5(1,7), t6(4,3), t9(1,1);
    Trougao T(t1,t2,t3);
    Trougao T2(t4,t5,t6);
    //T2.Centriraj(t9);
    //T.Centriraj(t9);
    //Tacka t7(T.DajCentar()), t8(T2.DajCentar());
    T.Ispisi();
    T2.Ispisi();
    std::cout<<"Prvi Centar : /"<<T.DajCentar().first<<","<<T.DajCentar().second<<"/"<<std::endl<<"Drugi Centar : /"<<T2.DajCentar().first<<","<<T2.DajCentar().second<<"/";
	return 0;
}