#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double, double> Tacka;
const double epsilon=10E-15;
class Trougao{
    Tacka t1,t2,t3;
    double DajP()const {return 0.5*(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));}
    int Proizvod() const{
        int suma(1);
        suma*=Orijentacija(t1,t2,t3);
        suma*=Orijentacija(t1,t3,t2);
        suma*=Orijentacija(t2,t1,t3);
        suma*=Orijentacija(t2,t3,t1);
        suma*=Orijentacija(t3,t1,t2);
        suma*=Orijentacija(t3,t2,t1);
        return suma;
    }
    int SumaOrijentacija1() const{
        int suma(0);
        suma+=Orijentacija(t1,t2,t3);
        //suma+=Orijentacija(t1,t3,t2);
        suma+=Orijentacija(t2,t1,t3);
        //suma+=Orijentacija(t2,t3,t1);
        //suma+=Orijentacija(t3,t1,t2);
        suma+=Orijentacija(t3,t2,t1);
        return suma;
    }
    int SumaOrijentacija2() const{
        int suma(0);
        suma+=Orijentacija(t1,t2,t3);
        suma+=Orijentacija(t1,t3,t2);
        suma+=Orijentacija(t2,t1,t3);
        suma+=Orijentacija(t2,t3,t1);
        suma+=Orijentacija(t3,t1,t2);
        suma+=Orijentacija(t3,t2,t1);
        return suma;
    }
public:
    static bool Jednako(double a,double b){return std::fabs(a-b)<epsilon;}
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){Postavi(t1,t2,t3);}
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Jednako(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second),0))return 0;
        else if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<0)return -1;
        else return 1;
    }
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const{return std::make_pair((t1.first+t2.first+t3.first)/2.0,(t1.second+t2.second+t3.second)/2.0);}
    double DajObim() const{return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);}
    double DajPovrsinu() const{return 0.5*std::fabs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));}
    bool DaLiJePozitivnoOrijentiran() const{return Orijentacija(t1,t2,t3)==1;}
    bool DaLiJeUnutra(const Tacka &t) const;//popravi
    void Ispisi() const{std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";}
    void Transliraj(double delta_x, double delta_y){t1.first+=delta_x; t2.first+=delta_x; t3.first+=delta_x; t1.second+=delta_y; t2.second+=delta_y; t3.second+=delta_y; }
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor){
        if(std::fabs(faktor-epsilon)<0)throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka n1,n2,n3;
        n1=std::make_pair(t.first+faktor*(t1.first-t.first),t.second+faktor*(t1.second-t.second));
        n2=std::make_pair(t.first+faktor*(t2.first-t.first),t.second+faktor*(t2.second-t.second));
        n3=std::make_pair(t.first+faktor*(t3.first-t.first),t.second+faktor*(t3.second-t.second));
        Postavi(n1,n2,n3);
    }
    void Rotiraj(double ugao){Tacka cent(DajCentar()); Rotiraj(cent,ugao);}
    void Skaliraj(double faktor){Tacka cent(DajCentar()); Skaliraj(cent,faktor);}
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
void Trougao::Postavi(int indeks, const Tacka &t){
    switch(indeks){
        case 1:
            if(Orijentacija(t,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
            t1=t;
            break;
        case 2:
            if(Orijentacija(t1,t,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
            t2=t;
            break;
        case 3:
            if(Orijentacija(t1,t2,t)==0)throw std::domain_error("Nekorektne pozicije tjemena");
            t3=t;
            break;
        default: 
            if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
            break;
    }
}
Tacka Trougao::DajTjeme(int indeks)const{
    switch(indeks){
        case 1:
            return t1;
            break;
        case 2:
            return t2;
            break;
        case 3:
            return t3;
            break;
        default: 
            if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
            break;
    }
    return std::make_pair(0.,0.);
}
double Trougao::DajStranicu(int indeks) const{
    switch(indeks){
        case 1:
            return std::sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
            break;
        case 2:
            return std::sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
            break;
        case 3:
            return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
            break;
        default: 
            if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
            break;
    }
    return 0;
}
double Trougao::DajUgao(int indeks) const{
    double k1,k2;
    switch(indeks){
        case 1:
            k1=(t3.second-t1.second)/(t3.first-t1.first);
            k2=(t2.second-t1.second)/(t2.first-t1.first);
            return std::atan(std::fabs((k2-k1)/(1+k1*k2)));
            break;
        case 2:
            k1=(t3.second-t2.second)/(t3.first-t2.first);
            k2=(t1.second-t2.second)/(t1.first-t2.first);
            return std::atan(std::fabs((k2-k1)/(1+k1*k2)));
            break;
        case 3:
            k1=(t1.second-t3.second)/(t1.first-t3.first);
            k2=(t2.second-t3.second)/(t2.first-t3.first);
            return std::atan(std::fabs((k2-k1)/(1+k1*k2)));
            break;
        default: 
            if(indeks<1 || indeks>3)throw std::range_error("Nekorektan indeks");
            break;
    }
    return 0;
}
void Trougao::Centriraj(const Tacka &t){
    double delta_x,delta_y;
    Tacka c(DajCentar());
    delta_x=c.first-t.first;
    delta_y=c.second-t.second;
    Transliraj(delta_x,delta_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    Tacka n1,n2,n3;
    n1=std::make_pair(t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao),
    t.second+(t1.first-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao));
    
    n2=std::make_pair(t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao),
    t.second+(t2.first-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao));
    
    n3=std::make_pair(t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao),
    t.second+(t3.first-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao));
    Postavi(n1,n2,n3);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    return Trougao::Jednako(t1.DajTjeme(1).first+t1.DajTjeme(2).first+t1.DajTjeme(3).first,t2.DajTjeme(1).first+t2.DajTjeme(2).first+t2.DajTjeme(3).first) && 
        Trougao::Jednako(t1.DajTjeme(1).second+t1.DajTjeme(2).second+t1.DajTjeme(3).second,t2.DajTjeme(1).second+t2.DajTjeme(2).second+t2.DajTjeme(3).second);
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    return Trougao::Jednako((t1.DajObim()/t2.DajObim())*(t1.DajObim()/t2.DajObim()),t1.DajPovrsinu()/t2.DajPovrsinu());//
}//
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){

    return Trougao::Jednako(t1.DajObim(),t2.DajObim()) && Trougao::Jednako(t1.DajPovrsinu(),t2.DajPovrsinu());
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    int o1,o2,o3,o4;
    o1=Orijentacija(t1,t2,t3);
    o2=Orijentacija(t1,t2,t);
    o3=Orijentacija(t2,t3,t);
    o4=Orijentacija(t3,t1,t);

   // if(o1*o2*o3*o4==0)std::cout<<"NIJE SIGURNO"<<std::endl;
    //else if(o1==o2 && o2==o3 && o3==o4)std::cout<<"Jeste"<<std::endl;
    return o1==o2 && o2==o3 && o3==o4;
}
void UnesiBroj(int &br,int znak){
    int x;
    while(std::cin>>x,!std::cin || x*znak<0 ||  std::cin.peek()!='\n'){   
        std::cout<<"Unijeli ste pogresan podatak! Pokusajte ponovo: "<<std::endl;
        std::cin.clear();
        std::cin.ignore(10000,'\n');
    }
    br=x;
    
}
int main ()
{//
    int n(0);
    std::cout<<"Koliko zelite kreirati trouglova: ";
    UnesiBroj(n,1);
    std::vector<std::shared_ptr<Trougao>>trouglovi(n,nullptr);
    Tacka t1,t2,t3,t;
    double x,y;
    for(int i=0; i<trouglovi.size();i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>x>>y;
        t1=std::make_pair(x,y);
        std::cin>>x>>y;
        t2=std::make_pair(x,y);
        std::cin>>x>>y;
        t3=std::make_pair(x,y);
        try{
            trouglovi[i]=std::make_shared<Trougao>(Trougao(t1,t2,t3));
        }catch(std::domain_error a){
            std::cout<<a.what()<<std::endl;
            i--;
        }catch(...){
            std::cout<<"Nedovoljno memorije!"<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    double ug;
    std::cin>>ug;
    std::cout<<"Unesite faktor skaliranja: ";
    double k;
    while(std::cin>>k,Trougao::Jednako(k,0)){
        std::cout<<"Faktor skaliranja ne moze biti 0! Unesite ponovo: ";
    }

    std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),[dx,dy,k,ug](std::shared_ptr<Trougao> t){
        t->Transliraj(dx,dy);
        t->Rotiraj(ug);
        t->Skaliraj(t->DajTjeme(1),k);
        return t;
    });
    std::sort(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
        return t1->DajPovrsinu()<t2->DajPovrsinu();
    });
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t){
        t->Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto p(std::min_element(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
        return (t1->DajObim())<(t2->DajObim());
    }));
    (*p)->Ispisi();
    std::cout<<std::endl;
    std::cout<<"Parovi identicnih trouglova: "<<std::endl;
    for(int i=0; i<trouglovi.size();i++){
        for(int j=i+1; j<trouglovi.size(); j++)
            if(DaLiSuIdenticni(*trouglovi[i],*trouglovi[j])){
                trouglovi[i]->Ispisi();
                std::cout<<" i ";
                trouglovi[j]->Ispisi();
                std::cout<<std::endl;
            }
    }
    std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
    for(int i=0; i<trouglovi.size();i++){
        for(int j=i+1; j<trouglovi.size(); j++)
            if(DaLiSuPodudarni(*trouglovi[i],*trouglovi[j])){
                trouglovi[i]->Ispisi();
                std::cout<<" i ";
                trouglovi[j]->Ispisi();
                std::cout<<std::endl;
            }
    }
 
    std::cout<<"Parovi slicnih trouglova: "<<std::endl;
    for(int i=0; i<trouglovi.size();i++){
        for(int j=i+1; j<trouglovi.size(); j++)
            if(DaLiSuSlicni(*trouglovi[i],*trouglovi[j])){
                trouglovi[i]->Ispisi();
                std::cout<<" i ";
                trouglovi[j]->Ispisi();
                std::cout<<std::endl;
            }
    }
	return 0;
}