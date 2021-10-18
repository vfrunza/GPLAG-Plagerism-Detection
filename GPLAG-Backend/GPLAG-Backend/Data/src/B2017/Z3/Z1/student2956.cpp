/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>

double Nesto(double x){
    return x*x+std::sin(x);
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> vektor){
    return [vektor](double x) -> double{
        auto it = vektor.begin(), it1 = vektor.begin();
        //bool ima = false, nema = false;
        double vrijednost(0);
        it=std::lower_bound(vektor.begin(), vektor.end(), std::make_pair(x, std::numeric_limits<double>::min()));
        if(it-vektor.begin()==0||it-vektor.end()==0){
            if(it-vektor.end()==0) throw std::range_error("Argument izvan opsega");
            if(it->first==x) return it->second;
            throw std::range_error("Argument izvan opsega");
        }
        it1=it;
        it1--;
        if(it->first==x) return it->second;
        else vrijednost = it1->second + (it->second - it1->second)/(it->first - it1->first)*(x-it1->first);
        return vrijednost;
    };
}

std::function<double(double)> LinearnaInterpolacija(double funkcija(double), double xmin, double xmax, double deltax){
    return [=](double x) -> double{
        if(xmin>xmax||deltax==0||(xmin==xmax&&deltax!=0)) throw std::domain_error("Nekorektrni parametri");
        std::vector<std::pair<double, double>> vektor;
        //std::cout<<"broj je: "<<xmax/deltax<<std::endl;
        for(int i = 0 ; i <xmax/deltax-1; i++ )
        {
            vektor.push_back(std::make_pair(xmin + i*deltax, funkcija(xmin+i*deltax)));
        }
        auto it = vektor.begin(), it1 = vektor.begin();
        //bool ima = false, nema = false;
        double vrijednost(0);
        it=std::lower_bound(vektor.begin(), vektor.end(), std::make_pair(x, std::numeric_limits<double>::min()));
        //for(auto i : vektor) std::cout<<"*it iznosi: "<<i.first<<std::endl;
        if(it-vektor.begin()==0||it-vektor.end()==0){
            if(it-vektor.end()==0) throw std::range_error("Argument izvan opsega");
            if(it->first==x) return it->second;
            throw std::range_error("Argument izvan opsega");
        }
        it1=it;
        it1--;
        if(it->first==x) return it->second;
        else vrijednost = it1->second + (it->second - it1->second)/(it->first - it1->first)*(x-it1->first);
        return vrijednost;
    };
}

int main ()
{
    std::function<double(double)> f;
    double pomocna(0),pomocna1(0);
    try{
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::vector<std::pair<double, double>> vektor;
    std::cin >> pomocna;
    if(pomocna == 1){
        double velicina(0);
        std::cout << "Unesite broj cvorova: ";
        std::cin >> velicina;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i = 0; i < velicina; i++){
            std::cin >> pomocna >> pomocna1;
            vektor.push_back(std::make_pair(pomocna, pomocna1));
        }
        std::sort(vektor.begin(), vektor.end(), [](const std::pair<double, double> &prvi,const std::pair<double, double> &drugi){
            return prvi.first < drugi.first;
        });
        auto test = std::unique(vektor.begin(), vektor.end(), [](const std::pair<double, double> &prvi,const std::pair<double, double> &drugi){
            return prvi.first == drugi.first;
        });
        if (test-vektor.end()<0) throw std::domain_error("Neispravni cvorovi");
        f=LinearnaInterpolacija(vektor);
        std::string rijec;
        for(;;){
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> rijec;
            if(rijec == "kraj") break;
            pomocna1 = std::stod(rijec);
            std::cout << "f(" << pomocna1 << ") = " << f(pomocna1) << std::endl;
            rijec.clear();
        }
    }
    if(pomocna==2){
        std::cout << "Unesite krajeve intervala i korak: ";
        double pocetak(0), kraj(0), korak(0);
        std::cin >> pocetak >> kraj >> korak;
        f=LinearnaInterpolacija(Nesto, pocetak, kraj, korak);
        std::string rijec;
        for(;;){
            try{
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::cin >> rijec;
            if(rijec == "kraj") break;
            pomocna1 = std::stod(rijec);
            std::cout << "f(" << pomocna1 << ") = " << pomocna1*pomocna1+std::sin(pomocna1) << " fapprox(" << pomocna1<< ") = " <<f(pomocna1) << std::endl;
            rijec.clear();}
            catch(std::range_error greska){
	            std::cout<<greska.what()<<std::endl;
	        }
	        catch(std::domain_error greska){
	        std::cout<<greska.what();
	        return 0;
	        }
        }
    }
	return 0;}
	catch(std::range_error greska){
	    std::cout<<greska.what()<<std::endl;
	    /*if(pomocna==2){
	        std::string rijec;
            for(;;){
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin >> rijec;
                if(rijec == "kraj") break;
                pomocna1 = std::stod(rijec);
                if(pomocna==2) std::cout << "f(" << pomocna1 << ") = " << pomocna1*pomocna1+std::sin(pomocna1) << " fapprox(" << pomocna1<< ") = " <<f(pomocna1) << std::endl;
                else std::cout << "f(" << pomocna1 << ") = " << f(pomocna1) << std::endl;
                rijec.clear();
            }
	    }*/
	}
	catch(std::domain_error greska){
	    std::cout<<greska.what();
	}
}
/*

bekap 1

/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <utility>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> vektor){
    return [vektor](double x) -> double{
        auto it = vektor.begin(), it1 = vektor.begin();
        //bool ima = false, nema = false;
        double vrijednost(0);
        for(;it!=vektor.end();it++){
            if(it->first==x){
                ima = true;
                vrijednost = it->second;
                break;
            }
        }
        if(!ima){
            it=vektor.begin();
            for(;it!=vektor.end();it++){
                if(it->first > x){
                    nema = true;
                    it1 = it;
                    it1--;
                    vrijednost = it1->second + (it->second - it1->second)/(it->first - it1->first)*(x-it1->first);
                    break;
                }
            }
        }
        return vrijednost;
    };
}

int main ()
{
    std::vector<std::pair<double, double>> vektor;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    double pomocna(0),pomocna1(0);
    std::cin >> pomocna;
    if(pomocna == 1){
        double velicina(0);
        std::cout << "Unesite broj cvorova: ";
        std::cin >> velicina;
        std::cout << "Unesite cvorove kao parove x y: ";
        for(int i = 0; i < velicina; i++){
            std::cin >> pomocna >> pomocna1;
            vektor.push_back(std::make_pair(pomocna, pomocna1));
        }
    }
    auto f(LinearnaInterpolacija(vektor)); 
    std::string rijec;
    for(;;){
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::cin >> rijec;
        if(rijec == "kraj") break;
        pomocna = std::stod(rijec);
        std::cout << "f(" << pomocna << ") = " << f(pomocna) << std::endl;
        rijec.clear();
    }
	return 0;
}
*/

