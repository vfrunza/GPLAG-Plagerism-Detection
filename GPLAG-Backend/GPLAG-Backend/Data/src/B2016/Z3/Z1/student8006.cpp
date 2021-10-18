/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#define eps 0.00000000001

double f1 (double x) {return x * x + std::sin(x);}
//NOTE: KOPIRANJA KOJA SU SE DESILA U ZADATKU, ZATO STO SAM SHVATIO DA CE BITI LAKSE NAPISATI PROGRAM I DA CE BITI PREGLEDNIJI UKOLIKO 
//NAPRAVIM POMOCNU FUNKCIJU KREIRAJVEKTORPAROVA
std::vector<double> KreirajVektorParova(int n, int d, std::vector<std::pair<double, double> > parovi) {
    std::vector<double> w;
    for(int i = 1; i <= n; ++i) {    //    std::cout << i << " iteracija prve petlje!" << std::endl;
        double suma(0); //  std::cout << "Proizvod na pocetku: " << proizvod << " Suma na pocetku: " << suma << std::endl;
  //      std::cout << std::endl;
        for(int k = std::max(1, i - d); k <= std::min(i, n - d); ++k) {
            double proizvod(1);
        //    std::cout << k << " iteracija k-te petlje!" << std::endl;
            for(int j = k; j <= k + d; ++j) {
                if(j == i)
                continue;
                
                proizvod *= 1 / (parovi.at(i - 1).first - parovi.at(j - 1).first);
            }    
                if((k - 1) % 2 != 0)
                proizvod *= -1;
                
            suma += proizvod;//std::cout << proizvod << " " << suma << std::endl;
        }
        w.push_back(suma);//std::cout << "Suma na kraju: " << suma << " Proizvod na kraju: " << proizvod << std::endl << std::endl;
    }
    return w;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> parovi, int d) {
    int n(parovi.size());//    std::cout << "Kreiran broj n!" << std::endl;
    if(d < 0 || d > n) throw std::domain_error("Nedozvoljen red");
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) 
            if(j != i && fabs(parovi.at(i).first - parovi.at(j).first) < eps) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> w;  //  std::cout << "Kreiran vektor w!" << std::endl;
    w = KreirajVektorParova(n, d, parovi);
  //  std::cout << std::endl;
    return [w, n, parovi] (double x) {
        double suma1(0);
        double suma2(0);
        for(int i = 0; i < n; ++i) {
            if(x - parovi.at(i).first) {
                suma1 += (w.at(i) / (x - parovi.at(i).first) * parovi.at(i).second); 
                suma2 += (w.at(i) / (x - parovi.at(i).first));
            }
            else
            return parovi.at(i).second;
        }//std::cout << "Suma1: " << suma1 << std::endl;//    std::cout << "Suma2: " << suma2 << std::endl;
        return (suma1 / suma2);
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double dx, int d) {
    if(xmin > xmax) throw std::domain_error("Nekorektni parametri");
    
    std::vector<std::pair<double, double>> parovi;    
    for(double i = xmin; i <= xmax; i += dx) {
        if(i > xmax) break;
        std::pair<double, double> temp;
        temp = std::make_pair(i, f(i));
        parovi.push_back(temp);
    }
    
    int n = parovi.size();
    std::vector<double> w;
    w = KreirajVektorParova(parovi.size(), d, parovi);
    
    return [parovi, n, w] (double x) {
        double suma1(0);
        double suma2(0);
        for(int i = 0; i < n; ++i) {
            if(x - parovi.at(i).first) {
                suma1 += (w.at(i) / (x - parovi.at(i).first) * parovi.at(i).second); 
                suma2 += (w.at(i) / (x - parovi.at(i).first));
            }
            else
            return parovi.at(i).second;
        }
        return suma1 / suma2;
    };
}


int main() {
    try {
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija(0);
    std::cin >> opcija;
    
    if(opcija == 1) {
        int broj_cvorova;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj_cvorova;
        if(broj_cvorova < 0) throw std::domain_error("Nekorektni parametri");
        
        std::cout << "Unesite cvorove kao parove x y: ";
        double x, y;
        int temp = broj_cvorova;
        std::vector<std::pair<double, double>> parovi;
        while(temp != 0) {
            std::pair<double, double> par;
            std::cin >> x >> y;
            par = std::make_pair(x, y);
            parovi.push_back(par);
            temp--;
        }
        
        int d;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
    //    if(d < 0) throw std::domain_error("Nedozvoljen red");
        
        while(1) {
            double argument;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): "; 
            std::cin >> argument;
            if(!std::cin)
            break;
            auto f = BaricentricnaInterpolacija(parovi, d);
            std::cout << "f(" << argument << ") = " << f(argument) << std::endl;
        }
    }
    
    if(opcija == 2) {
        double poc_intervala;
        double kraj_intervala;
        double korak;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> poc_intervala >> kraj_intervala >> korak;
        
        std::cout << "Unesite red interpolacije: ";
        int d;
        std::cin >> d;
        
        while(1) {
            double argument;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): "; 
            std::cin >> argument;
            if(!std::cin)
            break;
            auto f = BaricentricnaInterpolacija(f1, poc_intervala, kraj_intervala, korak, d);
            std::cout << "f(" << argument << ") = " << f1(argument) << " fapprox(" << argument << ") = " << f(argument) << std::endl;
        }
    }
    }
    catch(std::domain_error trash) {
        std::cout << trash.what() << std::endl;
    }
    return 0;
}
