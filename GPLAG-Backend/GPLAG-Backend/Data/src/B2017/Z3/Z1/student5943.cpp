
#include<iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;


 double funkcija (double x) {
        return x*x;
    }


int Pronadi(double x, std::vector<std::pair<double, double>> p) {

    int poc(0),kraj(p.size());
    int sred;
    while(poc<=kraj){
    sred=((poc+kraj)/2);
        if(sred==5){
        if(p[sred-1].first < x){
            return sred;
        }
        else if(p[sred-1].first > x) kraj=sred-1;
        
        else poc=sred+1;    
        }else if(sred==0){
            if( p[sred].first>=x){
                return sred;
            }
            else if( p[sred].first>x) kraj=sred-1;
        
            else poc=sred+1;
        
        }else{
            
        if(p[sred-1].first < x && p[sred].first>=x){
            return sred;
        }
        else if(p[sred-1].first > x && p[sred].first>x) kraj=sred-1;
        
        else poc=sred+1;
    }}
    return -1 ;    
}



std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double, double>> p){
	auto v(p);
        sort(v.begin(),v.end(),[](const pair<double,double> &x,const pair<double,double> &y){
            
            return x.first<y.first;
        });
    
        for(int i(1);i<v.size();i++){
            if(v[i].first==v[i-1].first) throw domain_error("Neispravni cvorovi");
        }
        


	

      return [v](double vr){
	int i(Pronadi(vr,v));
	if(i==-1) throw std::range_error("Argument izvan opsega");
        if(i==v.size()) i--;
        if(i==0)i++;
  	 if(vr==v[v.size()-1].first) return v[v.size()-1].second;  
        return v[i].second + (v[i+1].second-v[i].second)/(v[i+1].first-v[i].first)*(vr-v[i].first);
       
    };
}

std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double xmin,double xmax, double korak){
	std::vector<std::pair<double, double>> parovi;
	if( korak<= 0 || xmin > xmax) throw domain_error ("Nekorektni parametri");
	double vrijednost=xmin;
	int i=0;
	while(true){
		double y(f(vrijednost));
		parovi.push_back(std::make_pair(vrijednost,y));
		i++;
		vrijednost+=korak;
		if(vrijednost>xmax)break;
	}
     return [parovi](double vr){
	int i(Pronadi(vr,parovi));
	if(i==-1) throw std::range_error("Argument izvan opsega");
        if(i==parovi.size()) i--;
        if(i==0)i++;
  	if (vr==parovi[parovi.size()-1].first)  return parovi[parovi.size()-1].second ; 
        return parovi[i].second + (parovi[i+1].second-parovi[i].second)/(parovi[i+1].first-parovi[i].first)*(vr-parovi[i].first);
       
    };

}



int main (){
    
    
   
    
    double opcija, broj_cv, argument,korak,a,b;
   vector<pair <double,double>> p;
    
  cout<<  "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija):";
  
  
  while  (cin>>opcija ){
   
  if (opcija==1){
  
    cout<<" Unesite broj cvorova:";
  cin>>broj_cv;
    cout<<" Unesite cvorove kao parove x y:";
    double prvi, drugi;
    for(int i=0; i<broj_cv; i++){
        
        cin>> prvi;
        cin>> drugi;
        
p.push_back(make_pair(prvi , drugi));
        
    }
              cout<<" Unesite argument (ili ""kraj"" za kraj):";

   while( cin>> argument){
          

     auto f(LinearnaInterpolacija( p));
       double rezultat =f(argument);
       cout<<"f("<<argument<<") = "<<rezultat;
       cout<< endl;
                 cout<<"Unesite argument (ili ""kraj"" za kraj): ";

       }
    
  }
  
  if(opcija == 2) {
      cout<<" Unesite krajeve intervala i korak:";
      cin>> a;
      cin>>b;
      cin>> korak;
                cout<<" Unesite argument (ili \"kraj"\ za kraj):";

      while(cin>>argument){

      cin>> argument;
      
      auto f(LinearnaInterpolacija (funkcija ,a,b,korak));
     double rezultat = f(argument);
     cout<<"f("<<argument<<") = "<<rezultat;
     cout<<endl;
               cout<<"Unesite argument (ili ""kraj"" za kraj): ";

      }
  }
   
  }
    

    
    return 0;
} 
