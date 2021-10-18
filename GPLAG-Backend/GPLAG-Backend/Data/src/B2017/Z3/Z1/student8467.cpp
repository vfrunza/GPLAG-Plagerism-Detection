/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <functional>
#include <algorithm>
#include <cmath>


typedef std::pair<double,double> par;
//Prva verzija prima vektor parova, vraća drugu funkciju koja prima jednu realnu promjenjivu i vraća jednu realnu promjenjivu
auto kriteriji = [](par p1, par p2){return p1.first < p2.first;};

std::vector<par> vektor{};

//---------------------------PRVA VERZIJA---------------------------------------
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> v){
    //Sortiranje vektora parova po koordinati x
    
    std::sort(v.begin(), v.end(), kriteriji);
    //Provjeravanje da li postoje iste x koordinate
    for(int i = 0; i < v.size() - 1; i++){
        if(fabs(v.at(i).first - v.at(i + 1).first) < 0.000001) throw std::domain_error("Neispravni cvorovi");
    }
    
    //Vracanje CAROBNE funkcije
    return [v](double x){
        //Provjera da li je x < x1 ili x > xn
        if(x < v.at(0).first || x > v.at(v.size()-1).first) throw std::range_error("Argument izvan opsega");
       
        //Trazenje okolnih parova
        auto pok( std::lower_bound(v.begin(), v.end(), par(x,0),kriteriji) );
        //Slucaj da se poklapa sa koordinanatama
        if(fabs(x - pok->first) < 0.00000001) return pok->second;
        
        std::pair<double,double> prvi_cvor(*(pok - 1)); 
        std::pair<double,double> drugi_cvor(*(pok));
        
        return (prvi_cvor.second + ((drugi_cvor.second - prvi_cvor.second)/(drugi_cvor.first - prvi_cvor.first))*(x - prvi_cvor.first) );
    };
}

std::function<double(double)> LinearnaInterpolacija(double f(double), double pocetak, double kraj, double korak){
    if(pocetak > kraj || korak <= 0) throw std::domain_error("Nekorektni parametri");
    
    if(vektor.size() == 0){
        double pomjeraj = pocetak;
        while(pomjeraj < kraj){
            vektor.push_back(par(pomjeraj, f(pomjeraj)));
            pomjeraj += korak;
        }
        vektor.push_back(par(kraj, f(kraj)));
        //std::cout << "ibvo" << std::endl;
    }
    
    return [](double x){
        //Provjera da li je x < x1 ili x > xn
        if(x < vektor.at(0).first || x > vektor.at(vektor.size()-1).first) throw std::range_error("Argument izvan opsega");
        //Trazenje okolnih parova
        auto pok( std::lower_bound(vektor.begin(), vektor.end(), par(x,0), kriteriji) );
        if(fabs(x - pok->first) < 0.00000001) return pok->second;
        std::pair<double,double> prvi_cvor(*(pok - 1)); 
        std::pair<double,double> drugi_cvor(*(pok));
        
        return (prvi_cvor.second + ((drugi_cvor.second - prvi_cvor.second)/(drugi_cvor.first - prvi_cvor.first))*(x - prvi_cvor.first) );
    };
    
}



int main (){
    int unos;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> unos;
    
    if(unos == 1){
        int broj_cvorova;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj_cvorova;
        if(broj_cvorova == 0) return 0;
        std::cout << "Unesite cvorove kao parove x y: ";
        std::vector<par> v;
        for(int i = 0; i < broj_cvorova; i++){
            double prvi, drugi;
            std::cin >> prvi >> drugi;
            v.push_back(par(prvi, drugi));
        }
        
        try {
            auto f(LinearnaInterpolacija(v));
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
            return 0;
        }
        double x;
        do{
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> x;
            if(!std::cin) return 0;
            try {
                auto f(LinearnaInterpolacija(v));
                std::cout << "f(" << x << ") = " << f(x) << std::endl;
            }
            catch (std::exception &e){
                std::cout << e.what() << std::endl;
            }
        }while(true);
    //--------------------------------------------------------------------------
    }else if(unos == 2){
        double pocetak, kraj, korak;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> pocetak >> kraj >> korak;
        double x;
        try {
            auto f(LinearnaInterpolacija([](double x){ return (x*x + sin(x)); }, pocetak, kraj, korak));
        }catch (std::exception &e){
            std::cout << e.what() << std::endl;
            return 0;
        }
        do{
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> x;
            if(!std::cin) return 0;
            try {
                auto f(LinearnaInterpolacija([](double x){ return (x*x + sin(x)); }, pocetak, kraj, korak));
                std::cout << "f(" << x << ") = " << (x*x + sin(x)) << " fapprox(" << x << ") = "<< f(x) << std::endl;
            }
            catch (std::exception &e){
                std::cout << e.what() << std::endl;
            }
        }while(true);
    //--------------------------------------------------------------------------
    }else{
        std::cout << std::endl;
        std::cout << "Greska u unosu!" << std::endl;
    }
	return 0;
}