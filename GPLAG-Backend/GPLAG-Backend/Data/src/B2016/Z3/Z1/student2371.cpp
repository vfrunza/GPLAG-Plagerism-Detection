/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <stdexcept>
#include<vector>
#include<utility>
#include<pair>
#include<functional>
using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::domain_error;
using std::function;

int maksimum(d){
    if (d<1) return 1;
    else return d;
}
int minimum(i, d){
    if (d<i) return d;
    else i;
}

function<> <BaricentricnaInterpolacija(vector<pair<double, double>> v, int d){
    if (d<=0 || d> v.size()) throw domain_error ("Nedozvoljen red");
    for(int i(0);i<v.size(); i++){
        for (int j(i+1); j<v.size(); j++){
            if (fabs(v[i].first-v[j].first)==0) throw domain_error("Neispravni cvorovi");
        }
    }
   return[](double x){
       for(int i=1; i<n; i++){
           double wi=0;
           for (int k=maksimum(i-d); k<=minimum(i, n-d); k++){
               double p=1;
               for (int j=k; j<=k+d; j++){
                   if(j!=i)
                   p=(p/x[i]-x[j]);
               }
               if (k%2==0);
               p=-p;
           }
        }
        wi+=p;
        p=0;
        q=0;
        for (i=0; i<n; i++){
            if x=x;
        }
   }; 
}


int main ()
{
	return 0;
}