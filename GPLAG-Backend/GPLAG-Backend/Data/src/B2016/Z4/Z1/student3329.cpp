#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

const double EPS = 1E-10;
typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka tc1,tc2,tc3;
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
    bool DaLiJePozitivnoOrijentisan() const;
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
    if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    tc1=t1; tc2=t2; tc3=t3;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    tc1=t1; tc2=t2; tc3=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks==1) tc1=t;
    else if(indeks==2) tc2=t;
    else if(indeks==3) tc3=t;
    else throw std::range_error("Nekorektan indeks");
}
int Ori(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Ori(t1, t2, t3)>0) return 1;
    else if(Ori(t1, t2, t3)<0) return -1; else return 0;
}
Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks==1) return tc1;
    else if(indeks==2) return tc2;
    else if(indeks==3) return tc3;
    else throw std::range_error("Nekorektan indeks");
}
double Trougao::DajStranicu(int indeks) const{
    if(indeks==1) return sqrt(pow(tc2.first-tc3.first,2)+pow(tc2.second-tc3.second,2));
    else if(indeks==2) return sqrt(pow(tc1.first-tc3.first,2)+pow(tc1.second-tc3.second,2));
    else if(indeks==3) return sqrt(pow(tc1.first-tc2.first,2)+pow(tc1.second-tc2.second,2));
    else throw std::range_error("Nekorektan indeks");
}
double Trougao::DajUgao(int indeks) const{
    if(indeks==1) return acos((pow(DajStranicu(2),2)+pow(DajStranicu(3),2)-pow(DajStranicu(1),2))/(2*DajStranicu(2)*DajStranicu(3)));
    else if(indeks==2) return acos((pow(DajStranicu(1),2)+pow(DajStranicu(3),2)-pow(DajStranicu(2),2))/(2*DajStranicu(1)*DajStranicu(3)));
    else if(indeks==3) return acos((pow(DajStranicu(1),2)+pow(DajStranicu(2),2)-pow(DajStranicu(3),2))/(2*DajStranicu(1)*DajStranicu(2)));
    else throw std::range_error("Nekorektan indeks");
}
Tacka Trougao::DajCentar() const{
    Tacka t; t.first=(tc1.first+tc2.first+tc3.first)/3; t.second=(tc1.second+tc2.second+tc3.second)/3;
    return t;
}
double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu() const{
    return abs(Ori(tc1, tc2, tc3))/2;
}
bool Trougao::DaLiJePozitivnoOrijentisan() const{
    if(Orijentacija(tc1, tc2, tc3)>0) return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    return Orijentacija(tc1, tc2, t)>0 && Orijentacija(tc2, tc3, t)>0 && Orijentacija(tc3, tc1, t);
}
void Trougao::Ispisi() const{
    std::cout<<"(("<<tc1.first<<","<<tc1.second<<"),("<<tc2.first<<","<<tc2.second<<"),("<<tc3.first<<","<<tc3.second<<"))";
}
void Trougao::Transliraj(double delta_x, double delta_y){
    tc1.first+=delta_x; tc1.second+=delta_y;
    tc2.first+=delta_x; tc2.second+=delta_y;
    tc3.first+=delta_x; tc3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    Tacka csad=this->DajCentar();
    double dx(t.first-csad.first);
    double dy(t.second-csad.second);
    Transliraj(dx, dy);
}
void Rot(Tacka &t, const Tacka &ref, double ugao){ //pomocna
    double x, y;
    x=ref.first+std::cos(ugao)*(t.first-ref.first)-std::sin(ugao)*(t.second-ref.second);
    y=ref.second+std::sin(ugao)*(t.first-ref.first)+std::cos(ugao)*(t.second-ref.second);
    t.first=x; t.second=y;
}
void Skal(Tacka &t, const Tacka &ref, double faktor){ //pomocna
    t.first=ref.first+faktor*(t.first-ref.first);
    t.second=ref.second+faktor*(t.second-ref.second);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    Rot(tc1, t, ugao); Rot(tc2, t, ugao); Rot(tc3, t, ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(!faktor) throw std::domain_error("Nekorektan faktor skaliranja");
    Skal(tc1, t, faktor); Skal(tc2, t, faktor); Skal(tc3, t, faktor);
}
void Trougao::Rotiraj(double ugao){
    Tacka centar=this->DajCentar();
    Rot(tc1, centar, ugao); Rot(tc2, centar, ugao); Rot(tc3, centar, ugao);
}
void Trougao::Skaliraj(double faktor){
    if(!faktor) throw std::domain_error("Nekorektan faktor skaliranja");
    Tacka centar=this->DajCentar();
    Skal(tc1, centar, faktor); Skal(tc2, centar, faktor); Skal(tc3, centar, faktor);
}
bool PorediDbl(double x, double y){
    return abs(x-y)<EPS;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    int br(0);
    for(int i=1; i<=3; i++)
        for(int j=1; j<=3; j++)
            if(PorediDbl(t1.DajTjeme(i).first, t2.DajTjeme(j).first) && PorediDbl(t1.DajTjeme(i).second, t2.DajTjeme(j).second)){br++;break;}
    if(br==3) return true; else return false;
}
double TriTackeZaUgao(const Tacka &tref, const Tacka &t1, const Tacka &t2){
    Tacka vecA({t1.first-tref.first, t1.second-tref.second});
    Tacka vecB({t2.first-tref.first, t2.second-tref.second});
    return acos((vecA.first*vecB.first+vecA.second*vecB.second)/(sqrt(vecA.first*vecA.first+vecA.second*vecA.second)*sqrt(vecB.first*vecB.first+vecB.second*vecB.second)));
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    for(int i=1; i<=3; i++){
        Trougao t1new(t1);
        t1new.Centriraj(t2.DajCentar());
        double ugel(TriTackeZaUgao(t1new.DajCentar(), t1new.DajTjeme(1), t2.DajTjeme(i)));
        while(1)
            if(ugel-360/(180/(atan(1.)))>360/(180/(atan(1.)))) ugel-=360/(180/(atan(1.))); else break;
        t1new.Rotiraj(ugel);
        if(DaLiSuIdenticni(t1new, t2)) return true;
    }
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::vector<double> vt1, vt2;
    Trougao t2temp(t2);
    for(int i=1; i<=3; i++){
        vt1.push_back(t1.DajStranicu(i));
        vt2.push_back(t2temp.DajStranicu(i));
    }
    std::sort(vt1.begin(), vt1.end());
    std::sort(vt2.begin(), vt2.end());
    
    double k(vt1[0]/vt2[0]);
    for(int i=1; i<3; i++)
        if(!PorediDbl(vt1[i]/vt2[i], k)) return false;
    t2temp.Skaliraj(t2temp.DajCentar(), k);
    return DaLiSuPodudarni(t2temp, t1);
}

int main (){
    std::cout<<"Koliko zelite kreirati trouglova: "; int n; std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i=0; i<n; i++){
        double x1,x2,x3,y1,y2,y3; bool bio_izuzetak(true);
        while(bio_izuzetak){
            try{
                bio_izuzetak=false;
                std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
                std::cin>>x1>>y1>>x2>>y2>>x3>>y3; Trougao t({{x1,y1}, {x2,y2}, {x3, y3}});
                v[i] = std::make_shared<Trougao>(t);
            }catch(std::domain_error izuzetak){
                std::cout<<izuzetak.what()<<", ponovite unos!"<<std::endl; bio_izuzetak=true;
            }
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): "; double dx,dy; std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: "; double ugao; std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: "; double faktor; std::cin>>faktor;
    std::transform(v.begin(), v.end(), v.begin(), [dx,dy,faktor,ugao](std::shared_ptr<Trougao> p){
        p->Transliraj(dx,dy); p->Rotiraj(ugao); p->Skaliraj(p->DajTjeme(1), faktor);
        return p;
    });
    auto vn(v);
    std::sort(vn.begin(), vn.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
        return p1->DajPovrsinu()<p2->DajPovrsinu();
    });
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(vn.begin(), vn.end(), [](std::shared_ptr<Trougao> p){
        p->Ispisi(); std::cout<<std::endl;
    });
    auto a=std::max_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> p1, std::shared_ptr<Trougao> p2){
        return p1->DajObim()>p2->DajObim();
    });
    std::cout<<"Trougao sa najmanjim obimom: "; (*a)->Ispisi();
    int b(0);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)
        if(DaLiSuIdenticni(*v[i], *v[j])){
            if(!b) std::cout<<std::endl<<"Parovi identicnih trouglova:"<<std::endl; b++;
            v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi();std::cout<<std::endl;}
    } if(!b) std::cout<<std::endl<<"Nema identicnih trouglova!"<<std::endl;
    
    b=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)
        if(DaLiSuPodudarni(*v[i], *v[j])){
            if(!b) std::cout<<"Parovi podudarnih trouglova:"<<std::endl; b++;
            v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi(); std::cout<<std::endl;}
    } if(!b) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    
    b=0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)
        if(DaLiSuSlicni(*v[i], *v[j])){
            if(!b) std::cout<<"Parovi slicnih trouglova:"<<std::endl; b++;
            v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi();std::cout<<std::endl;}
    } if(!b) std::cout<<"Nema slicnih trouglova!"<<std::endl;
	return 0;
}