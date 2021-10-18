//B 2016/2017, Zadaća 1, Zadatak 3
#include <iostream>
#include <vector>
#include <cmath>

const double eps{1e-10};
typedef std::vector<std::vector<double>> Matrica_inc;

bool JeSuLiJednaki (double x, double y) {
    return std::fabs(x-y) <= eps * (std::fabs(x) + std::fabs(y));
}

Matrica_inc RastuciPodnizovi (std::vector<double> vektor)
{
    Matrica_inc rastuci_podnizovi;
    
    if (vektor.size() >= 2)
    for (int i=0; i<vektor.size()-1; ++i) {
        bool postoji_podniz(false);
        std::vector<double> podniz;
        
        while (i < vektor.size()-1 and ((vektor[i] < vektor[i+1]) or JeSuLiJednaki(vektor[i], vektor[i+1])))
        {
            podniz.push_back(vektor[i]);
            postoji_podniz = true;
            i++;
        }   if (postoji_podniz) podniz.push_back(vektor[i]);
            
        if (podniz.size() >= 2)
            rastuci_podnizovi.push_back(podniz);
    }   return rastuci_podnizovi;
}

Matrica_inc OpadajuciPodnizovi (std::vector<double> vektor)
{
    Matrica_inc opadajuci_podnizovi;
    
    if (vektor.size() >= 2)
    for (int i=0; i<vektor.size()-1; ++i) {
        bool postoji_podniz(false);
        std::vector<double> podniz;
        
        while (i < vektor.size()-1 and ((vektor[i] > vektor[i+1]) or JeSuLiJednaki(vektor[i], vektor[i+1])))
        {
            podniz.push_back(vektor[i]);
            postoji_podniz = true;
            i++;
        }   if (postoji_podniz) podniz.push_back(vektor[i]);
        
        if (podniz.size() >= 2)
            opadajuci_podnizovi.push_back(podniz);
    }   return opadajuci_podnizovi;
}

int main ()
{
    int br_elemenata;
    std::cout << "Unesite broj elemenata vektora: ";
    std::cin >> br_elemenata;
    
    std::vector<double> vektor;
    std::cout << "Unesite elemente vektora: ";
    for (int i=0; i<br_elemenata; ++i) {
        double broj;
        std::cin >> broj;
        vektor.push_back(broj);
    }
    
    std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
    for (auto red : RastuciPodnizovi(vektor)) {
        for (auto x : red)  std::cout << x << " ";
        std::cout << std::endl;
    }

    std::cout << "Maksimalni opadajuci podnizovi:  " << std::endl;
    for (auto red : OpadajuciPodnizovi(vektor)) {
        for (auto x : red)    std::cout << x << " ";
        std::cout << std::endl;
    }
    
	return 0;
}