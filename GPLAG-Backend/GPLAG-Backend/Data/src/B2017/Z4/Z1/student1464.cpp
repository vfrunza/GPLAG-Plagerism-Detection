/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <memory>

class Kugla
{
    double x, y, z, r;
    const double PI = 4*std::atan(1);
    static bool Jednaki(double x, double y, double eps = 10e-10) {
        if(std::fabs(x - y) <= eps * (std::fabs(x) + std::fabs(y))) return true;
        return false;
    }
public:
    explicit Kugla(double r = 0) {
        if( r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r = r;
        Kugla::x = 0;
        Kugla::y = 0;
        Kugla::z = 0;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r = r;
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        Kugla::r = r;
    }
    double DajX () const {
        return x;
    }
    double DajY () const {
        return y;
    }
    double DajZ () const {
        return z;
    }
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(x, y, z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4 * r *r * PI;
    }
    double DajZapreminu() const {
        return r * r * r * PI *4./3.;
    }
    Kugla &PostaviX (double x) {
        Kugla:: x = x;
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

    Kugla &PostaviCentar (double x, double y, double z) {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        Kugla::r = r;
    }
    void Ispisi() const {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," <<
                  DajPoluprecnik() << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
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
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    if(Kugla::Jednaki(k1.DajX(), k2.DajX()) && Kugla::Jednaki(k1.DajY(), k2.DajY())&&
            Kugla::Jednaki(k1.DajZ(), k2.DajZ()) && Kugla::Jednaki(k1.DajPoluprecnik(), k2.DajPoluprecnik()))
        return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(Kugla::Jednaki(k1.DajPoluprecnik(), k2.DajPoluprecnik())) return true;
    return false;
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if(Kugla::Jednaki(k1.DajX(), k2.DajX()) && Kugla::Jednaki(k1.DajY(), k2.DajY()) &&
            Kugla::Jednaki(k1.DajZ(), k2.DajZ())) return true;
    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla & k2)
{
    if(Kugla::Jednaki(RastojanjeCentara(k1, k2), k1.DajPoluprecnik()+k2.DajPoluprecnik())) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    if(Kugla::Jednaki(RastojanjeCentara(k1, k2), std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()))) return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeDodirujuIznutra(k1,k2) || DaLiSeSijeku(k1,k2) || DaLiSuIdenticne(k1,k2) || DaLiSuKoncentricne(k1,k2) ||
            k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return true;
    return false;
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if(RastojanjeCentara(k1,k2) < k1.DajPoluprecnik() + k2.DajPoluprecnik() &&
            DaLiSeDodirujuIznutra(k1,k2) == false && k1.DaLiSadrzi(k2) == false && k2.DaLiSadrzi(k1) == false
            && DaLiSuIdenticne(k1,k2) == false && DaLiSuKoncentricne(k1,k2) == false) return true;
    return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    if(DajPoluprecnik() > k.DajPoluprecnik()) {
        if(DaLiSuKoncentricne(*this, k)) return true;
    }
    if(DaLiSeDodirujuIznutra(*this, k) || DaLiSuIdenticne(*this, k)) return true;
    double v, m;
    if(DajPoluprecnik() > k.DajPoluprecnik()) {
        v = DajPoluprecnik();
        m = k.DajPoluprecnik();
    } else {
        v = k.DajPoluprecnik();
        m = DajPoluprecnik();
    }
    if(RastojanjeCentara(*this, k) + m < v) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return std::sqrt((k1.DajX() - k2.DajX())*(k1.DajX() - k2.DajX()) +
                     (k1.DajY() - k2.DajY())*(k1.DajY() - k2.DajY()) + (k1.DajZ() - k2.DajZ())*(k1.DajZ() - k2.DajZ()));
}

int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    for(; ;) {
        std::cin>> n;
        if(!std::cin || n <= 0) {
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        break;
    }

    std::vector<std::shared_ptr<Kugla>> v(n);
    double x, y, z, r;
    int brojac(0);
    for(int i(0); i< n; i++) {
        for(; ;) {
            brojac++;
            std::cout << "Unesite centar " << brojac << ". kugle: ";
            std::cin>> x >> y >> z;
            if(!std::cin) {
                std::cout << "Neispravan centar" << std::endl;;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                brojac--;
                continue;
            }
            std::cout << "Unesite poluprecnik " << brojac << ". kugle: ";
            std::cin>> r;
            if(!std::cin || r < 0) {
                std::cout << "Ilegalan poluprecnik" << std::endl;
                brojac--;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }
            break;
        }
        v.at(i) = std::make_shared<Kugla> (x,y,z,r);
    }
    double deltaX, deltaY, deltaZ;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(; ;) {
        std::cin>> deltaX >> deltaY >> deltaZ;
        if(!std::cin) {
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        break;
    }
    std::transform(v.begin(), v.end(), v.begin(), [deltaX, deltaY, deltaZ](std::shared_ptr<Kugla> k) {
        k -> Transliraj(deltaX, deltaY, deltaZ);
        return k;
    });
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        if(k1->DajZapreminu() < k2->DajZapreminu()) return true;
        return false;
    });
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Kugla> k) {
        k -> Ispisi();
    });
    std::cout << std::endl <<"Kugla sa najvecom povrsinom je: " ;
    auto it = std::max_element(v.begin(), v.end(), [] (std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        if(k1 -> DajPovrsinu() < k2 -> DajPovrsinu()) return true;
        return false;
    });
    (*it)->Ispisi();
    int ind(0);
    bool bilo(false);
    std::for_each(v.begin(), v.end(), [&bilo, &ind, v] (std::shared_ptr<Kugla> k1) {
        ind++;
        std::for_each(v.begin()+ind, v.end(), [&bilo, k1] (std::shared_ptr<Kugla>k2) {
            if(DaLiSeSijeku(*k1, *k2)) {
                bilo = true;
                std::cout << std::endl << "Presjecaju se kugle: ";
                k1->Ispisi();
                k2->Ispisi();
            }

        });
    });
    if(bilo == false) std::cout << std::endl <<  "Ne postoje kugle koje se presjecaju!";

    return 0;
}

