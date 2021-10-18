/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <new>
#include <utility>
#include <cmath>
#include <memory>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
const double Eps(1e-10);
typedef pair<double, double> Tacka;
class Trougao {
    Tacka tacka1, tacka2, tacka3;
    
    double Duzina(Tacka t1, Tacka t2) const {
        return sqrt((t2.first-t1.first)*(t2.first-t1.first) + (t2.second-t1.second)*(t2.second-t1.second));
    }
    double Ugao(double a, double b, double c) const {
        return acos(double(a*a+b*b-c*c)/double(2*a*b));
    }
    double Izraz(Tacka t1, Tacka t2, Tacka t3) const {
        return t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second);
    }
    Tacka Rot_Ugao(Tacka t1, Tacka t, double ugao) {
        double x=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao); 
        double y=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao); 
        return make_pair(x,y);
    }
    Tacka Ska_Faktor(Tacka t1,Tacka t, double k) {
        double x=t.first+k*(t1.first-t.first);
        double y=t.second+k*(t1.second-t.second);
        return make_pair(x,y);
    }
    static bool Poredi(Tacka t1, Tacka t2)  {
        if(jesuLiJednaki(t1.first,t2.first)==true && jesuLiJednaki(t1.second,t2.second)==true) return true;
        return false;
    }
    static bool jesuLiJednaki(double x, double y) {
        return fabs(x-y)<=Eps *(fabs(x)+fabs(y));
    }
    
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if((t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second)) > 0) return 1;
    else if((t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second)) < 0) return -1;
    else if(fabs(t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second))<=Eps) return 0;
    return 0;
    }
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

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double orij=Izraz(t1,t2,t3);
    if(fabs(orij)<=Eps) throw domain_error("Nekorektne pozicije tjemena");
    tacka1=t1; tacka2=t2; tacka3=t3;
    }
    
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
    this->tacka1=t1; this->tacka2=t2; this->tacka3=t3;
    }
    
void Trougao::Postavi(int indeks, const Tacka &t) {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
    if(indeks==1) this->tacka1=t;
    else if(indeks==2) this->tacka2=t;
    else if(indeks==3) this->tacka3=t;
    if(fabs(Izraz(tacka1,tacka2,tacka3))<=Eps) throw domain_error("Nekorektne pozicije tjemena");
    }

Tacka Trougao::DajTjeme(int indeks) const { 
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
    if(indeks==1) return make_pair(tacka1.first, tacka1.second);
    else if(indeks==2) return make_pair(tacka2.first, tacka2.second);
    else if(indeks==3) return make_pair(tacka3.first, tacka3.second); 
    return make_pair(0,0);
}

double Trougao::DajStranicu(int indeks) const {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
    double duzina(0);
    if(indeks==1) duzina=Duzina(tacka2, tacka3); 
    else if(indeks==2) duzina=Duzina(tacka1, tacka3);
    else if(indeks==3) duzina=Duzina(tacka1, tacka2);
    return duzina;
}

double Trougao::DajUgao(int indeks) const {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
    double ugao(0),a,b,c;
    if(indeks==1) { a=Duzina(tacka1, tacka3); b=Duzina(tacka1, tacka2); c=Duzina(tacka2, tacka3); ugao=Ugao(a, b, c); }
    else if(indeks==2) { a=Duzina(tacka2, tacka1); b=Duzina(tacka2, tacka3); c=Duzina(tacka1, tacka3); ugao=Ugao(a,b,c); }
    else if(indeks==3) { a=Duzina(tacka3, tacka1); b=Duzina(tacka3, tacka2); c=Duzina(tacka1, tacka2); ugao=Ugao(a,b,c); }
    return ugao;
}

Tacka Trougao::DajCentar() const {
    return make_pair((tacka1.first+tacka2.first+tacka3.first)/3, (tacka1.second+tacka2.second+tacka3.second)/3);
}

double Trougao::DajObim() const {
    double a, b, c;
    a=Duzina(tacka1, tacka2); b=Duzina(tacka2, tacka3); c=Duzina(tacka1, tacka3);
    return a+b+c;
}

double Trougao::DajPovrsinu() const {
    return (0.5)*abs(tacka1.first*(tacka2.second-tacka3.second) - tacka2.first*(tacka1.second-tacka3.second) + tacka3.first*(tacka1.second-tacka2.second));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
    return Orijentacija(tacka1, tacka2, tacka3)>0 ;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if(DaLiJePozitivnoOrijentiran()) { if(Orijentacija(tacka1,tacka2,t)>0 && Orijentacija(tacka2,tacka3,t)>0 && Orijentacija(tacka3,tacka1,t)>0) return true;}
    else { if(Orijentacija(tacka1,tacka2,t)<0 && Orijentacija(tacka2,tacka3,t)<0 && Orijentacija(tacka3,tacka1,t)<0) return true; }
    return false;
}

void Trougao::Ispisi() const {
    cout<<"(("<<tacka1.first<<","<<tacka1.second<<"),("<<tacka2.first<<","<<tacka2.second<<"),("<<tacka3.first<<","<<tacka3.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    tacka1.first+=delta_x; tacka1.second+=delta_y;
    tacka2.first+=delta_x; tacka2.second+=delta_y;
    tacka3.first+=delta_x; tacka3.second+=delta_y;
    Postavi(tacka1,tacka2,tacka3);
}

void Trougao::Centriraj(const Tacka &t) {
    Tacka m=DajCentar();
    int x, y;
    x=abs(t.first-m.first);
    y=abs(t.second-m.second);
    tacka1.first+=x; tacka1.second+=y;
    tacka2.first+=x; tacka2.second+=y;
    tacka3.first+=x; tacka3.second+=y;
    Postavi(tacka1,tacka2,tacka3);
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    Tacka t1,t2,t3;
    t1=Rot_Ugao(tacka1,t,ugao);
    t2=Rot_Ugao(tacka2,t,ugao);
    t3=Rot_Ugao(tacka3,t,ugao);
    Postavi(t1,t2,t3);
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(fabs(faktor)<=Eps) throw domain_error("Nekorektan faktor skaliranja");
    Tacka t1,t2,t3;
    t1=Ska_Faktor(tacka1,t,faktor);
    t2=Ska_Faktor(tacka2,t,faktor);
    t3=Ska_Faktor(tacka3,t,faktor);
    Postavi(t1,t2,t3);
}

void Trougao::Rotiraj(double ugao) {
    Tacka t=DajCentar(); 
    Tacka t1,t2,t3;
    t1=Rot_Ugao(tacka1,t,ugao);
    t2=Rot_Ugao(tacka2,t,ugao);
    t3=Rot_Ugao(tacka3,t,ugao);
    Postavi(t1,t2,t3);
}

void Trougao::Skaliraj(double faktor) {
    if(fabs(faktor)<=Eps) throw domain_error("Nekorektan faktor skaliranja");
    Tacka t=DajCentar();
    Tacka t1,t2,t3;
    t1=Ska_Faktor(tacka1,t,faktor);
    t2=Ska_Faktor(tacka2,t,faktor);
    t3=Ska_Faktor(tacka3,t,faktor);
    Postavi(t1,t2,t3);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if((Trougao::Poredi(t1.tacka1,t2.tacka1)==true || Trougao::Poredi(t1.tacka1,t2.tacka2)==true || Trougao::Poredi(t1.tacka1,t2.tacka3)==true) && (Trougao::Poredi(t1.tacka2,t2.tacka1)==true || Trougao::Poredi(t1.tacka2,t2.tacka2)==true || Trougao::Poredi(t1.tacka2,t2.tacka3)==true) && (Trougao::Poredi(t1.tacka3,t2.tacka1)==true || Trougao::Poredi(t1.tacka3,t2.tacka2)==true || Trougao::Poredi(t1.tacka3,t2.tacka3)==true)) return true;
     return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    int n1,n2;
    n1=Trougao::Orijentacija(t1.tacka1,t1.tacka2,t1.tacka3); n2=Trougao::Orijentacija(t2.tacka1,t2.tacka2,t2.tacka3);
    double a1,b1,c1,a2,b2,c2;
    a1=t1.DajUgao(1); b1=t1.DajUgao(2); c1=t1.DajUgao(3);
    a2=t2.DajUgao(1); b2=t2.DajUgao(2); c2=t2.DajUgao(3);
    double p1,p2;
    p1=t1.DajPovrsinu(); p2=t2.DajPovrsinu();
    if(n1==n2) {
        if(((Trougao::jesuLiJednaki(a1,a2)==true && Trougao::jesuLiJednaki(b1,b2)==true) || (Trougao::jesuLiJednaki(a1,c2)==true && Trougao::jesuLiJednaki(b1,a2)==true) || (Trougao::jesuLiJednaki(a1,b2)==true && Trougao::jesuLiJednaki(b1,c2)==true)) && Trougao::jesuLiJednaki(p1,p1)==true) { return true;}
    }
    if(n1!=n2) {
        if(((Trougao::jesuLiJednaki(a1,a2)==true && Trougao::jesuLiJednaki(b1,c2)==true)|| (Trougao::jesuLiJednaki(c1,c2)==true && Trougao::jesuLiJednaki(a1,b2)==true) || (Trougao::jesuLiJednaki(b1,b2)==true && Trougao::jesuLiJednaki(a1,c2)==true)) && Trougao::jesuLiJednaki(p1,p2)==true) { return true;}
    } 
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    int n1,n2;
    n1=Trougao::Orijentacija(t1.tacka1,t1.tacka2,t1.tacka3); n2=Trougao::Orijentacija(t2.tacka1,t2.tacka2,t2.tacka3);
    double a1,b1,c1,a2,b2,c2;
    a1=t1.DajUgao(1); b1=t1.DajUgao(2); c1=t1.DajUgao(3);
    a2=t2.DajUgao(1); b2=t2.DajUgao(2); c2=t2.DajUgao(3); 
    if(n1==n2) {
        if((Trougao::jesuLiJednaki(a1,a2)==true && Trougao::jesuLiJednaki(b1,b2)==true) || (Trougao::jesuLiJednaki(a1,c2)==true && Trougao::jesuLiJednaki(b1,a2)==true) || (Trougao::jesuLiJednaki(a1,b2)==true && Trougao::jesuLiJednaki(b1,c2)==true))  { return true;}
    }
    if(n1!=n2) {
        if((Trougao::jesuLiJednaki(a1,a2)==true && Trougao::jesuLiJednaki(b1,c2)==true)|| (Trougao::jesuLiJednaki(c1,c2)==true && Trougao::jesuLiJednaki(a1,b2)==true) || (Trougao::jesuLiJednaki(b1,b2)==true && Trougao::jesuLiJednaki(a1,c2)==true)) { return true;}
    }
    return false;
}
int main ()
{
    int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    vector<shared_ptr<Trougao>> vp(n);
    try {
    for(int i=0;i<n;i++)
    {
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1,t2,t3;
        double x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        t1=make_pair(x1,y1);
        t2=make_pair(x2,y2);
        t3=make_pair(x3,y3);
        try {
        Trougao t(t1,t2,t3);
        vp[i]=make_shared<Trougao> (t); 
        }
        catch(domain_error e) {
            cout<<e.what()<<", ponovite unos!"<<endl;
            i--;
        }
    }
    
    double delx, dely;
    cout<<"Unesite vektor translacije (dx dy): "; cin>>delx>>dely;
    transform(vp.begin(),vp.end(),vp.begin(),[delx,dely] (shared_ptr<Trougao> p) {p->Transliraj(delx,dely); return p;});
    double ugao;
    cout<<"Unesite ugao rotacije: "; cin>>ugao;
    transform(vp.begin(),vp.end(),vp.begin(),[ugao] (shared_ptr<Trougao> p){p->Rotiraj(ugao); return p;});
    double faktor;
    cout<<"Unesite faktor skaliranja: "; cin>>faktor;
    transform(vp.begin(),vp.end(),vp.begin(),[faktor] (shared_ptr<Trougao> p){p->Skaliraj(p->DajTjeme(1),faktor); return p;});
    sort(vp.begin(),vp.end(),[] (shared_ptr<Trougao> p1, shared_ptr<Trougao> p2) -> bool { return p1->DajPovrsinu() < p2->DajPovrsinu(); });
    cout<<"Trouglovi nakon obavljenih transformacija:"<<endl;
    for_each(vp.begin(),vp.end(),[](shared_ptr<Trougao> p) {p->Ispisi(); cout<<endl;}); 
    auto pt=min_element(vp.begin(),vp.end(),[] (shared_ptr<Trougao> p1, shared_ptr<Trougao> p2) {return p1->DajObim()<p2->DajObim();});
    Trougao tro=**pt;
    cout<<"Trougao sa najmanjim obimom: ";
    tro.Ispisi(); 
    cout<<endl;
    int br1(0);
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(DaLiSuIdenticni(*vp[i],*vp[j]))  {br1++; if(br1==1) {cout<<"Parovi identicnih trouglova:"<<endl;} vp[i]->Ispisi(); cout<<" i "; vp[j]->Ispisi(); cout<<endl;}
        }
    }
    if(br1==0) cout<<"Nema identicnih trouglova!"<<endl;
    int br(0);
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(DaLiSuPodudarni(*vp[i],*vp[j])) { br++;if(br==1){cout<<"Parovi podudarnih trouglova:"<<endl;} vp[i]->Ispisi(); cout<<" i "; vp[j]->Ispisi(); cout<<endl;}
        }
    }
    if(br==0) cout<<"Nema podudarnih trouglova!"<<endl;
    int br2(0);
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(DaLiSuSlicni(*vp[i],*vp[j])) { br2++; if(br2==1) {cout<<"Parovi slicnih trouglova:"<<endl;} vp[i]->Ispisi(); cout<<" i ";  vp[j]->Ispisi(); cout<<endl;}
        }
    }
    if(br2==0) cout<<"Nema slicnih trouglova!";
    }
    catch(range_error e) {
        cout<<e.what();
    }
    catch(domain_error ee) {
        cout<<ee.what();
    }
	return 0;
}