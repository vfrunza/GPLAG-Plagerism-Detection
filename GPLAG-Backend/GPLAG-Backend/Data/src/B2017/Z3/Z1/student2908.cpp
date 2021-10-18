/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <utility>
#include <vector>
#include <cmath>

typedef std::vector<std::pair<double, double>> vektor;

void Sortiranje(vektor &v) {
    bool sortiran(true);
    for(int i=0; i<v.size()-1; i++) { // paziti na prekoracenje opsega
        if(v.at(i)>v.at(i+1)) { // .at moze baciti izuzetak
            sortiran=false;
            break;
        }
    }
    if(!sortiran) std::sort(v.begin(), v.end()); // ako je soritran, sort vektoru nece nista uraditi
    // mozda i ne trba provjera je li sortiran
}

bool cmp(const std::pair<double, double> &l, const std::pair<double, double> &r) {
    return l.first<r.first;
}

std::function<double(double)> LinearnaInterpolacija(vektor v)
{
    // bacanje izuzetaka (ima iste x) - mozda neka bibliotecka funkcija algorithm
    const double eps(0.0001);
    for(int i=0; i<v.size()-1; i++) { // paziti na prekoracenje opsega
        for(int j=i+1; j<v.size(); j++) {
            if(fabs(v.at(i).first-v.at(j).first)<eps) { // i ovo .at bi moglo baciti izuzetak, a ... bi mogle uhvatit
                throw std::domain_error("Neispravni cvorovi");
            }
        }
    }
    // sortiranje
    Sortiranje(v);
    // glavni dio funkcije
    return [v] (double x) {
        // bacanje izuzetaka
        if(x<v[0].first || x>((v.end()-1)->first)) throw std::range_error("Argument izvan opsega");
        // provjera je li x vec u vektoru
        auto it1(std::find_if(v.begin(), v.end(), [x] (std::pair<double, double> y) { const double eps(0.0001); return fabs(y.first-x)<eps; }));
        if(it1!=v.end()) return it1->second;
        // ako nije prekinuta funkcija, ovdje se nastavlja: trazimo odg interval
        auto it(std::lower_bound(v.begin(), v.end(), std::make_pair(x, 0.0), cmp)); // parove poredimo po prvoj vrijednosti
        // linearna interpolacija
        return (it->second+((it+1)->second-it->second)/((it+1)->first -it->first)*(x-it->first));
    };
}

vektor LinearnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double delta) {
    
}

int main ()
{
    return 0;
}
