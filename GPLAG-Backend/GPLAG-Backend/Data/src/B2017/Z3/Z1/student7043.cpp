/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <utility>
#include <vector>
#include <functional>
#include <cmath>
#include <string>
#include <algorithm>

#define e 0.000001

bool DaLiSuCvoroviIspravni(std::vector<std::pair<double,double> > vektor_parova){
    bool istina(true);
    for (int i=0;i<vektor_parova.size();i++){
    if  (i!=vektor_parova.size()-1){
        if (vektor_parova[i].first>vektor_parova[i+1].first) {
            istina=false;
            break;
        }
        } 
    }
     if (vektor_parova[vektor_parova.size()-1].first<vektor_parova[vektor_parova.size()-2].first) istina=false;
    return istina;
}

std::function<double(double)>   LinearnaInterpolacija(std::vector<std::pair<double,double> > vektor_parova){
        int brojac(0);
        for (auto a:vektor_parova){
                    for (auto b:vektor_parova){
                        if (fabs(a.first-b.first)<e )brojac++ ;
                    }
                }
                if (brojac>vektor_parova.size()) throw std::domain_error("Neispravni cvorovi");
                bool istina(DaLiSuCvoroviIspravni(vektor_parova));
                if (istina==false) throw std::domain_error("Neispravni cvorovi");
        return [vektor_parova](double x){
                if ((x<vektor_parova[0].first) || (x>vektor_parova[vektor_parova.size()-1].first)) throw std::range_error("Argument izvan opsega");
                double y;
                double x1=int(x);
                double x2;
                double y1,y2;
                for (int i=0;i<vektor_parova.size();i++){
                    if (vektor_parova[i].first-x1<e) {
                    y1=vektor_parova[i].second;
                    if (i!=vektor_parova.size()-1){
                    x2=vektor_parova[i+1].first;
                    y2=vektor_parova[i+1].second;
                        }
                    if (i==vektor_parova.size()-1){
                        return y1;
                        }    
                    }
                }
                y=y1+((y2-y1)*(x-x1))/(x2-x1);
             return y;
        };
    }


std::vector<std::pair<double,double> >   LinearnaInterpolacija( double f (double) , double Xmin , double Xmax , double DX ) {
    if (Xmin>Xmax || DX<0) throw std::domain_error("Nekorektni parametri");
    std::vector<std::pair<double,double> > vektor_parova;
    for (int i=0;i<(Xmax-Xmin)/DX;i++){
        double a,b;
        a=Xmin+i*DX;
        b=f(a);
        auto p=std::make_pair(a,b);
        vektor_parova.push_back(p);
    }
    return vektor_parova;
}






int main ()
{
    try{
        std::vector<std::pair<double,double>> vektor_parova;
        std::cout <<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
        int opcija;
        std::cin >> opcija;
        
        
        
        if (opcija==1){
        std::cout <<"Unesite broj cvorova: ";
        int broj_cvorova;
        std::cin >> broj_cvorova;
        std::cout <<"Unesite cvorove kao parove x y: ";
        for (int i=0;i<broj_cvorova;i++){
            double a,b;
            std::cin >>a >> b ;
            auto p=std::make_pair(a,b);
            vektor_parova.push_back(p);
            }
        bool istina(DaLiSuCvoroviIspravni(vektor_parova)) ;
        if (istina==false) throw std::domain_error("Neispravni cvorovi");
        do {
        std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
        std::string argument;
        std::cin >> argument;
        double lol = atof(argument.c_str());
        if (argument=="kraj") break;
        auto f(LinearnaInterpolacija(vektor_parova));
        std::cout <<"f("<<lol<<") = "<<f(lol)<<std::endl;
            }while (1);
        }
        
        
        
        
        if (opcija==2){
            std::cout <<"Unesite krajeve intervala i korak: ";
            double Xmin,Xmax,DX;
            std::cin >> Xmin >> Xmax >> DX;
            do{
                try{
            std::cout << "Unesite argument (ili \"kraj\" za kraj): ";
            std::string argument;
            std::cin >> argument;
            if (argument=="kraj") break;
            double lol= atof(argument.c_str());
        vektor_parova=LinearnaInterpolacija([](double x){ return x*x+sin(x);},Xmin,Xmax,DX);
        auto f(LinearnaInterpolacija(vektor_parova));
        std::cout <<"f("<<lol<<") = "<<lol*lol+sin(lol)<<" fapprox("<<lol<<") = " <<f(lol)<<std::endl;
                }
        catch (std::range_error izuzetak){
            std::cout<<izuzetak.what()<<std::endl;
        }
            }while(1);
        }
    }
    catch(std::domain_error izuzetak){
        std::cout << izuzetak.what();
    }
    catch (std::range_error izuzetak){
        std::cout << izuzetak.what()<<std::endl;
    }
	return 0;
}
