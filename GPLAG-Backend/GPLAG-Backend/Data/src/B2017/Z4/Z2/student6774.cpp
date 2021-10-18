#include <iostream>
#include<tuple>
#include<stdexcept>
#include<memory>
#include<vector>
#include<cmath>
#include<algorithm>

#define PI 4*atan(1)
#define epsilon pow(10,-10)

class NepreklapajucaKugla{
    double x,y,z,r;
    public:
    explicit NepreklapajucaKugla(double r1 = 0){
        if(r1<0)throw  std::domain_error{"Ilegalan poluprecnik"};
        x=0;y=0;z=0;r=r1;
    }
NepreklapajucaKugla(double x1, double y1, double z1, double r1 = 0){
    if(r1<0)throw  std::domain_error{"Ilegalan poluprecnik"};
    x=x1;y=y1;z=z1;r=r1;
}
explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r1 = 0){
    if(r1<0)throw  std::domain_error{"Ilegalan poluprecnik"};
    x=std::get<0>(centar);y=std::get<1>(centar);z=std::get<2>(centar);r=r1;
}
double DajX() const{return x;}
double DajY() const{return y;}
double DajZ() const{return z;}
std::tuple<double, double, double> DajCentar() const{
    return std::make_tuple(x,y,z);
}
double DajPoluprecnik() const{return r;}
double DajPovrsinu() const{return  4*r*r*PI;}
double DajZapreminu() const{return (4/3)*r*r*r*PI;}
NepreklapajucaKugla &PostaviX(double x1){x=x1;return *this;}
NepreklapajucaKugla &PostaviY(double y1){y=y1;return *this;}
NepreklapajucaKugla &PostaviZ(double z1){z=z1;return *this;}
NepreklapajucaKugla &PostaviCentar(double x1, double y1, double z1){x=x1;y=y1;z=z1;return *this;}
NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){x=std::get<0>(centar);y=std::get<1>(centar);z=std::get<2>(centar);return *this;}
NepreklapajucaKugla &PostaviPoluprecnik(double r1){r=r1;return *this;}
void Ispisi() const{std::cout << "{("<<x<<","<< y<<","<< z<<"),"<< r<<"}" << std::endl;}
void Transliraj(double dx, double dy, double dz){x+=dx;y+=dy;z+=dz;}
friend bool DaLiSuIdenticne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSuPodudarne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSuKoncentricne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSeDodirujuIzvana(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSeDodirujuIznutra(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
friend bool DaLiSeSijeku(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
bool DaLiSadrzi(const NepreklapajucaKugla &k2) const{
    if(sqrt((x-k2.x)*(x-k2.x)+(y-k2.y)*(y-k2.y)+(z-k2.z)*(z-k2.z))<r-k2.r||sqrt((x-k2.x)*(x-k2.x)+(y-k2.y)*(y-k2.y)+(z-k2.z)*(z-k2.z))<k2.r-r)return true;
     if(sqrt((x-k2.x)*(x-k2.x)+(y-k2.y)*(y-k2.y)+(z-k2.z)*(z-k2.z))-epsilon<r-k2.r+epsilon||sqrt((x-k2.x)*(x-k2.x)+(y-k2.y)*(y-k2.y)+(z-k2.z)*(z-k2.z))-epsilon<k2.r-r+epsilon)return true;
   if(sqrt((x-k2.x)*(x-k2.x)+(y-k2.y)*(y-k2.y)+(z-k2.z)*(z-k2.z))+epsilon<r-k2.r-epsilon||sqrt((x-k2.x)*(x-k2.x)+(y-k2.y)*(y-k2.y)+(z-k2.z)*(z-k2.z))+epsilon<k2.r-r-epsilon)return true;
    return false;
}
friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
bool DaLiSuIdenticne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    if(k1.x==k2.x&&k1.y==k2.y&&k1.z==k2.z&&k1.r==k2.r)return true;
    if(k1.x-epsilon==k2.x+epsilon&&k1.y-epsilon==k2.y+epsilon&&k1.z-epsilon==k2.z+epsilon&&k1.r-epsilon==k2.r+epsilon)return true;
   if(k1.x+epsilon==k2.x-epsilon&&k1.y+epsilon==k2.y-epsilon&&k1.z+epsilon==k2.z-epsilon&&k1.r+epsilon==k2.r-epsilon)return true;
   return false;
}
bool DaLiSuPodudarne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){if(k1.r==k2.r)return true; if(k1.r+epsilon==k2.r-epsilon)return true;if(k1.r-epsilon==k2.r+epsilon)return true;return false; }
bool DaLiSuKoncentricne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){if(k1.x==k2.x&&k1.y==k2.y&&k1.z==k2.z)return true;if(k1.x+epsilon==k2.x-epsilon&&k1.y+epsilon==k2.y-epsilon&&k1.z+epsilon==k2.z-epsilon)return true;if(k1.x-epsilon==k2.x+epsilon&&k1.y-epsilon==k2.y+epsilon&&k1.z-epsilon==k2.z+epsilon)return true;return false;}
bool DaLiSeDodirujuIzvana(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))+epsilon==k1.r+k2.r-epsilon)return true;
   if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))-epsilon==k1.r+k2.r+epsilon)return true;
   if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))==k1.r+k2.r)return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))+epsilon==k1.r-k2.r-epsilon||sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))+epsilon==k2.r-k1.r-epsilon)return true;
    if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))-epsilon==k1.r-k2.r+epsilon||sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))-epsilon==k2.r-k1.r+epsilon)return true;
    if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))+epsilon==k1.r-k2.r-epsilon||sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))-epsilon==k2.r-k1.r+epsilon)return true;
  if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))+epsilon==k1.r-k2.r-epsilon||sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))+epsilon==k2.r-k1.r-epsilon)return true;
    if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))==k1.r-k2.r||sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))==k2.r-k1.r)return true;
  
    return false;
}
bool DaLiSeSijeku(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))+epsilon<k1.r+k2.r-epsilon&&!DaLiSeDodirujuIznutra(k1,k2)&&!DaLiSeDodirujuIzvana(k1,k2))return true;
    if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))-epsilon<k1.r+k2.r+epsilon&&!DaLiSeDodirujuIznutra(k1,k2)&&!DaLiSeDodirujuIzvana(k1,k2))return true;
   return false;
}
bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))+epsilon<k1.r+k2.r-epsilon)return true;
    if(sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z))-epsilon<k1.r+k2.r+epsilon)return true;
    return false;
}
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

int main (){
    std::cout<<"Unesite broj Kugla: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v(n);
    for(int i=0;i<n;i++){
        std::cout << "Unesite centar "<<i+1<<". kugle: Unesite poluprecnik "<<i+1<<". kugle: ";
        double a1,a2,a3,a4;
        if(!(std::cin>>a1>>a2>>a3>>a4)){
            std::cout<<"Nepravilan unos. Unesite ponovo\n";
               std::cin.clear();
            std::cin.ignore(1000,'\n');
            i--;continue;
        }
     
        if(a4<0){
            std::cout<<"Ilegalan poluprecnik\n";
            i--;continue;
        }
        v[i]=std::make_shared<NepreklapajucaKugla>(a1,a2,a3,a4);
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dex,dey,dez;
    std::cin>>dex>>dey>>dez;
    std::vector<std::shared_ptr<NepreklapajucaKugla>> kys(n);
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::transform(v.begin(),v.end(),kys.begin(),[ dex, dey, dez](std::shared_ptr<NepreklapajucaKugla> k){k->Transliraj(dex,dey,dez);return k;});
    std::sort(kys.begin(),kys.end(),[](std::shared_ptr<NepreklapajucaKugla> k1,std::shared_ptr<NepreklapajucaKugla> k2){return k1->DajZapreminu()<k2->DajZapreminu();});
    std::for_each(kys.begin(),kys.end(),[](std::shared_ptr<NepreklapajucaKugla>k){k->Ispisi();});
    std::cout << "Kugla sa najvecom povrsinom je: ";
auto p=std::max_element(kys.begin(),kys.end(),[](std::shared_ptr<NepreklapajucaKugla>k1,std::shared_ptr<NepreklapajucaKugla>k2){return k1->DajPovrsinu()<k2->DajPovrsinu();});
	(*p)->Ispisi();
	int e=0;
	int br=0;
	std::for_each(kys.begin(),kys.end(),[kys,&e,&br](std::shared_ptr<NepreklapajucaKugla> k1){
	    std::for_each(kys.begin()+e,kys.end(),[k1,&br](std::shared_ptr<NepreklapajucaKugla> k2){
	        if(k2==k1);else{
	            if(DaLiSeSijeku(*k1,*k2)){std::cout << "Presjecaju se kugle: " ;k1->Ispisi();k2->Ispisi();br++;}
	            
	        }
	        
	    });
	    e++;
	});
	if(br==0)std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
	return 0;
}
