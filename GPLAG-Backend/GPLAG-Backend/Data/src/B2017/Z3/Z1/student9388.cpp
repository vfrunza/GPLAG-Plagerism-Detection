/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <cmath>
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> a)
{
    std::sort(a.begin(), a.end());
    for(int i=0; i<a.size(); i++) {
        bool dupli(false);
        double prvi_x(a[i].first);
        for(int j=i+1; j<a.size(); j++) {
            double drugi_x(a[j].first);
            if(prvi_x==drugi_x) dupli=true;
            break;
        }
        if(dupli) throw std::domain_error("Neispravni cvorovi");
    }


    return [a](double n) {
        if(n<a.at(0).first || n>a.at(a.size()-1).first) throw std::range_error("Argument izvan opsega");
        std::pair<double, double> par;
        par.first=n;
        par.second=0;
        auto pok=std::lower_bound(a.begin(), a.end(), par);
        if(pok==a.end()) {
            pok--;
            return pok->second;
        }
        auto pok2=pok;
        pok2--;

        return pok2->second+((pok->second - pok2->second)/(pok->first - pok2->first))*(n-pok2->first);

    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double dx, double gx, double razm)
{
    if(dx>gx || razm<0) throw std::domain_error("Nekorektni parametri");
    double br;
    std::vector<std::pair<double, double>> a;
    for(br=dx; br<gx; br+=razm) {
        std::pair<double, double> par;
        par.first=br;
        par.second=f(br);
        a.push_back(par);
    }
    return LinearnaInterpolacija(a);
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int x;
    std::cin>>x;
    if(x==1) {
        std::cout << "Unesite broj cvorova: ";
        int y;
        std::cin >> y;
        std::vector<std::pair<double, double>> vektor;
        vektor.resize(y);

        std::cout << "Unesite cvorove kao parove x y: ";

        for(int i=0; i<y; i++) {
            double a, b;
            std::cin>>a>>b;
            vektor.at(i).second=b;
            vektor.at(i).first=a;

        }
        try {
            auto Formula(LinearnaInterpolacija(vektor));
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double a;
                try {
                    if(!(std::cin >>a)) break;
                    double rez(Formula(a));
                    std::cout << "f("<< a <<") = " << rez << std::endl;
                } catch(std::range_error p) {
                    std::cout << p.what() << std::endl;
                }
            }
        } catch(std::domain_error p) {
            std::cout << p.what() << std::endl;
        }


    } else if(x==2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double pocetak, kraj, korak;
        std::cin >>pocetak>>kraj>>korak ;
        try {
            auto f(LinearnaInterpolacija([](double x) {
                return x*x+std::sin(x);
            },pocetak,kraj,korak));
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double a;
                if(!(std::cin >>a)) break;
                try {
                    double rez(a*a+std::sin(a));
                    double rez_funkcije(f(a));
                    std::cout << "f("<< a <<") = " << rez<< " fapprox("<< a <<") = " << rez_funkcije << std::endl;
                } catch(std::range_error p) {
                    std::cout << p.what() << std::endl;
                }
            }
        } catch(std::domain_error p) {
            std::cout << p.what() << std::endl;
        }

    }

    return 0;
}
