/B2017/2018: Zadaća 4, Zadatak 2

#include <algorithm>
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>

class NepreklapajucaKugla{
    std::tuple<double, double, double> centar;
    double r;
    bool brisi = true;
    
    static NepreklapajucaKugla* zadnji;
    NepreklapajucaKugla* prethodni = nullptr;
    
    static bool poredi (double x, double y)
    {
         return std::fabs(x - y) < 10e-10 * (std::fabs(x) + std::fabs(y));
    }
    
    static bool DaLiSeDodirujuIznutra(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
    {
        return NepreklapajucaKugla::poredi(RastojanjeCentara(k1, k2), std::fabs(k1.r - k2.r));
    }
    
    static bool DaLiSeDodirujuIzvana(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
    {
        return NepreklapajucaKugla::poredi(RastojanjeCentara(k1, k2), k1.DajPoluprecnik() + k2.DajPoluprecnik());
    }
    
    static bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
    {
        return DaLiSeDodirujuIznutra(k1, k2) || k1.DaLiSadrzi(k2) || DaLiSeSijeku(k1, k2) || k2.DaLiSadrzi(k1) || DaLiSeDodirujuIzvana(k1, k2);
    }
    
    static bool DaLiSeSijeku(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
    {
        return !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1) && RastojanjeCentara(k1, k2) < (k1.r + k2.r) ;
    }
    
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const
    {
        return RastojanjeCentara(*this, k) < r - k.r || NepreklapajucaKugla::poredi(RastojanjeCentara(*this, k), r - k.r);
    }
    
    NepreklapajucaKugla(double x, double y, double z, double r, bool tag)
    {
        brisi = false;
        centar = std::tie(x, y, z);
        this->r = r;
    }
    
    void ProvjeriPreklapanje(const NepreklapajucaKugla& k)
    {
        for(auto pok = zadnji; pok != nullptr; pok = pok->prethodni)
            if(DaLiSePreklapaju(*pok, k))
                throw std::logic_error("Nedozvoljeno preklapanje");
    }
    
public:
    explicit NepreklapajucaKugla(double r) : NepreklapajucaKugla(0,0,0,r)  {}
    
    NepreklapajucaKugla(double x, double y, double z, double r = 0) : NepreklapajucaKugla(std::make_tuple(x,y,z), r) {}
    
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0); 
 
    NepreklapajucaKugla(const NepreklapajucaKugla&) = delete;
    NepreklapajucaKugla(NepreklapajucaKugla&&) = delete;
 
    NepreklapajucaKugla& operator=(NepreklapajucaKugla&&) = delete;
    NepreklapajucaKugla& operator=(const NepreklapajucaKugla&) = delete;
 
    double DajX() const { return std::get<0>(centar);}
    double DajY() const { return std::get<1>(centar);} 
    double DajZ() const { return std::get<2>(centar);}
    std::tuple<double, double, double> DajCentar() const {return centar;}
    
    double DajPoluprecnik() const {return r;}
    
    double DajPovrsinu() const
    {   
        return 16 * std::atan(1) * r * r;
    }
    
    double DajZapreminu() const
    {
        return 16./ 3 * std::atan(1) * r * r * r;
    }
    
    NepreklapajucaKugla &PostaviX(double x)
    {
        ProvjeriPreklapanje(NepreklapajucaKugla(x, DajY(), DajZ(), DajPoluprecnik(), true));
        std::get<0>(centar) = x;
        return *this;
    } 
    
    NepreklapajucaKugla &PostaviY(double y)
    {
        ProvjeriPreklapanje(NepreklapajucaKugla(DajX(), y, DajZ(), DajPoluprecnik(), true));
        std::get<1>(centar) = y;
        return *this;
    }
    
    NepreklapajucaKugla &PostaviZ(double z)
    {
        ProvjeriPreklapanje(NepreklapajucaKugla(DajX(), DajY(), z, DajPoluprecnik(), true));
        std::get<2>(centar) = z;
        return *this;
    }
    
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z)
    {
        ProvjeriPreklapanje(NepreklapajucaKugla(x, y, z, DajPoluprecnik(), true));
        centar = std::tie(x,y,z);
        return *this;
    }
    
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar)
    {
        ProvjeriPreklapanje(NepreklapajucaKugla(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), DajPoluprecnik(), true));
        this->centar = centar;
        return *this;
    }
    
    NepreklapajucaKugla &PostaviPoluprecnik(double r)
    {
        if(r < 0)
            throw std::domain_error("Ilegalan poluprecnik");
        ProvjeriPreklapanje(NepreklapajucaKugla(DajX(), DajY(), DajZ(), r, true));
        this->r = r;
        return *this;
    }
    
    void Ispisi() const
    {
        std::cout << "{(" << DajX() << ',' << DajY() << ',' << DajZ() << ")," << DajPoluprecnik() << "}";    
    }
    
    void Transliraj(double delta_x, double delta_y, double delta_z);
    
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2); 
 
    ~NepreklapajucaKugla();
};
NepreklapajucaKugla* NepreklapajucaKugla::zadnji = nullptr;

void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    ProvjeriPreklapanje(NepreklapajucaKugla(DajX() + delta_x, DajY() + delta_y, DajZ() + delta_z, DajPoluprecnik(), true));
    std::get<0>(centar) += delta_x;
    std::get<1>(centar) += delta_y;
    std::get<2>(centar) += delta_z;
}

NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r) : centar(centar), r(r)
{
    if(r < 0)
        throw std::domain_error("Ilegalan poluprecnik");
    
    ProvjeriPreklapanje(NepreklapajucaKugla(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r, true));
    
    if(zadnji == nullptr){
        zadnji = this;
    } else {
        prethodni = zadnji;
        zadnji = this;
    }
    
}

NepreklapajucaKugla::~NepreklapajucaKugla()
{
    if(!brisi)
        return;
    
    if(this == zadnji)
            zadnji = this->prethodni;
    else if(this->prethodni == nullptr){
        auto q = zadnji->prethodni;
        auto p = zadnji;
        while(q != nullptr){
            p = p->prethodni;
            q = q->prethodni;
        }
        p->prethodni = nullptr;
    } else {
        auto q = zadnji->prethodni, p = zadnji;
        while(q != this){
            p = p->prethodni;
            q = q->prethodni;
        }
        p->prethodni = this->prethodni;
    }
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    const double x = (k2.DajX() - k1.DajX()); 
    const double y = (k2.DajY() - k1.DajY());
    const double z = (k2.DajZ() - k1.DajZ());
    
    return std::sqrt(x*x + y*y + z*z);
}


int main ()
{
    std::cout << "Unesite broj kugli: ";
    
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
    
    std::vector<std::shared_ptr<NepreklapajucaKugla>> vec;
    vec.reserve(n);
    for(int i = 0; i < n; ++i){
        double x, y, z, r;
        std::cout << "Unesite centar za " << i + 1 << ". kuglu: ";
        for(;;){
            std::cin >> x >> y >> z;
            if(!std::cin){
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Neispravan centar, unesite ponovo:\n";
                continue;
            }
            break;
        }
        
        std::cout << "Unesite poluprecnik: ";
        for(;;){
            
            std::cin >> r;    
            
            if(!std::cin){
                std::cin.clear();
                std::cin.ignore(1000, '\n');    
                std::cout << "Neispravan poluprecnik, unesite ponovo:\n";
                continue;                
            }

            if(r < 0){
                std::cout << "Neispravan poluprecnik, unesite ponovo:\n";
                continue;
            }
            break;
        }
        
        try {
            vec.emplace_back(new NepreklapajucaKugla(x,y,z,r));
        }
        catch (std::domain_error e) {
            --i;
            std::cout << e.what() << std::endl;
        }
        catch(std::logic_error e){
            --i;
            std::cout << e.what() << std::endl;
        }
        
        
    }
    
    std::sort(vec.begin(), vec.end(), [](const std::shared_ptr<NepreklapajucaKugla>& k1, const std::shared_ptr<NepreklapajucaKugla>& k2){
        return k1->DajZapreminu() < k2->DajZapreminu();
    } );
    
    
    std::cout << "\nKugle nakon obavljenog sortiranja: \n";
    std::for_each(vec.begin(), vec.end(), [] (const std::shared_ptr<NepreklapajucaKugla>& k) {
        k->Ispisi();
        std::cout << '\n';
    } );
    

}
