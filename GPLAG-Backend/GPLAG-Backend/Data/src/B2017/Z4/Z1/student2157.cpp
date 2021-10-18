/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>

const double Pi = 4*atan(1);
const double E = pow(10, -10);
bool presjecaju = true;

class Kugla{
    double x, y, z, r;
    public: 
        explicit Kugla(double r = 0) : x(0), y(0), z(0) {} 
        Kugla(double x, double y, double z, double r = 0) : x(x), y(y), z(z), r(r){ if(r < 0) throw std::domain_error("Ilegalan poluprecnik");}  
        explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) : x(std::get<0>(centar)), y(std::get<1>(centar)),
        z(std::get<2>(centar)), r(r){if(r < 0) throw std::domain_error("Ilegalan poluprecnik");}
        double DajX() const{return x;} 
        double DajY() const{return y;} 
        double DajZ() const{return z;} 
        std::tuple<double, double, double> DajCentar() const{ std::tuple<double, double, double> temp; std::get<0>(temp) = x; std::get<1>(temp) = y; std::get<2>(temp) = z; return temp;}
        double DajPoluprecnik() const{return r;} 
        double DajPovrsinu() const{return r*r*Pi;} 
        double DajZapreminu() const{return (4./3)*r*r*r*Pi;} 
        Kugla &PostaviX(double x){ this->x = x; return *this;} 
        Kugla &PostaviY(double y){this->y = y; return *this;} 
        Kugla &PostaviZ(double z){this->z=z; return *this;} 
        Kugla &PostaviCentar(double x, double y, double z){
            this->x = x; this->y = y; this->z=z; return *this;
        }
        Kugla &PostaviCentar(const std::tuple<double, double, double> &centar){
            this->x = std::get<0>(centar); 
            this->y = std::get<1>(centar); 
            this->z = std::get<2>(centar); 
            return *this;
        }
        Kugla &PostaviPoluprecnik(double r){this->r=r; return *this;} 
        void Ispisi() const{std::cout<<"{(" << DajX()<<","<<DajY()<<","<<DajZ()<<"),"<<DajPoluprecnik()<<"}"; }
        void Transliraj(double delta_x, double delta_y, double delta_z){
            x+=delta_x;
            y+=delta_y;
            z+=delta_z;
        } 
        friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
        friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
        bool DaLiSadrzi(const Kugla &k) const{
            if(this->DajPoluprecnik() > k.DajPoluprecnik() + RastojanjeCentara(*this, k)) return true;
            else return false;
        }
        friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};
        
        bool Jednakost(const Kugla &k1, const Kugla &k2){
        return ((fabs(k1.DajX() - k2.DajX()) < E*(fabs(k1.DajX()) + fabs(k2.DajX()))) &&
        (fabs(k1.DajY() - k2.DajY()) < E*(fabs(k1.DajY()) + fabs(k2.DajY()))) &&
        (fabs(k1.DajZ() - k2.DajZ()) < E*(fabs(k1.DajZ()) + fabs(k2.DajZ())))); }
        
        bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){ 
            return ((Jednakost(k1, k2)) && ((fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik())) < (E*(fabs(k1.DajPoluprecnik()) + fabs(k2.DajPoluprecnik())))));}
       
        bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
        return (fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()) < (E * (k1.DajPoluprecnik() + k2.DajPoluprecnik())));} 
       
        bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){ return Jednakost(k1, k2);}
      
        bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){ 
        return  ((fabs(RastojanjeCentara(k1, k2) - (k1.DajPoluprecnik() + k2.DajPoluprecnik()))) < (E * (RastojanjeCentara(k1, k2) + k1.DajPoluprecnik() + k2.DajPoluprecnik()))); }
      
        bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){ 
        return  ((fabs(RastojanjeCentara(k1, k2) - (k1.DajPoluprecnik() - k2.DajPoluprecnik()))) < (E * (RastojanjeCentara(k1, k2) + k1.DajPoluprecnik() - k2.DajPoluprecnik()))); }
       
        bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){ 
            if(k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)|| DaLiSeSijeku(k1, k2)) return true;
            else return false;
        }
        bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){return (RastojanjeCentara(k1, k2) > fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()));}

        double RastojanjeCentara(const Kugla &k1, const Kugla &k2){return sqrt((k1.x - k2.x)*(k1.x - k2.x) + (k1.y - k2.y)*(k1.y - k2.y) + (k1.z - k2.z)*(k1.z - k2.z)); }
int main ()
{
    std::cout<<"Unesite broj kugla: ";
    int n;
    std::cin>>n;
    while(n <= 0 || !std::cin){
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
        std::cin>>n;
    }
    std::vector<std::shared_ptr<Kugla>> V;
    for(int i = 0; i < n; i++){
        try{
        std::cout<<"Unesite centar "<<i+1<<". kugle: ";
        double x, y, z;
        std::cin>>x>>y>>z;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw std::range_error("Neispravan centar");
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        double r;
        std::cin>>r;
        if(!std::cin || r<0){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            throw std::range_error("Ilegalan poluprecnik");
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::shared_ptr<Kugla> p(new Kugla(x, y, z, r));
 
        V.push_back(p);
        }catch(std::domain_error e){
            std::cout<<e.what()<<std::endl;
            i--;
        }
        catch(std::range_error e){
            std::cout<<e.what()<<std::endl;
            i--;
        }
        
    }
    std::cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double x, y, z;
    std::cin>>x>>y>>z;
    while(!std::cin){
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
        std::cin>>x>>y>>z;
    }
    std::transform(V.begin(), V.end(), V.begin(), [x, y, z](std::shared_ptr<Kugla> k){ k->Transliraj(x, y, z); return k;});
    std::sort(V.begin(), V.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){return k1->DajZapreminu() < k2->DajZapreminu();});
    std::cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<std::endl;
    std::for_each(V.begin(), V.end(), [](std::shared_ptr<Kugla> x){ x->Ispisi(); std::cout<<std::endl;});
    auto maks(std::max_element(V.begin(), V.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2){ 
        return (k1->DajPovrsinu() < k2->DajPovrsinu());}));
    std::cout<<"Kugla sa najvecom povrsinom je: ";
    (*maks)->Ispisi();
    std::cout<<std::endl;
    auto i1(V.begin()), i2(V.end());
    std::for_each (i1 , i2 - 1, [i1, i2] (std::shared_ptr<Kugla> k1) { 
        std::for_each (i1 + 1, i2, [i1, i2, k1] (std::shared_ptr<Kugla> k2) {
        if(DaLiSePreklapaju(*k1, *k2) && i1 != i2){
               presjecaju = false;
               std::cout<<"Presjecaju se kugle: ";
               k1->Ispisi(); 
               std::cout<<std::endl;
               k2->Ispisi(); 
               std::cout<<std::endl;
           }
       });
    });
    if(presjecaju) std::cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}
