/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
bool jednaki(double a,double b){
    return std::fabs(a-b)<1E-10;
}
typedef std::pair<double, double> Tacka;
class Trougao{
    Tacka t1,t2,t3;
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
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1;Trougao::t2=t2;Trougao::t3=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks<1||indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1){
        if(Orijentacija(t,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        t1=t;}
    else if(indeks==2){
         if(Orijentacija(t1,t,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
         t2=t; 
    }
    else {
         if(Orijentacija(t1,t2,t)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        t3=t;
    }
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1;Trougao::t2=t2;Trougao::t3=t3;
}
double fun(const Tacka &t1, const Tacka &t2, const Tacka &t3){
     double provjera=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
     return provjera;
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double provjera=fun(t1,t2,t3);
    if(jednaki(provjera,0)) return 0;
    if(provjera>0) return 1;
    return -1;
}
Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks<1||indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return t1;
    if(indeks==2) return t2;
    return t3;
}
double Trougao::DajStranicu(int indeks) const{
    if(indeks<1||indeks>3) throw std::range_error("Nekorektan indeks");
    Tacka tmp1,tmp2;
     if(indeks==1){ tmp1=t2;tmp2=t3;}
     if(indeks==2){ tmp1=t1;tmp2=t3;}
     if(indeks==3){tmp1=t1;tmp2=t2;}
     double duzina=std::sqrt((tmp1.first-tmp2.first)*(tmp1.first-tmp2.first)+(tmp1.second-tmp2.second)*(tmp1.second-tmp2.second));
     return duzina;
}
double Trougao::DajUgao(int indeks) const{
     if(indeks<1||indeks>3) throw std::range_error("Nekorektan indeks");
     Tacka tmp1,tmp2,tmp3;
     if(indeks==1){ tmp1=t1;tmp2=t2;tmp3=t3;}
     if(indeks==2){ tmp1=t2;tmp2=t1;tmp3=t3;}
     if(indeks==3){tmp1=t3;tmp2=t1;tmp3=t2;}
     double a=std::sqrt((tmp3.first-tmp2.first)*(tmp3.first-tmp2.first)+(tmp3.second-tmp2.second)*(tmp3.second-tmp2.second));
     double b=std::sqrt((tmp1.first-tmp3.first)*(tmp1.first-tmp3.first)+(tmp1.second-tmp3.second)*(tmp1.second-tmp3.second));
     double c=std::sqrt((tmp1.first-tmp2.first)*(tmp1.first-tmp2.first)+(tmp1.second-tmp2.second)*(tmp1.second-tmp2.second)); // a^2=b^2 +c^2-2bccosalfa =>  cos(alfa)=(b^2+c^2-a^2)/2*bc
     double cosugla=(b*b+c*c-a*a)/(2*b*c);
     double ugao=std::acos(cosugla);
     return ugao;
}
Tacka Trougao::DajCentar() const{
    Tacka centar=std::make_pair((t1.first+t2.first+t3.first)/3.,(t1.second+t2.second+t3.second)/3.);
    return centar;
}
double Trougao::DajObim() const{
    double a=std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    double b=std::sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
    double c=std::sqrt((t3.first-t2.first)*(t3.first-t2.first)+(t3.second-t2.second)*(t3.second-t2.second));
    return (a+b+c);
}
double Trougao::DajPovrsinu() const{
    return std::fabs(fun(t1,t2,t3))/2.;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const{
    double provjera=fun(t1,t2,t3);
    return provjera>0;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    double provjera1,provjera2,provjera3,provjera4;
    provjera1=Orijentacija(t1,t2,t3);
    provjera2=Orijentacija(t1,t2,t);
    provjera3=Orijentacija(t2,t3,t);
    provjera4=Orijentacija(t3,t1,t);
    if((provjera1>=0&&provjera2>=0&&provjera3>=0&&provjera4>=0)||(provjera1<=0&&provjera2<=0&&provjera3<=0&&provjera4<=0)) return true;
    return false;
}
void Trougao::Transliraj(double delta_x, double delta_y){
    t1.first+=delta_x;t2.first+=delta_x;t3.first+=delta_x;
    t1.second+=delta_y;t2.second+=delta_y;t3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    Tacka centar=DajCentar();
    double deltax=t.first-centar.first,deltay=t.second-centar.second;
    Transliraj(deltax,deltay);
}
void RotirajTacku(Tacka &t1,const Tacka &t2,double ugao){
    double a=t2.first+(t1.first-t2.first)*std::cos(ugao)-(t1.second-t2.second)*std::sin(ugao);
    double b=t2.second+(t1.first-t2.first)*std::sin(ugao)+(t1.second-t2.second)*std::cos(ugao);
    t1.first=a;t1.second=b;
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    //ugao*=180/(4*atan(1));
    RotirajTacku(t1,t,ugao);
    RotirajTacku(t2,t,ugao);
    RotirajTacku(t3,t,ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(jednaki(faktor,0.)) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first=t.first+faktor*(t1.first-t.first);
    t2.first=t.first+faktor*(t2.first-t.first);
    t3.first=t.first+faktor*(t3.first-t.first);
    t1.second=t.second+faktor*(t1.second-t.second);
    t2.second=t.second+faktor*(t2.second-t.second);
    t3.second=t.second+faktor*(t3.second-t.second);
}
void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao);
}
void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(),faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    std::vector<Tacka> v1{t1.t1,t1.t2,t1.t3};
    std::vector<Tacka>v2{t2.t1,t2.t2,t2.t3};
    std::sort(v1.begin(),v1.end(),[](Tacka t1,Tacka t2){
        return t1.first<t2.first;
    });
    std::sort(v2.begin(),v2.end(),[](Tacka t1,Tacka t2){
        return t1.first<t2.first;
    });
    bool isti=true;
    for(int i=0;i<3;i++){
        if(!(jednaki(v1[i].first,v2[i].first))||!(jednaki(v1[i].second,v2[i].second))){
            isti=false;break;
        }
    }
    return isti;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::vector<std::pair<Tacka,double>> v1,v2;
    std::vector<Tacka> v3{t1.t1,t1.t2,t1.t3},v4{t2.t1,t2.t2,t2.t3};
    for(int i=0;i<3;i++){
        v1.push_back(std::make_pair(v3[i],t1.DajStranicu(i+1)));
        v2.push_back(std::make_pair(v4[i],t2.DajStranicu(i+1)));
    }
    std::sort(v1.begin(),v1.end(),[](std::pair<Tacka,double> t1,std::pair<Tacka,double> t2){
        return t1.second<t2.second;
    });
    std::sort(v2.begin(),v2.end(),[](std::pair<Tacka,double> t1,std::pair<Tacka,double> t2){

        return t1.second<t2.second;
    });
    if(Trougao::Orijentacija(v1[0].first,v1[1].first,v1[2].first)!=Trougao::Orijentacija(v2[0].first,v2[1].first,v2[2].first)) return false;
    bool podudarni=true;
    for(int i=0;i<3;i++){
        if(!(jednaki(v1[i].second,v2[i].second))){
            podudarni=false;break;
        }
    }
    return podudarni;    
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::vector<std::pair<Tacka,double>> v1,v2;
    std::vector<Tacka> v3{t1.t1,t1.t2,t1.t3},v4{t2.t1,t2.t2,t2.t3};
    for(int i=0;i<3;i++){
        v1.push_back(std::make_pair(v3[i],t1.DajUgao(i+1)));
        v2.push_back(std::make_pair(v4[i],t2.DajUgao(i+1)));
    }
    std::sort(v1.begin(),v1.end(),[](std::pair<Tacka,double> t1,std::pair<Tacka,double> t2){
        return t1.second<t2.second;
    });
    std::sort(v2.begin(),v2.end(),[](std::pair<Tacka,double> t1,std::pair<Tacka,double> t2){
        return t1.second<t2.second;
    });
    if(Trougao::Orijentacija(v1[0].first,v1[1].first,v1[2].first)!=Trougao::Orijentacija(v2[0].first,v2[1].first,v2[2].first)) return false;
    bool podudarni=true;
    for(int i=0;i<3;i++){
        if(!(jednaki(v1[i].second,v2[i].second))){
            podudarni=false;break;
        }
    }
    return podudarni;    
}
void Trougao::Ispisi() const{
    std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}


int main(){
std::cout<<"Koliko zelite kreirati trouglova: ";
int n; std::cin>>n;
std::vector <std::shared_ptr<Trougao>> trouglovi;
try{
    for(int i=0;i<n;i++){
        Tacka t1,t2,t3;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
        try{
        trouglovi.emplace_back(std::make_shared<Trougao>(Trougao(t1,t2,t3)));
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
}
catch(std::bad_alloc){
    return 0;
}
std::cout<<"Unesite vektor translacije (dx dy): ";
double dx,dy; std::cin>>dx>>dy;
std::cout<<"Unesite ugao rotacije: ";
double rot; std::cin>>rot;
std::cout<<"Unesite faktor skaliranja: ";
double skal; std::cin>>skal;
auto bla=std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),[dx,dy,rot,skal](std::shared_ptr<Trougao> t1){
    (*t1).Transliraj(dx,dy);
    (*t1).Rotiraj(rot);
    (*t1).Skaliraj(t1->DajTjeme(1),skal);
    return t1;
});
std::sort(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
    return (*t1).DajPovrsinu()<(*t2).DajPovrsinu();
});
std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
std::for_each(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t){ (*t).Ispisi(); std::cout<<std::endl;});
auto minimalni=std::min_element(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
    return (*t1).DajObim()<(*t2).DajObim();
});
std::cout<<"Trougao sa najmanjim obimom: "; 
(**minimalni).Ispisi(); std::cout<<std::endl;
std::vector<std::pair<Trougao,Trougao>> identicni,podudarni,slicni;
for(int i=0;i<trouglovi.size();i++){
    for(int j=i+1;j<trouglovi.size();j++){
        if(DaLiSuIdenticni(*trouglovi[i],*trouglovi[j])) identicni.emplace_back(std::make_pair(*trouglovi[i],*trouglovi[j]));
        if(DaLiSuPodudarni(*trouglovi[i],*trouglovi[j])) podudarni.emplace_back(std::make_pair(*trouglovi[i],*trouglovi[j]));
        if(DaLiSuSlicni(*trouglovi[i],*trouglovi[j])) slicni.emplace_back(std::make_pair(*trouglovi[i],*trouglovi[j]));
    }
}
if(identicni.size()==0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
else{
std::cout<<"Parovi identicnih trouglova: "<<std::endl;
std::for_each(identicni.begin(),identicni.end(),[](std::pair<Trougao,Trougao> t){
    t.first.Ispisi();
    std::cout<<" i ";
    t.second.Ispisi(); std::cout<<std::endl;
});
}
if(podudarni.size()==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
else{
std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
std::for_each(podudarni.begin(),podudarni.end(),[](std::pair<Trougao,Trougao> t){
    t.first.Ispisi();
    std::cout<<" i ";
    t.second.Ispisi(); std::cout<<std::endl;
});
}
if(slicni.size()==0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
else{
std::cout<<"Parovi slicnih trouglova: "<<std::endl;
std::for_each(slicni.begin(),slicni.end(),[](std::pair<Trougao,Trougao> t){
    t.first.Ispisi();
    std::cout<<" i ";
    t.second.Ispisi(); std::cout<<std::endl;
});
}
return 0;
}