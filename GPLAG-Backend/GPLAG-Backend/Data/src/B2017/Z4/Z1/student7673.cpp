/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <vector>
#include <memory>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace std;

double eps=0.0000000001;
double pi=atan(1) * 4;



class Kugla
{
private:
    double xk,yk,zk,p;
public:
    explicit Kugla(double r = 0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        p=r;
        xk=0; yk=0; zk=0;
    }
    Kugla(double x, double y, double z, double r = 0){
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        p=r;
        xk=x; yk=y; zk=z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0){
        
        if(r<0) throw domain_error("Ilegalan poluprecnik");
        p=r;
        xk=get<0>(centar);
        yk=get<1>(centar);
        zk=get<2>(centar);
    }
    double DajX() const { return xk;}
    double DajY() const {return yk;}
    double DajZ() const {return zk;}
    std::tuple<double, double, double> DajCentar() const { return make_tuple(xk,yk,zk);}
    double DajPoluprecnik() const { return p;}
    double DajPovrsinu() const {return 4*pi*p*p;}
    double DajZapreminu() const {return (4*pi*p*p*p)/3;}
    Kugla &PostaviX(double x) { xk=x; return *this;}
    Kugla &PostaviY(double y) {yk=y;return *this;}
    Kugla &PostaviZ(double z) {zk=z;return *this;}
    Kugla &PostaviCentar(double x, double y, double z){
        xk=x;
        yk=y;
        zk=z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        xk=get<0>(centar);
        yk=get<1>(centar);
        zk=get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) { if(r<0) throw domain_error("Ilegalan poluprecnik");p=r;return *this;}
    void Ispisi() const{
        cout<<"{("<<xk<<","<<yk<<","<<zk<<"),"<<p<<"}"<<endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        xk+=delta_x; yk+=delta_y; zk+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        return k1.DajX()==k2.DajX() && k1.DajY()==k2.DajY() && k1.DajZ()==k2.DajZ() && k1.DajPoluprecnik()==k2.DajPoluprecnik();
    }
    
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
    {
        return k1.DajPoluprecnik()==k2.DajPoluprecnik();
    }
    
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
    {
       return k1.DajX()==k2.DajX() && k1.DajY()==k2.DajY() && k1.DajZ()==k2.DajZ();
    }
    
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
    {
       return Udaljenost(k1,k2)>0;
    }
    
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
    {
        return Udaljenost(k1,k2)<0;
    }
    
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
    {
        return Udaljenost(k1,k2)==0;
    }
    
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
    {
        return Udaljenost(k1,k2)>0 || Udaljenost(k1,k2)<0;
    }
    
    bool DaLiSadrzi(const Kugla &k) const
    {
        return DaLiSePreklapaju(*this,k);
    }
    
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
    {
        return Udaljenost(k1,k2);
    }
    
    friend double Udaljenost(const Kugla k1,const Kugla k2)
    {
        return sqrt((k2.DajX()-k1.DajX())*k2.DajX()-k1.DajX()+(k2.DajY()-k1.DajY())*k2.DajY()-k1.DajY()+(k2.DajZ()-k1.DajZ())*k2.DajZ()-k1.DajZ());
    }

};


int main ()
{   
    int n;
    cout<<"Unesite broj kugla: ";
    cin>>n;
    
    
    vector<shared_ptr<Kugla>> v(n);
	
	for(int i=0;i<n;i++)
	{
	    cout<<"Unesite centar "<<i+1<<". kugle: ";
	    double a,b,c;
	    cin>>a>>b>>c;
	    tuple<double,double,double> cr(make_tuple(a,b,c));
	    
	    cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
	    double r;
	    cin>>r;
	    
	    v[i]=make_shared<Kugla>(cr,r);
	}
	
	double dx,dy,dz;
	cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
	cin>>dx>>dy>>dz;
	transform(v.begin(),v.end(),v.begin(),[&dx,&dy,&dz](shared_ptr<Kugla> k){k->Transliraj(dx,dy,dz);return k;});
    sort(v.begin(),v.end(),[](shared_ptr<Kugla> k1,shared_ptr<Kugla> k2){
        return (4/3)*k1->DajPoluprecnik()*k1->DajPoluprecnik()*k1->DajPoluprecnik()*pi<(4/3)*k2->DajPoluprecnik()*k2->DajPoluprecnik()*k2->DajPoluprecnik()*pi;
    });
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
    for_each(v.begin(),v.end(),[](shared_ptr<Kugla> k){k->Ispisi();});
	
	auto k=max_element(v.begin(),v.end(),[](shared_ptr<Kugla> k1,shared_ptr<Kugla> k2){return k1->DajPoluprecnik()*k1->DajPoluprecnik()*pi<k2->DajPoluprecnik()*k2->DajPoluprecnik()*pi;});
	
	
	cout<<"Kugla sa najvecom povrsinom je: ";
    k->get()->Ispisi();
	
    bool ima=0;
	for_each(v.begin(),v.end(),[v,&ima](shared_ptr<Kugla> k){for_each(v.begin(),v.end(),[k,&ima](shared_ptr<Kugla> k1){if (DaLiSeSijeku(*k,*k1)){ima=1; cout<<"Presjecaju se kugle: ";k->Ispisi();k1->Ispisi();}});});
	   if(ima==0)cout<<"Ne postoje kugle koje se presjecaju!";     

	return 0;
}
