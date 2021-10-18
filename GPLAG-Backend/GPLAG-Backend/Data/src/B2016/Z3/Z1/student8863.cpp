#include <iostream>
#include <stdexcept>
#include <functional>
#include <utility>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;

std::vector<double> TezinskiKoeficijent(std::vector<std::pair<double, double>> cvorovi_interpolacije, int d){
    std::vector<double> tezinski_koeficijent(cvorovi_interpolacije.size());
    for(int i = 0; i < cvorovi_interpolacije.size(); i++){
        int gornja(cvorovi_interpolacije.size() - d), donja(1);
        if(gornja > i + 1) gornja = i + 1;
        if(donja < i - d + 1) donja = i - d + 1;
        for(int k = donja; k <= gornja; k++){
            double proizvod(1);
            for(int j = k; j <= k + d; j++){
                if(j != i + 1) proizvod *= 1/(cvorovi_interpolacije[i].first - cvorovi_interpolacije[j - 1].first);
            }
            tezinski_koeficijent[i] += pow(-1, k - 1) * proizvod;
        }
    }
    return tezinski_koeficijent;
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double, double>> cvorovi_interpolacije, int d){
    if(!(d >= 0 && d <= cvorovi_interpolacije.size())) throw std::domain_error("Nedozvoljen red");
    std::vector<double> tezinski_koeficijent(TezinskiKoeficijent(cvorovi_interpolacije, d));
    return[=](double x){
        double suma1(0), suma2(0);
        for(int i = 0; i < cvorovi_interpolacije.size(); i++){
            if(x == cvorovi_interpolacije[i].first) return cvorovi_interpolacije[i].second;
            suma1 += tezinski_koeficijent[i] / (x - cvorovi_interpolacije[i].first);
            suma2 += cvorovi_interpolacije[i].second * tezinski_koeficijent[i] / (x - cvorovi_interpolacije[i].first);
        }
        return suma2/suma1;
    };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> fun, double xmin, double xmax, double deltaX, int d){
    if(xmin > xmax || deltaX <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> tacke;
    while(xmin <= xmax){
        std::pair<double, double> privremeni;
        privremeni.first = xmin;
        privremeni.second = fun(xmin);
        tacke.push_back(privremeni);
        xmin += deltaX;
    }
    std::vector<double> tezinski_koeficijent(TezinskiKoeficijent(tacke, d));
    return[=](double x){
        double suma1(0), suma2(0);
        for(int i = 0; i < tacke.size(); i++){
            if(x == tacke[i].first) return tacke[i].second;
            suma1 += tezinski_koeficijent[i] / (x - tacke[i].first);
            suma2 += tacke[i].second * tezinski_koeficijent[i] / (x - tacke[i].first);
        }
        return suma2/suma1;
    };
}

int main ()
{
   /* cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int unos;
    cin >> unos;
    switch(unos){
        case 1 :
            int broj_cvorova;
            cout << "Unesite broj cvorova: ";
            cin >> broj_cvorova;
            std::vector<std::pair<double, double>> cvorovi(broj_cvorova);
            cout << "Unesite cvorove kao parove x y: ";
            for(auto &x : cvorovi){
                cin >> x.first;
                cin >> x.second;
            }
            cout << "Unesite red interpolacije: ";
            int d;
            cin >> d;
            std::string tacke;
            cout << "Unesite argument(ili ""kraj"" za kraj"
            
    } */
    return 0;
}