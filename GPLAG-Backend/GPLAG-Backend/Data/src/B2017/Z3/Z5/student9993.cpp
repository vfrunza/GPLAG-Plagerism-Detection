/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <vector>

bool moja_funkcija(std::pair<double, double> a, std::pair<double, double> b){
    return (a.first<b.first);
}

std::function<double(double)> LinearnaInterpolacija(   //prva verzija
    std::vector<std::pair<double, double>> v){
        return [v] (double x){ 
            double povratni; int vel=v.size(); int marker;
            if(x==v.at(vel-1).first) return v.at(vel-1).second;
            if(x<v[0].first || x>v[vel-1].first) { throw std::range_error ("Argument izvan opsega");} 
            //vektor samo od x-eva
            std::vector<double> iksevi;
            for(int i(0); i<v.size(); i++){  //pravimo vektor samo od x iz uredjenih parova
                iksevi.push_back(v[i].first);
            }
            for(int i(0); i<iksevi.size(); i++){
                for(int j(i+1); j<iksevi.size(); j++){
                    if(iksevi[i]==iksevi[j]) { throw std::domain_error ("Neispravni cvorovi"); break;}
                }
            }
        
            std::vector<double>::iterator pos=std::lower_bound(iksevi.begin(), iksevi.end(), x)-1; //par-koji sadrzi donju granicu od x
            for(int i(0); i<v.size(); i++){
                if(*pos==v[i].first) {
                    marker=i;
                    break; //trazimo korespondirajuci uredjen par
                }
            }
            povratni=v[marker].second+((v[marker+1].second-v[marker].second)/(v[marker+1].first-v[marker].first))*(x-v[marker].first);
            return povratni;};}

    
           

std::function<double(double)> LinearnaInterpolacija(  //druga verzija
    std::function<double(double)> f, double xmin, double xmax, double dx){
        return[xmin, xmax, dx, f] (double x){
        if(xmin>xmax || dx<=0) { throw std::domain_error ("Nekorektni parametri");}    
        if(x<xmin || x>xmax) { throw std::range_error ("Argument izvan opsega");}
        std::vector<std::pair<double, double>> cvorovi(0); int brojac(0);
        std::pair<double, double> tekuci_par;
        for(int i(0);; i++){
            std::pair<double, double> tekuci_par;
            if((xmin+i*dx)==xmax){
                tekuci_par.first=xmax;
                tekuci_par.second=f(xmax);
                cvorovi.push_back(tekuci_par);
                break;
            }
            tekuci_par.first=xmin+i*dx;
            tekuci_par.second=f(tekuci_par.first);
            cvorovi.push_back(tekuci_par);
        }
        //sad imamo vektor parova sa datim korakom... moramo sortirati
        std::sort(cvorovi.begin(), cvorovi.end(), moja_funkcija);
        std::vector<double> iksevi2;
            for(int i(0); i<cvorovi.size(); i++){  //pravimo vektor samo od x iz uredjenih parova
                iksevi2.push_back(cvorovi[i].first);
            }
        int marker2; double povratni2;
        std::vector<double>::iterator pos=std::lower_bound(iksevi2.begin(), iksevi2.end(), x)-1; //par-koji sadrzi donju granicu od x
            for(int i(0); i<cvorovi.size(); i++){
                if(*pos==cvorovi[i].first) {
                    marker2=i;
                    break; //trazimo korespondirajuci uredjen par
                }
            }
            povratni2=cvorovi[marker2].second+((cvorovi[marker2+1].second-cvorovi[marker2].second)/(cvorovi[marker2+1].first-cvorovi[marker2].first))*(x-cvorovi[marker2].first);
            return povratni2;};}

double fun(double x){
    return x*x+std::sin(x);
}

int main (){
    int choice; int br_cv;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>choice;
    if(choice==1) {
        try{
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>br_cv;
        std::vector<std::pair<double, double>> vek(br_cv);
        std::cout<<"Unesite cvorove kao parove x y: ";
        for(int i(0); i<br_cv; i++){
            std::cin>>vek.at(i).first>>vek.at(i).second;
        }
        //sortiranje po velicini x-koordinata
        std::sort(vek.begin(), vek.end(), moja_funkcija);
        
        auto fx(LinearnaInterpolacija(vek));
        double arg;
        try{
        do{
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            std::cin>>arg;
            if(!(std::cin)) return 0;
            std::cout<<"f("<<arg<<") = "<<fx(arg)<<std::endl;
        }while(std::cin);
        }catch(std::range_error izuzetak2){                                               // izvan opsega
            std::cout<<izuzetak2.what()<<std::endl;
        }
    }catch(std::domain_error izuzetak){                                                  //iste x koordinate
                std::cout<<izuzetak.what()<<std::endl;
            }
        return 0;
    }
    
      else if(choice==2){
          
          std::cout<<"Unesite krajeve intervala i korak: ";
          double min; double max; double step;
          std::cin>>min>>max>>step;
          
          auto fx2(LinearnaInterpolacija(fun, min, max, step));
          do{
              try{
                double arg2;
              std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
              std::cin>>arg2;
          
              if(!(std::cin)) return 0;
              std::cout<<"f("<<arg2<<") = "<<fun(arg2)<<" fapprox("<<arg2<<") = "<<fx2(arg2)<<std::endl;
              }catch(std::range_error izuzetak2){                                               // izvan opsega
            std::cout<<izuzetak2.what()<<std::endl;
        } 
          }while(std::cin);
          return 0;
      }
return 0;
}