#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;
const double Eps(1e-10);

class Trougao {
    Tacka t1, t2, t3;
    static double pomocna1(Tacka a, Tacka b, Tacka c) {
        return a.first*(b.second-c.second)-b.first*(a.second-c.second)+c.first*(a.second-b.second);
    }
    static double Nova_x(Tacka T, Tacka C, double ugao) {
        return (C.first+(T.first-C.first)*cos(ugao)-(T.second-C.second)*sin(ugao));
    }
    static double Nova_y(double x, double y, Tacka C, double ugao) {
        return (C.second+(x-C.first)*sin(ugao)+(y-C.second)*cos(ugao));
    }
    static double Skal_x(Tacka T, Tacka C, double faktor) {
        return C.first+faktor*(T.first-C.first);
    }
    static double Skal_Y(Tacka T, Tacka C, double faktor) {
        return C.second+faktor*(T.second-C.second);
    }
    static int Min_str(Trougao tr) {
        if (tr.DajStranicu(1)<=tr.DajStranicu(2) && tr.DajStranicu(1)<=tr.DajStranicu(3)) return 1;
        else if (tr.DajStranicu(2)<=tr.DajStranicu(3) && tr.DajStranicu(2)<=tr.DajStranicu(2)) return 2;
        else return 3;
    }
    static int NEM1(Trougao tr) {
        if (Min_str(tr)==1) return 2;
        else if (Min_str(tr)==2) return 3;
        else return 1;
    }
    static int NEM2(Trougao tr) {
        if (Min_str(tr)==1) return 3;
        else if (Min_str(tr)==2) return 1;
        else return 2;
    }
    static bool Provjera(Trougao t1, Trougao t2) {
        if(t1.DaLiJePozitivnoOrijentiran()==t2.DaLiJePozitivnoOrijentiran()) {
            if (fabs(t1.DajUgao(t1.NEM1(t1))-t2.DajUgao(t2.NEM1(t2)))<=Eps) return true; else return false;}
        else {if (fabs(t1.DajUgao(t1.NEM1(t1))-t2.DajUgao(t2.NEM2(t2)))<=Eps) return true; else return false;}
    }
    
    public: 
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    
    void Postavi(int indeks, const Tacka &t) {
        if(indeks<=0 || indeks>=4) throw std::range_error("Nekorektan indeks");
        if(indeks==1) { 
        if(Orijentacija(t,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); t1=t;}
        else if(indeks==2) {
        if(Orijentacija(t1,t,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena"); t2=t;}
        else if(indeks==3) {
        if(Orijentacija(t1,t2,t)==0) throw std::domain_error("Nekorektne pozicije tjemena"); t3=t;}
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double pom=pomocna1(t1, t2, t3);
        if(pom>0) return 1; else if(pom<0) return -1; else return 0;
    }
    Tacka DajTjeme(int indeks) const {if(indeks==1) return t1; else if(indeks==2) return t2; else if(indeks==3) return t3; else throw std::range_error("Nekorektan indeks");}
    
    double DajStranicu(int indeks) const {if(indeks==1) {return sqrt((t3.second-t2.second)*(t3.second-t2.second)+(t3.first-t2.first)*(t3.first-t2.first));}
    else if(indeks==2) return sqrt((t1.second-t3.second)*(t1.second-t3.second)+(t1.first-t3.first)*(t1.first-t3.first)); 
    else if(indeks==3) return sqrt((t1.second-t2.second)*(t1.second-t2.second)+(t1.first-t2.first)*(t1.first-t2.first));
    else throw std::range_error("Nekorektan indeks");
    }
    
    double DajUgao(int indeks) const {
    double a=DajStranicu(1); double b=DajStranicu(2); double c=DajStranicu(3);
    if (indeks==1) return acos((b*b+c*c-a*a)/(2*b*c));
    else if (indeks==2) return acos((c*c+a*a-b*b)/(2*a*c));
    else if(indeks==3) return acos((b*b+a*a-c*c)/(2*a*b));
    else throw std::range_error("Nekorektan indeks");
    }
    
    Tacka DajCentar() const {Tacka t; t.first=(t1.first+t2.first+t3.first)/3.; t.second=(t1.second+t2.second+t3.second)/3.; return t;}
    
    double DajObim() const { return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);}
    
    double DajPovrsinu() const {return fabs(pomocna1(t1, t2, t3))/2.;}
    
    bool DaLiJePozitivnoOrijentiran() const {if (Orijentacija(t1,t2,t3)>0) return true; else return false;}
    
    bool DaLiJeUnutra(const Tacka &t) const {if ((Orijentacija(t1,t2,t3)>0 && Orijentacija(t1,t2,t)>0 && Orijentacija(t2,t3,t)>0 && Orijentacija(t3,t1,t)>0) || (Orijentacija(t1,t2,t3)<0 && Orijentacija(t1,t2,t)<0 && Orijentacija(t2,t3,t)<0 && Orijentacija(t3,t1,t)<0)) return true;
    else return false;}
    
    void Ispisi() const {std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";}
    
    void Transliraj(double delta_x, double delta_y) {t1.first+=delta_x; t1.second+=delta_y; t2.first+=delta_x; t2.second+=delta_y; t3.first+=delta_x; t3.second+=delta_y;}
    
    void Centriraj(const Tacka &t) {double x=t.first-DajCentar().first; double y=t.second-DajCentar().second; Transliraj(x,y);}
    
    void Rotiraj(const Tacka &t, double ugao) {
        double x=t1.first;
        double y=t1.second;
        t1.first=Nova_x(t1,t,ugao); t1.second=Nova_y(x,y,t,ugao);
        x=t2.first; y=t2.second;
        t2.first=Nova_x(t2,t,ugao); t2.second=Nova_y(x,y,t,ugao); 
        x=t3.first; y=t3.second;
        t3.first=Nova_x(t3,t,ugao); t3.second=Nova_y(x,y,t,ugao);}
    
    void Skaliraj(const Tacka &t, double faktor) {
        if(faktor-0<Eps) throw std::domain_error("Nekorektan faktor skaliranja");
        t1.first=Skal_x(t1,t,faktor); t1.second=Skal_Y(t1,t,faktor); t2.first=Skal_x(t2,t,faktor); t2.second=Skal_Y(t2,t,faktor); t3.first=Skal_x(t3,t,faktor); t3.second=Skal_Y(t3,t,faktor); }
    
    void Rotiraj(double ugao) {
        Tacka t=DajCentar();
        double x=t1.first;
        double y=t1.second;
        t1.first=Nova_x(t1,t,ugao); t1.second=Nova_y(x,y,t,ugao);
        x=t2.first; y=t2.second;
        t2.first=Nova_x(t2,t,ugao); t2.second=Nova_y(x,y,t,ugao); 
        x=t3.first; y=t3.second;
        t3.first=Nova_x(t3,t,ugao); t3.second=Nova_y(x,y,t,ugao);}
    
    void Skaliraj(double faktor) {
        Tacka t=DajCentar();
        if(faktor-0<Eps) throw std::domain_error("Nekorektan faktor skaliranja");
        t1.first=Skal_x(t1,t,faktor); t1.second=Skal_Y(t1,t,faktor); t2.first=Skal_x(t2,t,faktor); t2.second=Skal_Y(t2,t,faktor); t3.first=Skal_x(t3,t,faktor); t3.second=Skal_Y(t3,t,faktor); }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if((t1.DajTjeme(1)==t2.DajTjeme(1)) && (t1.DajTjeme(2)==t2.DajTjeme(2)) && (t1.DajTjeme(3)==t2.DajTjeme(3))) {return true; }
    else if((t1.DajTjeme(1)==t2.DajTjeme(1)) && (t1.DajTjeme(2)==t2.DajTjeme(3)) && (t1.DajTjeme(3)==t2.DajTjeme(2))) {return true; }
    else if((t1.DajTjeme(1)==t2.DajTjeme(2)) && (t1.DajTjeme(2)==t2.DajTjeme(1)) && (t1.DajTjeme(3)==t2.DajTjeme(3))) {return true; }
    else if((t1.DajTjeme(1)==t2.DajTjeme(2)) && (t1.DajTjeme(2)==t2.DajTjeme(3)) && (t1.DajTjeme(3)==t2.DajTjeme(1))) {return true; }
    else if((t1.DajTjeme(1)==t2.DajTjeme(3)) && (t1.DajTjeme(2)==t2.DajTjeme(1)) && (t1.DajTjeme(3)==t2.DajTjeme(2))) {return true; }
    else if((t1.DajTjeme(1)==t2.DajTjeme(3)) && (t1.DajTjeme(2)==t2.DajTjeme(2)) && (t1.DajTjeme(3)==t2.DajTjeme(1))) {return true; }
    else return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    if(fabs(t1.DajStranicu(1)-t2.DajStranicu(1))<=Eps && fabs(t1.DajStranicu(2)-t2.DajStranicu(2))<=Eps && fabs(t1.DajStranicu(3)-t2.DajStranicu(3))<=Eps && t1.Provjera(t1,t2)) {return true; }
    else if(fabs(t1.DajStranicu(1)-t2.DajStranicu(1))<=Eps && fabs(t1.DajStranicu(2)-t2.DajStranicu(3))<=Eps && fabs(t1.DajStranicu(3)-t2.DajStranicu(2))<=Eps && t1.Provjera(t1,t2)) {return true; }
    else if(fabs(t1.DajStranicu(1)-t2.DajStranicu(2))<=Eps && fabs(t1.DajStranicu(2)-t2.DajStranicu(1))<=Eps && fabs(t1.DajStranicu(3)-t2.DajStranicu(3))<=Eps && t1.Provjera(t1,t2)) {return true; }
    else if(fabs(t1.DajStranicu(1)-t2.DajStranicu(2))<=Eps && fabs(t1.DajStranicu(2)-t2.DajStranicu(3))<=Eps && fabs(t1.DajStranicu(3)-t2.DajStranicu(1))<=Eps && t1.Provjera(t1,t2)) {return true; }
    else if(fabs(t1.DajStranicu(1)-t2.DajStranicu(3))<=Eps && fabs(t1.DajStranicu(2)-t2.DajStranicu(1))<=Eps && fabs(t1.DajStranicu(3)-t2.DajStranicu(2))<=Eps && t1.Provjera(t1,t2)) {return true; }
    else if(fabs(t1.DajStranicu(1)-t2.DajStranicu(3))<=Eps && fabs(t1.DajStranicu(2)-t2.DajStranicu(2))<=Eps && fabs(t1.DajStranicu(3)-t2.DajStranicu(1))<=Eps && t1.Provjera(t1,t2)) {return true; }
    else return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    if(fabs(t1.DajStranicu(1)/t2.DajStranicu(1)-t1.DajStranicu(2)/t2.DajStranicu(2))<=Eps && fabs(t1.DajStranicu(1)/t2.DajStranicu(1)-t1.DajStranicu(3)/t2.DajStranicu(3))<=Eps && t1.Provjera(t1,t2)) return true;
    if(fabs(t1.DajStranicu(1)/t2.DajStranicu(1)-t1.DajStranicu(2)/t2.DajStranicu(3))<=Eps && fabs(t1.DajStranicu(1)/t2.DajStranicu(1)-t1.DajStranicu(3)/t2.DajStranicu(2))<=Eps && t1.Provjera(t1,t2)) return true;
    if(fabs(t1.DajStranicu(1)/t2.DajStranicu(2)-t1.DajStranicu(2)/t2.DajStranicu(1))<=Eps && fabs(t1.DajStranicu(1)/t2.DajStranicu(2)-t1.DajStranicu(3)/t2.DajStranicu(3))<=Eps && t1.Provjera(t1,t2)) return true;
    if(fabs(t1.DajStranicu(1)/t2.DajStranicu(2)-t1.DajStranicu(2)/t2.DajStranicu(3))<=Eps && fabs(t1.DajStranicu(1)/t2.DajStranicu(2)-t1.DajStranicu(3)/t2.DajStranicu(1))<=Eps && t1.Provjera(t1,t2)) return true;
    if(fabs(t1.DajStranicu(1)/t2.DajStranicu(3)-t1.DajStranicu(2)/t2.DajStranicu(1))<=Eps && fabs(t1.DajStranicu(1)/t2.DajStranicu(3)-t1.DajStranicu(3)/t2.DajStranicu(2))<=Eps && t1.Provjera(t1,t2)) return true;
    if(fabs(t1.DajStranicu(1)/t2.DajStranicu(3)-t1.DajStranicu(2)/t2.DajStranicu(2))<=Eps && fabs(t1.DajStranicu(1)/t2.DajStranicu(3)-t1.DajStranicu(3)/t2.DajStranicu(1))<=Eps && t1.Provjera(t1,t2)) return true;
    else return false;
}

int main ()
{   

    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> vek(n);
    
     Tacka t1,t2,t3;
    for(int i=0; i<n; i++) {
        try{
        int x1,y1,x2,y2,x3,y3;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): "; 
        std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
       
        t1.first=x1; t1.second=y1; t2.first=x2; t2.second=y2; t3.first=x3; t3.second=y3;
        vek[i]=(std::make_shared<Trougao>(t1,t2,t3));
        }
        catch(std::domain_error izuzetak) {std::cout<<izuzetak.what()<<", ponovite unos!"<<std::endl; i--;}
    }
    
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double x,y;
    std::cin>>x>>y;
    std::transform(vek.begin(), vek.end(), vek.begin(), [x,y](std::shared_ptr<Trougao> v) {v->Transliraj(x,y); return v;});

    std::cout<<"Unesite ugao rotacije: ";
    double ugao; std::cin>>ugao;
    std::transform(vek.begin(), vek.end(), vek.begin(), [ugao](std::shared_ptr<Trougao> v) 
    { v->Rotiraj(v->DajCentar(), ugao); return v; });
    
    
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor; std::cin>>faktor;
    std::transform(vek.begin(), vek.end(), vek.begin(), [faktor](std::shared_ptr<Trougao> v) 
    { v->Skaliraj(v->DajTjeme(1), faktor); return v; });
    
    std::sort(vek.begin(),vek.end(), [](std::shared_ptr<Trougao> v1, std::shared_ptr<Trougao> v2) 
    {if (v1->DajPovrsinu()<v2->DajPovrsinu()) return true; return false;});
    
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(vek.begin(),vek.end(), [](std::shared_ptr<Trougao> v) 
    {v->Ispisi(); std::cout<<std::endl;});
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    
    Trougao tro=**std::min_element(vek.begin(),vek.end(), [](std::shared_ptr<Trougao> v1, std::shared_ptr<Trougao> v2) 
    {return (v1->DajObim()<v2->DajObim());});
    tro.Ispisi(); std::cout<<std::endl;
    
    int brojac=0;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
        if(DaLiSuIdenticni(*vek[i], *vek[j])) {brojac++;}
    }
    }
    if(brojac==0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
    else
    std::cout<<"Parovi identicnih trouglova:"<<std::endl;

    
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
        if(DaLiSuIdenticni(*vek[i], *vek[j])) {vek[i]->Ispisi(); std::cout<<" i "; vek[j]->Ispisi(); std::cout<<std::endl;}
    }
    }
     brojac=0;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
        if(DaLiSuPodudarni(*vek[i], *vek[j])) {brojac++;}
    }
    }
    if(brojac==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    else
    std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
    
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
        if(DaLiSuPodudarni(*vek[i], *vek[j])) {vek[i]->Ispisi(); std::cout<<" i "; vek[j]->Ispisi(); std::cout<<std::endl;}
    }
    }
    
    brojac=0;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
        if(DaLiSuSlicni(*vek[i], *vek[j])) {brojac++;}
    }
    }
    if(brojac==0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
    else
    std::cout<<"Parovi slicnih trouglova:"<<std::endl;
    
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
        if(DaLiSuSlicni(*vek[i], *vek[j])) {vek[i]->Ispisi(); std::cout<<" i "; vek[j]->Ispisi(); std::cout<<std::endl;}
    }
    }
	return 0;
}