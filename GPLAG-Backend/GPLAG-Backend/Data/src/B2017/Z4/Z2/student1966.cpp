/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <cmath>

#include <tuple>
#include <vector>

#include <algorithm>
#include <memory>

typedef std::tuple<double, double, double> Koordinata;

class NepreklapajucaKugla {
    double x, y, z;
    double r;
    const double PI = 4.0 * std::atan(1.0);
    
    NepreklapajucaKugla *prethodna;
    static NepreklapajucaKugla *posljednja;
    
    static bool jesuIstiDouble(double a, double b)
    {
        return std::fabs(a - b) <= 1e-10 * (std::fabs(a) + std::fabs(b));
    }
    
    static bool DaLiSePreklapaju(const NepreklapajucaKugla &k, double x, double y, double z, double r);
    static bool DaLiImaDaSePoklapa(double x, double y, double z, double r, NepreklapajucaKugla *context);
public:
    explicit NepreklapajucaKugla(double r = 0.0);
    NepreklapajucaKugla(double x, double y, double z, double r = 0.0);
    explicit NepreklapajucaKugla(const Koordinata &centar, double r = 0.0);
    ~NepreklapajucaKugla();
    
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    Koordinata DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    
    NepreklapajucaKugla &PostaviX(double x);
    NepreklapajucaKugla &PostaviY(double y);
    NepreklapajucaKugla &PostaviZ(double z);
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z);
    NepreklapajucaKugla &PostaviCentar(const Koordinata &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r);
    
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla *NepreklapajucaKugla::posljednja(nullptr);

template <typename InputType>
void Unesite(const std::string &error, const std::vector<InputType*> &input, bool baciIzuzetak = false);

int main ()
{
    int n;
    std::cout << "Unesite broj kugli: ";
    do {
        Unesite("Neispravan broj kugli, unesite ponovo!", std::vector<int*>{&n});
        if (n <= 0)
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
    }
    while (n <= 0);
    
    std::vector<std::shared_ptr<NepreklapajucaKugla>> v(n, nullptr);
    for (int i = 0; i < n; i++)
    {
        double x, y, z;
        double r;
        
        std::cout << "Unesite centar za " << i + 1 << ". kuglu: ";
        Unesite("Neispravan centar, unesite ponovo:", std::vector<double*>{&x, &y, &z});
                
        std::cout << "Unesite poluprecnik: ";
        do {
            Unesite("Neispravan poluprecnik, unesite ponovo:", std::vector<double*>{&r});
            
            if (r < 0)
                std::cout << "Neispravan poluprecnik, unesite ponovo:" << std::endl;
        }
        while (r < 0);
        
        try {
            v.at(i) = std::make_shared<NepreklapajucaKugla>(x, y, z, r);
        }
        catch (std::bad_alloc) {
            std::cout << "Memorijska greska!" << std::endl;
            return 0;
        }
        catch (const std::exception &er) {
            std::cout << er.what() << std::endl;
            i--;
        }
    }
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> k1, std::shared_ptr<NepreklapajucaKugla> k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    });
    
    std::cout << "\nKugle nakon obavljenog sortiranja: " << std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> k) {
        k->Ispisi();
        std::cout << std::endl;
    });
        
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<NepreklapajucaKugla> &k) {
        k = nullptr;
    });
    
	return 0;
}

NepreklapajucaKugla::NepreklapajucaKugla(double r) : r(0)
{
    PostaviCentar(0, 0, 0);
    PostaviPoluprecnik(r);
    
    prethodna = posljednja;
    posljednja = this;
}

NepreklapajucaKugla::NepreklapajucaKugla(double x, double y, double z, double r) : r(0)
{
    PostaviCentar(x, y, z);
    PostaviPoluprecnik(r);
    
    prethodna = posljednja;
    posljednja = this;
}

NepreklapajucaKugla::NepreklapajucaKugla(const Koordinata &centar, double r) : r(0)
{
    PostaviCentar(centar);
    PostaviPoluprecnik(r);
    
    prethodna = posljednja;
    posljednja = this;
}

NepreklapajucaKugla::~NepreklapajucaKugla()
{
    NepreklapajucaKugla *it(posljednja);
    
    if (!posljednja)
        throw std::runtime_error("Kako se ovo desilo uopce...");
    
    if (posljednja == this) {
        posljednja = posljednja->prethodna;
        return;
    }
    
    while (it != nullptr && it->prethodna != this)
        it = it->prethodna;
        
    it->prethodna = it->prethodna->prethodna;
}

double NepreklapajucaKugla::DajX() const
{
    return x;
}

double NepreklapajucaKugla::DajY() const
{
    return y;
}

double NepreklapajucaKugla::DajZ() const
{
    return z;
}

Koordinata NepreklapajucaKugla::DajCentar() const
{
    return std::make_tuple(x, y, z);
}

double NepreklapajucaKugla::DajPoluprecnik() const
{
    return r;
}

double NepreklapajucaKugla::DajPovrsinu() const
{
    return 4.0 * r * r * PI;
}

double NepreklapajucaKugla::DajZapreminu() const
{
    return (4.0 / 3.0) * r * r * r * PI;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviX(double x)
{
    return PostaviCentar(x, y, z);
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviY(double y)
{
    return PostaviCentar(x, y, z);
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviZ(double z)
{
    return PostaviCentar(x, y, z);
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(double x, double y, double z)
{
    if (DaLiImaDaSePoklapa(x, y, z, r, this))
        throw std::logic_error("Nedozvoljeno preklapanje");
    
    this->x = x;
    this->y = y;
    this->z = z;
    return *this;
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviCentar(const Koordinata &centar)
{
    double x, y, z;
    std::tie(x, y, z) = centar;
    
    return PostaviCentar(x, y, z);
}

NepreklapajucaKugla &NepreklapajucaKugla::PostaviPoluprecnik(double r)
{
    if (r < 0)
        throw std::domain_error("Ilegalan poluprecnik");
    
    if (DaLiImaDaSePoklapa(x, y, z, r, this))
        throw std::logic_error("Nedozvoljeno preklapanje");
    
    this->r = r;
    return *this;
}

void NepreklapajucaKugla::Ispisi() const
{
    std::cout << "{(" << x << "," << y << "," << z << "),"
        << r << "}";
}

void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    PostaviCentar(x + delta_x, y + delta_y, z + delta_z);
}

bool NepreklapajucaKugla::DaLiSePreklapaju(const NepreklapajucaKugla &k, double x, double y, double z, double r)
{
    double rastojanje{std::sqrt(
        (k.x - x) * (k.x - x) +
        (k.y - y) * (k.y - y) +
        (k.z - z) * (k.z - z)
    )};
    
    return rastojanje < k.r + r ||
        NepreklapajucaKugla::jesuIstiDouble(rastojanje, k.r + r);
}

bool NepreklapajucaKugla::DaLiImaDaSePoklapa(double x, double y, double z, double r, NepreklapajucaKugla *context)
{
    for (NepreklapajucaKugla *it = NepreklapajucaKugla::posljednja; it != nullptr; it = it->prethodna)
        if (it == context)
            continue;
        else if (DaLiSePreklapaju(*it, x, y, z, r))
            return true;
    
    return false;
}

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)
{
    return std::sqrt(
        (k1.x - k2.x) * (k1.x - k2.x) +
        (k1.y - k2.y) * (k1.y - k2.y) +
        (k1.z - k2.z) * (k1.z - k2.z)
    );
}

template <typename InputType>
void Unesite(const std::string &error, const std::vector<InputType*> &input, bool baciIzuzetak)
{
    while (true) {
        for (auto i : input)
            std::cin >> *i;
        
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            
            std::cout << error << std::endl;
            
            if (baciIzuzetak)
                throw baciIzuzetak;
            
            continue;
        }
        
        while (std::cin.peek() == ' ')
            std::cin.get();
        
        if (std::cin.peek() == '\n' || std::cin.peek() == EOF)
            return;
        
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << error << std::endl;
        
        if (baciIzuzetak)
            throw baciIzuzetak;
    }
    
}