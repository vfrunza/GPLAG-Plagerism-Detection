/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <functional>

// funcucija koja vfaca funkciju????????????????? ok

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> v_par) {
    std::sort(v_par.begin(), v_par.end());
    for(int i(0); i<v_par.size(); i++) {
        for(int j(i+1); j<v_par.size(); j++) {
            if(v_par.at(i).first==v_par.at(j).first) throw std::domain_error ("Neispravni cvorovi");
    }
    /*for(int i(0); i<v_par.size(); i++) {
        f = v_par.at(i).second + ((v_par.at(i+1).second - v_par.at(i).second)/(v_par.at(i+1).first - v_par.at(i)))(x - v_par.at(i).first)     
        yi+1 - yi / xi+1 -xi * (x-xi) xa
        xa
        xa
        xaxa
        xaxaax
        ax
        axa
        xaxaaxa
        xaxax
        axa
        xax
        axa
        xax
        ax*/
        
    }
    return []
}



int main ()
{
	return 0;
}
