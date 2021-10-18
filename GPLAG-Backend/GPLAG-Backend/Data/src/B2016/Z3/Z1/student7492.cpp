#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <functional>

typedef std::vector<std::pair<double,double>> VektorParova;
typedef std::vector<double> VektorDouble;

double funkcijica(double x){
    return x*x+sin(x);
}

double RacunatorOmege (VektorParova vektor, int d,int i){
    int n=vektor.size();
    double suma(0);
    double proizvod(1);
        int k;
        int a=i-d;
        if(a<=0) k=1;
        else k=a;
        int min;
        int b=n-d;
        if(i<b) min=i;
        else min=b;
       // std::cout<< i<<" je i, "<<k<< " je k "<<min<< " je krajnji"<<std::endl;
        for(int f=k;f<=min;f++){
            int pov=pow(-1,f-1);
            int c=f+d;
            for(int j=f;j<=c;j++){
              if(vektor[i-1].first==vektor[j-1].first && i-1!=j-1) throw std::domain_error("Neispravni cvorovi");
              //std::cout<<vektor[i-1].first<<std::endl;
             if(i-1!=j-1) proizvod=proizvod*(1./(vektor[i-1].first-vektor[j-1].first));
            }
           // std::cout<<pov<<" pov "<<proizvod<<" proizvod"<<std::endl;
            suma=suma+(pov*proizvod);
            proizvod=1;
        }
    
    return suma;
}
std::function<double (double)> BaricentricnaInterpolacija(VektorParova vektor, int d){
    int n=vektor.size();
    if(d<0 || d>n) throw std::domain_error("Nedozvoljen red");
    return[vektor,d,n](double x){
            double brojnik(0);
            double nazivnik(0);
            double f;
            for(int i(1);i<=n;i++){
                if(vektor[i-1].first!=x){
                brojnik=brojnik+(RacunatorOmege(vektor,d,i)/(x-vektor[i-1].first))*vektor[i-1].second;
                nazivnik=nazivnik+(RacunatorOmege(vektor,d,i)/(x-vektor[i-1].first));}
                else{
                    return vektor[i-1].second;
                }
            }
            f=brojnik/nazivnik;
        return f;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,double xmin,double xmax,double deltax,int d){
    if(xmin>xmax || deltax<=0) throw std::domain_error ("Nekorektni parametri");
    VektorParova vektor;
     double prvi=xmin;
     for(;;){
        vektor.push_back(std::make_pair(prvi,f(prvi)));
        prvi=prvi+deltax;
        if(prvi>xmax) break;
    }
    int n=vektor.size();
    if(d<0 || d>n) throw std::domain_error("Nedozvoljen red");
    return [vektor,d,f,n](double x){
            double brojnik(0);
            double nazivnik(0);
            double vrijednost;
            for(int i(1);i<=n;i++){
                if(vektor[i-1].first!=x){
                    brojnik=brojnik+(RacunatorOmege(vektor,d,i)/(x-vektor[i-1].first))*vektor[i-1].second;
                    nazivnik=nazivnik+(RacunatorOmege(vektor,d,i)/(x-vektor[i-1].first));}
                else{ return f(x);}
            }
                vrijednost=brojnik/nazivnik;
                return vrijednost;};}

int main ()
{
    int opcija=1;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija==1){
        int br_cvorova;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>br_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        VektorParova vektor;
        for(int i(0);i<br_cvorova;i++){
            double x,y;
            std::cin>>x;
            std::cin>>y;
            std::pair<double,double> p=std::make_pair(x,y);
            vektor.push_back(p);
        }
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        double x;
        for(;;){
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>x;
        if(!std::cin) return 0;
        try{
        auto f(BaricentricnaInterpolacija(vektor,d));
        double a=f(x);
        std::cout<<"f("<<x<<") = "<<a<<std::endl;
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
            return 0;
        }
    }}
    else if(opcija==2){
        double xmin,xmax,deltax;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>xmin>>xmax>>deltax;
        int d;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
        for(;;){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double x;
            std::cin>>x;
            if(!std::cin) return 0;
            try{
            auto f(BaricentricnaInterpolacija(funkcijica,xmin,xmax,deltax,d));
            double a=f(x);
            std::cout<<"f("<<x<<") = "<<funkcijica(x)<<" fapprox("<<x<<") = "<<a<<std::endl;
            }
            catch(std::domain_error e){
                std::cout<<e.what()<<std::endl;
                return 0;
            }
        }
    }
	return 0;
}

















