/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <algorithm>
#include <memory>

#define PI 4*atan(1)
#define EPSILON pow(10, (-10))

using namespace std;

class Kugla {
    
    double x , Y, Z, r;
    
    public:
    
    explicit Kugla(double r = 0) { Kugla::x=0; Kugla::Y=0; Kugla::Z=0; Kugla::r=r; }
    
Kugla(double X, double Y, double Z, double r = 0) { if (r<0) throw domain_error ("Ilegalan popluprecnik");
Kugla::x=X; Kugla::Y=Y; Kugla::Z=Z; Kugla::r=r; }

explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) { if (r<0) throw domain_error ("Ilegalan popluprecnik");

    tie(Kugla::x,Kugla::Y,Kugla::Z) = centar; 
    Kugla::r=r;
}

double DajX() const { return x; }

double DajY() const { return Y; }

double DajZ() const { return Z; }

std::tuple<double, double, double> DajCentar() const { return tie(x,Y,Z); }

double DajPoluprecnik() const { return r; }

double DajPovrsinu() const { return 4*r*r*PI; }

double DajZapreminu() const { 
    return 4*r*r*r*PI/3; 
}

Kugla &PostaviX(double x) { Kugla::x=x; return *this; }
Kugla &PostaviY(double y) { Kugla::Y=y; return *this; }

Kugla &PostaviZ(double z) { Kugla::Z=z; return *this; }

Kugla &PostaviCentar(double x, double y, double z) { Kugla::x=x; Kugla::Y=y; Kugla::Z=z; return *this; }

Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { tie(x,Y,Z)=centar; return *this;}
    
Kugla &PostaviPoluprecnik(double p) { Kugla::r=p; if(p<0) throw domain_error ("Ilegalan poluprecnik"); return *this; }

void Ispisi() const;

void Transliraj(double delta_x, double delta_y, double delta_z) {
    x+=delta_x;
    Y+=delta_y;
    Z+=delta_z;
}

friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) { if(abs(k1.DajPoluprecnik() - k2.DajPoluprecnik())<EPSILON*( abs( k1.DajPoluprecnik()) + abs (k2.DajPoluprecnik() ) ) ) return true; else return false; }

friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    
    if(abs(k1.DajX() - k2.DajX())<EPSILON*( abs( k1.DajX()) + abs (k2.DajX()) ) ) {
        if(abs(k1.DajY() - k2.DajY())<EPSILON*( abs( k1.DajY()) + abs (k2.DajY()) ) ) {
            if(abs(k1.DajZ() - k2.DajZ())<EPSILON*( abs( k1.DajZ()) + abs (k2.DajZ()) ) ) return true ;
    }
    }
    
    
    else 
    return false; 
    
}
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
bool DaLiSadrzi(const Kugla &k) const;
friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) { 
    return  sqrt ( pow((k2.DajX()-k1.DajX()),2) + pow((k2.DajY()-k1.DajY()),2) + pow((k2.DajZ()-k1.DajZ()),2) ); }
};

void Kugla::Ispisi () const {
    cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<endl;
}

 bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
     if(abs(k1.DajPoluprecnik() - k2.DajPoluprecnik() ) < EPSILON*( abs( k1.DajPoluprecnik()) + abs (k2.DajPoluprecnik() ) ) ) {
         
     if(abs(k1.DajX() - k2.DajX())<EPSILON*( abs( k1.DajX()) + abs (k2.DajX()) ) ) {
        if(abs(k1.DajY() - k2.DajY())<EPSILON*( abs( k1.DajY()) + abs (k2.DajY()) ) ) {
            if(abs(k1.DajZ() - k2.DajZ())<EPSILON*( abs( k1.DajZ()) + abs (k2.DajZ()) ) ) return true ;
        }
     }
     }
     else return false;
 }
 
 bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
     double udaljenost = sqrt ( pow((k2.DajX()-k1.DajX()),2) + pow((k2.DajY()-k1.DajY()),2) + pow((k2.DajZ()-k1.DajZ()),2) );
     
     if((k1.DajPoluprecnik()+k2.DajPoluprecnik()) == udaljenost) return true;
     else
     return false;
 }
 
 bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
     double veci, manji;
     if(k1.DajPoluprecnik()>k2.DajPoluprecnik()) { 
         veci=k1.DajPoluprecnik();
         manji=k2.DajPoluprecnik();
         
           double udaljenost = sqrt ( pow((k2.DajX()-k1.DajX()),2) + pow((k2.DajY()-k1.DajY()),2) + pow((k2.DajZ()-k1.DajZ()),2) );
           
           if((udaljenost+manji)==veci) return true;
         
 } 
 if(k1.DajPoluprecnik()<k2.DajPoluprecnik()) {
       manji=k1.DajPoluprecnik();
         veci=k2.DajPoluprecnik();
         
          double udaljenost = sqrt ( pow((k2.DajX()-k1.DajX()),2) + pow((k2.DajY()-k1.DajY()),2) + pow((k2.DajZ()-k1.DajZ()),2) );
           
           if((udaljenost+manji)==veci) return true;
 }
 
 return false;
 }
 
 
 bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
  
  double manji, veci;
  
   if(k1.DajPoluprecnik()<k2.DajPoluprecnik()) {
       
       manji=k1.DajPoluprecnik();
         veci=k2.DajPoluprecnik();
   double udaljenost = sqrt ( pow((k2.DajX()-k1.DajX()),2) + pow((k2.DajY()-k1.DajY()),2) + pow((k2.DajZ()-k1.DajZ()),2) );
   
   if(udaljenost<veci) return true;
 }
 
   if(k1.DajPoluprecnik()>k2.DajPoluprecnik()) {
       veci=k1.DajPoluprecnik();
         manji=k2.DajPoluprecnik();
   double udaljenost = sqrt ( pow((k2.DajX()-k1.DajX()),2) + pow((k2.DajY()-k1.DajY()),2) + pow((k2.DajZ()-k1.DajZ()),2) );
   
   if(udaljenost<veci) return true;
 }
 
 return false;
 }
 
  bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) { 
      
      if(DaLiSuIdenticne(k1,k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1))    
      return false;
  
   double udaljenost = sqrt ( pow((k2.DajX()-k1.DajX()),2) + pow((k2.DajY()-k1.DajY()),2) + pow((k2.DajZ()-k1.DajZ()),2) );
   
   if(udaljenost<(k1.DajPoluprecnik()+k2.DajPoluprecnik()) &&  (udaljenost>k1.DajPoluprecnik() || udaljenost>k2.DajPoluprecnik()) ) return true;
   return false;
 }
 

 bool Kugla::DaLiSadrzi(const Kugla &k) const {
     
     if(k.DajPoluprecnik()<DajPoluprecnik()) {
     
     double udaljenost = sqrt ( pow((DajX()-k.DajX()),2) + pow((DajY()-k.DajY()),2) + pow((DajZ()-k.DajZ()),2) );
     if(udaljenost+k.DajPoluprecnik()<DajPoluprecnik()) return true;
     
     }
     else return false;
     
 }
 int main ()
{
    try {
        
    int n;
    
    while (true) {
        
    
     cout<<"Unesite broj kugla: ";
        cin>> n;
        
   while(!cin) {
       cout<<"Neispravan broj kugli, unesite ponovo!"<<endl; 
    
     cin.clear();
     cin.ignore(10000, '\n');
     cin>>n;
   }
   
        
       
   if(n<0 ){
        cout<<"Neispravan broj kugli, unesite ponovo!"<<endl; 
   
     cin.clear();
      cin.ignore(10000, '\n');
     cin>>n;
   
   
   }
     if(n>0) break;
        
    }
        double x,y,z;
        
        vector <shared_ptr <Kugla>> niz ;
        
        for(int i=0; i<n; i++){
            
            cout<<"Unesite centar "<<i+1<<". kugle: ";
           
            cin>>x>>y>>z;
            
            while(1) {
            try {  
           
            cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            
            double k;
            
            cin>>k;
            if(k>=0) {
                std::shared_ptr<Kugla> kugla = std::make_shared<Kugla>(x,y,z,k);
                niz.push_back(kugla);
                break;
            }
           
            }
            catch (domain_error e) { cout<<e.what(); } }
        }
        
        cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        
       double t1,t2,t3;
       cin>>t1>>t2>>t3;
       
       std::transform(niz.begin(), niz.end(), niz.begin(),[t1,t2,t3](std::shared_ptr<Kugla> kugla) {
    
     kugla->Transliraj(t1,t2,t3);
     return kugla;
});
       
        
   
sort(niz.begin(), niz.end(), [] (shared_ptr<Kugla> Neka1, shared_ptr<Kugla> Neka2) -> bool {
    
    return Neka1->DajZapreminu()<Neka2->DajZapreminu();
}); 

cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:"<<endl;

for (auto x: niz) 

x->Ispisi();


shared_ptr<Kugla>  pokazivac=*max_element (niz.begin(), niz.end(), [] (shared_ptr<Kugla> Prva, shared_ptr<Kugla> Druga) {
    return Druga->DajPovrsinu()>Prva->DajPovrsinu();
});

cout<<"Kugla sa najvecom povrsinom je: ";
pokazivac->Ispisi();

bool postojeKojeSeSijeku = false;
int index = 0;
for_each(niz.begin(), niz.end(), [niz,&postojeKojeSeSijeku,&index] (shared_ptr<Kugla> Prva) { 
    
    
    for_each(niz.begin() + index++, niz.end(),[&postojeKojeSeSijeku, Prva]  (shared_ptr<Kugla> Prva1)  { 
        
            
        if(DaLiSeSijeku(*Prva,*Prva1))
        
        {
            cout<<"Presjecaju se kugle: ";
            Prva->Ispisi();
            Prva1->Ispisi();
            postojeKojeSeSijeku = true; 
        }
    });
    
});

if(!postojeKojeSeSijeku) cout<<"Ne postoje kugle koje se presjecaju!";
        
    }
    
    catch(domain_error izuzetak) {
        cout<<izuzetak.what()<<endl;
    }
	return 0;
}

