/B2017/2018: Zadaća 5, Zadatak 6
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>

class Berza {
    int maksimalna_cijena, minimalna_cijena;
    std::vector<int> cijene;
    void FunkcijaSortiranja () {
        std::sort(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, std::placeholders::_2));
    }

public:
  
Berza(int minimalna, int maksimalna) {
    if (maksimalna < 0 || minimalna < 0) throw std::range_error ("Ilegalne granicne cijene");
    maksimalna_cijena = maksimalna;
    minimalna_cijena = minimalna;
}

Berza(int maksimalna):minimalna_cijena(0) {
    if (maksimalna < 0) throw std::range_error ("Ilegalne granicne cijene");
    maksimalna_cijena = maksimalna;
}

void RegistrirajCijenu(int unesena_cijena) {
    if (unesena_cijena > maksimalna_cijena || unesena_cijena < minimalna_cijena) throw std::range_error ("Ilegalna cijena");
    cijene.push_back(unesena_cijena);
    FunkcijaSortiranja();
}

int DajBrojRegistriranihCijena() {
    return cijene.size();
}

void BrisiSve () {
    for (int i(0); i<cijene.size(); i++) {
        cijene[i] = 0;
    }
    cijene.resize(0);
}

int DajMinimalnuCijenu() {
    if (cijene.size() == 0) throw std::range_error ("Nema registriranih cijena");
    int najmanja = *min_element (cijene.begin(), cijene.end(), [=] (int c1, int c2) {
        return c1 < c2;
    });
    return najmanja;
}

int DajMaksimalnuCijenu() {
    if (cijene.size() == 0) throw std::range_error ("Nema registriranih cijena");
    int najveca = *max_element (cijene.begin(), cijene.end(), [=] (int c1, int c2){
        return c1 < c2;
    });
    return najveca;
}

bool operator !() {
    if (cijene.size() == 0) return true;
    return false;
}

int DajBrojCijenaVecihOd(int cijena_od_koje_treba_biti_vece) {
    
    if (cijene.size()==0) throw std::range_error ("Nema registriranih cijena");
    int broj;
    broj = std::count_if(cijene.begin(), cijene.end(), std::bind(std::equal_to<int>(), 1, std::placeholders::_1));
    return broj;
}

void Ispisi() const {
    std::for_each(cijene.begin(), cijene.end(), [=] (int c) {
        std::cout << std::fixed << std::setprecision(2) << c / 100. << std::endl;
    });
}

int operator [] (int indeks_broja_koji_nas_interesuje) {
    if (indeks_broja_koji_nas_interesuje > cijene.size()) throw std::range_error ("Neispravan indeks");
    return cijene[indeks_broja_koji_nas_interesuje - 1];
}

Berza operator ++() {
    transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::plus<int>(), 100/*ovo je vrijednost koji dodajemo, 100 je zbog toga sto je u feninzima*/, std::placeholders::_1));
    int broj;
    broj = std::count_if(cijene.begin(), cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, maksimalna_cijena));
    if (broj > 0) throw std::range_error ("Prekoracen dozvoljen opseg cijena");
    return *this;
}

Berza operator --(){
    transform (cijene.begin(), cijene.end(),cijene.begin(), std::bind(std::minus<int> (), std::placeholders::_1, 100));
    int broj;
    broj = std::count_if(cijene.begin(), cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, minimalna_cijena));
    if (broj > 0) throw std::range_error ("Prekoracen dozvoljen opseg cijena");
    return *this;
}

Berza operator -(){
    std::transform(cijene.begin(), cijene.end(), cijene.begin(), std::bind(std::minus<int>(), minimalna_cijena+maksimalna_cijena, std::placeholders::_1));
    int broj3, broj4;
    broj3 = std::count_if(this->cijene.begin(), this->cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, minimalna_cijena));
    broj4 = std::count_if(this->cijene.begin(), this->cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, maksimalna_cijena));
    if (broj3 > 0 || broj4 > 0) ;
    return *this;
}

bool operator ==(Berza b){
    int broj1,broj2,broj3,broj4;
    if (b.cijene.size() != this->cijene.size()) return false;
    else {
        broj1 = std::count_if(b.cijene.begin(), b.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna_cijena));//provjeriti ovdje kako ukljuciti b1 i b2 u pricu
        broj2 = std::count_if(b.cijene.begin(), b.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.maksimalna_cijena));
        broj3 = std::count_if(this->cijene.begin(), this->cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, minimalna_cijena));
        broj4 = std::count_if(this->cijene.begin(), this->cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, maksimalna_cijena));
        if(broj1 > 0 || broj2 > 0 || broj3 > 0 || broj4 > 0) return false;
        auto it1 = b.cijene.begin();
        auto it2 = this->cijene.begin();
        int brojac = std::count_if(this->cijene.begin(), this->cijene.end(), std::bind(std::equal_to<int>(), *it1++, *it2++));
        if (brojac != this->cijene.size()) return false;
        return true;
    }
}

bool operator !=(Berza b) {
    int broj1,broj2,broj3,broj4;
    if (b.cijene.size() == this->cijene.size()) return false;
    else {
        broj1 = std::count_if(b.cijene.begin(), b.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna_cijena));//provjeriti ovdje kako ukljuciti b1 i b2 u pricu
        broj2 = std::count_if(b.cijene.begin(), b.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.maksimalna_cijena));
        broj3 = std::count_if(this->cijene.begin(), this->cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, minimalna_cijena));
        broj4 = std::count_if(this->cijene.begin(), this->cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, maksimalna_cijena));
        if(broj1 > 0 || broj2 > 0 || broj3 > 0 || broj4 > 0) return false;
        auto it1 = b.cijene.begin();
        auto it2 = this->cijene.begin();
        int brojac = std::count_if(this->cijene.begin(), this->cijene.end(), std::bind(std::not_equal_to<int>(), *it1++, *it2++));
        if (brojac != this->cijene.size()) return false;
        return true;
        
    }
}
friend Berza operator +(int y, Berza b);
friend Berza operator +(Berza b, int y);
friend Berza operator -(Berza b, int y);
friend Berza operator -(Berza b1, Berza b2);
};

Berza operator +(int y, Berza b) {
    std::transform(b.cijene.begin(), b.cijene.end(), b.cijene.begin(), std::bind(std::plus<int>(),  y, std::placeholders::_1));
        int  broj3, broj4;
        broj3 = std::count_if(b.cijene.begin(), b.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna_cijena));
        broj4 = std::count_if(b.cijene.begin(), b.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1,b.maksimalna_cijena));
        if( broj3 > 0 || broj4 > 0) throw std::domain_error("Prekoracen dozvoljeni opseg cijena");
    return b;
}

Berza operator +(Berza b, int y) {
    return y+b;
}

Berza operator - (Berza b, int y) {
    std::transform(b.cijene.begin(), b.cijene.end(), b.cijene.begin(), std::bind(std::minus<int>(), std::placeholders::_1, y));
        int  broj3, broj4;
        broj3 = std::count_if(b.cijene.begin(), b.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, b.minimalna_cijena));
        broj4 = std::count_if(b.cijene.begin(), b.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, b.maksimalna_cijena));
        if( broj3 > 0 || broj4 > 0) throw std::domain_error ("Prekoracen dozvoljeni opseg cijena");
        
    return b;
}

Berza operator -(Berza b1, Berza b2) {
    if (b1.cijene.size() != b2.cijene.size() || b1.maksimalna_cijena != b2.maksimalna_cijena || b1.minimalna_cijena != b2.minimalna_cijena) throw std::domain_error ("Nesaglasni operandi");
    auto it1 = b1.cijene.begin();
    auto it2 = b2.cijene.begin();
    Berza konacno = Berza(b1.minimalna_cijena, b2.maksimalna_cijena);
    konacno.cijene.resize(b1.cijene.size());
    int broj3, broj4;
    std::transform(b1.cijene.begin(), b2.cijene.end(),konacno.cijene.begin(),std::bind(std::minus<int>(), *it1++, *it2++));
    broj3 = std::count_if(konacno.cijene.begin(), konacno.cijene.end(), std::bind(std::less<int>(), std::placeholders::_1, konacno.minimalna_cijena));
    broj4 = std::count_if(konacno.cijene.begin(), konacno.cijene.end(), std::bind(std::greater<int>(), std::placeholders::_1, konacno.maksimalna_cijena));
    if( broj3 > 0 || broj4 > 0) throw std::domain_error ("Prekoracen dozvoljeni opseg cijena");
        
return konacno;
    
}

int main ()
{   /*Berza b1 = Berza(1000,4000);
    b1.RegistrirajCijenu(3000);
    b1.RegistrirajCijenu(1500);
    b1.Ispisi();
    --b1;
    b1.Ispisi();
    b1=b1+1;
    b1=1+b1;
    b1=b1-5;
    b1.Ispisi();
    -b1;
    b1.Ispisi();
    std::cout << "Minimalna cijena: " << b1.DajMinimalnuCijenu() << std::endl;
    std::cout << "Maksimalna cijena: " << b1.DajMaksimalnuCijenu();*/
	return 0;
}
