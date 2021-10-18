/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <utility>
#define eps 10^-10
using namespace std;
typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka T1,T2,T3;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3); //napisano
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3); //napisano
    void Postavi (int indeks, const Tacka &t); //napisano
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3); //napisano
    Tacka DajTjeme(int indeks) const; //napisano
    double DajStranicu(int indeks) const; //napisano
    double DajUgao (int indeks) const; //napisano
    Tacka DajCentar () const; //napisano
    double DajObim () const; //napisano
    double DajPovrsinu () const; //napisano
    bool DaLiJePozitivnoOrijentiran () const;//napisano
    bool DaLiJeUnutra (const Tacka &t) const;//napisano
    void Ispisi () const;//napisano
    void Transliraj (double delta_x, double delta_y);//napisano
    void Centriraj (const Tacka &t);//napisano
    void Rotiraj (const Tacka &t, double ugao);//napisano
    void Skaliraj (const Tacka &t, double faktor);//napisano
    void Rotiraj (double ugao);//napisano
    void Skaliraj (double faktor);//napisano
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    T1=std::make_pair(t1.first,t1.second);
    T2=std::make_pair(t2.first,t2.second);
    T3=std::make_pair(t3.first,t3.second);
    }
    
    
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    T1=std::make_pair(t1.first,t1.second);
    T2=std::make_pair(t2.first,t2.second);
    T3=std::make_pair(t3.first,t3.second);
}


void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks!=1 || indeks!=2 || indeks!=3) throw std::range_error ("Nekorektan indeks");    
    if (indeks==1) T1=std::make_pair(t.first,t.second);
    if (indeks==2) T2=std::make_pair(t.first,t.second);
    if (indeks==3) T3=std::make_pair(t.first,t.second);
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double p=t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second);
    if (p<0) return -1;
    else if (p>0) return 1;
    else return 0;
}

Tacka Trougao::DajTjeme (int indeks) const {
    if(indeks==1) return T1;
    if(indeks==2) return T2;
    if(indeks==3) return T3;
    throw std::range_error ("Nekorektan indeks");
}

double Trougao::DajStranicu (int indeks) const {
    if (indeks==1) { 
        return (std::sqrt ( (T3.first-T2.first)*(T3.first-T2.first)+(T3.second-T2.second)*(T3.second-T2.second)) );
    }
    if (indeks==2) { 
        return (std::sqrt ( (T1.first-T3.first)*(T1.first-T3.first)+(T1.second-T3.second)*(T1.second-T3.second)) );
    }
    if (indeks==3) { 
        return (std::sqrt ( (T2.first-T1.first)*(T2.first-T1.first)+(T2.second-T1.second)*(T2.second-T1.second)) );
    }
    throw std::range_error("Nekorektan indeks");
}

double Trougao::DajObim () const {
    return (DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
}

double Trougao::DajPovrsinu () const {
    double S=(DajStranicu(1)+DajStranicu(2)+DajStranicu(3))/2;
    return (std::sqrt (S* (S-DajStranicu(1)) * (S-DajStranicu(2)) * (S-DajStranicu(3)) ) );
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if (Orijentacija(T1,T2,T3)==1) return true;
    else return false;
}


double Trougao::DajUgao (int indeks) const {
    if(indeks==1) return (acos ( (DajStranicu(2)*DajStranicu(2) + DajStranicu(3)*DajStranicu(3) - DajStranicu(1)*DajStranicu(1)) / (2*DajStranicu(2)*DajStranicu(3)) ) );
    if(indeks==2) return (acos ( (DajStranicu(1)*DajStranicu(1) + DajStranicu(3)*DajStranicu(3) - DajStranicu(2)*DajStranicu(2)) / (2*DajStranicu(1)*DajStranicu(3)) ) );
    if(indeks==3) return (acos ( (DajStranicu(1)*DajStranicu(1) + DajStranicu(2)*DajStranicu(2) - DajStranicu(3)*DajStranicu(3)) / (2*DajStranicu(1)*DajStranicu(2)) ) );
    throw std::range_error("Nekorektan indeks");
}

Tacka Trougao::DajCentar() const {
    Tacka T4 =std::make_pair((T1.first+T2.first+T3.first)/3,(T1.second+T2.second+T3.second)/3);
    return T4;
}


bool Trougao::DaLiJeUnutra (const Tacka &t) const {
    if( ( Orijentacija(T1,T2,T3)*Orijentacija(T1,T2,t)*Orijentacija(T2,T3,t)*Orijentacija(T3,T1,t) ) >0) return true;
    else return false;
}

void Trougao::Ispisi() const {
    cout << "( (" << T1.first << "," << T1.second << ") , (" << T2.first << "," << T2.second << ") , (" << T3.first << "," << T3.second << ") )";
}

void Trougao::Transliraj (double delta_x, double delta_y) {
    T1=std::make_pair(T1.first+delta_x,T1.second+delta_y);
    T2=std::make_pair(T2.first+delta_x,T2.second+delta_y);
    T3=std::make_pair(T3.first+delta_x,T3.second+delta_y);
}

void Trougao::Centriraj (const Tacka &t) {
    double Dx, Dy;
    Dx=t.first-DajCentar().first;
    Dy=t.second-DajCentar().second;
    Transliraj(Dx,Dy);
}

void Trougao::Rotiraj (const Tacka &t, double ugao) {
    T1=std::make_pair( (t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao)) , (t.second+(T1.first-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao)) );
    T2=std::make_pair( (t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao)) , (t.second+(T2.first-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao)) );
    T3=std::make_pair( (t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao)) , (t.second+(T3.first-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao)) );
}

void Trougao::Rotiraj (double ugao) {
    Tacka tez=DajCentar();
    T1=std::make_pair( (tez.first+(T1.first-tez.first)*cos(ugao)-(T1.second-tez.second)*sin(ugao)) , (tez.second+(T1.first-tez.first)*sin(ugao)+(T1.second-tez.second)*cos(ugao)) );
    T2=std::make_pair( (tez.first+(T2.first-tez.first)*cos(ugao)-(T2.second-tez.second)*sin(ugao)) , (tez.second+(T2.first-tez.first)*sin(ugao)+(T2.second-tez.second)*cos(ugao)) );
    T3=std::make_pair( (tez.first+(T3.first-tez.first)*cos(ugao)-(T3.second-tez.second)*sin(ugao)) , (tez.second+(T3.first-tez.first)*sin(ugao)+(T3.second-tez.second)*cos(ugao)) );
}

void Trougao::Skaliraj (const Tacka &t, double faktor) {
    if (faktor!=0.) {
    T1=std::make_pair(t.first+faktor*(T1.first-t.first), t.second+faktor*(T1.second-t.second));
    T2=std::make_pair(t.first+faktor*(T2.first-t.first), t.second+faktor*(T2.second-t.second));
    T3=std::make_pair(t.first+faktor*(T3.first-t.first), t.second+faktor*(T3.second-t.second));
    }
    else throw domain_error ("Nekorektan faktor skaliranja");
}

void Trougao::Skaliraj (double faktor) {
    if (faktor!=0.) {
    Tacka tez=DajCentar();
    T1=std::make_pair( tez.first+faktor*(T1.first-tez.first), tez.second+faktor*(T1.second-tez.second));
    T2=std::make_pair( tez.first+faktor*(T2.first-tez.first), tez.second+faktor*(T2.second-tez.second));
    T3=std::make_pair( tez.first+faktor*(T3.first-tez.first), tez.second+faktor*(T3.second-tez.second));
    }
    else throw domain_error ("Nekorektan faktor skaliranja");
}

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2) {
 
    Tacka A1,A2,B1,B2,C1,C2; 
    A1=t1.DajTjeme(1);
    B1=t1.DajTjeme(2);
    C1=t1.DajTjeme(3);
    A2=t2.DajTjeme(1);
    B2=t2.DajTjeme(2);
    C2=t2.DajTjeme(3);
    
    if (A1==A2) {
        if ((B1==B2)&&(C1==C2)) return true;
        if ((C1==B2)&&(B1==C2)) return true;
        else return false;
    }
    if (A1==B2) {
        if ((B1==C2)&&(C1==A2)) return true;
        if ((C1==A2)&&(B1==C2)) return true;
        else return false;
    }
    if (A1==C2) {
        if ((B1==A2)&&(C1==B2)) return true;
        if ((C1==A2)&&(B1==B2)) return true;
        else return false;
    }
    else return false;
    
}


int main () {
    Tacka t1, t2, t3,t;
    double x1,y1,x2,y2,x3,y3;
    try {
    cout << "Unos 3 koordinate trougla : ";
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cin.ignore(10000,'\n');
    t1 =std::make_pair(x1,y1);
    t2 =std::make_pair(x2,y2);
    t3 =std::make_pair(x3,y3);
    Trougao trog1(t1,t2,t3);
	trog1.Postavi(t1,t2,t3);
    cout<<t1.first<<" "<<t1.second<<" "<<trog1.DajStranicu(2)<<" "<<trog1.DajPovrsinu();
    cout<<"\n"<<trog1.DajObim()<<" "<<trog1.Orijentacija(t1,t2,t3);
    cout<<"\nUnesi tekucu tacku: ";
    double x,y;
    cin >> x >> y;
    t=std::make_pair(x,y);
    cout<<trog1.DaLiJeUnutra(t)<<endl;
    trog1.Transliraj(2,2);
    trog1.Ispisi();
    trog1.Centriraj(std::make_pair(2,7));
    trog1.Ispisi();
    //trog1.Rotiraj(std::make_pair(0,0), atan(1)*4);
    //trog1.Ispisi();
    //trog1.Rotiraj(atan(1)*4);
    //trog1.Ispisi();
    double a;
    cout << "Unesi a:";
    cin >> a;
    trog1.Skaliraj(a);
    trog1.Ispisi();
    /*
    Trougao trogtest1(make_pair(4,0),make_pair(0,0),make_pair(0,3));
    Trougao trogtest2(make_pair(5,0),make_pair(0,3),make_pair(4,0));
    cout<<DaLiSuIdenticni(trogtest1,trogtest2);*/
    
    } catch(std::range_error izuzetak) {
        cout << izuzetak.what();
    } catch(std::domain_error e) {
        cout << e.what();
    }
	return 0;
}