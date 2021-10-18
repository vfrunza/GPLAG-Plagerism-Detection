/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>

bool ProvjeriCvorove(const std::vector<std::pair<double,double>> &cvorovi){
    for(int i =0; i < cvorovi.size()-1; i++) for(int j= i+1; j < cvorovi.size(); ++j) if(cvorovi[i].first == cvorovi[j].first) return false;
    return true;
}

double momakpls(const std::vector<std::pair<double,double>> &vektor, int d, int indeks){
    double novi(0);
    int donji(1);
    int gornji(indeks);
    if(indeks -d > 1) donji = indeks - d;
    if(vektor.size() - d < indeks) gornji = vektor.size() - d;
    for(auto j = donji; j <= gornji; j++){
        double predznak(-1);
        if((j-1)% 2 == 0) predznak = 1;
        else predznak = -1;
        double suma(1);
        for(int k= j-1; k < j+d; k++){
            if(k != indeks-1) suma *=(1/(vektor[indeks-1].first - vektor[k].first));
        }
        novi += predznak * suma;
    }
    return novi;
}

std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair<double,double>> &vektor, int d){
    if(d<0 || d>=vektor.size()) throw std::domain_error("Nedozvoljen red");
    if(!ProvjeriCvorove(vektor)) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> novi(vektor.size());
    for(int i=0; i < vektor.size(); i++) novi[i] = momakpls(vektor, d, i+1);
    
    return ([novi, vektor](double x){
        double brojnik(0), nazivnik(0);
        for(int i=0; i < vektor.size(); i++) if(x == vektor[i].first) return vektor[i].second;
        for(int i=0; i < vektor.size(); i++){
            brojnik += (novi[i] / (x-vektor[i].first)) * vektor[i].second;
            nazivnik += (novi[i] / (x - vektor[i].first));
        }
        return brojnik/nazivnik;
    });
}

template<typename tip>
std::function<double(double)> BaricentricnaInterpolacija(tip f, double min, double max, double dx, int d){
    if(min > max || dx <=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> vektor;
    while( min <= max){
        std::pair<double, double> novi{min, f(min)};
        vektor.push_back(novi);
        min += dx;
    }
    return BaricentricnaInterpolacija(vektor, d);
}

double xxxsinx (double x) {return x * x + std::sin(x);}

int main ()
{
    int broj;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> broj;
    if(broj == 1){
        std::vector<std::pair<double, double>> vektor;
        int broj_cl;
        double a, b;
        std::cout << "Unesite broj cvorova: ";
        std::cin >> broj_cl;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i=0; i < broj_cl; i++){
            std::cin >> a; std::cin >> b;
            vektor.push_back({a,b});
        }
        std::cout << "Unesite red interpolacije: ";
        int red_inter;
        std::cin >> red_inter;
        double vrijednost;
        try{
            auto z(BaricentricnaInterpolacija(vektor, red_inter));
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        while (std::cin >> vrijednost) {
            while(char(std::cin.peek()) ==' ') std::cin.get();
            if(std::cin.peek() != '\n') return 0;
            std::cout << "f(" << vrijednost << ") = " << z(vrijednost) << std::endl;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        }
        }catch(std::domain_error exec){
            std::cout << exec.what() << std::endl;
            return 0;
        }
    
        
    }else if(broj == 2){
        double a, b, dx;
        std::cout << "Unesite krajeve intervala i korak: ";
        std::cin >> a >> b >> dx;
        int red_interp;
        std::cout << "Unesite red interpolacije: ";
        std::cin >> red_interp;
        double vrijednost;
        try{
            auto z(BaricentricnaInterpolacija(xxxsinx, a, b, dx, red_interp));
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        while (std::cin >> vrijednost) {
            while(char(std::cin.peek()) ==' ') std::cin.get();
            if(std::cin.peek() != '\n') return 0;
            std::cout << "f(" << vrijednost << ") = " << xxxsinx(vrijednost) << " " << "fapprox(" << vrijednost << ") = " << z(vrijednost) << std::endl;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        }
        
        
        }catch(std::domain_error exec){
            std::cout << exec.what() << std::endl;
            return 0;
        }
        
    }
	return 0;
}