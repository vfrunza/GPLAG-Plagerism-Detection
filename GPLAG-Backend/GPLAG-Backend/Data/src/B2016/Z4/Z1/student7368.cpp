/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <memory>
#include <vector>
#include <new>
#include <iomanip>
#include <algorithm>

typedef std::pair<double,double>Tacka;


class Trougao {
    private:
    const double PI=4*atan(1);
    static constexpr double Eps=(1e-10);
    Tacka t1,t2,t3;
    mutable Tacka tez;
    double static Rez_Form(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double rezultat=t1.first*(t2.second+t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        return rezultat;
    }
    double static Povrsina(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return (1/2*abs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)));
    }
    bool static Com(const Tacka &t1, const Tacka &t2){
        double a1=t1.first,a2=t2.first,b1=t1.second,b2=t2.second;
        if ((std::fabs(a1-a2)<=Eps*(std::fabs(a1)-std::fabs(a2))) && (std::fabs(b1-b2)<=Eps*(std::fabs(b1)-std::fabs(b2))))
        return true;
        return false;
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        Postavi(t1,t2,t3);
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi (int indeks, const Tacka &t);
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
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    int orijentacija=Orijentacija(t1,t2,t3);
    if (orijentacija==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    else {
        Trougao::t1.first=t1.first;
        Trougao::t1.second=t1.second;
        Trougao::t2.first=t2.first;
        Trougao::t2.second=t2.second;
        Trougao::t3.first=t3.first;
        Trougao::t3.second=t3.second;
    }
}
void Trougao::Postavi (int indeks, const Tacka &t){
    if (indeks==1) {
        t1.first=t.first;
        t1.second=t.second;
    }
    else if (indeks==2) {
        t2.first=t.first;
        t2.second=t.second;
    }
    else if (indeks==3) {
        t3.first=t.first;
        t3.second=t.second;
    }
    else throw std::range_error ("Nekorektan indeks");
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double rezultat=Rez_Form(t1,t2,t3);
    if (rezultat>0) return 1;
    if (rezultat<0) return -1;
    return 0;
} 
Tacka Trougao::DajTjeme (int indeks) const {
    if (indeks==1) return t1;
    else if (indeks==2) return t2;
    else if (indeks==3) return t3;
    else throw std::range_error ("Nekorektan indeks");
}

double Trougao::DajStranicu (int indeks) const {
    double stranica;
    if (indeks==1) {
        stranica=std::sqrt(((t2.first-t3.first)*(t2.first-t3.first))+((t2.second-t3.second)*(t2.second-t3.second)));
    }
    else if (indeks==2) {
        stranica=std::sqrt(((t1.first-t3.first)*(t1.first-t3.first))+((t1.second-t3.second)*(t1.second-t3.second)));
    }
    else if (indeks==3) {
        stranica=std::sqrt(((t2.first-t1.first)*(t2.first-t1.first))+((t2.second-t1.second)*(t2.second-t1.second)));
    }
    else throw std::range_error ("Nekorektan indeks");
    return stranica;
}
double Trougao::DajUgao(int indeks) const {
    double a,b,c,cos_ugao,ugao;
    a=DajStranicu(1); b=DajStranicu(2); c=DajStranicu(3);
    if (indeks==1){
        cos_ugao=(b*b+c*c-a*a)/(2*b*c);
        ugao=acos(a/c);
    }
    else if (indeks==2){
        cos_ugao=(c*c+a*a-b*b)/(2*a*c);
        ugao=acos(b/a);
    }
    else if (indeks==3){
        cos_ugao=(a*a+b*b-c*c)/(2*b*a);
        ugao=acos(c/b);
    }
    else throw std::range_error("Nekorektan indeks");
    ugao=ugao*(PI/180);
    return ugao;
}
Tacka Trougao::DajCentar() const {
    double x_t,y_t;
    x_t=(t1.first+t2.first+t3.first)/3;
    y_t=(t1.second+t2.second+t3.second)/3;
    tez.first=x_t;
    tez.second=y_t;
    
    return tez;
}
double Trougao::DajObim() const {
    return (DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
}
double Trougao::DajPovrsinu() const {
    return Povrsina(t1,t2,t3);
}
bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if (Orijentacija(t1,t2,t3)==1) return true;
    if (Orijentacija(t1,t2,t3)==-1) return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    double povrsina,povrsina1,povrsina2,povrsina3;
    povrsina=DajPovrsinu();
    povrsina1=Povrsina(t1,t2,t);
    povrsina2=Povrsina(t2,t3,t);
    povrsina3=Povrsina(t3,t1,t);
    double zbir=povrsina1+povrsina2+povrsina3;
    if (std::fabs(povrsina-zbir)<=Eps*(std::fabs(povrsina)+std::fabs(zbir))) return true;
    return false;
}
void Trougao::Transliraj(double delta_x, double delta_y){
    t1.first=t1.first+delta_x;  t1.second=t1.second+delta_y;
    t2.first=t2.first+delta_x;  t2.second=t2.second+delta_y;
    t3.first=t3.first+delta_x;  t3.second=t3.second+delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    tez.first=t.first;
    tez.second=t.second;
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if (faktor==0) throw std::domain_error ("Nekorektan faktor skaliranja");
    t1.first=t.first+faktor*(t1.first-t.first);
    t1.second=t.second+faktor*(t1.second-t.second);
    
    t2.first=t.first+faktor*(t2.first-t.first);
    t2.second=t.second+faktor*(t2.second-t.second);
    
    t3.first=t.first+faktor*(t3.first-t.first);
    t3.second=t.second+faktor*(t3.second-t.second);
    
    if(faktor<0) {
        Rotiraj(180);
    }
}
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    t1.first=t.first+cos(ugao)*(t1.first-t.first)-sin(ugao)*(t1.second-t.second);
    t2.first=t.first+cos(ugao)*(t2.first-t.first)-sin(ugao)*(t2.second-t.second);
    t3.first=t.first+cos(ugao)*(t3.first-t.first)-sin(ugao)*(t3.second-t.second);
    
    t1.second=t.second+sin(ugao)*(t1.first-t.first)+cos(ugao)*(t1.second-t.second);
    t2.second=t.second+sin(ugao)*(t2.first-t.first)+cos(ugao)*(t2.second-t.second);
    t3.second=t.second+sin(ugao)*(t3.first-t.first)+cos(ugao)*(t3.second-t.second);
}
void Trougao::Rotiraj (double ugao){
    Rotiraj(DajCentar(),ugao);
}
void Trougao::Skaliraj (double faktor) {
    Skaliraj(DajCentar(),faktor);
}
/*bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    int orj_t1=Trougao::Orijentacija(t1.Trougao::t1,t1.Trougao::t2,t1.Trougao::t3);
    int orj_t2=Trougao::Orijentacija(t2.Trougao::t1,t2.Trougao::t2,t2.Trougao::t3);
    
}*/
void Trougao::Ispisi() const{
    std::cout<<"(("<<std::setw(2)<<t1.first<<","<<std::setw(2)<<t1.second<<")"<<",";
    std::cout<<"("<<t2.first<<","<<t2.second<<")"<<",";
    std::cout<<"("<<t3.first<<","<<t3.second<<"))";
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    Tacka a1,b1,c1,a2,b2,c2;
    int brojac=0;
    a1=t1.Trougao::t1;  a2=t2.Trougao::t1;
    b1=t1.Trougao::t2;  b2=t2.Trougao::t2;
    c1=t1.Trougao::t3;  c2=t2.Trougao::t3;
    if (Trougao::Com(a1,a2)==true || Trougao::Com(a1,b2)==true || Trougao::Com(a1,c2)==true) brojac++;
    if (Trougao::Com(b1,a2)==true || Trougao::Com(b1,b2)==true || Trougao::Com(b1,c2)==true) brojac++;
    if (Trougao::Com(c1,a2)==true || Trougao::Com(c1,b2)==true || Trougao::Com(c1,c2)==true) brojac++;
    if (brojac==3) return true;
    return false;
}
int main () {
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>>v(n);
    //std::cout<<"Unesite elemente: ";
    for (int i=0; i<n; i++){
        std::pair<double,double>par1,par2,par3;
        double x1,y1,x2,x3,y2,y3;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): "; 
        std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
        par1=std::make_pair(x1,y1);
        par2=std::make_pair(x2,y2);
        par3=std::make_pair(x3,y3);
        v[i]=std::make_shared<Trougao>(par1,par2,par3);
    }
    double dx,dy,ugao,faktor;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
   
    std::transform(v.begin(), v.end(),v.begin(), [dx,dy,ugao,faktor](std::shared_ptr<Trougao>&pok){
        pok->Transliraj(dx,dy);
        pok->Rotiraj(ugao);
        pok->Skaliraj(faktor);
        return pok;
    });
    std::sort (v.begin(), v.end(), [](std::shared_ptr<Trougao>pok1,std::shared_ptr<Trougao>pok2){
        return pok1->DajPovrsinu()<pok2->DajPovrsinu();
    });
    std::cout<<std::endl;
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao>pok){
        pok->Ispisi();
        std::cout<<std::endl;
    });
    
    std::vector<std::shared_ptr<Trougao>>v1=v;
    std::vector<std::shared_ptr<Trougao>>v2;
    auto pok=std::min_element(v.begin(), v.end(),[](const std::shared_ptr<Trougao>pok1,const std::shared_ptr<Trougao>pok2){
        if ((pok1->DajObim())<(pok2->DajObim())) return true;
        else return false;
    });
    std::cout<<"TRougao sa najmanjim obimom: ";
    (**pok).Ispisi();
    v=v1;
    std::cout<<std::endl<<"Parovi identicnih trouglova: "<<std::endl;
    std::vector<std::shared_ptr<Trougao>>v3;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (DaLiSuIdenticni(*v[i],*v[j])) {
               v2.push_back(v[i]);
               v3.push_back(v[j]);
            }
        }
    }
    for (int k=0; k<v2.size(); k++){
        v2[k]->Ispisi();
        std::cout<<" i ";
        v3[k]->Ispisi();
        if (k!=v2.size()-1) std::cout<<std::endl;
    }
    
    
    
    
    
	return 0;
}