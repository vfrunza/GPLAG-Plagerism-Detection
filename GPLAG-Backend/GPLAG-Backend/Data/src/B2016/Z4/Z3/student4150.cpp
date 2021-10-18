#include <iostream>
#include <stdexcept>
#include <string>
class Datum{
    int d = 0, m = 0, g = 0;
    friend class Prodaja;
    friend class Kupac;
    friend class Stan;
    public:
    Datum(int dan, int mjesec, int godina) {
        if(dan < 1 || dan >31 || mjesec < 1 || mjesec > 12 || godina < 0)
        throw std::domain_error ("Neispravan datum");
        Datum::d = dan;
        Datum::m = mjesec;
        Datum::g = godina;
    }
    void Postavi(int dan, int mjesec, int godina) {
        if(dan < 1 || dan > 31 || mjesec < 1 || mjesec > 12 || godina < 0)
        throw std::domain_error ("Neispravan datum");
        Datum::d = dan;
        Datum::m = mjesec;
        Datum::g = godina;
    }
    int DajDan() const { return d; }
    int DajMjesec() const { return m; }
    int DajGodinu() const { return g; }
    void Ispisi() const {
        std::cout << d <<"/" << m << "/" << g << std::endl;
    }
};

class Kupac {
    std::string ime;
    Datum datum;
    friend class Datum;
    friend class Prodaja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()) {
        for(int i(0); i < ime_i_prezime.size(); i++) {
            if(ime_i_prezime[i] < 'a' || ime_i_prezime[i] > 'z' || ime_i_prezime[i] < 'A' || ime_i_prezime[i] > 'Z' || 
            ime_i_prezime[i] < '0' || ime_i_prezime[i] > '9' || ime_i_prezime[i] != '-' || ime_i_prezime[i] != 39) 
            throw std::domain_error ("Neispravno ime i prezime");
        }
        Kupac::ime = ime_i_prezime;
        Kupac::datum = datum_rodjenja;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
        for(int i(0); i < ime_i_prezime.size(); i++) {
            if(ime_i_prezime[i] < 'a' || ime_i_prezime[i] > 'z' || ime_i_prezime[i] < 'A' || ime_i_prezime[i] > 'Z' || 
            ime_i_prezime[i] < '0' || ime_i_prezime[i] > '9' || ime_i_prezime[i] != '-' || ime_i_prezime[i] != 39) 
            throw std::domain_error ("Neispravno ime i prezime");
        }
        Kupac::ime = ime_i_prezime;
        Kupac::datum = datum_rodjenja;
    }
    std::string DajImePrezime() const { return ime; }
    Datum DajDatumRodjenja() const { return datum; }
    void Ispisi() const; //OVO!!
};
class Stan {
    std::string adresa;
    int sprat, broj_soba;
    double kvadratura;
    bool namjesten;
    friend class Kupac;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if(broj_soba <0 || sprat < 0 || kvadratura < 0 || namjesten < 0) throw std::domain_error ("Neispravan unos podataka");
        Stan::adresa = adresa;
        Stan::sprat = sprat;
        Stan::broj_soba = broj_soba;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if(broj_soba < 0 || sprat < 0 || kvadratura < 0 || namjesten <0) throw std::domain_error ("Neispravan unos podataka");
        Stan::adresa = adresa;
        Stan::sprat = sprat;
        Stan::broj_soba = broj_soba;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
    }
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    //OVO POPRAVITI - soba,sobe
    void Ispisi() const { 
        if(namjesten == true) std::cout << "Stan se nalazi na adresi "<< adresa << " na " << sprat << " spratu i ima broj "<< broj_soba<<"soba."<<std::endl <<"Kvadratura stana je "<<kvadratura<<" i stan je namjesten.";
    else std::cout << "Stan se nalazi na adresi "<< adresa << " na " << sprat << " spratu i ima broj "<< broj_soba<<"soba."<<std::endl<<"Kvadratura stana je "<<kvadratura<<" i stan nije namjesten.";
    }
};
class Prodaja {
    std::string agent;
    double cijenastana;
    Datum datumprodaje;
    Kupac kupacstana;
    Stan kupljenistan;
    friend class Stan;
    friend class Datum;
    friend class Kupac;
public: 
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return agent; }
    std::string DajImeKupca() const { return kupacstana.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datumprodaje; }
    double DajCijenuStana() const { return cijenastana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : 
    datumprodaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()), kupacstana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
    kupljenistan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu() ){
    agent = ime_agenta_prodaje;
    cijenastana = cijena_stana;
//    datumprodaje = datum_prodaje;
//    kupacstana = kupac_stana;
//    kupljenistan = kupljeni_stan;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : 
     datumprodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupacstana(ime_kupca, datum_rodjenja_kupca), kupljenistan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {
    agent = ime_agenta_prodaje;
    cijenastana = cijena_stana;
}
      
void Prodaja::PromijeniKupca(const Kupac &novi_kupac) {
    kupacstana = novi_kupac;
}      
void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena) {
    cijenastana = nova_cijena;
}
void Prodaja::PomjeriDanUnaprijed() {
    datumprodaje.d++;
}
void Prodaja::PomjeriDanUnazad() {
    datumprodaje.d--;
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if(p1.datumprodaje.DajGodinu() < p2.datumprodaje.DajGodinu()) return true;
    else if(p1.datumprodaje.DajGodinu() > p2.datumprodaje.DajGodinu()) return false;
    else {
        if(p1.datumprodaje.DajMjesec() < p2.datumprodaje.DajMjesec()) return true;
        else if(p1.datumprodaje.DajMjesec() > p2.datumprodaje.DajMjesec()) return false;
        else {
            if(p1.datumprodaje.DajDan() < p2.datumprodaje.DajDan()) return true;
            else return false;
        }
    }
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
  if(p1.cijenastana > p2.cijenastana) return true;
  return false;
}
void Prodaja::Ispisi() const {
    std::cout << "Ime agenta: " << agent << std::endl 
              << "Ime kupca: " << kupacstana.Ispisi() << std::endl
              << "Cijena stana: " << cijenastana << std::endl
              << "Informacije o stanu: " << std::endl
              << kupljenistan.Ispisi();
    
}

/*

class Prodaje {
    
    
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const;
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju() const;
    Prodaja &DajNajSkupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    
    
};













*/

int main () {/*
    std::cout << "Dobrodosli!" << std::endl << std::endl;
    std::cout << "Izaberite opciju: " << std::endl <<" 0 - kraj"<<std::endl<< " 1 - uredjivanje stanova"<<std::endl<<
    " 2 - uredjivanje kupaca" << std::endl;
    
    
    */
    
	return 0;
}



