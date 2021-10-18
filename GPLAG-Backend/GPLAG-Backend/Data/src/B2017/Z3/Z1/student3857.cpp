/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <math.h>


bool ProvjeriDuple (std::vector<std::pair<double,double>> v1)
{

    for (int i=0; i<v1.size(); i++) {
        for (int j=i+1; j<v1.size(); j++) {

            if (v1[i].first==v1[j].first) {

                return true;
            }
        }
    }

    return false;
}

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double,double>> &v1)
{

    std::sort (v1.begin(),v1.end());

    if (ProvjeriDuple(v1)) throw std::domain_error ("Neispravni cvorovi");

    return [v1] (double x) {

        if (x < v1[0].first || x>v1[v1.size()-1].first) throw std::range_error ("Argument izvan opsega");

        auto drugi (std::lower_bound(v1.begin(),v1.end(),x, [](std::pair<double,double> v1, double x) {

            return v1.first<x;

        }));

        auto prvi = (drugi-1);

        return prvi->second + (( (drugi->second - prvi-> second)) / (drugi->first - prvi->first))*(x-prvi->first) ;

    };
}

double ojhaj(double x)
{
    return x * x + std::sin(x);

}

std::function<double(double)>
LinearnaInterpolacija (double lopata (double),double xmin, double xmax, double deltax)
{

    if (xmin>xmax || deltax<0) throw std::domain_error ("Nekorektni parametri.");

    std::vector<std::pair<double,double>> v1;
    double a,b;
    std::pair<double,double> temp;
    double q = deltax;

    for (double i= xmin; i <=xmax; i+=q) {

        a = i;
        b = lopata(i);

        temp = std::make_pair(a,b);
        v1.push_back(temp);

    }

    std::sort(v1.begin(),v1.end());

    return [v1] (double x) {

        if (x < v1[0].first || x>v1[v1.size()-1].first) throw std::range_error ("Argument izvan opsega");

        auto drugi(std::lower_bound(v1.begin(),v1.end(),x, [](std::pair<double,double> v1, double x) {

            return v1.first<x;

        }));

        auto prvi = (drugi-1);

        return prvi->second + (( (drugi->second - prvi-> second)) / (drugi->first - prvi->first))*(x-prvi->first) ;


    };
}

void OcistiTok (int a)
{
    std::cin.clear();
    std::cin.ignore (10000,'\n');
}

double UnosParametara (double &broj)
{
    std::cin >> broj;
    char c = std::cin.peek();
    if (!std::cin || broj<0) {
        throw ("A");
        OcistiTok(1);
    }

}

int main ()
{

    while (true) {
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::vector<std::pair<double,double> > v1;
        int izbor;
        std::cin >> izbor;

        if (izbor == 1) {
            double a,b,c;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> c;

            std::cout << "Unesite cvorove kao parove x y: ";
            std::pair<double,double> temp;
            for (int i(0); i < c; i++) {

                std::cin >> a;
                std::cin >> b;

                temp = std::make_pair (a,b);

                v1.push_back (temp);


            }
            try {
                auto f (LinearnaInterpolacija(v1));

                for (;;) {
                    double arg;
                    std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";

                    try {
                        UnosParametara(arg);
                        std::cout << "f(" << arg <<")" << " = " << f(arg) << std::endl;
                    } catch(const std::range_error &e) {
                        std::cout << e.what() << std::endl;

                        continue;
                    }
                    catch(...) {
                        return 0;
                    }


                }
            } catch(const std::domain_error &e) {
                std::cout << e.what() << std::endl;
                return 0;
            } catch(const std::range_error &e) {
                std::cout << e.what() << std::endl;
                return 0;

            }
        } else if (izbor==2) {
            double a,b,c;
            std::cout << "Unesite krajeve intervala i korak: ";
            std::cin >> a >> b >>c;

            try {
                auto f1 (LinearnaInterpolacija(ojhaj,a,b,c));

                for (;;) {
                    double arg;
                    std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";

                    try {
                        UnosParametara(arg);
                        std::cout << "f(" << arg <<")" << " = " << ojhaj(arg) << " fapprox(" << arg << ") = " << f1(arg) << std::endl;
                    } catch(const std::range_error &e) {
                        std::cout << e.what() << std::endl;

                        continue;
                    }
                    catch(...) {
                        return 0;
                    }
                }
            } catch(const std::domain_error &e) {
                std::cout << e.what() << std::endl;
                return 0;

            } catch(const std::range_error &e) {
                std::cout << e.what() << std::endl;

            }
        }
    }
    return 0;
}
