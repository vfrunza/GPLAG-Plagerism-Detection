#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Datum {
    int dan, mj, god;
public:    
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mj; }
    int DajGodinu() const { return god; }
    void Ispisi() const { cout << DajDan() << "/" << DajMjesec() << "/" << DajGodinu(); }
};

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0))
        broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw std::domain_error("Neispravan datum");
        
    this->dan = dan; this->mj = mjesec; this->god = godina;
}

class Kupac {
    string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum_rodjenja(datum_rodjenja){
        Postavi(ime_i_prezime, datum_rodjenja);
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const {  cout << ime_i_prezime << "("; datum_rodjenja.Ispisi(); cout << ")"; }
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    for (auto it = ime_i_prezime.begin(); it != ime_i_prezime.end(); it++) 
        if (!((*it >= 'a' && *it <= 'z') or (*it >= 'A' && *it <= 'Z') or *it == '\''
            or *it == ' ' or (*it >= '1' && *it <= '9')))
            throw std::domain_error ("Neispravno ime i prezime");
    this -> datum_rodjenja = datum_rodjenja;
    this -> ime_i_prezime = ime_i_prezime;
}

class Stan {
    string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public :
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
    if (sprat < 0 or broj_soba < 0 or kvadratura < 0)
        throw std::domain_error ("Neispravan unos podataka");
    this -> adresa = adresa;
    this -> sprat = sprat;
    this -> broj_soba = broj_soba;
    this -> namjesten = namjesten;
    this -> kvadratura = kvadratura;
}

void Stan::Ispisi() const {
    cout << "Stan se nalazi na adresi " << adresa << " na " << sprat 
        << ". spratu i ima " << broj_soba;
    if (broj_soba == 2 or broj_soba == 3 or broj_soba == 4)         // MOZE ZAJEBAVATI AKO BUDE IMAO 21,22,23,31,32,33... soba :/
        cout << " sobe." << endl;
    else 
        cout << " soba." << endl;
    cout << "Kvadratura stana je " << std::fixed << std::setprecision(2) << kvadratura  // POPRAVITI STD::FIXED I TO U ISPISU
        << " (m^2) i stan ";
    if(namjesten)
        cout << "je";
    else 
        cout << "nije";
    cout << " namjesten.";    
}   

class Prodaja {
    string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:    
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
        const Datum &datum_prodaje, const Kupac &kupac_stana,
        const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
        int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
        const std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
        const std::string &adresa_stana, int sprat_stana, int broj_soba,
        bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) { kupac_stana = novi_kupac; }
    void PromijeniStan(const Stan &novi_stan) { kupljeni_stan = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datum_prodaje = novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena_stana = nova_cijena; }
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

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) :
    datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {
    
    this -> ime_agenta_prodaje = ime_agenta_prodaje;
    this -> cijena_stana = cijena_stana;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, 
    int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
    const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
    datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca),
    kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
    {
    this -> ime_agenta_prodaje = ime_agenta_prodaje;
    this -> cijena_stana = cijena_stana;
}

void Prodaja::PomjeriDanUnaprijed() {
            
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    dan++;
    
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0))
        broj_dana[1]++;
    
    if(dan > broj_dana[mjesec - 1]) dan = 1, mjesec++;
    if(mjesec > 12) mjesec = 1, godina++;
    
    datum_prodaje.Postavi(dan, mjesec, godina);
}

void Prodaja::PomjeriDanUnazad() {
    
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    dan++;
    
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0))
        broj_dana[1]++;
    
    if(dan == 0) {
        if(mjesec == 1)
            dan = 31, mjesec = 12, godina--;
        else     
            dan = broj_dana[mjesec - 2], mjesec--, godina--;
    }   
    datum_prodaje.Postavi(dan, mjesec, godina);
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if (p1.datum_prodaje.DajGodinu() != p2.datum_prodaje.DajGodinu())
        return p1.datum_prodaje.DajGodinu() < p2.datum_prodaje.DajGodinu();
    if (p1.datum_prodaje.DajMjesec() != p2.datum_prodaje.DajMjesec())
        return p1.datum_prodaje.DajMjesec() < p2.datum_prodaje.DajMjesec();
    return p1.datum_prodaje.DajDan() < p2.datum_prodaje.DajDan();  
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    return  p1.DajCijenuStana() < p2.DajCijenuStana();
}

void Prodaja::Ispisi() const {
    cout << std::setw(30) << std::left << "Ime agenta:" << DajImeAgenta() << endl
        << std::setw(30) << "Ime kupca:" << DajImeKupca() << endl
        << std::setw(30) << "Zakazani datum prodaje:"; datum_prodaje.Ispisi(); cout << endl
        << std::setw(30) << "Cijena stana:" << std::fixed << std::setprecision(2) << cijena_stana << endl // PROVJERITI ZA SETPRECISION :/
        << "Informacije o stanu:" << endl;
        kupljeni_stan.Ispisi();
}

class Prodaje {
    Prodaja **prodaje{};
    int max_broj_prodaja, broj_prodaja;
    void Obrisi () {
        if(prodaje) {
            for (int i = 0; i < broj_prodaja; i++) 
                delete prodaje[i];
            delete[] prodaje;
        }    
    }
public:    
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje() { Obrisi(); }
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
        double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
        int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
        const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
        int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const { return broj_prodaja; }
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

Prodaje::Prodaje (int max_broj_prodaja) :  prodaje(nullptr), max_broj_prodaja(max_broj_prodaja),
    broj_prodaja(0) {
    try {
        prodaje = new Prodaja* [max_broj_prodaja];
        
        for(int i = 0; i < max_broj_prodaja; i++) 
            prodaje[i] = nullptr;
    }
    catch (std::bad_alloc) {
        //Obrisi();
        throw;
    }
}

Prodaje::Prodaje (std::initializer_list<Prodaja> spisak_prodaja) :
    prodaje(nullptr), max_broj_prodaja(spisak_prodaja.size()), broj_prodaja(0){
    try {
        prodaje = new Prodaja* [max_broj_prodaja];
        
        for(int i = 0; i < max_broj_prodaja; i++) 
            prodaje[i] = nullptr;
        int i(0);
        for (auto it = spisak_prodaja.begin(); it != spisak_prodaja.end(); it++) {
            prodaje[i] = new Prodaja(*it);
            broj_prodaja++;
            i++;
        }
    }
    catch (std::bad_alloc) {
        Obrisi();
        throw;
    }
}

Prodaje::Prodaje(const Prodaje &p) : prodaje(nullptr), max_broj_prodaja(p.max_broj_prodaja),
    broj_prodaja(p.broj_prodaja) {
        
    try {
        prodaje = new Prodaja* [p.max_broj_prodaja];
        
        for(int i = 0; i < p.max_broj_prodaja; i++) 
            prodaje[i] = nullptr;
            
        for (int i = 0; i < p.broj_prodaja; i++) 
            prodaje[i] = new Prodaja(*p.prodaje[i]);
    }
    catch (std::bad_alloc) {
        Obrisi();
        throw;
    }
}

Prodaje::Prodaje(Prodaje &&p) : prodaje(p.prodaje), max_broj_prodaja(p.max_broj_prodaja),
    broj_prodaja(p.broj_prodaja) {
    
    p.max_broj_prodaja = 0;
    p.broj_prodaja = 0;
    p.prodaje = nullptr;       
}
 
Prodaje &Prodaje::operator =(const Prodaje &p) {
    
    //Samododjela                                          //Mozda bude trebalo baciti izuzetak ako se maxbrojprodaja ne poklapa
    if(this == &p)
        return *this;
        
    //Pravljenje duboke kopije
    Prodaja **prodajedeep(nullptr);
    try {
        prodajedeep = new Prodaja* [p.max_broj_prodaja];
        
        for (int i = 0; i < p.max_broj_prodaja; i++) 
            prodajedeep[i] = nullptr;
            
        for (int i = 0; i < p.broj_prodaja; i++) 
            prodajedeep[i] = new Prodaja(*p.prodaje[i]);
            
        // brisanje   
        Obrisi();
        
        //kopiranje
        max_broj_prodaja = p.max_broj_prodaja;
        broj_prodaja = p.broj_prodaja;  
        prodaje = prodajedeep;
        prodajedeep = nullptr;
    }
    catch (std::bad_alloc) {
        if(prodajedeep){
            for(int i = 0; i < p.max_broj_prodaja; i++){
                delete prodajedeep[i];    
            }
            delete[] prodajedeep;
            
        }
        throw;
    }
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&p) {
    if (this == &p) 
        return *this;
    
    max_broj_prodaja = p.max_broj_prodaja;
    broj_prodaja = p.broj_prodaja;
    prodaje = p.prodaje;
    p.prodaje = nullptr;
    
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,
    const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    
    if(broj_prodaja == max_broj_prodaja) 
        throw std::range_error("Dostignut maksimalni broj prodaja");
    
    try {
        prodaje[broj_prodaja] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
    }
    catch (std::bad_alloc) {
        throw;
    }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
    const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    
    if(broj_prodaja == max_broj_prodaja) 
        throw std::range_error("Dostignut maksimalni broj prodaja");
    
    try {
      prodaje[broj_prodaja] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    }
    catch (std::bad_alloc) {
        throw;
    }
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    
    if(broj_prodaja == max_broj_prodaja) 
        throw std::range_error("Dostignut maksimalni broj prodaja");
        
    prodaje[broj_prodaja] = std::move(prodaja);    
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(prodaje, prodaje+broj_prodaja, [datum] (Prodaja *p1) {
            if(p1 -> DajDatumProdaje().DajGodinu() == datum.DajGodinu() && p1 -> DajDatumProdaje().DajMjesec() == datum.DajMjesec() && p1 -> DajDatumProdaje().DajDan() == datum.DajDan())
                return true;
            return false;    
            });
}

Prodaja &Prodaje::DajNajranijuProdaju() {
    if (broj_prodaja == 0)
        throw std::domain_error ("Nema registriranih prodaja");
    return **std::min_element(prodaje, prodaje+broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        if (p1 -> DajDatumProdaje().DajGodinu() != p2 -> DajDatumProdaje().DajGodinu())
            return p1 -> DajDatumProdaje().DajGodinu() < p2 -> DajDatumProdaje().DajGodinu();
        if (p1 -> DajDatumProdaje().DajMjesec() != p2 -> DajDatumProdaje().DajMjesec())
            return p1 -> DajDatumProdaje().DajMjesec() <p2 -> DajDatumProdaje().DajMjesec();
        return p1 -> DajDatumProdaje().DajDan() < p2 -> DajDatumProdaje().DajDan();    
    });    
}

Prodaja Prodaje::DajNajranijuProdaju() const {
    if (broj_prodaja == 0)
        throw std::domain_error ("Nema registriranih prodaja");
    return **std::min_element(prodaje, prodaje+broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        if (p1 -> DajDatumProdaje().DajGodinu() != p2 -> DajDatumProdaje().DajGodinu())
            return p1 -> DajDatumProdaje().DajGodinu() > p2 -> DajDatumProdaje().DajGodinu();
        if (p1 -> DajDatumProdaje().DajMjesec() != p2 -> DajDatumProdaje().DajMjesec())
            return p1 -> DajDatumProdaje().DajMjesec() > p2 -> DajDatumProdaje().DajMjesec();
        return p1 -> DajDatumProdaje().DajDan() > p2 -> DajDatumProdaje().DajDan();    
    });    
}

Prodaja &Prodaje::DajNajskupljuProdaju() {
    if (broj_prodaja == 0) 
        throw std::domain_error ("Nema registriranih prodaja");
    return **std::max_element(prodaje, prodaje + broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        return p1 -> DajCijenuStana() > p2 -> DajCijenuStana();             
    });    
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
    if (broj_prodaja == 0) 
        throw std::domain_error ("Nema registriranih prodaja");
    return **std::max_element(prodaje, prodaje + broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        return p1 -> DajCijenuStana() > p2 -> DajCijenuStana();     // Provjeriti u ove 4 fje, valja li < > znakovi
    });    
}

void Prodaje::IsprazniKolekciju() {
    for (int i = 0; i < broj_prodaja; i++) {
        delete prodaje[i];
        prodaje[i] = nullptr;
    }                        
    broj_prodaja = 0;
}

void Prodaje::ObrisiNajranijuProdaju() {
    if(broj_prodaja == 0) 
        throw std::range_error ("Prazna kolekcija");
    Prodaja *prodaja = &DajNajranijuProdaju(); 
    for (int i = 0; i < broj_prodaja; i++) {
        if (prodaje[i] == prodaja) {
            delete prodaje[i];
            prodaje[i] = nullptr;
            broj_prodaja--;
        }    
    }
    std::sort(prodaje, prodaje + max_broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        if(p1)
            return true;
        return false;
    });
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    for (int i = 0; i < broj_prodaja; i++) {
        if(prodaje[i] -> DajImeAgenta() == ime_agenta) {
            delete prodaje[i];
            prodaje[i] = nullptr;
            broj_prodaja--;
        }    
    }
    std::sort(prodaje, prodaje + max_broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        if(p1)
            return true;
        return false;    
    });
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    for (int i = 0; i < broj_prodaja; i++) {
        if(prodaje[i] -> DajDatumProdaje().DajGodinu() == datum.DajGodinu() && prodaje[i] -> DajDatumProdaje().DajMjesec() == datum.DajMjesec() && prodaje[i] -> DajDatumProdaje().DajDan() == datum.DajDan()) {
            delete prodaje[i];
            prodaje[i] = nullptr;
            broj_prodaja--;
        }    
    }
    std::sort(prodaje, prodaje + max_broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        if(p1)
            return true;
        return false;    
    });
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    std::sort(prodaje, prodaje + broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        return p1 -> DajImeKupca() < p2 -> DajImeKupca();
    });
    for (int i = 0; i < broj_prodaja; i++) 
        if(prodaje[i] -> DajDatumProdaje().DajGodinu() == datum.DajGodinu() && prodaje[i] -> DajDatumProdaje().DajMjesec() == datum.DajMjesec() && prodaje[i] -> DajDatumProdaje().DajDan() == datum.DajDan())
            prodaje[i] -> Ispisi();
}

void Prodaje::IspisiSveProdaje() const {
    std::sort(prodaje, prodaje + broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        if (p1 -> DajDatumProdaje().DajGodinu() == p2 -> DajDatumProdaje().DajGodinu() && p1 -> DajDatumProdaje().DajMjesec() == p2 -> DajDatumProdaje().DajMjesec() && p1 -> DajDatumProdaje().DajDan() == p2 -> DajDatumProdaje().DajDan())
            return p1 -> DajImeKupca() < p2 -> DajImeKupca();
        if (p1 -> DajDatumProdaje().DajGodinu() != p2 -> DajDatumProdaje().DajGodinu())
            return p1 -> DajDatumProdaje().DajGodinu() < p2 -> DajDatumProdaje().DajGodinu();
        if (p1 -> DajDatumProdaje().DajMjesec() != p2 -> DajDatumProdaje().DajMjesec())
            return p1 -> DajDatumProdaje().DajMjesec() <p2 -> DajDatumProdaje().DajMjesec();
        return p1 -> DajDatumProdaje().DajDan() < p2 -> DajDatumProdaje().DajDan();   
    });
    for (int i = 0; i < broj_prodaja; i++) 
        prodaje[i] -> Ispisi();
}

int main ()
{   
    return 0;
}
