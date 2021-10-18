#include <vector>
#include <deque>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <tuple>
#include <algorithm>

const double pi=4.*atan(1.);
const double ep=pow(10, -10);

class Kugla {
    double x, y, z, r;
    public:
        explicit Kugla(double r=0) {
            if (r<0 or !std::cin) throw std::domain_error("Ilegalan poluprecnik");
            Kugla::r=r;
        }
        Kugla(double x, double y, double z, double r=0) {
            if (r<0 or !std::cin) throw std::domain_error("Ilegalan poluprecnik");
            Kugla::x=x;
            Kugla::y=y;
            Kugla::z=z;
            Kugla::r=r;
        }
        explicit Kugla(const std::tuple<double, double, double> &centar, double r=0) {
            if (r<0 or !std::cin) throw std::domain_error("Ilegalan poluprecnik");
            Kugla::x=std::get<0>(centar);
            Kugla::y=std::get<1>(centar);
            Kugla::z=std::get<2>(centar);
            Kugla::r=r;
        }
        double DajX() const {
            return Kugla::x;
        }
        double DajY() const {
            return Kugla::y;
        }
        double DajZ() const {
            return Kugla::z;
        }
        std::tuple<double, double, double> DajCentar() const {
            return std::make_tuple(Kugla::x, Kugla::y, Kugla::z);
        }
        double DajPoluprecnik() const {
            return Kugla::r;
        }
        double DajPovrsinu() const {
            return 4.*r*r*pi;
        }
        double DajZapreminu() const {
            return (4./3)*r*r*r*pi;
        }
        Kugla &PostaviX(double x) {
            Kugla::x=x;
            return *this;
        }
        Kugla &PostaviY(double y) {
            Kugla::y=y;
            return *this;
        }
        Kugla &PostaviZ(double z) {
            Kugla::z=z;
            return *this;
        }
        Kugla &PostaviCentar(double x, double y, double z) {
            Kugla::x=x;
            Kugla::y=y;
            Kugla::z=z;
            return *this;
        }
        Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
            Kugla::x=std::get<0>(centar);
            Kugla::y=std::get<1>(centar);
            Kugla::z=std::get<2>(centar);
            return *this;
        }
        Kugla &PostaviPoluprecnik(double r) {
            if (r<0 or !std::cin) throw std::domain_error("Ilegalan poluprecnik");
            Kugla::r=r;
            return *this;
        }
        void Ispisi() const {
            std::cout << "{(" << x << "," << y << "," << z << ")" << "," << r << "}" << std::endl;
        }
        void Transliraj(double delta_x, double delta_y, double delta_z) {
            Kugla::x+=delta_x;
            Kugla::y+=delta_y;
            Kugla::z+=delta_z;
        }
        friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
            if (std::fabs(k1.DajX()-k2.DajX())<ep*(std::fabs(k1.DajX())+std::fabs(k2.DajX())) and std::fabs(k1.DajY()-k2.DajY())<ep*(std::fabs(k1.DajY())+std::fabs(k2.DajY())) and std::fabs(k1.DajZ()-k2.DajZ())<ep*(std::fabs(k1.DajZ())+std::fabs(k2.DajZ())) and std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<ep*(std::fabs(k1.DajPoluprecnik())+std::fabs(k2.DajPoluprecnik()))) return true;
            return false;
        }
        friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
            if (std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<ep*(std::fabs(k1.DajPoluprecnik())+std::fabs(k2.DajPoluprecnik()))) return true;
            return false;
        }
        friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
            if (std::fabs(k1.DajX()-k2.DajX())<ep*(std::fabs(k1.DajX())+std::fabs(k2.DajX())) and std::fabs(k1.DajY()-k2.DajY())<ep*(std::fabs(k1.DajY())+std::fabs(k2.DajY())) and std::fabs(k1.DajZ()-k2.DajZ())<ep*(std::fabs(k1.DajZ())+std::fabs(k2.DajZ()))) return true;
            return false;
        }
        friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
            if (std::fabs(k1.DajPoluprecnik()+k2.DajPoluprecnik()-sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ()*k1.DajZ()-k2.DajZ())))<ep*(std::fabs(k1.DajPoluprecnik())+std::fabs(k2.DajPoluprecnik())+std::fabs(sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ()*k1.DajZ()-k2.DajZ()))))) return true;
            if ((k1.DajPoluprecnik()-0)<ep*std::fabs(k1.DajPoluprecnik()) and (k2.DajPoluprecnik()-0)<ep*std::fabs(k2.DajPoluprecnik()) and std::fabs(k1.DajX()-k2.DajX())<ep*(std::fabs(k1.DajX())+std::fabs(k2.DajX())) and std::fabs(k1.DajY()-k2.DajY())<ep*(std::fabs(k1.DajY())+std::fabs(k2.DajY())) and std::fabs(k1.DajZ()-k2.DajZ())<ep*(std::fabs(k1.DajZ())+std::fabs(k2.DajZ()))) return true;
            return false;
        }
        friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
            if (std::fabs(std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())-RastojanjeCentara(k1, k2))<ep*(std::fabs(std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())+std::fabs(RastojanjeCentara(k1, k2))))) return true;
            if ((k1.DajPoluprecnik()-0)<ep*(std::fabs(k1.DajPoluprecnik())) and (k2.DajPoluprecnik()-0)<ep*(std::fabs(k2.DajPoluprecnik())) and std::fabs(k1.DajX()-k2.DajX())<ep*(std::fabs(k1.DajX())+std::fabs(k2.DajX())) and std::fabs(k1.DajY()-k2.DajY())<ep*(std::fabs(k1.DajY())+std::fabs(k2.DajY())) and std::fabs(k1.DajZ()-k2.DajZ())<ep*(std::fabs(k1.DajZ())+std::fabs(k2.DajZ()))) return true;
            return false;
        }
        friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
            if (std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())>RastojanjeCentara(k1, k2)) return true;
            return false;
        }
        friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
            if (std::fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik())<RastojanjeCentara(k1, k2)) return true;
            return false;
        }
        bool DaLiSadrzi(const Kugla &k) const {
            return ((std::sqrt((Kugla::x-k.x)*(Kugla::x-k.x)+(Kugla::y-k.y)*(Kugla::y-k.y)+(Kugla::z-k.z)*(Kugla::z-k.z))+k.r)<=Kugla::r);
        }
        friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
            return sqrt(((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX()))+(k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY())+(k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()));
        }
};

int main ()
{
    int n;
    double x, y, z, r;
    std::cout << "Unesite broj kugla: ";
    for (;;) {
        std::cin >> n;
        if (std::cin and n>0) break;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
    }
    int i=0;
    std::vector<std::shared_ptr<Kugla>> v(n);
    for (;;) {
        for (;;) {
            std::cout << "Unesite centar "  << i+1 << ". kugle: ";
            std::cin >> x >> y >> z;
            if (std::cin) break;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Neispravan centar" << std::endl;
        }
        std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        std::cin >> r;
        try {
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                throw std::domain_error("Ilegalan poluprecnik");
            }
            Kugla k(x, y, z, r);
            v[i]=std::make_shared<Kugla>(k);
            i++;
            if (i==n) break;
        }
        catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for (;;) {
        std::cin >> x >> y >> z;
        if (std::cin) break;
        else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
        }
    }
    std::vector<std::shared_ptr<Kugla>>::iterator it;
    std::transform(v.begin(), v.end(), v.begin(), [x, y, z] (std::shared_ptr<Kugla> p1) {p1->Transliraj(x, y, z); return p1;});
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) {return (p1->DajZapreminu()<p2->DajZapreminu());});
    for (int i=0; i<n; i++) {
        v[i]->Ispisi();
    }
    int brojac=0;
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*(std::max_element(v.begin(), v.end(), [] (std::shared_ptr<Kugla> p1, std::shared_ptr<Kugla> p2) { return (p1->DajPovrsinu()<p2->DajPovrsinu()); } )))->Ispisi();
    for_each(v.begin(), v.end(), [&] (const std::shared_ptr<Kugla> &p1) {
        for_each(v.begin(), v.end(), [&] (const std::shared_ptr<Kugla> &p2) {
            if ((&p2)>(&p1) and DaLiSeSijeku((*p1), (*p2))) {
                std::cout << "Presjecaju se kugle: ";
                p1->Ispisi(), p2->Ispisi(); // sejtan operator
                brojac++;
            }
        });
    });
    if (brojac==0) std::cout << "Ne postoje kugle koje se presjecaju!";
	return 0;
}
