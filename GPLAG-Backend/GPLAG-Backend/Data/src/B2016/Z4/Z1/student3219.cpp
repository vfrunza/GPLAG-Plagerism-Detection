/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
#define pi 3.14159
#define eps 1E-10

typedef std::pair<double, double> Tacka;

using namespace std;

class Trougao {
    Tacka A,B,C;
    static bool Isti(double a, double b) { if (fabs(a-b)<=eps*(fabs(a)+fabs(b))) return true; return false; };
    static double UbivenaPomocna(const Tacka &t1, const Tacka &t2, const Tacka &t3) { return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second); };
    public:
    
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) ;
    void Postavi(int indeks,const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) { double orijentacija=UbivenaPomocna(t1,t2,t3); if(orijentacija>0) return 1; else if(orijentacija<0) return -1; else return 0; };
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrjentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x,double delta_y);
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
    if(Trougao::Orijentacija(t1,t2,t3)==0) throw domain_error ("Nekorektne pozicije tjemena");
    else {
        A.first=t1.first; A.second=t1.second;
        B.first=t2.first; B.second=t2.second;
        C.first=t3.first; C.second=t3.second;
    }
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Trougao::Orijentacija(t1,t2,t3)==0) throw domain_error ("Nekorektne pozicije tjemena");
    else {
        A.first=t1.first; A.second=t1.second;
        B.first=t2.first; B.second=t2.second;
        C.first=t3.first; C.second=t3.second;
    }
}
void Trougao::Postavi(int indeks,const Tacka &t) {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error ("Nekorektan indeks");
    switch( indeks ) {
        case 1:
             A.first=t.first; A.second=t.second;
             break;
        case 2:
             B.first=t.first; B.second=t.second;
             break;
        case 3:
             C.first=t.first; C.second=t.second;
             break;
    }
    if(Trougao::Orijentacija(A,B,C)==0) throw domain_error ("Nekorektne pozicije tjemena");
}
Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error ("Nekorektan indeks");
    switch( indeks ) {
        case 1:
             return A;
        case 2:
             return B;
        case 3:
             return C;
    }
    return A;
}

double Trougao::DajStranicu(int indeks) const {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error ("Nekorektan indeks");
    switch( indeks ) {
        case 1:
             return sqrt((B.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second));
        case 2:
             return sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
        case 3:
             return sqrt((B.first-A.first)*(B.first-A.first)+(B.second-A.second)*(B.second-A.second));
    }
    return 0;
}

double Trougao::DajUgao(int indeks) const {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error ("Nekorektan indeks");
    double a,b,c;
    a=Trougao::DajStranicu(1);
    b=Trougao::DajStranicu(2);
    c=Trougao::DajStranicu(3);
    switch( indeks ) {
        case 1:
            return ((acos((b*b+c*c-a*a)/(2*b*c)))*180/pi);
        case 2:
            return ((acos((a*a+c*c-b*b)/(2*a*c)))*180/pi);
        case 3:
            return ((acos((b*b+a*a-c*c)/(2*b*a)))*180/pi);
    }
    return 0;
}

Tacka Trougao::DajCentar() const {
    Tacka centar;
    centar.first=(A.first+B.first+C.first)/3;
    centar.second=(A.second+B.second+C.second)/3;
    return centar;
}

double Trougao::DajObim() const {
    return Trougao::DajStranicu(1)+Trougao::DajStranicu(2)+Trougao::DajStranicu(3);
}

double Trougao::DajPovrsinu() const {
    return fabs(UbivenaPomocna(A,B,C))/2;
}

bool Trougao::DaLiJePozitivnoOrjentiran() const {
    if(Trougao::Orijentacija(A,B,C)==1) return true;
    else return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if(Trougao::Orijentacija(A,B,C)==1) {
        if(Trougao::Orijentacija(A,B,t)==1 && Trougao::Orijentacija(B,C,t)==1 && Trougao::Orijentacija(C,A,t)==1) return true;
    }
    else if(Trougao::Orijentacija(A,B,C)==-1) {
        if(Trougao::Orijentacija(A,B,t)==-1 && Trougao::Orijentacija(B,C,t)==-1 && Trougao::Orijentacija(C,A,t)==-1) return false;
    }
    return false;
}

void Trougao::Ispisi() const {
    cout<<"(("<<A.first<<","<<A.second<<"),("<<B.first<<","<<B.second<<"),("<<C.first<<","<<C.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y) {
    A.first+=delta_x; A.second+=delta_y;
    B.first+=delta_x; B.second+=delta_y;
    C.first+=delta_x; C.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t) {
    Trougao::Transliraj(Trougao::DajCentar().first-t.first,Trougao::DajCentar().second-t.second);
}

void Trougao::Rotiraj(const Tacka &t, double ugao) {
    Tacka pom;
    pom.first=t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao);
    
    pom.second=t.second+(A.first-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao);
    
    A.first=pom.first; A.second=pom.second;
    
    pom.first=t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao);
    pom.second=t.second+(B.first-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao);
    B.first=pom.first; B.second=pom.second;
    pom.first=t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao);
    pom.second=t.second+(C.first-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao);
    C.first=pom.first; C.second=pom.second;
}

void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(Isti(faktor,0)) throw domain_error ("Nekorektan faktor skaliranja");
    A.first=t.first+faktor*(A.first-t.first);
    A.second=t.second+faktor*(A.second-t.second);
    B.first=t.first+faktor*(B.first-t.first);
    B.second=t.second+faktor*(B.second-t.second);
    C.first=t.first+faktor*(C.first-t.first);
    C.second=t.second+faktor*(C.second-t.second);

}

void Trougao::Rotiraj(double ugao) {
    Tacka centar=Trougao::DajCentar();
    Trougao::Rotiraj(centar,ugao);
}

void Trougao::Skaliraj(double faktor) {
    Tacka centar=Trougao::DajCentar(); 
    Trougao::Skaliraj(centar,faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    bool prva=false,druga=false,treca=false;
    if((Trougao::Isti(t1.A.first,t2.A.first) && Trougao::Isti(t1.A.second,t2.A.second)) || ((Trougao::Isti(t1.A.first,t2.B.first)) && (Trougao::Isti(t1.A.second,t2.B.second))) || 
    (Trougao::Isti(t1.A.first,t2.C.first) && Trougao::Isti(t1.A.second,t2.C.second))) prva=true;
    
    if((Trougao::Isti(t1.B.first,t2.A.first) && Trougao::Isti(t1.B.second,t2.A.second)) || ((Trougao::Isti(t1.B.first,t2.B.first)) && (Trougao::Isti(t1.B.second,t2.B.second))) || 
    (Trougao::Isti(t1.B.first,t2.C.first) && Trougao::Isti(t1.B.second,t2.C.second))) druga=true;
    
    if((Trougao::Isti(t1.C.first,t2.A.first) && Trougao::Isti(t1.C.second,t2.A.second)) || ((Trougao::Isti(t1.C.first,t2.B.first)) && (Trougao::Isti(t1.C.second,t2.B.second))) || 
    (Trougao::Isti(t1.C.first,t2.C.first) && Trougao::Isti(t1.C.second,t2.C.second))) treca=true;
    
    if(prva==true && druga==true && treca==true) return true;
    else return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    double alfa1=t1.DajUgao(1), beta1=t1.DajUgao(2), gama1=t1.DajUgao(3), alfa2=t2.DajUgao(1), beta2=t2.DajUgao(2), gama2=t2.DajUgao(3);
    int n=Trougao::Orijentacija(t1.A,t1.B,t1.C), n1=Trougao::Orijentacija(t2.A,t2.B,t2.C);
    if(n==n1) {
        if((Trougao::Isti(alfa1,alfa2) && Trougao::Isti(beta1,beta2)) || (Trougao::Isti(alfa1,gama2) && Trougao::Isti(beta1,alfa2)) || (Trougao::Isti(alfa1,beta2) && Trougao::Isti(beta1,gama2))) return true;
    }
    if(n!=n1) {
        if((Trougao::Isti(alfa1,alfa2) && Trougao::Isti(beta1,gama2)) || (Trougao::Isti(gama1,gama2) && Trougao::Isti(alfa1,beta2)) || (Trougao::Isti(beta1,beta2) && Trougao::Isti(alfa1,gama2))) return true;
    }
    return false;
    
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    double alfa1=t1.DajUgao(1), beta1=t1.DajUgao(2), gama1=t1.DajUgao(3), alfa2=t2.DajUgao(1), beta2=t2.DajUgao(2), gama2=t2.DajUgao(3);
    double P1=t1.DajPovrsinu(), P2=t2.DajPovrsinu();
    int n=Trougao::Orijentacija(t1.A,t1.B,t1.C), n1=Trougao::Orijentacija(t2.A,t2.B,t2.C);
     if(n==n1) {
        if(((Trougao::Isti(alfa1,alfa2) && Trougao::Isti(beta1,beta2)) || (Trougao::Isti(alfa1,gama2) && Trougao::Isti(beta1,alfa2)) || (Trougao::Isti(alfa1,beta2) && Trougao::Isti(beta1,gama2))) &&
        Trougao::Isti(P1,P2)) return true;
     }
     if(n!=n1) {
        if(((Trougao::Isti(alfa1,alfa2) && Trougao::Isti(beta1,gama2)) || (Trougao::Isti(gama1,gama2) && Trougao::Isti(alfa1,beta2)) || (Trougao::Isti(beta1,beta2) && Trougao::Isti(alfa1,gama2))) && 
        Trougao::Isti(P1,P2)) return true;
     }
    return false;
}

int main ()
{
    cout << "Koliko zelite kreirati trouglova: ";
    int n; cin>>n;
    vector<shared_ptr<Trougao> > vektor(n, nullptr);
    int i(0);
    while(i<n) {
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        int x,y,x1,y1,x2,y2; cin>>x>>y>>x1>>y1>>x2>>y2;
        Tacka A=make_pair(x,y);
        Tacka B=make_pair(x1,y1);
        Tacka C=make_pair(x2,y2);
        try {
            vektor[i]=make_shared<Trougao> (A,B,C);
        }catch(domain_error e) { cout<<e.what()<<", ponovite unos!"<<endl; i--; }
        i++;
    }
    
    cout<< "Unesite vektor translacije (dx dy): ";
    double dx,dy;
    cin>>dx>>dy;
    
    transform(vektor.begin(), vektor.end(), vektor.begin(), [dx,dy] (shared_ptr<Trougao> trougao) {trougao->Transliraj(dx,dy); return trougao;});

    cout<< "Unesite ugao rotacije: ";
    double fi;
    cin>>fi;
    
    transform(vektor.begin(),vektor.end(),vektor.begin(), [fi](shared_ptr<Trougao> trougao) {trougao->Rotiraj(trougao->DajCentar(),fi); return trougao;});

    cout<< "Unesite faktor skaliranja: ";
    double faktor;
    cin>>faktor;
    try{
        transform(vektor.begin(), vektor.end(), vektor.begin(), [faktor] (shared_ptr<Trougao> trougao) {trougao->Skaliraj(trougao->DajTjeme(1),faktor); return trougao;});
    }catch(domain_error e) { cout<<e.what(); }

    cout<< "Trouglovi nakon obavljenih transformacija:\n";
    
    sort(vektor.begin(), vektor.end(), [](shared_ptr<Trougao> trougao, shared_ptr<Trougao> trougao1) {return trougao->DajPovrsinu()<trougao1->DajPovrsinu();});
    
    for_each(vektor.begin(), vektor.end(), [] (shared_ptr<Trougao> trougao) {trougao->Ispisi(); cout<<endl;});
    
    auto najmanji = *min_element(vektor.begin(), vektor.end(), [](shared_ptr<Trougao> tr, shared_ptr<Trougao> tr1) {return tr->DajObim()<tr1->DajObim();});
    
    cout<< "Trougao sa najmanjim obimom: "; najmanji->Ispisi(); cout<<endl;
    
    vector<pair<Trougao, Trougao> > Identicni;
    bool ima=false;
    for(int j(0);j<vektor.size()-1;j++) {
        for(int k=j+1;k<vektor.size();k++) {
            if(DaLiSuIdenticni(*vektor[j], *vektor[k])) {
                Identicni.push_back(make_pair(*vektor[j], *vektor[k]));
                ima=true;
            }
        }
    }
    if(!ima) cout<< "Nema identicnih trouglova!\n";
    else {
        ima=false;
        cout<< "Parovi identicnih trouglova:"<<endl;
        for_each(Identicni.begin(), Identicni.end(), [](pair<Trougao, Trougao> par) {par.first.Ispisi(); cout<<" i "; par.second.Ispisi(); cout<<endl;});
    }
    
    vector<pair<Trougao, Trougao> > Podudarni;
     for(int j(0);j<vektor.size()-1;j++) {
        for(int k=j+1;k<vektor.size();k++) {
            if(DaLiSuPodudarni(*vektor[j], *vektor[k])) {
                Podudarni.push_back(make_pair(*vektor[j], *vektor[k]));
                ima = true;
            }
        }
    }
    if(!ima) cout<< "Nema podudarnih trouglova!\n";
    else {
        ima=false;
         cout<< "Parovi podudarnih trouglova:"<<endl;
         for_each(Podudarni.begin(), Podudarni.end(), [](pair<Trougao, Trougao> par) {par.first.Ispisi(); cout<<" i "; par.second.Ispisi(); cout<<endl;});
    }
    
    vector<pair<Trougao, Trougao> > Slicni;
    for(int j(0);j<vektor.size()-1;j++) {
        for(int k=j+1;k<vektor.size();k++) {
            if(DaLiSuSlicni(*vektor[j], *vektor[k])) {
                Slicni.push_back(make_pair(*vektor[j], *vektor[k]));
                ima = true;
            }
        }
    }
    if(!ima) cout<< "Nema slicnih trouglova!\n";
    else {
        cout<<"Parovi slicnih trouglova:"<<endl;
        for_each(Slicni.begin(), Slicni.end(),[] ( pair<Trougao, Trougao> par) { par.first.Ispisi(); cout<<" i "; par.second.Ispisi(); cout<<endl; });
    }
        
    
	return 0;
}
