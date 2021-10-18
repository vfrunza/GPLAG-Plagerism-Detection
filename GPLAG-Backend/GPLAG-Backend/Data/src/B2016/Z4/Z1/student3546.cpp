#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

using std::cin;
using std::cout;

typedef std::pair<double,double> Tacka;

bool operator ==(const std::pair<double,double> &p1,const std::pair<double,double> &p2){
    if((abs(p1.first-p2.first)<0.0000000001) && (abs(p1.second-p2.second)<0.0000000001))
    return true;
    return false;
}

double Orijentacija1(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    return (t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
}

double Stranica(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    double duzina;
    duzina=std::sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
    return duzina;
}

double Ugao(const Tacka &A,const Tacka &B,const Tacka &C){
    double ugao;
    ugao=acos((Stranica(B,A,C)*Stranica(B,A,C)+Stranica(C,A,B)*Stranica(C,A,B)-Stranica(A,B,C)*Stranica(A,B,C))/(2*Stranica(B,A,C)*Stranica(C,A,B)));
    return ugao;
}

bool Jednaki(double x, double y){
    double razlika;
    razlika=std::abs(x-y);
    if (razlika<0.0000000001) return true;
    return false;
}

class Trougao{
    Tacka A,B,C;
    public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(abs(Orijentacija1(t1,t2,t3))<0.0000000001) throw std::domain_error("Nekorektne pozicije tjemena");
        A.first=t1.first; A.second=t1.second; B.first=t2.first; B.second=t2.second; C.first=t3.first; C.second=t3.second;
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(abs(Orijentacija1(t1,t2,t3))<0.0000000001) throw std::domain_error("Nekorektne pozicije tjemena");
        A.first=t1.first; A.second=t1.second; B.first=t2.first; B.second=t2.second; C.first=t3.first; C.second=t3.second;
    }
    void Postavi(int indeks,const Tacka &t){
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
        if(indeks==1) {A.first=t.first; A.second=t.second;}
        else if(indeks==2) {B.first=t.first; B.second=t.second;}
        else if(indeks==3) {C.first=t.first; C.second=t.second;}
        if(Orijentacija(A,B,C)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    }
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if (Orijentacija1(t1,t2,t3)<0) return -1;
        else if (Orijentacija1(t1,t2,t3)>0) return 1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
        if(indeks==1) return A;
        else if(indeks==2) return B;
        else if(indeks==3) return C;
    }
    double DajStranicu(int indeks) const{
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
        if(indeks==1) return Stranica(A,B,C);
        else if(indeks==2) return Stranica(B,A,C);
        else if(indeks==3) return Stranica(C,A,B);
    }
    double DajUgao(int indeks) const{
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
        if(indeks==1) return Ugao(A,B,C);
        else if(indeks==2) return Ugao(B,A,C);
        else if(indeks==3) return Ugao(C,A,B);
    }
    Tacka DajCentar() const{
        Tacka centar;
        centar.first=(A.first+B.first+C.first)/3;
        centar.second=(A.second+B.second+C.second)/3;
        return centar;
    }
    double DajObim() const{
        double obim;
        obim=Stranica(A,B,C)+Stranica(B,A,C)+Stranica(C,A,B);
        return obim;
    }
    double DajPovrsinu() const{
        double povrsina;
        povrsina=0.5*abs(Orijentacija1(A,B,C));
        return povrsina;
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija1(A,B,C)>0) return true;
        return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        if((Orijentacija1(A,B,C)>0 && Orijentacija1(A,B,t)>0 && Orijentacija(B,C,t)>0 && Orijentacija(C,B,t)>0) || (Orijentacija1(A,B,C)<0 && Orijentacija1(A,B,t)<0 && Orijentacija(B,C,t)<0 && Orijentacija(C,B,t)<0))
        return true;
        return false;
    }
    void Ispisi() const{
        cout<<"(("<<A.first<<","<<A.second<<"),("<<B.first<<","<<B.second<<"),("<<C.first<<","<<C.second<<"))";
    }
    void Transliraj(double delta_x,double delta_y){
        A.first+=delta_x; A.second+=delta_y; B.first+=delta_x; B.second+=delta_y; C.first+=delta_x; C.second+=delta_y;
    }
    void Centriraj(const Tacka &t){
        double deltax=t.first-DajCentar().first;
        double deltay=t.second-DajCentar().second;
        A.first+=deltax; A.second+=deltay; B.first+=deltax; B.second+=deltay; C.first+=deltax; C.second+=deltay;
    }
    void Rotiraj(const Tacka &t,double ugao){
        double x(A.first);
        A.first=t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao);
        A.second=t.second+(x-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao);
        double y(B.first);
        B.first=t.first+(B.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao);
        B.second=t.second+(y-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao);
        double z(C.first);
        C.first=t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao);
        C.second=t.second+(z-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao);
    }
    void Skaliraj(const Tacka &t,double faktor){
        if(abs(faktor)<0.0000000001) throw std::domain_error("Nekorektan faktor skaliranja");
        A.first=t.first+faktor*(A.first-t.first);
        A.second=t.second+faktor*(A.second-t.second);
        B.first=t.first+faktor*(B.first-t.first);
        B.second=t.second+faktor*(B.second-t.second);
        C.first=t.first+faktor*(C.first-t.first);
        C.second=t.second+faktor*(C.second-t.second);
    }
    void Rotiraj(double ugao){
        Tacka t;
        t.first=DajCentar().first;
        t.second=DajCentar().second;
        double x(A.first);
        A.first=t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao);
        A.second=t.second+(x-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao);
        double y(B.first);
        B.first=t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao);
        B.second=t.second+(y-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao);
        double z(C.first);
        C.first=t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao);
        C.second=t.second+(z-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao);
    }
    void Skaliraj(double faktor){
        if(abs(faktor)<0.0000000001) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t;
        t.first=DajCentar().first;
        t.second=DajCentar().second;
        A.first=t.first+faktor*(A.first-t.first);
        A.second=t.second+faktor*(A.second-t.second);
        B.first=t.first+faktor*(B.first-t.first);
        B.second=t.second+faktor*(B.second-t.second);
        C.first=t.first+faktor*(C.first-t.first);
        C.second=t.second+faktor*(C.second-t.second);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
    if(t1.A==t2.A && t1.B==t2.B && t1.C==t2.C) return true;
    else if(t1.A==t2.A && t1.B==t2.C && t1.C==t2.B) return true;
    else if(t1.A==t2.B && t1.B==t2.A && t1.C==t2.C) return true;
    else if(t1.A==t2.B && t1.B==t2.C && t1.C==t2.A) return true;
    else if(t1.A==t2.C && t1.B==t2.A && t1.C==t2.B) return true;
    else if(t1.A==t2.C && t1.B==t2.B && t1.C==t2.A) return true;
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
    if(Jednaki(t1.DajStranicu(1),t2.DajStranicu(1)) && Jednaki(t1.DajUgao(1),t2.DajUgao(1)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(2)) && Jednaki(t1.DajUgao(2),t2.DajUgao(2)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(3)) && Jednaki(t1.DajUgao(3),t2.DajUgao(3))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)))) return true;
    }
    if(Jednaki(t1.DajStranicu(1),t2.DajStranicu(1)) && Jednaki(t1.DajUgao(1),t2.DajUgao(1)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(3)) && Jednaki(t1.DajUgao(2),t2.DajUgao(3)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(2)) && Jednaki(t1.DajUgao(3),t2.DajUgao(2))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2)))) return true;
    }
    if(Jednaki(t1.DajStranicu(1),t2.DajStranicu(2)) && Jednaki(t1.DajUgao(1),t2.DajUgao(2)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(1)) && Jednaki(t1.DajUgao(2),t2.DajUgao(1)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(3)) && Jednaki(t1.DajUgao(3),t2.DajUgao(3))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3)))) return true;
    }
    if(Jednaki(t1.DajStranicu(1),t2.DajStranicu(2)) && Jednaki(t1.DajUgao(1),t2.DajUgao(2)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(3)) && Jednaki(t1.DajUgao(2),t2.DajUgao(3)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(1)) && Jednaki(t1.DajUgao(3),t2.DajUgao(1))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1)))) return true;
    }
    if(Jednaki(t1.DajStranicu(1),t2.DajStranicu(3)) && Jednaki(t1.DajUgao(1),t2.DajUgao(3)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(2)) && Jednaki(t1.DajUgao(2),t2.DajUgao(2)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(1)) && Jednaki(t1.DajUgao(3),t2.DajUgao(1))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1)))) return true;
    }
    if(Jednaki(t1.DajStranicu(1),t2.DajStranicu(3)) && Jednaki(t1.DajUgao(1),t2.DajUgao(3)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(1)) && Jednaki(t1.DajUgao(2),t2.DajUgao(1)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(2)) && Jednaki(t1.DajUgao(3),t2.DajUgao(2))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2)))) return true;
    }
    return false;
}

bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
    if(Jednaki(t1.DajUgao(1),t2.DajUgao(1)) && Jednaki(t1.DajUgao(2),t2.DajUgao(2)) && Jednaki(t1.DajUgao(3),t2.DajUgao(3))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)))) return true;
    }
    if(Jednaki(t1.DajUgao(1),t2.DajUgao(1)) && Jednaki(t1.DajUgao(2),t2.DajUgao(3)) && Jednaki(t1.DajUgao(3),t2.DajUgao(2))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2)))) return true;
    }
    if(Jednaki(t1.DajUgao(1),t2.DajUgao(2)) && Jednaki(t1.DajUgao(2),t2.DajUgao(1)) && Jednaki(t1.DajUgao(3),t2.DajUgao(3))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3)))) return true;
    }
    if(Jednaki(t1.DajUgao(1),t2.DajUgao(2)) && Jednaki(t1.DajUgao(2),t2.DajUgao(3)) && Jednaki(t1.DajUgao(3),t2.DajUgao(1))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1)))) return true;
    }
    if(Jednaki(t1.DajUgao(1),t2.DajUgao(3)) && Jednaki(t1.DajUgao(2),t2.DajUgao(2)) && Jednaki(t1.DajUgao(3),t2.DajUgao(1))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1)))) return true;
    }
    if(Jednaki(t1.DajUgao(1),t2.DajUgao(3)) && Jednaki(t1.DajUgao(2),t2.DajUgao(1)) && Jednaki(t1.DajUgao(3),t2.DajUgao(2))){
        if(Jednaki(Orijentacija1(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)),Orijentacija1(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2)))) return true;
    }
    return false;
}

int main ()
{
    int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i=0;i<n;i++){
        Tacka A,B,C;
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>A.first>>A.second;
        cin>>B.first>>B.second;
        cin>>C.first>>C.second;
        try{
            v[i]=std::make_shared<Trougao>(A,B,C);
        }
        catch(std::domain_error iz){
            cout<<iz.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double deltax,deltay;
    cin>>deltax>>deltay;
    cout<<"Unesite ugao rotacije: ";
    double ugao;
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    double faktor;
    cin>>faktor;
    std::transform(v.begin(),v.end(),v.begin(),[deltax,deltay,ugao,faktor](std::shared_ptr<Trougao> pnat){
        (*pnat).Transliraj(deltax,deltay);
        (*pnat).Rotiraj(ugao);
        (*pnat).Skaliraj((*pnat).DajTjeme(1),faktor);
        return pnat;
    });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
        if((*t1).DajPovrsinu()<(*t2).DajPovrsinu()) return true;
        return false;
    });
    cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> pnat){
       (*pnat).Ispisi();
       cout<<std::endl;
    });
    auto it=std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
       if((*t1).DajObim()<(*t2).DajObim()) return true;
       return false;
    });
    cout<<"Trougao sa najmanjim obimom: ";
    (**it).Ispisi();
    cout<<std::endl;
    int brojac(0);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuIdenticni(*v[i],*v[j]))
            brojac++;
        }
    }
    if(brojac==0)
    cout<<"Nema identicnih trouglova!"<<std::endl;
    else{
    cout<<"Parovi identicnih trouglova: "<<std::endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuIdenticni(*v[i],*v[j])){
            (*v[i]).Ispisi();
            cout<<" i ";
            (*v[j]).Ispisi();
            cout<<std::endl;
            }
        }
    }
    }
    brojac=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuPodudarni(*v[i],*v[j]))
            brojac++;
        }
    }
    if(brojac==0)
    cout<<"Nema podudarnih trouglova!"<<std::endl;
    else{
    cout<<"Parovi podudarnih trouglova: "<<std::endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuPodudarni(*v[i],*v[j])){
            (*v[i]).Ispisi();
            cout<<" i ";
            (*v[j]).Ispisi();
            cout<<std::endl;
            }
        }
    }
    }
    brojac=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuSlicni(*v[i],*v[j]))
            brojac++;
        }
    }
    if(brojac==0)
    cout<<"Nema slicnih trouglova!"<<std::endl;
    else{
    cout<<"Parovi slicnih trouglova: "<<std::endl;
     for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuSlicni(*v[i],*v[j])){
            (*v[i]).Ispisi();
            cout<<" i ";
            (*v[j]).Ispisi();
            cout<<std::endl;
            }
        }
    }
    }
	return 0;
}