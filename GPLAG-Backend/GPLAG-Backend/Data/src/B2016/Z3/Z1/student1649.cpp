/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>
int min(int x,int y){
    if (x<y) return x;
    return y;
}
int max(int x,int y){
    if(x>y) return x;
    return y;
}
bool JesuLiJednaki(double x,double y, double Eps=1e-10){
    return std::fabs(x-y) <=Eps*(std::fabs(x)+std::fabs(y));
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> CvoroviInterpolacije,int d){
    int n(CvoroviInterpolacije.size());
    if(d<0 || d>=n) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(JesuLiJednaki(CvoroviInterpolacije[i].first,CvoroviInterpolacije[j].first)) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> TezinskiKoeficijenti(n);
    for(int i=1;i<=n;i++){
        int k(max(1,i-d)),l(min(i,n-d));
        for(;k<=l;k++){
            double Proizvod(1);
            for(int j=k;j<=k+d;j++){
                if(j!=i) Proizvod*=(1/(CvoroviInterpolacije[i-1].first-CvoroviInterpolacije[j-1].first));
            }
            TezinskiKoeficijenti[i-1]+=(std::pow(-1,k-2)*Proizvod);
        }
    }
    return [CvoroviInterpolacije,TezinskiKoeficijenti](double x){
        double Brojnik(0),Nazivnik(0);
        for(int i=0;i<CvoroviInterpolacije.size();i++){
            if(JesuLiJednaki(x,CvoroviInterpolacije[i].first)) return CvoroviInterpolacije[i].second;
            Brojnik+=(TezinskiKoeficijenti[i]/(x-CvoroviInterpolacije[i].first))*CvoroviInterpolacije[i].second;
            Nazivnik+=(TezinskiKoeficijenti[i]/(x-CvoroviInterpolacije[i].first));
        }
        return (Brojnik/Nazivnik);
    };
}
template<typename Funkcija>
std::function<double(double)> BaricentricnaInterpolacija(Funkcija f,double xmin,double xmax,double dx,int d){
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> CvoroviInterpolacije;
    for(int i=0;xmin+(i*dx)<=xmax;i++) CvoroviInterpolacije.push_back(std::make_pair(xmin+i*dx,f(xmin+i*dx)));
    return (BaricentricnaInterpolacija(CvoroviInterpolacije,d));
}
double xxplussinx(double x){return x*x+std::sin(x);}
int main (){
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int Opcija(0);
    std::cin>>Opcija;
    if(Opcija==1){
        std::cout<<"Unesite broj cvorova: ";
        int BrojCvorova;
        std::cin>>BrojCvorova;
        std::vector<std::pair<double,double>> Cvorovi;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<BrojCvorova;i++){
            double x,y;
            std::cin>>x>>y;
            Cvorovi.push_back(std::make_pair(x,y));
        }
        std::cout<<"Unesite red interpolacije: ";
        int RedInterpolacije;
        std::cin>>RedInterpolacije;
        try{
            for(;;){
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double Argument;
                std::cin>>Argument;
                if(!std::cin) break;
                double fun(BaricentricnaInterpolacija(Cvorovi,RedInterpolacije)(Argument));
                std::cout<<"f("<<Argument<<") = "<<fun<<"\n";
            }
        }catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
        }
    }
    if(Opcija==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double Pocetak,Kraj,Korak;
        std::cin>>Pocetak>>Kraj>>Korak;
        std::cout<<"Unesite red interpolacije: ";
        int RedInterpolacije;
        std::cin>>RedInterpolacije;
        try{
            auto Aproksimacija(BaricentricnaInterpolacija(xxplussinx,Pocetak,Kraj,Korak,RedInterpolacije));
            for(;;){
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double Argument;
                std::cin>>Argument;
                if(!std::cin) break;
                std::cout<<"f("<<Argument<<") = "<<xxplussinx(Argument)<<" fapprox("<<Argument<<") = "<<Aproksimacija(Argument)<<"\n";
            }
        }catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
        }
    }
	return 0;
}