/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream>
#include<utility>
#include<vector>
#include<functional>
#include<stdexcept>
#include<cmath>
int mini(int i, int n, int d){
    
    if(i<(n-d)) return i;
    else return n-d;
    
}
int maxi(int i, int d){
    if((i-d)>1) return i-d;
    else return 1;
}

int minjed(int k)
{
    if(k%2==0) return 1;
    else return -1;
}
double w(std::vector<std::pair<double,double>> a,int i,int d){
    
    double w1(0);
    
    
    int n(a.size());
    
    for(int k=maxi(i,d);k<=mini(i,n,d);k++){
        
       int p(minjed(k-1));
        
        double proizvod(1);
        
        for(int j=k;j<=k+d;j++){
            if(j==i) continue;
            
            
            proizvod*=(1./(a[i-1].first-a[j-1].first));
            
        
        }
        
        
    w1+=p*proizvod;
    

    }

    
return w1;
    
}

std::vector<double> wi(std::vector<std::pair<double,double>> a,int d){
    
    std::vector<double>v;
    
    for(int i=1;i<=a.size();i++){
        v.push_back(w(a,i,d));
        
    }
    
    return v;
}


std::function<double(double)>pomocna1(std::vector<std::pair<double,double>> a,int i, int d,std::vector<double> v){

    std::function<double(double)> f([a,i,d,v](double x){
      
        return (v[i-1]*a[i-1].second)/(x-a[i-1].first);
    });

    return f;
    
}
std::function<double(double)> pomocna2(std::vector<std::pair<double,double>> a ,int i,int d,std::vector<double> v){
    return [a,i,d,v](double x){
       
        return (v[i-1]/(x-a[i-1].first));
    };
}
std::function<double(double)> saberi(std::function<double(double)> f,std::function<double(double)> g){
    return [f,g](double x){ return f(x)+g(x);
        
    };
    
}


std::function<double(double)> podijeli(std::function<double(double)>f, std::function<double(double)>g, std::vector<std::pair<double,double>> a){
    
    const double Eps(1e-10);
    
    return[f,g,a,Eps](double x){
        for(int i=0;i<a.size();i++){
             if(std::fabs(x-a[i].first)<=Eps) {
                 auto f1([a,i](double x){return a[i].second*x;});
                 auto g1([](double x){return x;});
                 return f1(x)/g1(x);
                 
             }
         }
         
        return f(x)/g(x);
    };
}

bool legalno_d(int d,int n){
    
    return d>=0 && d<n ;
}

bool legalan_a(std::vector<std::pair<double,double>> a){
   
   const double Eps(1e-10);
   
    for(int i=0;i<a.size()-1;i++){
        
        for(int j=i+1;j<a.size();j++){
            if(std::fabs(a[i].first-a[j].first)<=Eps)
            {
                return false;
            }
        }
    }
    return true;
}



std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> a,int d){
    
   int n(a.size());
   
   if(!(legalno_d(d,n))) throw std::domain_error("Nedozvoljen red");
   
   
  if(!(legalan_a(a))) throw std::domain_error("Neispravni cvorovi");
  
  
  auto w(wi(a,d));
  
  
  
     auto h1(pomocna1(a,1,d,w));  
     auto h2(pomocna2(a,1,d,w));
 
    
     for(int i=2;i<=n;i++){
         
         h1=saberi(h1,pomocna1(a,i,d,w));
         h2=saberi(h2,pomocna2(a,i,d,w));
         
     }
     
     auto q(podijeli(h1,h2,a));
     
     
     return q;
}

std::function<double(double)>BaricentricnaInterpolacija(std::function<double(double)> f,double xmin,double xmax,double deltax,int d){
    
    if(xmin>xmax || deltax<=0) throw std::domain_error("Nekorektni parametri");
    
    
    
    std::vector<std::pair<double,double>> a;
    
    for(double i=xmin; i<=xmax;i=i+deltax){
        
        a.push_back(std::make_pair(i,f(i)));
    }

    
   return BaricentricnaInterpolacija(a,d);
    
}


int main ()
{
    
   std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
   
   int z;
   
   std::cin>>z;
   
   try{
   if(z==1){
       int n;
       std::cout<<"Unesite broj cvorova: ";
       std::cin>>n;
       
       std::cout<<"Unesite cvorove kao parove x y: ";
       
       std::vector<std::pair<double,double>> a;
       
       for(int i=0;i<n;i++){
           
           double a1,a2;
           std::cin>>a1;
           std::cin>>a2;
           
           a.push_back(std::make_pair(a1,a2));
           
       }
       
       std::cout<<"Unesite red interpolacije: ";
       int d;
       std::cin>>d;
       double k;
        char m('"');
       for(;;){
       std::cout<<"Unesite argument (ili "<<m<<"kraj"<<m<<" za kraj): ";
      
       std::cin>>k;
       if(!std::cin){
        std::cin.clear();
        std::cin.ignore(10000,'\n');
        break;
       }
       auto f(BaricentricnaInterpolacija(a,d));
       std::cout<<"f("<<k<<") = "<<f(k)<<std::endl;
       

       }
       
      


       
   }
   if(z==2){
       std::cout<<"Unesite krajeve intervala i korak: ";
       double xmin,xmax,deltax;
       std::cin>>xmin>>xmax>>deltax;
       std::cout<<"Unesite red interpolacije: ";
       int d;
       std::cin>>d;
       double k;
       char n('"');
       
       for(;;){
           std::cout<<"Unesite argument (ili "<<n<<"kraj"<<n<<" za kraj): ";
           std::cin>>k;
           if(!std::cin){
               std::cin.ignore();
               std::cin.ignore(10000,'\n');
               break;
           }
           auto f(BaricentricnaInterpolacija([xmin,xmax,deltax,d](double x){return x*x+std::sin(x);},xmin,xmax,deltax,d));
           auto g([](double x){ return x*x+::std::sin(x);});
           std::cout<<"f("<<k<<") = "<<g(k);
           std::cout<<" fapprox("<<k<<") = "<<f(k)<<std::endl;
       }
   }
  
   }
   catch(std::domain_error poruka){
       std::cout<<poruka.what()<<std::endl;
   }
   
    
	return 0;
}