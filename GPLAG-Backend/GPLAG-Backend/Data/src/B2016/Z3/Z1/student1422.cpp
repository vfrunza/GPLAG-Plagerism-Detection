#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <utility>
#include <cstring>
#include <string>
#include <iomanip>
#include <cmath>

typedef std::vector<std::pair<double,double>> VektorParova;
typedef std::pair<double,double> Par;
typedef std::vector<double> Vektor;

double W(VektorParova v, int d, int i){
    int n=int(v.size());
    if(d>=0 && d<n){
        double suma(0),proizvod(1.);
            for(int k=std::max(1,i-d);k<=std::min(i,n-d);k++){
                proizvod=1.;
                for(int j=k;j<=k+d;j++){
                    if(j!=i){
                    proizvod*=1./(v[i-1].first-v[j-1].first);
                    }
                }
            if (k%2==0) suma+=(-1)*proizvod;
            else suma+=1*proizvod;
            }
    return suma;
    }
}

std::function<double(double)> BaricentricnaInterpolacija(VektorParova v, int d){
    if(d<0 || d>int(v.size())) throw std::domain_error("Nedozvoljen red");
    return [v,d](double x){
        int n(int(v.size()));
        double suma1(0),suma2(0);
        for(int i=1;i<=n;i++){
            
            if(i!=n)
            if(x==v[i].first) return v[i].second;
            
            double w(W(v,d,i));
            std::cout<<"w["<<i<<"]="<<w<<std::endl;
            suma1+=(w*v[i-1].second)/(x-v[i-1].first);
            suma2+=w/(x-v[i-1].first);
        }
    return suma1/suma2;};
}

std::function<double(double)> BaricentricnaInterpolacija(double f(double),double xmin,double xmax,double dx,int d){
    if(xmin>xmax || dx<=0) throw std::domain_error("Nekorektni parametri");
    VektorParova cvorovi(0);
    Par tmp;
    for(double i=xmin;i<xmax;i+=dx){
        tmp=std::make_pair(i,f(i));
        cvorovi.push_back(tmp);
    }
    return BaricentricnaInterpolacija(cvorovi,d);
}

double KonkretnaFunkcija(double x){
    return x*x+std::sin(x);
}

int main (){
    /*try{
    int opcija;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1){
    int broj_cvorova;
    std::cout<<"Unesite broj cvorova: ";
    std::cin>>broj_cvorova;
    VektorParova v;
    std::cout<<"Unesite cvorove kao parove x y: ";
    for(int i=0;i<broj_cvorova;i++){
        int x,y;
        std::cin>>x;
        std::cin>>y;
        v.push_back(std::make_pair(x,y));
    }
    int red_interpolacije;
    std::cout<<"Unesite red interpolacije: ";
    std::cin>>red_interpolacije;
    do{
        double argument;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cin>>argument;
        if(std::cin.fail()) break;
        std::cout<<"f("<<argument<<") = ";
        auto f(BaricentricnaInterpolacija(v,red_interpolacije)); 
        std::cout<<f(argument)<<std::endl;
    }while(1);
    }
    else if(opcija==2){
        double pocetak, kraj, korak;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>pocetak>>kraj>>korak;
        int red;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>red;
        do{
        double argument;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cin>>argument;
        if(std::cin.fail()) break;
        std::cout<<"f("<<argument<<") = ";
        auto f(BaricentricnaInterpolacija(KonkretnaFunkcija,pocetak,kraj,korak,red)); 
        std::cout<<KonkretnaFunkcija(argument)<<" "<<"fapprox("<<argument<<") = "<<f((argument))<<std::endl;
    }while(1);
    }
    } catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }*/
    auto f(BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, 2));
        std::cout << f(2.5);
	return 0;
}