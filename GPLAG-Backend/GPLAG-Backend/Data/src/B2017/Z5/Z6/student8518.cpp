/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>

class Berza
{
    private:
    
    int minimalna, maksimalna;
    std::vector<int> v;
    
    public:
    Berza (int min, int maks);
    Berza(int maks);
    Berza() =delete;   //????
    void RegistrirajCijenu(int nova);
    int DajBrojRegistriranihCijena() const { return v.size();}
    void BrisiSve() { v.resize(0);}
    int DajMinimalnuCijenu() const;
    int DajMaksimalnuCijenu() const;
    bool operator !();
    bool operator !() const;
    int DajBrojCijenaVecihOd(int od_koje_cijene); //treba l biti const
    void Ispisi() const;
    int operator[](int indeks); //kaze u postavci da s ene moze korisiti za izmjenu podataka s lijeve strane jednakosti, tj. ne vraca referencu
    int operator[](int indeks) const;
    
    Berza &operator ++();
    Berza &operator --();
    
    Berza operator ++(int);
    Berza operator --(int);
    
    friend Berza operator + (const Berza &b, int dodaj);
    friend Berza operator - (const Berza &b, int oduzmi);
    
    friend Berza operator + (int dodaj, const Berza &b);
    friend Berza operator - (int oduzmi, const Berza &b);
    
    friend Berza operator + (const Berza &b1, const Berza &b2);
    friend Berza operator - (const Berza &b1, const Berza &b2);
    
    Berza &operator +=(const Berza &b); 
    Berza &operator -=(const Berza &b);
    
    bool operator ==(const Berza &b);
    bool operator !=(const Berza &b);
};

Berza::Berza(int min, int maks)
{
    if( min<0 || maks<0)
    throw std::range_error ("“Ilegalne granicne cijene");
    
    minimalna=min;
    maksimalna=maks;
}

Berza::Berza(int maks)
{
     if(maks<0)
    throw std::range_error ("“Ilegalne granicne cijene");
    
    minimalna=0;
    maksimalna=maks;
}

void Berza::RegistrirajCijenu(int nova)
{
    if(nova<minimalna || nova>maksimalna)
    throw std::range_error("Ilegalna cijena");
    
    v.push_back(nova);
    
}

int Berza::DajMinimalnuCijenu() const
{
    if(v.size()==0)
    throw std::range_error ("Nema registriranih cijena");
    
    return *std::min_element(v.begin(), v.end());
}

int Berza::DajMaksimalnuCijenu() const
{
    if(v.size()==0)
    throw std::range_error ("Nema registriranih cijena");
    
    return *std::max_element(v.begin(), v.end());  //max_element vraca iterator na najveci element, a ne samo najveci element
}

 bool Berza::operator !()
 {
    if(v.size()==0)
    return true;
    else
    return false;
 }
 
 bool Berza::operator !() const
 {
    if(v.size()==0)
    return true;
    else
    return false; 
 }
 
 int Berza::DajBrojCijenaVecihOd(int od_koje_cijene)
 {
    if(v.size()==0)
    throw std::range_error ("Nema registriranih cijena");
    
    return std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1,od_koje_cijene)); 
 }
 
 void Berza::Ispisi() const
 {
    std::vector<int> pomocni(v);
     
    std::sort(pomocni.begin(), pomocni.end(), std::greater<int>() );
     
    //std::transform(pomocni.begin(), pomocni.end(), pomocni.begin(), std::bind(std::divides<int>(), std::placeholders::_1, 100)); 
     
    for(int i=0; i<pomocni.size(); i++)
    std::cout<<std::fixed<<std::setprecision(2)<<pomocni.at(i)/100.<<std::endl;
     
 }
 
 int Berza::operator[](int indeks)
 {
    if(indeks-1<0 || indeks>v.size())
    throw std::range_error("“Neispravan indeks");
    
    return v.at(indeks-1);
 }
 
 int Berza::operator[](int indeks) const
 {
    if(indeks-1<0 || indeks>v.size())
    throw std::range_error("“Neispravan indeks");
    
    return v.at(indeks-1);
 }
 
 Berza &Berza::operator ++()
 {
    if(*std::max_element(v.begin(), v.end())+100>maksimalna)   //da li su minimalna i maksimalna cijena u markama ili feninzima??
    throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    
    return *this;
 }
 
 Berza &Berza::operator --()
 {
    if(*std::min_element(v.begin(), v.end())-100<minimalna)   //da li su minimalna i maksimalna cijena u markama ili feninzima??
    throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
    
    return *this;
 }
 
 Berza Berza::operator ++(int)
 {
    if(*std::max_element(v.begin(), v.end())+100>maksimalna)   //da li su minimalna i maksimalna cijena u markama ili feninzima??
    throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    
    Berza pomocna(*this);
    
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::plus<int>(), std::placeholders::_1, 100));
    
    return pomocna; 
 }
 
 Berza Berza::operator --(int)
 {
    if(*std::min_element(v.begin(), v.end())-100<minimalna)   //da li su minimalna i maksimalna cijena u markama ili feninzima??
    throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    
    Berza pomocna(*this);
    
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, 100));
    
    return pomocna; 
 }
 
 Berza operator + (const Berza &b, int dodaj)
 {
    if(*std::max_element(b.v.begin(), b.v.end())+dodaj>b.maksimalna)   //da li su minimalna i maksimalna cijena u markama ili feninzima??
    throw std::range_error("Prekoracen dozvoljeni opseg cijena"); 
    
    Berza b1(b.minimalna, b.maksimalna);
    
    std::transform(b1.v.begin(), b1.v.end(), b1.v.begin(), std::bind(std::plus<int>(), std::placeholders::_1, dodaj));
    
    return b1;
 }
 
 Berza operator - (const Berza &b, int oduzmi)
 {
    if(*std::min_element(b.v.begin(), b.v.end())-oduzmi<b.minimalna)   //da li su minimalna i maksimalna cijena u markama ili feninzima??
    throw std::range_error("Prekoracen dozvoljeni opseg cijena"); 
    
    Berza b2(b.minimalna, b.maksimalna);
    
    std::transform(b2.v.begin(), b2.v.end(), b2.v.begin(), std::bind(std::minus<int>(), std::placeholders::_1, oduzmi));
    
    return b2;
 }

 Berza operator + (int dodaj, const Berza &b)
 {
    b+dodaj;
    
    return b;
 }
 
 Berza operator - (int oduzmi, const Berza &b)
 {
    b-oduzmi;
    
    return b;
 }
 
 Berza operator + (const Berza &b1, const Berza &b2)
 {
    if(b1.maksimalna!=b2.maksimalna || b1.maksimalna!=b2.minimalna || b1.v.size()!=b2.v.size())
    throw std::domain_error("“Nesaglasni operandi");
    
    Berza b3(b1.minimalna, b1.maksimalna);
    
    std::transform(b1.v.begin(), b1.v.end(), b2.v.begin(), b3.v.begin(), std::plus<int>() );
    
    if(*std::max_element(b3.v.begin(), b3.v.end())>b3.maksimalna)
    throw std::range_error("Prekoracen dozvoljeni opseg cijena"); 
    
    return b3;
 }
 
 Berza operator - (const Berza &b1, const Berza &b2)
 {
    if(b1.maksimalna!=b2.maksimalna || b1.maksimalna!=b2.minimalna || b1.v.size()!=b2.v.size())
    throw std::domain_error("“Nesaglasni operandi");
    
    Berza b3(b1.minimalna, b1.maksimalna);
    
    std::transform(b1.v.begin(), b1.v.end(), b2.v.begin(), b3.v.begin(), std::minus<int>() );
    
    if(*std::min_element(b3.v.begin(), b3.v.end())<b3.minimalna)
    throw std::range_error("Prekoracen dozvoljeni opseg cijena"); 
    
    return b3;
 }
 
 Berza &Berza::operator +=(const Berza &b)
 {
    if(maksimalna!=b.maksimalna || maksimalna!=b.minimalna || v.size()!=b.v.size())
    throw std::domain_error("“Nesaglasni operandi");
    
    Berza b3(minimalna, maksimalna);
    
    std::transform(v.begin(), v.end(), b.v.begin(), b3.v.begin(), std::plus<int>() );
    
    if(*std::max_element(b3.v.begin(), b3.v.end())>b3.maksimalna)
    throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    
    *this=b3;
    
    return *this;
 }
 
Berza &Berza::operator -=(const Berza &b)
 {
    if(maksimalna!=b.maksimalna || maksimalna!=b.minimalna || v.size()!=b.v.size())
    throw std::domain_error("“Nesaglasni operandi");
    
    Berza b3(minimalna, maksimalna);
    
    std::transform(v.begin(), v.end(), b.v.begin(), b3.v.begin(), std::minus<int>() );
    
    if(*std::min_element(b3.v.begin(), b3.v.end())<b3.minimalna)
    throw std::range_error("Prekoracen dozvoljeni opseg cijena");
    
    *this=b3;
    
    return *this;
 }
 
bool Berza::operator ==(const Berza &b)
{
    if(v.size()==b.v.size())
    {
        return std::equal(v.begin(), v.end(), b.v.begin(), std::equal_to<int>() );
    }
    else
    return false;
}

bool Berza::operator !=(const Berza &b)
{
    if(v.size()==b.v.size())
    {
        return std::equal(v.begin(), v.end(), b.v.begin(), std::not_equal_to<int>() );
    }
    else
    return false; //ovdje true??
}

int main ()
{
    
    Berza b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(3000);
    b1.RegistrirajCijenu(1500);
    b1.RegistrirajCijenu(2000);
    std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena() << std::endl;
    b1.Ispisi();
    b1.BrisiSve();
    std::cout << "Broj registrovanih cijena: " << b1.DajBrojRegistriranihCijena();
    
	return 0;
}
