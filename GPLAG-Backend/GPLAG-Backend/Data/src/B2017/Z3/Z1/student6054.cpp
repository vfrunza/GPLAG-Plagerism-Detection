/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
bool Poredi(std::pair<double,double>a,std::pair<double,double> b)
{
    return a.first<b.first;
}
std::function<double(double)> LinearnaInterpolacija (std::vector<std::pair<double,double>> v)
{
    for(int i=0; i<v.size(); i++) {
        for(int j=i+1; j<v.size(); j++) {
            if(v[i].first==v[j].first) {
                throw std::domain_error ("Neispravni cvorovi");

            }
        }
    }
    std::sort(v.begin(),v.end(),Poredi);
    return [v](double x) {
        auto p=std::begin(v);
        auto k=std::end(v);
        k--;
        //double p(0);
        if(x>v[v.size()-1].first|| x<v[0].first) {
            throw std::range_error ("Argument izvan opsega");

        }
        auto dgr=std::upper_bound(p,k,std::make_pair(x,0),[](std::pair<double,double>no1,std::pair<double,double> no2 ){ return no2.first>no1.first;});
        auto ggr=std::lower_bound(p,k,std::make_pair(x,0),[](std::pair<double,double>no1,std::pair<double,double> no2 ){ return no2.first>no1.first;});
        dgr--;
        double s;
        
        if(x==(ggr->first)) {
            return s=(ggr->second);
        }
        s=(dgr->second)+((ggr->second)-(dgr->second))/((ggr->first)-(dgr->first))*(x-(dgr->first));
        /*for(int i=0; i<v.size()-1; i++) {
            if(v[i+1].first>=x && v[i].first<=x) {
                double f;
                f=v[i].second+((v[i+1].second-v[i].second)/(v[i+1].first-v[i].first))*(x-v[i].first);
                return f;
            }
        }*/
        return s;

    };

}

std::function<double(double)>LinearnaInterpolacija(double f(double),double min,double max,double delta)
{
    if(min>max || delta<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> apr;
    for(auto i=min; i<=max; i=i+delta) {
        apr.push_back(std::make_pair(i,f(i)));
    }
    return LinearnaInterpolacija(apr);
}
int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int o;
    std::cin>>o;
    if(o==1) {
        try {
            std::cout<<"Unesite broj cvorova: ";
            int n;
            std::cin>>n;
            std::vector<std::pair<double,double>> v;
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<n; i++) {
                std::pair<double,double> cv;
                std::cin>>cv.first>>cv.second;
                v.push_back(cv);
            }
                        auto fun(LinearnaInterpolacija(v));

            double y;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>y;


            //auto fun(LinearnaInterpolacija(v));
            while(std::cin) {

                std::cout<<"f("<<y<<") = "<<fun(y)<<std::endl;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>y;
                if(!std::cin) break;
            }
        } catch (std::domain_error izuzetak) {
            std::cout<<izuzetak.what();
            return 0;
        } catch (std::range_error izuz) {
            std::cout<<izuz.what();
            return 0;
        }
    }
    if(o==2) {
        try {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double min,max,delta;
            std::cin>>min>>max>>delta;

            /* while(y>max || y<min) {
                 std::cout<<"Argument izvan opsega";
                 std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                 std::cin>>y;
             }*/
            auto f(LinearnaInterpolacija([](double y) {
                return y*y+sin(y);
            }, min, max, delta));

            while(std::cin) {

                try {

                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    double y;
                    std::cin>>y;
                    if(!std::cin)break;
                    std::cout<<"f("<<y<<") = "<<y*y+sin(y)<<" fapprox("<<y<<") = "<<f(y)<<std::endl;
                    /* std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                     std::cin>>y;*/

                } catch (std::range_error izuz) {
                    std::cout<<izuz.what()<<std::endl;
                }

            }

        } catch(std::domain_error izuzetak) {
            std::cout<<izuzetak.what()<<std::endl;
            return 0;
        } catch (std::range_error izuz) {
            std::cout<<izuz.what()<<std::endl;
            return 0;
        }


    }
    return 0;
}
