/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <functional>
#include <iomanip>

class Berza
{
    std::vector<int> cijene;
    int max_cijena, min_cijena;

    void Prekoracenje() {
        if(std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, max_cijena))
                || std::count_if(cijene.begin(), cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, min_cijena)))
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }


public:
    explicit Berza(int max_cijena);
    Berza(int min_cijena, int max_cijena);

    void RegistrirajCijenu(int nova_cijena);
    int DajBrojRegistriranihCijena() const;
    void BrisiSve();

    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;

    bool operator! () const;
    int operator [] (int x) const;
    Berza &operator ++ ();
    Berza &operator -- ();
    Berza operator ++ (int);
    Berza operator -- (int);
    Berza operator -() const;
    friend Berza operator +(const Berza &x, int y);
    friend Berza operator -(const Berza &x, int y);
    friend Berza operator +(int y , const Berza &x);
    friend Berza operator -(int y, const Berza & x);
    friend Berza operator -(const Berza &x, const Berza &y);
    operator int() const = delete;
    Berza &operator +=(int y);
    Berza &operator -=(int y);
    Berza &operator -=(const Berza &y);
    bool operator ==(const Berza &y);
    bool operator != (const Berza &y);

    int DajBrojCijenaVecihOd(int vrijednost) const;

    void Ispisi() const;



};

struct ZaIspis {

    void operator() (double x) {
        std::cout << std::fixed << std::setprecision(2) << x <<std::endl;
    }
};

Berza::Berza(int min_cijena, int max_cijena): cijene(0)
{

    if(min_cijena < 0 || max_cijena < 0) throw std::range_error("Ilegalne granice cijene");

    Berza::max_cijena = max_cijena;
    Berza::min_cijena = min_cijena;
}
Berza::Berza(int max_cijena): min_cijena(0), cijene(0)
{
    if(max_cijena < 0) throw std::range_error("Ilegalne granice cijene");
    Berza::max_cijena = max_cijena;
}
void Berza::RegistrirajCijenu(int nova_cijena)
{
    if(nova_cijena < min_cijena || nova_cijena > max_cijena) throw std::range_error("Ilegalna cijena");

    cijene.emplace_back(nova_cijena);
}
int Berza::DajBrojRegistriranihCijena() const
{
    return cijene.size();
}
void Berza::BrisiSve()
{
    cijene.resize(0);
}
int Berza::DajMinimalnuCijenu() const
{
    if(cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
    return *min_element(cijene.begin(), cijene.end());
}

int Berza::DajMaksimalnuCijenu() const
{
    if(cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
    return *max_element(cijene.begin(), cijene.end());
}

bool Berza::operator! () const
{
    return cijene.size() == 0;
}
int Berza::DajBrojCijenaVecihOd(int vrijednost) const
{
    if(cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
    return std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1 , vrijednost));
}
void Berza::Ispisi() const
{
    std::vector<double> novi(cijene.size());
    std::copy(cijene.begin(), cijene.end(), novi.begin());
    std::sort(novi.begin(), novi.end(), std::greater<int>());
    std::transform(novi.begin(), novi.end(), novi.begin() ,std::bind(std::divides<double>(), std::placeholders::_1, 100));
    std::for_each(novi.begin(), novi.end(), ZaIspis());
}
int Berza::operator [] (int x) const
{
    if(x < 1 || x >= cijene.size()) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return cijene[x - 1];
}
Berza &Berza::operator ++ ()
{
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    Prekoracenje();
    return *this;
}
Berza &Berza::operator -- ()
{
    std::transform(cijene.begin(), cijene.end(), cijene.begin() , std::bind(std::minus<int>(), std::placeholders::_1, 100));
    Prekoracenje();
    return *this;
}
Berza Berza::operator ++ (int)
{
    Berza pomocna(*this);
    std::transform(cijene.begin(), cijene.end(), cijene.begin() , std::bind(std::plus<int>(), std::placeholders::_1, 100));
    return pomocna;
}
Berza Berza::operator -- (int)
{
    Berza pomocna(*this);
    std::transform(cijene.begin(), cijene.end(), cijene.begin() , std::bind(std::minus<int>(), std::placeholders::_1, 100));
    return pomocna;
}
Berza Berza::operator -() const
{
    Berza novi(this->min_cijena, this->max_cijena);
    novi.cijene.resize(this->cijene.size());
    std::transform(novi.cijene.begin(), novi.cijene.end(), novi.cijene.begin(), std::bind(std::minus<int>(),
                   max_cijena + min_cijena, std::placeholders::_1 ));
    return novi;
}
Berza operator +(const Berza &x, int y)
{
    Berza novi(x.min_cijena, x.max_cijena);
    novi.cijene.resize(x.cijene.size());
    std::transform(x.cijene.begin(), x.cijene.end(), novi.cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
    novi.Prekoracenje();
    return novi;
}
Berza operator -(const Berza &x, int y)
{
    Berza novi(x.min_cijena, x.max_cijena);
    novi.cijene.resize(x.cijene.size());
    std::transform(x.cijene.begin(), x.cijene.end(), novi.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
    novi.Prekoracenje();
    return novi;
}
inline Berza operator +(int y , const Berza &x)
{
    return x + y;
}
Berza operator -(int y, const Berza & x)
{
    Berza novi(x.min_cijena, x.max_cijena);
    novi.cijene.resize(x.cijene.size());
    std::transform(x.cijene.begin(), x.cijene.end(), novi.cijene.begin(), std::bind(std::minus<int>(), y, std::placeholders::_1));
    novi.Prekoracenje();
    return novi;
}
Berza operator -(const Berza &x, const Berza &y)
{
    if(x.cijene.size() != y.cijene.size() || x.min_cijena != y.min_cijena || x.min_cijena != y.min_cijena)
        throw std::domain_error("Nesaglasni operandi");

    Berza novi(x.min_cijena, x.max_cijena);
    novi.cijene.resize(x.cijene.size());
    std::transform(x.cijene.begin(), x.cijene.end(), y.cijene.begin(), novi.cijene.begin(), std::minus<int>());
    novi.Prekoracenje();
    return novi;
}
Berza &Berza::operator +=(int y)
{
    *this = *this + y;
    return *this;
}
Berza &Berza::operator -=(int y)
{
    *this = *this - y;
    return *this;
}
Berza &Berza::operator -=(const Berza &y)
{
    *this = *this - y;
    return *this;
}
bool Berza::operator ==(const Berza &y)
{
    return (cijene.size() == y.cijene.size()) && std::equal(cijene.begin(), cijene.end(), y.cijene.begin(), std::equal_to<int>());
}
inline bool Berza::operator != (const Berza &y)
{
    return (cijene.size() != y.cijene.size()) || std::equal(cijene.begin(), cijene.end(), y.cijene.begin(), std::not_equal_to<int>());
}



int main ()
{
    Berza test (1, 10000);
    test.RegistrirajCijenu(900);
    test.RegistrirajCijenu(400);
    test.RegistrirajCijenu(1000);

    Berza test2 (1, 10000);
    test2.RegistrirajCijenu(900);
    test2.RegistrirajCijenu(500);
    test2.RegistrirajCijenu(1000);


    std::cout << (test2 == test);

    return 0;
}
