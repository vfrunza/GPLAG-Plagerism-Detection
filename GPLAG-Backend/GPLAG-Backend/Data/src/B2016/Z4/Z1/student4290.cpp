#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <algorithm>
typedef std::pair<double,double> Tacka;
class Trougao{
    std::vector<Tacka> t;
    static bool Imal(const Tacka &t,const std::vector<Tacka> &v);
    public:
        Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
            if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
            t.push_back(t1);t.push_back(t2);t.push_back(t3);
        }
        void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
            if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
            t.push_back(t1);t.push_back(t2);t.push_back(t3);
        }
        void Postavi(int indeks,const Tacka &t1);
        static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3);
        Tacka DajTjeme(int indeks) const;
        double DajStranicu(int indeks) const;
        double DajUgao(int indeks) const;
        Tacka DajCentar() const{return std::make_pair((t[0].first+t[1].first+t[2].first)/3,(t[0].second+t[1].second+t[2].second)/3);}
        double DajObim() const{return (DajStranicu(1)+DajStranicu(2)+DajStranicu(3));}
        double DajPovrsinu() const{return 0.5*std::abs(t[0].first*(t[1].second-t[2].second)-t[1].first*(t[0].second-t[2].second)+t[2].first*(t[0].second-t[1].second));}
        bool DaLiJePozitivnoOrijentiran () const{return Orijentacija(t[0],t[1],t[2])>0;}
        bool DaLiJeUnutra(const Tacka &t1) const;
        void Ispisi() const{std::cout<<"( ("<<t[0].first<<","<<t[0].second<<") , ("<<t[1].first<<","<<t[1].second<<") , ("<<t[2].first<<","<<t[2].second<<") )"<<std::endl;}
        void Transliraj (double delta_x,double delta_y);
        void Centriraj(const Tacka &t);
        void Rotiraj(const Tacka &t, double ugao);
        void Skaliraj(const Tacka &t, double faktor);
        void Rotiraj(double ugao);
        void Skaliraj(double faktor);
        friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){return (Imal(t1.t[0],t2.t)&&Imal(t1.t[1],t2.t)&&Imal(t1.t[2],t2.t));}
        friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
        friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};
bool Trougao::Imal(const Tacka &t1,const std::vector<Tacka> &v){
    for(int i=0;i<v.size();i++)if(v[i]==t1)return true;
    return false;
}
int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    int o=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    if(o>0)return 1;
    if(o<0)return -1;
    return 0;
}
void Trougao::Postavi(int indeks,const Tacka &t1){
    if(indeks<1 || indeks>3)throw std::range_error("Nekorektan index");
    t[indeks-1]=t1;
    if(Orijentacija(t[0],t[1],t[2])==0)throw std::domain_error("Nekorektne pozicije tjemena");
}
Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks<1 || indeks>3)throw std::range_error("Nekorektan index");
    return t[indeks-1];
}
double Trougao::DajStranicu(int indeks) const{
    if(indeks<1 || indeks>3)throw std::range_error("Nekorektan index");
    double duzina;
    if(indeks==1)duzina=std::sqrt(std::pow(2,t[1].first-t[2].first)+std::pow(2,t[1].second-t[2].second));
    if(indeks==2)duzina=std::sqrt(std::pow(2,t[0].first-t[2].first)+std::pow(2,t[0].second-t[2].second));
    if(indeks==3)duzina=std::sqrt(std::pow(2,t[1].first-t[0].first)+std::pow(2,t[1].second-t[0].second));
    return duzina;
}
double Trougao::DajUgao(int indeks) const{
    if(indeks<1 || indeks>3)throw std::range_error("Nekorektan index");
    double ugao;
    if(indeks==1)ugao=std::acos(((DajStranicu(2)*DajStranicu(2))+(DajStranicu(3)*DajStranicu(3))-(DajStranicu(1)*DajStranicu(1)))/(2*DajStranicu(2)*DajStranicu(3)));
    if(indeks==2)ugao=std::acos(((DajStranicu(1)*DajStranicu(1))+(DajStranicu(3)*DajStranicu(3))-(DajStranicu(2)*DajStranicu(2)))/(2*DajStranicu(1)*DajStranicu(3)));
    if(indeks==3)ugao=std::acos(((DajStranicu(2)*DajStranicu(2))+(DajStranicu(1)*DajStranicu(1))-(DajStranicu(3)*DajStranicu(3)))/(2*DajStranicu(2)*DajStranicu(1)));
    return ugao;
}
void Trougao::Transliraj(double delta_x,double delta_y){
    for(int i=0;i<3;i++){
        t[i].first+=delta_x;
        t[i].second+=delta_y;
    }
}
void Trougao::Centriraj(const Tacka &t){
    Tacka c=(*this).DajCentar();
    double dex=t.first-c.first;
    double dey=t.second-c.second;
    (*this).Transliraj(dex,dey);
}
void Trougao::Rotiraj(const Tacka &t,double ugao){
    Trougao::t[0].first=t.first+((Trougao::t[0].first-t.first)*std::cos(ugao))-(Trougao::t[0].second-t.second)*std::sin(ugao);
    Trougao::t[1].first=t.first+((Trougao::t[1].first-t.first)*std::cos(ugao))-(Trougao::t[1].second-t.second)*std::sin(ugao);
    Trougao::t[2].first=t.first+((Trougao::t[2].first-t.first)*std::cos(ugao))-(Trougao::t[2].second-t.second)*std::sin(ugao);
    Trougao::t[0].second=t.second+((Trougao::t[0].first-t.first)*std::sin(ugao))-(Trougao::t[0].second-t.second)*std::cos(ugao);
    Trougao::t[1].second=t.second+((Trougao::t[1].first-t.first)*std::sin(ugao))-(Trougao::t[1].second-t.second)*std::cos(ugao);
    Trougao::t[2].second=t.second+((Trougao::t[2].first-t.first)*std::sin(ugao))-(Trougao::t[2].second-t.second)*std::cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t,double faktor){
    if(faktor==0)throw std::domain_error("Nekorektan faktor skaliranja");
    Trougao::t[0].first=t.first+faktor*(Trougao::t[0].first-t.first);
    Trougao::t[0].second=t.second+faktor*(Trougao::t[0].second-t.second);
    Trougao::t[1].first=t.first+faktor*(Trougao::t[1].first-t.first);
    Trougao::t[1].second=t.second+faktor*(Trougao::t[1].second-t.second);
    Trougao::t[2].first=t.first+faktor*(Trougao::t[2].first-t.first);
    Trougao::t[2].second=t.second+faktor*(Trougao::t[2].second-t.second);
}
void Trougao::Rotiraj(double ugao){
    Tacka c=this->DajCentar();
    this->Rotiraj(c,ugao);
}
void Trougao::Skaliraj(double faktor){
    Tacka c(this->DajCentar());
    this->Skaliraj(c,faktor);
}
bool Trougao::DaLiJeUnutra(const Tacka &t1)const{
    if(Orijentacija(t[0],t[1],t[2])>0 && Orijentacija(t[0],t[1],t1)>0 && Orijentacija(t[1],t[2],t1)>0 && Orijentacija(t[2],t[0],t1)>0)return true;
    else if(Orijentacija(t[0],t[1],t[2])<0 && Orijentacija(t[0],t[1],t1)<0 && Orijentacija(t[1],t[2],t1)<0 && Orijentacija(t[2],t[0],t1)<0)return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
    if((t1.DajStranicu(1)==t2.DajStranicu(1)||t1.DajStranicu(1)==t2.DajStranicu(2)||t1.DajStranicu(1)==t2.DajStranicu(3))&&(t1.DajStranicu(2)==t2.DajStranicu(1)||t1.DajStranicu(2)==t2.DajStranicu(2)||t1.DajStranicu(2)==t2.DajStranicu(3))
        &&(t1.DajStranicu(3)==t2.DajStranicu(1)||t1.DajStranicu(3)==t2.DajStranicu(2)||t1.DajStranicu(3)==t2.DajStranicu(3))&&(
            (Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2])>0 && Trougao::Orijentacija(t2.t[0],t2.t[1],t2.t[2])>0)||(Trougao::Orijentacija(t1.t[0],t1.t[1],t1.t[2])<0 && Trougao::Orijentacija(t2.t[0],t2.t[1],t2.t[2])<0)))return true;
        return false;
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
    if(DaLiSuPodudarni(t1,t2))return true;
    if((t1.DajStranicu(1)/t2.DajStranicu(1))==(t1.DajStranicu(2)/t2.DajStranicu(2))==(t1.DajStranicu(3)/t2.DajStranicu(3)))return true;
    return false;
}
int main (){
    Trougao t({1,3},{4,5},{2,7});
    std::cout<<t.DajStranicu(3)<<std::endl<<t.DajStranicu(1)<<std::endl<<t.DajStranicu(2)<<std::endl<<t.DajObim()<<std::endl;
    t.Skaliraj(3);
    t.Rotiraj(2);
    t.Ispisi();
	return 0;
}