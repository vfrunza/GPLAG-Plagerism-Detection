/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>

class Berza
{
    int min, max;
    std::vector<int> cijene;
    void Sortiraj() {
        std::sort(cijene.begin(), cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, std::placeholders::_2));
    }
public:
    explicit Berza(int minimalno) {
        if(minimalno < 0) throw std::range_error("Ilegalne granicne cijene");
        min = minimalno;
    };
    Berza(int minimalno, int maksimalno) {
        if(minimalno < 0) throw std::range_error("Ilegalne granicne cijene");
        if(minimalno > maksimalno) throw std::range_error("Ilegalne granicne cijene");
        min = minimalno;
        max = maksimalno;
    }
    void RegistrirajCijenu(int kolicina) {
        if(kolicina < min || kolicina > max) throw std::range_error("Ilegalna cijena");
        cijene.emplace_back(kolicina);
        Sortiraj();
    }
    int DajBrojRegistriranihCijena() const {
        return cijene.size();
    }
    void BrisiSve() {
        cijene.resize(0);
    }
    int DajMinimalnuCijenu() const {
        if(cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
        return *max_element(cijene.begin(), cijene.end(), [=](int a, int b) {
            return a<b;
        });
    }
    int DajMaksimalnuCijenu() const {
        if(cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
        return *max_element(cijene.begin(), cijene.end(), [=](int a, int b) {
            return a>b;
        });
    }
    bool operator !() const {
        if(cijene.size() == 0) return true;
        return false;
    }
    int DajBrojCijenaVecihOd(int vrijednost) const {
        if(cijene.size() == 0) throw std::range_error("Nema registriranih cijena");
        return std::count_if(cijene.begin(), cijene.end(), std::bind(std::equal_to<int>(), 1, std::placeholders::_1));
    }
    void Ispisi() const {
        for(int i(0); i<cijene.size(); ++i) {
            std::cout<<std::fixed<<std::setprecision(2)<<cijene[i] / 100.<<std::endl;
        }
    }
    int operator [](int indeks) const {
        if(indeks <= 0 || indeks > cijene.size()) throw std::domain_error("Neispravan indeks");
        return cijene[indeks + 1];
    }
    void operator++() {
        std::for_each(cijene.begin(), cijene.end(), std::bind(std::plus<int>(), 1, std::placeholders::_1));
    }
    Berza operator++(int) {
        Berza temp = *this;
        std::for_each(cijene.begin(), cijene.end(), std::bind(std::plus<int>(), 1, std::placeholders::_1));
        return temp;
    }
    void operator--() {
        std::for_each(cijene.begin(), cijene.end(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
    }
    Berza operator--(int) {
        Berza temp = *this;
        std::for_each(cijene.begin(), cijene.end(), std::bind(std::minus<int>(), std::placeholders::_1, 1));
        return temp;
    }


};


int main ()
{

    return 0;
}
