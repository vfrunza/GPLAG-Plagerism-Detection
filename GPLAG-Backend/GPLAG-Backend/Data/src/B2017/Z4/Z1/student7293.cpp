/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>
#define eps pow(10,-10)
#define PI 4*atan(1)

class Kugla {
    double x, y, z, r;
    static bool Jednakost (double a, double b) {
        if (std::fabs(a-b) <= eps*(std::fabs(a)+std::fabs(b))) return true;
        return false;
    }
    public:
    explicit Kugla (double r=0); 
    Kugla (double x, double y, double z, double r=0);
    explicit Kugla (const std::tuple<double, double, double> &centar, double r=0);
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const;
    double DajZapreminu() const;
    Kugla &PostaviX (double x);
    Kugla &PostaviY (double y);
    Kugla &PostaviZ (double z);
    Kugla &PostaviCentar (double x, double y, double z);
    Kugla &PostaviCentar (const std::tuple<double, double, double> &centar);
    Kugla &PostaviPoluprecnik (double r);
    void Ispisi() const;
    void Transliraj (double delta_x, double delta_y, double delta_z);
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

Kugla::Kugla (double r) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::r = r;
}

Kugla::Kugla (double x, double y, double z, double r) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::x = x;
    Kugla::y = y;
    Kugla::z = z;
    Kugla::r = r;
}

Kugla::Kugla (const std::tuple<double, double, double> &centar, double r) {
    Kugla::x = std::get<0>(centar);
    Kugla::y = std::get<1>(centar);
    Kugla::z = std::get<2>(centar);
    Kugla::r = r;
}

std::tuple<double, double, double> Kugla::DajCentar() const {
    auto centar = std::make_tuple(x, y, z);
    return centar;
}

double Kugla::DajPovrsinu() const {
    return 4*PI*r*r;
}

double Kugla::DajZapreminu() const {
    return (4*PI*r*r*r)/3;
}

Kugla &Kugla::PostaviX (double x) {
    Kugla::x = x;
    return *this;
}

Kugla &Kugla::PostaviY (double y) {
    Kugla::y = y;
    return *this;
}

Kugla &Kugla::PostaviZ (double z) {
    Kugla::z = z;
    return *this;
}

Kugla &Kugla::PostaviCentar (double x, double y, double z) {
    Kugla::x = x;
    Kugla::y = y;
    Kugla::z = z;
    return *this;
}

Kugla &Kugla::PostaviCentar (const std::tuple<double, double, double> &centar) {
    Kugla::x = std::get<0>(centar);
    Kugla::y = std::get<1>(centar);
    Kugla::z = std::get<2>(centar);
    return *this;
}

Kugla &Kugla::PostaviPoluprecnik (double r) {
    if (r<0) throw std::domain_error ("Ilegalan poluprecnik");
    Kugla::r = r;
    return *this;
}

void Kugla::Ispisi() const {
    std::cout << "{(" << Kugla::x << "," << Kugla::y << "," << Kugla::z <<")," << Kugla::r << "}";
}

void Kugla::Transliraj (double delta_x, double delta_y, double delta_z) {
    Kugla::x += delta_x;
    Kugla::y += delta_y;
    Kugla::z += delta_z;
}

bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2) {
    if (Kugla::Jednakost(k1.x, k2.x) && Kugla::Jednakost(k1.y, k2.y) && Kugla::Jednakost(k1.z, k2.z) && Kugla::Jednakost(k1.r, k2.r)) return true;
    return false;
}

bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) {
    if (Kugla::Jednakost(k1.r, k2.r)) return true;
    return false;
}

bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2) {
    if (Kugla::Jednakost(k1.x, k2.x) && Kugla::Jednakost(k1.y, k2.y) && Kugla::Jednakost(k1.z, k2.z)) return true;
    return false;
}

bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2) {
    double d = RastojanjeCentara(k1, k2);
    double zbir = k1.r+k2.r;
    if (Kugla::Jednakost(d, zbir)) return true;
    return false;
}

bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2) {
    double d = RastojanjeCentara(k1, k2);
    double razlika = std::fabs(k1.r-k2.r);
    if (Kugla::Jednakost(d, razlika)) return true;
    return false;
}

bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2) {
    if (DaLiSeSijeku(k1, k2)) return true;
    if (DaLiSeDodirujuIznutra(k1, k2)) return true;
    if(DaLiSuIdenticne(k1, k2)) return true;
   
    //if (DaLiSeDodirujuIzvana(k1, k2)) return true;
    if(k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)) return true;
    double d = RastojanjeCentara(k1, k2);
    double zbir = k1.r+k2.r;
    if (!Kugla::Jednakost(d, zbir) && d<zbir) return true;
    return false;
}

bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2) {
    double d = RastojanjeCentara(k1, k2);
    double zbir = k1.r+k2.r;
    double razlika = std::fabs(k1.r-k2.r);
    if ((!Kugla::Jednakost(d, zbir) && d<zbir) && (!Kugla::Jednakost(d, razlika) && d>razlika)) return true;
    return false;
}

bool Kugla::DaLiSadrzi (const Kugla &k) const {
    Kugla ova = *this;
    double d = RastojanjeCentara(ova, k);
    //double razlika = std::fabs(ova.r-k.r);
    //if (!Kugla::Jednakost(d, razlika) && d<razlika) return true;
    if(d+k.r<r || std::fabs(d+k.r-r)<=eps*(std::fabs(d+k.r)+std::fabs(r))) return true;
    return false;
}

double RastojanjeCentara (const Kugla &k1, const Kugla &k2) {
    double a = std::pow(k2.x-k1.x, 2);
    double b = std::pow(k2.y-k1.y, 2);
    double c = std::pow(k2.z-k1.z, 2);
    return std::sqrt(a+b+c);
}

int main ()
{
    try {
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
        std::vector<std::shared_ptr<Kugla>> v(n);
        double x, y, z, r;
        for (int i=0; i<n; i++) {
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
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
            Kugla k (x, y, z, r);
            v.at(i) = std::make_shared<Kugla> (k);
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
        std::transform (v.begin(), v.end(), v.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> p1) {
                                                            p1->Transliraj(delta_x, delta_y, delta_z);
                                                            return p1;
                                                        });
        std::sort (v.begin(), v.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
                                            double v1 = p1->DajZapreminu(), v2 = p2->DajZapreminu();
                                            return (!(fabs(v1-v2) < eps*(fabs(v1)+fabs(v2))) && v1<v2);
                                        });
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
        std::for_each (v.begin(), v.end(), [] (std::shared_ptr<Kugla> p) { p->Ispisi(); std::cout << std::endl; });
        auto Povrsina = *(std::max_element(v.begin(), v.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {
                                                                double povr1=p1->DajPovrsinu(), povr2=p2->DajPovrsinu();
                                                                return (!(fabs(povr1-povr2) < eps*(fabs(povr1)+fabs(povr2))) && povr1<povr2);
                                                            }));
        std::cout << "Kugla sa najvecom povrsinom je: ";
        Povrsina->Ispisi();
        int br(0);
        bool ima(false);
        std::for_each(v.begin(), v.end(), [v, &br, &ima] (std::shared_ptr<Kugla> p1) {
                                                br++;
                                                std::for_each (v.begin()+br, v.end(), [p1, &ima] (std::shared_ptr<Kugla> p2) {
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
        
    }
	return 0;
}
