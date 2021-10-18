#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>
#include <set>
#include <vector>

typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka x[3];
static bool JesuLiJednaki(double x, double y, double Eps=1e-10) { return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y)); }
    public:
    
Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    x[0]=t1;
    x[1]=t2;
    x[2]=t3;
}
void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
    x[0]=t1;
    x[1]=t2;
    x[2]=t3;
    
}

void Postavi(int indeks, const Tacka &t) {
 if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");  
 
    x[indeks-1]=t;
   
               if (Orijentacija(x[0],x[1],x[2])==0) throw std::domain_error("Nekorektne pozicije tjemena");

    
}
static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    
double x=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);

if(x > 0) return 1;
if(x < 0) return -1;
else return 0;

}


Tacka DajTjeme(int indeks) const {
     if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");  
return x[indeks-1];
    
    
}

double DajStranicu(int indeks) const {      if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");  
    if (indeks == 1) return sqrt (((x[1].first-x[2].first)*(x[1].first-x[2].first))+((x[1].second-x[2].second)*(x[1].second-x[2].second)));
if (indeks == 2) return sqrt (((x[0].first-x[2].first)*(x[0].first-x[2].first))+((x[0].second-x[2].second)*(x[0].second-x[2].second)));
    return sqrt (((x[1].first-x[0].first)*(x[1].first-x[0].first))+((x[1].second-x[0].second)*(x[1].second-x[0].second)));
}
double DajUgao(int indeks) const {
    
         if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");  
         double ugao;
         if (indeks==1) ugao=acos( (DajStranicu(3)*DajStranicu(3)+DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1)) / (2.*DajStranicu(2)*DajStranicu(3)) );
         if (indeks==2) ugao=acos( (DajStranicu(1)*DajStranicu(1)+DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2)) / (2.*DajStranicu(3)*DajStranicu(1)) );
         if (indeks==3) ugao=acos( (DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3)) / (2.*DajStranicu(2)*DajStranicu(1)) );
        
        return ugao;

}
Tacka DajCentar() const {
    
 Tacka nova;
  nova.first = (x[0].first+x[1].first+x[2].first) / 3;
  nova.second = (x[0].second+x[1].second+x[2].second) / 3;
  return nova;
    
}
double DajObim() const {
    
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double DajPovrsinu() const {
   
   return abs( x[0].first*(x[1].second-x[2].second) - x[1].first*(x[0].second-x[2].second) + x[2].first*(x[0].second-x[1].second) ) / 2.;

    
}
bool DaLiJePozitivnoOrijentiran() const {
    
if (Orijentacija(x[0],x[1],x[2]) == 1) return true;
else return false;    
}
bool DaLiJeUnutra(const Tacka &t) const {
    
    return ( JesuLiJednaki(Orijentacija(x[0],x[1],x[2]),Orijentacija(x[0],x[1],t)) && JesuLiJednaki(Orijentacija(x[1],x[2],t),Orijentacija( x[0],x[1],t)) && JesuLiJednaki(Orijentacija(x[2],x[0],t),Orijentacija(x[0],x[1],t)));
}
void Ispisi() const {
    
    std::cout<<"(("<<x[0].first<<","<<x[0].second<<"),("<<x[1].first<<","<<x[1].second<<"),("<<x[2].first<<","<<x[2].second<<"))";
}
void Transliraj(double delta_x, double delta_y) {
    
x[0].first+=delta_x;
x[1].first+=delta_x;    
x[2].first+=delta_x;   

x[0].second+=delta_y;    
x[1].second+=delta_y;    
x[2].second+=delta_y;    
    
}
void Centriraj(const Tacka &t) {
    
    double z=t.first-DajCentar().first;
    double y=t.second-DajCentar().second;
    
    x[0].first+=z;
    x[1].first+=z;    
    x[2].first+=z;   

    x[0].second+=y;    
    x[1].second+=y;    
    x[2].second+=y; 
    
}
void Rotiraj(const Tacka &t, double ugao) {
   
   double a,b,c;
    a = t.first + (x[0].first-t.first)*cos(ugao)-(x[0].second-t.second)*sin(ugao);
    b = t.first + (x[1].first-t.first)*cos(ugao)-(x[1].second-t.second)*sin(ugao);
    c = t.first + (x[2].first-t.first)*cos(ugao)-(x[2].second-t.second)*sin(ugao);


    x[0].second = t.second + (x[0].first-t.first)*std::sin(ugao) + (x[0].second - t.second)*std::cos(ugao);    
    x[1].second = t.second + (x[1].first-t.first)*std::sin(ugao) + (x[1].second - t.second)*std::cos(ugao);    
    x[2].second = t.second + (x[2].first-t.first)*std::sin(ugao) + (x[2].second - t.second)*std::cos(ugao);   
    
x[0].first=a; x[1].first=b; x[2].first=c;
    
}
void Skaliraj(const Tacka &t, double faktor) { if (JesuLiJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja"); 

        x[0].first = t.first + (faktor * (x[0].first - t.first));
        x[1].first = t.first + (faktor * (x[1].first - t.first));
        x[2].first = t.first + (faktor * (x[2].first - t.first));

        x[0].second = t.second + (faktor * (x[0].second - t.second));
        x[1].second = t.second + (faktor * (x[1].second - t.second));
        x[2].second = t.second + (faktor * (x[2].second - t.second));


}
void Rotiraj(double ugao) {
    
    x[0].first = DajCentar().first+(x[0].first-DajCentar().first)*cos(ugao)-(x[0].second-DajCentar().second)*sin(ugao);
    x[1].first = DajCentar().first+(x[1].first-DajCentar().first)*cos(ugao)-(x[1].second-DajCentar().second)*sin(ugao);
    x[2].first = DajCentar().first+(x[2].first-DajCentar().first)*cos(ugao)-(x[2].second-DajCentar().second)*sin(ugao);


    x[0].second = DajCentar().second + (x[0].first-DajCentar().first)*std::sin(ugao)+(x[0].second - DajCentar().second)*std::cos(ugao);    
    x[1].second = DajCentar().second + (x[1].first-DajCentar().first)*std::sin(ugao)+(x[1].second - DajCentar().second)*std::cos(ugao);    
    x[2].second = DajCentar().second + (x[2].first-DajCentar().first)*std::sin(ugao)+(x[2].second - DajCentar().second)*std::cos(ugao);    

    
}
void Skaliraj(double faktor) { if (JesuLiJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja"); 
    
        x[0].first = DajCentar().first + (faktor * (x[0].first - DajCentar().first));
        x[1].first = DajCentar().first + (faktor * (x[1].first - DajCentar().first));
        x[2].first = DajCentar().first + (faktor * (x[2].first - DajCentar().first));

        x[0].second = DajCentar().second + (faktor * (x[0].second - DajCentar().second));
        x[1].second = DajCentar().second + (faktor * (x[1].second - DajCentar().second));
        x[2].second = DajCentar().second + (faktor * (x[2].second - DajCentar().second));
}
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {

int brojac(0);
if ( (JesuLiJednaki(t1.x[0].first, t2.x[0].first) && JesuLiJednaki(t1.x[0].second, t2.x[0].second)) || (JesuLiJednaki(t1.x[0].first, t2.x[1].first) && JesuLiJednaki(t1.x[0].second, t2.x[1].second)) || (JesuLiJednaki(t1.x[0].first, t2.x[2].first) && JesuLiJednaki(t1.x[0].second, t2.x[2].second))) brojac++;

if ( (JesuLiJednaki(t1.x[1].first, t2.x[0].first) && JesuLiJednaki(t1.x[1].second, t2.x[0].second)) || (JesuLiJednaki(t1.x[1].first, t2.x[1].first) && JesuLiJednaki(t1.x[1].second, t2.x[1].second)) || (JesuLiJednaki(t1.x[1].first, t2.x[2].first) && JesuLiJednaki(t1.x[1].second, t2.x[2].second))) brojac++;

if ( (JesuLiJednaki(t1.x[2].first, t2.x[0].first) && JesuLiJednaki(t1.x[2].second, t2.x[0].second)) || (JesuLiJednaki(t1.x[2].first, t2.x[1].first) && JesuLiJednaki(t1.x[2].second, t2.x[1].second)) || (JesuLiJednaki(t1.x[2].first, t2.x[2].first) && JesuLiJednaki(t1.x[2].second, t2.x[2].second))) brojac++;

if (brojac==3) return true;
else return false;
    
}
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
  
        int minindeks=1;
      int maxindeks=1;
   int srednjiindeks=1;

   for (int i = 1; i <= 3; i++) {
       
      if (t1.DajStranicu(i) < t1.DajStranicu(minindeks) ) minindeks=i;
            if (t1.DajStranicu(i) > t1.DajStranicu(maxindeks) ) maxindeks=i;

   }
   
   
      for (int i = 1; i <= 3; i++) {
       
if (i != minindeks && i != maxindeks) srednjiindeks=i;
   }
      int minindeks2=1;
      int maxindeks2=1;
   int srednjiindeks2=1;

   for (int i = 1; i <= 3; i++) {
       
      if (t2.DajStranicu(i) < t2.DajStranicu(minindeks2) ) minindeks2=i;
            if (t2.DajStranicu(i) > t2.DajStranicu(maxindeks2) ) maxindeks2=i;

   }
   
   
      for (int i = 1; i <= 3; i++) {
       
if (i != minindeks2 && i != maxindeks2) srednjiindeks2=i;
   }
   int brojac(0);
   
   if(Trougao::Orijentacija(t1.DajTjeme(minindeks), t1.DajTjeme(srednjiindeks), t1.DajTjeme(maxindeks))==Trougao::Orijentacija(t2.DajTjeme(minindeks2), t2.DajTjeme(srednjiindeks2), t2.DajTjeme(maxindeks2))) brojac++;
  
  if (JesuLiJednaki(t1.DajStranicu(minindeks),t2.DajStranicu(minindeks2)) && JesuLiJednaki(t1.DajStranicu(maxindeks),t2.DajStranicu(maxindeks2)) && JesuLiJednaki(t1.DajStranicu(srednjiindeks),t2.DajStranicu(srednjiindeks2))) brojac++;

if (brojac==2 )return true;
return false;


}
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
   
   int minindeks=1;
      int maxindeks=1;
   int srednjiindeks=1;

   for (int i = 1; i <= 3; i++) {
       
      if (t1.DajStranicu(i) < t1.DajStranicu(minindeks) ) minindeks=i;
            if (t1.DajStranicu(i) > t1.DajStranicu(maxindeks) ) maxindeks=i;

   }
   
   
      for (int i = 1; i <= 3; i++) {
       
if (i != minindeks && i != maxindeks) srednjiindeks=i;
   }
      int minindeks2=1;
      int maxindeks2=1;
   int srednjiindeks2=1;

   for (int i = 1; i <= 3; i++) {
       
      if (t2.DajStranicu(i) < t2.DajStranicu(minindeks2) ) minindeks2=i;
            if (t2.DajStranicu(i) > t2.DajStranicu(maxindeks2) ) maxindeks2=i;

   }
   
   
      for (int i = 1; i <= 3; i++) {
       
if (i != minindeks2 && i != maxindeks2) srednjiindeks2=i;
   }
   int brojac(0);
   
   if(Trougao::Orijentacija(t1.DajTjeme(minindeks), t1.DajTjeme(srednjiindeks), t1.DajTjeme(maxindeks))==Trougao::Orijentacija(t2.DajTjeme(minindeks2), t2.DajTjeme(srednjiindeks2), t2.DajTjeme(maxindeks2))) brojac++;
  
 double a1 = t1.DajStranicu(maxindeks);
  double a2 = t2.DajStranicu(maxindeks2);
 double b1 = t1.DajStranicu(srednjiindeks);
 double b2 = t2.DajStranicu(srednjiindeks2);
 double c1 = t1.DajStranicu(minindeks);
 double c2 = t2.DajStranicu(minindeks2);

  
    if (JesuLiJednaki((a1*b1)/(a2*b2), (a1*c1)/(a2*c2)) and JesuLiJednaki((a1*c1)/(a2*c2), (b1*c1)/(b2*c2))) brojac++;

if (brojac==2 )return true;
return false;

}
};
int main ()
{
   
        

    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> vektor;
   try 
   {
    for (int i = 0; i < n; i++) {
        
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka t1;
        std::cin>>t1.first;
        std::cin>>t1.second;

        Tacka t2;
         std::cin>>t2.first;
        std::cin>>t2.second;

        Tacka t3;
         std::cin>>t3.first;
        std::cin>>t3.second;
         try
            {
                std::shared_ptr<Trougao> p = std::make_shared<Trougao> (t1,t2,t3);
                vektor.push_back(p);
            }
            catch(std::domain_error izuzetak)
            {
                std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
                i--;
            }
    }
   }  
    catch(std::bad_alloc)
    {
        std::cout << "Problemi s memorijom!\n";
    }
  

std::cout<<"Unesite vektor translacije (dx dy): ";
double deltax;
double deltay;
std::cin>>deltax;
std::cin>>deltay;
std::transform(vektor.begin(), vektor.end(), vektor.begin(), [deltax, deltay] (std::shared_ptr<Trougao> p) { (*p).Transliraj(deltax, deltay); return p;});
std::cout<<"Unesite ugao rotacije: ";
double ugao;
std::cin>>ugao;
std::transform(vektor.begin(), vektor.end(), vektor.begin(), [ugao] (std::shared_ptr<Trougao> p) { (*p).Rotiraj((*p).DajCentar(), ugao); return p;});
std::cout<<"Unesite faktor skaliranja: ";
double faktor;
std::cin>>faktor;
std::transform(vektor.begin(), vektor.end(), vektor.begin(), [faktor] (std::shared_ptr<Trougao> p) { (*p).Skaliraj((*p).DajTjeme(1), faktor); return p;});

std::sort(vektor.begin(), vektor.end(), [] (std::shared_ptr<Trougao> p, std::shared_ptr<Trougao> q) { return (*p).DajPovrsinu() < (*q).DajPovrsinu(); } );
std::cout<<"Trouglovi nakon obavljenih transformacija:";
std::cout<<std::endl;
std::for_each(vektor.begin(), vektor.end(), [] (std::shared_ptr<Trougao> p ) { (*p).Ispisi(); std::cout<<std::endl; return p; } );

auto p=std::min_element(vektor.begin(), vektor.end(), [] (std::shared_ptr<Trougao> p, std::shared_ptr<Trougao> q) { return (*p).DajObim() < (*q).DajObim(); } );
std::cout<<"Trougao sa najmanjim obimom: ";
(*p)->Ispisi();
std::vector < std::pair < std::shared_ptr<Trougao>,std::shared_ptr<Trougao> > > identicni;
for (int i = 0; i < n; i++) {
    
  for (int j=i+1; j < n; j++) {
      
     if ( DaLiSuIdenticni(*vektor[i],*vektor[j]) ) identicni.push_back(std::make_pair(vektor[i],vektor[j]));
    
    }
}
std::vector < std::pair < std::shared_ptr<Trougao>,std::shared_ptr<Trougao> > > podudarni;
for (int i = 0; i < n; i++) {
    
  for (int j=i+1; j < n; j++) if ( DaLiSuPodudarni(*vektor[i],*vektor[j]) ) podudarni.push_back(std::make_pair(vektor[i],vektor[j]));
    
}

std::vector < std::pair < std::shared_ptr<Trougao>,std::shared_ptr<Trougao> > > slicni;
for (int i = 0; i < n; i++) {
    
  for (int j=i+1; j < n; j++) {
      
     if ( DaLiSuSlicni(*vektor[i],*vektor[j]) ) slicni.push_back(std::make_pair(vektor[i],vektor[j]));
    
    }
}
std::cout<<std::endl;
if (identicni.size()==0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
else { std::cout<<"Parovi identicnih trouglova:";
std::cout<<std::endl;
for (auto p = identicni.begin(); p != identicni.end(); p++) {
    
    p->first->Ispisi();
    std::cout<<" i ";
        p->second->Ispisi();    

        std::cout<<std::endl;

}
}
if (podudarni.size()==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
else {
std::cout<<"Parovi podudarnih trouglova:";
std::cout<<std::endl;
for (auto p = podudarni.begin(); p != podudarni.end(); p++) {
    
    p->first->Ispisi();
    std::cout<<" i ";
        p->second->Ispisi();    
    std::cout<<std::endl;

    
}
}
if (slicni.size()==0) std::cout<<"Nema slicnih trouglova!"<<std::endl;
else {
std::cout<<"Parovi slicnih trouglova:";
std::cout<<std::endl;
for (auto p = slicni.begin(); p != slicni.end(); p++) {
    
    p->first->Ispisi();
    std::cout<<" i ";
        p->second->Ispisi();    

    std::cout<<std::endl;
}
}
for (int i=0; i<identicni.size(); i++) { 
	for (int j=i+1; j<identicni.size(); j++ )
	{
	if (identicni[i]==identicni[j]) {
	
identicni.erase(identicni.begin() + j);
	j--;
	}
	}
}	

for (int i=0; i<podudarni.size(); i++) { 
	for (int j=i+1; j<podudarni.size(); j++ )
	{
	if (podudarni[i]==podudarni[j]) {
	
podudarni.erase(podudarni.begin() + j);
	j--;
	}
	}
}	

for (int i=0; i<slicni.size(); i++) { 
	for (int j=i+1; j<slicni.size(); j++ )
	{
	if (slicni[i]==slicni[j]) {
	
slicni.erase(slicni.begin() + j);
	j--;
	}
	}
}	

	return 0;
}