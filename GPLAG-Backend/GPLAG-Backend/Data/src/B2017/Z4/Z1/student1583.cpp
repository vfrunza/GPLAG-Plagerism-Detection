/B2017/2018: Zadaæa 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <new>
#include <memory>
#include <stdexcept>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

constexpr double pi{4*atan(1)};
constexpr double epsilon{1e-10};


class Kugla{

double x,y,z;
double r;

static bool Ispravan_poluprecnik (const Kugla &kugla){ return kugla.DajPoluprecnik()>=0; }

static bool Ista_vrijednost (double a, double b) {return std::fabs(a-b)<=epsilon*(std::fabs(a)+std::fabs(b));} //da li su dva realna broja jednaka

static double Udaljenost_izmedju_tacaka (const std::tuple<double,double,double> &koordinata1, const std::tuple<double,double,double> &koordinata2) {
    double x1,x2,y1,y2,z1,z2; std::tie(x1,y1,z1) = koordinata1; std::tie(x2,y2,z2) = koordinata2;
    return std::sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1) );
}


public:

explicit Kugla(double r = 0 ) { PostaviPoluprecnik(r); PostaviCentar(0,0,0); }
Kugla(double x, double y, double z, double r = 0) {PostaviPoluprecnik(r); PostaviCentar(x,y,z);}
explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){ PostaviPoluprecnik(r); PostaviCentar(centar); }
double DajX() const{return x;}
double DajY() const{return y;}
double DajZ() const{return z;}
std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x,y,z); }
double DajPoluprecnik() const { return r; }
double DajPovrsinu() const { return 4*DajPoluprecnik()*DajPoluprecnik()*pi; }
double DajZapreminu() const { return (4*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik()*pi)/3; }
Kugla &PostaviX(double x){ Kugla::x=x; return *this;}
Kugla &PostaviY(double y){ Kugla::y=y; return *this;}
Kugla &PostaviZ(double z){ Kugla::z=z; return *this;}
Kugla &PostaviCentar(double x, double y, double z){ Kugla::x=x; Kugla::y=y; Kugla::z=z; return *this; }
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { std::tie(x,y,z) = centar; return *this; }
Kugla &PostaviPoluprecnik(double r) { if(r<0) throw std::domain_error ("Ilegalan poluprecnik"); Kugla::r=r; return *this;}
void Ispisi() const { cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}\n"; }
void Transliraj(double delta_x, double delta_y, double delta_z) {x+=delta_x; y+=delta_y; z+=delta_z;}

friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return { Ista_vrijednost(k1.DajX(),k2.DajX()) && Ista_vrijednost(k1.DajY(),k2.DajY()) && Ista_vrijednost(k1.DajZ(),k2.DajZ()) && Ista_vrijednost(k1.DajPoluprecnik(),k2.DajPoluprecnik()) };
}
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) { return Ista_vrijednost(k1.DajPoluprecnik(),k2.DajPoluprecnik()); }
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) { return Ista_vrijednost(k1.DajX(),k2.DajX()) && Ista_vrijednost(k1.DajY(),k2.DajY()) && Ista_vrijednost(k1.DajZ(),k2.DajZ()); }
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) { return Ista_vrijednost(k1.DajPoluprecnik()+k2.DajPoluprecnik(),RastojanjeCentara(k1,k2)); }
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) { return { Ista_vrijednost(std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()),RastojanjeCentara(k1,k2)) && ( !DaLiSuIdenticne(k1,k2) || (Ista_vrijednost(k1.DajPoluprecnik(),0) && Ista_vrijednost(k2.DajPoluprecnik(),0)) )  };  }
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) { return k1.DajPoluprecnik()+k2.DajPoluprecnik()>RastojanjeCentara(k1,k2); }
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) { return { k1.DajPoluprecnik()+k2.DajPoluprecnik()>RastojanjeCentara(k1,k2) &&
                            !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1)  }; }
bool DaLiSadrzi(const Kugla &k) const{ return DajPoluprecnik()-k.DajPoluprecnik()>RastojanjeCentara(*this,k) ||
                                        Ista_vrijednost( DajPoluprecnik()-k.DajPoluprecnik(),RastojanjeCentara(*this,k) ); }
friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) { return Udaljenost_izmedju_tacaka(k1.DajCentar(), k2.DajCentar()); }

};


int main(){
   
   
cout<<"Unesite broj kugla: ";
int n;
while(!(cin>>n) || n<=0){
cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
std::cin.clear();
std::cin.ignore(10000,'\n');
}


try{
std::vector<std::shared_ptr<Kugla>> v;

for(int i=0;i<n;i++){
    
        double x,y,z,r;

cout<<"Unesite centar "<<i+1<<". kugle: ";


    
while(!(cin>>x>>y>>z) ){
        cout<<"Neispravan centar"<<endl;
        cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
}

cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
cin>>r;

while(!cin || r<0 ){
    
    cout<<"Ilegalan poluprecnik"<<endl;
    cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        
        while(!(cin>>x>>y>>z) ){
        cout<<"Neispravan centar"<<endl;
        cout<<"Unesite centar "<<i+1<<". kugle: ";
        std::cin.clear();
        std::cin.ignore(10000,'\n');
}

cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
cin>>r;
        
}




std::shared_ptr<Kugla> pok_na_kuglu( std::make_shared<Kugla> (Kugla(x,y,z,r)) );

v.push_back(pok_na_kuglu);

}


cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
double delta_x,delta_y,delta_z;
while(!(cin>>delta_x>>delta_y>>delta_z)){
    cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
}

std::transform( v.begin(),v.end(),v.begin(), [delta_x,delta_y,delta_z]  (std::shared_ptr<Kugla> pok_na_kuglu) { pok_na_kuglu->Transliraj(delta_x,delta_y,delta_z); return pok_na_kuglu; } );

std::sort( v.begin(),v.end(), [] (std::shared_ptr<Kugla> pok_na_kuglu1, std::shared_ptr<Kugla> pok_na_kuglu2 ) {return pok_na_kuglu1->DajZapreminu()<pok_na_kuglu2->DajZapreminu(); } );

cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
std::for_each(v.begin() ,v.end(), [] (std::shared_ptr<Kugla> pok_na_kuglu) { pok_na_kuglu->Ispisi(); } );

auto pok_na_max (std::max_element( v.begin(),v.end(),[] (std::shared_ptr<Kugla> pok_na_kuglu1, std::shared_ptr<Kugla> pok_na_kuglu2 ) { return pok_na_kuglu1->DajPovrsinu()<pok_na_kuglu2->DajPovrsinu(); } ));
cout<<"Kugla sa najvecom povrsinom je: ";
if(pok_na_max!=v.end()) (*pok_na_max)->Ispisi();

int cnt(0);
bool nalaze_se_barem_dvije_kugle_koje_se_sijeku{false};

std::for_each(v.begin(),v.end(), [v,&cnt,&nalaze_se_barem_dvije_kugle_koje_se_sijeku] (std::shared_ptr<Kugla> p) { 
    std::for_each(v.begin()+cnt+1,v.end(),[p,&nalaze_se_barem_dvije_kugle_koje_se_sijeku] (std::shared_ptr<Kugla> q) { if( DaLiSeSijeku(*p,*q) ) { nalaze_se_barem_dvije_kugle_koje_se_sijeku=true; cout<<"Presjecaju se kugle: "; p->Ispisi(); q->Ispisi();} } ); 
    cnt++;
} );

if(!nalaze_se_barem_dvije_kugle_koje_se_sijeku) cout<<"Ne postoje kugle koje se presjecaju!"<<endl;
}
catch(std::bad_alloc){
    cout<<"Problemi sa memorijom\n";
}




return 0;
}
