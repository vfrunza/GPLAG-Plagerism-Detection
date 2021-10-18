/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include<vector>
#include<stdexcept>
#include<functional>
#include<cmath>
#include<algorithm>

using namespace std;
typedef pair<double,double> par;

template<typename t>
void namjesti(t &it1, double  x,const vector<pair<double,double>> &k){
    it1=k.begin();
    it1=lower_bound(k.begin(), k.end(), x,[](std::pair<double, double> const & x, double d){ return x.first < d; });
    if(it1->first!=x)it1--;
}

template<typename t>
void iteratori(t &it1, t &it2,double  x,const vector<pair<double,double>> &k){
     pair<double,double>p(x,0);
        namjesti(it1,x,k);
        it2=k.begin();
        it2=upper_bound(k.begin(), k.end(),p,[](pair<double,double> lhs, pair<double,double> rhs)  { return lhs.first < rhs.first; });
    
}

bool provjera(vector<pair<double,double>> k){
    for(int i=0;i<k.size()-1;i++) 
        if(k.at(i).first==k.at(i+1).first) return false;
    return true;
}

function<double(double)> LinearnaInterpolacija(vector<pair<double,double>>k) {
    sort(k.begin(),k.end(),[](pair<double,double> a, pair<double,double> b){ return a.first<b.first;});
    
    if(!provjera(k)) throw domain_error("Neispravni cvorovi");
    function<double(double)>f;
    
  
    f=[k](double x) {
        if(x<k.at(0).first) throw domain_error("Argument izvan opsega");
        if(x>k.at(k.size()-1).first) throw domain_error("Argument izvan opsega");
        double y=0;
        if(x==k.at(k.size()-1).first) return k.at(k.size()-1).second;
        auto it1=k.begin(), it2=k.begin();
       iteratori(it1,it2,x,k);
        y=it2->second + (x-it2->first)*((it1->second-it2->second)/(it1->first-it2->first));
        return y;

        };
    
    return f;
}

bool provjera(double mi, double ma, double delta){
    if(delta<=0 || mi>ma) return false;
    return true;
}

std::vector<pair<double,double>> vekt(){
    int n;
    cout<<"Unesite broj cvorova: ";
                    cin>>n;
                    cout<<"Unesite cvorove kao parove x y: ";
                    vector<pair<double,double>> k(n);
                    for(int i=0; i<k.size();i++){
                        pair<double,double> pom;
                        cin>>pom.first;
                        cin>>pom.second;
                        k.at(i)=pom;
                         
                    }
            return k;
}

function<double(double)>LinearnaInterpolacija(double f(double), double mi, double ma, double delta){
    if(!provjera(mi,ma,delta)) throw domain_error("Nekorektni parametri");
    vector<par> k;
     while(1){
          if(!(mi>ma)) {
            pair<double,double> pom;
            pom.first=mi;
            pom.second=f(mi);
            k.push_back(pom);
            mi+=delta; continue;
          }
          else break;
     }
     return LinearnaInterpolacija(k);

}

double fun(double x){
    return x*x+sin(x);
}

void opcija(int n){
    try{
         cout<<"Unesite krajeve intervala i korak: ";
                    double i,j,k;
                    cin>>i>>j>>k;
                    auto f=LinearnaInterpolacija(fun,i,j,k);
                    for(;;) {
                         cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                         double arg;
                         cin>>arg;
                         if(cin){
                         try{
                            cout<<"f("<<arg<<") = "<<arg*arg+sin(arg)<<" fapprox("<<arg<<") = "<<f(arg)<<endl; 
                         }catch(domain_error r) { cout<<r.what()<<endl; }
                         }
                         else {std::cin.ignore(10000, '\n');break;}
                    }
        
    }
    catch(domain_error iz) { throw domain_error(iz.what());}
}


int main ()
{ 
 
     try{
          int n;
               cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
               cin>>n;
               if(n==1)
               {
                    vector<pair<double,double>> k=vekt();
                    auto f=LinearnaInterpolacija(k);
                    
                    for(;;) {
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    
                    double arg;
                    cin>>arg;
                    if(cin){
                        try{
                            cout<<"f("<<arg<<") = "<<f(arg)<<endl; 
                        } catch(domain_error r) { cout<<r.what()<<endl; }
                    }
                    else { std::cin.ignore(10000, '\n');break;}
                  }
          
               }
               else
               {
                   opcija(10);
               }
     }
     catch(domain_error iz) { cout<<iz.what();}
    
	return 0;
}
