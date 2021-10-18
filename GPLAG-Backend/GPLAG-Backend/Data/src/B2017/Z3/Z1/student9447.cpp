/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <functional>
#include <stdexcept>
#define eps 0.0000000000000001

function<double(double)> LinearnaInterpolacija (std::vector<pair<double,double>> tacke){
    for (int i(0);i<tacke.size()-1;i++){
        for (int j(0);j<tacke.size();j++){
            if (abs(tacke[i].first-tacke[j].first)<eps) throw std::domain_error ("Neispravni cvorovi");
        }
    }
}

int main ()
{
	return 0;
}
