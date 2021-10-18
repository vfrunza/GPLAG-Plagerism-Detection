/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>

double f(double x){
    double rez;
    rez= x*x+sin(x);
    return rez;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v, int d){
    int n=v.size();
    if(d>n || d<0) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i].first==v[j].first)throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double> tezinski(n);
    for(int i=1;i<=n;i++){
        double tezinski_element(0);
        int gornja_granica(n-d);
        int donja_granica(1);
        if(i-d>donja_granica) donja_granica=i-d;
        if(i<gornja_granica) gornja_granica=i;
        
        for(int k=donja_granica;k<=gornja_granica;k++){
            double proizvod(1);
            for(int j=k; j<=k+d;j++){
                if(j==i) continue;
                proizvod*=static_cast<double>(1)/(v[i-1].first-v[j-1].first);
//                    proizvod*=1./(v[i-1].first-v[j-1].first);
            }
            proizvod*=pow(-1,k-1);
            tezinski[i-1]+=proizvod;
 //           tezinski_element+=proizvod;
  //          tezinski.push_back(tezinski_element);
        }
    }
    return[tezinski, v](double x){
        double brojnik(0), nazivnik(0);
        for(int i=0;i<v.size();i++){
            if(x==v[i].first) return v[i].second;
            double tezinski_element=tezinski[i];
            brojnik+=tezinski_element*v[i].second/(x-v[i].first);
            nazivnik+=tezinski_element/(x-v[i].first);
        }
        return brojnik/nazivnik;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f, double xmin, double xmax, double deltax, int d){
    if(xmin>xmax || deltax<=0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvorovi;
    for(double i=xmin; i<=xmax; i=i+deltax) cvorovi.push_back({i,f(i)});
    return BaricentricnaInterpolacija(cvorovi, d);
}

int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    switch(opcija){
        case 1:{
            std::vector<std::pair<double,double>> v;
            std::cout<<"Unesite broj cvorova: ";
            int br_cvorova;
            std::cin>>br_cvorova;
            std::cout<<"Unesite cvorove kao parove x y: ";
            for(int i=0;i<br_cvorova;i++){
                int x, y;
                std::cin>>x>>y;
                v.push_back(std::make_pair(x,y));
            }
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            std::string kraj("kraj");
            double arg;
            try{
                auto f(BaricentricnaInterpolacija(v, d));
                while(std::cout<<"Unesite argument (ili \"kraj\" za kraj): ",std::cin>>arg, std::cin){
                std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
                }}
            catch(std::domain_error msg){
                std::cout<<msg.what();
            }
        break;
        }
        case 2:{
            std::cout<<"Unesite krajeve intervala i korak: ";
            double kraj1, kraj2;
            double korak;
            std::cin>> kraj1>>kraj2>>korak;
            std::cout<<"Unesite red interpolacije: ";
            int inter;
            std::cin>>inter;
            double ar;
            try{
                auto fapprox(BaricentricnaInterpolacija([](double x){return x*x+sin(x);}, kraj1, kraj2, korak, inter));
                while(std::cout<<"Unesite argument (ili \"kraj\" za kraj): ",std::cin>>ar, std::cin){
                std::cout<<"f("<<ar<<") = "<<f(ar)<<
                " fapprox("<<ar<<") = "<<fapprox(ar)<<std::endl;
                }}
            catch(std::domain_error msg){
                std::cout<<msg.what();
            }
        break;
        }
    }
	return 0;
}