#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iterator>
#include <new>
#include <utility>
#include <stdexcept>
#include <memory>
#include <functional>
#include <cmath>
#include <map>
#include <tuple>
const double EPSILON=pow(10,-10);
class NepreklapajucaKugla{
    double m,n,o;
    double pp;
    std::tuple<double,double,double> r1;
    public:
    explicit NepreklapajucaKugla(double pp = 0){m=0;n=0;o=0;};
    explicit NepreklapajucaKugla(double x, double y, double z, double pp = 0){
        m=x;n=y;o=z;
    };
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double pp = 0){
        r1=centar;
    };
    double DajX() const{return m;}
    double DajY() const{return n;}
    double DajZ() const{return o;}
    std::tuple<double, double, double> DajCentar() const{return r1;}
    double DajPoluprecnik() const {return pp;}
    double DajPovrsinu() const{return 4*pp*pp*(4*atan(1.));}
    double DajZapreminu() const{return (4./3.)*pp*pp*pp*(4*atan(1.));}
    NepreklapajucaKugla &PostaviX(double x){m=x;return *this;}
    NepreklapajucaKugla &PostaviY(double y){ n=y; return *this;}
    NepreklapajucaKugla &PostaviZ(double z){o=z; return *this;}
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){m=x;n=y;o=z;return *this;}
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){r1=centar;return *this;}
    NepreklapajucaKugla &PostaviPoluprecnik(double r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        pp=r;return *this;}
    void Ispisi() const{
        std::cout << "{(" << DajX() << "," << DajY() << ","<<DajZ()<<")," << DajPoluprecnik() <<"}\n";
    };
    friend bool DaLiSadrzi(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2);
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};
double RastojanjeCentara(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2){
    return sqrt( pow( k1.DajX() - k2.DajX(), 2 ) + pow( k1.DajY() - k2.DajY(), 2 ) + pow( k1.DajZ() - k2.DajZ(), 2 ) );
}
bool DaLiSadrzi(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2){
     return (RastojanjeCentara(k1,k2)<=(k1.DajPoluprecnik()+k2.DajPoluprecnik()) && (RastojanjeCentara(k1,k2)> abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())));}

int main(){
     int m;
    std::cout << "Unesite broj kugli: ";
    std::cin>>m;
    while(m<=0 || !(std::cin)){
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cin>>m;
    }
     std::vector<NepreklapajucaKugla> v(m);
    for(int i=0;i<m;i++){
        
        std::cout << "Unesite centar za " << i+1 <<". kuglu: ";
        double x1,y1,z1;
        NepreklapajucaKugla nekaKugla;
        while(!(std::cin >> x1 >> y1 >> z1)){std::cout << "Neispravan centar, unesite ponovo:\n";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        }
        double ro;
        std::cout << "Unesite poluprecnik: ";
        std::cin>>ro;
        while(ro<0 || !(std::cin)){
            std::cout << "Neispravan poluprecnik, unesite ponovo:\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cin>>ro;
        }
        try{
        nekaKugla.PostaviCentar(x1,y1,z1);
        nekaKugla.PostaviPoluprecnik(ro);
        }
        catch(std::domain_error e){
            std::cout << e.what();
            i--;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::cout << std::endl;
            continue;
        }
        
        if(v.size()==0){
            v.push_back(nekaKugla);
        }
        else{
            bool a=true;
            for(int k=0;k<v.size();k++){
            NepreklapajucaKugla prva=v[k];
            if((RastojanjeCentara(nekaKugla,prva)<=(nekaKugla.DajPoluprecnik()+prva.DajPoluprecnik())) && (RastojanjeCentara(nekaKugla,prva)> abs(nekaKugla.DajPoluprecnik()-prva.DajPoluprecnik()))){
                a=false;
                std::cout << "Nedozvoljeno preklapanje\n";
                i--;
                break;}
        }
        if(a==true) v.push_back(nekaKugla);
        }}
    for(int i=0;i<m;i++){
        v.erase(v.begin());
    }
    
    std::cout << std::endl;
    std::cout << "Kugle nakon obavljenog sortiranja: \n";
    std::sort(v.begin(),v.end(),[](const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2){return k1.DajPovrsinu()<k2.DajPovrsinu();});
    std::for_each(v.begin(),v.end(),[](NepreklapajucaKugla const &k){ k.Ispisi();});
   
    return 0;
}



