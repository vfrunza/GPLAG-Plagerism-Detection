/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector> 
#include <memory>

typedef std::pair <double, double> Tacka;

class Trougao {
    Tacka A, B, C;
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        A.first=t1.first; A.second=t1.second; 
        B.first=t2.first; B.second=t2.second;
        C.first=t3.first; C.second=t3.second;
    }
    
void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {A=t1; B=t2; C=t3;}

void Postavi (int indeks, const Tacka &t) {
    if (indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    if (indeks==1) A=t;
    else if (indeks==2) B=t;
    else if (indeks==3) C=t;
}

static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double smjer;
    smjer=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    if (smjer>0) return 1;
    else if (smjer<0) return -1;
    return 0;
}

Tacka DajTjeme (int indeks) const {
    if (indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    if (indeks==1) return A;
    else if (indeks==2) return B;
    return C;
}

double DajStranicu (int indeks) const {
    if (indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    double strA=sqrt((A.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second));
    double strB=sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
    double strC=sqrt((A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second));
    if (indeks==1) return strA;
    else if (indeks==2) return strB;
    return strC;
}

double DajUgao (int indeks) const {
    if (indeks<1 || indeks>3) throw std::range_error ("Nekorektan indeks");
    double strA=sqrt((B.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second));
    double strB=sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
    double strC=sqrt((A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second));
    if (indeks==1) return (strA*strA-strB*strB-strC*strC)/(-2*strB*strC);
    else if (indeks==2) return (strB*strB-strA*strA-strC*strC)/(-2*strA*strC);
    return (strC*strC-strA*strA-strB*strB)/(-2*strA*strB);
}

Tacka DajCentar () const {
    Tacka centar;
    centar.first=(A.first+B.first+C.first)/3.;
    centar.second=(A.second+B.second+C.second)/3.;
    return centar;
}

double DajObim () const {
    double strA=sqrt((B.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second));
    double strB=sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
    double strC=sqrt((A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second));
    return strC+strB+strA;
}

double DajPovrsinu() const { return abs(A.first*(B.second-C.second)-B.first*(A.second-C.second)+C.first*(A.second-B.second))/2.;}

bool DaLiJePozitivnoOrijentiran () {
    if (Orijentacija(A, B, C)==1) return true;
    return false;
}

bool DaLiJeUnutra (const Tacka &t) {
    if (Orijentacija(A, B, C) == 1 && Orijentacija(A, B, t) == 1 && Orijentacija(A, C, t) == 1 && Orijentacija(B, C, t) == 1 ) return true;
    return false;
}

void Ispisi () { std::cout << "( (" << A.first << "," << A.second << ") , ("  << B.first << "," << B.second << ") , (" << C.first << "," << C.second << ") )";}

void Transliraj (double delta_x, double delta_y){
    A.first=A.first+delta_x; A.second=A.second+delta_y;
    B.first=B.first+delta_x; B.second=B.second+delta_y;
    C.first=C.first+delta_x; C.second=C.second+delta_y;
}

void Centriraj (const Tacka &t){
    double x=t.first*3./(A.first+B.first+C.first);
    double y=t.second*3./(A.second+B.second+C.second);
    A.first=A.first+x; A.second=A.second+y;
    B.first=B.first+x; B.second=B.second+y;
    C.first=C.first+x; C.second=C.second+y;
}

void Rotiraj (const Tacka &t, double ugao){
    A.first=(t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao));
    A.second=t.second+(A.first-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao);
    B.first=t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao);
    B.second=t.second+(B.first-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao);
    C.first=t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao);
    C.second=t.second+(C.first-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao);
}

void Skaliraj (const Tacka &t, double faktor){
    if (faktor==0) throw std::range_error ("Nekorektan faktor skaliranja");
    A.first=t.first+faktor*(A.first-t.first); A.second=t.second+faktor*(A.second-t.second);
    B.first=t.first+faktor*(B.first-t.first); B.second=t.second+faktor*(B.second-t.second);
    C.first=t.first+faktor*(C.first-t.first); C.second=t.second+faktor*(C.second-t.second);
}

void Rotiraj(double ugao){
    Tacka t;
    t.first=(A.first+B.first+C.first)/3.;
    t.second=(A.second+B.second+C.second)/3.;
    A.first=t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao);
    A.second=t.second+(A.first-t.first)*sin(ugao)-(A.second-t.second)*cos(ugao);
    B.first=t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao);
    B.second=t.second+(B.first-t.first)*sin(ugao)-(B.second-t.second)*cos(ugao);
    C.first=t.first+(C.first-t.first)*cos(ugao)- (C.second-t.second)*sin(ugao);
    C.second=t.second+(C.first-t.first)*sin(ugao)-(C.second-t.second)*cos(ugao);
}

void Skaliraj(double faktor){
    if (faktor==0) throw std::range_error ("Nekorektan faktor skaliranja");
    Tacka t;
    t.first=(A.first+B.first+C.first)/3.;
    t.second=(A.second+B.second+C.second)/3.;
    A.first=t.first+faktor*(A.first-t.first); A.second=t.second+faktor*(A.second-t.second);
    B.first=t.first+faktor*(B.first-t.first); B.second=t.second+faktor*(B.second-t.second);
    C.first=t.first+faktor*(C.first-t.first); C.second=t.second+faktor*(C.second-t.second);
}

friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);

};

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2){
    std::vector<Tacka> trougao1, trougao2;
    int brojac=0;
    trougao1[0].first=t1.A.first; trougao1[0].second=t1.A.second;
    trougao1[1].first=t1.B.first; trougao1[1].second=t1.B.second;
    trougao1[2].first=t1.C.first; trougao1[2].second=t1.C.second;
    trougao2[0].first=t2.A.first; trougao2[0].second=t2.A.second;
    trougao2[1].first=t2.B.first; trougao2[1].second=t2.B.second;
    trougao2[2].first=t2.C.first; trougao2[2].second=t2.C.second;
    
    for (int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if (trougao1[i]==trougao2[j]) brojac++;
        }
        if (brojac==0) return false;
    }
    if (brojac==3) return true;
    return false;
}



int main ()
{
    std::vector <std::shared_ptr<Trougao>>v;
    int n;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    v.resize(n);
    std::vector<Tacka> tjemena;
    tjemena.resize(3);
    for(int i=0; i<n; i++){
        std::cout<<"Unesite " << i+1 <<". trougao: "<<std::endl;
    for (int j=0; j<3; j++){
        double x, y;
        std::cout << "Unesite koordinate " << j+1 <<". tjemena: "<<std::endl;
        std::cin >> x >> y;
        if (x<0 || y<0){
            std::cout<<"Pogresne koordinate"<<std::endl;
            j--;
            continue;
        }
        tjemena[j].first=x;
        tjemena[j].second=y;
    }
    v[i]=std::make_shared <Trougao> (tjemena[0], tjemena[1], tjemena[2]);
    v[i]->Postavi(tjemena[0], tjemena[1], tjemena[2]);
    }
    for (int i=0; i<n; i++){
        double delta_x, delta_y;
        std::cout << "Unesite delta x";
        std::cin >> delta_x;
        std::cout << "Unesit delta y";
        std::cin >> delta_y;
         v[i]->Transliraj(delta_x, delta_y);
    }
    for (int i=0; i<n; i++){
        double ugao;
        std::cout<<"Unesite ugao rotacije: ";
        std::cin>>ugao;
        v[i]->Rotiraj(v[i]->DajCentar(), ugao);
    }
    for (int i=0; i<n; i++){
        double faktor;
        std::cout<<"Unesite faktor skaliranja: ";
        std::cin>>faktor;
        v[i]->Skaliraj(v[i]->DajTjeme(1), faktor);
    }
    
    
    std::cout << "hehe";
	return 0;
}