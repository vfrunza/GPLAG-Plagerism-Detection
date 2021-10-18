/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double,double> Tacka;

class Trougao {
    Tacka t1,t2,t3; 
    
    double Udaljenost (Tacka t1, Tacka t2) const {
        double d; 
        d=std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second)); 
        return d; 
    }
    
    void TestirajIndeks (int indeks) const {
        if (indeks<1 || indeks>3) 
        throw std::range_error ("Nekorektan indeks"); 
    }
    
    static double Pomocna (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    }
    
    public: 
    
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Postavi(t1,t2,t3); 
    }
    
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (Udaljenost(t1,t2)+Udaljenost(t2,t3)-Udaljenost(t1,t3)<0.00001)
        throw std::domain_error ("Nekorektne pozicije tjenema"); 
        
        Trougao::t1=t1; 
        Trougao::t2=t2; 
        Trougao::t3=t3; 
    }
    
    void Postavi (int indeks, const Tacka &t) {
        
        TestirajIndeks(indeks); 
        
        if (indeks==1) Trougao::t1=t; 
        else if (indeks==2) Trougao::t2=t; 
        else if (indeks==3) Trougao::t3=t; 
    }
    
    static int Orjentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    
    Tacka DajTjeme (int indeks) const {
    TestirajIndeks(indeks); 
    
    if (indeks==1) return Trougao::t1; 
    if (indeks==2) return Trougao::t2; 
    if (indeks==3) return Trougao::t3; 

    } 
    
    double DajStranicu (int indeks) const {
        TestirajIndeks(indeks); 
        
        if (indeks==1) return Udaljenost(t2,t3);  
        if (indeks==2) return Udaljenost(t1,t3);
        if (indeks==3) return Udaljenost(t1,t2); 
    }  
    
    double DajUgao (int indeks) const {
        TestirajIndeks(indeks);  
        
        double alfa,beta,gama; 
        alfa=std::acos ((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(3)*DajStranicu(2)));
        beta=std::acos ((DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
        gama=std::acos ((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2))); 
        
        if (indeks==1) return alfa; 
        if (indeks==2) return beta; 
        if (indeks==3) return gama; 
    }
    
    Tacka DajCentar() const {
        Tacka t; 
        t.first=((t1.first+t2.first+t3.first)/3); 
        t.second=((t1.second+t2.second+t3.second)/3); 
        return t; 
    }
    
    double DajObim() const { return Udaljenost(t1,t2)+Udaljenost(t2,t3)+Udaljenost(t1,t3); } 
    double DajPovrsinu() const { double p=0.5*std::fabs(Pomocna(t1,t2,t3));  return p; }
    bool DaLiJePozitivnoOrjentiran() const {
        if (Orjentacija(t1,t2,t3)==1) return true; 
        return false; 
    } 
    
    bool DaLiJeUnutra (const Tacka &t) const {
        if (DaLiJePozitivnoOrjentiran()==true) {
            if (Orjentacija(t1,t2,t)==1 && Orjentacija(t2,t3,t)==1 && Orjentacija(t3,t1,t)==1) 
            return true; 
        }
        else if (DaLiJePozitivnoOrjentiran()==false) {
            if (Orjentacija(t1,t2,t)==-1 && Orjentacija(t2,t3,t)==-1 && Orjentacija(t3,t1,t)==-1) 
            return true; 
        }
        else return false; 
    }
    
    void Ispisi() const {
        std::cout << "((" << DajTjeme(1).first << "," << DajTjeme(1).second << "),(" << DajTjeme(2).first << "," << DajTjeme(2).second << "),(" << DajTjeme(3).first << "," << DajTjeme(3).second << "))"; 
    }
    
    void Transliraj (double delta_x, double delta_y) {
        t1.first=t1.first+delta_x; t1.second=t1.second+delta_y; 
        t2.first=t2.first+delta_x; t2.second=t2.second+delta_y; 
        t3.first=t3.first+delta_x; t3.second=t3.second+delta_y; 
    }
    
    void Centriraj (const Tacka &t) {
        double x,y; 
        x=t.first-DajCentar().first; 
        y=t.second-DajCentar().second; 
        Transliraj(x,y); 
    }
    
    void Rotiraj (const Tacka &t, double ugao) {
        t1.first=t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao); 
        t1.second=t.second+(t1.first-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao); 
        
        t2.first=t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao); 
        t2.second=t.second+(t2.first-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao); 
        
        t3.first=t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao); 
        t3.second=t.second+(t3.first-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao); 
    }
    
    void Skaliraj (const Tacka &t, double faktor) {
        if (faktor-0<0.00001) 
        throw std::domain_error ("Nekorektan faktor skaliranja");
        Tacka tt;
        t1.first=t.first+faktor*(t1.first-t.first); 
        t1.second=t.second+faktor*(t1.second-t.second);  
        
        t2.first=t.first+faktor*(t2.first-t.first); 
        t2.second=t.second+faktor*(t2.second-t.second); 
        
        t3.first=t.first+faktor*(t3.first-t.first); 
        t3.second=t.second+faktor*(t3.second-t.second); 
    }
    
    void Rotiraj(double ugao) {
        Rotiraj(DajCentar(),ugao); 
    }
    
    void Skaliraj(double faktor) {
        Skaliraj(DajCentar(), faktor); 
    }
    
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2); 
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2); 
    
}; 

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2) {
    if ((t1.DajStranicu(1)-t2.DajStranicu(1)<0.00001 || t1.DajStranicu(1)-t2.DajStranicu(2)<0.00001 || t1.DajStranicu(1)-t2.DajStranicu(3)<0.00001) && 
        (t1.DajStranicu(2)-t2.DajStranicu(1)<0.00001 || t1.DajStranicu(2)-t2.DajStranicu(2)<0.00001 || t1.DajStranicu(2)-t2.DajStranicu(3)<0.00001) &&
        (t1.DajStranicu(3)-t2.DajStranicu(1)<0.00001 || t1.DajStranicu(3)-t2.DajStranicu(2)<0.00001 || t1.DajStranicu(3)-t2.DajStranicu(3)<0.00001)) 
        return true; 
    else return false; 
}

bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2) {
    if ((t1.DajStranicu(1)-t2.DajStranicu(1)<0.00001) && (t1.DajStranicu(2)-t2.DajStranicu(2)<0.00001) && (t1.DajStranicu(3)-t2.DajStranicu(3)<0.00001))
    return true; 
    else return false;
}

bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2) {
    
    if (((t1.DajStranicu(1)*t1.DajStranicu(2))/(t2.DajStranicu(1)*t2.DajStranicu(2)))-((t1.DajStranicu(1)*t1.DajStranicu(3))/(t2.DajStranicu(1)*t2.DajStranicu(3)))<0.0001)
    return true; 
    else return false; 
}

int Trougao::Orjentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double izraz; 
    izraz=Pomocna(t1,t2,t3);
    if (izraz>0) 
    return 1; 
    if (izraz<0) 
    return -1; 
}

int main ()
{
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n; 
    std::cin >> n; 
    
    std::vector<std::shared_ptr<Trougao>> vektor(n);
    
    Tacka t1,t2,t3; 
    
    for (int i=0; i<n; i++) {
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): "; 
        int x1,y1,x2,y2,x3,y3; 
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3; 
        
        t1=std::make_pair(x1,y1); 
        t2=std::make_pair(x2,y2); 
        t3=std::make_pair(x3,y3); 
        
        try {
            Trougao t(t1,t2,t3); 
            vektor[i]=std::make_shared<Trougao>(t); 
        }
        catch (std::domain_error e) {
          std::cout << e.what() << ", ponovite unos!" << std::endl;
          i--;
        }
        }
   
   std::cout << "Unesite vektor translacije (dx dy): "; 
   int a,b; 
   std::cin >> a >> b; 
   
   std::cout << "Unesite ugao rotacije: "; 
   int c; 
   std::cin >> c; 
   
   std::cout << "Unesite faktor skaliranja: "; 
   int d; 
   std::cin >> d; 
   
   std::vector<std::shared_ptr<Trougao>> vektor1(n); 
   
  std::transform (vektor.begin(), vektor.end(), vektor1.begin(), [=](std::shared_ptr<Trougao>t) {
       t->Transliraj(a,b); 
       t->Rotiraj(c);
       t->Skaliraj(t1, d);
       return t;   
   });
  
  std::sort (vektor1.begin(), vektor1.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
      return t1->DajPovrsinu()-t2->DajPovrsinu()<0; 
  });
  
  std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl; 
  
  std::for_each (vektor1.begin(), vektor1.end(), [](std::shared_ptr<Trougao> t1) -> void {
      t1->Ispisi(); 
      std::cout << std::endl; 
  });
  
  std::cout << "Trougao sa najmanjim obimom: " ; 
  std::min_element (vektor1.begin(), vektor1.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
      if (t1->DajObim()-t2->DajObim()) return true; 
      else return false; 
  });
 
 std::cout << std::endl << "Parovi identicnih trouglova: "; 
 
  
  

	return 0;
	
}
