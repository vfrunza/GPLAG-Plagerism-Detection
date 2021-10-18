#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <utility>
#include <algorithm>

using std::cout;
using std::cin;

double Funkcija(double x) {
    return x*x + std::sin(x);
}

bool Poredak(std::pair<double, double> par1, std::pair<double, double> par2) {
    return par1.first<par2.first;
}

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> parovi) {
    
    const double EPSILON(0.000000001);
    
    for(int i=0; i<parovi.size(); i++) {
        for(int j=i+1; j<parovi.size(); j++) {
            if(fabs(parovi[i].first-parovi[j].first)<EPSILON) throw std::domain_error("Neispravni cvorovi");
        }
    }
    
    std::sort(parovi.begin(), parovi.end(), Poredak); 
    
    return [parovi](double x)->double {
        if(x<parovi[0].first || x>parovi[parovi.size()-1].first) throw std::range_error("Argument izvan opsega");
        
        auto it2=std::lower_bound(parovi.begin(), parovi.end(), std::make_pair(x, 0), Poredak);
        auto it1(it2-1);
        return it1->second + ((it2->second-it1->second)/(it2->first-it1->first))*(x-it1->first);
    };
}

std::function<double(double)> LinearnaInterpolacija(double f(double), double xmin, double xmax, double deltax) {
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    
    std::vector<std::pair<double, double>> parovi;
    
    while(xmin<=xmax) {
        parovi.push_back({xmin, f(xmin)});
        xmin+=deltax;
    }
    
    return [parovi](double x)->double {
        if(x<parovi[0].first || x>parovi[parovi.size()-1].first) throw std::range_error("Argument izvan opsega");
        
        auto it2=std::lower_bound(parovi.begin(), parovi.end(), std::make_pair(x, 0), Poredak);
        auto it1(it2-1);
        return it1->second + ((it2->second-it1->second)/(it2->first-it1->first))*(x-it1->first);
    };
        
}

bool problem(false);

int main ()
{
    int izbor;
    for(;;) {
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        cin>>izbor;
        if(!cin) {
            cin.clear();
            cin.ignore(10000, '\n');
            break;
        }
        if(izbor==1) {
            int n;
            std::vector<std::pair<double, double>> parovi;
            cout<<"Unesite broj cvorova: ";
            cin>>n;
            double x, y;
            cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<n; i++) {
                cin>>x>>y;
                parovi.push_back(std::make_pair(x, y));
            }
            try {
                auto f(LinearnaInterpolacija(parovi));
                for(;;) {
                    double x;
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    cin>>x;
                    if(!cin) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        problem=true;
                        break;
                    }
                    try {
                        cout<<"f("<<x<<") = "<<f(x)<<"\n";
                    } catch(std::range_error izuzetak) {
                        cout<<izuzetak.what()<<"\n";
                    }
                }
            } catch (std::domain_error izuzetak) {
                cout<<izuzetak.what()<<"\n";
                return 0;
            }
            
        } else if(izbor==2) {
            double xmin, xmax, deltax;
            cout<<"Unesite krajeve intervala i korak: ";
            cin>>xmin>>xmax>>deltax;
            try {
                auto f(LinearnaInterpolacija(Funkcija, xmin, xmax, deltax));
                for(;;) {
                    double x;
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    cin>>x;
                    if(!cin) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        problem=true;
                        break;
                    }
                    try {
                        cout<<"f("<<x<<") = "<<Funkcija(x)<<" fapprox("<<x<<") = "<<f(x)<<"\n";
                    } catch(std::range_error izuzetak) {
                        cout<<izuzetak.what()<<"\n";
                    }
                }
            } catch (std::domain_error izuzetak) {
                cout<<izuzetak.what()<<"\n";
                return 0;
            }
        }
        if(problem) break;    
    }
	return 0;
}
