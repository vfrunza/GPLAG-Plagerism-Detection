/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <vector>
#include <cmath>
#include <algorithm>
#define epsi 0.0000001

int max_element(int a, int b){
    if(b>a)return b;
    else return a;
}
int min_element(int a, int b){
    if(b>a)return a;
    else return b;
}

double Koeficijenti(std::vector<std::pair<double,double>>v, int d, int n, int i)
{
   
    
        auto maxi=max_element(1,i-d);
        auto mini=min_element(i,v.size()-d);
        double suma=0;
        for(int k=maxi;k<=mini;k++){
            double proizvod=1;
            for(int j=k;j<=k+d;j++){
                if(j!=i)
                proizvod =proizvod*( 1./(v[i-1].first- v[j-1].first));
            }
            suma+=pow(-1,k-1)*proizvod;
        }
    return suma;
}


std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>>v, int d)
{
 if(d<0 || d>=v.size())throw std::domain_error("Nedozvoljeni red");  
 /*
 for(int i(0);i<v.size()-1;i++)
 for(int j(i+1);j<v.size();j++)
 if(fabs(v[i].first-v[j].first)<epsi) throw std::domain_error("Neispravni cvorovi");
 double o1=Koeficijenti(v,d,v.size(),1);
 double a=v[0].first;
 double b=v[0].second;
 std::function<double(double)> f1=[o1,a,b](double x){return(o1*b)/(x-a);};
 std::function<double(double)> f2=[o1,a](double x){return o1/(x-a);};
 for(int i=2;i<=v.size();i++){
     a=v[i-1].first;
     b=v[i-1].second;
     double o=Koeficijenti(v,i,v.size(),d);
     f1=[f1,o,a,b](double x){return f1(x)+(o*b)/(x-a);};
     f2=[f2,o,a](double x){return f2(x)+o/(x-a);};
 }
 f1=[f1,f2,v](double x){ 
     for(int i=0;i<v.size();i++)
     if(fabs(v[i].first-x)<epsi)
     return v[i].second;
     return f1(x)/f2(x);
     
 };
 */
 std::vector<double> vec;
 vec.resize(v.size());
 for(int i=1;i<vec.size();i++){
     vec[i]=Koeficijenti(v,d,v.size(),1);
 }
 return[vec,v](double vrijednost){
     double f=0,f1(0),f2(0);
     for(int i=1;i<=v.size();i++){
         f1+=((vec[i-1]*v[i-1].second)/(vrijednost-v[i-1].first));
         f2+=(vec[i-1]/(vrijednost-v[i-1].second));
         f+=f1/f2;
     }
     return f;
 };
// return f1; 
}


template<typename NekiTip>
std::function<double(double)> BaricentricnaInterpolacija(NekiTip f, double xmin, double xmax, double delta, int d){
    std::vector<std::pair<double,double>>v;
    while(xmin<=xmax)
    {
        v.push_back(make_pair(xmin, f(xmin)));
        xmin+=delta;
    }
    std::function<double(double)>f1=BaricentricnaInterpolacija(v,d);
    return f1;
}

int main ()
{
    auto f(BaricentricnaInterpolacija({{1,3}, {2,5}, {4,4}, {5,2}, {7,1}}, 2));
    std::cout<<f(2.5);
	return 0;
}