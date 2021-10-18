 /B2017/2018: Zadaća 3, Zadatak 1
 #include <iostream>
 #include <algorithm>
 #include <stdexcept>
 #include <vector>
 #include <functional>
 #define epsilon 0.00001
 #include <cmath>
 #include <cstdlib>
 
 
 int PronadjiInterval(double x,const std::vector<std::pair<double,double>> &v){
         int pozicija=0;
         if(x < v[0].first){  
            pozicija=0;
            return 0;
         }
        else if(x>v[v.size()-1].first){
             pozicija=v.size();
             return v.size();
        }
      pozicija=std::lower_bound(v.begin(),v.end(),x,[] (const std::pair<double,double> p,double k){ return p.first<k;} )-v.begin(); //uzimamo poziciju trazenog elementa
      return pozicija;
     }
     
 std::function<double(double x)> LinearnaInterpolacija(const std::vector<std::pair<double,double>> &vek){
     return [=] (double x){
      std::vector<std::pair<double,double>> v;
      v=vek;
      int i=PronadjiInterval(x,v);
      i--;
      if(i<0) i++;
      if(i==v.size()-1)  i--;
      double rez;
      rez=v[i].second + (((v[i+1].second - v[i].second)/(v[i+1].first - v[i].first)) * (x-v[i].first));
     std::sort(v.begin(),v.end(),[=] (const std::pair<double,double> &y, const std::pair<double,double> &z) {
     if(fabs(y.first-z.first)<=epsilon*(fabs(y.first) + fabs(z.first))) throw std::domain_error("Neispravni cvorovi");
     if(x < v[0].first || x > v[v.size()-1].first) 
     throw std::range_error("Argument izvan opsega\n"); 
      return y.first < z.first; });
      return rez;
     
    };
 }
   
  std::function<double(double)>  LinearnaInterpolacija(std::function<double(double)> fun,double x_min, double x_max, double delta_x){
     if(x_min > x_max || delta_x <= 0) throw std::domain_error("Nekorektni parametri"); 
     std::vector<std::pair<double,double>> novi;
     double x_1=x_min;
     double x_2;
     while(x_1<=x_max){
      
         x_2=fun(x_1);
         novi.push_back(std::make_pair(x_1,x_2));
         x_1+=delta_x;
     }
     return [=](double x){
      
         return LinearnaInterpolacija(novi)(x);//funkcija prethodna mi svakako locira x i na to mjesto vrsi interpolaciju
     };
 }
 
 double f(double x){
     return x*x+std::sin(x);
 }
 int main ()
 {   
    int opcija;
  try{
      
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin>>opcija;
         std::vector<std::pair<double,double>> v;
            double x;
        if(opcija==1){
               int br_cvorova;
               std::cout<<"Unesite broj cvorova: ";
               std::cin>>br_cvorova;
              try{  
               std::cout<<"Unesite cvorove kao parove x y: ";
               std::pair<double,double> cvor;
               double par_1,par_2;
               for(int i=0; i<br_cvorova; i++){
                 std::cin>>par_1;
                 std::cin>>par_2;
                 cvor.first=par_1;
                 cvor.second=par_2;
                 v.push_back(cvor);
              // double f_1= LinearnaInterpolacija(v)(x); ne hvata dorbo izuzetak
             //std::cout<<"f("<<x<<") = "<<f_1<<std::endl;
               }
              }
               catch(std::domain_error e){
                std::cout<<e.what();
   }
          
     do{
         try{
             std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
             std::cin>>x;
             if(!std::cin) break;
             double f_1= LinearnaInterpolacija(v)(x);
             std::cout<<"f("<<x<<") = "<<f_1<<std::endl;
          }
          catch(std::range_error e){
                 std::cout<<e.what();
              }
       }while(std::cin);
     }
  }
     catch(std::domain_error e){
        std::cout<<e.what();
   }
   
   
   
   try{
        if(opcija==2){
           double x_min,x_max,k;
           std::cout<<"Unesite krajeve intervala i korak: ";
           std::cin>>x_min>>x_max>>k;
      do{ 
         try{
              double x; 
              std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
              std::cin>>x;
              if(!std::cin) break;
               double f_2=LinearnaInterpolacija(f,x_min,x_max,k)(x);
                std::cout<<"f("<<x<<") = "<<f(x)<<" fapprox("<<x<<") = "<<f_2<<std::endl;         
              }
        catch(std::range_error e){
              std::cout<<e.what();
          }
        
        }while(std::cin);
     }
   }
      catch(std::domain_error e){
      std::cout<<e.what();
     }
       
 	return 0;
 }