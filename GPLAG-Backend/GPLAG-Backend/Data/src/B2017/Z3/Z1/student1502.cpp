#include <iostream>
#include <functional>
#include <stdexcept>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;
double fija(double x){
    return x*x+sin(x);
}



function<double(double)> LinearnaInterpolacija(vector<pair<double,double>> v){
    
    //Provjeriti sortiranje
    sort(v.begin(),v.end(),[](pair<double,double> a,pair<double,double> b){
        return a.first<b.first;
    });

    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(fabs(v[i].first-v[j].first)==0){
                throw domain_error("Neispravni cvorovi");
            }
        }
    }
    
    

    
    return [v](double x){
        if(x<v[0].first or x>v[v.size()-1].first)throw range_error("Argument izvan opsega");
        int i=0;
        
        while(i<v.size()-1){
            if(v[i].first<=x and v[i+1].first>=x){
                return v[i].second+((v[i+1].second-v[i].second)/(v[i+1].first-v[i].first))*(x-v[i].first);
            }
            i++;
        }
        
        
    };
    
    
    
}


function<double(double)> LinearnaInterpolacija(double fija(double),double xmin,double xmax,double deltax){

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
    
    
    
    return [v](double x){
         if(x<v[0].first or x>v[v.size()-1].first)throw range_error("Argument izvan opsega");
          int i=0;
        
       while(i<v.size()-1){
            if(v[i].first<=x and v[i+1].first>x){
                return v[i].second+((v[i+1].second-v[i].second)/(v[i+1].first-v[i].first))*(x-v[i].first);
            }
            i++; 
            
        }
       
        
        
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
                
                
                auto f(LinearnaInterpolacija(v));
              
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
              
              auto f1(LinearnaInterpolacija(fija,a,b,c));
             
              
              for(;;){
                cin.clear();
                cin.ignore(1000,'\n');
                
                
                cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<" za kraj): ";
                double argument;
                cin>>argument;
                if(cin.fail()!=true){
                    try{
                    cout<<"f("<<argument<<") = "<<fija(argument)<<" fapprox("<<argument<<") = "<<f1(argument)<<endl;
                    }catch(range_error hehe){
                            cout<<hehe.what()<<endl;
                    }
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