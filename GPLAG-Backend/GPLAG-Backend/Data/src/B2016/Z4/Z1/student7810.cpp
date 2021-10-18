/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <utility>

#define PI 4*atan(1)

using std::cout;
using std::cin;
using std::endl;
using std::pair;
using std::range_error;
using std::domain_error;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::make_pair;
typedef pair<double, double> Tacka;
bool Jednakost (double x, double y, double eps=1e-10){
    return std::fabs(x-y)<= eps* (std::fabs(x)+std::fabs(y));
}
double DuzinaStranice(Tacka t1, Tacka t2){
    return (std::sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second)));
}
double Ugao (Tacka prva, Tacka druga, Tacka treca){
    return std::acos((std::pow(DuzinaStranice(prva,treca),2)+std::pow(DuzinaStranice(prva,druga),2)-std::pow(DuzinaStranice(druga,treca),2))/(2*DuzinaStranice(prva,treca)*DuzinaStranice(prva,druga)));
    
}
double Povrsina (Tacka t1, Tacka t2, Tacka t3){
    return ((t1.first)*(t2.second - t3.second)- (t2.first)*(t1.second - t3.second) + (t3.first)*(t1.second - t2.second));
}
Tacka Rotacija (Tacka t, Tacka c, double ugao){
    Tacka nova;
    nova.first=c.first+(t.first-c.first)*cos(ugao)-(t.second-c.second)*sin(ugao);
    nova.second=c.second+(t.first-c.first)*sin(ugao)+(t.second-c.second)*cos(ugao);
    return nova;
}
// +( − ) cos α−( − ) sinα
// + ( − ) sin α+( − ) cosα
Tacka Skaliranje (Tacka t, Tacka c, double faktor){
    Tacka nova;
    nova.first=c.first+(t.first-c.first)*faktor;
    nova.second=c.second+(t.second-c.second)*faktor;
    return nova;
}

class Trougao{
    Tacka t1,t2,t3;
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {if (Orijentacija(t1,t2,t3)==0) throw domain_error ("Nekorektne pozicije tjemena"); Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;};
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {if (Orijentacija(t1,t2,t3)==0) throw domain_error ("Nekorektne pozicije tjemena"); Trougao::t1=t1; Trougao::t1=t2; Trougao::t3=t3;};
    void Postavi (int indeks, const Tacka &t) {if (indeks<1 || indeks>3) throw range_error ("Nekorektan indeks"); if (indeks==1) t1=t; else if (indeks==2) t2=t; else t3=t;};
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme (int indeks) const {if (indeks==1) return t1; else if (indeks==2) return t2; else return t3;};
    double DajStranicu(int indeks) const {if (indeks==1) return DuzinaStranice(t2,t3); else if (indeks==2) return DuzinaStranice(t1,t3); else return DuzinaStranice(t1,t2);};
    double DajUgao (int indeks) const {if (indeks==1) return Ugao(t1,t2,t3); else if (indeks==2) return Ugao(t2,t1,t3); else return Ugao(t3,t1,t2);};
    Tacka DajCentar () const { Tacka centar; centar.first=((t1.first+t2.first+t3.first)/3.); centar.second=((t1.second+t2.second+t3.second)/3.); return centar;};
    double DajObim () const {return (DuzinaStranice(t1,t2)+DuzinaStranice(t2,t3)+DuzinaStranice(t1,t3));};
    double DajPovrsinu () const {return ((t1.first)*(t2.second - t3.second)- (t2.first)*(t1.second - t3.second) + (t3.first)*(t1.second - t2.second));};
    bool DaLiJePozitivnoOrijentiran () const { return ((t1.first<t2.first) && (t2.first<t3.first));};
    bool DaLiJeUnutra (const Tacka &t) const {return Jednakost(DajPovrsinu(),Povrsina(t1,t2,t)+Povrsina(t1,t3,t)+Povrsina(t2,t3,t));};
    void Ispisi () const {cout<<"( ("<<t1.first<<","<<t1.second<<")"<<", ("<<t2.first<<","<<t2.second<<")"<<", ("<<t3.first<<","<<t3.second<<") )";};
    void Transliraj (double delta_x, double delta_y){t1.first+=delta_x;t1.second+=delta_y;t2.first+=delta_x;t2.second+=delta_y;t3.first+=delta_x;t3.second+=delta_y;};
    void Centriraj (const Tacka &t) {Transliraj(t.first-DajCentar().first,t.second-DajCentar().second);};
    void Rotiraj (const Tacka &t,double ugao){
        //Postavi(1,Rotacija(t1,t,ugao));Postavi(2,Rotacija(t2,t,ugao));Postavi(3,Rotacija(t3,t,ugao));
        t1=Rotacija(t1,t,ugao);t2=Rotacija(t2,t,ugao);t3=Rotacija(t3,t,ugao);
    };
    void Skaliraj(const Tacka &t, double faktor){if(Jednakost(faktor,0)) throw domain_error("Nekorektan faktor skaliranja"); Postavi(1,Skaliranje(t1,t,faktor));Postavi(2,Skaliranje(t2,t,faktor));Postavi(3,Skaliranje(t3,t,faktor));};
    void Rotiraj (double ugao){Tacka centar(DajCentar());t1=Rotacija(t1,centar,ugao);t2=Rotacija(t2,centar,ugao);t3=Rotacija(t3,centar,ugao);};
    void Skaliraj( double faktor){if(Jednakost(faktor,0)) throw domain_error("Nekorektan faktor skaliranja"); Tacka centar(DajCentar()); t1=Skaliranje(t1,centar,faktor);t2=Skaliranje(t2,centar,faktor);t3=Skaliranje(t3,centar,faktor);};
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    
};

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    int orijentacija((t1.first)*(t2.second - t3.second)- (t2.first)*(t1.second - t3.second) + (t3.first)*(t1.second - t2.second));
    if (orijentacija>0) return 1; else if (orijentacija<0)  return -1; else return 0;
}
bool DaLiSuIdenticni (const Trougao &tro1, const Trougao &tro2){
    vector<Tacka> v1; v1.push_back(tro1.t1);v1.push_back(tro1.t2);v1.push_back(tro1.t3);
    vector<Tacka> v2; v2.push_back(tro2.t1);v2.push_back(tro2.t2);v2.push_back(tro2.t3);
    bool ima(false);
    for (int i=0;i<v1.size();i++){
        ima=false;
        int k(0);
        for(int j=0;j<v2.size();j++){
            if (v1[i]==v2[j]) {ima=true;break;k=j;}
        }
        if(ima) {
            v1.erase(v1.begin()+i); v2.erase(v2.begin()+k);
            i--;
        }
        else return false;
    }
    if (Jednakost(v1.size(),0)) return true;

}
int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int broj_tr;
    cin>>broj_tr;
    vector<shared_ptr<Trougao>> trouglovi(broj_tr);
    for(int i=0;i<broj_tr;i++){
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        trouglovi[i]=make_shared<Trougao> (make_pair(x1,y1), make_pair(x2,y2), make_pair(x3,y3));
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    int dx,dy;
    cin>>dx>>dy;
    cout<<"Unesite ugao rotacije: ";
    int ugaorotacije;
    cin>>ugaorotacije;
    double ugao((ugaorotacije/180)*PI);
    trouglovi[0]->Rotiraj(trouglovi[0]->DajCentar(),ugao);
    trouglovi[0]->Ispisi();
   /* cout<<"Unesite faktor skaliranja: ";
    int faktorskaliranja;
    cin>>faktorskaliranja;
    for(int i=0;i<broj_tr;i++){
        auto rot(trouglovi[i]->DajCentar());
        auto skat(trouglovi[i]->DajTjeme(1));
        trouglovi[i]->Transliraj(dx,dy);
        trouglovi[i]->Rotiraj(rot,ugao);
        trouglovi[i]->Skaliraj(skat,faktorskaliranja);
    }
    cout<<"Trouglovi nakon obavljenih transformacija: ";
    for(int i=0;i<broj_tr;i++){
        trouglovi[i]->Ispisi();
    }*/
	return 0;
}