/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka t1, t2, t3;
    static bool Poredjenje(double x, double y, double eps=1e-10){
        return std::fabs(x-y)<=eps*(std::fabs(y)+std::fabs(x));
    }
    static double F(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){ 
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Postavi(t1,t2,t3); 
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){ 
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        if(indeks<=0 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) t1=t;
        else if(indeks==2) t2=t;
        else t3=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(F(t1,t2,t3)>0) return 1;
        if(F(t1,t2,t3)<0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks<=0 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return t1;
        else if(indeks==2) return t2;
        else return t3;
    }
    double DajStranicu(int indeks) const{
        if(indeks<=0 || indeks>3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return std::sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
        else if(indeks==2) return std::sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
        else return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
    double DajUgao(int indeks) const;
    
    Tacka DajCentar() const{
        Tacka t;
        t.first=(t1.first+t2.first+t3.first)/3;
        t.second=(t1.second+t2.second+t3.second)/3;
        return t;
    }
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const{
        return (1./2)*abs(F(t1,t2,t3));
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(t1,t2,t3)==1) return 1;
        else if(Orijentacija(t1,t2,t3)==-1) return 0;
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        if(Orijentacija(t1,t2,t3)==Orijentacija(t1,t2,t)==Orijentacija(t2,t3,t)==Orijentacija(t3,t1,t)) return true;
        else return false;
    }
    void Ispisi() const{
        cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y){
        t1.first+=delta_x; t1.second+=delta_y;
        t2.first+=delta_x; t2.second+=delta_y;
        t3.first+=delta_x; t3.second+=delta_y;
    }
    void Centriraj(const Tacka &t){
       double delta_x=DajCentar().first-t.first;
       double delta_y=DajCentar().second-t.second;
       Transliraj(delta_x, delta_y);
    }
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao){
        Tacka t(DajCentar());
        Rotiraj(t, ugao);
    }
    void Skaliraj(double faktor){
        if(Poredjenje(faktor, 0)==true) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t(DajCentar());
        Skaliraj(t, faktor);
    }
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);

};

double Trougao::DajUgao(int indeks) const{
        if(indeks<=0 || indeks>3) throw std::range_error("Nekorektan indeks");
        double a(DajStranicu(1));
        double b(DajStranicu(2));
        double c(DajStranicu(3));
        if(indeks==1){
            double u1=(b*b+c*c-a*a)/(2*b*c);
            return std::acos(u1);
        }
        else if(indeks==2){
            double u2=(a*a+c*c-b*b)/(2*a*c);
            return std::acos(u2);
        }
        else{
            double u3=(a*a+b*b-c*c)/(2*b*a);
            return std::acos(u3);
        }
    }
    
    void Trougao::Rotiraj(const Tacka &t, double ugao){
        Tacka pom1, pom2, pom3;
        pom1.first=t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao);
        pom1.second=t.second+(t1.first-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao);
        pom2.first=t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao);
        pom2.second=t.second+(t2.first-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao);
        pom3.first=t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao);
        pom3.second=t.second+(t3.first-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao);
        t1=pom1; t2=pom2; t3=pom3;
    }
    void Trougao::Skaliraj(const Tacka &t, double faktor){
        if(Poredjenje(faktor, 0)==true) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka pom1, pom2, pom3;
        pom1.first=t.first+faktor*(t1.first-t.first);
        pom1.second=t.second+faktor*(t1.second-t.second);
        pom2.first=t.first+faktor*(t2.first-t.first);
        pom2.second=t.second+faktor*(t2.second-t.second);
        pom3.first=t.first+faktor*(t3.first-t.first);
        pom3.second=t.second+faktor*(t3.second-t.second);
        t1=pom1; t2=pom2; t3=pom3;
    }
    
    bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        std::vector<Tacka>v1;
        std::vector<Tacka>v2;
        v1.push_back(t1.Trougao::t1);
        v1.push_back(t1.Trougao::t2);
        v1.push_back(t1.Trougao::t3);
        v2.push_back(t2.Trougao::t1);
        v2.push_back(t2.Trougao::t2);
        v2.push_back(t2.Trougao::t3);
        std::vector<double>vs1(3);
        std::vector<double>vs2(3);
        for(int i=0;i<3;i++){
            vs1[i]=t1.DajStranicu(i+1);
            vs2[i]=t2.DajStranicu(i+1);
        }
        for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if(vs1[i]>vs1[j]) {
                    std::swap(vs1[i], vs1[j]);
                    std::swap(v1[i], v1[j]);
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if(vs2[i]>vs2[j]) {
                    std::swap(vs2[i], vs2[j]);
                    std::swap(v2[i], v2[j]);
                }
            }
        }
        bool identicni(true);
        for(int i=0;i<3;i++){
            if(!(Trougao::Poredjenje(v1[i].first, v2[i].first)) || !(Trougao::Poredjenje(v1[i].second, v2[i].second))) identicni=false;
        }
        return identicni;
    }
    
    bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        std::vector<Tacka>v1;
        std::vector<Tacka>v2;
        v1.push_back(t1.Trougao::t1);
        v1.push_back(t1.Trougao::t2);
        v1.push_back(t1.Trougao::t3);
        v2.push_back(t2.Trougao::t1);
        v2.push_back(t2.Trougao::t2);
        v2.push_back(t2.Trougao::t3);
        std::vector<double>vs1(3);
        std::vector<double>vs2(3);
        for(int i=0;i<3;i++){
            vs1[i]=t1.DajStranicu(i+1);
            vs2[i]=t2.DajStranicu(i+1);
        }
        std::vector<double>vu1(3);
        std::vector<double>vu2(3);
        for(int i=0;i<3;i++){
            vu1[i]=t1.DajUgao(i+1);
            vu2[i]=t2.DajUgao(i+1);
        }
        for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if(vs1[i]>vs1[j]){
                    std::swap(vs1[i], vs1[j]);
                    std::swap(v1[i], v1[j]);
                    std::swap(vu1[i], vu1[j]);
                        
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if(vs2[i]>vs2[j]){
                    std::swap(vs2[i], vs2[j]);
                    std::swap(v2[i], v2[j]);
                    std::swap(vu2[i], vu2[j]);
                }
            }
        }
        bool podudarni(true);
        for(int i=0;i<3;i++){
            if(!Trougao::Poredjenje(vs1[i],vs2[i]) || !Trougao::Poredjenje(vu1[i],vu2[i])) podudarni=false;
        }
        if(podudarni==true && (Trougao::Orijentacija(v1[0], v1[1], v1[2])==Trougao::Orijentacija(v2[0], v2[1], v2[2]))) return true;
        else return false;
    }
    
    bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        std::vector<Tacka>v1;
        std::vector<Tacka>v2;
        v1.push_back(t1.Trougao::t1);
        v1.push_back(t1.Trougao::t2);
        v1.push_back(t1.Trougao::t3);
        v2.push_back(t2.Trougao::t1);
        v2.push_back(t2.Trougao::t2);
        v2.push_back(t2.Trougao::t3);
        std::vector<double>vs1(3);
        std::vector<double>vs2(3);
        double faktor(t1.DajStranicu(1)/t2.DajStranicu(1));
        for(int i=0;i<3;i++){
            vs1[i]=t1.DajStranicu(i+1);
            vs2[i]=t2.DajStranicu(i+1);
        }
        for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if(vs1[i]>vs1[j]){
                    std::swap(vs1[i], vs1[j]);
                    std::swap(v1[i], v1[j]);
                }
            }
        }
        for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if(vs2[i]>vs2[j]){
                    std::swap(vs2[i], vs2[j]);
                    std::swap(v2[i], v2[j]);
                }
            }
        }
        bool slicni(true);
        for(int i=0;i<3;i++){
            if(!Trougao::Poredjenje(vs1[i]/vs2[i],faktor)) slicni=false;
        }
        if(slicni==true && (Trougao::Orijentacija(v1[0], v1[1], v1[2])==Trougao::Orijentacija(v2[0], v2[1], v2[2]))) return true;
        else return false;
    }
    

int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    cin>>n;
    std::vector<std::shared_ptr<Trougao>>v;
    
    for(int i=0;i<n;i++){
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1,t2,t3;
        cin>>t1.first>>t1.second;
        cin>>t2.first>>t2.second;
        cin>>t3.first>>t3.second;
        try{
            auto p(std::make_shared<Trougao>(t1,t2,t3));
            v.push_back(p);
        }
        catch(std::domain_error iz){
            cout<<iz.what()<<", ponovite unos!"<<endl;
            i--;
        }
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double dx,dy;
    cin>>dx>>dy;
    cout<<"Unesite ugao rotacije: ";
    double ugao;
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    double faktor;
    cin>>faktor;
    std::transform(v.begin(), v.end(), v.begin(), [=] (std::shared_ptr<Trougao>pok){
        pok->Transliraj(dx,dy);
        pok->Rotiraj(ugao);
        pok->Skaliraj(pok->DajTjeme(1), faktor);
        return pok;
    });
    std::sort(v.begin(), v.end(), [=] (std::shared_ptr<Trougao>pok1, std::shared_ptr<Trougao>pok2){
       return pok1->DajPovrsinu()<pok2->DajPovrsinu();
    });
    cout<<"Trouglovi nakon obavljenih transformacija: ";
    std::for_each(v.begin(), v.end(), [=] (std::shared_ptr<Trougao>pok){ 
        cout<<endl;
        pok->Ispisi();
    });
    auto it=std::min_element(v.begin(), v.end(), [=] (std::shared_ptr<Trougao>pok1, std::shared_ptr<Trougao>pok2){
        return pok1->DajObim()<pok2->DajObim();
    });
    cout<<endl;
    cout<<"Trougao sa najmanjim obimom: ";
    (*it)->Ispisi();
    cout<<endl;
    
    bool identicni(false);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuIdenticni(*v[i], *v[j])) identicni=true;
        }
    }
    if(!identicni) cout<<"Nema identicnih trouglova!"<<endl;
    else{
        cout<<"Parovi identicnih trouglova:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuIdenticni(*v[i], *v[j])){
                    v[i]->Ispisi();
                    cout<<" i ";
                    v[j]->Ispisi();
                    cout<<endl;
                }
            }
        }
    }
    bool podudarni(false);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuPodudarni(*v[i], *v[j])) podudarni=true;
        }
    }
    if(!podudarni) cout<<"Nema podudarnih trouglova!"<<endl;
    else{
        cout<<"Parovi podudarnih trouglova:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuPodudarni(*v[i], *v[j])){
                    v[i]->Ispisi();
                    cout<<" i ";
                    v[j]->Ispisi();
                    cout<<endl;
                }
            }
        }
    }
    bool slicni(false);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuPodudarni(*v[i], *v[j])) slicni=true;
        }
    }
    if(!slicni) cout<<"Nema slicnih trouglova!"<<endl;
    else{
        cout<<"Parovi slicnih trouglova:"<<endl;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuPodudarni(*v[i], *v[j])){
                    v[i]->Ispisi();
                    cout<<" i ";
                    v[j]->Ispisi();
                    cout<<endl;
                }
            }
        }
    }
    
	return 0;
}