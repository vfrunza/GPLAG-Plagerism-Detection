/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <cmath>
std::function<double(double)> LinearnaInterpolacija(std::vector< std::pair<double,double> > tacke){
    std::sort(tacke.begin(),tacke.end(),[](std::pair<double,double> a,std::pair<double,double>b){
        return a.first < b.first;
    });
    for(int i(0);i<tacke.size();i++)
        for(int j(i);j<tacke.size();j++)
            if(i!=j && tacke.at(i).first == tacke.at(j).first)
                throw std::domain_error("Neispravni cvorovi");
        
    return [tacke](double x){
        if(x<tacke.at(0).first || x>tacke.at(tacke.size()-1).first)
            throw std::range_error("Argument izvan opsega");
            
        std::vector<double> vx;
        for(int i(0);i<tacke.size();i++)
        vx.push_back(tacke.at(i).first);
        
        auto px(std::lower_bound(vx.begin(),vx.end(),x));
        if(x == *px)
            return tacke.at(px-vx.begin()).second;
        int index(px-vx.begin()-1);
        double f1 = tacke.at(index).second;
        double f2 = tacke.at(index+1).second - tacke.at(index).second;
        double f3 = tacke.at(index+1).first - tacke.at(index).first;
        
        return f1 + f2*(x - tacke.at(index).first)/f3;
     
    };
}

std::function<double(double)> LinearnaInterpolacija
(std::function<double(double)> f, double min, double max, double korak){
    if(min>max || korak<=0) throw std::domain_error("Nekorektni parametri");
    int broj_cvorova = (max-min)/korak+1;
    std::vector<std::pair<double,double>> v(broj_cvorova);
    v.at(0).first = min;
    v.at(0).second = f(min);
    for(int i(1);i<broj_cvorova;i++){
        v.at(i).first = v.at(i-1).first + korak;
        v.at(i).second = f(v.at(i).first);
    }
    return LinearnaInterpolacija(v);
}

int main (){
    
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija; std::cin>>opcija;
    
    if(opcija == 1){
        std::cout<<"Unesite broj cvorova: ";
        int bc; std::cin>>bc;
        try {
            std::vector<std::pair<double,double>> v(bc);
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i(0);i<v.size();i++){
                double prvi, drugi;
                std::cin>>prvi>>drugi;
                v.at(i) = std::make_pair(prvi,drugi);
            }
            auto f(LinearnaInterpolacija(v));
            while(std::cin){
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg; std::cin>>arg;
                if(!std::cin)return 0;
                try{
                    double a(f(arg));
                    std::cout<<"f("<<arg<<") = "<<a<<std::endl;
                }catch(std::range_error e){
                    std::cout<<e.what()<<std::endl;
                }
                
            }
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
        }catch(std::range_error e){
            std::cout<<e.what()<<std::endl;
        }
        
    }else if(opcija == 2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double poc,kraj,korak;
        std::cin>>poc>>kraj>>korak;
        auto f([](double x){return x*x +sin(x);});
        try{
            auto fapprox(LinearnaInterpolacija(f,poc,kraj,korak));
            while(std::cin){
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg; std::cin>>arg;
                if(!std::cin)return 0;
                try{
                    double a(fapprox(arg));
                    std::cout<<"f("<<arg<<") = "<<f(arg)
                    <<" fapprox("<<arg<<") = "<<a<<std::endl;
                }catch(std::range_error e){
                    std::cout<<e.what()<<std::endl;
                }
            }
        }catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
        }catch(std::range_error e){
            std::cout<<e.what()<<std::endl;
        }
        
    }
	return 0;
}