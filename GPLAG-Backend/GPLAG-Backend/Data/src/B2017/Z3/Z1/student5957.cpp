/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>
using std::function;
using std::vector;
using std::cout;
using std::cin;
using std::pair;
const double EPS=1e-5;
typedef pair<double,double> PAR;

bool VeciManji(PAR prvi, PAR drugi)
{
    if(prvi.first-drugi.first<EPS && prvi.first-drugi.first>-EPS) throw std::domain_error("Neispravni cvorovi");
    return prvi.first<drugi.first;
}

double fun(double x)
{
    return x*x+std::sin(x);
}

function<double(double)> LinearnaInterpolacija(vector<PAR> &v)
{
    std::sort(v.begin(),v.end(),VeciManji);
    return [&v](double a) {
        double xi(0),xi1(0),yi(0),yi1(0);
        auto it(std::lower_bound(v.begin(),v.end(),a,[](std::pair<double,double> par,double a) {
            return (par.first<a || (par.first-a<EPS && par.first-a>EPS));
        }));
        if(it==v.end()) throw std::range_error("Argument izvan opsega");
        else if(it==v.begin() && a<it->first) throw std::range_error("Argument izvan opsega");
        else if(it->first-a<EPS && it->first-a>EPS) {
            auto pom(it);
            pom++;
            if(pom==v.end()) return it->second;
            xi=it->first;
            yi=it->second;
            xi1=pom->first;
            yi1=pom->second;
            return yi+((yi1-yi)/(xi1-xi))*(a-xi);
        }
        auto pom(it);
        it--;
        xi=it->first;
        yi=it->second;
        xi1=pom->first;
        yi1=pom->second;
        return yi+((yi1-yi)/(xi1-xi))*(a-xi);
    };
}

function<double(double)> LinearnaInterpolacija(function<double(double)> fun,double xmin,double xmax,double dx)
{
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    return [fun,xmin,xmax,dx](double a) {
        vector<double> v;
        double min=xmin;
        while(min<=xmax) {
            v.push_back(min);
            min+=dx;
        }
        auto it(std::lower_bound(v.begin(),v.end(),a));
        double xi(0),xi1(0),yi(0),yi1(0);
        if(it==v.end()) throw std::range_error("Argument izvan opsega");
        else if(it==v.begin() && a<*it) throw std::range_error("Argument izvan opsega");
        else if(*it-a<EPS && *it-a>-EPS) {
            auto pom(it);
            pom++;
            if(pom==v.end()) return fun(*it);
            xi=*it;
            yi=fun(*it);
            xi1=*pom;
            yi1=fun(*pom);
            return yi+((yi1-yi)/(xi1-xi))*(a-xi);
        }
        auto pom(it);
        it--;
        xi=*it;
        yi=fun(*it);
        xi1=*pom;
        yi1=fun(*pom);
        return yi+((yi1-yi)/(xi1-xi))*(a-xi);
    };
}

int main ()
{
    int opcija(0);
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>opcija;
    try {
        char a('"');
        if(opcija==1) {
            int br_cvorova(0);
            cout<<"Unesite broj cvorova: ";
            cin>>br_cvorova;
            vector<pair<double,double>> vec(br_cvorova);
            cout<<"Unesite cvorove kao parove x y: ";
            for(int i(0); i<br_cvorova; i++) {
                cin>>vec[i].first;
                cin>>vec[i].second;
            }
            double arg(0);
            auto f(LinearnaInterpolacija(vec));
            for(;;) {
                cout<<"Unesite argument (ili "<<a<<"kraj"<<a<<" za kraj): ";
                cin>>arg;
                if(!cin) {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    break;
                }
                try {
                    cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
                } catch(std::domain_error izuzetak) {
                    cout<<izuzetak.what()<<std::endl;
                } catch(std::range_error izuzetak) {
                    cout<<izuzetak.what()<<std::endl;
                }
            }

        }
        if(opcija==2) {
            double xmin(0),xmax(0),dx(0);
            cout<<"Unesite krajeve intervala i korak: ";
            cin>>xmin>>xmax>>dx;
            double arg(0);
            auto f(LinearnaInterpolacija(fun,xmin,xmax,dx));
            for(;;) {
                cout<<"Unesite argument (ili "<<a<<"kraj"<<a<<" za kraj): ";
                cin>>arg;
                if(!cin) {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    break;
                }
                try {
                    cout<<"f("<<arg<<") = "<<arg*arg+std::sin(arg)<<" fapprox("<<arg<<") = "<<f(arg)<<std::endl;
                } catch(std::domain_error izuzetak) {
                    cout<<izuzetak.what()<<std::endl;
                } catch(std::range_error izuzetak) {
                    cout<<izuzetak.what()<<std::endl;
                }
            }
        }
    } catch(std::domain_error izuzetak) {
        cout<<izuzetak.what();
    } catch(std::range_error izuzetak) {
        cout<<izuzetak.what();
    }

    return 0;
}
