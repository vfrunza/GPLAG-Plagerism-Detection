/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON(0.0001);

double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

void DaLiSuIspravniCvorovi(std::vector<std::pair<double, double>> vp){
    for(int i=0; i<vp.size(); i++)
        for(int j=i+1; j<vp.size(); j++)
            if(EPSILON>std::fabs(vp[i].first-vp[j].first)) throw std::domain_error("Neispravni cvorovi");
}

void DaLiSuIspravniKrajeviIntervalaIKorak(double x_min, double x_max, double delta_x){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
}
std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    DaLiSuIspravniCvorovi(vp);
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(EPSILON>std::fabs(x-vp[i].first)) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(EPSILON>std::fabs(x-vp[i].first)) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    DaLiSuIspravniKrajeviIntervalaIKorak(x_min, x_max, delta_x);
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                DaLiSuIspravniCvorovi(vp);
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!(std::cin.peek()>='0' && std::cin.peek()<='9') && std::cin.peek()!='\n') return 0;
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                DaLiSuIspravniKrajeviIntervalaIKorak(x_min,x_max,delta_x);
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}/*/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON 0.0001
double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=1; i<vp.size()-1; i++){
        for(int j=i+1; j<vp.size(); j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON 0.0001
double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=1; i<vp.size()-1; i++){
        for(int j=i+1; j<vp.size(); j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON 0.0001
double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=1; i<vp.size()-1; i++){
        for(int j=i+1; j<vp.size(); j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON 0.0001
double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=1; i<vp.size()-1; i++){
        for(int j=i+1; j<vp.size(); j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON 0.0001
double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=1; i<vp.size()-1; i++){
        for(int j=i+1; j<vp.size(); j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON 0.0001
double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=1; i<vp.size()-1; i++){
        for(int j=i+1; j<vp.size(); j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON 0.0001
double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=1; i<vp.size()-1; i++){
        for(int j=i+1; j<vp.size(); j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON 0.0001
double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=1; i<vp.size()-1; i++){
        for(int j=i+1; j<vp.size(); j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON 0.0001
double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=1; i<vp.size()-1; i++){
        for(int j=i+1; j<vp.size(); j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

const double EPSILON 0.0001
double Produkt(int i, int k, int d, std::vector<std::pair<double,double>> &v){
    double produkt(1);
    for(int j=k; j<=k+d; j++){
        if(j==i)continue;
        produkt*=1./(v[i-1].first-v[j-1].first);
    }
    return produkt;
}
double TezinskiKoeficijent(int i, int d, std::vector<std::pair<double,double>> &vp){
    int n(vp.size());
    int a, b;
    if(i<n-d) b=i;
    else b=n-d;
    if(1>i-d) a=1;
    else a=i-d;
    double suma(0);
    for(int k=a; k<=b; k++){
        suma+=std::pow(-1, k-1)*Produkt(i,k,d,vp);
    }
    return suma;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vp, int broj){
    if(broj<0 || broj>=vp.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=1; i<vp.size()-1; i++){
        for(int j=i+1; j<vp.size(); j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    }
    std::vector<double> tk(vp.size());
    for(int i=0; i<vp.size(); i++){
        tk[i]=(TezinskiKoeficijent(i+1, broj, vp));
    }
    
    return [vp, tk](double x)->double{
        double f1(0), f2(0);
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f1+=tk[i]*vp[i].second/(x-vp[i].first);
        }
        for(int i=0; i<vp.size(); i++){
            if(x==vp[i].first) return vp[i].second;
            f2+=tk[i]/(x-vp[i].first);
        }
        return f1/f2;
    };
}

std::function<double(double)>BaricentricnaInterpolacija(double f(double), double x_min, double x_max, double delta_x, int d){
    if(x_min>x_max || delta_x<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    int j(0);
    for(double i=x_min; i<=x_max; i+=delta_x){
        vp.resize(j+1);
        vp[j].first=i;
        vp[j].second=f(i);
        j++;
    }
    return BaricentricnaInterpolacija(vp,d);
}
int main ()
{
    try{
        for(;;){
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
            int x;
            std::cin>>x;
            if(x==1){
                std::cout<<"Unesite broj cvorova: ";
                int cvorovi;
                std::cin>>cvorovi;
                std::vector<std::pair<double,double>> vp(cvorovi);
                std::cout<<"Unesite cvorove kao parove x y: ";
                for(auto &a : vp){
                    std::cin>>a.first>>a.second;
                }
                std::cout<<"Unesite red interpolacije: ";
                int d;
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija(vp,d));
                    std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
            if(x==2){
                std::cout<<"Unesite krajeve intervala i korak: ";
                double x_min, x_max, delta_x;
                std::cin>>x_min>>x_max>>delta_x;
                int d;
                std::cout<<"Unesite red interpolacije: ";
                std::cin>>d;
                for(;;){
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;
                    if(!std::cin) return 0;
                    auto f(BaricentricnaInterpolacija([](double x) { return x*x+std::sin(x);}, x_min, x_max, delta_x, d));
                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
                }
            }
        }
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
	return 0;
}*/