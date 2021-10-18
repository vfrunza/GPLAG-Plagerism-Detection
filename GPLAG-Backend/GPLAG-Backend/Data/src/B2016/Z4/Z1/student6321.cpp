/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include<iostream>
#include<utility>
#include<stdexcept>
#include<vector>
#include<new>
#include<cmath>
#include<memory>
#include<algorithm>
typedef std::pair<double,double> Tacka;

class Trougao{
    
    Tacka A;
    Tacka B;
    Tacka C;
    
   static bool ProvjeraIndeksa(int indeks);
   static double Pomocna(const Tacka &t1,const Tacka &t2,const Tacka &t3);
   static bool Poredi(double a,double b);
   static bool PorediTacke(const Tacka &t1,const Tacka &t2);
   static double Duzina(const Tacka &t1,const Tacka &t2);
   static double Ugao(double a, double b,double c);
   
          
    
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
    void Transliraj(double delta_x,double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t,double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};


 bool Trougao::ProvjeraIndeksa(int indeks){
    std::vector<int> a{1,2,3};
    for(int i=0;i<3;i++){
        if(indeks==a[i]) return true;
        
    }
    return false;
    
}

double Trougao::Pomocna(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}

bool Trougao::Poredi(double a,double b){
    const double eps(1e-10);
    return std::fabs(a-b)<=eps;
}

bool Trougao::PorediTacke(const Tacka &t1,const Tacka &t2){
    
    return (Poredi(t1.first,t2.first) && Poredi(t1.second,t2.second));
    
    
}

double Trougao::Duzina(const Tacka &t1,const Tacka &t2){
    
    return std::sqrt(((t2.first-t1.first)*(t2.first-t1.first))+((t2.second-t1.second)*(t2.second-t1.second)));
}

double Trougao::Ugao(double a, double b, double c){
    
    auto p((b*b+c*c-a*a)/(2*b*c));
    
   // std::cout<<"---"<<b*b+c*c-a*a<<"---";
    
    return std::acos(p);
}

Trougao::Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    Postavi(t1,t2,t3);
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2,const Tacka &t3){
    A=t1; B=t2; C=t3;
    if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(!ProvjeraIndeksa(indeks)) throw std::range_error ("Nekorektan indeks");
    
    if(indeks==1) A=t;
    if(indeks==2) B=t;
    if(indeks==3) C=t;
    
    if(Orijentacija(A,B,C)==0) throw std::domain_error("Nekorektne pozicije tjemena");
}

 int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    auto a(Pomocna(t1,t2,t3));
    
    if(Poredi(a,0)) return 0;
    else if(a>0) return 1;
    else return -1;
    
}
Tacka Trougao::DajTjeme(int indeks) const{
    if(!ProvjeraIndeksa(indeks)) throw std::range_error ("Nekorektan indeks");
    if(indeks==1) return A;
    if(indeks==2) return B;
    if(indeks==3) return C;
}

double Trougao::DajStranicu(int indeks) const{
     if(!ProvjeraIndeksa(indeks)) throw std::range_error ("Nekorektan indeks");
    if(indeks==1) return Duzina(B,C);
    if(indeks==2) return Duzina(A,C);
    if(indeks==3) return Duzina(A,B);
}

double Trougao::DajUgao(int indeks) const{
      if(!ProvjeraIndeksa(indeks)) throw std::range_error ("Nekorektan indeks");
      
      if(indeks==1) return Ugao(DajStranicu(1),DajStranicu(2),DajStranicu(3));
      if(indeks==2) return Ugao (DajStranicu(2),DajStranicu(3),DajStranicu(1));
      if(indeks==3) return Ugao(DajStranicu(3),DajStranicu(1),DajStranicu(2));
      
}

Tacka Trougao::DajCentar() const{
    Tacka centar;
    
    centar.first=(A.first+B.first+C.first)/3.;
    centar.second=(A.second+B.second+C.second)/3.;
    return centar;

}

double Trougao::DajObim() const{
    
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu() const{
    return 1./2*fabs(Pomocna(A,B,C));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    return (Orijentacija(A,B,C)==1);
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    
    return((Orijentacija(A,B,C)==Orijentacija(A,B,t)) && (Orijentacija(A,B,C)==Orijentacija(B,C,t)) && (Orijentacija(A,B,C)==Orijentacija(C,A,t))) ;
}

void Trougao::Ispisi() const{
    std::cout<<"(("<<A.first<<","<<A.second<<"),("<<B.first<<","<<B.second<<"),("<<C.first<<","<<C.second<<"))";
}

void Trougao::Transliraj(double delta_x,double delta_y){
   
    
    A.first+=delta_x;
    B.first+=delta_x;
    C.first+=delta_x;
   
    A.second+=delta_y;
    B.second+=delta_y;
    C.second+=delta_y;
   
   
    
    
}
void Trougao::Centriraj(const Tacka &t){
    
    Tacka Centar(DajCentar());
    
    auto delta_x(t.first-Centar.first);
    auto delta_y(t.second-Centar.second);
    
   
    
    Transliraj(delta_x,delta_y);
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    
    Tacka t1(A),t2(B),t3(C);
    A.first=t.first+(t1.first-t.first)*std::cos(ugao)-(t1.second-t.second)*std::sin(ugao);
    A.second=t.second+(t1.first-t.first)*std::sin(ugao)+(t1.second-t.second)*std::cos(ugao);
    
    B.first=t.first+(t2.first-t.first)*std::cos(ugao)-(t2.second-t.second)*std::sin(ugao);
    B.second=t.second+(t2.first-t.first)*std::sin(ugao)+(t2.second-t.second)*std::cos(ugao);
    
    C.first=t.first+(t3.first-t.first)*std::cos(ugao)-(t3.second-t.second)*std::sin(ugao);
    C.second=t.second+(t3.first-t.first)*std::sin(ugao)+(t3.second-t.second)*std::cos(ugao);
    
}
void Trougao::Skaliraj(const Tacka &t,double faktor){
    
    if(Poredi(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
   
   auto faktor2(std::fabs(faktor));  
   
    A.first=t.first+faktor2*(A.first-t.first);
    A.second=t.second+faktor2*(A.second-t.second);
    
    B.first=t.first+faktor2*(B.first-t.first);
    B.second=t.second+faktor2*(B.second-t.second);
    
    C.first=t.first+faktor2*(C.first-t.first);
    C.second=t.second+faktor2*(C.second-t.second);
   
    if(faktor<0){
        
    const double pi(4*std::atan(1));
    Rotiraj(pi);
        
    }
}

void Trougao::Rotiraj(double ugao){
 Tacka centar(DajCentar());
 Rotiraj(centar,ugao);
 
}

void Trougao::Skaliraj(double faktor){
    Tacka centar(DajCentar());
    Skaliraj(centar,faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    
   
    if(Trougao::PorediTacke(t1.A,t2.A)){
        if(Trougao::PorediTacke(t1.B,t2.B) && Trougao::PorediTacke(t1.C,t2.C)) return true;
        if(Trougao::PorediTacke(t1.B,t2.C) && Trougao::PorediTacke(t1.C,t2.B)) return true;
    }
    if(Trougao::PorediTacke(t1.A,t2.B)){
        if(Trougao::PorediTacke(t1.B,t2.A) && Trougao::PorediTacke(t1.C,t2.C)) return true;
        if(Trougao::PorediTacke(t1.B,t2.C) && Trougao::PorediTacke(t1.C,t2.A)) return true;
    }
    if(Trougao::PorediTacke(t1.A,t2.C)){
        if(Trougao::PorediTacke(t1.B,t2.A) && Trougao::PorediTacke(t1.C,t2.B)) return true;
        if(Trougao::PorediTacke(t1.B,t2.B) && Trougao::PorediTacke(t1.C,t2.A)) return true;
        
    }
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
    
    if(DaLiSuIdenticni(t1,t2)) return true;
    
   bool p(false);
   double  a(t1.DajStranicu(1)),x(t2.DajStranicu(1)),b(t1.DajStranicu(2)),y(t2.DajStranicu(2)),c(t1.DajStranicu(3)),z(t2.DajStranicu(3));

   Tacka pomocna1(t1.DajTjeme(1));
   
   
   int tjeme(0);
     
    if(Trougao::Poredi(a,x)){
      
       tjeme=1;
        if(Trougao::Poredi(b,y) && Trougao::Poredi(c,z)) p=true;
        if(Trougao::Poredi(b,z) && Trougao::Poredi(c,y)) p=true;
        
    }
    if(Trougao::Poredi(a,y)){
        
        tjeme=2;
        if(Trougao::Poredi(b,x) && Trougao::Poredi(c,z)) p=true;
        if(Trougao::Poredi(b,z) && Trougao::Poredi(c,x)) p=true;
        
    }
    if(Trougao::Poredi(a,z)){
  
       tjeme=3;
        if(Trougao::Poredi(b,x) && Trougao::Poredi(c,y)) p=true;
        if(Trougao::Poredi(b,y) && Trougao::Poredi(c,x)) p=true;
    }
    
    if(!p) return false;
    else{
       
       auto t22(t2);
       
       auto centar1(t1.DajCentar());
       
       t22.Centriraj(centar1);
       
       Tacka pomocna2(t22.DajTjeme(tjeme));
       
       auto nasuprotna(Trougao::Duzina(pomocna1,pomocna2));
       auto p1(Trougao::Duzina(centar1,pomocna1)), p2(Trougao::Duzina(centar1,pomocna2));
       
 
       
       const double pi(4*std::atan(1));
       auto ugao(Trougao::Ugao(nasuprotna,p1,p2));
 
      auto t222(t22);
       
       t22.Rotiraj(ugao);
       
     bool pr1(DaLiSuIdenticni(t1,t22));
     if(pr1) return true;
     else{
         ugao=2*pi-ugao;
         t222.Rotiraj(ugao);
         return DaLiSuIdenticni(t1,t222);
     }

    }
 
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){


    if(DaLiSuIdenticni(t1,t2) || DaLiSuPodudarni(t1,t2)) return true;
    auto t22(t2);
    bool provjera(false);
    double  a(t1.DajStranicu(1)),x(t2.DajStranicu(1)),b(t1.DajStranicu(2)),y(t2.DajStranicu(2)),c(t1.DajStranicu(3)),z(t2.DajStranicu(3));

    double k(0);
    int tjeme;
    if(Trougao::Poredi(a/x,b/y) && Trougao::Poredi(a/x,c/z)) {
        provjera=true;
        k=a/x;
        tjeme=1;
       
    }
    
     if(Trougao::Poredi(a/x,b/z) && Trougao::Poredi(a/x,c/y)) {
        provjera=true;
        k=a/x;
        tjeme=1;
       
    }
     if(Trougao::Poredi(a/y,b/x) && Trougao::Poredi(a/y,c/z)) {
         
        provjera=true;
        k=a/y;
        
        tjeme=2;
    }
     if(Trougao::Poredi(a/y,b/z) && Trougao::Poredi(a/y,c/x)) {
        provjera=true;
        k=a/y;
       tjeme=2;
    }
    if(Trougao::Poredi(a/z,b/x) && Trougao::Poredi(a/z,c/y)) {
        provjera=true;
        k=a/z;
        tjeme=3;
    }
     if(Trougao::Poredi(a/z,b/y) && Trougao::Poredi(a/z,c/x)) {
        provjera=true;
        k=a/z;
        tjeme=3;
    }
   
   if(!provjera){
       return false;
       
   }
   else{

       t22.Skaliraj(k);

       return DaLiSuPodudarni(t22,t1);
      
   }

    
    
}


int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    
    int n;
    std::cin>>n;
    
   std::vector<std::shared_ptr<Trougao>> v(n,nullptr);
   for(int i=0;i<n;i++){
       std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
       double x1,x2,x3,y1,y2,y3;
       
       std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
       try{
       
       v[i]=(std::make_shared<Trougao> (Trougao(std::make_pair(x1,y1),std::make_pair(x2,y2),std::make_pair(x3,y3))));
       }catch(std::domain_error e){
           std::cout<<e.what()<<", ponovite unos!"<<std::endl;
           i--;
       }
      
   }
    std::cout<<"Unesite vektor translacije (dx dy): ";
       double dx,dy;
       std::cin>>dx>>dy;
       
       std::cout<<"Unesite ugao rotacije: ";
       double ugao;
       std::cin>>ugao;
       std::cout<<"Unesite faktor skaliranja: ";
       double faktor;
       std::cin>>faktor;
       std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
       
  
           
       std::transform(v.begin(),v.end(),v.begin(),[dx,dy,ugao,faktor](std::shared_ptr<Trougao> t)  {t->Transliraj(dx,dy);t->Rotiraj(t->DajCentar(),ugao);t->Skaliraj(t->DajTjeme(1),faktor);
           return t;
       });
         std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
           return t1->DajPovrsinu()<t2->DajPovrsinu();
        });
         std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> t){t->Ispisi();std::cout<<std::endl;});
         
         std::cout<<"Trougao sa najmanjim obimom: ";
    
     (*std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){return t1->DajObim()<t2->DajObim();}))->Ispisi();
   
  
 bool pr(false);
 for(int i=0;i<n-1;i++){
     for(int j=i;j<n;j++){
         if(i==j) continue;
         if(DaLiSuIdenticni(*v[i],*v[j])){
             std::cout<<"\nParovi identicnih trouglova:"<<std::endl;
             v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi(); std::cout<<std::endl;
             pr=true;
         }
        
     }
 }
 if(!pr) std::cout<<"\nNema identicnih trouglova!\n";
 
 
 int br(0);

  for(int i=0;i<n-1;i++){
     for(int j=i;j<n;j++){
         if(i==j) continue;
         if(DaLiSuPodudarni(*v[i],*v[j])){
             br++;
             if(br==1) std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
             v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi(); std::cout<<std::endl;
            
         }
     }
 }
 if(br==0) std::cout<<"Nema podudarnih trouglova!\n";
 int br2(0);

  for(int i=0;i<n-1;i++){
     for(int j=i;j<n;j++){
         if(i==j) continue;
         if(DaLiSuSlicni(*v[i],*v[j])){
             br2++;
             if(br2==1) std::cout<<"Parovi slicnih trouglova:"<<std::endl;
             v[i]->Ispisi(); std::cout<<" i "; v[j]->Ispisi(); std::cout<<std::endl;
         }
     }
 }
 if(br2==0) std::cout<<"Nema slicnih trouglova!\n";
   
   
	return 0;
}