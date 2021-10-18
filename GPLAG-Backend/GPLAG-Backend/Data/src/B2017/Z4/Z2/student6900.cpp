/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

const double pi = 4*std::atan(1);
const double eps = std::pow(10, -10);

bool Isti(double x, double y)
{
    return (std::fabs(x - y) <= eps * (std::fabs(x) + std::fabs(y)));
}

double Rastojanje(double x1, double y1, double z1, double x2, double y2, double z2)
{
    return std::sqrt(std::pow(x1-x2, 2) + std::pow(y1-y2, 2) + std::pow(z1-z2, 2));
}

class NepreklapajucaKugla
{
    double x, y, z, r;
    NepreklapajucaKugla* prosla_kugla;
    static NepreklapajucaKugla* pocetak;
    static bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, double x, double y, double z, double r) {
        return (Rastojanje(k1.DajX(), k1.DajY(), k1.DajZ(), x, y, z) <= (k1.DajPoluprecnik() + r));
    }
public:
    explicit NepreklapajucaKugla(double r = 0) {
        if (!pocetak) {
            pocetak=this;
            prosla_kugla=nullptr;
        } else {
            NepreklapajucaKugla* p(pocetak);
            do {
                if (DaLiSePreklapaju(*p, 0, 0, 0, r))
                    throw std::logic_error("Nedozvoljeno preklapanje");
                p = p->prosla_kugla;
            } while (p!=nullptr);
            prosla_kugla=pocetak;
            pocetak=this;
        }
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        x=0;
        y=0;
        z=0;
        NepreklapajucaKugla::r=r;
    }

    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if (!pocetak) {
            pocetak=this;
            prosla_kugla=nullptr;
        } else {
            NepreklapajucaKugla* p(pocetak);
            do {
                if (DaLiSePreklapaju(*p, x, y, z, r))
                    throw std::logic_error("Nedozvoljeno preklapanje");
                p = p->prosla_kugla;
            } while (p!=nullptr);
            prosla_kugla=pocetak;
            pocetak=this;
        }
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
    }

    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if (!pocetak) {
            pocetak=this;
            prosla_kugla=nullptr;
        } else {
            NepreklapajucaKugla* p(pocetak);
            do {
                if (DaLiSePreklapaju(*p, std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r))
                    throw std::logic_error("Nedozvoljeno preklapanje");
                p = p->prosla_kugla;
            } while (p!=nullptr);
            prosla_kugla=pocetak;
            pocetak=this;
        }
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        NepreklapajucaKugla::r=r;
    }

    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla(NepreklapajucaKugla &&k) = delete;
    NepreklapajucaKugla& operator =(const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla& operator =(NepreklapajucaKugla &&k) = delete;

    ~NepreklapajucaKugla() {
        if (this==pocetak) {
            pocetak=this->prosla_kugla;
        } else {
            NepreklapajucaKugla* p(pocetak);
            do {
                if (this==p->prosla_kugla) {
                    p->prosla_kugla=this->prosla_kugla;
                    break;
                }
                p = p->prosla_kugla;
            } while (p!=nullptr);
        }
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
    std::tuple<double, double, double> DajCentar() const {
        return std::make_tuple(x, y, z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*pi;
    }
    double DajZapreminu() const {
        return 4*r*r*r*pi/3;
    }
    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla* p(pocetak);
        do {
            if (DaLiSePreklapaju(*p, x, y, z, r))
                throw std::logic_error("Nedozvoljeno preklapanje");
            p = p->prosla_kugla;
        } while (p!=nullptr);
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla* p(pocetak);
        do {
            if (DaLiSePreklapaju(*p, x, y, z, r))
                throw std::logic_error("Nedozvoljeno preklapanje");
            p = p->prosla_kugla;
        } while (p!=nullptr);
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla* p(pocetak);
        do {
            if (DaLiSePreklapaju(*p, x, y, z, r))
                throw std::logic_error("Nedozvoljeno preklapanje");
            p = p->prosla_kugla;
        } while (p!=nullptr);
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla* p(pocetak);
        do {
            if (DaLiSePreklapaju(*p, x, y, z, r))
                throw std::logic_error("Nedozvoljeno preklapanje");
            p = p->prosla_kugla;
        } while (p!=nullptr);
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        NepreklapajucaKugla* p(pocetak);
        do {
            if (DaLiSePreklapaju(*p, std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r))
                throw std::logic_error("Nedozvoljeno preklapanje");
            p = p->prosla_kugla;
        } while (p!=nullptr);
        NepreklapajucaKugla::x=std::get<0>(centar);
        NepreklapajucaKugla::y=std::get<1>(centar);
        NepreklapajucaKugla::z=std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        NepreklapajucaKugla* p(pocetak);
        do {
            if (DaLiSePreklapaju(*p, x, y, z, r))
                throw std::logic_error("Nedozvoljeno preklapanje");
            p = p->prosla_kugla;
        } while (p!=nullptr);
        if (r<0)
            throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        NepreklapajucaKugla* p(pocetak);
        do {
            if (DaLiSePreklapaju(*p, x+delta_x, y+delta_y, z+delta_z, r))
                throw std::logic_error("Nedozvoljeno preklapanje");
            p = p->prosla_kugla;
        } while (p!=nullptr);
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }

    bool DaLiSadrzi(const NepreklapajucaKugla &k) const {
        return (k.r<this->r && RastojanjeCentara(*this, k) <= std::fabs(r - k.r));
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);

};

NepreklapajucaKugla* NepreklapajucaKugla::pocetak = nullptr;

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return Rastojanje(k1.x, k1.y, k1.z, k2.x, k2.y, k2.z);
}


int main ()
{
    int n;
    std::cout << "Unesite broj kugli: ";
    do {
        std::cin >> n;
        if (!std::cin || n<=0) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        } else
            break;
    } while (true);
    std::vector<std::shared_ptr<NepreklapajucaKugla>> niz(n, nullptr);
    for (int i = 0; i < n; i++) {
        double x, y, z, r;
        bool valja1(false), valja2(false);
        
        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        do {
            std::cin >> x >> y >> z;
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
                continue;
            } else
                valja1=true;
        } while(!valja1);
        
        std::cout << "Unesite poluprecnik: ";
        do {
            std::cin >> r;
            if (!std::cin || r<0) {
                std::cin.clear();
                std::cin.ignore(10000,'\n');
                std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
            } else
                valja2=true;
        } while (!valja2);
        
        std::shared_ptr<NepreklapajucaKugla> pomoc(nullptr);
        try {
            pomoc = std::make_shared<NepreklapajucaKugla>(x, y, z, r);
        } catch (const std::exception &greska) {
            std::cout << greska.what() << std::endl;
            i--;
            continue;
        }
        niz.at(i)=pomoc;
    }
    std::sort(niz.begin(), niz.end(), [] (const std::shared_ptr<NepreklapajucaKugla> &k1, const std::shared_ptr<NepreklapajucaKugla> &k2) {
        return k1->DajPoluprecnik() < k2->DajPoluprecnik();
    });
    std::cout << "\nKugle nakon obavljenog sortiranja: " << std::endl;
    for (auto i : niz)
        i->Ispisi();
    return 0;
}
