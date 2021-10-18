#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <set>
#include <utility>
#include <cmath>
#include <stdexcept>
#include <unordered_map>

bool Imaduplih(std::vector<int>brojevi) {/* za neispravne cvorove pomocna*/
    size_t broj = brojevi.size();
    if (!broj)
        return false;
    std::unordered_map<int, int> tbl;
    for (size_t i = 0; i < broj; i++) {
        if (tbl.find(brojevi[i]) != tbl.end())
            return true;
        tbl[brojevi[i]] = 1;
    }
    return false;
}
bool Isti(double a, double b)
{
    return std::fabs(a - b) <= 1e-12;
}
int Jeasu(std::vector<std::pair<double,double>>cvorovi,const double x){/*ako x->x[i] da f(x)->y[i] */
    int t=-3;
    for(int i(0);i<cvorovi.size();i++){
         if(Isti(x,cvorovi[i].first)) t=i;;
         }
    return t;
}
double Pro (int d,int k,std::vector<std::pair<double,double>>cvorovi,const int i){
    double pro=1;
    for(int  j=k ;  j<=k+d   ;j++){
        if( j!=i ) pro*=(1./(cvorovi[i].first-cvorovi[j].first));/*memorijska greska u vezi granice dokle  j ide*/
    }
    return pro;
}

    double Suma (int d,const int brojac_i,int brojelemenata,std::vector<std::pair<double,double>>cvorovi){/*suma za tezinske ostatke*/
        int min(0),max(0);
         if(brojelemenata-d<=brojac_i) min=brojelemenata-d;
         if(brojac_i<=brojelemenata-d) min=brojac_i;
         if(brojac_i-d>=1) max=brojac_i-d;
         if(1>=brojac_i-d) max=1;
        double sum(0);
        for(int k(max);k<=min;k++){
            sum+=((std::pow(-1,k-1))*Pro(d,k,cvorovi,brojac_i));
        }
        return sum;
    }

std::function<  double(double) > BaricentricnaInterpolacija (std::vector<std::pair<double,double>>cvorovi,int d){
    if(d<0 ||  d>cvorovi.size()) throw std::domain_error  ("Nedozvoljen red");
    std::vector<int>brojaci;
    for(int i(0);i<cvorovi.size();i++){
   brojaci.push_back(cvorovi[i].first);
    }
   bool a=Imaduplih(brojaci);
   if(a)  throw std::domain_error("Neispravni cvorovi");
    std::vector<double>W(cvorovi.size());
    for(int i(1);i<=cvorovi.size();i++){
        W[i]=(Suma(d,i,cvorovi.size(),cvorovi)); /*odredjujem tezinske*/

    }
    return[W,cvorovi] (double x){  
       double summa(0);
       int n=cvorovi.size();
    for(int i=1;i<n ;i++){
        summa+=((W[i]/(x-cvorovi[i].first))*cvorovi[i].second); /*povratna suma brojnik*/
    }
    
     double suma(0);
    for(int i=1;i<n ;i++){
        if(!Isti(x,cvorovi[i].first)) suma+=(W[i]/(x-cvorovi[i].first)); /*povratna suma nazivnik*/
    
    }
    int ovo=Jeasu(cvorovi,x);
    if(ovo>=0) return cvorovi[ovo].second;
    if(ovo==-3) {return summa/suma;}/*f(x) sta vraca*/
     };
}


std::function<double(double)> BaricentricnaInterpolacija(double f(double),int xmin,int xmax,double korak,int d){
    std::vector<std::pair<double,double>>cvorovi;
    if(xmin>xmax || korak<=0 ) throw std::domain_error("Nekorektni parametri");
    return [cvorovi,d] (double x) {return x+std::sin(x);};
}

int main ()
{
    try{
    int opcija(0);
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    if(opcija!=1 && opcija!=2 ) return 0;
    if(opcija==1){
    auto f(BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, 2));
    std::cout << f(2.5);
        }
    if(opcija==2){
    auto fun = BaricentricnaInterpolacija(std::sin, 4, 1, 0.1, 2);
    std::cout<<fun(3);
    }
    }
    catch(std::domain_error e){
        std::cout<<e.what();
    }
	return 0;
}