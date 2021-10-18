/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <set>
#include <vector>  
#include <memory>
#include <algorithm>
typedef std::pair<double,double> Tacka;
const double Eps(1e-10);
class Trougao{  
    Tacka v1,v2,v3;
    void TestIndeksa(int indeks)const{
        if(indeks<0 || indeks>3) throw std::range_error("Nekorektan indeks");
    }
    void TestLinearnosti(const Tacka&t1,const Tacka&t2,const Tacka&t3)const{
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    }
    double DuzinaStranice(const Tacka&t1,const Tacka&t2)const{
        return std::sqrt(std::fabs(t1.first-t2.first)*std::fabs(t1.first-t2.first)+std::fabs(t1.second-t2.second)*std::fabs(t1.second-t2.second));
    }
    static double Izraz(const Tacka&t1,const Tacka&t2,const Tacka&t3){
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    void RotirajTacku(Tacka&vrh, const Tacka&t, double ugao){
        double x(t.first+(vrh.first-t.first)*std::cos(ugao)-(vrh.second-t.second)*std::sin(ugao));
        double y(t.second+(vrh.first-t.first)*std::sin(ugao)+(vrh.second-t.second)*std::cos(ugao));
        vrh.first=x;
        vrh.second=y;
    }
    void SkalirajTacku(Tacka&vrh,const Tacka&t,double faktor){
        vrh.first=t.first+faktor*(vrh.first-t.first);
        vrh.second=t.second+faktor*(vrh.second-t.second);
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
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    Postavi(t1,t2,t3);
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    TestLinearnosti(t1,t2,t3);
    v1=t1; v2=t2; v3=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    TestIndeksa(indeks);
    switch(indeks){
        case 1:v1=t;
            break;
        case 2:v2=t;
            break;
        case 3:v3=t;    
    }
    TestLinearnosti(v1,v2,v3);
}
int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    if(Izraz(t1,t2,t3)>0) return 1;
    if(Izraz(t1,t2,t3)<0) return -1;
    return 0;
}
Tacka Trougao::DajTjeme(int indeks)const{
    TestIndeksa(indeks);
    switch(indeks){
        case 1:return v1;
        case 2:return v2;
    }
    return v3;
}
double Trougao::DajStranicu(int indeks)const{
    TestIndeksa(indeks);
    switch(indeks){
        case 1:return DuzinaStranice(v2,v3);
        case 2:return DuzinaStranice(v1,v3);
    }
    return DuzinaStranice(v1,v2);
}
double Trougao::DajUgao(int indeks)const{
    TestIndeksa(indeks);
    switch(indeks){
        case 1:return std::acos((DuzinaStranice(v1,v3)*DuzinaStranice(v1,v3)+DuzinaStranice(v1,v2)*DuzinaStranice(v1,v2)
        -DuzinaStranice(v2,v3)*DuzinaStranice(v2,v3))/(2*DuzinaStranice(v1,v2)*DuzinaStranice(v1,v3)));
        break;
        case 2:return std::acos((DuzinaStranice(v1,v2)*DuzinaStranice(v1,v2)+DuzinaStranice(v2,v3)*DuzinaStranice(v2,v3)
        -DuzinaStranice(v1,v3)*DuzinaStranice(v1,v3))/(2*DuzinaStranice(v1,v2)*DuzinaStranice(v2,v3)));
    }
    return std::acos((DuzinaStranice(v1,v3)*DuzinaStranice(v1,v3)+DuzinaStranice(v2,v3)*DuzinaStranice(v2,v3)
    -DuzinaStranice(v1,v2)*DuzinaStranice(v1,v2))/(2*DuzinaStranice(v1,v3)*DuzinaStranice(v2,v3)));
}
Tacka Trougao::DajCentar()const{
    Tacka t;
    t.first=(v1.first+v2.first+v3.first)/3;
    t.second=(v1.second+v2.second+v3.second)/3;
    return t;
}
double Trougao::DajObim()const{
    return DuzinaStranice(v1,v2)+DuzinaStranice(v1,v3)+DuzinaStranice(v2,v3);
}
double Trougao::DajPovrsinu()const{
    return std::fabs(Izraz(v1,v2,v3))/2.;
}
bool Trougao::DaLiJePozitivnoOrijentiran()const{
    if(Orijentacija(v1,v2,v3)==1)return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka&t)const{
    double a((v1.second*v3.first-v1.first*v3.second+t.first*(v3.second-v1.second)+t.second*(v1.first-v3.first))/Izraz(v1,v2,v3));
    double b((v1.first*v2.second-v1.second*v2.first+t.first*(v1.second-v2.second)+t.second*(v2.first-v1.first))/Izraz(v1,v2,v3));
    if(a>0 && b>0 && 1-a-b>0) return true;
    return false;
}
void Trougao::Ispisi()const{
    std::cout<<"(("<<v1.first<<","<<v1.second<<"),("<<v2.first<<","<<v2.second<<"),("<<v3.first<<","<<v3.second<<"))";
}
void Trougao::Transliraj(double delta_x,double delta_y){
    v1.first+=delta_x; v2.first+=delta_x; v3.first+=delta_x;
    v1.second+=delta_y; v2.second+=delta_y; v3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka&t){
    auto t2(DajCentar());
    Transliraj(t.first-t2.first,t.second-t2.second);
}
void Trougao::Rotiraj(const Tacka&t, double ugao){
    RotirajTacku(v1,t,ugao);
    RotirajTacku(v2,t,ugao);
    RotirajTacku(v3,t,ugao);
}
void Trougao::Skaliraj(const Tacka&t, double faktor){
    if(faktor==0)throw std::domain_error("Nekorektan faktor skaliranja");
    SkalirajTacku(v1,t,faktor);
    SkalirajTacku(v2,t,faktor);
    SkalirajTacku(v3,t,faktor);
}
void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao);
}
void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(),faktor);
}
bool DaLiSuIdenticni(const Trougao&t1, const Trougao&t2){
    std::set<Tacka> skup1,skup2;
    skup1.insert((t1.v1)); skup1.insert((t1.v2)); skup1.insert((t1.v3));
    skup2.insert((t2.v1)); skup2.insert((t2.v2)); skup2.insert((t2.v3));
    if(skup1!=skup2) return false;
    return true;
}
bool DaLiSuPodudarni(const Trougao&t1,const Trougao&t2){
    /*if(t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))!=t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))) return false;
    std::set<std::pair<double,double>> skup1,skup2;
    for(int i=1;i<=3;i++){
        skup1.insert({t1.DajStranicu(i),t1.DajUgao(i)});
        skup2.insert({t2.DajStranicu(i),t2.DajUgao(i)});
    }
    if(skup1!=skup2) return false;*/
    int u1(1),u2(1);
    for(int i=2;i<=3;i++){
    if(t1.DajUgao(i)>t1.DajUgao(u1))u1=i;
    if(t2.DajUgao(i)>t2.DajUgao(u2))u2=i;
    }
    Tacka va1,va2,vb1,vb2;
    int a1,a2,b1,b2;
    switch(u1){
        case 1:
        if(t1.DuzinaStranice(t1.DajTjeme(u1),t1.DajTjeme(2))<t1.DuzinaStranice(t1.DajTjeme(u1),t1.DajTjeme(3))){a1=2; a2=3;}
        else{ a1=3;a2=2;}
        break;
        case 2:
        if(t1.DuzinaStranice(t1.DajTjeme(u1),t1.DajTjeme(1))<t1.DuzinaStranice(t1.DajTjeme(u1),t1.DajTjeme(3))){a1=1; a2=3;}
        else{a1=3; a2=1;}
        //std::cout<<t1.DuzinaStranice(t1.DajTjeme(u1),t1.DajTjeme(1))<<" "<<t1.DuzinaStranice(t1.DajTjeme(u1),t1.DajTjeme(3));
        //std::cout<<a1<<","<<a2;
        break;
        case 3:
        if(t1.DuzinaStranice(t1.DajTjeme(u1),t1.DajTjeme(1))<t1.DuzinaStranice(t1.DajTjeme(u1),t1.DajTjeme(2))){ a1=1;a2=2;}
        else{a1=2;a2=1;}
    }
    va1={t1.DajTjeme(a1).first-t1.DajTjeme(u1).first,t1.DajTjeme(a1).second-t1.DajTjeme(u1).second};
    va2={t1.DajTjeme(a2).first-t1.DajTjeme(u1).first,t1.DajTjeme(a2).second-t1.DajTjeme(u1).second};
    switch(u2){
        case 1:
        if(t2.DuzinaStranice(t2.DajTjeme(u2),t2.DajTjeme(2))<t2.DuzinaStranice(t2.DajTjeme(u2),t2.DajTjeme(3))){b1=2;b2=3;}
        else{b1=3;b2=2;}
        break;
        case 2:
        if(t2.DuzinaStranice(t2.DajTjeme(u2),t2.DajTjeme(1))<t2.DuzinaStranice(t2.DajTjeme(u2),t2.DajTjeme(3))){b1=1;b2=3;}
        else{b1=3;b2=1;}
        break;
        case 3:
        if(t2.DuzinaStranice(t2.DajTjeme(u2),t2.DajTjeme(1))<t2.DuzinaStranice(t2.DajTjeme(u2),t2.DajTjeme(2))){b1=1;b2=2;}
        else{ b1=2;b2=1;}
    }    
    vb1={t2.DajTjeme(b1).first-t2.DajTjeme(u2).first,t2.DajTjeme(b1).second-t2.DajTjeme(u2).second};
    vb2={t2.DajTjeme(b2).first-t2.DajTjeme(u2).first,t2.DajTjeme(b2).second-t2.DajTjeme(u2).second};
    //std::cout<<"va1: "<<va1.first<<","<<va1.second<<" va2: "<<va2.first<<","<<va2.second<<" vb1: "<<vb1.first<<","<<vb1.second<<" vb2: "<<vb2.first<<","<<vb2.second<<std::endl;
    double k1(va1.first*va2.second-va1.second*va2.first),k2(vb1.first*vb2.second-vb1.second*vb2.first);
    if(std::fabs(k1-k2)>Eps*(std::fabs(k1)+std::fabs(k2))) return false;
    return true;
}
bool DaLiSuSlicni(const Trougao&t1,const Trougao&t2){
    std::set<std::pair<double,double>> skup1,skup2;
    for(int i=1;i<=3;i++){
        skup1.insert({t1.DajStranicu(i),t1.DajUgao(i)});
        skup2.insert({t2.DajStranicu(i),t2.DajUgao(i)});
    }
    double faktor(skup1.begin()->first/skup2.begin()->first);
    Trougao drugi(t1);
    drugi.Skaliraj(faktor);
    if(DaLiSuPodudarni(drugi,t2)) return true;
    return false;
}
int main (){
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> vektor(n,nullptr);
    for(int i=0;i<n;i++){
        try{
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka niz[3];
            for(int j=0;j<3;j++){
                double x,y;
                std::cin>>x>>y;
                niz[j]={x,y};
            }
            vektor[i]=std::make_shared<Trougao>(niz[0],niz[1],niz[2]);
            if(vektor[i]->Orijentacija(niz[0],niz[1],niz[2])==0){
                vektor[i]=nullptr;
                throw;
            }
        }catch(...){std::cout<<"Nekorektne pozicije tjemena, ponovite unos!\n"; i--;}
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double x,y;
    std::cin>>x>>y;
    std::cout<<"Unesite ugao rotacije: Unesite faktor skaliranja: ";
    double ugao,faktor;
    std::cin>>ugao>>faktor;
    std::transform(vektor.begin(),vektor.end(),vektor.begin(),[ugao,x,y,faktor](std::shared_ptr<Trougao> point){
        point->Transliraj(x,y);
        point->Rotiraj(ugao);
        point->Skaliraj(point->DajTjeme(1),faktor);
        return point;
    });
    std::sort(vektor.begin(),vektor.end(),[](std::shared_ptr<Trougao> point1,std::shared_ptr<Trougao> point2){
        if(point1->DajPovrsinu()<point2->DajPovrsinu())return true;
        return false;
    });
    std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(vektor.begin(),vektor.end(),[](std::shared_ptr<Trougao>point){
        point->Ispisi();std::cout<<std::endl;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*std::min_element(vektor.begin(),vektor.end(),[](std::shared_ptr<Trougao>p1,std::shared_ptr<Trougao>p2){
        if(p1->DajObim()<p2->DajObim()) return true;
        return false;
    }))->Ispisi();std::cout<<std::endl;
    bool identicni(false),podudarni(false),slicni(false);
    for(int i=0;i<vektor.size()-1;i++){
        for(int j=i+1;j<vektor.size();j++){
            if (DaLiSuIdenticni(*vektor[i],*vektor[j])){
                if(identicni==false)std::cout<<"Parovi identicnih trouglova:\n";
                identicni=true;
                vektor[i]->Ispisi();std::cout<<" i ";vektor[j]->Ispisi();std::cout<<std::endl;}
        }
    }
    if(identicni==false)std::cout<<"Nema identicnih trouglova!\n";
    for(int i=0;i<vektor.size()-1;i++){
        for(int j=i+1;j<vektor.size();j++){
            if (DaLiSuPodudarni(*vektor[i],*vektor[j])){
                if(podudarni==false)std::cout<<"Parovi podudarnih trouglova:\n";
                podudarni=true;
                vektor[i]->Ispisi();std::cout<<" i ";vektor[j]->Ispisi();std::cout<<std::endl;}
        }
    }
    if(podudarni==false)std::cout<<"Nema podudarnih trouglova!\n";
    for(int i=0;i<vektor.size()-1;i++){
        for(int j=i+1;j<vektor.size();j++){
            if (DaLiSuSlicni(*vektor[i],*vektor[j])){
                if(slicni==false)std::cout<<"Parovi slicnih trouglova:\n";
                slicni=true;
                vektor[i]->Ispisi();std::cout<<" i ";vektor[j]->Ispisi();std::cout<<std::endl;}
        }
    }
    if(slicni==false)std::cout<<"Nema slicnih trouglova!";
	return 0;
}