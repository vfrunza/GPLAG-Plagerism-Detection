/*Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
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
void Skaliraj(const 
Tacka &t, double faktor);
void Rotiraj(double ugao);
void Skaliraj(double faktor);
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);*/
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
using namespace std;

typedef pair<double, double> Tacka;

class Trougao{
    Tacka t[3];
    void ProvjeriIndeks(int indeks) const { if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks"); }
    double DuzinaStranice(const Tacka &t1, const Tacka &t2) const {
        double temp;
        temp=sqrt(pow(t1.first-t2.first,2)+pow(t1.second-t2.second,2));
        return temp;
    }
    static double orj(Tacka t1, Tacka t2, Tacka t3)  { return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second); }
    
    Tacka RotiranaTacka(const Tacka &t,const Tacka &c,double u){  
        double x(t.first),y(t.second),x1(c.first),y1(c.second);
        Tacka a;
        a.first=x1+(x-x1)*cos(u)-(y-y1)*sin(u);
        a.second=y1+(x-x1)*sin(u)+(y-y1)*cos(u);
        return a;
    }
    Tacka SkaliranaTacka(const Tacka &t,const Tacka &c,double u){  
        double x(t.first),y(t.second),x1(c.first),y1(c.second);
        Tacka a;
        a.first=x1+(x-x1)*u;
        a.second=y1+(y-y1)*u;
        return a;
    }
    double PopraviUgao(double u){
        while(u>atan(1)*4) u=u-atan(1)*4;
        while(u<0) u=u+atan(1)*4;
        return u;
    }
public: 
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
    t[0].first=t1.first; t[0].second=t1.second;
    t[1].first=t2.first; t[1].second=t2.second;
    t[2].first=t3.first; t[2].second=t3.second;
}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
    t[0].first=t1.first; t[0].second=t1.second;
    t[1].first=t2.first; t[1].second=t2.second;
    t[2].first=t3.first; t[2].second=t3.second;
}
void Postavi(int indeks, const Tacka &t){
    ProvjeriIndeks(indeks);
    this->t[indeks].first=t.first; this->t[indeks].second=t.second;
    if(Orijentacija(this->t[0],this->t[1],this->t[2])==0) throw domain_error("Nekorektne pozicije tjemena");
}
int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double temp=orj(t1,t2,t3);
    if(temp<0+0.0001 && temp>0-0.0001) return 0;
    else if(temp>0) return 1;
    else return -1;
}

Tacka DajTjeme(int indeks) const { ProvjeriIndeks(indeks); return t[indeks]; }
double DajStranicu(int indeks) const { ProvjeriIndeks(indeks);
    if(indeks==1) return DuzinaStranice(t[1],t[2]);
    else if(indeks==2) return DuzinaStranice(t[0],t[2]);
    else return DuzinaStranice(t[0],t[1]);
}
double DajUgao(int indeks) const { ProvjeriIndeks(indeks);
    double a(DuzinaStranice(t[0],t[1])),b(DuzinaStranice(t[0],t[2])),c(DuzinaStranice(t[1],t[2]));
    if(indeks==1) return acos((a*a+b*b-c*c)/(2*a*b));
    else if(indeks==2) return acos((a*a+c*c-b*b)/(2*a*c));
    else return acos((c*c+b*b-a*a)/(2*b*c));
}
Tacka DajCentar() const {
    Tacka c;
    c.first=(t[0].first+t[1].first+t[2].first)/3;
    c.second=(t[0].second+t[1].second+t[2].second)/3;
    return c;
}
double DajObim() const { 
    double a(DuzinaStranice(t[0],t[1])),b(DuzinaStranice(t[0],t[2])),c(DuzinaStranice(t[1],t[2]));
    return (a+b+c);
}
double DajPovrsinu() const {
    return orj(t[0],t[1],t[2]);
}
bool DaLiJePozitivnoOrijentiran() const { if(orj(t[0],t[1],t[2])>1) return true; else return false; }
bool DaLiJeUnutra(const Tacka &t) const {
    double p1(orj(t,this->t[0],this->t[1])),p2(orj(t,this->t[2],this->t[1])),p3(orj(t,this->t[0],this->t[2]));
    if(p1+p2+p3==orj(this->t[0],this->t[1],this->t[2])) return true;
    return false;
}
void Ispisi() const {
    cout<<"(("<<t[0].first<<","<<t[0].second<<"),("<<t[1].first<<","<<t[1].second<<"),("<<t[2].first<<","<<t[2].second<<"))";                                            
}

void Transliraj(double delta_x, double delta_y){
    t[0].first+=delta_x; t[1].first+=delta_x; t[2].first+=delta_x;
    t[0].second+=delta_y; t[1].second+=delta_y; t[2].second+=delta_y;
}
void Centriraj(const Tacka &t){
    Tacka c(DajCentar());
    double x,y;
    x=t.first-c.first; y=t.second-c.second;
    this->t[0].first+=x; this->t[1].first+=x; this->t[2].first+=x;
    this->t[0].second+=y; this->t[1].second+=y; this->t[2].second+=y;
}
void Rotiraj(const Tacka &t, double ugao){
    if(ugao<0 || ugao>atan(1)*4) ugao=PopraviUgao(ugao);
    this->t[0]=RotiranaTacka(this->t[0],t,ugao);
    this->t[1]=RotiranaTacka(this->t[1],t,ugao);
    this->t[2]=RotiranaTacka(this->t[2],t,ugao);
}
void Skaliraj(const Tacka &t, double faktor){
    this->t[0]=SkaliranaTacka(this->t[0],t,faktor);
    this->t[1]=SkaliranaTacka(this->t[1],t,faktor);
    this->t[2]=SkaliranaTacka(this->t[2],t,faktor);
}
void Rotiraj(double ugao){
    if(ugao<0 || ugao>atan(1)*4) ugao=PopraviUgao(ugao);
    this->t[0]=RotiranaTacka(this->t[0],DajCentar(),ugao);
    this->t[1]=RotiranaTacka(this->t[1],DajCentar(),ugao);
    this->t[2]=RotiranaTacka(this->t[2],DajCentar(),ugao);
}
void Skaliraj(double faktor){
    this->t[0]=SkaliranaTacka(this->t[0],DajCentar(),faktor);
    this->t[1]=SkaliranaTacka(this->t[1],DajCentar(),faktor);
    this->t[2]=SkaliranaTacka(this->t[2],DajCentar(),faktor);
}
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    Tacka a1(t1.t[0]),a2(t1.t[1]),a3(t1.t[2]),b1(t2.t[0]),b2(t2.t[1]),b3(t2.t[2]);
    if(a1==b1){
        if(a2==b2 && a3==b3) return true;
        if(a2==b3 && a3==b2) return true;
        }
    if(a1==b2){
        if(a2==b1 && a3==b3) return true;
        if(a2==b3 && a3==b1) return true;
    }
    if(a1==b3){
        if(a2==b2 && a3==b1) return true;
        if(a2==b1 && a3==b2) return true;
    }
    return false;
}
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    double a1(t1.DajStranicu(1)),a2(t1.DajStranicu(2)),a3(t1.DajStranicu(3)),b1(t2.DajStranicu(1)),b2(t2.DajStranicu(2)),b3(t2.DajStranicu(3));
    bool a(false);
    if(a1==b1){
        if(a2==b2 && a3==b3) a=true;
        if(a2==b3 && a3==b2) a=true;
        }
    if(a1==b2){
        if(a2==b1 && a3==b3) a=true;
        if(a2==b3 && a3==b1) a=true;
    }
    if(a1==b3){
        if(a2==b2 && a3==b1) a=true;
        if(a2==b1 && a3==b2) a=true;
    }
    if(abs(orj(t1.t[0],t1.t[1],t1.t[2])-orj(t2.t[0],t2.t[1],t2.t[2]))<0.0001) a=true;
    else a=false;
    return a;
}
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double a1(t1.DajUgao(1)),a2(t1.DajUgao(2)),a3(t1.DajUgao(3)),b1(t2.DajUgao(1)),b2(t2.DajUgao(2)),b3(t2.DajUgao(3));
    bool a(false);
    if(a1==b1){
        if(a2==b2 && a3==b3) a=true;
        if(a2==b3 && a3==b2) a=true;
        }
    if(a1==b2){
        if(a2==b1 && a3==b3) a=true;
        if(a2==b3 && a3==b1) a=true;
    }
    if(a1==b3){
        if(a2==b2 && a3==b1) a=true;
        if(a2==b1 && a3==b2) a=true;
    }
    if(abs(orj(t1.t[0],t1.t[1],t1.t[2])-orj(t2.t[0],t2.t[1],t2.t[2]))<0.0001) a=true;
    else a=false;
    return a;
}
};
int main ()
{
    
    int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    vector<shared_ptr<Trougao>> pok(n);
    for(int i = 0; i < n; i++){
        while(1){
        double x1,x2,x3,y1,y2,y3;
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Tacka t1(make_pair(x1,y1)),t2(make_pair(x2,y2)),t3(make_pair(x3,y3));
        try{ 
            pok[i]=make_shared<Trougao>(t1,t2,t3); 
            }
        catch(domain_error e){
            cout<<e.what()<<", ponovite unos!"<<endl;
            continue;
            }
        break;
        }
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    cin>>dx>>dy;
    cout<<"Unesite ugao rotacije: ";
    double ugao;
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    double s;
    cin>>s;
    cout<<"Trouglovi nakon obavljenih transformacija: "<<endl;
    for(int i = 0; i < n; i++){
        pok[i]->Transliraj(dx,dy);
        pok[i]->Rotiraj(pok[i]->DajCentar(),ugao);
        pok[i]->Skaliraj(pok[i]->DajTjeme(1),s);
        pok[i]->Ispisi(); cout<<endl;
    }
    vector<double> v(n);
    for(int i = 0; i < n; i++) v[i]=pok[i]->DajObim();
    int min(0);
    for(int i = 0; i < n; i++) {
        int br(0);
       for(int j = 0; j < n; j++){
           if(v[i]>v[j]) br++;
        }
        if(br==n-1) { min=i; break; }
        br=0;
    }
    cout<<"Trougao sa najmanjim obimom: ";
    pok[min]->Ispisi(); cout<<endl;
    int br(0);
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(DaLiSuIdenticni(*pok[i],*pok[j])) { if (br==0) cout<<"Parovi identicnih trouglova: "<<endl; pok[i]->Ispisi(); cout<<" i "; pok[j]->Ispisi(); cout<<endl; br++; }
        }
    }
    if(br==0) cout<<"Nema identicnih trouglova!"<<endl;
    br=0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(DaLiSuPodudarni(*pok[i],*pok[j])) { if (br==0) cout<<"Parovi podudarnih trouglova: "<<endl; pok[i]->Ispisi(); cout<<" i "; pok[j]->Ispisi(); cout<<endl; br++; }
        }
    }
    if(br==0) cout<<"Nema podudarnih trouglova!"<<endl;
    br=0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(DaLiSuSlicni(*pok[i],*pok[j])) { if (br==0) cout<<"Parovi slicnih trouglova: "<<endl; pok[i]->Ispisi(); cout<<" i "; pok[j]->Ispisi(); cout<<endl; br++; }
        }
    }
    if(br==0) cout<<"Nema slicnih trouglova!"<<endl;
   
	return 0;
}




