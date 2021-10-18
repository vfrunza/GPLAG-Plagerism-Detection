/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>


std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
    int n(v.size());
    if(d<0 || d>=n) throw std::domain_error("Nedozvoljen red");
    return [v,d,n](double x){
        double f;
        double nazivnik(0), brojnik(0);
        for(int i=1;i<=n;i++){
            double w(0);
            for(int j=std::max(1,i-d);j<=std::min(i,n-d);j++){
                double proizvod(1);
                for(int h=j;h<=j+d;h++){
                    if(h!=i)
                        proizvod*=(1/(v[i-1].first-v[h-1].first));
                }
                w+=pow(-1, j-1)*proizvod;
            }
            if(x==v[i-1].first){
                return v[i-1].second;
            }
                brojnik+=w*v[i-1].second/(x-v[i-1].first);
                nazivnik+=w/(x-v[i-1].first);
            
        }
        f=brojnik/nazivnik;
        return f;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltax, int d){
         
        std::vector<std::pair<double,double>> v;
        for(double i=xmin;i<=xmax;i+=deltax){
            std::pair<double,double> par;
            par.first=i;
            par.second=f(par.first);
            v.push_back(par);
        }
        if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
        std::function<double(double)> fun(BaricentricnaInterpolacija(v, d));
        return fun;
    }

int main ()
{   try{
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int izbor;
        std::cin>>izbor;
        if(izbor==1){
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;
            std::vector<std::pair<double,double>> v;
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0;i<n;i++){
                std::pair<double,double> par;
                std::cin>>par.first;
                std::cin>>par.second;
                v.push_back(par);
            }
            for(int i=0;i<n-1;i++){
                for(int j=1;j<n;j++){
                    if(v[i].first==v[j].first && i!=j){
                        throw std::domain_error("Neispravni cvorovi");
                    }
                }
            }
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            //if(d<0 || d>=n) throw std::domain_error("Nedozvoljen red");
            for(;;){
                double x;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>x;
                if(!std::cin) break;
                std::function<double(double)> func(BaricentricnaInterpolacija(v,d));
                std::cout<<"f("<<x<<") = "<<func(x)<<std::endl;
            }
        }
        else if(izbor==2){
            std::cout<<"Unesite krajeve intervala i korak: ";
            double max, min, korak;
            std::cin>>min>>max>>korak;
            if(min>max || korak<=0) throw std::domain_error("Nekorektni parametri");
            std::cout<<"Unesite red interpolacije: ";
            int d;
            auto fija=[](double u)->double {return pow(u,2)+sin(u);};
            std::cin>>d;
            std::vector<std::pair<double,double>> pomocni;
            for(double i=min;i<=max;i+=korak){
                std::pair<double,double> par;
                par.first=i;
                par.second=fija(par.first);
                pomocni.push_back(par);
            }
            //if(d<0 || d>=pomocni.size()) throw std::domain_error("Nedozvoljen red");
            for(;;){
                double x;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>x;
                if(!std::cin) break;
                std::function<double(double)> bar(BaricentricnaInterpolacija(fija,min,max,korak,d));
                std::cout<<"f("<<x<<") = "<<fija(x)<<" fapprox("<<x<<") = "<<bar(x)<<std::endl;
            }
        }
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
	return 0;
}