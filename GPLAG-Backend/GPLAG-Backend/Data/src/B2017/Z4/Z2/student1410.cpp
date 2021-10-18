#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <memory>
#include <algorithm>
using std::cout;
using std::cin;
const double PI(4*atan(1));
const double eps(1e-10);
class NepreklapajucaKugla{
    double R,X,Y,Z;
   static double DajUdaljenost(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2){
        auto udaljenost(sqrt(pow(k1.X-k2.X,2)+pow(k1.Y-k2.Y,2)+pow(k1.Z-k2.Z,2)));
        return udaljenost;
    }
public:
explicit NepreklapajucaKugla(double r=0){
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    X=0; Y=0; Z=0; R=r;
}
 NepreklapajucaKugla(double x,double y,double z,double r=0){
     if(r<0) throw std::domain_error("Ilegalan poluprecnik");
     X=x; Y=y; Z=z; R=r;
 }
 explicit NepreklapajucaKugla(const std::tuple<double,double,double>&centar,double r=0){
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
 //NAPRAVITI PROVJERU
 NepreklapajucaKugla &PostaviX(double x){ X=x; return *this;}
 NepreklapajucaKugla &PostaviY(double y){Y=y; return *this;}
 NepreklapajucaKugla &PostaviZ(double z){Z=z; return *this;}
 NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
     X=x;Y=y;Z=z; return *this;}
 NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){std::tie(X,Y,Z)=centar; return *this;}
 NepreklapajucaKugla &PostaviPoluprecnik(double r){
      if(r<0) throw std::domain_error("Ilegalan poluprecnik");
     R=r; return *this;
 }

 void Ispisi() const{
     std::cout<<"{("<<X<<","<<Y<<","<<Z<<"),"<<R<<"}"<<std::endl;
 }

void Transliraj(double delta_x, double delta_y, double delta_z){
    X+=delta_x; Y+=delta_y; Z+=delta_z;
}
bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
     auto D(sqrt(pow(X-k.X,2)+pow(Y-k.Y,2)+pow(Z-k.Z,2)));
      auto razlika(fabs(R-k.R));
       if(D<razlika) return true;
       return false;
}
friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    auto udaljenost(DajUdaljenost(k1,k2)); 
    return udaljenost;
}
};

int main ()
{
    /*
cout<<"Unesite broj kugla: ";
int n;
cin>>n;
double x,y,z,r;
std::vector<std::shared_ptr<Kugla>> vektor;
for(int i(0);i<n;i++){
    try{
    cout<<"Unesite centar "<<i+1<<". kugle: ";
    cin>>x>>y>>z;
    cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
    cin>>r;
    auto kugla(std::make_shared<Kugla>(x,y,z,r));
    vektor.push_back(kugla);
 }catch(std::domain_error e){
        std::cout<<e.what();
        i--; }
}
double deltaX,deltaY,deltaZ;
cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
cin>>deltaX>>deltaY>>deltaZ;
cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: ";
std::transform(vektor.begin(),vektor.end(),vektor.begin(),[deltaX,deltaY,deltaZ](std::shared_ptr<Kugla> k1){ k1->Transliraj(deltaX,deltaY,deltaZ);});
std::sort(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2){return k1->DajZapreminu()<k2->DajZapreminu();});
std::for_each(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla>k){k->Ispisi();});
/*  Na kraju, program treba pronaći sve parove kugli koje se presjecaju i ispisati koje su to
kugle (ili ispisati obavijest da takvih kugli nema). Ovo također trebate izvesti bez petlji nego
kaskadnom primjenom funkcije “foreach”, odnosno tako što će jedan poziv “foreach” funkcije
koristiti lambda funkciju u čijem će se tijelu nalaziti poziv druge lambda funkcije.*/
    auto kuglaa(*std::max_element(vektor.begin(),vektor.end(),[](std::shared_ptr<Kugla>k1,std::shared_ptr<Kugla>k2){return k1->DajPovrsinu()>k2->DajPovrsinu();}));
    //kuglaa je pok
    cout<<"Kugla sa najvecom povrsinom je: ";
    kuglaa->Ispisi();
   // std::for_each(vektor.begin(),vektor.end(),[]())*/
	return 0;
}
