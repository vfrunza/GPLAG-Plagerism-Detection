/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <stdexcept>
#include <vector> 
#include <cmath>
#include <tuple>
#include <algorithm>
#include <memory>
#include <iomanip>
#define eps 0.0000000001
#define PI 4*atan(1)
using namespace std;
bool test(0);


double kvadratich(double x){
    return x*x;
}

class Kugla{
  double x,y,z,r;
  
  public:
  explicit Kugla(double r=0){
      if(r<0)throw domain_error("Ilegalan poluprecnik");
      Kugla::r=r;
      Kugla::x=0;
      Kugla::y=0;
      Kugla::z=0;
      
  }
  Kugla(double x, double y, double z, double r=0){
      if(r<0)throw domain_error("Ilegalan poluprecnik");
      Kugla::r=r;
      Kugla::x=x;
      Kugla::y=y;
      Kugla::z=z;
  }
  explicit Kugla(const tuple<double,double,double> &centar, double r=0){
      if(r<0)throw domain_error("Ilegalan poluprecnik");
      Kugla::r=r;
      Kugla::x=get<0>(centar);
      Kugla::y=get<1>(centar);
      Kugla::z=get<2>(centar);
  }
  double DajX()const{return x;}
  double DajY()const{return y;}
  double DajZ()const{return z;}
  tuple<double,double,double>DajCentar()const{
    return tuple<double,double,double>(x,y,z);
}
double DajPoluprecnik()const{return r;}
double DajPovrsinu()const{return 4*PI*r*r;}
double DajZapreminu()const{return ((4*PI*r*r*r)/3);}
Kugla &PostaviX(double x){
    Kugla::x=x;
    return *this;
}
Kugla &PostaviY(double y){
    Kugla::y=y;
    return *this;
}
Kugla &PostaviZ(double z){
    Kugla::z=z;
    return *this;
}
Kugla &PostaviCentar(double x, double y, double z){
    this->x=x;
    this->y=y;
    this->z=z;
    return *this;
}
Kugla &PostaviCentar(const tuple<double,double,double>&centar){
    this->x=get<0>(centar);
    this->y=get<1>(centar);
    this->z=get<2>(centar);
    return *this;
}
Kugla &PostaviPoluprecnik(double r){
    if(r<0)throw domain_error("Ilegalan poluprecnik");
    this->r=r;
}
void Ispisi()const{
    cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}";
}
void Transliraj(double delta_x, double delta_y, double delta_z){
    this->x+=delta_x;
    this->y+=delta_y;
    this->z+=delta_z;
}
friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    if(!DaLiSuKoncentricne(k1,k2)) return false;
    if(fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<eps*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik()))) return false;
    return true;
}
friend bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
    if(k1.DajPoluprecnik()-k2.DajPoluprecnik()<eps*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik()))){
    return false;
    }
    return true;
}
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(fabs(k1.DajX()-k2.DajX())<eps*(fabs(k1.DajX())+fabs(k2.DajX()))) return false;
    if(fabs(k1.DajY()-k2.DajY())<eps*(fabs(k1.DajY())+fabs(k2.DajY()))) return false;
    if(fabs(k1.DajZ()-k2.DajZ())<eps*(fabs(k1.DajZ())+fabs(k2.DajZ()))) return false;
    return true;
}
    


friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    double temp(k1.DajPoluprecnik()+k2.DajPoluprecnik());
    if(fabs(RastojanjeCentra(k1,k2)-temp)<eps*(fabs(RastojanjeCentra(k1,k2))+fabs(temp))) return true;
    return false;   
}
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    double temp(k1.DajPoluprecnik()+k2.DajPoluprecnik());
    if(fabs(RastojanjeCentra(k1,k2)-temp)<eps*(fabs(RastojanjeCentra(k1,k2))+fabs(temp))) return false;
    if(RastojanjeCentra(k1,k2)<temp && (k1.DajPoluprecnik()==(k2.DajPoluprecnik()-RastojanjeCentra(k1,k2)) || k2.DajPoluprecnik()==(k1.DajPoluprecnik()-RastojanjeCentra(k1,k2)))) return true;
    return false;
}
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    double temp(k1.DajPoluprecnik()+k2.DajPoluprecnik());
    if (RastojanjeCentra(k1,k2)<temp) return true;
}
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    double temp1(k1.DajPoluprecnik());
    double temp2(k2.DajPoluprecnik());
    if (RastojanjeCentra(k1,k2)<temp1+temp2 && k1.DajCentar()!=k2.DajCentar() && (temp1>temp2-RastojanjeCentra(k1,k2) || temp2>temp1+RastojanjeCentra(k1,k2))) return true;
    return false;
}
bool DaLiSadrzi(const Kugla &k)const{
    return 0;
}
friend double RastojanjeCentra(const Kugla &k1, const Kugla &k2){
    return sqrt(kvadratich(k1.DajX()-k2.DajX())+kvadratich(k1.DajY()-k2.DajY())+kvadratich(k1.DajZ()-k2.DajZ()));
}


};

int main(){
    cout << "Unesite broj kugla: ";
    int broj;
    cin >> broj;
    while((!cin) || (broj<=0)) {
        cout << "Neispravan broj kugli, unesite ponovo!" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> broj;
    }
    vector<shared_ptr<Kugla>>kugle;
    kugle.resize(broj);
    for(int i=0; i<broj; i++) {
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        double x, y, z, r;
        cin >> x >> y >> z;
        while(!cin) {
            cout << "Neispravan centar" <<endl;
            cout << "Unesite centar " << i+1 << ". kugle: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> x >> y >> z;
        }
        cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        cin >> r;
        if(!cin) {
            cout << "Ilegalan poluprecnik" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            i--;
            continue;
        }
        try {
            kugle[i]=make_shared<Kugla>(Kugla(x,y,z,r));
        }catch(std::domain_error haa) {
            cout << haa.what() << std::endl;
            i--;
        }
    }
    
    cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x, y, z;
    cin >> x >> y >> z;
    while(!cin) {
        cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin>>x>>y>>z;
    }
    transform(kugle.begin(), kugle.end(), kugle.begin(), [x,y,z](shared_ptr<Kugla>t) {
        t->Transliraj(x,y,z);
        return t;
    });
    sort(kugle.begin(), kugle.end(), [](shared_ptr<Kugla>t1, shared_ptr<Kugla>t2) {
        return t1->DajZapreminu()<t2->DajZapreminu();
    });
    cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << endl;
    for_each(kugle.begin(), kugle.end(), [](shared_ptr<Kugla>t) {
        t->Ispisi();
        cout << endl;
    });
    cout << "Kugla sa najvecom povrsinom je: ";
    auto povrsina=max_element(kugle.begin(), kugle.end(), [](shared_ptr<Kugla>t1, shared_ptr<Kugla>t2) {
       return t1->DajPovrsinu()<t2->DajPovrsinu(); 
    });
    (*povrsina)->Ispisi();
    cout << endl;
    auto tempb(kugle.begin());
    auto tempe(kugle.end());
    for_each(tempb, tempe-1, [tempb, tempe](shared_ptr<Kugla>t1) {
        for_each(tempb+1, tempe, [t1, tempb, tempe](shared_ptr<Kugla>t2) {
           if(DaLiSeSijeku(*t1, *t2) && tempb!=tempe) {
               test=1;
               cout << "Presjecaju se kugle: ";
               (*t1).Ispisi();
               cout << endl;
               (*t2).Ispisi();
               cout << endl;
           } 
        });
    });
    if(!test) cout << "Ne postoje kugle koje se presjecaju!";
	return 0;
}
/* 

foreach(......, [](){
   if(presjecaju)
   return [](){
       ....
   }
   else return 0;
});

*/