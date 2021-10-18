/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>



class Kugla
{
    static constexpr double PI = 4 * std::atan(1);
    static constexpr double e = 10e-010;

    double x, y, z, r;

    static bool PorediITacke (double prva, double druga);
    static bool Degenerisana(const Kugla &k);

public:

    explicit Kugla(double r = 0) {
        PostaviCentar(0,0,0);
        PostaviPoluprecnik(r);
    }
    Kugla (double x, double y, double z, double r = 0) {
        PostaviCentar(x,y,z);
        PostaviPoluprecnik(r);
    }
    explicit Kugla (const std::tuple<double, double, double> &centar, double r = 0) {
        PostaviCentar(centar);
        PostaviPoluprecnik(r);
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
    Kugla &PostaviCentar (double x, double y, double z) {
        Kugla::x = x;
        Kugla::y = y;
        Kugla::z = z;

        return*this;
    }
    Kugla &PostaviCentar (const std::tuple<double,double,double> &centar) {
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);

        return *this;
    }

    Kugla &PostaviPoluprecnik (double r) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        Kugla::r = r;

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

    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        return PorediITacke(k1.r, k2.r);
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);

    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        return DaLiSuKoncentricne(k1, k2) && DaLiSuPodudarne(k1, k2);
    }

    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);

    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
        return PorediITacke(k1.r + k2.r, RastojanjeCentara(k1,k2));
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
        return(!DaLiSuIdenticne(k1,k2) && PorediITacke(RastojanjeCentara(k1,k2), std::fabs(k1.r - k2.r)));
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);

    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
        return ((!Degenerisana(k1) && !Degenerisana(k2)) && (DaLiSuIdenticne(k1,k2) || ((RastojanjeCentara(k1,k2) < k1.r + k2.r) &&
                RastojanjeCentara(k1,k2) > std::fabs(k1.r - k2.r))));
    }

    bool DaLiSadrzi (const Kugla &k) const;

};

bool Kugla::Degenerisana(const Kugla &k)
{
    return PorediITacke(0, k.r);
}

bool Kugla::PorediITacke(double prva, double druga)
{
    return std::fabs(prva - druga) <= e* (std::fabs(prva) + std::fabs(druga));
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return k1.PorediITacke(k1.x, k2.x) && k1.PorediITacke(k1.y, k2.y) && k1.PorediITacke(k1.z, k2.z);
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return (std::sqrt((k1.x - k2.x) * (k1.x - k2.x) + (k1.y - k2.y)*(k1.y - k2.y) + (k1.z - k2.z)*(k1.z -k2.z)));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{

    double veci(k1.r);
    if (veci < k2.r) veci = k2.r;

    return (!k1.Degenerisana(k1) && !k1.Degenerisana(k2)) && (DaLiSuIdenticne(k1,k2) || DaLiSeSijeku(k1,k2) || DaLiSeDodirujuIznutra(k1,k2)
            || ((RastojanjeCentara(k1,k2) + k1.r + k2.r) < 2*veci));
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    return DaLiSuIdenticne(*this, k) || RastojanjeCentara(*this,k) < (r - k.r) || (Degenerisana(k)
            && PorediITacke(RastojanjeCentara(*this,k),r)) || (DaLiSeDodirujuIznutra(*this,k) && this->DajZapreminu() >k.DajZapreminu())
            || (DaLiSuKoncentricne(*this, k) && this->DajZapreminu() > k.DajZapreminu()) || (Degenerisana(k) && RastojanjeCentara(*this, k) <= r);
}

int main ()
{

    std::cout << "Unesite broj kugla: ";
    double broj_kugla;
    std::cin >> broj_kugla;
    if(!std::cin || broj_kugla < 1) for(;;) {
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            std::cin >> broj_kugla;
            if(std::cin && broj_kugla > 0) break;
        }

    std::vector<std::shared_ptr<Kugla>> vektor_pokazivaca (broj_kugla);

    for(int i = 0; i < broj_kugla; i++) {
        std::cout << "Unesite centar " << i + 1 << ". kugle: ";

        bool ponovi(false);

        double x, y, z;
        if(!(std::cin >> x >> y >> z)) {
            std::cout << "Neispravan centar" << std::endl;
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            ponovi = true;
            i--;
        }
        if(ponovi) continue;

        try {
            std::cout << "Unesite poluprecnik " << i + 1 << ". kugle: ";
            double r;
            std::cin >> r;

            if(!std::cin || r < 0) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw std::domain_error("Ilegalan poluprecnik");
            }


            vektor_pokazivaca.at(i) = std::make_shared <Kugla>( Kugla(x,y,z,r));
        } catch(const std::exception &e) {
            std::cout << e.what() << std::endl;
            i--;
        }

    }

    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double delta_x, delta_y, delta_z;
    while(!(std::cin >> delta_x >> delta_y >>  delta_z)) {
        std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }



    std::transform (vektor_pokazivaca.begin(), vektor_pokazivaca.end(), vektor_pokazivaca.begin(),
    [delta_x,delta_y,delta_z] (std::shared_ptr<Kugla> pametni) {
        pametni->Transliraj(delta_x ,delta_y, delta_z);
        return pametni;
    });

    std::sort(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [](std::shared_ptr<Kugla> pok1, std::shared_ptr<Kugla> pok2) {
        return pok1->DajZapreminu() < pok2-> DajZapreminu();
    });

    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;

    std::for_each(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [](std::shared_ptr<Kugla> pok) {
        pok->Ispisi();
    });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*std::max_element(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [] (std::shared_ptr<Kugla> pok1, std::shared_ptr<Kugla> pok2) {
        return pok1->DajPovrsinu() < pok2 -> DajPovrsinu();
    }))-> Ispisi();

    int brojac(0), brojac_ispisa(0);
    std::for_each(vektor_pokazivaca.begin(), vektor_pokazivaca.end(), [vektor_pokazivaca, &brojac, &brojac_ispisa](std::shared_ptr<Kugla> pok1) {
        std::for_each(vektor_pokazivaca.begin() + brojac, vektor_pokazivaca.end(), [vektor_pokazivaca, pok1, &brojac, &brojac_ispisa] (std::shared_ptr<Kugla> pok2) {
            if(!(pok1 == pok2) && DaLiSeSijeku(*pok1, *pok2)) {
                std::cout << "Presjecaju se kugle: ";
                pok1->Ispisi();
                pok2->Ispisi();
                brojac_ispisa++;
            }
            if(brojac_ispisa == 0 && brojac == vektor_pokazivaca.size() - 1)
                std::cout << "Ne postoje kugle koje se presjecaju!";
        });
        brojac++;
    }
                 );
    return 0;
}
