#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <functional>
using std::vector;

class Berza
{
    int min, max;
    vector<int> cijene;
public:
    Berza(int min, int max) : min(min), max(max)
    {
        if (min <= 0 || max <= 0) throw std::range_error("Ilegalne granicne cijene");
    }
    //?Kontradikcija. U prethodnom konstruktoru obe granicne cijene trebaju biti pozitivne, a ovdje se minimalna postavlja na nulu
    //Logicno bi bilo prepraviti uslov u prvom konstruktoru da min moze biti i nula, ali cu se drzati postavke zadatka
    explicit Berza(int max) : min(0), max(max)
    {
        if (max <= 0) throw std::range_error("Ilegalne granicne cijene");
    }
    void RegistrirajCijenu(int);
    int DajBrojRegistriranihCijena() const { return cijene.size(); }
    void BrisiSve() { cijene.clear(); }
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    int DajBrojCijenaVecihOd(int) const;
    void Ispisi() const;
    bool operator !() const { return cijene.empty(); }
    Berza &operator ++();
    Berza &operator --();
    Berza operator ++(int) { Berza b(*this); ++*this; return b; }
    Berza operator --(int) { Berza b(*this); --*this; return b; }
    Berza &operator +=(int);
    Berza &operator -=(int x) { return *this += -x; }
    
    bool operator ==(const Berza&) const;
    bool operator !=(const Berza &b) const { return !(*this == b); }
    
    int operator [](int i) const { if (i < 1 || i > cijene.size()) throw std::range_error("Neispravan indeks"); return cijene[i-1]; }
    friend Berza operator -(int, Berza);
    friend Berza operator -(Berza);
    friend Berza operator -(Berza, const Berza&);
};
void Berza::RegistrirajCijenu(int c)
{
    if (c < min || c > max)
        throw std::range_error("Ilegalna cijena");
    cijene.push_back(c);
}
int Berza::DajMinimalnuCijenu() const
{
    if (cijene.empty()) throw std::range_error("Nema registriranih cijena");
    return *min_element(cijene.begin(), cijene.end());
}
int Berza::DajMaksimalnuCijenu() const
{
    if (cijene.empty()) throw std::range_error("Nema registriranih cijena");
    return *max_element(cijene.begin(), cijene.end());
}
int Berza::DajBrojCijenaVecihOd(int c) const
{
    if (cijene.empty()) throw std::range_error("Nema registriranih cijena");
    return std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, c));
}
void Berza::Ispisi() const
{
    auto v(cijene);
    std::sort(v.begin(), v.end(), std::greater<int>());
    for_each(v.begin(), v.end(), [](int x) {
        std::cout << x / 100 << '.' << (x % 100 < 10 ? "0" : "") << x % 100 << '\n';
    });
}
Berza &Berza::operator ++()
{
    if (cijene.empty()) return *this;
    if (std::find_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, max - 100)) != cijene.end())
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    return *this;
}
Berza &Berza::operator --()
{
    if (cijene.empty()) return *this;
    if (std::find_if(cijene.begin(), cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, min + 100)) != cijene.end())
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, -100));
    return *this;
}
Berza &Berza::operator +=(int x)
{
    if (cijene.empty()) return *this;
    if (std::find_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, max - x)) != cijene.end()
    || std::find_if(cijene.begin(), cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, min - x)) != cijene.end())
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, x));
    return *this;
}
bool Berza::operator ==(const Berza &b) const
{
    return cijene.size() == b.cijene.size() && std::equal(cijene.begin(), cijene.end(), b.cijene.begin());
}
//?Pretpostavljam da ostaju iste granicne vrijednosti za vraceni objekat
Berza operator -(Berza b)
{
    std::transform(b.cijene.begin(), b.cijene.end(), b.cijene.begin(), std::bind(std::minus<int>(), b.min + b.max, std::placeholders::_1));
    return b;
}
inline Berza operator +(Berza b, int x) { return b += x; }
inline Berza operator -(Berza b, int x) { return b -= x; }
inline Berza operator +(int x, Berza b) { return b += x; }
Berza operator -(int x, Berza b)
{
    if (std::find_if(b.cijene.begin(), b.cijene.end(), std::bind(std::greater<int>(), x-b.max, std::placeholders::_1)) != b.cijene.end()
    || std::find_if(b.cijene.begin(), b.cijene.end(), std::bind(std::less<int>(), x-b.min, std::placeholders::_1)) != b.cijene.end())
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(b.cijene.begin(), b.cijene.end(), b.cijene.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    return b;
}
Berza operator -(Berza a, const Berza &b)
{
    if (a.cijene.size() != b.cijene.size() || a.min != b.min || a.max != b.max)
        throw std::domain_error("Nesaglasni operandi");
    std::transform(a.cijene.begin(), a.cijene.end(), b.cijene.begin(), a.cijene.begin(), std::minus<int>());
    if (std::find_if(a.cijene.begin(), a.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, a.max)) != a.cijene.end()
    || std::find_if(a.cijene.begin(), a.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, a.min)) != a.cijene.end())
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return a;
}

int main()
{
    Berza berza(1, 109);
    for (int i(1); i < 10; ++i)
        berza.RegistrirajCijenu(i);
    std::cout << "Broj cijena: " << berza.DajBrojRegistriranihCijena() << '\n';
    berza.BrisiSve();
    std::cout << "Prazno: " << std::boolalpha << !berza;
    std::cout << "\nBroj cijena: " << berza.DajBrojRegistriranihCijena() << '\n';
    for (int i(1); i < 10; ++i)
        berza.RegistrirajCijenu(i);
    std::cout << "Broj cijena: " << berza.DajBrojRegistriranihCijena()
    << "\nNajmanja cijena: " << berza.DajMinimalnuCijenu()
    << "\nNajveca cijena: " << berza.DajMaksimalnuCijenu() << "\nBroj elemenata vecih od: ";
    for (int i(0); i < 10; ++i)
        std::cout << berza.DajBrojCijenaVecihOd(i) << ' ';
    berza++;
    std::cout << '\n'; berza.Ispisi();
    berza--;
    std::cout << '\n'; berza.Ispisi();
    ++berza;
    std::cout << '\n'; berza.Ispisi();
    --berza;
    std::cout << '\n'; berza.Ispisi();
    std::cout << '\n'; (berza += 10).Ispisi();
    std::cout << '\n'; (berza -= 10).Ispisi();
    for (int i(1); i <= 9; ++i) std::cout << berza[i] << ' ';
    berza = 100 - berza;
    std::cout << '\n'; berza.Ispisi();
    berza = -berza; std::cout << '\n'; berza.Ispisi();
    Berza b(1, 109);
    for (int i(10); i < 19; ++i) b.RegistrirajCijenu(i);
    std::cout << '\n'; (berza - b).Ispisi();
    std::cout << "Jednaki: " << (b == berza);
	return 0;
}