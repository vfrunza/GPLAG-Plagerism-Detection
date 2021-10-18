/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

bool TestirajCvorove(std::vector<std::pair<double, double>> v){
    for(auto it=v.begin(); it!=v.end(); it++)
        for(auto it1=v.begin(); it1!=v.end(); it1++)
            if(it->first == it1->first && it!=it1)
                return false;
    return true;
}

int NadjiMax(int prvi, int drugi){
    if(prvi > drugi) return prvi;
    return drugi;
}

int NadjiMin(int prvi, int drugi){
    if(prvi < drugi) return prvi;
    return drugi;
}

std::vector<double> NadjiTezinske(std::vector<std::pair<double, double>> v, int d){
    std::vector<double> tezinski(v.size());
    for(int i=1; i<v.size(); i++){
        int max(NadjiMax(1, i-d));
        int min(NadjiMin(i, v.size()-1-d));
        double suma(0);
        for(int k=max; k<=min; k++){
            double proizvod(1);
            for(int j=k; j<=k+d; j++){
                if(j!=i) proizvod *= (1/(v[i].first - v[j].first));
            }
            if((k-1)%2 != 0) proizvod = -1*proizvod;
            suma += proizvod;
            }
    tezinski[i] = suma;
    }
    return tezinski;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v1, int d){
    std::vector<std::pair<double, double>> v(v1.size()+1);
    for(int i=1; i<v.size();i++)
        v[i] = v1[i-1];
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    if(!TestirajCvorove(v1)) throw std::domain_error("Neispravni cvorovi");
    std::vector<double> tezinski(NadjiTezinske(v, d));
    return [tezinski, v](double x) -> double{
        double suma1(0), suma2(0);
        for(int i=1; i<v.size(); i++)
            if(x == v[i].first)
                return v[i].second;
        for(int i=1; i<v.size(); i++)
            suma1 += ((tezinski[i]*v[i].second) / (x - v[i].first));
        for(int i=1; i<v.size(); i++)
            suma2 += (tezinski[i] / (x - v[i].first));
    return suma1 / suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(double fun(double), double min, double max, double delta, int d){
    if(min > max || delta <= 0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    int index(0);
    for(;;){
        if(min + index*delta > max) break;
        std::pair<double, double> par;
        par.first = min + index*delta;
        par.second = fun(par.first);
        v.push_back(par);
        index++;
    }
    return BaricentricnaInterpolacija(v, d);
}

std::function<double(double)> DajMiFunkciju(){
    return [](double x) -> double{
        return x*x + sin(x);
    };
}

int main ()
{
    char c(34);
    int opcija;
    cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin >> opcija;
    try{
    if(opcija == 1){
        int br;
        std::cout << "Unesite broj cvorova: ";
        cin >> br;
        cout << "Unesite cvorove kao parove x y: ";
        int prvi, drugi;
        std::vector<std::pair<double, double>> v(br);
        for(int i=0; i<v.size(); i++){
            cin >> prvi >> drugi;
            v[i].first = prvi; v[i].second = drugi;
        }
        int red;
        cout << "Unesite red interpolacije: ";
        cin >> red;
        auto fun(BaricentricnaInterpolacija(v, red));
        while(cin){
        double argument;
        cout << "Unesite argument (ili "<<c<<"kraj"<<c<<" za kraj): ";
        cin >> argument;
        if(!cin) break;
        cout << "f(" << argument << ") = " << fun(argument) << endl;
        }
    }
    else if(opcija == 2){
        cout << "Unesite krajeve intervala i korak: ";
        double min, max, delta;
        cin >> min >> max >> delta;
        int red;
        cout << "Unesite red interpolacije: ";
        cin >> red;
        auto fun(DajMiFunkciju());
        auto fapprox(BaricentricnaInterpolacija([](double x) -> double{return x*x + sin(x);}, min, max, delta, red));
        while(cin){
        double argument;
        cout << "Unesite argument (ili "<<c<<"kraj"<<c<<" za kraj): ";
        cin >> argument;
        if(!cin) break;
        cout << "f(" << argument << ") = " << fun(argument) << " fapprox(" << argument << ") = " << fapprox(argument) <<endl;
        }
        
    }
    }catch(std::domain_error cigla){cout << cigla.what();}
	return 0;
}