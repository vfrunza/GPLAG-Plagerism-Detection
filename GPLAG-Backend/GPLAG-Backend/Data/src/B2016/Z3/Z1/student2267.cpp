/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <utility>
#include <vector>
#include <cmath>
#define epsilon 0.0001

double f(double x)
{
    return x*x+std::sin(x);
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvor,int d)
{

    if(d<0 || d>=cvor.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0;i<cvor.size()-1;i++){
        for(int j=i+1;j<cvor.size();j++){
            if(cvor[i].first==cvor[j].first)    throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::vector<double>vektor_suma;
    double w_suma;
    int i(1);
    int max,min;
    while(i<=cvor.size()) {
        double iks=cvor[i-1].first;
        int razlika_max=i-d;

        //Trazenje maximuma
        if(razlika_max>=1)    max=razlika_max;
        else    max=1;

        //Trazenje minimuma
        int razlika_min=cvor.size()-d;
        if(razlika_min<=i)    min=razlika_min;
        else                 min=i;

        w_suma=0;
        for(int k=max; k<=min; k++) {
            double w_proizvod(1);
            int j=k;
            //Racunanje proizvoda
            while(j<=(k+d)) {

                if(j==i || std::fabs(iks-cvor[j-1].first)<epsilon)  {
                    j++;
                    continue;
                }

                w_proizvod=w_proizvod*(1./(iks-cvor[j-1].first));

                j++;
            }

            //Suma ogromna
            w_suma+=(double)pow(-1,k-1)*w_proizvod;

        }
        vektor_suma.push_back(w_suma);

        i++;
    }

    return [vektor_suma,cvor](double x) {
        double brojnik(0),nazivnik(0),rezultat;
        for(int i=1; i<=cvor.size(); i++) {
            if(std::fabs(x-cvor[i-1].first)<epsilon) return cvor[i-1].second;
            brojnik=brojnik+((vektor_suma[i-1]*cvor[i-1].second)/(x-cvor[i-1].first));
            nazivnik=nazivnik+((vektor_suma[i-1])/(x-cvor[i-1].first));
            rezultat=brojnik/nazivnik;
        }

        return rezultat;
    };

}

std::function<double(double)> BaricentricnaInterpolacija(double fun(double),double min_x,double max_x,double prirastaj_x,int d)
{

    std::function<double(double)>nova_funkcija;
    if(min_x>max_x || prirastaj_x<=0)   throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> kreirani_cvorovi;
    double sum(min_x);
    while(sum<=max_x) {
        double y=fun(sum);
        kreirani_cvorovi.push_back(std::make_pair(sum,y));
        sum=sum+prirastaj_x;
    }
    if(d<0 || d>=kreirani_cvorovi.size()) throw std::domain_error("Nedozvoljen red");
    nova_funkcija=BaricentricnaInterpolacija(kreirani_cvorovi,d);

    return nova_funkcija;

}

int main ()
{

    int broj_cvorova;
    double x,y;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int odaberi;   
    std::cin>>odaberi; 
    std::vector<std::pair<double,double>> v_cvor;
    if(odaberi==1) {
        
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>broj_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
      
        int brojac(0);
        while(brojac<broj_cvorova) {
            std::cin>>x>>y;
            v_cvor.push_back(std::make_pair(x,y));
            brojac++;
        }
        
    
        int red;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>red;
        double argument;
        try{
            
            for(;;) {
            BaricentricnaInterpolacija(v_cvor,red);
            std::cout<<"Unesite argument (ili "<<"\"kraj\""<<" za kraj): ";
            if(!(std::cin>>argument))
                break;
            std::function<double(double)> funkcija=BaricentricnaInterpolacija(v_cvor,red);   
            std::cout<<"f("<<argument<<")"<<" = "<<funkcija(argument);
            std::cout<<std::endl;
            std::cin.ignore(1000,'\n');

        }
        }
     
       catch(std::domain_error poruka){
            std::cout<<poruka.what();
      
        }
        
    }
    
 
    else if(odaberi==2) {
        std::vector<std::pair<double,double>> v_cvor_;
        double min,max,korak;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>min>>max>>korak;
        std::cout<<"Unesite red interpolacije: ";
        int red;
        std::cin>>red;
        double argument;

        std::function<double(double)> fun;
        try{
        fun=BaricentricnaInterpolacija(f,min,max,korak,red);  
        for(;;) {
            std::cout<<"Unesite argument (ili "<<"\"kraj\""<<" za kraj): ";
            if(!(std::cin>>argument))
                break;
            std::cout<<"f("<<argument<<")"<<" = "<<f(argument)<<" fapprox("<<argument<<")"<<" = "<<fun(argument);
            std::cout<<std::endl;
            std::cin.ignore(1000,'\n');
        }
  
        }
  catch(std::domain_error poruka){
            std::cout<<poruka.what();
        
        }
        
  
  
}



    return 0;
}

