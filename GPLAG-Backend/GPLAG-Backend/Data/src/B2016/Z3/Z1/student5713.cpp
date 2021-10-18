/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <cmath>
#include <vector>
#include <functional>

using namespace std;
//cvor sinonim za proizvod wooow 

  double fja (double x){
        return pow(x,2)+sin(x);
    }
    


    int NadjiMini (int a, int b){
        if(a>b) return b;
        return a;
    }
    
    int NadjiMaxi (int a, int b){
        if(a>b) return a;
        return b;
    }
    
    
  
 function<double(double)> BaricentricnaInterpolacija(vector<pair<double, double>> v, int red){
     int n=v.size();
     if(red<0 || red>n) throw domain_error("Nedozvoljen red");
     
     for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if(v[i].first==v[j].first) throw domain_error("Neispravni cvorovi");
        
     vector<double> pomocni;
     double suma(0), suma2=1;
     
     for(int i=1; i<=n; i++){
         suma=0; 
         for(int k=NadjiMaxi(1, i-red); k<=NadjiMini(i, n-red); k++){
         suma2=1;
         for(int j=k; j<=k+red; j++){
             if(i-1==j-1) continue;
             suma2=suma2*(1/(v[i-1].first-v[j-1].first));
         }
         suma=suma+pow(-1, k-1)*suma2;
     }
     pomocni.push_back(suma);
     
     }

return [red, v, pomocni](double x){
    double gore=0, dole=0, konacno;
    for(int i=0; i<v.size(); i++){
        if(x==v[i].first) return v[i].second;
        gore=gore+(pomocni[i]*v[i].second)/(x-v[i].first);
        dole=dole+pomocni[i]/(x-v[i].first);
    }
    konacno=gore/dole;
    return konacno;
};
}

function<double(double)> BaricentricnaInterpolacija(double f (double), double mini, double maxi, double prirastaj, int red ){
    if(prirastaj<=0 || mini>maxi) throw domain_error("Nekorektni parametri");
    
    double i=mini;
    vector<pair<double, double>> v;
    while(1){
        if(i>maxi) break;
        v.push_back(make_pair(i, f(i)));
        i=i+prirastaj;
    }
    
    return BaricentricnaInterpolacija(v, red); 
}







int main(){
    int n, br_c, red=0;
    double poc, kraj, korak;
    vector<pair<double, double>> v;
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    cin>>n;
    int a, b;
    if(n==1){
        try{
        cout<<"Unesite broj cvorova: ";
        cin>>br_c;
        cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<br_c; i++){
        cin>>a>>b;
        v.push_back(make_pair(a,b));}
        cout<<"Unesite red interpolacije: ";
        cin>>red;
        
        
        double argument;
         while(1){
     cout<<"Unesite argument (ili \"kraj\" za kraj): ";
    
     if(!(cin>>argument)) break;
     
     cout<<"f("<<argument<<") = "<<BaricentricnaInterpolacija(v, red)(argument)<<endl;
    }
        }
    catch(domain_error nesto){
        cout<<nesto.what();
    }
        
    }
    else if(n==2){
        try{
        cout<<"Unesite krajeve intervala i korak: ";
        cin>>poc>>kraj>>korak;
        cout<<"Unesite red interpolacije: ";
        int red;
        cin>>red;
    
    double argument;
    while(1){
     cout<<"Unesite argument (ili \"kraj\" za kraj): ";
     
     if(!(cin>>argument)) break;
     cout<<"f("<<argument<<") = "<<fja(argument)<<" ";
     cout<<"fapprox("<<argument<<") = "<< BaricentricnaInterpolacija(fja, poc, kraj, korak,red )(argument)<<endl;     
     
    }}
    catch(domain_error izuzetak){
        cout<<izuzetak.what();
    }
    }

    return 0;
}