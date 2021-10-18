/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iterator>
#include <iomanip>

class Berza
{
    std::vector<int> tekuce_cijene;
    int min_cijena, max_cijena;
public:
    Berza(int min_cijena, int max_cijena) {
        if (min_cijena < 0 || max_cijena < 0)
            throw std::range_error ("Ilegalne granicne cijene");
        Berza::min_cijena = min_cijena;
        Berza::max_cijena = max_cijena;
    }
    explicit Berza(int max_cijena){
        if(max_cijena < 0) 
            throw std::range_error ("Ilegalne granicne cijene");
        Berza::max_cijena = max_cijena;
        min_cijena = 0;
    }
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena() const {
        return tekuce_cijene.size();
    }
    void BrisiSve(){
        tekuce_cijene.resize(0);
    }
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator !();
    int DajBrojCijenaVecihOd(int x) const;
    void Ispisi() const;
    int operator [](int i){
        if(i<1 || i> tekuce_cijene.size())
            throw std::range_error ("Neispravan indeks");
        return tekuce_cijene[i-1];
    }
    Berza& operator ++ ();
    Berza operator ++ (int);
    Berza& operator -- ();
    Berza operator -- (int);
    Berza operator + (int y);
    Berza operator - (int y);
    friend Berza operator + (const Berza &b1, const Berza &b2);
    friend Berza operator - (const Berza &b1, const Berza &b2);
    Berza& operator += (int y);
    Berza& operator -= (int y);
    Berza& operator += (const Berza &b);
    Berza& operator -= (const Berza &b);
    friend bool operator == (const Berza &b1, const Berza &b2);
    friend bool operator != (const Berza &b1, const Berza &b2);

};


int main ()
{
    Berza b1(150,10000), b2(1500);
    b1.RegistrirajCijenu(257);
    b1.RegistrirajCijenu(265);
    b2.RegistrirajCijenu(220);
    b2.RegistrirajCijenu(275);
    std::cout << b1.DajBrojRegistriranihCijena() << std::endl;
    std::cout << b1.DajMaksimalnuCijenu() << std::endl;
    std::cout << b1.DajMinimalnuCijenu() << std::endl;
    std::cout << b2.DajBrojCijenaVecihOd(50) << std::endl;
    std::cout << !b2 << std::endl;
    b1++;
    b1--;
    b1.Ispisi();
    --b2;
    b2.Ispisi();
    //(b1+b2).Ispisi(); Nesaglasni operandi 
    //b1+=b2;
    b1.Ispisi();
    b1.BrisiSve();
    b2.BrisiSve();
    b1.Ispisi(); 
    b2.Ispisi();
    return 0;
}

//Implementacija
void Berza::RegistrirajCijenu(int cijena){
    if(cijena < min_cijena || cijena > max_cijena) 
        throw std::range_error ("Ilegalna cijena");
    tekuce_cijene.push_back(cijena);
}
int Berza::DajMinimalnuCijenu() const{
    if(tekuce_cijene.size() == 0) 
        throw std::range_error ("Nema registriranih cijena");
    auto min(std::min_element(tekuce_cijene.begin(), tekuce_cijene.end(), 
        [](int a, int b){
            return a < b;
        }));
    return *min;
}
int Berza::DajMaksimalnuCijenu() const{
    if(tekuce_cijene.size() == 0) 
        throw std::range_error ("Nema registriranih cijena");
    auto maks(std::max_element(tekuce_cijene.begin(), tekuce_cijene.end(), 
        [](int a, int b){
            return a < b;
        }));
    return *maks;
}

bool Berza::operator !(){
    return tekuce_cijene.size() == 0;
}

int Berza::DajBrojCijenaVecihOd(int x) const{
    if(tekuce_cijene.size() == 0) 
        throw std::range_error ("Nema registriranih cijena");
    int br(std::count_if(tekuce_cijene.begin(), tekuce_cijene.end(), 
        std::bind(std::greater<int>(), std::placeholders::_1, x)));
    return br;
}

void Berza::Ispisi() const{
    std::vector<int> tmp(tekuce_cijene);
    std::sort(tmp.begin(), tmp.end(), std::greater<int>());
    std::cout.precision(2);
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), std::bind(std::divides<double>(), std::placeholders::_1, double(100)));
    std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<double>(std::cout<<std::fixed<<std::setprecision(2) , "\n"));
}

Berza& Berza::operator ++(){
    int br(std::count_if(tekuce_cijene.begin(), tekuce_cijene.end(), 
        std::bind(std::greater_equal<int>(), std::placeholders::_1, max_cijena-100)));
    if(br != 0)
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(tekuce_cijene.begin(), tekuce_cijene.end(), tekuce_cijene.begin(),
    std::bind(std::plus<int>(), std::placeholders::_1, 100));
    return *this;
}

Berza Berza::operator ++(int){
    Berza pomocna(*this);
    ++(*this);
    return pomocna;
}

Berza& Berza::operator --(){
    int br(std::count_if(tekuce_cijene.begin(), tekuce_cijene.end(), 
        std::bind(std::less_equal<int>(), std::placeholders::_1, min_cijena+100)));
    if(br != 0)
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(tekuce_cijene.begin(), tekuce_cijene.end(), tekuce_cijene.begin(),
    std::bind(std::minus<int>(), std::placeholders::_1, 100));
    return *this;
}

Berza Berza::operator --(int){
   Berza pomocna(*this);
    --(*this);
    return pomocna;
}

Berza Berza::operator + (int y){
    Berza b(*this);
    b+=y;
    return b;
}
Berza Berza::operator - (int y){
    Berza b(*this);
    b-=y;
    return b;
}
Berza operator + (const Berza &b1, const Berza &b2){
    if(b1.tekuce_cijene.size() != b2.tekuce_cijene.size() || 
        b1.max_cijena != b2.max_cijena || b1.min_cijena != b2.min_cijena)
            throw std::domain_error ("Nesaglasni operandi");
    Berza b(b1);
    b+=b2;
    return b;
}
Berza operator - (const Berza &b1, const Berza &b2){
    if(b1.tekuce_cijene.size() != b2.tekuce_cijene.size() || 
        b1.max_cijena != b2.max_cijena || b1.min_cijena != b2.min_cijena)
            throw std::domain_error ("Nesaglasni operandi");
    Berza b(b1);
    b-=b2;
    return b;
}

Berza& Berza::operator += (int y){
    int br(std::count_if(tekuce_cijene.begin(), tekuce_cijene.end(), 
        std::bind(std::less_equal<int>(), std::placeholders::_1, min_cijena+y)));
    if(br != 0)
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(tekuce_cijene.begin(), tekuce_cijene.end(), tekuce_cijene.begin(),
    std::bind(std::minus<int>(), std::placeholders::_1, y));
    return *this;
}
Berza& Berza::operator -= (int y){
    int br(std::count_if(tekuce_cijene.begin(), tekuce_cijene.end(), 
        std::bind(std::less_equal<int>(), std::placeholders::_1, min_cijena+y)));
    if(br != 0)
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    std::transform(tekuce_cijene.begin(), tekuce_cijene.end(), tekuce_cijene.begin(),
    std::bind(std::minus<int>(), std::placeholders::_1, y));
    return *this;
}
Berza& Berza::operator += (const Berza &b){
    Berza tmp(*this);
    if(tekuce_cijene.size() != b.tekuce_cijene.size() || 
        max_cijena != b.max_cijena || min_cijena != b.min_cijena)
            throw std::domain_error ("Nesaglasni operandi");
    std::transform(tekuce_cijene.begin(), tekuce_cijene.end(), b.tekuce_cijene.begin(), 
    tekuce_cijene.begin(), std::plus<int>());
    int br(std::count_if(tekuce_cijene.begin(), tekuce_cijene.end(), 
        std::bind(std::greater_equal<int>(), std::placeholders::_1, max_cijena)));
    if(br != 0){
        *this = tmp;
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    return *this;
}
Berza& Berza::operator -= (const Berza &b){
    Berza tmp(*this);
    if(tekuce_cijene.size() != b.tekuce_cijene.size() || 
        max_cijena != b.max_cijena || min_cijena != b.min_cijena)
            throw std::domain_error ("Nesaglasni operandi");
    std::transform(tekuce_cijene.begin(), tekuce_cijene.end(), b.tekuce_cijene.begin(), 
    tekuce_cijene.begin(), std::minus<int>());
    int br(std::count_if(tekuce_cijene.begin(), tekuce_cijene.end(), 
        std::bind(std::less_equal<int>(), std::placeholders::_1, min_cijena)));
    if(br != 0){
        *this = tmp;
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
    return *this;
}

bool operator == (const Berza &b1, const Berza &b2){
    return b1.tekuce_cijene.size() == b2.tekuce_cijene.size() &&
    std::equal(b1.tekuce_cijene.begin(), b1.tekuce_cijene.end(), b2.tekuce_cijene.begin());
}

bool operator != (const Berza &b1, const Berza &b2){
    return !(b1 == b2);
}


