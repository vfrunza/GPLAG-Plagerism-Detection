#include <stdexcept>
#include <cmath>
#include <iostream>
#include <vector> 
#include <memory>
#include <algorithm>
const double Eps=1e-10;
bool JesuLiJednaki(double x, double y) {
    if (std::fabs(x-y) <= Eps * (std::fabs(x) + std::fabs(y))) return true;
    else return false;
    
    }
typedef std::pair<double, double> Tacka;
class Trougao {
    Tacka t1,t2,t3;
    
  
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
      Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) {
            throw std::domain_error ("Nekorektne pozicije tjemena");
        }
        else {
        this->t1=t1;
        this->t2=t2;
        this->t3=t3;
    }
    }
    void Postavi(int indeks, const Tacka &t) {
        
        if(indeks==1 )  {
            if( Orijentacija(t,t2,t3)!=0)
            this->t1=t;
            else throw std::domain_error ("Nekorektne pozicije tjemena");
        }
        if(indeks==2 )  {
            if( Orijentacija(t1,t,t3)!=0)
            this->t2=t;
            else throw std::domain_error ("Nekorektne pozicije tjemena");
        }
        if(indeks==3 )  {
            if( Orijentacija(t1,t2,t)!=0)
            this->t3=t;
            else throw std::domain_error ("Nekorektne pozicije tjemena");
        }
        
        else throw std::domain_error ("Nekorektan index");
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
     if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0) return 1;
     else if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<0) return -1;
     else return 0;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks==1) return t1;
        else if(indeks==2) return t2;
        else if(indeks==3) return t3;
    }
    double DajStranicu(int indeks) const ;
    double DajUgao(int indeks) const ;
    
    
    Tacka DajCentar() const {
        Tacka t;
        t.first=(t1.first+t2.first+t3.first)/3;
        t.second=(t1.second+t2.second+t3.second)/3;
        return t;
    }
    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const {
        return 1/2*fabs(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)>0)) return true;
        else return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    
    void Ispisi() const {
        std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y) ;
    
    void Centriraj(const Tacka &t);
    
    void Rotiraj(const Tacka &t, double ugao);
    
    void Skaliraj(const Tacka &t, double faktor);
    
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    //gotovo
     friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
        /* Tacka prva=t1.DajTjeme(1);
         Tacka druga=t1.DajTjeme(2);
         Tacka treca=t1.DajTjeme(3);
         Tacka prva_=t2.DajTjeme(1);
         Tacka druga_=t2.DajTjeme(2);
         Tacka treca_=t2.DajTjeme(3);*/
         if(t1.DajTjeme(1)==t2.DajTjeme(1) && t1.DajTjeme(2)==t2.DajTjeme(2) && t1.DajTjeme(3)== t2.DajTjeme(3)) return true;
         else if(t1.DajTjeme(1)==t2.DajTjeme(1) && t1.DajTjeme(2)==t2.DajTjeme(3) && t1.DajTjeme(3)== t2.DajTjeme(2)) return true;
         else if(t1.DajTjeme(1)==t2.DajTjeme(3) && t1.DajTjeme(2)==t2.DajTjeme(2) && t1.DajTjeme(3)== t2.DajTjeme(1)) return true;
         else if(t1.DajTjeme(1)==t2.DajTjeme(2) && t1.DajTjeme(2)==t2.DajTjeme(1) && t1.DajTjeme(3)== t2.DajTjeme(3)) return true;
         else if(t1.DajTjeme(1)==t2.DajTjeme(3) && t1.DajTjeme(2)==t2.DajTjeme(1) && t1.DajTjeme(3)== t2.DajTjeme(2)) return true;
         else if(t1.DajTjeme(1)==t2.DajTjeme(2) && t1.DajTjeme(2)==t2.DajTjeme(3) && t1.DajTjeme(3)== t2.DajTjeme(1)) return true;
         return false;
         
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
        //prvi trougao
        double alfa=t1.DajUgao(1);
        double beta=t1.DajUgao(2);
        double gama=t1.DajUgao(3);
        double a=t1.DajStranicu(1);
        double b=t1.DajStranicu(2);
        double c=t1.DajStranicu(3);
        //drugi trougao
        double alfa1=t2.DajUgao(1);
        double beta1=t2.DajUgao(2);
        double gama1=t2.DajUgao(3);
        double a1=t2.DajStranicu(1);
        double b1=t2.DajStranicu(2);
        double c1=t2.DajStranicu(3);
        if((Orijentacija(t1.t1,t1.t2,t1.t3)==1 && Orijentacija(t2.t1,t2.t2,t2.t3)==1 )||(Orijentacija(t1.t1,t1.t2,t1.t3)==-1 && Orijentacija(t2.t1,t2.t2,t2.t3)==-1 )) {
        if(JesuLiJednaki(a,a1) && JesuLiJednaki(b,b1) && JesuLiJednaki(c,c1)) {
            //ove uslove kopirat u svaki
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
            
        }
        else if(JesuLiJednaki(a,a1) && JesuLiJednaki(b,c1) && JesuLiJednaki(c,b1)) {
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
        }
        else if(JesuLiJednaki(a,c1) && JesuLiJednaki(b,b1) && JesuLiJednaki(c,a1)) {
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
        }
        else if(JesuLiJednaki(a,b1) && JesuLiJednaki(b,a1) && JesuLiJednaki(c,c1)) {
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
        }
        else if(JesuLiJednaki(a,c1) && JesuLiJednaki(b,a1) && JesuLiJednaki(c,b1)) {
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
        }
        else if(JesuLiJednaki(a,b1) && JesuLiJednaki(b,c1) && JesuLiJednaki(c,a1)) {
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
        } 
            
        }
        
        return false;
        
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
         double alfa=t1.DajUgao(1);
        double beta=t1.DajUgao(2);
        double gama=t1.DajUgao(3);
        double a=t1.DajStranicu(1);
        double b=t1.DajStranicu(2);
        double c=t1.DajStranicu(3);
        //drugi trougao
        double alfa1=t2.DajUgao(1);
        double beta1=t2.DajUgao(2);
        double gama1=t2.DajUgao(3);
        double a1=t2.DajStranicu(1);
        double b1=t2.DajStranicu(2);
        double c1=t2.DajStranicu(3);
        if((Orijentacija(t1.t1,t1.t2,t1.t3)==1 && Orijentacija(t2.t1,t2.t2,t2.t3)==1 )||(Orijentacija(t1.t1,t1.t2,t1.t3)==-1 && Orijentacija(t2.t1,t2.t2,t2.t3)==-1 )) {
        if(JesuLiJednaki(a/a1,b/b1) && JesuLiJednaki(b/b1,c/c1) ) {
            //ove uslove kopirat u svaki
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
            
        }
        else if(JesuLiJednaki(a/a1,b/c1) && JesuLiJednaki(b/c1,c/b1)) {
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
        }
        else if(JesuLiJednaki(a/c1,b/b1) && JesuLiJednaki(b/b1,c/a1) ) {
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
        }
        else if(JesuLiJednaki(a/b1,b/a1) && JesuLiJednaki(b/a1,c/c1) ) {
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
        }
        else if(JesuLiJednaki(a/c1,b/a1) && JesuLiJednaki(b/a1,c/b1) ) {
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
        }
        else if(JesuLiJednaki(a/b1,b/c1) && JesuLiJednaki(b/c1,c/a1)) {
            if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama,gama1)) return true;
            else if(JesuLiJednaki(alfa,alfa1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama,beta1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,beta1) && JesuLiJednaki(gama, alfa1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, gama1)) return true;
            else if(JesuLiJednaki(alfa,gama1) && JesuLiJednaki(beta,alfa1) && JesuLiJednaki(gama, beta1)) return true;
            else if(JesuLiJednaki(alfa,beta1) && JesuLiJednaki(beta,gama1) && JesuLiJednaki(gama, alfa1)) return true;
        } 
            
        }
         return false;
         
    }
};
    double Trougao::DajUgao(int indeks) const {
        double alfa;
        if(indeks==1) {
            alfa=acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/2*DajStranicu(2)*DajStranicu(3));
            
        }
        if(indeks==2) {
            alfa=acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/2*DajStranicu(1)*DajStranicu(3));
            
        }
        if(indeks==3) {
            alfa=acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/2*DajStranicu(1)*DajStranicu(2));
            
        }
        return alfa;
    }
    double Trougao::DajStranicu(int indeks) const {
        if(indeks==1) return sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
        if(indeks==2) return sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
        if(indeks==3) return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));

    }
    bool Trougao::DaLiJeUnutra(const Tacka &t) const  {
        if(Orijentacija(t1,t2,t3)==-1 && Orijentacija(t1,t2,t)==-1 &&Orijentacija(t2,t3,t)==-1 && Orijentacija(t3,t1,t)==-1) return true;
        else if(Orijentacija(t1,t2,t3)==1 && Orijentacija(t1,t2,t)==1 &&Orijentacija(t2,t3,t)==1 && Orijentacija(t3,t1,t)==1) return true;
        else return false;

    }
    void Trougao::Transliraj(double delta_x, double delta_y) {
        t1.first+=delta_x;
        t2.first+=delta_x;
        t3.first+=delta_x;
        t1.second+=delta_y;
        t2.second+=delta_y;
        t3.second+=delta_y;
    }
        void Trougao::Centriraj(const Tacka &t) {
            Tacka T=DajCentar();
            double delta=sqrt((T.first-t.first)*(T.first-t.first)+(T.second-t.second)*(T.second-t.second));
            if(JesuLiJednaki(T.second,t.second)) Transliraj(delta, 0);
            if(JesuLiJednaki(t.first, T.first)) Transliraj(0,delta);
            else {
            t1.first+=delta;
            t2.first+=delta;;
            t3.first+=delta;
            t1.second+=delta;
            t2.second+=delta;
            t3.second+=delta;
            }
        }
         void Trougao::Rotiraj(const Tacka &t, double ugao) {
             t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
             t1.second=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
             t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
             t2.second=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
             t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
             t3.second=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
         }
        void Trougao::Skaliraj(const Tacka &t, double faktor) {
            if(faktor==0) throw std::domain_error ("Nekorektan faktor skaliranja");
            if(faktor>0 ) {
            t1.first=t.first+faktor*(t1.first-t.first);
            t1.second=t.second+faktor*(t1.second-t.second);
            t2.first=t.first+faktor*(t2.first-t.first);
            t2.second=t.second+faktor*(t2.second-t.second);
            t3.first=t.first+faktor*(t3.first-t.first);
            t3.second=t.second+faktor*(t3.second-t.second);
            }
            if(faktor<0) {
            t1.first=t.first+faktor*(t1.first-t.first);
            t1.second=t.second+faktor*(t1.second-t.second);
            t2.first=t.first+faktor*(t2.first-t.first);
            t2.second=t.second+faktor*(t2.second-t.second);
            t3.first=t.first+faktor*(t3.first-t.first);
            t3.second=t.second+faktor*(t3.second-t.second);
                Rotiraj(t,180);
            }
        }
         void Trougao::Rotiraj(double ugao) {
             Tacka T=DajCentar();
             Rotiraj(T,ugao);
         }

         void Trougao::Skaliraj(double faktor) {
             Tacka T=DajCentar();
             Skaliraj(T,faktor);
         }
       
   

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    try{
    std::vector<std::shared_ptr<Trougao>> Vektor;
    for(int i(0);i<n;i++) {
        
        std::cout<<"Unesite podatke za "<<i+1<<". trougao  (x1 y1 x2 y2 x3 y3): "<<std::endl;
        Tacka t1,t2,t3;
       int a,b,c,d,e,f;
        std::cin>>a>>b;
        t1.first=a;
        t1.second=b;
        //std::cout<<"Unesite drugu tacku: ";
        std::cin>>c>>d;
        t2.first=c;
        t2.second=d;
        //std::cout<<"Unesite trecu tacku: ";
        std::cin>>e>>f;
        t3.first=e;
        t3.second=f;
        if(Trougao::Orijentacija(t1,t2,t3)!=0) {
            std::shared_ptr<Trougao> p(new Trougao(t1,t2,t3));
            Vektor.push_back(p);
        }
        if(Trougao::Orijentacija(t1,t2,t3)==0) {
            std::cout<<"Nekorektne pozicije tjemena, ponovite unos!";
            i--;
            
        }
        
        }
        double dx,dy;
        std::cout<<"Unesite vektor translacije (dx dy): ";
        std::cin>>dx>>dy;
        std::transform(Vektor.begin(),Vektor.end(),Vektor.begin(),[&](std::shared_ptr<Trougao> T) {T->Transliraj(dx,dy); return T;});
        std::cout<<"Unesite ugao rotacije: ";
        double ugao;
        std::cin>>ugao;
        std::transform(Vektor.begin(),Vektor.end(),Vektor.begin(),[&](std::shared_ptr<Trougao> T) {T->Rotiraj(ugao); return T;});
        std::cout<<"Unesite faktor skaliranja: ";
        double faktor;
        std::cin>>faktor;
       std::transform(Vektor.begin(),Vektor.end(),Vektor.begin(),[&](std::shared_ptr<Trougao> T) {T->Skaliraj(faktor); return T;});
        std::sort(Vektor.begin(),Vektor.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {return (t1->DajPovrsinu())<(t2->DajPovrsinu());});
        std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
        std::for_each(Vektor.begin(),Vektor.end(), [](std::shared_ptr<Trougao> t) {t->Ispisi();std::cout<<std::endl;});
        
        std::cout<<"Trougao sa najmanjim obimom: "<<*(std::min_element(Vektor.begin(),Vektor.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){return (t1->DajObim())<(t2->DajObim());}));
        std::cout<<std::endl;
        bool ima=false;
        for(int i(0);i<n-1;i++)  {
            for(int j=i+1;j<n;j++) {
                if(DaLiSuIdenticni(*Vektor[i],*Vektor[j])) {
                    ima=true;
                   break;
                }
                
        }
        }
        if(ima==false) std::cout<<"Nema identicnih trouglova"<<std::endl;
        if(ima==true) {std::cout<<"Parovi identicnih trouglovas su :"<<std::endl;
        for(int i(0);i<n-1;i++)  {
            for(int j=i+1;j<n;j++) {
                if(DaLiSuIdenticni(*Vektor[i],*Vektor[j])) {
                    Vektor[i]->Ispisi();
                    std::cout<<" i ";
                    Vektor[j]->Ispisi();
                }
             }
         
        }
        }//poduradni
          bool ima1=false;
        for(int i(0);i<n-1;i++)  {
            for(int j=i+1;j<n;j++) {
                if(DaLiSuPodudarni(*Vektor[i],*Vektor[j])) {
                    ima1=true;
                   break;
                }
                
        }
        }
        if(ima1==false) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
        if(ima1==true) {std::cout<<"Parovi podudarnih trouglova su :"<<std::endl;
        for(int i(0);i<n-1;i++)  {
            for(int j=i+1;j<n;j++) {
                if(DaLiSuPodudarni(*Vektor[i],*Vektor[j])) {
                    Vektor[i]->Ispisi();
                    std::cout<<" i ";
                    Vektor[j]->Ispisi();
                }
             }
         
        }
       
        }
         //slicni
          
            bool ima2=false;
        for(int i(0);i<n-1;i++)  {
            for(int j=i+1;j<n;j++) {
                if(DaLiSuSlicni(*Vektor[i],*Vektor[j])) {
                    ima2=true;
                   break;
                }
                
        }
        }
        if(ima2==false) std::cout<<"Nema slicnih trouglova";
        if(ima2==true) {std::cout<<"Parovi slicnih trouglova su :"<<std::endl;
        for(int i(0);i<n-1;i++)  {
            for(int j=i+1;j<n;j++) {
                if(DaLiSuSlicni(*Vektor[i],*Vektor[j])) {
                    Vektor[i]->Ispisi();
                    std::cout<<" i ";
                    Vektor[j]->Ispisi();
                }
             }
         
        }
       
        }
        
    //ovo je kr
    }
   
    catch(std::range_error tekst) {
        std::cout<<tekst.what();
    }
    catch(std::domain_error tekst) {
        std::cout<<tekst.what();
    }
    
	return 0;
}