/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>

const long double PI(4*atan(1));
const double eps(1e-10);
class NepreklapajucaKugla
{
    double x,y,z,r;
    NepreklapajucaKugla* prethodna_kugla = nullptr;
    static NepreklapajucaKugla* posljednja_kreirana_kugla;
    bool DaLiSePreklapaju(double x, double y, double z , double r, const NepreklapajucaKugla &k);
public:
    explicit NepreklapajucaKugla(double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        else if(posljednja_kreirana_kugla) {
            for(NepreklapajucaKugla *p(posljednja_kreirana_kugla); p!=nullptr; p=p->prethodna_kugla) {
                if(DaLiSePreklapaju(0,0,0,r, *p)) throw std::logic_error("Nedozvoljeno preklapanje");
            }

        }
        x=0;
        y=0;
        z=0;
        NepreklapajucaKugla::r=r;
        this->prethodna_kugla=posljednja_kreirana_kugla;
        posljednja_kreirana_kugla=this;
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        else if(posljednja_kreirana_kugla) {
            for(NepreklapajucaKugla *p(posljednja_kreirana_kugla); p!=nullptr; p=p->prethodna_kugla) {
                if(DaLiSePreklapaju(x,y,z,r, *p)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        NepreklapajucaKugla::r=r;
        this->prethodna_kugla=posljednja_kreirana_kugla;
        posljednja_kreirana_kugla=this;
    }
    explicit NepreklapajucaKugla(const std::tuple <double, double, double> &centar, double r = 0) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        else if(posljednja_kreirana_kugla) {
            for(NepreklapajucaKugla *p(posljednja_kreirana_kugla); p!=nullptr; p=p->prethodna_kugla) {
                if(DaLiSePreklapaju(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), r, *p)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
        }
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        NepreklapajucaKugla::r=r;
        this->prethodna_kugla=posljednja_kreirana_kugla;
        posljednja_kreirana_kugla=this;
    }
    ~NepreklapajucaKugla() {
        if(posljednja_kreirana_kugla==this) posljednja_kreirana_kugla=this->prethodna_kugla;
        else {
            NepreklapajucaKugla* p;
            if(posljednja_kreirana_kugla) {
                for(p=posljednja_kreirana_kugla; p->prethodna_kugla!=this; p=p->prethodna_kugla);
                p->prethodna_kugla=this->prethodna_kugla;
            }
        }
    }
    NepreklapajucaKugla (const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k) = delete;

    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }
    std::tuple <double, double, double> DajCentar() const {
        return std::make_tuple(x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*PI;
    }
    double DajZapreminu() const {
        return 4./3*PI*r*r*r;
    }
    NepreklapajucaKugla &PostaviX(double x) {
        if(posljednja_kreirana_kugla) {
            for(NepreklapajucaKugla *p(posljednja_kreirana_kugla); p!=nullptr; p=p->prethodna_kugla) {
                if(p!=this && DaLiSePreklapaju(x, this->y, this->z, this->r, *p)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::x=x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y) {
        if(posljednja_kreirana_kugla) {
            for(NepreklapajucaKugla *p(posljednja_kreirana_kugla); p!=nullptr; p=p->prethodna_kugla) {
                if(p!=this && DaLiSePreklapaju(this->x, y, this->z, this->r, *p)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::y=y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z) {
        if(posljednja_kreirana_kugla) {
            for(NepreklapajucaKugla *p(posljednja_kreirana_kugla); p!=nullptr; p=p->prethodna_kugla) {
                if(p!=this && DaLiSePreklapaju(this->x, this->y, z, this->r, *p)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        if(posljednja_kreirana_kugla) {
            for(NepreklapajucaKugla *p(posljednja_kreirana_kugla); p!=nullptr; p=p->prethodna_kugla) {
                if(p!=this && DaLiSePreklapaju(x, y, z, this->r, *p)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::x=x;
        NepreklapajucaKugla::y=y;
        NepreklapajucaKugla::z=z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple <double, double, double> &centar) {
        if(posljednja_kreirana_kugla) {
            for(NepreklapajucaKugla *p(posljednja_kreirana_kugla); p!=nullptr; p=p->prethodna_kugla) {
                if(p!=this && DaLiSePreklapaju(std::get<0>(centar), std::get<1>(centar), std::get<2>(centar), this->r, *p)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
        }
        x=std::get<0>(centar);
        y=std::get<1>(centar);
        z=std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if(r<0) throw std::domain_error("Ilegalan poluprecnik");
        else if(posljednja_kreirana_kugla) {
            for(NepreklapajucaKugla *p(posljednja_kreirana_kugla); p!=nullptr; p=p->prethodna_kugla) {
                if(p!=this && DaLiSePreklapaju(this->x, this->y, this->z, r, *p)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
        }
        NepreklapajucaKugla::r=r;
        return *this;
    }
    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}\n";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        if(posljednja_kreirana_kugla) {
            for(NepreklapajucaKugla *p(posljednja_kreirana_kugla); p!=nullptr; p=p->prethodna_kugla) {
                if(p!=this && DaLiSePreklapaju(x+delta_x, y+delta_y, z+delta_z, r, *p)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
        }
        x+=delta_x;
        y+=delta_y;
        z+=delta_z;
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

bool NepreklapajucaKugla::DaLiSePreklapaju(double x, double y, double z, double r, const NepreklapajucaKugla &k)
{
    double rastojanje_centara(std::sqrt(std::pow(k.x-x,2)+std::pow(k.y-y,2)+std::pow(k.z-z,2)));
    if(rastojanje_centara<=k.r+r) return true;
    return false;
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return std::sqrt(std::pow(k1.x-k2.x,2)+std::pow(k1.y-k2.y,2)+std::pow(k1.z-k2.z,2));
}

NepreklapajucaKugla* NepreklapajucaKugla::posljednja_kreirana_kugla(nullptr);

int main ()
{
    std::vector<std::shared_ptr<NepreklapajucaKugla>> kugle;
    int n;
    std::cout << "Unesite broj kugli: ";
    for(;;) {
        std::cin >> n;
        if(n>0 && std::cin && std::cin.peek()=='\n') break;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
    }
    for(int i(0); i<n; i++) {
        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        double x,y,z,r;
        try {
            for(;;) {
                std::cin >> x >> y >> z;
                if(std::cin) break;
                std::cout << "Neispravan centar, unesite ponovo:\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            std::cout << "Unesite poluprecnik: ";
            for(;;) {
                std::cin >> r;
                if(std::cin && r>-eps) break;
                std::cout << "Neispravan poluprecnik, unesite ponovo:\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            kugle.push_back(std::make_shared<NepreklapajucaKugla>(x,y,z,r));
        } catch(std::logic_error e) {
            i--;
            std::cout << e.what() << std::endl;
        }
    }
    std::sort(kugle.begin(), kugle.end(), [](std::shared_ptr<NepreklapajucaKugla> kugla1, std::shared_ptr<NepreklapajucaKugla> kugla2) {
        return kugla1->DajPovrsinu()<kugla2->DajPovrsinu();
    });
    std::cout << "\nKugle nakon obavljenog sortiranja:\n";
    std::for_each(kugle.begin(), kugle.end(), [](std::shared_ptr<NepreklapajucaKugla> kugla) {
        kugla->Ispisi();
    });
    return 0;
}
