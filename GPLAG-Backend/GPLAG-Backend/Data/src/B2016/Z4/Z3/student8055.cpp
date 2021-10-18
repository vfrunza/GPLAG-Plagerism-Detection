
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>

Datum(int dan, int mjesec, int godina);
void Postavi(int dan, int mjesec, int mjesec);
int DajDan() const;
int DajMjesec() const;
int DajGodinu() const;
void Ispisi() const;

Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
std::string DajImePrezime() const;
Datum DajDatumRodjenja() const;
void Ispisi() const;

Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
 double kvadratura);
void Postavi(const std::string &adresa, int sprat, int broj_soba,
 bool namjesten, double kvadratura);
std::string DajAdresu() const;
int DajSprat() const;
int DajBrojSoba() const;
bool DajNamjesten() const;
double DajKvadraturu() const;
void Ispisi() const;

Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
 const Datum &datum_prodaje, const Kupac &kupac_stana,
 const Stan &kupljeni_stan);
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


explicit Prodaje(int max_broj_prodaja);
Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
~Prodaje();
Prodaje(const Prodaje &prodaje);
Prodaje(Prodaje &&prodaje);
Prodaje &operator =(const Prodaje &prodaje);
Prodaje &operator =(Prodaje &&prodaje);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
 double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
const Stn &kupljeni_stan);
void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje,
int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
 const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
 int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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


int main ()
{
	return 0;
}