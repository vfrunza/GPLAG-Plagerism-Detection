/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>


const double EPS (0.00001);
using std::cin;
using std::cout;
using std::endl;

std::pair<double,double> Napravi_Parove (){
    
    double x,y;
    cin>>x>>y;
    std::pair<double,double> parovi(std::make_pair(x,y));
    return parovi;
}
std::pair<double,double> Napravi_Parove (double x, double y){
    std::pair<double,double> parovi(std::make_pair(x,y));
    return parovi;
}
bool ProvjeriParove(std::vector<std::pair<double,double>> parovi){
    for(int i(0);i<parovi.size()-1;i++){
        
        for(int j(i+1);j<(parovi.size());j++){
            if((parovi[i].first - parovi[j].first)<EPS) return true;
        }
    }
    return false;
}

std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> parovi, int d){
    if(d<0 || d>parovi.size()) throw std::domain_error("Nedozvoljen red");
    /*if(ProvjeriParove(parovi)) throw std::domain_error("Neispravni cvorovi");*/
    std::vector<double> vec;
    int k;
    int l;
    for(int i(1);i<=parovi.size();i++){
        
        if(i-d<=1) k=1;
        else k=i-d;
        if(parovi.size()-d>=i) l=i;
        else l=parovi.size()-d;
        double wi(0);
        
        for(;k<=l;k++){
            double proizvod(1);
            for(int j(k);j<=k+d;j++){
                if(j==i) continue;
                proizvod=proizvod*(1/(parovi[i-1].first-parovi[j-1].first));
            }
            wi=wi+std::pow(-1,k-1)*proizvod;
            
        }
        
        vec.push_back(wi);
    }
    return [vec,parovi](double vr){
        double gornji(0),donji(0);
      
        for(int i(0);i<parovi.size();i++){
            if(i==parovi.size()) break;
            if(std::abs(vr-parovi[i].first)<EPS){return parovi[i].second;}
            else{
            gornji=gornji+((vec[i])/(vr-parovi[i].first))*parovi[i].second;
            donji=donji+((vec[i])/(vr-parovi[i].first));
            }
        }
    
        return gornji/donji;
       
    };
}

std::function<double(double)> BaricentricnaInterpolacija (std::function<double(double)> f,double i1, double i2,double k ,int n){
    if(i1>i2 || k<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> vec;
    for(double i(i1);i2>i;i+=k){
        vec.push_back(Napravi_Parove(i,f(i)));
    }
    return [vec,n](double x){
    auto fun(BaricentricnaInterpolacija(vec,n));
    return fun(x);
};}

int main ()
{
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    cin>>opcija;
    if(opcija==1){
        cout<<"Unesite broj cvorova: ";
        int n;
        cin>>n;
        cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>> vec;
        for(int i(0);i<n;i++)
        vec.push_back(Napravi_Parove());
        
        cout<<"Unesite red interpolacije: ";
        int red;
        cin>>red;
       
        do{
        cout<<"Unesite argument (ili " << '"' << "kraj" << '"' <<" za kraj): ";
        double argument;
        cin>>argument;
        if(!cin) break;
        try{
        auto fun = BaricentricnaInterpolacija(vec, red);
            std::cout << "f("<<argument<<") = " << fun (argument)<<endl;
        }catch(std::domain_error e){
            cout<<e.what()<<endl;return 0;
        }
    }while(1);
    }else{
        
        cout<<"Unesite krajeve intervala i korak: ";
        double i1,i2,k;
        cin>>i1>>i2>>k;
        cout<<"Unesite red interpolacije: ";
        int n;
        cin>>n;
        do{
        cout<<"Unesite argument (ili " << '"' << "kraj" << '"' <<" za kraj): ";
        double argument;
        cin>>argument;
        if(!cin) break;
        try{
        auto fun = BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);}, i1, i2,k, n);
            std::cout << "f("<<argument<<") = " << argument*argument+std::sin(argument)<<" fapprox("<<argument<<") = "<<fun (argument)<< endl;
        }catch(std::domain_error e){
            cout<<e.what()<<endl;return 0;
        }
    }while(1);
    }

    return 0;
}