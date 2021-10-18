/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>


typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka t1,t2,t3;
    public:
    
  Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
      
      if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
       Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
  }
      
     
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;}
void Postavi(int indeks, const Tacka &t){if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
    
    if(indeks==1)
    Trougao::t1=t;
    if(indeks==2)
    Trougao::t2=t2;
    if(indeks==3)
    Trougao::t3=t3;
}

static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second) >0)  )
    return 1;
    
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second) <0))
    return -1;
    
    if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second) ==0))
    return 0;
    
    
}
  
  Tacka DajTjeme(int indeks) const {if (indeks==1)return t1; if (indeks==2) return t2; if(indeks==3)return t3;}
  
double DajStranicu(int indeks) const{ 
    if(indeks==1) {
        
        return (sqrt( (t2.second-t3.second)*(t2.second-t3.second)+(t2.first-t3.first)*(t2.first-t3.first) ));
    }
    
    if(indeks==2) {
        
        return (sqrt( (t3.second-t1.second)*(t3.second-t1.second)+(t3.first-t1.first)*(t3.first-t1.first) ));
    }
    
     if(indeks==3) {
        
        return (sqrt( (t2.second-t1.second)*(t2.second-t1.second)+(t2.first-t1.first)*(t2.first-t1.first) ));
    }
}

double DajUgao(int indeks) const {
    
    
    if (indeks==1) {
        
        return ( acos( (DajStranicu(1)*DajStranicu(1)) /(DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-2*DajStranicu(2)*DajStranicu(3))   )       );
    }
    
     if (indeks==2) {
        
        return ( acos( (DajStranicu(2)*DajStranicu(2)) /(DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-2*DajStranicu(1)*DajStranicu(3))   )       );
    }
    
    if (indeks==3) {
        
        return ( acos( (DajStranicu(3)*DajStranicu(3)) /(DajStranicu(2)*DajStranicu(2)+DajStranicu(1)*DajStranicu(1)-2*DajStranicu(2)*DajStranicu(1))   )       );
    }
    
    
    
}

Tacka DajCentar() const {
    
    Tacka centar;
    centar.first=(t1.first+t2.first+t3.first)/3;
    centar.second=(t1.second+t2.second+t3.second)/3;
    return centar;
    
}

double DajObim() const {
    
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double DajPovrsinu() const {
    
    
return (0.5*    abs ( (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second) ) ) );
    
}
  
 bool DaLiJePozitivnoOrijentiran() const {
     
     if (Orijentacija(t1, t2, t3)) return true;
 if (!Orijentacija(t1, t2, t3)) return false;
     
 }    
 
 
 
 
bool DaLiJeUnutra(const Tacka &t) const { 
    
    if(Orijentacija(t1,t2,t3)==-1) {
        
        if(Orijentacija(t1,t2,t)==-1 && Orijentacija(t2,t3,t)==-1 && Orijentacija(t3,t1,t)==-1)
        return true;
    }
    
    if(Orijentacija(t1,t2,t3)==1) {
        
        if(Orijentacija(t1,t2,t)==1 && Orijentacija(t2,t3,t)==1 && Orijentacija(t3,t1,t)==1)
        return true;
    }
    
    return false;
    
    }
    
    
    
void Ispisi() const {
    std::cout<<"( ("<<t1.first<<","<<t1.second<<") , ("<<t2.first<<","<<t2.second<<") , ("<<t3.first<<","<<t3.second<<") )"<<std::endl;   
    
}

void Transliraj(double delta_x, double delta_y) {
    
    t1.first+=delta_x;
    t2.first+=delta_x;
    t3.first+=delta_x;
    
    t1.second+=delta_y;
    t2.second+=delta_y;
    t3.second+=delta_y;
    
}

  void Centriraj(const Tacka &t) {
      
   int x,y;
   Tacka centar;
      centar=DajCentar();
      
     x=t.first-centar.first;
     y=t.second-centar.second;
      
     Transliraj(x,y);
  }
  
  
  
  
void Rotiraj(const Tacka &t, double ugao) {
    
    t1.first=(t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao));
    t2.first=(t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao));
    t3.first=(t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao));
    
    t1.second=(t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao));
    t2.second=(t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao));
    t3.second=(t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao));
    
}


void Skaliraj(const Tacka &t, double faktor)
{
    
    if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
    
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
    Skaliraj(DajCentar(),faktor);
}


friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
    
};


bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {





}

int main ()
{
    
    std::cout<<"Koliko zelite kreirati trouglova:";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>>vektor(n);
    
    for (int i=0;i<n;i++) {
    int t1x,t1y,t2x,t2y,t3x,t3y;
    Tacka t1,t2,t3;
    std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
    
    try {
    std::cin>>t1x>>t1y>>t2x>>t2y>>t3x>>t3y;
    t1=std::make_pair(t1x,t1y);
    t2=std::make_pair(t2x,t2y);
    t3=std::make_pair(t3x,t3y);

vektor[i]= std::make_shared<Trougao>(Trougao(t1,t2,t3));
    }
    
    catch (std::domain_error d) {
        std::cout<<d.what()<<std::endl;
        i--;
    }

    }
    
   
    std::cout<<"Unesite vektor translacije (dx dy): ";
    int dx,dy;
    std::cin>>dx>>dy;
   
    std::cout<<"Unesite ugao rotacije: ";
    int ugaorot;
    std::cin>>ugaorot;
    std::cout<<"Unesite faktor skaliranja: ";
    int faktorskal;
    std::cin>>faktorskal;
    
   
   transform(vektor.begin(),vektor.end(),vektor.begin(),[dx,dy,ugaorot,faktorskal] (std::shared_ptr<Trougao>p)->std::shared_ptr<Trougao> { 
      
      
      
       p-> Transliraj(dx,dy);p->Rotiraj(ugaorot);p->Skaliraj(faktorskal); 
       
       return p;}  );
    
    
sort(vektor.begin(),vektor.end(),[] (std::shared_ptr<Trougao>p1,std::shared_ptr<Trougao>p2)->bool   { if(p1->DajPovrsinu()>p2->DajPovrsinu()) return false; return true; }  );
    
     std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    
    
    for_each(vektor.begin(),vektor.end(), [] (std::shared_ptr<Trougao>p)->void {  p->Ispisi();}        ); 
    
    
    
    
    
	return 0;
}