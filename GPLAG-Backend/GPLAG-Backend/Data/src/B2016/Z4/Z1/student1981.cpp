/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <utility>
#include <memory>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;

typedef std::pair<double, double> Tacka;

class Trougao {
Tacka t1,t2,t3;

static double DuzinaStranice( Tacka t1,  Tacka t2) {
    return sqrt(pow(t1.first-t2.first,2)+pow(t1.second-t2.second,2));
}

static double Povrsina (Tacka t1, Tacka t2, Tacka t3) {
    return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
}

static bool Poredi (double x, double y) {
    double e(1e-10);
    if(fabs(x-y)<=e*(fabs(x)+fabs(y))) return true;
    return false;
}

static bool PorediTacke (Tacka t1, Tacka t2) {
    
    if(Trougao::Poredi(t1.first,t2.first) && Trougao::Poredi(t1.second,t2.second)) return true;
    return false;
    
}
static bool Proporcionalni (double x, double y, double p, double q, double a, double b) {
    double k1,k2,k3;
    k1=x/y;
    k2=p/q;
    k3=a/b;
    if(Trougao::Poredi(k1,k2) && Trougao::Poredi(k1,k3)) return true;
    return false;
}
static bool Podudarni(Tacka x, Tacka y,Tacka p, Tacka q) {
   
    if(Trougao::Poredi(Trougao::DuzinaStranice(x,y),Trougao::DuzinaStranice(p,q)) ) return true;
    return false;
}
static double NajduzaStranica (Tacka x, Tacka y,Tacka z,Tacka &p) {
    double a(DuzinaStranice(x,y)),b(DuzinaStranice(x,z)),c(DuzinaStranice(z,y));
    double max(a);
    if(max<b) max=b;
    if(max<c) max=c;
    
    if(Trougao::Poredi(max,a)) p=z;
    if(Trougao::Poredi(max,b)) p=y;
    if(Trougao::Poredi(max,c)) p=x;
    
    return max;
}
static double NajkracaStranica (Tacka x, Tacka y,Tacka z,Tacka &p) {
    double a(DuzinaStranice(x,y)),b(DuzinaStranice(x,z)),c(DuzinaStranice(z,y));
    double min(a);
    if(min>b) min=b;
    if(min>c) min=c;
    
    if(Trougao::Poredi(min,a)) p=z;
    if(Trougao::Poredi(min,b)) p=y;
    if(Trougao::Poredi(min,c)) p=x;
    
    return min;
}
    
static double SrednjaStranica (Tacka x, Tacka y,Tacka z, Tacka &p) {
    double a(DuzinaStranice(x,y)),b(DuzinaStranice(x,z)),c(DuzinaStranice(z,y));
    double sr,min,max;
    max=NajduzaStranica(x,y,z,p);
    min=NajkracaStranica(x,y,z,p);
    
    if((Trougao::Poredi(max,a) && Trougao::Poredi(min,b)) || (Trougao::Poredi(max,b) && Trougao::Poredi(min,a))) sr=c;
    else if((Trougao::Poredi(max,a) && Trougao::Poredi(min,c)) || (Trougao::Poredi(max,c) && Trougao::Poredi(min,a))) sr=b;
    else if((Trougao::Poredi(max,b) && Trougao::Poredi(min,c)) || (Trougao::Poredi(max,c) && Trougao::Poredi(min,b))) sr=a;
    
    if(Trougao::Poredi(sr,a)) p=z;
    if(Trougao::Poredi(sr,b)) p=y;
    if(Trougao::Poredi(sr,c)) p=x;
    
    return sr;
    
}


public:

Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Trougao::Orijentacija(t1,t2,t3)==0) std::domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1;
    Trougao::t2=t2;
    Trougao::t3=t3;
}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    *this=Trougao(t1,t2,t3);
}
void Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>3) std::range_error ("Nekorektan indeks");
    if(indeks==1) t1=t;
    if(indeks==2) t2=t;
    if(indeks==3) t3=t;
}
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Povrsina(t1,t2,t3)<0)
    return -1;
    if(Povrsina(t1,t2,t3)>0)
    return 1;
    if(Poredi(Povrsina(t1,t2,t3),0))
    return 0;
    return 0;
}
Tacka DajTjeme(int indeks) const { 
    if(indeks<1 || indeks>3) std::range_error ("Nekorektan indeks");
    if(indeks==1) return t1;
    if(indeks==2) return t2;
    if(indeks==3) return t3;

    }
double DajStranicu(int indeks) const {
    double d;
    if(indeks<1 || indeks>3) std::range_error ("Nekorektan indeks");
    if(indeks==1) d=DuzinaStranice(t2,t3);
    if(indeks==2) d=DuzinaStranice(t1,t3);
    if(indeks==3) d=DuzinaStranice(t1,t2);
    return d;
}
double DajUgao(int indeks) const {
    double a,b,c,ugao;
    if(indeks<1 || indeks>3) std::range_error ("Nekorektan indeks");
    if(indeks==1) {
        a=DuzinaStranice(t1,t2);
        b=DuzinaStranice(t1,t3);
        c=DuzinaStranice(t2,t3);
    }
    if(indeks==2) {
        a=DuzinaStranice(t2,t1);
        b=DuzinaStranice(t2,t3);
        c=DuzinaStranice(t1,t3);
    }
    if(indeks==3) {
        a=DuzinaStranice(t3,t2);
        b=DuzinaStranice(t3,t1);
        c=DuzinaStranice(t1,t2);
    }
    
    ugao=acos((b*b+a*a-c*c)/(2*a*b));
    return ugao;
}
Tacka DajCentar() const {
    Tacka T;
    T.first=(t1.first+t2.first+t3.first)/3;
    T.second=(t1.second+t2.second+t3.second)/3;
    return T;
}
double DajObim() const {
    double a(DuzinaStranice(t1,t2)),b(DuzinaStranice(t1,t3)),c(DuzinaStranice(t2,t3));
    return a+b+c;
}
double DajPovrsinu() const {
    return abs(Povrsina(t1,t2,t3))/2;
}

bool DaLiJePozitivnoOrijentiran() const {
    if(Povrsina(t1,t2,t3)>0) return true;
    return false;
}
bool DaLiJeUnutra(const Tacka &t) const {
    if(Trougao::Orijentacija(t1,t2,t3)==Trougao::Orijentacija(t1,t2,t) && 
    Trougao::Orijentacija(t2,t3,t)==Trougao::Orijentacija(t1,t2,t3) &&
    Trougao::Orijentacija(t1,t2,t3)==Trougao::Orijentacija(t3,t1,t)) return true;
    return false;
    
}
void Ispisi() const {
    cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","
    <<t3.second<<"))";
}
void Transliraj(double delta_x, double delta_y) {
    t1.first+=delta_x;
    t1.second+=delta_y;
    
    t2.first+=delta_x;
    t2.second+=delta_y;
    
    t3.first+=delta_x;
    t3.second+=delta_y;
}

void Centriraj(const Tacka &t) {
    double x,y;
    
    x=t.first-this->DajCentar().first;
    y=t.second-this->DajCentar().second;
    
    Transliraj(x,y);
}

void Rotiraj(const Tacka &t, double ugao) {
    double a,b,c;
    a=t1.first;
    b=t2.first;
    c=t3.first;
    
    a=(t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao));
    t1.second=(t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao));
    t1.first=a;
    
    b=(t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao));
    t2.second=(t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao));
    t2.first=b;
    
    c=(t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao));
    t3.second=(t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao));
    t3.first=c;
    
}
void Skaliraj(const Tacka &t, double faktor) {
    if(Poredi(faktor,0)) throw std::domain_error ("Nekorektan faktor skaliranja");
    
    t1.first=t.first+faktor*(t1.first-t.first);
    t1.second=t.second+faktor*(t1.second-t.second);
    
    t2.first=t.first+faktor*(t2.first-t.first);
    t2.second=t.second+faktor*(t2.second-t.second);
    
    t3.first=t.first+faktor*(t3.first-t.first);
    t3.second=t.second+faktor*(t3.second-t.second);
    
    
}
void Rotiraj(double ugao) {
    Tacka t(DajCentar());
    Rotiraj(t,ugao);
}
void Skaliraj(double faktor) {
    Tacka t(DajCentar());
    Skaliraj(t,faktor);

}
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    int br(0);
   if(Trougao::PorediTacke(t1.Trougao::t1,t2.Trougao::t1) || Trougao::PorediTacke(t1.Trougao::t1,t2.Trougao::t2) 
   || Trougao::PorediTacke(t1.Trougao::t1,t2.Trougao::t3)) br++;
   if( Trougao::PorediTacke(t1.Trougao::t2,t2.Trougao::t1) || Trougao::PorediTacke(t1.Trougao::t2,t2.Trougao::t2)
   || Trougao::PorediTacke(t1.Trougao::t2,t2.Trougao::t3)) br++;
    if(Trougao::PorediTacke(t1.Trougao::t3,t2.Trougao::t1) || Trougao::PorediTacke(t1.Trougao::t3,t2.Trougao::t2) 
   || Trougao::PorediTacke(t1.Trougao::t3,t2.Trougao::t3)) br++;
   if(br==3) return true;
   return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    Tacka a1(t1.Trougao::t1), b1(t1.Trougao::t2), c1(t1.Trougao::t3);
    
    Tacka a2(t2.Trougao::t1), b2(t2.Trougao::t2), c2(t2.Trougao::t3);

    double max,min,max1,min1,sr,sr1;
    Tacka p,q,r,p1,q1,r1;
    
    max=Trougao::NajduzaStranica(a1,b1,c1,p);
    min=Trougao::NajkracaStranica(a1,b1,c1,q);
    sr=Trougao::SrednjaStranica(a1,b1,c1,r);
    
    max1=Trougao::NajduzaStranica(a2,b2,c2,p1);
    min1=Trougao::NajkracaStranica(a2,b2,c2,q1);
    sr1=Trougao::SrednjaStranica(a2,b2,c2,r1);

    if(Trougao::Poredi(max,max1) && Trougao::Poredi(min,min1) && Trougao::Poredi(sr,sr1) 
    && Trougao::Orijentacija(p1,q1,r1)==Trougao::Orijentacija(p,q,r)) return true;
    
    
    return false;
     
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {

    if(DaLiSuPodudarni(t1,t2)) return true;
    
    Tacka a1(t1.Trougao::t1), b1(t1.Trougao::t2), c1(t1.Trougao::t3);
    
    Tacka a2(t2.Trougao::t1), b2(t2.Trougao::t2), c2(t2.Trougao::t3);

    double max,min,max1,min1,sr,sr1;
    Tacka p,q,r,p1,q1,r1;
    
    max=Trougao::NajduzaStranica(a1,b1,c1,p);
    min=Trougao::NajkracaStranica(a1,b1,c1,q);
    sr=Trougao::SrednjaStranica(a1,b1,c1,r);
    
    max1=Trougao::NajduzaStranica(a2,b2,c2,p1);
    min1=Trougao::NajkracaStranica(a2,b2,c2,q1);
    sr1=Trougao::SrednjaStranica(a2,b2,c2,r1);

    if(Trougao::Proporcionalni(max,max1,min,min1,sr,sr1) 
    && Trougao::Orijentacija(p1,q1,r1)==Trougao::Orijentacija(p,q,r)) return true;


    return false;
}

int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    cin>>n;
    vector<shared_ptr<Trougao>> v;
    
    for (int i = 0; i <n; i++) {
       
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka x,y,z;
        cin>>x.first>>x.second;
        cin>>y.first>>y.second;
        cin>>z.first>>z.second;
        if(Trougao::Orijentacija(x,y,z)==0) {
            cout<<"Nekorektne pozicije tjemena, ponovite unos!"<<endl;
            cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        
            cin>>x.first>>x.second;
            cin>>y.first>>y.second;
            cin>>z.first>>z.second;
        }
        
        shared_ptr<Trougao> p(make_shared<Trougao> (x,y,z));
       
        v.push_back(p);
    }
        
        cout<<"Unesite vektor translacije (dx dy): ";
        double dx,dy;
        cin>>dx>>dy;
        std::transform(v.begin(),v.end(),v.begin(), [dx,dy](shared_ptr<Trougao> p){ p->Transliraj(dx,dy); return p; } );
        
        
        cout<<"Unesite ugao rotacije: ";
        double ugao;
        cin>>ugao;
        std::transform(v.begin(),v.end(),v.begin(), [ugao](shared_ptr<Trougao> p){ p->Rotiraj(ugao); return p;} );
        
        cout<<"Unesite faktor skaliranja: ";
        double faktor;
        cin>>faktor;
        std::transform(v.begin(),v.end(),v.begin(), [faktor](shared_ptr<Trougao> p){ p->Skaliraj(p->DajTjeme(1),faktor); return p;} );
        
        cout<<"Trouglovi nakon obavljenih transformacija:\n";
        std::sort(v.begin(), v.end(), [] (shared_ptr<Trougao> p, shared_ptr <Trougao> q) {
            return p->DajPovrsinu()<q->DajPovrsinu();  });
        std::for_each(v.begin(), v.end(), [] (shared_ptr<Trougao> p) {p->Ispisi(); cout<<endl; return p;} );
        
        cout<<"Trougao sa najmanjim obimom: ";
        (*std::min_element(v.begin(),v.end(), [] (shared_ptr<Trougao> x,shared_ptr<Trougao> y){ 
            return x->DajObim()<y->DajObim(); }))->Ispisi();
        
        
        cout<<endl;
        
        int br(0);
        vector<int> a,b;
        for (int i=0; i<n; i++) 
            for(int j=i+1; j<n; j++)
            if(DaLiSuIdenticni(*v[i],*v[j])) {
                a.push_back(i);
                b.push_back(j);
                br++;
            }
        if(br==0) cout<<"Nema identicnih trouglova!\n";
        
        else {
            cout<<"Parovi identicnih trouglova:\n";
            for(int i=0; i<a.size(); i++) {
            v[a[i]]->Ispisi(); cout<<" i ";
            v[b[i]]->Ispisi(); cout<<endl;
            }
        }
    
        br=0;
        a.resize(0); b.resize(0);
        for (int i=0; i<n; i++) 
            for(int j=i+1; j<n; j++)
            if(DaLiSuPodudarni(*v[i],*v[j]) ) {
                 a.push_back(i); b.push_back(j);
                br++;
            }
        if(br==0) cout<<"Nema podudarnih trouglova!\n";
        else {
            cout<<"Parovi podudarnih trouglova:\n";
            for(int i=0; i<a.size(); i++) {
            v[a[i]]->Ispisi(); cout<<" i ";
            v[b[i]]->Ispisi(); cout<<endl;
            }
        }
        
        br=0;
        a.resize(0); b.resize(0);
        for (int i=0; i<n; i++) 
            for(int j=i+1; j<n; j++)
            if(DaLiSuSlicni(*v[i],*v[j])) {
                a.push_back(i); b.push_back(j);
                br++;
            }
    
        if(br==0) cout<<"Nema slicnih trouglova!\n";
        else {
            cout<<"Parovi slicnih trouglova:\n";
            for(int i=0; i<a.size(); i++) {
            v[a[i]]->Ispisi(); cout<<" i ";
            v[b[i]]->Ispisi(); cout<<endl;
            }
        }
        
	return 0;
	
	
}