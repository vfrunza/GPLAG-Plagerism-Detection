#include <iostream>
#include <stdexcept>
#include <vector>
#include <functional>
#include <utility>
#include <cmath>

double Daj_W(std::vector<std::pair<double,double>> v, int d, int i){
    double rez=0;
    int min,max;
    if(1>i+1-d) max=1; else max=i+1-d;
    if((v.size()-d)<i+1) min=v.size()-d; else min=i+1;
    
    for(int k=max-1; k<min; k++){
        double proizvod=1;
        for(int j=k; j<=(k+d);j++){
            if(j==i) continue;
            proizvod=proizvod*(1/(v[i].first-v[j].first));
        }
        rez=rez+std::pow(-1,k)*proizvod;
    }
    return rez;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    std::vector<double> w_i;
    for(int i=0; i<v.size();i++){
        for(int j=i+1; j<v.size(); j++){
            if(v[i].first==v[j].first)
                throw std::domain_error("Neispravni cvorovi");
        }
    }    
    
    for(int i(0); i<v.size();i++){
        w_i.push_back(Daj_W(v,d,i));
    }
    return [v,d,w_i] (double x){
        double suma_1(0), suma_2(0);
        for(int i=0;i<v.size();i++){
            if (std::fabs(x-v[i].first)<0.00000001) return v[i].second;
            suma_1=suma_1+(w_i[i]/(x-v[i].first))*v[i].second;
            suma_2=suma_2+(w_i[i]/(x-v[i].first));
        }
        return double(suma_1)/double(suma_2);
    };
}
std::function<double(double)> BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x,  int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    while (x_min<=x_max) {
        v.push_back(std::make_pair(x_min, f(x_min)));
        x_min=x_min+delta_x;
    }
    return BaricentricnaInterpolacija(v,d);    
}

int main ()
{
    try {
            std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int n; std::cin >> n;
            if(n==1){
                std::cout <<"Unesite broj cvorova: ";
                int br_cvorova; std::cin >> br_cvorova;
                std::cout <<"Unesite cvorove kao parove x y: ";
                std::vector<std::pair<double,double>> v(br_cvorova);
                for(int i=0; i<br_cvorova; i++){
                    std::cin >> v[i].first;
                    std::cin >> v[i].second;
                    
                }
                std::cout << "Unesite red interpolacije: ";
                int d; std::cin >> d;
                char ch='"';
                auto f(BaricentricnaInterpolacija(v,d));
                while(true){
                    std::cout <<"Unesite argument (ili "<<ch<<"kraj"<<ch<<" za kraj): ";
                    double y; std::cin >> y;
                    if(!std::cin){
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            break;
                    }
                    std::cout <<"f("<<y<<") = "<<f(y)<<"\n";
                }
                return 0;
            }
            if(n==2){
                std::cout << "Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x; 
                std::cin >> x_min; 
                std::cin >>x_max; 
                std::cin >> delta_x;
                std::cout <<"Unesite red interpolacije: ";
                int d; std::cin >> d;
                char ch='"';
                auto f(BaricentricnaInterpolacija([](double x){ return std::pow(x,2)+std::sin(x);},x_min,x_max,delta_x,d));
                while(true){
                    std::cout <<"Unesite argument (ili "<<ch <<"kraj"<<ch <<" za kraj): ";
                    double y; std::cin >> y;
                    if(!std::cin){
                            std::cin.clear();
                            std::cin.ignore(10000, '\n');
                            break;
                    }
                    std::cout <<"f("<<y <<") = "<< std::pow(y,2)+std::sin(y)<<" "<<"fapprox("<<y<<") = "<<f(y)<<"\n";
                }
                return 0;
            }
    }
    catch (std::domain_error error) {
        std::cout << error.what() << std::endl;
    }
	return 0;
}