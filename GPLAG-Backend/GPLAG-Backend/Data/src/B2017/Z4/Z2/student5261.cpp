#include <iostream>
#include <tuple>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
class NepreklapajucaKugla
{
    double x, y, z, r;
    NepreklapajucaKugla *prije{};
    static NepreklapajucaKugla *zadnja;
    static double PI;
    static bool eq(double a, double b);
    void TestPreklapanja(double, double, double, double);
    bool PreklapaSa(double, double, double, double);
    double RastojanjeOdCentra(double, double, double);
    void Dodaj() { prije = zadnja; zadnja = this; }
public:
    explicit NepreklapajucaKugla(double p = 0) : x(0), y(0), z(0) { PostaviPoluprecnik(p); Dodaj(); }
    NepreklapajucaKugla(double, double, double, double = 0);
    explicit NepreklapajucaKugla(const std::tuple<double, double, double>&, double = 0);
    ~NepreklapajucaKugla();
    NepreklapajucaKugla(const NepreklapajucaKugla&) = delete;
    NepreklapajucaKugla(NepreklapajucaKugla&&) = delete;
    NepreklapajucaKugla &operator =(const NepreklapajucaKugla&) = delete;
    NepreklapajucaKugla &operator =(NepreklapajucaKugla&&) = delete;
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return r*r * 4*PI; }
    double DajZapreminu() const { return r*r*r * 4*PI/3; }
    NepreklapajucaKugla &PostaviX(double a) { TestPreklapanja(a, y, z, r); x = a; return *this; }
    NepreklapajucaKugla &PostaviY(double a) { TestPreklapanja(x, a, z, r); y = a; return *this; }
    NepreklapajucaKugla &PostaviZ(double a) { TestPreklapanja(x, y, a, r); z = a; return *this; }
    NepreklapajucaKugla &PostaviCentar(double a, double b, double c) { TestPreklapanja(a, b, c, r); x = a; y = b; z = c; return *this; }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double>&);
    NepreklapajucaKugla &PostaviPoluprecnik(double);
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend double RastojanjeCentara(const NepreklapajucaKugla&, const NepreklapajucaKugla&);
};
double NepreklapajucaKugla::PI{std::atan(1)*4};
NepreklapajucaKugla *NepreklapajucaKugla::zadnja{};
bool NepreklapajucaKugla::eq(double a, double b) { return std::abs(a - b) <= 1e-10 * (std::abs(a) + std::abs(b)); }
double NepreklapajucaKugla::RastojanjeOdCentra(double a, double b, double c)
{
    return std::sqrt(std::pow(x - a, 2) + std::pow(y - b, 2) + std::pow(z - c, 2));
}
bool NepreklapajucaKugla::PreklapaSa(double a, double b, double c, double p)
{
    return RastojanjeOdCentra(a, b, c) <= r + p || eq(RastojanjeOdCentra(a, b, c), r + p);
}
void NepreklapajucaKugla::TestPreklapanja(double a, double b, double c, double r)
{
    for (auto p(zadnja); p != nullptr; p = p->prije)
        if (p != this && p->PreklapaSa(a, b, c, r))
            throw std::logic_error("Nedozvoljeno preklapanje");
}
NepreklapajucaKugla::NepreklapajucaKugla(double a, double b, double c, double p)
{
    if (p < 0) throw std::domain_error("Ilegalan poluprecnik");
    TestPreklapanja(a, b, c, p);
    x = a; y = b; z = c; r = p;
    Dodaj();
}
NepreklapajucaKugla::NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double p)
{
    if (p < 0) throw std::domain_error("Ilegalan poluprecnik");
    double a, b, c;
    std::tie(a, b, c) = centar;
    TestPreklapanja(a, b, c, p);
    x = a; y = b; z = c; r = p;
    Dodaj();
}
NepreklapajucaKugla::~NepreklapajucaKugla()
{
    if (this == zadnja) { zadnja = prije; return; }
    for (auto p(zadnja); p != nullptr; p = p->prije)
        if (p->prije == this)
            p->prije = p->prije->prije;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double p)
{
    if (p < 0) throw std::domain_error("Ilegalan poluprecnik");
    TestPreklapanja(x, y, z, p);
    r = p;
    return *this;
}
NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const std::tuple<double, double, double> &centar) 
{
    double a, b, c;
    std::tie(a, b, c) = centar;
    return PostaviCentar(a, b, c);
}
void NepreklapajucaKugla::Ispisi() const { std::cout << "{(" << x << ',' << y << ',' << z << ")," << r << '}'; }
void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    TestPreklapanja(x + delta_x, y + delta_y, z + delta_z, r);
    x += delta_x; y += delta_y; z += delta_z;
}
double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return std::sqrt(std::pow(k1.x - k2.x, 2) + std::pow(k1.y - k2.y, 2) + std::pow(k1.z - k2.z, 2));
}
int main()
{
    int n;
    std::cout <<"Unesite broj kugli: ";
    while (!(std::cin >> n) || n < 1)
    {
        std::cout << "Neispravan broj kugli, unesite ponovo!\n";
        std::cin.clear(); std::cin.ignore(10000, '\n');
    }
    try
    {
        std::vector<std::shared_ptr<NepreklapajucaKugla>> v;
        double x, y, z, r;
        for (int i(0); i < n; ++i)
            try
            {
                std::cout << "Unesite centar za " << i+1 << ". kuglu: ";
                while (!(std::cin >> x >> y >> z))
                {
                    std::cout << "Neispravan centar, unesite ponovo:\n";
                    std::cin.clear(); std::cin.ignore(10000, '\n');
                }
                std::cout << "Unesite poluprecnik: ";
                while (!(std::cin >> r) || r < 0)
                {
                   std::cout << "Neispravan poluprecnik, unesite ponovo:\n";
                   std::cin.clear(); std::cin.ignore(10000, '\n');
                }
                v.emplace_back(std::move(std::make_shared<NepreklapajucaKugla>(x, y, z, r)));
            }  catch (const std::exception &e) { std::cout << e.what() << '\n'; --i; }
            catch (...) {}
        std::sort(v.begin(), v.end(), [](const std::shared_ptr<NepreklapajucaKugla> &a, const std::shared_ptr<NepreklapajucaKugla> &b) { return a->DajZapreminu() < b->DajZapreminu(); });
        std::cout << "\nKugle nakon obavljenog sortiranja: ";
        std::for_each(v.begin(), v.end(), [](const std::shared_ptr<NepreklapajucaKugla> &a) { std::cout << '\n'; a->Ispisi(); });
    }
    catch (...) {}
	return 0;
}