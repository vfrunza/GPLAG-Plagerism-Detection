/B2017/2018: Zadaća 4, Zadatak 1  
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <new>
#include <algorithm>
using namespace std;

const double PI=4*atan(1);
const double eps=0.0000000001;

class Kugla{
    
  double x,y,z,r;
  
  public:
  explicit Kugla(double r=0){
     if(r<0) throw domain_error("Ilegalan poluprecnik");
      Kugla::r=r;
      x = 0;
      y = 0;
      z = 0;
  }
  Kugla(double x, double y, double z, double r=0){
    if(r<0) throw domain_error("Ilegalan poluprecnik");
    Kugla::x=x; Kugla::y=y; Kugla::z=z; Kugla::r=r;
  }
  explicit Kugla(const tuple<double, double, double> &centar, double r=0){
     if(r<0) throw domain_error("Ilegalan poluprecnik");
    Kugla::x=get<0>(centar); Kugla::y=get<1>(centar); Kugla::z=get<2>(centar);
    Kugla::r=r;
  }
  double DajX() const;
  double DajY() const;
  double DajZ() const;
  tuple<double, double, double> DajCentar() const;
  double DajPoluprecnik() const;
  double DajPovrsinu() const;
  double DajZapreminu() const;
  Kugla &PostaviX(double x);
  Kugla &PostaviY(double y);
  Kugla &PostaviZ(double z);
  Kugla &PostaviCentar(double x, double y, double z);
  Kugla &PostaviCentar(const tuple<double, double, double> &centar);
  Kugla &PostaviPoluprecnik(double r);
  void Ispisi() const;
  void Transliraj(double delta_x, double delta_y, double delta_z);
  friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
  friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
  bool DaLiSadrzi(const Kugla &k) const;
  friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
  
};

  double Kugla::DajX() const{
    return x;
  }
  double Kugla::DajY() const{
    return y;
  }
  double Kugla::DajZ() const{
    return z;
  }
  tuple<double, double, double> Kugla::DajCentar() const{
    tuple<double, double, double> temp;
    get<0>(temp)=DajX();  get<1>(temp)=DajY(); get<2>(temp)=DajZ();
    return temp;
  }
  double Kugla::DajPoluprecnik() const{
    return r;
  }
  double Kugla::DajPovrsinu() const{
    return 4*r*r*PI;
  }
  double Kugla::DajZapreminu() const{
    return 4/3*r*r*r*PI;
  }
  Kugla& Kugla::PostaviX(double x){
    Kugla::x=x;
    return *this;
  }
  Kugla& Kugla::PostaviY(double y){
    Kugla::y=y;
    return *this;
  }
  Kugla& Kugla::PostaviZ(double z){
    Kugla::z=z;
    return *this;
  }
  Kugla& Kugla::PostaviCentar(double x, double y, double z){
    Kugla::x=x; Kugla::y=y; Kugla::z=z;
    return *this;
  }
  Kugla& Kugla::PostaviCentar(const tuple<double, double, double> &centar){
    Kugla::x=get<0>(centar);
    Kugla::y=get<1>(centar);
    Kugla::z=get<2>(centar);
    return *this;
  }
  Kugla& Kugla::PostaviPoluprecnik(double r){
    if(r<0) throw domain_error("Ilegalan poluprecnik");
    Kugla::r=r;
    return *this;
  }
 void Kugla::Ispisi() const{
   cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<endl;
 }
 void Kugla::Transliraj(double delta_x, double delta_y, double delta_z){
   Kugla::x=DajX()+delta_x;
   Kugla::y=DajY()+delta_y;
   Kugla::z=DajZ()+delta_z;
 }
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
  if(fabs(k1.DajX()-k2.DajX())<eps && fabs(k1.DajY()-k2.DajY())<eps && fabs(k1.DajZ()-k2.DajZ())<eps && fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<eps){
    return true;
  }
  return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
  if(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<eps){
    return true;
  }
  return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
  tuple<double,double,double> t1,t2;
  t1=k1.DajCentar();
  t2=k2.DajCentar();
  if(fabs(get<0>(t1)-(get<0>(t2)))<eps && fabs(get<1>(t1)-(get<1>(t2)))<eps && fabs(get<2>(t1)-(get<2>(t2)))<eps){
    return true;
  }
  return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    if(fabs(RastojanjeCentara(k1,k2)-(k1.DajPoluprecnik()+k2.DajPoluprecnik()))<eps){
      return true;
    }  
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
  double rastojanje=RastojanjeCentara(k1,k2);
  if(fabs(rastojanje-fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))<eps && DaLiSuKoncentricne(k1,k2)==false){
    return true;
  }
  return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
  if(k1.DajPoluprecnik()+k2.DajPoluprecnik()>RastojanjeCentara(k1,k2)){
    return true;
  }
  return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
  if((k1.DajPoluprecnik()+k2.DajPoluprecnik())>RastojanjeCentara(k1,k2) && DaLiSeDodirujuIznutra(k1, k2)==false ){
    return true;
  }
  return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const{
  if((this->DajPoluprecnik()-RastojanjeCentara(*this,k))>k.DajPoluprecnik()){
    return true;
  }
  return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
  return sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
}

int main(){
  int n;
  cout<<"Unesite broj kugla: ";
  cin>>n;
  while(!cin || n<=0){
   cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
   cin.clear();
   cin.ignore(10000, '\n');
   cin>>n;
  }
  vector<shared_ptr<Kugla>> v;
  for(int i=0; i<n; i++){
    cout<<"Unesite centar "<<i+1<<". kugle: ";
    double x,y,z;
    cin>>x>>y>>z;
    while(!cin){
      cout<<"Neispravan centar";
      cin.clear();
      cin.ignore(10000,'\n');
      cout<<endl<<"Unesite centar "<<i+1<<". kugle: ";
      cin>>x>>y>>z;
    }
    cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
    double r;
    cin>>r;
    while(!cin || r<0){
      cout<<"Ilegalan poluprecnik"<<endl;
      cout<<"Unesite centar "<<i+1<<". kugle: ";
      cin.clear();
      cin.ignore();
      cin>>x>>y>>z;
      cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
      cin>>r;
    }
    Kugla k;
    k.PostaviCentar(x,y,z);
    k.PostaviPoluprecnik(r);
    shared_ptr<Kugla> pnk=make_shared<Kugla>();
    *pnk=k;
    v.push_back(pnk);
  }
  cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
  double dx,dy,dz;
  cin>>dx>>dy>>dz;
  while(!cin){
    cout<<"Neispravni parametri translacije, unesite ponovo!";
    cin.clear();
    cin.ignore(10000,'\n');
    cin>>dx>>dy>>dz;
  }
  vector<shared_ptr<Kugla>> pom(n);
  transform(v.begin(),v.end(),pom.begin(), [dx,dy,dz](shared_ptr<Kugla> temp){
    temp->Transliraj(dx,dy,dz);
    return temp;
  });
  cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
  sort(pom.begin(),pom.end(),[](shared_ptr<Kugla> k1, shared_ptr<Kugla> k2){
    return k1->DajZapreminu()<k2->DajZapreminu();
  });
  
  for_each(pom.begin(),pom.end(),[](shared_ptr<Kugla> trenutni){
    trenutni->Ispisi();
  });
  
  auto max=max_element(pom.begin(), pom.end(), [](shared_ptr<Kugla> p1,shared_ptr<Kugla> p2){
    return p2->DajPovrsinu()>p1->DajPovrsinu();
  } );  
  cout<<"Kugla sa najvecom povrsinom je: ";
  (**max).Ispisi();
  auto p1=pom.begin();
  auto p2=pom.end();
  int i(0);
  for_each(p1,p2,[p1,p2,&i](shared_ptr<Kugla> ptr1){
     for_each(p1+i,p2,[ptr1,&i](shared_ptr<Kugla> ptr2){
        if(ptr2!=ptr1 && DaLiSeSijeku(*ptr2,*ptr1)){
         i++;
         cout<<"Presjecaju se kugle: ";
         ptr1->Ispisi(); ptr2->Ispisi();
       }
    });
  
  });
    if(i==0){
     cout<<"Ne postoje kugle koje se presjecaju!";
    }
  return 0;
}