/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stdexcept>
#include <iterator>
#include <cmath>
#include <limits>

#define epsilon 0.0001

bool ImaIsteElemente(std::vector<std::pair<double, double>> koordinate)
{
    typename std::vector<std::pair<double, double>>::iterator it_koordinate=koordinate.begin(), it_drugi;

    for(int i=0; i<koordinate.size(); i++) {
        if( fabs( (i+1) - koordinate.size() ) < epsilon)
            break;

        it_drugi = it_koordinate;
        it_drugi++;

        for(int j=i; j<koordinate.size(); j++) {
            if( fabs( (it_drugi->first)-(it_koordinate->first) ) < epsilon)
                return true;

            it_drugi++;

            if(it_drugi==koordinate.end())
                break;
        }
    }

    return false;
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> koordinate)
{
    if(ImaIsteElemente(koordinate))
        throw std::domain_error ("Neispravni cvorovi");

    std::sort(koordinate.begin(), koordinate.end(), [](std::pair<double, double> prvi, std::pair<double, double> drugi) {
        return prvi.first < drugi.first;
    });
    //std::cout<<koordinate.begin()->first;
    return [koordinate](double x) { //ovaj "double x" oznacava sta funkcija koja se vraca iz funkcije prima kao parametar
        auto it_koordinate = koordinate.end();
        std::advance(it_koordinate, -1);
        if(koordinate.size()==0 || x<koordinate.begin()->first || x>it_koordinate->first )  //jer je sortiran tako da najmanji bude prvi, a najveci zadnji
            throw std::range_error ("Argument izvan opsega");

        if( fabs( koordinate.at(koordinate.size()-1).first - x )< epsilon)
            return koordinate.at(koordinate.size()-1).second;

        auto veci=std::upper_bound(koordinate.begin(), koordinate.end(), std::make_pair(x, std::numeric_limits<double>::min()), []
        (std::pair<double, double> prvi, std::pair<double, double> drugi) {
            return prvi.first < drugi.first;
        });
        auto manji=veci;
        std::advance(manji, -1);

        return manji->second + (veci->second - manji->second) / (veci->first - manji->first) * (x - manji->first);
    };

}

void PopuniVektor(std::vector<std::pair<double, double>> &v, std::function<double(double)> &aproksimiraj, double x_min, const double &x_max, const double &delta_x)
{
    while(x_min<=x_max) {
        v.push_back( std::make_pair(x_min, aproksimiraj(x_min)) );
        x_min+=delta_x;
    }
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> aproksimiraj, double x_min, double x_max, double delta_x )
{
    if(delta_x<=0 || x_min>x_max)
        throw std::domain_error ("Nekorektni parametri");

    std::vector<std::pair<double, double>> v;

    PopuniVektor(v, aproksimiraj, x_min, x_max, delta_x);

    return LinearnaInterpolacija(v);
}

double ime_neke_funkcije (double x)
{
    return x*x + std::sin(x);
}

int main ()
{
    /*std::vector<std::pair<double, double>> v{std::make_pair(1,1), std::make_pair(4,2), std::make_pair(2,1), std::make_pair(3,1)};
    if(ImaIsteElemente(v))
    std::cout<<"ima iste x koordinate";
    else
    std::cout<<"nema";*/

    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int odabir;
    std::cin>>odabir;

    if(odabir==1) {
        std::cout<<"Unesite broj cvorova: ";
        int br_cvorova;
        std::cin>>br_cvorova;

        std::cout<<"Unesite cvorove kao parove x y: ";

        std::vector<std::pair<double,double>> cvorovi;

        for(int i=0; i<br_cvorova; i++) {
            int x, y;
            std::cin>>x>>y;
            cvorovi.push_back( std::make_pair(x, y) );
        }
        try {
            do {
                try {

                    auto funkcija=LinearnaInterpolacija(cvorovi);
                    double argument;
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>argument;
                    if(!std::cin) break;


                    std::cout<<"f("<<argument<<") = "<<funkcija(argument)<<std::endl;
                    // std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";

                } catch(std::range_error poruka2) {
                    std::cout<<poruka2.what()<<std::endl;//<<"Unesite argument (ili \"kraj\" za kraj): ";;
                }
            } while(std::cin);
        } catch(std::domain_error poruka) {
            std::cout<<poruka.what()<<std::endl;//<<"Unesite argument (ili \"kraj\" za kraj): ";;
        }
    }


    else if(odabir==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double korak, prvi_kraj, drugi_kraj;
        std::cin>>prvi_kraj>>drugi_kraj>>korak;
        try {

            do {
                try {
                    auto funkcija=LinearnaInterpolacija(ime_neke_funkcije, prvi_kraj, drugi_kraj, korak);
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double argument;
                    //while(std::cin>>argument) {
                    //if(std::cin.peek()!='\n')
                    //break;
                    std::cin>>argument;
                    if(!std::cin) break;


                    std::cout<<"f("<<argument<<") = "<<argument*argument+std::sin(argument) <<" fapprox(" << argument << ") = "<< funkcija(argument) <<std::endl;
                    //std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                }

                catch(std::range_error poruka2) {
                    std::cout<<poruka2.what()<<std::endl;//<<"Unesite argument (ili \"kraj\" za kraj): ";;
                }
            } while(std::cin);
        } catch(std::domain_error poruka) {
            std::cout<<poruka.what()<<std::endl;//<<"Unesite argument (ili \"kraj\" za kraj): ";;
        }
    }

    return 0;
}
