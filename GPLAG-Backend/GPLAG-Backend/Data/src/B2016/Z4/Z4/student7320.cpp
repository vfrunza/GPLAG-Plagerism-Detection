/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Datum {
  int day, month, year;
  int VratiBrojDana(int mjesec, int godina) {
    int BrojDanaUMjesecu[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) BrojDanaUMjesecu[2]++;
    return BrojDanaUMjesecu[mjesec];
  }
public:
  Datum(int dan, int mjesec, int godina) {
    Postavi(dan, mjesec, godina);
  };
  void Postavi(int dan, int mjesec, int godina) {
    int x = VratiBrojDana(mjesec, godina);
    if (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > x) throw std::domain_error("Neispravan datum");
    day = dan; month = mjesec; year = godina;
  }
  int DajDan() const { return day; }
  int DajMjesec() const { return month; }
  int DajGodinu() const { return year; }
  void Ispisi() const { std::cout << day << "/" << month << "/" << year; }
};
class Kupac {
  std::string ime;
  Datum dat = Datum(1, 1, 1);
  int VratiBrojDana(int mjesec, int godina) {
    int BrojDanaUMjesecu[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) BrojDanaUMjesecu[2]++;
    return BrojDanaUMjesecu[mjesec];
  }
public:
  Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    Postavi(ime_i_prezime, datum_rodjenja);
  }
  void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    for (int i = 0; i < ime_i_prezime.length(); i++)
      if (!((ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z') || (ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z') || (ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9') || ime_i_prezime[i] == '-' || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '\''))
        throw std::domain_error("Neispravno ime i prezime");
    int x, y, z;
    x = datum_rodjenja.DajDan(); y = datum_rodjenja.DajMjesec(); z = datum_rodjenja.DajGodinu();
    int xx = VratiBrojDana(y, z);
    if (z < 1 || x < 1 || y < 1 || y > 12 || x > xx) throw std::domain_error("Neispravan datum");
    ime = ime_i_prezime;
    dat = datum_rodjenja;
  }
  std::string DajImePrezime() const { return ime; }
  Datum DajDatumRodjenja() const { return dat; }
  void Ispisi() const { std::cout << ime << " ("; dat.Datum::Ispisi(); std::cout << ")"; }
};
class Stan {
  std::string Adr;
  int Sprat, BrojSoba;
  double Kvadrata;
  bool Namjesten;
public:
  Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
  }
  void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    Adr = adresa; Sprat = sprat; BrojSoba = broj_soba; Kvadrata = kvadratura; Namjesten = namjesten;
  }
  std::string DajAdresu() const { return Adr; }
  int DajSprat() const { return Sprat; }
  int DajBrojSoba() const { return BrojSoba; }
  bool DajNamjesten() const { return Namjesten; }
  double DajKvadraturu() const { return Kvadrata; }
  void Ispisi() const { 
    std::cout << "Stan se nalazi na adresi " << Adr << " na " << Sprat << ". spratu i ima " << BrojSoba << " sob";
    if (BrojSoba % 10 == 1) std::cout << "u";
    else if (BrojSoba % 10 == 2) std::cout << "e";
    else if (BrojSoba % 10 == 3) std::cout << "e";
    else if (BrojSoba % 10 == 4) std::cout << "e";
    else std::cout << "a";
    std::cout << ".\n";
    std::cout << "Kvadratura stana je " << Kvadrata << " (m^2) i stan ";
    if (!Namjesten) std::cout << "ni";
    std::cout << "je namjesten.\n";
  }
};
class Prodaja {
  std::string ImeAgenta;
  double CijenaStana;
  Datum DatumProdaje = Datum(1, 1, 1);
  Kupac KupacStana = Kupac("", {1, 1, 1});
  Stan KupljeniStan = Stan("", 1, 1, 1, 1);
public:
  Prodaja() {};
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    ImeAgenta = ime_agenta_prodaje; CijenaStana = cijena_stana; DatumProdaje = datum_prodaje; KupacStana = kupac_stana; KupljeniStan = kupljeni_stan;
  }
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
  const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    ImeAgenta = ime_agenta_prodaje; CijenaStana = cijena_stana; DatumProdaje = Datum(dan_prodaje, mjesec_prodaje, godina_prodaje);
    KupacStana = Kupac(ime_kupca, datum_rodjenja_kupca); KupljeniStan = Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
  }
  void PromijeniKupca(const Kupac &novi_kupac) { KupacStana = novi_kupac; }
  void PromijeniStan(const Stan &novi_stan) { KupljeniStan = novi_stan; }
  void PromijeniDatumKupovine(const Datum &novi_datum) { DatumProdaje = novi_datum; }
  void PromijeniCijenuProdaje(const double &nova_cijena) { CijenaStana = nova_cijena; }
  void PomjeriDanUnaprijed() {
    int dani, mjeseci, godine; 
    int BrojDanaUMjesecu[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    dani = DatumProdaje.DajDan(); mjeseci = DatumProdaje.DajMjesec(); godine = DatumProdaje.DajGodinu();
    dani++;
    if ((godine % 4 == 0 && godine % 100 != 0) || godine % 400 == 0) BrojDanaUMjesecu[2]++;
    if (dani > BrojDanaUMjesecu[mjeseci]) { dani = 1; mjeseci++; }
    if (mjeseci > 12) { mjeseci = 1; godine++; }
    DatumProdaje = Datum(dani,mjeseci, godine);
  }
  void PomjeriDanUnazad() {
    int dani, mjeseci, godine; 
    int BrojDanaUMjesecu[]{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    dani = DatumProdaje.DajDan(); mjeseci = DatumProdaje.DajMjesec(); godine = DatumProdaje.DajGodinu();
    dani--;
    if ((godine % 4 == 0 && godine % 100 != 0) || godine % 400 == 0) BrojDanaUMjesecu[2]++;
    if (dani <= 0) { 
      mjeseci--; 
      if (mjeseci == 0) mjeseci = 12, godine--;
      dani = BrojDanaUMjesecu[mjeseci];
    }
    DatumProdaje = Datum(dani,mjeseci, godine);
  }
  std::string DajImeAgenta() const { return ImeAgenta; }
  std::string DajImeKupca() const { return KupacStana.DajImePrezime(); }
  Datum DajDatumProdaje() const { return DatumProdaje; }
  double DajCijenuStana() const { return CijenaStana; }
  friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
  friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
  void Ispisi() const { 
    std::cout << "Ime agenta: " << DajImeAgenta() << "\n";
    std::cout << "Ime kupca: " << DajImeKupca() << "\n";
    std::cout << "Zakazani datum prodaje: "; DajDatumProdaje().Ispisi(); std::cout << "\n";
    std::cout << "Cijena stana: " << DajCijenuStana();
    std::cout << "\nInformacije o stanu: "; KupljeniStan.Stan::Ispisi();
  }
};
class Prodaje {
  Prodaja *niz = nullptr;
  int velicina = 0;
public:
  explicit Prodaje(int max_broj_prodaja) {
    niz = new Prodaja[max_broj_prodaja]{}; 
    velicina = max_broj_prodaja;
  }
  Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
    niz = new Prodaja[spisak_prodaja.size()]{};
    std::copy(spisak_prodaja.begin(), spisak_prodaja.end(), niz);
    velicina = spisak_prodaja.size();
  }
  ~Prodaje() {
    if (niz) delete niz;
  }
  Prodaje(const Prodaje &prodaje) : velicina(prodaje.velicina), niz(new Prodaja[prodaje.velicina]) {
    std::copy(prodaje.niz, prodaje.niz + velicina, niz);
  }
  Prodaje(Prodaje &&prodaje) : velicina(prodaje.velicina), niz(new Prodaja[prodaje.velicina]) { prodaje.niz = nullptr; }
  Prodaje &operator =(const Prodaje &prodaje) {
    if (&prodaje != this) {
      delete[] niz;
      velicina = prodaje.velicina; niz = new Prodaja[velicina];
      std::copy(prodaje.niz, prodaje.niz + velicina, niz);
    }
    return *this;
  }
  Prodaje &operator =(Prodaje &&prodaje) {
    if (&prodaje != this) {
      delete[] niz;
      niz = prodaje.niz;
      velicina = prodaje.velicina;
      prodaje.niz = nullptr;
    }  
    return *this;
  }
  void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
  void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
  const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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
  
}

