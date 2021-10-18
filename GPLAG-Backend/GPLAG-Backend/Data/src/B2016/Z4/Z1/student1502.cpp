/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

typedef pair<double,double> Tacka;

class Trougao{
    Tacka tacka1, tacka2, tacka3;
    int indeks;
    double ugao, faktor;
    double delta_x, delta_y;
    
    
public:

static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    int temp;
    temp=t1.first*(t2.second-t3.second)-t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
    if(fabs(temp)==0)return 0;
    if(temp>0) return 1;
    else if(temp<0)return-1;
    
    return 0;
}

Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    //baciti izuzetak ukoliko tri tacke se nalaze na istom pravcu
    if(Orijentacija(t1,t2,t3)==0)throw domain_error("Nekorektne pozicije tjemena");
    tacka1=t1;
    tacka2=t2;
    tacka3=t3;
}

void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    //Isto kao i konstruktor samo sto postavlja vrijednost nad vec postojecim elementom
    tacka1=t1;
    tacka2=t2;
    tacka3=t3;
}

void Postavi(int indeks, const Tacka &t){
    //promjena samo jedne tacke tj indexa 
     if(indeks<=0 or indeks>3) throw range_error ("Nekorektan indeks");
     if(Orijentacija(tacka1,tacka2,tacka3)==0)throw domain_error("Nekorektne pozicije tjemena");
    //baciti izuzetak ako index nije korektan tj != 1,2,3
    if(indeks==1) tacka1=t;
    else if(indeks==2) tacka2=t;
    else if(indeks==3) tacka3=t;
    
}



Tacka DajTjeme(int indeks) const{
    if(indeks<=0 or indeks>3) throw range_error ("Nekorektan indeks");
    if(indeks==1)return tacka1;
    else if(indeks==2)return tacka2;
    else if(indeks==3)return tacka3;
    //provjeriti
    
}

double DajStranicu(int indeks) const{
    if(indeks<=0 or indeks>3) throw range_error ("Nekorektan indeks");
    if(indeks==1)return (tacka2.second*tacka2.second+tacka3.second*tacka3.second);
    else if(indeks==2)return (tacka1.second*tacka1.second+tacka3.second*tacka3.second);
    else if(indeks==3)return (tacka2.second*tacka2.second+tacka1.second*tacka1.second);
    
}

double DajUgao(int indeks) const{
    if(indeks<=0 or indeks>3) throw range_error ("Nekorektan indeks");
    if(indeks==1)return 1;                                                          //UGLOviNE TECKE
    else if(indeks==2)return 2;
    else if(indeks==3)return 3;
    
}

Tacka DajCentar() const{
    Tacka T;
    double t11=(tacka1.first+tacka2.first+tacka3.first)/3.;
    double t22=(tacka1.second+tacka2.second+tacka3.second)/3.;
    T=make_pair(t11,t22);
    return T;
    
}

double DajObim() const{
    double obim;
    obim=(tacka2.second*tacka2.second+tacka3.second*tacka3.second)+(tacka1.second*tacka1.second+tacka3.second*tacka3.second)+(tacka2.second*tacka2.second+tacka1.second*tacka1.second);
    return obim;

}

double DajPovrsinu() const{
    double s=(tacka2.second*tacka2.second+tacka3.second*tacka3.second)+(tacka1.second*tacka1.second+tacka3.second*tacka3.second)+(tacka2.second*tacka2.second+tacka1.second*tacka1.second)/2.;
    double a,b,c;
    a=tacka2.second*tacka2.second+tacka3.second*tacka3.second;
    b=tacka1.second*tacka1.second+tacka3.second*tacka3.second;
    c=tacka2.second*tacka2.second+tacka1.second*tacka1.second;
    double povrsina=sqrt(s*(s-a)*(s-b)*(s-c));
    return povrsina;
    
}

bool DaLiJePozitivnoOrijentiran() const{
    int temp;
    temp=tacka1.first*(tacka2.second-tacka3.second)-tacka2.first*(tacka3.second-tacka1.second)+tacka3.first*(tacka1.second-tacka2.second);
   
    if(temp>=0) return true;
    else if(temp<0)return false;
    
}

bool DaLiJeUnutra(const Tacka &t) const{
    int or1,or2,or3;
    or1=Orijentacija(tacka1,tacka2,t);
    or2=Orijentacija(tacka1,t,tacka3);
    or3=Orijentacija(t,tacka2,tacka3);
    if(or1>0 and or2>0 and or3>0)return true;
    else return false;
}

void Ispisi() const{
    cout<<"(("<<tacka1.first<<","<<tacka1.second<<"),("<<tacka2.first<<","<<tacka2.second<<"),("<<tacka3.first<<","<<tacka3.second<<"))";
    
}

void Transliraj(double delta_x, double delta_y){
    
    tacka1.first+=delta_x;
    tacka2.first+=delta_x;
    tacka3.first+=delta_x;
    tacka1.second+=delta_y;
    tacka2.second+=delta_y;
    tacka3.second+=delta_y;
    
}

void Centriraj(const Tacka &t){
    Tacka centar=DajCentar();
    tacka1.first= t.first+tacka1.first;
    tacka2.first= t.first+tacka2.first;
    tacka3.first= t.first+tacka3.first;
    tacka1.second= t.second+tacka1.second;
    tacka2.second= t.second+tacka2.second;
    tacka3.second= t.second+tacka3.second;
}

void Rotiraj(const Tacka &t, double ugao){
    double xc,yc;
    xc=t.first*(tacka1.first-t.first)*cos(ugao)-(tacka1.second-t.second)*sin(ugao);
    xc=t.second*(tacka1.first-t.first)*sin(ugao)-(tacka1.second-t.second)*cos(ugao);
    tacka1=make_pair(xc,yc);
    
    xc=t.first*(tacka2.first-t.first)*cos(ugao)-(tacka2.second-t.second)*sin(ugao);
    xc=t.second*(tacka2.first-t.first)*sin(ugao)-(tacka2.second-t.second)*cos(ugao);
    tacka2=make_pair(xc,yc);
    
    xc=t.first*(tacka3.first-t.first)*cos(ugao)-(tacka3.second-t.second)*sin(ugao);
    xc=t.second*(tacka3.first-t.first)*sin(ugao)-(tacka3.second-t.second)*cos(ugao);
    tacka3=make_pair(xc,yc);
}

void Skaliraj(const Tacka &t, double faktor){
    
    if(fabs(faktor)==0)throw domain_error("Nekorektan faktor skaliranja");
    double xc,yc;
    xc=t.first+faktor*(tacka1.first+t.first);
    yc=t.second+faktor*(tacka1.second+t.second);
    tacka1=make_pair(xc,yc);
    
    xc=t.first+faktor*(tacka2.first+t.first);
    yc=t.second+faktor*(tacka2.second+t.second);
    tacka2=make_pair(xc,yc);
    
    xc=t.first+faktor*(tacka3.first+t.first);
    yc=t.second+faktor*(tacka3.second+t.second);
    tacka3=make_pair(xc,yc);
}

void Rotiraj(double ugao){
    Tacka t;
    t=DajCentar();
    double xc,yc;
    xc=t.first*(tacka1.first-t.first)*cos(ugao)-(tacka1.second-t.second)*sin(ugao);
    xc=t.second*(tacka1.first-t.first)*sin(ugao)-(tacka1.second-t.second)*cos(ugao);
    tacka1=make_pair(xc,yc);
    
    xc=t.first*(tacka2.first-t.first)*cos(ugao)-(tacka2.second-t.second)*sin(ugao);
    xc=t.second*(tacka2.first-t.first)*sin(ugao)-(tacka2.second-t.second)*cos(ugao);
    tacka2=make_pair(xc,yc);
    
    xc=t.first*(tacka3.first-t.first)*cos(ugao)-(tacka3.second-t.second)*sin(ugao);
    xc=t.second*(tacka3.first-t.first)*sin(ugao)-(tacka3.second-t.second)*cos(ugao);
    tacka3=make_pair(xc,yc);
    
}

void Skaliraj(double faktor){
    Tacka t;
    t=DajCentar();
     if(fabs(faktor)==0)throw domain_error("Nekorektan faktor skaliranja");
    double xc,yc;
    xc=t.first+faktor*(tacka1.first+t.first);
    yc=t.second+faktor*(tacka1.second+t.second);
    tacka1=make_pair(xc,yc);
    
    xc=t.first+faktor*(tacka2.first+t.first);
    yc=t.second+faktor*(tacka2.second+t.second);
    tacka2=make_pair(xc,yc);
    
    xc=t.first+faktor*(tacka3.first+t.first);
    yc=t.second+faktor*(tacka3.second+t.second);
    tacka3=make_pair(xc,yc);
}

friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);

friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);

friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

    
};


bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
   
    
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){

    
    
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){

    
}


int main (){
 /*   
    int broj;
    
    cout<<"Kolko zelite kreirati trouglova: "<<endl;
    cin>> broj;
    vector<Trougao> v; 
    Trougao tr;
    
    for(int i=1;i<=broj;i++){
    cout <<"Unesite podatke za "<<i<<". trougao (x1 y1 x2 y2 x3 y3): "<<endl;
    cin>>tr;
    v.push_back(tr);
    }
    
    double dx,dy;
    
    cout<<"Unesite vektor translacije (dx dy): "<<endl;
    cin>>dx>>dy;
    for(int i=0; i<broj;i++){
    Trougao TEMP;
    TEMP=v[i];
    TEMP.Transliraj(dx,dy);
    TEMP.Ispisi();
    cout<<endl;
    }
    
    
    
    
    */
    
	return 0;
}