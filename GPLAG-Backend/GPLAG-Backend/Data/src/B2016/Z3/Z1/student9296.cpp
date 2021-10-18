/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>
int max(int x, int y){
    if(x>y) return x;
    return y;
}
int min(int x, int y){
    if(x<y) return x;
    return y;
}
double fun(double x){
    return x*x+std::sin(x);
}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d){
    if(d<0 || d>=v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size(); i++)
        for(int j=i+1; j<v.size()-1; j++)
            if(v[i].first==v[j].first) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> v_w;
        for(int i=1; i<=v.size(); i++){
            double w(0);
            for(int k=max(1, i-d); k<=min(i, v.size()-d); k++){
                double proizvod(1);
                for(int j=k; j<=k+d; j++){
                    if(i-1==j-1) continue;
                    proizvod*=1/(v[i-1].first-v[j-1].first);
                }
                w+=pow(-1, k-1)*proizvod;
            }
            v_w.push_back(w);
        }
    
    return [v_w, v](double x){
        double brojnik(0), nazivnik(0);
        for(int i=0; i<v.size(); i++){
            if(x==v[i].first) return v[i].second;
            brojnik+=(v_w[i]*v[i].second)/(x-v[i].first);
            nazivnik+=v_w[i]/(x-v[i].first);
        }
            return brojnik/nazivnik;};
}
std::function<double(double)>BaricentricnaInterpolacija(double aproksimant(double), double x_min, double x_max, double delx, int d){
    if(x_min>x_max || delx<=0) throw std::domain_error("Nekorektni parametri");
    double i(x_min);
    int j(0);
    std::vector<std::pair<double, double>> ugh;
    for(;;){
        if(i>x_max) break;
        ugh.resize(ugh.size()+1);
        ugh[j].first=i;
        ugh[j].second=aproksimant(i);  //prave se cvorovi
        i+=delx;
        j++;
    }
    return BaricentricnaInterpolacija(ugh, d);
}

int main ()
{
    try{
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin>>opcija;
        std::vector<std::pair<double, double>>v;
        if(opcija==1){
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;
            std::cout<<"Unesite cvorove kao parove x y: ";
            int i(0);
            while(v.size()!=n){
                v.resize(v.size()+1);
                std::cin>>v[i].first>>v[i].second;
                i++;
            }
            std::cout<<"Unesite red interpolacije: ";            
            int d;
            std::cin>>d;
            try{
                for(;;){
                    auto f(BaricentricnaInterpolacija(v,d));
                    double arg;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    if(!(std::cin>>arg)) return 0;
                    std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
                }
            }
            catch(std::domain_error iz){
                std::cout<<iz.what();
                return 0;
            }
        }
            if(opcija==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, korak;
                std::cin>>x_min>>x_max>>korak;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                try{
                    for(;;){
                        auto f(BaricentricnaInterpolacija(fun, x_min, x_max, korak, d));
                        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                        double arg;
                        if(!(std::cin>>arg)) return 0;
                        std::cout<<"f("<<arg<<") = "<<fun(arg)<<" fapprox("<<arg<<") = "<<f(arg);
                        std::cout<<std::endl;
                    }
                }
                catch(std::domain_error bleh){
                    std::cout<<bleh.what();
                    return 0;
                }
        }
    }
    catch(std::domain_error ew){
        std::cout<<ew.what();
    }
	return 0;
}