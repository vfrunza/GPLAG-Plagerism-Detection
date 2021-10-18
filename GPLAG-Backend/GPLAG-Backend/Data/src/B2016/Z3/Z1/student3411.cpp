/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <math.h>

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> matrica, int d){
    int n(matrica.size());
    if(d<0 || d>n) throw std::domain_error("Nedozvoljen red"); //provjera da li se šalje nedozvoljen parametar
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(matrica[i].first==matrica[j].first) throw std::domain_error("Neispravni cvorovi"); //provjera ispravnosti poslanih cvorova
        }
    }
    std::vector<double> w(n);
    //računanje težinskih koeficijenata: wi
    for(int i=0; i<n; i++){
        double s(0);
        int br,vel;
        if((i-d)<0) br=0; //odredjivanje donje vrijednosti za brojac nadolazece sume(tj wi)
        else br=i-d;
        if(i+1<(n-d)) vel=i;//odredjivanje gornje granice za brojac nadolazeće sume(tj wi)
        else vel=n-d-1;
        for(int k=br; k<=vel; k++){ 
            double p(1);
            for(int j=k; j<=k+d; j++){
                if(j==i) continue;
                p*=(1./(matrica[i].first-matrica[j].first));
            }
            if((k-1)%2!=0) p*=-1;
            s+=p;
        }
        w[i]=s;
    }
    return [w,matrica,n] (double x) {double s1(0),s2(0); for(int i=0; i<n; i++) { if(x==matrica[i].first) return matrica[i].second;
    double pom=w[i]/(x-matrica[i].first); s2+=pom; s1+=pom*matrica[i].second;} return s1/s2;}; //vracanje odg funckije kao rezultata ove funkcije
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,double min,double max, double delta,int d){
    if(min>max || delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    for(double i=min; i<=max; i+=delta){ //for petlja u kojoj se vrši formiranje čvorova na način definisan postavkom
        double y=f(i);
        cvorovi.push_back(std::make_pair(i,y));
    }
    try{
    return BaricentricnaInterpolacija(cvorovi,d); //izvrsava se u try bloku budući da može doći do bacanja izuzetka
    }
    catch(...){
        throw;
    }
}
double Pomocna(double x){
    return (x*x+sin(x));
}
int main ()
{   
    int x;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>x;
    if(x==1){
        try{
        int n;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> matrica(n);
        for(int i=0; i<n; i++){
            double a,b;
            std::cin>>a>>b;
            matrica[i]=std::make_pair(a,b);
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        for(;;){
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double arg;
        std::cin>>arg;
        if(!std::cin) break;
        try{
            auto fun(BaricentricnaInterpolacija(matrica,d));
            std::cout<<"f("<< arg <<") = "<<fun(arg)<<std::endl;
        }
        catch(std::domain_error e){
            throw;
        }
        }
    }
        catch(std::domain_error e){
            std::cout<<e.what();
        }
    }
    if(x==2){
        try{
        double min,max,delta;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>min>>max>>delta;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        for(;;){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin>>arg;
            if(!std::cin) break;
            std::function<double(double)> fun;
            try{
                 fun=(BaricentricnaInterpolacija([](double x){return (x*x+sin(x));}, min,max,delta,d));
            }
            catch(std::domain_error e){
                throw;
            }
            std::cout<<"f("<< arg <<") = "<<Pomocna(arg)<<" ";
            std::cout<<"fapprox("<< arg <<") = "<<fun(arg)<<std::endl;
        }
    }
        catch(std::domain_error e){
            std::cout<<e.what();
        }
    }
	return 0;
}