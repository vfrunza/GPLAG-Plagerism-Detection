/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <algorithm>

double fun(double x){
    return x*x + std::sin(x);
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi){
    constexpr double EPS=0.000000001;
    int velicina=cvorovi.size();
    int koliko(0);
    
    for(int i=0; i<velicina; i++){
        koliko=0;
        for(int j=0; j<velicina; j++){
            if(std::fabs(cvorovi.at(i).first - cvorovi.at(j).first)<=EPS*(std::fabs(cvorovi.at(i).first)+std::fabs(cvorovi.at(j).first))) koliko++;
        }
        if(koliko>1) throw std::domain_error("Neispravni cvorovi");
    }
    
    std::sort(cvorovi.begin(), cvorovi.end(), [](std::pair<double, double> prvi, std::pair<double, double> drugi){return prvi.first<drugi.first;});
    
    
    
    return [cvorovi](double x){
        if(!(std::fabs(cvorovi.at(0).first - x)<=EPS*(std::fabs(cvorovi.at(0).first)+std::fabs(x))) && (x<cvorovi.at(0).first || x>cvorovi.at(cvorovi.size()-1).first)) throw std::range_error("Argument izvan opsega");
        if(!(std::fabs(cvorovi.at(cvorovi.size()-1).first - x)<=EPS*(std::fabs(cvorovi.at(cvorovi.size()-1).first)+std::fabs(x))) && x>cvorovi.at(cvorovi.size()-1).first) throw std::range_error("Argument izvan opsega");
        
        double povratna(0);
        double pocetakX(0), pocetakY(0);
        double krajX(0), krajY(0);
        
        if(std::fabs(cvorovi.at(cvorovi.size()-1).first - x)<=EPS*(std::fabs(cvorovi.at(cvorovi.size()-1).first) + std::fabs(x))) return cvorovi.at(cvorovi.size()-1).second;
        auto it=cvorovi.begin();
        std::pair<double, double> par=std::make_pair(x,0);
        auto p=cvorovi.begin();
    
            
            it=std::upper_bound(p, cvorovi.end(), par, [](std::pair<double, double> prvi, std::pair<double, double> drugi){return prvi.first<drugi.first;});
            pocetakX=(it-1)->first;
            krajX=it->first;
            
            pocetakY=(it-1)->second;
            krajY=it->second;
            
            
        povratna=pocetakY + ((krajY-pocetakY)/(krajX-pocetakX))*(x-pocetakX);
        return povratna;
    };
}

std::function<double(double)> LinearnaInterpolacija(double funkcija(double), double xmin, double xmax, double deltax){
    constexpr double EPS=0.000000001;
    if(xmin>xmax) throw std::domain_error("Nekorektni parametri");
    if(deltax<=0) throw std::domain_error("Nekorektni parametri");
   
    std::vector<std::pair<double, double>> ubaciti;
    double unos(xmin);
    
  
    while(true){
        std::pair<double, double> pomocni;
        pomocni=std::make_pair(unos, 0.00);
        ubaciti.push_back(pomocni);
       
        unos+=deltax;
        if(!(std::fabs(unos-xmax)<=EPS*(std::fabs(unos)+std::fabs(xmax))) && unos>xmax) break;
    }
   
    int velicina=ubaciti.size();
    
    for(int i=0; i<velicina; i++)
        ubaciti.at(i).second=funkcija(ubaciti.at(i).first);
    
    return LinearnaInterpolacija(ubaciti);
}





int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija(0);
    std::cin>>opcija;
    
    int n(0);
    if(opcija==1){
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
    
    std::cout<<"Unesite cvorove kao parove x y: ";
    std::vector<std::pair<double, double>> cvorovi(n);
    for(int i=0; i<n; i++){
        double a(0), b(0);
        std::cin>>a>>b;
        cvorovi.at(i)=std::make_pair(a, b);
    }
    
    while(true){
        try{
            
        auto f(LinearnaInterpolacija(cvorovi));
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
       
        double x(0);
        std::cin>>x;
        if(std::cin.peek()!='\n') break;
        
        
        try{
            double rezultat(0);
            rezultat=f(x);
            std::cout<<"f("<<x<<") = "<<rezultat<<std::endl;
        }
        catch(std::domain_error e){
            std::cout<<e.what();
            return 0;
        }
        catch(std::range_error e){
            std::cout<<e.what()<<std::endl;
           
        }
        }
        catch(std::domain_error e){
            std::cout<<e.what();
            return 0;
        }
    }
    }
    else if(opcija==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double pocetak(0), kraj(0), korak(0);
        std::cin>>pocetak>>kraj>>korak;
        
        while(true){
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";

        double x(0);
        std::cin>>x;
        
        if(std::cin.peek()!='\n') break;
        
        auto f(LinearnaInterpolacija(fun, pocetak, kraj, korak));
        try{
            double rezultat(0);
            rezultat=f(x);
            std::cout<<"f("<<x<<") = "<<fun(x)<<" fapprox("<<x<<") = "<<rezultat<<std::endl;
        }
        catch(std::domain_error e){
            std::cout<<e.what();
            return 0;
        }
        catch(std::range_error e){
            std::cout<<e.what()<<std::endl;
           
        }
    }
        
    }
    
    
	return 0;
}
