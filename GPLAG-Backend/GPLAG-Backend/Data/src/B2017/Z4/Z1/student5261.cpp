#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
class Kugla
{
    double x, y, z, r;
    static double PI;
    static bool eq(double a, double b);
public:
    explicit Kugla(double p = 0) { PostaviPoluprecnik(p); x = y = z = 0; }
    Kugla(double a, double b, double c, double p = 0) { PostaviPoluprecnik(p).PostaviCentar(a, b, c); }
    explicit Kugla(const std::tuple<double, double, double> &centar, double p = 0) { PostaviPoluprecnik(p).PostaviCentar(centar); }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return r*r * 4*PI; }
    double DajZapreminu() const { return r*r*r * 4*PI/3; }
    Kugla &PostaviX(double a) { x = a; return *this; }
    Kugla &PostaviY(double a) { y = a; return *this; }
    Kugla &PostaviZ(double a) { z = a; return *this; }
    Kugla &PostaviCentar(double a, double b, double c) { x = a; y = b; z = c; return *this; }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) { std::tie(x, y, z) = centar; return *this; }
    Kugla &PostaviPoluprecnik(double);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z) { x += delta_x; y += delta_y; z += delta_z; }
    friend bool DaLiSuIdenticne(const Kugla&, const Kugla&);
    friend bool DaLiSuPodudarne(const Kugla&, const Kugla&);
    friend bool DaLiSuKoncentricne(const Kugla&, const Kugla&);
    friend bool DaLiSeDodirujuIzvana(const Kugla&, const Kugla&);
    friend bool DaLiSeDodirujuIznutra(const Kugla&, const Kugla&);
    friend bool DaLiSePreklapaju(const Kugla&, const Kugla&);
    friend bool DaLiSeSijeku(const Kugla&, const Kugla&);
    bool DaLiSadrzi(const Kugla&) const;
    friend double RastojanjeCentara(const Kugla&, const Kugla&);
};
double Kugla::PI{std::atan(1)*4};
bool Kugla::eq(double a, double b) { return std::abs(a - b) <= 1e-10 * (std::abs(a) + std::abs(b)); }
Kugla &Kugla::PostaviPoluprecnik(double p)
{
    if (p < 0) throw std::domain_error("Ilegalan poluprecnik");
    r = p;
    return *this;
}
void Kugla::Ispisi() const { std::cout << "{(" << x << ',' << y << ',' << z << ")," << r << '}' << std::endl; }
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) { return DaLiSuPodudarne(k1, k2) && DaLiSuKoncentricne(k1, k2); }
bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) { return Kugla::eq(k1.r, k2.r); }
bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) { return Kugla::eq(k1.x, k2.x) && Kugla::eq(k1.y, k2.y) && Kugla::eq(k1.z, k2.z); }
bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) { return Kugla::eq(RastojanjeCentara(k1, k2), k1.r + k2.r); }
bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return Kugla::eq(std::abs(k1.r - k2.r), RastojanjeCentara(k1, k2)) && (k1.r == 0 || k2.r == 0 || !DaLiSuIdenticne(k1, k2));
}
bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return RastojanjeCentara(k1, k2) < k1.r + k2.r && k1.r > 0 && k2.r > 0 && !DaLiSeDodirujuIzvana(k1, k2);
}
bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return k1.r > 0 && k2.r > 0 && ((RastojanjeCentara(k1, k2) < k1.r + k2.r && RastojanjeCentara(k1, k2) > std::abs(k1.r - k2.r)
        && !DaLiSeDodirujuIznutra(k1, k2) && !DaLiSeDodirujuIzvana(k1, k2)) || DaLiSuIdenticne(k1, k2));
}
bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    return RastojanjeCentara(k, *this) + k.r <= r || eq(RastojanjeCentara(k, *this) + k.r, r) || DaLiSuIdenticne(k, *this);
}
double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return std::sqrt(pow(k1.x - k2.x, 2) + pow(k1.y - k2.y, 2) + pow(k1.z - k2.z, 2));
}
int main()
{
    int n;
    std::cout <<"Unesite broj kugla: ";
    while (!(std::cin >> n) || n < 1)
    {
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear(); std::cin.ignore(10000, '\n');
    }
    try
    {
        std::vector<std::shared_ptr<Kugla>> v;
        double x, y, z, r;
        for (int i(0); i < n; ++i)
        {
            std::cout << "Unesite centar " << i+1 << ". kugle: ";
            if (!(std::cin >> x >> y >> z))
            {
                std::cout << "Neispravan centar\n";
                std::cin.clear(); std::cin.ignore(10000, '\n');
                --i; continue;
            }
            std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
            if (!(std::cin >> r) || r < 0)
            {
                std::cout << "Ilegalan poluprecnik\n";
                std::cin.clear(); std::cin.ignore(10000, '\n');
                --i; continue;
            }
            v.emplace_back(std::move(std::make_shared<Kugla>(x, y, z, r)));
        }
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        while (!(std::cin >> x >> y >> z))
        {
            std::cout << "Neispravni parametri translacije, unesite ponovo!\n";
            std::cin.clear(); std::cin.ignore(10000, '\n');
        }
        std::transform(v.begin(), v.end(), v.begin(), [=](const std::shared_ptr<Kugla> &a) { a->Transliraj(x, y, z); return a; });
        std::sort(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &a, const std::shared_ptr<Kugla> &b) { return a->DajPoluprecnik() < b->DajPoluprecnik(); });
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
        std::for_each(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &a) { a->Ispisi(); });
        std::cout << "Kugla sa najvecom povrsinom je: ";
        if (!v.empty())
            (*std::max_element(v.begin(), v.end(), [](const std::shared_ptr<Kugla> &a, const std::shared_ptr<Kugla> &b) { return a->DajPoluprecnik() < b->DajPoluprecnik(); }))->Ispisi();
        bool f(false);
        for_each(v.begin(), v.end(), [&](const std::shared_ptr<Kugla> &a) {
            std::for_each(v.begin() + (&a - &*v.begin()) + 1, v.end(), [&](const std::shared_ptr<Kugla> &b) {
                if (DaLiSeSijeku(*a, *b))
                {
                    std::cout << "Presjecaju se kugle: ";
                    a->Ispisi();b->Ispisi();
                    if (!f) f = true;
                }
            });
        });
        if (!f) std::cout << "Ne postoje kugle koje se presjecaju!";
    }
    catch (...) {}
	return 0;
}