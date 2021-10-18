/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>

std::function<double(double)>LinearnaInterpolacija (std::vector<std::pair<double, double>> v)
{
    for ( int i = 0; i < v.size(); i++) {
        for( int j = i + 1; j <= i + 1; j++) {
            if ( v.at(i).first == v.at(j).second) throw std::domain_error("Neispravni cvorovi")//ako su x koordinate jednake izuzetak
                if ( v.at(i).first > v.at(j).first)//prolazim kroz vektor, ako nije ipravno sortiran, sortiraj!cvorovi moraju biti sortirani po x koordinati
                    std::sort(v.begin(), v.end(), [](double a, double b) {
                    return a < b;
                });
        }
    }
   /* for( int i = 0; i < v.size(); i++) {
        //x za koje se vrsi procjena mora pripadati intervalu x1,xn
        //ako je x=xn onda return function = yn
        for( int j = i + 1 ; j <= i + 1 ; j++) {
            if ( v.at(i).first < x && v.at(j).first > x) {
                double xi = v.at(i).first;
                double xi1 = v.at(j).first;
                double yi = v.at(i).second;
                double yi1 = v.at(j).second;
                continue;
            }
        }
    }*/
    //f(x) = yi + ((yi1 - yi)/(xi1 - xi)) * (x - xi);
    //binarna pretraga vraca T ili F, ako ima element ili nema
   if(std::binary_search(v.begin(), v.end(), x)){
       auto xi1 = upper_bound (v.begin(), v.end(), x) - v.begin();
       auto  x = lower_bound ( v.begin(), v.end(), x) - v.begin() - 1;
       
   }
    

    return [v](double x)->double {return ;

                                 }
    
                                 
LinearnaInterpolacija ( double f(double), double xmin, double xmax, double delta){
    if( xmin > xmax || delta < 0 ) throw std::domain_error ( "Nekorektni parametri");
    
}



    int main () {

        return 0;
    }
