#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>

class NepreklapajucaKugla
{
    double x, y, z, r;
    NepreklapajucaKugla *p;
    bool DaLiSePreklapaju(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
public:

    //Deklaracija i implementacija konstruktora sa jednim parametrom(koji ima podrazumijevanu vrijednost)
    explicit NepreklapajucaKugla(double r = 0) {
        NepreklapajucaKugla::r = 0;
    }
    //Deklaracija i implementacija konstruktora sa 4 parametra(od kojih jedan ima podrazumijevanu vrijednost)
    NepreklapajucaKugla(double x, double y, double z, double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x = x;
        NepreklapajucaKugla::y = y;
        NepreklapajucaKugla::z = z;
        NepreklapajucaKugla::r = r;
    }

    //Deklaracija i implementacija konstruktora sa dva paramtra od kojih je jedan trojka a drugi podrazumijevana vrijednost
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        x = std::get<0>(centar);
        y = std::get<1>(centar);
        z = std::get<2>(centar);
    }

    //Zabrana kopiranja objekata koji su tipa ove klase
    NepreklapajucaKugla(const NepreklapajucaKugla &k) = delete;

    //zabrana dodjele objekata koji su tipa ove klase
    NepreklapajucaKugla &operator = (const NepreklapajucaKugla &k) = delete;

    //Deklaracija i implementacija metode DajX
    double DajX() const {
        return x;
    }
    //Deklaracija i implementacija metode DajY
    double DajY() const {
        return y;
    }
    //Deklaracija i implementacija metode DajZ
    double DajZ() const {
        return z;
    }
    //Deklaracija i implementacija metode DajCentar
    std::tuple<double, double, double> DajCentar() const {
        std::tuple<double,double,double> t(std::make_tuple(x,y,z));
        return t;
    }
    //Deklaracija i implementacija metode DajPoluprecnik
    double DajPoluprecnik() const {
        return r;
    }
    //Deklaracija i implementacija metode DajPovrsinu
    double DajPovrsinu() const {
        return 4*r*r*(4*atan(1));
    }
    //Deklaracija i implementacija metode DajZapreminu
    double DajZapreminu() const {
        return (4/3)*r*r*r*(4*atan(1));
    }
    //Deklaracija metode PostaviX
    NepreklapajucaKugla &PostaviX(double x);

    //Deklaracija metode PostaviY
    NepreklapajucaKugla &PostaviY(double y);

    //Deklaracija metode PostaviZ
    NepreklapajucaKugla &PostaviZ(double z);

    //Deklaracija metode PostaviCentar
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar);

    //Deklaracija metode PostaviPoluprecnik
    NepreklapajucaKugla &PostaviPoluprecnik(double r);

    //Deklaracija i implementacija metode Ispisi
    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}";
    }

    //Deklaracija metode Transliraj
    void Transliraj(double delta_x, double delta_y, double delta_z);

    //Deklaracija metode DaLiSadrzi
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;

    //Deklaracija prijateljske funkcije RastojanjeCentara
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);

};


int main ()
{
    try {
        std::cout << "Unesite broj nepreklapajucih kugla: ";
        int broj_nepreklapajucih_kugla;
        std::cin >> broj_nepreklapajucih_kugla;
        int brojac(0);
        double x, y, z;
        std::vector<std::shared_ptr<NepreklapajucaKugla>> v;
        do {
            if(broj_nepreklapajucih_kugla == 0) break;
            std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
            std::cin >> x >> y >> z;

            while(!std::cin) {
                std::cout << "Ilegalan centar\n";
                std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cin >> x >> y >> z;
            }
            std::cout << "Unesite poluprecnik " << brojac + 1 << ". kugle: ";
            std::cin >> r;
            while(r < 0) {
                std::cout << "Ilegalan poluprecnik\n";
                std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
                std::cin >> x >> y >> z;
                while(!std::cin) {
                    std::cout << "Ilegalan centar\n";
                    std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    std::cin >> x >> y >> z;
                }
                std::cout << "Unesite poluprecnik " << brojac + 1 << ". kugle: ";
                std::cin >> r;
            }
            std::shared_ptr<NepreklapajucaKugla> p(std::make_shared<NepreklapajucaKugla>(x,y,z,r));
            v.push_back(p);
            brojac++;
        }
    } catch(std::domain_error e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
