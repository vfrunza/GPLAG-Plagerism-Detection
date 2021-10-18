/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <memory>
#define PI 3.14159265358979323846

typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka T1, T2, T3;
    static bool JesuLiJednaki(double x, double y, double Eps=1e-10){
        return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
    }
    
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi(int indeks, const Tacka &t);
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        Tacka DajTjeme(int indeks) const;
        double DajStranicu(int indeks) const;
        double DajUgao(int indeks) const;
        Tacka DajCentar() const;
        double DajObim() const;
        double DajPovrsinu() const;
        bool DaLiJePozitivnoOrijentiran() const;
        bool DaLiJeUnutra(const Tacka &t) const;
        void Ispisi() const;
        void Transliraj(double delta_x, double delta_y);
        void Centriraj(const Tacka &t);
        void Rotiraj(const Tacka &t, double ugao);
        void Skaliraj(const Tacka &t, double faktor);
        void Rotiraj(double ugao);
        void Skaliraj(double faktor);
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
//pomocna fija koja ispituje kolinearnost tacaka
double UslovKolinearnosti(Tacka t1, Tacka t2, Tacka t3){
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}
//implementacija kontruktora-isto tijelo kao i metoda Postavi
Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    Postavi(t1, t2, t3);
}
//prva verzija metode Postavi
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(JesuLiJednaki(UslovKolinearnosti(t1, t2, t3), 0))throw std::domain_error("Nekorektne pozicije tjemena");
    T1=t1;
    T2=t2;
    T3=t3;
}
//druga verzija metode Postavi
void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    DajTjeme(indeks)=t;
    if(JesuLiJednaki(UslovKolinearnosti(T1, T2, T3), 0)) throw std::domain_error("Nekorektne pozicije tjemena");
}

//pozitivna return 1;/ negativna return -1;/ tacke kolinearne return 0;
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(JesuLiJednaki(UslovKolinearnosti(t1, t2, t3), 0)) return 0;
    if(UslovKolinearnosti(t1, t2, t3)>0) return 1;
    return -1;
}

Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    if(indeks==1) return T1;
    else if(indeks==2) return T2;
    else return T3;
}

double Trougao::DajStranicu(int indeks) const{
     if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
     if(indeks==1){
         return std::sqrt((T3.first-T2.first)*(T3.first-T2.first)+(T3.second-T2.second)*(T3.second-T2.second));
     }
     else if(indeks==2){
         return std::sqrt((T3.first-T1.first)*(T3.first-T1.first)+(T3.second-T1.second)*(T3.second-T1.second));
     }
     else{
         return std::sqrt((T2.first-T1.first)*(T2.first-T1.first)+(T2.second-T1.second)*(T2.second-T1.second));
     }
}

double Trougao::DajUgao(int indeks) const{
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    double ugao;
    if(indeks==1){
        ugao=acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(3)*DajStranicu(2)))*PI/180;
    }
    else if(indeks==2){
         ugao=acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(3)*DajStranicu(1)))*PI/180;
    }
    else {
         ugao=acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)))*PI/180;
    }
    return ugao;
}

Tacka Trougao::DajCentar() const{
    Tacka teziste;
    teziste.first=(T1.first+T2.first+T3.first)/3;
    teziste.second=(T1.second+T2.second+T3.second)/3;
    return teziste;
}

double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}

double Trougao::DajPovrsinu() const{
    return (1./2)*std::fabs(UslovKolinearnosti(T1, T2, T3));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(T1, T2, T3)==1) return true;
    else return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if(Orijentacija(T1, T2, T3)==-1 && Orijentacija(T1, T2, t)==1 && Orijentacija(T2, T3, t)==1 && Orijentacija(T3, T1, t)==1){
        return true;
    }
    if(Orijentacija(T1, T2, T3)==-1 && Orijentacija(T1, T2, t)==-1 && Orijentacija(T2, T3, t)==-1 && Orijentacija(T3, T1, t)==-1){
        return true;
    }
    return false;
}

void Trougao::Ispisi() const{
    std::cout<<"(("<<T1.first<<","<<T1.second<<"),("<<T2.first<<","<<T2.second<<"),("<<T3.first<<","<<T3.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y){
    T1.first+=delta_x;
    T1.second+=delta_y;
    
    T2.first+=delta_x;
    T2.second+=delta_y;
    
    T3.first+=delta_x;
    T3.second+=delta_y;
}

//specijalan slucaj translacije
void Trougao::Centriraj(const Tacka &t){
    T1.first+=t.first-DajCentar().first;
    T1.second+=t.second-DajCentar().second;
    
    T2.first+=t.first-DajCentar().first;
    T2.second+=t.second-DajCentar().second;
    
    T3.first+=t.first-DajCentar().first;
    T3.second+=t.second-DajCentar().second;
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    double temp1, temp2, temp3;
    
    temp1=T1.first;
    temp2=T2.first;
    temp3=T3.first;
    
    T1.first=t.first+(T1.first-t.first)*cos(ugao)-(T1.second-t.second)*sin(ugao);
    T1.second=t.second+(temp1-t.first)*sin(ugao)+(T1.second-t.second)*cos(ugao);
    
    T2.first=t.first+(T2.first-t.first)*cos(ugao)-(T2.second-t.second)*sin(ugao);
    T2.second=t.second+(temp2-t.first)*sin(ugao)+(T2.second-t.second)*cos(ugao);
    
    T3.first=t.first+(T3.first-t.first)*cos(ugao)-(T3.second-t.second)*sin(ugao);
    T3.second=t.second+(temp3-t.first)*sin(ugao)+(T3.second-t.second)*cos(ugao);
    
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(JesuLiJednaki(faktor, 0)) throw std::domain_error("Nekorektan faktor skaliranja");
    
    T1.first=t.first+faktor*(T1.first-t.first);
    T1.second=t.second+faktor*(T1.second-t.second);
    
    T2.first=t.first+faktor*(T2.first-t.first);
    T2.second=t.second+faktor*(T2.second-t.second);
    
    T3.first=t.first+faktor*(T3.first-t.first);
    T3.second=t.second+faktor*(T3.second-t.second);
    
    if(faktor<0) Rotiraj(180);
}

void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(), ugao);
}

void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(), faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    std::vector<std::pair<double, double>> v{t1.T1, t1.T2, t1.T3};
    std::vector<std::pair<double, double>> k{t2.T1, t2.T2, t2. T3};
    int n(0);
    std::vector<std::pair<double, double>> p;
    for(int i=0;i<3;i++){
       for(int j=0;j<3;j++){
           if(Trougao::JesuLiJednaki(v[i].first, k[j].first) && Trougao::JesuLiJednaki(v[i].second, k[j].second)){
               n++;
           }
       }
    }
    if(n==3) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::vector<Tacka> p, d;
    bool podudarni(false);
       int stranice(0), uglovi(0);
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(Trougao::JesuLiJednaki(t1.DajStranicu(i), t2.DajStranicu(j))){ stranice++;}
                    if(Trougao::JesuLiJednaki(t1.DajUgao(i), t2.DajUgao(j))) { uglovi++; p.push_back(t1.DajTjeme(i)); d.push_back(t2.DajTjeme(j));}
                }
            }
            if(uglovi>=3 && stranice>=3 && Trougao::JesuLiJednaki(t1.Orijentacija(p[0], p[1], p[2]), t2.Orijentacija(d[0], d[1], d[2]))){
               podudarni=true;
            }
        
    return podudarni;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    
    bool slicni(false);
    std::vector<Tacka> p, d;
    int uglovi(0);
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(Trougao::JesuLiJednaki(t1.DajUgao(i), t2.DajUgao(j))) { uglovi++; p.push_back(t1.DajTjeme(i)); d.push_back(t2.DajTjeme(j));}
                }
            }
            if(uglovi>=3 && Trougao::JesuLiJednaki(t1.Orijentacija(p[0], p[1], p[2]), t2.Orijentacija(d[0], d[1], d[2]))){
               slicni=true;
            }
    return slicni;
}
//pomocna fija koja racuna udaljenost izmedju dvije tacke
double dd(Tacka A, Tacka B){
    double dx=A.first-B.first;
    double dy=A.second-B.second;
    return std::sqrt(dx*dx+dy*dy);
}

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    if(n>0) 
    {
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i=0;i<n;i++){
        Tacka A, B, C;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>A.first>>A.second>>B.first>>B.second>>C.first>>C.second;
        try{
            v[i]=std::make_shared<Trougao>(Trougao(A, B, C));
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin>>dx>>dy;
    
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    
    std::cout<<"Unesite faktor skaliranja: ";
    double f;
    std::cin>>f;
   
    std::transform(v.begin(), v.end(), v.begin(), [dx, dy](std::shared_ptr<Trougao> t){ t->Transliraj(dx, dy); return t; });
    std::transform(v.begin(), v.end(), v.begin(), [ugao](std::shared_ptr<Trougao> t){ t->Rotiraj(ugao); return t; });
    std::transform(v.begin(), v.end(), v.begin(), [f](std::shared_ptr<Trougao> t){ t->Skaliraj(t->DajTjeme(1),f); return t;});
    
    
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> prvi, std::shared_ptr<Trougao> drugi){return prvi->DajPovrsinu()<drugi->DajPovrsinu();});
    
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t){t->Ispisi();std::cout<<std::endl;});
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*std::min_element(v.begin(), v.end(),[](std::shared_ptr<Trougao> prvi, std::shared_ptr<Trougao> drugi){return prvi->DajObim()<drugi->DajObim();}))->Ispisi();
    std::cout<<std::endl;
    
        bool k(false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuIdenticni(*v[i], *v[j])){
                    k=true;
                }
            }
        }
        if(!k) std::cout<<"Nema identicnih trouglova!"<<std::endl;
        else{
            std::cout<<"Parovi identicnih trouglova:"<<std::endl;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(DaLiSuIdenticni(*v[i], *v[j])){
                        v[i]->Ispisi();
                        std::cout<<" i ";
                        v[j]->Ispisi();
                        std::cout<<std::endl;
                    }
                }
            }
        }
        bool b(false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuPodudarni(*v[i], *v[j])){
                    b=true;
                }
            }
        }
        if(!b) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
        else{
            std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(DaLiSuPodudarni(*v[i], *v[j])){
                        v[i]->Ispisi();
                        std::cout<<" i ";
                        v[j]->Ispisi();
                        std::cout<<std::endl;
                    }
                }
            }
            
        }
   
        bool g(false);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuSlicni(*v[i], *v[j])){
                   g=true;
                }
            }
        }
        if(!g) std::cout<<"Nema slicnih trouglova!"<<std::endl;
        else{
             std::cout<<"Parovi slicnih trouglova:"<<std::endl;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    if(DaLiSuSlicni(*v[i], *v[j])){
                        v[i]->Ispisi();
                        std::cout<<" i ";
                        v[j]->Ispisi();
                        std::cout<<std::endl;
                    }
                }
            }
        }
        
    }
    
	return 0;
}