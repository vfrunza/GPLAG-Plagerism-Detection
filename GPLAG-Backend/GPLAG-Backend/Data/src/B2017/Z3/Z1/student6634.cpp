#include <iostream>
#include <functional>
#include <vector>
#include <stdexcept>
#include <cmath>
std::vector<std::pair<double,double>> SortirajParove(const std::vector<std::pair<double,double>> &parovi){
    std::pair<double,double>temp;
    auto parovi1(parovi);
    for (int i=0; i<parovi1.size();i++){
        for(int j=i+1; j< parovi1.size(); j++){
            if(parovi1[i].first > parovi1[j].first){
                temp=parovi1[i];
                parovi1[i]=parovi1[j];
                parovi1[j]=temp;
            }
        }
    }
    return parovi1;
}

std::function <double (double)>LinearnaInterpolacija( const std::vector<std::pair<double,double>> &parovi){
    for(auto it=parovi.begin(); it != parovi.end(); it++){
            auto it1(it+1);
            for(it1; it1 != parovi.end(); it1++){
                if(it->first == it1->first) throw std::domain_error("Neispravni cvorovi");
            }
    }
    auto parovipom(SortirajParove(parovi));
    return [parovipom](double x){ 
        auto it(parovipom.begin()),it1(parovipom.end()-1);
        
        if(it->first > x || it1->first < x) throw std::range_error("Argument izvan opsega");
        
        for(auto it=parovipom.begin(); it != parovipom.end(); it++){
            auto it1(it+1);
            if(it1!=parovipom.end()){
                if(it1->first == x)return(it1->second);
                else if(it->first <= x && it1->first > x) 
                return (it->second+(it1->second - it->second)/(it1->first - it->first)*(x - it->first));
            }
        }
    };
}
template <typename FunkcijskiTip>
std::function <double (double)>LinearnaInterpolacija( FunkcijskiTip f, double Xmin,  double Xmax, double deltaX){
    if (Xmin > Xmax || deltaX<=0)throw std::domain_error("Nekorektni parametr");
    std::vector<double>cvorovi;
    int brojac(0);
    double brojac2(deltaX);
    while(brojac2<=Xmax){
        cvorovi.push_back(Xmin+deltaX*brojac);
        brojac2+=deltaX;
        brojac++;
    }
    
    cvorovi.push_back(Xmax);
    std::vector<std::pair<double,double>>cvorovi2;
    
    for (int i=0; i<cvorovi.size();i++)
        cvorovi2.push_back(std::make_pair(cvorovi[i],f(cvorovi[i])));
    
    return (LinearnaInterpolacija(cvorovi2));
    
}


int main(){
    
    for(;;){
        std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija(0);
        std::cin>>opcija;
        
        if (opcija==1){
            std::cout<<"Unesite broj cvorova: ";
            int brojcvorova(0);
            std::cin >> brojcvorova;
            std::vector<std::pair<double,double>>cvorovi;
            std::cout << "Unesite cvorove kao parove x y: ";
            for(int i=0; i<brojcvorova; i++){
                double x(0),y(0);
                std::cin>>x;
                std::cin>>y;
                cvorovi.push_back(std::make_pair(x,y));
            }
            double argument(0);
            auto f(LinearnaInterpolacija(cvorovi));
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
    while((std::cin>>argument)) {
        
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        
        std::cout <<"f("<<argument<<") = "<< f(argument)<< std::endl;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        
            
   }
        }
     
    
        if (opcija==2){    
            std::cout << "Unesite krajeve intervala i korak: " ;
            double x(0),y(0),korak(0);
                std::cin>>x;
                std::cin>>y;
                std::cin>>korak;
                double argument(0);
                
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
    try {         
    while((std::cin>>argument)) {
        
        std::cin.clear();
        std::cin.ignore(1000,'\n');
      
            auto f2(LinearnaInterpolacija([](double x){return (x*x + std::sin (x)); },x,y,korak));
            auto f([](double x){return (x*x + std::sin (x)); });
            f2(argument);
            std::cout <<"f("<<argument<<") = " << f(argument);
            std::cout <<" fapprox("<<argument<<") = "<< f2(argument)<< std::endl;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
      }
            }
            catch(std::range_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            while((std::cin>>argument)) {
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            auto f2(LinearnaInterpolacija([](double x){return (x*x + std::sin (x)); },x,y,korak));
                auto f([](double x){return (x*x + std::sin (x)); });
                std::cout <<"f("<<argument<<") = " << f(argument);
                std::cout <<" fapprox("<<argument<<") = "<< f2(argument)<< std::endl;
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            }
        }
        }
        break;
    }
    
    return 0;
}
