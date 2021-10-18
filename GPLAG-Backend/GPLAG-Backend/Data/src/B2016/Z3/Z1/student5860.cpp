/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdexcept>

//druga formula u postavci
double tezinskiKoeficijent (std::vector<std::pair<double, double>> cvoroviInterpolacije, int i, int d, int n) {
    double suma(0);
    //suma u drugoj formuli u postavci
    for(int k = std::max(0, i-d-1); k < std::min(i, n-d); k++) { //umjesto 1 u max funkciji stavio sam 0, jer odatle pocinju nizovi. moguce da treba i ostale pomjeriti
        double proizvod(1);
        //Proizvod u drugoj formuli u postavci
        for(int j = k; j < k + d; j++) {
            if(j == i) continue;
            proizvod *= (cvoroviInterpolacije.at(i).first - cvoroviInterpolacije.at(j).first);
        }
        suma += ((k%2) ? -1 : 1) * (1 / proizvod);
    }
    return suma;
}
std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>> cvoroviInterpolacije, int redInterpolacije) {
    if(redInterpolacije < 0 || cvoroviInterpolacije.size() < redInterpolacije) throw std::domain_error("Nedozvoljen red");
    for(int i = 0; i < cvoroviInterpolacije.size(); i++)
        for(int j = i + 1; j < cvoroviInterpolacije.size(); j++)
            if(cvoroviInterpolacije.at(i).first == cvoroviInterpolacije.at(j).first) throw std::domain_error("Neispravni cvorovi");
    //prva formula u postavci
    return [=](double x) {
        double brojnik(0), nazivnik(0);
        for(int i = 0; i < cvoroviInterpolacije.size(); i++) {
            //dvije sume u formuli. Mogu u istu petlju
            brojnik += tezinskiKoeficijent(cvoroviInterpolacije, i, redInterpolacije, cvoroviInterpolacije.size()) / (x - cvoroviInterpolacije.at(i).first) * cvoroviInterpolacije.at(i).second;
            nazivnik += tezinskiKoeficijent(cvoroviInterpolacije, i, redInterpolacije, cvoroviInterpolacije.size()) / (x - cvoroviInterpolacije.at(i).first);
        }
        return brojnik / nazivnik;
    };
}

int main () {
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int odabir;
    std::cin >> odabir;
    try {
        if(odabir == 1) {
            std::cout << "Unesite broj cvorova: ";
            int brojCvorova;
            std::cin >> brojCvorova;
            std::cout << "Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> cvoroviInterpolacije(0);
            for(int i = 0; i < brojCvorova; i++) {
                std::pair<int, int> pom;
                std::cin >> pom.first >> pom.second;
                cvoroviInterpolacije.push_back(pom);
            }
            std::cout << "Unesite red interpolacije: ";
            int redInterpolacije;
            std::cin >> redInterpolacije;
            auto fun(BaricentricnaInterpolacija(cvoroviInterpolacije, redInterpolacije));
            for(;;) {
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin >> argument;
                if(!std::cin) break;
                std::cout << "f(" << argument << ") = " << fun(argument) << "\n";
            }
        } 
        if(odabir == 2) {
            std::cout << "Unesite krajeve intervala i korak: ";
            double korak, 
        }
    }catch(std::domain_error e){
        std::cout << e.what();
    }
    return 0;
}