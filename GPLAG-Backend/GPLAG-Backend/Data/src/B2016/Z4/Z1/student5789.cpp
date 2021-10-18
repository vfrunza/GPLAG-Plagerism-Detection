/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#define pi 4*atan(1.)
#define eps 0.00000001
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka t1, t2, t3;
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

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1.first=t1.first;
    Trougao::t1.second=t1.second;
    Trougao::t2.first=t2.first;
    Trougao::t2.second=t2.second;
    Trougao::t3.first=t3.first;
    Trougao::t3.second=t3.second;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    Trougao::t1.first=t1.first;
    Trougao::t1.second=t1.second;
    Trougao::t2.first=t2.first;
    Trougao::t2.second=t2.second;
    Trougao::t3.first=t3.first;
    Trougao::t3.second=t3.second;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1){
        t1.first=t.first;
        t1.second=t.second;
    }
    else if(indeks==2){
        t2.first=t.first;
        t2.second=t.second;
    }
    else if(indeks==3){
        t3.first=t.first;
        t3.second=t.second;
    }
}
static int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    int a=t1.first*(t2.second-t3.second)- t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    if(a>0) return 1;
    else if(a<0) return -1;
    else if(a==0) return 0;
}
Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks<1 ||indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1){
        return t1;
    }
    else if(indeks==2){
        return t2;
    }
    else if(indeks==3){
        return t3;
    }
}
double Trougao::DajStranicu(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1){
        return sqrt((t2.first-t3.first)*(t2.first-t3.first)+ (t2.second-t3.second)*(t2.second-t3.second));
    }
    else if(indeks==2){
        return sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
    }
    else if(indeks==3){
        return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
}
double Trougao::DajUgao(int indeks)const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    double a=sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
    double b=sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
    double c=sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    if(indeks==1){
        double alfa=acos((b*b+c*c-a*a)/2*b*c);
        alfa=alfa*(pi/180);
    }
}
Tacka Trougao::DajCentar() const{
    Tacka centar;
    centar.first=(t1.first+t2.first+t3.first)/3;
    centar.second=(t1.second+t2.second+t3.second)/3;
    return centar;
}
double Trougao::DajObim() const{
    double obim=DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    return obim;
}
double Trougao::DajPovrsinu() const{
    double s=DajObim()/2;
    double povrsina=sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3)));
    return povrsina;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(t1,t2,t3)==1) return 1;
    return -1;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if((Orijentacija(t1,t2,t3)==1 || Orijentacija(t1,t2,t3==-1))  && (Orijentacija(t1,t2,t)==1 || Orijentacija(t1,t2,t)==-1) && (Orijentacija(t2,t3,t)==1 || Orijentacija(t2,t3,t)==-1) && (Orijentacija(t3,t1,t)==1 || Orijentacija(t3,t1,t)==-1 )) return true;
    return false;
}
void Trougao::Ispisi() const{
    std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}
void Trougao::Transliraj(double delta_x, double delta_y){
    t1.first+=delta_x; t1.second+=delta_y;
    t2.first+=delta_x; t2.second+=delta_y;
    t3.first+=delta_x; t3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    double x=(3*t.first)/(t1.first+t2.first+t3.first);
    double y=(3*t.second)/(t1.second+t2.second+t3.second);
    t1.first+=x; t1.second+=y;
    t2.first+=x; t2.second+=y;
    t3.first+=x; t3.second+=y;
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
    t1.second=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
    t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
    t2.second=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
    t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
    t3.second=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor-0<eps) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first=t.first+faktor*(t1.first-t.first);
    t1.second=t.second+faktor*(t1.second-t.second);
    t2.first=t.first+faktor*(t2.first-t.first);
    t2.second=t.second+faktor*(t2.second-t.second);
    t3.first=t.first+faktor*(t3.first-t.first);
    t3.second=t.second+faktor*(t3.second-t.second);
}
void Trougao::Rotiraj(double ugao){
    Tacka centar=DajCentar();
    Rotiraj(centar, ugao);
}
void Trougao::Skaliraj(double faktor){
    if(faktor-0<eps) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka centar=DajCentar();
    Skaliraj(centar,faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    Tacka tj1= t1.DajTjeme(1), tj2=t1.DajTjeme(2), tj3=t1.DajTjeme(3), tj11=t2.DajTjeme(1),tj22=t2.DajTjeme(2), tj33=t2.DajTjeme(3);
    if((tj1.first - tj11.first<eps && tj1.second - tj11.second<eps) || (tj1.first - tj22.first<eps && tj1.second - tj22.second<eps) || (tj1.first - tj33.first<eps && tj1.second - tj33.second<eps)){
        if((tj2.first - tj11.first<eps && tj2.second - tj11.second<eps) ||(tj2.first - tj22.first<eps && tj2.second - tj22.second<eps) || (tj2.first - tj33.first<eps && tj2.second-tj33.second<eps)){
            if((tj3.first - tj11.first<eps && tj3.second - tj11.second<eps) || (tj3.first - tj22.first<eps && tj3.second - tj22.second<eps) || (tj3.first - tj33.first<eps && tj3.second - tj33.second<eps)) return true; 
        }
    }
    return false;
}
//friend bool Trougao::DaLiSuPodudarni(const Trougao &t1, )
int main ()
{
    int n;
    std::vector<Trougao>s;
    
	return 0;
}