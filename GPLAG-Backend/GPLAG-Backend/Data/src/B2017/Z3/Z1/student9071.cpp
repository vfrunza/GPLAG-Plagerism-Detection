/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>
using std::cout;
using std::cin;
using std::pair;
using std::vector;

std::function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> cvor)
{
    std::sort(cvor.begin(),cvor.end(),[](pair<double,double> prvi ,pair<double,double> drugi) {
        return prvi.first<drugi.first;
    });

    return [cvor](double x) {
        double foo(0);
        if(x<cvor[0].first||x>cvor[cvor.size()-1].first) {
            throw std::range_error("Argument izvan opsega");
        }

        for(int i=0; i<cvor.size()-1; i++) {
            if(x==cvor[cvor.size()-1].first) {
                return cvor[cvor.size()-1].second;
            }
            if(x>=cvor[i].first&&x<cvor[i+1].first) {
                double a=cvor[i].second;
                double b=cvor[i+1].second;
                double c=cvor[i+1].first;
                double d=cvor[i].first;
                foo=a+((b-a)/(c-d))*(x-d);

                return foo;
            }




        }


        return foo;
    };
}
std::function<double(double)> LinearnaInterpolacija(double foo(double),double xminimum, double xmaksimum, double korak)
{
    if(xminimum>xmaksimum||korak<=0) {
        throw std::domain_error("Nekorektni parametri");
    }
    vector<pair<double,double>> vektor;
    double temp=xminimum;
    int i=0;
    while(temp<=xmaksimum) {
        vektor.push_back(std::make_pair(temp,foo(temp)));
        i++;
        temp+=i*korak;
    }

    return [foo,vektor,korak](double x) {
        double f=0;
        if(x<vektor[0].first||x>vektor[vektor.size()-1].first) {
            throw std::range_error("Argument izvan opsega");
        }
        if(x==vektor[vektor.size()-1].first) {
            return vektor[vektor.size()-1].second;
        }
        for(int i=0; i<vektor.size(); i++) {
            if(i+1<=(vektor.size()-1)) {
                auto it(std::lower_bound(vektor.begin(),vektor.end(),x,[](pair<double,double> prvi,double drugi) {
                    return prvi.first<drugi;
                }));


                double d=it->first;
                double a=foo(d);
                double c=it->first-korak;
                double b=foo(c);
                f=a+((b-a)/(c-d))*(x-d);
                return f;
            }
        }


        return f;
    };
}
int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
    try {
        switch(opcija) {
        case 1: {
            cin.ignore(10000,'\n');
            cout<<"Unesite broj cvorova: ";
            int broj;
            cin>>broj;

            vector<pair<double,double>> vektor;
            double x,y;

            cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0; i<broj; i++) {
                cin>>x;
                cin>>y;
                vektor.push_back(std::make_pair(x,y));
            }
            for(int i=0; i<vektor.size(); i++) {
                for(int j=i+1; j<vektor.size(); j++) {
                    if(vektor[i].first==vektor[j].first) {
                        throw std::domain_error("Neispravni cvorovi");
                    }
                }
            }

            while(true) {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                cin>>arg;
                if(!cin) {
                    return 0;
                }
                try {
                    auto foo(LinearnaInterpolacija(vektor));
                    cout<<"f("<<arg<<") = "<<foo(arg)<<"\n";
                }

                catch (std::domain_error err) {
                    cout<<err.what()<<"\n";
                } catch (std::range_error err) {
                    cout<<err.what()<<"\n";
                }
            }
        }
        break;
        case 2: {
            cin.ignore(10000,'\n');
            cout<<"Unesite krajeve intervala i korak: ";
            double xminimum,xmaksimum,korak;
            cin>>xminimum;
            cin>>xmaksimum;
            cin>>korak;
            while(true) {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                cin>>arg;
                if(!cin) {
                    return 0;
                }
                try {
                    auto foo(LinearnaInterpolacija([](double arg) {
                        return arg*arg+sin(arg);
                    },xminimum,xmaksimum,korak));
                    cout<<"f("<<arg<<") = "<<arg*arg+sin(arg)<<" fapprox("<<arg<<") = "<<foo(arg)<<"\n";
                } catch (std::domain_error err) {
                    cout<<err.what()<<"\n";
                } catch (std::range_error err) {
                    cout<<err.what()<<"\n";
                }

            }
        }
        break;
        }
    } catch (std::domain_error err) {
        cout<<err.what()<<"\n";
    }


    return 0;
}
