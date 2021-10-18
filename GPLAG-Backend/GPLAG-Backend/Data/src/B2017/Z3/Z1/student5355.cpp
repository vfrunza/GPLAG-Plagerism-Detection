#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>
#include <stdexcept>
#include <set>
#include <cmath>

enum opcija {cvor=1, aprox=2};
bool ViseMinusa (const std::string &arg)
{
    int brojac(0);
    for (int i(0); i<arg.size(); i++) {
        if ( arg[i]=='-') {
            brojac++;
            if (brojac>=2) return true;
        }
    }
    return false;
}

bool ViseTacaka (const std::string &arg)
{
    int brojac(0);
    for (int i(0); i<arg.size(); i++) {
        if ( arg[i]=='.') {
            brojac++;
            if (brojac>=2) return true;
        }
    }
    return false;
}

bool NaN ( std::string arg)
{
    if (arg=="." || arg=="-") return false;
    if (ViseTacaka(arg) || ViseMinusa(arg)) return false;
    for (int i(0); i<arg.size(); i++) {
        if (arg[i]==',') return false;
        if ( (arg[i]<'0'|| arg[i]>'9') && arg[i]!='\n' &&  arg[i]!='.' && arg[i]!='-') {
            return false;
        }
    }
    arg.erase (arg.begin()+ arg.size()-1);
    return true;
}

bool PrviElement (std::vector<std::pair<double,double>> &V)
{

    int sizeV(V.size());
    if (V.size()==0) return true;
    std::set<double> L;
    for (int i(0); i<V.size(); i++) {
        auto k(V[i].first);
        L.insert(k);
    }
    int sizeL(L.size());
    if (sizeL==sizeV) {
        std::sort (V.begin(), V.end());
        return true;
    }
    return false;

}

std::function<double(double)>  LinearnaInterpolacija (   std::vector<std::pair<double,double>> & VUP)
{
      
    if (!PrviElement(VUP)) throw std::domain_error ("Neispravni cvorovi");


    return [=] (double x) {
        int last=VUP.size()-1;
        if (VUP.size()==0) throw std::range_error (" Argument izvan opsega");
        if (x<VUP[0].first || x>VUP[last].first) throw std::range_error (" Argument izvan opsega");
        if (VUP[0].first==0 && x==0) return VUP[0].first;
        const std::pair<double, double> trazi (x,0);


        auto x1= std::lower_bound (VUP.begin(), VUP.end(), trazi);
        auto x0=x1;
        x0--;

        return  (x0->second +  ((x1->second - x0->second)/(x1->first - x0->first))* (x- x0->first));
    };


}

std::function <double(double)>  LinearnaInterpolacija ( double fun(double), double xp, double xk , double korak)
{

    if (xp>xk || korak<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair <double,double>> VUP2;
    double pom(xp),pomf(0);
    int i(0);
    while (pom<xk) {
        pom= xp+ (korak*i);
        pomf= fun(pom);
        std::pair<double, double> trazi=std::make_pair (pom,pomf);
        VUP2.push_back (trazi);
        i++;
    }
    
 return [=] (double x) {
        int last=VUP2.size()-1;
        if (VUP2.size()==0) throw std::range_error ("Argument izvan opsega");
        if (VUP2[0].first==0 && x==0) return VUP2[0].first;
        if (x<VUP2[0].first || x>VUP2[last].first) throw std::range_error ("Argument izvan opsega");
        const std::pair<double, double> trazi (x,0);
        auto x1= std::lower_bound (VUP2.begin(), VUP2.end(), trazi);
        auto x0=x1;
        x0--;
        return  (x0->second +  ((x1->second - x0->second)/(x1->first - x0->first))* (x- x0->first));
    };
}


int main ()
{

    int un(0);
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>un;
    if (cvor==un) {
        std::cout<<"Unesite broj cvorova: ";
        int cbr(0);
        std::cin>>cbr;
        if (cbr==0) return 0;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> parovi;
        for (int i(0); i<cbr; i++) {
            double x(0),y(0);
            std::cin>>x>>y;
            parovi.push_back (std::pair <double,double> (x,y));
        }
        try {
         LinearnaInterpolacija (parovi);
        } catch (std::domain_error e) {
            std::cout<<e.what();
            return 0;
        }
        std::cin.ignore (10000, '\n');
        while (1) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::string arg;
            std::getline(std::cin, arg);

            if ( NaN(arg))  {
                double argd= std::stod(arg);

                try {
                    auto f=LinearnaInterpolacija (parovi);
                    auto arr=f(argd);
                    std::cout<<"f("<<argd<<") = "<<arr<<std::endl;
                } catch (std::range_error td) {
                    std::cout<<td.what();
                    std::cout<<std::endl;
                }
                continue;
            } else {
                break;
            }

        }
    } else if (aprox==un) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double min(0), max(0) , korak(0);
        std::cin>>min>>max>>korak;
        std::cin.ignore (10000, '\n');
        try {
            auto f= LinearnaInterpolacija ([](double x)-> double { return x*x+ std::sin (x);} ,min,max,korak);
        } catch (std::domain_error td) {
            std::cout<<td.what();
            return 0;
        }
        while (1) {
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::string arg;
            std::getline(std::cin, arg);

            if ( NaN(arg))  {
                double argd= std::stod(arg);
                try {
                    auto f= LinearnaInterpolacija ([](double x)-> double { return x*x+ std::sin (x);} ,min,max,korak);
                    auto adds=f(argd);
                    std::cout<<"f("<<argd<<") = "<<(argd*argd+std::sin(argd))<<" fapprox("<<argd<<") = "<<adds<<std::endl;
                } catch (std::range_error e) {
                    std::cout<<e.what();
                    std::cout<<std::endl;

                }

                continue;
            } else {
                break;
            }
        }
    }
 return 0;
}

