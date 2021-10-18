/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <limits>
#include <memory>
#include <vector>
#include <algorithm>


const double eps=std::numeric_limits<double>::epsilon();
const double pi=std::atan(1)*4;
typedef std::pair<double, double> Tacka;

double UdaljenostTacaka(const Tacka &t1, const Tacka &t2){
    return std::sqrt((t2.first-t1.first)*(t2.first-t1.first) + (t2.second-t1.second)*(t2.second-t1.second));
}
double S(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return t1.first+(t2.second-t3.second)-t2.first*(t3.second-t1.second)-t3.first*(t1.second-t2.second);
}
class Trougao{
    Tacka t1, t2, t3;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(S(t1, t2, t3)>0) return 1;
        else if (S(t1, t2, t3)<0) return -1;
        else return 0;
    }
    
        Tacka DajTjeme(int indeks) const;
        double DajStranicu(int indeks) const;
        double DajUgao(int indeks) const;
        Tacka DajCentar() const;
        double DajObim() const;
        double DajPovrsinu() const;
        bool DaLiJePozitivnoOrijentiran() const { return Orijentacija(t1,t2,t3)==1; }
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
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if((t1.t1==t2.t1) || (t1.t1==t2.t2) || (t1.t1==t2.t3))
        if((t1.t2==t2.t1) || (t1.t1==t2.t2) || (t1.t2==t2.t3))
            if((t1.t3==t2.t1) || (t1.t3==t2.t2) || (t1.t3==t2.t3))
                return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    if(t1.DajStranicu(1)==t2.DajStranicu(1))
        if(t1.DajStranicu(2)==t2.DajStranicu(2))
            if(t1.DajStranicu(3)==t2.DajStranicu(3))
                return true;
     if(t1.DajStranicu(1)==t2.DajStranicu(2))
        if(t1.DajStranicu(2)==t2.DajStranicu(3))
            if(t1.DajStranicu(3)==t2.DajStranicu(1))
                return true;
     if(t1.DajStranicu(1)==t2.DajStranicu(3))
        if(t1.DajStranicu(2)==t2.DajStranicu(1))
            if(t1.DajStranicu(3)==t2.DajStranicu(2))
                return true;
    return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double a1, b1, c1, a2, b2, c2;
    if(t1.DajStranicu(1)>t1.DajStranicu(2) && t1.DajStranicu(1)>t1.DajStranicu(3)){
        a1=t1.DajStranicu(1);
        if(t1.DajStranicu(2)>t1.DajStranicu(3)){
            b1=t1.DajStranicu(2);
            c1=t1.DajStranicu(3);
        }
        else {
            b1=t1.DajStranicu(3);
            c1=t1.DajStranicu(2);
        }
    }
    else if(t1.DajStranicu(2)>t1.DajStranicu(1) && t1.DajStranicu(2)>t1.DajStranicu(3)){
        a1=t1.DajStranicu(2);
        if(t1.DajStranicu(1)>t1.DajStranicu(3)){
            b1=t1.DajStranicu(1);
            c1=t1.DajStranicu(3);
        }
        else {
            b1=t1.DajStranicu(3);
            c1=t1.DajStranicu(1);
        }
    }
    else {
        a1=t1.DajStranicu(3);
        if(t1.DajStranicu(1)>t1.DajStranicu(2)){
            b1=t1.DajStranicu(1);
            c1=t1.DajStranicu(2);
        }
        else{
            b1=t1.DajStranicu(2);
            c1=t1.DajStranicu(1);
        }
    }
    
    if(t2.DajStranicu(1)>t2.DajStranicu(2) && t2.DajStranicu(1)>t2.DajStranicu(3)){
        a2=t2.DajStranicu(1);
        if(t2.DajStranicu(2)>t2.DajStranicu(3)){
            b2=t2.DajStranicu(2);
            c2=t2.DajStranicu(3);
        }
        else {
            b2=t2.DajStranicu(3);
            c2=t2.DajStranicu(2);
        }
    }
    else if(t2.DajStranicu(2)>t2.DajStranicu(1) && t2.DajStranicu(2)>t2.DajStranicu(3)){
        a2=t2.DajStranicu(2);
        if(t2.DajStranicu(1)>t2.DajStranicu(3)){
            b2=t2.DajStranicu(1);
            c2=t2.DajStranicu(3);
        }
        else {
            b2=t2.DajStranicu(3);
            c2=t2.DajStranicu(1);
        }
    }
    else {
        a2=t2.DajStranicu(3);
        if(t2.DajStranicu(1)>t2.DajStranicu(2)){
            b2=t2.DajStranicu(1);
            c2=t2.DajStranicu(2);
        }
        else{
            b2=t2.DajStranicu(2);
            c2=t2.DajStranicu(1);
        }
    }
    
    if(a1/a2==(int)(a1/a2) && b1/b2== (int)(b1/b2) && c1/c2==(int)(c1/c2)) return true;
    return false;
}
void Trougao::Rotiraj(double ugao){
    this->Rotiraj(this->DajCentar(), ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first=t.first+faktor*(t1.first-t.first);
    t1.second=t.second+faktor*(t1.second-t.second);
    t2.first=t.first+faktor*(t2.first-t.first);
    t2.second=t.second+faktor*(t2.second-t.second);
    t3.first=t.first+faktor*(t3.first-t.first);
    t3.second=t.second+faktor*(t3.second-t.second);
}
void Trougao::Centriraj(const Tacka &t){
    Tacka temp=this->DajCentar();
    this->Transliraj(t.first-temp.first, t.second-temp.second);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    t1.first=t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao);
    t1.second=t.second+(t1.first-t.first)*std::sin(ugao)-(t1.second-t.second)*std::cos(ugao);
    t2.first=t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao);
    t2.second=t.second+(t2.first-t.first)*std::sin(ugao)-(t2.second-t.second)*std::cos(ugao);
    t3.first=t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao);
    t3.second=t.second+(t3.first-t.first)*std::sin(ugao)-(t3.second-t.second)*std::cos(ugao);
}
void Trougao::Transliraj(double delta_x, double delta_y) {
    t1.first+=delta_x;
    t2.first+=delta_x;
    t3.first+=delta_x;
    t1.second+=delta_y;
    t2.second+=delta_y;
    t3.second+=delta_y;
}
void Trougao::Ispisi() const{
    std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<
    "),("<<t3.first<<","<<t3.second<<"))"<<std::endl;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if(std::fabs(std::fabs(S(t1,t2,t))/2 + std::fabs(S(t2,t3,t))/2 + std::fabs(S(t3,t1,t))/2 - this->DajPovrsinu())<eps) return true;
    return false;
}
double Trougao::DajPovrsinu() const{
    return std::fabs(S(t1,t2,t3))/2;
}
double Trougao::DajObim() const {
    return UdaljenostTacaka(t1,t2) + UdaljenostTacaka(t2,t3) + UdaljenostTacaka(t1,t3);
}
Tacka Trougao::DajCentar() const{
    return {(t1.first+t2.first+t3.first)/3, (t1.second+t2.second+t3.second)/3};
}
double Trougao::DajUgao(int indeks) const{
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    double a=UdaljenostTacaka(t2,t3);
    double b=UdaljenostTacaka(t1,t3);
    double c=UdaljenostTacaka(t1,t2);
    if(indeks==1) return (std::acos((b*b+c*c-a*a)/(2*b*c))*(pi/180));
    if(indeks==2) return (std::acos((a*a+c*c-b*b)/(2*a*c))*(pi/180));
    else return (std::acos((a*a+b*b-c*c)/(2*a*b)))*(pi/180);
}
double Trougao::DajStranicu(int indeks) const {
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return UdaljenostTacaka(t2,t3);
    if(indeks==2) return UdaljenostTacaka(t1,t3);
    else return UdaljenostTacaka(t1,t2);
}
Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return t1;
    else if(indeks==2) return t2;
    else return t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) t1=t;
    if(indeks==2) t2=t;
    else t3=t;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    this->t1=t1;
    this->t2=t2;
    this->t3=t3;
}
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
     if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    this->t1=t1;
    this->t2=t2;
    this->t3=t3;
}
int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i(0); i<n; i++){
        try{
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1,t2,t3;
        std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
        
        std::shared_ptr<Trougao> p (std::make_shared<Trougao>(t1, t2, t3));
        v[i]=p;
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<". ponovite unos!"<<std::endl;
            i--;
        }
        
    }
    
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin>> dx >> dy;
    double ugao;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>> ugao;
    double faktor;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    for(auto x : v) { x->Transliraj(dx, dy); x->Rotiraj(ugao); x->Skaliraj(x->DajTjeme(1), faktor); }
        
    for(auto x : v) x->Ispisi();
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    double obim;
    std::cout<<"Parovi identicnih trouglova: ";
    
	return 0;
}