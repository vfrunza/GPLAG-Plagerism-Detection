#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> vp, int d) {
    int n(vp.size());
    if(d<0 or d>n) throw std::domain_error("Nedozvoljen red");
    for(int i(0); i<n; i++)
        for(int j(i+1); j<n; j++)
            if(vp[i].first==vp[j].first) throw std::domain_error("Neispravni cvorovi");
    return [vp, d, n] (double x) { double temp2(0), temp3(0);
                                for(int i(1); i<=n; i++) {
                                    if(vp[i-1].first==x) return vp[i-1].second;
                                    double w(0);
                                    int temp(n-d);
                                    if(i<temp) temp=i;
                                    int k(1);
                                    if((i-d)>1) k=i-d;
                                    for(; k<=temp; k++) {
                                        double wtemp(1);
                                        for(int j(k); j<=(k+d); j++) {
                                            if(j!=i) {
                                                wtemp*=1./(vp[i-1].first-vp[j-1].first);
                                            }
                                        }
                                        if((k-1)%2!=0) wtemp = -wtemp;
                                        w+=wtemp;
                                    }
                                    temp2 += w/(x-vp[i-1].first);
                                    temp3 += (w/(x-vp[i-1].first))*vp[i-1].second;
                                }
                                return temp3/temp2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double delta_x, int d) {
    if(x_min>x_max or delta_x<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double, double>> vp;
    while(x_min <= x_max) {
        vp.push_back({x_min, f(x_min)});
        x_min+=delta_x;
    }
    int n(vp.size());
    return [vp, d, n] (double x) { double temp2(0), temp3(0);
                                for(int i(1); i<=n; i++) {
                                    if(vp[i-1].first==x) return vp[i-1].second;
                                    double w(0);
                                    int temp(n-d);
                                    if(i<temp) temp=i;
                                    int k(1);
                                    if((i-d)>1) k=i-d;
                                    for(; k<=temp; k++) {
                                        double wtemp(1);
                                        for(int j(k); j<=(k+d); j++) {
                                            if(j!=i) {
                                                wtemp*=1./(vp[i-1].first-vp[j-1].first);
                                            }
                                        }
                                        if((k-1)%2!=0) wtemp = -wtemp;
                                        w+=wtemp;
                                    }
                                    temp2 += w/(x-vp[i-1].first);
                                    temp3 += (w/(x-vp[i-1].first))*vp[i-1].second;
                                }
                                return temp3/temp2;
    };
}

int main ()
{   
    try {
    std::function<double(double)> fun = [] (double x) {return x*x+std::sin(x);};
    int broj;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> broj;
    if(broj == 1) {
        int n;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> n;
        std::vector<std::pair<double, double>> vp(n);
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i(0); i<n; i++) std::cin >> vp[i].first >> vp[i].second;
        int d;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
        auto f(BaricentricnaInterpolacija(vp, d));
        while(1) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double x; std::cin >> x;
            if(!std::cin) break;
            std::cout << "f(" << x << ") = " << f(x) << std::endl;
        }
    } else if(broj == 2) {
        double x_min, x_max, delta_x;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> x_min >> x_max >> delta_x;
        int d;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> d;
        auto f(BaricentricnaInterpolacija(fun, x_min, x_max, delta_x, d));
        while(1) {
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double x; std::cin >> x;
            if(!std::cin) break;
            std::cout << "f(" << x << ") = " << fun(x) << " fapprox(" << x << ") = " << f(x) << std::endl;
        }
    }
    }
    catch(std::domain_error a) {
        std::cout << "Izuzetak: " << a.what();
    }
	return 0;
}