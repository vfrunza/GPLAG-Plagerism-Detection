#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>

class Berza
{
    std::vector<int> uk_cijene;
    int min_cijena, max_cijena;
public:
    Berza (int min, int max) {
        if (min<0 || max<0)
            throw std::range_error("Ilegalne granice cijene");
        min_cijena=min;
        max_cijena=max;
    }
    explicit Berza(int max) {
        if (max<0)
            throw std::range_error("Ilegalne granice cijene");
        min_cijena=0;
        max_cijena=max;
    }
    Berza& RegistrirajCijenu(int cijena) {
        if (cijena<min_cijena || cijena>max_cijena)
            throw std::range_error("Ilegalna cijena");
        uk_cijene.push_back(cijena);
        return *this;
    }
    int DajBrojRegistriranihCijena() const {
        return uk_cijene.size();
    }
    void BrisiSve() {
        uk_cijene.resize(0);
    }
    int DajMinimalnuCijenu() const {
        if (!uk_cijene.size())
            throw std::range_error("Nema registriranih cijena");
        return *std::min_element(uk_cijene.begin(), uk_cijene.end());
    }
    int DajMaksimalnuCijenu() const {
        if (!uk_cijene.size())
            throw std::range_error("Nema registriranih cijena");
        return *std::max_element(uk_cijene.begin(), uk_cijene.end());
    }
    bool operator !() {
        return !uk_cijene.size();
        return false;
    }
    int DajBrojCijenaVecihOd(int c) const {
        if (!uk_cijene.size())
            throw std::range_error("Nema registriranih cijena");
        return std::count_if(uk_cijene.begin(), uk_cijene.end(), std::bind(std::less<int>(), c, std::placeholders::_1));
    }
    void Ispisi() const {
        std::vector<int> kopija = uk_cijene;
        std::sort(kopija.begin(), kopija.end(), std::greater<int>());
        for (auto i : kopija)
            std::cout << std::setprecision(2) << std::fixed << i/100. << std::endl;
    }
    int operator [](int indeks) const {
        if (indeks<1 || indeks>uk_cijene.size())
            throw std::range_error("Neispravan indeks");
        return uk_cijene[indeks-1];
    }
    Berza& operator++();
    Berza& operator--();
    Berza operator++(int);
    Berza operator--(int);
    Berza operator -();

    friend Berza operator +(const Berza &b, int broj);
    friend Berza operator -(const Berza &b, int broj);
    friend Berza operator +(int broj, const Berza &b);
    friend Berza operator -(int broj, const Berza &b);
    friend Berza operator -(const Berza &b1, const Berza &b2);

    Berza& operator +=(int broj) {
        return *this = *this + broj;
    }
    Berza& operator -=(int broj) {
        return *this = *this - broj;
    }
    Berza operator -=(const Berza &b) {
        return *this = *this - b;
    }

    friend bool operator ==(const Berza &b1, const Berza &b2);
    friend bool operator !=(const Berza &b1, const Berza &b2);
};

Berza& Berza::operator++()
{
    if (DajMaksimalnuCijenu()+1>max_cijena)
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(uk_cijene.begin(), uk_cijene.end(), uk_cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return *this;
}

Berza& Berza::operator--()
{
    if (DajMinimalnuCijenu()-1<min_cijena)
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(uk_cijene.begin(), uk_cijene.end(), uk_cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, -1));
    return *this;
}

Berza Berza::operator++(int)
{
    if (DajMaksimalnuCijenu()+1>max_cijena)
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    Berza kopija(min_cijena, max_cijena);
    kopija.uk_cijene.resize(uk_cijene.size());
    std::copy(uk_cijene.begin(), uk_cijene.end(), kopija.uk_cijene.begin());
    std::transform(uk_cijene.begin(), uk_cijene.end(), uk_cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 1));
    return kopija;
}

Berza Berza::operator--(int)
{
    if (DajMinimalnuCijenu()-1<min_cijena)
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    Berza kopija(min_cijena, max_cijena);
    kopija.uk_cijene.resize(uk_cijene.size());
    std::copy(uk_cijene.begin(), uk_cijene.end(), kopija.uk_cijene.begin());
    std::transform(uk_cijene.begin(), uk_cijene.end(), uk_cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, -1));
    return kopija;
}

Berza Berza::operator -()
{
    int zbir(min_cijena+max_cijena);
    Berza kopija(min_cijena, max_cijena);
    kopija.uk_cijene.resize(uk_cijene.size());
    std::transform(uk_cijene.begin(), uk_cijene.end(), kopija.uk_cijene.begin(), std::bind(std::minus<int>(), zbir, std::placeholders::_1));
    return kopija;
}

bool operator ==(const Berza &b1, const Berza &b2)
{
    if (b1.uk_cijene.size()!=b2.uk_cijene.size())
        return false;
    return std::equal(b1.uk_cijene.begin(), b1.uk_cijene.end(), b2.uk_cijene.begin());
}

bool operator !=(const Berza &b1, const Berza &b2)
{
    return !(b1==b2);
}

Berza operator +(const Berza &b, int broj)
{
    if (b.DajMaksimalnuCijenu()+broj>b.max_cijena)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    Berza kopija(b.min_cijena, b.max_cijena);
    kopija.uk_cijene.resize(b.uk_cijene.size());
    std::transform(b.uk_cijene.begin(), b.uk_cijene.end(), kopija.uk_cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, broj));
    return kopija;
}

Berza operator -(const Berza &b, int broj)
{
    if (b.DajMinimalnuCijenu()-broj<b.min_cijena)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    Berza kopija(b.min_cijena, b.max_cijena);
    kopija.uk_cijene.resize(b.uk_cijene.size());
    std::transform(b.uk_cijene.begin(), b.uk_cijene.end(), kopija.uk_cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, broj));
    return kopija;
}

Berza operator +(int broj, const Berza &b)
{
    return b + broj;
}

Berza operator -(int broj, const Berza &b)
{
    if (broj-b.DajMaksimalnuCijenu()<b.min_cijena || broj-b.DajMinimalnuCijenu()>b.max_cijena)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    Berza kopija(b.min_cijena, b.max_cijena);
    kopija.uk_cijene.resize(b.uk_cijene.size());
    std::transform(b.uk_cijene.begin(), b.uk_cijene.end(), kopija.uk_cijene.begin(), std::bind(std::minus<int>(), broj, std::placeholders::_1));
    return kopija;
}

Berza operator -(const Berza &b1, const Berza &b2)
{
    if (b1.DajBrojRegistriranihCijena()!=b2.DajBrojRegistriranihCijena() || b1.min_cijena!=b2.min_cijena || b1.max_cijena!=b2.max_cijena)
        throw std::domain_error("Nesaglasni operandi");
    Berza kopija(b1.min_cijena, b1.max_cijena);
    kopija.uk_cijene.resize(b1.uk_cijene.size());
    std::copy(b1.uk_cijene.begin(), b1.uk_cijene.end(), kopija.uk_cijene.begin());
    std::transform(kopija.uk_cijene.begin(), kopija.uk_cijene.end(), b2.uk_cijene.begin(), kopija.uk_cijene.begin(), std::minus<int>());
    if (*std::min_element(kopija.uk_cijene.begin(), kopija.uk_cijene.end())<kopija.min_cijena || *std::max_element(kopija.uk_cijene.begin(), kopija.uk_cijene.end())>kopija.max_cijena)
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return kopija;
}

int main ()
{
    Berza b(50000);
    b.RegistrirajCijenu(100).RegistrirajCijenu(200).RegistrirajCijenu(500).RegistrirajCijenu(10000);
    Berza b2(50000);
    b2.RegistrirajCijenu(101).RegistrirajCijenu(300).RegistrirajCijenu(500).RegistrirajCijenu(20000);
    b.Ispisi();
    (b2-b).Ispisi();
    return 0;
}
