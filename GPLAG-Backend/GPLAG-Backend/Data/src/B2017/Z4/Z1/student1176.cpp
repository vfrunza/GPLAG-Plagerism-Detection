/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <new>
#include <tuple>
#include <vector> 
#include <memory>
#include <algorithm>


const double Pi(4 * atan(1));
const double eps = 1e-10;


class Kugla
{
    double x, y, z, r;
    
    static bool JesuLiJednaki(double x, double y, double eps = 1e-10)
    {
        return (std::fabs(x-y) <= eps * (std::fabs(x) + std::fabs(y)));
    }
    
    public:
    
    explicit Kugla(double r = 0);
    Kugla(double x, double y, double z, double r = 0);
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0);
    
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    
    std::tuple<double, double, double> DajCentar() const;
    
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik(double r);
    
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    
    bool DaLiSadrzi(const Kugla &k) const;
    
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
    
};

Kugla::Kugla(double r)
{
   Kugla::r = r;
   Kugla::x = 0;
   Kugla::y = 0;
   Kugla::z = 0;

}


Kugla::Kugla(double x, double y, double z, double r)
{
    Kugla::x = x;
    Kugla::y = y;
    Kugla::z = z;
    Kugla::r = r;
}

Kugla::Kugla(const std::tuple<double, double, double> &centar, double r)
{
    if(r<0) throw std::domain_error("Ilegalan poluprecnik");
    
    Kugla::x = std::get<0>(centar);
    Kugla::y = std::get<1>(centar);
    Kugla::z = std::get<2>(centar);
    Kugla::r = r;
}

double Kugla::DajX() const
{
    return x;
}

double Kugla::DajY() const
{
    return y;
}

double Kugla::DajZ() const
{
    return z;
}

std::tuple<double, double, double> Kugla::DajCentar() const
{
    std::tuple<double, double, double> a;
    a = std::make_tuple(Kugla::x, Kugla::y, Kugla::z);
    
    return a;
}

double Kugla::DajPoluprecnik() const
{
    return r;
}

double Kugla::DajPovrsinu() const
{
    return 4 * r * r * Pi;
}

double Kugla::DajZapreminu() const
{
    return (4.0/3.0) * r * r * r * Pi; 
}

Kugla &Kugla::PostaviX(double x)
{
    Kugla::x = x;
    return *this;
}

Kugla &Kugla::PostaviY(double y)
{
    Kugla::y = y;
    return *this;
}

Kugla &Kugla::PostaviZ(double z)
{
    Kugla::z = z;
    return *this;
}

Kugla &Kugla::PostaviCentar(double x, double y, double z)
{
    Kugla::x = x;
    Kugla::y = y;
    Kugla::z = z;
    
    return *this;
}

Kugla &Kugla::PostaviCentar(const std::tuple<double, double, double> &centar)
{
    Kugla::x = std::get<0>(centar);
    Kugla::y = std::get<1>(centar);
    Kugla::z = std::get<2>(centar);
    
    return *this;
}

Kugla &Kugla::PostaviPoluprecnik(double r)
{
    if(r<0) throw std::domain_error ("Ilegalan poluprecnik");
    
    Kugla::r = r;
    
    return *this;
}

void Kugla::Ispisi() const
{
    std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    Kugla::x += delta_x;
    Kugla::y += delta_y;
    Kugla::z += delta_z;
}

// Prijateljske funkcije:

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    int brojac(0);
    if(Kugla::JesuLiJednaki(k1.DajX(), k2.DajX()) == true) brojac++;
    if(Kugla::JesuLiJednaki(k1.DajY(), k2.DajY()) == true) brojac++;
    if(Kugla::JesuLiJednaki(k1.DajZ(), k2.DajZ()) == true) brojac++;
    if(Kugla::JesuLiJednaki(k1.DajPoluprecnik(), k2.DajPoluprecnik()) == true) brojac++;
    
    if(brojac == 4) return true;
    else return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(Kugla::JesuLiJednaki(k1.DajPoluprecnik(), k2.DajPoluprecnik()) == true) return true;
    
    return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    int brojac(0);
    if(Kugla::JesuLiJednaki(k1.DajX(), k2.DajX()) == true) brojac++;
    if(Kugla::JesuLiJednaki(k1.DajY(), k2.DajY()) == true) brojac++;
    if(Kugla::JesuLiJednaki(k1.DajZ(), k2.DajZ()) == true) brojac++;
    
    if(brojac == 3) return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    double rastojanje1 = RastojanjeCentara(k1, k2);
    double rastojanje2 = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    
    if(Kugla::JesuLiJednaki(rastojanje1, rastojanje2) == true) return true;
    return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    double rastojanje1 = RastojanjeCentara(k1, k2);
    double rastojanje2 = std::fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik());
    
    if(Kugla::JesuLiJednaki(rastojanje1, rastojanje2)) return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSuIdenticne(k1, k2) == true || DaLiSuKoncentricne(k1, k2) == true || DaLiSeDodirujuIznutra(k1, k2) == true || DaLiSeSijeku(k1, k2) == true || 
        k1.DaLiSadrzi(k2) == true || k2.DaLiSadrzi(k1) == true) return true;
        
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    double rastojanje1 = RastojanjeCentara(k1, k2);
    double rastojanje2 = k1.DajPoluprecnik() + k2.DajPoluprecnik();
    
    if(rastojanje1 <= rastojanje2 && DaLiSeDodirujuIznutra(k1, k2) == false && DaLiSeDodirujuIzvana(k1, k2) == false && (k1.DaLiSadrzi(k2) == false || k2.DaLiSadrzi(k1) == false)) return true;
    
    return false;
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    double rastojanje = RastojanjeCentara(*this, k);
    
    if(this->r > rastojanje + k.DajPoluprecnik()) return true;
    
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    double rastojanje(0);
    
    rastojanje = std::sqrt((k2.DajX() - k1.DajX())*(k2.DajX() - k1.DajX()) + (k2.DajY() - k1.DajY())*(k2.DajY() - k1.DajY()) + (k2.DajZ() - k1.DajZ())*(k2.DajZ() - k1.DajZ()));
    
    return rastojanje;
}



int main ()
{
    int n;
    
    try
    {
        //Unos broja kugli:
        
        std::cout << "Unesite broj kugla: ";
        for(;;)
        {
            std::cin >> n;
            
            if(!std::cin || std::cin.peek() != '\n' || n <= 0) 
            {
                std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
            }
            else break;
        }
        
        std::vector<std::shared_ptr<Kugla>> Vektor(n);
        
        //Unos Kugli:
        bool centarBool = false;
        bool poluprecnikBool = false;
        
        for(int i=0; i<n; i++)
        {
            double r;
            double a, b, c;
            //int kont(0);
            
            //
            for(;;)
            {
                for(;;)
                {
                    std::cout << "Unesite centar " << i+1 << ". kugle: ";
                    
                    std::cin >> a >> b >> c;
                
                    //if(!std::cin || std::cin.peek() != '\n')
                    if(!std::cin)
                    {
                        std::cout << "Neispravan centar" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(100000, '\n');
                    }
                    else 
                    {
                        centarBool = true;
                        break;
                    }
                }
            
                std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
                for(;;)
                {
                    
                    std::cin >> r;
                
                   // if(!std::cin || std::cin.peek() != '\n' || r<0)
                    if(!std::cin || r<0)
                    {
                        std::cout << "Ilegalan poluprecnik" << std::endl;
                        std::cin.clear();
                        std::cin.ignore(100000, '\n');
                        
                        poluprecnikBool = false;
                        if(centarBool == true && poluprecnikBool == false )
                        {
                            i--;
                            break;
                        }
                    }
                    else
                    {
                        poluprecnikBool = true;
                        break;
                    }
                }
                if(centarBool && poluprecnikBool)
                {
                    std::shared_ptr<Kugla> kuglica = std::make_shared<Kugla>(a, b, c, r);
            
                    Vektor[i] = kuglica;
                    break;
                }
                else
                {
                    break;
                }
            }
        }
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        
        double delta_x, delta_y, delta_z;
        
        for(;;)
        {
            std::cin >> delta_x >> delta_y >> delta_z;
            
           // if(!std::cin || std::cin.peek() != '\n')
            if(!std::cin)
            {
                std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
                std::cin.clear();
                std::cin.ignore(100000, '\n');
            }
            else break;
        }
        
        std::transform(Vektor.begin(), Vektor.end(), Vektor.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> kugla)
        {
            kugla->Transliraj(delta_x, delta_y, delta_z);
            return kugla;
        });
        
        std::sort(Vektor.begin(), Vektor.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2)
        {
            double v1, v2;
            v1 = k1->DajZapreminu();
            v2 = k2->DajZapreminu();
            
            if(v1 < v2) return true;
            return false;
        });
        
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
        
        std::for_each(Vektor.begin(), Vektor.end(), [](std::shared_ptr<Kugla> k)
        {
            k->Ispisi();
        });
        
        auto pok = std::max_element(Vektor.begin(), Vektor.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2)
        {
            double p1, p2;
            p1 = k1->DajPovrsinu();
            p2 = k2->DajPovrsinu();
            
            if(p1 < p2) return true;
            return false;
        });
        
        std::cout << "Kugla sa najvecom povrsinom je: ";
        (*pok)->Ispisi();
        
        int index(0), brojac(0);
        
        std::for_each(Vektor.begin(), Vektor.end(), [&index, &brojac, Vektor](std::shared_ptr<Kugla> k1)
        {
            index++;
            std::for_each(Vektor.begin() + index, Vektor.end(), [k1, &brojac](std::shared_ptr<Kugla> k2)
            {
                if(DaLiSeSijeku(*k1, *k2))
                {
                    std::cout << "Presjecaju se kugle: ";
                    k1->Ispisi();
                    k2->Ispisi();
                    brojac++;
                }
            });
        });
        
        if(brojac == 0) std::cout << "Ne postoje kugle koje se presjecaju!";
    }
    catch (std::domain_error izuzetak)
    {
        std::cout << izuzetak.what();
    }
    
	return 0;
}
