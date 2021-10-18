/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double PI(4*atan(1));
const double e(1e-10);

class Kugla
{
    double x,y,z;
    double poluprecnik;
    
    public:
    explicit Kugla (double r = 0)
    {
        Kugla::poluprecnik = r;
        x = 0; 
        y = 0;
        z = 0;
    }
    
    Kugla (double x, double y, double z, double r = 0)
    {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        Kugla::poluprecnik = r;
    }
    
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0)
    {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::x = std::get<0>(centar);
        Kugla::y = std::get<1>(centar);
        Kugla::z = std::get<2>(centar);
        Kugla::poluprecnik = r;
    }
    
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x,y,z); }
    double DajPoluprecnik() const { return poluprecnik; }
    double DajPovrsinu() const { return 4*poluprecnik*poluprecnik*PI; }
    double DajZapreminu() const { return (4/3*poluprecnik*poluprecnik*poluprecnik*PI); }
    
    Kugla &PostaviX (double x) { Kugla::x = x;  return *this; }
    Kugla &PostaviY (double y) { Kugla::y = y;  return *this; }
    Kugla &PostaviZ (double z) { Kugla::z = z;  return *this; }
    Kugla &PostaviCentar (double x, double y, double z) 
    {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        
        return *this;
    }
    
    Kugla &PostaviCentar (std::tuple<double, double, double> &centar)
    {
        Kugla::x = std::get<0>(centar);
        Kugla::y = std::get<1>(centar);
        Kugla::z = std::get<2>(centar);
        
        return *this;
    }
    Kugla &PostaviPoluprecnik (double r)
    {
        Kugla::poluprecnik = r;
        return *this;
    }
    
    void Ispisi() const
    {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")" << "," << DajPoluprecnik() << "}";
    }
    
    void Transliraj (double delta_x, double delta_y, double delta_z)
    {
        Kugla::x += delta_x;
        Kugla::y += delta_y;
        Kugla::z += delta_z;
    }
    
    friend bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi (const Kugla &k) const;
    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
    
};

bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2)
{
    if ((fabs(k1.x - k2.x) < (e*(fabs(k1.x) + fabs(k2.x)))) && (fabs(k1.y - k2.y) < (e*(fabs(k1.y) + fabs(k2.y)))) && (fabs(k1.z - k2.z) < (e*(fabs(k1.z) + fabs(k2.z)))) && (fabs(k1.poluprecnik - k2.poluprecnik) < (e*(fabs(k1.poluprecnik) + fabs(k2.poluprecnik))))) return true;
    return false;
}

bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2)
{
    if ((fabs(k1.poluprecnik - k2.poluprecnik) < (e*(fabs(k1.poluprecnik) + fabs(k2.poluprecnik))))) return true;
    return false;
}

bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2)
{
    if ((fabs(k1.x - k2.x) < (e*(fabs(k1.x) + fabs(k2.x)))) && (fabs(k1.y - k2.y) < (e*(fabs(k1.y) + fabs(k2.y)))) && (fabs(k1.z - k2.z) < (e*(fabs(k1.z) + fabs(k2.z))))) return true;
    return false;
}

bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2)
{
    if ((fabs(RastojanjeCentara(k1,k2) - (k1.poluprecnik + k2.poluprecnik))) <  (e*(fabs(RastojanjeCentara(k1,k2) + fabs(k1.poluprecnik + k2.poluprecnik))))) return true;
    return false;
}
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2);
double RastojanjeCentara (const Kugla &k1, const Kugla &k2)
{
    return (sqrt((k1.x - k2.x)*(k1.x - k2.x) + (k1.y - k2.y)*(k1.y - k2.y) + (k1.z - k2.z)*(k1.z - k2.z)));
}
int main ()
{
    
    int n;
    std::cout << "Unesite broj kugla: ";
    std::cin >> n;
    
    

    std::vector<std::shared_ptr<Kugla>> vektor(n);
    
    double x, y, z, r;
    
    for (int i = 0; i < n; i++)
    {
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        std::cin >> x;
        std::cin >> y; 
        std::cin >> z;
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        std::cin >> r;
        
        try
        {
            vektor[i] = std::make_shared<Kugla> (Kugla(x,y,z,r));
        }
        
        catch (std::domain_error izuzetak)
        {
            std::cout << izuzetak.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
    Kugla k(x,y,z,r);
    k.PostaviCentar(x,y,z);
    double delta_x, delta_y, delta_z;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    std::cin >> delta_x >> delta_y >> delta_z;
    std::vector<std::shared_ptr<Kugla>> v(n);
    std::transform (vektor.begin(), vektor.end(), v.begin(), [delta_x,delta_y, delta_z] (std::shared_ptr<Kugla> vektor) {
        vektor->Transliraj(delta_x, delta_y, delta_z);
        return vektor;
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:" << std::endl;
    
    std::sort (v.begin(), v.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2)
    {
        return (p1 -> DajZapreminu() < p2 -> DajZapreminu());
    });
    
    std::for_each (v.begin(), v.end(), [] (std::shared_ptr<Kugla> p)
    {
        p -> Ispisi();
        std::cout << std::endl;
    });
    
    auto max = std::max_element (v.begin(), v.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2)
    {
        return (p1 -> DajPovrsinu() < p2 -> DajPovrsinu());
    });
    
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*max)->Ispisi();
	return 0;
}
