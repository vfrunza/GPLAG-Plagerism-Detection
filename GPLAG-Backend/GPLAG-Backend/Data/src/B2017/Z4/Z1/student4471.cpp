#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

bool Jednaki(double x, double y, double Eps = 1e-10) {
    return fabs(x - y) <= Eps * (fabs(x) + fabs(y));
} 

class Kugla {
    double x, y, z, r;
public:
    explicit Kugla(double r = 0) { PostaviPoluprecnik(r); PostaviCentar(0,0,0); }   
    Kugla(double x, double y, double z, double r = 0) {
        PostaviPoluprecnik(r); PostaviCentar(x,y,z); 
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
       PostaviPoluprecnik(r); PostaviCentar(centar);
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(x, y, z);
    }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*r*r*4*atan(1); }
    double DajZapreminu() const { return 4./3*r*r*r*4*atan(1); }
    Kugla &PostaviX(double x) { Kugla::x = x; return *this; }
    Kugla &PostaviY(double y) { Kugla::y = y; return *this; }
    Kugla &PostaviZ(double z) { Kugla::z = z; return *this; }
    Kugla &PostaviCentar(double x, double y, double z) {
        PostaviX(x); PostaviY(y); PostaviZ(z);
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        PostaviX(std::get<0>(centar)); 
        PostaviY(std::get<1>(centar)); 
        PostaviZ(std::get<2>(centar));
        return *this;
    }
    Kugla &PostaviPoluprecnik(double &r) {
        if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r; return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ()
                  << ")," << DajPoluprecnik() << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x += delta_x; y += delta_y; z += delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const {
        return RastojanjeCentara(*this,k)+k.DajPoluprecnik() < DajPoluprecnik()
            || Jednaki(RastojanjeCentara(*this,k)+k.DajPoluprecnik(), DajPoluprecnik());
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);  //
    friend bool Jednaki(double x, double y, double Eps);
};

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return DaLiSuKoncentricne(k1,k2) && DaLiSuPodudarne(k1,k2);
}
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return Jednaki(k1.DajPoluprecnik(), k2.DajPoluprecnik());
}
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return Jednaki(k1.DajX(), k2.DajX()) && Jednaki(k1.DajY(), k2.DajY()) && Jednaki(k1.DajZ(), k2.DajZ());
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    return Jednaki(RastojanjeCentara(k1,k2), k1.DajPoluprecnik() + k2.DajPoluprecnik());
}
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    return (DaLiSuIdenticne(k1,k2) && k1.r == 0 && k2.r == 0) || (!DaLiSuIdenticne(k1,k2) && 
        (Jednaki(k1.DajPoluprecnik(),RastojanjeCentara(k1,k2)+k2.DajPoluprecnik()) ||
        Jednaki(k2.DajPoluprecnik(),RastojanjeCentara(k1,k2)+k1.DajPoluprecnik())));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    return DaLiSeSijeku(k1,k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1);
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    return !k1.DaLiSadrzi(k2) && !k2.DaLiSadrzi(k1) 
    && (RastojanjeCentara(k1,k2) < k1.DajPoluprecnik() + k2.DajPoluprecnik());
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt(pow(k2.x-k1.x,2) + pow(k2.y-k1.y,2) + pow(k2.z-k1.z,2));
}

typedef std::shared_ptr<Kugla> PK;

int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    for (;;) {
        std::cin >> n;
        if (!std::cin || n <= 0) {
            std::cin.clear(); std::cin.ignore(1000, '\n');
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        }
        else break;
    }
    try {
        std::vector<PK> kugle(n);
        for (int i = 0; i < n; i++) {
            double x, y, z, r;
            for (;;) {
                std::cout << "Unesite centar " << i+1 << ". kugle: ";
                std::cin >> x >> y >> z;
                if (!std::cin) {
                    std::cin.clear(); std::cin.ignore(1000, '\n');
                    std::cout << "Neispravan centar" << std::endl; continue;
                }
                std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
                std::cin >> r;
                if (!std::cin || r < 0) {
                    std::cin.clear(); std::cin.ignore(1000, '\n');
                    std::cout << "Ilegalan poluprecnik" << std::endl;
                }
                else break;
            }
            kugle[i] = std::make_shared<Kugla>(x,y,z,r);
        }
        double dx, dy, dz;
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        for (;;) {
            if (!(std::cin >> dx >> dy >> dz)) {
                std::cin.clear(); std::cin.ignore(1000, '\n');
                std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
            }
            else break;
           
        }
        std::transform(kugle.begin(), kugle.end(), kugle.begin(), [dx,dy,dz](PK k1) {
            k1->Transliraj(dx,dy,dz); return k1;
        });
        std::sort(kugle.begin(), kugle.end(), [](PK k1, PK k2) {
            return k1->DajZapreminu() < k2->DajZapreminu();
        });
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
        std::for_each(kugle.begin(), kugle.end(), [](PK k1) { k1->Ispisi(); });
        std::cout << "Kugla sa najvecom povrsinom je: ";
        (*(std::max_element(kugle.begin(), kugle.end(), [](PK k1, PK k2) { 
            return k1->DajPovrsinu() < k2->DajPovrsinu();
        })))->Ispisi();
        int index(1);
        bool presjecajuce(false);
        std::for_each(kugle.begin(), kugle.end(), [kugle, &presjecajuce, &index](PK k1) {
            std::for_each(kugle.begin() + index, kugle.end(), [k1, &presjecajuce](PK k2) {
                if (DaLiSeSijeku(*k1, *k2)) {
                    std::cout << "Presjecaju se kugle: ";
                    k1->Ispisi(); k2->Ispisi(); presjecajuce = true;
                }
            });
            index++;
        });
        if (!presjecajuce) std::cout << "Ne postoje kugle koje se presjecaju!";


    }
    catch (...) {
        std::cout << "Problemi sa memorijom";
    }
	return 0;
}
