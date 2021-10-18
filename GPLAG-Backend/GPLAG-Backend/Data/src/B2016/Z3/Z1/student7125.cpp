/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include <cmath>
#include <stdexcept>

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> par,int d);
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun,double x, double y, double dx,int d);
int minmax(int a,int b, bool izbor);
int prebroj(std::vector<std::pair<double,double>> par);

int main ()
{
    try{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int k,d;
    double n,z;
    double x,y;
    std::cin>>k;
    std::vector<std::pair<double,double>> par;
    if(k == 1){
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>n;
        par.resize(n);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i(0); i < n; i++)
        std::cin>>par[i].first>>par[i].second;
        
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
    }
    else if(k == 2){
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>x>>y>>z;
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>d;
    }
    while(true){
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        if(!(std::cin>>n)) break;
      
        if(k == 1)
        std::cout<<"f("<<n<<") = "<<BaricentricnaInterpolacija(par,d)(n);
        
        else if(k == 2){
            auto fun(BaricentricnaInterpolacija([](double x){return double(x*x + std::sin(x));},x,y,z,d));
        std::cout<<"f("<<n<<") = "<<n*n +std::sin(n)<<" fapprox("<<n<<") = "<<fun (n);
        }
        std::cout<<std::endl;
        
    }}catch(std::domain_error error){
        std::cout<<error.what();
    }

    return 0;
}

std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> par,int d)
{
    if (d < 0 || d >= par.size()) throw std::domain_error("Nedozvoljen red");
    if(prebroj(par) > 1)
        throw std::domain_error("Neispravni cvorovi");
    
    //računanje težinskih koeficijenata, pomocna funkcija minmax vrać najveći broj između neka dva ako je treca proslijeđena varijable = true, u suprotnom vraća najmanji    
    std::vector<double> w(par.size());
    for(int i(0); i < par.size(); i++) {
        for(int j(minmax(1,1+i-d,true)); j <= minmax(i+1,par.size()-d,false); j++) {
            double proizvod(1);
                for(int f(j-1); f < j+d; f++) {
                    if(f != i)
                        proizvod *= 1/(par[i].first - par[f].first);
                }
            if(((j-1)%2) == 0) w[i] += proizvod;
            else w[i] -= proizvod;
        }
    }
    //kraj
    
    return [w,par](double x) {
        double brojnik(0),nazivnik(0);
        const double EPS(0.000000000000001);
        for(int i(0); i < par.size(); i++) {
        //ako  x -> xi onda  f(x) -> f(xi)
            if(std::fabs(x - par[i].first) < EPS)
                return par[i].second;
            //izračunaj brojnik i nazivnik   
            
            brojnik += (w[i]*par[i].second)/(x - par[i].first);
            nazivnik += (w[i])/(x - par[i].first);
        }
        //vrati količnik brojnika i nazivnika (one formule)
        return brojnik/nazivnik;
    };
}
std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun,double x, double y, double dx,int d){
    if(x>y || dx<=0) throw std::domain_error("Nekorektni parametri");
    
  double k(0);
  std::vector<std::pair<double,double>> par;
  //nađi sve parove u nekom segmentu
  while(x+k*dx<=y){
      par.push_back({x+k*dx,fun(x+k*dx)});
      k++;
  }
  //iskoristi već postojeću funkciju za računanje
  return BaricentricnaInterpolacija(par,d);
}

int minmax(int a,int b, bool izbor)
{
    //ako je izbor == true vrati veći od dva broja, inače vrati manji
    if(izbor) {
        if(a > b)
            return a;
        else return b;
    } else {
        if(a < b)
            return a;
        else return b;
    }
}

int prebroj(std::vector<std::pair<double,double>> par){
    int br(1);
    const double EPS(0.0000000000001);
    for(int i(0); i < par.size(); i++)
        for(int j(i+1); j < par.size(); j++)
            if(std::fabs(par[i].first - par[j].first) < EPS)
                br++;
    //nađi koliko ima istih x-ova među parovima, (ako je br = 1 znači da nema istih)
    return br;
            
}