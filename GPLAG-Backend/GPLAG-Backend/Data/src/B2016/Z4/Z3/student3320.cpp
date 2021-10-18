/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <string>
#include <utility>
#include <new>
#include <algorithm>

// DATUM
class Datum {
int d, m, g;
public:
void Postavi(int dan, int mjesec, int godina);
int DajDan() const;
int DajMjesec() const;
int DajGodinu() const;
void Ispisi() const;
};

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum!");
    d=dan;
    m=mjesec;
    g=godina;
    
}

int Datum::DajDan() { return d; }

int Datum::DajMjesec() { return m; }

int Datum::DajGodinu() { return g; }

void Datum::Ispisi() { std::cout << d << "/" << m << "/" << ga; }

// KUPCI
class Kupac {
std::string ime_i_prezime;
Datum datum_rodjenja;
public:    
Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
std::string DajImePrezime() const;
Datum DajDatumRodjenja() const;
void Ispisi() const;
};



std::string Kupac::DajImePrezime() { return std::string ime_i_prezime; }
Datum Kupac::DajDatumRodjenja() { 
    Datum temp;
    temp
    return;
}

// STANOVI
class Stan {
std::string adresa;
int sprat, broj_soba;
bool namjesten;
double kvadratura;
public:    
Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
void Postavi(const std::string &adresa, int sprat, int broj_soba,
bool namjesten, double kvadratura);
std::string DajAdresu() const;
int DajSprat() const;
int DajBrojSoba() const;
bool DajNamjesten() const;
double DajKvadraturu() const;
void Ispisi() const;
};

// PRODAJA
class Prodaja {
std::string ime_agenta_prodaje;
double cijena_stana;
Datum datum_prodaje;
Kupac kupac_stana;
Stan kupljeni_stan;
public:    
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
const std::string &adresa_stana, int sprat_stana, int broj_soba,
bool namjesten_stan, double broj_kvadrata);
void PromijeniKupca(const Kupac &novi_kupac);   
void PromijeniStan(const Stan &novi_stan);
void PromijeniDatumKupovine(const Datum &novi_datum);
void PromijeniCijenuProdaje(const double &nova_cijena);
void PomjeriDanUnaprijed();
void PomjeriDanUnazad();
std::string DajImeAgenta() const;
std::string DajImeKupca() const;
Datum DajDatumProdaje() const;
double DajCijenuStana() const;
friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
void Ispisi() const;
};

// PRODAJE
class Prodaje {
std::initializer_list<Prodaja> spisak_prodaja;    
public:    
explicit Prodaje(int max_broj_prodaja);
Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
~Prodaje();
Prodaje(const Prodaje &prodaje);
Prodaje(Prodaje &&prodaje);
Prodaje &operator =(const Prodaje &prodaje);
Prodaje &operator =(Prodaje &&prodaje);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
void RegistrirajProdaju(Prodaja *prodaja);
int DajBrojProdaja() const;
int DajBrojProdajaNaDatum(const Datum &datum) const;
int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
Prodaja &DajNajranijuProdaju();
Prodaja DajNajranijuProdaju() const;
Prodaja &DajNajskupljuProdaju();
Prodaja DajNajskupljuProdaju() const;
void IsprazniKolekciju();
void ObrisiNajranijuProdaju();
void ObrisiProdajeAgenta(const std::string &ime_agenta); 
void ObrisiProdajeNaDatum(const Datum &datum);
void IspisiProdajeNaDatum(const Datum &datum) const;
void IspisiSveProdaje() const;
};





int main () {
	return 0;
}