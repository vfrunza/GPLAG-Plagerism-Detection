/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;

typedef std::pair<double, double> Tacka;

class Trougao
{
    Tacka A,B,C;
    double pomocna(const Tacka &A,const Tacka &B, const Tacka &C)const
    {
        double povrsina=Orijentacija(A,B,C);
        povrsina=abs(povrsina/2);
        return povrsina;
    }
    public:
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    Postavi(t1,t2,t3);
}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    int orijent= Orijentacija(t1,t2,t3);
    if(orijent==0)
    throw domain_error("Nekorektne pozicije tjemena");
    A=t1;B=t2;C=t3;
}
void Postavi(int indeks, const Tacka &t)
{
    if(indeks==1)
    A=t;
    else if(indeks==2)
    B=t;
    else if(indeks==3)
    C=t;
    else
    throw range_error("Nekorektan idenks");
}
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
  int rez= t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    if(rez>0)
    return 1;
    else if(rez<0)
    return -1;
    return 0;
}
Tacka DajTjeme(int indeks) const
{
    if(indeks==1)
    return A;
    else if(indeks==2)
    return B;
    else if(indeks==3)
    return C;
    else 
    throw range_error("Nekorektan indeks");
}
double DajStranicu(int indeks) const
{
    double a= sqrt((B.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second));
    double b= sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
    double c= sqrt((A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second));
    if(indeks==1)
    return a;
    else if(indeks==2)
    return b;
    else if(indeks==3)
    return c;
    else
    throw range_error("Nekorektan indeks");
}
double DajUgao(int indeks) const
{
    double alfa=(DajStranicu(3)*DajStranicu(3)+DajStranicu(2)*DajStranicu(2)-DajStranicu(1)-DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3));
    double beta=(DajStranicu(3)*DajStranicu(3)+DajStranicu(1)*DajStranicu(1)-DajStranicu(2)-DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3));
    double gama=(DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)-DajStranicu(3))/(2*DajStranicu(2)*DajStranicu(1));
    if(indeks==1)
    return alfa;
    else if(indeks==2)
    return beta;
    else if(indeks==3)
    return gama;
    else throw range_error("Nekorektan indeks");
}
Tacka DajCentar() const
{
    Tacka centar;
    centar.first=(A.first+B.first+C.first)/3;
    centar.second=(A.second+B.second+C.second)/3;
    return centar;
}
double DajObim() const
{
    double obim=DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    return obim;
}
double DajPovrsinu() const
{
    double povrsina=Orijentacija(A,B,C);
    povrsina=abs(povrsina/2);
    return povrsina;
}
bool DaLiJePozitivnoOrijentiran() const
{
    double rez=Orijentacija(A,B,C);
    if(rez>0)
    return true;
    else
    return false;
}
bool DaLiJeUnutra(const Tacka &t) const
{
    double prva=pomocna(A,B,t);
    double druga=pomocna(A,C,t);
    double treca=pomocna(B,C,t);
    if(prva==0 || druga==0 || treca==0)
    return false;
    else if(fabs(DajPovrsinu()-(prva+druga+treca)<0.0000000005))
    return true;
    else return false;
    
}
void Ispisi() const
{
    cout<<"(("<<A.first<<","<<A.second<<"),("<<B.first<<","<<B.second<<"),("<<C.first<<","<<C.second<<"))"<<endl;
}
void Transliraj(double delta_x, double delta_y)
{
    A.first+=delta_x;
    B.first+=delta_x;
    C.first+=delta_x;
    A.second+=delta_y;
    B.second+=delta_y;
    C.second+=delta_y;
}
void Centriraj(const Tacka &t)
{
   Tacka O= DajCentar();
   double x=t.first-O.first;
   double y=t.second-O.second;
   Transliraj(x,y);
    
}
void Rotiraj(const Tacka &t, double ugao)
{   
    double ax=A.first;
    double ay=A.second;
    double bx=B.first;
    double by=B.second;
    double cx=C.first;
    double cy=C.second;
    A.first=(t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao));
    B.first=(t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao));
    C.first=(t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao));
    
    A.second=t.second+(ax-t.first)*sin(ugao)+(ay-t.second)*cos(ugao);
    B.second=t.second+(bx-t.first)*sin(ugao)+(by-t.second)*cos(ugao);
    B.second=t.second+(cx-t.first)*sin(ugao)+(cy-t.second)*cos(ugao);
}
void Skaliraj(const Tacka &t, double faktor)
{
    if(faktor==0)
    throw domain_error("Nekorektan faktor skaliranja");
    else
    {
    A.first=t.first+faktor*(A.first-t.first);
    B.first=t.first+faktor*(B.first-t.first);
    C.first=t.first+faktor*(C.first-t.first);
    
    A.second=t.second+faktor*(A.second-t.second);
    B.second=t.second+faktor*(B.second-t.second);
    C.second=t.second+faktor*(C.second-t.second);
    }
    
}
void Rotiraj(double ugao)
{
    Tacka t=DajCentar();
    Rotiraj(t,ugao);
}
void Skaliraj(double faktor)
{
    Tacka t=DajCentar();
    Skaliraj(t,faktor);
}
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    double a1=t1.DajUgao(1);
    double a2=t1.DajUgao(2);
    double a3=t1.DajUgao(3);
    double b1=t2.DajUgao(1);
    double b2=t2.DajUgao(2);
    double b3=t2.DajUgao(3);
    
    if(a1==b1 || a1==b2 || a1==b3)
        if(a2==b1 || a2==b2 || a3==b3)
            if(a3==b1 || a3==b2 || a3==b3)
            return true;
    
}
};

int main ()
{
    int n;
    
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    vector<shared_ptr<Trougao>>v(n);
    Tacka A,B,C;
    for(int i=0;i<n;i++)
    {
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>A.first>>A.second>>B.first>>B.second>>C.first>>C.second;
        shared_ptr<Trougao>pp(new Trougao(A,B,C));
        v[i]=pp;
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    cin>>dx>>dy;
    cout<<"Unesite ugao rotacije: ";
    double ugao;
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    double skal;
    cin>>skal;
    transform(v.begin(),v.end(),v.begin(),[dx,dy,ugao,skal](shared_ptr<Trougao>pok){
        pok->Transliraj(dx,dy);
        pok->Rotiraj(ugao);
        pok->Skaliraj(pok->DajTjeme(1),skal);
        return pok;
    });
    sort(v.begin(),v.end(),[](shared_ptr<Trougao>E,shared_ptr<Trougao>O){
        return E->DajPovrsinu()<O->DajPovrsinu();
    });
    cout<<"Trouglovi nakon obavljenih transformacija:"<<endl;
    for_each(v.begin(),v.end(), [](shared_ptr<Trougao>pok){
        pok->Ispisi();
    });
    
	return 0;
}