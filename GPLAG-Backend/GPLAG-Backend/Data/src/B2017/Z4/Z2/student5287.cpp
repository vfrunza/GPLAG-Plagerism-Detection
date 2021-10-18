/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>
#include <memory>

typedef std::tuple<double, double, double> t3d;
const double pi(4 * std::atan(1));
const double eps(0.0000000001);

bool Equal(double a, double b){
    return std::abs(a-b) < (eps * (std::abs(a)+std::abs(b)));
}
double Pow2(double a){ return a*a; }

class NepreklapajucaKugla{
    double x, y, z, r;
    double povrsina, zapremina;
    NepreklapajucaKugla* prethodna;
    static NepreklapajucaKugla* posljednja;
    
    void CheckRadius(double r){
        if(r < 0) throw std::domain_error("Neispravan poluprecnik, unesite ponovo:");
    }
    double GetSurface(){
        return 4 * pi * r * r;
    }
    double GetVolume(){
        return (4 * pi * r * r * r)/3;
    }
    
    void ProvjeriPreklapanje(double _x, double _y, double _z, double _r) const{
        NepreklapajucaKugla* ptr = posljednja;
        while(ptr != nullptr){
            if(std::sqrt( Pow2(_x-ptr->x) + Pow2(_y-ptr->y) + Pow2(_z-ptr->z) ) <= _r+ptr->r)
                throw std::logic_error("Nedozvoljeno preklapanje");
            ptr = ptr->prethodna;
        }
    }
    void Dodaj(){
        prethodna = posljednja;
        posljednja = this;
    }
public:
    explicit NepreklapajucaKugla(double r = 0) : x(0), y(0), z(0) {
        //Najprije provjeri validnost kugle
        CheckRadius(r);
        
        //Provjeri preklapanje
        ProvjeriPreklapanje(x, y, z, r);
        Dodaj();
        
        NepreklapajucaKugla::r = r;
        
        povrsina = GetSurface();
        zapremina = GetVolume();
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        CheckRadius(r);
        
        ProvjeriPreklapanje(x, y, z, r);
        Dodaj();
        
        NepreklapajucaKugla::x = x;
        NepreklapajucaKugla::y = y;
        NepreklapajucaKugla::z = z;
        NepreklapajucaKugla::r = r;
        
        povrsina = GetSurface();
        zapremina = GetVolume();
    }
    explicit NepreklapajucaKugla(const t3d &centar, double r = 0) {
        CheckRadius(r);
        
        double x, y, z;
        std::tie(x, y, z) = centar;
        
        ProvjeriPreklapanje(x, y, z, r);
        Dodaj();
        
        NepreklapajucaKugla::x = x;
        NepreklapajucaKugla::y = y;
        NepreklapajucaKugla::z = z;
        NepreklapajucaKugla::r = r;
        
        povrsina = GetSurface();
        zapremina = GetVolume();
    }
    
    NepreklapajucaKugla(const NepreklapajucaKugla &nk) = delete;
    NepreklapajucaKugla(const NepreklapajucaKugla &&nk) = delete;
    int operator=(const NepreklapajucaKugla &nk) = delete;
    int operator=(const NepreklapajucaKugla &&nk) = delete;
    
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    t3d DajCentar() const { return std::make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return povrsina; }
    double DajZapreminu() const { return zapremina; }
    
    NepreklapajucaKugla &PostaviX(double x) {
        ProvjeriPreklapanje(x, y, z, r);
        NepreklapajucaKugla::x = x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        ProvjeriPreklapanje(x, y, z, r);
        NepreklapajucaKugla::y = y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        ProvjeriPreklapanje(x, y, z, r);
        NepreklapajucaKugla::z = z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        ProvjeriPreklapanje(x, y, z, r);
        std::tie(NepreklapajucaKugla::x, NepreklapajucaKugla::y, NepreklapajucaKugla::z) = std::make_tuple(x, y, z);
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const t3d &centar) {
        double _x, _y, _z;
        std::tie(_x, _y, _z) = centar;
        ProvjeriPreklapanje(_x, _y, _z, r);
        x = _x;
        y = _y;
        z = _z;
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        CheckRadius(r);
        ProvjeriPreklapanje(x, y, z, r);
        NepreklapajucaKugla::r = r;
        povrsina = GetSurface();
        zapremina = GetVolume();
        return *this;
    }
    
    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        ProvjeriPreklapanje(x + delta_x, y + delta_y, z + delta_z, r);
        x += delta_x;
        y += delta_y;
        z += delta_z;
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla* NepreklapajucaKugla::posljednja = nullptr;

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return std::sqrt( Pow2(k1.x-k2.x) + Pow2(k1.y-k2.y) + Pow2(k1.z-k2.z) );
}

bool CheckCin(){
    if(!std::cin){
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}
void IspisiKugle(std::vector<std::shared_ptr<NepreklapajucaKugla>> &vec){
    std::for_each(vec.begin(), vec.end(), [](std::shared_ptr<NepreklapajucaKugla> k){
        k->Ispisi();
    });
}

int main () {
    
    int n;
    std::cout << "Unesite broj kugli: ";
    while(true){
        std::cin >> n;
        
        if(!CheckCin() || n <= 0){
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            continue;
        }
        
        break;
    }
    
    std::vector<std::shared_ptr<NepreklapajucaKugla>> vec;
    int i = 0;
    while(i < n){
        try{
            double x, y, z, r;
            
            std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
            while(true) {
                std::cin >> x >> y >> z;
                if(!CheckCin()){
                    std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
                    continue;
                }
                break;
            }
            
            std::cout << "Unesite poluprecnik: ";
            while(true) {
                std::cin >> r;
                if(!CheckCin() || r < 0){
                    std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
                    continue;
                }
                break;
            }
            
            vec.emplace_back(std::make_shared<NepreklapajucaKugla>(x, y, z, r));
            
        }catch(std::exception &err){
            std::cout << err.what() << std::endl;
            continue;
        }
        i++;
    }
    
    std::sort(vec.begin(), vec.end(), [](std::shared_ptr<NepreklapajucaKugla> a, std::shared_ptr<NepreklapajucaKugla> b){
        return a->DajPovrsinu() < b->DajPovrsinu();
    });
    
    std::cout << std::endl;
    std::cout << "Kugle nakon obavljenog sortiranja: " << std::endl;
    IspisiKugle(vec);
    
	return 0;
}
