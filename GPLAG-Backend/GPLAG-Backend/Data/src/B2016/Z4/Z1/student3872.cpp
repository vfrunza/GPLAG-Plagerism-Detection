/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<vector>
#include<list>
#include<iomanip>
#include<stdexcept>
#include<algorithm>
#include<string>
#include<utility>
#include<cmath>
#include<memory>
using namespace std;
typedef pair<double, double> Tacka;
class Trougao
{
  Tacka t_1, t_2, t_3;
public:
//copy-paste iz postavke zadaće
static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3)
{
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}
Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3)
{
    int test=Orijentacija(t1, t2, t3); if(test==0) throw domain_error("Nekorektne pozicije tjemena");
    t_1=t1;
    t_2=t2;
    t_3=t3;
}

void Postavi(const Tacka &t1, const Tacka &t2,const Tacka &t3)
{
    int test=Orijentacija(t1, t2, t3); if(test==0) throw domain_error("Nekorektne pozicije tjemena");
    t_1=t1; t_2=t2; t_3=t3;
}
void Postavi(int indeks,const Tacka &t)
{
    
    if(indeks<1 && indeks>3) throw range_error("Nekorektan indeks");
    if(indeks==1) t_1=t; else if(indeks==2) t_2=t; else t_3=t;
    int test=Orijentacija(t_1, t_2, t_3); if(test==0) throw domain_error("Nekorektne pozicije tjemena");
}
Tacka DajTjeme(int indeks)const
{
    if(indeks<1 && indeks>3) throw range_error("Nekorektan indeks");
     if(indeks==1) return t_1; else if(indeks==2) return t_2; else return t_3;
}

double DajStranicu(int indeks) const;
double DajUgao(int indeks) const;
Tacka DajCentar() const;
double DajObim()const;
double DajPovrsinu() const;
 bool DaLiJePozitivnoOrijentiran() const;
bool DaLiJeUnutra(const Tacka &t) const; 
void Ispisi() const
{
    cout<<"(("<<t_1.first<<","<<t_1.second<<"),("<<t_2.first<<","<<t_2.second<<"),("<<t_3.first<<","<<t_3.second<<"))";
} 

void Transliraj(double delta_x, double delta_y); 

void Centriraj(const Tacka &t);
void Rotiraj(const Tacka &t,double ugao);
void Skaliraj(const Tacka &t,double faktor ); 
void Rotiraj(double ugao);
void Skaliraj(double faktor); 
friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao&t1,const Trougao &t2);
};


double Trougao::DajStranicu(int indeks) const 
{
    if(indeks>3 && indeks<1) throw range_error("Nekorektan indeks");
    double stranica(0);
    if(indeks==1) stranica=sqrt((t_1.first-t_2.first)*(t_1.first-t_2.first)+(t_1.second-t_2.second)*(t_1.second-t_2.second));
    else if(indeks==2) stranica=sqrt((t_2.first-t_3.first)*(t_2.first-t_3.first)+(t_2.second-t_3.second)*(t_2.second-t_3.second));
    else if(indeks==3) stranica=sqrt((t_1.first-t_3.first)*(t_1.first-t_3.first)+(t_1.second-t_3.second)*(t_1.second-t_3.second));
    return stranica;
}
double Trougao::DajUgao(int indeks) const
{
    if(indeks>3 && indeks<1) throw range_error("Nekorektan indeks");
    double a=sqrt((t_1.first-t_2.first)*(t_1.first-t_2.first)+(t_1.second-t_2.second)*(t_1.second-t_2.second));
    double b=sqrt((t_2.first-t_3.first)*(t_2.first-t_3.first)+(t_2.second-t_3.second)*(t_2.second-t_3.second));
    double c=sqrt((t_1.first-t_3.first)*(t_1.first-t_3.first)+(t_1.second-t_3.second)*(t_1.second-t_3.second));
   double ugao=0;
   if(indeks==1)
   {
       ugao=acos((b*b+c*c-a*a)/(2*b*c));
       
   }
    else if(indeks==2) ugao=acos((a*a+c*c-b*b)/(2*a*c));
    
    else if(indeks==3) ugao=acos((a*a+b*b-c*c)/(2*a*b));
    return ugao;
}

Tacka Trougao::DajCentar() const
{
    Tacka centar;
    double prvi=t_1.first+t_2.first+t_3.first;
    double drugi=t_1.second+t_2.second+t_3.second;
    prvi/=3;
    drugi/=3;
    centar=make_pair(prvi, drugi);
    return centar;
    
} 
double Trougao::DajObim() const
{
     double a=sqrt((t_1.first-t_2.first)*(t_1.first-t_2.first)+(t_1.second-t_2.second)*(t_1.second-t_2.second));
    double b=sqrt((t_2.first-t_3.first)*(t_2.first-t_3.first)+(t_2.second-t_3.second)*(t_2.second-t_3.second));
    double c=sqrt((t_1.first-t_3.first)*(t_1.first-t_3.first)+(t_1.second-t_3.second)*(t_1.second-t_3.second));
    return a+b+c;
}
double Trougao::DajPovrsinu () const
{
     double a=sqrt((t_1.first-t_2.first)*(t_1.first-t_2.first)+(t_1.second-t_2.second)*(t_1.second-t_2.second));
    double b=sqrt((t_2.first-t_3.first)*(t_2.first-t_3.first)+(t_2.second-t_3.second)*(t_2.second-t_3.second));
    double c=sqrt((t_1.first-t_3.first)*(t_1.first-t_3.first)+(t_1.second-t_3.second)*(t_1.second-t_3.second));
    double s=(a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

bool Trougao::DaLiJePozitivnoOrijentiran ()const
{
    int test=Orijentacija(t_1, t_2, t_3);
    if(test>0) return true;
    return false;

    
}
double Tester(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    return (t1.first-t3.first)*(t2.second-t3.second)-(t2.first-t3.first)*(t1.second-t3.second);
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    bool prvi, drugi, treci;
    prvi=Tester(t, t_1, t_2);
    drugi=Tester(t, t_2, t_3);
    treci=Tester(t, t_3, t_1);
    return ((prvi==drugi)&&(drugi==treci));
}

void Trougao::Transliraj(double delta_x, double delta_y)
{
    t_1.first+=delta_x; t_1.second+=delta_y;
    t_2.first+=delta_x; t_2.second+=delta_y;
    t_3.first+=delta_x; t_3.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t)
{
    Tacka centar=DajCentar();
    centar.first=t.first;
    centar.second=t.second;
    double x=centar.first;
    double y=centar.second;
    
    t_1.first+=x; t_1.second+=y;
    t_2.first+=x; t_2.second+=y;
    t_3.first+=x; t_3.second+=y;
}
 
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    double prvi=t_1.first, drugi=t_2.first, treci=t_3.first;
    if(ugao<0) ugao+=180;
    t_1.first=(t.first+(t_1.first-t.first)*cos(ugao)-(t_1.second-t.second)*sin(ugao));
    t_1.second=(t.second+(prvi-t.first)*sin(ugao)+(t_1.second-t.second)*cos(ugao));
    t_2.first=(t.first+(t_2.first-t.first)*cos(ugao)-(t_2.second-t.second)*sin(ugao));
    t_2.second=(t.second+(drugi-t.first)*sin(ugao)+(t_2.second-t.second)*cos(ugao));
    t_3.first=(t.first+(t_2.first-t.first)*cos(ugao)-(t_3.second-t.second)*sin(ugao));
    t_3.second=(t.second+(treci-t.first)*sin(ugao)+(t_3.second-t.second)*cos(ugao));
} 

void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(faktor==0) throw domain_error("Nekorektan faktor skaliranja");
    t_1.first=t.first+faktor*(t_1.first-t.first);
    t_1.second=t.second+faktor*(t_1.second-t.second);
    t_2.first=t.first+faktor*(t_2.first-t.first);
    t_2.second=t.second+faktor*(t_2.second-t.second);
    t_3.first=t.first+faktor*(t_3.first-t.first);
    t_3.second=t.second+faktor*(t_3.second-t.second);
 if(faktor<0) Rotiraj(180);
    
}

void Trougao::Rotiraj(double ugao)
{
    if(ugao<0) ugao+=180;
    Tacka centar=DajCentar();
    double prvi=t_1.first, drugi=t_2.first, treci=t_3.first;
    t_1.first=(centar.first+(t_1.first-centar.first)*cos(ugao)-(t_1.second-centar.second)*sin(ugao));
    t_1.second=(centar.second+(prvi-centar.first)*sin(ugao)+(t_1.second-centar.second)*cos(ugao));
    t_2.first=(centar.first+(t_2.first-centar.first)*cos(ugao)-(t_2.second-centar.second)*sin(ugao));
    t_2.second=(centar.second+(drugi-centar.first)*sin(ugao)+(t_2.second-centar.second)*cos(ugao));
    t_3.first=(centar.first+(t_3.first-centar.first)*cos(ugao)-(t_3.second-centar.second)*sin(ugao));
    t_3.second=(centar.second+(treci-centar.first)*sin(ugao)+(t_3.second-centar.second)*cos(ugao));
}
void Trougao::Skaliraj(double faktor)
{
    if(faktor==0) throw domain_error("Nekorektan faktor skaliranja");
    Tacka centar=DajCentar();
    t_1.first=centar.first+faktor*(t_1.first-centar.first);
    t_1.second=centar.second+faktor*(t_1.second-centar.second);
    t_2.first=centar.first+faktor*(t_2.first-centar.first);
    t_2.second=centar.second+faktor*(t_2.second-centar.second);
    t_3.first=centar.first+faktor*(t_3.first-centar.first);
    t_3.second=centar.second+faktor*(t_3.second-centar.second);
    if(faktor<0) Rotiraj(180);
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    double a_1=sqrt((t1.t_1.first-t1.t_2.first)*(t1.t_1.first-t1.t_2.first)+(t1.t_1.second-t1.t_2.second)*(t1.t_1.second-t1.t_2.second));
    double b_1=sqrt((t1.t_3.first-t1.t_2.first)*(t1.t_3.first-t1.t_2.first)+(t1.t_3.second-t1.t_2.second)*(t1.t_3.second-t1.t_2.second));
    double c_1=sqrt((t1.t_1.first-t1.t_3.first)*(t1.t_1.first-t1.t_3.first)+(t1.t_1.second-t1.t_3.second)*(t1.t_3.second-t1.t_1.second));
double a=sqrt((t2.t_1.first-t2.t_2.first)*(t2.t_1.first-t2.t_2.first)+(t2.t_1.second-t2.t_2.second)*(t2.t_1.second-t1.t_2.second));
    double b=sqrt((t2.t_3.first-t2.t_2.first)*(t2.t_3.first-t2.t_2.first)+(t2.t_3.second-t2.t_2.second)*(t2.t_3.second-t2.t_2.second));
    double c=sqrt((t2.t_1.first-t2.t_3.first)*(t2.t_1.first-t2.t_3.first)+(t2.t_1.second-t2.t_3.second)*(t2.t_3.second-t2.t_1.second));
    vector<double> v1{a_1, b_1, c_1}, v2{a,b,c};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return v1==v2;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
double    a_1=sqrt((t1.t_1.first-t1.t_2.first)*(t1.t_1.first-t1.t_2.first)+(t1.t_1.second-t1.t_2.second)*(t1.t_1.second-t1.t_2.second));
    double b_1=sqrt((t1.t_3.first-t1.t_2.first)*(t1.t_3.first-t1.t_2.first)+(t1.t_3.second-t1.t_2.second)*(t1.t_3.second-t1.t_2.second));
    double c_1=sqrt((t1.t_1.first-t1.t_3.first)*(t1.t_1.first-t1.t_3.first)+(t1.t_1.second-t1.t_3.second)*(t1.t_3.second-t1.t_1.second));
double a_2=sqrt((t2.t_1.first-t2.t_2.first)*(t2.t_1.first-t2.t_2.first)+(t2.t_1.second-t2.t_2.second)*(t2.t_1.second-t1.t_2.second));
    double b_2=sqrt((t2.t_3.first-t2.t_2.first)*(t2.t_3.first-t2.t_2.first)+(t2.t_3.second-t2.t_2.second)*(t2.t_3.second-t2.t_2.second));
    double c_2=sqrt((t2.t_1.first-t2.t_3.first)*(t2.t_1.first-t2.t_3.first)+(t2.t_3.second-t2.t_1.second)*(t2.t_3.second-t2.t_1.second));
    vector<double> v1{a_1, b_1, c_1}, v2{a_2,b_2,c_2};
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    double epsilon=(1e-10);
    double a(v1[0]/v2[0]), b(v1[1]/v2[1]), c(v1[2]/v2[2]);
    return(a>=(b-epsilon) &&a<=(b+epsilon) && b>=(c-epsilon) && b<=(c+epsilon));
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
   
   Tacka prva(t1.t_1), druga(t1.t_2), treca(t1.t_3);
   Tacka nova(t2.t_1), nov(t2.t_2), no(t2.t_3);
   if((prva==nova || prva==nov || prva==no) && (druga==nova || druga==nov || druga==no) && (treca==nova || treca==nov || treca==no))
   return true;
   return false;
}
bool DaLiJeUVektoru(vector<std::pair<Trougao,Trougao>> trouglovi, pair<Trougao,Trougao> par)
{
    for(int i=0;i<(int)trouglovi.size();i++)
    {
        if((DaLiSuIdenticni(trouglovi[i].first,par.first) && DaLiSuIdenticni(trouglovi[i].second,par.second)) || (DaLiSuIdenticni(trouglovi[i].first,par.second) && DaLiSuIdenticni(trouglovi[i].second,par.first)) ) return true;
    }
    return false;
}
int main ()
{
    
    int broj_trouglova;
    Tacka prva, druga, treca;
    double a, b, c, d, e, f;
    vector<shared_ptr<Trougao>> Trouglovi;
    cout<<"koliko zelite kreirati trouglova: ";
    cin>>broj_trouglova;
    for(int i=0;i<broj_trouglova;i++)
    {
        cout<<"Unesite podatke za "<<i+1<<". trougao(x1 y1 x2 y2 x3 y3): ";
        cin>>a>>b>>c>>d>>e>>f;
        prva=make_pair(a,b);
        druga=make_pair(c,d);
        treca=make_pair(e,f);
        try
        {
            Trouglovi.emplace_back(make_shared<Trougao>(Trougao(prva, druga, treca)));
        }
        catch(domain_error)
        {
            cout<<"Nekorektne pozicije "<<i<<". ti trougao: ";
            i--;
        }
    }
    double x,y, ugao, faktor;
    cout<<"Unesite vektor translacije (dx dy): ";
    cin>>x>>y;
    cout<<"Unesite ugao rotacije: ";
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    cin>>faktor;
    cout<<"Trouglovi nakon obavljenih transformacija: ";
    vector<shared_ptr<Trougao>> Trouglovi2(broj_trouglova), Trouglovi3(broj_trouglova), Trouglovi4(broj_trouglova);
    transform(Trouglovi.begin(), Trouglovi.end(), Trouglovi2.begin(), [x,y](shared_ptr<Trougao> Trouglovi) { (*Trouglovi).Transliraj(x,y); return Trouglovi;});
    transform(Trouglovi2.begin(), Trouglovi2.end(), Trouglovi3.begin(), [ugao](shared_ptr<Trougao>Trouglovi2) { (*Trouglovi2).Rotiraj((*Trouglovi2).DajCentar(), ugao); return Trouglovi2;});
    transform(Trouglovi3.begin(), Trouglovi3.end(), Trouglovi4.begin(), [faktor](shared_ptr<Trougao> Trouglovi3) { (*Trouglovi3).Skaliraj((*Trouglovi3).DajTjeme(1), faktor); return Trouglovi3;});
    sort(Trouglovi4.begin(), Trouglovi4.end(), [](shared_ptr<Trougao> t1, shared_ptr<Trougao>t2)
    {
        return t1->DajPovrsinu()<t2->DajPovrsinu();
    });
    cout<<endl;
    for_each(Trouglovi4.begin(), Trouglovi4.end(), [](shared_ptr<Trougao>t) { t->Ispisi();
        cout<<endl;
    });
    cout<<"Trougao sa najmanjim obimom: ";
    (*min_element(Trouglovi4.begin(), Trouglovi4.end(), [](shared_ptr<Trougao> t1, shared_ptr<Trougao> t2)
    {
        return t1->DajObim()<t2->DajObim();
    }))->Ispisi();
    
    vector<pair<Trougao, Trougao>> id, po, sl;
    cout<<endl;
    for(int i=0;i<broj_trouglova;i++)
    {
        for(int j=0;j<broj_trouglova;j++)
        {
            if(i!=j)
            {
                if(DaLiSuIdenticni(*Trouglovi4[i], *Trouglovi4[j]))
                {
                    if(!DaLiJeUVektoru(id, make_pair(*Trouglovi4[j], * Trouglovi4[i])))
                    {
                        id.push_back(make_pair(*Trouglovi4[j], *Trouglovi[i]));
                    }
                }
                if(DaLiSuPodudarni(*Trouglovi4[i], *Trouglovi4[i]))
                {
                    if(!DaLiJeUVektoru(po, make_pair(*Trouglovi4[j], *Trouglovi4[i])))
                    po.push_back(make_pair(*Trouglovi4[j], *Trouglovi4[i]));
                }
                if(DaLiSuSlicni(*Trouglovi4[i], *Trouglovi4[j]))
                {
                    if(!DaLiJeUVektoru(sl, make_pair(*Trouglovi4[j], *Trouglovi4[i])))
                    {
                        sl.push_back(make_pair(*Trouglovi4[i], *Trouglovi4[j]));
                }
            }
            
        }
    }
    
        
    }
    
if((int)id.size()!=0)
{
    cout<<"Parovi identicnih trouglova: "<<endl;
    for_each(id.begin(), id.end(), [](pair<Trougao, Trougao> t)
    {
        t.second.Ispisi();
        cout<<" i ";
        t.first.Ispisi();
        cout<<endl;
    });
}
else cout<<"Nema identicnih trouglova!"<<endl;
    
if((int)po.size()!=0)
{
    cout<<"Parovi podudarnih trouglova: "<<endl;
    for_each(po.begin(), po.end(), [](pair<Trougao, Trougao>t) {
        t.second.Ispisi();
        cout<<" i ";
        t.first.Ispisi();
        cout<<endl;
    });
}
else cout<<"Nema podudarnih trouglova!"<<endl;
    if((int)sl.size()!=0)
    {
        cout<<"Parovi slicnih trouglova: "<<endl;
        for_each(sl.begin(), sl.end(), [](pair<Trougao, Trougao>t)
        {
            t.second.Ispisi();
            cout<<" i ";
            t.first.Ispisi();
            cout<<endl;
        });
        
    }
    else cout<<"Nema slicnih trouglova!"<<endl; 
    return 0;
    
    
    
    
    
    
}