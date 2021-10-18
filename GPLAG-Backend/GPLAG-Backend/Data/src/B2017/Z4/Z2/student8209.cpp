/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>



class NepreklapajucaKugla
{
    static constexpr double PI = 4 * std::atan(1);
    static constexpr double e = 10e-010;

    double x, y, z, r;
    NepreklapajucaKugla* prethodni = nullptr;
    static  NepreklapajucaKugla* kraj;

    bool PorediITacke (double prva, double druga) const ;
    bool Degenerisana(const NepreklapajucaKugla &k) const ;

    bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const ;

    bool DaLiSuPodudarne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
        return PorediITacke(k1.r, k2.r);
    }
    bool DaLiSuKoncentricne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)const ;

    bool DaLiSuIdenticne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
        return DaLiSuKoncentricne(k1, k2) && DaLiSuPodudarne(k1, k2);
    }
    bool DaLiSeDodirujuIzvana(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
        return PorediITacke(k1.r + k2.r, RastojanjeCentara(k1,k2));
    }

    bool DaLiSeDodirujuIznutra(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
        return(!DaLiSuIdenticne(k1,k2) && PorediITacke(RastojanjeCentara(k1,k2), std::fabs(k1.r - k2.r)));
    }

    bool DaLiSeSijeku(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const {
        return ((!Degenerisana(k1) && !Degenerisana(k2)) && (DaLiSuIdenticne(k1,k2) ||
                ((RastojanjeCentara(k1,k2) < k1.r + k2.r) &&
                 RastojanjeCentara(k1,k2) > std::fabs(k1.r - k2.r))));
    }

    static void Test (NepreklapajucaKugla* k) {
        for(auto p = kraj; p != nullptr; p = p->prethodni) {
            if (p == k) continue;
            if(k->DaLiSePreklapaju(*p, *k)) throw std::logic_error("Nedozvoljeno preklapanje");
        }
    }
    static void UbaciIProvjeri(NepreklapajucaKugla* k) {
        Test(k);

        if(!(k->prethodni)) {
            kraj = k;
            return;
        }
        k->prethodni = kraj;
        kraj = k;

    }

public:

    explicit NepreklapajucaKugla(double r = 0) {
        PostaviCentar(0,0,0);
        PostaviPoluprecnik(r);
        UbaciIProvjeri(this);
    }
    NepreklapajucaKugla (double x, double y, double z, double r = 0) {
        PostaviCentar(x,y,z);
        PostaviPoluprecnik(r);
        UbaciIProvjeri(this);
    }
    explicit NepreklapajucaKugla (const std::tuple<double, double, double> &centar, double r = 0) {
        PostaviCentar(centar);
        PostaviPoluprecnik(r);
        UbaciIProvjeri(this);
    }
    NepreklapajucaKugla (const NepreklapajucaKugla &k) = delete;
    NepreklapajucaKugla &operator= (const NepreklapajucaKugla &k) = delete;
    ~NepreklapajucaKugla() {

        if(prethodni && this == kraj) kraj = prethodni;

        else
            for(auto p = kraj; p != nullptr; p = p->prethodni) {

                if(p->prethodni == nullptr) {
                    p = nullptr;
                    break;
                }
                if (p == this) p = this->prethodni;

            }

    }


    NepreklapajucaKugla(NepreklapajucaKugla &&k) = default;

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
        return std::make_tuple (x,y,z);
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4 * r * r * PI;
    }
    double DajZapreminu() const {
        return 4./3 * r * r * r * PI;
    }
    NepreklapajucaKugla &PostaviX (double x) {
        NepreklapajucaKugla::x = x;
        Test(this);
        return *this;
    }
    NepreklapajucaKugla &PostaviY (double y) {
        NepreklapajucaKugla::y = y;
        Test(this);
        return *this;
    }
    NepreklapajucaKugla &PostaviZ (double z) {
        NepreklapajucaKugla::z = z;
        Test(this);
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar (double x, double y, double z) {
        NepreklapajucaKugla::x = x;
        NepreklapajucaKugla::y = y;
        NepreklapajucaKugla::z = z;
        Test(this);

        return*this;
    }
    NepreklapajucaKugla &PostaviCentar (const std::tuple<double,double,double> &centar) {
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
        Test(this);

        return *this;
    }

    NepreklapajucaKugla &PostaviPoluprecnik (double r) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::r = r;
        Test(this);
        return *this;
    }

    void Ispisi () const {
        std::cout << "{("<< DajX() <<","<< DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
    }
    void Transliraj (double delta_x, double delta_y, double delta_z) {
        x += delta_x;
        y += delta_y;
        z += delta_z;
    }

    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    bool DaLiSadrzi (const NepreklapajucaKugla &k) const;

};

NepreklapajucaKugla* NepreklapajucaKugla::kraj(nullptr);

bool NepreklapajucaKugla::Degenerisana(const NepreklapajucaKugla &k) const
{
    return PorediITacke(0, k.r);
}

bool NepreklapajucaKugla::PorediITacke(double prva, double druga) const
{
    return std::fabs(prva - druga) <= e* (std::fabs(prva) + std::fabs(druga));
}

bool NepreklapajucaKugla::DaLiSuKoncentricne(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const
{
    return k1.PorediITacke(k1.x, k2.x) && k1.PorediITacke(k1.y, k2.y) && k1.PorediITacke(k1.z, k2.z);
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return (std::sqrt((k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y)*(k1.y - k2.y) + (k1.z - k2.z)*(k1.z -k2.z)));
}

bool NepreklapajucaKugla::DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) const
{

    return PorediITacke(RastojanjeCentara(k1,k2), k1.r + k2.r) && (RastojanjeCentara(k1,k2) <= k1.r + k2.r);
}

bool NepreklapajucaKugla::DaLiSadrzi(const NepreklapajucaKugla &k) const
{
    return DaLiSuIdenticne(*this, k) || RastojanjeCentara(*this,k) < (r - k.r) || (Degenerisana(k)
            && PorediITacke(RastojanjeCentara(*this,k),r));
}

int main ()
{
    std::cout << "Unesite broj kugli: ";
    int broj_NepreklapajucaKugla;

    for(;;) {
        std::cin >> broj_NepreklapajucaKugla;
        if(!std::cin) {
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        if(broj_NepreklapajucaKugla < 1) {
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            continue;
        }
        break;
    }

    std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor_pokazivaca(broj_NepreklapajucaKugla);

    for(int i = 0; i < broj_NepreklapajucaKugla; i++) {
        std::cout << "Unesite centar za " << i + 1 << ". kuglu: ";

        double x, y, z;
        for(;;) {

            std::cin >> x >> y >> z;
            if(!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Neispravan centar, unesite ponovo:" << std::endl;
                continue;
            }

            break;
        }

        try {
            std::cout << "Unesite poluprecnik: ";
            double r;

            for(;;) {
                std::cin >> r;
                if(!std::cin) {
                    std::cout << "Neispravan poluprecnik, unesite ponovo: " << std::endl;
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    continue;
                }

                if(r < 0) {
                    std::cout << "Neispravan poluprecnik, unesite ponovo: " << std::endl;
                    continue;
                }

                break;

            }


            vektor_pokazivaca.at(i) = (std::make_shared <NepreklapajucaKugla>( NepreklapajucaKugla(x,y,z,r)));
        } catch(const std::exception &e) {
            std::cout << e.what() << std::endl;
            i--;
        }

    }


    std::sort(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [](std::shared_ptr<NepreklapajucaKugla> pok1, std::shared_ptr<NepreklapajucaKugla> pok2) {
        return pok1->DajPovrsinu() < pok2-> DajPovrsinu();
    });

    std::cout << std::endl <<  "Kugle nakon obavljenog sortiranja: " << std::endl;

    std::for_each(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [](std::shared_ptr<NepreklapajucaKugla> pok) {
        pok->Ispisi();
    });


    return 0;

}
