/B2017/2018: Zadaća 4, Zadatak 1

#include <algorithm>
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>

class Kugla{
    std::tuple<double, double, double> centar;
    double r;
    
    static bool poredi (double x, double y)
    {
         return std::fabs(x - y) < 10e-10 * (std::fabs(x) + std::fabs(y));
    }
    
public:
    explicit Kugla(double r) : Kugla(0,0,0,r) {}
    
    Kugla(double x, double y, double z, double r = 0) : Kugla(std::make_tuple(x,y,z), r) {}
    
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) : centar(centar), r(r)
    {
        if(r < 0)
            throw std::domain_error("Ilegalan poluprecnik");
    }
    
    double DajX() const { return std::get<0>(centar);}
    double DajY() const { return std::get<1>(centar);} 
    double DajZ() const { return std::get<2>(centar);}
    std::tuple<double, double, double> DajCentar() const {return centar;}
    
    double DajPoluprecnik() const {return r;}
    double DajPovrsinu() const
    {   
        const auto pi = 4 * std::atan(1.);
        return 4 * r * r * pi;
    }
    double DajZapreminu() const
    {
        const auto pi = 4 * std::atan(1.);
        return 4./ 3 * r * r * r * pi;
    }
    
    Kugla &PostaviX(double x)
    {
        std::get<0>(centar) = x;
        return *this;
    } 
    Kugla &PostaviY(double y)
    {
        std::get<1>(centar) = y;
        return *this;
    }
    Kugla &PostaviZ(double z)
    {
        std::get<2>(centar) = z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z)
    {
        centar = std::tie(x,y,z);
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar)
    {
        this->centar = centar;
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r)
    {
        if(r < 0)
            throw std::domain_error("Ilegalan poluprecnik");
        this->r = r;
        return *this;
    }
    
    void Ispisi() const
    {
        std::cout << "{(" << DajX() << ',' << DajY() << ',' << DajZ() << ")," << DajPoluprecnik() << "}";    
    }
    
    void Transliraj(double delta_x, double delta_y, double delta_z)
    {
        std::get<0>(centar) += delta_x;
        std::get<1>(centar) += delta_y;
        std::get<2>(centar) += delta_z;
    }
    
    bool DaLiSadrzi(const Kugla &k) const
    {
        return RastojanjeCentara(*this, k) < r - k.r || Kugla::poredi(RastojanjeCentara(*this, k), r - k.r);
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

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return DaLiSuKoncentricne(k1, k2) && DaLiSuPodudarne(k1, k2);
}


bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::poredi(k1.r, k2.r);
}


bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::poredi(k1.DajX(), k2.DajX()) && Kugla::poredi(k1.DajY(), k2.DajY()) &&
            Kugla::poredi(k1.DajZ(), k2.DajZ());
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return Kugla::poredi(RastojanjeCentara(k1, k2), k1.DajPoluprecnik() + k2.DajPoluprecnik());
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return Kugla::poredi(RastojanjeCentara(k1, k2), std::fabs(k1.r - k2.r));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return DaLiSeDodirujuIznutra(k1, k2) || k1.DaLiSadrzi(k2) || DaLiSeSijeku(k1, k2) || k2.DaLiSadrzi(k1) || DaLiSeDodirujuIzvana(k1, k2);
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1) && RastojanjeCentara(k1, k2) < (k1.r + k2.r);
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    const double x = (k2.DajX() - k1.DajX()); 
    const double y = (k2.DajY() - k1.DajY());
    const double z = (k2.DajZ() - k1.DajZ());
    
    return std::sqrt(x*x + y*y + z*z);
}

int main ()
{
    
    Kugla k(1,1,1,1);
    std::cout << k.DaLiSadrzi(k);
    return 0;
    
    std::cout << "Unesite broj kugla: ";
    
    int n;
    
    for(;;){
        std::cin >> n;
        if(n > 0){
            break;
        }
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(1000, '\n');    
        }
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        
    }
    
    std::vector<std::shared_ptr<Kugla>> vec;
    vec.reserve(n);
    for(int i = 0; i < n; ++i){
        double x, y, z, r;
        for(;;){
            std::cout << "Unesite centar " << i + 1 << ". kugle: ";
            std::cin >> x >> y >> z;
            if(!std::cin){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Neispravan centar\n";
                continue;
            }
            
            std::cout << "Unesite poluprecnik " << i + 1 << ". kugle: ";
            std::cin >> r;    
            
            if(!std::cin){
                std::cin.clear();
                std::cin.ignore(1000, '\n');    
                std::cout << "Ilegalan poluprecnik\n";
                continue;                
            }

            if(r < 0){
                std::cout << "Ilegalan poluprecnik\n";
                continue;
            }
            break;
        }
        
        try {
            Kugla k(x,y,z,r);
            vec.emplace_back(new Kugla(k));
        }
        catch (std::domain_error e) {
            --i;
            std::cout << e.what() << std::endl;
        }
        
        
    }
    
    
    double dx, dy, dz;
    
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;){
        std::cin >> dx >> dy >> dz;
        if(!std::cin){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Neispravni parametri translacije, unesite ponovo!\n"; 
        }
        else{
            break;
        }
        
    }
    
    std::transform(vec.begin(), vec.end(), vec.begin(), [dx, dy, dz](std::shared_ptr<Kugla>& k) {
        k->Transliraj(dx, dy, dz);
        return k;
    });
    
    std::sort(vec.begin(), vec.end(), [](const std::shared_ptr<Kugla>& k1, const std::shared_ptr<Kugla>& k2){
        return k1->DajZapreminu() < k2->DajZapreminu();
    } );
    
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each(vec.begin(), vec.end(), [] (const std::shared_ptr<Kugla>& k) {
        k->Ispisi();
        std::cout << '\n';
    } );
    
    std::cout << "Kugla sa najvecom povrsinom je: ";
    
    (*std::max_element(vec.begin(), vec.end(), [](const std::shared_ptr<Kugla>& k1, const std::shared_ptr<Kugla>& k2){
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    } ))->Ispisi();
    std::cout << '\n';
    
    bool sijeku = false;
    std::for_each(vec.begin(), vec.end(), [&vec, &sijeku] (const std::shared_ptr<Kugla>& k1) {
        auto poc = std::find(vec.begin(), vec.end(), k1);
        poc = (poc == vec.end() ? poc : ++poc);
        std::for_each(poc, vec.end(), [&k1, &sijeku] (const std::shared_ptr<Kugla>& k2) {
            if(DaLiSeSijeku(*k1, *k2) && &k1 != &k2){
                sijeku = true;
                std::cout << "Presjecaju se kugle: ";
                k1->Ispisi();
                std::cout << '\n';
                k2->Ispisi();
                std::cout << '\n';
            }
        } );
    } );
    
    if(!sijeku){
        std::cout << "Ne postoje kugle koje se presjecaju!";
    }
}
