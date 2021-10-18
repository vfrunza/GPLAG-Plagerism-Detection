/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Datum{
    int dan1, mjesec1, godina1;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const;
    int DajMjesec() const;
    int DajGodinu() const;
    void Ispisi() const;
};
Datum::Datum(int dan, int mjesec, int godina){
    Postavi(dan,mjesec,godina);
}
void Datum::Postavi(int dan, int mjesec, int godina){
    dan1=dan;
    mjesec1=mjesec;
    godina1=godina;
}
int Datum::DajDan() const{
    return dan1;
}
int Datum::DajMjesec() const{
    return mjesec1;
}
int Datum::DajGodinu() const{
    return godina1;
}
void Datum::Ispisi() const{
    cout<<dan1<<"/"<<mjesec1<<"/"<<godina1<<endl;
}
class Kupac{
    string ime_i_prezime1;
    Datum datum_rodjenja1;
    public:
    Kupac(const string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja);
    string DajImePrezime() const;
    Datum DajDatumRodjenja() const;
    void Ispisi() const;
};
/*Kupac::Kupac(const string &ime_i_prezime, const Datum &datum_rodjenja){
    
}*/
void Kupac::Postavi(const string &ime_i_prezime, const Datum &datum_rodjenja){
    
}
string Kupac::DajImePrezime() const{
    
}
Datum Kupac::DajDatumRodjenja() const{
    
}
void Kupac::Ispisi() const{
    
}
class Stan{
    public:
    Stan(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    string DajAdresu() const;
    int DajSprat() const;
    int DajBrojSoba() const;
    bool DajNamjesten() const;
    double DajKvadraturu() const;
    void Ispisi() const;
};
Stan::Stan(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    
}
void Stan::Postavi(const string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    
}
string Stan::DajAdresu() const{
    
}
int Stan::DajSprat() const{
    
}
int Stan::DajBrojSoba() const{
    
}
bool Stan::DajNamjesten() const{
    
}
double Stan::DajKvadraturu() const{
    
}
void Stan::Ispisi() const{
    
}

class Prodaja{
    public:
    Prodaja(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, const Datum &datum_rodjenja_kupca, const string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac); 
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    string DajImeAgenta() const;
    string DajImeKupca() const;
    Datum DajDatumProdaje() const;
    double DajCijenuStana() const;
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};
Prodaja::Prodaja(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    
}
Prodaja::Prodaja(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, const Datum &datum_rodjenja_kupca, const string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
    
}
void Prodaja::PromijeniKupca(const Kupac &novi_kupac){
    
}
void Prodaja::PromijeniStan(const Stan &novi_stan){
    
}
void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum){
    
}
void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena){
    
}
void Prodaja::PomjeriDanUnaprijed(){
    
}
void Prodaja::PomjeriDanUnazad(){
    
}
string Prodaja::DajImeAgenta() const{
    
}
string Prodaja::DajImeKupca() const{
    
}
Datum Prodaja::DajDatumProdaje() const{
    
}
double Prodaja::DajCijenuStana() const{
    
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    
}
class Prodaje{
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, string &ime_kupca, const Datum &datum_rodjenja_kupca, const string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const;
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const string &ime_agenta); 
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

int main ()
{
	return 0;
}