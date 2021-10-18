/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#define PI (4*atan(1))
#define debug if(false)
using std::endl;
using std::cout;
typedef std::pair<double,double> Tacka;

class Trougao {
    Tacka a,b,c;
    static bool d_d(double a,double b){
    return (std::abs(a-b)<=0.0000000001);
    }
    Tacka &dajTacku(int indeks) {
        provjeri(indeks);
        switch(indeks) {
        case 1:
            return a;
        case 2:
            return b;
        case 3:
            return c;
        }
        return a;
    }
    static double udaljenostTacaka(const Tacka &t1,const Tacka &t2) {
        return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+
                         (t1.second-t2.second)*(t1.second-t2.second));
    }
    static int sljedeceTjeme(int i) {
        if(i==3)return 1;
        return i+1;
    }
    void provjeri(const Tacka &t1,const Tacka &t2, const Tacka &t3)const {
        if(!Orijentacija(t1,t2,t3))
            throw std::domain_error("Nekorektne pozicije tjemena");
    }
    void provjeri(int i)const {
        if(i<1 || i>3)
            throw std::range_error("Nekorektan indeks");
    }
    static double izraz(const Tacka &t1,const Tacka &t2, const Tacka &t3) {
        return t1.first*(t2.second-t3.second) + t2.first*(t3.second-t1.second)
               + t3.first *(t1.second - t2.second);
    }
    static double znak(const Tacka &t1,const Tacka &t2, const Tacka &t3) {
        return (t1.first-t3.first)*(t2.second-t3.second)-
               (t2.first-t3.first)*(t1.second-t3.second);
    }
public:
    static int Orijentacija(const Tacka &t1,const Tacka &t2, const Tacka &t3) {
        double tmp = izraz(t1,t2,t3);
        if(!tmp)return 0;
        else if(tmp<0)return -1;
        return 1;
    }
    Trougao(const Tacka &t1,const Tacka &t2, const Tacka &t3) {
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1,const Tacka &t2, const Tacka &t3) {
        provjeri(t1,t2,t3);
        a=t1;
        b=t2;
        c=t3;
    }
    void Postavi(int indeks,const Tacka &t) {
        Tacka tmp = dajTacku(indeks);
        dajTacku(indeks) = t;
        try {
            provjeri(a,b,c);
        } catch (...) {
            dajTacku(indeks)=tmp;
            throw;
        }
    }
    Tacka DajTjeme(int i)const {
        provjeri(i);
        switch(i) {
        case 1:
            return a;
        case 2:
            return b;
        case 3:
            return c;
        }
        return a;
    }
    double DajStranicu(int i)const {
        provjeri(i);
        return udaljenostTacaka(DajTjeme(Trougao::sljedeceTjeme(i)),
                                DajTjeme(Trougao::sljedeceTjeme(Trougao::sljedeceTjeme(i))));
    }
    double DajUgao(int i)const {
        double A = DajStranicu(i);
        double B = DajStranicu(Trougao::sljedeceTjeme(i));
        double C = DajStranicu(Trougao::sljedeceTjeme(Trougao::sljedeceTjeme(i)));
        debug cout<<A<<" "<<B<<" "<<C<<endl;
        return std::acos(((B*B)+(C*C)-(A*A))/(2*B*C));
    }
    Tacka DajCentar()const {
        return Tacka((a.first+b.first+c.first)/3,
                     (a.second+b.second+c.second)/3);
    }
    double DajObim()const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu()const {
        return 0.5*std::abs(izraz(a,b,c));
    }
    bool DaLiJePozitivniOrijentiran()const {
        return (Orijentacija(a,b,c)>0);
    }
    bool DaLiJeUnutra(const Tacka &t)const {
        bool
        q = (znak(t,a,b)<0.00),
        w=(znak(t,b,c)<0.00),
        e=(znak(t,c,a)<0.00);
        return (q==w&&w==e);
    }
    void Ispisi() const{
        cout<<"(("<<a.first<<','<<a.second<<"),("<<b.first<<','<<b.second
            <<"),("<<c.first<<','<<c.second<<"))";
    }
    void Transliraj(double dx,double dy) {
        for (int i = 1; i <= 3; i++) {
            dajTacku(i).first+=dx;
            dajTacku(i).second+=dy;
        }
    }
    void Centriraj(const Tacka &t) {
        Transliraj(DajCentar().first-t.first,DajCentar().second-t.second);
    }
    void Rotiraj(const Tacka &t,double ugao) {
        for(int i =1; i<=3; i++) {
            dajTacku(i) = Tacka(
                          (t.first+(dajTacku(i).first-t.first)*std::cos(ugao)  -
                           (dajTacku(i).second-t.second)*std::sin(ugao)),
                          (t.second+(dajTacku(i).first-t.first)*std::sin(ugao) +
                           (dajTacku(i).second-t.second)*std::cos(ugao))
                      );
        }
    }
    void Skaliraj(const Tacka &t,double k) {
        if(!k)throw std::domain_error("Nekorektan faktor skaliranja");
        for (int i = 1; i <= 3; i++) {
            dajTacku(i) = Tacka(
                t.first + k*(dajTacku(i).first - t.first),
                t.second + k*(dajTacku(i).second - t.second)
                );
        }
    }
    void Rotiraj(double ugao){Rotiraj(DajCentar(),ugao);}
    void Skaliraj(double k){
        Skaliraj(DajCentar(),k);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};
bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
    for (int i = 1; i <= 3; i++) {
        bool ima=false;
        for(int j=1;j<=3;j++){
            if(t1.DajTjeme(i)==t2.DajTjeme(j))ima = true;
        }
        if(!ima)return false;
    }
    return true;
}
bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
    auto o = Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3));
    for (int i = 1; i <= 3; i++) {
        for(int j = 1; j<=3 ; j++)
            for(int k=1;k<=3;k++)
            {
                if(i!=k && i!=j && k!=j)
                {
                    Tacka a = t2.DajTjeme(i),b=t2.DajTjeme(j),c=t2.DajTjeme(k);
                    if(Trougao::Orijentacija(a,b,c)==o){
                        Trougao x(a,b,c);
                        bool iste_stranice = true;
                        for (int e = 1; e <= 3; e++) {
                            if(!Trougao::d_d(x.DajStranicu(e),t1.DajStranicu(e)))
                                iste_stranice=false;
                        }
                        if(iste_stranice)
                        return true;
                    }
                    
                }
            }
    }
    return false;
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
    auto o = Trougao::Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3));
    for (int i = 1; i <= 3; i++) {
        for(int j = 1; j<=3 ; j++)
            for(int k=1;k<=3;k++)
            {
                if(i!=j && i!=k && k!=j )
                {
                    Tacka a = t2.DajTjeme(i),b=t2.DajTjeme(j),c=t2.DajTjeme(k);
                    if(Trougao::Orijentacija(a,b,c)==o){
                        Trougao x(a,b,c);
                        bool iste_stranice = true;
                        for (int e = 1; e <= 3; e++) {
                            if(!Trougao::d_d(x.DajUgao(e),t1.DajUgao(e)))
                                iste_stranice=false;
                        }
                        if(iste_stranice)
                        return true;
                    }
                    
                }
            }
    }
    return false;
}

using std::vector;
using std::shared_ptr;
using std::cin;
int main () {
    int n(0);
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    vector<shared_ptr<Trougao>> v;
    {
    Tacka a,b,c;
    Trougao *tmp=nullptr;
    for (int i = 0; i < n; i++) {
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
        try{
            tmp = new Trougao(a,b,c);
            v.push_back(static_cast<shared_ptr<Trougao>>(tmp));
        }catch(std::domain_error e){
            cout<<e.what()<<", ponovite unos!"<<endl;
            i--;
        }catch(...){
            return 0;
        }
    }
    }
    Tacka vt;
    double ur,fs;
    cout<<"Unesite vektor translacije (dx dy): ";
    cin>>vt.first>>vt.second;
    cout<<"Unesite ugao rotacije: ";
    cin>>ur;
    cout<<"Unesite faktor skaliranja: ";
    cin>>fs;
    cout<<"Trouglovi nakon obavljenih transformacija: \n";
    std::transform(v.begin(),v.end(),v.begin(),[&vt,&ur,&fs](shared_ptr<Trougao> a){
        a->Transliraj(vt.first,vt.second);
        a->Rotiraj(ur);
        a->Skaliraj(a->DajTjeme(1),fs);
        return a;
    });
    
    std::sort(v.begin(),v.end(),[](shared_ptr<Trougao> a, shared_ptr<Trougao> b){
        return a->DajPovrsinu()<b->DajPovrsinu();
    });
    std::for_each(v.begin(),v.end(),[](shared_ptr<Trougao> a){
        a->Ispisi();
        cout<<endl;
    });
    
    cout<<"Trougao sa najmanjim obimom: ";
    (*std::min_element(v.begin(),v.end(),[](shared_ptr<Trougao> a,shared_ptr<Trougao> b){
        return (a->DajObim()<b->DajObim());
    }))->Ispisi();
    cout<<endl;
    bool ima = false;
    bool prvi = true;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) {
            if(DaLiSuIdenticni(*v[i],*v[j])){
                if(prvi)cout<<"Parovi identicnih trouglova: \n";
                prvi=false;
                v[i]->Ispisi();cout<<" i ";v[j]->Ispisi();cout<<endl;
                ima = true;
            }
        }
    }
    if(!ima)cout<<"Nema identicnih trouglova! \n";
    ima=false;
    prvi=true;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) {
            if(DaLiSuPodudarni(*v[i],*v[j])){
                if(prvi)cout<<"Parovi podudarnih trouglova: \n";
                prvi=false;
                v[i]->Ispisi();cout<<" i ";v[j]->Ispisi();cout<<endl;
                ima=true;
            }
        }
    }
    if(!ima)cout<<"Nema podudarnih trouglova! \n";
    prvi=true;
    ima=false;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i+1; j < v.size(); j++) {
            if(DaLiSuSlicni(*v[i],*v[j])){
                if(prvi)cout<<"Parovi slicnih trouglova: \n";
                prvi=false;
                v[i]->Ispisi();cout<<" i ";v[j]->Ispisi();cout<<endl;
                ima=true;
            }
        }
    }
    if(!ima)cout<<"Nema slicnih trouglova! \n";
    return 0;
}
