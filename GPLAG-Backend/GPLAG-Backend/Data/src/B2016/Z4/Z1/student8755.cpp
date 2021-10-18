/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <memory>
typedef std::pair<double,double> Tacka;
const double eps(1E-10);
class Trougao
{
    Tacka niz[3];
    static double Determinanta(const Tacka &t1, const Tacka &t2, const Tacka &t3) {return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);}
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);    //iskoristi f-iju Orijentacija
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi(int indeks, const Tacka &t);   //indeks: 1, 2, 3!
        static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3);
        Tacka DajTjeme(int indeks) const{if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks"); return niz[indeks-1];}
        double DajStranicu(int indeks) const;
        double DajUgao(int indeks) const;
        Tacka DajCentar() const {return std::make_pair((niz[0].first+ niz[1].first+niz[2].first)/3,(niz[0].second + niz[1].second + niz[2].second)/3);}
        double DajObim() const {return this->DajStranicu(1)+this->DajStranicu(2)+this->DajStranicu(3);}
        double DajPovrsinu() const {return std::fabs(this->Determinanta(niz[0],niz[1],niz[2]))/2;}
        bool DaLiJePozitivnoOrijentiran() const {return (Orijentacija(niz[0], niz[1], niz[2])==1);}
        bool DaLiJeUnutra(const Tacka &t) const {return (Orijentacija(niz[0], niz[1], niz[2]) == Orijentacija(niz[0], niz[1], t) && Orijentacija(niz[1], niz[2], t) == Orijentacija(niz[2], niz[0], t) && Orijentacija(niz[0], niz[1], t) && Orijentacija(niz[2], niz[1], t)); }//orijentacija !=0
        void Ispisi() const{std::cout<<"(("<<niz[0].first<<","<<niz[0].second<<"),("<<niz[1].first<<","<<niz[1].second<<"),("<<niz[2].first<<","<<niz[2].second<<"))";}
        void Transliraj(double delta_x, double delta_y);
        void Centriraj(const Tacka &t){this->Transliraj(t.first-this->DajCentar().first, t.second-this->DajCentar().second);}
        void Rotiraj(const Tacka &t, double ugao);
        void Skaliraj(const Tacka &t, double faktor);
        void Rotiraj(double ugao){this->Rotiraj(this->DajCentar(), ugao);}
        void Skaliraj(double faktor){this->Skaliraj(this->DajCentar(), faktor);}
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
    
};
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(!this->Orijentacija(t1,t2,t3))   throw std::domain_error("Nekorektne pozicije tjemena");
    else{ niz[0]=t1; niz[1]=t2; niz[2]=t3;}
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(!this->Orijentacija(t1,t2,t3))   throw std::domain_error("Nekorektne pozicije tjemena");
    else{ niz[0]=t1; niz[1]=t2; niz[2]=t3;}
}
void Trougao::Postavi(int indeks, const Tacka &t1)
{
    if(!this->Orijentacija(niz[0],niz[1],niz[2]))   throw std::domain_error("Nekorektne pozicije tjemena");
    if(indeks<1 || indeks>3)    throw std::range_error("Nekorektan indeks");
    else niz[indeks-1]=t1;
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    double temp(Determinanta(t1,t2,t3));
    if(temp) return temp/fabs(temp);
    else return 0;
}
double Trougao::DajStranicu(int indeks) const
{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    double x,y;
    indeks--;
    bool DaLiJePrvaTacka(true);
    for(int i=0; i<3; i++)
    {
        if(i==indeks) continue;
        else if(DaLiJePrvaTacka){ x=niz[i].first; y=niz[i].second; DaLiJePrvaTacka=false;}
        else if(!DaLiJePrvaTacka){ x-=niz[i].first; y-=niz[i].second;}
    }
    return std::sqrt(x*x+y*y);
}
double Trougao::DajUgao(int indeks) const
{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    indeks--;
    double ugao(this->DajStranicu(indeks+1)*this->DajStranicu(indeks+1));
    for(int i=0; i<3; i++)
        if(i!=indeks) ugao-=(this->DajStranicu(i+1)*this->DajStranicu(i+1));
    for(int i=0; i<3; i++)
        if(i!=indeks) ugao/=this->DajStranicu(i+1);
    return std::acos(ugao/(-2.));
}
void Trougao::Transliraj(double delta_x, double delta_y)
{
    for(int i=0; i<3; i++)
    {
        niz[i].first+=delta_x;  niz[i].second+=delta_y;
    }
}
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    double temp;
    for(int i=0; i<3; i++)
    {
        temp=t.first+(niz[i].first-t.first)*std::cos(ugao)-(niz[i].second-t.second)*std::sin(ugao);
        niz[i].second=t.second+(niz[i].first-t.first)*std::sin(ugao)+(niz[i].second-t.second)*std::cos(ugao);
        niz[i].first=temp;
    }
}
void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(std::fabs(faktor)<eps)   throw std::domain_error("Nekorektan faktor skaliranja");
    for(int i=0; i<3; i++)
    {
        niz[i].first=t.first+faktor*(niz[i].first-t.first);
        niz[i].second=t.second+faktor*(niz[i].second-t.second);
    }
    if(faktor<0) this->Rotiraj(t,std::atan(1)*4);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    int br(0);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            if(t1.niz[i]==t2.niz[j])
            {   
                br++;
                break;
            }
        }
    return br==3;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    Trougao temp(t2);
    std::vector<Tacka> v;
    int br(0);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(std::fabs(t1.DajUgao(i+1)-t2.DajUgao(j+1)<eps) && std::fabs(t1.DajStranicu(i+1)-t2.DajStranicu(j+1))<eps)
            {   
                v.push_back(t2.niz[j]);
                br++;
                break;
            }
    if(br==3)   temp.Postavi(v[0], v[1], v[2]);
    return (br==3 && t1.DaLiJePozitivnoOrijentiran() == temp.DaLiJePozitivnoOrijentiran());
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    Trougao temp(t2);
    std::vector<Tacka> v;
    int br(0);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            if(std::fabs(t1.DajUgao(i+1)-t2.DajUgao(j+1))<eps)
            {
                v.push_back(t2.niz[j]);
                br++;
                break;
            }
    if(br==3)   temp.Postavi(v[0], v[1], v[2]);
    return (br==3 && t1.DaLiJePozitivnoOrijentiran()==temp.DaLiJePozitivnoOrijentiran());
    
}
int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v_pok(n, nullptr);
    for(int i=0; i<n; i++)
    {
        double x1,y1, x2, y2, x3, y3;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Tacka t1(std::make_pair(x1,y1)), t2(std::make_pair(x2,y2)), t3(std::make_pair(x3,y3));
        try
        {
            v_pok[i]=std::shared_ptr<Trougao>(new Trougao(t1,t2,t3));
        }
        catch(std::domain_error izuzetak)
        {
            std::cout<<izuzetak.what()<<", ponovite unos!"<< std::endl;
            i--;
        }
    }
    
    //za translaciju
    int delta_x, delta_y;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>delta_x>>delta_y;
    //std::transform(v_pok.begin(), v_pok.end(), v_pok.begin(), [delta_x, delta_y](Trougao &*t)->void{t->Transliraj(delta_x, delta_y);});
    //za rotaciju
    int ugao;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    //std::transform(v_pok.begin(), v_pok.end(), v_pok.begin(), [ugao](Trougao *&t)->void{t->Rotiraj(ugao);});
    //za skaliranje
    int faktor;
    std::cout<<"Unesite faktor skaliranja: ";
    try
    {
        std::cin>>faktor;
    }
    catch(std::domain_error izuzetak)
    {
        std::cout<<izuzetak.what();
    }
    std::transform(v_pok.begin(), v_pok.end(), v_pok.begin(), [delta_x, delta_y, ugao, faktor](std::shared_ptr<Trougao>t)->std::shared_ptr<Trougao>{t->Transliraj(delta_x, delta_y); t->Rotiraj(ugao); t->Skaliraj(t->DajTjeme(1),faktor); return t;});
    std::sort(v_pok.begin(), v_pok.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2)->bool{return t1->DajPovrsinu()<t2->DajPovrsinu();});
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(v_pok.begin(), v_pok.end(), [](std::shared_ptr<Trougao>t)->void{t->Ispisi(); std::cout<<std::endl;});
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto temp(*std::min_element(v_pok.begin(), v_pok.end(), [](const std::shared_ptr<Trougao>t1, const std::shared_ptr<Trougao>t2)->bool{return t1->DajObim()<t2->DajObim();}));
    temp->Ispisi();
    std::cout<<std::endl;
    bool postoji(false);
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(DaLiSuIdenticni(*v_pok[i],*v_pok[j]))
            {
                if(!postoji) std::cout<<"Parovi identicnih trouglova:"<<std::endl;
                v_pok[i]->Ispisi();
                std::cout<<" i ";
                v_pok[j]->Ispisi();
                std::cout<<std::endl;
                postoji=true;
            }
    if(!postoji) std::cout<<"Nema identicnih trouglova!"<<std::endl;
    postoji=false;
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(DaLiSuPodudarni(*v_pok[i],*v_pok[j]))
            {
                if(!postoji) std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
                v_pok[i]->Ispisi();
                std::cout<<" i ";
                v_pok[j]->Ispisi();
                std::cout<<std::endl;
                postoji=true;
            }
    if(!postoji) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    postoji=false;
    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(DaLiSuSlicni(*v_pok[i],*v_pok[j]))
            {
                if(!postoji) std::cout<<"Parovi slicnih trouglova:"<<std::endl;
                v_pok[i]->Ispisi();
                std::cout<<" i ";
                v_pok[j]->Ispisi();
                std::cout<<std::endl;
                postoji=true;
            }
    if(!postoji) std::cout<<"Nema slicnih trouglova!"<<std::endl;
}