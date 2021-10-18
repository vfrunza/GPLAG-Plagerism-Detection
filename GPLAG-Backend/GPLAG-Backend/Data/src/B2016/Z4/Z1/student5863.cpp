/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>
#include <new>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka prvaTacka;
    Tacka drugaTacka;
    Tacka trecaTacka;
    
    static double orijentPov(const Tacka t1, const Tacka t2, const Tacka t3) {
         double orijent = t1.first*( t2.second - t3.second ) - t2.first*( t1.second - t3.second ) + t3.first*( t1.second - t2.second );
         return orijent;
    }
    void provjeraIndeksa(int indeks) const;
    
    static bool isti(double a, double b) {
        double eps = 1e-10;
        return std::fabs(a-b) <= eps*(std::fabs(a) + std::fabs(b));
    }
    
    static double duzinaStr(const Tacka t1, const Tacka t2) { 
        double duzina = 0;
        duzina = std::sqrt( ((t1.first - t2.first)*(t1.first - t2.first)) + ((t1.second - t2.second)*(t1.second - t2.second)) );
        return duzina;
    }
    static bool provjeraTacki(const Tacka prva, const Tacka druga, const Tacka treca) {
          double a = duzinaStr(prva,druga);
          double b = duzinaStr(druga,treca);
          double c = duzinaStr(prva,treca);
        
        if( a+b <= c || a+c <= b || b+c <= a) return false;
        return true;
           
    }
    
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double o = Trougao::orijentPov(t1,t2,t3);
        
        if(o > 0) return 1;
        else if( o < 0) return -1;
        return 0;
    }
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


 
    void Trougao::provjeraIndeksa(int indeks) const {
        if(indeks < 1 || indeks > 3 ) throw std::range_error("Nekorektan indeks");
    }

    Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(!Trougao::provjeraTacki(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::prvaTacka = t1;
        Trougao::drugaTacka = t2;
        Trougao::trecaTacka = t3;
    }
    
    
    void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(!Trougao::provjeraTacki(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::prvaTacka = t1;
        Trougao::drugaTacka = t2;
        Trougao::trecaTacka = t3;
    }
    
    
    void Trougao::Postavi(int indeks, const Tacka &t) {
       Trougao::provjeraIndeksa(indeks);
        switch(indeks) {
            case 1 : prvaTacka = t; break;
            case 2 : drugaTacka = t; break;
            case 3 : trecaTacka = t; break;
        }
    }
    
    
   
    
    
    Tacka Trougao::DajTjeme(int indeks) const {
       Trougao::provjeraIndeksa(indeks);
        
        switch(indeks){
            case 1 : return prvaTacka;
            case 2 : return drugaTacka;
            case 3 : return trecaTacka;
        }
    }
    
    
    double Trougao::DajStranicu(int indeks) const {
       Trougao::provjeraIndeksa(indeks);
        double duzina = 0;
        
        switch(indeks) {
            case 1 : duzina = std::sqrt( std::pow((drugaTacka.first - trecaTacka.first),2) + std::pow((drugaTacka.second - trecaTacka.second),2) ); 
                      break;
            case 2 :  duzina = std::sqrt( std::pow((prvaTacka.first - trecaTacka.first),2) + std::pow((prvaTacka.second - trecaTacka.second),2) ); 
                      break;   
            case 3 : duzina = std::sqrt( std::pow((drugaTacka.first - prvaTacka.first),2) + std::pow((drugaTacka.second - prvaTacka.second),2) ); 
                      break;          
        }
        return duzina;
    }
    
    double Trougao::DajUgao(int indeks) const {
      Trougao::provjeraIndeksa(indeks);
        double a_BC1 = 0,b_AC2 = 0,c_AB3 = 0,alfa = 0,beta = 0,gama = 0;
        a_BC1 = DajStranicu(1);
        b_AC2 = DajStranicu(2);
        c_AB3 = DajStranicu(3);
        
        alfa = std::acos( double(b_AC2*b_AC2 + c_AB3*c_AB3 - a_BC1*a_BC1) / double(2*b_AC2*c_AB3) );
        beta = std::acos( double(a_BC1*a_BC1 + c_AB3*c_AB3 - b_AC2*b_AC2) / double(2*a_BC1*c_AB3) );
        gama = std::acos( double(a_BC1*a_BC1 + b_AC2*b_AC2 - c_AB3*c_AB3) / double(2*a_BC1*b_AC2) );
        
        switch(indeks) {
            case 1 : return alfa;
            case 2 : return beta;
            case 3 : return gama;
        }
    }
    
    
    Tacka Trougao::DajCentar() const {
        Tacka centar;
        centar.first = ( prvaTacka.first + drugaTacka.first + trecaTacka.first ) / 3.;
        centar.second = ( prvaTacka.second + drugaTacka.second + trecaTacka.second ) / 3.;
        return centar;
    }
    
    double Trougao::DajObim() const {
        return DajStranicu(1) + DajStranicu(2) + DajStranicu(3);
    }
    
    
    double Trougao::DajPovrsinu() const {
        double povrsina = 0;
        povrsina = std::abs(Trougao::orijentPov(prvaTacka, drugaTacka, trecaTacka))/2.;
        return povrsina;
    }
    
    
    bool Trougao::DaLiJePozitivnoOrijentiran() const {
        double pr = Trougao::orijentPov(prvaTacka, drugaTacka, trecaTacka);
        if( pr > 0) return true;
        return false; // sta ako je 0
    }
    
    bool Trougao::DaLiJeUnutra(const Tacka &t) const {
       double prvi = Trougao::orijentPov(prvaTacka,drugaTacka,trecaTacka);
       double drugi = Trougao::orijentPov(prvaTacka, drugaTacka, t);
       double treci = Trougao::orijentPov(drugaTacka, trecaTacka, t);
       double cetvrti = Trougao::orijentPov(trecaTacka,prvaTacka, t);
       
        if( prvi > 0 && drugi > 0 && treci > 0 && cetvrti > 0) return true;
        if( prvi < 0 && drugi < 0 && treci < 0 && cetvrti < 0) return true;
        
        return false;
    }
    
    
    void Trougao::Ispisi() const {
       std::cout<< "((" << prvaTacka.first << "," << prvaTacka.second << "),(" << drugaTacka.first << "," << drugaTacka.second << "),(" << trecaTacka.first << "," << trecaTacka.second << "))";
    }
    
    void Trougao::Transliraj(double delta_x, double delta_y) {
        Tacka pom1 = prvaTacka;
        Tacka pom2 = drugaTacka;
        Tacka pom3 = trecaTacka;
        prvaTacka.first = delta_x + pom1.first;
        prvaTacka.second = delta_y + pom1.second;
        drugaTacka.first = delta_x + pom2.first;
        drugaTacka.second = delta_y + pom2.second;
        trecaTacka.first = delta_x + pom3.first;
        trecaTacka.second = delta_y + pom3.second;
    }
    
    
    void Trougao::Centriraj(const Tacka &t) {
        Tacka centar = DajCentar(); // treba po kvadrantima!!!!
        double x = t.first - centar.first;
        double y =  t.second - centar.second;
        Transliraj(x,y);
    }
    
    
    void Trougao::Rotiraj(const Tacka &t, double ugao) {
        Tacka pom1 = prvaTacka;
        Tacka pom2 = drugaTacka;
        Tacka pom3 = trecaTacka;
        
        prvaTacka.first = t.first + ((pom1.first - t.first)*std::cos(ugao)) - ((pom1.second - t.second)*std::sin(ugao) );
        prvaTacka.second = t.second + ((pom1.first - t.first)*std::sin(ugao)) + ((pom1.second - t.second)*std::cos(ugao) );
        drugaTacka.first =  t.first + ((pom2.first - t.first)*std::cos(ugao)) - ((pom2.second - t.second)*std::sin(ugao) );
        drugaTacka.second =  t.second + ((pom2.first - t.first)*std::sin(ugao)) + ((pom2.second - t.second )*std::cos(ugao));
        trecaTacka.first =  t.first + ((pom3.first - t.first)*std::cos(ugao)) - ((pom3.second - t.second)*std::sin(ugao) );
        trecaTacka.second =  t.second + ((pom3.first - t.first)*std::sin(ugao)) + ((pom3.second - t.second)*std::cos(ugao) );
         
    }
    
    
    void Trougao::Skaliraj(const Tacka &t, double faktor) {
        if(Trougao::isti(faktor,0) ) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka pom1 = prvaTacka;
        Tacka pom2 = drugaTacka;
        Tacka pom3 = trecaTacka;
        prvaTacka.first = ( t.first + ((pom1.first - t.first)*faktor) );
        prvaTacka.second = ( t.second + ((pom1.second - t.second)*faktor) );
        drugaTacka.first = ( t.first + ((pom2.first - t.first)*faktor) );
        drugaTacka.second = ( t.second + ((pom2.second - t.second)*faktor) );
        trecaTacka.first = ( t.first + ((pom3.first - t.first)*faktor) );
        trecaTacka.second = ( t.second + ((pom3.second - t.second)*faktor) );
        
    }
    
    
    void Trougao::Rotiraj(double ugao) {
        
        Rotiraj(this->DajCentar(),ugao);
    }
    
    
    void Trougao::Skaliraj(double faktor) {
        if( Trougao::isti(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
       
        Skaliraj(this->DajCentar(),faktor);
    }
    
    
     bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
        bool jedan = false, dva = false, tri = false;
        if( Trougao::isti(t1.prvaTacka.first, t2.prvaTacka.first) && Trougao::isti(t1.prvaTacka.second, t2.prvaTacka.second) ) jedan = true;
        if( Trougao::isti(t1.prvaTacka.first, t2.drugaTacka.first) && Trougao::isti(t1.prvaTacka.second, t2.drugaTacka.second) ) jedan = true;
        if( Trougao::isti(t1.prvaTacka.first, t2.trecaTacka.first) && Trougao::isti(t1.prvaTacka.second, t2.trecaTacka.second) ) jedan = true;
        if( !jedan) return false;
        if( Trougao::isti(t1.drugaTacka.first, t2.prvaTacka.first) && Trougao::isti(t1.drugaTacka.second, t2.prvaTacka.second) ) dva = true;
        if( Trougao::isti(t1.drugaTacka.first, t2.drugaTacka.first) && Trougao::isti(t1.drugaTacka.second, t2.drugaTacka.second) ) dva = true;
        if( Trougao::isti(t1.drugaTacka.first, t2.trecaTacka.first) && Trougao::isti(t1.drugaTacka.second, t2.trecaTacka.second) ) dva = true;
        if( !dva) return false;
        if( Trougao::isti(t1.trecaTacka.first, t2.prvaTacka.first) && Trougao::isti(t1.trecaTacka.second, t2.prvaTacka.second) ) tri = true;
        if( Trougao::isti(t1.trecaTacka.first, t2.drugaTacka.first) && Trougao::isti(t1.trecaTacka.second, t2.drugaTacka.second) ) tri = true;
        if( Trougao::isti(t1.trecaTacka.first, t2.trecaTacka.first) && Trougao::isti(t1.trecaTacka.second, t2.trecaTacka.second) ) tri = true; 
        
        if( jedan && dva && tri) return true;
        return false;
    }
    
    
     bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
       double a = Trougao::duzinaStr(t1.drugaTacka,t1.trecaTacka), b= Trougao::duzinaStr(t1.prvaTacka,t1.trecaTacka), c= Trougao::duzinaStr(t1.prvaTacka,t1.drugaTacka);
       double a1 = Trougao::duzinaStr(t2.drugaTacka,t2.trecaTacka), b1 = Trougao::duzinaStr(t2.prvaTacka,t2.trecaTacka), c1 = Trougao::duzinaStr(t2.prvaTacka,t2.drugaTacka);
       double d=0,e=0,f=0,g=0,u=0,u1=0,h=0,l=0,m=0;
       
       for(int i = 1; i <= 6; i++) {
           d = a; f= b; u = c;
           if( i == 1 || i == 2) { e = a1; u1 = b1;  h = 1;
            if( i == 1) { g = b1; m = 3; l=2; }
            else {
                g = c1;  m= 2; l = 3;
            }
           }
            else if(i == 3 || i == 4) { e = b1;  h = 2;
            if( i == 3) { g = a1; u1 = c1; m = 3; l = 1; }
            else { 
                g = c1; u1 = b1; m=2; l = 3;
            }
            }
            else if( i > 4) { e = c1; h = 3;
             if( i == 5) { g = a1; u1 = b1; m=2; l = 1; }
             else {
                 g = b1; u1 = a1; m = 1; l = 2;
             }
            }
            
         if(Trougao::isti(d,e) && Trougao::isti(f,g) && Trougao::isti(u,u1) && Trougao::isti(Trougao::orijentPov(t2.DajTjeme(h),t2.DajTjeme(l),t2.DajTjeme(m)),Trougao::orijentPov(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3))) ) return true;
          
       }
       
    
       
       double alfa = t1.DajUgao(1), beta = t1.DajUgao(2), gama = t1.DajUgao(3);
       double alfa1 = t2.DajUgao(1), beta1 = t2.DajUgao(2), gama1 = t2.DajUgao(3);
       
       //SUSUSU
       d=0,e=0,f=0,g=0,u=0,u1=0;
       for(int i = 1; i <= 9; i++) {
           
           if(i == 1) { d = a; e= a1; f = c; g = c1; u= beta; u1 = beta1; }
           else if(i == 2) { d = a; e = a1; f = b; g = b1; u = gama; u1= gama1; }
           else if( i == 3) { d = b; e = b1; f = c; g = c1; u = alfa; u1 = alfa1; } //sus
           else if( i == 4) { d = alfa; e = alfa1; f = b; g = b1; u = gama; u1 = gama1; }
           else if(i == 5) { d = alfa; e = alfa1; f =beta; g = beta1; u =c; u1=c1; }
           else if(i == 6) { d = beta; e = beta1;  f = gama; g = gama1; u =a; u1= a1; } //usu
           else if(i == 7) { d = a; e = a1; f = b; g = b1;
               if( a > b) { u = alfa; u1 = alfa1; }
               else { u = beta; u1 = beta1; }
           }
           else if( i == 8) { d = b; e = b1; f = c; g = c1;
              if( b > c) { u = beta; u1 = beta1; }
              else { u = gama; u1 = gama1; }
           }
           else if(i == 9) { d = a; e = a1; f = c; g = c1;
           if(a > c) { u = alfa; u1 = alfa1; }
           else { u = gama; u1 = gama1; }
           }                                   //susuglovi
           
           if(Trougao::isti(u,u1) && Trougao::isti(d,e) && Trougao::isti(f,g)) return true;
       }
  
       return false;
        
       
    }
        
    
     bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
       if(DaLiSuPodudarni(t1,t2)) return true;
         double a = Trougao::duzinaStr(t1.drugaTacka,t1.trecaTacka), b= Trougao::duzinaStr(t1.prvaTacka,t1.trecaTacka), c= Trougao::duzinaStr(t1.prvaTacka,t1.drugaTacka);
       double a1 = Trougao::duzinaStr(t2.drugaTacka,t2.trecaTacka), b1 = Trougao::duzinaStr(t2.prvaTacka,t2.trecaTacka), c1 = Trougao::duzinaStr(t2.prvaTacka,t2.drugaTacka);
       
        double x =0,y=0,z=0,h=0,l=0,m=0;
       for( int i = 1; i <=6; i++) {
           if( i == 1) { x = a/a1; y =b/b1; z = c/c1; h =1; l =2; m =3;}
           else if( i ==2) { x = a/b1; y = b/a1; z = c/c1; h= 2; l=1; m=3; }
           else if(i == 3) { x = a/b1; y = b/c1; z = c/a1; h =2; l=3; m=1;}
           else if( i == 4) { x =a/c1; y = b/b1; z = c/a1; h = 3; l=2; m=1;}
           else if(i == 5) { x = a/a1; y = b/c1; z= c/b1; h=1; l=3; m=2;}
           else {
               x=a/c1; y = b/a1; z = c/b1; h=3; l=1; m=2;
           }
           
           
           if(Trougao::isti(x,y) && Trougao::isti(y,z) && Trougao::isti(x,z) && Trougao::isti(Trougao::orijentPov(t2.DajTjeme(h),t2.DajTjeme(l),t2.DajTjeme(m)),Trougao::orijentPov(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)))) return true;
       }
       
       return false;
        
    }
    
   


int main ()
{
  
    try{
    std::vector<std::shared_ptr<Trougao>> trokuti;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n = 0;
    std::cin>>n;
    for(int i = 0; i < n; i++) {
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        
        double px = 0, py = 0, dx = 0,dy = 0, tx = 0, ty = 0;
        std::cin>>px>>py>>dx>>dy>>tx>>ty;
        Tacka prva = std::make_pair(px,py);
        Tacka druga = std::make_pair(dx,dy);
        Tacka treca = std::make_pair(tx,ty);
        try{
         
        std::shared_ptr<Trougao> t = std::make_shared<Trougao>(Trougao(prva,druga,treca));
        trokuti.emplace_back(t);
        }catch(std::domain_error e) {
            std::cout<< e.what() <<", ponovite unos!" << std::endl;
            i--;
        }
        
        }
    
   /* for( auto it = trokuti.begin(); it != trokuti.end(); it++ )
        (*it)->Ispisi();*/
        double delta_x = 0,delta_y = 0,ugao = 0,faktor = 0;
        
                std::cout<<"Unesite vektor translacije (dx dy): ";
                std::cin>>delta_x>>delta_y;
          
                std::cout<<"Unesite ugao rotacije: ";
                std::cin>>ugao;
           
                std::cout<<"Unesite faktor skaliranja: "; 
                std::cin>>faktor;
          
            std::transform(trokuti.begin(), trokuti.end(), trokuti.begin(), [delta_x,delta_y,ugao,faktor] (std::shared_ptr<Trougao> t) {
                   
                    t->Transliraj(delta_x,delta_y);
                    t->Rotiraj(ugao);
                    t->Skaliraj(t->DajTjeme(1),faktor);
                return t;
                
            });
       
        
        std::sort(trokuti.begin(), trokuti.end(), [](std::shared_ptr<Trougao> t, std::shared_ptr<Trougao> k) {
            return (t->DajPovrsinu() < k->DajPovrsinu());
        });
        
        std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
        std::for_each(trokuti.begin(), trokuti.end(), [](std::shared_ptr<Trougao> t){
            t->Ispisi();
            std::cout<<std::endl;
        });
        
        
        std::cout<<"Trougao sa najmanjim obimom: ";
        auto torkut = *std::min_element(trokuti.begin(), trokuti.end(), [](std::shared_ptr<Trougao> t, std::shared_ptr<Trougao> k) { return (t->DajObim() < k->DajObim() ); } );
        torkut->Ispisi();
        std::cout<<std::endl;
        
        std::vector<std::pair<Trougao,Trougao>> identicni;
        std::vector<std::pair<Trougao,Trougao>> slicni;
        std::vector<std::pair<Trougao,Trougao>> podudarni;
       
       for(auto t = trokuti.begin(); t != trokuti.end(); t++) {
           for(auto k = t; k != trokuti.end(); k++) {
               if(k != t) {
          if(DaLiSuIdenticni(**t,**k)) identicni.emplace_back(std::make_pair(**t,**k));
          if(DaLiSuPodudarni(**t,**k)) podudarni.emplace_back(std::make_pair(**t,**k));
          if(DaLiSuSlicni(**t,**k)) slicni.emplace_back(std::make_pair(**t,**k));
               }
        
       }
       }

        
        for(int i = 1; i <= 3; i++) {
         std::vector<std::pair<Trougao,Trougao>> pomocni;
         if( i == 1) pomocni = identicni;
         else if(i == 2) pomocni = podudarni;
         else pomocni = slicni;
        
        if( pomocni.size() == 0) {
            switch(i) {
                case 1 : std::cout<<"Nema identicnih trouglova!"<<std::endl; break;
                case 2 : std::cout<<"Nema podudarnih trouglova!"<<std::endl; break;
                case 3 : std::cout<<"Nema slicnih trouglova!"<<std::endl; break;
            }
        }
        else {
            switch(i) {
                case 1 : std::cout<<"Parovi identicnih trouglova: "<<std::endl; break;
                case 2 : std::cout<<"Parovi podudarnih trouglova: "<<std::endl; break;
                case 3 : std::cout<<"Parovi slicnih trouglova: "<<std::endl; break;
            }
        std::for_each(pomocni.begin(), pomocni.end(), [](std::pair<Trougao,Trougao> par) {
           
            par.first.Ispisi();
            std::cout<<" i ";
            par.second.Ispisi();
            std::cout<<std::endl;
        });
        }
        }
    }catch(std::domain_error d) {
        std::cout << d.what() << std::endl;
    }catch(std::range_error r) {
        std::cout << r.what() << std::endl;
    }catch(std::bad_alloc b) {
        std::cout << "Nema memorije" << std::endl;
    }
      
    
	return 0;
}