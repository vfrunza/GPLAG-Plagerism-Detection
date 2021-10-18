/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <stdexcept>
#include <utility>
double funkcija (double x){
    return x*x+std::sin(x);
}
double tezinskikoeficijenti (int i, int n, int d, std::vector<std::pair<double, double>> vektor){
    int min, max;
    double suma(0);
    if (i <n-d) min = i; else min = n-d;
    if (1>i-d) max = 1; else max = i-d;
    for (int k = max; k<=min; k++) {
        int znak(pow (-1, k-1));
        double proizvod (1);
        for (int j=k; j<=k+d; j++){
            if (j == i) continue;
            proizvod = proizvod*(1/(vektor[i-1].first - vektor[j-1].first));
        }
        proizvod = proizvod*znak;
        suma+=proizvod;
    }
    return suma;
}
std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>> vektor, int d){
    if (!(d>=0 && d<vektor.size())) throw std::domain_error("Nedozvoljen red");
    for (int k=0; k<vektor.size(); k++){
        for (int l=k+1; l<vektor.size(); l++)
        {
            if (vektor[k].first==vektor[l].first) throw std::domain_error ("Neispravni cvorovi");   //
        }
    }
    int n (vektor.size());
    return [d, n, vektor] (double x){
    double suma1(0),suma2(0);
    for (int i =1; i<=n; i++){
        if(x==vektor[i-1].first) return vektor[i-1].second;
        suma1= suma1 + tezinskikoeficijenti (i, n, d, vektor)*vektor[i-1].second/(x -vektor[i-1].first);
        suma2= suma2 + tezinskikoeficijenti (i, n, d, vektor)/(x -vektor[i-1].first);
    }
    return suma1/suma2;
    };
}
std::function<double(double)> BaricentricnaInterpolacija (double funkcija(double), double x_min, double x_max, double d_x, int d ){
    if (x_min>x_max || d_x<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double, double>> vektor;
    int i(0);
    while (!(  x_min + i*d_x - x_max> 0.0001)){
        vektor.resize(vektor.size()+1);
        vektor[i].first = x_min + i*d_x;
        //std::cout<<i<<"*"<<vektor[i].first<<std::endl ;
        vektor[i].second = funkcija(vektor[i].first ); //po definicji, x , f(x) je cvor interpolacije;
        i++;

    }
    //std::cout<<vektor.size();

    return BaricentricnaInterpolacija(vektor, d);
}

int main ()
{
try{
   std::vector<std::pair<double, double>> vektor;
   int a; 
   std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
   std::cin>>a;
   if (a == 1){
       std::cout<<"Unesite broj cvorova: ";
       int cvorovi;
       std::cin>>cvorovi;
       std::cout<<"Unesite cvorove kao parove x y: ";
       for (int i =0; i<cvorovi; i++){
           vektor.resize( vektor.size() +1);
           std::cin>> vektor[i].first>>vektor[i].second;
       }
       std::cout<<"Unesite red interpolacije: ";
       int d;
       std::cin>>d;
       for (; ;){
       std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
       double zahl;
       std::cin>>zahl;
       if (!(std::cin)) return 0; // iz prvog predavnja.....
       std::cout<<"f("<<zahl<<") = "<<BaricentricnaInterpolacija(vektor, d)(zahl)<<std::endl;
       }
   }
   if (a == 2){
       std::cout<<"Unesite krajeve intervala i korak: ";
       double x_min,x_max,step;
       std::cin>>x_min>>x_max>>step;
       std::cout<<"Unesite red interpolacije: ";
       int d;
       std::cin>>d;
       for (; ;){
       std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
       double zahl;
       std::cin>>zahl;
       if (!(std::cin)) return 0; // iz prvog predavnja.....
       std::cout<<"f("<<zahl<<") = "<<funkcija(zahl)<<" fapprox("<<zahl<<") = "<<BaricentricnaInterpolacija(funkcija, x_min, x_max, step, d)(zahl)<<std::endl;
       }
   }
}
catch(std::domain_error e){
    std::cout<<e.what();
}
	return 0;
}

