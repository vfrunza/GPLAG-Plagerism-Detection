#include <iostream>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <vector>
#include <memory>
typedef std::pair<double,double> Tacka;
const double PI=4*std::atan(1.);
bool DobarIndeks(const int &indeks){if(indeks <=0 || indeks >3) throw std::range_error("Nekorektan indeks");return true;}
bool istisu(double x,double y){return std::fabs(x-y)<10E-10;}
void rotirajtacku(Tacka &t1, const Tacka &t2, double ugao){
    double x,y;
    x=t2.first+(t1.first-t2.first)*std::cos(ugao)-(t1.second-t2.second)*std::sin(ugao);
    y=t2.second+(t1.first-t2.first)*std::sin(ugao)+(t1.second-t2.second)*std::cos(ugao);
    t1.first=x;
    t1.second=y;
}
double DuzinaStranice(const Tacka &prva, const Tacka druga){
return std::sqrt((druga.first-prva.first)*(druga.first-prva.first)+(druga.second-prva.second)*(druga.second-prva.second));
}
class Trougao{
Tacka t1,t2,t3;
public:

Trougao(const Tacka &T1, const Tacka &T2, const Tacka &T3){
    if(!Orijentacija(T1,T2,T3)) throw std::domain_error("Nekorektne pozicije tjemena");
this->t1=T1;this->t2=T2;this->t3=T3;
}

void Postavi(const Tacka &T1,const Tacka &T2,const Tacka &T3){
    if(!Orijentacija(T1,T2,T3)) throw std::domain_error("Nekorektne pozicije tjemena");
this->t1=T1;this->t2=T2;this->t3=T3;
}

void Postavi(int indeks, const Tacka T){
    if(DobarIndeks(indeks))
    ;
    if(indeks == 1){this->t1=T;return;}
    if(indeks == 2){this->t2=T;return;}
    this->t3=T;
}
static int Orijentacija(const Tacka &T1, const Tacka &T2, const Tacka &T3){
    auto izraz = T1.first*(T2.second - T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second);
if(izraz>0.) return 1;
if(izraz<0.) return -1;
return 0;
}

Tacka DajTjeme(int indeks)const{
    if(DobarIndeks(indeks))
    ;
    if(indeks == 1){return this->t1;}
    if(indeks == 2){return this->t2;}
    return this->t3;
}

double DajStranicu(int indeks)const{
    if(DobarIndeks(indeks))
    ;
    if(indeks == 1) return DuzinaStranice(this->t2,this->t3);
    if(indeks == 2) return DuzinaStranice(this->t1,this->t3);
    return DuzinaStranice(this->t1,this->t2);
}

double DajUgao(int indeks)const{
    if(DobarIndeks(indeks))
    ;
    double a,b,c; //stranice trougla
    a=DajStranicu(1);
    b=DajStranicu(2);
    c=DajStranicu(3);
if(indeks==1)//traži se alfa
    return std::acos((b*b+c*c-a*a)/(2*b*c));
if(indeks==2)//traži se beta
    return std::acos((a*a+c*c-b*b)/(2*a*c));
    return std::acos((a*a+b*b-c*c)/(2*a*b));
}

Tacka DajCentar()const{
    Tacka izlaz;
    izlaz.first=(this->t1.first+this->t2.first+this->t3.first)/3;
    izlaz.second=(this->t1.second+this->t2.second+this->t3.second)/3;
    return izlaz; //znam da je neefikasno i ružno ali je preglomazno strpat' sve u jedno.
}

double DajObim()const{
    return(this->DajStranicu(1)+this->DajStranicu(2)+this->DajStranicu(3));
}

double DajPovrsinu()const{
auto izraz = this->t1.first*(this->t2.second - this->t3.second)-this->t2.first*(this->t1.second-this->t3.second)+this->t3.first*(this->t1.second-this->t2.second);
return .5*(std::fabs(izraz));
}

bool DaLiJePozitivnoOrijentiran()const{
    if(Orijentacija(this->t1,this->t2,this->t3)==1)return true;
    return false;
}

bool DaLiJeUnutra(const Tacka &t)const{
if(Orijentacija(this->t1,this->t2,this->t3)>0 &&
Orijentacija(this->t1,this->t2,t)>0 &&
Orijentacija(this->t2,this->t3,t)>0 &&
Orijentacija(this->t3,this->t1,t)>0) return true;
if(Orijentacija(this->t1,this->t2,this->t3)<0 &&
Orijentacija(this->t1,this->t2,t)<0 &&
Orijentacija(this->t2,this->t3,t)<0 &&
Orijentacija(this->t3,this->t1,t)<0) return true;
return false;
}

void Ispisi()const{
    std::cout<<"(("<<this->t1.first<<","<<this->t1.second<<"),("<<this->t2.first<<","<<this->t2.second<<"),("
    <<this->t3.first<<","<<this->t3.second<<"))";
}

void Transliraj(double delta_x,double delta_y){
    this->t1.first+=delta_x;
    this->t2.first+=delta_x;
    this->t3.first+=delta_x;
this->t1.second+=delta_y;
this->t2.second+=delta_y;
this->t3.second+=delta_y;
}

void Centriraj(const Tacka &t){
    Tacka cent=this->DajCentar();
    double delta_x=t.first-cent.first,delta_y=t.second-cent.second;
    this->Transliraj(delta_x,delta_y);
}
void Rotiraj(const Tacka &t, double ugao){ // ne valja rotiranje y koordinata
    rotirajtacku(t1,t,ugao);
    rotirajtacku(t2,t,ugao);
    rotirajtacku(t3,t,ugao);
}
void Rotiraj(double ugao){Rotiraj(this->DajCentar(), ugao);}

void Skaliraj(const Tacka &t, double faktor){
if(std::fabs(faktor-0)<10E-10) throw std::domain_error("Nekorektan faktor skaliranja");
    this->t1.first=t.first+faktor*(this->t1.first-t.first);
    this->t1.second=t.second+faktor*(this->t1.second-t.second);
this->t2.first=t.first+faktor*(this->t2.first-t.first);
this->t2.second=t.second+faktor*(this->t2.second-t.second);
this->t3.first=t.first+faktor*(this->t3.first-t.first);
this->t3.second=t.second+faktor*(this->t3.second-t.second);
}

void Skaliraj(double faktor){Skaliraj(this->DajCentar(),faktor);}

friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
int main (){
std::cout<<"Koliko zelite kreirati trouglova: "; unsigned n;
std::cin>>n;
std::vector<std::shared_ptr<Trougao>> v(n,nullptr);
unsigned static i=0;
a:try{
Tacka prvo,drugo,trece;
for(;i<n;i++){
    std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
    std::cin>>prvo.first>>prvo.second;
    std::cin>>drugo.first>>drugo.second;
    std::cin>>trece.first>>trece.second;
v[i]=std::make_shared<Trougao>(Trougao(prvo,drugo,trece));
}
}catch(std::bad_alloc){std::cout<<"Problemi sa memorijom, molimo Vas ponovite unos za ";goto a;}
catch(std::domain_error &ex){std::cout<<ex.what();std::cout<<", ponovite unos!"<<std::endl;goto a;}
catch(std::range_error &ex){std::cout<<ex.what();}
double delta_x,delta_y,ugao,faktor;
std::cout<<"Unesite vektor translacije (dx dy): ";std::cin>>delta_x>>delta_y;
std::cout<<"Unesite ugao rotacije: ";std::cin>>ugao;
std::cout<<"Unesite faktor skaliranja: ";std::cin>>faktor;
std::transform(v.begin(),v.end(),v.begin(),
[delta_x,delta_y,ugao,faktor](std::shared_ptr<Trougao>trougao){
    trougao->Transliraj(delta_x,delta_y);
    return trougao;
});
std::transform(v.begin(),v.end(),v.begin(),
[delta_x,delta_y,ugao,faktor](std::shared_ptr<Trougao>trougao){
    trougao->Rotiraj(ugao);
    return trougao;
});
std::transform(v.begin(),v.end(),v.begin(),
[delta_x,delta_y,ugao,faktor](std::shared_ptr<Trougao>trougao){
    trougao->Skaliraj(trougao->DajTjeme(1),faktor); return trougao;
});
std::sort(v.begin(),v.end(),[](const std::shared_ptr<Trougao> &prvi, const std::shared_ptr<Trougao> &drugi){
return prvi->DajPovrsinu()<drugi->DajPovrsinu();});
std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
std::for_each(v.begin(),v.end(),[](const std::shared_ptr<Trougao> &trougao){
trougao->Ispisi();std::cout<<std::endl;});

auto it_najmanjeg_obima=std::max_element(v.begin(),v.end(),[](const std::shared_ptr<Trougao>&prvi,const std::shared_ptr<Trougao>&drugi){
return prvi->DajObim()>drugi->DajObim();
});
std::cout<<"Trougao sa najmanjim obimom: ";
(*it_najmanjeg_obima)->Ispisi();std::cout<<std::endl;
std::vector<std::pair<Trougao,Trougao>> identicni,podudarni,slicni;
for(unsigned i=0;i<v.size();i++)
for(unsigned j=i+1;j<v.size();j++){
    if(DaLiSuIdenticni(*v[i],*v[j])) identicni.push_back(std::make_pair(*v[i],*v[j]));
    if(DaLiSuPodudarni(*v[i],*v[j])) podudarni.push_back(std::make_pair(*v[i],*v[j]));
    if(DaLiSuSlicni(*v[i],*v[j])) slicni.push_back(std::make_pair(*v[i],*v[j]));
}
if(identicni.size()){
    std::cout<<"Parovi identicnih trouglova:\n";
for(unsigned i=0;i<identicni.size();i++){ identicni[i].first.Ispisi();std::cout<<" i "; identicni[i].second.Ispisi();std::cout<<std::endl;}
}
else std::cout<<"Nema identicnih trouglova!\n";
if(podudarni.size()){
    std::cout<<"Parovi podudarnih trouglova:\n";
for(unsigned i=0;i<podudarni.size();i++){ podudarni[i].first.Ispisi();std::cout<<" i "; podudarni[i].second.Ispisi();std::cout<<std::endl;}
}
else std::cout<<"Nema podudarnih trouglova!\n";
if(slicni.size()){
    std::cout<<"Parovi slicnih trouglova:\n";
for(unsigned i=0;i<slicni.size();i++){slicni[i].first.Ispisi();std::cout<<" i "; slicni[i].second.Ispisi();std::cout<<std::endl;}
}
if(!slicni.size()) std::cout<<"Nema slicnih trouglova!";
	return 0;
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    std::vector<Tacka> v1,v2;
v1.push_back(t1.DajTjeme(1));
v1.push_back(t1.DajTjeme(2));
v1.push_back(t1.DajTjeme(3));
    v2.push_back(t2.DajTjeme(1));
    v2.push_back(t2.DajTjeme(2));
    v2.push_back(t2.DajTjeme(3));
std::sort(v1.begin(),v1.end(),[](const Tacka &prva, const Tacka &druga){return prva.first>druga.first;});
std::sort(v2.begin(),v2.end(),[](const Tacka &prva, const Tacka &druga){return prva.first>druga.first;});
for(unsigned i=0;i<3;i++)
    if(!(istisu(v1[i].first,v2[i].first) && istisu(v1[i].second,v2[i].second))) return false;
return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
std::vector<std::pair<Tacka,double>> prviv,drugiv;
std::vector<Tacka> treciv{t1.t1,t1.t2,t1.t3},cetvrtiv{t2.t1,t2.t2,t2.t3};
unsigned i=0;
while(true){if(i==3) break;
    prviv.push_back(std::make_pair(treciv[i],t1.DajStranicu(i+1)));
    drugiv.push_back(std::make_pair(cetvrtiv[i],t2.DajStranicu(i+1)));
    i++;
}
std::sort(prviv.begin(),prviv.end(),[](const std::pair<Tacka,double>t1,const std::pair<Tacka,double>t2){return t1.second<t2.second;});
std::sort(drugiv.begin(),drugiv.end(),[](const std::pair<Tacka,double>t1,const std::pair<Tacka,double>t2){return t1.second<t2.second;});
if(Trougao::Orijentacija(prviv[0].first,prviv[1].first,prviv[2].first)!=Trougao::Orijentacija(drugiv[0].first,drugiv[1].first,drugiv[2].first))return false;
bool okej=true;
i=0;
while(true){if(i==3)break; if(!istisu(prviv[i].second,drugiv[i].second)){okej=false;break;}i++;}
return okej;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
//     double a1,b1,c1,a2,b2,c2; std::vector<std::pair<double,double>>prviv,drugiv;
// a1=t1.DajUgao(1);prviv.push_back(std::make_pair(t1.DajStranicu(1),a1));
// b1=t1.DajUgao(2);prviv.push_back(std::make_pair(t1.DajStranicu(2),b1));
// c1=t1.DajUgao(3);prviv.push_back(std::make_pair(t1.DajStranicu(3),c1));
// a2=t2.DajUgao(1);drugiv.push_back(std::make_pair(t2.DajStranicu(1),a2));
// b2=t2.DajUgao(2);drugiv.push_back(std::make_pair(t2.DajStranicu(2),b2));
// c2=t2.DajUgao(3);drugiv.push_back(std::make_pair(t2.DajStranicu(3),c2));
//     std::sort(prviv.begin(),prviv.end(),[](const std::pair<double,double> &prva,const std::pair<double,double> &druga){
//         return prva.second>druga.second;
//     });
//     std::sort(drugiv.begin(),drugiv.end(),[](const std::pair<double,double> &prva,const std::pair<double,double> &druga){
//         return prva.second>druga.second;
//     });
// unsigned i=0;
// while(true){if(i==3)break; if(!istisu(prviv[i].second,drugiv[i].second))return false;i++;}
// if(istisu(prviv[0].first/drugiv[0].first,prviv[1].first/drugiv[1].first)&&
// istisu(prviv[0].first/drugiv[0].first,prviv[2].first/drugiv[2].first)) return true;
// return false;
std::vector<std::pair<Tacka,double>> prviv,drugiv;
std::vector<Tacka> treciv{t1.t1,t1.t2,t1.t3},cetvrtiv{t2.t1,t2.t2,t2.t3};
unsigned i=0;
while(true){if(i==3) break;
    prviv.push_back(std::make_pair(treciv[i],t1.DajUgao(i+1)));
    drugiv.push_back(std::make_pair(cetvrtiv[i],t2.DajUgao(i+1)));
    i++;
}
std::sort(prviv.begin(),prviv.end(),[](const std::pair<Tacka,double>t1,const std::pair<Tacka,double>t2){return t1.second<t2.second;});
std::sort(drugiv.begin(),drugiv.end(),[](const std::pair<Tacka,double>t1,const std::pair<Tacka,double>t2){return t1.second<t2.second;});
if(Trougao::Orijentacija(prviv[0].first,prviv[1].first,prviv[2].first)!=Trougao::Orijentacija(drugiv[0].first,drugiv[1].first,drugiv[2].first))return false;
bool okej=true;
i=0;
while(true){if(i==3)break; if(!istisu(prviv[i].second,drugiv[i].second)){okej=false;break;}i++;}
return okej;
}




