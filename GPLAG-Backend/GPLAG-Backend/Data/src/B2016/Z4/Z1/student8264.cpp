/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
typedef std::pair<double, double> Tacka;
using std::cout;
using std::cin;
using std::vector;

bool Jednaki(double x, double y,double eps=1e-10) {
    return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));}

class Trougao {
    private:
    Tacka primera,segunda,tercera;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);//zavrseno
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);//zavrseno
    void Postavi(int indeks, const Tacka &t);//zavrseno
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3); //zavrseno
    Tacka DajTjeme(int indeks) const; //zavrseno
    double DajStranicu(int indeks) const; //zavrseno
    double DajUgao(int indeks) const; //zavrseno
    Tacka DajCentar() const; //zavrseno
    double DajObim() const; //zavrseno
    double DajPovrsinu() const; //zavrseno
    bool DaLiJePozitivnoOrijentiran() const; //zavrseno
    bool DaLiJeUnutra(const Tacka &t) const; //zavrseno
    void Ispisi() const; //zavrseno
    void Transliraj(double delta_x, double delta_y); //zavrseno?
    void Centriraj(const Tacka &t); //zavrseno?
    void Rotiraj(const Tacka &t, double ugao); //zavrseno?
    void Skaliraj(const Tacka &t, double faktor); //zavrseno?
    void Rotiraj(double ugao); //zavrseno??
    void Skaliraj(double faktor); //zavrseno?
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2); //zavrseno..?
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2); //pokusaj
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2); //istooxD
};
double f1 (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double y=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    return y;
}
int Trougao::Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (f1(t1,t2,t3)>0) return 1;
    else if(f1(t1,t2,t3)<0) return -1;
    return 0;
}
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    primera=t1;
    segunda=t2;
    tercera=t3;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    primera=t1;
    segunda=t2;
    tercera=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t) {
    //if (Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if (indeks==1) primera=t;
    else if (indeks==2) segunda=t;
    else tercera=t;
}
Tacka Trougao::DajTjeme(int indeks) const {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if (indeks==1) return primera;
    else if (indeks==2) return segunda;
    else return tercera;
}
double Trougao::DajStranicu(int indeks) const {
    if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return std::sqrt((segunda.first-tercera.first)*(segunda.first-tercera.first)+(segunda.second-tercera.second)*(segunda.second-tercera.second));
    else if(indeks==2) return std::sqrt((primera.first-tercera.first)*(primera.first-tercera.first)+(primera.second-tercera.second)*(primera.second-tercera.second));
    else return std::sqrt((segunda.first-primera.first)*(segunda.first-primera.first)+(segunda.second-primera.second)*(segunda.second-primera.second));
}
double Trougao::DajUgao(int indeks) const {
    if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if (indeks==1) {
        double ugao=(DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3));
        ugao=std::acos(ugao)*((4*std::atan(1))/180);
        return ugao;
    }
    else if(indeks==2) {
        double ugao=(DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3));
        ugao=std::acos(ugao)*((4*std::atan(1))/180);
        return ugao;
    }
    else {
        double ugao=(DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2));
        ugao=std::acos(ugao)*((4*std::atan(1))/180);
        return ugao;
    }
}
Tacka Trougao::DajCentar() const {
    double x=(primera.first+segunda.first+tercera.first)/3;
    double y=(primera.second+segunda.second+tercera.second)/3;
    Tacka c(x,y);
    return c;
}
double Trougao::DajObim() const {
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu() const {
    return (std::abs(f1(primera,segunda,tercera)))*0.5;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if(Orijentacija(primera,segunda,tercera)==1)    return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if(Orijentacija(primera,segunda,tercera)==Orijentacija(primera,segunda,t) && Orijentacija(primera,segunda,tercera)==Orijentacija(segunda,tercera,t) && Orijentacija(primera,segunda,tercera)==Orijentacija(tercera,primera,t))
        return true;
    return false;
}
void Trougao::Ispisi() const {
    cout<<"(("<<primera.first<<","<<primera.second<<"),("<<segunda.first<<","<<segunda.second<<"),("<<tercera.first<<","<<tercera.second<<"))"<<std::endl;
}
void Trougao::Transliraj(double delta_x, double delta_y) {
    Tacka nova(primera.first+delta_x,primera.second+delta_y);
    Trougao::Postavi(1,nova);
    Tacka nova1(segunda.first+delta_x,segunda.second+delta_y);
    Trougao::Postavi(2,nova1);
    Tacka nova2(tercera.first+delta_x,tercera.second+delta_y);
    Trougao::Postavi(3,nova2);
}
void Trougao::Centriraj(const Tacka &t) {
    Tacka T(DajCentar());
    double x=t.first-T.first;
    double y=t.second-T.second;
    Tacka n(primera.first+x,primera.second+y);
    Postavi(1,n);
    Tacka n1 (segunda.first+x,segunda.second+y);
    Postavi(2,n1);
    Tacka n2(tercera.first+x,tercera.second+y);
    Postavi (3,n2);
}
void Trougao::Rotiraj(const Tacka &t, double ugao) {
    double x,y,x2,y2,x3,y3;
    x=t.first+(primera.first-t.first)*std::cos(ugao)-(primera.second-t.second)*std::sin(ugao);
    y=t.second+(primera.first-t.first)*std::sin(ugao)+(primera.second-t.second)*std::cos(ugao);
    Tacka xy(x,y);
    Postavi(1,xy);
    
    x2=t.first+(segunda.first-t.first)*std::cos(ugao)-(segunda.second-t.second)*std::sin(ugao);
    y2=t.second+(segunda.first-t.first)*std::sin(ugao)+(segunda.second-t.second)*std::cos(ugao);
    Tacka x2y2(x2,y2);
    Postavi(2,x2y2);
    
    x3=t.first+(tercera.first-t.first)*std::cos(ugao)-(tercera.second-t.second)*std::sin(ugao);
    y3=t.second+(tercera.first-t.first)*std::sin(ugao)+(tercera.second-t.second)*std::cos(ugao);
    Tacka x3y3(x3,y3);
    Postavi(3,x3y3);
}
void Trougao::Skaliraj(const Tacka &t, double faktor) {
    if(Jednaki(faktor,0.0)) throw std::domain_error("Nekorektan faktor skaliranja");
    if(faktor<0)   Rotiraj(t,180);
    double x,y,x2,y2,x3,y3;
    x=t.first+faktor*(primera.first-t.first);
    y=t.second+faktor*(primera.second-t.second);
    Tacka xy;
    Postavi(1,xy);
    x2=t.first+faktor*(segunda.first-t.first);
    y2=t.second+faktor*(segunda.second-t.second);
    Tacka x2y2;
    Postavi(2,x2y2);
    x3=t.first+faktor*(tercera.first-t.first);
    y3=t.second+faktor*(tercera.second-t.second);
    Tacka x3y3;
    Postavi(3,x3y3);
}
void Trougao::Rotiraj(double ugao) {
    Tacka T(DajCentar());
    Rotiraj(T,ugao);
}
void Trougao::Skaliraj(double faktor) {
    Tacka T(DajCentar());
    Skaliraj(T,faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if((t1.DajTjeme(1)==t2.DajTjeme(1) || t1.DajTjeme(1)==t2.DajTjeme(2) || t1.DajTjeme(1)==t2.DajTjeme(3)) && (t1.DajTjeme(2)==t2.DajTjeme(1) || t1.DajTjeme(2)==t2.DajTjeme(2) || t1.DajTjeme(2)==t2.DajTjeme(3))
    && (t1.DajTjeme(3)==t2.DajTjeme(1) || t1.DajTjeme(3)==t2.DajTjeme(2) || t1.DajTjeme(3)==t2.DajTjeme(3)))
        return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    if ((Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))>0 && Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))>0) || (Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))<0 && Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))<0)) {
        if ((Jednaki(t1.DajStranicu(1),t2.DajStranicu(1)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(2)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(3))) || (Jednaki(t1.DajStranicu(1),t2.DajStranicu(2)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(3)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(1))) || (Jednaki(t1.DajStranicu(1),t2.DajStranicu(3)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(1)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(2))))
            return true;
        return false;
    }
    else {
        if ((Jednaki(t1.DajStranicu(1),t2.DajStranicu(1)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(2)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(3))) || (Jednaki(t1.DajStranicu(1),t2.DajStranicu(3)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(1)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(2))) ||(Jednaki(t1.DajStranicu(1),t2.DajStranicu(2)) && Jednaki(t1.DajStranicu(2),t2.DajStranicu(3)) && Jednaki(t1.DajStranicu(3),t2.DajStranicu(1))))
            return true;
        return false;
    }
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
    if ((Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))<0 && Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))<0) || (Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))>0 && Trougao::Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3))>0)) {
        if ((Jednaki(t1.DajUgao(1),t2.DajUgao(1)) && Jednaki(t1.DajUgao(2),t2.DajUgao(2)) && Jednaki(t1.DajUgao(3),t2.DajUgao(3))) || (Jednaki(t1.DajUgao(1),t2.DajUgao(2)) && Jednaki(t1.DajUgao(2),t2.DajUgao(3)) && Jednaki(t1.DajUgao(3),t2.DajUgao(1))) || (Jednaki(t1.DajUgao(1),t2.DajUgao(3)) && Jednaki(t1.DajUgao(2),t2.DajUgao(1)) && Jednaki(t1.DajUgao(3),t2.DajUgao(2))))
            return true;
        return false;
    }
    else {
        if ((Jednaki(t1.DajUgao(1),t2.DajUgao(1)) && Jednaki(t1.DajUgao(3),t2.DajUgao(2)) && Jednaki(t1.DajUgao(2),t2.DajUgao(3)) || (Jednaki(t1.DajUgao(1),t2.DajUgao(2)) && Jednaki(t1.DajUgao(2),t2.DajUgao(1)) && Jednaki(t1.DajUgao(3),t2.DajUgao(3))) || (Jednaki(t1.DajUgao(1),t2.DajUgao(3)) && Jednaki(t1.DajUgao(2),t2.DajUgao(2)) && Jednaki(t1.DajUgao(3),t2.DajUgao(1)))))
            return true;
        return false;
    }
}
    
int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    double x1,x2,x3,y1,y2,y3,dx,dy,ugao,k;
    cin>>n;
    vector<std::shared_ptr<Trougao>> v(n,nullptr);
    for (int i=1; i<=n;i++) {
        cout<<"Unesite podatke za "<<i<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Tacka xy1(x1,y1), xy2(x2,y2), xy3(x3,y3);
        bool vr(Trougao::Orijentacija(xy1,xy2,xy3));
        while (vr==false) {
            cout<<"Upozorenje: Za ova tjemena se ne moze formirati trougao! Ponovni unos:";
            cin>>x1>>y1>>x2>>y2>>x3>>y3;
        }
        try {
            auto t(std::make_shared<Trougao>(Trougao(xy1,xy2,xy3)));
            v.push_back(t);
        }
        catch(...){
            cout<<"Greska pri alociranju memorije";
        }
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    cin>>dx>>dy;
    cout<<"Unesite ugao rotacije: ";
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    cin>>k;
    std::transform(v.begin(),v.end(),v.begin(),[dx,dy,ugao,k](const std::shared_ptr<Trougao> t) { t->Transliraj(dx,dy);   t->Rotiraj(ugao);   t->Skaliraj(t->DajTjeme(1),k); });
    for(int i=1;i<=n-1;i++) 
        std::sort(v.begin(),v.end(),[i,v](const std::shared_ptr<Trougao> t){return v[i]->DajPovrsinu()<v[i+1]->DajPovrsinu();});
    cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
    std::for_each(v.begin(),v.end(),[n,v](const std::shared_ptr<Trougao> t){for(int i=1;i<=n;i++) v[i]->Ispisi();});
    (*std::min_element(v.begin(),v.end(),[v,n](const std::shared_ptr<Trougao> t1){double min=v[1]; for(int i=1;i<=n-1;i++) if(v[i].DajObim()<min.DajObim()) min=v[i]; return v[i]->DajObim();}))->Ispisi();
    cout<<"Trougao sa najmanjim obimom: ";
    cout<<"Parovi identicnih trouglova: ";
    for(int i=1;i<=n-1;i++)
        for(int j=i;j<=n;j++) {
            if(DaLiSuIdenticni(*v[i],*v[j])) {
                v[i]->Ispisi();
                cout<<" i ";
                v[j]->Ispisi();
                cout<<std::endl;
            }
        }
    cout<<"Parovi podudarnih trouglova: ";
    for (int i=1;i<=n-1;i++)
        for(int j=i;j<=n;j++) {
            if(DaLiSuPodudarni(*v[i],*v[j])) {
                v[i]->Ispisi();
                cout<<" i ";
                v[j]->Ispisi();
                cout<<std::endl;
            }
        }
    cout<<"Parovi slicnih trouglova: ";
    for (int i=1;i<=n-1;i++)
        for (int j=i;j<=n;j++) {
            if (DaLiSuSlicni(*v[i],*v[j])) {
                v[i]->Ispisi();
                cout<<" i ";
                v[j]->Ispisi();
                cout<<std::endl;
            }
        }
        
	return 0;
}