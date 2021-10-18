/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <map>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

typedef std::pair<double, double> Tacka;
const double PI (4*atan(1));

class Trougao{
    Tacka t1, t2, t3;
    void Ispisitacku(const Tacka &t)const{
        std::cout<<"("<<t.first<<","<<t.second<<")";
    }
    bool KorektanIndex(int index){
        return (index>0 && index<4);
    }
    static double KruzniIzraz(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double izraz(t1.first*(t2.second - t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second - t2.second));
        return izraz;
    }
    Tacka FormulaZaRotaciju(Tacka &t, const Tacka &t1, double ugao){
        Tacka pom;
        pom.first = (t.first+(t1.first-t1.first)*std::cos(ugao)) - ((t1.second-t.second)*std::sin(ugao));
        pom.second = (t.second+(t1.first-t.first))*std::sin(ugao) - (t1.second-t.second)*std::cos(ugao);
        return pom;
    }
    Tacka FormulaZaSkaliranje(const Tacka &t, const Tacka &t1, double faktor){
        Tacka pom;
        pom.first = (t.first + faktor*(t1.first-t.first));
        pom.second = (t.second + faktor*(t1.second-t.second)); 
        return pom;
    }
    template<typename TIP>
        bool DoubleJednak(TIP a, TIP b, double Eps=1e-10){
            return std::fabs(a-b) <= Eps*(std::fabs(a)+std::fabs(b));
        }
    
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){Postavi(t1,t2,t3);}
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    void Postavi(int index, const Tacka &t){
        if(!(index>=1 && index<=3)) throw std::range_error("Nekorektan indeks");
        if(index==1){if(Orijentacija(t,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");   Trougao::t1=t;}
        if(index==2){if(Orijentacija(t1,t,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");   Trougao::t2=t;}
        if(index==3){if(Orijentacija(t1,t2,t)==0) throw std::domain_error("Nekorektne pozicije tjemena");   Trougao::t3=t;}
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double izraz(KruzniIzraz(t1,t2,t3));
        if(izraz>0) return 1;
        if(izraz<0) return -1;
        return 0;
    }
    Tacka DajTjeme(int index) const {
        if(!(index>=1 && index<=3)) throw std::range_error("Nekorektan indeks");
        if(index==1){return t1;}
        if(index==2){return t2;}
        return t3;
    }
    double DajStranicu(int index) const {
        if(!(index>=1 && index<=3)) throw std::range_error("Nekorektan index");
        if(index==1){return (std::sqrt(((t3.first-t2.first)*(t3.first-t2.first) + (t3.second-t2.second)*(t3.second-t2.second))));}
        if(index==2){return (std::sqrt(((t3.first-t1.first)*(t3.first-t1.first) + (t3.second-t1.second)*(t3.second-t1.second))));}
        return (std::sqrt(((t1.first-t2.first)*(t1.first-t2.first) + (t1.second-t2.second)*(t1.second-t2.second))));
    }
    double DajUgao(int index) const {
        if(!(index>=1 && index<=3)) throw std::range_error("Nekorektan indeks");
        double a(DajStranicu(1));
        double b(DajStranicu(2));
        double c(DajStranicu(3));
        if(index==1){
            double Alpha;
            Alpha = acos(((b*b)+(c*c)-(a*a))/(2*b*c)) * 180./PI;
            return Alpha;
        }
        if(index==2){
            double Beta;
            Beta = acos(((c*c)+(a*a)-(b*b)) / (2*c*a)) * 180.0/PI;
            return Beta;
        }
        double Gamma;
        Gamma = acos(((a*a)+(b*b)-(c*c))/(2*b*a)) * 180.0/PI;
        return Gamma;
    }
    Tacka DajCentar() const {
        Tacka S;
        S.first = (t1.first + t2.first + t3.first)/3;
        S.second = (t1.second + t2.second + t3.second)/3;
        return S;
    }
    double DajObim() const {return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);}
    double DajPovrsinu() const {return 0.5*std::abs(KruzniIzraz(t1,t2,t3));}
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(t1,t2,t3)==-1 || Orijentacija(t1,t2,t3)==0) return false;
        return true;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if(Orijentacija(t1,t2,t3) == Orijentacija(t1,t2,t) == Orijentacija(t2,t3,t) == Orijentacija(t3,t1,t)) return true;
        return false;
    }
    void Ispisi() const {
        std::cout<<"(";Ispisitacku(DajTjeme(1));
        std::cout<<" , "; Ispisitacku(DajTjeme(2));
        std::cout<<" , "; Ispisitacku(DajTjeme(3));
        std::cout<<")";    
    }
    void Transliraj(double delta_x, double delta_y){
        Trougao::t1.first += delta_x;
        Trougao::t1.second += delta_y;
        Trougao::t2.first += delta_x;
        Trougao::t2.second += delta_y;
        Trougao::t3.first += delta_x;
        Trougao::t3.second +=delta_y;
    }
    void Centriraj(const Tacka &t){
        Tacka stari_centar(DajCentar());
        double delta_x=t.first-stari_centar.first;
        double delta_y=t.second-stari_centar.second;
        Transliraj(delta_x,delta_y);
    }
    void Rotiraj(const Tacka &t, double ugao){
        Trougao::t1=FormulaZaRotaciju(t1,t,ugao);
        Trougao::t2=FormulaZaRotaciju(t2,t,ugao);
        Trougao::t3=FormulaZaRotaciju(t3,t,ugao);
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(DoubleJednak(faktor,0.)) {std::domain_error("Nekorektan faktor skaliranja");}
        Trougao::t1=FormulaZaSkaliranje(t1,t,faktor);
        Trougao::t2=FormulaZaSkaliranje(t2,t,faktor);
        Trougao::t3=FormulaZaSkaliranje(t3,t,faktor);
    }
    void Rotiraj(double ugao){
        Tacka t(DajCentar());
        Rotiraj(t,ugao);
    }
    void Skaliraj(double faktor){
        Tacka t(DajCentar());
        Skaliraj(t,faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
template<typename TIP>
    bool DoubleJednak(TIP a, TIP b, double Eps=1e-10){
        return std::fabs(a-b) <= Eps*(std::fabs(a)+std::fabs(b));
    }
bool PorediTjemena(const Tacka &t1, const Tacka &t2){
    if(DoubleJednak(t1.first, t2.first)==true && DoubleJednak(t1.second,t2.second)==true) return 1;
    return 0;
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    for(int i=1;i<4;i++){
        bool Ima=false;
        Tacka prva = t1.DajTjeme(i);
        for(int j=1;j<4;j++){
            Tacka druga = t2.DajTjeme(j);
            if(PorediTjemena(prva, druga)==true) {Ima=true; break;}
        }
        if(Ima==false) return 0;
    }
    return 1;
}

bool IspitajPodudarnost();
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    for(int i=1;i<=3;i++){
        bool preskoci=false;
        double b1,b2;
        double a1(t1.DajStranicu(i)), a2(t2.DajStranicu(i));
        if(i==3) {b1=t1.DajStranicu(1), b2=t2.DajStranicu(1); preskoci=true;}
        if(preskoci==false) b1=t1.DajStranicu(i+1), b2=t2.DajStranicu(i+1);
        double ugao1(t1.DajUgao(i)), ugao2(t2.DajUgao(i));
        
        if(DoubleJednak(a1,a2) && DoubleJednak(b1,b2) && DoubleJednak(ugao1,ugao2)) return true;
    }
    return false;
}

int main (){
    Tacka prva(0,5);
    Tacka druga(0,0);
    Tacka treca(5,0);
    Trougao u(prva,druga,treca);
    u.Rotiraj(druga, 4*atan(1));
    u.Ispisi();

/*
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    if(n<=0) {std::cout<<"Niste unijeli prirodan broj!"; return 0;}
	
	std::vector<std::shared_ptr<Trougao>> vek(n,nullptr);
    try{
        for(int i=0;i<n;i++){
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            double x1,y1;
            std::cin>>x1>>y1;
            Tacka prva(x1,y1);
            
            double x2,y2;
            std::cin>>x2>>y2;
            Tacka druga(x2,y2);
            
            double x3,y3;
            std::cin>>x3>>y3;
            Tacka treca(x3,y3);
            Trougao t(prva,druga,treca);
            auto s = std::make_shared<Trougao>(t);
            vek[i]=s;
        }
        std::cout<<"Unesite vektor translacije (dx dy): ";
        double delta_x, delta_y;
        std::cin>>delta_x>>delta_y;
        
        //std::transform(vek.begin(), vek.end(), vek.begin(), [delta_x,delta_y](Trougao &t))
        
        std::cout<<"Unesite ugao rotacije: ";
        double ugao;
        std::cin>>ugao;
        
        std::cout<<"Unesite faktor skaliranja: ";
        double faktor;
        std::cin>>faktor;
        
//Pozivanje funkcija        
        for(int i=0;i<n;i++){
            vek[i]->Transliraj(delta_x,delta_y);
        }
        
        for(int i=0;i<n;i++){
            vek[i]->Rotiraj(vek[i]->DajTjeme(1),ugao);
        }
        for(int i=0;i<n;i++){
            vek[i]->Skaliraj(vek[i]->DajTjeme(1),faktor);
        }
        
        std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
        //std::sort(vek.begin(),vek.end(),[](Trougao *t1, Trougao *t2){ return (t1->DajPovrsinu() > t2->DajPovrsinu());});
        for(int i=0;i<n;i++){
            vek[i]->Ispisi();   std::cout<<std::endl;
        }
        
        std::cout<<"Trougao sa najmanjim obimom: ";
        //auto s = std::min_element(vek.begin(),vek.end(),[](Trougao t1) {return t1.DajObim();});
        
        
        std::cout<<"Parovi identicnih trouglova: ";
        
        std::cout<<"Parovi podudarnih trouglova: ";
        
        std::cout<<"Parovi slicnih trouglova: ";
    }catch(std::domain_error izu){
        std::cout<<izu.what()<<", ponovite unos!"<<std::endl;
    }
*/    
	return 0;
}