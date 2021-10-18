/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;
const double epsilon=0.0000000001;
const double PI=4*atan(1.);
class Kugla{
    private:
    double x,y,z,r;
    public:
  explicit Kugla(double r=0){if(r<0) throw domain_error("Ilegalan poluprecnik"); Kugla::x=0;Kugla::y=0;Kugla::z=0; Kugla::r=r;}
  
  Kugla(double x,double y,double z,double r=0){ if(r<0) throw domain_error("Ilegalan poluprecnik"); Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;}
  
  explicit Kugla(const tuple<double,double,double>&centar,double r=0){ 
      if(r<0) throw domain_error("Ilegalan poluprecnik"); 
      Kugla::x=get<0>(centar);
      Kugla::y=get<1>(centar);
      Kugla::z=get<2>(centar);
      Kugla::r=r;
  }
  
  double DajX() const { return x;}
  double DajY() const { return y;}
  double DajZ() const { return z;}
  tuple<double,double,double>DajCentar() const { return make_tuple(Kugla::x,Kugla::y,Kugla::z);}
  double DajPoluprecnik() const { return r;}
  double DajPovrsinu() const { return 4.*r*r*PI;}
  double DajZapreminu() const { return (4./3)*r*r*r*PI;}
  Kugla &PostaviX(double x){ Kugla::x=x; return *this;}
  Kugla &PostaviY(double y){ Kugla::y=y; return *this;}
  Kugla &PostaviZ(double z){ Kugla::z=z; return *this;}
  Kugla &PostaviCentar(double x,double y,double z){ Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this;}
  Kugla &PostaviCentar(tuple<double,double,double>&centar){ Kugla::x=get<0>(centar); Kugla::y=get<1>(centar); Kugla::z=get<2>(centar); return *this;}
  Kugla &PostaviPoluprecnik(double r){ if(r<0) throw domain_error("Ilegalan poluprecnik"); Kugla::r=r; return *this;}
  void Ispisi() const{ cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<endl;}
  void Transliraj(double delta_x,double delta_y,double delta_z){ Kugla::x+=delta_x; Kugla::y+=delta_y; Kugla::z+=delta_z;}
  friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);
  bool DaLiSadrzi(const Kugla &k) const{
    tuple<double,double,double>t(k.DajCentar());
    //provjeriti za dodirivanje iznutra
    double d=sqrt((Kugla::x-get<0>(t))*(Kugla::x-get<0>(t))+(Kugla::y-get<1>(t))*(Kugla::y-get<1>(t))+(Kugla::z-get<2>(t))*(Kugla::z-get<2>(t)));
    if(d<fabs(Kugla::r-k.DajPoluprecnik())) return true;
    return false;
}
   friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
};
bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2){
    tuple<double,double,double>t1(k1.DajCentar());
    tuple<double,double,double>t2(k2.DajCentar());
    double r1(k1.DajPoluprecnik());
    double r2(k2.DajPoluprecnik());
    if(fabs(r1-r2)<epsilon*(fabs(r1)+fabs(r2)) && t1==t2) return true; 
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
    if(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<epsilon*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik()))) return true; 
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2){
    if(k1.DajCentar()==k2.DajCentar()) return true;  
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2){
      return (fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik()-RastojanjeCentara(k1,k2))<epsilon*(fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik())+fabs(RastojanjeCentara(k1,k2))));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2){
    return (fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())-RastojanjeCentara(k1,k2))<epsilon*(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())+RastojanjeCentara(k1,k2));
}
bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2){
    if(DaLiSeSijeku(k1,k2)) return true;
    return false;
} 
bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2){
    if(k1.DajPoluprecnik()+k2.DajPoluprecnik()>RastojanjeCentara(k1,k2) && fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<RastojanjeCentara(k1,k2)) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
    tuple<double,double,double>t1(k1.DajCentar());
    tuple<double,double,double>t2(k2.DajCentar());
    return sqrt((get<0>(t1)-get<0>(t2))*(get<0>(t1)-get<0>(t2))+(get<1>(t1)-get<1>(t2))*(get<1>(t1)-get<1>(t2))+(get<2>(t1)-get<2>(t2))*(get<2>(t1)-get<2>(t2)));
} 
int main ()
{
    try{
    cout<<"Unesite broj kugla: ";
    int n;
    cin>>n;
    while(!cin || n<=0){
         cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
         cin.clear(); 
         cin.ignore(10000, '\n'); 
         cin>>n;
    }
    vector<shared_ptr<Kugla>>v;
    double x,y,z,r;
    for(int i=0;i<n;i++){
        cout<<"Unesite centar "<<i+1<<". kugle: ";
        cin>>x>>y>>z;
        while(!cin){
         cout<<"Neispravan centar"<<endl;
         cin.clear(); 
         cin.ignore(10000, '\n'); 
         cout<<"Unesite centar "<<i+1<<". kugle: ";
         cin>>x>>y>>z;
    } 
    
        cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        cin>>r;
               while(!cin || r<0){
         cout<<"Ilegalan poluprecnik"<<endl;
         cin.clear(); 
         cin.ignore(10000, '\n'); 
         cout<<"Unesite centar "<<i+1<<". kugle: ";
         cin>>x>>y>>z; 
         cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
         cin>>r;
    } 
       Kugla k(x,y,z,r);
        v.push_back(make_shared<Kugla>(k));
    }
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx,dy,dz;
    cin>>dx>>dy>>dz;
        while(!cin){
         cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
         cin.clear(); 
         cin.ignore(10000, '\n'); 
         cin>>dx>>dy>>dz;
    } 
    transform(v.begin(),v.end(),v.begin(),[dx,dy,dz](shared_ptr<Kugla>k){k->Transliraj(dx,dy,dz); return k;});
    sort(v.begin(),v.end(),[](shared_ptr<Kugla>k1,shared_ptr<Kugla>k2){return k1->DajZapreminu()<k2->DajZapreminu();});
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:"<<endl;
    for_each(v.begin(),v.end(),[](shared_ptr<Kugla>k){k->Ispisi();});
    auto pok=max_element(v.begin(),v.end(),[](shared_ptr<Kugla>k1,shared_ptr<Kugla>k2){return k1->DajPovrsinu()<k2->DajPovrsinu();});
    cout<<"Kugla sa najvecom povrsinom je: ";(*pok)->Ispisi();
    vector<pair<shared_ptr<Kugla>,shared_ptr<Kugla>>>v1;
    for_each(v.begin(),v.end(),[&v1,v](shared_ptr<Kugla>p1){
        for_each(v.begin(),v.end(),[&v1,v,p1](shared_ptr<Kugla>p2){
            if(DaLiSeSijeku(*p1,*p2) && v1.size()==0) v1.push_back(make_pair(p1,p2));
            else if(DaLiSeSijeku(*p1,*p2) && v1.size()>0){
                int a(0);
                for_each(v1.begin(),v1.end(),[p1,p2,&a](pair<shared_ptr<Kugla>,shared_ptr<Kugla>>par){
                    if((par).first==p2 && (par).second==p1) a++;});
                    if(a==0) v1.push_back(make_pair(p1,p2));
                    else a=0;
            }
            ;});
        ;});
        for_each(v1.begin(),v1.end(),[](pair<shared_ptr<Kugla>,shared_ptr<Kugla>>k){cout<<"Presjecaju se kugle: ";(k).first->Ispisi();(k).second->Ispisi();});
        if(v1.size()==0) cout<<"Ne postoje kugle koje se presjecaju!";
    }
    catch(domain_error e){
        cout<<e.what();
    }
	return 0;
}
 