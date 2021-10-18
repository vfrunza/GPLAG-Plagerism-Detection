/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <cmath>

bool JesuLiJednaki(double x, double y, double Eps = 1e-10) //funkcija kojom poredimo jednakost dva broja tipa double
{
    return ( std::fabs(x-y) <= Eps*(std::fabs(x)+std::fabs(y)) );
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> cvorovi)
{
    bool sortiran(1);
    for(int i=0; i<int(cvorovi.size()); i++) {
        for(int j=i+1; j<int(cvorovi.size()); j++) {
            if(cvorovi.at(i).first > cvorovi.at(j).first) sortiran=false;
            if(JesuLiJednaki(cvorovi.at(i).first, cvorovi.at(j).first)) throw std::domain_error("Neispravni cvorovi");
        }
    }
    if(!sortiran) {
        std::sort(cvorovi.begin(), cvorovi.end(), [](std::pair<double, double> p1, std::pair<double, double> p2) {
            return p1.first<p2.first;
        });
    }


    return [cvorovi](double x) {
        double f(0);
        double X1, Xn, Yn;
        int velicina(cvorovi.size());
        X1 = cvorovi.at(0).first;
        Xn = cvorovi.at(velicina-1).first;
        Yn = cvorovi.at(velicina-1).second;
        if(JesuLiJednaki(x, Xn)) return Yn;
        if(x<X1 || x>Xn) throw std::range_error("Argument izvan opsega");
        for(int i=0; i<velicina; i++) {
            if(JesuLiJednaki(x, cvorovi.at(i).first)) return cvorovi.at(i).second; //da se u fiji upper_bound gleda samo prvi clan
        }
        double Xi, Xi1;  //interval od x
        double Yi, Yi1;
        std::pair<double, double> p(x, 1); //da bi u fiji upper_bound mogli vrsiti poredjenje, moramo poslati objekat tipa pair(1 je slucajna vrijednost)

        auto it(std::upper_bound(cvorovi.begin(), cvorovi.end(), p));


        Xi1 = (*it).first;
        Yi1 = (*it).second;
        it--;
        Xi = (*it).first;
        Yi = (*it).second;

        f = Yi + ((Yi1-Yi)/(Xi1-Xi))*(x-Xi);
        return f;
    };
}


std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f,double Xmin,double Xmax,double DX)
{
    std::vector<std::pair<double, double>> cvorovi;
    if(Xmin > Xmax || DX<=0) throw std::domain_error("Nekorektni parametri");
    int velicina(Xmax/DX);
    for(int i=0; i<velicina; i++) {
        cvorovi.push_back(std::make_pair(Xmin + i*DX, f(Xmin + i*DX)));
    }
    return [cvorovi](double x) {
        double f(0);
        double X1, Xn, Yn;
        int velicina(cvorovi.size());
        X1 = cvorovi.at(0).first;
        Xn = cvorovi.at(velicina-1).first;
        Yn = cvorovi.at(velicina-1).second;
        if(JesuLiJednaki(x, Xn)) return Yn;
        if(x<X1 || x>Xn) throw std::range_error("Argument izvan opsega");
        for(int i=0; i<velicina; i++) {
            if(JesuLiJednaki(x, cvorovi.at(i).first)) return cvorovi.at(i).second; //da se u fiji upper_bound gleda samo prvi clan
        }
        double Xi, Xi1;  //interval od x
        double Yi, Yi1;
        std::pair<double, double> p(x, 1); //da bi u fiji upper_bound mogli vrsiti poredjenje, moramo poslati objekat tipa pair(1 je slucajna vrijednost)

        auto it(std::upper_bound(cvorovi.begin(), cvorovi.end(), p));

        Xi1 = (*it).first;
        Yi1 = (*it).second;
        it--;
        Xi = (*it).first;
        Yi = (*it).second;

        f = Yi + ((Yi1-Yi)/(Xi1-Xi))*(x-Xi);
        return f;
    };
}


int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    double testni;
    bool unos_cvorova(0), aproksimacija(0);
    for(;;) {
        std::cin>>testni;
        if(std::cin) {
            if(JesuLiJednaki(testni, 1)) {
                unos_cvorova = true;
                break;
            } else if(JesuLiJednaki(testni,2)) {
                aproksimacija = true;
                break;
            } else std::cout<<"Neispravan unos! Unesite ponovo: ";
        } else {
            std::cout<<"Neispravan unos! Unesite ponovo: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }
    try {
        if(unos_cvorova) {
            int br_cvorova;
            std::cout<<"Unesite broj cvorova: ";
            std::cin>>br_cvorova;
            if(br_cvorova<0) return 0;
            std::vector<std::pair<double, double>> c(br_cvorova);
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<br_cvorova; i++) {
                std::cin>>c.at(i).first>>c.at(i).second;
            }
            try {
                auto f(LinearnaInterpolacija(c));
                for(;;) {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double x;
                    std::cin>>x;
                    if(std::cin) {
                        try {
                            std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
                        } catch(std::range_error izuzetak) {
                            std::cout<<izuzetak.what()<<std::endl;
                        }
                    } else break;
                }
            } catch(...) {
                throw;
            }
        } else if(aproksimacija) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double min, max, d;
            std::cin>>min>>max>>d;
            std::function<double(double)> funkcija([](double x) {
                return x*x + std::sin(x);
            });
            try {
                auto f(LinearnaInterpolacija(funkcija, min, max, d));
                for(;;) {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double x;
                    std::cin>>x;
                    if(std::cin) {
                        try {
                            std::cout<<"f("<<x<<") = "<<funkcija(x)<<" fapprox("<<x<<") = "<<f(x)<<std::endl;
                        } catch(std::range_error izuzetak) {
                            std::cout<<izuzetak.what()<<std::endl;
                        }
                    } else  break;
                }
            } catch(...) {
                throw;
            }
        }
    }  catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}
