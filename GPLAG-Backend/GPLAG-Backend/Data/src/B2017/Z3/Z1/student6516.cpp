/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <cmath>
#include <stdexcept>
#include <algorithm>
bool Sortiranje(std::pair<double,double> x,std::pair<double,double> y){
    return x.first<y.first;
}
std::function<double(double)>LinearnaInterprotacija(std::vector<std::pair<double,double >> v){
    
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i].first== v[j].first) throw std::domain_error("Neispravni cvorovi");
        }
    }
    std::sort(v.begin(),v.end(),[](std::pair<double,double>p,std::pair<double,double>d){ return p.first<d.first;});
    return [v](double x){
         auto pocetak=std::begin(v);
         auto kraj=std::end(v);
         kraj--;
          if(x<v[0].first || x>v[v.size()-1].first) throw std::range_error("Argument izvan opsega");
        auto dg=std::upper_bound(pocetak,kraj,std::make_pair(x,0),[](std::pair<double,double> prvi,std::pair<double,double> drugi){return drugi.first>prvi.first;});
        auto gg=std::lower_bound(pocetak,kraj,std::make_pair(x,0),[](std::pair<double,double> prvi,std::pair<double,double> drugi){return drugi.first>prvi.first;});        
        dg--;
        double g;
        if(x==(gg->first)) return g=(gg->second);
        g=(dg->second)+((gg->second)-(dg->second))/((gg->first)-(dg->first))*(x-(dg->first));
        return g;
    };
    
  
}
std::function<double(double)>LinearnaInterprotacija(std::function<double(double)> funckija,double xmin,double xmax, double dx){
 
 if(dx<0 || xmin>xmax) throw std::domain_error("Nekorektni parametri");   
 std::vector<std::pair<double,double>> cvor;
 
 for(double i=xmin;i<=xmax;i=i+dx){
     cvor.push_back(std::make_pair(i,funckija(i)));
 }
 return LinearnaInterprotacija(cvor);
 
}


int main ()
{
    auto li2(LinearnaInterprotacija({{1,1},{2,2},{3,3},{4,4},{5,5},{6,6}}));

std::cout << li2(1.5) << std::endl;
std::cout << li2(1) << std::endl;
std::cout << li2(6) << std::endl;
std::cout << li2(3);
    /*
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int n;
    std::cin>>n;
    if(n==1){
        std::cout<<"Unesite broj cvorova: ";
        int n1;
        std::cin>>n1;
        std::vector<std::pair<double,double>>cvor;
        std::cout <<"Unesite cvorove kao parove x y: ";
        for(int i=0;i<n1;i++){
         std::pair<double,double> cvoric;
         std::cin>>cvoric.first>>cvoric.second;
         cvor.push_back(cvoric);
        }
        try{
        
         auto funkcija=LinearnaInterprotacija(cvor);
         std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";
        double arg;
        std::cin>>arg;
        
        while(std::cin ){
        std::cout <<"f("<<arg<<") = "<<funkcija(arg);
        std::cout <<std::endl<<"Unesite argument (ili \"kraj\" za kraj): ";
        std::cin>>arg;
        }
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
            return 0;
        }catch(std::range_error izuzetak){
            std::cout<<izuzetak.what();
            return 0;
        }
    }
        if(n==2){
            try{
            std::cout<<"Unesite krajeve intervala i korak: ";
            double x,y,z;
            std::cin>>x>>y>>z;
            
            
           auto fun=LinearnaInterprotacija([](double broj){ return broj*broj+sin(broj);},x,y,z);
            
           
             while(std::cin){
                 try{
                     double arg;
                     std::cout <<"Unesite argument (ili \"kraj\" za kraj): ";
                       std::cin >>arg;
                       if(!std::cin) break;
            
            
                std::cout<<"f("<<arg<<") = "<<arg*arg+sin(arg)<<" fapprox("<<arg<<") = "<<fun(arg);
               std::cout<<std::endl;
            }catch(std::range_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
                
            }
             }
           
                 
            
            
        }
             catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
            return 0;   
        }
       
        
    }*/
	return 0;
}
