/B2017/2018: Zadaća 3, Zadatak 1
#include <iostream>
#include <functional>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <vector>

bool moja_funkcija(std::pair<double, double> a, std::pair<double, double> b)
{
    return (a.first<b.first);
}

std::function<double(double)> LinearnaInterpolacija(   //prva verzija
    std::vector<std::pair<double, double>> v)
{
    
        int vel=v.size();
        
        //vektor samo od x-eva
        std::vector<double> iksevi;
        for(int i(0); i<v.size(); i++) { //pravimo vektor samo od x iz uredjenih parova
            iksevi.push_back(v[i].first);
        }
        int flag(0);
        for(int i(0); i<iksevi.size(); i++) {
            for(int j(i+1); j<iksevi.size(); j++) {
                if(iksevi[i]==iksevi[j]) flag++;
            }
        }
        if(flag!=0) {
            throw std::domain_error ("Neispravni cvorovi");
        }
    return [v,vel,iksevi] (double x) {
        int marker;
        if(x==v.at(vel-1).first) return v.at(vel-1).second;
        if(x<v[0].first || x>v[vel-1].first) {
            throw std::range_error ("Argument izvan opsega");
        }

        auto pos(std::lower_bound(iksevi.begin(), iksevi.end(), x)-1); //par-koji sadrzi donju granicu od x
        for(int i(0); i<v.size(); i++) {
            if(*pos==v[i].first) {
                marker=i;
                break; //trazimo korespondirajuci uredjen par
            }
        }
        double povratni=v[marker].second+((v[marker+1].second-v[marker].second)/(v[marker+1].first-v[marker].first))*(x-v[marker].first);
        return povratni;
    };
}

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
    try{
    int stanje;
    std::cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin>>stanje;
    if(stanje==1){
        int br_cvorova;
        std::cout<<"Unesite broj cvorova: ";
        std::cin>>br_cvorova;
        std::cout<<"Unesite cvorove kao parove x y: ";
        double x, y;
        std::vector<std::pair<double, double>> cvor(br_cvorova);
        for(int i(0); i<br_cvorova; i++){
            std::cin>>x>>y;
            cvor.at(i)=std::make_pair(x,y);
        }
        auto fun(LinearnaInterpolacija(cvor));
        double argument;
        std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        while(std::cin>>argument){
            try{
                std::cout<<"f("<<argument<<") = "<<fun(argument)<<std::endl;
            }catch(std::range_error izuzetak){
                std::cout<<izuzetak.what()<<std::endl;}
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
        }
    }
        else if(stanje==2){
            double xmin, xmax, korak;
            std::cout<<"Unesite krajeve intervala i korak: ";
            std::cin>>xmin>>xmax>>korak;
            auto funkc(LinearnaInterpolacija(fun, xmin, xmax, korak));
            double argument;
            std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";
            while(std::cin>>argument){
                try{
                    std::cout<<"f("<<argument<<") = "<<fun(argument)<<" fapprox("<<argument<<") = "<<funkc(argument)<<std::endl;
                }catch(std::range_error izuzetak){
                    std::cout<<izuzetak.what()<<std::endl;
                }
                std::cout<<"Unesite argument (ili \"kraj\" za kraj): ";  
            }
        }
        
    }catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    return 0;
}
