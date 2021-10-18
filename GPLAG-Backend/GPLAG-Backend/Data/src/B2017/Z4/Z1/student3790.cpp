/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include<tuple>
#include<stdexcept>
#include<cmath>
#include<exception>
#include<memory>
#include<vector>
#include<algorithm>
#define pi (4*atan(1.0))
#define eps (10e-10)

template<typename tip>
bool jednako(tip x,tip y)
{
    if(x<0) x=-x;
    if(y<0) y=-y;
    if(x>y)
    return ((x-y)<eps*((x)+(y)));
    else return ((y-x)<eps*((x)+(y)));
}
class Kugla{
double x,y,z,r;
public:
explicit Kugla(double pol = 0){
    if(pol<0) throw std::domain_error("Ilegalan poluprecnik");
    x=0;
    y=0;
    z=0;
    r=pol;
}
Kugla(double x1, double y1, double z1, double r1 = 0){
    if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
    x=x1;
    y=y1;
    z=z1;
    r=r1;
}
explicit Kugla(const std::tuple<double, double, double> &centar, double r1 = 0){
    if(r1<0) throw std::domain_error("Ilegalan poluprecnik");
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    r=r1;
}
double DajX() const{
    return x;
}
double DajY() const{
    return y;
}
double DajZ() const{
    return z;
}
std::tuple<double, double, double> DajCentar() const{
    return (std::make_tuple(x,y,z));
   
}
double DajPoluprecnik() const{
    return r;
}
double DajPovrsinu() const{
    return 4*r*r*pi;
}
double DajZapreminu() const{
    return (4/3)*r*r*r*pi;
}
Kugla &PostaviX(double x1){
    x=x1;
    return *this;
}
Kugla &PostaviY(double y1){
    y=y1;
    return *this;
}
Kugla &PostaviZ(double z1){
    z=z1;
    return *this;
}
Kugla &PostaviCentar(double x1, double y1, double z1){
    x=x1;
    y=y1;
    z=z1;
    return *this;
}
Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
    x=std::get<0>(centar);
    y=std::get<1>(centar);
    z=std::get<2>(centar);
    return *this;
}
Kugla &PostaviPoluprecnik(double r1){
    r=r1;
    return *this;
}
//“{( , , ), }”.
void Ispisi() const{
    std::cout<<"{("<<x<<","<<y<<","<<z<<"),"<<r<<"}"<<std::endl;
}
void Transliraj(double delta_x, double delta_y, double delta_z){
    x+=delta_x;
    y+=delta_y;
    z+=delta_z;
}

friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);//URADJENO
friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);//URADJENO
friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);//URADJENO
friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);//URADJENO
friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);//URADJENO
friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);//URADJENO
friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
bool DaLiSadrzi(const Kugla &k) const{
return (r>=k.r+RastojanjeCentara(*this,k));
}
friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    return (jednako(k1.x,k2.x) and jednako(k2.y,k1.y) and  jednako(k2.z,k1.z) and jednako(k1.r,k2.r));
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return jednako(k1.r,k2.r);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
return (jednako(k1.x,k2.x) and jednako(k2.y,k1.y) and  jednako(k2.z,k1.z) );
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return (!(k1.DaLiSadrzi(k2) or k2.DaLiSadrzi(k1)) and jednako(RastojanjeCentara(k1,k2),k1.r+k2.r));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    return ((k1.DaLiSadrzi(k2) and jednako(k1.r,k2.r+RastojanjeCentara(k1,k2))) or (k2.DaLiSadrzi(k1) and jednako(k2.r,k1.r+RastojanjeCentara(k1,k2)) ) );
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    return(RastojanjeCentara(k1,k2)<k1.r+k2.r);
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    return (DaLiSePreklapaju(k1,k2) and !(k1.DaLiSadrzi(k2)  or k2.DaLiSadrzi(k1)));
}
int main ()
{
    int k=0;
    int n=0;
    std::cout<<"Unesite broj kugla: ";
    do{
      
    if(k>0) std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
    
    std::cin>>n;
    if(n<1){std::cin.clear(); std::cin.ignore(10000,'\n'); }
      k++;
     
    }while(n<1);
    std::vector<std::shared_ptr<Kugla>> v(n);
    try{
        for(int i=0;i<n;i++)
        {
            do{
            std::cout<<"Unesite centar "<<i+1 <<". kugle: ";
            double x,y,z;
            std::cin>>x>>y>>z;
            if(!(std::cin)) { std::cin.clear(); std::cin.ignore(10000,'\n'); std::cout<<"Neispravan centar\n"; continue;}
            
            v[i]=std::make_shared<Kugla>(x,y,z);
            double r;
            
            std::cout<<"Unesite poluprecnik "<<i+1 <<". kugle: ";
            std::cin>>r;
            if(!(std::cin) or r<0){ std::cin.clear(); std::cin.ignore(10000,'\n'); std::cout<<"Ilegalan poluprecnik\n"; continue;}
            else{
            (*v[i]).PostaviPoluprecnik(r);
                break;
            }
            }while (1); 
            
            
            
        }
        double delta_x,delta_y,delta_z;
        
        std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        do{
        std::cin>>delta_x>>delta_y>>delta_z;
        if(!(std::cin)){std::cin.clear(); std::cin.ignore(10000,'\n'); std::cout<<"Neispravni parametri translacije, unesite ponovo!\n"; continue;}
        else break;
        }while (true);
        std::transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y,delta_z] (std::shared_ptr<Kugla> p1) {(*p1).Transliraj(delta_x,delta_y,delta_z); return p1; });
        std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla> p1,std::shared_ptr<Kugla> p2){return ((*p1).DajZapreminu()<(*p2).DajZapreminu());});
        std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
        std::for_each(v.begin(),v.end(),[](std::shared_ptr<Kugla> p1){(*p1).Ispisi();   });
        auto p=std::max_element(v.begin(),v.end(),[](std::shared_ptr<Kugla> p1,std::shared_ptr<Kugla> p2){return ((*p1).DajPovrsinu()<(*p2).DajPovrsinu());});
        std::cout<<"Kugla sa najvecom povrsinom je: ";
        (**p).Ispisi();
        int br=0,br1=0;
        std::for_each(v.begin(),v.end(),[&br,v,&br1](std::shared_ptr<Kugla> p1){
            
            std::for_each(v.begin()+br1,v.end(),[&br,p1](std::shared_ptr<Kugla> p2){
                if(DaLiSeSijeku(*p1,*p2)){ std::cout<<"\nPresjecaju se kugle: ";
                (*p1).Ispisi();
                std::cout<<std::endl;
                (*p2).Ispisi();
                br++;}
            });
           br1++; 
        });
        if(br==0) std::cout<<"\nNe postoje kugle koje se presjecaju!";
    }
    catch(std::exception &e){
        std::cout<<e.what();
    }
	return 0;
}
