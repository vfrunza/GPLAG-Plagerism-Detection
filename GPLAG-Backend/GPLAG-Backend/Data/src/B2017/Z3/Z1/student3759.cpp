/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <map>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdexcept>

std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> vp){
    const double eps(0.001);
    for(int i(0);i<vp.size()-1;i++){
        for(int j=i+1;j<vp.size();j++){
            if(abs(vp[i].first-vp[j].first)<eps) throw std::domain_error ("Nesipravni cvorovi");
        }
    }
    bool sortirano(true);
    for(int i(0);i<vp.size()-1;i++){
        if(vp[i].first>=vp[i+1].first){
            sortirano=false;
            break;
        }
    }
    if(!sortirano){
        std::sort(vp.begin(),vp.end(),[](std::pair<double,double> p1, std::pair<double,double> p2){return p1.first<p2.first;});
    }
    return [=](double x){
        if(x<vp[0].first || x>vp[vp.size()-1].first) throw std::range_error("Argument izvan opsega");
        if(std::abs(vp[vp.size()-1].first-x)<eps) return vp[vp.size()-1].second;
        int index(0);
        for(int i(0);i<vp.size()-1;i++){
            if(x>=vp[i].first && x<vp[i+1].first) {
                index=i;
                break;
            }
        }
        return vp[index].second+((vp[index+1].second-vp[index].second)/(vp[index+1].first-vp[index].first))*(x-vp[index].first);
    };
}
int BinarySearch(std::vector<std::pair<double,double>> vp, double broj){
int min=0;
int max=vp.size();
int mid;
while (max >= min){
    mid = (min + max) / 2;

    if (vp[mid].first < broj)
        min = mid + 1;
    else if (vp[mid].first > broj)
        max = mid - 1;

    else return mid;

}

return min-1;
}



std::function<double(double)> LinearnaInterpolacija(double f(double), double xmin, double xmax, double korak){
    const double eps(0.0000001);
    if(xmin>xmax || korak<=0) throw std::domain_error ("Nekorektni parametri");
    std::vector<std::pair<double,double>> vp;
    while(xmin<=xmax){
        vp.push_back(std::make_pair(xmin,f(xmin)));
        xmin+=korak;
    }
    
   
    
    return [=](double x){
        if(std::abs(x-vp[vp.size()-1].first)<eps) return vp[vp.size()-1].second;
        if(x<vp[0].first || x>vp[vp.size()-1].first) throw std::range_error("Argument izvan opsega");
        
        int index(BinarySearch(vp,x));
        return vp[index].second+((vp[index+1].second-vp[index].second)/(vp[index+1].first-vp[index].first))*(x-vp[index].first);
    };
}

double fun (double x){return x*x+sin(x);}


int main ()
{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    int opcija(0);
    std::cin>>opcija;
    if(opcija==1)
        {
        std::vector<std::pair<double,double>> vp;
        std::cout<<"Unesite broj cvorova: ";
        int br_cvorova;
        std::cin>>br_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        double x,y;
        
        for(int i(0);i<br_cvorova;i++){
            std::cin>>x>>y;
            vp.push_back(std::make_pair(x,y));
        }
       try{
            auto f(LinearnaInterpolacija(vp));
                
                    double arg;
                    while(1){
                    try{
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>arg;
                    if(!std::cin) break;
                    std::cout<<"f("<<arg<<") = "<<f(arg)<<std::endl;
                    
                    }
                        catch(std::range_error e){
                        std::cout<<e.what()<<std::endl;
                        }
                    }
       }    
        catch(std::domain_error e){
            std::cin.clear();
            std::cout<<e.what();
        }
    }
    if(opcija==2)
     {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double xmin,xmax,korak;
        std::cin>>xmin>>xmax>>korak;
        try{
            
            auto f(LinearnaInterpolacija([](double x){return x*x+sin(x);},xmin,xmax,korak));
            
        double arg;
         while(1){
                    try{
                    std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
                    std::cin>>arg;
                    if(!std::cin) break;
                    std::cout<<"f("<<arg<<") = "<<fun(arg)<<" fapprox("<<arg<<") = "<<f(arg)<<std::endl;
                    
                    }
                        catch(std::range_error e){
                        std::cout<<e.what()<<std::endl;
                        }
                    }
        }
        catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
        }
     }
   
    
    

	return 0;
}
                                       