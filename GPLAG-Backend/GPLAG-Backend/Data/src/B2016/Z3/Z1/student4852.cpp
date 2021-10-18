#include <iostream>
#include<cmath>
#include<vector>
#include<utility>
#include<stdexcept>
#include<functional>
#include<vector>
double f(double x){
    return pow(x,2)+std::sin(x);
}
// d-red interpolacije
// w-tezinski koeficijenti
// n-broj cvorova interpolacije
// i-indeks cvorova interpolacije i tezinskih koeficijenata
double IzracunajTezinskiKoeficijent(std::vector<std::pair<double,double>> CvoroviInterpolacije,int d,int i){
    int n=CvoroviInterpolacije.size();
// k=max{1,i-d}
int k;
if(i-d>1)
k=i-d;
else
k=1;

// m=min{i,n-d}
int m;
if(n-d<i)
m=n-d;
else
m=i;
double produkt=1;
double w=0;
for(int k1=k;k1<=m;k1++){
    produkt=1;
    for(int j=k1;j<=k1+d;j++){
    if(j==i){continue;}
    produkt=produkt*(1/(CvoroviInterpolacije[i-1].first-CvoroviInterpolacije[j-1].first));
}
    w=w+pow(-1,k1-1)*produkt;
}
return w;
}

std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair<double,double>>& CvoroviInterpolacije,int d){
    int n=CvoroviInterpolacije.size();
 if(d<0||d>n)throw std::domain_error("Nedozvoljen red");
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(j==i)continue;
           if(CvoroviInterpolacije[i].first==CvoroviInterpolacije[j].first)
           throw std::domain_error("Neispravni cvorovi");
       }
    }
return [CvoroviInterpolacije,d,n](double x)->double{
    for(int i=0;i<n;i++){
        if(x==CvoroviInterpolacije[i].first)
        return CvoroviInterpolacije[i].second;
    }
    double suma1=0;
    double suma2=0;
    for(int i=1;i<=n;i++){
        suma1=suma1+((IzracunajTezinskiKoeficijent(CvoroviInterpolacije,d,i)*CvoroviInterpolacije[i-1].second)/(x-CvoroviInterpolacije[i-1].first));
    }
     for(int i=1;i<=n;i++){
        suma2=suma2+(IzracunajTezinskiKoeficijent(CvoroviInterpolacije,d,i)/(x-CvoroviInterpolacije[i-1].first));
    }
    return suma1/suma2;
};
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)>f,double x_min,double x_max,double delta_x,int d){
    if(x_min>x_max||delta_x<0)
    throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>>v;
    int i(0);
    auto x_min1(x_min);
    while(x_min1<=x_max){
        v.push_back(std::make_pair(x_min1,f(x_min1)));
        i++;
        x_min1=x_min+i*delta_x;
    }
    return BaricentricnaInterpolacija(v,d);
}

int main ()
{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1){
        std::vector<std::pair<double,double>> cvorovi;
    std::pair<double,double>cvor;
    int red_interpolacije;
    double a,b;
    int broj_cvorova;
    std::cout<<"Unesite broj cvorova: ";
    std::cin>>broj_cvorova;
    std::cout<<"Unesite cvorove kao parove x y: ";
    for(int i=0;i<broj_cvorova;i++){
        std::cin>>a>>b;
        cvor=std::make_pair(a,b);
        cvorovi.push_back(cvor);
    }
    std::cout<<"Unesite red interpolacije: ";
    std::cin>>red_interpolacije;
    auto f(BaricentricnaInterpolacija(cvorovi,red_interpolacije));
    double arg;
     for(;;){
         std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
    std::cin>>arg;
    if(!std::cin)return 0;
    std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
     }
    }
    
   if(opcija==2){
    int red_interpolacije;
    double a,b,korak;
    std::cout<<"Unesite krajeve intervala i korak: ";
    std::cin>>a>>b>>korak;
    std::cout<<"Unesite red interpolacije: ";
    std::cin>>red_interpolacije;
    auto f1(BaricentricnaInterpolacija(f,a,b,korak,red_interpolacije));
    double arg;
     for(;;){
         std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
    std::cin>>arg;
    if(!std::cin)return 0;
    std::cout<<"f("<<arg<<") = "<<f(arg)<<" fapprox("<<arg<<") = "<<f1(arg)<<std::endl;
     }
    }
	return 0;
}