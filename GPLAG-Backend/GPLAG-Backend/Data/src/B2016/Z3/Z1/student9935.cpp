/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include<iostream>
#include<utility>
#include<functional>
#include<vector>
#include<cmath>
#include<iomanip>

double w(int i, int n, int d, const std::vector<std::pair<double, double>> &v){
    double rezultat(0);
    if(d>=0 && d<n){
        for(int k=std::max(1, i-d); k<=std::min(i, n-d); k++){
            double proizvod(1);
            for(int j=k; j<=k+d; j++){
                if(i!=j)
                    proizvod*=1/(v.at(i-1).first-v.at(j-1).first);
            }
            rezultat+=pow(-1, k-1)*proizvod;
        }
    }
    return rezultat; 
}
//prvi tip funkcije
std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair<double, double>> &v, int d){
    if(!(d>0 && d<v.size()))
        throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size()-1; i++){
        for(int j=i+1; j<v.size(); j++){
            if(v.at(i).first==v.at(j).first)
                throw std::domain_error("Neispravni cvorovi");
        }
    }
    return [d, v](double x){
        double f1(0),f2(0),f(0);
        int n(v.size());
        for(int i=1; i<=n; i++){
            if(x>v.at(i-1).first || x<v.at(i-1).first){
                auto w_i(w(i, n, d, v));
                f1+=(w_i*(v.at(i-1).second))/(x-v.at(i-1).first);
                f2+=(w_i/(x-v.at(i-1).first));
            }
            else{
                return v.at(i-1).second;
            }
        }
        f=f1/f2;
        return f;
    };
}
//drugi tip funkcije
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0)
        throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    for(auto i=x_min; i<=x_max; i+=delta_x){
        std::pair<double, double> cvor;
        cvor.first=i;
        cvor.second=f(cvor.first);
        v.push_back(cvor);
    }
    return BaricentricnaInterpolacija(v, d);
}

int main (){
        try{
            int odluka;
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            std::cin>>odluka;
            if(odluka==1){
                std::cout<<"Unesite broj cvorova: ";
                int br_cvorova;
                std::cin>>br_cvorova;
                std::vector<std::pair<double, double>> v;
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(int i=0; i<br_cvorova; i++){
                    int x, y;
                    std::cin>>x>>y;
                    v.push_back(std::make_pair(x, y));
                }
                int red_interpolacije;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>red_interpolacije;
                for(;;){
                    double argument;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>argument;
                    if(!std::cin){
                        return 1;
                    }
                    else{
                            auto fun = BaricentricnaInterpolacija(v, red_interpolacije);
                                std::cout << "f("<<argument<<") = " << fun (argument);
                            std::cout<<std::endl;
                    }
                }
            }
            else if(odluka==2){
                double pocetak_intervala, kraj_intervala, korak;
                std::cout<<"Unesite krajeve intervala i korak: ";
                std::cin>>pocetak_intervala>>kraj_intervala>>korak;
                std::cin.ignore(10000, '\n');
                std::cin.clear();
                std::cout<<"Unesite red interpolacije: ";
                int red_interpolacije(0);
                std::cin>>red_interpolacije;
                for(;;){
                    double argument(0);
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>argument;
                    if(!std::cin){
                       return 2;
                    }
                    else{
                            auto fun = BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);}, pocetak_intervala, kraj_intervala, korak, red_interpolacije);
                                auto lamda([](double x){return x*x+std::sin(x);});
                                std::cout << "f("<<argument<<") = " <<lamda(argument)<< " fapprox("<<argument<<") = " << fun (argument);
                            std::cout<<std::endl;
                    }
                }
            }
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
        }
	return 0;
}