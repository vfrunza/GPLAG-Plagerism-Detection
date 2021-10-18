/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cmath>

bool cmp(std::pair<double, double> A, std::pair<double, double> B)
{
    return std::fabs(A.first - B.first) < 0.00001*(std::fabs(A.first) + std::fabs(B.first));
}
bool JesuLiJednaki(double a, double b)
{
    return std::fabs(a - b) <= 0.0000001*(std::fabs(a) + std::fabs(b));
}
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> &cvorovi)
{
    std::sort(cvorovi.begin(), cvorovi.end(), cmp);

    for(int i=0; i<cvorovi.size(); i++) {
        for(int j=i+1; j<cvorovi.size(); j++) {
            if(cvorovi[i].first == cvorovi[j].first)
                throw std::domain_error("Neispravni cvorovi");
        }
    }

    return [&cvorovi](double x) {
        auto min(cvorovi[0]), max(cvorovi[cvorovi.size()-1]);
        if(x < min.first) throw std::range_error("Argumenti izvan opsega");
        if(x > max.first) throw std::range_error("Argumenti izvan opsega");
        int xi1_1 = std::lower_bound(cvorovi.begin(), cvorovi.end(), std::pair<double, double>(x,0.)) - cvorovi.begin();
        int xi_1 = std::upper_bound(cvorovi.begin(), cvorovi.end(), std::pair<double, double>(x,0.)) - cvorovi.begin()-1;
        if(xi_1==-1) {
            xi_1=0;
            xi1_1=1;
        }
        return cvorovi[xi_1].second + ((cvorovi[xi1_1].second - cvorovi[xi_1].second)*(x - cvorovi[xi_1].first))/(cvorovi[xi1_1].first - cvorovi[xi_1].first);
    };

}

double funkcija(double x)
{
    return x*x + std::sin(x);
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> funkcija, double &xmin, double &xmax, double &xdelta)
{

    if(xmin>xmax || xdelta<=0) throw std::domain_error("Nekorektni parametri");
    
    

    return [&xmin, &xmax, &xdelta, &funkcija](double x) {

        std::vector<std::pair<double, double>> cvorovi;

        
        int i(0);
        while(xmin + i*xdelta <= xmax) {
            cvorovi.push_back(std::make_pair(xmin + i*xdelta, funkcija(xmin + i*xdelta)));
            i++;
        }
        if(JesuLiJednaki(x, xmin) || x < xmin) throw std::range_error("Argument izvan opsega");
        if(JesuLiJednaki(x, xmax) || x > xmax) throw std::range_error("Argument izvan opsega");
        int xi1_1 = std::lower_bound(cvorovi.begin(), cvorovi.end(), std::pair<double, double>(x,0.)) - cvorovi.begin();
        int xi_1 = std::upper_bound(cvorovi.begin(), cvorovi.end(), std::pair<double, double>(x,0.)) - cvorovi.begin()-1;
        if(xi_1==-1) {
            xi_1=0;
            xi1_1=1;
        }
        return cvorovi[xi_1].second + ((cvorovi[xi1_1].second - cvorovi[xi_1].second)*(x - cvorovi[xi_1].first))/(cvorovi[xi1_1].first - cvorovi[xi_1].first);
    };
}

int main ()
    try {

        std::vector<std::pair<double,double>> cvorovi;
        int broj_cvorova(0);
        int izbor(0);
        double min, max, korak;

        while(izbor!=2 || std::cin.ignore()) {
            std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";

            std::cin>>izbor;

            if(izbor==1) {
                std::cout<<"Unesite broj cvorova: ";
                std::cin>>broj_cvorova;
                std::cout<<"Unesite cvorove kao parove x y: ";

                for(int i=0; i<broj_cvorova; i++) {
                    std::pair<double, double> cvor;
                    double x,y;
                    std::cin>>x;
                    std::cin>>y;
                    cvor = std::make_pair(x,y);
                    cvorovi.push_back(cvor);
                }
                while(1) {
                    bool uhvacen(false);
                    std::function<double(double)> f;
                    try {
                        f=LinearnaInterpolacija(cvorovi);
                    } catch(std::range_error izuzetak2) {
                        uhvacen=true;
                        std::cout<<izuzetak2.what()<<std::endl;
                    }
                    if(!uhvacen) {
                        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                        double argument;
                        std::cin>>argument;
                        if(!std::cin) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            return 0;
                        }

                        std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
                    }
                }
            }

            else if(izbor==2) {

                bool uhvacen1(true);
                while(uhvacen1) {
                    uhvacen1=false;
                    std::cout<<"Unesite krajeve intervala i korak: ";
                    std::cin>>min;
                    std::cin>>max;
                    std::cin>>korak;
                    try {
                        std::function<double(double)> fja(LinearnaInterpolacija(funkcija, min, max, korak));
                    } catch(std::domain_error d_izuzetak) {
                        uhvacen1=true;
                        std::cout<<d_izuzetak.what()<<std::endl;
                    }
                }
                while(1) {
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    std::cin>>argument;

                    if(!std::cin) {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        return 0;
                    }
                    std::function<double(double)> fja(LinearnaInterpolacija(funkcija, min, max, korak));
                    bool uhvacen(false);
                    double nesto;
                    try {
                        nesto=fja(argument);
                    } catch(std::range_error izuzetak) {
                        uhvacen=true;
                        std::cout<<izuzetak.what()<<std::endl;
                    }
                    if(!uhvacen) {
                        std::cout<<"f("<<argument<<") = "<<funkcija(argument);
                        std::cout<<" fapprox("<<argument<<") = "<<nesto<<std::endl;
                    }
                }

            }
        }
    } catch(std::domain_error d_izuzetak) {
        std::cout<<d_izuzetak.what()<<std::endl;
    } catch(...) {
    }
    return 0;
}
