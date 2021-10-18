/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <iomanip>

 double stepenovan(){
        double x(1);
        for (int i(0);i<10;i++){
            x/=10;
        }
        return x;
    }
    double const eps=stepenovan();
   
 class Kugla {
     double x;
     double y;
     double z;
     double poluprecnik;
     
    public:

    
     
     explicit Kugla(double r=0){ 
         if (r<0){ 
         throw std::domain_error("Ilegalan poluprecnik");}
     x=y=z=0;poluprecnik=r;}
    
   
     Kugla(double a, double b, double c,double r=0){
         if (r<0){ throw std::domain_error("Ilegalan poluprecnik");}
         x=a;
         y=b;
         z=c;
         poluprecnik=r;
     }
     
     
     explicit Kugla(std::tuple<double,double,double> &centar, double r=0){
         if (r<0){ throw std::domain_error("Ilegalan poluprecnik");}
        poluprecnik=r;
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
     }
     
     double DajX() const{
         return x;
     }
     double DajY() const{
         return y;
     }
     double DajZ() const {
         return z;
     }
     
     std::tuple<double,double,double> DajCentar() const {
         return std::make_tuple(x,y,z);
     }
     
    double DajPoluprecnik() const {
         return poluprecnik;
     }
     
    double  DajPovrsinu() const {
         return 4*poluprecnik*poluprecnik*(4*atan(1));
     }
     
     double DajZapreminu() const {
         return (4*poluprecnik*poluprecnik*poluprecnik*(4*atan(1)))/3;
     }
     
     Kugla &PostaviX(double a){
         x=a;
         return *this;
     }
     
     Kugla &PostaviY(double b){
         y=b;
         return *this;
     }
     
     Kugla &PostaviZ(double c){
         z=c;
         return *this;
     }
     Kugla &PostaviCentar (double a, double b, double c){
         x=a;
         y=b;
         z=c;
         return *this;
     }
     
     Kugla &PostaviCentar(const std::tuple<double,double,double> &centar){
         x=std::get<0>(centar);
         y=std::get<1>(centar);
         z=std::get<2>(centar);
         return *this;
     }
     Kugla &PostaviPoluprecnik(double r){
         if (r<0){throw std::domain_error("Ilegalan poluprecnik");};
         poluprecnik=r;
         return *this;
     }
     
     void Ispisi() const {
         std::cout<<"{"<<" "<<"("<<x<<","<<y<<","<<z<<")"<<","<<poluprecnik<<" }";
     }
     
     void Transliraj( double deltax, double deltay, double deltaz){
         x+=deltax;
         y+=deltay;
         z+=deltaz;
     }
     
     friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2){
         return (std::fabs(k1.poluprecnik - k2.poluprecnik) < ((k1.poluprecnik+k2.poluprecnik)*eps)) && (std::fabs((k1.x - k2.x)  <((k1.x+k2.x)*eps))) && (std::fabs(k1.y - k2.y)<((k1.y+k2.y)*eps) && (std::fabs(k1.z - k2.z) < ((k1. z +k2.z)*eps)));
         
     }
     
     friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
         return  (std::fabs(k1.poluprecnik-k2.poluprecnik)<((k1.poluprecnik+k2.poluprecnik)*eps));
     }
     
     friend bool DaLiSuKoncentricne( const Kugla &k1, const Kugla &k2){
         return  (std::fabs((k1.x - k2.x)  <((k1.x+k2.x)*eps))) && (std::fabs(k1.y - k2.y)<((k1.y+k2.y)*eps)) && (std::fabs(k1.z - k2.z) < ((k1. z +k2.z)*eps));
     }
     
     friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
         return ((std::fabs(k1.x)+std::fabs(k2.x) - (k1.poluprecnik+k2.poluprecnik))<eps&&(std::fabs(k1.x)+std::fabs(k2.x) - (k1.poluprecnik+k2.poluprecnik))>(-eps))&&((std::fabs(k1.y)+std::fabs(k2.y) - (k1.poluprecnik+k2.poluprecnik)<eps)&&(std::fabs(k1.y)+std::fabs(k2.y) - (k1.poluprecnik+k2.poluprecnik))>(-eps))&&(((std::fabs(k1.z)+std::fabs(k2.z) - (k1.poluprecnik+k2.poluprecnik))<eps)&&(std::fabs(k1.z)+std::fabs(k2.z) - (k1.poluprecnik+k2.poluprecnik))>(-eps));
     }
     
     friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
       return (((std::fabs(std::fabs(k1.x)-std::fabs(k2.x))<k1.poluprecnik)||(std::fabs(std::fabs(k1.x)-std::fabs(k2.x))<k2.poluprecnik))&&((std::fabs(std::fabs(k1.y)-std::fabs(k2.y))<k1.poluprecnik)||(std::fabs(std::fabs(k1.y)-std::fabs(k2.y))<k2.poluprecnik))&&((std::fabs(std::fabs(k1.z)-std::fabs(k2.z))<k1.poluprecnik)||(std::fabs(std::fabs(k1.z)-std::fabs(k2.z))<k2.poluprecnik)))&&((std::fabs(k1.x)+std::fabs(k2.x) - (k1.poluprecnik+k2.poluprecnik))<eps)&&(std::fabs(k1.y)+std::fabs(k2.y) - (k1.poluprecnik+k2.poluprecnik)<eps)&&((std::fabs(k1.z)+std::fabs(k2.z) - (k1.poluprecnik+k2.poluprecnik))<eps);
     }
     
     friend bool DaLiSePreklapaju( const Kugla &k1, const Kugla &k2){
         return ((std::fabs(k1.x)+std::fabs(k2.x))<(k1.poluprecnik+k2.poluprecnik))&&((std::fabs(k1.y)+fabs(k2.y))<(k1.poluprecnik+k2.poluprecnik))&&((std::fabs(k1.z)+std::fabs(k2.z))<(k1.poluprecnik+k2.poluprecnik));
     }
     friend bool DaLiSeSijeku ( const Kugla &k1, const Kugla &k2){
         return DaLiSePreklapaju(k1,k2);
     }
     
     bool DaLiSadrzi(const Kugla &k1) const {
         return ((std::fabs(x)+std::fabs(y))<(poluprecnik-k1.poluprecnik))&&((std::fabs(y)+std::fabs(y))<(poluprecnik-k1.poluprecnik))&&((std::fabs(z)+std::fabs(z))<(poluprecnik-k1.poluprecnik));
     }
     
     friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
         return sqrt(pow(k1.x+k2.x,2)+pow(k1.y+k2.y,2)+pow(k1.z,k2.z));
     }
 };
 
 

int main ()
{
    int n(0);
    std::cin>>n;
    std::vector<shared_ptr>
	return 0;
}
