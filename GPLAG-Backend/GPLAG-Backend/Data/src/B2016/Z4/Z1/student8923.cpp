/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <map>
#include <memory>
using std::cin;
using std::cout;
using std::pair;

using std::vector;
using std::map;
const double PI=4*atan(1);
typedef std::pair<double, double> Tacka;
bool JesuLiIsti(double x,double y,double eps=1e-10)
{
    return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
}
class Trougao
{
private:
Tacka tacka1,tacka2,tacka3;
double DajDuzinuStranice(const Tacka &t1,const Tacka &t2) const;
Tacka RotirajTacku(const Tacka &t,const Tacka &tc,double ugao);
bool UporediTacke(const Tacka &t1,const Tacka &t2);
Tacka SkalirajTacku(const Tacka &t,const Tacka &tc,double faktor);
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
bool Trougao::UporediTacke(const Tacka &t1,const Tacka &t2)
{
    if(JesuLiIsti(t1.first,t2.first) && JesuLiIsti(t1.second,t2.second))
    return true;
    return false;
}
Tacka Trougao::SkalirajTacku(const Tacka &t,const Tacka &tc,double faktor)
{
    Tacka pom;
    pom.first=tc.first+faktor*(t.first-tc.first);
    pom.second=tc.second+faktor*(t.second-tc.second);
    return pom;
}
double Trougao::DajDuzinuStranice(const Tacka &t1,const Tacka &t2) const
{
    double izraz;
    izraz=std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    return izraz;
}
Tacka Trougao::RotirajTacku(const Tacka &t,const Tacka &tc,double ugao)
{
    Tacka pom;
  //  ugao=ugao/(PI/180);
    pom.first=(tc.first+(t.first-tc.first)*cos(ugao)-(t.second-tc.second)*sin(ugao));    //provjeriti je li slucajno treba pretvarati iz stepena u radijane ili obrnuto
    pom.second=(tc.second+(t.first-tc.first)*sin(ugao)+(t.second-tc.second)*cos(ugao));   // -||-
    return pom;
}
int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3)
{
    double izraz;
    izraz=(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    if(izraz>0)
    return 1;
    if(izraz<0)
    return -1;
    return 0;
}
Trougao::Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3)
{
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::tacka1=t1;
    Trougao::tacka2=t2;
    Trougao::tacka3=t3;
}
void Trougao::Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3)
{
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::tacka1=t1;
    Trougao::tacka2=t2;
    Trougao::tacka3=t3;
}
void Trougao::Postavi(int indeks,const Tacka &t)
{
    if(indeks!=1 && indeks!=2 && indeks!=3)
    throw std::range_error("Nekorektan indeks");
    if(indeks==1)
    {
    if(Orijentacija(t,tacka2,tacka3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::tacka1=t;
    }
    if(indeks==2)
    {
    if(Orijentacija(tacka1,t,tacka3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::tacka2=t;
    }
    if(indeks==3)
    {
    if(Orijentacija(tacka1,tacka2,t)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::tacka3=t;
    }
}
Tacka Trougao::DajTjeme(int indeks) const
{
Tacka pom;
  if(indeks==1) pom=Trougao::tacka1; 
  if(indeks==2) pom=Trougao::tacka2; 
  if(indeks==3) pom=Trougao::tacka3;  
  return pom;
}
double Trougao::DajStranicu(int indeks) const
{
    double duzina(0);
    if(indeks==1)
    duzina=std::sqrt((Trougao::tacka2.first-Trougao::tacka3.first)*(Trougao::tacka2.first-Trougao::tacka3.first)+(Trougao::tacka2.second-Trougao::tacka3.second)*(Trougao::tacka2.second-Trougao::tacka3.second));
    if(indeks==2)
    duzina=std::sqrt((Trougao::tacka1.first-Trougao::tacka3.first)*(Trougao::tacka1.first-Trougao::tacka3.first)+(Trougao::tacka1.second-Trougao::tacka3.second)*(Trougao::tacka1.second-Trougao::tacka3.second));
    if(indeks==3)
    duzina=std::sqrt((Trougao::tacka2.first-Trougao::tacka1.first)*(Trougao::tacka2.first-Trougao::tacka1.first)+(Trougao::tacka2.second-Trougao::tacka1.second)*(Trougao::tacka2.second-Trougao::tacka1.second));
    return duzina;
}
double Trougao::DajUgao(int indeks) const
{
   double a,b,c;
   a=DajDuzinuStranice(Trougao::tacka2,Trougao::tacka3);
   b=DajDuzinuStranice(Trougao::tacka1,Trougao::tacka3);
   c=DajDuzinuStranice(Trougao::tacka1,Trougao::tacka2);
   double ugao(0);
   if(indeks==1)
   ugao=acos((b*b+c*c-a*a)/(2*b*c));
   if(indeks==2)
   ugao=acos((c*c+a*a-b*b)/(2*a*c));
   if(indeks==3)
   ugao=acos((a*a+b*b-c*c)/(2*a*b));
   ugao*=(PI/180);
   return ugao;
}
double Trougao::DajPovrsinu() const
{
    double izraz;
    izraz=std::fabs(Trougao::tacka1.first*(Trougao::tacka2.second-Trougao::tacka3.second)-Trougao::tacka2.first*(Trougao::tacka1.second-Trougao::tacka3.second)+Trougao::tacka3.first*(Trougao::tacka1.second-Trougao::tacka2.second));
    return izraz;
}
double Trougao::DajObim() const
{
   double a,b,c;
   a=DajDuzinuStranice(Trougao::tacka2,Trougao::tacka3);
   b=DajDuzinuStranice(Trougao::tacka1,Trougao::tacka3);
   c=DajDuzinuStranice(Trougao::tacka1,Trougao::tacka2);
   double obim;
   obim=a+b+c;
   return obim;
}
Tacka Trougao::DajCentar() const
{
    Tacka pom;
    pom.first=(Trougao::tacka1.first+Trougao::tacka2.first+Trougao::tacka3.first)/3;
    pom.second=(Trougao::tacka1.second+Trougao::tacka2.second+Trougao::tacka3.second)/3;
    return pom;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    double izraz;
    izraz=(Trougao::tacka1.first*(Trougao::tacka2.second-Trougao::tacka3.second)-Trougao::tacka2.first*(Trougao::tacka1.second-Trougao::tacka3.second)+Trougao::tacka3.first*(Trougao::tacka1.second-Trougao::tacka2.second));
    if(izraz>0)
    return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    double orijentacija;
    orijentacija=Orijentacija(tacka1,tacka2,tacka3);
    bool pom;
    if(orijentacija>0)
    pom=true;
    else
    pom=false;
    if(pom==Orijentacija(tacka1,tacka2,t) && pom==Orijentacija(tacka2,tacka3,t) && pom==Orijentacija(tacka3,tacka1,t) && !JesuLiIsti(orijentacija,0))
    return true;
    return false;
}

void Trougao::Ispisi() const
{
    cout<<"(("<<tacka1.first<<","<<tacka1.second<<"),("<<tacka2.first<<","<<tacka2.second<<"),("<<tacka3.first<<","<<tacka3.second<<"))";
}
void Trougao::Transliraj(double delta_x,double delta_y)
{
    Trougao::tacka1.first+=delta_x;
    Trougao::tacka2.first+=delta_x;
    Trougao::tacka3.first+=delta_x;
    Trougao::tacka1.second+=delta_y;
    Trougao::tacka2.second+=delta_y;
    Trougao::tacka3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t)
{
    double delta_x,delta_y;
    Tacka teziste;
    teziste=(*this).DajCentar();
    delta_x=t.first-teziste.first;
    delta_y=t.second-teziste.second;
    (*this).Transliraj(delta_x,delta_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    tacka1=RotirajTacku(tacka1,t,ugao);
    tacka2=RotirajTacku(tacka2,t,ugao);
    tacka3=RotirajTacku(tacka3,t,ugao);
}
void Trougao::Rotiraj(double ugao)
{
    Tacka t;
    t=(*this).DajCentar();
    (*this).Rotiraj(t,ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(JesuLiIsti(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
   Trougao::tacka1=SkalirajTacku(tacka1,t,faktor);
   Trougao::tacka2=SkalirajTacku(tacka2,t,faktor);
   Trougao::tacka3=SkalirajTacku(tacka3,t,faktor);
   
}
void Trougao::Skaliraj(double faktor)
{
    if(JesuLiIsti(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka t;
    t=(*this).DajCentar();
   Trougao::tacka1=SkalirajTacku(tacka1,t,faktor);
   Trougao::tacka2=SkalirajTacku(tacka2,t,faktor);
   Trougao::tacka3=SkalirajTacku(tacka3,t,faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    std::multimap<double,double> map1,map2;
    map1.insert(t1.tacka1);
    map1.insert(t1.tacka2);
    map1.insert(t1.tacka3);
    map2.insert(t2.tacka1);
    map2.insert(t2.tacka2);
    map2.insert(t2.tacka3);
    auto it1=map1.begin();
    auto it2=map2.begin();
    int brojac(0);
    while(it1!=map1.end() && it2!=map2.end())
    {
        if(JesuLiIsti(it1->first,it2->first) && JesuLiIsti(it1->second,it2->second))
        brojac++;
        it1++;
        it2++;
    }
    if(brojac==3)
    return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    double a1,b1,c1,a2,b2,c2;
    a1=t1.DajStranicu(3);
    b1=t1.DajStranicu(1);
    c1=t1.DajStranicu(2);
    a2=t2.DajStranicu(3);
    b2=t2.DajStranicu(1);
    c2=t2.DajStranicu(2);
    vector<double> vek1;
    vector<double> vek2;
    vek1.push_back(a1);
    vek1.push_back(b1);
    vek1.push_back(c1);
    vek2.push_back(a2);
    vek2.push_back(b2);
    vek2.push_back(c2);
    std::sort(vek1.begin(),vek1.end());
    std::sort(vek2.begin(),vek2.end());
    if(vek1!=vek2)
    return false;
    if(JesuLiIsti(a1,b1) || JesuLiIsti(a1,c1) || JesuLiIsti(b1,c1)) return  true; //jednakokraki(ili jednakostranicni)-sigurni podudaran sa trouglom istih stranica
    Tacka t1a,t1b,t1c,t2a,t2b,t2c;
    if(a1>b1 && a1>c1)
    {
    t1a=t1.tacka3;
    if(b1>c1)
    {
        t1b=t1.tacka1;
        t1c=t1.tacka2;
    }
    else
    {
        t1b=t1.tacka2;
        t1c=t1.tacka1;
    }
    }
    if(b1>a1 && b1>c1)
    {
    t1a=t1.tacka1;
    if(a1>c1)
    {
        t1b=t1.tacka3;
        t1c=t1.tacka2;
    }
    else
    {
        t1b=t1.tacka2;
        t1c=t1.tacka3;
    }
    }
    if(c1>a1 && c1>b1)
    {
    t1a=t1.tacka2;
    if(a1>b1)
    {
        t1b=t1.tacka3;
        t1c=t1.tacka1;
    }
    else
    {
        t1b=t1.tacka1;
        t1c=t1.tacka3;
    }
    }
    if(a2>b2 && a2>c2)
    {
        t2a=t2.tacka3;
        if(b2>c2)
        {
            t2b=t2.tacka1;
            t2c=t2.tacka2;
        }
        else
        {
            t2b=t2.tacka2;
            t2c=t2.tacka1;
        }
    }
    if(b2>a2 && b2>c2)
    {
        t2a=t2.tacka1;
        if(a2>c2)
        {
            t2b=t2.tacka3;
            t2c=t2.tacka2;
        }
        else
        {
            t2b=t2.tacka2;
            t2c=t2.tacka3;
        }
    }
    if(c2>a2 && c2>b2)
    {
        t2a=t2.tacka2;
        if(a2>b2)
        {
            t2b=t2.tacka3;
            t2c=t2.tacka1;
        }
        else
        {
            t2b=t2.tacka1;
            t2c=t2.tacka3;
        }
    }
    if(Trougao::Orijentacija(t1a,t1b,t1c)==Trougao::Orijentacija(t2a,t2b,t2c))
    return true;
    else
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    double a1,b1,c1,a2,b2,c2;
    a1=t1.DajStranicu(3);
    b1=t1.DajStranicu(1);
    c1=t1.DajStranicu(2);
    a2=t2.DajStranicu(3);
    b2=t2.DajStranicu(1);
    c2=t2.DajStranicu(2);
    vector<double> vek1{a1,b1,c1};
    vector<double> vek2{a2,b2,c2};
    std::sort(vek1.begin(),vek1.end());
    std::sort(vek2.begin(),vek2.end());
    double k1,k2,k3;
    k1=vek1[0]/vek2[0];
    k2=vek1[1]/vek2[1];
    k3=vek1[2]/vek2[2];
    if(!JesuLiIsti(k1,k2) || !JesuLiIsti(k2,k3) || !JesuLiIsti(k1,k3))
    return false;
    Trougao t3(t2.tacka1,t2.tacka2,t2.tacka3);
    t3.Skaliraj(k1);
    if(DaLiSuPodudarni(t1,t3))
    return true;
    return false;
}
int main ()
{
/*Tacka t1a,t1b,t1c,t2a,t2b,t2c;
t1a=std::make_pair(1,1);
t1b=std::make_pair(2,1);
t1c=std::make_pair(1,3);
t2a=std::make_pair(1,1);
t2b=std::make_pair(1.5,1);
t2c=std::make_pair(1,2);
cout<<DaLiSuSlicni(Trougao(t1a,t1b,t1c),Trougao(t2a,t2b,t2c));*/
int n;
cout<<"Koliko zelite kreirati trouglova: ";
cin>>n;
try
{
    vector<std::shared_ptr<Trougao>> vek(n);
    for(int i=0;i<n;i++)
    {
        double t1x,t1y,t2x,t2y,t3x,t3y;
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>t1x>>t1y;
        cin>>t2x>>t2y;
        cin>>t3x>>t3y;
        pair<double,double> tac1,tac2,tac3;
        tac1=std::make_pair(t1x,t1y);
        tac2=std::make_pair(t2x,t2y);
        tac3=std::make_pair(t3x,t3y);
        try
        {
           vek[i]=std::make_shared<Trougao>(Trougao(tac1,tac2,tac3)); 
        }
        catch(std::domain_error izuzetak)
        {
            cout<<izuzetak.what()<<", ponovite unos!" <<std::endl;
            i--;
        }
    }
    if(n!=0)
    {
        cout<<"Unesite vektor translacije (dx dy): ";
        double dx,dy;
        cin>>dx>>dy;
        cout<<"Unesite ugao rotacije: ";
        double alfa;
        cin>>alfa;
        cout<<"Unesite faktor skaliranja: ";
        double f;
        cin>>f;
        if(JesuLiIsti(f,0))
        throw std::domain_error("Nekorektan faktor skaliranja");
        std::transform(vek.begin(),vek.end(),vek.begin(),[=](std::shared_ptr<Trougao> trougao)
        {
           trougao->Trougao::Transliraj(dx,dy);
           trougao->Trougao::Rotiraj(alfa);
           trougao->Trougao::Skaliraj(trougao->Trougao::DajTjeme(1),f);
           return trougao;
        });
    }
        std::sort(vek.begin(),vek.end(),[](std::shared_ptr<Trougao> trougao1,std::shared_ptr<Trougao> trougao2)
        {
            return (trougao1->Trougao::DajPovrsinu()<trougao2->Trougao::DajPovrsinu());
        });
        cout<<"Trouglovi nakon obavljenih transformacija:";
        std::for_each(vek.begin(),vek.end(),[](std::shared_ptr<Trougao> trougao)
        {
            cout<<std::endl;
            trougao->Trougao::Ispisi();
        });
        auto min=std::min_element(vek.begin(),vek.end(),[](std::shared_ptr<Trougao> trougao1,std::shared_ptr<Trougao> trougao2)
        {
            if(trougao1->Trougao::DajObim()<trougao2->Trougao::DajObim())
            return true;
            return false;
        });
        cout<<std::endl;
        if(n!=0)
        {
        cout<<"Trougao sa najmanjim obimom: ";
        (*(min))->Trougao::Ispisi();
        cout<<std::endl;
        }
        bool identicni(false),podudarni(false),slicni(false);
        int brojac1(0),brojac2(0),brojac3(0);
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<vek.size();j++)
            {
                if(DaLiSuIdenticni(*vek[i],*vek[j]))
                {
                    identicni=true;
                    if(brojac1==0)
                    cout<<"Parovi identicnih trouglova:"<<std::endl;
                    vek[i]->Trougao::Ispisi();
                    cout<<" i ";
                    vek[j]->Trougao::Ispisi();
                    cout<<std::endl;
                    brojac1++;
                }
            }
        }
        if(!identicni)
        cout<<"Nema identicnih trouglova!"<<std::endl;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<vek.size();j++)
            {
               if(DaLiSuPodudarni(*vek[i],*vek[j])) 
               {
                   podudarni=true;
                   if(brojac2==0)
                   cout<<"Parovi podudarnih trouglova:"<<std::endl;
                   vek[i]->Trougao::Ispisi();
                   cout<<" i ";
                   vek[j]->Trougao::Ispisi();
                   cout<<std::endl;
                   brojac2++;
               }
            }
        }
        if(!podudarni)
        cout<<"Nema podudarnih trouglova!"<<std::endl;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<vek.size();j++)
            {
                if(DaLiSuSlicni(*vek[i],*vek[j])) 
               {
                   slicni=true;
                   if(brojac3==0)
                   cout<<"Parovi slicnih trouglova:"<<std::endl;
                   vek[i]->Trougao::Ispisi();
                   cout<<" i ";
                   vek[j]->Trougao::Ispisi();
                   cout<<std::endl;
                   brojac3++;
                   
               }
            }
        }
        if(!slicni)
        cout<<"Nema slicnih trouglova!";
}
catch(std::domain_error izuzetak)
{
    cout<<izuzetak.what();
    
}
catch(...)
{
    cout<<"Problemi sa memorijom.";
}
	return 0;
}