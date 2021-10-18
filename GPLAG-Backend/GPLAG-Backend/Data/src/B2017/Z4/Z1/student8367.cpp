/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <memory>
#include <algorithm>
#include <string>
#include <tuple>
const double PI = 4 * atan(1);
const double Eps(1e-10);

class Kugla
{
    double x, y, z, r;
public:
    explicit Kugla (double r = 0) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r = r;
        Kugla::x = 0;
        Kugla::y = 0;
        Kugla::z = 0;
    }

    Kugla (double x, double y, double z, double r = 0) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r = r;
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
    }

    explicit Kugla (const std::tuple < double, double, double > &centar, double r = 0) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r = r;
        Kugla::x = std::get < 0 > (centar);
        Kugla::y = std::get < 1 > (centar);
        Kugla::z = std::get < 2 > (centar);
    }

    double DajX() const {
        return x;
    }

    double DajY() const {
        return y;
    }

    double DajZ() const {
        return z;
    }

    bool static TestirajJednakost (double a, double b) {
        if (fabs (a - b) < Eps *(fabs(a) + fabs(b)))
            return true;
        return false;
    }

    std::tuple < double, double, double > DajCentar() const {
        return std::make_tuple(x, y, z);
    }

    double DajPoluprecnik() const {
        return r;
    }

    double DajPovrsinu() const {
        return 4 * r * r * PI;
    }

    double DajZapreminu() const {
        return 4. / 3 * r * r * r * PI;
    }

    Kugla &PostaviX (double x) {
        Kugla::x = x;
        return *this;
    }

    Kugla &PostaviY (double y) {
        Kugla::y = y;
        return *this;
    }

    Kugla &PostaviZ (double z) {
        Kugla::z = z;
        return *this;
    }

    Kugla &PostaviCentar(double x, double y, double z) {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        return *this;
    }

    Kugla &PostaviCentar (const std::tuple < double, double, double > &centar) {
        Kugla::x = std::get < 0 > (centar);
        Kugla::y = std::get < 1 > (centar);
        Kugla::z = std::get < 2 > (centar);
        return *this;
    }

    Kugla &PostaviPoluprecnik (double r) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r = r;
        return *this;
    }

    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}";
    }

    void Transliraj (double delta_x, double delta_y, double delta_z) {
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
    friend double RastojanjeCentara (const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi (const Kugla &k) const {
        return RastojanjeCentara (*this, k) <= r - k.r;
    }
};

bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2)
{
    if (Kugla::TestirajJednakost(k1.DajX(), k2.DajX()) && Kugla::TestirajJednakost(k1.DajY(), k2.DajY()) && Kugla::TestirajJednakost(k1.DajZ(), k2.DajZ())
            && Kugla::TestirajJednakost(k1.DajPoluprecnik(), k2.DajPoluprecnik()))
        return true;
    return false;
}

bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2)
{
    if (Kugla::TestirajJednakost(k1.DajPoluprecnik(), k2.DajPoluprecnik()))
        return true;
    return false;
}

bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2)
{
    if (Kugla::TestirajJednakost(k1.DajX(), k2.DajX()) && Kugla::TestirajJednakost(k1.DajY(), k2.DajY()) && Kugla::TestirajJednakost(k1.DajZ(), k2.DajZ()))
        return true;
    return false;
}

bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2)
{
    if (Kugla::TestirajJednakost(k1.DajPoluprecnik() + k2.DajPoluprecnik(), RastojanjeCentara(k1, k2))) {
        return true;
    }
    return false;
}

bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2)
{
    if (Kugla::TestirajJednakost(fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()), RastojanjeCentara(k1, k2)))
        return true;
    return false;
}

bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2)
{
    if (DaLiSeSijeku(k1, k2) || DaLiSuIdenticne(k1, k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1))
        return true;
    return false;
}

bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2)
{
    if ((fabs(RastojanjeCentara(k1, k2)) < k1.r + k2.r) && (fabs(RastojanjeCentara(k1, k2)) > fabs(k1.r - k2.r)))
        return true;
    return false;
}

double RastojanjeCentara (const Kugla &k1, const Kugla &k2)
{
    return sqrt (pow(k2.x - k1.x, 2) + pow(k2.y - k1.y, 2) + pow(k2.z - k1.z, 2));
}

template < typename TIP >
bool ValidanUnos (TIP &unos, std::string s)
{
    //std::cout << s;
    while (1) {
        if (std::cin >> unos) {
            break;
        } else {
            
            //std::cout << s;
            return false;
        }
    }
    return true;
}

int main ()
{
    int n;
    std::cout<<"Unesite broj kugla: ";
    bool validanUnos=true;
    while (true) 
    {
        validanUnos=ValidanUnos(n, "Unesite broj kugla: ");
        if(n<1 || validanUnos==false)
        {
            std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else break;
    }
    std::vector < std::shared_ptr < Kugla >> kugle (n);
    for (int i = 0; i < n; i++) {
        ponovo:
        validanUnos=true;
        double x, y, z, r;
        std::cout << "Unesite centar " << i+1 << ". kugle: ";
        if(ValidanUnos(x, "x = ")==false) validanUnos=false; 
        if(ValidanUnos(y, "y = ")==false) validanUnos=false;
        if(ValidanUnos(z, "z = ")==false) validanUnos=false;
        if(validanUnos==false)
        {
            std::cout<<"Neispravan centar\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            goto ponovo;
        }
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        validanUnos=ValidanUnos(r, "r = ");
        while (1) {
            if (r < 0 || validanUnos==false) {
                std::cout << "Ilegalan poluprecnik" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                goto ponovo;
            } else break;
        }
        kugle [i] = std::make_shared < Kugla > (x, y, z, r);
    }
    double delta_x, delta_y, delta_z;
    int brojac(1);
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    ponovo1:
       bool v=true;
       if(ValidanUnos(delta_x, "x = ")==false) v=false; 
        if(ValidanUnos(delta_y, "y = ")==false) v=false;
        if(ValidanUnos(delta_z, "z = ")==false) v=false;
        if(v==false)
        {
            std::cout<<"Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            goto ponovo1;
        }
    std::transform (kugle.begin(), kugle.end(), kugle.begin(), [&delta_x, &delta_y, &delta_z, &brojac] (std::shared_ptr < Kugla > k) {
       (*k).Transliraj(delta_x, delta_y, delta_z);
       brojac++;
       return k;
    });

    std::sort (kugle.begin(), kugle.end(), [] (std::shared_ptr < Kugla > k1, std::shared_ptr < Kugla > k2) {
        return k1 -> DajZapreminu() < k2 -> DajZapreminu();
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:\n";
    brojac = 1;
    std::for_each (kugle.begin(), kugle.end(), [&brojac] (std::shared_ptr < Kugla > za_ispis) {
        za_ispis -> Ispisi();
        std::cout << std::endl;
        brojac++;
    });

    auto max_kugla = *max_element (kugle.begin(), kugle.end(), [](std::shared_ptr < Kugla > najveci, std::shared_ptr < Kugla > sljedeci) {
        if (najveci -> DajPovrsinu() < sljedeci -> DajPovrsinu()) return true;
        return false;
    });

    std::cout << "Kugla sa najvecom povrsinom je: ";
    max_kugla -> Ispisi();
    bool t = true;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (DaLiSeSijeku(*kugle[i], *kugle[j])) {
                std::cout << "\nPresjecaju se kugle: ";
                kugle[i] -> Ispisi();
                std::cout << "\n";
                kugle[j] -> Ispisi();
                t = false;
            }
        }
    }
    std::cout << std::endl;
    if (t) std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
    return 0;
}
