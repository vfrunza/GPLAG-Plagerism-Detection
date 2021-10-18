/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>     
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <limits>
#include <set>
bool comp (const std::pair<double,double> &i, const std::pair<double,double> &j) {
    double e(0.00001);
    return fabs(i.first - j.first) < e;
}
bool comp2 (const std::pair<double,double> &i, const std::pair<double,double> &j) {

    return i.first <  j.first;
}
std::function<double(double)>  LinearnaInterpolacija (std::vector<std::pair<double,double>> a){
    int i(0);
    std::sort(a.begin(),a.end());
    std::set<double> temp2;
    while(i < a.size()){
        temp2.insert(std::get<0>(a.at(i)));
        i++;
    }
    if(temp2.size() != a.size()){
        throw std::domain_error("Neispravni cvorovi");
    }
    return [a](double x){
        try{
        std::vector<std::pair<double,double>> b;
        
        
        std::vector<std::pair<double,double>>::iterator x1,x2,tm,tm2;
        std::pair<double,double> tem;
        tem = std::make_pair (x,1.1);
        if(!((fabs(x - std::get<0>(a.at(0))) < 0.0001))){
            if(x < std::get<0>(a.at(0))){
                throw std::range_error("Argument izvan opsega");
            }
        }
        if(!((fabs(x - std::get<0>(a.at(a.size() - 1))) < 0.0001))){
            if(x > std::get<0>(a.at(a.size() - 1))){
                throw std::range_error("Argument izvan opsega");
            }
        }
        b =a;
        b.push_back(tem);
        std::sort(b.begin(),b.end());
        x1 = std::lower_bound(b.begin(),b.end(),std::make_pair(x,1.1),comp2);
        if(fabs(x - std::get<0>(a.at(a.size() - 1))) < 0.0001){
            return std::get<1>(a.at(a.size() - 1));
        }
        if(fabs(x - std::get<0>(a.at(0))) < 0.00001){
            return  std::get<1>(a.at(0));
        }
        tm = x1;
        tm++;
        if(fabs(x1->first - (tm)->first) < 0.00001 ){
            return tm->second;
        }
        tm2 = x1;
        tm2--;
        if(fabs(x1->first - (tm2)->first) < 0.00001){
            return tm2->second;
        }
        x2 = std::upper_bound(b.begin(),b.end(),std::make_pair(x,1.1),comp2);
        x1--;
        double f;
        f = x1->second + ((x2->second - x1->second) / (x2->first - x1->first))*(x -  x1->first);
        return f;
        } catch (std::range_error e){
            std::cout << e.what();
            return -14535453455354535433534534543435.3;
        }
    };
}
std::function<double(double)>  LinearnaInterpolacija (std::function<double(double)> h,double min,double max,double D){
    std::vector<std::pair<double,double>> a;
    int y(0);
    while(!(fabs((min + y*D) - max) < 0.0001)){
        a.push_back(std::make_pair(min+y*D,h(min+y*D)));
        y++;
    }
    a.push_back(std::make_pair(max,h(max)));
    return LinearnaInterpolacija(a);
}

int main ()
{
    int a;
    std::vector<std::pair<double,double>> v;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> a;
    std::function<double(double)> f;
    double k;
    int u(a);
    try{
    if(a == 1){
         double x,y;
        std::cout <<"Unesite broj cvorova: ";
        std::cin >> a;
        std::cout <<"Unesite cvorove kao parove x y: ";
        for(int i = 0;i < a;i++){
            std::cin >> x;
            std::cin >> y;
            v.push_back(std::make_pair(x,y));
        }
        f = LinearnaInterpolacija(v);
    } else if (a == 2){
        std::cout << "Unesite krajeve intervala i korak: ";
        double x,xm,d;
        std::cin >> x >> xm >> d;
         f = LinearnaInterpolacija([] (double u) {return pow(u,2) + sin(u);},x,xm,d);
    }
    }catch (std::domain_error e){
        std::cout << e.what();
        return 0;
    }
    if(u == 1){
    while(1){
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> k;
            if(!std::cin){
                break;
            }
            if (f(k) != -14535453455354535433534534543435.3){
            std::cout << "f(" << k << ") = " << f(k) << "\n";
            } else {
                std::cout << "\n";
            }
        }
    } else if(u==2){
         while(1){
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> k;
            if(!std::cin){
                break;
            }
           
            if (f(k) != -14535453455354535433534534543435.3){
            std::cout << "f(" << k << ") = " << pow(k,2.0) + sin(k) << " ";
            std::cout << "fapprox(" << k << ") = " << f(k) << '\n';
            } else {
                std::cout <<"\n";
            }
           
        }
    }
	return 0;
}
