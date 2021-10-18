/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::pair<double,double>> VektorParova;

struct F {
    double x,x_i,x_ii,y_i,y_ii;
}; // struktura koja sadrzi varijable interpolacije

void Sortiraj (VektorParova &cvorovi)
{
    for (int i = 0; i<cvorovi.size(); i++){
        for (int j = i; j<cvorovi.size()-1; j++){
            if (fabs(cvorovi.at(i).first-cvorovi.at(j+1).first)<0.000001) throw std::domain_error ("Neispravni cvorovi");
        }
    }
    std::sort(cvorovi.begin(),cvorovi.end(),[](std::pair<double,double> x,std::pair<double,double> y) {
        if (x.first>y.first) return false;
        return true;
    });
} // Sortira vektor i baca izuzetak ukoliko postoje dva ista elementa

double Formula (F var)  // Formula interpolacije
{
    return (var.y_i + ((var.y_ii-var.y_i)/(var.x_ii-var.x_i))*(var.x-var.x_i));
}

double Nadji (VektorParova cvorovi, double x){
    std::pair<double,double> par{x,0};
    VektorParova::iterator it(std::lower_bound(cvorovi.begin(),cvorovi.end(),par));  // trazi prvu x-koordinatu koja je veca od trazene tacke
    it--;
    if (fabs((*it).first-cvorovi.at(cvorovi.size()-1).first)<0.000001) { return (*it).second;}   // ako nije nadjena trazena tacka onda treba da vrati samo y-koordinatu

    auto trenutni(it);   // trentuni je i it++ su dva cvora izmedju kojih je x
    it++;  // postaje sljedeci element
    return Formula({x,(*trenutni).first,(*it).first,(*trenutni).second,(*it).second});
}

std::function<double(double)> LinearnaInterpolacija (VektorParova cvorovi){
    Sortiraj(cvorovi);
    return [cvorovi](double x){
        if (x<cvorovi.at(0).first || x>cvorovi.at(cvorovi.size()-1).first) throw std::range_error ("Argument izvan opsega");
        return Nadji(cvorovi,x);
    };
}

VektorParova LinearnaInterpolacija (double funkcija(double), double x_min, double x_max, double delta_x){
    if (x_max<x_min || delta_x<=0) throw std::domain_error ("Nekorektni parametri");
    VektorParova cvorovi;
    double korak(0);
    int i(1);
    while (1){
        cvorovi.resize(i);
        cvorovi.at(i-1)={x_min+korak,funkcija(x_min+korak)};
        korak+=delta_x;
        if (korak>=x_max) break;
        i++;
    }
    return cvorovi;
}

void UnosCvorova (){
    std::cout<<"Unesite broj cvorova: ";
    int n;
    std::cin>>n;
    VektorParova cvorovi(n);
    std::cout<<"Unesite cvorove kao parove x y: ";
    for (int i = 0; i<n; i++){
        double x,y;
        std::cin>>x>>y;
        cvorovi.at(i)={x,y};
    }
    Sortiraj(cvorovi);
    while (1){
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double x;
        std::cin>>x;
        if (!std::cin) break;
        std::cout<<"f("<<x<<") = "<<LinearnaInterpolacija(cvorovi)(x)<<std::endl;
    }
}

void Aproksimacija (){
    std::cout<<"Unesite krajeve intervala i korak: ";
    double x_min,x_max,korak;
    std::cin>>x_min>>x_max>>korak;
    // uslov
    while (1){
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        double x;
        std::cin>>x;
        if (!std::cin) break;
        try {
        std::cout<<"f("<<x<<") = "<<std::sin(x)+x*x<<" fapprox("<<x<<") = "<<LinearnaInterpolacija(LinearnaInterpolacija([](double x){
            return (std::sin(x)+x*x);},x_min,x_max,korak))(x)<<std::endl;
        }
        catch (std::range_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
        }
    }
}

int main ()
{
    try{
   auto li2(LinearnaInterpolacija({}));

std::cout << li2(1.5) << std::endl;
}catch (std::range_error e)
{
    std::cout << "'" << e.what() << "'";
}
catch (...)
{
    std::cout << "Pogresan tip izuzetka";
}
    return 0;
}
