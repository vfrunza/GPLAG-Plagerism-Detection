/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cmath>

const double epsilon=0.0000001;

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>> vektor, int red) {
    int n(vektor.size());
    if(red>n || red<=0) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(fabs(vektor[i].first-vektor[j].first)<epsilon) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> w;
    for(int i=1;i<=n;i++) {
        double wi(0);
        for(int k=std::max(1,i-red);k<=std::min(i,n-red);k++) {
            double x(1);
            for(int j=k;j<=k+red;j++) {
                if(i!=j) {
                    x*=double(1/(vektor[i-1].first-vektor[j-1].first));
                }
            }
            if(k%2==0) wi+=(-1)*x;
            else wi+=x;
        }
        w.push_back(wi);
    }
    return [w,vektor] (double x) {
        double suma1(0),suma2(0);
        for(int i=1;i<=vektor.size();i++) {
            if(x==vektor[i-1].first) return vektor[i-1].second;
            suma1+=((w[i-1]/(x-vektor[i-1].first))*vektor[i-1].second);
        }
        for(int i=1;i<=vektor.size();i++) {
            suma2+=((w[i-1]/(x-vektor[i-1].first)));
        }
        return double(suma1/suma2);
    };
}


std::pair<double,double> NapraviCvor (double x, double y) {
    return std::make_pair(x,y);
}

std::function<double(double)> BaricentricnaInterpolacija(double fun(double), double xmin, double xmax, double Dx, int red) {
    if (xmax<xmin || red<=0) throw std::domain_error("Nekorektni parametri");
    std::pair<double,double> cvor;
    std::vector<std::pair<double,double>> vektor;
    for(auto i=xmin; i<=xmax; i+=Dx) {
        double x(i);
        double y(fun(i));
        cvor=NapraviCvor(x,y);
        vektor.push_back(cvor);
    }
    return BaricentricnaInterpolacija(vektor,red);
}

std::pair<double,double> NapraviPar() {
    double x,y;
    std::cin >> x >> y; 
    return std::make_pair(x,y);
}

double xxsinx1 (double x) {
    return x*x+sin(x);
}

int main () {
    std::pair<double,double> cvor;
    std::vector<std::pair<double,double>> vektor;
    int opcija,broj;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opcija;
    try {
        if(opcija==1) {
            std::cout << "Unesite broj cvorova: ";
            std::cin >> broj;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0;i<broj;i++) {
                cvor=NapraviPar();
                vektor.push_back(cvor);
            }
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            char znak{'"'};
            double a;
            auto f(BaricentricnaInterpolacija(vektor,d));
            do {
                std::cout << "Unesite argument (ili " << znak << "kraj" << znak << " za kraj): ";
                std::cin >> a;
                if(!std::cin) break;
                std::cout << "f(" << a << ") = " << f(a) << std::endl;
                std::cin.ignore(1000,'\n');
            } while(std::cin);
        }
        if(opcija==2) {
            double xmin,xmax,Dx;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> xmin >> xmax >> Dx;
            int d;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> d;
            char znak{'"'};
            double a;
            auto f(BaricentricnaInterpolacija(xxsinx1,xmin,xmax,Dx,d));
            do {
                std::cout << "Unesite argument (ili " << znak << "kraj" << znak << " za kraj): ";
                std::cin >> a;
                if(!std::cin) break;
                std::cout << "f(" << a << ") = " << xxsinx1(a) << " fapprox(" << a << ") = " << f(a) << std::endl;
                std::cin.ignore(1000,'\n');
            } while(std::cin);
        }
    }
    catch (std::domain_error izutetak) {
        std::cout << izutetak.what() << std::endl;
    }
	return 0;
}