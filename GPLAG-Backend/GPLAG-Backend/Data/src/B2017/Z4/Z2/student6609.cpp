/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>
#define eps pow(10,-10)
#define PI 4*atan(1)

class NepreklapajucaKugla {
    double x, y, z, r;
    static bool Jednakost (double a, double b) {
        if (std::fabs(a-b) <= eps*(std::fabs(a)+std::fabs(b))) return true;
        return false;
    }
    public:
    explicit NepreklapajucaKugla (double r=0); 
    NepreklapajucaKugla (double x, double y, double z, double r=0);
    explicit NepreklapajucaKugla (const std::tuple<double, double, double> &centar, double r=0);
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const;
    double DajZapreminu() const;
    NepreklapajucaKugla &PostaviX (double x);
    NepreklapajucaKugla &PostaviY (double y);
    NepreklapajucaKugla &PostaviZ (double z);
    NepreklapajucaKugla &PostaviCentar (double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar (const std::tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik (double r);
    void Ispisi() const;
    void Transliraj (double delta_x, double delta_y, double delta_z);
    friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla::NepreklapajucaKugla (double r) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    NepreklapajucaKugla::r = r;
}

NepreklapajucaKugla::NepreklapajucaKugla (double x, double y, double z, double r) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    NepreklapajucaKugla::x = x;
    NepreklapajucaKugla::y = y;
    NepreklapajucaKugla::z = z;
    NepreklapajucaKugla::r = r;
}

NepreklapajucaKugla::NepreklapajucaKugla (const std::tuple<double, double, double> &centar, double r) {
    NepreklapajucaKugla::x = std::get<0>(centar);
    NepreklapajucaKugla::y = std::get<1>(centar);
    NepreklapajucaKugla::z = std::get<2>(centar);
    NepreklapajucaKugla::r = r;
}

std::tuple<double, double, double> NepreklapajucaKugla::DajCentar() const {
    auto centar = std::make_tuple(x, y, z);
    return centar;
}

double NepreklapajucaKugla::DajPovrsinu() const {
    return 4*PI*r*r;
}

double NepreklapajucaKugla::DajZapreminu() const {
    return (4*PI*r*r*r)/3;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviX (double x) {
    NepreklapajucaKugla::x = x;
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviY (double y) {
    NepreklapajucaKugla::y = y;
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviZ (double z) {
    NepreklapajucaKugla::z = z;
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar (double x, double y, double z) {
    NepreklapajucaKugla::x = x;
    NepreklapajucaKugla::y = y;
    NepreklapajucaKugla::z = z;
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar (const std::tuple<double, double, double> &centar) {
    NepreklapajucaKugla::x = std::get<0>(centar);
    NepreklapajucaKugla::y = std::get<1>(centar);
    NepreklapajucaKugla::z = std::get<2>(centar);
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik (double r) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    NepreklapajucaKugla::r = r;
    return *this;
}

void NepreklapajucaKugla::Ispisi() const {
    std::cout << "{(" << NepreklapajucaKugla::x << "," << NepreklapajucaKugla::y << "," << NepreklapajucaKugla::z <<")," << NepreklapajucaKugla::r << "}";
}

void NepreklapajucaKugla::Transliraj (double delta_x, double delta_y, double delta_z) {
    NepreklapajucaKugla::x += delta_x;
    NepreklapajucaKugla::y += delta_y;
    NepreklapajucaKugla::z += delta_z;
}



double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    double a = std::pow(k2.x-k1.x, 2);
    double b = std::pow(k2.y-k1.y, 2);
    double c = std::pow(k2.z-k1.z, 2);
    return std::sqrt(a+b+c);
}

int main ()
{
    /*try {
        int n;
        std::cout << "Unesite broj kugla: ";
        std::cin >> n;
        for (;;) {
            if (!std::cin || n<1) {
                std::cout << "Neispravan broj kugli, unesite ponovo!";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cin >> n;
                std::cout << std::endl;
            }
            else break;
        }
        std::vector<std::shared_ptr<NepreklapajucaKugla>> v(n);
        double x, y, z, r;
        for (int i=0; i<n; i++) {
            std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
            std::cin >> x;
            if (!std::cin) {
                std::cout << "Neispravan centar" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            }
            std::cin >> y;
            if (!std::cin) {
                std::cout << "Neispravan centar" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            }
            std::cin >> z;
            if (!std::cin) {
                std::cout << "Neispravan centar" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            }
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            std::cin >> r;
            if (!std::cin || r<0) {
                std::cout << "Ilegalan poluprecnik" << std::endl;
                std::cin.clear();
                std::cin.ignore (10000, '\n');
                i--;
                continue;
            }
            NepreklapajucaKugla k (x, y, z, r);
            v.at(i) = std::make_shared<NepreklapajucaKugla> (k);
        }
        int delta_x, delta_y, delta_z;
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        for (int i=1;; i++) {
            std::cin >> delta_x;
            if (!std::cin) {
                std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            }
            std::cin >> delta_y;
            if (!std::cin) {
                std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
                std::cin.clear(); 
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            }
            std::cin >> delta_z;
            if (!std::cin) {
                std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                i--;
                continue;
            }
            break;
        }
        std::transform (v.begin(), v.end(), v.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<NepreklapajucaKugla> p1) {
                                                            p1->Transliraj(delta_x, delta_y, delta_z);
                                                            return p1;
                                                        });
        std::sort (v.begin(), v.end(), [] (std::shared_ptr<NepreklapajucaKugla> p1, std::shared_ptr<NepreklapajucaKugla> p2) {
                                            double v1 = p1->DajZapreminu(), v2 = p2->DajZapreminu();
                                            return (!(fabs(v1-v2) < eps*(fabs(v1)+fabs(v2))) && v1<v2);
                                        });
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
        std::for_each (v.begin(), v.end(), [] (std::shared_ptr<NepreklapajucaKugla> p) { p->Ispisi(); std::cout << std::endl; });
        auto Povrsina = *(std::max_element(v.begin(), v.end(), [] (std::shared_ptr<NepreklapajucaKugla> p1, std::shared_ptr<NepreklapajucaKugla> p2) {
                                                                double povr1=p1->DajPovrsinu(), povr2=p2->DajPovrsinu();
                                                                return (!(fabs(povr1-povr2) < eps*(fabs(povr1)+fabs(povr2))) && povr1<povr2);
                                                            }));
        std::cout << "Kugla sa najvecom povrsinom je: ";
        Povrsina->Ispisi();
        int br(0);
        bool ima(false);
        std::for_each(v.begin(), v.end(), [v, &br, &ima] (std::shared_ptr<NepreklapajucaKugla> p1) {
                                                br++;
                                                std::for_each (v.begin()+br, v.end(), [p1, &ima] (std::shared_ptr<NepreklapajucaKugla> p2) {
                                                                                        if (DaLiSeSijeku(*p1, *p2)) {
                                                                                            ima = true;
                                                                                            std::cout << "\nPresjecaju se kugle: ";
                                                                                            p1->Ispisi();
                                                                                            std::cout << std::endl;
                                                                                            p2->Ispisi();
                                                                                        }
                                                                                    });
                                            });
        if (!ima) std::cout << "\nNe postoje kugle koje se presjecaju!";
    }
    catch (...) {
        
    }*/
	return 0;
}