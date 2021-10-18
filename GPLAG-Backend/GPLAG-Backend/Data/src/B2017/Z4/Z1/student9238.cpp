/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Kugla
{
    double x,y,z,r;
    
    double pi=atan(1)*4;
    
    double ep=pow(10,-10);
    
    public:
    
    explicit Kugla(double r = 0):x(0),y(0),z(0){
        if (r<0) throw domain_error("Ilegalan poluprecnik");
    }
    
    Kugla(double x, double y, double z, double r = 0):x(x),y(y),z(z),r(r){}
    
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        
        double x,y,z;
        tie(x,y,z)=centar;
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=r;
    }
    
    
    double DajX() const{
        return this->x;
    }
    
    double DajY() const{
        return this->y;
    }
    
    double DajZ() const{
        return this->z;
    }
    
    std::tuple<double, double, double> DajCentar() const{
        return make_tuple(this->x,this->y,this->z);
    }
    
    double DajPoluprecnik() const{
        return this->r;
    }
    
    double DajPovrsinu() const{
        
        return 4*pi*r*r;
        
    }
    
    double DajZapreminu() const{
        
        return (4/3)*pi*r*r*r;
        
    }
    
    Kugla &PostaviX(double x){
        this->x=x;
        return *this;
    }
    
    Kugla &PostaviY(double y){
        this->y=y;
        return *this;
    }
    
    Kugla &PostaviZ(double z){
        this->z=z;
        return *this;
    }
    
    Kugla &PostaviCentar(double x, double y, double z){
        this->x=x;
        this->y=y;
        this->z=z;
        return *this;
    }
    
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        
        double x,y,z;
        tie(x,y,z)=centar;
        this->x=x;
        this->y=y;
        this->z=z;
        return *this;
    }
    
    Kugla &PostaviPoluprecnik(double r){
        
        if (r<0) throw domain_error("Ilegalan poluprecnik");
        this->r=r;
        return *this;
    }
    
    void Ispisi() const{
        
        cout<<"{"<<"("<<this->x<<","<<this->y<<","<<this->z<<")"<<","<<r<<"}"<<endl;
        
    }
    
    void Transliraj(double delta_x, double delta_y, double delta_z){
        
        this->x+=delta_x;
        this->y+=delta_y;
        this->z+=delta_z;
    }
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        
    return(k1.x==k2.x && k1.y==k2.y && k1.z==k2.z && k1.r==k2.r);
    }
    
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
        
        return k1.r==k2.r;
    }
    
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    
          return(k1.x==k2.x && k1.y==k2.y && k1.z==k2.z);
    }
    
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        
    double udaljenost=sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));
    
    double temp=k1.r+k2.r;
    
        return (fabs(temp-udaljenost)<k1.ep*(fabs(temp)+fabs(udaljenost)));
        
    }
    
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        
    double udaljenost=sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));
    
    double temp=fabs(k1.r-k2.r);//temp=udaljenost
    
    
    return (fabs(temp-udaljenost)<k1.ep*(fabs(temp)+fabs(udaljenost)));
    
    
    
    }
    
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
        
    if(DaLiSeSijeku(k1,k2)==true || k1.DaLiSadrzi(k2)==true || k2.DaLiSadrzi(k1))return true;
    return false;
    
    }
    
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        
    double udaljenost=sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));
   
     double min,max;
     
     if(k1.r>k2.r){
         max=k1.r;
         min=k2.r;
     }
     else{
         max=k2.r;
         min=k1.r;
     }
    
     
     if(k1.DaLiSadrzi(k2))return false;
     
        
    
     
     if(udaljenost==k1.r || udaljenost==k2.r) return true;
     
     return(min>fabs(max-udaljenost));
    
    }
    
    bool DaLiSadrzi(const Kugla &k) const{
        
    double udaljenost=sqrt(pow(this->x-k.x,2)+pow(this->y-k.y,2)+pow(this->z-k.z,2));
    
    return (fabs(this->r-k.r)>=udaljenost);
    }
    
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
         double udaljenost=sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));
         return udaljenost;
    }
    
};





int main ()
{
    vector<shared_ptr<Kugla>> v,vt;
     int n;
    cout<<"Unesite broj kugla: ";
    
    while(1){
    cin>>n;
    if(n<=0){cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;cin.clear();cin.ignore(10000, '\n');}
    else break;
    }
    
    for(int i=0;i<n;i++){
        double p=0,x=0,y=0,z=0;
        
        
        
        cout<<"Unesite centar "<<i+1<<". kugle: ";
        if(!(cin>>x>>y>>z)){cout<<"Neispravan centar"<<endl;cin.clear();cin.ignore(10000, '\n');i--;continue;}
        
        
        cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
       if(!(cin>>p )){
           cout<<"Ilegalan poluprecnik"<<endl;cin.clear();cin.ignore(10000, '\n');i--;continue;
       }
        if(p<0){
           cout<<"Ilegalan poluprecnik"<<endl;cin.clear();cin.ignore(10000, '\n');i--;continue;
       }
        
        shared_ptr<Kugla> ptr=make_shared<Kugla>(x,y,z,p);
        v.push_back(ptr);
        
    }
    
    
    double dx,dy,dz;
    vt.resize(v.size());
    
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    
    while(1){
         if(!(cin>>dx>>dy>>dz)){cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;cin.clear();cin.ignore(10000, '\n');continue;}
         else break;
    }
    
    transform(v.begin(),v.end(),vt.begin(),[dx,dy,dz](shared_ptr<Kugla> k){k->Transliraj(dx,dy,dz);return k;});
    
    sort(vt.begin(),vt.end(),[](shared_ptr<Kugla> k1,shared_ptr<Kugla> k2){return k1->DajZapreminu()<k2->DajZapreminu();});
    
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
    
  for_each(vt.begin(),vt.end(),[](shared_ptr<Kugla> k){k->Ispisi();});
    
    
    auto temp=*max_element(vt.begin(),vt.end(),
  [](shared_ptr<Kugla> k1,shared_ptr<Kugla> k2){return k1->DajPovrsinu()<k2->DajPovrsinu();});
  cout<<"Kugla sa najvecom povrsinom je: ";temp->Ispisi();
 
 int brojac=1;
 int pres=0;
 
 for_each(vt.begin(),vt.end(),
 [vt,brojac,&pres](shared_ptr<Kugla> k1)mutable
 {
 for_each(vt.begin()+brojac,vt.end(),
 [vt,brojac,&pres,k1](shared_ptr<Kugla> k2)mutable
 {
     
     if( DaLiSeSijeku(*k1,*k2)==true && DaLiSuIdenticne(*k1,*k2)==false){
         cout<<"Presjecaju se kugle: ";
         k1->Ispisi();
         k2->Ispisi();
         pres++;
     }

 });
 brojac++;
 });
 if(pres==0)cout<<"Ne postoje kugle koje se presjecaju!";
 
    return 0;
}
