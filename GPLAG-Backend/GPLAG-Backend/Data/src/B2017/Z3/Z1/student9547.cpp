/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<stdexcept>
#include<iomanip>
#include<functional>
#include<cmath>



double fun(double x){
    return x*x+sin(x);
}
std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double,double> > a){
    std::sort(a.begin(), a.end(),[](std::pair<double,double>x,
                                    std::pair<double,double>y){
                                        if(x.first<y.first) return true;
                                        return false; });
for(int i(0);i < a.size();i++){
    for(int j(i+1); j<a.size();j++){
        std::pair<double,double> par = a.at(i);
        std::pair<double,double> drugi =a.at(j);
        if(par.first == drugi.first) throw std::domain_error("Neispravni cvorovi");
    }
}
return[a](double x){
    if(x < a.at(0).first || x>a.at(a.size()-1).first) throw std::range_error("Argument izvan opsega");
    if(x == a.at(a.size()-1).first)  return a.at(a.size()-1).second;
    std::pair<double,double>prvi,drugi;
    for(int i(0);i<a.size();i++){
        if(x<a.at(i).first){
            drugi = a.at(i);
            prvi = a.at(i-1);
            break;
        }
    }
    double rezultat = prvi.second+((drugi.second-prvi.second)/(drugi.first-prvi.first))*(x-prvi.first);
    return rezultat;
};
}

std::function<double(double)>LinearnaInterpolacija(std::function<double(double)>fun, double min, double max, double delta){
    if (min>max || delta <= 0) throw std::domain_error("Nekonkretni parametri");
    std::vector<std::pair<double,double>> rezultat;
    while(min <= max){
        std::pair<double,double > temp = std::make_pair(min,fun(min));
        rezultat.push_back(temp);
        min += delta;
    }
    return LinearnaInterpolacija(rezultat);
    
}
int main ()
{   
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija)"": " ;
    int a;
    std::cin >> a;
    if(a == 1){
        std::cout << "Unesite broj cvorova: ";
        int broj;
        std::cin >> broj;
        std::vector<std::pair<double,double>>vektor;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i(0); i < broj; i++){
            std::pair<double,double> par;
            std::cin >> par.first;
            std::cin >> par.second;
            vektor.push_back(par);
        }
        try{
            auto funkcija = LinearnaInterpolacija(vektor);
            while(1){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin>>arg;
                if(!std::cin || std::cin.peek()!='\n') break;
                try{
                    std::cout << "f(" << arg << ") = " <<funkcija(arg)<<std::endl;
                }catch(std::range_error){
                    std::cout << "Argument izvan opsega ";}
            }
            
        }catch(std::domain_error e){
            std::cout << e.what() << std::endl;
           }
}
        
        
        else if( a == 2){
            std::vector<double>vektor;
            double x1,x2,korak;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> x1;
            std::cin >> x2;
            std::cin >> korak;
            try{
                auto funkcija = LinearnaInterpolacija(fun,x1,x2,korak);
                 while(1){
                    std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                    double arg;
                    std::cin >> arg;
                    if(!std::cin || std::cin.peek()!='\n') break;
                    try{
                    std::cout << "f(" << arg << ") = " <<fun(arg) << " fapprox(" << arg << ") = " <<funkcija(arg)<<std::endl;
                
                    }catch(std::range_error){
                    std::cout <<"Argument izvan opsega"<< std::endl;
                    }
                
                 }
            }catch(std::domain_error e){
                    std::cout << e.what()<<std::endl;
            }
            
        }
        
    
	return 0;
}
