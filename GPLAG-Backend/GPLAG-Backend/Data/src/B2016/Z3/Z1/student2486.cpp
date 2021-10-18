/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include<limits>
#include <utility>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::function;
using std:: pair;
using std::domain_error;
double my(double s)
{
    return s*s+sin(s);   //potrebna funkcija
}


function <double(double)> BaricentricnaInterpolacija (vector<pair<double,double>> cvor, int red)
{

    if(red<0 || red>=cvor.size())throw domain_error("Nedozvoljen red");
    for(int i(0); i<cvor.size(); i++) {
        for(int j(i+1); j<cvor.size(); j++) {
            if(cvor[i].first==cvor[j].first)throw domain_error("Neispravni cvorovi");
        }
    }//bacanje izuzetaka

    vector<double> wi(cvor.size());
    for(int i(1); i<=cvor.size(); i++) {

        wi[i-1]=0;
        int max;
        int min;
        if(1>i-red) {//odredjivanje intervala
            max=1;
        } else max=i-red;
        if(i<(cvor.size()-red)) {
            min=i;
        } else min=cvor.size()-red;
        for(int j=max; j<=min; j++) {
            double h=1; //proizvod pa mora jedan jer je neutralni element

            for(int k=j; k<=j+red; k++) {
                if(k-1!=i-1)h=h/(cvor[i-1].first-cvor[k-1].first);
            }
            if(j%2==0)h=h*(-1);

            wi[i-1]=wi[i-1]+h;
        }
    }

    return [wi,cvor,red](double realnavrijednost) {//vracanje lambda funkcije u kojoj smo zarobili wi, cvor i red
        double rezultat1,rezultat2,suma1(0),suma2(0);
        for(int i(0); i<cvor.size(); i++) {
            if(cvor[i].first==realnavrijednost)return cvor[i].second;
        }
        for(int i(1); i<=cvor.size(); i++) {
            rezultat1 = (wi[i-1]/(realnavrijednost-cvor[i-1].first))*cvor[i-1].second;
            suma1=suma1+rezultat1;
            rezultat2 =wi[i-1]/(realnavrijednost-cvor[i-1].first);
            suma2=suma2+rezultat2;
        }
        return (suma1/suma2);//vracamo kolicnik
    };
}

function <double(double)> BaricentricnaInterpolacija(double funkcijica(double),double xmin,double xmax,double deltax,int red)
{
    if(xmin>xmax || deltax<=0)throw domain_error("Nekorektni parametri");
    vector <pair<double,double>> cvor;
    double sada=xmin;
    while(sada<=xmax) {
        cvor.push_back(pair<double,double>(sada,funkcijica(sada)));

        sada=sada+deltax;

        if(sada>xmax)break; }

    return BaricentricnaInterpolacija(cvor,red);
    //vracamo poziv funkcije


}
int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
    if(opcija==1) {
        cout<<"Unesite broj cvorova: ";
        int brojcvorova;
        cin>>brojcvorova;
        vector<pair<double,double>> cvor;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i(0); i<brojcvorova; i++) {
            double x,y;
            cin>>x;
            cin>>y;
            cvor.push_back(pair<double,double>(x,y));
        }

        cout<<"Unesite red interpolacije: ";
        int redinterpolacije;
        cin>>redinterpolacije;
        try {
            auto fja(BaricentricnaInterpolacija(cvor,redinterpolacije));
            double argument;
            while(cin) {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";

                cin>>argument;
                if(!cin)break;
                cout<<"f("<<argument<<") = "<<fja(argument)<<endl;

            }
        } catch(domain_error izuzetak) {
            cout<<izuzetak.what();
        }
    } else if(opcija==2) {
        cout<<"Unesite krajeve intervala i korak: ";
        double kraj1,kraj2,korak;
        cin>>kraj1>>kraj2>>korak;
        cout<<"Unesite red interpolacije: ";
        int redinterpolacije;
        cin>>redinterpolacije;

        double argument;
        try {
            auto molimteproradi=BaricentricnaInterpolacija(my,kraj1,kraj2,korak,redinterpolacije);
            while(cin) {
                cout<<"Unesite argument (ili \"kraj\" za kraj): ";

                cin>>argument;
                if(!cin)break;

                cout<<"f("<<argument<<") = "<<my(argument)<<" fapprox("<<argument<<") = "<<molimteproradi(argument)<<endl;
            }
        } catch(domain_error izuzetak) {
            cout<<izuzetak.what();
            return 0;
        }
    }
    return 0;
}