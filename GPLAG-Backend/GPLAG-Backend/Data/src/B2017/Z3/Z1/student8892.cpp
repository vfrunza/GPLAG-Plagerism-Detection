#include <iostream>
#include <functional>
#include <stdexcept>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>

std::function<double (double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> vektor_parova){
    auto pocetak = std::begin(vektor_parova);
    auto kraj = std::end(vektor_parova);
    std::sort (pocetak, kraj, [](std::pair<double, double> prvi, std::pair<double, double> drugi) {return drugi.first > prvi.first;});
    bool postoji_identican = false;
   try{
        for(auto i = pocetak; i != kraj; i++){
            for(auto j = i + 1; j != kraj; j++){
                if(j-> first == i -> first){
                    postoji_identican = true;
                    break;
                }
            }
        }
        if(postoji_identican)throw std::domain_error ("Neispravni cvorovi");
   } 
   catch(...){
       throw;
   }
    
    return [vektor_parova]  (double x)-> double{
        auto prvi = std::begin(vektor_parova);
        auto zadnji = std::end(vektor_parova);
        zadnji --;
        if (x < (prvi -> first) || x > (zadnji->first))throw std::range_error("Argument izvan opsega");
        //zadnji--;
        auto gornja_granica = std::lower_bound(prvi, zadnji, std::make_pair(x, 0) , [](std::pair<double, double> prvi, std::pair<double, double> drugi) {return drugi.first > prvi.first;});
        auto donja_granica = std::upper_bound(prvi, zadnji, std::make_pair(x, 0) , [](std::pair<double, double> prvi, std::pair<double, double> drugi) {return drugi.first > prvi.first;});
        donja_granica--;
        
        double rezultat ;
        if(x == gornja_granica -> first) return rezultat = (gornja_granica -> second);
        rezultat = (donja_granica -> second) + ((gornja_granica -> second) - (donja_granica->second))/((gornja_granica -> first) - (donja_granica-> first)) * (x - (donja_granica -> first));
       
        return rezultat;
    };
}

std::function<double (double)> LinearnaInterpolacija(double f(double), double min_x, double max_x, double korak){
    if(min_x > max_x || korak <= 0)throw std::domain_error("Nekorektni parametri");
    int broj = (int) max_x / korak;
    std::vector<std::pair<double, double>> vektor_parova;
    for(int i = 0; i < broj; i++){
        double x, y;
        x = min_x + i * korak;
        y = f(x);
        std::pair<double, double> par = std::make_pair(x,y);
        vektor_parova.push_back(par);
    }
    return [vektor_parova, min_x, max_x](double x){
        auto prvi = std::begin(vektor_parova);
        auto zadnji = std::end(vektor_parova);
        zadnji--;
        if (x < (min_x) || x > (max_x))throw std::range_error("Argument izvan opsega");
        //zadnji++;
        auto gornja_granica = std::lower_bound ( prvi,  zadnji , std::make_pair(x, 0), [](std::pair<double, double> prvi, std::pair<double, double> drugi) {return drugi.first > prvi.first;});
        auto donja_granica = std::upper_bound ( prvi ,  zadnji , std::make_pair(x, 0), [](std::pair<double, double> prvi, std::pair<double, double> drugi) {return drugi.first > prvi.first;});
        donja_granica --;
        
        double rezultat ;
        if(x == gornja_granica -> first) return rezultat = (gornja_granica -> second);
        rezultat = (donja_granica -> second) + ((gornja_granica -> second) - (donja_granica->second))/((gornja_granica -> first) - (donja_granica-> first)) * (x - (donja_granica -> first));
        
        
        return rezultat;
    };
    
}





int main(){
    try{
        std::cout <<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int naredba;
        std::cin >> naredba;
        if(naredba == 1){
    
                std::cout << "Unesite broj cvorova: ";
                int broj_cvorova;
                std::cin >> broj_cvorova;
                std::cout <<"Unesite cvorove kao parove x y: ";
                std::vector<std::pair<double, double>> vektor_parova;
                for(int i = 0; i < broj_cvorova; i++){
                    double x, y;
                    std::cin >> x >> y;
                    std::pair<double, double> par;
                    par = std::make_pair(x,y);
                    vektor_parova.push_back(par);
                }
                 try{
                 auto f(LinearnaInterpolacija(vektor_parova));
                }
                catch(std::domain_error ){
                    throw;
                }
                std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin >> argument;
               
                auto f(LinearnaInterpolacija(vektor_parova));
                while(std::cin ){
                   try{
                    std::cout<< "f("<< argument <<") = "<< f(argument) << std::endl;
                   }
                    catch(std::domain_error izuzetak){
                       std::cout << izuzetak.what() << std::endl;
                   }
                   catch(std::range_error izuzetak){
                       std::cout <<izuzetak.what() << std::endl;
                   }
                    std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin >> argument;
                   
                }
                
            }
         
        else if(naredba == 2){
            
                std::cout << "Unesite krajeve intervala i korak: ";
                double pocetak, kraj, korak;
                std::cin >> pocetak >> kraj >> korak;
                try{
                    auto fapprox(LinearnaInterpolacija([](double x){return x*x +std::sin(x);}, pocetak, kraj, korak));
                }
                catch(...){
                    throw;
                }
                std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin >> argument;
                while(std::cin ){
                    try{
                    auto fapprox(LinearnaInterpolacija([](double x){return x*x +std::sin(x);}, pocetak, kraj, korak));
                    std::cout<< "f("<< argument <<") = "<< argument * argument + std::sin(argument)<< " fapprox("<< argument<< ") = " << fapprox(argument) << std::endl;
                    }
                    catch(std::domain_error izuzetak){
                       std::cout << izuzetak.what() << std::endl;
                   }
                   catch(std::range_error izuzetak){
                       std::cout <<izuzetak.what() << std::endl;
                   }
                    std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin >> argument;
                }
            }
        }
        catch(std::domain_error izuzetak){
            std::cout << izuzetak.what() << std::endl;
        }
        catch(std::range_error izuzetak){
            std::cout << izuzetak.what() << std::endl;
        }

    
    
    return 0;
}