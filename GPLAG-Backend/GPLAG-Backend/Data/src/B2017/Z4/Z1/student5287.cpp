/B2017/2018: Zadaća 4, Zadatak 1
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

class Kugla{
    double x, y, z, r;
    double povrsina, zapremina;
    void CheckRadius(double r){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
    }
    double GetSurface(){
        return 4 * pi * r * r;
    }
    double GetVolume(){
        return (4 * pi * r * r * r)/3;
    }
public:
    explicit Kugla(double r = 0) : x(0), y(0), z(0) {
        CheckRadius(r);
        Kugla::r = r;
        povrsina = GetSurface();
        zapremina = GetVolume();
    }
    Kugla(double x, double y, double z, double r = 0) : x(x), y(y), z(z) {
        CheckRadius(r);
        Kugla::r = r;
        povrsina = GetSurface();
        zapremina = GetVolume();
    }
    explicit Kugla(const t3d &centar, double r = 0) {
        CheckRadius(r);
        Kugla::r = r;
        std::tie(x, y, z) = centar;
        povrsina = GetSurface();
        zapremina = GetVolume();
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    t3d DajCentar() const { return std::make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return povrsina; }
    double DajZapreminu() const { return zapremina; }
    Kugla &PostaviX(double x) { Kugla::x = x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y = y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z = z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) {
        std::tie(Kugla::x, Kugla::y, Kugla::z) = std::make_tuple(x, y, z);
        return *this;
    }
    Kugla &PostaviCentar(const t3d &centar) {
        std::tie(Kugla::x, Kugla::y, Kugla::z) = centar;
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        CheckRadius(r);
        Kugla::r = r;
        povrsina = GetSurface();
        zapremina = GetVolume();
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z){
        x += delta_x;
        y += delta_y;
        z += delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        return RastojanjeCentara(*this, k) < std::abs(r-k.r);
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool Equal(double a, double b){
    return std::abs(a-b) < (eps * (std::abs(a)+std::abs(b)));
}
double Pow2(double a){ return a*a; }

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    return std::sqrt( Pow2(k1.x-k2.x) + Pow2(k1.y-k2.y) + Pow2(k1.z-k2.z) );
}
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
    return Equal(k1.x, k2.x) && Equal(k1.y, k2.y) && Equal(k1.z, k2.z) && Equal(k1.r, k2.r);
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
    return Equal(k1.r, k2.r);
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    return Equal(k1.x, k2.x) && Equal(k1.y, k2.y) && Equal(k1.z, k2.z);
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    return Equal(RastojanjeCentara(k1, k2), k1.r+k2.r);
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    return Equal(RastojanjeCentara(k1, k2), std::abs(k1.r-k2.r));
}
//Provjeriti valjanost funkcije!!!
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    return RastojanjeCentara(k1, k2) < k1.r+k2.r;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
    return DaLiSePreklapaju(k1, k2) && RastojanjeCentara(k1, k2) > std::abs(k1.r-k2.r);
}

bool CheckCin(){
    if(!std::cin){
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    return true;
}
void TranslateSystem(std::vector<std::shared_ptr<Kugla>> &vec, double dx, double dy, double dz){
    std::transform(vec.begin(), vec.end(), vec.begin(), [dx, dy, dz](std::shared_ptr<Kugla> k){
        k->Transliraj(dx, dy, dz);
        return k;
    });
}
void SortSystem(std::vector<std::shared_ptr<Kugla>> &vec){
    std::sort(vec.begin(), vec.end(), [](std::shared_ptr<Kugla> a, std::shared_ptr<Kugla> b){
        return a->DajZapreminu() < b->DajZapreminu();
    });
}
void IspisiKugle(std::vector<std::shared_ptr<Kugla>> &vec){
    std::for_each(vec.begin(), vec.end(), [](std::shared_ptr<Kugla> k){
        k->Ispisi();
    });
}
std::shared_ptr<Kugla> NajvecaPovrsina(std::vector<std::shared_ptr<Kugla>> &vec){
    return *std::max_element(vec.begin(), vec.end(), [](std::shared_ptr<Kugla> a, std::shared_ptr<Kugla> b){
        return a->DajPovrsinu() < b->DajPovrsinu();
    });
}

int main () {
    
    int n;
    std::cout << "Unesite broj kugla: ";
    while(true){
        std::cin >> n;
        
        if(!CheckCin() || n <= 0){
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            continue;
        }
        
        break;
    }
    
    std::vector<std::shared_ptr<Kugla>> vec;
    int i = 0;
    while(i < n){
        try{
            int x, y, z, r;
            
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            std::cin >> x >> y >> z;
            if(!CheckCin()) {
                std::cout << "Neispravan centar" << std::endl;
                continue;
            }
            
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            std::cin >> r;
            if(!CheckCin()) {
                std::cout << "Ilegalan poluprecnik" << std::endl;
                continue;
            }
            
            vec.emplace_back(std::make_shared<Kugla>(x, y, z, r));
            
        }catch(std::domain_error &err){
            std::cout << err.what() << std::endl;
            continue;
        }
        i++;
    }
    
    int dx, dy, dz;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while(true){
        std::cin >> dx >> dy >> dz;
        
        if(!CheckCin()){
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            continue;
        }
        
        break;
    }
    
    TranslateSystem(vec, dx, dy, dz);
    SortSystem(vec);
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    IspisiKugle(vec);
    
    std::shared_ptr<Kugla> k = NajvecaPovrsina(vec);
    std::cout << "Kugla sa najvecom povrsinom je: ";
    k->Ispisi();
    
    bool nePostoje = true;
    std::vector<std::shared_ptr<Kugla>>::iterator it = vec.begin();
    std::for_each(vec.begin(), vec.end(), [&vec, &nePostoje, &it](const std::shared_ptr<Kugla> &k){
        std::for_each(it, vec.end(), [&k, &nePostoje](const std::shared_ptr<Kugla> &kt){
            if(DaLiSeSijeku(*k, *kt)){
                std::cout << "Presjecaju se kugle: ";
                k->Ispisi();
                kt->Ispisi();
                nePostoje = false;
            }
        });
        it++;
    });
    
    if(nePostoje)
        std::cout << "Ne postoje kugle koje se presjecaju!";
    
	return 0;
}
