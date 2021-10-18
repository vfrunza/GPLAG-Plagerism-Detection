/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>

#include <tuple>
#include <vector>

#include <algorithm>
#include <memory>

typedef std::tuple<double, double, double> Koordinata;

class Kugla {
    double x, y, z;
    double r;
    const double PI = 4.0 * std::atan(1.0);
    
    static bool jesuIstiDouble(double a, double b)
    {
        return std::fabs(a - b) <= 1e-10 * (std::fabs(a) + std::fabs(b));
    }
public:
    explicit Kugla(double r = 0.0);
    Kugla(double x, double y, double z, double r = 0.0);
    explicit Kugla(const Koordinata &centar, double r = 0.0);
    
    double DajX() const;
    double DajY() const;
    double DajZ() const;
    Koordinata DajCentar() const;
    double DajPoluprecnik() const;
    double DajPovrsinu() const;
    double DajZapreminu() const;
    
    Kugla &PostaviX(double x);
    Kugla &PostaviY(double y);
    Kugla &PostaviZ(double z);
    Kugla &PostaviCentar(double x, double y, double z);
    Kugla &PostaviCentar(const Koordinata &centar);
    Kugla &PostaviPoluprecnik(double r);
    
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    
    bool DaLiSadrzi(const Kugla &k) const;
    
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

template <typename InputType>
void Unesite(const std::string &error, const std::vector<InputType*> &input, bool baciIzuzetak = false);

int main ()
{
    int n;
    std::cout << "Unesite broj kugla: ";
    do {
        Unesite("Neispravan broj kugli, unesite ponovo!", std::vector<int*>{&n});
        if (n <= 0)
            std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
    }
    while (n <= 0);
    
    std::vector<std::shared_ptr<Kugla>> v(n, nullptr);
    for (int i = 0; i < n; i++)
    {
        double x, y, z;
        double r;
        
        do {
            try {
                std::cout << "Unesite centar " << i + 1 << ". kugle: ";
                Unesite("Neispravan centar", std::vector<double*>{&x, &y, &z}, true);
                
                std::cout << "Unesite poluprecnik " << i + 1 << ". kugle: ";
                Unesite("Ilegalan poluprecnik", std::vector<double*>{&r}, true);
            }
            catch (...) {
                r = -1;
                continue;
            }
            
            if (r < 0)
                std::cout << "Ilegalan poluprecnik" << std::endl;
        }
        while (r < 0);
        
        try {
            v.at(i) = std::make_shared<Kugla>(x, y, z, r);
        }
        catch (std::bad_alloc) {
            std::cout << "Memorijska greska!" << std::endl;
            return 0;
        }
    }
    
    double delta_x, delta_y, delta_z;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    Unesite("Neispravni parametri translacije, unesite ponovo!", std::vector<double*>{&delta_x, &delta_y, &delta_z});
    
    std::transform(v.begin(), v.end(), v.begin(), [delta_x, delta_y, delta_z](std::shared_ptr<Kugla> k) {
        k->Transliraj(delta_x, delta_y, delta_z);
        return k;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajZapreminu() < k2->DajZapreminu();
    });
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> k) {
        k->Ispisi();
        std::cout << std::endl;
    });
    
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (*std::max_element(v.begin(), v.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {
        return k1->DajPovrsinu() < k2->DajPovrsinu();
    }))->Ispisi();
    std::cout << std::endl;
    
    int i = 1;
    bool imaLi = false;
    std::for_each(v.begin(), v.end() - 1, [v, &i, &imaLi](std::shared_ptr<Kugla> k1) {
        std::for_each(v.begin() + i, v.end(), [k1, &imaLi](std::shared_ptr<Kugla> k2) {
            if (DaLiSeSijeku(*k1, *k2))
            {
                imaLi = true;
                
                std::cout << "Presjecaju se kugle: ";
                k1->Ispisi();
                k2->Ispisi();
            }
        });
        i++;
    });
    
    if (!imaLi)
        std::cout << "Ne postoje kugle koje se presjecaju!" << std::endl;
        
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Kugla> &k) {
        k = nullptr;
    });
    
	return 0;
}

Kugla::Kugla(double r)
{
    PostaviCentar(0, 0, 0);
    PostaviPoluprecnik(r);
}

Kugla::Kugla(double x, double y, double z, double r)
{
    PostaviCentar(x, y, z);
    PostaviPoluprecnik(r);
}

Kugla::Kugla(const Koordinata &centar, double r)
{
    PostaviCentar(centar);
    PostaviPoluprecnik(r);
}

double Kugla::DajX() const
{
    return x;
}

double Kugla::DajY() const
{
    return y;
}

double Kugla::DajZ() const
{
    return z;
}

Koordinata Kugla::DajCentar() const
{
    return std::make_tuple(x, y, z);
}

double Kugla::DajPoluprecnik() const
{
    return r;
}

double Kugla::DajPovrsinu() const
{
    return 4.0 * r * r * PI;
}

double Kugla::DajZapreminu() const
{
    return (4.0 / 3.0) * r * r * r * PI;
}

Kugla &Kugla::PostaviX(double x)
{
    this->x = x;
    return *this;
}

Kugla &Kugla::PostaviY(double y)
{
    this->y = y;
    return *this;
}

Kugla &Kugla::PostaviZ(double z)
{
    this->z = z;
    return *this;
}

Kugla &Kugla::PostaviCentar(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    return *this;
}

Kugla &Kugla::PostaviCentar(const Koordinata &centar)
{
    std::tie(x, y, z) = centar;
    return *this;
}

Kugla &Kugla::PostaviPoluprecnik(double r)
{
    if (r < 0)
        throw std::domain_error("Ilegalan poluprecnik");
    
    this->r = r;
    return *this;
}

void Kugla::Ispisi() const
{
    std::cout << "{(" << x << "," << y << "," << z << "),"
        << r << "}" << std::endl;
}

void Kugla::Transliraj(double delta_x, double delta_y, double delta_z)
{
    PostaviCentar(x + delta_x, y + delta_y, z + delta_z);
}

bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    return RastojanjeCentara(*this, k) <= r - k.r;
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    return DaLiSuPodudarne(k1, k2) && DaLiSuKoncentricne(k1, k2);
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::jesuIstiDouble(k1.r, k2.r);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    return Kugla::jesuIstiDouble(k1.x, k2.x) &&
        Kugla::jesuIstiDouble(k1.y, k2.y) &&
        Kugla::jesuIstiDouble(k1.z, k2.z);
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    return Kugla::jesuIstiDouble(RastojanjeCentara(k1, k2), k1.r + k2.r);
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    return Kugla::jesuIstiDouble(RastojanjeCentara(k1, k2), std::fabs(k1.r - k2.r)) &&
        !DaLiSuIdenticne(k1, k2);
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    return RastojanjeCentara(k1, k2) < k1.r + k2.r &&
        !DaLiSeDodirujuIzvana(k1, k2);
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    return (RastojanjeCentara(k1, k2) < k1.r + k2.r &&
        RastojanjeCentara(k1, k2) > std::fabs(k1.r - k2.r)) ||
        DaLiSuIdenticne(k1, k2);
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
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