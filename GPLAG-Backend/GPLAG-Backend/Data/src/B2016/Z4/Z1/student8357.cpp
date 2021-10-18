#include <iostream>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <memory>
#include<algorithm>
#include<cmath>

typedef std::pair<double, double> Tacka;  

const double PI=4*atan(1);
class Trougao{
   Tacka t1,t2,t3; 
   static double pomocna (Tacka t1, Tacka t2, Tacka t3){
       return { t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second) };
   }
   static bool uporedjivanje (double a, double b, double eps=1e-10){
       return std::fabs(a-b) <= eps* (std::fabs(a) + std::fabs(b));
   }
   static bool sortiranje(double a, double b) {return a<b;}
  public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks!=1 || indeks!=2 || indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) Trougao::t1=t;
        if(indeks==2) Trougao::t2=t;
        if(indeks==3) Trougao::t3=t;
    }
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

     

int Trougao::Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(pomocna(t1,t2,t3)<0) return -1;
    if(pomocna(t1,t2,t3)==0) return 0;
    if(pomocna(t1,t2,t3)>0) return 1;
}

Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks==1) return t1;
    if(indeks==2) return t2;
    if(indeks==3) return t3;
}

double Trougao::DajStranicu(int indeks) const{
    double duzina;
    if(indeks==1){
       duzina=sqrt((t2.first-t3.first)*(t2.first-t3.first) + (t2.second-t3.second)*(t2.second-t3.second)); 
    }
    if(indeks==2){
       duzina=sqrt((t1.first-t3.first)*(t1.first-t3.first) + (t1.second-t3.second)*(t1.second-t3.second)); 
    }
    if(indeks==3){
        duzina=sqrt((t1.first-t2.first)*(t1.first-t2.first) + (t1.second-t2.second)*(t1.second-t2.second));
    }
    return duzina;
}

double Trougao::DajUgao(int indeks) const {
    double ugao;
    if(indeks==1){ // alfa
        ugao=acos ( (DajStranicu(2)*DajStranicu(2)+ DajStranicu(3)*DajStranicu(3) - DajStranicu(1)*DajStranicu(1)) / (2*DajStranicu(2)*DajStranicu(3)) );
    }
    if(indeks==2){ //beta
        ugao= acos( (DajStranicu(1)*DajStranicu(1) + DajStranicu(3)*DajStranicu(3)- DajStranicu(2)*DajStranicu(2)) / (2*DajStranicu(1)*DajStranicu(3)) );
    }
    if(indeks==3){ //gama
        ugao=acos( (DajStranicu(1)*DajStranicu(1) + DajStranicu(2)*DajStranicu(2) - DajStranicu(3)*DajStranicu(3)) / (2*DajStranicu(1)*DajStranicu(2)) );
    }
    return ugao;
}

Tacka Trougao::DajCentar()const{
    Tacka teziste;
    teziste.first= (t1.first + t2.first + t3.first)/3;
    teziste.second= (t1.second + t2.second + t3.second)/3;
    return teziste;
}

double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}

double Trougao::DajPovrsinu()const {
    double p= 1./2* abs (Trougao::pomocna(t1,t2,t3));
    return p;
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    bool jeste=false;
    if(Orijentacija(this->t1, this->t2, this->t3)==1) jeste=true;
    return jeste;
}


bool Trougao::DaLiJeUnutra (const Tacka &t) const{
    if((Orijentacija(t1,t2,t3)==1 && Orijentacija(t1,t2,t)==1 && Orijentacija(t2,t3,t)==1 && Orijentacija(t3,t1,t)==1) || (Orijentacija(t1,t2,t3)==-1 && Orijentacija(t1,t2,t)==-1 && Orijentacija(t2,t3,t)==-1 && Orijentacija(t3,t1,t)==-1)) return true;
    return false;
}

void Trougao::Ispisi () const{
    std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y){
    t1.first+=delta_x; t1.second+=delta_y;
    t2.first+=delta_x; t2.second+=delta_y;
    t3.first+=delta_x; t3.second+=delta_y;
}

void Trougao::Centriraj (const Tacka &t){
    Tacka a=DajCentar();
    double delta_x=t.first-a.first;
    double delta_y=t.second-a.second;
    t1.first+=delta_x; t1.second+=delta_y;
    t2.first+=delta_x; t2.second+=delta_y;
    t3.first+=delta_x; t3.second+=delta_y;
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    t1.first=t.first +(t1.first-t.first)*cos (ugao) - (t1.second-t.second)*sin(ugao);
    t1.second=t.second + (t1.first-t.first)*sin(ugao) + (t1.second-t.second)*cos(ugao);
    
    t2.first=t.first +(t2.first-t.first)*cos (ugao) - (t2.second-t.second)*sin(ugao);
    t2.second=t.second + (t2.first-t.first)*sin(ugao) + (t2.second-t.second)*cos(ugao);
    
    t3.first=t.first +(t3.first-t.first)*cos (ugao) - (t3.second-t.second)*sin(ugao);
    t3.second=t.second + (t3.first-t.first)*sin(ugao) + (t3.second-t.second)*cos(ugao);
}

void Trougao::Skaliraj (const Tacka &t, double faktor){
    if(Trougao::uporedjivanje(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
    
    if(t.first==t1.first && t.second==t1.second){
        t2.first=t.first + faktor*(t2.first - t.first);
        t2.second=t.second + faktor*(t2.second-t.second);
        t3.first=t.first + faktor*(t3.first - t.first);
        t3.second=t.second + faktor*(t3.second-t.second);
    }
    
    if(t.first==t2.first && t.second==t2.second){
        t1.first=t.first + faktor*(t1.first - t.first);
        t1.second=t.second + faktor*(t1.second-t.second);
        t3.first=t.first + faktor*(t3.first - t.first);
        t3.second=t.second + faktor*(t3.second-t.second);
    }
    
    if(t.first==t3.first && t.second==t3.second){
        t1.first=t.first + faktor*(t1.first - t.first);
        t1.second=t.second + faktor*(t1.second-t.second);
        t2.first=t.first + faktor*(t2.first - t.first);
        t2.second=t.second + faktor*(t2.second-t.second);
    }
    /*if(t!=t1){
        t1.first=t.first + faktor*(t1.first - t.first);
        t1.second=t.second + faktor*(t1.second-t.second);
    }
    else if(t!=t2){
        t2.first=t.first + faktor*(t2.first - t.first);
        t2.second=t.second + faktor*(t2.second-t.second);
    }
    else if(t!=t3){
        t3.first=t.first + faktor*(t3.first - t.first);
        t3.second=t.second + faktor*(t3.second-t.second);
    }*/
}


void Trougao::Rotiraj(double ugao){
   const Tacka &t=DajCentar();
 
    t1.first=t.first +(t1.first-t.first)*cos (ugao) - (t1.second-t.second)*sin(ugao);
    t1.second=t.second + (t1.first-t.first)*sin(ugao) + (t1.second-t.second)*cos(ugao);
    
    t2.first=t.first +(t2.first-t.first)*cos (ugao) - (t2.second-t.second)*sin(ugao);
    t2.second=t.second + (t2.first-t.first)*sin(ugao) + (t2.second-t.second)*cos(ugao);
    
    t3.first=t.first +(t3.first-t.first)*cos (ugao*180/PI) - (t3.second-t.second)*sin(ugao);
    t3.second=t.second + (t3.first-t.first)*sin(ugao*180/PI) + (t3.second-t.second)*cos(ugao);
}

void Trougao::Skaliraj(double faktor){
    const Tacka &t=DajCentar();
    if(Trougao::uporedjivanje(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
    t1.first=t.first + faktor*(t1.first - t.first);
    t1.second=t.second + faktor*(t1.second-t.second);
    
    t2.first=t.first + faktor*(t2.first - t.first);
    t2.second=t.second + faktor*(t2.second-t.second);
    
    t3.first=t.first + faktor*(t3.first - t.first);
    t3.second=t.second + faktor*(t3.second-t.second);
}

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2){
    if((t1.t1==t2.t1 || t1.t1==t2.t2 || t1.t1==t2.t3) && (t1.t2==t2.t1 || t1.t2==t2.t2 || t1.t2==t2.t3) && (t1.t3==t2.t1 || t1.t3==t2.t2 || t1.t3==t2.t3)) return true;
    return false;
}

bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2){
    double O1=t1.DajObim(), O2=t2.DajObim();
    int o1=Trougao::Orijentacija(t1.t1,t1.t2,t1.t3);
    int o2=Trougao::Orijentacija(t2.t1,t2.t2,t2.t3);
    if(Trougao::uporedjivanje(O1,O2)){
        if(o1==o2){
            if((Trougao::uporedjivanje(t1.DajUgao(1), t2.DajUgao(3)) && Trougao::uporedjivanje(t1.DajUgao(2), t2.DajUgao(1))) || (Trougao::uporedjivanje(t1.DajUgao(1),t2.DajUgao(1)) && Trougao::uporedjivanje(t1.DajUgao(2), t2.DajUgao(2))) || (Trougao::uporedjivanje(t1.DajUgao(1),t2.DajUgao(2)) && Trougao::uporedjivanje(t1.DajUgao(2),t2.DajUgao(3)))) return true;
        }
        if(o1!=o2){
            if((Trougao::uporedjivanje(t1.DajUgao(1), t2.DajUgao(1)) && Trougao::uporedjivanje(t1.DajUgao(2), t2.DajUgao(3))) || (Trougao::uporedjivanje(t1.DajUgao(3),t2.DajUgao(3)) && Trougao::uporedjivanje(t1.DajUgao(1), t2.DajUgao(2))) || (Trougao::uporedjivanje(t1.DajUgao(2),t2.DajUgao(2)) && Trougao::uporedjivanje(t1.DajUgao(1),t2.DajUgao(3)))) return true;
        }
    }
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::vector<double>v1, v2;
    v1.push_back(t1.DajStranicu(1)); v1.push_back(t1.DajStranicu(2)); v1.push_back(t1.DajStranicu(3));
    v2.push_back(t2.DajStranicu(1)); v2.push_back(t2.DajStranicu(2)); v2.push_back(t2.DajStranicu(3));
    std::sort(v1.begin(),v1.end(),Trougao::sortiranje);
    std::sort(v2.begin(),v2.end(),Trougao::sortiranje);
    
    double a,b,c;
    a=v1[0]-v2[0]; b=v1[1]-v2[1]; c=v1[2]-v2[2];
    
    int o1=Trougao::Orijentacija(t1.t1,t1.t2,t1.t3);
    int o2=Trougao::Orijentacija(t2.t1,t2.t2,t2.t3);
    
   // if(a==b==c){
        if(Trougao::uporedjivanje(o1,o2)){
            if((Trougao::uporedjivanje(t1.DajUgao(1), t2.DajUgao(3)) && Trougao::uporedjivanje(t1.DajUgao(2), t2.DajUgao(1))) || (Trougao::uporedjivanje(t1.DajUgao(1),t2.DajUgao(1)) && Trougao::uporedjivanje(t1.DajUgao(2), t2.DajUgao(2))) || (Trougao::uporedjivanje(t1.DajUgao(1),t2.DajUgao(2)) && Trougao::uporedjivanje(t1.DajUgao(2),t2.DajUgao(3)))) return true;
        }
        if(!Trougao::uporedjivanje(o1,o2)){
            if((Trougao::uporedjivanje(t1.DajUgao(1), t2.DajUgao(1)) && Trougao::uporedjivanje(t1.DajUgao(2), t2.DajUgao(3))) || (Trougao::uporedjivanje(t1.DajUgao(3),t2.DajUgao(3)) && Trougao::uporedjivanje(t1.DajUgao(1), t2.DajUgao(2))) || (Trougao::uporedjivanje(t1.DajUgao(2),t2.DajUgao(2)) && Trougao::uporedjivanje(t1.DajUgao(1),t2.DajUgao(3)))) return true;
        }
    //}
    return false;
}

int main ()
{
   int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>>v;
    std::pair<double , double > A,B,C;
    for(int i=0;i<n;i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        try{
            double a,b,c,d,e,f;
            std::cin>>a>>b>>c>>d>>e>>f;
            A=std::make_pair(a,b);
            B=std::make_pair(c,d);
            C=std::make_pair(e,f);
            std::shared_ptr<Trougao> t (new Trougao(A,B,C));
            v.push_back(t);
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<", ponovite unos!\n";
            i--;
        }
    }
        std::cout<<"Unesite vektor translacije (dx dy): ";
        double dx,dy,ugao,faktor;
        std::cin>>dx>>dy;
        std::cout<<"Unesite ugao rotacije: ";
        std::cin>>ugao;
        std::cout<<"Unesite faktor skaliranja: ";
        try{
        std::cin>>faktor;
        }
        catch(std::domain_error e){
            std::cout<<e.what();
        }
      
      std::transform(v.begin(), v.end(), v.begin(), [dx,dy,ugao,faktor](const std::shared_ptr<Trougao> &t){
           t->Transliraj(dx,dy);
           t->Rotiraj(ugao);
           t->Skaliraj(t->DajTjeme(1),faktor);
           return t;
      });
      
        std::sort(v.begin(), v.end(), [] (const std::shared_ptr<Trougao>&t1, const std::shared_ptr<Trougao>&t2){
           return t1->DajPovrsinu() < t2->DajPovrsinu();
        });
        
        std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
        std::for_each(v.begin(), v.end(), [] (const std::shared_ptr<Trougao> &t){
            t->Ispisi();
            std::cout<<std::endl;
        });
        
        std::cout<<"Trougao sa najmanjim obimom: ";
        auto t =std::min_element(v.begin(),v.end(),[](const std::shared_ptr<Trougao>&t1, const std::shared_ptr<Trougao>&t2){
           return t1->DajObim() < t2->DajObim();
       });
       
       (*t)->Ispisi();
        int brojac=0;
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuIdenticni(*v[i],*v[j])==true) brojac++;
            }
         }
        if(brojac!=0){
        std::cout<<"\nParovi identicnih trouglova:\n";
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuIdenticni(*v[i],*v[j])==true){
                    v[i]->Ispisi();
                    std::cout<<" i ";
                    v[j]->Ispisi();
                    std::cout<<std::endl;
                }
            }
          }
        }
         else std::cout<<"\nNema identicnih trouglova!";
    
        int brojac1=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(DaLiSuPodudarni(*v[i],*v[j])==true) brojac1++;
        if(brojac1!=0){
         std::cout<<"Parovi podudarnih trouglova:\n";
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuPodudarni(*v[i],*v[j])==true){
                    v[i]->Ispisi();
                    std::cout<<" i ";
                    v[j]->Ispisi();
                    std::cout<<std::endl;
                }
            }
        }
        }
        else std::cout<<"\nNema podudarnih trouglova!";
        
        int brojac2=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(DaLiSuSlicni(*v[i],*v[j])==true) brojac2++;
        if(brojac2!=0){
         std::cout<<"Parovi slicnih trouglova:\n";
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuSlicni(*v[i],*v[j])==true){
                    v[i]->Ispisi();
                    std::cout<<" i ";
                    v[j]->Ispisi();
                    std::cout<<std::endl;
                }
            }
        }
        }
        else std::cout<<"\nNema slicnih trouglova!";
	return 0;
}