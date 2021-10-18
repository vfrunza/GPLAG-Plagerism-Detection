#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <functional>
#include <algorithm>
#include <cmath>

 
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> vek) {
 
    std::sort(vek.begin(),vek.end(), [](std::pair<double,double> par1, std::pair<double,double> par2) {
        return par1.first<par2.first;
    });
   
    return [vek](double tmp) {
        double rez(0);
        if(tmp<vek[0].first || tmp>vek[vek.size()-1].first) throw std::range_error("Argument izvan opsega");
        for(int i(0);i<vek.size()-1;i++) {
            if(tmp==vek[vek.size()-1].first) {
                return vek[vek.size()-1].second;
            }
            if(tmp>=vek[i].first && tmp<vek[i+1].first) {
                double tmp1=vek[i].first;
                double tmp2=vek[i].second;
                double tmp11=vek[i+1].first;
                double tmp22=vek[i+1].second;
                rez=tmp2+((tmp22-tmp2)/(tmp11-tmp1))*(tmp-tmp1);
                return rez;
            }  
        }
        return rez;
    };
}
 
std::function<double(double)> LinearnaInterpolacija(double funk(double), double min, double max, double param) {
    if(min>max or param<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> vekpar;
    int j(0);
    for(double i(min);i<=max;i=i+j*param) {
        vekpar.push_back(std::make_pair(i,funk(i)));
        j++;
    }
    return [funk,vekpar,param] (double x) {
        double fun(0);
        if(x<vekpar[0].first or x>vekpar[vekpar.size()-1].first) throw std::range_error("Argument izvan opsega");
        if(x==vekpar[vekpar.size()-1].first) {
            return vekpar[vekpar.size()-1].second;
        }
        for(int i(0);i<vekpar.size();i++) {
            if(i+1<=vekpar.size()-1){
            auto it(lower_bound(vekpar.begin(),vekpar.end(),x, [] (const std::pair<double,double> &a, const double &b) {
                return a.first<b;
            }));
            double xi=it->first;
            double yi=funk(xi);
            double xii=it->first-param;
            double yii=funk(xii);
            fun=yi+((yii-yi)/(xii-xi))*(x-xi);
            return fun;
            }
        }
        return fun;
    };
}
 
int main ()
{
    int a;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>a;
    if(a==1) {
        int tmp;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>tmp;
        std::cin.ignore(1000,'\n');
        std::vector<std::pair<double,double>> vektorpar;
        std::pair<double,double> p;
        double x, y;
        try {
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i(0);i<tmp;i++) {
            std::cin>>x>>y;
            p=std::make_pair(x,y);
            vektorpar.push_back(p);
        }
        for(int i(0);i<vektorpar.size();i++) {
        double prvi(vektorpar[i].first);
        for(int j(0);j<vektorpar.size();j++) {
            if(i!=j) {
            if(prvi==vektorpar[j].first) throw std::domain_error("Neispravni cvorovi");  
            }
        }
        }
        double param;
        for(;;) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>param;
            if(!std::cin) return 0;
                auto f(LinearnaInterpolacija(vektorpar));
                std::cout<<"f("<<param<<") = "<<f(param)<<std::endl;
        }
        }
        catch (std::domain_error a) {
            std::cout<<a.what()<<std::endl;
        }
        catch (std::range_error b) {
            std::cout<<b.what()<<std::endl;
        }
       
    }
    else if(a==2) {
        double min,max,param;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>min>>max>>param;
        std::cin.ignore(1000,'\n');
        double x;
        for(;;) {
             std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
             std::cin>>x;
             if(!std::cin) return 0;
             try {
                 auto f(LinearnaInterpolacija([](double x) {return x*x+sin(x);},min,max,param));
                 std::cout<<"f("<<x<<") = "<<x*x+sin(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
             }
             catch (std::domain_error a) {
                std::cout<<a.what()<<std::endl;
             }
             catch (std::range_error b) {
                std::cout<<b.what()<<std::endl;
             }
        }
    }
    return 0;
}