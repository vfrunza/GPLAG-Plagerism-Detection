/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <utility>

bool JesuLiJednaki(double x, double y, double Eps=1e-10) {
    if ((x<0 && y>0) || (x>0 && y<0)) return false;
    return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
}

int MaxElement(int x, int y) {
    if (x>=y) return x;
    else return y;
}

int MinElement(int x, int y) {
    if (x>=y) return y;
    return x;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> vup, int d) {
    if (d<0 || d>vup.size()) throw std::domain_error("Nedozvoljen red");
    for (int i=0; i<vup.size(); i++)
        for (int j=i+1; j<vup.size(); j++)
            if (JesuLiJednaki(vup[i].first, vup[j].first)) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> tezinski_koeficijenti;
    for (int i=0; i<vup.size(); i++) {
        double w(0);
        for (int k=MaxElement(1,i+1-d)-1; k<=MinElement(i+1,vup.size()-d)-1; k++) {
            double proizvod(1);
            for (int j=k; j<=k+d; j++) {
                if (j==i) continue;
                else proizvod*=double(1/(vup[i].first-vup[j].first));
            }
            w+=std::pow(-1,k-1)*proizvod;
        }
        tezinski_koeficijenti.push_back(w);
    }
    return[vup,tezinski_koeficijenti,d](double x){
        double brojnik(0), nazivnik(0);
        for (int i=0; i<vup.size(); i++) {
            if (JesuLiJednaki(x,vup[i].first)) 
                return vup[i].second;
            else {
                brojnik+=double((tezinski_koeficijenti[i]*vup[i].second)/(x-vup[i].first));
                nazivnik+=double(tezinski_koeficijenti[i]/(x-vup[i].first));
            }
        }
        return double(brojnik/nazivnik);
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double x_min, double x_max, double d_x, int d) {
    if (((x_min>x_max) && !JesuLiJednaki(x_min, x_max)) || ((d_x<=0) || JesuLiJednaki(d_x,0))) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> vup;
    while(x_min<=x_max) {
        std::pair<double,double> p;
        p=std::make_pair(x_min,f(x_min));
        vup.push_back(p);
        x_min+=d_x;
    }
    return BaricentricnaInterpolacija(vup,d);
}

int main () {
    int opcija;
    do {
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> opcija;
        if (opcija==1) {
            int broj_cvorova;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> broj_cvorova;
            std::vector<std::pair<double,double>> vektor_uredjenih_parova(broj_cvorova);
            std::cout << "Unesite cvorove kao parove x y: ";
            for (int i=0; i<broj_cvorova; i++)
                std::cin >> vektor_uredjenih_parova[i].first >> vektor_uredjenih_parova[i].second;
            int red_interpolacije;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> red_interpolacije;
            double argument;
            std::function<double(double)> fun;
            try {
                fun=BaricentricnaInterpolacija(vektor_uredjenih_parova, red_interpolacije);
            }
            catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what();
                return 0;
            }
            do {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if (!std::cin) return 0;
                else std::cout << "f(" << argument << ") = " << fun(argument) << std::endl;
            } while(1);
        }
        else if (opcija==2) {
            double x_min, x_max, d_x;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> x_min >> x_max >> d_x;
            int red_interpolacije;
            std::cout << "Unesite red interpolacije: ";
            std::cin >> red_interpolacije;
            double argument;
            std::function<double(double)> fun;
            try {
                fun=BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);}, x_min, x_max, d_x, red_interpolacije);
            }
            catch(std::domain_error izuzetak) {
                std::cout << izuzetak.what();
                return 0;
            }
            do {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> argument;
                if (!std::cin) return 0;
                else std::cout << "f(" << argument << ") = " << argument*argument+std::sin(argument) << " fapprox(" << argument << ") = " << fun(argument) << std::endl;
            } while(1);
        }
    } while(1);
	return 0;
}