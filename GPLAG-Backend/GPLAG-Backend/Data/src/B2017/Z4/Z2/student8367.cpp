/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <memory>
#include <algorithm>
#include <string>
#include <tuple>
const double PI = 4 * atan(1);
const double Eps(1e-10);

class NepreklapajucaKugla
{
    double x, y, z, r;
    NepreklapajucaKugla *veza;
public:
    static NepreklapajucaKugla *posljednja;
    explicit NepreklapajucaKugla (double r = 0):veza(nullptr) {
        if (r < 0) throw std::domain_error("Ilegalan poluprecnik");
        if (posljednja == nullptr)
            posljednja = this;
        else {
            veza = posljednja;
            posljednja = this;
        }
        NepreklapajucaKugla::r = r;
        NepreklapajucaKugla::x = 0;
        NepreklapajucaKugla::y = 0;
        NepreklapajucaKugla::z = 0;
        for (auto it = posljednja->veza; it != nullptr; it = it->veza) {
            if (TestirajPreklapanje(*posljednja, *it)) {
                auto pomocna = posljednja->veza;
                posljednja->veza = nullptr;
                posljednja = pomocna;
                pomocna=nullptr;
                throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
    }

    NepreklapajucaKugla(double x, double y, double z, double r = 0):veza(nullptr) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        if (posljednja == nullptr)
            posljednja = this;
        else {
            veza = posljednja;
            posljednja = this;
        }
        NepreklapajucaKugla::r = r;
        NepreklapajucaKugla::x = x;
        NepreklapajucaKugla::y = y;
        NepreklapajucaKugla::z = z;
        for (auto it = posljednja->veza; it != nullptr; it = it->veza) {
            if (TestirajPreklapanje(*posljednja, *it)) {
                auto pomocna = posljednja->veza;
                posljednja->veza = nullptr;
                posljednja = pomocna;
                pomocna=nullptr;
                throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
    }

    explicit NepreklapajucaKugla(const std::tuple < double, double, double > &centar, double r = 0):veza(nullptr) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        if (posljednja == nullptr)
            posljednja = this;
        else {
            veza = posljednja;
            posljednja = this;
        }
        NepreklapajucaKugla::r = r;
        NepreklapajucaKugla::x = std::get < 0 > (centar);
        NepreklapajucaKugla::y = std::get < 1 > (centar);
        NepreklapajucaKugla::z = std::get < 2 > (centar);
        for (auto it = posljednja->veza; it != nullptr; it = it->veza) {
            if (TestirajPreklapanje(*posljednja, *it)) {
                auto pomocna = posljednja->veza;
                posljednja->veza = nullptr;
                posljednja = pomocna;
                pomocna=nullptr;
                throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
    }

    ~NepreklapajucaKugla() {
        if (posljednja != nullptr) {
            if (posljednja->veza == nullptr) {
                posljednja = nullptr;
            } else if (posljednja == this) {
                posljednja = posljednja->veza;
            } else {
                for (auto it = posljednja; it != nullptr; it = it->veza) {
                    if (it->veza == this) {
                        it->veza = this->veza;
                    }
                }
            }
        }
    }

    bool static TestirajJednakost(double a, double b) {
        if (fabs (a - b) < Eps * (fabs(a) + fabs(b)))
            return true;
        return false;
    }

    bool static TestirajPreklapanje (NepreklapajucaKugla k1, NepreklapajucaKugla k2) {
        if ((fabs(RastojanjeCentara(k1, k2)) < k1.r + k2.r && fabs(RastojanjeCentara(k1, k2)) > fabs(k1.r - k2.r))
                || (NepreklapajucaKugla::TestirajJednakost(k1.DajX(), k2.DajX()) && NepreklapajucaKugla::TestirajJednakost(k1.DajY(), k2.DajY()) && NepreklapajucaKugla::TestirajJednakost(k1.DajZ(), k2.DajZ())
            && NepreklapajucaKugla::TestirajJednakost(k1.DajPoluprecnik(), k2.DajPoluprecnik())) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1)
             || (NepreklapajucaKugla::TestirajJednakost(k1.DajPoluprecnik() + k2.DajPoluprecnik(), RastojanjeCentara(k1, k2))) || (NepreklapajucaKugla::TestirajJednakost(fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()), RastojanjeCentara(k1, k2))))
            return true;
        return false;
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

    std::tuple < double, double, double > DajCentar() const {
        return std::make_tuple(x, y, z);
    }

    double DajPoluprecnik() const {
        return r;
    }

    double DajPovrsinu() const {
        return 4 * r * r * PI;
    }

    double DajZapreminu() const {
        return 4. / 3 * r * r * r * PI;
    }

    NepreklapajucaKugla &PostaviX(double x) {
        NepreklapajucaKugla::x = x;
        for (auto it = posljednja->veza; it != nullptr; it = it->veza) {
            if (TestirajPreklapanje(*posljednja, *it)) {
                auto pom = posljednja->veza;
                posljednja->veza = nullptr;
                posljednja = pom;
                throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        return *this;
    }

    NepreklapajucaKugla &PostaviY(double y) {
        NepreklapajucaKugla::y = y;
        for (auto it = posljednja->veza; it != nullptr; it = it->veza) {
            if (TestirajPreklapanje(*posljednja, *it)) {
                auto pom = posljednja->veza;
                posljednja->veza = nullptr;
                posljednja = pom;
                throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        return *this;
    }

    NepreklapajucaKugla &PostaviZ(double z) {
        NepreklapajucaKugla::z = z;
        for (auto it = posljednja->veza; it != nullptr; it = it->veza) {
            if (TestirajPreklapanje(*posljednja, *it)) {
                auto pom = posljednja->veza;
                posljednja->veza = nullptr;
                posljednja = pom;
                throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        return *this;
    }

    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
        NepreklapajucaKugla::x = x;
        NepreklapajucaKugla::y = y;
        NepreklapajucaKugla::z = z;
        for (auto it = posljednja->veza; it != nullptr; it = it->veza) {
            if (TestirajPreklapanje(*posljednja, *it)) {
                auto pom = posljednja->veza;
                posljednja->veza = nullptr;
                posljednja = pom;
                throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        return *this;
    }

    NepreklapajucaKugla &PostaviCentar(const std::tuple < double, double, double > &centar) {
        NepreklapajucaKugla::x = std::get < 0 > (centar);
        NepreklapajucaKugla::y = std::get < 1 > (centar);
        NepreklapajucaKugla::z = std::get < 2 > (centar);
        for (auto it = posljednja->veza; it != nullptr; it = it->veza) {
            if (TestirajPreklapanje(*posljednja, *it)) {
                auto pom = posljednja->veza;
                posljednja->veza = nullptr;
                posljednja = pom;
                throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        return *this;
    }

    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik");
        NepreklapajucaKugla::r = r;
        for (auto it = posljednja->veza; it != nullptr; it = it->veza) {
            if (TestirajPreklapanje(*posljednja, *it)) {
                auto pom = posljednja->veza;
                posljednja->veza = nullptr;
                posljednja = pom;
                throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
        return *this;
    }

    void Ispisi() const {
        std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}";
    }

    void Transliraj (double delta_x, double delta_y, double delta_z) {
        NepreklapajucaKugla::x += delta_x;
        NepreklapajucaKugla::y += delta_y;
        NepreklapajucaKugla::z += delta_z;
        for (auto it = posljednja->veza; it != nullptr; it = it->veza) {
            if (TestirajPreklapanje(*posljednja, *it)) {
                auto pom = posljednja->veza;
                posljednja->veza = nullptr;
                posljednja = pom;
                throw std::logic_error ("Nedozvoljeno preklapanje");
            }
        }
    }

    friend double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
    bool DaLiSadrzi (const NepreklapajucaKugla &k) const {
        return RastojanjeCentara (*this, k) <= r - k.r;
    }
};

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return sqrt (pow(k2.x - k1.x, 2) + pow(k2.y - k1.y, 2) + pow(k2.z - k1.z, 2));
}

template < typename TIP >
bool ValidanUnos (TIP &unos, std::string s)
{
    //std::cout << s;
    while (1) {
        if (std::cin >> unos) {
            break;
        } else {

            //std::cout << s;
            return false;
        }
    }
    return true;
}

NepreklapajucaKugla* NepreklapajucaKugla::posljednja=nullptr;

int main ()
{
    int n;
    std::cout<<"Unesite broj kugli: ";
    bool validanUnos=true;
    while (true)
    {
        validanUnos=ValidanUnos(n, "Unesite broj kugli: ");
        if(n<1 || validanUnos==false)
        {
            std::cout<<"Neispravan broj kugli, unesite ponovo!\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        else break;
    }
    std::vector < std::shared_ptr < NepreklapajucaKugla >> kugle (n);
    for (int i = 0; i < n; i++) {
        ponovo:
        std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
        ponovoCentar:
        validanUnos=true;
        double x, y, z, r;
        if(ValidanUnos(x, "x = ")==false) validanUnos=false;
        if(ValidanUnos(y, "y = ")==false) validanUnos=false;
        if(ValidanUnos(z, "z = ")==false) validanUnos=false;
        if(validanUnos==false)
        {
            std::cout<<"Neispravan centar, unesite ponovo:\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            goto ponovoCentar;
        }
        std::cout << "Unesite poluprecnik: ";
        ponovoPoluprecnik:
        validanUnos=ValidanUnos(r, "r = ");
        while (1) {
            if (r < 0 || validanUnos==false) {
                std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                goto ponovoPoluprecnik;
            } else break;
        }
        try
        {
            kugle[i]=std::make_shared<NepreklapajucaKugla>(x,y,z,r);
        }
        catch(std::logic_error poruka)
        {
            std::cout << poruka.what()<<"\n";
            goto ponovo;
        }
        catch(std::domain_error poruka)
        {
            std::cout << poruka.what()<<"\n";
            goto ponovo;
        }
    }
    std::sort(kugle.begin(),kugle.end(),[](std::shared_ptr<NepreklapajucaKugla> k1,std::shared_ptr<NepreklapajucaKugla> k2)
    {
        return k1->DajPovrsinu()<k2->DajPovrsinu();
    });
    std::cout<<"\nKugle nakon obavljenog sortiranja: \n";
    int brojac = 1;
    std::for_each (kugle.begin(), kugle.end(), [&brojac] (std::shared_ptr < NepreklapajucaKugla > za_ispis) {
        za_ispis -> Ispisi();
        std::cout << std::endl;
        brojac++;
    });

    return 0;
}
