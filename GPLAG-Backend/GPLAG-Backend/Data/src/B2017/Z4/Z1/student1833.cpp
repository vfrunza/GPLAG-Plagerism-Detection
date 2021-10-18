/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
   
  
 class  Kugla {
     
     public: 
     //konstruktori
     explicit Kugla (double r=0); 
     Kugla(double x, double y, double z, double r=0); 
     explicit Kugla(const std::tuple<double,double, double> &centar, double r=0); 
     // metode
     double DajX() const { return x; }
     double DajY() const { return y; }
     double DajZ() const { return z; }
     
     std::tuple<double, double, double> DajCentar() const; 
     double DajPoluprecnik () const; 
     double DajPovrsinu () const: 
     double DajZapreminu() const; 
     
     
     Kugla &PostaviX
     Kugla &PostaviY
     Kugla &PostaviZ
     Kugla &PostaviCentar
     Kugla &PostaviCentar
     Kugla &PostaviPoluprecnik
     void Ispisi
     void Transliraj
     
 };
int main ()
{
	return 0;
}
