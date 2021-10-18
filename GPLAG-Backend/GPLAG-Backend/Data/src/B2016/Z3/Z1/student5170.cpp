/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <utility>
#include <stdexcept>
#include <vector>

double proizvod(int d, int i, std::vector<std::pair> vektor) {
    int k(1);
    if ((i-d)>1) k=i-d;
    else if((i-d)<1) k=1;
    double proizvod(1);
    for (int j(k); j<k+d; j++) {
        proizvod=proizvod*(1/(vektor[i].first-vektor[j].first));
    }
    return proizvod;
}

double omega (int d, int i, std::vector<std::pair> vektor) {
    int k(1);
    if ((i-d)>1) k=i-d;
    else if ((i-d)<1) k=1;
    int min(i);
    int n(vektor.size());
    if (i<(n-d)) min=i;
    else if (i>(n-d)) min=n-d;
    double suma(0);
    for (int j(k), j<min; j++) {
        suma=suma+(pow(-1,j-1)*proizvod(d,i,vektor));
    }
    return suma;
}

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair> vektor, int red_inter) {
    if (red_inter<0 || red_inter>vektor.size()) throw domain_error ("Nedozvoljen red");
    for (int i=0; i<vektor.siez(); i++) {
        vektoromega[i]=omega(red_inter, i, )
    }
    for (int i(0), i<vektor.size()-1; i++) {
        for (int j(i+1), j<vektor.size(); j++) {
            if(vektor[i].first == vektor[j].first) throw domain_error ("Neispravni cvorovi");
        }
    }
 return    
}

template <typename Funkcijskitip>
BaricentricnaInterpolacija (Funkcijskitip f, double min, double max, double delta, int d) {
    
}

int main ()
{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): " << std::endl;
    int izbor;
    std::cin >> izbor;
    if (izbor==1) {
        std::cout << "Unesite broj cvorova: " << std::endl;
        int n;
        std::cin >> n;
        std::cout << "Unesite cvorove kao parove x y: " << std::endl;
        double x,y;
        std::vector<std::pair> vektor;
        for (int i(0); i<n; i++) {
            std::cin >> x;
            std::cin >> y;
            vektor[i]=std::make_pair(x,y);
        }
        std::cout << "Unesite red interpolacije: " << std::endl;
        int d;
        std::cin >> d;
        for(;;) {
            std::cout << "Unesite argument (ili "kraj" za kraj)":  << std::endl;
        }
    }
    
    
    
    
    
    
    
    
    
	return 0;
}