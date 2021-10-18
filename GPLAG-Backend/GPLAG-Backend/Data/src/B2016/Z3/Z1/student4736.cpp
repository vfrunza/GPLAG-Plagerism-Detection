/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <set>

using namespace std;

bool JesuLiJednaki(double x, double y, double Eps = 1e-10)
{
    return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
}


function<double(double)> BaricentricnaInterpolacija(std::vector< pair<double,double> >parovi , int d)
{

    if(d<0||d>=parovi.size()) throw domain_error("Nedozvoljen red");

    set<double>s;
    for (int i = 0; i < parovi.size(); i++) {
        s.insert(parovi[i].first);
    }

    if(s.size()!=parovi.size()) throw domain_error("Neispravni cvorovi");


    std::vector<double> tezinski_koeficijenti;

    for (int i = 1; i <= parovi.size(); i++) {

        int pocetak = i-d;
        if(pocetak<1) pocetak=1;

        int kraj = parovi.size()-d;
        if(i<kraj) kraj=i;

        double tezinskiKoeficijent=0;

        for (int k = pocetak; k<= kraj; k++) {
            double p = 1;
            if((k-1)%2==1)p*=-1; // (-1)^(k-1)

            for (int j = k; j <= k+d; j++) {
                if(j==i)continue;

                p *= 1/(parovi[i-1].first - parovi[j-1].first);

            }



            tezinskiKoeficijent += p;

        }

        tezinski_koeficijenti.push_back(tezinskiKoeficijent);


    }

    return [parovi,tezinski_koeficijenti](double x) {
        for (int i = 0; i < parovi.size(); i++) {
            if(JesuLiJednaki(x,parovi[i].first)) return parovi[i].second;
        }

        double brojnik = 0;
        double nazivnik = 0;

        for (int i = 1; i <= parovi.size(); i++) {
            brojnik+= (tezinski_koeficijenti[i-1]*parovi[i-1].second)/(x-parovi[i-1].first);
        }

        for (int i = 1; i <= parovi.size(); i++) {
            nazivnik+= (tezinski_koeficijenti[i-1])/(x-parovi[i-1].first);
        }


        return brojnik/nazivnik;
    };
}

function<double(double)> BaricentricnaInterpolacija(function<double(double)> f,double xMin, double xMax, double deltaX, int d )
{
    if(xMin>xMax||deltaX<=0) throw domain_error("Nekorektni parametri");
    vector< pair<double,double> >parovi;

    for(double x=xMin; x<=xMax; x+=deltaX) {
        double y = f(x);
        parovi.push_back(make_pair(x,y));
    }

    return BaricentricnaInterpolacija(parovi,d);
}

double mojaFunkcija(double x)
{
    return x*x+sin(x);
}
int main ()
{
    try {
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        cin>>opcija;

        if(opcija==1) {

            cout<<"Unesite broj cvorova: ";
            int brojCvorova;
            cin>>brojCvorova;
            cout<<"Unesite cvorove kao parove x y: ";
            vector<pair<double,double>>parovi;
            for (int i = 0; i < brojCvorova; i++) {
                double x,y;
                cin>>x>>y;
                parovi.push_back(make_pair(x,y));
            }
            cout<<"Unesite red interpolacije: ";
            int d;
            cin>>d;


            function<double(double)>f = BaricentricnaInterpolacija(parovi,d);




            do {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>ws;
                double broj;
                cin>>broj;
                if(!cin)break;

                cout<<"f("<<broj<<") = "<<f(broj)<<endl;


            } while(true);

        } else if(opcija==2) {

            cout<<"Unesite krajeve intervala i korak: ";
            double xMin,xMax,deltaX;

            cin>>xMin>>xMax>>deltaX;
            cout<<"Unesite red interpolacije: ";
            int d;
            cin>>d;

            function<double(double)>f = BaricentricnaInterpolacija(mojaFunkcija,xMin,xMax,deltaX,d);



            do {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                cin>>ws;
                double broj;
                cin>>broj;
                if(!cin)break;
                cout<<"f("<<broj<<") = "<<mojaFunkcija(broj);
                cout<<" fapprox("<<broj<<") = "<<f(broj)<<endl;


            } while(true);

        }
    } catch(domain_error e) {
        cout<<e.what()<<endl;
    }

    return 0;
}