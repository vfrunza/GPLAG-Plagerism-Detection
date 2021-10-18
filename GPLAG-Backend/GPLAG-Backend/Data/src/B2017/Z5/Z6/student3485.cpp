/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>

using std::bind;
using std::transform;
using std::count_if;
using std::min_element;
using std::max_element;
using std::sort;
using std::equal;

class Berza {
    std::vector<int> cijene;
    int max_cijena;
    int min_cijena;
public:
    explicit Berza(int);
    Berza(int, int);
    void RegistrirajCijenu(int);
    int DajBrojRegistriranihCijena() const { return cijene.size(); }
    void BrisiSve() { cijene.resize(0); }
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator !() const { return cijene.size() == 0; }
    int DajBrojCijenaVecihOd(int) const;
    void Ispisi() const;
    int operator [](int) const;
    friend Berza& operator ++(Berza&);
    friend Berza operator ++(Berza&, int);
    Berza& operator --();
    Berza operator --(int);
    Berza operator -();
    friend Berza operator +(const Berza&, const Berza&);
    friend Berza operator +(const Berza&, int);
    friend Berza operator +(int, const Berza&);
    friend Berza operator -(const Berza&, const Berza&);
    friend Berza operator -(const Berza&, int);
    friend Berza operator -(int, const Berza&);
    friend Berza& operator +=(Berza&, int);
    friend Berza& operator +=(Berza&, const Berza&);
    friend Berza& operator -=(Berza&, int);
    friend Berza& operator -=(Berza&, const Berza&);
    friend bool operator ==(const Berza&, const Berza&);
    friend bool operator !=(const Berza& b1, const Berza& b2) { return !(b1 == b2); }
};

Berza::Berza(int max_cijena) {
    this -> min_cijena = 0;
    if(max_cijena < 1)
        throw std::range_error("Ilegalne granicne cijene");
    this -> max_cijena = max_cijena;
}

Berza::Berza(int min_cijena, int max_cijena) {
    if(min_cijena < 1 || max_cijena < 1)
        throw std::range_error("Ilegalne granicne cijene");
    this -> max_cijena = max_cijena;
    this -> min_cijena = min_cijena;
}

void Berza::RegistrirajCijenu(int nova_cijena) {
    if(nova_cijena < min_cijena || nova_cijena > max_cijena)
        throw std::range_error("Ilegalna cijena");
    cijene.push_back(nova_cijena);
}

int Berza::DajMinimalnuCijenu() const {
    if(cijene.size() == 0)
        throw std::range_error("Nema registriranih cijena");
    return *(min_element(
        cijene.begin(), cijene.end(), std::less<int>()
        ));
}

int Berza::DajMaksimalnuCijenu() const {
    if(cijene.size() == 0)
        throw std::range_error("Nema registriranih cijena");
    return *(min_element(
        cijene.begin(), cijene.end(), std::greater<int>()
        ));
}

int Berza::DajBrojCijenaVecihOd(int cijena) const {
    if(cijene.size() == 0)
        throw std::range_error("Nema registriranih cijena");
    return count_if(
        cijene.begin(), cijene.end(),
        std::bind(std::greater<int>(), std::placeholders::_1, cijena)
        );
}

void Berza::Ispisi() const {
    std::vector<int> ispis(cijene);
    sort(
        ispis.begin(), ispis.end(), std::greater<int>()
        );
    for(int x : ispis)
        std::cout << std::fixed << std::setprecision(2) << x / 100. << "\n";
}

int Berza::operator [](int i) const {
    if(i < 1 || i > cijene.size())
        throw std::range_error("Neispravan indeks");
    return cijene[i - 1];
}

Berza& operator ++(Berza& berza) {
    transform(
        berza.cijene.begin(), berza.cijene.end(),
        berza.cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100)
        );
    if(count_if(
        berza.cijene.begin(), berza.cijene.end(),
        std::bind(std::greater<int>(), std::placeholders::_1, berza.max_cijena)
        ) > 0)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return berza;    
}

Berza operator ++(Berza& berza, int) {
    Berza nova_berza(berza);
    transform(
        berza.cijene.begin(), berza.cijene.end(),
        berza.cijene.begin(), std::bind(std::plus<int>(), 100, std::placeholders::_1)
        );
    if(count_if(
        berza.cijene.begin(), berza.cijene.end(),
        std::bind(std::greater<int>(), std::placeholders::_1, berza.max_cijena)
        ) > 0)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return nova_berza;  
}

Berza& Berza::operator --() {
    transform(
        cijene.begin(), cijene.end(),
        cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100)
        );
    if(count_if(
        cijene.begin(), cijene.end(), 
        std::bind(std::less<int>(), std::placeholders::_1, min_cijena)
        ) > 0)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        return *this;
}

Berza Berza::operator --(int) {
    Berza nova_berza(*this);
    transform(
        cijene.begin(), cijene.end(),
        cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100)
        );
    if(count_if(
        cijene.begin(), cijene.end(), 
        std::bind(std::less<int>(), std::placeholders::_1, min_cijena)
        ) > 0)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return nova_berza;
}

Berza Berza::operator -() {
    transform(
        cijene.begin(), cijene.end(),
        cijene.begin(), std::bind(std::minus<int>(), max_cijena + min_cijena, std::placeholders::_1)
        );
    return *this;
}

Berza operator +(const Berza& berza1, const Berza& berza2) {
    if(berza1.DajBrojRegistriranihCijena() != berza2.DajBrojRegistriranihCijena() || 
        berza1.max_cijena != berza2.max_cijena ||
        berza1.min_cijena != berza2.min_cijena)
            throw std::domain_error("Nesaglasni operandi");
    Berza nova_berza(berza1);
    nova_berza += berza2;
    return nova_berza;
}

Berza operator +(const Berza& berza, int iznos) {
    Berza nova_berza(berza);
    nova_berza += iznos;
    return nova_berza;
}

Berza operator +(int iznos, const Berza& berza) {
    Berza nova_berza(berza);
    nova_berza += iznos;
    return nova_berza;
}

Berza operator -(const Berza& berza1, const Berza& berza2) {
    if(berza1.DajBrojRegistriranihCijena() != berza2.DajBrojRegistriranihCijena() || 
        berza1.max_cijena != berza2.max_cijena ||
        berza1.min_cijena != berza2.min_cijena)
            throw std::domain_error("Nesaglasni operandi");
    Berza nova_berza(berza1);
    nova_berza -= berza2;
    return nova_berza;
}

Berza operator -(const Berza& berza, int iznos) {
    Berza nova_berza(berza);
    nova_berza -= iznos;
    return nova_berza;
}

Berza operator -(int iznos, const Berza& berza) {
    Berza nova_berza(berza);
    transform(
        berza.cijene.begin(), berza.cijene.end(),
        nova_berza.cijene.begin(), std::bind(std::minus<int>(), iznos, std::placeholders::_1)
        );
    if(count_if(
        nova_berza.cijene.begin(), nova_berza.cijene.end(), 
        std::bind(std::less<int>(), std::placeholders::_1, nova_berza.min_cijena)
        ) > 0)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    if(count_if(
        nova_berza.cijene.begin(), nova_berza.cijene.end(), 
        std::bind(std::greater<int>(), std::placeholders::_1, nova_berza.max_cijena)
        ) > 0)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return nova_berza;
}

Berza& operator +=(Berza& berza, int iznos) {
    transform(
        berza.cijene.begin(), berza.cijene.end(),
        berza.cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, iznos)
    );
    if(count_if(
        berza.cijene.begin(), berza.cijene.end(), 
        std::bind(std::greater<int>(), std::placeholders::_1, berza.max_cijena)
        ) > 0)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return berza;
}

Berza& operator +=(Berza& berza1, const Berza& berza2) {
    transform(
        berza1.cijene.begin(), berza1.cijene.end(),
        berza2.cijene.begin(), berza1.cijene.begin(), std::plus<int>()
    );
    if(count_if(
        berza1.cijene.begin(), berza1.cijene.end(), 
        std::bind(std::greater<int>(), std::placeholders::_1, berza1.max_cijena)
        ) > 0)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return berza1;
}

Berza& operator -=(Berza& berza, int iznos) {
    transform(
        berza.cijene.begin(), berza.cijene.end(),
        berza.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, iznos)
    );
    if(count_if(
        berza.cijene.begin(), berza.cijene.end(), 
        std::bind(std::less<int>(), std::placeholders::_1, berza.min_cijena)
        ) > 0)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return berza;
}

Berza& operator -=(Berza& berza1, const Berza& berza2) {
    transform(
        berza1.cijene.begin(), berza1.cijene.end(),
        berza2.cijene.begin(), berza1.cijene.begin(), std::minus<int>()
    );
    if(count_if(
        berza1.cijene.begin(), berza1.cijene.end(), 
        std::bind(std::less<int>(), std::placeholders::_1, berza1.min_cijena)
        ) > 0)
            throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return berza1;
}

bool operator ==(const Berza& berza1, const Berza& berza2) {
    return (berza1.cijene.size() == berza2.cijene.size() &&
                equal(
                    berza1.cijene.begin(), berza1.cijene.end(),
                    berza2.cijene.begin(), std::equal_to<int>()
                )
            );
}

int main ()
{
    try {
        Berza b(12000);
        b.RegistrirajCijenu(2000);
        b.RegistrirajCijenu(5000);
        b.RegistrirajCijenu(800);
        b.RegistrirajCijenu(1999);
        b.RegistrirajCijenu(270);
        b.RegistrirajCijenu(870);
        b.RegistrirajCijenu(1630);
        b.RegistrirajCijenu(3110);
        b.RegistrirajCijenu(9160);
        b.RegistrirajCijenu(1000);
        b.RegistrirajCijenu(1050);
        (--b)--;
        b.Ispisi();
        Berza b2(100, 22720);
        b2.RegistrirajCijenu(740);
        b2.RegistrirajCijenu(930);
        b2.RegistrirajCijenu(5430);
        b2.RegistrirajCijenu(1111); 
        Berza b3(80000);
        b3 = b2 += 600;
        b3++;
        b3--;
        b2 -= 150;
        b2 += 150;
        b3.Ispisi();
        b2.Ispisi();
        if(b2 == b3)
            std::cout << "OK\n";
        std::cout << b2.DajBrojRegistriranihCijena() << " " << b3.DajBrojRegistriranihCijena() << " ";
        std::cout << b2.DajMaksimalnuCijenu() << " " << b3.DajMaksimalnuCijenu() << " ";
        std::cout << b2.DajMinimalnuCijenu() << " " << b3.DajMinimalnuCijenu() << std::endl;
        (b3 - b2).Ispisi();
    }
    catch(std::domain_error err) {
        std::cout << err.what();
    }
    catch(std::range_error err) {
        std::cout << err.what();
    }
	return 0;
}
