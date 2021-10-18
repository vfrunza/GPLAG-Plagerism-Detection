/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#define E 0.00000000000000000000000000000000000000000000000000000001
#define Ep -0.0000000000000000000000000000000000000000000000000000001

double Interpolacija (std::vector<std::pair<double,double>>cvor,int red,double x)
{


    double suma2(0),suma1(0),proizvod (1),stepen(1),wi(0);
    std::vector<std::pair<double,double>>cvorovi(cvor);
    int red_interpolacije(red),n(cvorovi.size());


    for (int i=1; i<=n; i++) {
        wi = 0;
        double xi(cvorovi[i-1].first),yi(cvorovi[i-1].second); // pitanje
        if (x == xi) return yi;

        for (int k=std::max(1,i-red_interpolacije); k<=std::min(i,n-red_interpolacije); k++) { // pitanje
            stepen = std::pow (-1,k-1);
            proizvod=1;

            for (int j=k; j<=k+red_interpolacije; j++) {
                if (i==j) continue;

                double xj(cvorovi[j-1].first);
                proizvod*=(1/(xi-xj));
            }
            wi+=(stepen*proizvod);
        }
        suma1+=(wi*yi)/(x-xi);
        suma2+=wi/(x-xi);
    }
    return suma1/suma2;
}

std::function<double(double)> BaricentricnaInterpolacija ( std::vector<std::pair<double,double>> cvor,int red)
{
    std::vector<std::pair<double,double>> cvorovi(cvor);
    int red_interpolacije(red);

    if (red_interpolacije<0 || red_interpolacije>cvorovi.size()) throw std::domain_error ("Nedozvoljen red");

    for (int i=0; i<cvorovi.size(); i++) {
        for (int j=i+1; j<cvorovi.size(); j++) {
            if (cvorovi[i].first>0 && cvorovi[j].first>0){
            if (fabs(cvorovi[i].first-cvorovi[j].first)<E && cvorovi[i].first-cvorovi[j].first>Ep)
                throw std::domain_error ("Neispravni cvorovi");
        }
        else {
            if (cvorovi[i].first-cvorovi[j].first<E && cvorovi[i].first-cvorovi[j].first>Ep)
            throw std::domain_error ("Neispravni cvorovi");
        }}
    }
    return ([=](double x) {
        return Interpolacija(cvorovi,red_interpolacije,x);
    });
}

double fun (double x)
{
    return x*x+std::sin(x);
}

std::function<double(double)> BaricentricnaInterpolacija (double f(double),double  xmin, double xmax,double dx,int red_interpolacije)
{
    if (xmin>xmax || dx<=0) throw std::domain_error ("Nekorektni parametri");

    double y;
    std::vector<std::pair<double,double>> cvorovi ;

    for (double i=xmin; i<=xmax; i+=dx) {
        
        y=f(i);  
        cvorovi.push_back(std::make_pair (i,y));
       
    }
    return ([=](double x) {
        return (Interpolacija(cvorovi,red_interpolacije,x));
    });
}

int main ()
{

    int opcija,broj_cvorova,red_interpolacije;
    double argument;

    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;

    std::vector<std::pair<double,double>> cvorovi ;
    std::pair <double,double> cvor;
    double f;

    if (opcija==1) {
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj_cvorova;

        std::cout << "Unesite cvorove kao parove x y: ";

        for (int i=0; i<broj_cvorova; i++) {
            double prva_koordinata;
            double druga_koordinata;

            std::cin >> prva_koordinata >> druga_koordinata;

            cvor.first = prva_koordinata;
            cvor.second =druga_koordinata;

            cvorovi.push_back(cvor);
        }

        std::cout << "Unesite red interpolacije: ";
        std::cin >> red_interpolacije;

        do {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> argument;

            if (!std::cin ) break;

            f=BaricentricnaInterpolacija(cvorovi,red_interpolacije)(argument);
            std::cout << "f("<< argument << ") = " << f << std::endl;

        }   while (std::cin);
    }

    double pocetak,kraj,korak,g;

    if (opcija==2) {

        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> pocetak >> kraj >> korak;

        std::cout << "Unesite red interpolacije: ";
        std::cin >> red_interpolacije;


        do {
            std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> argument;

            if (!std::cin) break;

            g=BaricentricnaInterpolacija(fun,pocetak,kraj,korak,red_interpolacije) (argument);
            std::cout <<  "f(" << argument << ") = " << fun(argument);
            std::cout << " fapprox(" << argument << ") = " << g << std::endl;  // koja je ovo funkcija fapprox ?!?!?!?
        } while (std::cin);
    }
    return 0;
}