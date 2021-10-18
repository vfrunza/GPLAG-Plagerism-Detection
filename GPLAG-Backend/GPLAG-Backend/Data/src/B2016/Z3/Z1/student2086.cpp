#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> parovi, int d){
        if((d<0)or(d>parovi.size()))
                throw std::domain_error ("Nedozvoljen red");
        const double EPS(0.000000000001);
        const double NEPS(-0.000000000001);
        for(auto x(0); x<parovi.size();x++){
                for(auto y(0); y<parovi.size(); y++){
                    if(x==y) continue;
                        if((parovi[y].first-parovi[x].first<EPS)and(parovi[y].first-parovi[x].first>NEPS))
                                throw std::domain_error ("Neispravni cvorovi");
                }
        }
        std::vector<double> w;
        for(int i=1; i<=parovi.size(); i++){
            double wi(0);
            for(int k=std::max(1,i-d); k<=std::min(i,(int)parovi.size()-d); k++){
                double suma(1);
                            for(int j=k; j<=k+d; j++){
                                if(j==i) continue;
                                suma*=1/(parovi[i-1].first-parovi[j-1].first);
                            }
                            wi+=pow(-1,k-1)*suma;
                           
                    }
                     w.push_back(wi);
        }
        return [parovi,d,w](double x){
            double suma1(0),suma2(0);
            const double EPS(0.000000000001);
            const double NEPS(-0.000000000001);
            for(int i=1; i<=parovi.size(); i++){
                    if((x-parovi[i-1].first<EPS)  and  (x-parovi[i-1].first>NEPS)){
                            return parovi[i-1].second;
                    }
                    suma1+=(w[i-1]/(x-parovi[i-1].first))*parovi[i-1].second;
                    suma2+=(w[i-1]/(x-parovi[i-1].first));
            }
            return suma1/suma2;
        };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,double min,double max, double dx, int d){
    if((min>max)or(dx<=0))
        throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    for( ; min<max; min+=dx){
        std::pair<double,double> par{min,f(min)};
        cvorovi.push_back(par);
    }
    return  BaricentricnaInterpolacija(cvorovi,d);
}

double fj(double x){
    return pow(x,2)+std::sin(x);
}

int main ()
{
    for(;;){
        
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opc;
        std::cin>>opc;
        if(opc==1){
            std::cout<<"Unesite broj cvorova: ";
            int br_c;
            std::cin>>br_c;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double,double>> parovi;
            for(int i=0; i<br_c; i++){
                std::pair<double,double> par;
                std::cin>>par.first>>par.second;
                parovi.push_back(par);
            }
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            for(;;){
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double x;
                std::cin>>x;
                if(!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(1000,'\n');
                    return 0;
                }
                try{
                auto P(BaricentricnaInterpolacija(parovi,d)(x));
                std::cout<<"f("<<x<<") = "<<P<<std::endl;
                }catch(std::domain_error izuzetak){
                    std::cout<<izuzetak.what();
                    return 0;
                }
            }
            
        }else{
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout<<"Unesite krajeve intervala i korak: ";
            double min,max,dx;
            std::cin>>min>>max>>dx;
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            for(;;){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            std::cin>>x;
            if(!std::cin) return 0;
            try{
                auto P(BaricentricnaInterpolacija(fj,min,max,dx,d)(x));
                std::cout<<"f("<<x<<") = "<<fj(x)<<" fapprox("<<x << ") = " <<P <<std::endl;
            }catch(std::domain_error izuzetak){
                    std::cout<<izuzetak.what();
                    return 0;
            }
            }
        }
    }
	return 0;
}