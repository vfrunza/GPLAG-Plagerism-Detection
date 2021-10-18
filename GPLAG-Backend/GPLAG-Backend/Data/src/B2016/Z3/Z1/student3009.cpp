/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>
std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>>v,int d){
    if(d<0 || d>=v.size())throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i].first==v[j].first)throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::function<double(double)>f;
    return[f,v,d](double x){
        for(int i=0;i<v.size();i++){
            if(x==v[i].first)return v[i].second;
        }
        int s=v.size();
        double p=0;
        for(int i=1;i<=v.size();i++){
            double w=0;
            int t=std::max(1,i-d);
            int c=std::min(i,s-d);
            for(int k=std::max(1,t);k<=c;k++){
                double p=1;
                for(int j=k;j<=k+d;j++){
                    if(j!=i)
                        p/=v[i-1].first-v[j-1].first;
                }
                if(k%2==0)
                    p=-p;
                    w+=p;
            }
            p+=(w*v[i-1].second)/(x-v[i-1].first);
        }
        double q=0;
        for(int i=1;i<=v.size();i++){
            double w=0;
            int t=std::max(1,i-d);
            int c=std::min(i,s-d);
            for(int k=std::max(1,t);k<=c;k++){
                double p=1;
                for(int j=k;j<=k+d;j++){
                    if(j!=i)
                        p*=1/(v[i-1].first-v[j-1].first);
                }
                if(k%2==0)
                    p=-p;
                    w+=p;
            }
            q+=w/(x-v[i-1].first);
        }
        return p/q;
    };
}
std::function<double(double)>BaricentricnaInterpolacija(std::function<double(double)>f,double x_min,double x_max,double delx,int  d){
    if(x_min>x_max || delx<=0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    //((x_max-x_min)/delx+1);
    //std::cout<<v.size();
    /*for(int i=0;i<v.size();i++){
        v[i].first=x_min;
        v[i].second=f(x_min);
        x_min+=delx;
    }*/
    for(double i=x_min;i<=x_max;i+=delx){
        std::pair<double,double>pom;
        pom.first=i;
        pom.second=f(i);
        v.push_back(pom);
    }
    /*std::cout<<"da vidimo :"<<v.size()<<std::endl;
    for(int i=0;i<v.size();i++)std::cout<<v[i].first<<" "<<v[i].second<<std::endl;*/
    auto r=BaricentricnaInterpolacija(v,d);
    return r;
}
double pomocna (double x) {return x * x + std::sin(x);}
int main ()
{
    /*auto f(BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, 2));
    std::cout << f(2.5)<<std::endl;
    auto s=BaricentricnaInterpolacija([](double x){return x*x+std::sin(x);},0,1,0.1,2);
    std::cout<< s(5);*/
    try{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija;
    std::cin>>opcija;
    if(opcija==1){
        std::cout<<"Unesite broj cvorova: ";
        int cvorovi;
        std::cin>>cvorovi;
        std::cout<<"Unesite cvorove kao parove x y: ";
        std::vector<std::pair<double,double>>v(cvorovi);
        for(int i=0;i<v.size();i++){
            std::cin>>v[i].first>>v[i].second;
        }
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        auto f=BaricentricnaInterpolacija(v,d);
        std::string kraj="kraj";
        double argument;
        std::string sr="Unesite argument (ili ";
            sr.push_back('"');
            sr+=kraj;
            sr.push_back('"');
            sr+=" za kraj): ";
        for(;;){
            std::cout<<sr;
            std::cin>>argument;
            if(!std::cin)break;
            std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl; 
        }
    }
    else if(opcija==2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        double x_min,x_max,delx;
        std::cin>>x_min>>x_max>>delx;
        std::cout<<"Unesite red interpolacije: ";
        int d;
        std::cin>>d;
        std::string kraj="kraj";
        std::string sr="Unesite argument (ili ";
            sr.push_back('"');
            sr+=kraj;
            sr.push_back('"');
            sr+=" za kraj): ";
        double argument;
        auto f=BaricentricnaInterpolacija(pomocna,x_min,x_max,delx,d);
        for(;;){
            std::cout<<sr;
            std::cin>>argument;
            if(!std::cin)break;
            std::cout<<"f("<<argument<<") = "<<pomocna(argument)<<" fapprox("<<argument<<") = "<<f(argument)<<std::endl; 
        }
    }
    }
    catch(std::domain_error e){
        std::cout<<"Izuzetak: "<<e.what();
    }
	return 0;
}