/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <new>
#include <vector>
#include <cmath>
#include <memory>
typedef std::pair<double, double> Tacka;

class Trougao
{   
    //bool veca(const int x,const int y) const { if(x>y) return true; return false; }
    Tacka t1, t2, t3;
    static bool Poredi(double x, double y) {
        const double ee(1e-15);
        return(std::fabs(x-y)<=ee*(std::fabs(x)+std::fabs(y)));
    }
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

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second, x3=t3.first, y3=t3.second;
    int x=(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2));
    if(x==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1;
    Trougao::t2=t2;
    Trougao::t3=t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second, x3=t3.first, y3=t3.second;
    int x=(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2));
    if(x==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1;
    Trougao::t2=t2;
    Trougao::t3=t3;
}

void Trougao::Postavi(int indeks, const Tacka &t)
{  // Tacka tx=t;
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) t1=t;
    if(indeks==2) t2=t;
    else t3=t;
   // double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second, x3=t3.first, y3=t3.second;
   // int x=(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2));
   // if(x==0 && indeks==0) { t1=tx; 
}

static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second, x3=t3.first, y3=t3.second;
    double p=(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2));
    if(p>0) return 1;
    if(p<0) return -1;
    return 0;
}

Tacka Trougao::DajTjeme(int indeks) const
{
    if(indeks<0 || indeks>0) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return Trougao::t1;
    if(indeks==2) return Trougao::t2;
    return Trougao::t3;
}

double Trougao::DajStranicu(int indeks) const
{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return std::sqrt( ((t2.first-t3.first)*(t2.first-t3.first)) +((t2.second-t3.second)*(t2.second-t3.second)) );
    if(indeks==2) {
        double x1=t1.first, y1=t1.second, x2=t3.first, y2=t3.second;
        return std::sqrt( ((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)) );
    } else {
        double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second;
        return std::sqrt( ((x2-x2)*(x2-x1))+ ((y2-y1)*(y2-y1)) );
    }
}

double Trougao::DajUgao(int indeks) const
{
    if(indeks<0 || indeks>3) throw std::range_error("Nekorektan indeks");
    double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second, x3=t3.first, y3=t3.second;
    double a=std::sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) );
    double b=std::sqrt( ((x3-x2)*(x3-x2)) + ((y3-y2)*(y3-y2)) );
    double c=std::sqrt( ((x3-x1)*(x3-x1)) + ((y3-y1)*(y3-y1)) );
    if(indeks==1) return (std::acos((a*a+c*c-b*b)/(2*a*c)));
    if(indeks==2) return (std::acos((a*a+b*b-c*c)/(2*a*b)));
    else return (std::acos((b*b+c*c-a*a)/(2*b*c)));
}

Tacka Trougao::DajCentar() const
{
    Tacka t;
    t.first=(t1.first+t2.first+t3.first)/3;
    t.second=(t1.second+t2.second+t3.second)/3;
    return t;
}


double Trougao::DajObim() const
{
    double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second, x3=t3.first, y3=t3.second;
    double a=std::sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) );
    double b=std::sqrt( ((x3-x2)*(x3-x2)) + ((y3-y2)*(y3-y2)) );
    double c=std::sqrt( ((x3-x1)*(x3-x1)) + ((y3-y3)*(y3-y1)) );
    return a+b+c;
}

double Trougao::DajPovrsinu() const
{
    double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second, x3=t3.first, y3=t3.second;
    double p=( (x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2)) );
    p/=2;
    if(p<0) p*=-1;
    return p;
}

bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second, x3=t3.first, y3=t3.second;
    int p=(x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2));
    if(p>0) return true;
    return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const { 
    int x=t.first, y=t.second,  x1=t1.first, x2=t2.first, x3=t3.first, y1=t1.second, y2=t2.second, y3=t3.second;
   // if(veca(x,x1) && veca(x,x2) && !veca(x,x3) && veca(y,y1) && veca(y,y2) && !veca(y,y3))  return true;
  //  if(veca(x,x1) && veca(x,x2) && !veca(x,x3) && veca(y,y1) && veca(y,y3) && !veca(y,y2)) return true;
   // if(veca())
int vecaod(0), manjaod(0);
if(x>x1) vecaod++; if(x<x1) manjaod++;
if(x>x2) vecaod++; if(x<x2) manjaod++;
if(x>x3) vecaod++; if(x<x3) manjaod++;
int vecaody(0), manjaody(0);
if(y>y1) vecaody++; if(y<y1) manjaody++;
if(y>y2) vecaody++; if(y<y2) manjaody++;
if(y>y3) vecaody++; if(y<y3) manjaody++;
if(vecaod==2 && manjaod==1 && vecaody==2 && manjaody==1) return true;
return false;
    
} 

void Trougao::Ispisi() const
{
    std::cout<<"("<<"("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    t1.first+=delta_x;
    t1.second+=delta_y;
    t2.first+=delta_x;
    t2.second+=delta_y;
    t3.first+=delta_x;
    t3.second+=delta_y;
}

// void Centriraj (const Tacka &t);


void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    double xc=t.first, yc=t.second;
    t1.first=(xc+(t1.first-xc)*std::cos(ugao)-(t1.second-yc)*std::sin(ugao));
    t2.first=(xc+(t2.first-xc)*std::cos(ugao)-(t2.second-yc)*std::sin(ugao));
    t3.first=(xc+(t3.first-xc)*std::cos(ugao)-(t3.second-yc)*std::sin(ugao));
    t1.second=(yc+(t1.first-xc)*std::sin(ugao)+(t1.second-yc)*std::cos(ugao));
    t2.second=(yc+(t2.first-xc)*std::sin(ugao)+(t2.second-yc)*std::cos(ugao));
    t3.second=(yc+(t3.first-xc)*std::sin(ugao)+(t3.second-yc)*std::cos(ugao));
}

void Trougao::Rotiraj(double ugao)
{
    double xc=(t1.first+t2.first+t3.first)/3, yc=(t1.second+t2.second+t3.second)/3;
    t1.first=(xc+(t1.first-xc)*std::cos(ugao)-(t1.second-yc)*std::sin(ugao));
    t2.first=(xc+(t2.first-xc)*std::cos(ugao)-(t2.second-yc)*std::sin(ugao));
    t3.first=(xc+(t3.first-xc)*std::cos(ugao)-(t3.second-yc)*std::sin(ugao));
    t1.second=(yc+(t1.first-xc)*std::sin(ugao)+(t1.second-yc)*std::cos(ugao));
    t2.second=(yc+(t2.first-xc)*std::sin(ugao)+(t2.second-yc)*std::cos(ugao));
    t3.second=(yc+(t3.first-xc)*std::sin(ugao)+(t3.second-yc)*std::cos(ugao));
}
void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(Poredi(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
    double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second, x3=t3.first, y3=t3.second;
    if(t==Trougao::t1) {
        x2=x1+faktor*(x2-x1);
        y2=y1+faktor*(y2-y1);
        x3=x1+faktor*(x3-x1);
        y3=y1+faktor*(y3-y1);
        t2.first=x2;
        t2.second=y2;
        t3.first=x3;
        t3.second=y3;
        return;
    }
    if(t==Trougao::t2) {
        x1=x2+faktor*(x1-x2);
        y1=y2+faktor*(y1-y2);
        x3=x2+faktor*(x3-x2);
        y3=y2+faktor*(y3-y2);
        t1.first=x1;
        t1.second=y1;
        t3.first=x3;
        t3.second=y3;
        return;
    }
    if(t==Trougao::t3) {
        x1=x3+faktor*(x1-x3);
        y1=y3+faktor*(y1-y3);
        x2=x3+faktor*(x2-x3);
        y2=y3+faktor*(y2-y3);
        t1.first=x1;
        t1.second=y1;
        t2.first=x2;
        t2.second=y2;
        return;
    }
}

void Trougao::Skaliraj(double faktor)
{
    double x1=t1.first, y1=t1.second, x2=t2.first, y2=t2.second, x3=t3.first, y3=t3.second;
    Tacka t;
    t.first=(x1+x2+x3)/3;
    t.second=(y1+y2+y3)/3;
    double x=t.first, y=t.second;
    x1=x+faktor*(x1-x);
    y1=y+faktor*(y1-y);
    x2=x+faktor*(x2-x);
    y2=y+faktor*(y2-y);
    x3=x+faktor*(x3-x);
    y3=y+faktor*(y3-y);
    t1.first=x1;
    t1.second=y1;
    t2.first=x2;
    t2.second=y2;
    t3.first=x3;
    t3.second=y3;
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    Tacka t11=t1.t1, t12=t1.t2, t13=t1.t3, t21=t2.t1, t22=t2.t2, t23=t2.t3;
    if( (t11==t21 || t11==t22 || t11==t23) && (t12==t21 || t12==t22 || t12==t23) && (t13==t21 || t13==t22 || t13==t23)) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    if( ( !Trougao::Poredi(t1.DajStranicu(1), t2.DajStranicu(1)) && !Trougao::Poredi(t1.DajStranicu(1), t2.DajStranicu(2)) && !Trougao::Poredi(t1.DajStranicu(1), t2.DajStranicu(3)) ) || (!Trougao::Poredi(t1.DajStranicu(2), t2.DajStranicu(1)) &&  !Trougao::Poredi(t1.DajStranicu(2), t2.DajStranicu(2)) && !Trougao::Poredi(t1.DajStranicu(2), t2.DajStranicu(3)) ) || (!Trougao::Poredi(t1.DajStranicu(3), t2.DajStranicu(1)) && !Trougao::Poredi(t1.DajStranicu(3), t2.DajStranicu(2)) &&  !Trougao::Poredi(t1.DajStranicu(3), t2.DajStranicu(3)) ) ) return false;
    if( (!Trougao::Poredi(t1.DajUgao(1), t2.DajUgao(1)) && !Trougao::Poredi(t1.DajUgao(1), t2.DajUgao(2)) && !Trougao::Poredi(t1.DajUgao(1), t2.DajUgao(3)) )  || (!Trougao::Poredi(t1.DajUgao(2), t2.DajUgao(1)) && !Trougao::Poredi(t1.DajUgao(2), t2.DajUgao(3)) &&  !Trougao::Poredi(t1.DajUgao(2), t2.DajUgao(2)) ) ||  (!Trougao::Poredi(t1.DajUgao(3), t2.DajUgao(1)) && !Trougao::Poredi(t1.DajUgao(3), t2.DajUgao(2)) &&  !Trougao::Poredi(t1.DajUgao(3), t2.DajUgao(3)) ) ) return false;
    return true;
}

// da li su slicni
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
  double ugao1=t1.DajUgao(1), ugao2=t1.DajUgao(2), ugao3=t1.DajUgao(3), ugao11=t2.DajUgao(1), ugao22=t2.DajUgao(2), ugao33=t2.DajUgao(3);
  if(  (!Trougao::Poredi(ugao1, ugao11) && !Trougao::Poredi(ugao1,ugao22) && !Trougao::Poredi(ugao1, ugao33)) || (!Trougao::Poredi(ugao2, ugao11) && !Trougao::Poredi(ugao2, ugao22) && !Trougao::Poredi(ugao2, ugao33)) || (!Trougao::Poredi(ugao3, ugao11) && !Trougao::Poredi(ugao3, ugao22) && !Trougao::Poredi(ugao3, ugao33)) ) return false;        
    
    if( !Trougao::Poredi((t1.DajStranicu(1)/t2.DajStranicu(1)),(t1.DajStranicu(2)/t2.DajStranicu(2))) || !Trougao::Poredi((t1.DajStranicu(2)/t2.DajStranicu(2)),(t1.DajStranicu(3)/t2.DajStranicu(3))) || !Trougao::Poredi((t1.DajStranicu(3)/t2.DajStranicu(3)),(t1.DajStranicu(1)/t2.DajStranicu(1))) ) return false;
    return true;
}

int main ()
{
    int n;
    std::cout<<"Unesite n: ";
    std::cin>>n;
    try {
        std::vector<std::shared_ptr<Trougao>> Trouglovi(n);
        for(int i=0; i<n; i++) {
            Tacka t1, t2, t3;
            std::cout<<"Unesite podatke za trougao"<<i+1<<": ";
            std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
            try {
                Trouglovi[i]=std::make_shared<Trougao>(Trougao(t1,t2,t3));
            } catch(...) {
                std::cout<<"Neuspjelo, ponovo.";
                i--;
                continue;
            }
        }
        for(int i=0; i<n; i++) {
            Trouglovi[i]->Ispisi();
            std::cout<<std::endl;
        }
    } catch(...) {
        std::cout<<"Memorija..";
    }
    double x;
    Tacka t1,t2,t3; std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
    Trougao t(t1, t2, t3);
    x=t.DajUgao(1); std::cout<<std::endl<<x;
    t.Skaliraj(t2, 0);
    // int a=0;
    // std::cout<<a;
    return 0;
}