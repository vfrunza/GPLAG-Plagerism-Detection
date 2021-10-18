/B2016/2017: Zadaća 3, Zadatak 1
//Autotestovi by Enil Pajic (epajic1@etf.unsa.ba)

#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <stdexcept>
#include <cmath>

int max(int a,int b){
    if(a>=b)return a;
    else return b;
}

int min(int a,int b){
    if(a<=b)return a;
    else return b;
}


std::function<double(double)>BaricentricnaInterpolacija(std::vector<std::pair<double,double>> v,int d){
    
    if(d<0 || d>=v.size())throw std::domain_error("Nedozvoljen red");
    for(auto t = v.begin();t != v.end();t++){
        double temp = (*t).first;
        auto p =t;p++;
        for(auto q =p;q!=v.end();q++){
            if(temp==(*q).first)throw std::domain_error("Neispravni cvorovi");
        }
    }
    
    std::vector<double> tk(v.size()+1);//tezinski koeficijenti
    std::vector<double> x(v.size()+1);
    std::vector<double> y(v.size()+1);
    
    for(int i=0;i<v.size();i++)x[i+1] = v[i].first;
    for(int i=0;i<v.size();i++)y[i+1] = v[i].second;
    
    int n = v.size();
    for(int i=1;i<=n;i++){
        double suma = 0;
          
        for(int k = max(1,i-d); k <=min(i,n-d);k++ ){
          double proizvod = 1;
            for(int j=k;j<=k+d;j++){
               if(j==i)continue;
                proizvod*=(1./(x[i]-x[j])); 
               
                
            }
            suma+=(std::pow(-1,k-1))*proizvod;
        }
        tk[i] = suma;
    }
    
    std::function<double(double)>f1 = [n,x,y,tk](double t){
        double suma = 0;
        for(int i=1;i<=n;i++){
            if(t==x[i]){suma=0;suma+=y[i];return suma;}
           suma+=((tk[i])/(t-x[i]))*y[i];
           
        }
        return suma;
    };
    
    std::function<double(double)>f2 = [n,x,y,tk](double t){
        double suma = 0;
        for(int i=1;i<=n;i++){
           if(t==x[i]){suma=1;return suma;}
    
           suma+=(tk[i]/(t-x[i]));
           
        }
        return suma;
    };
    
    
   
    return [f1,f2](double t){return f1(t)/f2(t);};
}

std::function<double(double)> BaricentricnaInterpolacija(std::function<double(double)>fun,double x_min,double x_max,double deltax,int d){
    if(x_min > x_max || deltax<=0)throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double>> v;
    
   //PRVI NACIN ,koji ne radi !
   /*
   double q = 0;
    for(int i=0;;i++){
        if((x_min+i*deltax)<=x_max){
         q= x_min + double(i)*deltax;
        v.push_back(std::make_pair(q,fun(q)));
        }else break;
    }*/
    

    //DRUGI NACIN 
    for(double i = x_min;i<x_max;i+=deltax){
        v.push_back(std::make_pair(i,fun(i))); // moze i sa make_pair
    }
    
    /*
    double i = x_min;
    while(i<x_max){
        v.push_back(std::pair<double,double>(i,fun(i)));
        i+=deltax;
    }*/
  
    try{
    auto f = BaricentricnaInterpolacija(v,d);
    return f;
    }catch(std::domain_error temp){
        throw std::domain_error(temp.what());
    }
    
    
}

int main ()
{
    
    std::function<double(double)> f = [](double x){return x*x + std::sin(x);};
    std::vector<std::pair<double,double>>v;
    int unos;
    
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin>>unos;
        if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
        
        if(unos == 1){
            
            std::cout<<"Unesite broj cvorova: ";
            int br;
            std::cin>>br;
            if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
            std::cout<<"Unesite cvorove kao parove x y: ";
            double x,y;
            for(int i=0;i<br;i++){
                std::cin>>x;
                if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
                std::cin>>y;
                if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
                v.push_back(std::make_pair(x,y));;
            }
            
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
            
            
            
            
            try{
                auto rez = BaricentricnaInterpolacija(v,d);
                for(;;){
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            double arg;
            std::cin>>arg;
            if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
                std::cout<<"f("<<arg<<") = "<<rez(arg)<<std::endl;
                }   
            }catch(std::domain_error temp){
                std::cout<<temp.what()<<std::endl;
                return 0;
            }
            
            
            
        }else if(unos == 2){
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x_min,x_max,deltax;
            std::cin>>x_min;
            if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
            std::cin>>x_max;
            if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
            std::cin>>deltax;
            if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
            std::cout<<"Unesite red interpolacije: ";
            int d;
            std::cin>>d;
            if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
            
            
            try{
               
                auto rez = BaricentricnaInterpolacija(f,x_min,x_max,deltax,d);
                for(;;){
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                double arg;
                std::cin>>arg;
                if(std::cin.peek() != '\n' && std::cin.peek() != ' ')return 0;
                std::cout<<"f("<<arg<<") = "<<f(arg)<<" "<<"fapprox("<<arg<<") = "<<rez(arg)<<std::endl;}
            }catch(std::domain_error temp){
                std::cout<<temp.what()<<std::endl;
                return 0;
            }
            
        }else return 0;
        
        
    
	return 0;
}


































