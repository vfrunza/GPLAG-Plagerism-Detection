/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <memory>
#include <algorithm>
const double e(1E-10);
typedef std::pair<double, double> Tacka;
bool jednako(double x, double y){ return fabs(x-y)<e;}
class Trougao{
    Tacka ta1, ta2, ta3;
    static bool IndeksIspravan ( const int indeks){
    if(indeks==1 || indeks==2 || indeks==3) return true;
    return false;
}
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka&t1, const Tacka&t2, const Tacka&t3);
    Tacka DajTjeme(int indeks)const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim () const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentian() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Translatiraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    ta1=t1;
    ta2=t2;
    ta3=t3;
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    ta1=t1;
    ta2=t2;
    ta3=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(!IndeksIspravan(indeks)) throw std::range_error("Neispravan indeks");
    if(indeks==1){
        if(Orijentacija(t,ta2,ta3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        ta1=t;
    }
    if(indeks==2) {
        if(Orijentacija(ta1,t,ta3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        ta2=t;
    }
    if(indeks==3) {
        if(Orijentacija(ta1,ta2,t)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        ta3=t;
    }
}
int Trougao::Orijentacija(const Tacka&t1, const Tacka&t2, const Tacka&t3){
    double o=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)- t3.first*(t1.second-t2.second);
    if(o<0) return -1;
    if(o>0) return 1;
    else return 0;
}
Tacka Trougao::DajTjeme(int indeks)const{
    if(!IndeksIspravan(indeks)) throw std::range_error("Neispravan indeks");
    if(indeks==1) return ta1;
    if(indeks==2) return ta2;
    return ta3;
}
double Trougao::DajStranicu(int indeks) const{
    if(!IndeksIspravan(indeks)) throw std::range_error("Neispravan indeks");
    if(indeks==1){
        double stranica=std::sqrt((ta2.first-ta3.first)*(ta2.first-ta3.first)-(ta2.second-ta3.second)*(ta2.second-ta3.second));
        return stranica;
    }
    if(indeks==2){
        double stranica=std::sqrt((ta1.first-ta3.first)*(ta1.first-ta3.first)-(ta1.second-ta3.second)*(ta1.second-ta3.second));
        return stranica;
    }
    double stranica=std::sqrt((ta2.first-ta1.first)*(ta2.first-ta1.first)-(ta2.second-ta1.second)*(ta2.second-ta1.second));
    return stranica;
}
double Trougao::DajUgao(int indeks) const{
    if(!IndeksIspravan(indeks)) throw std::range_error("Neispravan indeks");
    double a=DajStranicu(1), b=DajStranicu(2), c=DajStranicu(3);
    if(indeks==1){
        double Ugao=(a*a-b*b-c*c)/(2*b*c);
        return Ugao;
    }
    if(indeks==2){
        double Ugao=(b*b-a*a-c*c)/(2*a*c);
        return Ugao;
    }
    double Ugao=(c*c-b*b-a*a)/(2*b*a);
    return Ugao;
    
}
Tacka Trougao::DajCentar() const{
    Tacka t;
    t.first=(ta1.first+ta2.first+ta3.first)/3;
    t.second=(ta1.second+ta2.second+ta3.second)/3;
    return t;
}
double Trougao::DajObim () const{
    double obim=DajStranicu(1)+DajStranicu(2)+ DajStranicu(3);
    return obim;
}
double Trougao::DajPovrsinu() const{
    double povrsina=ta1.first*(ta2.second-ta3.second)-ta2.first*(ta1.second-ta3.second)- ta3.first*(ta1.second-ta2.second);
    return povrsina;
}
bool Trougao::DaLiJePozitivnoOrijentian() const{
    if(Orijentacija(ta1, ta2, ta3)==1)return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    Trougao t1(ta1,ta2,t), t2(ta2, ta3, t), t3(ta3, ta1, t);
    if(DaLiJePozitivnoOrijentian()&& t1.DaLiJePozitivnoOrijentian() &&t2.DaLiJePozitivnoOrijentian()&&t3.DaLiJePozitivnoOrijentian()) return true;
    return false;
}
void Trougao::Ispisi() const{
    std::cout<<"(("<<ta1.first<<","<<ta1.second<<"),("<<ta2.first<<","<<ta2.second<<"),("<<ta3.first<<","<<ta3.second<<"))";
}
void Trougao::Translatiraj(double delta_x, double delta_y){
    ta1.first+=delta_x; ta1.second+=delta_y;
    ta2.first+=delta_x; ta2.second+=delta_y;
    ta3.first+=delta_x; ta3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    Tacka tc=DajCentar();
    double delta_x=t.first-tc.first;
    double delta_y=t.second-tc.second;
    Translatiraj(delta_x, delta_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    ta1.first=t.first+(ta1.first-t.first)*std::cos(ugao)-(ta1.second-t.second)*std::sin(ugao);
    ta1.second=t.second+(ta1.first-t.first)*std::sin(ugao)-(ta1.second-t.second)*std::cos(ugao);
    ta2.first=t.first+(ta2.first-t.first)*std::cos(ugao)-(ta2.second-t.second)*std::sin(ugao);
    ta2.second=t.second+(ta2.first-t.first)*std::sin(ugao)-(ta2.second-t.second)*std::cos(ugao);
    ta3.first=t.first+(ta3.first-t.first)*std::cos(ugao)-(ta3.second-t.second)*std::sin(ugao);
    ta3.second=t.second+(ta3.first-t.first)*std::sin(ugao)-(ta3.second-t.second)*std::cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    if(t==ta1){
        ta2.first=t.first+faktor*(ta2.first-t.first);
        ta2.second=t.second+faktor*(ta2.second-t.second);
        ta3.first=t.first+faktor*(ta3.first-t.first);
        ta3.second=t.second+faktor*(ta3.second-t.second);
    }
    if(t==ta2){
        ta1.first=t.first+faktor*(ta1.first-t.first);
        ta1.second=t.second+faktor*(ta1.second-t.second);
        ta3.first=t.first+faktor*(ta3.first-t.first);
        ta3.second=t.second+faktor*(ta3.second-t.second);
    }
    if(t==ta3){
        ta2.first=t.first+faktor*(ta2.first-t.first);
        ta2.second=t.second+faktor*(ta2.second-t.second);
        ta1.first=t.first+faktor*(ta1.first-t.first);
        ta1.second=t.second+faktor*(ta1.second-t.second);
    }
    
}
void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(), ugao);
}
void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(), faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if((t1.ta1==t2.ta1 || t1.ta1==t2.ta2|| t1.ta1==t2.ta3)&&(t1.ta2==t2.ta1 || t1.ta1==t2.ta2|| t1.ta2==t2.ta3) &&(t1.ta3==t2.ta1|| t1.ta3==t2.ta1|| t1.ta3==t2.ta1) ) return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    double a1=t1.DajStranicu(1), b1=t1.DajStranicu(2), c1=t1.DajStranicu(3);
    double alfa1=t1.DajUgao(1), beta1=t1.DajUgao(2), gama1=t1.DajUgao(3);
    double a2=t2.DajStranicu(1), b2=t2.DajStranicu(2), c2=t2.DajStranicu(3);
    double alfa2=t2.DajUgao(1), beta2=t2.DajUgao(2), gama2=t2.DajUgao(3);
    if((jednako(a1, a2) && jednako(b1, b2) && jednako(gama1,gama2))||(jednako(a1,a2) && jednako(c1,c2)&&jednako(beta2, beta1)) || (jednako(b1, b2)&&jednako(c1,c2)&& jednako(alfa1, alfa2))) return true;
    if((jednako(a1, c2)&& jednako(b1, a2)&&jednako(gama1, beta2))||(jednako(a1, b2)&& jednako(b1, c2)&&jednako(gama1, alfa2))) return true;
    if((jednako(a1,c2)&&jednako(c1,b2)&&jednako(beta1, alfa2))||(jednako(a1, b2) &&jednako(c1, a2) &&jednako(beta1, gama2))) return true;
    if((jednako(b1, c2)&&jednako(c1,a2)&& jednako(alfa1, beta2))||(jednako(b1, a2)&&(jednako(c1,b2)&&jednako(alfa1, gama2)))) return true;
    
    if((jednako(alfa1, alfa2) && jednako(beta2, beta1) && jednako(c1,c2)) ||(jednako(beta2,beta1) && jednako(gama2,gama1) &&jednako(a1,a2))||(jednako(gama2,gama1)&& jednako(alfa1,alfa2) &&jednako(b1,b2))) return true;
    
    if((jednako(a1,a2) && jednako(b1,b2) &&jednako(c1,c2))|| (jednako(a1,c2)&&jednako(b1,a2)&&jednako(c1,b2))||(jednako(a1, b2)&& jednako(b1, c2)&&jednako(c1,a2))) return true;
    
    if(jednako(a1,a2) && jednako(b1,b2) &&((a1>b1 && jednako(alfa1,alfa2))||(b1>a1 && jednako(beta1,beta2)))) return true;
    
    if(jednako(a1,a2) && jednako(c1,c2)&&((a1>c1 && jednako(alfa1,alfa2))||(c1>a1 && jednako(gama1, gama2)))) return true;
    
    if(jednako(c1,c2) && jednako(b1, b2) &&((c1>b1 && jednako(gama2, gama1))||(b1>c1 && jednako(beta2, beta1)))) return true;
    
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double alfa1=t1.DajUgao(1), beta1=t1.DajUgao(2), gama1=t1.DajUgao(3); 
    double alfa2=t2.DajUgao(1), beta2=t2.DajUgao(2), gama2=t2.DajUgao(3);
    if((jednako(alfa1,alfa2) && jednako(beta1, beta2)&& jednako(gama1, gama2)) || (jednako(alfa1,gama2) && jednako(beta1,alfa2) && jednako(gama1,beta2)) || (jednako(alfa1,beta2) && jednako(beta1,gama2) && jednako(gama1,alfa2))) return true;
    return false;
}
int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i=0; i<n; i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1,t2,t3;
        std::cin>>t1.first>>t1.second;
        std::cin>>t2.first>>t2.second;
        std::cin>>t3.first>>t3.second;
        Trougao t(t1,t2,t3);
        if(t.Orijentacija(t1,t2,t3)==0) {
            while(t.Orijentacija(t1,t2,t3)==0){
                double a,b,c,d,e,f;
                std::cin>>a>>b>>c>>d>>e>>f;
                t1.first=a; t1.second=b;
                t2.first=c; t2.second=d;
                t3.first=e; t3.second=f;
                t.Postavi(t1,t2,t3);
            }
        }
     v[i]= std::shared_ptr<Trougao> (new Trougao(t1,t2,t3));
    }
    std::transform(v.begin(), v.end(), v.begin(), [](std::shared_ptr<Trougao> a){
        double x,y;
        std::cout<<"Unesite vektor translacije (dx, dy): ";
        std::cin>>x>>y;
        a->Translatiraj(x,y);
        double z;
        std::cout<<"Unesite ugao rotacije: ";
        std::cin>>z;
        a->Rotiraj(z);
        double q;
        std::cout<<"Unesite faktor skaliranja: ";
        std::cin>>q;
        a->Skaliraj(a->DajTjeme(1), q);
        
        return a;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> a, std::shared_ptr<Trougao> b){
        return a->DajPovrsinu()<b->DajPovrsinu();
    });
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> a){
        a->Ispisi();
        std::cout<<std::endl;
    });
    auto a= std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> a, std::shared_ptr<Trougao> b){
        return a->DajObim()<b->DajObim();
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto b=*a;
    b->Ispisi();
    //parovi
    return 0;
}