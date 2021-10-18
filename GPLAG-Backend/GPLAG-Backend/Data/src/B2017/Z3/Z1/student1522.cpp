/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <cmath>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> v)
{
    //Trebamo pronaci vrijednost Xi <= X < Xi+1
    //Sto cemo obaviti uz pomoc funkcija iz algoritma
    //Prvo trebamo sortirati primljeni vektor
    std::sort(v.begin(), v.end());
    //Provjeravamo da li postoje cvorovi sa jednakim x-koordinatama, te u tom slucaju bacamo izuzetak
    for(int i(0); i < v.size()-1; i++) {
        if(v[i].first == v[i+1].first) throw std::domain_error ("Neispravni cvorovi");
    }
    // if(it != v.end()) throw std::domain_error("Neispravni cvorovi");

    //vracamo funkciju koja u biti obavlja sav posao
    return [v] (double arg) {
        //Provjeravamo da li je arg van opsega
        if(v.empty() || v[0].first > arg || arg > v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
        //Ako je argument jednak x-koordinati posljednjeg clana
        if(arg == v[v.size()-1].first) return v[v.size()-1].second;
        std::pair<double, double> temp(arg, 0);
        auto it(std::lower_bound(v.begin(), v.end(), temp));
        std::pair<double, double> par1(0, 0);
        std::pair<double, double> par2(0, 0);
        if(it == v.begin()){
            par1 = *it;
            it += 1;
            par2 = *it;
            return par2.second + ((par1.second - par2.second) / (par1.first - par2.first)) * (arg - par2.first);
        }
        else {
            par2 = *it;
            it -= 1;
            par1 = *it;
            return par2.second + ((par1.second - par2.second) / (par1.first - par2.first)) * (arg - par2.first);
        }
        /*auto par2(*it);
        if(it != v.begin()) it-=1;
        auto par1(*it);
        //Ako je argument manji od x-koordinate prvog clana ili argument veci od x-koordinate zadnjeg clana
        //bacamo izuzetak
        //if(arg < par1.first || arg > v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
        return par2.second + ((par1.second - par2.second) / (par1.first - par2.first)) * (arg - par2.first);
        */
    };

}

double fun(double arg)
{
    return arg * arg + std::sin(arg);
}

std::function<double(double)> LinearnaInterpolacija(double(double), double x_min, double x_max, double delta_x)
{
    if(x_min > x_max || delta_x <= 0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double, double>> v {};
    std::pair<double, double> temp {};
    int br(0);
    while(temp.first <= x_max) {
        temp.first = x_min + (br * delta_x);
        temp.second = fun(x_min + (br * delta_x));
        v.push_back(temp);
        br++;
    }

    //Radimo isti posao kao i sa prvom funkcijom
    //Prvo sortiramo i provjeravamo da li ima istih cvorova
    std::sort(v.begin(), v.end());
    auto it(std::unique(v.begin(), v.end()));
    if(it != v.end()) throw std::domain_error("Neispravni cvorovi");

    //Vracamo funkciju koja obavlja interpolaciju
    return [v] (double arg) {
        //Ako je argument jednak x-koordinati prvog clana vracamo y-koordinatu posljednjeg para
        //Provjeravamo da li idemo van opsega
        if(v.empty() || v[0].first > arg || arg > v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
        if(arg == v[v.size()-1].first) return v[v.size()-1].second;
        std::pair<double, double> temp (arg, 0);
        auto it(std::lower_bound(v.begin(), v.end(), temp));
        std::pair<double, double> par1(0, 0);
        std::pair<double, double> par2(0, 0);
        if(it == v.begin()) {
            par1 = *it;
            it += 1;
            par2 = *it;
            return par2.second + ((par1.second - par2.second) / (par1.first - par2.first)) * (arg - par2.first);
        }
        else{
            par2 = *it;
            it -= 1;
            par1 = *it;
            return par2.second + ((par1.second - par2.second) / (par1.first - par2.first)) * (arg - par2.first);
        }
        
        /*auto par2(*it);
        if(it != v.begin()) it-=1;
        auto par1(*it);
        //if(arg < par1.first || arg > v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
        return par2.second + ((par1.second - par2.second) / (par1.first - par2.first)) * (arg - par2.first);
        */
    };

}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int trigger(0);
    std::cin >> trigger;
    std::vector<std::pair<double, double>> v {};
    //Ako zelimo unijeti cvorove
    if(trigger == 1) {
        std::cout << "Unesite broj cvorova: ";
        int br_cvorova(0);
        std::cin >> br_cvorova;
        std::cout << "Unesite cvorove kao parove x y: ";
        //Petlja kojom unosimo elemente cvorova, koje zatim guramo u jedan vektor
        std::function<double(double)> f {};
        for(int i(0); i < br_cvorova; i++) {
            std::pair<double, double> temp;
            std::cin >> temp.first >> temp.second;
            v.push_back(temp);
        }
        try {
            f = LinearnaInterpolacija(v);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what();
            return 0;
        }
        //Unosimo argumente i pozivamo prvi tip funkcije "LinearnaInterpolacija"
        //sve dok se ne unese nešto što nije broj
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        double argument(0);
        while(std::cin >> argument) {
            //Poziv funkcije
            //Inicijalizacija funkcije
            try {
                std::cout << "f(" << argument << ") = " << f(argument);
            } catch(std::range_error izuzetak) {
                std::cout << izuzetak.what();
                //return 0;
            }
            std::cout << std::endl << "Unesite argument (ili \"kraj\" za kraj): ";
        }
    } else if(trigger == 2) {
        std::cout << "Unesite krajeve intervala i korak: ";
        double x_min(0), x_max(0), delta_x(0);
        std::cin >> x_min >> x_max >> delta_x;
        std::function<double(double)> f1 {};
        try {
            f1 = LinearnaInterpolacija(fun, x_min, x_max, delta_x);
        } catch(std::domain_error izuzetak) {
            std::cout << izuzetak.what();
            return 0;
        } catch(...) {
            std::cout << "Neispravni cvorovi";
            return 0;
        }

        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        double argument(0);
        while(std::cin >> argument) {
            try {
                std::cout << "f(" << argument << ") = " << fun(argument) << " fapprox(" << argument << ") = " << f1(argument);
            } catch(std::range_error izuzetak) {
                std::cout << izuzetak.what();
                //return 0;
            }
            std::cout << std::endl << "Unesite argument (ili \"kraj\" za kraj): ";
        }

    }

    return 0;
}
