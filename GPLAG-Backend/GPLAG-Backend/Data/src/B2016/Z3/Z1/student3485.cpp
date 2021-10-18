/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)
#include <iostream> 
#include <functional>
#include <utility>
#include <vector>
#include <cmath>
#include <iterator>
//double xxsinx (double x) {return x * x + std::sin(x);}
int Max(int x,int y){
    if(x>y) return x;
    else return y;
}
int Min(int x,int y){
    if(x<y) return x;
    else return y;
}


double xsinx (double x) {return x * x + std::sin(x);}
std::function<double(double)> BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v,int red){
    if(red<0 || red>v.size()) throw std::domain_error("Nedozvoljen red");
    return [v,red]( double x){
        
        auto it1=v.begin();
        auto it2=v.end();
        for(int i=0;i<v.size();i++){
            if(v[i].first==x) return v[i].second;
            
        }
        int n=v.size();
         double suma1=0,suma2=0,suma3=0;
        double proizvod=1;
        std::vector<double>pomocni;
        
       double suma=0;
        int donja_granica,gornja_granica;
         int k,l;
    for(int i=1;i<=n;i++){
       
        int donja_granica=Max(1,i-red);
        int gornja_granica=Min(i,n-red);
        suma=0;
       
        for(int j=donja_granica;j<=gornja_granica;j++){
         k=donja_granica;
         l=red+donja_granica;
         if(j%2!=0) proizvod=1;
         else proizvod=-1;
         
          for(int t=j;t<=j+red;t++){
              if(t!=i){
                  auto it1=v.begin()+i-1;
                  auto it2=v.begin()+t-1;
               proizvod=proizvod*(1/((it1->first)-(it2->first)));
          
                  
              }
              
          }
          suma=suma+(proizvod);   
          
        }
        
        pomocni.push_back(suma);
        
    }
   suma1=0;
    for(int i=1;i<=n;i++){
        auto it1=v.begin()+i-1;
        double hasan=it1->second;
       suma1=suma1+(pomocni[i-1]*hasan)/(x-it1->first);
       
        
    }
    suma2=0;
    for(int i=1;i<=n;i++){
        auto it1=v.begin()+i-1;
        double hasan=it1->second;
       suma2=suma2+(pomocni[i-1])/(x-it1->first);
       
        
    }suma3=suma1/suma2;
  
    return suma3;
    };
    
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)> fun,double xmin,double xmax,double deltaX,int red){
   std::vector<std::pair<double,double>> v;
    if(xmin>xmax || deltaX<=0) throw std::domain_error("Nekorektni parametri");
    int i=1;
    double x=xmin;
    while(x<=xmax){
     
        std::pair<double,double> tacka;
        tacka=std::make_pair(x,fun(x));
        
        v.push_back(tacka);
        //std::cout<<x<<","<<std::endl;
         x=xmin+deltaX*i;
        i++; 
        
       
          
     } 
    
    auto f= BaricentricnaInterpolacija(v,red);
   
       return [f](double x){
          return  f(x);
  };
 }





//double xxsinx (double x) {return x * x + std::sin(x);}
int main ()
   

{ 
/*/auto fun = BaricentricnaInterpolacija(xxsinx, 0, 1, 0.05, 2);
    double tacke[] = {0.3, 0.57, 5};
    for (const auto &i : tacke)
        std::cout << "fun (" << i << ") = " << fun (i) << std::endl;/*/
try{
    int opcija,broj_cvorova,red_interpolacije;
    double argument,xmin,xmax,korak;
    std::vector<std::pair<double,double>> cvorovi;
    std::pair<double,double> parovi;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    std::cin.clear();
    if(opcija==1){
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>broj_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<broj_cvorova;i++){
            std::cin>>parovi.first;
             
            std::cin>>parovi.second;
            cvorovi.push_back(parovi);
        } 
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>red_interpolacije;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
       
       std::cin>>argument;
            if(std::cin){
        for(;;){
             
            
            
            
            auto f =BaricentricnaInterpolacija(cvorovi,red_interpolacije);
            std::cout<<"f("<<argument<<")"<<" = "<<f(argument);
            std::cout<<"\nUnesite argument (ili \"kraj\" za kraj): ";
             std::cin>>argument;
             if(!std::cin) return 0;
             
            
            
        }}
        
    }
    
       
       try {
      
       if(opcija==2){
       std::cout<<"Unesite krajeve intervala i korak: ";
       std::cin>>xmin;
       std::cin.clear();
       std::cin>>xmax;
       std::cin.clear();
       std::cin>>korak;
       std::cin.clear();
        std::cout<<"Unesite red interpolacije: ";
        std::cin>>red_interpolacije;
        std::cin.clear();
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>argument;
        if(std::cin) {for(;;){
            
        
       
        auto f1=BaricentricnaInterpolacija([](double x){return x * x+ std::sin(x);},xmin,xmax,korak,red_interpolacije);
        std::cout<<"f("<<argument<<")"<<" = "<<xsinx(argument)<<" ";
        std::cout<<"fapprox("<<argument<<")"<<" = "<<f1(argument);
       std::cout<<"\nUnesite argument (ili \"kraj\" za kraj): ";
             std::cin>>argument;
             if(!std::cin) return 0;
       
        
     
            
        
            
        }
           
            
        
        }
        
            
            
        }
    }
     catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
        return 0;}
   
      
}catch(std::domain_error izuzetak1){
        std::cout<<izuzetak1.what();
}
   /*/  auto fun = BaricentricnaInterpolacija({
        {1, 2}, {0, 4}, {-5, 2}, {11, 5},
        {3, 2}, {5, 4}, {4.3, 50}, {2, 5},
        {-3, 2}, {-4, 4}, {24.1, 25}, {12, 15}
    }, 11);
    for (double i = -8; i <= 15.1; i += 1.37)
        std::cout << "fun (" << i << ") = ", std::cout.precision(4), std::cout << std::fixed << fun (i) << std::endl;
/*/
    
    
    
	return 0;
}