/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double,double>Tacka;
Tacka Tjeme(Tacka &t1,Tacka &t2,Tacka &t3){
    Tacka t;
    t.first=(t1.first+t2.first+t3.first)/3;
    t.second=(t1.second+t2.second+t3.second)/3;
    return t;
}
void TestiranjeIndeksa(int indeks){
    if(indeks<=0 || indeks>3)throw std::range_error("Nekorektan indeks");
}
double Stranica(Tacka t1,Tacka t2){
    return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
}
int TestiranjeOrijentacije(const Tacka&t1,const Tacka&t2,const Tacka&t3){
    int broj(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    return broj;
}
class Trougao{
    Tacka x,y,z;
    static bool DaLiSuJednaki(double x,double y,double EPS=1e-10){
        return std::fabs(x-y)<=EPS*(std::fabs(x)+std::fabs(y));
    }
    public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        x=t1;y=t2;z=t3;
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        x=t1;y=t2;z=t3;
    }
    void Postavi(int indeks,const Tacka &t){
        TestiranjeIndeksa(indeks);
        if(indeks==1){x=t;if(Orijentacija(t,y,z)==0)throw std::domain_error("Nekorektne pozicije tjemena");}
        else if(indeks==2){y=t;if(Orijentacija(x,t,z)==0)throw std::domain_error("Nekorektne pozicije tjemena");}
        else z=t;
        if(Orijentacija(x,y,t)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        
    }
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(TestiranjeOrijentacije(t1,t2,t3)>0)return 1;
        else if(TestiranjeOrijentacije(t1,t2,t3)<0)return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks)const{
        TestiranjeIndeksa(indeks);
        if(indeks==1)return x;
        else if(indeks==2)return y;
        else return z;
    }
    double DajStranicu(int indeks)const{
        TestiranjeIndeksa(indeks);
        if(indeks==1)return Stranica(y,z);
        else if(indeks==2)return Stranica(x,z);
        else return Stranica(x,y);
    }
    double DajUgao(int indeks)const{
        TestiranjeIndeksa(indeks);
        if(indeks==1)return (std::acos((Stranica(x,y)*Stranica(x,y)+Stranica(x,z)*Stranica(x,z)-Stranica(y,z)*Stranica(y,z))/2*Stranica(x,y)*Stranica(x,z)));
        else if(indeks==2)return (std::acos((Stranica(x,y)*Stranica(x,y)+Stranica(y,z)*Stranica(y,z)-Stranica(x,z)*Stranica(x,z))/2*Stranica(x,y)*Stranica(y,z)));
       else return (std::acos((Stranica(x,z)*Stranica(x,z)+Stranica(y,z)*Stranica(y,z)-Stranica(x,y)*Stranica(x,y))/2*Stranica(x,z)*Stranica(y,z)));
    }
    Tacka DajCentar()const{
        Tacka t;
        t.first=(x.first+y.first+z.first)/3;
        t.second=(x.second+y.second+z.second)/3;
        return t;
        
    }
    double DajObim()const{
        return Stranica(x,y)+Stranica(x,z)+Stranica(y,z);
    }
    double DajPovrsinu()const{
        return 1/2.*std::fabs(TestiranjeOrijentacije(x,y,z));
    }
    bool DaLiJePozitivnoOrijentiran()const{
        if(TestiranjeOrijentacije(x,y,z)>0)return true;
        else return false;
    }
    bool DaLiJeUnutra(const Tacka &t)const{
        if(TestiranjeOrijentacije(x,y,t)>0 && TestiranjeOrijentacije(y,z,t)>0 && TestiranjeOrijentacije(x,z,t)>0 &&TestiranjeOrijentacije(x,y,z)>0)return true;
        return false;
    }
    void Ispisi()const{
        std::cout<<"(("<<x.first<<","<<x.second<<"),("<<y.first<<","<<y.second<<"),("<<z.first<<","<<z.second<<"))";
    }
    void Transliraj(double delta_x,double delta_y){
        x.first+=delta_x;
        y.first+=delta_x;
        z.first+=delta_x;
        x.second+=delta_y;
        y.second+=delta_y;
        z.second+=delta_y;
    }
    void Rotiraj(const Tacka &t,double ugao){
        double sinus(std::sin(ugao));
        double kosinus(std::cos(ugao));
        double pomx(x.first);
        double pomy(y.first);
        double pomz(z.first);
        x.first=t.first+(x.first-t.first)*kosinus-(x.second-t.second)*sinus;
        x.second=t.second+(pomx-t.first)*sinus+(x.second-t.second)*kosinus;
        y.first=t.first+(y.first-t.first)*kosinus-(y.second-t.second)*sinus;
        y.second=t.second+(pomy-t.first)*sinus+(y.second-t.second)*kosinus;
        z.first=t.first+(z.first-t.first)*kosinus-(z.second-t.second)*sinus;
        z.second=t.second+(pomz-t.first)*sinus+(z.second-t.second)*kosinus;
    }
    void Skaliraj(const Tacka &t,double faktor){
        if(DaLiSuJednaki(faktor,0))throw std::domain_error("Nekorektan faktor skaliranja");
        x.first=t.first+faktor*(x.first-t.first);
        x.second=t.second+faktor*(x.second-t.second);
        y.first=t.first+faktor*(y.first-t.first);
        y.second=t.second+faktor*(y.second-t.second);
        z.first=t.first+faktor*(z.first-t.first);
        z.second=t.second+faktor*(z.second-t.second);
    }
    void Rotiraj(double ugao){
        double sinus(std::sin(ugao));
        double kosinus(std::cos(ugao));
        Tacka t(Tjeme(x,y,z));
        x.first=t.first+(x.first-t.first)*kosinus-(x.second-t.second)*sinus;
        x.second=t.second+(x.first-t.first)*sinus+(x.first-t.first)*kosinus;
        y.first=t.first+(y.first-t.first)*kosinus-(y.second-t.second)*sinus;
        y.second=t.second+(y.first-t.first)*sinus+(y.first-t.first)*kosinus;
        z.first=t.first+(z.first-t.first)*kosinus-(z.second-t.second)*sinus;
        z.second=t.second+(z.first-t.first)*sinus+(z.first-t.first)*kosinus;
    }
    void Skaliraj(double faktor){
        if(DaLiSuJednaki(faktor,0))throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t(Tjeme(x,y,z));
        x.first=t.first+faktor*(x.first-t.first);
        x.second=t.second+faktor*(x.second-t.second);
        y.first=t.first+faktor*(y.first-t.first);
        y.second=t.second+faktor*(y.second-t.second);
        z.first=t.first+faktor*(z.first-t.first);
        z.second=t.second+faktor*(z.second-t.second);
    }
    void Centriraj(const Tacka &t){
        Tacka sredina(Tjeme(x,y,z));
        double delta1(t.first-sredina.first);
        double delta2(t.second-sredina.second);
        Transliraj(delta1,delta2);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};
    bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
        for(int i(1);i<4;i++){
        Tacka t(t1.DajTjeme(i));
        bool ima(false);
        int br(0);
        for(int j(1);j<4;j++){
            br++;
            if(t==t2.DajTjeme(j)){ima=true;break;}
        }
        if(br==3)return false;
        else continue;
    }
    return true;
}
    bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
        std::vector<std::pair<double, Tacka>> a(3),b(3);
        for(int i(0); i<3; i++)
        {
            a[i]=std::make_pair(t1.DajStranicu(i+1),t1.DajTjeme(i+1));
            b[i]=std::make_pair(t2.DajStranicu(i+1),t2.DajTjeme(i+1));
        }
        std::sort(a.begin(),a.end(),[] (std::pair<double,Tacka> t1, std::pair<double,Tacka> t2) { return t1.first<t2.first; });
        std::sort(b.begin(),b.end(),[] (std::pair<double,Tacka> t1, std::pair<double,Tacka> t2) { return t1.first<t2.first; });
        if(TestiranjeOrijentacije(a[0].second,a[1].second,a[2].second)<=0 || TestiranjeOrijentacije(b[0].second,b[1].second,b[2].second)<=0)
        return false;
        if(Trougao::DaLiSuJednaki(a[0].first,b[0].first)!=true || Trougao::DaLiSuJednaki(a[1].first,b[1].first)!=true || Trougao::DaLiSuJednaki(a[2].first,b[2].first)!=true)
        return false;
        else return false;
    }
    bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
        return false;
    }
int main ()
{   
try{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>>trouglovi(n);
    for(int i(0);i<n;i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka x,y,z;
        std::cin>>x.first>>x.second>>y.first>>y.second>>z.first>>z.second;
        try{
            trouglovi[i]=std::make_shared<Trougao>(x,y,z);
        }
        catch(std::domain_error greska){
            std::cout<<greska.what()<<", ponovite unos!"<<std::endl;
            i--;
    }
}
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double delta1,delta2;
    std::cin>>delta1>>delta2;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
    std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),[ugao,faktor,delta1,delta2](std::shared_ptr<Trougao> pametni)
    {
        pametni->Transliraj(delta1,delta2);
        pametni->Rotiraj(pametni->DajCentar(),ugao);
        pametni->Skaliraj(pametni->DajTjeme(1),faktor);
        return pametni;
    });
    std::sort(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao>pametni1,std::shared_ptr<Trougao>pametni2){
        return pametni1->DajPovrsinu()<pametni2->DajPovrsinu();
    });
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao>pametni){
        pametni->Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto pok(std::min_element(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao>pametni1,std::shared_ptr<Trougao>pametni2){
        return pametni1->DajObim()<pametni2->DajObim();
    }));
    std::shared_ptr<Trougao>bolji(*pok);
    bolji->Ispisi();
    int brojac(0);
    for(int i(0);i<n;i++){
        for(int j(i+1);j<n;j++){
            if(DaLiSuIdenticni(*trouglovi[i],*trouglovi[j])){
                brojac++;
                break;
            }
            if(brojac!=0)break;
        }
    }
    if(brojac==0)std::cout<<std::endl<<"Nema identicnih trouglova!"<<std::endl;
    else{
    std::cout<<"Parovi identicnih trouglova: "<<std::endl;
    for(int i(0);i<n;i++){
        for(int j(i+1);j<n;j++){
            if(DaLiSuIdenticni(*trouglovi[i],*trouglovi[j])){
                trouglovi[i]->Ispisi();
                std::cout<<" i ";
                trouglovi[j]->Ispisi();
                std::cout<<std::endl;
            }
        }
    }
}
    std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    /*std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
        for(int i(0);i<n;i++){
            for(int j(i+1);j<n;j++){
                if(DaLiSuPodudarni(*trouglovi[i],*trouglovi[j])){
                    trouglovi[i]->Ispisi();
                    std::cout<<" i ";
                    trouglovi[i]->Ispisi();
                    std::cout<<std::endl;
                }
            }
        }*/
    std::cout<<"Nema slicnih trouglova!";
   /* std::cout<<"Parovi slicnih trouglova: "<<std::endl;
    for(int i(0);i<n;i++){
        for(int j(i+1);j<n;j++){
            if(DaLiSuSlicni(*trouglovi[i],*trouglovi[j])){
                trouglovi[i]->Ispisi();
                std::cout<<" i ";
                trouglovi[i]->Ispisi();
                std::cout<<std::endl;
            }
        }
    }*/
}
    catch(std::domain_error greska){
        std::cout<<greska.what();
    }
    catch(std::range_error greska){
        std::cout<<greska.what();
    }
    catch(std::bad_alloc){
        std::cout<<"Problemi sa memorijom.";
    }
	return 0;
}