#include<iostream>
#include<functional>
#include<vector>
#include<utility>
#include <stdexcept>
#include <cmath>


template <typename itter>
void razmjeni (itter p1,itter p2){
    auto temp(*p1);*p1=*p2;*p2=temp;
}
std::vector<std::pair<double, double>> sortiraj(std::vector<std::pair<double ,double>>v){
     for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            if(v[i].first>v[j].first)razmjeni(&v[i],&v[j]);
        }
    }
    return v;
}
void ProvjeriValidnost(std::vector<std::pair<double ,double>>v){
    for(int i=1;i<v.size();i++){
        if(v[i].first<=v[i-1].first)throw std::domain_error{"rekt"};
    }
}
int nadji(std::vector<std::pair<double ,double>> v,double x){
    if(x==v[v.size()-1].first)return v.size()-1;
    int i;
    for( i=1;i<v.size();i++){
        if(v[i].first>x&&v[i-1].first<=x)return i-1;
    }
    return i;
}
std::function<double(double)> LinearnaInterpolacij(std::vector<std::pair<double ,double>> v){
    
    try{
        ProvjeriValidnost(v);
    }catch(...){
        throw std::domain_error{"Neispravni cvorovi"};
    }
    return [v](double x){
        if(x<v[0].first||x>v[v.size()-1].first)throw std::range_error{"Argument izvan opsega"};
        int i;
        i=nadji(v,x);
        if(i!=v.size()-1){
        return v[i].second+((double(v[i+1].second-v[i].second)/(v[i+1].first-v[i].first))*(x-v[i].first));
        }else{
            return double(v[i].second);
        }
     };
}
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double ,double>> v){
  
    try{
        ProvjeriValidnost(v);
    }catch(...){
        throw std::domain_error{"Neispravni cvorovi"};
    }
    return [v](double x){
        if(x<v[0].first||x>v[v.size()-1].first)throw std::range_error{"Argument izvan opsega"};
        int i;
        i=nadji(v,x);
       
        if(i!=v.size()-1){
        return v[i].second+((double(v[i+1].second-v[i].second)/(v[i+1].first-v[i].first))*(x-v[i].first));
        }else{
            return double(v[i].second);
        }
     };
}
std::vector<std::pair<double ,double>> stvorivektorparova(double xmin,double xmax,double deltax){
      std::vector<std::pair<double ,double>> v;
      while(xmin<=xmax){
          std::pair<double,double>p;
          p.first=xmin;
          v.push_back(p);
          xmin+=deltax;
      }
      return v;
 }
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f, double xmin,double xmax,double deltax){
    if(xmin>xmax||deltax<=0)throw std::domain_error {"Nekorektni parametri"};
    auto v(stvorivektorparova(xmin,xmax,deltax));
    for(int i=0;i<v.size();i++){
        v[i].second=f(v[i].first);
    }
   return LinearnaInterpolacij(v);
}
std::pair<double,double> unesipar(){
     double temp1,temp2;
     std::cin >> temp1;
     std::cin >> temp2;
     std::pair<double,double>p;
     p.first=temp1;p.second=temp2;
    return p;
}


int main (){
    
    while(1){
        
        int n;
        std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        std::cin >> n;
        if(n==1){
            int broj;
            std::cout << "Unesite broj cvorova: ";
            std::cin >> broj;
            std::vector<std::pair<double,double>>v;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0;i<broj;i++){
                auto p(unesipar());
            v.push_back(p);
            }
            double temp;
            std::cout << "Unesite argument (ili \"kraj\" za kraj): " ;
            while(std::cin >> temp){
                try{
                auto f(LinearnaInterpolacija(v));
                std::cout <<"f("<<temp<<") = "<<f(temp)<< std::endl  ;
                
                }catch(std::domain_error er){
                    std::cout << er.what() << std::endl;
                    break;
                }catch(std::range_error er){
                    std::cout << er.what() << std::endl;
                    break;
                }
                std::cin.ignore(1000,'\n');
                std::cin.clear();
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            }std::cin.ignore(1000,'\n');
                std::cin.clear();
                break;
        }
        if(n==2){
            std::cout << "Unesite krajeve intervala i korak: ";
            double xmin,xmax,deltax;
            std::cin >> xmin>>xmax>>deltax;
            double temp;
          std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
          while(std::cin >> temp){
                try{
                    
                auto f(LinearnaInterpolacija([](double x){return x*x+sin(x);},xmin,xmax,deltax));
                std::cout <<"f("<<temp<<") = "<<temp*temp+sin(temp)<<" " <<"fapprox("<<temp<<") = "<<f(temp)<< std::endl ;
                
                }catch(std::domain_error er){
                    std::cout << er.what()<< std::endl ;
                }catch(std::range_error er){
                    std::cout << er.what() << std::endl;
                }
                std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
                std::cin.ignore(1000,'\n');
                std::cin.clear();
            }std::cin.ignore(1000,'\n');
                std::cin.clear();
                break;
        }
        std::cin.ignore(1000,'\n');
        std::cin.clear();
        break;
}
    return 0;
}
