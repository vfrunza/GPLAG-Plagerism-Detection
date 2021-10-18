/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <vector> 
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;

bool I(double x, double y, double Eps = 0.00000001) {
 return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
}

bool I(double x, double y,double z, double Eps = 0.00000001)
{
    return I(x,y)&&I(y,z)&&I(x,z);
}

class Trougao
{
    Tacka tr[3];
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(!Orijentacija(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        tr[0]=t1,tr[1]=t2,tr[2]=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(!Orijentacija(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        tr[0]=t1,tr[1]=t2,tr[2]=t3;
    }
    void Postavi(int indeks, const Tacka &t)
    {
        if(indeks>3||indeks<1)throw std::range_error("Nekorektan indeks");
        if(!Orijentacija(tr[(indeks)%3],tr[(1+indeks)%3],t)) throw std::domain_error("Nekorektne pozicije tjemena");
        tr[indeks-1]=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        double x=t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
        if(fabs(x)<0.000001)return 0;
        return x/fabs(x);
    }
    Tacka DajTjeme(int indeks) const{if(indeks>3||indeks<1)throw std::range_error("Nekorektan indeks");return tr[indeks-1];}
    double DajStranicu(int indeks) const{if(indeks>3||indeks<1)throw std::range_error("Nekorektan indeks");return sqrt((tr[indeks%3].first-tr[(indeks+1)%3].first)*(tr[indeks%3].first-tr[(indeks+1)%3].first)+(tr[indeks%3].second-tr[(indeks+1)%3].second)*(tr[indeks%3].second-tr[(indeks+1)%3].second));}
    double DajUgao(int indeks) const
    {
        if(indeks>3||indeks<1)throw std::range_error("Nekorektan indeks");
        double a=DajStranicu((indeks)%3+1),b=DajStranicu((indeks+1)%3+1),c=DajStranicu(indeks);
        return acos((a*a+b*b-c*c)/(2*a*b));
    }
    Tacka DajCentar() const
    {
        Tacka n;
        n.first=(tr[0].first+tr[1].first+tr[2].first)/3;
        n.second=(tr[0].second+tr[1].second+tr[2].second)/3;
        return n;
    };
    double DajObim() const{return DajStranicu(3)+DajStranicu(1)+DajStranicu(2);}
    double DajPovrsinu() const{return fabs(tr[0].first*(tr[1].second-tr[2].second)+tr[1].first*(tr[2].second-tr[0].second)+tr[2].first*(tr[0].second-tr[1].second));}
    bool DaLiJePozitivnoOrijentiran() const{return Orijentacija(tr[0],tr[1],tr[2])>0;}
    bool DaLiJeUnutra(const Tacka &t) const{return Orijentacija(tr[0],tr[1],tr[2])==Orijentacija(tr[0],tr[1],t)==Orijentacija(tr[1],tr[2],t)==Orijentacija(tr[2],tr[0],t);}
    void Ispisi() const{std::cout << "((" << tr[0].first << "," << tr[0].second << "),("<< tr[1].first << "," << tr[1].second << "),("<< tr[2].first << "," << tr[2].second << "))";}
    void Transliraj(double delta_x, double delta_y)
    {
        tr[0].first+=delta_x;
        tr[1].first+=delta_x;
        tr[2].first+=delta_x;
        tr[0].second+=delta_y;
        tr[1].second+=delta_y;
        tr[2].second+=delta_y;
    }
    void Centriraj(const Tacka &t)
    {
        Tacka c=DajCentar();
        Transliraj(t.first-c.first,t.second-c.second);
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        double xc=t.first,yc=t.second,x,y;
        for(int i=0;i<3;i++)
        {
            x=tr[i].first,y=tr[i].second;
            tr[i].first=xc+cos(ugao)*(x-xc)-sin(ugao)*(y-yc);
            tr[i].second=yc+sin(ugao)*(x-xc)+cos(ugao)*(y-yc);
        }
    }
    void Skaliraj(const Tacka &t, double faktor)
    {
        tr[0].first=t.first+faktor*(tr[0].first-t.first);
        tr[0].second=t.second+faktor*(tr[0].second-t.second);
        tr[1].first=t.first+faktor*(tr[1].first-t.first);
        tr[1].second=t.second+faktor*(tr[1].second-t.second);
        tr[2].first=t.first+faktor*(tr[2].first-t.first);
        tr[2].second=t.second+faktor*(tr[2].second-t.second);
    }
    void Rotiraj(double ugao){Rotiraj(DajCentar(),ugao);}
    void Skaliraj(double faktor){Skaliraj(DajCentar(),faktor);}
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> vt,tvt(n);
    for(int i=0;i<n;i++)
    {
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka x1,x2,x3;
        std::cin >> x1.first >> x1.second >> x2.first >> x2.second >> x3.first >> x3.second;
        try
        {
            std::shared_ptr<Trougao> novi(new Trougao(x1,x2,x3));
            vt.push_back(novi);
        }
        catch(std::domain_error x)
        {
            std::cout << x.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
    Tacka pom;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> pom.first >> pom.second;
    double ug,sk;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ug;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> sk;
    std::transform(vt.begin(),vt.end(),tvt.begin(),[pom,ug,sk](std::shared_ptr<Trougao> n)
    {
        n->Transliraj(pom.first,pom.second);
        n->Rotiraj(ug);
        n->Skaliraj(n->DajTjeme(1),sk);
        return n;
    });
    std::sort(tvt.begin(),tvt.end(),[](std::shared_ptr<Trougao> n1,std::shared_ptr<Trougao> n2){return n1->DajPovrsinu()<n2->DajPovrsinu();});
    std::cout << "Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(tvt.begin(),tvt.end(),[](std::shared_ptr<Trougao> n){n->Ispisi();std::cout << "\n";});
    std::cout << "Trougao sa najmanjim obimom: ";
    auto pok=std::min_element(tvt.begin(),tvt.end(),[](std::shared_ptr<Trougao> n1,std::shared_ptr<Trougao> n2){return n1->DajObim()<n2->DajObim();});
    (*pok)->Ispisi();
    bool id=false,p=false,s=false;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(DaLiSuIdenticni(*tvt[i],*tvt[j]))
            {
                if(!id)
                {
                    std::cout << "\nParovi identicnih trouglova:\n";
                    id=true;
                }
                tvt[i]->Ispisi();
                std::cout << " i ";
                tvt[j]->Ispisi();
                std::cout << "\n";
            }
        }
    }
    if(!id) std::cout << "\nNema identicnih trouglova!\n";
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(DaLiSuPodudarni(*tvt[i],*tvt[j]))
            {
                if(!p)
                {
                    std::cout << "Parovi podudarnih trouglova:\n";
                    p=true;
                }
                tvt[i]->Ispisi();
                std::cout << " i ";
                tvt[j]->Ispisi();
                std::cout << "\n";
            }
        }
    }
    if(!id) std::cout << "Nema podudarnih trouglova!\n";
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(DaLiSuSlicni(*tvt[i],*tvt[j]))
            {
                if(!s)
                {
                    std::cout << "Parovi slicnih trouglova:\n";
                    s=true;
                }
                tvt[i]->Ispisi();
                std::cout << " i ";
                tvt[j]->Ispisi();
                std::cout << "\n";
            }
        }
    }
    if(!id) std::cout << "Nema slicnih trouglova!\n";
	return 0;
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    int a=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            a+=int(I(t1.tr[i].second,t2.tr[j].second) && I(t1.tr[i].first,t2.tr[j].first));
    return a==3;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    if(Trougao::Orijentacija(t1.tr[0],t1.tr[1],t1.tr[2])==Trougao::Orijentacija(t2.tr[0],t2.tr[1],t2.tr[2]))
        return (I(t1.DajStranicu(1),t2.DajStranicu(1))&&I(t1.DajStranicu(2),t2.DajStranicu(2))&&I(t1.DajStranicu(3),t2.DajStranicu(3)))||(I(t1.DajStranicu(1),t2.DajStranicu(2))&&I(t1.DajStranicu(2),t2.DajStranicu(3))&&I(t1.DajStranicu(3),t2.DajStranicu(1)))||(I(t1.DajStranicu(1),t2.DajStranicu(3))&&I(t1.DajStranicu(2),t2.DajStranicu(1))&&I(t1.DajStranicu(3),t2.DajStranicu(2)));
    return (I(t1.DajStranicu(1),t2.DajStranicu(1))&&I(t1.DajStranicu(2),t2.DajStranicu(3))&&I(t1.DajStranicu(3),t2.DajStranicu(2)))||(I(t1.DajStranicu(1),t2.DajStranicu(2))&&I(t1.DajStranicu(2),t2.DajStranicu(1))&&I(t1.DajStranicu(3),t2.DajStranicu(3)))||(I(t1.DajStranicu(1),t2.DajStranicu(3))&&I(t1.DajStranicu(2),t2.DajStranicu(2))&&I(t1.DajStranicu(3),t2.DajStranicu(1)));
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    if(Trougao::Orijentacija(t1.tr[0],t1.tr[1],t1.tr[2])==Trougao::Orijentacija(t2.tr[0],t2.tr[1],t2.tr[2]))
        return (I(t1.DajUgao(1),t2.DajUgao(1))&&I(t1.DajUgao(2),t2.DajUgao(2))&&I(t1.DajUgao(3),t2.DajUgao(3)))||(I(t1.DajUgao(1),t2.DajUgao(2))&&I(t1.DajUgao(2),t2.DajUgao(3))&&I(t1.DajUgao(3),t2.DajUgao(1)))||(I(t1.DajUgao(1),t2.DajUgao(3))&&I(t1.DajUgao(2),t2.DajUgao(1))&&I(t1.DajUgao(3),t2.DajUgao(2)));
    return (I(t1.DajUgao(1),t2.DajUgao(1))&&I(t1.DajUgao(2),t2.DajUgao(3))&&I(t1.DajUgao(3),t2.DajUgao(2)))||(I(t1.DajUgao(1),t2.DajUgao(2))&&I(t1.DajUgao(2),t2.DajUgao(1))&&I(t1.DajUgao(3),t2.DajUgao(3)))||(I(t1.DajUgao(1),t2.DajUgao(3))&&I(t1.DajUgao(2),t2.DajUgao(2))&&I(t1.DajUgao(3),t2.DajUgao(1)));
}