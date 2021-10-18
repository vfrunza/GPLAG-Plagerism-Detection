/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>
#include <functional>
#include <utility>
#include <algorithm>

double funkcija(double x)                                           
{
    return x*x+std::sin(x);
}

std::function<double (double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> cvorovi_inter)
{
    double eps(0.000001);                                                       //bacanje izuzetka
    for(int i=0; i<int(cvorovi_inter.size())-1; i++) {
        for(int j=i+1; j<int (cvorovi_inter.size()); j++)
            if(fabs(cvorovi_inter[j].first-cvorovi_inter[i].first)<eps)
                throw std::domain_error("Neispravni cvorovi");
    }
    std::sort(cvorovi_inter.begin(), cvorovi_inter.end(),                       //sortiranje u rastuci poredak prema koordinati x
    [] (const std::pair<double, double> &p1,const std::pair<double, double> &p2){
        return p1.first<p2.first;
    });
    for(int i=0; i<int(cvorovi_inter.size())-1; i++)                            //provjera jesu li sve vrijednosti x razlicite
        for(int j=i+1; j<cvorovi_inter.size(); j++)
            if(cvorovi_inter[i].first==cvorovi_inter[j].first)
                throw std::domain_error("Neispravni cvorovi");
                
    return [cvorovi_inter] (double x) {                                         //vraca se nova funkcija
        double x1, x2, y1, y2;
        if(x>=cvorovi_inter[0].first && x<=cvorovi_inter[cvorovi_inter.size()-1].first ) {
            auto pomocna=std::find_if(cvorovi_inter.begin(), cvorovi_inter.end(),
                [x] (std::pair<double, double> p) {
                return p.first>=x;
            });                                                                 //iskoristena je binarna pretraga
            if (pomocna->first==x) return pomocna->second;
            x2=pomocna->first;
            y2=pomocna->second;
            pomocna--;
            x1=pomocna->first;
            y1=pomocna->second;
            return y1+((y2-y1)/(x2-x1))*(x-x1);                                 //formula koja se koristi za procjenu
        } else {
            throw std::range_error("Argument izvan opsega");
        }
    };
}

template <typename FunkcijskiTip>
std::function<double (double)> LinearnaInterpolacija(FunkcijskiTip f, double x_min, double x_max, double delta_x)
{
    if(x_min>x_max || delta_x<=0)
        throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double, double>> novi_cvorovi;                        //prvo se kreira vektor cvorova
    while(x_min<=x_max) {
        novi_cvorovi.push_back(std::make_pair(x_min,f(x_min)));
        x_min+=delta_x;
    }
    return LinearnaInterpolacija(novi_cvorovi);                                 //novi vektor saljemo prvoj verziji fje za interpolaciju
}

int main ()
{
    for(;;) {
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin>>opcija;
        if(!std::cin) break;
        if(opcija==1) {
            std::cout<<"Unesite broj cvorova: ";
            int br_cvorova;
            std::cin>>br_cvorova;
            std::cout<<"Unesite cvorove kao parove x y: ";
            std::vector<std::pair<double, double>> cvorovi(br_cvorova);
            for(int i=0; i<br_cvorova; i++)
                std::cin>>cvorovi[i].first>>cvorovi[i].second;
            try {                                                               //provjera da li je vektor ispravan
                auto f(LinearnaInterpolacija(cvorovi));
            } catch (std::domain_error izuzetak) {
                std::cout<<izuzetak.what()<<std::endl;
                return 0;
            } 
            for(;;) {
                double argument;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                std::cin>>argument;
                if(!std::cin) return 0;
                try {
                    std::cout<<"f("<<argument<<") = "
                             <<LinearnaInterpolacija(cvorovi)(argument)<<std::endl;
                }  catch (std::domain_error izuzetak) {
                    std::cout<<izuzetak.what()<<std::endl;
                }  catch (std::range_error izuzetak) {
                    std::cout<<izuzetak.what()<<std::endl; 
                }
            }
        } else if(opcija==2) {
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x_min, x_max, delta_x;
            std::cin>>x_min>>x_max>>delta_x;
            //???
            try {                                                               //hvatanje izuzetka ako nisu poslani dobri parameti
                auto f(LinearnaInterpolacija(funkcija, x_min, x_max, delta_x));
            } catch (std::domain_error izuzetak) {
                std::cout<<izuzetak.what()<<std::endl;
            }
            for(;;) {                                                           //beskonacna for petlja
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double argument;
                std::cin>>argument;
                if(!std::cin) return 0;                                         //prekid kada se unese sto nije broj
                try {
                    std::cout<<"f("<<argument<<") = "<<funkcija(argument)
                             <<" fapprox("<<argument<<") = "
                             <<LinearnaInterpolacija(funkcija, x_min, x_max, delta_x)(argument)
                             <<std::endl;
                } catch (std::domain_error izuzetak) {
                    std::cout<<izuzetak.what()<<std::endl;
                    return 0;
                } catch (std::range_error izuzetak) { 
                    std::cout<<izuzetak.what()<<std::endl;
                }
            }
        }
    }
    return 0;
}