#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
#include <stdexcept>
#include <cmath>


bool DaLiJeSortiran(const std::vector<std::pair<double,double>> &v)
{
    bool sortiran(true);
    for(int i=0;i<v.size()-1;i++)
    {
       if(v[i].first>v[i+1].first) 
       {
           sortiran=false;
           break;
       }
        
        
    }
    
    
 return sortiran;   
}





std::function<double(double)>LinearnaInterpolacija(std::vector<std::pair<double,double>> &v)
{

    for(int i=0; i<v.size(); i++) {

        if(std::count_if(v.begin(),v.end(),[v,i] (std::pair<double,double> p1) {
        return p1.first==v[i].first;
        })!=1) {
            throw std::domain_error("Neispravni cvorovi");

        }
    }
    if(!(DaLiJeSortiran(v))) {
        std::sort(v.begin(),v.end(),[](std::pair<double,double> p1,std::pair<double,double> p2) {
            return p1.first<p2.first;

        });

    }

    return [v] (double x)->double {

        if(x<v[0].first || x>v[v.size()-1].first) {
            throw std::range_error("Argument izvan opsega");
        }

        auto it (std::upper_bound(v.begin(),v.end(),std::make_pair(x,0),[](std::pair<double,double> p1,std::pair<double,double> p2) {
            return p1.first<p2.first;
        }));

        if(it==v.end()) return v[v.size()-1].second;



        return (it-1)->second+((it->second-(it-1)->second)/(it->first-(it-1)->first))*(x-(it-1)->first);
    };
}
std::function<double(double)> LinearnaInterpolacija(std::function<double(double)> f,double xmin,double xmax,double deltax)
{
    if(xmin>xmax || deltax<=0) {
        throw std::domain_error("Nekorektni parametri");
    }

    std::vector<std::pair<double,double>> v;
    double pomocni(xmin);
    for(int i=0; i<(xmax-xmin)/deltax; i++) {

        v.push_back(std::make_pair(pomocni,f(pomocni)));
        pomocni=pomocni+deltax;

    }

    return LinearnaInterpolacija(v);


}
int main()

{


    int unos;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>unos;
    if(unos==1) {
        int broj_cvorova;
        std::vector<std::pair<double,double>> v;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>broj_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<broj_cvorova; i++) {

            std::pair<double,double> pomocna;
            std::cin>>pomocna.first>>pomocna.second;
            v.push_back(pomocna);
        }
        
        std::function<double(double)> f;
        try{
         f=LinearnaInterpolacija(v);
        
       
        for(;;) {

            double arg;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>arg;
            if(!std::cin) {
             
                break;
            }
            try{
                std::cout<<"f("<<arg<<")"<<" = "<<f(arg)<<std::endl;
            }
            catch(std::range_error izuzetak) {
                std::cout<<izuzetak.what();
               
            }
}

}catch(std::domain_error izuzetak) {
                std::cout<<izuzetak.what()<<std::endl;
            }


}
    else if(unos==2) {
        std::cout<<"Unesite krajeve intervala i korak: ";
        double pocetak,kraj,korak;
        std::cin>>pocetak>>kraj>>korak;
        std::function<double(double)> f;
        try{
         f=LinearnaInterpolacija([](double x) {
            return x*x+sin(x);
        },pocetak,kraj,korak);

        for(;;) {
            double arg;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>arg;
            if(!std::cin) {
       
                break;
            }
            try {
                std::cout<<"f("<<arg<<")"<<" = "<<arg*arg+sin(arg)<<" fapprox("<<arg<<")"<<" = "<<f(arg)<<std::endl;
            }  catch(std::range_error izuzetak) {
                std::cout<<izuzetak.what()<<std::endl;
                
            }

        }
        
        
        }catch(std::domain_error izuzetak) {
                std::cout<<izuzetak.what()<<std::endl;
            }
        
        
    }






    return 0;
}