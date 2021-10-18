/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <cmath>

template <typename Tip>
bool ImaIstih(const std::vector<std::pair<Tip, Tip>> &v)
{

    auto i(v.begin());
    auto j(v.begin());
    ++j;
    auto zadnji_clan(v.end());
    --zadnji_clan;
    Tip x;

    for(i; i != zadnji_clan; ++i) {
        x = i->first;
        for(j = i + 1; j != v.end(); ++j) {
            if(x == j->first) return true;
        }
    }

    return false;
}

template <typename Tip>
bool NeispravanX(double x, const std::vector<std::pair<Tip, Tip>> &v)
{

    auto it(v.begin());
    if(x < it->first) return true;

    it = v.end();
    --it;
    if(x > it->first) return true;

    return false;
}

bool slova_u_unosu(std::string s)
{

    for(int i(0); i<s.length(); ++i) {
        if(s[i] >= 'A' && s[i] <= 'Z') return true;
        if(s[i] >= 'a' && s[i] <= 'z') return true;
    }

    return false;
}

//template <typename Tip>
std::function<double(double)> LinearnaInterpolacija(const std::vector<std::pair<double, double>> &v)
{
    if(ImaIstih(v)) throw std::domain_error("Neispravni cvorovi");

    return [=](double x) {

        if(NeispravanX(x, v)) throw std::range_error("Nekorektni parametri");

        auto p = std::make_pair(x, 0.);

        auto xiyi(std::lower_bound(v.begin(), v.end(), p));
        --xiyi;
        auto xpiypi(std::lower_bound(v.begin(), v.end(), p));

        double Rezultat(xiyi->second + ((xpiypi->second - xiyi->second) / (xpiypi->first - xiyi->first)) * (x - xiyi->first));

        return Rezultat;
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltax)
{

    if(xmin > xmax || deltax <= 0) throw std::domain_error("Nekorektni parametri");

    std::vector<std::pair<double, double>> cvorovi;

    double cvor(0);
    for(double i(0); cvor < xmax; ++i) {

        double zbir_delte(0);
        for(int j(0); j<i; ++j) zbir_delte+=deltax;

        cvor = zbir_delte + xmin;

        auto par_za_vektor(std::make_pair(cvor, f(cvor)));
        cvorovi.emplace_back(par_za_vektor);
    }

    if(ImaIstih(cvorovi)) throw std::domain_error("Neispravni cvorovi");

    return [=](double x) {

        if(NeispravanX(x, cvorovi)) throw std::range_error("Nekorektni parametri");

        auto p = std::make_pair(x, 0.);

        auto xiyi(std::lower_bound(cvorovi.begin(), cvorovi.end(), p));
        --xiyi;
        auto xpiypi(std::lower_bound(cvorovi.begin(), cvorovi.end(), p));

        double Rezultat(xiyi->second + ((xpiypi->second - xiyi->second) / (xpiypi->first - xiyi->first)) * (x - xiyi->first));

        return Rezultat;
    };
}

int main ()
{
    try {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int unos;
        std::cin>>unos;

        if(unos == 1) {
            std::cout<<"Unesite broj cvorova: ";
            int broj_cvorova;
            std::cin>>broj_cvorova;
            std::vector<std::pair<double, double>> vektor_parova(broj_cvorova);

            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i(0); i<broj_cvorova; ++i) {

                int x, y;
                std::cin>>x>>y;

                auto par = std::make_pair(x,y);
                vektor_parova[i] = par;
            }

            //Sortiraj
            std::sort(vektor_parova.begin(), vektor_parova.end(), [](const std::pair<double, double> &p1, const std::pair<double, double> &p2) {
                return p1<p2;
            });

            std::cin.ignore(10000, '\n');
            auto f(LinearnaInterpolacija(vektor_parova));
            for(;;) {

                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::string unesi;
                getline(std::cin, unesi);

                double x;
                if(slova_u_unosu(unesi)) break;

                x = std::stod(unesi);

                std::cout<<"f("<<x<<") = "<<f(x)<<std::endl;
            }
        } else if(unos == 2) { //DRUGA OPCIJA---------------------------------------------------------------------------

            std::cout<<"Unesite krajeve intervala i korak: ";
            double x1, x2, dx;
            std::cin>>x1>>x2>>dx;
            auto f(LinearnaInterpolacija([](double x) {
                return std::pow(x, 2) + std::sin(x);
            }, x1, x2, dx));
            std::cin.ignore(10000, '\n');
            for(;;) {
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::string unos;
                getline(std::cin, unos);
                if(slova_u_unosu(unos)) break;
                double argument;
                argument = std::stod(unos);
                if(argument < x1 || argument> x2) {
                    std::cout<<"Argument izvan opsega"<<std::endl;
                    continue;
                }
                std::cout<<"f("<<argument<<") = "<<std::pow(argument, 2) + std::sin(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl;
            }
        }
    } catch(std::domain_error e) {
        std::cout<<e.what();
    } catch(std::range_error e) {
        std::cout<<e.what();
    }
    
    return 0;
}