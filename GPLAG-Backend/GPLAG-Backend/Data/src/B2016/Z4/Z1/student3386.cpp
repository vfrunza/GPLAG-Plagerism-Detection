/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>



using std::vector;
using std::cout;
using std::cin;

typedef std::pair<double,double> Tacka;

class Trougao
{
    Tacka tacke[3];
    double Udaljenost(const Tacka &t1,const Tacka &t2)const
    {
        return std::sqrt(((t2.first-t1.first)*(t2.first-t1.first))+((t2.second-t1.second)*(t2.second-t1.second)));
    }
    void TestIndeksa(int a)const
    {
        if(a<1 or a>3)
            throw std::range_error("Nekorektan indeks");
    }
    static double Pomoc(const Tacka &t1,const Tacka &t2,const Tacka &t3)
    {
        return ((t1.first*(t2.second-t3.second))-(t2.first*(t1.second-t3.second))+(t3.first*(t1.second-t2.second)));
    }
    public:
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3)
    {
        double x(Pomoc(t1,t2,t3));
        if(x<0)
            return -1;
        else if(x>0)
            return 1;
        return 0;
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3)
    {
        if(!Orijentacija(t1,t2,t3))
            throw std::domain_error("Nekorektne pozicije tjemena");
        tacke[0]=t1;tacke[1]=t2;tacke[2]=t3;
    }
    void Postavi(int indeks,const Tacka &t)
    {
        TestIndeksa(indeks);
        tacke[indeks-1]=t;
        if(!Orijentacija(tacke[0],tacke[1],tacke[2]))
            throw std::domain_error("Nekorektne pozicije tjemena");
    }
    Trougao (const Tacka &t1,const Tacka &t2,const Tacka &t3)
    {Postavi(t1,t2,t3);}
    Tacka DajTjeme(int indeks)const
    {
        TestIndeksa(indeks);
        return tacke[indeks-1];
    }
    double DajStranicu(int indeks)const
    {
        TestIndeksa(indeks);
        if(indeks==1)
            return Udaljenost(tacke[1],tacke[2]);
        else if(indeks==2)
            return Udaljenost(tacke[0],tacke[2]);
        return Udaljenost(tacke[0],tacke[1]);
    }
    double DajUgao(int indeks)const
    {
        TestIndeksa(indeks);
        double a(DajStranicu(indeks)),b,c;
        if(indeks==1)
            b=DajStranicu(2),c=DajStranicu(3);
        else if(indeks==2)
            b=DajStranicu(1),c=DajStranicu(3);
        else
            b=DajStranicu(1),c=DajStranicu(2);
        return std::acos(((b*b)+(c*c)-(a*a))/(2*b*c));
        
    }
    Tacka DajCentar()const
    {
        return {((tacke[0].first+tacke[1].first+tacke[2].first)/3.),((tacke[0].second+tacke[1].second+tacke[2].second)/3.)};
    }
    double DajObim()const
    {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu()const
    {
        double x(Pomoc(tacke[0],tacke[1],tacke[2]));
        return (std::fabs(x))/2.;
    }
    bool DaLiJePozitivnoOrijentiran()const
    {
        if(Orijentacija(tacke[0],tacke[1],tacke[2])>0)
            return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t)const
    {
        double a(((tacke[1].second-tacke[2].second)*(t.first-tacke[2].first)+(tacke[2].first-tacke[1].first)*(t.first-tacke[2].first))/((tacke[1].second-tacke[2].second)*(tacke[0].first-tacke[2].first)+(tacke[2].first-tacke[1].first)*(tacke[0].second-tacke[2].second)));
        double b(((tacke[2].second-tacke[0].second)*(t.first-tacke[2].first)+(tacke[0].first-tacke[2].first)*(t.first-tacke[2].first))/((tacke[1].second-tacke[2].second)*(tacke[0].first-tacke[2].first)+(tacke[2].first-tacke[1].first)*(tacke[0].second-tacke[2].second)));
        double c(1.0-a-b);
        if(a>0 and b>0 and c>0)
            return true;
        return false;
    }
    void Ispisi()const
    {
        cout<<"(("<<tacke[0].first<<","<<tacke[0].second<<"),("<<tacke[1].first<<","<<tacke[1].second<<"),("<<tacke[2].first<<","<<tacke[2].second<<"))";
    }
    void Transliraj(double delta_x,double delta_y)
    {
        for(int i=0;i<3;i++)
        {
            tacke[i].first+=delta_x;
            tacke[i].second+=delta_y;
        }
    }
    void Centriraj(const Tacka &t)
    {
        Tacka neka=DajCentar();
        Transliraj(t.first-neka.first,t.second-neka.second);
    }
    void Rotiraj(const Tacka &t,double ugao)
    {
        for(int i=0;i<3;i++)
        {
            auto x=t.first+(tacke[i].first-t.first)*std::cos(ugao)-(tacke[i].second-t.second)*std::sin(ugao);
            auto y=t.second+(tacke[i].first-t.first)*std::sin(ugao)+(tacke[i].second-t.second)*std::cos(ugao);
            tacke[i].first=x;
            tacke[i].second=y;
        }
    }
    void Rotiraj(double ugao)
    {
        Rotiraj(DajCentar(),ugao);
    }
    void Skaliraj(const Tacka &t,double faktor)
    {
        if(!faktor)
            throw std::domain_error("Nekorektan faktor skaliranja");
        for(int i=0;i<3;i++)
        {
            auto x(t.first+faktor*(tacke[i].first-t.first));
            tacke[i].first=x;
            x=t.second+faktor*(tacke[i].second-t.second);
            tacke[i].second=x;
        }
    }
    void Skaliraj(double faktor)
    {
        Skaliraj(DajCentar(),faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};
bool Isti(double a,double b)
{
    return std::fabs(a-b)<1E-10;
}
bool Help(const Tacka &t1,const Tacka &t2)
{
    if(Isti(t1.first,t2.first))
        return t1.second<t2.second;
    return t1.first<t2.first;
}
bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2)
{
    vector<Tacka> v1(3),v2(3);
    for(int i=0;i<3;i++)
    {
        v1[i]=t1.tacke[i];
        v2[i]=t2.tacke[i];
    }
    std::sort(v1.begin(),v1.end(),Help);
    std::sort(v2.begin(),v2.end(),Help);
    if(v1==v2)
        return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2)
{
    vector<std::pair<Tacka,double>> v1,v2;
    for(int i=0;i<3;i++)
    {
        v1.push_back({t1.DajTjeme(i+1),t1.DajStranicu(i+1)});
        v2.push_back({t2.DajTjeme(i+1),t2.DajStranicu(i+1)});
    }
    std::sort(v1.begin(),v1.end(),[](const std::pair<Tacka,double> &t1,const std::pair<Tacka,double> &t2){return t1.second<t2.second;});
    std::sort(v2.begin(),v2.end(),[](const std::pair<Tacka,double> &t1,const std::pair<Tacka,double> &t2){return t1.second<t2.second;});
    if(Trougao::Orijentacija(v1[0].first,v1[1].first,v1[2].first)!=Trougao::Orijentacija(v2[0].first,v2[1].first,v2[2].first))
        return false;
    for(int i=0;i<3;i++)
        if(!Isti(v1[i].second,v2[i].second))
            return false;
    return true;
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2)
{
    vector<std::pair<Tacka,double>> v1,v2;
    for(int i=0;i<3;i++)
    {
        v1.push_back({t1.DajTjeme(i+1),t1.DajUgao(i+1)});
        v2.push_back({t2.DajTjeme(i+1),t2.DajUgao(i+1)});
    }
    std::sort(v1.begin(),v1.end(),[](const std::pair<Tacka,double> &t1,const std::pair<Tacka,double> &t2){return t1.second<t2.second;});
    std::sort(v2.begin(),v2.end(),[](const std::pair<Tacka,double> &t1,const std::pair<Tacka,double> &t2){return t1.second<t2.second;});
    if(Trougao::Orijentacija(v1[0].first,v1[1].first,v1[2].first)!=Trougao::Orijentacija(v2[0].first,v2[1].first,v2[2].first))
        return false;
    for(int i=0;i<3;i++)
        if(!Isti(v1[i].second,v2[i].second))
            return false;
    return true;
}
int main ()
{
    typedef std::shared_ptr<Trougao> pamet;
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    cin>>n;
    vector<pamet> v(n);
    for(int i=0;i<n;i++)
    {
        Tacka prva,druga,treca;
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>prva.first>>prva.second>>druga.first>>druga.second>>treca.first>>treca.second;
        try
        {
            v[i]=std::make_shared<Trougao>(Trougao(prva,druga,treca));
        }
        catch(std::domain_error e)
        {
            cout<<e.what()<<", ponovite unos!\n";
            i--;
            continue;
        }
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    cin>>dx>>dy;
    cout<<"Unesite ugao rotacije: ";
    double ugao;
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    double faktor;
    cin>>faktor;
    std::transform(v.begin(),v.end(),v.begin(),[dx,dy,ugao,faktor](pamet p)
    {
        p->Transliraj(dx,dy);
        p->Rotiraj(ugao);
        p->Skaliraj(p->DajTjeme(1),faktor);
        return p;
    });
    std::sort(v.begin(),v.end(),[](pamet p1,pamet p2)
    {
        return p1->DajPovrsinu()<p2->DajPovrsinu();
    });
    cout<<"Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(v.begin(),v.end(),[](pamet p)
    {
        p->Ispisi();
        cout<<"\n";
    });
    auto k(std::min_element(v.begin(),v.end(),[](pamet p1,pamet p2){return p1->DajObim()<p2->DajObim();}));
    cout<<"Trougao sa najmanjim obimom: ";
    if(k==v.end());
    else
        (*k)->Ispisi();
    cout<<"\n";
    vector<std::pair<pamet,pamet>> pomoc;
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
            if(DaLiSuIdenticni(*v[i],*v[j]))
                pomoc.push_back({v[i],v[j]});
    if(pomoc.empty() or v.size()<2)
        cout<<"Nema identicnih trouglova!\n";
    else
    {
        cout<<"Parovi identicnih trouglova:\n";
        for(int i=0;i<pomoc.size();i++)
        {
            pomoc[i].first->Ispisi();
            cout<<" i ";
            pomoc[i].second->Ispisi();
            cout<<"\n";
        }
    }
    pomoc.resize(0);
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
            if(DaLiSuPodudarni(*v[i],*v[j]))
                pomoc.push_back({v[i],v[j]});
    if(pomoc.empty() or v.size()<2)
        cout<<"Nema podudarnih trouglova!\n";
    else
    {
        cout<<"Parovi podudarnih trouglova:\n";
        for(int i=0;i<pomoc.size();i++)
        {
            pomoc[i].first->Ispisi();
            cout<<" i ";
            pomoc[i].second->Ispisi();
            cout<<"\n";
        }
    }
    pomoc.resize(0);
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
            if(DaLiSuSlicni(*v[i],*v[j]))
                pomoc.push_back({v[i],v[j]});
    if(pomoc.empty() or v.size()<2)
        cout<<"Nema slicnih trouglova!\n";
    else
    {
        cout<<"Parovi slicnih trouglova:\n";
        for(int i=0;i<pomoc.size();i++)
        {
            pomoc[i].first->Ispisi();
            cout<<" i ";
            pomoc[i].second->Ispisi();
            cout<<"\n";
        }
    }
	return 0;
}