#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>
#include <functional>
#include <cmath>


using std::cin;
using std::cout;
using std::endl;
using std::domain_error;
using std::pair;
using std::vector;
using std::function;
using std::make_pair;


double F(double x){
    return x*x+sin(x);
}

int Abaskus(int i, int d, bool temp){
        if(temp){
           if(d>1)return d;
           else return 1;
        }

        if(!temp){
              if(i<d)return i;
              else return d;
         }
}
/*
function<double(double)> BaricentricnaInterpolacija(double fija(double),double xmin,double xmax,double deltax,int d){

    if(deltax<=0 or xmin>xmax)throw domain_error("Nekorektni parametri"); //baciti izuzetak
    
    
    vector<pair<double,double>> Parovi;
    
    int brojac=0
  for(double i=xmin;i<xmax;i+=deltax){
      brojac++;
  }
    Parovi.resize(brojac);
    int koordinata=0;
    for(double i=xmin;i<xmax;i+=deltax){
                    double a=i;
                    double b=fija(i);
                    Parovi[koordinata]=make_pair(a,b);
                    koordinata++;
    }
    
    int n=Parovi.size();
    vector<double>wow;

    Parovi.insert(Parovi.begin(), pair<double,double> (0,0));   
   for(int i=1;i<Parovi.size();i++){
    int poc=Abaskus(1, i-d, true)
    int kraj=Abaskus(1, Parovi.size()-1-d, false);
    double suma=0;    
    for(int k=poc;k<=kraj;k++){
        double p=1;        
        for(int j=k;j<=k+d;j++)if(i!=j) p*=(1./(v[i].first-v[j].first));
        if((k-1)%2!=0) p=p*(-1);
        suma+=p;
    }
    
    wow.push_back(suma);
    
        
  }
    
    return [Parovi,d,n,xmin,xmax,deltax,fija,wow](double x){
    
    
        
        double suma1=0.0,suma2=0.0;
        
        
        for(int i=0;i<n;i++){
         
         if(fabs(x-v[i].first)==0) return Parovi[i].second;
        
            double pomoc=(wow[i]/(x-Parovi[i].first));
          
            suma1=suma1+pomoc*Parovi[i].second;
            suma2=suma2+pomoc;
        }
        
        return suma1/suma2;
        
        
    };
    
    
 }
*/

function<double(double)> BaricentricnaInterpolacija(vector<pair<double, double>> parovi, int d){
    
        if(d<0 || d>parovi.size()) throw domain_error ("Nedozovljen red");
        for(int i=0; i<parovi.size();i++){
                for(int j=i+1; j<parovi.size();j++){
                        if(fabs(parovi[i].first-parovi[j].first)==0 ) throw domain_error ("Neispravni cvorovi");
                }
        }
        
       int n(parovi.size());
      
       
    return[parovi, d, n](double a){
            double suma(0), suma1(0), suma2(0);
            vector<double>Wi;
            auto parovi1=parovi;
            parovi1.insert(parovi1.begin(), pair<double, double> (0, 0));
            for(int i=1; i<=parovi.size();i++){
                     int pocetak(Abaskus(1, i-d, true));
                     int kraj(Abaskus(i, parovi.size()-d, false));
                    suma=0;
                    for(int j=pocetak; j<=kraj; j++){
                            double p=1;
                            for(int k=j; k<=j+d; k++){
                                    if(i!=k){
                                            p*=(1./(parovi[i-1].first-parovi[k-1].first));
                                    }
                            }
                            if(j%2==0) p*=(-1);
                            suma+=p;
                    }
                    Wi.push_back(suma);
            }
            for(int i=1; i<=n; i++){
                    if(fabs(a-parovi[i-1].first)==0) return parovi[i-1].second;
                    double temp=(Wi[i-1]/(a-parovi[i-1].first));
                    suma1+=temp*parovi[i-1].second;
                    suma2+=temp;
            }
            return suma1/suma2;
    };
}

int main (){
        try{
            vector<pair<double, double>> Parovi;
            int izbor;
            do{
                cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): "<<endl;
                cin>>izbor;
                if(izbor==1){
                    cout<<"Unesite broj cvorova: ";
                    int broj_cv;
                    cin>>broj_cv;
                    pair<double, double> par;
                    for(int i(0); i<broj_cv; i++){
                        cin>>par.first;
                        cin>>par.second;
                        Parovi.push_back(par);
                    }
                    
                    
                    
                    cout<<"Unesite stepen interpolacije: "<<endl;
                    int red_inter;
                    cin>>red_inter;
                    
                    auto f(BaricentricnaInterpolacija(Parovi, red_inter));
                    
                    while(1){
                        cin.clear();
                        cin.ignore(10000, '\n');
                        
                        cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<"za kraj): "<<endl;
                        double arg;
                        cin>>arg;
                        if(!cin){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            break;
                        }
                        else cout<<"f("<<arg<<")="<<f(arg);
                    }
                    break;
                }
                if(izbor==2){
                    cout<<"Unesite krajeve intervala i korak: ";
                    double a, b, c;
                    cin>>a>>b>>c;
                    cout<<"Unesite red interpolacije: ";
                    int d;
                    cin>>d;
                     auto f(BaricentricnaInterpolacija(F, a, b, c, d));
                    while(1){
                        cin.clear();
                        cin.ignore(10000, '\n');
                        
                        cout<<"Unesite argument (ili "<<'"'<<"kraj"<<'"'<<"za kraj): "<<endl;
                        double arg;
                        cin>>arg;
                        if(!cin){
                            cin.clear();
                            cin.ignore(1000, '\n');
                            break;
                        }
                        else cout<<"f("<<arg<<")="<<f(arg);
                    }
                }
                
                
            }while(1);
            
        }
        catch(domain_error izuzetak){
            cout<<izuzetak.what();
        }
        /*cout<<"Unesite cvorove kao parove x y:";
        vector<pair<double, double>> parovi;
        pair<double, double> par;
        double x, y;
        for(int i=0; i<5; i++){
                cin>>x>>y;
                par.first=x;
                par.second=y;
                parovi.push_back(par);
        }
        int d=2;
        auto f=BaricentricnaInterpolacija(parovi, d);
        
        cout<<f(2.5);
        
        auto f(BaricentricnaInterpolacija({{1, 3}, {2, 5}, {4, 4}, {5, 2}, {7, 1}}, 2));
        std::cout << f(2.5);
        */
	return 0;
}