/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <stdexcept>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;

const double epsilon {1e-7};

double f(const double &x, const double &x1, const double &x2, const double &y1, const double &y2)
{

    return {y1 + ((y2-y1)/(x2-x1))*(x-x1)};

}


std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> v)
{

    std::sort(v.begin(),v.end());

    for(int i=0; i<v.size()-1; i++) {
        auto xi_yi(v.at(i));
        if(std::lower_bound(v.begin()+i+1,v.end(),xi_yi)->first-xi_yi.first<epsilon) throw std::domain_error ("Neispravni cvorovi");
    }

    return [v] (double x) {



        if(x<v.at(0).first || x>v.at(v.size()-1).first) throw std::range_error ("Argument izvan opsega");


        auto x2_i_y2(*(std::lower_bound(v.begin(),v.end(),std::make_pair(x,0.))));
        auto p( std::upper_bound( v.begin(),v.end(),std::make_pair(x,0.)) );
        p--;
        auto x1_i_y1(*p);

        if(x1_i_y1==x2_i_y2) return x1_i_y1.second;

        return f(x,x1_i_y1.first,x2_i_y2.first,x1_i_y1.second,x2_i_y2.second);

    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> funkcija, const double &xmin, const double &xmax, const double &h)
{

    if(xmin>xmax || h<=0) throw std::domain_error ("Nekorektni parametri");

    std::vector<std::pair<double,double>> vektor_cvorova;
    for(int i=0; i<=((xmax-xmin)/h); i++) {
        vektor_cvorova.push_back(std::make_pair(xmin+i*h,funkcija(xmin+i*h)));
    }



    return [vektor_cvorova,funkcija] (double x) {


        if(x<vektor_cvorova.at(0).first || x>vektor_cvorova.at(vektor_cvorova.size()-1).first) throw std::range_error ("Argument izvan opsega");


        auto x2_i_y2(*(std::lower_bound(vektor_cvorova.begin(),vektor_cvorova.end(),std::make_pair(x,0.))));
        auto x1_i_y1(*(std::upper_bound(vektor_cvorova.begin(),vektor_cvorova.end(),std::make_pair(x,0.))-1));

        if(x1_i_y1==x2_i_y2) return x1_i_y1.second;

        return f(x,x1_i_y1.first,x2_i_y2.first,x1_i_y1.second,x2_i_y2.second);

    };
}




int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;

    if(opcija==1) {
        int br_cvorova;
        cout<<"Unesite broj cvorova: ";
        cin>>br_cvorova;
        cout<<"Unesite cvorove kao parove x y: ";
        std::pair<double,double> cvor;
        std::vector<std::pair<double,double>> vektor_cvorova;
        for(int i=0; i<br_cvorova; i++) {
            cin>>cvor.first>>cvor.second;
            vektor_cvorova.push_back(cvor);
        }
        try {
            auto f(LinearnaInterpolacija(vektor_cvorova));

            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;

            while(cin>>argument) {
                try {
                    cout<<"f("<<argument<<") = "<<f(argument)<<endl;
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                }

                catch(std::domain_error izuzetak1) {
                    cout<<izuzetak1.what()<<endl;
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                } catch(std::range_error izuzetak2) {
                    cout<<izuzetak2.what()<<endl;
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                }
            }
        }

        catch(std::domain_error izuzetak1) {
            cout<<izuzetak1.what()<<endl;
        } catch(std::range_error izuzetak2) {
            cout<<izuzetak2.what()<<endl;
        }
    }
    else {
        cout<<"Unesite krajeve intervala i korak: ";
        double x_min,x_max,h;
        cin>>x_min>>x_max>>h;

        try {

            auto fapprox ( LinearnaInterpolacija ( [] (double x) { return x*x + std::sin(x); },x_min,x_max,h) );

            cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double argument;

            while(cin>>argument) {
                try {
                    auto rezultat(fapprox(argument));
                    cout<<"f("<<argument<<") = "<<[] (double x) {return x*x + std::sin(x);}(argument);
                    cout<<" fapprox("<<argument<<") = "<<rezultat<<endl;
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                }

                catch(std::domain_error izuzetak1) {
                    cout<<izuzetak1.what()<<endl;
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                } catch(std::range_error izuzetak2) {
                    cout<<izuzetak2.what()<<endl;
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                }
            }
        } 
        catch(std::domain_error izuzetak1) {
            cout<<izuzetak1.what()<<endl;
        } 
        catch(std::range_error izuzetak2) {
            cout<<izuzetak2.what()<<endl;
        }
    }

    return 0;
}
