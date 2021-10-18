/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <iomanip>
#include <functional>
#include <iterator>
#include <stdexcept>
#include <algorithm>

class Berza
{
    std::vector<int> cijene_dionica;
    int min_cijena, max_cijena;
    
    public:
    
    Berza(int min_cijena, int max_cijena)
    {
        if(min_cijena < 0 || max_cijena < 0 || max_cijena < min_cijena) throw std::range_error("Ilegalne granice cijene");
        Berza::min_cijena = 0;
        Berza::max_cijena = max_cijena;
    }
    
    explicit Berza(int max_cijena)
    {
        if(max_cijena < 0) throw std::range_error("Ilegalne granice cijene");
        Berza::min_cijena = 0;
        Berza::max_cijena = max_cijena;
    }
    
    void RegistrirajCijenu(int cijena)
    {
        if(cijena < min_cijena || cijena > max_cijena) throw std:: range_error("Ilegalna cijena");
        cijene_dionica.push_back(cijena);
    }
    
    int DajBrojRegistriranihCijena() const
    {
        return cijene_dionica.size();
    }
    
    void BrisiSve()
    {
        cijene_dionica.resize(0);
    }
    
    int DajMinimalnuCijenu();
    int DajMaksimalnuCijenu();
    bool operator ! ();
    int DajBrojCijenaVecihOd(int cijena);
    void Ispisi() const;
    int operator [](int index) const
    {
        if(index < 1 || index > cijene_dionica.size()) throw std::range_error("Neispravan index");
        return cijene_dionica[index - 1];
    }
    
    Berza &operator ++ ();
    Berza operator ++ (int);
    Berza &operator -- ();
    Berza operator -- (int);
    Berza operator - () const;
    Berza &operator += (Berza b1);
    Berza &operator -= (Berza b2);
    
    friend Berza operator + (Berza b1, int broj);
    friend Berza operator + (int broj, Berza b1);
    friend Berza operator - (Berza b1, int broj);
    friend Berza operator - (int broj, Berza b1);
    
    friend Berza operator - (Berza b1, Berza b2);
    friend Berza operator + (Berza b1, Berza b2);
    friend bool operator == (const Berza &b1, const Berza &b2);
    friend bool operator != (const Berza &b1, const Berza &b2);
};

int Berza::DajMinimalnuCijenu()
{
    if(cijene_dionica.size() == 0) throw std::range_error("Nema registriranih cijena");
    return *std::min_element(cijene_dionica.begin(), cijene_dionica.end());
}

int Berza::DajMaksimalnuCijenu()
{
    if(cijene_dionica.size() == 0) throw std::range_error("Nema registriranih cijena");
    return *std::max_element(cijene_dionica.begin(), cijene_dionica.end());
}

bool Berza::operator ! () 
{
    if(cijene_dionica.size() == 0) return true;
    return false;
}

int Berza::DajBrojCijenaVecihOd (int cijena)
{
    if(cijene_dionica.size() == 0) throw std::range_error("Nema registriranih cijena");
    return std::count_if(cijene_dionica.begin(), cijene_dionica.end(), std::bind(std::greater<int>(), std::placeholders::_1, cijena));
}

void Berza::Ispisi() const
{
    std::vector<double> c_cijene(cijene_dionica.size());
    std::copy(cijene_dionica.begin(), cijene_dionica.end(), c_cijene.begin());
    std::sort(c_cijene.begin(), c_cijene.end(), std::greater<double>());
    std::transform(c_cijene.begin(), c_cijene.end(), c_cijene.begin(), std::bind(std::multiplies<double>(), 1./100, std::placeholders::_1));
    std::copy(c_cijene.begin(), c_cijene.end(), std::ostream_iterator<double>(std::cout<< std::fixed << std::setprecision(2), "\n"));
}

Berza &Berza::operator ++ ()
{
    std::transform(cijene_dionica.begin(), cijene_dionica.end(), cijene_dionica.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    if(this -> DajMaksimalnuCijenu() > max_cijena || this -> DajMinimalnuCijenu() < min_cijena) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}

Berza Berza::operator ++ (int)
{
    Berza pomocni(min_cijena, max_cijena);
    pomocni.cijene_dionica = cijene_dionica;
    std::transform(cijene_dionica.begin(), cijene_dionica.end(), cijene_dionica.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    if(this -> DajMaksimalnuCijenu() > max_cijena || this -> DajMinimalnuCijenu() < min_cijena) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return pomocni;
}

Berza &Berza::operator -- () 
{
    std::transform(cijene_dionica.begin(), cijene_dionica.end(), cijene_dionica.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
    if(this -> DajMaksimalnuCijenu() > max_cijena || this -> DajMinimalnuCijenu() < min_cijena) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}

Berza Berza::operator -- (int)
{
    Berza pomocni (min_cijena, max_cijena);
    pomocni.cijene_dionica = cijene_dionica;
    std::transform(cijene_dionica.begin(), cijene_dionica.end(), cijene_dionica.begin(), std::bind(std::minus<int>(), std::placeholders::_1,100));
    if(this -> DajMaksimalnuCijenu() > max_cijena || this -> DajMinimalnuCijenu() < min_cijena) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    return pomocni;
}

Berza Berza::operator - () const
{
    Berza pomocni(min_cijena, max_cijena);
    pomocni.cijene_dionica = cijene_dionica;
    std::transform(cijene_dionica.begin(), cijene_dionica.end(), pomocni.cijene_dionica.begin(), std::bind(std::minus<int>(), std::placeholders::_1, min_cijena + max_cijena));
    return pomocni;
}

bool operator ==(const Berza &b1, const Berza &b2)
{
    return b1.cijene_dionica.size() == b2.cijene_dionica.size() && b1.cijene_dionica == b2.cijene_dionica;
}

bool operator != (const Berza &b1, const Berza &b2)
{
    return !(b1 == b2);
}

Berza &Berza::operator -= (Berza b1)
{
    if(min_cijena != b1.min_cijena || max_cijena != b1.max_cijena || cijene_dionica.size() != b1.cijene_dionica.size()) throw std::domain_error("Nesaglasni operandi");
    
    std::transform(cijene_dionica.begin(), cijene_dionica.end(), b1.cijene_dionica.begin(), cijene_dionica.begin(), std::minus<int>());
    if(this -> DajMinimalnuCijenu() < min_cijena || this -> DajMaksimalnuCijenu() > max_cijena) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}

Berza &Berza::operator += (Berza b1)
{
    if(min_cijena != b1.min_cijena || max_cijena != b1.max_cijena || cijene_dionica.size() != b1.cijene_dionica.size()) throw std::domain_error("Nesaglasni operndi");
    
    std::transform(cijene_dionica.begin(), cijene_dionica.end(), b1.cijene_dionica.begin(), cijene_dionica.begin(), std::plus<int>());
    if(this -> DajMinimalnuCijenu() < min_cijena || this -> DajMaksimalnuCijenu() > max_cijena) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return *this;
}

Berza operator + (Berza b1, Berza b2)
{
    if(b1.min_cijena != b2.min_cijena || b1.max_cijena != b2.max_cijena || b1.cijene_dionica.size() != b2.cijene_dionica.size()) throw std::domain_error("Nesaglasni operandi");
    Berza pomocni(b1.min_cijena, b1.max_cijena);
    pomocni.cijene_dionica = b1.cijene_dionica;
    
    std::transform(b1.cijene_dionica.begin(), b1.cijene_dionica.end(), b2.cijene_dionica.begin(), pomocni.cijene_dionica.begin(), std::plus<int>());
    if(pomocni.DajMaksimalnuCijenu() > b1.max_cijena || b1.max_cijena || pomocni.DajMinimalnuCijenu() < b1.min_cijena) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return pomocni;
}

Berza operator - (Berza b1, Berza b2)
{
    Berza pomocni(b1.min_cijena, b1.max_cijena);
    pomocni.cijene_dionica = b1.cijene_dionica;
    
    if(b1.min_cijena != b2.min_cijena || b1.max_cijena != b2.max_cijena || b1.cijene_dionica.size() != b2.cijene_dionica.size()) throw std::domain_error("Nesaglasni operandi");
    
    std::transform(b1.cijene_dionica.begin(), b1.cijene_dionica.end(), b2.cijene_dionica.begin(), pomocni.cijene_dionica.begin(), std::minus<int> ());
    if(pomocni.DajMinimalnuCijenu() < b1.min_cijena || pomocni.DajMaksimalnuCijenu() > b1.max_cijena) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return pomocni;
}

Berza operator - (int broj, Berza b1)
{
    Berza pomocni(b1.min_cijena, b1.max_cijena);
    pomocni.cijene_dionica = b1.cijene_dionica;
    
    std::transform(b1.cijene_dionica.begin(), b1.cijene_dionica.end(), pomocni.cijene_dionica.begin(), std::bind(std::minus<int>(), std::placeholders::_1, broj));
    if(pomocni.DajMinimalnuCijenu() < b1.min_cijena || pomocni.DajMaksimalnuCijenu() > b1.max_cijena) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return pomocni;
}

Berza operator - (Berza b1, int broj)
{
    Berza pomocni(b1.min_cijena, b1.max_cijena);
    pomocni.cijene_dionica = b1.cijene_dionica;
    
    std::transform(b1.cijene_dionica.begin(), b1.cijene_dionica.end(), pomocni.cijene_dionica.begin(), std::bind(std::minus<int>(), std::placeholders::_1, broj));
    if(pomocni.DajMinimalnuCijenu() < b1.min_cijena || pomocni.DajMaksimalnuCijenu() > b1.max_cijena ) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return pomocni;
}

Berza operator + (int broj, Berza b1)
{
    return b1 + broj;
}

Berza operator + (Berza b1, int broj)
{
    Berza pomocni(b1.min_cijena, b1.max_cijena);
    pomocni.cijene_dionica = b1.cijene_dionica;
    
    std::transform(b1.cijene_dionica.begin(), b1.cijene_dionica.end(), pomocni.cijene_dionica.begin(), std::bind(std::plus<int>(), std::placeholders::_1, broj));
    if(pomocni.DajMaksimalnuCijenu() > b1.max_cijena || pomocni.DajMinimalnuCijenu() < b1.min_cijena) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return pomocni;
}

int main ()
{
    //std::cout << "Radi daaa!!!!";
	
	Berza b (1, 10000);
	b.RegistrirajCijenu(3000);
	b.RegistrirajCijenu(4000);
	b.RegistrirajCijenu(8000);
	b.RegistrirajCijenu(6000);
	b++++;
	b.Ispisi();
	
	return 0;
}
