/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <memory>
using namespace std;
class Kugla
{
    double x,y,z,r;
    //if(r<0)throw logic_error("Ne moze negativan");

public:
explicit Kugla (double r=0){if(r<0)throw domain_error("Ilegalan poluprecnik");else x=y=z=r=0;};
Kugla (double x,double y,double z,double r=0){x=x;y=y;z=z;r=r;};
explicit Kugla (const tuple<double,double,double> &centar,double r=0){tie(x,y,z)=centar;}
double DajX() const{return x;}
double DajY() const{return y;}
double DajZ() const{return z;}
tuple<double,double,double> DajCentar() const{return {make_tuple(x,y,z)};}
double DajPoluprecnik() const{return r;}
double DajPovrsinu() const{return (r*r*4*4*atan(1));}
double DajZapreminu() const{return ((4*r*r*r*4*atan(1))/3);}
Kugla &PostaviX (double x){Kugla::x=x;return *this;};
Kugla &PostaviY (double y){Kugla::y=y;return *this;}
Kugla &PostaviZ (double z){Kugla::z=z;return *this;}
Kugla &PostaviCentar (double x,double y,double z){Kugla::x=x;Kugla::y=y;Kugla::z=z;return *this;}
Kugla &PostaviCentar (const tuple<double,double,double> &centar){make_tuple(x,y,z);return *this;}
Kugla &PostaviPoluprecnik (double r){if(r<0)throw logic_error ("Ilegalan poluprecnik");else Kugla::r=r;return *this;}
void Ispisi() const{cout<<"{("<<DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"<<endl;}
void Transiliraj(double delta_x,double delta_y,double delta_z){x+=delta_x;y+=delta_y;z+=delta_z;}
friend bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2);
friend bool DaLiSuPodudarne (const Kugla &k1,const Kugla &k2);
friend bool DaLiSuKoncentricne (const Kugla &k1,const Kugla &k2);
friend bool DaLiSeDodirujuIzvana (const Kugla &k1,const Kugla &k2);
friend bool DaLiSeDodirujuIznutra (const Kugla &k1,const Kugla &k2);
friend bool DaLiSePreklapaju (const Kugla &k1,const Kugla &k2);
friend bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2);
bool DaLiSadrzi(const Kugla &k)const;
friend double RastojanjeCentra (const Kugla &k1,const Kugla &k2);
};
bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2)
{
    if(k1.DajX()==k2.DajX() && k1.DajY()==k2.DajY() && k1.DajZ()==k2.DajZ() && k1.DajPoluprecnik()==k2.DajPoluprecnik())
    return true;
    else return false;
}
bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2)
{
    if(k1.DajPoluprecnik()==k2.DajPoluprecnik())return true;
    else return false;
}
bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2)
{
    if(k1.DajX()==k2.DajX() && k1.DajY()==k2.DajY() && k1.DajZ()==k2.DajZ())return true;
    else return false;
}
//bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2)
bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2)
{
if(sqrt(pow(k1.DajX()-k2.DajX(),2)+pow(k1.DajY()-k2.DajY(),2)+pow(k1.DajZ()-k2.DajZ(),2))<k1.DajPoluprecnik()+k2.DajPoluprecnik())
return true;
else return false;
}
double RastojanjeCentra(const Kugla &k1,const Kugla &k2)
{
    if(k1.DajPoluprecnik()<0)throw logic_error("Ilegalan poluprecnik");
    else if(k2.DajPoluprecnik()<0)throw logic_error("Ilegalan poluprecnik");
    else {
        double rastojanje;
        rastojanje=sqrt(pow(k1.DajX()-k2.DajX(),2)+pow(k1.DajY()-k2.DajY(),2)+pow(k1.DajZ()-k2.DajZ(),2));
        return rastojanje;
    }
    
}
int main ()
{
    int n;
    cin>>n;
    vector<shared_ptr<Kugla>> *v;
    for(int i=0;i<n;i++)
    {
        double x,y,z,r;
        Kugla k;
        cin>>x;
        cin>>y;
        cin>>z;
        cin>>r;
        k= shared_ptr<double> (new *Kugla(x,y,z,r));
        v.push_back->k;
    }
    
	return 0;
}
