/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include <functional>
#include <stdexcept>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>


using namespace std;
double fija(double x){
    return x*x+sin(x);
}


int vece(int d){
    if(d>1)return d;
    else return 1;
    
}

int manje(int i, int d){
    if(i<d)return i;
    else return d;
    
}
vector<double> wi(vector<pair<double,double>> v, int d){
 
  vector<double> Wi;

    v.insert(v.begin(), pair<double,double> (0,0.0));   
   
   for(int i=1;i<v.size();i++){
    
    int poc=vece(i-d);
    int kraj=manje(i,v.size()-1-d);
    
    double suma=0;    
    for(int k=poc;k<=kraj;k++){
        double p=1;        
        for(int j=k;j<=k+d;j++)if(i!=j) p*=(1./(v[i].first-v[j].first));
        if((k-1)%2!=0) p=p*(-1);
        suma+=p;
    }
    
    Wi.push_back(suma);
    
        
  }
   return Wi;
}


function<double(double)> BaricentricnaInterpolacija(vector<pair<double,double>> v, int d){
    
    if(d<0 or d>v.size())throw domain_error("Nedozvoljen red"); //baciti izuzetak
    
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(fabs(v[i].first-v[j].first)==0){
                throw domain_error("Neispravni cvorovi");
            }
        }
    }
    
    
    int n=v.size();
    
    return [v,d,n](double x){
        
        double suma1=0.0,suma2=0.0;
        vector<double>Wi=wi(v,d);
        
        for(int i=0;i<n;i++){
         
         if(fabs(x-v[i].first)==0) return v[i].second;
        
            double pomoc=(Wi[i]/(x-v[i].first));
          
            suma1=suma1+pomoc*v[i].second;
            suma2=suma2+pomoc;
        }
        
        return suma1/suma2;
        
        
    };
    
    
    
}


function<double(double)> BaricentricnaInterpolacija(double fija(double),double xmin,double xmax,double deltax,int d){

    vector<pair<double,double>> v;
    
    
    if(deltax<=0 or xmin>xmax)throw domain_error("Nekorektni parametri"); //baciti izuzetak
    int brojac=0;
  for(double i=xmin;i<xmax;i+=deltax){
      brojac++;
  }
    v.resize(brojac);
    int koordinata=0;
    for(double i=xmin;i<xmax;i+=deltax){
                    double a=i;
                    double b=fija(i);
                    v[koordinata]=make_pair(a,b);
                    koordinata++;
    }
    
    int n=v.size();
    vector<double>wow=wi(v,d);
    
    return [v,d,n,xmin,xmax,deltax,fija,wow](double x){
    
    
        
        double suma1=0.0,suma2=0.0;
        
        
        for(int i=0;i<n;i++){
         
         if(fabs(x-v[i].first)==0) return v[i].second;
        
            double pomoc=(wow[i]/(x-v[i].first));
          
            suma1=suma1+pomoc*v[i].second;
            suma2=suma2+pomoc;
        }
        
        return suma1/suma2;
        
        
    };
    
    
 }

int main (){
    try{
    int p;
    vector<pair<double,double>> v;
    bool kraj=false;
    for(;;){
        if(kraj)break;
        cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        cin>>p;
        switch(p){
           case 1:{
                int broj_cvorova;
                cout<<"Unesite broj cvorova: ";
                cin>>broj_cvorova;
                v.resize(broj_cvorova);
                cout<<"Unesite cvorove kao parove x y: ";
                for(int i=0;i<broj_cvorova;i++){
                    double a,b;
                    cin>>a>>b;
                    v[i]=make_pair(a,b);
                }
                int red_interpolacije;
                cout<<"Unesite red interpolacije: ";
                cin>>red_interpolacije;
                auto f(BaricentricnaInterpolacija(v,red_interpolacije));
                for(;;){
                cin.clear();
                cin.ignore(1000,'\n');
                cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
                double argument;
                cin>>argument;
                if(cin.fail()!=true){
                    cout<<"f("<<argument<<") = "<<f(argument)<<endl;
                }else{
                  
                kraj=true;
                    break;
                }
            }
            break;
           }
           case 2:{
               cout<<"Unesite krajeve intervala i korak: ";
               double a,b,c;
               cin>>a>>b>>c;
              cout<<"Unesite red interpolacije: ";
              int d;
              cin>>d;
              auto f1(BaricentricnaInterpolacija(fija,a,b,c,d));
              for(;;){
                cin.clear();
                cin.ignore(1000,'\n');
                
                
                cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
                double argument;
                cin>>argument;
                if(cin.fail()!=true){
                    cout<<"f("<<argument<<") = "<<fija(argument)<<" fapprox("<<argument<<") = "<<f1(argument)<<endl;
                }else{
                   
                    kraj=true;
                    break;
                }
            }
                break;
            }
            default:
            //pogresan unos
            break;
        }
    }
    }catch(domain_error hehe){
        cout<<hehe.what();
    }
	return 0;
}