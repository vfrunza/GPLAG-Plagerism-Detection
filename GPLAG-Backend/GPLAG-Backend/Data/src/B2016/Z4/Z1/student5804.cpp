#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

const double epsilon(pow(10,-10));
typedef std::pair<double,double> Tacka;

double str1( Tacka t1,  Tacka t2, Tacka t3) {
    double str=std::sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
    return str;
}
double str2( Tacka t1,  Tacka t2, Tacka t3){
    double str=std::sqrt((t2.first-t1.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
    return str;
}
double str3( Tacka t1,  Tacka t2, Tacka t3){
    double str=std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    return str;
}
class Trougao{
    Tacka tacka1,tacka2,tacka3;
double str1(const Tacka tacka1, const Tacka tacka2,const Tacka tacka3) const{
    double str=std::sqrt((tacka2.first-tacka3.first)*(tacka2.first-tacka3.first)+(tacka2.second-tacka3.second)*(tacka2.second-tacka3.second));
    return str;
}
double str2(const Tacka tacka1, const Tacka tacka2,const Tacka tacka3)const{
    double str=std::sqrt((tacka2.first-tacka1.first)*(tacka1.first-tacka3.first)+(tacka1.second-tacka3.second)*(tacka1.second-tacka3.second));
    return str;
}
double str3(const Tacka tacka1, const Tacka tacka2,const Tacka tacka3)const{
    double str=std::sqrt((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+(tacka2.second-tacka1.second)*(tacka2.second-tacka1.second));
    return str;
}
double apsolutnibroj(const Tacka &t1, const Tacka &t2, const Tacka &t3)const{
    double P;
   P=t1.first*(t2.second-t3.second)+t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
   return P;
}

public:
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    tacka1=t1;
    tacka2=t2;
    tacka3=t3;
}
void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    tacka1=t1;
    tacka2=t2;
    tacka3=t3;
}
void Postavi(int indeks, const Tacka&t){
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) tacka1=t;
    if(indeks==2) tacka2=t;
    if(indeks==3) tacka3=t;
}
static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
   double P=t1.first*(t2.second-t3.second)+t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
   if( P>0) return 1;
   if(P<0) return -1;
   if(fabs(P-0)<epsilon) return 0;
}
Tacka DajTjeme(int indeks)const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return tacka1;
    if(indeks==2) return tacka2;
    if(indeks==3) return tacka3;
}
double DajStranicu(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
double stranica1=str1(tacka1,tacka2,tacka3);
double stranica2=str2(tacka1,tacka2,tacka3);
double stranica3=str3(tacka1,tacka2,tacka3);
    if(indeks==1) return stranica1;
    if(indeks==2) return stranica2;
    if(indeks==3) return stranica3;}
double DajUgao(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    double alfa,beta,gama;
    alfa=std::acos(std::sqrt((str2(tacka1,tacka2,tacka3)*str2(tacka1,tacka2,tacka3)+str3(tacka1,tacka2,tacka3)*str3(tacka1,tacka2,tacka3)-str1(tacka1,tacka2,tacka3)*str1(tacka1,tacka2,tacka3))/(2*str2(tacka1,tacka2,tacka3)*str3(tacka1,tacka2,tacka3))));
    beta=std::acos(std::sqrt((-str2(tacka1,tacka2,tacka3)*str2(tacka1,tacka2,tacka3)+str3(tacka1,tacka2,tacka3)*str3(tacka1,tacka2,tacka3)+str1(tacka1,tacka2,tacka3)*str1(tacka1,tacka2,tacka3))/(2*str1(tacka1,tacka2,tacka3)*str3(tacka1,tacka2,tacka3))));
    gama=std::acos(std::sqrt((str2(tacka1,tacka2,tacka3)*str2(tacka1,tacka2,tacka3)-str3(tacka1,tacka2,tacka3)*str3(tacka1,tacka2,tacka3)+str1(tacka1,tacka2,tacka3)*str1(tacka1,tacka2,tacka3))/(2*str2(tacka1,tacka2,tacka3)*str1(tacka1,tacka2,tacka3))));
    if(indeks==1) return alfa;
    if(indeks==2) return beta;
    if(indeks==3) return gama;}
Tacka DajCentar(){
    Tacka centar;
    centar.first=(tacka1.first+tacka2.first+tacka3.first)/3;
    centar.second=(tacka1.second+tacka2.second+tacka3.second)/3;
    return centar;}
double DajObim() const{
    double O=str1(tacka1,tacka2,tacka3)+str2(tacka1,tacka2,tacka3)+str3(tacka1,tacka2,tacka3);
    return O;
}
double DajPovrsinu(){
    return (0.5*fabs(apsolutnibroj(tacka1,tacka2,tacka3)));}
bool DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(tacka1,tacka2,tacka3)==1) return true;
    else return false;
}
bool DaLiJeUnutra(const Tacka &t) const{
    if(Orijentacija(tacka1,tacka2,t)==1 && Orijentacija(tacka2,tacka3,t)==1 && Orijentacija(tacka3,tacka1,t)==1 && Orijentacija(tacka1,tacka2,tacka3)) return true;
    else return false;
}
void Ispisi() const{
std::cout<<"(("<<tacka1.first<<","<<tacka1.second<<"),("<<tacka2.first<<","<<tacka2.second<<"),("<<tacka3.first<<","<<tacka3.second<<"))";}
void Transliraj(double delta_x, double delta_y){
    tacka1.first=tacka1.first+delta_x;
    tacka1.second=tacka1.second+delta_y;
    tacka2.first=tacka2.first+delta_x;
    tacka2.second=tacka2.second+delta_y;
    tacka3.first=tacka3.first+delta_x;
    tacka3.second=tacka3.second+delta_y;
}
void Centriraj(const Tacka &t){
   Transliraj(DajCentar().first-t.first,DajCentar().second-t.second);
}

void Rotiraj(const Tacka &t,double ugao){
    
    tacka1.first=(t.first+(tacka1.first-t.first)*std::cos(ugao)-(tacka1.second-t.second)*std::sin(ugao));
    tacka1.second=(t.second+(tacka2.first-t.first)*std::sin(ugao)-(tacka1.second-t.second)*std::cos(ugao));
    tacka2.first=(t.first+(tacka2.first-t.first)*std::cos(ugao)-(tacka2.second-t.second)*std::sin(ugao));
    tacka2.second=(t.second+(tacka2.first-t.first)*std::sin(ugao)-(tacka2.second-t.second)*std::cos(ugao));
    tacka3.first=(t.first+(tacka3.first-t.first)*std::cos(ugao)-(tacka3.second-t.second)*std::sin(ugao));
    tacka3.second=(t.second+(tacka3.first-t.first)*std::sin(ugao)-(tacka3.second-t.second)*std::cos(ugao));
}
void Skaliraj(const Tacka &t, double faktor){
    if(fabs(faktor-0)<epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
     tacka1.first=(t.first+faktor*(tacka1.first-t.first));
     tacka1.second=(t.second+faktor*(tacka1.second-t.second));
     tacka2.first=(t.first+faktor*(tacka2.first-t.first));
     tacka2.second=(t.second+faktor*(tacka2.second-t.second));
     tacka3.first=(t.first+faktor*(tacka3.first-t.first));
     tacka3.second=(t.second+faktor*(tacka3.second-t.second));
}
void Rotiraj(double ugao){
    auto t=DajCentar();
    tacka1.first=(t.first+(tacka1.first-t.first)*std::cos(ugao)-(tacka1.second-t.second)*std::sin(ugao));
    tacka1.second=(t.second+(tacka2.first-t.first)*std::sin(ugao)-(tacka1.second-t.second)*std::cos(ugao));
    tacka2.first=(t.first+(tacka2.first-t.first)*std::cos(ugao)-(tacka2.second-t.second)*std::sin(ugao));
    tacka2.second=(t.second+(tacka2.first-t.first)*std::sin(ugao)-(tacka2.second-t.second)*std::cos(ugao));
    tacka3.first=(t.first+(tacka3.first-t.first)*std::cos(ugao)-(tacka3.second-t.second)*std::sin(ugao));
    tacka3.second=(t.second+(tacka3.first-t.first)*std::sin(ugao)-(tacka3.second-t.second)*std::cos(ugao));
}
void Skaliraj(double faktor){
   if(fabs(faktor-0)<epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
   auto t=DajCentar();
     tacka1.first=(t.first+faktor*(tacka1.first-t.first));
     tacka1.second=(t.second+faktor*(tacka1.second-t.second));
     tacka2.first=(t.first+faktor*(tacka2.first-t.first));
     tacka2.second=(t.second+faktor*(tacka2.second-t.second));
     tacka3.first=(t.first+faktor*(tacka3.first-t.first));
     tacka3.second=(t.second+faktor*(tacka3.second-t.second)); 
}
friend bool DaLiSuSlicni (const Trougao &t1,const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
if(fabs(t1.tacka1.first-t2.tacka1.first)<epsilon && fabs(t1.tacka1.second-t2.tacka1.second)<epsilon && fabs(t1.tacka2.first-t2.tacka2.first)<epsilon && fabs(t1.tacka3.first-t2.tacka3.first)<epsilon && fabs(t1.tacka2.second-t2.tacka2.second)<epsilon &&  fabs(t1.tacka3.second-t2.tacka3.second)<epsilon) return true;
if(fabs(t1.tacka1.first-t2.tacka2.first)<epsilon && fabs(t1.tacka1.second-t2.tacka2.second)<epsilon && fabs(t1.tacka2.first-t2.tacka1.first)<epsilon && fabs(t1.tacka3.first-t2.tacka3.first)<epsilon && fabs(t1.tacka2.second-t2.tacka1.second)<epsilon &&  fabs(t1.tacka3.second-t2.tacka3.second)<epsilon) return true;
if(fabs(t1.tacka1.first-t2.tacka3.first)<epsilon && fabs(t1.tacka1.second-t2.tacka3.second)<epsilon && fabs(t1.tacka2.first-t2.tacka2.first)<epsilon && fabs(t1.tacka3.first-t2.tacka1.first)<epsilon && fabs(t1.tacka2.second-t2.tacka2.second)<epsilon &&  fabs(t1.tacka3.second-t2.tacka1.second)<epsilon) return true;
if(fabs(t1.tacka1.first-t2.tacka1.first)<epsilon && fabs(t1.tacka1.second-t2.tacka1.second)<epsilon && fabs(t1.tacka2.first-t2.tacka3.first)<epsilon && fabs(t1.tacka3.first-t2.tacka2.first)<epsilon && fabs(t1.tacka2.second-t2.tacka3.second)<epsilon &&  fabs(t1.tacka3.second-t2.tacka2.second)<epsilon) return true;
else return false;}
bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
    auto a1=str1(t1.tacka1,t1.tacka2,t1.tacka3);
    auto b1=str2(t1.tacka1,t1.tacka2,t1.tacka3);
    auto c1=str3(t1.tacka1,t1.tacka2,t1.tacka3);
    auto a2=str1(t2.tacka1,t2.tacka2,t2.tacka3);
    auto b2=str2(t2.tacka1,t2.tacka2,t2.tacka3);
    auto c2=str3(t2.tacka1,t2.tacka2,t2.tacka3);
    if(fabs(a1-a2)<epsilon && fabs(b1-b2)<epsilon && fabs(c1-c2)<epsilon && Trougao::Orijentacija(t1.tacka1,t1.tacka2,t1.tacka3)==Trougao::Orijentacija(t2.tacka1,t2.tacka2,t2.tacka3)) return true;
    if(fabs(a1-b2)<epsilon && fabs(b1-a2)<epsilon && fabs(c1-c2)<epsilon && Trougao::Orijentacija(t1.tacka1,t1.tacka2,t1.tacka3)==Trougao::Orijentacija(t2.tacka1,t2.tacka2,t2.tacka3)) return true;
    if(fabs(a1-c2)<epsilon && fabs(b1-b2)<epsilon && fabs(a1-c2)<epsilon && Trougao::Orijentacija(t1.tacka1,t1.tacka2,t1.tacka3)==Trougao::Orijentacija(t2.tacka1,t2.tacka2,t2.tacka3)) return true;
    if(fabs(a1-a2)<epsilon && fabs(b1-c2)<epsilon && fabs(c1-b2)<epsilon && Trougao::Orijentacija(t1.tacka1,t1.tacka2,t1.tacka3)==Trougao::Orijentacija(t2.tacka1,t2.tacka2,t2.tacka3)) return true;
else return false;
 }
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
    double a1=std::acos(std::sqrt((str2(t1.tacka1,t1.tacka2,t1.tacka3)*str2(t1.tacka1,t1.tacka2,t1.tacka3)+str3(t1.tacka1,t1.tacka2,t1.tacka3)*str3(t1.tacka1,t1.tacka2,t1.tacka3)-str1(t1.tacka1,t1.tacka2,t1.tacka3)*str1(t1.tacka1,t1.tacka2,t1.tacka3))/(2*str2(t1.tacka1,t1.tacka2,t1.tacka3)*str3(t1.tacka1,t1.tacka2,t1.tacka3))));
    double b1=std::acos(std::sqrt((-str2(t1.tacka1,t1.tacka2,t1.tacka3)*str2(t1.tacka1,t1.tacka2,t1.tacka3)+str3(t1.tacka1,t1.tacka2,t1.tacka3)*str3(t1.tacka1,t1.tacka2,t1.tacka3)+str1(t1.tacka1,t1.tacka2,t1.tacka3)*str1(t1.tacka1,t1.tacka2,t1.tacka3))/(2*str1(t1.tacka1,t1.tacka2,t1.tacka3)*str3(t1.tacka1,t1.tacka2,t1.tacka3))));
    double c1=std::acos(std::sqrt((str2(t1.tacka1,t1.tacka2,t1.tacka3)*str2(t1.tacka1,t1.tacka2,t1.tacka3)-str3(t1.tacka1,t1.tacka2,t1.tacka3)*str3(t1.tacka1,t1.tacka2,t1.tacka3)+str1(t1.tacka1,t1.tacka2,t1.tacka3)*str1(t1.tacka1,t1.tacka2,t1.tacka3))/(2*str1(t1.tacka1,t1.tacka2,t1.tacka3)*str2(t1.tacka1,t1.tacka2,t1.tacka3))));
     double a2=std::acos(std::sqrt((str2(t2.tacka1,t2.tacka2,t2.tacka3)*str2(t2.tacka1,t2.tacka2,t2.tacka3)+str3(t2.tacka1,t2.tacka2,t2.tacka3)*str3(t2.tacka1,t2.tacka2,t2.tacka3)-str1(t2.tacka1,t2.tacka2,t2.tacka3)*str1(t2.tacka1,t2.tacka2,t2.tacka3))/(2*str2(t2.tacka1,t2.tacka2,t2.tacka3)*str3(t2.tacka1,t2.tacka2,t2.tacka3))));
    double b2=std::acos(std::sqrt((-str2(t2.tacka1,t2.tacka2,t2.tacka3)*str2(t2.tacka1,t2.tacka2,t2.tacka3)+str3(t2.tacka1,t2.tacka2,t2.tacka3)*str3(t2.tacka1,t2.tacka2,t2.tacka3)+str1(t2.tacka1,t2.tacka2,t2.tacka3)*str1(t2.tacka1,t2.tacka2,t2.tacka3))/(2*str1(t2.tacka1,t2.tacka2,t2.tacka3)*str3(t2.tacka1,t2.tacka2,t2.tacka3))));
    double c2=std::acos(std::sqrt((str2(t2.tacka1,t2.tacka2,t2.tacka3)*str2(t2.tacka1,t2.tacka2,t2.tacka3)-str3(t2.tacka1,t2.tacka2,t2.tacka3)*str3(t2.tacka1,t2.tacka2,t2.tacka3)+str1(t2.tacka1,t2.tacka2,t2.tacka3)*str1(t2.tacka1,t2.tacka2,t2.tacka3))/(2*str1(t2.tacka1,t2.tacka2,t2.tacka3)*str2(t2.tacka1,t2.tacka2,t2.tacka3))));
     if(fabs(a1-a2)<epsilon && fabs(b1-b2)<epsilon && fabs(c1-c2)<epsilon ) return true;
    if(fabs(a1-b2)<epsilon && fabs(b1-a2)<epsilon && fabs(c1-c2)<epsilon ) return true;
    if(fabs(a1-c2)<epsilon && fabs(b1-b2)<epsilon && fabs(a1-c2)<epsilon ) return true;
    if(fabs(a1-a2)<epsilon && fabs(b1-c2)<epsilon && fabs(c1-b2)<epsilon) return true;
else return false;

    
}












int main ()
{ 

int n;

std::cout<<"Koliko zelite kreirati trouglova: ";
std::cin>>n;
std::vector<std::shared_ptr<Trougao>> v(n);
Tacka x,y,z;
for(int i=0;i<n;i++){
    try{
    int x1,x2,x3,y1,y2,y3;    
    
    std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
    std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
x.first=x1;
x.second=y1;
y.first=x2;
y.second=y2;
z.first=x3;
z.second=y3;
v[i]=(std::make_shared<Trougao>(x,y,z));}
catch(std::domain_error e){
    std::cout<<e.what()<<", ponovite unos!";
    i--;
}}
std::cout<<"Unesite vektor translacije (dx dy): ";
double dx,dy,ugao,k;
std::cin>>dx>>dy;
std::transform(v.begin(),v.end(),v.begin(),[dx,dy](std::shared_ptr<Trougao>v){v->Transliraj(dx,dy);return v;});
std::cout<<"Unesite ugao rotacije: ";
std::cin>>ugao;
std::transform(v.begin(),v.end(),v.begin(),[ugao](std::shared_ptr<Trougao>v){v->Rotiraj(v->DajCentar(),ugao);return v;});
std::cout<<"Unesite faktor skaliranja: ";
std::cin>>k;
std::transform(v.begin(),v.end(),v.begin(),[k](std::shared_ptr<Trougao>v){v->Skaliraj(v->DajTjeme(1),k);return v;});
std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao>v1,std::shared_ptr<Trougao>v2){if(v1->DajPovrsinu()>v2->DajPovrsinu())return true; return false;});
std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao>v){v->Ispisi();std::cout<<std::endl;});


    
    
    
    
    
    
    
    

    
    
	return 0;
}