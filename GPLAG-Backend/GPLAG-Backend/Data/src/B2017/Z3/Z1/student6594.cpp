/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<double,double> par;
typedef function<double(double)> op;

void asist(vector<par> &v)
{
     sort(v.begin(), v.end(),[](par a, par b){return a.first<b.first;});
}

bool test(vector<par> &v)
{
     for(int i=0; i<v.size()-1; i++) 
          if(v.at(i).first==v.at(i+1).first) return false;
     return true;
}

bool testin(const vector<par> &v, double &x)
{
     return (x<v.at(0).first || x>v.at(v.size()-1).first);
}

op LinearnaInterpolacija(vector<par> v)
{
     asist(v);
     if(!test(v))
          throw domain_error("Neispravni cvorovi");
     return [v](double x)
     {
          par p(x,0);
          double y=1;
          if(testin(v,x)) throw range_error("Argument izvan opsega");
          if(x!=v.at(v.size()-1).first) 
          {
               auto it1=lower_bound(v.begin(), v.end(), x,[](std::pair<double, double> const & x, double d){ return x.first < d; });
              // 
               if(it1->first!=x)
                    it1--;//cout<<it1->first<<endl;
               
               auto it2=upper_bound(v.begin(), v.end(),p,[](pair<double,double> lhs, pair<double,double> rhs)  { return lhs.first < rhs.first; });
               
                    // cout<<it2->first<<endl;
//cout<<it1->first<<" "<<it2->first;
              
               y=it2->second + (x-it2->first)*((it1->second-it2->second)/(it1->first-it2->first));
          }
          else y=v.at(v.size()-1).second; 
          return y;
     };
}

op LinearnaInterpolacija(double f(double), double xmin, double xmax, double dx)
{
     if(xmin>xmax || dx<0) throw domain_error("Nekorektni parametri");
     vector<par> v;
     for(;;){
          if(xmin>xmax) break;
          v.push_back(make_pair(xmin,f(xmin)));
          xmin+=dx;
          
          
     }
   
     //cout<<endl;
     return LinearnaInterpolacija(v);
}

int main ()
{
     int n;
     try{
               cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
               cin>>n;
               if(n==1)
               {
                    cout<<"Unesite broj cvorova: ";
                    cin>>n;
                    cout<<"Unesite cvorove kao parove x y: ";
                    vector<pair<double,double>> v(n);
                    for(int i=0; i<n; i++){
                         cin>>v.at(i).first; 
                         cin>>v.at(i).second;
                    }
                    auto f=LinearnaInterpolacija(v);
                    for(;;) {
                    cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    
                    double ai;
                    cin>>ai;
                    if(cin){
                        try{
                            cout<<"f("<<ai<<") = "<<f(ai)<<endl; 
                        } catch(range_error r) { cout<<r.what()<<endl; }
                    }
                    else {std::cin.clear(); std::cin.ignore(10000, '\n');break;}
                  }
          
               }
               else if(n==2)
               {
                    cout<<"Unesite krajeve intervala i korak: ";
                    double a,b,c;
                    cin>>a>>b>>c;
                    auto f=LinearnaInterpolacija([](double x){return x*x+sin(x);},a,b,c);
                    for(;;) {
                         cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                         double ai;
                         cin>>ai;
                         if(cin){
                         try{
                            cout<<"f("<<ai<<") = "<<ai*ai+sin(ai)<<" fapprox("<<ai<<") = "<<f(ai)<<endl; 
                         }catch(range_error r) { cout<<r.what()<<endl; }
                         }
                         else {std::cin.clear(); std::cin.ignore(10000, '\n');break;}
                    }
               }
     }
     catch(domain_error iz) { cout<<iz.what();}
     catch(...) {}
	return 0;
}
