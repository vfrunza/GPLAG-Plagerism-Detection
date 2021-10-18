/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
#include <stdexcept>

using namespace std;

class Kugla
{
    double r;
    double x,y,z;
    static bool DaLiSuJednaki(double a, double b, double eps=1e-10){
        return fabs(a-b) < eps*(fabs(a)+fabs(b));
    }
public:
    explicit Kugla(double r = 0) {
        if(r<0)throw domain_error("Ilegalan poluprecnik");
        x=0;
        y=0;
        z=0;
        this->r=r;
    }

    Kugla(double x, double y, double z, double r = 0) {
        if(r<0)throw domain_error("Ilegalan poluprecnik");
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        this->r = r;
        x = get<0>(centar);
        y = get<1>(centar);
        z = get<2>(centar);
    }
    double DajX() const{return x;}
    double DajY() const{return y;}
    double DajZ() const{return z;}
    std::tuple<double, double, double> DajCentar() const{
        return tuple<double,double,double>(x,y,z);
    }
    double DajPoluprecnik() const{return r;}
    double DajPovrsinu() const{ return 4*r*r*atan(1)*4;}
    double DajZapreminu() const{ return (4./3)*r*r*r*atan(1)*4;}
    Kugla &PostaviX(double x){ this->x=x; return *this;}
    Kugla &PostaviY(double y){ this->y=y; return *this;}
    Kugla &PostaviZ(double z){ this->z=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z){
         this->x=x;
         this->y=y;
         this->z=z;
         return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
         x = DajX();
         y = DajY();
         z = DajZ();
         return *this;
    }
    Kugla &PostaviPoluprecnik(double r){
        if(r<0)throw domain_error("Ilegalan poluprecnik");
        this->r = r;
    }
    void Ispisi() const{
        cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        PostaviX(DajX()+delta_x);
        PostaviY(DajY()+delta_y);
        PostaviZ(DajZ()+delta_z);
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        return DaLiSuPodudarne(k1,k2) && DaLiSuKoncentricne(k1,k2);
        /*
        return Kugla::DaLiSuJednaki(k1.r,k2.r)&&
               DaLiSuJednaki(k1.x,k2.x)&&
               DaLiSuJednaki(k1.y,k2.y)&&
               DaLiSuJednaki(k1.z,k2.z);
               */
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
        return Kugla::DaLiSuJednaki(k1.r,k2.r);
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
        return DaLiSuJednaki(k1.x,k2.x)&&
               DaLiSuJednaki(k1.y,k2.y)&&
               DaLiSuJednaki(k1.z,k2.z);
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        double d = RastojanjeCentara(k1,k2);
        return DaLiSuJednaki(d,k1.r+k2.r);
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        double d = RastojanjeCentara(k1,k2);
        return DaLiSuJednaki(d+k1.r, k2.r) || DaLiSuJednaki(d+k2.r,k1.r);
    }
    
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
        return DaLiSeSijeku(k1,k2)||k1.DaLiSadrzi(k2)||k2.DaLiSadrzi(k1);
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        double d = RastojanjeCentara(k1,k2);
        return !DaLiSeDodirujuIzvana(k1,k2)&&!DaLiSeDodirujuIznutra(k1,k2)&&(d<k1.r+k2.r);
    }
    bool DaLiSadrzi(const Kugla &k) const{
        double d = RastojanjeCentara(*this,k);
        return r-d>k.r && d<r;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        return sqrt((k1.x-k2.x)*(k1.x-k2.x) +(k1.y-k2.y)*(k1.y-k2.y) +(k1.z-k2.z)*(k1.z-k2.z));
    }
};
int main ()
{
/*
    Kugla k1(20);
    k1.Ispisi();
    Kugla k2(1,2,3,5);
    k2.Ispisi();
    Kugla k3(tuple<double,double,double>(3,4,5),20);
    k3.Ispisi();
    
    cout<<k1.DajZapreminu()<<endl;
    cout<<k1.DajPovrsinu()<<endl;
    
    cout<<DaLiSuIdenticne(k1,k2);
    Kugla k4(1,2,3,5);
    cout<<endl<<DaLiSuIdenticne(k2,k4)<<endl;

    cout<<(DaLiSuKoncentricne(k2,k4)?"k2 i k4 su koncentricne":"nisu koncentricne")<<endl;
    cout<<(DaLiSuPodudarne(k1,k3)?"k1 i k3 su podudadrne":"nisu podudadrne")<<endl;
   */

   int n;
   cout<<"Unesite broj kugla: ";
   cin>>n;
   vector<shared_ptr<Kugla> > kugle;

   for (int i = 0; i < n; i++) {
       try{
       double x,y,z,r;
       cout<<"Unesite centar "<<i+1<<". kugle: ";
       cin>>x>>y>>z;
       cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
       cin>>r;
       if(!cin){
           cin.clear();
           cin.ignore(1000,'\n');
           i--;
           continue;
       }
       auto k = make_shared<Kugla>(x,y,z,r);
       kugle.push_back(k);
      
       }
       catch(domain_error e){
           cout<<e.what()<<endl;
           i--;
       }
   }
   double dx,dy,dz;
   cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
   cin>>dx>>dy>>dz;
 
   transform(kugle.begin(),kugle.end(),kugle.begin(),[dx,dy,dz](shared_ptr<Kugla>k){
     k->Transliraj(dx,dy,dz);
     return k;
   });
   
   sort(kugle.begin(), kugle.end(),[](shared_ptr<Kugla>k1, shared_ptr<Kugla>k2){
       return k1->DajZapreminu()<k2->DajZapreminu();
   });
   cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
   for_each(kugle.begin(),kugle.end(), [](shared_ptr<Kugla>k){
       k->Ispisi();
   });
   
   auto najveca = *max_element(kugle.begin(),kugle.end(),[](shared_ptr<Kugla>k1, shared_ptr<Kugla>k2){
       return k1->DajPovrsinu() < k2->DajPovrsinu();
   });
   cout<<"Kugla sa najvecom povrsinom je: ";
   najveca->Ispisi();
  
   int broj_parova_koji_se_sijeku=0;
   int br=1;
   for_each(kugle.begin(), kugle.end(), [&br,kugle,&broj_parova_koji_se_sijeku](shared_ptr<Kugla>k1){
      for_each(kugle.begin()+br, kugle.end(),[k1,&broj_parova_koji_se_sijeku](shared_ptr<Kugla>k2){
         if(DaLiSeSijeku(*k1,*k2)){
             cout<<"Presjecaju se kugle: ";
             k1->Ispisi();
             k2->Ispisi();
             broj_parova_koji_se_sijeku++;
         } 
      }); 
      br++;
   });
   
   if(broj_parova_koji_se_sijeku==0)cout<<"Ne postoje kugle koje se presjecaju!"<<endl;

    return 0;
}
