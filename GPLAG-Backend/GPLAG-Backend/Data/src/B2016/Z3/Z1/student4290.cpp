#include <iostream>
#include <vector>
#include <stdexcept>
#include <functional>
#include <utility>
#include <cmath>
double f(double d){
    return d*d+(std::sin(d));
}
int mini(int a,int b){
    int m=a;
    for(int i=a;i<b;i++)if(i<m)m=i;
    return m;
}
int maxi(int a,int b){
    int m=a;
    for(int i=a;i<b;i++)if(i>m)m=i;
    return m;
}
bool Jel(std::vector<std::pair<double,double>> v){
    for(int i=1;i<v.size();i++)if(v[i].first==v[0].first)return true;
    return false;
}
std::vector<double> FloaterHorman(const std::vector<std::pair<double,double>> &v,int d){
    int n=v.size();
    std::vector<double> sume;
    for(int i=0;i<n;i++){
        double suma(0);
        for(int k=maxi(1,i-d);k<mini(i,n-d);k++){
            double proizvod(1);
            for(int j=k;j<k+d;j++){
                if(i==j)continue;
                proizvod*=1/(v[i].first-v[j].first);
            }
            suma+=std::pow(-1,k-1)*proizvod;
        }
        sume.push_back(suma);
    }
    return sume;
}
std::function<double(double)> BaricentricnaInterpolacija(const std::vector<std::pair<double,double>> &cvorovi,int d){
    if(d>cvorovi.size() || d<0)throw std::domain_error("Nedozvoljen red");
    if(Jel(cvorovi))throw std::domain_error("Neispravni cvorovi");
    std::vector<double> w=FloaterHorman(cvorovi,d);
    return[cvorovi,d,w](double x){
        auto suma1=(w[1]/(x-cvorovi[1].first))*cvorovi[1].second;
        auto suma2=w[1]/(x-cvorovi[1].first);
        for(int i=2;i<w.size();i++){
            suma1+=(w[i]/(x-cvorovi[i].first))*cvorovi[i].second;
            suma2+=w[i]/(x-cvorovi[i].first);
        }
        return(suma1/suma2);
    };
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,double xmin,double xmax,double dx,int d){
    if(xmin>xmax || dx<0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> c;
    for(double i=xmin;i<xmax;i+=dx){
        c.push_back(std::make_pair(i,f(i)));
    }
    std::vector<double> w=FloaterHorman(c,d);
    return[c,d,w](double x){
        auto suma1=(w[1]/(x-c[1].first))*c[1].second;
        auto suma2=w[1]/(x-c[1].first);
        for(int i=2;i<w.size();i++){
            suma1+=(w[i]/(x-c[i].first))*c[i].second;
            suma2+=w[i]/(x-c[i].first);
        }
        return(suma1/suma2);
    };
}
int main (){
    int opcija;
    std::cout<<"Odaberite opciju ( 1 - unos cvorova, 2 - aproksimacija ) : ";
    std::cin>>opcija;
    if(opcija==1){
        int br;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>br;
        std::vector<std::pair<double,double>> c;
        std::cout<<"Unesite cvorove kao parove x y: ";
        double a,b;
        for(int i=0;i<br;i++){
            std::cin>>a >>b;
            c.push_back(std::make_pair(a,b));
        }
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        double argument;
        while(std::cin){
            std::cout<<"Unesite argument (ili ""kraj"" za kraj): ";
            std::cin>>argument;
            if(!(std::cin))break;
            auto f=BaricentricnaInterpolacija(c,d);
            std::cout<<"f("<<argument<<") = "<<f(argument)<<std::endl;
        }
    }
    else if(opcija==2){
        double mn,mx,dx;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>mn >>mx >>dx;
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        double argument;
        while(std::cin){
            std::cout<<"Unesite argument (ili ""kraj"" za kraj): ";
            std::cin>>argument;
            if(!std::cin)break;
            auto g=BaricentricnaInterpolacija(f,mn,mx,dx,d);
            std::cout<<"f("<<argument<<") = "<<f(argument)<<" fapprox("<<argument<<") = "<<g(argument)<<std::endl;
        }
    }
    
	return 0;
}