#include <iostream>
#include <functional>
#include <cmath>
#include <vector>
#include <utility>
#include <stdexcept>
#include <limits>
#include <iomanip>
const double epsilon(1e-9);

double f(double x){
    return x*x+std::sin(x);
}

double Tezinski_koeficijenti(std::vector<std::pair<double,double>> cvorovi,int i,int mmax,int mmin,int d ){
     double s=0;
     double p;
    for(int k=mmax;k<=mmin;k++){
        p=1;
        for(int j=k;j<=k+d;j++){
            if(j!=i && cvorovi[i-1]!=cvorovi[j-1])p=p/(cvorovi[i-1].first-cvorovi[j-1].first);
        }
        if(k%2==0)p=p*(-1);
    s+=p;
    }
    return s;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> cvorovi,int d){
    if(d<0 || d>cvorovi.size())throw std::domain_error ("Nedozvoljen red");
    for(int i=0;i<cvorovi.size();i++){
            double kopija=cvorovi[i].first;
            for(int j=i+1;j<cvorovi.size();j++)if (fabs(kopija-cvorovi[j].first)<epsilon) throw std::domain_error("Neispravni cvorovi");break;
    }
    return [cvorovi,d](double x){
        double suma=0;
        int mmin=0;
        int mmax=0;
        double suma1=0;
        double suma2=0;
        double s=0;
        int n=cvorovi.size();
        for(int i=1;i<=n;i++){
           
           if (i<n-d)mmin=i; 
           else mmin=n-d;
          
           if(1<i-d)mmax=i-d;
           else mmax=1;
          
           s=Tezinski_koeficijenti(cvorovi,i,mmax,mmin,d);
          
           
           if(fabs(x-cvorovi[i-1].first)<epsilon) return cvorovi[i-1].second;
               suma=s/(x-cvorovi[i-1].first);
               suma1+=suma*cvorovi[i-1].second;
               suma2+=suma;
        }
      
        return suma1/suma2;
    };
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fapprox,double xmin,double xmax,double deltax,int d){
    if(xmax<xmin || deltax<=0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> cvor;
    std::pair<double,double> par;
    for(double i=xmin;i<=xmax;i=i+deltax){
        par.first=i;
        par.second=fapprox(i);
        cvor.push_back(par);
    }
    return [cvor,d](double x){
    auto fun=BaricentricnaInterpolacija(cvor,d);
    return fun(x);
    };
}
int main ()
{
   try{
  int m,n,d;
  double x,y,arg;
  std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
  std::cin >> m;
  if(m==1){
      std::vector<std::pair<double,double>> v;
      std::pair<double,double> par;
      std::cout << "Unesite broj cvorova: ";
      std::cin>> n;
      std::cout << "Unesite cvorove kao parove x y: ";
      for(int i=0;i<n;i++){
      std::cin >> x >> y;
      par=std::make_pair(x,y);
      v.push_back(par);
      }
      std::cout << "Unesite red interpolacije: ";
      std::cin >> d;
      for(;;){
          std::cout << "Unesite argument (ili ""\"kraj""\" za kraj): ";
          std::cin >> arg;
          if(!arg)break;
          auto f=BaricentricnaInterpolacija(v,d);
          std::cout <<"f("<<arg<<") = "<< f(arg)<<std::endl;
          
      }}
    else if(m==2){
        std::cout << "Unesite krajeve intervala i korak: ";
        double a,b,korak;
        double arrg;
        std::cin >> a>>b>>korak;
        std::cout << "Unesite red interpolacije: ";
        int dd;
        std::cin >> dd;
        for(;;){
        std::cout << "Unesite argument (ili ""\"kraj""\" za kraj): ";
        std::cin >> arrg;
        if(!arrg) break;
        auto ff= BaricentricnaInterpolacija(f,a,b,korak,dd);
        std::cout << "f"<<"("<<arrg<<") = "<<f(arrg)<<" fapprox("<<arrg<<") = "<<ff(arrg)<<std::endl;
        }
    }
    }catch(std::domain_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}
