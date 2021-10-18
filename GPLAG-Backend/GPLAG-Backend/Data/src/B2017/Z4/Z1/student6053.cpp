/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <tuple>
#include <memory>

using std::vector;
using std::cout;
using std::cin;

const double PI=4*atan(1.);
const double epsilon=0.0000000001;

class Kugla{
    double x;
    double y;
    double z;
    double r;
    public:
  explicit Kugla(double r=0){
  if(r<0) throw std::domain_error("Ilegalan poluprecnik");
  Kugla::x=0;
  Kugla::y=0;
  Kugla::z=0;
  Kugla::r=r;
  }
  Kugla(double x,double y,double z,double r=0){
  if(r<0) throw std::domain_error("Ilegalan poluprecnik");
  Kugla::x=x;
  Kugla::y=y;
  Kugla::z=z;
  Kugla::r=r;
  }
  explicit Kugla(const std::tuple<double,double,double>&centar,double r=0){ 
      if(r<0) throw std::domain_error("Ilegalan poluprecnik");
      Kugla::x=std::get<0>(centar);
      Kugla::y=std::get<1>(centar);
      Kugla::z=std::get<2>(centar);
      Kugla::r=r;
  }
  double DajX() const { return x;}
  double DajY() const { return y;}
  double DajZ() const { return z;}
  std::tuple<double,double,double>DajCentar() const {
  return std::make_tuple(Kugla::x,Kugla::y,Kugla::z);
  }
  double DajPoluprecnik() const { return r;}
  double DajPovrsinu() const { return 4.*r*r*PI;}
  double DajZapreminu() const { return (4./3)*r*r*r*PI;}
  Kugla &PostaviX(double x){ Kugla::x=x; return *this;}
  Kugla &PostaviY(double y){ Kugla::y=y; return *this;}
  Kugla &PostaviZ(double z){ Kugla::z=z; return *this;}
  Kugla &PostaviCentar(double x,double y,double z){
      Kugla::x=x;
      Kugla::y=y; 
      Kugla::z=z; 
      return *this;
  }
  Kugla &PostaviCentar(std::tuple<double,double,double>&centar){
      Kugla::x=std::get<0>(centar);
      Kugla::y=std::get<1>(centar);
      Kugla::z=std::get<2>(centar);
      return *this;
  }
  Kugla &PostaviPoluprecnik(double r){
      if(r<0) throw std::domain_error("Ilegalan poluprecnik");
      Kugla::r=r; 
      return *this;
  }
  
  void Ispisi() const{ cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;}
  void Transliraj(double delta_x,double delta_y,double delta_z){ Kugla::x+=delta_x; Kugla::y+=delta_y; Kugla::z+=delta_z;}
  
  friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);
  friend double RastojanjeCentara(const Kugla &k1,const Kugla &k2);
  bool DaLiSadrzi(const Kugla &k) const{
    std::tuple<double,double,double>t(k.DajCentar());
    double d=sqrt((Kugla::x-std::get<0>(t))*(Kugla::x-std::get<0>(t))+(Kugla::y-std::get<1>(t))*(Kugla::y-std::get<1>(t))+(Kugla::z-std::get<2>(t))*(Kugla::z-std::get<2>(t)));
    if(d<fabs(Kugla::r-k.DajPoluprecnik())) return true;
    return false;
 }
 };
    double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
    std::tuple<double,double,double>t1(k1.DajCentar());
    std::tuple<double,double,double>t2(k2.DajCentar());
    return sqrt((std::get<0>(t1)-std::get<0>(t2))*(std::get<0>(t1)-std::get<0>(t2))+(std::get<1>(t1)-std::get<1>(t2))*(std::get<1>(t1)-std::get<1>(t2))+(std::get<2>(t1)-std::get<2>(t2))*(std::get<2>(t1)-std::get<2>(t2)));}
    bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2){
    if(k1.DajCentar()==k2.DajCentar()) return true;  
    return false;}
    bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
    if(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<epsilon) return true;
    return false;}

    bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2){
      return k1.DajPoluprecnik()+k2.DajPoluprecnik()==RastojanjeCentara(k1,k2);}
    bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2){
    return fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())==RastojanjeCentara(k1,k2);}
    bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2){
    if(DaLiSeSijeku(k1,k2)) return true;
    return false;} 
    bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2){
    if(k1.DajPoluprecnik()+k2.DajPoluprecnik()>RastojanjeCentara(k1,k2) && fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<RastojanjeCentara(k1,k2)) return true;
    return false;}

    bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2){
    std::tuple<double,double,double>t1(k1.DajCentar());
    std::tuple<double,double,double>t2(k2.DajCentar());
    double r1(k1.DajPoluprecnik());
    double r2(k2.DajPoluprecnik());
    if(fabs(r1-r2)<epsilon && t1==t2) return true; 
    return false;}
int main ()
{
    vector<std::shared_ptr<Kugla>>v;
    int l;
    cout<<"Unesite broj kugla: ";
    cin>>l;
    while(!cin || l<=0){
         cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
         cin.clear(); 
         cin.ignore(10000, '\n'); 
         cin>>l;
    }
    double x,y,z,r;
    for(int i=1;i<=l;i++){
        cout<<"Unesite centar "<<i<<". kugle: ";
        cin>>x>>y>>z;
        cout<<"Unesite poluprecnik "<<i<<". kugle: ";
        cin>>r;
       Kugla k(x,y,z,r);
        v.push_back(std::make_shared<Kugla>(k));
    }
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double d_x,d_y,d_z;
    cin>>d_x>>d_y>>d_z;
    transform(v.begin(),v.end(),v.begin(),[d_x,d_y,d_z](std::shared_ptr<Kugla>k){k->Transliraj(d_x,d_y,d_z); return k;});
    sort(v.begin(),v.end(),[](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2){return k1->DajZapreminu()<k2->DajZapreminu();});
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:"<<std::endl;
    for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla>k){k->Ispisi();});
    auto pokazivac=max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2){return k1->DajPovrsinu()<k2->DajPovrsinu();});
    cout<<"Kugla sa najvecom povrsinom je: ";(*pokazivac)->Ispisi();
    vector<std::pair<std::shared_ptr<Kugla>,std::shared_ptr<Kugla>>>vektor1;
    for_each(v.begin(),v.end(),[&vektor1,v](std::shared_ptr<Kugla>p1){
        for_each(v.begin(),v.end(),[&vektor1,v,p1](std::shared_ptr<Kugla>p2){
            if(DaLiSeSijeku(*p1,*p2) && vektor1.size()==0) vektor1.push_back(std::make_pair(p1,p2));
            else if(DaLiSeSijeku(*p1,*p2) && vektor1.size()>0){
                int a(0);
                for_each(vektor1.begin(),vektor1.end(),[p1,p2,&a](std::pair<std::shared_ptr<Kugla>,std::shared_ptr<Kugla>>par){
                    if((par).first==p2 && (par).second==p1) a++;});
                    if(a==0) vektor1.push_back(make_pair(p1,p2));
                    else a=0;
            };});;});
        for_each(vektor1.begin(),vektor1.end(),[](std::pair<std::shared_ptr<Kugla>,std::shared_ptr<Kugla>>k){cout<<"Presjecaju se kugle: ";(k).first->Ispisi();(k).second->Ispisi();});
        if(vektor1.size()==0) cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}