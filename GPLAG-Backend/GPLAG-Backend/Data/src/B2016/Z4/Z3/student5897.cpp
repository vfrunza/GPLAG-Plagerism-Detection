/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>

class Datum {
    int dan, mjesec, godina;
    
    public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
};

    void Datum::Postavi(int dan, int mjesec, int godina) {
    int br_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina %100 !=0) || godina % 400 == 0) br_dana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>br_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    
    public:
    //ne valja konstruktor
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):Kupac::ime_i_prezime(ime_i_prezime),Datum(datum_rodjenja.dan,datum_rodjenja.mjesec
    ,datum_rodjenja.Dgodina){}
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const { std::cout << ime_i_prezime << " (" << datum_rodjenja.DajDan() << "/" << datum_rodjenja.DajMjesec() << "/" << datum_rodjenja.DajGodinu() << ")"; }
};

    void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    Kupac::datum_rodjenja = datum_rodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    for(int i=0; i<ime_i_prezime.length(); i++) {
        if(!((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9'))) {
            throw std::domain_error("Neispravno ime i prezime");
        }
    }
}

class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa, sprat, broj_soba, namjesten, kvadratura); }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
};

    void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa = adresa; Stan::sprat = sprat; Stan::broj_soba = broj_soba; Stan::namjesten = namjesten; Stan::kvadratura = kvadratura; 
}

    void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << " spratu i ima ";
    if(broj_soba%10==1 || broj_soba!=11) std::cout << broj_soba << " sobu." << std::endl;
    else if(broj_soba%10>=2 && broj_soba<=4 && !(broj_soba>=12 && broj_soba<=14)) std::cout << broj_soba << " sobe." << std::endl;
    else std::cout << broj_soba << " soba." << std::endl;
    std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(namjesten) std::cout << "je namjesten";
    else std::cout << "nije namjesten"; 
}

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    
  public: 
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
  Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, 
  int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
  void PromijeniKupca(const Kupac &novi_kupac);
  void PromijeniStan(const Stan &novi_stan);
  void PromijeniDatumKupovine(const Datum &novi_datum);
  void PromijeniCijenuProdaje(const double &nova_cijena);
  void PomjeriDanUnaprijed();
  void PomjeriDanUnazad();
  std::string DajImeAgenta() const { return ime_agenta_prodaje; }
  std::string DajImeKupca() const { return kupac_stana.DajImePrezime(); }
  Datum DajDatumProdaje() const { return datum_prodaje; }
  double DajCijenuStana() const { return cijena_stana; }
  friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
  friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
  void Ispisi() const;
}; 

  //  Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
        Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
        
    }
  //  void Ispisi() const {
    std::cout << "Ime agenta: " << ime_agenta_prodaje << std::endl;
    std::cout << "Ime kupca: " << kupac_stana.Ispisi() << std::endl;
    std::cout << "Zakazani datum prodaje: " << datum_prodaje << std::endl;
    std::cout << "Cijena stana: " << cijena_stana << std::endl;
    std::cout << "Informacije o stanu: " << std::endl;
    kupljeni_stan.Ispisi();
} 










/*
class Prodaje {
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator = (const Prodaje &prodaje);
    Prodaje &operator = (Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(prodaja *prodaja);
    int DajBrojProdaja() const { return broj_prodaja; }
    int DajBrojProdajaNaDatum() const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta_prodaje) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuKolekciju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta_prodaje);
    void ObrisiProdajeNaDatum(const datum &datum);
    void IspisiProdajeNadatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
}; */

int main ()
{
    std::cout << "valja";
    Datum d(1,2,2012); d.Postavi(12, 3, 2001);
   // Kupac ime = "Ana bekuta";
    //ime.Ispisi();
    //d.DajDan().Ispisi();
	return 0;
}