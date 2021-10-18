#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <algorithm>

typedef std::pair<double, double> Tacka;
const double Eps(1e-10);

class Trougao{
    Tacka t1, t2, t3;
    
    static double racun(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return (t1.first*(t2.second-t3.second) + t2.first*(t3.second-t1.second) + t3.first*(t1.second-t2.second));
    }
    //Da bi se izbjegao potencijalni problem a aritmetikom, funkcija JesuLiJednaki smanjuje mogucnost greske kod poredjenja double-ova na dole prikazani nacin
    static bool JesuLiJednaki(double x, double y){
        return std::fabs(x - y)<= Eps*(std::fabs(x) + std::fabs(y));
    }
    
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        Postavi(t1, t2, t3);
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    
    void Postavi(int indeks, const Tacka &t){
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) {
            Trougao::t1=t;
            if(racun(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        }
        if(indeks==2) {
            Trougao::t2=t;
            if(racun(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        }
        if(indeks==3) {
            Trougao::t3=t;
            if(racun(t1, t2, t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        }
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        auto x(racun(t1, t2, t3));
        if(x>0) return 1;
        if(x<0) return -1;
        if(JesuLiJednaki(x, 0)==true) return 0;
    }
    
    Tacka DajTjeme(int indeks) const{
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return Trougao::t1;
        if(indeks==2) return Trougao::t2;
        if(indeks==3) return Trougao::t3;
    }
    
    double DajStranicu(int indeks) const{
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        
        //posto funkcija pow takodjer moze dovesti do izvjesnih problema kod aritmetiziranja, kao sto je preporuceno u DODATKU: sokantna prica o realnoj aritmetici, posto je eksponent relativno mali tj. 2 u daljem dijelu koda mnozim "rucno" takve dijelove koje bi inace lakse bilo ispisati u funkciji pow
        
        if(indeks==1) return std::sqrt(double((Trougao::t2.first-Trougao::t3.first)*(Trougao::t2.first-Trougao::t3.first)) + double((Trougao::t2.second-Trougao::t3.second)*(Trougao::t2.second-Trougao::t3.second)));
        if(indeks==2) return std::sqrt(double((Trougao::t1.first-Trougao::t3.first)*(Trougao::t1.first-Trougao::t3.first)) + double((Trougao::t1.second-Trougao::t3.second)*(Trougao::t1.second-Trougao::t3.second)));
        if(indeks==3) return std::sqrt(double((Trougao::t1.first-Trougao::t2.first)*(Trougao::t1.first-Trougao::t2.first)) + double((Trougao::t1.second-Trougao::t2.second)*(Trougao::t1.second-Trougao::t2.second)));
    }
    
    double DajUgao(int indeks) const{
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) {
            double x((double(DajStranicu(2)*DajStranicu(2)) + double(DajStranicu(3)*DajStranicu(3)) - double(DajStranicu(1)*DajStranicu(1)))/double(2*DajStranicu(2)*DajStranicu(3)));
            return std::acos(x);
        }
        if(indeks==2){
            double x((double(DajStranicu(1)*DajStranicu(1)) + double(DajStranicu(3)*DajStranicu(3)) - double(DajStranicu(2)*DajStranicu(2)))/double(2*DajStranicu(1)*DajStranicu(3)));
            return std::acos(x);
        }
        if(indeks==3){
            double x((double(DajStranicu(1)*DajStranicu(1)) + double(DajStranicu(2)*DajStranicu(2)) - double(DajStranicu(3)*DajStranicu(3)))/double(2*DajStranicu(1)*DajStranicu(2)));
            return std::acos(x);
        }
    }
    
    Tacka DajCentar() const{
        double x, y;
        x= double((Trougao::t1.first + Trougao::t2.first + Trougao::t3.first)/3);
        y= double((Trougao::t1.second + Trougao::t2.second + Trougao::t3.second)/3);
        Tacka tacka;
        tacka= std::make_pair(x, y);
        return tacka;
    }
    
    double DajObim() const{ return (DajStranicu(1) + DajStranicu(2) + DajStranicu(3)); }
    double DajPovrsinu() const{ return double((std::abs(racun(t1, t2, t2)))/2);}
    
    bool DaLiJePozitivnoOrijenitran() const{
        if(racun(t1, t2, t3)>0) return true;
        else return false;
    }
    
    bool DaLiJeUnutra(const Tacka &t) const{
        auto x(double(std::abs(racun(t1, t2, t3))/2));
        auto y(double((std::abs(racun(t1, t2, t)))/2) + double((std::abs(racun(t2, t3, t)))/2) + double((std::abs(racun(t3, t1, t)))/2));
        
        if(std::fabs(x-y)<=Eps*(std::fabs(x) + std::fabs(y))) return true;
        else return false;
    }
    
    void Ispisi() const{ std::cout<<"(("<<int(Trougao::t1.first)<<","<<int(Trougao::t1.second)<<"),("<<int(Trougao::t2.first)<<","<<int(Trougao::t2.second)<<"),("<<int(Trougao::t3.first)<<","<<int(Trougao::t3.second)<<"))"; }
    
    void Transliraj (double delta_x, double delta_y){
        t1.first=t1.first+delta_x;
        t1.second=t1.second+delta_y;
        
        t2.first=t2.first+delta_x;
        t2.second=t2.second+delta_y;
        
        t3.first=t3.first+delta_x;
        t3.second=t3.second+delta_y;
    }
    
    void Centriraj (const Tacka &t){
        double po_x, po_y;
        Tacka T(DajCentar());
        
        po_x= double(t.first - T.first);
        po_y= double(t.second - T.second);
        
        t1.first=t1.first + po_x;
        t1.second=t1.second + po_y;
        
        t2.first= t2.first + po_x;
        t2.second= t2.second + po_y;
        
        t3.first= t3.first + po_x;
        t3.second= t3.second + po_y;
        
    }
    
    void Rotiraj (const Tacka &t, double ugao){
        
        t1.first= t.first + (t1.first - t.first)*std::cos(ugao) - (t1.second - t.second)*std::sin(ugao);
        t1.second= t.second + (t1.first - t.first)*std::sin(ugao) + (t1.second - t.second)*std::cos(ugao);
        
        t2.first= t.first + (t2.first - t.first)*std::cos(ugao) - (t2.second - t.second)*std::sin(ugao);
        t2.second= t.second + (t2.first - t.first)*std::sin(ugao) + (t2.second - t.second)*std::cos(ugao);
        
        t3.first= t.first + (t3.first - t.first)*std::cos(ugao) - (t3.second - t.second)*std::sin(ugao);
        t3.second= t.second + (t3.first - t.first)*std::sin(ugao) + (t3.second - t.second)*std::cos(ugao);
        
    }
    
    void Skaliraj (const Tacka &t, double faktor){
        if(faktor<0) throw std::domain_error("Nekorektan faktor skaliranja");
        
        t1.first= t.first + faktor*(t1.first - t.first);
        t1.second=t.second + faktor*(t1.second - t.second);
        
        t2.first= t.first + faktor*(t2.first - t.first);
        t2.second= t.second + faktor*(t2.second - t.second);
        
        t3.first= t.first + faktor*(t3.first - t.first);
        t3.second= t.second + faktor*(t3.second - t.second);
    }
    
    void Rotiraj (double ugao){
        Tacka t(DajCentar());
        
        t1.first= t.first + (t1.first - t.first)*std::cos(ugao) - (t1.second - t.second)*std::sin(ugao);
        t1.second= t.second + (t1.first - t.first)*std::sin(ugao) + (t1.second - t.second)*std::cos(ugao);
        
        t2.first= t.first + (t2.first - t.first)*std::cos(ugao) - (t2.second - t.second)*std::sin(ugao);
        t2.second= t.second + (t2.first - t.first)*std::sin(ugao) + (t2.second - t.second)*std::cos(ugao);
        
        t3.first= t.first + (t3.first - t.first)*std::cos(ugao) - (t3.second - t.second)*std::sin(ugao);
        t3.second= t.second + (t3.first - t.first)*std::sin(ugao) + (t3.second - t.second)*std::cos(ugao);
    
    }
    
    void Skaliraj (double faktor){
        if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t(DajCentar());
        
        t1.first=t.first + faktor*(t1.first - t.first);
        t1.second=t.second + faktor*(t1.second - t.second);
        
        t2.first= t.first + faktor*(t2.first - t.first);
        t2.second= t.second + faktor*(t2.second - t.second);
        
        t3.first= t.first + faktor*(t3.first - t.first);
        t3.second= t.second + faktor*(t3.second - t.second);
    }
    
    
    friend bool DaLiSuIdenticni (const Trougao &T1, const Trougao &T2);
    friend bool DaLiSuPodudarni (const Trougao &T1, const Trougao &T2);
    friend bool DaLiSuSlicni (const Trougao &T1, const Trougao &T2);
};

bool DaLiSuIdenticni (const Trougao &T1, const Trougao &T2){
    int br(0);
    
   if((Trougao::JesuLiJednaki(T1.t1.first, T2.t1.first) && Trougao::JesuLiJednaki(T1.t1.second, T2.t1.second)) || (Trougao::JesuLiJednaki(T1.t1.first, T2.t2.first) && Trougao::JesuLiJednaki(T1.t1.second, T2.t2.second)) || (Trougao::JesuLiJednaki(T1.t1.first, T2.t3.first) && Trougao::JesuLiJednaki(T1.t1.second, T2.t3.second))){
       br++;
   }
   
   if((Trougao::JesuLiJednaki(T1.t2.first, T2.t1.first) && Trougao::JesuLiJednaki(T1.t2.second, T2.t1.second)) || (Trougao::JesuLiJednaki(T1.t2.first, T2.t2.first) && Trougao::JesuLiJednaki(T1.t2.second, T2.t2.second)) || (Trougao::JesuLiJednaki(T1.t2.first, T2.t3.first) && Trougao::JesuLiJednaki(T1.t2.second, T2.t3.second))){
       br++;
   }
   if((Trougao::JesuLiJednaki(T1.t3.first, T2.t1.first) && Trougao::JesuLiJednaki(T1.t3.second, T2.t1.second)) || (Trougao::JesuLiJednaki(T1.t3.first, T2.t2.first) && Trougao::JesuLiJednaki(T1.t3.second, T2.t2.second)) || (Trougao::JesuLiJednaki(T1.t3.first, T2.t3.first) && Trougao::JesuLiJednaki(T1.t3.second, T2.t3.second))){
       br++;
   }
   
   if(br==3) return true;
   return false;
}

bool DaLiSuPodudarni (const Trougao &T1, const Trougao &T2){
    int br(0);
    
    if(T1.DaLiJePozitivnoOrijenitran()==T2.DaLiJePozitivnoOrijenitran()){
    double a1(T1.DajStranicu(1)), b1(T1.DajStranicu(2)), c1(T1.DajStranicu(3));
    double a2(T2.DajStranicu(1)), b2(T2.DajStranicu(2)), c2(T2.DajStranicu(3));
    
    if(Trougao::JesuLiJednaki(a1, a2) || Trougao::JesuLiJednaki(a1, b2) || Trougao::JesuLiJednaki(a1, c2))
        br++;
    if(Trougao::JesuLiJednaki(b1, a2) || Trougao::JesuLiJednaki(b1, b2) || Trougao::JesuLiJednaki(b1, c2))
        br++;
    if(Trougao::JesuLiJednaki(c1, a2) || Trougao::JesuLiJednaki(c1, b2) || Trougao::JesuLiJednaki(c1, c2))
        br++;
    }
    if(br==3) return true;
    return false;
}

bool DaLiSuSlicni (const Trougao &T1, const Trougao &T2){
    int br(0);
    if(T1.DaLiJePozitivnoOrijenitran()==T2.DaLiJePozitivnoOrijenitran()){
        double alfa1(T1.DajUgao(1)), beta1(T1.DajUgao(2)), gama1(T1.DajUgao(3));
        double alfa2(T2.DajUgao(1)), beta2(T2.DajUgao(2)), gama2(T2.DajUgao(3));
    
    if(Trougao::JesuLiJednaki(alfa1, alfa2) || Trougao::JesuLiJednaki(alfa1, beta2) || Trougao::JesuLiJednaki(alfa1, gama2))
        br++;
    if(Trougao::JesuLiJednaki(beta1, alfa2) || Trougao::JesuLiJednaki(beta1, beta2) || Trougao::JesuLiJednaki(beta1, gama2))
        br++;
    if(Trougao::JesuLiJednaki(gama1, alfa2) || Trougao::JesuLiJednaki(gama1, beta2) || Trougao::JesuLiJednaki(gama1, gama2))
        br++;
    }
    
    if(br==3) return true;
    return false;
}

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> vec;
    int pozicija(0);
    Tacka t1, t2, t3;
    
    for(;;){
        if(pozicija==n) break;
        int j;
        j=pozicija+1;
        std::cout<<"Unesite podatke za "<<j<<". trougao (x1 y1 x2 y2 x3 y3): ";
        
      
        std::cin>>t1.first>>t1.second;
        std::cin>>t2.first>>t2.second;
        std::cin>>t3.first>>t3.second;
     
        if((t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second))==0) {
          std::cout<<"Nekorektne pozicije tjemena, ponovite unos! "<<std::endl;
        }
        
        else{
            Trougao(t1, t2, t3);
            std::shared_ptr<Trougao> PomPok = std::make_shared<Trougao>(t1, t2, t3);
            vec.push_back(PomPok);
            pozicija++;
        }
        
    }
    
    double TranslacijaPoX, TranslacijaPoY;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>TranslacijaPoX>>TranslacijaPoY;
    
    double UgaoRotacije;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>UgaoRotacije;
    
    double FaktorSkaliranja;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>FaktorSkaliranja;

    
    std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;;
    std::transform(vec.begin(), vec.end(), vec.begin(), [TranslacijaPoX, TranslacijaPoY] (std::shared_ptr<Trougao> x) -> std::shared_ptr<Trougao>{ x->Transliraj(TranslacijaPoX, TranslacijaPoY); return x; });
    std::transform(vec.begin(), vec.end(), vec.begin(), [UgaoRotacije](std::shared_ptr<Trougao> x) -> std::shared_ptr<Trougao> { x->Rotiraj(UgaoRotacije); return x;});
    std::transform(vec.begin(), vec.end(), vec.begin(), [FaktorSkaliranja](std::shared_ptr<Trougao> x) -> std::shared_ptr<Trougao> { Tacka Povratna(x->DajTjeme(1)); x->Skaliraj(Povratna, FaktorSkaliranja); return x;});
    
    
    std::sort(vec.begin(), vec.end(), [](std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y) -> bool{ return x->DajPovrsinu()>y->DajPovrsinu(); });
    std::for_each(vec.begin(), vec.end(), [](std::shared_ptr<Trougao> x) -> std::shared_ptr<Trougao>{ x->Ispisi(); std::cout<<std::endl; return x; });
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    std::shared_ptr<Trougao> pok(*std::max_element(vec.begin(), vec.end(), [](std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y) -> bool{ x->DajObim(); y->DajObim(); return x<y; }));
    pok->Ispisi(); std::cout<<std::endl;
    
    std::cout<<"Parovi identicnih trouglova:"<<std::endl;
    int PomBr(0);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuIdenticni(*vec[i], *vec[j])==true){
                vec[i]->Ispisi(); std::cout<<" i "; vec[j]->Ispisi();
                std::cout<<std::endl;
                PomBr++;
            }
        }
    }
    
    if(PomBr==0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
    
    std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
    int PomBr1(0);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuPodudarni(*vec[i], *vec[j])==true){
                vec[i]->Ispisi(); std::cout<<" i "; vec[j]->Ispisi();
                std::cout<<std::endl;
                PomBr1++;
            }
        }
    }
    
    if(PomBr1==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    
    std::cout<<"Parovi slicnih trouglova:"<<std::endl;
    int PomBr2(0);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuSlicni(*vec[i], *vec[j])==true){
                vec[i]->Ispisi(); std::cout<<" i "; vec[j]->Ispisi();
                std::cout<<std::endl;
                PomBr2++;
            }
        }
    }
    
    if(PomBr2==0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
    
    
	return 0;
}