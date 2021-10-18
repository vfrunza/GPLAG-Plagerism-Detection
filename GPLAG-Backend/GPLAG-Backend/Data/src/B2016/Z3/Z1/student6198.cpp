/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <cmath>
#include <algorithm>
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double, double>> v, int d) {
    if(d<0 || d>v.size()) throw std::domain_error("Nedozvoljen red");
    for(int i=0; i<v.size()-1; i++){
        if(v[i].first==v[i+1].first && v.size()!=0 && v.size()!=1) throw std::domain_error ("Neispravni cvorovi");//moze izaci izvan opsega za 1 ili 0 clanova
    } 
    if(v[v.size()].first==v[v.size()-1].first) throw std::domain_error ("Neispravni cvorovi");
    int pom=1; 
    int clan=0;
    for(int i=0; i<v.size(); i++){
        
        for(int k=fmax(1,i-d); k<=fmin(i,v.size()-d);k++){
            
        
        for(int j=fmax(1,i-d);j<fmax(1,i-d)+d;j++){
            if(j!=i){
            double pom1=1/(v[i].first-v[j].first);
            pom*=pom1;
           
            } 
        }
        clan+=pow(-1,k-1)*pom;
        
    }
    }
     //ovdje imam w[i]=clan
    //ovdje ide poziv druge funkcije-one gornje 
    //x je onoo sto joj posaljemo
    
    /*for(int h=0; h<v.size();h++){
        double brojnik=0;
        double nazivnik=0;
        brojnik+=(clan*v[i].second)/(x-v[i].first);
        nazivnik+=clan/(x-v[i].first);
        double rez= brojnik/nazivnik;
        
    }
    */
    return [clan,v] (double x){
        /*double brojnik=0;
        double nazivnik=0;
       
        
        brojnik+=(clan*v[i].second)/(x-v[i].first);
        nazivnik+=clan/(x-v[i].first);*/
        for(int h=0; h<v.size();h++){
        double brojnik=0;
        double nazivnik=0;
        brojnik+=(clan*v[h].second)/(x-v[h].first);
        nazivnik+=clan/(x-v[h].first);
         
    
        
        return brojnik/nazivnik;
       
    };
}
   
    



std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> f,int xmin, int xmax, double delta, int d){
    if(xmin>xmax || delta<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double, double>> v;
    int pom=2;
    v.push_back(std::make_pair(xmin,f(xmin)));//oovo je opet opseg!!!!!!
    for(int i=xmin; i<xmax;i++){
        v.push_back(std::make_pair(xmin+delta,f(xmin)));
        delta=delta*pom;
        pom++;
        
    }
    return BaricentricnaInterpolacija(v,d);
}


int main ()
{
    int a=0; std::cout<<a;
	return 0;
}