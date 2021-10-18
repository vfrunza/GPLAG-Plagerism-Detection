#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double eps = 1e-10;
class Kugla
{
    double x, y, z, r;
public:
    explicit Kugla(double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = 0;
        Kugla::x = 0;
        Kugla::y = 0;
        Kugla::z = 0;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;
        Kugla::r = r;
    }
    explicit Kugla(const std::tuple<double,double,double> &centar, double r1 = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        r = r1;
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
    std::tuple<double,double,double> DajCentar() const {
        std::tuple<double,double,double> t(std::make_tuple(x,y,z));
        return t;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*(4*atan(1));
    }
    double DajZapreminu() const {
        return (4/3.)*r*r*r*(4*atan(1));
    }
    Kugla &PostaviX(double x) {
        Kugla::x = x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        Kugla::y = y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        Kugla::z = z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
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
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;
        return  *this;
    }
    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}";
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
    if((std::abs(k1.x - k2.x) < eps*(std::abs(k1.x) + std::abs(k2.x))) &&
            (std::abs(k1.y - k2.y) < eps*(std::abs(k1.y) + std::abs(k2.y))) &&
            (std::abs(k1.z - k2.z) < eps*(std::abs(k1.z) + std::abs(k2.z))) &&
            (std::abs(k1.r - k2.r) < eps*(std::abs(k1.r) + std::abs(k2.r))))
        return true;
    return false;
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if(std::abs(k1.r - k2.r) < eps*(std::abs(k1.r) + std::abs(k2.r))) return true;
    return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    if((std::abs(k1.x - k2.x) < eps*(std::abs(k1.x) + std::abs(k2.x))) &&
            (std::abs(k1.y - k2.y) < eps*(std::abs(k1.y) + std::abs(k2.y))) &&
            (std::abs(k1.z - k2.z) < eps*(std::abs(k1.z) + std::abs(k2.z)))) return true;

    return false;
}
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    if(std::abs(RastojanjeCentara(k1,k2) - (k1.r + k2.r))
            < eps*(std::abs(RastojanjeCentara(k1,k2)) +
                   std::abs(k1.r + k2.r))) return true;
    return false;
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    if(std::abs(RastojanjeCentara(k1,k2) - std::abs(k1.r-k2.r)) < eps*(std::abs(RastojanjeCentara(k1,k2)) + std::abs(k1.r-k2.r)))
        return true;
    return false;
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if(DaLiSeSijeku(k1,k2)) return true;
    if(RastojanjeCentara(k1,k2) < (k1.r + k2.r)) return true;
    return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    if((RastojanjeCentara(k1,k2) < (k1.r + k2.r)) && (RastojanjeCentara(k1,k2) >  std::abs(k1.r-k2.r))) return true;
    return false;
}
bool Kugla::DaLiSadrzi(const Kugla &k) const
{

    if(std::sqrt((x-k.x)*(x-k.x) + (y-k.y)*(y-k.y) + (z-k.z)*(z-k.z)) < r) return true;
    return false;
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x) + (k1.y-k2.y)*(k1.y-k2.y) + (k1.z-k2.z)*(k1.z-k2.z));
}
int main ()
{
    int broj_kugla;
    std::cout << "Unesite broj kugla: ";
    try {
        do {
            std::cin >> broj_kugla;
            if(broj_kugla > 0) break;
            if(broj_kugla <= 0) {
                std::cout << "Neispravan broj kugli, unesite ponovo!\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        } while(broj_kugla <= 0 || !std::cin);
        int brojac(0);
        double x, y, z, r;
        std::vector<std::shared_ptr<Kugla>> v;
        do {
            std::cout << "Unesite centar " << brojac+1 << ". kugle: ";
            std::cin >> x >> y >> z;

            while(!std::cin) {
                std::cout << "Neispravan centar\n";
                std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cin >> x >> y >> z;
            }
            std::cout << "Unesite poluprecnik " << brojac+1 << ". kugle: ";
            std::cin >> r;
            while(r < 0 || !std::cin) {
                std::cout << "Ilegalan poluprecnik\n";
                std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cin >> x >> y >> z;
                while(!std::cin) {
                    std::cout << "Neispravan centar\n";
                    std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
                    std::cin.clear();
                    std::cin.ignore(10000,'\n');
                    std::cin >> x >> y >> z;
                }
                std::cout << "Unesite poluprecnik " << brojac + 1 << ". kugle: ";
                std::cin >> r;
            }
            std::shared_ptr<Kugla> p(std::make_shared<Kugla>(x,y,z,r));
            v.push_back(p);
            brojac++;

        } while(brojac != broj_kugla);
        double delta_x, delta_y, delta_z;
        do {
            std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
            std::cin >> delta_x >> delta_y >> delta_z;
            while(!std::cin) {
                std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cin >> delta_x >> delta_y >> delta_z;
            }
        } while(!std::cin);
        std::transform(v.begin(), v.end(), v.begin(),[delta_x,delta_y,delta_z](std::shared_ptr<Kugla> p1) {
            (*p1).Transliraj(delta_x,delta_y,delta_z);
            return p1;
        });

        std::sort(v.begin(),v.end(),[](std::shared_ptr<Kugla> p2, std::shared_ptr<Kugla> p3) {
            return (*p2).DajZapreminu() < (*p3).DajZapreminu();
        });

        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
        std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> p) {
            std::cout << "{(" << (*p).DajX() << "," << (*p).DajY() << "," << (*p).DajZ() << ")"
                      << "," << (*p).DajPoluprecnik() << "}\n";
        });
        std::cout << "Kugla sa najvecom povrsinom je: ";
        auto Max = std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
            return (*p1).DajPovrsinu() < (*p2).DajPovrsinu();
        });
        std::cout << "{(" << (**Max).DajX() << "," << (**Max).DajY() << "," << (**Max).DajZ() << ")"
                  << "," << (**Max).DajPoluprecnik() << "}\n";

        std::vector<std::pair<Kugla,Kugla>> P;
        std::for_each(v.begin(), v.end(), [&P,v](std::shared_ptr<Kugla> k1) {
            std::for_each(v.begin(),v.end(), [&P,v,k1](std::shared_ptr<Kugla> k2) {
                if(DaLiSeSijeku(*k1,*k2) && k1 != k2 ) {
                    P.push_back(std::make_pair(*k1,*k2));
                }
            });
        });
        if(P.size() == 0) std::cout << "Ne postoje kugle koje se presjecaju!";
        else {
            for(int i = 0; i < P.size(); i++) {
                Kugla K1(P[i].first);
                Kugla K2(P[i].second);
                for(int j = i+1; j < P.size(); j++) {

                    if(
                        (std::abs(K1.DajX() - P[j].second.DajX())) <= eps*(std::abs(K1.DajX()) + std::abs(P[j].second.DajX())) &&
                        (std::abs(K1.DajY() - P[j].second.DajY())) <= eps*(std::abs(K1.DajY()) + std::abs(P[j].second.DajY())) &&
                        (std::abs(K1.DajZ() - P[j].second.DajZ())) <= eps*(std::abs(K1.DajZ()) + std::abs(P[j].second.DajZ())) &&

                        (std::abs(K2.DajX() - P[j].first.DajX())) <= eps*(std::abs(K2.DajX()) + std::abs(P[j].first.DajX())) &&
                        (std::abs(K2.DajY() - P[j].first.DajY())) <= eps*(std::abs(K2.DajY()) + std::abs(P[j].first.DajY())) &&
                        (std::abs(K2.DajZ() - P[j].first.DajZ())) <= eps*(std::abs(K2.DajZ()) + std::abs(P[j].first.DajZ()))
                    ) {
                        P.erase(P.begin() + j);
                        i--;
                        break;
                    }
                }
            }
            for(int i = 0; i < P.size(); i++) {
                std::cout << "Presjecaju se kugle: ";
                std::cout << "{(" << P[i].first.DajX() << "," << P[i].first.DajY() << "," << P[i].first.DajZ() << "),"
                          << P[i].first.DajPoluprecnik() << "}" << std::endl;
                std::cout << "{(" << P[i].second.DajX() << "," << P[i].second.DajY() << "," << P[i].second.DajZ() << "),"
                          << P[i].second.DajPoluprecnik() << "}" << std::endl;
            }
        }
    } catch(std::domain_error e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
