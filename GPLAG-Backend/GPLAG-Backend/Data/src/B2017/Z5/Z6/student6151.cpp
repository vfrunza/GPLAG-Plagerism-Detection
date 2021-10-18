#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <functional>
#include <vector>


class Berza {
    int minimalna, maksimalna;
    std::vector<int> cijene;

    public:
    Berza (int x, int y) {
        if (x <= 0 || y <= 0) throw std::range_error("Ilegalne granicne cijene");
        else { minimalna = x; maksimalna = y; }
    }
    explicit Berza (int y) : minimalna(0) {
        if (y <= 0) throw std::range_error("Ilegalne granicne cijene");
        maksimalna = y;
    }
    void RegistrirajCijenu(int ncijena) {
        if (ncijena > maksimalna || ncijena < minimalna) throw std::range_error("Ilegalna cijena");
        else cijene.push_back(ncijena);
    }
    int DajBrojRegistriranihCijena() const { return cijene.size(); }
    void BrisiSve() { cijene.resize(0); }
    int DajMinimalnuCijenu() const {
        if (cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
        return *(std::min_element(cijene.begin(), cijene.end(), std::less<int>()));
    }
    int DajMaksimalnuCijenu() const {
        if (cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
        return *(std::max_element(cijene.begin(), cijene.end(), std::less<int>()));
    }
    bool operator !() const;
    int DajBrojCijenaVecihOd (int x) const {
        if (cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
        return std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, x));
    }
    void Ispisi() const {
        if (cijene.size() == 0) return;
        std::vector <double> pom(cijene.size());
        //std::copy(cijene.begin(), cijene.end(), std::back_inserter(pom.begin()));
        std::transform(cijene.begin(), cijene.end(), pom.begin(), std::bind(std::divides<double>(), std::placeholders::_1, 100.));
        std::sort(pom.begin(), pom.end(), std::greater<double>());
        std::copy(pom.begin(), pom.end(), std::ostream_iterator<double>(std::cout << std::setprecision(2) << std::fixed, "\n"));
    }
    int operator [](int n) const;
    Berza &operator += (int x);
    Berza &operator -= (int x);
    Berza &operator -= (const Berza &x);
    friend bool operator == (const Berza &x, const Berza &y);
    friend bool operator != (const Berza &x, const Berza &y);
    friend Berza operator - (const Berza &x, const Berza &y);
    friend Berza operator + (const Berza &x, int y);
    friend Berza operator - (const Berza &x, int y);
    friend Berza operator + (int x, const Berza &y);
    friend Berza operator - (int x, const Berza &y);
    friend Berza operator - (const Berza &x);
    friend Berza operator ++ (Berza &x, int);
    friend Berza operator -- (Berza &x, int);
    friend Berza &operator ++ (Berza &x);
    friend Berza &operator -- (Berza &x);
};
    bool Berza::operator !()  const{
        if (cijene.size() == 0) return true;
        else return false;
    }
    int Berza::operator [](int n) const {
        if (n > cijene.size() || n < 0) throw std::range_error("Neispravan indeks");
        return cijene[n - 1];
    }
    Berza &Berza::operator += (int x) {
        *this = *this + x;
        return *this;
    }
    Berza &Berza::operator -= (int x) {
        *this = *this - x;
        return *this;
    }
    Berza &Berza::operator -= (const Berza &x) {
        Berza pom = *this;
        if (x.cijene.size() == cijene.size()) {
            std::transform(pom.cijene.begin(), pom.cijene.end(), x.cijene.begin(), pom.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, std::placeholders::_2));
            int h = std::count_if(pom.cijene.begin(), pom.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, this->maksimalna));
            int j = std::count_if(pom.cijene.begin(), pom.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, this->minimalna));
            if (h > 0 || j > 0) throw std::domain_error ("Prekoracen dozvoljeni opseg cijena");
            else *this = pom;
        }   
        return *this;
    }
    Berza operator - (const Berza &x) {
        Berza pom = x;
        std::transform(pom.cijene.begin(), pom.cijene.end(), pom.cijene.begin(), std::bind(std::minus<int>(), pom.maksimalna + pom.minimalna, std::placeholders::_1));
        return pom;
    }
    Berza operator + (const Berza &x, int y) {
        Berza pom = x;
        int h = std::count_if(x.cijene.begin(), x.cijene.end(), std::bind(std::greater<int>(), std::bind(std::plus<int>(), std::placeholders::_1 , y), x.maksimalna));
        int j = std::count_if(x.cijene.begin(), x.cijene.end(), std::bind(std::less<int>(), std::bind(std::plus<int>(), std::placeholders::_1 , y), x.minimalna));
        if (h > 0 || j > 0) throw std::domain_error ("Prekoracen dozvoljeni opseg cijena");
        std::transform(pom.cijene.begin(), pom.cijene.end(), pom.cijene.begin(), std::bind(std::plus<int>(), std::placeholders::_1, y));
        return pom;
    }
    Berza operator - (const Berza &x, int y) {
        Berza pom = x;
        int h = std::count_if(x.cijene.begin(), x.cijene.end(), std::bind(std::greater<int>(), std::bind(std::minus<int>(), std::placeholders::_1 , y), x.maksimalna));
        int j = std::count_if(x.cijene.begin(), x.cijene.end(), std::bind(std::less<int>(), std::bind(std::minus<int>(), std::placeholders::_1 , y), x.minimalna));
        if (h > 0 || j > 0) throw std::domain_error ("Prekoracen dozvoljeni opseg cijena");
        std::transform(pom.cijene.begin(), pom.cijene.end(), pom.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
        return pom;

    }
    Berza operator + (int x, const Berza &y) {
        return y + x;

    }
    Berza operator - (int x, const Berza &y) {
        Berza pom = y;
        int h = std::count_if(y.cijene.begin(), y.cijene.end(), std::bind(std::greater<int>(), std::bind(std::minus<int>(), x, std::placeholders::_1), y.maksimalna));
        int j = std::count_if(y.cijene.begin(), y.cijene.end(), std::bind(std::less<int>(), std::bind(std::minus<int>(), x, std::placeholders::_1), y.minimalna));
        if (h > 0 || j > 0) throw std::domain_error ("Prekoracen dozvoljeni opseg cijena");
        std::transform(pom.cijene.begin(), pom.cijene.end(), pom.cijene.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
        return pom;
    }
    Berza operator - (const Berza &x, const Berza &y) {
        if (x.cijene.size() == y.cijene.size() || x.maksimalna == y.maksimalna || y.minimalna == y.minimalna)
            throw std::domain_error("Nesaglasni operandi");
            
            auto pom = x;
            pom -= y;
            return pom;
    }
    bool operator == (const Berza &x, const Berza &y) {
        if (x.cijene.size() != y.cijene.size()) return false;
        bool brojac = std::equal(x.cijene.begin(), x.cijene.end(), y.cijene.begin(), std::bind(std::equal_to<int>(), std::placeholders::_1, std::placeholders::_2));
        if (brojac) return true;
        else return false;
    }
    bool operator != (const Berza &x, const Berza &y) {
        if (x == y) return false;
        else return true;
    }
    Berza &operator ++(Berza &x) {
        try {
            x = x + 100.;
            return x;
        }
        catch(std::domain_error) {
            throw std::range_error ("Prekoracen dozvoljeni opseg cijena");
        }
    }
    Berza &operator --(Berza &x) {
        try {
            x = x - 100.;
            return x;
        }
        catch(std::domain_error) {
            throw std::range_error ("Prekoracen dozvoljeni opseg cijena");
        }
    }
    Berza operator ++(Berza &x, int) {
        Berza pomocni = x;
        ++x;
        return pomocni;
    }
    Berza operator --(Berza &x, int) {
        Berza pomocni = x;
        --x;
        return pomocni;
    }
    
int main() {
    try {
    const Berza b(260);
    //std::cout << b[3];
    Berza c(260);
    c.RegistrirajCijenu(3);
    c.RegistrirajCijenu(35);
    std::cout << c[2];
    
    //b += c;
    //b.Ispisi();
    /*c.RegistrirajCijenu(25.);
    auto l = c - 5;
    auto m = b - l;
    m++.Ispisi();
    m.Ispisi();*/
    return 0;
    }
    catch (std::range_error Izuzetak) { std::cout << Izuzetak.what();}
}

