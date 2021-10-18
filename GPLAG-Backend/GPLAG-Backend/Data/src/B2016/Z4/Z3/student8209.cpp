/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <new>
#include <initializer_list>

class Datum {
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

void Datum::Postavi(int dan, int mjesec, int godina) {
    int br_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) br_dana[1]++;
    if(godina < 1 || mjesec < 1 || dan < 1 || mjesec > 12 || dan > br_dana[mjesec - 1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

class Kupac {
  std::string ime_i_prezime;
  Datum datum_rodjenja;
  public:
  Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : ime_i_prezime(ime_i_prezime), datum_rodjenja(datum_rodjenja) { }
  void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
  std::string DajImePrezime() const {
      return ime_i_prezime;
  }
  Datum DajDatumRodjenja() const {
      return datum_rodjenja;
  }
  void Ispisi() const {
      std::cout << ime_i_prezime << " (";
      datum_rodjenja.Ispisi();
      std::cout << ")";
  }
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    bool flag(false);
    /*for(int i = 0; i < ime_i_prezime.length(); i++) {
        if(ime_i_prezime[i])
    }*/
    if(flag) throw std::domain_error("Neispravno ime i prezime");
    Kupac::ime_i_prezime = ime_i_prezime;
    Kupac::datum_rodjenja = datum_rodjenja;
}

class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa = adresa;
    Stan::sprat = sprat;
    Stan::broj_soba = broj_soba;
    Stan::namjesten = namjesten;
    Stan::kvadratura = kvadratura;
}

void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
    if(broj_soba > 4 && broj_soba < 21) std::cout << " soba. ";
    else if(broj_soba % 10 == 1 && broj_soba != 11) std::cout << " sobu. ";
    else if(broj_soba % 10 == 2 || broj_soba % 10 == 3 || broj_soba % 10 == 4) std::cout << " sobe. ";
    std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(namjesten) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    static bool UporediDatume(const Datum &d1, const Datum &d2) {
        int datum1 = d1.DajDan() + d1.DajMjesec() * 100 + d1.DajGodinu() * 10000;
        int datum2 = d2.DajDan() + d2.DajMjesec() * 100 + d2.DajGodinu() * 10000;
        
        return datum1 > datum2;
        
    }
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {}
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}
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

void Prodaja::PromijeniKupca(const Kupac &novi_kupac) {
    kupac_stana = novi_kupac;
}

void Prodaja::PromijeniStan(const Stan &novi_stan) {
    kupljeni_stan = novi_stan;
}

void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum) {
    datum_prodaje = novi_datum;
}

void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena) {
    cijena_stana = nova_cijena;
}
/*
void Prodaja::PomjeriDanUnaprijed() {
    datum_prodaje.dan++;
    if(datum_prodaje.dan > )
}

void Prodaja::PomjeriDanUnazad() {
    
}*/

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    return Prodaja::UporediDatume(p1.datum_prodaje, p2.datum_prodaje);
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    return p1.cijena_stana > p2.cijena_stana;
}

void Prodaja::Ispisi() const {
    std::cout << "Ime agenta: " << ime_agenta_prodaje << std::endl;
    std::cout << "Ime kupca: " << DajImeKupca() << " ";
    kupac_stana.Ispisi();
    std::cout << std::endl;
    std::cout << "Zakazani datum prodaje: ";
    datum_prodaje.Ispisi() ;
    std::cout << std::endl;
    std::cout << "Informacije o stanu: ";
    kupljeni_stan.Ispisi();
    std::cout << std::endl;
}

class Prodaje {
    int broj_prodaja;
    int max_broj_prodaja;
    Prodaja **pprodaje = nullptr;
    public:
    explicit Prodaje(int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja), broj_prodaja(0), pprodaje(new Prodaja*[max_broj_prodaja]) {}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);  // kopirajuci konstr.
    Prodaje(Prodaje &&prodaje);     // pomjerajuci konstr.
    Prodaje &operator =(const Prodaje &prodaje);   // kopirajuci operator =
    Prodaje &operator =(Prodaje &&prodaje);   // pomjerajuci operator =
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const { return broj_prodaja; }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajProdaju(int redni_broj_prodaje);
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

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : broj_prodaja(spisak_prodaja.size()), max_broj_prodaja(spisak_prodaja.size()), pprodaje(new Prodaja*[spisak_prodaja.size()]) {
   int i = 0, alocirano = 0;
   try {
       for(auto p(spisak_prodaja.begin()); p != spisak_prodaja.end(); p++, i++, alocirano++)
          pprodaje[i] = new Prodaja(*p);
   }
   
   catch(std::bad_alloc) {
       if(pprodaje != nullptr) {
           for(int i = 0; i < alocirano; i++) delete pprodaje[i];
           delete[] pprodaje;
           
           throw;
       }
   }
}

Prodaje::~Prodaje() {
    if(pprodaje != nullptr) {
        for(int i = 0; i < broj_prodaja; i++) delete pprodaje[i];
        delete[] pprodaje;
        pprodaje = nullptr;
    }
}

Prodaje::Prodaje(const Prodaje &prodaje) : broj_prodaja(prodaje.broj_prodaja), max_broj_prodaja(prodaje.max_broj_prodaja), pprodaje(new Prodaja*[prodaje.max_broj_prodaja]) {   // kopirajuci konstruktor
    int alocirano = 0;
    try {
        for(int i = 0; i < prodaje.broj_prodaja; i++, alocirano++) pprodaje[i] = new Prodaja(*prodaje.pprodaje[i]);
    }
    
    catch(std::bad_alloc) {
        if(pprodaje != nullptr) {
            for(int i = 0; i < alocirano; i++) delete pprodaje[i];
            delete[] pprodaje;
        }
    }
}

Prodaje::Prodaje(Prodaje &&prodaje) : broj_prodaja(prodaje.broj_prodaja), max_broj_prodaja(prodaje.max_broj_prodaja), pprodaje(prodaje.pprodaje) {    // pomjerajuci konstr.
   prodaje.pprodaje = nullptr;
   prodaje.broj_prodaja = 0;
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje) {   // kopirajuci operator =
    try {
        if(prodaje.max_broj_prodaja == max_broj_prodaja) {
            if(prodaje.broj_prodaja > broj_prodaja) {
                for(int i = 0; i < broj_prodaja; i++) *pprodaje[i] = *prodaje.pprodaje[i];
                for(int i = broj_prodaja; i < prodaje.broj_prodaja; i++) pprodaje[i] = nullptr;
                for(int i = broj_prodaja; i < prodaje.broj_prodaja; i++) pprodaje[i] = new Prodaja(*prodaje.pprodaje[i]);
            }
            else {
                for(int i = 0; i < prodaje.broj_prodaja; i++) *pprodaje[i] = *prodaje.pprodaje[i];
                for(int i = prodaje.broj_prodaja; i < broj_prodaja; i++) delete pprodaje[i];
            }
        }
        else {
            for(int i = 0; i < broj_prodaja; i++) delete pprodaje[i];
            delete[] pprodaje;
            pprodaje = new Prodaja*[prodaje.max_broj_prodaja];
            for(int i = 0; i < prodaje.broj_prodaja; i++) pprodaje[i] = new Prodaja(*prodaje.pprodaje[i]);
        }
    }
    catch(std::bad_alloc) {
        if(pprodaje != nullptr) {
            for(int i = 0; i < prodaje.broj_prodaja; i++) delete pprodaje[i];
            delete[] pprodaje;
        }
        throw;
    }
    broj_prodaja = prodaje.broj_prodaja;
    max_broj_prodaja = prodaje.max_broj_prodaja;
    
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje) {  // pomjerajuci operator =
    if(&prodaje != this) {
        for(int i = 0; i < broj_prodaja; i++) delete pprodaje[i];
        delete[] pprodaje;
        pprodaje = prodaje.pprodaje;
        broj_prodaja = prodaje.broj_prodaja;
        prodaje.pprodaje = nullptr;
        prodaje.broj_prodaja = 0;
    }
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    if(broj_prodaja == max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    try {
        pprodaje[broj_prodaja++] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
    }
    catch(std::bad_alloc) {
        throw;
    }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    if(broj_prodaja == max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    try {
        pprodaje[broj_prodaja++] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    }
    catch(std::bad_alloc) {
        throw;
    }
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    if(broj_prodaja == max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    pprodaje[broj_prodaja++] = prodaja;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(pprodaje, pprodaje + broj_prodaja, [datum](Prodaja *p) {return (p->DajDatumProdaje().DajDan() == datum.DajDan() && p->DajDatumProdaje().DajMjesec() == datum.DajMjesec() && p->DajDatumProdaje().DajGodinu() == datum.DajGodinu());  });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return std::count_if(pprodaje, pprodaje + broj_prodaja, [ime_agenta](Prodaja *p) {
        return (p->DajImeAgenta() == ime_agenta);
    });
}

Prodaja &Prodaje::DajNajranijuProdaju() {
    
}

Prodaja Prodaje::DajNajranijuProdaju() const {
    
}

Prodaja &Prodaje::DajNajskupljuProdaju() {
    return **std::max_element(pprodaje, pprodaje + broj_prodaja, [](Prodaja *p1, Prodaja *p2) {
       return p1->DajCijenuStana() < p2->DajCijenuStana();
    });
}

Prodaja Prodaje::DajNajskupljuProdaju() const {
    return **std::max_element(pprodaje, pprodaje + broj_prodaja, [](Prodaja *p1, Prodaja *p2) {
       return p1->DajCijenuStana() < p2->DajCijenuStana(); 
    });
}

void Prodaje::IsprazniKolekciju() {
    for(int i = 0; i < broj_prodaja; i++) delete pprodaje[i];
    broj_prodaja = 0;
}
/*
void Prodaje::ObrisiNajranijuProdaju() {
    
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    
}

void Prodaje::IspisiSveProdajeNaDatum(const Datum &datum) const {
    
}*/

void Prodaje::IspisiSveProdaje() const {
    for(int i = 0; i < broj_prodaja; i++) {
        pprodaje[i]->Ispisi();
    }
}

int main ()
{
    try {
        std::cout << "Dobrodosli!\n\n";
        std::cout << "Izaberite opciju: " << std::endl;
        Datum dat(28, 6, 1950);
        std::string s = "Mujo Mujic";
        Prodaja p("Niko Niksic", 150000, 5, 3, 2017, s, dat, "Hamdije Cemerlica 14", 5, 5, true, 35.45 );
    }
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    catch(std::range_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
    catch(std::bad_alloc) {
        std::cout << "Problemi sa memorijom" << std::endl;
    }
    
	return 0;
}