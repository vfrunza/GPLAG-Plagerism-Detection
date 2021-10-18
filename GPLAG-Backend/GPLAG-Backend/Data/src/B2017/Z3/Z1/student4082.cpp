/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <cmath>
//pomocna f-ja za sortiranje vektora tacaka
void Sortiraj(std::vector<std::pair<double,double>> &tacke){
    for(int i=0; i<tacke.size()-1; i++){
        for(int j=i+1; j<tacke.size(); j++){
            if(tacke[i].first>tacke[j].first){
                std::pair<double,double> pom=tacke[i];
                tacke[i]=tacke[j];
                tacke[j]=pom;
            }
        }
    }
}
//pomocna f-ja za testiranje ispravnosti argumenta
void TestirajIspravnost(std::vector<std::pair<double,double>> tacke, double x){
    Sortiraj(tacke);
    if(x<tacke[0].first || x>tacke[tacke.size()-1].first) throw std::range_error("Argument izvan opsega"); 
}
void TestirajCvorove(std::vector<std::pair<double,double>> tacke){
    for(int i=0; i<tacke.size()-1; i++)
       for(int j=i+1; j<tacke.size(); j++){
           if(tacke[i].first==tacke[j].first) throw std::domain_error("Neispravni cvorovi");
           
       }
}
//prva verzija - samo bacanje izuzetaka
std::function<double(double)> LinearnaInterpolacija(std::vector<std::pair<double,double>> tacke){
    try{
        TestirajCvorove(tacke);
    } catch (std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
   return[tacke](double x){
        TestirajIspravnost(tacke,x);
        double interpolacija;
        interpolacija=tacke[0].first;
        return interpolacija;
    };
}
// druga verzija - samo bacanje izuzetaka
double f(double x){
    return x*x+sin(x);
}
std::function<double(double)> LinearnaInterpolacija(double xmin, double xmax, double korak){
 if(xmin>xmax || korak<=0) throw std::domain_error("Nekorektni parametri");
 return[xmin,xmax,korak](double x){
     return f(x);
 };
}
int main (){
    int opcija;
    do{
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>opcija;
    int br_izuzetak=0;
    if(opcija==1){
        int br_cvorova;
        double argument;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>br_cvorova;
        std::vector<std::pair<double,double>> tacke(br_cvorova);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i=0; i<tacke.size(); i++){
            double x,y;
            std::cin>>x>>y;
            tacke[i]=std::make_pair(x,y);
        }
        Sortiraj(tacke);
        try{
            auto f(LinearnaInterpolacija(tacke));
        } catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
            br_izuzetak++;
        }
        if(br_izuzetak>0) break;
        try{
            std::cout<<"Unesite argument (ili ""kraj"" za kraj): ";
            std::cin>>argument;
            f(argument);
        
        }catch(std::range_error izuzetak2){
            std::cout<<izuzetak2.what();
            br_izuzetak++;
        }
            
        
        if(br_izuzetak) break; br_izuzetak=0;
    }
    else if(opcija==2){
        int poc,kraj;
        double korak,argument;
        std::cout<<"Unesite krajeve intervala i korak: ";
        std::cin>>poc>>kraj;
        std::cin>>korak;
        std::cout<<"\nUnesite argument: (ili ""kraj"" za kraj): ";
        std::cin>>argument;
        try{
            auto f(LinearnaInterpolacija(poc,kraj,korak));
            f(argument);
        }catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what();
            br_izuzetak++;
        }
        if(br_izuzetak) break;
    }
    
    } while(opcija!=1 || opcija!=2);
    
    return 0;
}