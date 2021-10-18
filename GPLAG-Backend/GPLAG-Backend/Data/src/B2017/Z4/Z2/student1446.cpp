/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <algorithm>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <iterator>

const double PI(4*std::atan(1));
const double EPSILON(1e-10);

class NepreklapajucaKugla {
    double x, y, z;
    double r;
    static NepreklapajucaKugla* pok_na_prethodnu;
    NepreklapajucaKugla* veza_s_prethodnom;
    static bool JednakiRealni(double prvi, double drugi) {
        return std::fabs(prvi-drugi)<EPSILON*(std::fabs(prvi)+std::fabs(drugi));
    }
    static bool VeciRealni(double prvi, double drugi) {
        return std::fabs(prvi-drugi)>=EPSILON*(std::fabs(prvi)+std::fabs(drugi)) && prvi>drugi;
    }
    static bool ManjiRealni(double prvi, double drugi) {
        return std::fabs(prvi-drugi)>=EPSILON*(std::fabs(prvi)+std::fabs(drugi)) && prvi<drugi;
    }
    static bool DaLiSePreklapaju(double x1, double y1, double z1, double r1, const NepreklapajucaKugla &k2) {
        double rastojanje_centara;
        rastojanje_centara=std::sqrt((x1-k2.x)*(x1-k2.x)+(y1-k2.y)*(y1-k2.y)+(z1-k2.z)*(z1-k2.z));
        return NepreklapajucaKugla::JednakiRealni(rastojanje_centara, r1+k2.DajPoluprecnik()) 
        || NepreklapajucaKugla::ManjiRealni(rastojanje_centara, r1+k2.DajPoluprecnik());
    }
public:
    explicit NepreklapajucaKugla(double r=0) {
        if (NepreklapajucaKugla::ManjiRealni(r, 0)) throw std::domain_error("Ilegalan poluprecnik");
        for (NepreklapajucaKugla* tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (DaLiSePreklapaju(0, 0, 0, r, *tekuci)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::r=r;
        x=0; y=0; z=0;
        veza_s_prethodnom=pok_na_prethodnu;
        pok_na_prethodnu=this;
    }
    NepreklapajucaKugla(const NepreklapajucaKugla &kugla)=delete;
    NepreklapajucaKugla &operator =(const NepreklapajucaKugla &kugla)=delete;
    NepreklapajucaKugla(double x, double y, double z, double r=0) {
        if (NepreklapajucaKugla::ManjiRealni(r, 0)) throw std::domain_error("Ilegalan poluprecnik");
        for (NepreklapajucaKugla* tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (DaLiSePreklapaju(x, y, z, r, *tekuci)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::r=r;
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z;
        veza_s_prethodnom=pok_na_prethodnu;
        pok_na_prethodnu=this;
    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0) {
        if (NepreklapajucaKugla::ManjiRealni(r, 0)) throw std::domain_error("Ilegalan poluprecnik");
        for (NepreklapajucaKugla* tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (DaLiSePreklapaju(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r, *tekuci)) 
                throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::r=r;
        std::tie(x, y, z)=centar;
        veza_s_prethodnom=pok_na_prethodnu;
        pok_na_prethodnu=this;
    }
    ~NepreklapajucaKugla();
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
        return 4*DajPoluprecnik()*DajPoluprecnik()*PI;
    }
    double DajZapreminu() const {
        return (4./3)*DajPoluprecnik()*DajPoluprecnik()*DajPoluprecnik()*PI;
    }
    NepreklapajucaKugla &PostaviX(double x) {
        for (NepreklapajucaKugla* tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (DaLiSePreklapaju(x, y, z, r, *tekuci)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        for (NepreklapajucaKugla* tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (DaLiSePreklapaju(x, y, z, r, *tekuci)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        for (NepreklapajucaKugla* tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (DaLiSePreklapaju(x, y, z, r, *tekuci)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        for (NepreklapajucaKugla* tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (DaLiSePreklapaju(x, y, z, r, *tekuci)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::x=x; NepreklapajucaKugla::y=y; NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        for (NepreklapajucaKugla* tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (DaLiSePreklapaju(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r, *tekuci)) 
                throw std::logic_error("Nedozvoljeno preklapanje");
        }
        std::tie(x, y, z)=centar;
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if (NepreklapajucaKugla::ManjiRealni(r, 0)) throw std::domain_error("Ilegalan poluprecnik");
        for (NepreklapajucaKugla* tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (DaLiSePreklapaju(x, y, z, r, *tekuci)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        for (NepreklapajucaKugla* tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (DaLiSePreklapaju(x+delta_x, y+delta_y, z+delta_z, r, *tekuci)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla* NepreklapajucaKugla::pok_na_prethodnu(nullptr);

NepreklapajucaKugla::~NepreklapajucaKugla() {
    if (veza_s_prethodnom==nullptr && pok_na_prethodnu==this) {
        pok_na_prethodnu=nullptr;
    }
    else if (pok_na_prethodnu==this) {
        pok_na_prethodnu=veza_s_prethodnom;
        veza_s_prethodnom=nullptr;
    }
    else {
        NepreklapajucaKugla* tekuci;
        for (tekuci=pok_na_prethodnu; tekuci!=nullptr; tekuci=tekuci->veza_s_prethodnom) {
            if (tekuci->veza_s_prethodnom==this) break;
        }
        tekuci->veza_s_prethodnom=(this->veza_s_prethodnom);
        (this->veza_s_prethodnom)=nullptr;
    }
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return std::sqrt((k1.x-k2.x)*(k1.x-k2.x)+(k1.y-k2.y)*(k1.y-k2.y)+(k1.z-k2.z)*(k1.z-k2.z));
}

bool NepreklapajucaKugla::DaLiSadrzi(const NepreklapajucaKugla &k) const {
    return (NepreklapajucaKugla::ManjiRealni(k.r, r) || NepreklapajucaKugla::JednakiRealni(k.r, r)) && 
    (NepreklapajucaKugla::JednakiRealni(RastojanjeCentara(*this, k), std::fabs(r-k.r)) 
    || NepreklapajucaKugla::ManjiRealni(RastojanjeCentara(*this, k), std::fabs(r-k.r)));
}

int main ()
{
    std::cout << "Unesite broj kugli: ";
    int n(0);
    while (1) {
        std::cin >> n;
        if (std::cin && n>0) break;
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor_pokazivaca;
    for (int i=1; i<=n; i++) {
        std::cout << "Unesite centar za " << i << ". kuglu: ";
        double x(0.), y(0.), z(0.);
        std::cin >> x;
        std::cin >> y;
        std::cin >> z;
        while (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
            std::cin >> x;
            std::cin >> y;
            std::cin >> z;
        }
        std::cout << "Unesite poluprecnik: ";
        double r(0.);
        std::cin >> r;
        while (!std::cin || (r<0 && !(std::fabs(r)<EPSILON*(std::fabs(r))))) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
            std::cin >> r;
        }
        try {
            vektor_pokazivaca.push_back(std::make_shared<NepreklapajucaKugla>(x, y, z, r));
        }
        catch(std::logic_error greska) {
            std::cout << greska.what() << std::endl;
            i--;
            continue;
        }
        catch(std::domain_error greska) {
            std::cout << greska.what() << std::endl;
            i--;
            continue;
        }
    }
    std::cout << std::endl;
    std::cout << "Kugle nakon obavljenog sortiranja: ";
    std::cout << std::endl;
    std::sort(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [](std::shared_ptr<NepreklapajucaKugla> prvi, std::shared_ptr<NepreklapajucaKugla> drugi) {
        return (prvi->DajPovrsinu())<(drugi->DajPovrsinu());
    });
    std::for_each(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), 
    [](std::shared_ptr<NepreklapajucaKugla> pokazivac) {
        pokazivac->Ispisi();
    });
	return 0;
}
