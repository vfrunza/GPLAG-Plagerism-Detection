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
    int max_cijena, min_cijena;
    std::vector<int> cijene;
public:
    Berza (int min_cijena, int max_cijena);
    explicit Berza (int max_cijena);
    void RegistrirajCijenu (int cijena);
    int DajBrojRegistriranihCijena () const {
        return cijene.size();
    }
    void BrisiSve () {
        cijene.resize(0);
    }

    int DajMinimalnuCijenu () const;
    int DajMaksimalnuCijenu () const;

    friend bool operator !(const Berza &b);

    int DajBrojCijenaVecihOd (int cijena) const;

    void Ispisi () const ;

    int operator [] (int indeks);

    friend Berza &operator ++ (Berza &b);                                       //prefiksni
    friend Berza operator ++ (Berza &b, int);                                   //postfiksni
    friend Berza &operator -- (Berza &b);                                       //prefiksni
    friend Berza operator -- (Berza &b, int);                                   //postfiksni

    friend Berza operator + (const Berza &b, int y);
    friend  Berza operator +(int y, const Berza &b);
    friend Berza operator - (const Berza &b, int y);
    friend Berza operator - (const Berza &b);
    friend Berza &operator +=(Berza &b, int y);
    friend Berza &operator -=(Berza &b, int y);
    friend bool operator == (const Berza &b1, const Berza &b2);
    friend bool operator != (const Berza &b1, const Berza &b2);
};

Berza operator - (const Berza &b) {
    Berza pomocna(b);
    int zbir=b.max_cijena+b.min_cijena;
    std::transform(pomocna.cijene.begin(), pomocna.cijene.end(), pomocna.cijene.begin(),
        std::bind(zbir, std::minus<int>(),std::placeholders::_1, ));
    return pomocna;
}

Berza &operator -=(Berza &b, int y)
{
    b=b-y;
    return b;
}

Berza &operator +=(Berza &b, int y)
{
    b=b+y;
    return b;
}

Berza operator + (const Berza &b, int y)
{
    Berza rezultat(b.DajMinimalnuCijenu(), b.DajMaksimalnuCijenu());
    rezultat.cijene.resize(b.DajBrojRegistriranihCijena());
    std::copy(b.cijene.begin(), b.cijene.end(), rezultat.cijene.begin());
    std::transform(rezultat.cijene.begin(), rezultat.cijene.end(), rezultat.cijene.begin(),
                   std::bind(std::plus<int>(), std::placeholders::_1,y));
    auto tmp1=std::find_if(rezultat.cijene.begin(), rezultat.cijene.end(),
                           std::bind(std::greater<int>(), std::placeholders::_1, b.DajMaksimalnuCijenu()));
    if(tmp1!=rezultat.cijene.end())
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    auto tmp2=std::find_if(rezultat.cijene.begin(), rezultat.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, b.min_cijena));
    if(tmp2!=rezultat.cijene.end())
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return rezultat;
}

Berza operator +(int y, const Berza &b)
{
    auto rezultat=b+y;
    return rezultat;
}

Berza operator - (const Berza &b, int y)
{
    Berza rezultat(b.DajMinimalnuCijenu(), b.DajMaksimalnuCijenu());
    rezultat.cijene.resize(b.DajBrojRegistriranihCijena());
    std::copy(b.cijene.begin(), b.cijene.end(), rezultat.cijene.begin());
    std::transform(rezultat.cijene.begin(), rezultat.cijene.end(), rezultat.cijene.begin(),
                   std::bind(std::minus<int>(), std::placeholders::_1,y));
    auto tmp1=std::find_if(rezultat.cijene.begin(), rezultat.cijene.end(), 
        std::bind(std::greater<int>(), std::placeholders::_1, b.DajMaksimalnuCijenu()));
    if(tmp1!=rezultat.cijene.end())
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    auto tmp2=std::find_if(rezultat.cijene.begin(), rezultat.cijene.end(), 
        std::bind(std::less<int>(), std::placeholders::_1, b.min_cijena));
    if(tmp2!=rezultat.cijene.end())
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return rezultat;
}

int Berza::operator [] (int indeks)
{
    if(indeks<1 || indeks>DajBrojRegistriranihCijena()-1)
        throw std::range_error("Neispravan indeks");
    auto it=cijene.begin();
    std::advance(it, indeks-1);
    int rezultat(*it);
    return rezultat;
}

bool operator == (const Berza &b1, const Berza &b2)
{
    if(b1.DajBrojRegistriranihCijena()!=b2.DajBrojRegistriranihCijena()
            || b1.DajMaksimalnuCijenu()!=b2.DajMaksimalnuCijenu() || 
                b1.DajMinimalnuCijenu()!=b2.DajMinimalnuCijenu()) return false;
    else if(!std::equal(b1.cijene.begin(), b1.cijene.end(), b2.cijene.begin())) return false;
    return true;
}

bool operator != (const Berza &b1, const Berza &b2)
{
    return !(b1==b2);
}

Berza &operator ++ (Berza &b)
{
    Berza pomocna(b);
    std::transform(pomocna.cijene.begin(), pomocna.cijene.end(), pomocna.cijene.begin(),
                   std::bind(std::plus<int> (), std::placeholders::_1, 100));
    if(pomocna.DajBrojCijenaVecihOd(b.max_cijena)!=0)
        throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    b.cijene=pomocna.cijene;
    return b;
}

Berza operator ++ (Berza &b, int)
{
    Berza pomocna(b);
    ++b;
    return pomocna;
}

Berza &operator -- (Berza &b)
{
    Berza pomocna(b);
    std::transform(pomocna.cijene.begin(), pomocna.cijene.end(), pomocna.cijene.begin(),
                   std::bind(std::minus<int> (), std::placeholders::_1, 100));
     auto tmp2=std::find_if(pomocna.cijene.begin(), pomocna.cijene.end(), 
        std::bind(std::less<int>(), std::placeholders::_1, b.min_cijena));
    if(tmp2!=pomocna.cijene.end())
        throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    b.cijene=pomocna.cijene;
    return b;
}

Berza operator -- (Berza &b, int)
{
    Berza pomocna(b);
    --b;
    return pomocna;
}

void Berza::Ispisi () const
{
    Berza pomocna(*this);
    std::vector<int> novi_v;
    std::sort(pomocna.cijene.begin(), pomocna.cijene.end(), std::greater<int>()); //nije dobro
    /*std::for_each(pomocna.cijene.begin(), pomocna.cijene.end(), [] (int cijena) {
        cijena/=1000;
    });*/
    //std::transform(pomocna.cijene.begin(), pomocna.cijene.end(), novi_v, std::bind1st(std::divides<double>(), 1));
    std::for_each(pomocna.cijene.begin(), pomocna.cijene.end(), [] (int cijena) {
        std::cout<<std::fixed<<std::setprecision(2)<<double(cijena/100)<<std::endl;
    });
    //std::copy(pomocna.cijene.begin(), pomocna.cijene.end(), std::ostream_iterator<int> (std::cout) );

}

int Berza::DajBrojCijenaVecihOd (int cijena) const
{
    if(DajBrojRegistriranihCijena()==0)
        throw std::range_error("Nema registriranih cijena");
    int rezultat=std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int> (), std::placeholders::_1, cijena));
    return rezultat;
}

bool operator !(const Berza &b)
{
    return b.DajBrojRegistriranihCijena()==0;
}

int Berza::DajMinimalnuCijenu () const
{
    if(cijene.size()==0)
        throw std::range_error("Nema registriranih cijena");
    return *(std::min_element(cijene.begin(), cijene.end()));
}

int Berza::DajMaksimalnuCijenu () const
{
    if(cijene.size()==0)
        throw std::range_error("Nema registriranih cijena");
    return *(std::max_element(cijene.begin(), cijene.end()));
}

void Berza::RegistrirajCijenu (int cijena)
{
    if(cijena>max_cijena || cijena<min_cijena)
        throw std::range_error("Ilegalna cijena");
    cijene.push_back(cijena);
}

Berza::Berza (int min_cijena, int max_cijena)
{
    if(max_cijena<0 || min_cijena<0)
        throw::std::range_error("Ilegalne granicne cijene");
    Berza::max_cijena=max_cijena;
    Berza::min_cijena=min_cijena;
}

Berza::Berza (int max_cijena)
{
    if(max_cijena<0)
        throw::std::range_error("Ilegalne granicne cijene");
    Berza::max_cijena=max_cijena;
    Berza::min_cijena=0;
}

int main ()
{
    Berza b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(2500);
    b1.RegistrirajCijenu(2000);
    Berza b2(1000,4000);
    b2.RegistrirajCijenu(2500);
    b2.RegistrirajCijenu(2000);
    Berza nova(-b1);
    nova.Ispisi();
    /*std::cout<<b1[1]<<std::endl;
    std::cout<<b1.DajBrojCijenaVecihOd(1100)<<std::endl;
    b1++;
    b1.Ispisi();
    b2--;
    b2.Ispisi();
    if(b1==b2) {
        std::cout<<b1.DajMinimalnuCijenu()<<" "<<b1.DajMaksimalnuCijenu();
    } else std::cout<<"Klase nisu iste!";
    b1.BrisiSve();
    b2.BrisiSve();*/
    return 0;
}
