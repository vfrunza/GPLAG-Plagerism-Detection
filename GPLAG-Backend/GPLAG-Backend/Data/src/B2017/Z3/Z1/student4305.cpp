/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
#include <stdexcept>

std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double, double>> cvorovi) {
    //provjera da li je pravilno sortiran vektor i ima li onih sa istim x
    bool sortiran = true;
    for (int i = 0 ; i < cvorovi.size() ; i++) {
        for (int j = i + 1 ; j < cvorovi.size() ; j++) {
            if (cvorovi.at(i).first < cvorovi.at(j).first)
                sortiran = false;
            else if (cvorovi.at(i).first == cvorovi.at(j).first)
                throw std::domain_error ("Neispravni cvorovi");
        }
    }
    //ako nije sortiran kako treba, potrebno je sortirati
    if (!sortiran)
        std::sort(cvorovi.begin(), cvorovi.end(), [](std::pair<double, double> a, std::pair<double, double> b){
            return a.first < b.first;
        });
        
    auto fun = [cvorovi](double x) {
        std::pair<double, double> posljednjiPar = cvorovi.at(cvorovi.size() - 1);
        if (x < cvorovi.at(0).first || x > posljednjiPar.first)
            throw std::range_error ("Argument izvan opsega");
        else if (x == posljednjiPar.first)
            return posljednjiPar.second;
        
        //pronaci u kojem je intervalu x koje je ovdje primljeno i izvsiti interpolaciju
        //ovo ce vratiti prvi Xi+1, pa uradimo par-- za Xi
        auto par2 = std::find_if(cvorovi.begin(), cvorovi.end(), [x](std::pair<double, double> a) {
            return x < a.first;
        });
        auto par1 = par2 - 1;
        double rezultat = par1->second + (x - par1->first) * (par2->second - par1->second) / (par2->first - par1->first);
        return rezultat;
    };
    return fun;
}

std::function<double(double)> LinearnaInterpolacija (std::function<double(double)> funkcija, double Xmin, double Xmax, double Dx) {
    if (Xmin > Xmax || Dx <= 0)
        throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double, double>> cvorovi;
    for (double x = Xmin ; x <= Xmax ; x += Dx) {
        double y = funkcija(x);
        cvorovi.push_back({x, y});
    }
    return LinearnaInterpolacija(cvorovi);
}

double testFun(double x) {
    return x * x + std::sin(x);
}

int main ()
{
    try {
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin >> opcija;
        if (opcija == 1) {
            std::cout << "Unesite broj cvorova: ";
            int brojCvorova;
            std::cin >> brojCvorova;
            
            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> cvorovi(brojCvorova);
            for (int i = 0 ; i < brojCvorova ; i++)
                std::cin >> cvorovi.at(i).first >> cvorovi.at(i).second;
                
            auto funkcija = LinearnaInterpolacija(cvorovi);
            
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            while (std::cin >> argument) {
                try {
                    std::cout << "f(" << argument << ") = " << funkcija(argument) << std::endl;
                } catch (std::range_error e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
        }
        else if (opcija == 2) {
            std::cout << "Unesite krajeve intervala i korak: ";
            double Xmin, Xmax, Dx;
            std::cin >> Xmin >> Xmax >> Dx;
            
            auto funkcija = LinearnaInterpolacija(testFun, Xmin, Xmax, Dx);
            
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            double argument;
            while (std::cin >> argument) {
                try {
                    std::cout << "f(" << argument << ") = " << testFun(argument) << " fapprox(" << argument << ") = "  << funkcija(argument) << std::endl;
                } catch(std::range_error e) {
                    std::cout << e.what() << std::endl;
                }
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }
        }
    } catch(std::domain_error e) {
        std::cout << e.what() << std::endl;
    } catch(std::range_error e) {
        std::cout << e.what() << std::endl;
    }
    
	return 0;
}
