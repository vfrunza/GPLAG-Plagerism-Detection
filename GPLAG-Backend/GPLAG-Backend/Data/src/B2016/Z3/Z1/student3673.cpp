/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <stdexcept>

using namespace std;

function <double(double)> BaricentricnaInterpolacija(vector<pair<double,double>>vp,int d){
   if(d<0 || d>vp.size())throw domain_error("Nedozvoljen red");
   for(int i=0;i<vp.size();i++){
       if(vp[i].first==vp[i].second)throw domain_error("Neispravni cvorovi");
   }
   int max_ind=1,pamti_i;
   int min_razlika=d;
   for(int i=0;i<vp.size();i++){
       if(i-d<min_razlika && i-d>0){min_razlika=i-d;pamti_i=i;}
   }
   //max_ind je k ustvari
   for(int i=1;i<min_razlika;i++){
       if(i>max_ind)max_ind=i;
   }
   int min_ind=pamti_i;
   for(int i=pamti_i;i<vp.size()-d;i++){
       if(i>min_ind)min_ind=i;
   }
   double prozivod=1;
   for(int m=0;m<vp.size();m++){
   for(int k=max_ind,k<min_ind;k++){
       for(int i=1;i<vp.size();i++){
           for(int j=k;j<k+d;j++){
               if(i==j)continue;
               proizvod*=1/(vp[m].first)
           }
       }
   }
 }
    vector<pair<double,double>>vrati;
    double tezinski_koef;
    
}

int main ()
{
	return 0;
}