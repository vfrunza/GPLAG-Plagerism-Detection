/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <vector>

typedef std::pair<double,double> Tacka;


class Trougao{
    Tacka x, y, z;
   
    static double fun(const Tacka &t1, const Tacka &t2, const Tacka &t3){
       return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second); 
    }
    
    static bool JesuLiJednaki(double x, double y, double Eps=1e-10){
        return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
    }
   
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
       double temp(fun(t1,t2,t3));
        if(temp<0 && JesuLiJednaki(temp,0)==false) return -1;
        if(temp>0 && JesuLiJednaki(temp,0)==false) return 1;
        return 0;
    }
   
    public:
    
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const { return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); } 
    double DajPovrsinu() const { return (1./2.)*std::fabs(fun(x,y,z)); }
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra (const Tacka &t) const;
    void Ispisi () const;
    void Transliraj(double delta_x,  double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj (const Tacka &t, double ugao);
    void Skaliraj (const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    x=t1; y=t2; z=t3;
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    x=t1; y=t2; z=t3;
}

void Trougao::Postavi(int indeks, const Tacka &t){
    if((indeks==1 || indeks==2 || indeks==3)==false) throw std::range_error("Nekorektan indeks");
    if(indeks==1 && Orijentacija(t,y,z)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    if(indeks==2 && Orijentacija(x,t,z)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    if(indeks==3 && Orijentacija(x,y,t)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    
    if(indeks==1) x=t;
    if(indeks==2) y=t;
    if(indeks==3) z=t;
}

Tacka Trougao::DajTjeme(int indeks)const {
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
    if(indeks==1) return x;
    if(indeks==2) return y;
    return z;
}

double Trougao::DajStranicu(int indeks)const{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return std::sqrt((y.first-z.first)*(y.first-z.first)+(y.second-z.second)*(y.second-z.second));
    if(indeks==2) return std::sqrt((x.first-z.first)*(x.first-z.first)+(x.second-z.second)*(x.second-z.second));
                  return std::sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
}

double Trougao::DajUgao(int indeks) const{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return std::acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
    if(indeks==2) return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
                  return std::acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
}

Tacka Trougao::DajCentar() const{
    Tacka t;
    t.first=(x.first+y.first+z.first)/3;
    t.second=(x.second+y.second+z.second)/3;
    return t;
}

bool Trougao::DaLiJePozitivnoOrijentiran()const{
    if(Orijentacija(x,y,z)==1) return true;
    return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    return (Orijentacija(x,y,z)==Orijentacija(x,y,t) && Orijentacija(x,y,z)==Orijentacija(y,z,t) && Orijentacija(x,y,z)==Orijentacija(z,x,t));
}

void Trougao::Ispisi() const{
    std::cout<<"(("<<x.first<<","<<x.second<<"),("<<y.first<<","<<y.second<<"),("<<z.first<<","<<z.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y){
    x.first+=delta_x; y.first+=delta_x; z.first+=delta_x;
    x.second+=delta_y; y.second+=delta_y; z.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    Tacka temp(DajCentar());
    Transliraj(t.first-temp.first, t.second-temp.second);
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    Tacka temp(x);
    x.first=t.first+(temp.first-t.first)*std::cos(ugao)-(temp.second-t.second)*std::sin(ugao);
    x.second=t.second+(temp.first-t.first)*std::sin(ugao)+(temp.second-t.second)*std::cos(ugao);
    temp=y;
    y.first=t.first+(temp.first-t.first)*std::cos(ugao)-(temp.second-t.second)*std::sin(ugao);
    y.second=t.second+(temp.first-t.first)*std::sin(ugao)+(temp.second-t.second)*std::cos(ugao);
    temp=z;
    z.first=t.first+(temp.first-t.first)*std::cos(ugao)-(temp.second-t.second)*std::sin(ugao);
    z.second=t.second+(temp.first-t.first)*std::sin(ugao)+(temp.second-t.second)*std::cos(ugao);
}

void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(), ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(JesuLiJednaki(faktor,0)) throw std::domain_error ("Nekorektan faktor skaliranja");
    bool potrebna_rotacija(false);
    if(faktor<0 && !JesuLiJednaki(faktor,0)) { potrebna_rotacija=true; faktor=faktor*(-1);}
    
    Tacka temp(x);
    x.first=t.first+faktor*(temp.first-t.first); x.second=t.second+faktor*(temp.second-t.second);
    temp=y;
    y.first=t.first+faktor*(temp.first-t.first); y.second=t.second+faktor*(temp.second-t.second);
    temp=z;
    z.first=t.first+faktor*(temp.first-t.first); z.second=t.second+faktor*(temp.second-t.second);
    
    if(potrebna_rotacija) Rotiraj(t, std::atan(1)*4 );
}

void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(), faktor);
}

bool JesuLiIdenticni(double x, double y, double Eps=1e-10){
    return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    Tacka c1(t1.DajCentar()), c2(t2.DajCentar());
    if(!Trougao::JesuLiJednaki(c1.first,c2.first) || !Trougao::JesuLiJednaki(c1.first,c2.first) || !Trougao::JesuLiJednaki(c1.first,c2.first) ||
      !Trougao::JesuLiJednaki(c1.second,c2.second) || !Trougao::JesuLiJednaki(c1.second, c2.second) || !Trougao::JesuLiJednaki(c1.second,c2.second)) return false;
      
    std::vector<Tacka> tr1{t1.x, t1.y, t1.z}, tr2{t2.x,t2.y,t2.z};
    
    std::sort(tr1.begin(),tr1.end(), [](Tacka a, Tacka b){ if(JesuLiIdenticni(a.first,b.first)) return a.second<b.second && !JesuLiIdenticni(a.second,b.second);
                                                        return a.first<b.first && !JesuLiIdenticni(a.first,b.first); });
    std::sort(tr2.begin(),tr2.end(), [](Tacka a, Tacka b){ if(JesuLiIdenticni(a.first,b.first)) return a.second<b.second && !JesuLiIdenticni(a.second,b.second);
                                                        return a.first<b.first && !JesuLiIdenticni(a.first,b.first); }); 
     
    for(int i(0); i<3; i++){
        if(!JesuLiIdenticni(tr1.at(i).first,tr2.at(i).first) ||!JesuLiIdenticni(tr1.at(i).second,tr2.at(i).second)) return false;
    } 
    return true;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::vector<double> s1{t1.DajStranicu(1),t1.DajStranicu(2), t1.DajStranicu(3)}, s2={t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)}, s1c(s1), s2c(s2);
    std::sort(s1c.begin(), s1c.end(), [](double x, double y){return (x<y && !JesuLiIdenticni(x,y));}); 
    std::sort(s2c.begin(), s2c.end(), [](double x, double y){return (x<y && !JesuLiIdenticni(x,y)); });
    
    for(int i(0); i<3; i++ ){
        if(JesuLiIdenticni(s1c.at(i),s2c.at(i))==false) return false;
    } 
    
    if(t1.Orijentacija(t1.x,t1.y,t1.z)!=t2.Orijentacija(t2.x,t2.y,t2.z)) {
        std::reverse(s2.begin(), s2.end());
    }

    int brojac(0);
    
    if(JesuLiIdenticni(s1.at(0),s2.at(0))){
        for(int i(0); i<3; i++){
            if(JesuLiIdenticni(s1.at(i), s1.at(i))) brojac++;
            else break;
        }
        if(brojac==3) return true;
    }
    brojac=0;
    if(JesuLiIdenticni(s1.at(0),s2.at(1))){
        for(int i(0), j(1); i<3; i++, j++){
            if(JesuLiIdenticni(s1.at(i),s2.at(j))) brojac++;
            else break;
            if(j==2) j=-1;
        }
        if(brojac==3) return true;
    }
    brojac=0;
    if(JesuLiIdenticni(s1.at(0),s2.at(2))){
        for(int i(0), j(2); i<3; i++,j++){
            if(JesuLiIdenticni(s1.at(i),s2.at(j))) brojac++;
            else break;
            if(j==2) j=-1;
        }
        if(brojac==3) return true;
    }
    
    
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::vector<double> s1{t1.DajStranicu(1), t1.DajStranicu(2), t1.DajStranicu(3)}, s2={t2.DajStranicu(1), t2.DajStranicu(2), t2.DajStranicu(3)};
    std::sort(s1.begin(), s1.end(), [](double x, double y) {return x<y && !JesuLiIdenticni(x,y);} );
    std::sort(s2.begin(), s2.end(), [](double x, double y) {return x<y && !JesuLiIdenticni(x,y);});
    
     if((JesuLiIdenticni(s1.at(0)/s2.at(0), s1.at(1)/s2.at(1)) && JesuLiIdenticni(s1.at(1)/s2.at(1), s1.at(2)/s2.at(2)) && JesuLiIdenticni(s1.at(0)/s2.at(0), s1.at(2)/s1.at(2)))==false ) return false;
     
     double faktor(s1.at(0)/s2.at(0));
     
    Trougao temp(t1.x,t1.y,t1.z);
    temp.Skaliraj(faktor);
    
    if(DaLiSuPodudarni(temp,t2)) return true;
   
    
    return false;
}

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    
    std::vector<std::shared_ptr<Trougao>> v;
    
    for(int i(0); i<n; i++){
        double x1, x2,y1,y2,z1,z2;
        
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>x1>>x2>>y1>>y2>>z1>>z2;
        Tacka x(x1,x2),y(y1,y2), z(z1,z2);
        
        try{
            auto trougao(std::make_shared<Trougao>(x,y,z));
            v.push_back(trougao);
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    double delta_x , delta_y;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>delta_x>>delta_y;
    double ugao;
    std::cout<<"Unesite ugao rotacije: ";
    double faktor;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    
    try{
    std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y, ugao,faktor](std::shared_ptr<Trougao> t){ 
                                                    t->Transliraj(delta_x,delta_y);
                                                    
                                                    t->Rotiraj(ugao);
                                                    
                                                    t->Skaliraj(t->DajTjeme(1),faktor);
                                                    return t;});
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
     
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2) { return t1->DajPovrsinu()<t2->DajPovrsinu() && !JesuLiIdenticni(t1->DajPovrsinu(),t2->DajPovrsinu())  ; });
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t){ t->Ispisi(); std::cout<<std::endl; } );
   
   auto it(std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){ return t1->DajObim()<t2->DajObim()  && !JesuLiIdenticni(t1->DajObim(), t2->DajObim()) ;}));
    auto t(*it);
   
    std::cout<<"Trougao sa najmanjim obimom: ";
     t->Ispisi();std::cout<<std::endl;
    
    
    bool nije_ispisano(true), prvi_ispis(true);
    for(int i(0); i<n; i++){
        for(int j(i+1); j<n; j++){
            if( DaLiSuIdenticni(*(v.at(i)),*(v.at(j))) ) {
                if(prvi_ispis){ std::cout<<"Parovi identicnih trouglova:"; prvi_ispis=false;}
               std::cout<<std::endl; v.at(i)->Ispisi(); std::cout<<" i "; v.at(j)->Ispisi() ;
               nije_ispisano=false;
            }
        }
    }
    if(nije_ispisano) std::cout<<"Nema identicnih trouglova!"<<std::endl;
    nije_ispisano=true; prvi_ispis=true;
    
    for(int i(0); i<n; i++){
        for(int j(i+1); j<n; j++){
            if(DaLiSuPodudarni(*(v.at(i)), *(v.at(j)) ) ){
                if(prvi_ispis) {std::cout<<std::endl<<"Parovi podudarnih trouglova:"; prvi_ispis=false;}
                std::cout<<std::endl; v.at(i)->Ispisi(); std::cout<<" i "; v.at(j)->Ispisi();
                nije_ispisano=false;
            }
        }
    }
    if(nije_ispisano) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    
    nije_ispisano=true; prvi_ispis=true;
   
    for(int i(0); i<n; i++){
        for(int j(i+1); j<n; j++){
            
            if(DaLiSuSlicni( *(v.at(i)), *(v.at(j)) )){
                if(prvi_ispis) { std::cout<<std::endl<<"Parovi slicnih trouglova:"; prvi_ispis=false;}
               std::cout<<std::endl; v.at(i)->Ispisi(); std::cout<<" i "; v.at(j)->Ispisi();
                nije_ispisano=false;
            }
        }
    }
    
    if(nije_ispisano) std::cout<<"Nema slicnih trouglova!";
	return 0;
}