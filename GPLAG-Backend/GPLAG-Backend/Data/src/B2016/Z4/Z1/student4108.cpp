/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <algorithm>

typedef std::pair<double,double> Tacka;

double duzinastr (Tacka t1, Tacka t2){
    return sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
}
double orj(Tacka t1,Tacka t2, Tacka t3){
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}
bool JesuLiJednaki (double x,double y, double Eps=1e-10){
    return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
}

class Trougao{
    Tacka tac1,tac2,tac3;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        tac1=t1;
        tac2=t2;
        tac3=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) tac1=t;
        else if(indeks==2) tac2=t;
        else if(indeks==3) tac3=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double ori=orj(t1,t2,t3);
        if(ori>0) return 1;
        else if(ori<0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return tac1;
        else if(indeks==2) return tac2;
        else return tac3;
    }
    double DajStranicu(int indeks) const{
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return duzinastr(tac2,tac3);
        else if(indeks==2) return duzinastr(tac1,tac3);
        else return duzinastr(tac1,tac2);
    }
    double DajUgao(int indeks) const{
        if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
        double a=duzinastr(tac1, tac2);
        double b=duzinastr(tac1, tac3);
        double c=duzinastr(tac2, tac3);
        if(indeks==1) return acos((a*a+b*b-c*c)/(2*a*b));
        else if (indeks==2) return acos((a*a+c*c-b*b)/(2*a*c));
        else return acos((b*b+c*c-a*a)/(2*b*c));
    }
    Tacka DajCentar() const{
        Tacka centar;
        centar.first=(tac1.first+tac2.first+tac3.first)/3;
        centar.second=(tac1.second+tac2.second+tac3.second)/3;
        return centar;
    }
    double DajObim() const{
        return duzinastr(tac1,tac2)+duzinastr(tac1,tac3)+duzinastr(tac2,tac3);
    }
    double DajPovrsinu() const{
        return (1./2)*std::abs(orj(tac1,tac2,tac3));
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(tac1,tac2,tac3)==1) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        if(t.first>std::min({tac1.first,tac2.first,tac3.first}) && t.first<std::max({tac1.first,tac2.first,tac3.first}) && t.second>std::min({tac1.second,tac2.second,tac3.second}) && t.second<std::max({tac1.second,tac2.second,tac3.second})) return true;
        return false;
    }
    void Ispisi() const{
        std::cout<<"(("<<tac1.first<<","<<tac1.second<<"),("<<tac2.first<<","<<tac2.second<<"),("<<tac3.first<<","<<tac3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y){
        Tacka t1,t2,t3;
        t1.first=tac1.first+delta_x;
        t1.second=tac1.second+delta_y;
        t2.first=tac2.first+delta_x;
        t2.second=tac2.second+delta_y;
        t3.first=tac3.first+delta_x;
        t3.second=tac3.second+delta_y;
        Postavi(t1,t2,t3);
    }
    void Centriraj(const Tacka &t){
        Transliraj(t.first, t.second);
    }
    void Rotiraj(const Tacka &t, double ugao){
        tac1.first=t.first+(tac1.first-t.first)*cos(ugao)-(tac1.second-t.second)*sin(ugao);
        tac1.second=t.second+(tac1.first-t.first)*sin(ugao)-(tac1.second-t.second)*cos(ugao);
        tac2.first=t.first+(tac2.first-t.first)*cos(ugao)-(tac2.second-t.second)*sin(ugao);
        tac2.second=t.second+(tac2.first-t.first)*sin(ugao)-(tac2.second-t.second)*cos(ugao);
        tac3.first=t.first+(tac3.first-t.first)*cos(ugao)-(tac3.second-t.second)*sin(ugao);
        tac3.second=t.second+(tac3.first-t.first)*sin(ugao)-(tac3.second-t.second)*cos(ugao);
        Postavi(tac1,tac2,tac3);
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(!JesuLiJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
        tac1.first=t.first+faktor*(tac1.first-t.first);
        tac1.second=t.second+faktor*(tac1.second-t.second);
        tac2.first=t.first+faktor*(tac2.first-t.first);
        tac2.second=t.second+faktor*(tac2.second-t.second);
        tac3.first=t.first+faktor*(tac3.first-t.first);
        tac3.second=t.second+faktor*(tac3.second-t.second);
        Postavi(tac1,tac2,tac3);
    }
    void Rotiraj(double ugao){
        Tacka t;
        t.first=(tac1.first+tac2.first+tac3.first)/3;
        t.second=(tac1.second+tac2.second+tac3.second)/3;
        Rotiraj(t,ugao);
    }
    void Skaliraj(double faktor){
        Tacka t;
        t.first=(tac1.first+tac2.first+tac3.first)/3;
        t.second=(tac1.second+tac2.second+tac3.second)/3;
        Skaliraj(t,faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
  //  friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
   // friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if((t1.tac1==t2.tac1 || t1.tac1==t2.tac2 || t1.tac1==t2.tac3) && (t1.tac2==t2.tac1 || t1.tac2==t2.tac2 || t1.tac2==t2.tac3) && (t1.tac3==t2.tac1 || t1.tac3==t2.tac2 || t1.tac3==t2.tac3)) return true;
    return false;
}

//bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    
//}


int main ()
{   Trougao t1({0,0},{0,3},{4,0});
    Trougao t2({0,3},{4,0},{0,0});
    //std::cout<<t1.DajUgao(1);
    
	return 0;
}