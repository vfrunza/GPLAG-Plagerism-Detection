/B2017/2018: Zadaća 5, Zadatak 6
/B2017/2018: Zadaća 5, Zadatak 5
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>
 
class Berza
{
    int MIN,MAX;
    std::vector<int> cijene;
    void Test()
    {
        int n = std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(),std::placeholders::_1,MAX));
        if(n!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
        n = std::count_if(cijene.begin(), cijene.end(), std::bind(std::less<int>(),std::placeholders::_1,MIN));
        if(n!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    }
public:
    explicit Berza(int max);
    Berza(int min, int max);
    void RegistrirajCijenu(int cijena);
    int DajBrojRegistriranihCijena() const { return cijene.size(); }
    void BrisiSve() { cijene.clear(); }
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    int DajBrojCijenaVecihOd(int cijena);
    void Ispisi() const;
    friend bool operator!(Berza berza);
    int operator[](int x) const;
    friend Berza& operator++(Berza &berza);
    friend Berza operator++(Berza &berza, int);
    friend Berza& operator--(Berza &berza);
    friend Berza operator--(Berza &berza, int);
    friend Berza operator-(Berza berza);
    friend Berza operator+(const Berza &berza, int);
    friend Berza operator+(int, const Berza &berza);
    friend Berza operator-(const Berza &berza, int);
    friend Berza operator-(int, const Berza &berza);
    friend Berza operator-(const Berza &berza1, const Berza &berza2);
    friend Berza operator+(const Berza &berza1, const Berza &berza2);
    friend Berza operator-=(Berza &berza1, const Berza &berza2);
    friend Berza operator+=(Berza &berza1, const Berza &berza2);
    friend bool operator==(const Berza &berza1, const Berza &berza2);
    friend bool operator!=(const Berza &berza1, const Berza &berza2);
};
 
Berza::Berza(int max)
{
    if(max<0) throw std::range_error("Ilegalne granice cijene");
    MIN=0;
    MAX=max;
}
Berza::Berza(int min, int max)
{
    if(max<0 || min<0) throw std::range_error("Ilegalne granice cijene");
    MAX=max;
    MIN=min;
}
void Berza::RegistrirajCijenu(int cijena)
{
    if(cijena<MIN || cijena>MAX) throw std::range_error("Ilegalna cijena");
    cijene.push_back(cijena);
}
int Berza::DajMinimalnuCijenu() const
{
    if(cijene.size()==0) throw std::range_error("Nema registriranih cijena");
    auto p = std::min_element(cijene.begin(),cijene.end());
    return *p;
}
int Berza::DajMaksimalnuCijenu() const
{
    if(cijene.size()==0) throw std::range_error("Nema registriranih cijena");
    auto p = std::max_element(cijene.begin(),cijene.end());
    return *p;
}
int Berza::DajBrojCijenaVecihOd(int cijena)
{
    if(cijene.size()==0) throw std::range_error("Nema registriranih cijena");
    int n = std::count_if(cijene.begin(),cijene.end(),std::bind(std::greater<int>(),std::placeholders::_1,cijena));
    return n;
}
void Berza::Ispisi() const
{
    if(cijene.size()==0) return;
    std::vector<int> pom(cijene);
    std::sort(pom.begin(),pom.end(),std::greater<int>());
   
    for(int i=0;i<cijene.size();i++)
    {
        std::cout<<std::setprecision(2)<<std::fixed;
        std::cout<<pom.at(i)/100.<<std::endl;
    }
}
bool operator!(Berza berza)
{
    return !berza.DajBrojRegistriranihCijena();
}
int Berza::operator[](int x) const
{
    if(x<0 || x>=cijene.size()) throw std::range_error("Neispravan indeks");
    return cijene.at(x);
}
Berza& operator++(Berza &berza)
{
    std::vector<int> nove(berza.cijene.size());
    std::transform(berza.cijene.begin(), berza.cijene.end(), nove.begin(), std::bind(std::plus<int>(), 100, std::placeholders::_1));
    int n = std::count_if(nove.begin(), nove.end(), std::bind(std::greater<int>(),std::placeholders::_1,berza.MAX));
    if(n!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    n = std::count_if(nove.begin(), nove.end(), std::bind(std::less<int>(),std::placeholders::_1,berza.MIN));
    if(n!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    berza.cijene=nove;
    return berza;
}
Berza operator++(Berza &berza, int)
{
    Berza pomocni(berza);
    ++berza;
    return pomocni;
}
Berza& operator--(Berza &berza)
{
    std::vector<int> nove(berza.cijene.size());
    std::transform(berza.cijene.begin(), berza.cijene.end(), nove.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
    int n = std::count_if(nove.begin(), nove.end(), std::bind(std::greater<int>(),std::placeholders::_1,berza.MAX));
    if(n!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    n = std::count_if(nove.begin(), nove.end(), std::bind(std::less<int>(),std::placeholders::_1,berza.MIN));
    if(n!=0) throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    berza.cijene=nove;
    return berza;
}
Berza operator--(Berza &berza, int)
{
    Berza pomocni(berza);
    --berza;
    return pomocni;
}
Berza operator-(Berza berza)
{
    std::transform(berza.cijene.begin(), berza.cijene.end(), berza.cijene.begin(), std::bind(std::minus<int>(), berza.MAX + berza.MIN, std::placeholders::_1));
    return berza;
}
Berza operator+(const Berza &berza, int x)
{
    Berza pomocna(berza);
    std::transform(pomocna.cijene.begin(), pomocna.cijene.end(), pomocna.cijene.begin(), std::bind(std::plus<int>(), x, std::placeholders::_1));
    pomocna.Test();
    return pomocna;
}
Berza operator+(int x, const Berza &berza)
{
    Berza pomocna(berza);
    pomocna=pomocna+x;
    return pomocna;
}
Berza operator-(const Berza &berza, int x)
{
    Berza pomocna(berza);
    std::transform(pomocna.cijene.begin(), pomocna.cijene.end(), pomocna.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, x));
    pomocna.Test();
    return pomocna;
}
Berza operator-(int x, const Berza &berza)
{
    Berza pomocna(berza);
    std::transform(pomocna.cijene.begin(), pomocna.cijene.end(), pomocna.cijene.begin(), std::bind(std::minus<int>(), x, std::placeholders::_1));
    pomocna.Test();
    return pomocna;
}
Berza operator-(const Berza &berza1, const Berza &berza2)
{
    if(berza1.MAX != berza2.MAX || berza1.MIN != berza2.MIN || berza1.cijene.size() != berza2.cijene.size()) throw std::domain_error("Nesaglasni operandi");
    Berza pomocna(berza1);
    std::transform(berza1.cijene.begin(), berza1.cijene.end(), berza2.cijene.begin(), pomocna.cijene.begin(), std::minus<int>());
    pomocna.Test();
    return pomocna;
}
Berza operator+(const Berza &berza1, const Berza &berza2)
{
    if(berza1.MAX != berza2.MAX || berza1.MIN != berza2.MIN || berza1.cijene.size() != berza2.cijene.size()) throw std::domain_error("Nesaglasni operandi");
    Berza pomocna(berza1);
    std::transform(berza1.cijene.begin(), berza1.cijene.end(), berza2.cijene.begin(), pomocna.cijene.begin(), std::plus<int>());
    pomocna.Test();
    return pomocna;
}
Berza operator-=(Berza &berza1, const Berza &berza2)
{
    return berza1=berza1-berza2;
}
Berza operator+=(Berza &berza1, const Berza &berza2)
{
    return berza1=berza1+berza2;
}
bool operator==(const Berza &berza1, const Berza &berza2)
{
    if(berza1.cijene.size() != berza2.cijene.size()) return false;
    std::vector<int> priv1(berza1.cijene);
    std::vector<int> priv2(berza2.cijene);
    std::sort(priv1.begin(),priv1.end(),std::less<int>());
    std::sort(priv2.begin(),priv2.end(),std::less<int>());
    return std::equal(priv1.begin(),priv1.end(),priv2.begin());
}
bool operator!=(const Berza &berza1, const Berza &berza2)
{
    if(berza1.cijene.size() != berza2.cijene.size()) return true;
    std::vector<int> priv1(berza1.cijene);
    std::vector<int> priv2(berza2.cijene);
    std::sort(priv1.begin(),priv1.end(),std::less<int>());
    std::sort(priv2.begin(),priv2.end(),std::less<int>());
    return !std::equal(priv1.begin(),priv1.end(),priv2.begin());
}
int main ()
{
    std::cout<<"Unesite minimalnu i maksimalnu cijenu (min max): ";
    int n,m;
    std::cin>>n>>m;
    Berza berza(n,m);
    while(true)
    {
        try
        {
            std::cout<<"1 - Registriraj novu cijenu"<<std::endl<<"2 - Prikazi broj registriranih cijena"<<std::endl<<"3 - Obrisi sve cijene"<<std::endl<<"4 - Ispisi najmanju cijenu"<<std::endl<<"5 - Ispisi najvecu cijenu"<<std::endl<<"6 - Ispisi sve cijene"<<std::endl<<"7 - Dodaj 1KM na sve cijene"<<std::endl<<"8 - Oduzmi 1KM od svih cijena"<<std::endl;
            int unos;
            std::cin>>unos;
            if(unos == 1)
            {
                std::cout<<"Unesite cijenu: ";
                int cijena;
                std::cin>>cijena;
                berza.RegistrirajCijenu(cijena);
            }
            else if(unos==2)
            {
                std::cout<<"Broj cijena: "<<berza.DajBrojRegistriranihCijena()<<std::endl;
            }
            else if(unos==3)
            {
                berza.BrisiSve();
                std::cout<<"Sve cijene uspjesno obrisane"<<std::endl;
            }
            else if(unos==4)
            {
                std::cout<<"Najmanja cijena: "<<berza.DajMinimalnuCijenu()/100.<<std::endl;
            }
            else if(unos==5)
            {
                std::cout<<"Najveca cijena: "<<berza.DajMaksimalnuCijenu()/100.<<std::endl;
            }
            else if(unos==6)
            {
                berza.Ispisi();
            }
            else if(unos==7)
            {
                berza++;
                std::cout<<"Dodana marka na sve cijene"<<std::endl;
            }
            else if(unos==8)
            {
                berza--;
                std::cout<<"Oduzeta marka od svih cijena"<<std::endl;
            }
        }
        catch(std::range_error izuzetak)
        {
            std::cout<<"IZUZETAK: "<<izuzetak.what()<<std::endl;
        }
        catch(std::domain_error izuzetak)
        {
            std::cout<<"IZUZETAK: "<<izuzetak.what()<<std::endl;
        }
    }
    return 0;
}