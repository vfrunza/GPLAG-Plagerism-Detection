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
class Kugla{
    double m,n,o;
    double pp;
    std::tuple<double,double,double> r1;
    public:
    explicit Kugla(double pp = 0){m=0;n=0;o=0;};
    explicit Kugla(double x, double y, double z, double pp = 0){
        m=x;n=y;o=z;
    };
    explicit Kugla(const std::tuple<double, double, double> &centar, double pp = 0){
        r1=centar;
    };
    double DajX() const{return m;}
    double DajY() const{return n;}
    double DajZ() const{return o;}
    std::tuple<double, double, double> DajCentar() const{return r1;}
    double DajPoluprecnik() const {return pp;}
    double DajPovrsinu() const{return 4*pp*pp*(4*atan(1.));}
    double DajZapreminu() const{return (4./3.)*pp*pp*pp*(4*atan(1.));}
    Kugla &PostaviX(double x){m=x;return *this;}
    Kugla &PostaviY(double y){ n=y; return *this;}
    Kugla &PostaviZ(double z){o=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z){m=x;n=y;o=z;return *this;}
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){r1=centar;return *this;}
    Kugla &PostaviPoluprecnik(double r){
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        pp=r;return *this;}
    void Ispisi() const{
        std::cout << "{(" << DajX() << "," << DajY() << ","<<DajZ()<<")," << DajPoluprecnik() <<"}\n";
    };
    void Transliraj(double delta_x, double delta_y, double delta_z){
        m=m+delta_x;
        n=n+delta_y;
        o=o+delta_z;
    };
    bool DaLiSadrzi(const Kugla &k) const{
        Kugla k2;
        return((k.DajX()==k2.DajX() && k.DajY()==k2.DajY() && k.DajZ()==k2.DajZ() && k.DajPoluprecnik()!=k2.DajPoluprecnik()) || (k.r1==k2.r1 && k.pp!=k2.pp));
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
bool DaLiSuIdenticne(const Kugla &k1,const Kugla &k2){
    return ((k1.m==k2.m && k1.n==k2.n && k1.o==k2.o && k1.pp==k2.pp) || (k1.r1==k2.r1 && k1.pp==k2.pp));
}
bool DaLiSuPodudarne(const Kugla &k1,const Kugla &k2){
    return (k1.pp==k2.pp);
}
bool DaLiSuKoncentricne(const Kugla &k1,const Kugla &k2){
    return ((k1.m==k2.m && k1.n==k2.n && k1.o==k2.o) || (k1.r1==k2.r1));
}
bool DaLiSeDodirujuIznutra(const Kugla &k1,const Kugla &k2){
    return ((k1.m==k2.m && k1.n!=k2.n && k1.o!=k2.o) || (k1.m!=k2.m && k1.n==k2.n && k1.o!=k2.o) || (k1.m!=k2.m && k1.n!=k2.n && k1.o==k2.o));
}
bool DaLiSeDodirujuIzvana(const Kugla &k1,const Kugla &k2){
     return ((k1.m==k2.m && k1.n!=k2.n && k1.o!=k2.o) || (k1.m!=k2.m && k1.n==k2.n && k1.o!=k2.o) || (k1.m!=k2.m && k1.n!=k2.n && k1.o==k2.o));
}
bool DaLiSePreklapaju(const Kugla &k1,const Kugla &k2){
    return (((abs(k1.pp - k2.pp)) <= sqrt((k1.m - k2.m)*(k1.m-k2.m) + (k1.n - k2.n)*(k1.n - k2.n)+(k1.o-k2.o)*(k1.o-k2.o))) && ((abs(k1.pp + k2.pp)) >= sqrt((k1.m - k2.m)*(k1.m-k2.m) + (k1.n - k2.n)*(k1.n - k2.n)+(k1.o-k2.o)*(k1.o-k2.o))));
}
double RastojanjeCentara(const Kugla &k1,const Kugla &k2){
    return sqrt( pow( k1.DajX() - k2.DajX(), 2 ) + pow( k1.DajY() - k2.DajY(), 2 ) + pow( k1.DajZ() - k2.DajZ(), 2 ) );
}
bool DaLiSeSijeku(const Kugla &k1,const Kugla &k2){
    return (RastojanjeCentara(k1,k2)<=(k1.DajPoluprecnik()+k2.DajPoluprecnik()) && (RastojanjeCentara(k1,k2)> abs(k1.DajPoluprecnik()-k2.DajPoluprecnik())));
}

int main(){
    
    double m;
    std::cout << "Unesite broj kugla: ";
        std::cin>>m;
    while(m<=0 || !(std::cin)){
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        std::cin>>m;
    }
    std::vector<Kugla> v(m);
    for(int i=0;i<m;i++){
        
        std::cout << "Unesite centar " << i+1 <<". kugle: ";
        double x1,y1,z1;
        Kugla nekaKugla;
        if(!(std::cin >> x1 >> y1 >> z1)){std::cout << "Neispravan centar\n";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        i--;
        continue;}
        std::cin.clear();
        std::cin.ignore(1000,'\n');
        double ro;
        std::cout << "Unesite poluprecnik "<< i+1 <<". kugle: ";
        std::cin>>ro;
        if(ro<0 || !(std::cin)){
            std::cout << "Ilegalan poluprecnik\n";
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            i--;
            continue;
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
        v.push_back(nekaKugla);
    }
    for(int i=0;i<m;i++){
        v.erase(v.begin());
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x2,y2,z2;
    for(;;){
    if(!(std::cin>>x2 >> y2 >> z2)){
        std::cout <<"Neispravni parametri translacije, unesite ponovo!\n";
        std::cin.clear();
        std::cin.ignore(1000,'\n');
    }
        else break;
    };
    for(int i=0;i<v.size();i++){
        v[i].Transliraj(x2,y2,z2);
    } 
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::sort(v.begin(),v.end(),[](const Kugla &k1,const Kugla &k2){return k1.DajZapreminu()<k2.DajZapreminu();});
    std::for_each(v.begin(),v.end(),[](Kugla const &k){ k.Ispisi();});
    std::cout << "Kugla sa najvecom povrsinom je: ";
    auto k= std::max_element(v.begin(),v.end(),[](const Kugla &k1,const Kugla &k2){return k1.DajPoluprecnik()<k2.DajPoluprecnik();});
    k->Ispisi();
    int a=0;
    for(int i=0;i<v.size();i++){
        Kugla prva=v[i];
        for(int j=i+1;j<v.size();j++){
            Kugla druga=v[j];
            if(prva.DajX()==druga.DajX() && prva.DajY()==druga.DajY() && prva.DajZ()==druga.DajZ() && prva.DajPoluprecnik()==druga.DajPoluprecnik()) continue;
            if(DaLiSeSijeku(prva,druga)){
                std::cout <<"Presjecaju se kugle: ";
                prva.Ispisi();
                druga.Ispisi();
                a++;
            }
        }}
    if(a==0){
        std::cout << "Ne postoje kugle koje se presjecaju!";
    }
    return 0;
}
















