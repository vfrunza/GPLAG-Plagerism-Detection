#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <memory>
#include <algorithm>
#include <vector>
using std::cout;
using std::cin;

const double PI(4*atan(1));
const double eps(1e-10);
class Kugla{
    double R,X,Y,Z;
 //  static  double DajUdaljenost(const Kugla &k1,const Kugla &k2); //{
       //auto udaljenost(sqrt(pow(k1.X-k2.X,2)+pow(k1.Y-k2.Y,2)+pow(k1.Z-k2.Z,2)));
      // return udaljenost;
    //} 
public:
explicit Kugla(double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    X=0; Y=0; Z=0; R=r;
}
 Kugla(double x,double y,double z,double r=0){
     if(r<0) throw std::domain_error("Ilegalan poluprecnik");
     X=x; Y=y; Z=z; R=r;
 }
 explicit Kugla(const std::tuple<double,double,double>&centar,double r=0){
     if(r<0) throw std::domain_error("Ilegalan poluprecnik");
     std::tie(X,Y,Z)=centar; //smjestanje koordinata iz tuple 
     R=r;
 }
 double DajX()const{return X;}
 double DajY()const{return Y;}
 double DajZ()const {return Z;}
 std::tuple<double, double, double> DajCentar() const{
    auto t(std::make_tuple(X,Y,Z)); return t;}
 double DajPoluprecnik() const{ return R;}
 double DajPovrsinu() const{ return 4*PI*R*R;}
 double DajZapreminu() const{ auto rez(4/3*PI*R*R*R); return rez;}
 Kugla &PostaviX(double x){ X=x; return *this;}
 Kugla &PostaviY(double y){Y=y; return *this;}
 Kugla &PostaviZ(double z){Z=z; return *this;}
 Kugla &PostaviCentar(double x, double y, double z){
     X=x;Y=y;Z=z; return *this;}
 Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){std::tie(X,Y,Z)=centar; return *this;}
 Kugla &PostaviPoluprecnik(double r){
      if(r<0) throw std::domain_error("Ilegalan poluprecnik");
     R=r; return *this;
 }

 void Ispisi() const{
     std::cout<<"{("<<X<<","<<Y<<","<<Z<<"),"<<R<<"}"<<std::endl;
 }

void Transliraj(double delta_x, double delta_y, double delta_z){
    X+=delta_x; Y+=delta_y; Z+=delta_z;
}
friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);

friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
bool DaLiSadrzi(const Kugla &k) const{
     auto D(sqrt(pow(X-k.X,2)+pow(Y-k.Y,2)+pow(Z-k.Z,2)));
      auto razlika(fabs(R-k.R));
       if(D<razlika) return true;
       return false;
}};

 bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(((k1.X-k2.X)<=eps*(fabs(k1.X)+fabs(k2.X))) &&((k1.Y-k2.Y)<eps*(fabs(k1.Y)+fabs(k2.Y))) && ((k1.Z-k2.Z)<eps*(fabs(k1.Z)+fabs(k2.Z))) && ((k1.R-k2.R)<eps*(fabs(k1.R)+fabs(k2.R))))
    return true;
    return false;
}
 bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
   if((k1.R-k2.R)<=eps*(fabs(k1.R)+fabs(k2.R))) return true;
   return false;}
   bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
       if(((k1.X-k2.X)<=eps*(fabs(k1.X)+fabs(k2.X))) &&((k1.Y-k2.Y)<eps*(fabs(k1.Y)+fabs(k2.Y))) && ((k1.Z-k2.Z)<eps*(fabs(k1.Z)+fabs(k2.Z))))
       return true;
       return false;
  } 
   bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
      auto d(sqrt(pow(k1.X-k2.X,2)+pow(k1.Y-k2.Y,2)+pow(k1.Z-k2.Z,2)));
      auto zbir_r(k1.R+k2.R);
      if((d-zbir_r)<=eps*(fabs(d)+fabs(zbir_r))) return true;
      return false;
  }
  bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
      auto D(sqrt(pow(k1.X-k2.X,2)+pow(k1.Y-k2.Y,2)+pow(k1.Z-k2.Z,2)));
      auto razlika(k1.R-k2.R);
       if((D-fabs(razlika))<=eps*(fabs(D)+fabs(razlika))) return true;
       return false;
  }
 bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
  //if(DaLiSeSijeku(k1,k2) || k1.DaLiSadrzi(k2) || DaLiSeDodirujuIznutra(k1,k2) || k2.DaLiSadrzi(k1))
  //return true;
  //return false;
  auto zb(k1.R+k2.R);
  auto d(sqrt(pow(k1.X-k2.X,2)+pow(k1.Y-k2.Y,2)+pow(k1.Z-k2.Z,2)));
  if(d>zb || d<std::fabs(k2.R-k1.R)) return true;
  return false;
 
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    auto d(sqrt(pow(k1.X-k2.X,2)+pow(k1.Y-k2.Y,2)+pow(k1.Z-k2.Z,2)));
    auto zbir(k1.R+k2.R);
    auto razlika(fabs(k1.R-k2.R));
    if(d<zbir && d>razlika) return true;
    return false;
}

 double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
   auto udaljenost(sqrt(pow(k1.X-k2.X,2)+pow(k1.Y-k2.Y,2)+pow(k1.Z-k2.Z,2)));
return udaljenost;
}

int main ()
{
    int n;
    cout<<"Unesite broj kugla: ";
    while(1){
    
    
    cin>>n;
    if(!cin) {cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;cin.clear();cin.ignore(1000,'\n');}
    else if(n<=0 ) cout<<"Neispravan broj kugli, unesite ponovo!"<<std::endl;
    else if(n>0) break;
    
}
double x,y,z,r;
std::vector<std::shared_ptr<Kugla>> vektor;
for(int i(0);i<n;i++){
    /*try{
        while(1){
            while(1){
    cout<<"Unesite centar "<<i+1<<". kugle: ";
    cin>>x>>y>>z;
    if(cin) break;
     if(!cin) {cout<<"Neispravan centar"<<std::endl;cin.clear();cin.ignore(1000,'\n');}
    //else if(x<0 ||y<0||z<0 ) cout<<"Neispravan centar!"<<std::endl;
   // else if(x>=0 &&y>=0 &&z>=0) break;
   
            }
            while(1){
    cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
    cin>>r;
     if(!cin) {cout<<"Ilegalan poluprecnik"<<std::endl;cin.clear();cin.ignore(1000,'\n');}
        else if(r<0) cout<<"Ilegalan poluprecnik"<<std::endl;
       else if(r>=0) break;
            }
       if( r>=0) break;
    }
    std::shared_ptr<Kugla> kugla(std::make_shared<Kugla>(x,y,z,r));
    vektor.push_back(kugla);
 }catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
        i--; } */
        try{
        for(;;){
            cout<<"Unesite centar "<<i+1<<". kugle: ";
            cin>>x>>y>>z;
            if(!cin){
                cout<<"Neispravan centar\n";
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
                
            }
            cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            cin>>r;
            if(!cin || r<0){
                cout<<"Ilegalan poluprecnik\n";
                cin.clear();
                cin.ignore(1000,'\n');
                continue;
            }
            break;
        }
         std::shared_ptr<Kugla> kugla(std::make_shared<Kugla>(x,y,z,r));
        vektor.push_back(kugla);
        }catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
            i--; //treba lii?
        }
}
double deltaX,deltaY,deltaZ;
cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
for(;;){
cin>>deltaX>>deltaY>>deltaZ;
if(!cin){
    cout<<"Neispravni parametri translacije, unesite ponovo!\n";
    cin.clear();
    cin.ignore(1000,'\n');
    continue;
}
break;} 
cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl; 
std::transform(vektor.begin(),vektor.end(),vektor.begin(),[deltaX,deltaY,deltaZ](std::shared_ptr<Kugla> k1){ (*k1).Transliraj(deltaX,deltaY,deltaZ); return k1;});
std::sort(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2){return k1->DajZapreminu()<k2->DajZapreminu();});
std::for_each(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla>k){k->Ispisi();});
auto kuglaa(*std::max_element(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2){return k1->DajPovrsinu()<k2->DajPovrsinu();}));
  cout<<"Kugla sa najvecom povrsinom je: ";
    kuglaa->Ispisi();
    int brojac(0);
    
    std::for_each(vektor.begin(),vektor.end(),[&brojac,vektor](std::shared_ptr<Kugla> k){auto it(std::find(vektor.begin(),vektor.end(),k)); int pozicija(it-vektor.begin()); for_each(vektor.begin()+pozicija+1,vektor.end(),[&brojac,k](std::shared_ptr<Kugla> k2){if(DaLiSeSijeku(*k,*k2)){std::cout<<"Presjecaju se kugle: ";k->Ispisi(); k2->Ispisi(); brojac++;} });});
    if(brojac==0)
    std::cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}
