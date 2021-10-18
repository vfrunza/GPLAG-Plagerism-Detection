#include <iostream>
#include <stdexcept>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <type_traits>
#include <string>
#include <iomanip>
#include <functional>

double napraviW(std::vector<std::pair<double, double>> parovi, int d, int i){ // saljem vektorparova, d i (i+1)
    int max(1);
    if(i-d > 1) max = i-d;
    int min = i;
    if(parovi.size()-d < i) min = parovi.size()-d;
    double Wi(0);
    while(max <= min){
        double faktor = pow(-1, max-1), mnozilac(1);
        for(int j = max-1; j < max+d; j++){
            if(j == i-1) continue;
            mnozilac *= (1/(parovi[i-1].first - parovi[j].first));
        }
        Wi += faktor * mnozilac;
        max++;
    }
    return Wi;
}

void testirajXKoordinate(std::vector<std::pair<double, double>> parovi){
    for(int i(0); i < parovi.size(); i++)
        for(int j = i+1; j < parovi.size(); j++)
            if(parovi[i].first == parovi[j].first) throw std::domain_error("Neispravni cvorovi");
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> parovi, int d){
    if(d < 0 || d > parovi.size()) throw std::domain_error("Nedozvoljen red");
    testirajXKoordinate(parovi);
    std::vector<double> w;
    for(int i(0); i < parovi.size(); i++){
        w.push_back(napraviW(parovi, d, i+1));
    }
    return ([parovi, d, w](double x){
        for(int i(0); i < parovi.size(); i++)
            if(x == parovi[i].first) return parovi[i].second;
        double brojnik(0), nazivnik(0);
        for(int i(0); i < parovi.size(); i++){
            brojnik += (w[i] / (x - parovi[i].first)) * parovi[i].second;
            nazivnik += (w[i] / (x - parovi[i].first));
        }
        return brojnik / nazivnik;
    });
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun, double x_min, double x_max, double delta_x, int d){
    if(x_min > x_max || delta_x <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> parovi;
    {
        double first = x_min;
        while(first <= x_max){
            std::pair<double, double> tmp;
            tmp.first = first; tmp.second = fun(first);
            parovi.push_back(tmp);
            first += delta_x;
        }
    }
    return ([parovi, d](double x){
        return BaricentricnaInterpolacija(parovi, d)(x);
    });
}

bool nijeBroj(std::string ulaz){
    int i(0);
    while(i < ulaz.length() && ulaz[i] == ' ') i++;
    if(i < ulaz.length() && ulaz[i] != ' '){
        if(ulaz[i] == '-' || ulaz[i] == '+') i++;
        if(ulaz[i] >= '0' && ulaz[i] <= '9'){
            while(i < ulaz.length() && ulaz[i] >= '0' && ulaz[i] <= '9') i++;
            if(i < ulaz.length() && ulaz[i] == '.'){
                 i++;
                 if(i < ulaz.length() && ulaz[i] >= '0' && ulaz[i] <= '9'){
                    while(i < ulaz.length() && ulaz[i] >= '0' && ulaz[i] <= '9')i++;
                    if(i < ulaz.length() && ulaz[i] != ' ') return true;
                    else {
                        while(i < ulaz.length() && ulaz[i] == ' ') i++;
                        if(i < ulaz.length()) return true;
                    }
                 }
            }
            else if(i < ulaz.length() && ulaz[i] != ' ') return true;
            else {
                while(i < ulaz.length() && ulaz[i] == ' ') i++;
                if(i < ulaz.length()) return true;
            }
        }
        else return true;
    }
    return false;
}

void prvaFunkcija(){
    std::cout << "Unesite broj cvorova: ";
    int br_cvorova; std::cin >> br_cvorova;
    std::cout << "Unesite cvorove kao parove x y: ";
    std::vector<std::pair<double, double>> parovi;
    for(int i(0); i < br_cvorova; i++){
        std::pair<double, double> tmp;
        std::cin >> tmp.first >> tmp.second;
        parovi.push_back(tmp);
    }
    std::cout << "Unesite red interpolacije: ";
    int d; std::cin >> d;
    std::cin.ignore(10000, '\n');
    while(true){
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::string unos;
        std::getline(std::cin, unos);
        if(nijeBroj(unos)) return;
        else for(char c: unos){
            if((c < '0' || c > '9') && c != '.' && c != '-') return;
        }
        double temp = ::atof(unos.c_str());
        std::cout << "f(" << temp << ") = " << BaricentricnaInterpolacija(parovi, d)(temp) << std::endl;
    }
}

void drugaFunkcija(){
    std::cout << "Unesite krajeve intervala i korak: ";
    double x_min, x_max, delta_x;
    std::cin >> x_min >> x_max >> delta_x;
    std::cout << "Unesite red interpolacije: ";
    int d; std::cin>> d;
    std::cin.ignore(10000, '\n');
    while(true){
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::string unos;
        std::getline(std::cin, unos);
        if(nijeBroj(unos)) return;
        else for(char c: unos){
            if((c < '0' || c > '9') && c != '.' && c != '-') return;
        }
        double temp = ::atof(unos.c_str());
        std::cout << "f(" << temp << ") = " << temp*temp + std::sin(temp) << " " << "fapprox(" << temp << ") = " << BaricentricnaInterpolacija([](double x){
            return x*x + std::sin(x);
        }, x_min, x_max, delta_x, d)(temp) << std::endl;
    }
}

int main (){
    while(true){
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int unos;
        std::cin >> unos;
        try{
            switch(unos){
                case 1:
                    prvaFunkcija();
                    return 0;
                case 2:
                    drugaFunkcija();
                    return 0;
            }
        }
        catch(std::domain_error izuzetak){
            std::cout << std::endl << izuzetak.what();
            return 0;
        }
    }
	return 0;
}













