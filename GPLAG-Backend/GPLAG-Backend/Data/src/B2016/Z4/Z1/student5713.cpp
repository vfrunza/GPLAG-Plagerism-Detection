/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <memory>
#include<iomanip>
#include <utility>
const double epsilon (1e-10);

using namespace std;

typedef pair<double, double> Tacka;
const double PI=atan(1)*4;

class Trougao{
    Tacka A, B, C;
    double UdaljenostIzmedju2Tacke(const Tacka &t1, const Tacka &t2)const{
        return sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    }
    
    
    double  a=UdaljenostIzmedju2Tacke(B, C);
    double  b=UdaljenostIzmedju2Tacke(A, C);
    double  c=UdaljenostIzmedju2Tacke(A, B);
    void TestirajIndeks(int n){
        if(n<1 || n>3) throw range_error("Nekorektan indeks");
    }
    void TestirajIndeks(int n)const{
        if(n<1 || n>3) throw range_error("Nekorektan indeks");
    }
/*
    
    double Izraz ( Tacka t1,  Tacka t2,  Tacka t3){
        return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    }
    */
    double Izraz (const Tacka &t1, const Tacka &t2, const Tacka &t3)const{
       return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    }
    
    double Kosinusna_Teroema(int indeks)const{
        TestirajIndeks(indeks);
      
        double prva, druga, treca;
        if(indeks==1)   { prva=b; druga=c; treca=a;}
        else if(indeks==2)  { prva=a; druga=c; treca=b;}
        else {prva=a; druga=b; treca=c;}
        return acos((prva*prva+druga*druga-treca*treca)/(2*prva*druga));
    }
    
public:
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
   // if(((t2.first-t1.first)*(t3.second-t1.second)-(t2.second-t1.second)*(t3.first -t1.first))<epsilon)
   if(Orijentacija(t1, t2, t3)==0)
    throw domain_error("Nekorektne pozicije tjemena");
    A=t1;
    B=t2;
    C=t3;
    
}

void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
     if((t2.first-t1.first)*(t3.second-t1.second)-(t2.second-t1.second)*(t3.first -t1.first)<epsilon)
    throw domain_error("Nekorektne pozicije tjemena");
    A=t1;
    B=t2;
    B=t3;
}

void Postavi(int indeks, const Tacka &t){
    TestirajIndeks(indeks);
    if(indeks==1) A=t;
    else if(indeks==2) B=t;
    else C=t;
       if((B.first-A.first)*(C.second-A.second)-(B.second-A.second)*(C.first -A.first)<epsilon)
    throw domain_error("Nekorektne pozicije tjemena");
}

static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double povratna(0);
    //povratna=Izraz(t1,t2,t3); sto mi ovo nije radiloo
    povratna=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    if(povratna ==0) return 0;
    else if(povratna>0) return 1;
    return -1;
}

Tacka DajTjeme(int indeks) const{
    TestirajIndeks(indeks);
    if(indeks==1) return A;
    else if(indeks==2) return B;
    else return C;
}

double DajStranicu(int indeks) const{
    TestirajIndeks(indeks);
    double duzina;
    if(indeks==1) duzina=UdaljenostIzmedju2Tacke(B, C);
    else if(indeks==2) duzina=UdaljenostIzmedju2Tacke(C, A);
    else duzina=UdaljenostIzmedju2Tacke(A, B);
    return duzina;
}

double DajUgao(int indeks) const{
    TestirajIndeks(indeks);
    double ugao=Kosinusna_Teroema(indeks);
    ugao=ugao*PI/180;
    return ugao;
}

Tacka DajCentar() const{
    Tacka nova;
    nova.first=A.first+B.first+C.first;
    nova.first/=3;
    nova.second=A.second+B.second+C.second;
    nova.second/=3;
    return nova;
}

Tacka DajPrvu ()const{
    return A;
}
Tacka DajDrugu()const {
    return B;
}
double DajObim() const{
    return a+b+c;
}
double DajPovrsinu() const{
    double vr_izraza=Izraz(A, B, C);
    if(vr_izraza<0) vr_izraza=-vr_izraza;
    return vr_izraza/2;
}

bool DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija((*this).A, (*this).B, (*this).C)==1) return 1;
    return 0;

}
bool DaLiJeUnutra(const Tacka &t) const;

void Ispisi() const{
    cout<<"(("<<fixed<<setprecision(0)<<A.first<<","<<A.second<<")"<<",("<<B.first<<","<<B.second<<")"<<",("<<C.first<<","<<C.second<<"))"; 
}

void Transliraj(double delta_x, double delta_y){
    A.first+=delta_x; B.first+=delta_x; C.first+=delta_x;
    A.second+=delta_y; B.second+=delta_y; C.second+=delta_y;
}

void Centriraj(const Tacka &t){
    Tacka teziste=DajCentar();
    double udaljenost=teziste.first- t.first;
    if(udaljenost<0) udaljenost=-udaljenost;
    double udaljenost2=teziste.second-t.second;
    if(udaljenost2<0) udaljenost2=-udaljenost2;
    Transliraj(udaljenost, udaljenost2 );
}

void Rotiraj(const Tacka &t, double ugao){
   // if(ugao==0) return;
    double temp=A.first;
    A.first=t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao);
    //je li ovdje treba sad ova stara vr. A.first
    A.second=t.second+(temp-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao);
    
    temp=B.first;
    B.first=t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao);
    B.second=t.second+(temp-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao);
    
    temp=C.first;
    C.first=t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao);
    C.second=t.second+(temp-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao);
    
}

void Skaliraj(const Tacka &t, double faktor){
    if(faktor-0<epsilon) throw domain_error("Nekorektan faktor skaliranja");
    
    A.first=t.first+faktor*(A.first-t.first);
    A.second=t.second+faktor*(A.second-t.second);
    
    B.first=t.first+faktor*(B.first-t.first);
    B.second=t.second+faktor*(B.second-t.second);
    
    C.first=t.first+faktor*(C.first-t.first);
    C.second=t.second+faktor*(C.second-t.second);
    
    if(faktor<0) Rotiraj(180);
}



void Rotiraj(double ugao){
  //  if(ugao-0<epsilon) return;
    Tacka t=DajCentar();
    Rotiraj(t, ugao);
    
}
void Skaliraj(double faktor){
     if(faktor-0<epsilon) throw domain_error("Nekorektan faktor skaliranja");
    Tacka t=DajCentar();
   Skaliraj(t, faktor);
}

friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
if((t1.A==t2.A && t1.B==t2.B && t1.C==t2.C)
|| (t1.A==t2.A && t1.B==t2.C && t1.C==t2.B)
|| (t1.A==t2.B && t1.B==t2.A && t1.C==t2.C)
|| (t1.A==t2.B && t1.B==t2.C && t1.C==t2.A)
|| (t1.A==t2.C && t1.B==t2.A && t1.C==t2.B)
|| (t1.A==t2.C && t1.B==t2.B && t1.C==t2.A))return 1;
return 0;
}

friend bool DaLiSuPodudarni( const Trougao &t1,const Trougao &t2){
double prvi=t1.DajUgao(1);
double drugi=t1.DajUgao(2);
double treci=t1.DajUgao(3);
double prviprim=t2.DajUgao(1);
double drugiprim=t2.DajUgao(2);
double treciprim=t2.DajUgao(3);
double a1=t1.UdaljenostIzmedju2Tacke(t1.DajTjeme(1), t1.DajTjeme(2));
double a2=t1.UdaljenostIzmedju2Tacke(t1.DajTjeme(2), t1.DajTjeme(3));
double a3=t1.UdaljenostIzmedju2Tacke(t1.DajTjeme(3), t1.DajTjeme(1));

double a10=t2.UdaljenostIzmedju2Tacke(t2.DajTjeme(1), t2.DajTjeme(2));
double a20=t2.UdaljenostIzmedju2Tacke(t2.DajTjeme(2), t2.DajTjeme(3));
double a30=t2.UdaljenostIzmedju2Tacke(t2.DajTjeme(3), t2.DajTjeme(1));

if((a1==a10 || a1==a20 || a1==a30) && (a2==a10 || a2==a20 || a2==a30) && (a3==a10 || a3==a20 || a3==a30)){
vector<pair<double, Tacka>> vek, vek2;
vek.push_back(make_pair(prvi, t1.DajTjeme(1)));
vek.push_back(make_pair(drugi, t1.DajTjeme(2)));
vek.push_back(make_pair(treci, t1.DajTjeme(3)));
sort(vek.begin(), vek.end(), [](pair<double, Tacka> x, pair<double, Tacka> y){
    return x.first<y.first;
});

vek2.push_back(make_pair(prviprim, t2.DajTjeme(1)));
vek2.push_back(make_pair(drugiprim, t2.DajTjeme(2)));
vek2.push_back(make_pair(treciprim, t2.DajTjeme(3)));
sort(vek2.begin(), vek2.end(), [](pair<double, Tacka> x, pair<double, Tacka> y){
    return x.first<y.first;
});

return t1.Orijentacija(vek[0].second, vek[1].second, vek[2].second)==t2.Orijentacija(vek2[0].second, vek2[1].second, vek2[2].second);
}

 return 0;
 
 
  //  sort(v1.begin(), v1.end());
    //sort(v2.begin(), v2.end()); v1==v2
   // return testna && !(Orijentacija(t1.A, t1.B, t1.C)==Orijentacija(t2.A, t2.B,t2.C));
}

friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
 double prvi=t1.DajUgao(1);
double drugi=t1.DajUgao(2);
double treci=t1.DajUgao(3);
double prviprim=t2.DajUgao(1);
double drugiprim=t2.DajUgao(2);
double treciprim=t2.DajUgao(3); 

vector<pair<double, Tacka>> vek, vek2;
vek.push_back(make_pair(prvi, t1.DajTjeme(1)));
vek.push_back(make_pair(drugi, t1.DajTjeme(2)));
vek.push_back(make_pair(treci, t1.DajTjeme(3)));
sort(vek.begin(), vek.end(), [](pair<double, Tacka> x, pair<double, Tacka> y){
    return x.first<y.first;
});

vek2.push_back(make_pair(prviprim, t2.DajTjeme(1)));
vek2.push_back(make_pair(drugiprim, t2.DajTjeme(2)));
vek2.push_back(make_pair(treciprim, t2.DajTjeme(3)));
sort(vek2.begin(), vek2.end(), [](pair<double, Tacka> x, pair<double, Tacka> y){
    return x.first<y.first;
});

return t1.Orijentacija(vek[0].second, vek[1].second, vek[2].second)==t2.Orijentacija(vek2[0].second, vek2[1].second, vek2[2].second);
}


bool ImajuLiDvaJednakaUgla(const Trougao &t1,const Trougao &t2)const{
    if ((t1.DajUgao(1)==t2.DajUgao(1) && (t1.DajUgao(2)==t2.DajUgao(2) || t1.DajUgao(2)==t2.DajUgao(3)))
    || (t1.DajUgao(1)==t2.DajUgao(2) && (t1.DajUgao(2)==t2.DajUgao(1) || t1.DajUgao(2)==t2.DajUgao(3)))
    || (t1.DajUgao(1)==t2.DajUgao(3) && (t1.DajUgao(2)==t2.DajUgao(1) || t1.DajUgao(2)==t2.DajUgao(3)) ))return 1;
    return 0;
}
};

double UdaljenostIzmedju2Tackee( Tacka &t1,  Tacka &t2){
        return sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    }


int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    cin>>n;
    try{
    vector<shared_ptr<Trougao>> vek;
    double a0, a1, b0, b1, c0, c1;
    shared_ptr<Trougao> pok;
    for(int i=0; i<n; i++){
        cout<<"Unesite podatke za "<<i+1<<" trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>a0>>a1>>b0>>b1>>c0>>c1;
        
        Tacka prva, druga, treca;
        prva.first=a0; prva.second=a1;
        druga.first=b0; druga.second=b1;
        treca.first=c0; treca.second=c1;
        //Trougao novi(prva, druga, treca);
        try{Trougao novi(prva, druga, treca);
          
        
        pok=make_shared<Trougao>(novi);
        vek.push_back(pok);
        
        }
        catch(...){
            cout<<"Nekorektne pozicije tjemena, ponovite unos!\n"; i--; 
        }
   
       
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double dx, dy;
    cin>>dx>> dy;
    
    cout<<"Unesite ugao rotacije: ";
    double ugao;
    cin>>ugao;
    
    cout<<"Unesite faktor skaliranja: ";
    double faktor;
    cin>>faktor;
    

    transform(vek.begin(), vek.end(), vek.begin(), [dx, dy, ugao, faktor](shared_ptr<Trougao>&a){
        a->Transliraj(dx, dy);
      //  a->Rotiraj(ugao);
    //    a->Skaliraj(faktor);
        return a;
    }
    );
    /*
      cout<<"\n\nprije rotacije\n";
     for_each(vek.begin(), vek.end(), []( shared_ptr<Trougao> &a){
        a->Ispisi();
        cout<<endl;
    });*/
    
     transform(vek.begin(), vek.end(), vek.begin(), [dx, dy, ugao, faktor](shared_ptr<Trougao>&a){
        a->Rotiraj(ugao);
        return a;
         
     });      
     /*
          cout<<"\n\nprije translacije\n";
     for_each(vek.begin(), vek.end(), []( shared_ptr<Trougao> &a){
        a->Ispisi();
        cout<<endl;
    }); 
    */
    transform(vek.begin(), vek.end(), vek.begin(), [dx, dy, ugao, faktor](shared_ptr<Trougao>&a){
        a->Skaliraj(a->DajPrvu(), faktor); 
        return a;}
    );
    /*
    cout<<"\n\nprije sort\n";
     for_each(vek.begin(), vek.end(), []( shared_ptr<Trougao> &a){
        a->Ispisi();
        cout<<endl;
    });*/
    sort(vek.begin(), vek.end(), [](shared_ptr<Trougao> a, shared_ptr<Trougao> b){
        return a->DajPovrsinu()<b->DajPovrsinu();
        
        
    });
    
    cout<<"\nTrouglovi nakon obavljenih transformacija: \n";
    for_each(vek.begin(), vek.end(), []( shared_ptr<Trougao> &a){
        a->Ispisi();
        cout<<endl;
    });
    
    vector<shared_ptr<Trougao>> temp=vek, novi;
    auto poki=min_element(vek.begin(), vek.end(), [](const shared_ptr<Trougao> &a, const shared_ptr<Trougao> &b){
        if(a->DajObim()<b->DajObim()) return true;
        return false;
    });
    shared_ptr<Trougao> pokili=vek[0];
    for(int i=0; i<vek.size(); i++){
        if(vek[i]->DajObim()<pokili->DajObim()) 
        pokili=vek[i];
    }
    cout<<"Trougao sa najmanjim obimom: ";
    pokili->Ispisi();
    //pokii->Ispisi();
    
    vek=temp;
    cout<<"\nParovi identicnih trouglova: \n";
    vector<shared_ptr<Trougao>> novi2;
    for(int i=0; i<vek.size(); i++){
        for(int j=i+1; j<vek.size(); j++){
            if(DaLiSuIdenticni(*vek[i], *vek[j])) {
                novi.push_back(vek[i]);
                novi2.push_back(vek[j]);
        }
    }}
    
    for(int i=0; i<novi.size(); i++) {novi[i]->Ispisi(); cout<<" i "; novi2[i]->Ispisi();if(i!=novi.size()-1) cout<<endl;}

    vek=temp;
    novi.resize(0);
    novi2.resize(0);
    cout<<"\nParovi podudarnih trouglova: \n";
      for(int i=0; i<vek.size(); i++){
        for(int j=i+1; j<vek.size(); j++){
            if(DaLiSuPodudarni(*vek[i], *vek[j])) {
                novi.push_back(vek[i]);
                novi2.push_back(vek[j]);
        }
    }}
    
    for(int i=0; i<novi.size(); i++) {
        novi[i]->Ispisi(); cout<<" i "; novi2[i]->Ispisi(); cout<<endl;}
 
    vek=temp;
    cout<<"\nParovi slicnih trouglova: \n";
     vek=temp;
    novi.resize(0);
    
      for(int i=0; i<vek.size(); i++){
        for(int j=i+1; j<vek.size(); j++){
            if(DaLiSuSlicni(*vek[i], *vek[j])) novi.push_back(vek[i]);
        }
    }
    
    for(int i=0; i<novi.size(); i++) {novi[i]->Ispisi(); cout<<endl;}

    
    }
    catch(...){
        cout<<"greska";
    }
    
  //:( Ich bin ziemlich traurig... It s not the point to know math for programming, it s not a part of tp.
  
  // we are losing our time on searching some teorems... we should concentrate on implementation of this 'gradivo'...
    
	return 0;
}