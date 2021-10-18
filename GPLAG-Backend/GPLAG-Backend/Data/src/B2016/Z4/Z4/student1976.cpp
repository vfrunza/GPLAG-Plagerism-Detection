/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>

class Datum {
    int dan, mjesec, godina;
    int BrojDana(int m, int g) {
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(g % 4 == 0 && (g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
        return broj_dana[m - 1];
    }
public:
    Datum (int d, int m, int g) { Postavi(d, m, g); }
    
    void Postavi (int d, int m, int g);

    int DajDan() const {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    }
    int DajGodinu() const {
        return godina;
    }
    
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
    friend class Kupac;
    friend class Prodaja;
    friend class Prodaje;
};

void Datum::Postavi (int d, int m, int g) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g % 4 == 0 && (g % 100 != 0 || g % 400 == 0)) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1])
        throw std::domain_error ("Neispravan datum");
    dan = d; mjesec = m; godina = g;
}

class Kupac {
    std::string ime_i_prezime;
    Datum dat_rodjenja = Datum(1, 1, 1);
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const {
        return dat_rodjenja;
    }
    
    void Ispisi() const {
        std::cout << ime_i_prezime << "("; dat_rodjenja.Ispisi(); std::cout << ")";
    }
    friend class Prodaja;
    friend class Prodaje;
};

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    for(int i = 0; i < ime_i_prezime.length(); i++) 
        if(!((ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z') || (ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z') || (ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9') || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '/' || ime_i_prezime[i] == '-'))
            throw std::domain_error("Neispravno ime i prezime");
    Kupac::ime_i_prezime = ime_i_prezime; 
    dat_rodjenja = datum_rodjenja;
}
    
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    for(int i = 0; i < ime_i_prezime.length(); i++) 
        if(!((ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z') || (ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z') || (ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9') || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '/' || ime_i_prezime[i] == '-'))
            throw std::domain_error("Neispravno ime i prezime");
    Kupac::ime_i_prezime = ime_i_prezime;
    dat_rodjenja = datum_rodjenja;  
}

class Stan {
    std::string adresa_;
    int sprat_, br_soba;
    bool opremljen;
    double kvadratura_;
public: 
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { 
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    
    int DajSprat() const {
        return sprat_;
    }
    int DajBrojSoba() const {
        return br_soba;
    }
    bool DajNamjesten() const {
        return opremljen; 
    }
    double DajKvadraturu() const {
        return kvadratura_;
    }
    
    void Ispisi() const;
    friend class Prodaja;
    friend class Prodaje;
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    adresa_ = adresa; sprat_ = sprat; br_soba = broj_soba; opremljen = namjesten; kvadratura_ = kvadratura;
}
void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adresa_ << " na " << sprat_ <<". spratu i ima " << br_soba;
    if(br_soba < 5) 
        std::cout << " sobe." << '\n';
    else std::cout << " soba." << '\n';
    std::cout << "Kvadratura stana je " << kvadratura_ << " (m^2) i stan ";
    if(opremljen) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}

class Prodaja {
    std::string ime_agenta_prodaje_;
    double cijena_stana_;
    Datum datum_prodaje_ = Datum(1, 1, 1);
    Kupac kupac_stana_ = Kupac("", Datum(1, 1, 1));
    Stan kupljeni_stan_ = Stan("", 0, 0, false, 0);

public:
    Prodaja(){};
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    
    void PromijeniKupca(const Kupac &novi_kupac) {
        kupac_stana_ = novi_kupac;
    }
    void PromijeniStan(const Stan &novi_stan) {
        kupljeni_stan_ = novi_stan;   
    } 
    void PromijeniDatumKupovine(const Datum &novi_datum) {
        datum_prodaje_ = novi_datum;
    } 
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        cijena_stana_ = nova_cijena;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    
    std::string DajImeAgenta() const {
        return ime_agenta_prodaje_;
    }
    std::string DajImeKupca() const {
        return kupac_stana_.DajImePrezime();
    } 
    Datum DajDatumProdaje() const {
        return datum_prodaje_;
    } 
    double DajCijenuStana() const {
        return cijena_stana_;
    } 
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2); 
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2); 
    
    void Ispisi() const;
    friend class Prodaje;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    ime_agenta_prodaje_ = ime_agenta_prodaje;
    cijena_stana_ = cijena_stana;
    datum_prodaje_ = datum_prodaje;
    kupac_stana_ = kupac_stana;
    kupljeni_stan_ = kupljeni_stan;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    ime_agenta_prodaje_ = ime_agenta_prodaje;
    cijena_stana_ = cijena_stana;
    datum_prodaje_ = Datum(dan_prodaje, mjesec_prodaje, godina_prodaje);
    kupac_stana_ = Kupac(ime_kupca, datum_rodjenja_kupca);
    kupljeni_stan_ = Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
}

void Prodaja::PomjeriDanUnaprijed() {
    datum_prodaje_.dan++;
    if(datum_prodaje_.dan > datum_prodaje_.BrojDana(datum_prodaje_.mjesec, datum_prodaje_.godina)) datum_prodaje_.dan = 1; datum_prodaje_.mjesec++;
    if(datum_prodaje_.mjesec > 12) datum_prodaje_.mjesec = 1; datum_prodaje_.godina++;
}  

void Prodaja::PomjeriDanUnazad() {
    datum_prodaje_.dan--;
    if(datum_prodaje_.dan < 1) datum_prodaje_.mjesec--; datum_prodaje_.dan = datum_prodaje_.BrojDana(datum_prodaje_.mjesec, datum_prodaje_.godina); 
    if(datum_prodaje_.mjesec < 1) datum_prodaje_.mjesec = 12; datum_prodaje_.godina--;
}

void Prodaja::Ispisi() const { // dodati setw
    std::cout << "Ime agenta: " << ime_agenta_prodaje_ << '\n';
    std::cout << "Ime kupca: "; kupac_stana_.Ispisi(); std::cout << '\n';
    std::cout << "Zakazani datum prodaje: "; datum_prodaje_.Ispisi(); std::cout << '\n';
    std::cout << "Cijena stana: " << cijena_stana_ << "\n";
    std::cout << "Informacije o stanu: \n";
    kupljeni_stan_.Ispisi();
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if(p1.DajDatumProdaje().DajGodinu() < p2.DajDatumProdaje().DajGodinu()) return true;
    if(p1.DajDatumProdaje().DajGodinu() == p2.DajDatumProdaje().DajGodinu() && p1.DajDatumProdaje().DajMjesec() < p2.DajDatumProdaje().DajMjesec())
        return true;
    if(p1.DajDatumProdaje().DajGodinu() == p2.DajDatumProdaje().DajGodinu() && p1.DajDatumProdaje().DajMjesec() == p2.DajDatumProdaje().DajMjesec() && p1.DajDatumProdaje().DajDan() < p2.DajDatumProdaje().DajDan())
        return true;
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    if(p1.DajCijenuStana() > p2.DajCijenuStana()) return true;
    return false;
}

class Prodaje {
    int kapacitet;
    int br_prodaja;
    Prodaja **pok_na_niz;
    mutable int index = 0;
public:
   
    explicit Prodaje(int max_broj_prodaja){ kapacitet = max_broj_prodaja; br_prodaja = 0; pok_na_niz = new Prodaja*[max_broj_prodaja]{}; }
    
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    
    ~Prodaje() {
        for(int i = 0; i < kapacitet; i++) delete pok_na_niz[i];
        delete[] pok_na_niz; 
    } 
    
    Prodaje(const Prodaje &prodaje);
    
    Prodaje(Prodaje &&prodaje) {
        pok_na_niz = prodaje.pok_na_niz; kapacitet = prodaje.kapacitet; br_prodaja = prodaje.br_prodaja;
        prodaje.pok_na_niz = nullptr; prodaje.br_prodaja = 0;
    }
    
    Prodaje &operator =(const Prodaje &prodaje);
    
    Prodaje &operator =(Prodaje &&prodaje) {    
        if(prodaje.kapacitet != kapacitet) throw std::logic_error("Nesaglasni kapaciteti");
        std::swap(br_prodaja, prodaje.br_prodaja);
        std::swap(pok_na_niz, prodaje.pok_na_niz);
        return *this;
    }
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,  int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    
    int DajBrojProdaja() const {
        return br_prodaja;
    }
    
    Prodaja &DajProdaju(int index) {
        
    }    
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;

    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const ;
  
    void IsprazniKolekciju(){
        for(int i = 0; i < br_prodaja; i++) {
            delete pok_na_niz[i]; pok_na_niz[i] = nullptr;
        }
    }
    void ObrisiNajranijuProdaju();  
    void ObrisiProdajeAgenta(const std::string &ime_agenta); 
    void ObrisiProdajeNaDatum(const Datum &datum); 
    void IspisiProdajeNaDatum(const Datum &datum) const; 
    void IspisiSveProdaje() const;
};

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) { 
    br_prodaja = spisak_prodaja.size();
    pok_na_niz = new Prodaja*[spisak_prodaja.size()]{};
    auto it(spisak_prodaja.begin());
    try {
        for(int i = 0; i < br_prodaja; i++) {
            pok_na_niz[i] = new Prodaja(*it); it++;
        }
    } catch(...) {
        for(int i = 0; i < br_prodaja; i++) delete pok_na_niz[i];
        delete[] pok_na_niz; throw;
    }
}

Prodaje::Prodaje(const Prodaje &prodaje) {
    pok_na_niz = new Prodaja*[prodaje.kapacitet]{};
    kapacitet = prodaje.kapacitet;
    br_prodaja = prodaje.br_prodaja;
    try {
        for(int i = 0; i < prodaje.br_prodaja; i++)
            pok_na_niz[i] = new Prodaja(*prodaje.pok_na_niz[i]);
    } catch(...) {
        for(int i = 0; i < prodaje.br_prodaja; i++) delete pok_na_niz[i];
        delete[] pok_na_niz;
    }
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje) {
    if(prodaje.kapacitet != prodaje.kapacitet) throw std::logic_error("Nesuglasan kapacitet");
    if(prodaje.br_prodaja > br_prodaja) {
        try{
            for(int i = br_prodaja; i < prodaje.br_prodaja; i++)
                pok_na_niz[i] = new Prodaja(*prodaje.pok_na_niz[i]);
        } catch(...) {
            for(int i = br_prodaja; i < prodaje.br_prodaja; i++) {
                delete pok_na_niz[i]; 
                pok_na_niz[i] = nullptr;
            } throw;
        }
    } else {
        for(int i = prodaje.br_prodaja; i < br_prodaja; i++) {
            delete pok_na_niz[i]; pok_na_niz[i] = nullptr;
        } 
    }
    br_prodaja = prodaje.br_prodaja;
    for(int i = 0; i < br_prodaja; i++) 
        *pok_na_niz[i] = *prodaje.pok_na_niz[i];
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    if(br_prodaja == kapacitet) throw std::range_error("Dostignut maksimalni broj prodaja");
    Prodaja *novi(nullptr);
    try{
        novi = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
        pok_na_niz[br_prodaja++] = novi;
    } catch(...) {
        delete novi; novi = nullptr;
    }
} 

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,  int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    if(br_prodaja == kapacitet) throw std::range_error("Dostignut maksimalni broj prodaja");
        Prodaja *novi(nullptr);
    try{
        novi = new  Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
        pok_na_niz[br_prodaja++] = novi;
    } catch(...) {
        delete novi; novi = nullptr;
    }
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja) { //briga i brisanje
    if(br_prodaja == kapacitet) throw std::range_error("Dostignut maksimalni broj prodaja");
    pok_na_niz[br_prodaja++] = prodaja;
}

/*int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    int broj = std::count_if(pok_na_niz, pok_na_niz + br_prodaja, [datum] (Prodaja *prodaja) { 
        if(prodaja->datum_prodaje_ == datum) return true;    
        return false;
    });
    return broj;
}
*/
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    int broj = std::count_if(pok_na_niz, pok_na_niz + br_prodaja, [ime_agenta] (Prodaja *prodaja) {
        if(prodaja->ime_agenta_prodaje_ == ime_agenta) return true;
        return false;
    });
    return broj;
} 

int main ()
{
	return 0;
}