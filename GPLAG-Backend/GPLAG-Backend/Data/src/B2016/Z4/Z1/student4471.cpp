/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <map>
#include <cmath>
#include <set>
#include <vector>
#include <memory>
#include <new>
#include <algorithm>
#include <cmath>

typedef std::pair<double, double>Tacka;
const double eps = 1E-10;

class Trougao{
    private:
    Tacka T1,T2,T3;
    static bool NaPravoj(const Tacka &t1,const Tacka &t2,const Tacka &t3){return true;}; //implementirati
    static double DuzinaStranice(const Tacka &t1,const Tacka &t2); //implementirati
    static double VelUgla(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    static double Razdaljina(double x,double y);
    
    static bool Poredi3Stranice(const double &x1,const double &y1,const double &z1,const double &x2,const double &y2,const double &z2){
         if(Jednaki(x1,y1) && Jednaki(z1,x2) && Jednaki(y2,z2))return true; return false;
    }
    static bool Poredi3StraniceP(const double &x1,const double &y1,const double &z1,const double &x2,const double &y2,const double &z2){
        if(Jednaki(x1/y1,z1/x2) && Jednaki(z1/x2,y2/z2))return true; return false;
    }
    static bool Jednaki(const double &x,const double &y){
        if((x>0 && y<0) || (x<0 && y>0))return false;
        if(std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y)))return true;
        else return false;
    }
    
    public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    void Postavi(int indeks,const Tacka &t);
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    static double arcos(double x,double y,double z){
        double cosinus = (y*y+z*z-x*x)/(2*y*z);
    return std::acos(cosinus);
    }
    
    Tacka DajTjeme(int indeks) const{
        if(indeks<1 || indeks > 3)throw std::range_error("Nekorektan indeks");
        if(indeks == 1)return T1;
        else if(indeks==2)return T2;
        else return T3;
    }
    
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

Trougao::Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
    T1 = t1; T2 = t2; T3 = t3;
}

void Trougao::Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
    T1 = t1; T2 = t2; T3 = t3;
}

void Trougao::Postavi(int indeks,const Tacka &t){
    if(indeks<1 || indeks > 3)throw std::range_error("Nekorektan indeks");
    if(indeks == 1){if(Orijentacija(t,T2,T3)==0)throw std::domain_error("Nekorektne pozicije tjemena");T1 = t;}
    else if(indeks==2){if(Orijentacija(T1,t,T3)==0)throw std::domain_error("Nekorektne pozicije tjemena");T2 = t;}
    else {if(Orijentacija(T1,T2,t)==0)throw std::domain_error("Nekorektne pozicije tjemena");T3 = t;}
    
}

int Trougao::Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
    double test= t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    if(test>0)return 1;
    else if(test<0)return -1;
    else return 0;  //ako su kolinearne !
}

double Trougao::DajStranicu(int indeks)const{
    if(indeks<1 || indeks > 3)throw std::range_error("Nekorektan indeks");
    if(indeks==1)return DuzinaStranice(T2,T3);
    else if(indeks==2)return DuzinaStranice(T1,T3);
    else return DuzinaStranice(T1,T2);
}

double Trougao::DuzinaStranice(const Tacka &t1,const Tacka &t2){
    return std::sqrt(std::pow(t2.first-t1.first,2)+std::pow(t2.second-t1.second,2));   
}

double Trougao::DajUgao(int indeks) const {                               //IPLEMENTIRATI !!! BOLJE!
    if(indeks<1 || indeks > 3)throw std::range_error("Nekorektan indeks");
   if(indeks ==1)return VelUgla(T1,T2,T3);
    else if(indeks==2)return VelUgla(T2,T1,T3);
    else return VelUgla(T3,T1,T2);
  //  if(indeks==1)return arcos(DuzinaStranice(T2,T3),DuzinaStranice(T1,T2),DuzinaStranice(T1,T3));
    //else if(indeks==2)return arcos(DuzinaStranice(T1,T3),DuzinaStranice(T1,T2),DuzinaStranice(T2,T3));
    //return  arcos(DuzinaStranice(T1,T2),DuzinaStranice(T2,T3),DuzinaStranice(T1,T3));
    
}
                     
double Trougao::VelUgla(const Tacka &A,const Tacka &B,const Tacka &C){
    double a = DuzinaStranice(B,C), b = DuzinaStranice(A,C), c = DuzinaStranice(A,B);
    double cosinus = (b*b+c*c-a*a)/(2*b*c);
    return std::acos(cosinus);
    //return acos(cosinus);
}

Tacka Trougao::DajCentar() const{
    double x = (T1.first+T2.first + T3.first)/3;
    double y = (T1.second+T2.second + T3.second)/3;
    
   return {x,y};
}

double Trougao::DajObim() const{
    return DuzinaStranice(T1,T2)+DuzinaStranice(T1,T3)+DuzinaStranice(T2,T3);
}

double Trougao::DajPovrsinu() const{
    double test= std::fabs(T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second));
    return test/2;
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(T1,T2,T3)==1)return true;
    else return false;
}

bool Trougao::DaLiJeUnutra(const Tacka &T) const{             //IMPLEMENTRATI !!
    if( (Orijentacija(T1,T2,T3)==true && Orijentacija(T1,T2,T)==true && Orijentacija(T2,T3,T)==true && Orijentacija(T3,T1,T)==true) || 
   (Orijentacija(T1,T2,T3)==false && Orijentacija(T1,T2,T)==false && Orijentacija(T2,T3,T)==false && Orijentacija(T3,T1,T)==false) )return true;
    return false;
}

void Trougao::Ispisi() const{
    std::cout<<"(("<<T1.first<<","<<T1.second<<"),"<<"("<<T2.first<<","<<T2.second<<"),("<<T3.first<<","<<T3.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y){
    T1.first+=delta_x;T1.second+=delta_y;
    T2.first+=delta_x;T2.second+=delta_y;
    T3.first+=delta_x;T3.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    Tacka teziste(DajCentar());           //ovdje mozda treba dodat fabs
    double deltax,deltay;
    deltax = Razdaljina(t.first,teziste.first);
    deltay = Razdaljina(t.second,teziste.second);
    if(t.first<teziste.first)deltax=deltax*(-1);
    if(t.second<teziste.second)deltay = deltay*(-1);
    Transliraj(deltax,deltay);
}


void Trougao::Rotiraj(const Tacka &t, double ugao){//sta radit ako je ugao 0
    
    /*
    T1.first = t.first + (T1.first-t.first)*std::cos(ugao)-(T1.second-t.second)*std::sin(ugao);
    T1.second = t.second + (T1.first-t.first)*std::sin(ugao)+(T1.second-t.second)*std::cos(ugao);
    T2.first = t.first + (T2.first-t.first)*std::cos(ugao)-(T2.second-t.second)*std::sin(ugao);
    T2.second = t.second + (T2.first-t.first)*std::sin(ugao)+(T2.second-t.second)*std::cos(ugao);
    T3.first = t.first + (T3.first-t.first)*std::cos(ugao)-(T3.second-t.second)*std::sin(ugao);
    T3.second = t.second + (T3.first-t.first)*std::sin(ugao)+(T3.second-t.second)*std::cos(ugao);
    */
    T1 = std::make_pair(t.first + (T1.first-t.first)*std::cos(ugao)-(T1.second-t.second)*std::sin(ugao), t.second + (T1.first-t.first)*std::sin(ugao)+(T1.second-t.second)*std::cos(ugao));
    T2 =std::make_pair(t.first + (T2.first-t.first)*std::cos(ugao)-(T2.second-t.second)*std::sin(ugao),t.second + (T2.first-t.first)*std::sin(ugao)+(T2.second-t.second)*std::cos(ugao));
    T3 =std::make_pair(t.first + (T3.first-t.first)*std::cos(ugao)-(T3.second-t.second)*std::sin(ugao),t.second + (T3.first-t.first)*std::sin(ugao)+(T3.second-t.second)*std::cos(ugao));
    
    
}

void Trougao::Skaliraj(const Tacka &t, double k){
    if(k==0)throw std::domain_error("Nekorektan faktor skaliranja");
    T1.first = t.first + k*(T1.first-t.first);
    T1.second = t.second + k*(T1.second-t.second);
    T2.first = t.first + k*(T2.first-t.first);
    T2.second = t.second + k*(T2.second-t.second);
    T3.first = t.first + k*(T3.first-t.first);
    T3.second = t.second + k*(T3.second-t.second);
}

void Trougao::Rotiraj(double ugao){
    Tacka teziste(DajCentar());
    Rotiraj(teziste,ugao);
}

void Trougao::Skaliraj(double k){
    if(k==0)throw std::domain_error("Nekorektan faktor skaliranja");
    Skaliraj(DajCentar(),k);
}

                            
 bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){    //gdje god poredimo sada uredene parove trebamo formirati svoj preklopljeni oper jednakoost
                                                                       //sa tolerancijom epsilom
    std::set<Tacka> set1;
    set1.insert(t1.T1);set1.insert(t1.T2);set1.insert(t1.T3);
    std::set<Tacka> set2;
    set2.insert(t2.T1);set2.insert(t2.T2);set2.insert(t2.T3);
    return set1==set2;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
if(Trougao::Poredi3Stranice(t1.DajStranicu(1),t2.DajStranicu(1),t1.DajStranicu(2),t2.DajStranicu(2),t1.DajStranicu(3),t2.DajStranicu(3)) && Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T1,t2.T2,t2.T3)
                                                                    ||
Trougao::Poredi3Stranice(t1.DajStranicu(1),t2.DajStranicu(1),t1.DajStranicu(2),t2.DajStranicu(3),t1.DajStranicu(3),t2.DajStranicu(2)) && Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T1,t2.T3,t2.T2)                                                               
                                                                    ||
Trougao::Poredi3Stranice(t1.DajStranicu(1),t2.DajStranicu(2),t1.DajStranicu(2),t2.DajStranicu(1),t1.DajStranicu(3),t2.DajStranicu(3)) && Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T2,t2.T1,t2.T3)
                                                                    ||
Trougao::Poredi3Stranice(t1.DajStranicu(1),t2.DajStranicu(2),t1.DajStranicu(2),t2.DajStranicu(3),t1.DajStranicu(3),t2.DajStranicu(1)) && Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T2,t2.T3,t2.T1)
                                                                    ||
Trougao::Poredi3Stranice(t1.DajStranicu(1),t2.DajStranicu(3),t1.DajStranicu(2),t2.DajStranicu(1),t1.DajStranicu(3),t2.DajStranicu(2)) && Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T3,t2.T1,t2.T2)
                                                                    ||
Trougao::Poredi3Stranice(t1.DajStranicu(1),t2.DajStranicu(3),t1.DajStranicu(2),t2.DajStranicu(2),t1.DajStranicu(3),t2.DajStranicu(1)) && Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T3,t2.T2,t2.T1)

)return true;
    
    return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
if(Trougao::Poredi3StraniceP(t1.DajStranicu(1),t2.DajStranicu(1),t1.DajStranicu(2),t2.DajStranicu(2),t1.DajStranicu(3),t2.DajStranicu(3)) && Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T1,t2.T2,t2.T3)
                                                                    ||
Trougao::Poredi3StraniceP(t1.DajStranicu(1),t2.DajStranicu(1),t1.DajStranicu(2),t2.DajStranicu(3),t1.DajStranicu(3),t2.DajStranicu(2)) && Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T1,t2.T3,t2.T2)                                                              
                                                                    ||
Trougao::Poredi3StraniceP(t1.DajStranicu(1),t2.DajStranicu(2),t1.DajStranicu(2),t2.DajStranicu(1),t1.DajStranicu(3),t2.DajStranicu(3) )&& Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T2,t2.T1,t2.T3)
                                                                    ||
Trougao::Poredi3StraniceP(t1.DajStranicu(1),t2.DajStranicu(2),t1.DajStranicu(2),t2.DajStranicu(3),t1.DajStranicu(3),t2.DajStranicu(1) )&& Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T2,t2.T3,t2.T1)
                                                                    ||
Trougao::Poredi3StraniceP(t1.DajStranicu(1),t2.DajStranicu(3),t1.DajStranicu(2),t2.DajStranicu(1),t1.DajStranicu(3),t2.DajStranicu(2)) && Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T3,t2.T1,t2.T2)
                                                                    ||
Trougao::Poredi3StraniceP(t1.DajStranicu(1),t2.DajStranicu(3),t1.DajStranicu(2),t2.DajStranicu(2),t1.DajStranicu(3),t2.DajStranicu(1) )&& Trougao::Orijentacija(t1.T1,t1.T2,t1.T3)==Trougao::Orijentacija(t2.T3,t2.T2,t2.T1)

)return true;
    
    return false;
}    


double Trougao::Razdaljina(double x,double y){
    if(x>0 && y>0)return fabs(x-y);
    else if(x<0 && y<0)return fabs(x-y);
    else if(x<0 && y>0)return y-x;
    else return x-y;
}

int main ()
{
    
     std::cout<<"Koliko zelite kreirati trouglova: ";
     int n;
     std::cin>>n;
     std::vector<std::shared_ptr<Trougao>> v(n);
     Tacka t1,t2,t3;
     
     for(int i=0;i<n;i++){
         std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
         std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
         
         try{
         v[i] = std::make_shared<Trougao>(t1,t2,t3);
         }catch(std::domain_error temp){
             std::cout<<temp.what()<<", ponovite unos!"<<std::endl;
             i--;
         }
     }
     
     std::cout<<"Unesite vektor translacije (dx dy): ";
    double deltax,deltay;
    std::cin>>deltax>>deltay;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    double k;
    std::cin>>k;
    std::transform(v.begin(),v.end(),v.begin(),[deltax,deltay,ugao,k](std::shared_ptr<Trougao> p){p->Transliraj(deltax,deltay);p->Rotiraj(p->DajCentar(),ugao);
    try{p->Skaliraj(p->DajTjeme(1),k);}catch(std::domain_error temp){std::cout<<temp.what()<<std::endl;} return p;  });
    
	std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao> p,std::shared_ptr<Trougao> q){return p->DajPovrsinu()<q->DajPovrsinu();});
	
	std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
	
	//for(int i=0;i<n;i++)v[i]->Ispisi();
	std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao> p){p->Ispisi();std::cout<<std::endl;});
	Trougao tr = **std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao> p,std::shared_ptr<Trougao> q){return p->DajObim()<q->DajObim();});
	std::cout<<"Trougao sa najmanjim obimom: ";tr.Ispisi();
	std::cout<<std::endl;
	

	
	int brojac = 0;
	bool flag(true);
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        if(DaLiSuIdenticni(*v[i],*v[j])){
	            if(flag){std::cout<<"Parovi identicnih trouglova:"<<std::endl;flag=false;}
	            v[i]->Ispisi();std::cout<<" i ";v[j]->Ispisi();std::cout<<std::endl;brojac++;
	        }
	    }
	}
	
	if(brojac==0){std::cout<<"Nema identicnih trouglova!";std::cout<<std::endl;}
	brojac=0;
	flag = true;
	
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        if(DaLiSuPodudarni(*v[i],*v[j])){
	            if(flag){std::cout<<"Parovi podudarnih trouglova:"<<std::endl;flag=false;}
	            v[i]->Ispisi();std::cout<<" i ";v[j]->Ispisi();std::cout<<std::endl;brojac++;
	        }
	    }
	}
	
	if(brojac==0){std::cout<<"Nema podudarnih trouglova!";std::cout<<std::endl;}
	brojac=0;
	flag = true;
	
	for(int i=0;i<n;i++){
	    for(int j=i+1;j<n;j++){
	        if(DaLiSuSlicni(*v[i],*v[j])){
	            if(flag){std::cout<<"Parovi slicnih trouglova:"<<std::endl;flag=false;}
	            v[i]->Ispisi();std::cout<<" i ";v[j]->Ispisi();std::cout<<std::endl;brojac++;
	        }
	    }
	}
	
	if(brojac==0)std::cout<<"Nema slicnih trouglova!";
	brojac=0;
	
	
	return 0;
}




















