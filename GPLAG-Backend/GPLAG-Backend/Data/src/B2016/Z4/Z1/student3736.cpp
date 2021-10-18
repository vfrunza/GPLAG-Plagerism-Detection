/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <map>
#include <stdexcept>
#include <cmath>
#include <vector> 
#include <utility>
#include <memory>
#include <algorithm>
using namespace std;

typedef pair<double, double> Tacka;

class Trougao {
    vector<Tacka> tjemena;
    /*Tacka tjeme1;
    Tacka tjeme2;
    Tacka tjeme3;*/
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) ;
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrjentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t,double faktor);
    void Rotiraj(double ugao);
    void Skaliraj (double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double x1{t1.first}, y1{t1.second};
    double x2{t2.first}, y2{t2.second};
    double x3{t3.first}, y3{t3.second};
    double broj {  x1*(y2-y3) - x2*(y1-y3) + x3*(y1-y2) };
    if(broj>0)   return 1;
    if(broj<0)   return -1;
    else         return 0;
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if( Orijentacija(t1,t2,t3)==0  )   throw domain_error("Nekorektne pozicije tjemena");
    tjemena.resize(3);
    Postavi(t1,t2,t3);
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    tjemena[0]=t1;
    tjemena[1] = t2;
    tjemena[2] = t3;
}

void Trougao::Postavi(int indeks,const Tacka &t)
{
    if(indeks!=1 && indeks!=2 && indeks!=3)  throw range_error("Nekorektan indeks");
    tjemena[indeks-1] = t;
}

Tacka Trougao::DajTjeme(int indeks)  const
{
    return tjemena[indeks-1];
}

double Trougao::DajStranicu(int indeks)  const
{
    int indeks1 = (indeks+1)%3;
    int indeks2 = (indeks+2)%3;
    if(indeks1==0)  indeks1=3;
    if(indeks2==0)  indeks2=3;
    
    Tacka t1{ DajTjeme( (indeks1) ) };
    Tacka t2{ DajTjeme( (indeks2) ) };
    
    return  sqrt(  pow((t1.first - t2.first),2) + pow( (t1.second-t2.second),2 )  );
}

double Trougao::DajUgao(int indeks) const
{
    int indeks1 = (indeks+1)%3;
    int indeks2 = (indeks+2)%3;
    if(indeks1==0)  indeks1=3;
    if(indeks2==0)  indeks2=3;
    
    double a { DajStranicu(indeks1) };
    double b { DajStranicu(indeks2) };
    double c { DajStranicu(indeks) };
    
    double cosGama = (  pow(a,2) + pow(b,2) - pow(c,2)  ) / (2*a*b);
    return acos(cosGama);
}

Tacka Trougao::DajCentar() const
{
    double x { (tjemena[0].first + tjemena[1].first + tjemena[2].first)/3 };
    double y { (tjemena[0].second + tjemena[1].second + tjemena[2].second) /3 };
    return make_pair(x,y);
}

double Trougao::DajPovrsinu()  const
{
    double x1{ tjemena[0].first }, y1{ tjemena[0].second };
    double x2{ tjemena[1].first }, y2{ tjemena[1].second };
    double x3{ tjemena[2].first }, y3{ tjemena[2].second };
    double broj{ x1*(y2-y3) - x2*(y1-y3) + x3*(y1-y2) };
    return 0.5*abs(broj);
}

bool Trougao::DaLiJePozitivnoOrjentiran()  const
{
    return Orijentacija(tjemena[0],tjemena[1],tjemena[2])==1;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    int orNt{ Orijentacija(tjemena[0],tjemena[1],tjemena[2]) };
    if(Orijentacija(tjemena[0],tjemena[1],t)==0 || Orijentacija(tjemena[1],tjemena[2],t)==0 || Orijentacija(tjemena[2],tjemena[1],t)==0) return 0;
    if( orNt != Orijentacija(tjemena[0],tjemena[1],t)  || orNt != Orijentacija(tjemena[1],tjemena[2],t)  
                      || orNt != Orijentacija(tjemena[2],tjemena[0],t) )   return false;
    return true;
    
}

void Trougao::Ispisi() const
{
    cout<<"(("<<tjemena[0].first<<","<<tjemena[0].second<<"),("<<tjemena[1].first<<","<<tjemena[1].second<<"),("<<tjemena[2].first<<","<<tjemena[2].second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    tjemena[0].first += delta_x;
    tjemena[1].first += delta_x;
    tjemena[2].first += delta_x;
    
    tjemena[0].second += delta_y;
    tjemena[1].second += delta_y;
    tjemena[2].second += delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{
    Tacka teziste { DajCentar() };
    double delta_x { t.first - teziste.first };
    double delta_y { t.second - teziste.second };
    Transliraj(delta_x,delta_y);
}

void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    tjemena[0].first=t.first+(tjemena[0].first-t.first)*cos(ugao)-(tjemena[0].second-t.second)*sin(ugao);
    tjemena[0].second=t.second+(tjemena[0].first-t.first)*sin(ugao)+(tjemena[0].second-t.second)*cos(ugao);
    
    tjemena[1].first=t.first+(tjemena[1].first-t.first)*cos(ugao)-(tjemena[1].second-t.second)*sin(ugao);
    tjemena[1].second=t.second+(tjemena[0].first-t.first)*sin(ugao)+(tjemena[1].second-t.second)*cos(ugao);
    
    tjemena[2].first=t.first+(tjemena[2].first-t.first)*cos(ugao)-(tjemena[2].second-t.second)*sin(ugao);
    tjemena[2].second=t.second+(tjemena[2].first-t.first)*sin(ugao)+(tjemena[2].second-t.second)*cos(ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(faktor==0) throw domain_error("Nekorektan faktor skaliranja");
    tjemena[0].first=t.first+faktor*(tjemena[0].first-t.first);
    tjemena[0].second=t.second+faktor*(tjemena[0].second-t.second);
    
    tjemena[1].first=t.first+faktor*(tjemena[1].first-t.first);
    tjemena[1].second=t.second+faktor*(tjemena[1].second-t.second);
    
    tjemena[2].first=t.first+faktor*(tjemena[2].first-t.first);
    tjemena[2].second=t.second+faktor*(tjemena[2].first-t.second);
}

void Trougao::Rotiraj(double ugao)
{
    Tacka centar{DajCentar()};
    Rotiraj(centar,ugao);
}

void Trougao::Skaliraj(double faktor)
{
    Tacka centar{DajCentar()};
    Skaliraj(centar,faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    if((t1.tjemena[0]==t2.tjemena[0] || t1.tjemena[0]==t2.tjemena[1] || t1.tjemena[0]==t2.tjemena[2]) 
    && (t1.tjemena[1]==t2.tjemena[0] || t1.tjemena[1]==t2.tjemena[1] || t1.tjemena[0]==t2.tjemena[2])
    && (t1.tjemena[2]==t2.tjemena[0] || t1.tjemena[2]==t2.tjemena[1] || t1.tjemena[2]==t2.tjemena[2])) return true;

    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    double a1{t1.DajStranicu(1)};
    double b1{t1.DajStranicu(2)};
    double c1{t1.DajStranicu(3)};
    double a2{t2.DajStranicu(1)};
    double b2{t2.DajStranicu(2)};
    double c2{t2.DajStranicu(3)};
    if(t1.Orijentacija(t1.tjemena[0],t1.tjemena[1],t1.tjemena[2])==t2.Orijentacija(t2.tjemena[0],t2.tjemena[1],t2.tjemena[2])){
        if((a1==a2 || a1==b2 || a1==c2) && (b1==a2 || b1==b2 || b1==c2) && (c1==a2 || c1==b2 || c1==c2))
                return true;
    }
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    if(t1.Orijentacija(t1.tjemena[0],t1.tjemena[1],t1.tjemena[2])!=t2.Orijentacija(t2.tjemena[0],t2.tjemena[1],t2.tjemena[2]))
        return false;
    double alfa1{t1.DajUgao(1)};
    double beta1{t1.DajUgao(2)};
    double gama1{t1.DajUgao(3)};
    double alfa2{t2.DajUgao(1)};
    double beta2{t2.DajUgao(2)};
    double gama2{t2.DajUgao(3)};
    if((alfa1==alfa2 || alfa1==beta2 || alfa1==gama2) && (beta1==alfa1 || beta1==beta2 || beta1==gama2) && (gama1==alfa2 || gama1==beta2 || gama1==gama2))
        return true;
    return false;
}

int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int br_trouglova;
    cin>>br_trouglova;
    vector<shared_ptr<Trougao>> t(br_trouglova);
    
    for(int i=0;i<br_trouglova;i++)
    {
        double broj1,broj2,broj3,broj4,broj5,broj6;
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>broj1>>broj2>>broj3>>broj4>>broj5>>broj6;
        cin.clear();
        Tacka priv1,priv2,priv3;
        priv1=make_pair(broj1,broj2);  priv2=make_pair(broj3,broj4); priv3=make_pair(broj5,broj6);
        try{
            Trougao m(priv1,priv2,priv3);
            t[i]=make_shared<Trougao>(m);
        }
        catch(domain_error e){
            cout<<e.what()<<endl;
            i--;
            continue;
        }
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    cin>>dx>>dy;
    cout<<"Unesite ugao rotacije: ";
    double ugao_r;
    cin>>ugao_r;
    cout<<"Unesite faktor skaliranja: ";
    double fakt_skal;
    cin>>fakt_skal;
        transform(t.begin(),t.end(),t.begin(),[dx,dy]( shared_ptr<Trougao> x)
        {
            x->Transliraj(dx,dy);
        });
        for(int i=0;i<br_trouglova;i++){
        t[i]->Rotiraj(ugao_r);
        t[i]->Skaliraj(fakt_skal);
        }
    //cout<<"Trouglovi nakon obavljenih transformacija:";
    return 0;}