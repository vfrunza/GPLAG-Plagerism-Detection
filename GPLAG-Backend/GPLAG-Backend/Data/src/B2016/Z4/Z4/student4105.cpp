/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <list>
#include <vector>

void IspravnostDatuma(int d, int m, int g) {
     if(d<=0 || d>31 || m<=0 || m>12 || g<=0 ) throw std::domain_error("Neispravan datum");
     int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      // prestupne godine
      if( (g%4==0 && g%100==0) || g%400==0) 
        broj_dana[1]++;
     if(d>broj_dana[m-1]) throw std::domain_error("Neispravan datum");
}

class Datum {
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) : dan(dan), mjesec(mjesec), godina(godina) {
        IspravnostDatuma(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina) {
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
        
        IspravnostDatuma(dan,mjesec,godina);
    }
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
};

void IspravnostImenaIPrezimena (std::string ime_i_prezime) {
    
    if((char(ime_i_prezime[0]))==' ' || (char(ime_i_prezime[0]))=='\n') throw std::domain_error("Neispravno ime i prezime");
    for(int i=0; i<ime_i_prezime.length(); i++) {
        if(!( ( (char(ime_i_prezime[i]))>='a' && (char(ime_i_prezime[i]))<='z') || ((char(ime_i_prezime[i]))>='A' && (char(ime_i_prezime[i]))<='Z') || (char(ime_i_prezime[i]))==' '))
            throw std::domain_error("Neispravno ime i prezime");
    }
}

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : ime_i_prezime(ime_i_prezime), datum_rodjenja(datum_rodjenja) {
        IspravnostImenaIPrezimena(ime_i_prezime);
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
        this->ime_i_prezime = ime_i_prezime;
        this->datum_rodjenja = datum_rodjenja;
        IspravnostImenaIPrezimena(ime_i_prezime);
    }
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

class Stan {
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) : adresa(adresa), sprat(sprat),
        broj_soba(broj_soba), namjesten(namjesten), kvadratura(kvadratura) {
            if(sprat<0 || broj_soba<0 || kvadratura<0 || namjesten<0) throw std::domain_error("Neispravan unos podataka");
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        this->adresa = adresa;
        this->sprat = sprat;
        this->broj_soba = broj_soba;
        this->namjesten = namjesten;
        this->kvadratura = kvadratura;
        if(sprat<0 || broj_soba<0 || kvadratura<0 || namjesten<0) throw std::domain_error("Neispravan unos podataka");
    }
    std::string DajAdresu() const {
        return adresa;
    }
    int DajSprat() const {
        return sprat;
    }
    int DajBrojSoba() const {
        return broj_soba;
    }
    bool DajNamjesten() const {
        return namjesten;
    }
    double DajKvadraturu() const {
        return kvadratura;
    }
    void Ispisi() const {
        
        if(broj_soba==1) 
        std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba << " sobu." << std::endl;
        else if(broj_soba==2 || broj_soba==3 || broj_soba==4)
        std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba << " sobe." << std::endl;
        else
        std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba << " soba." << std::endl;
        
        if(namjesten==true)
        std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan je namjesten." << std::endl;
        else std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan nije namjesten." << std::endl;
    }
};

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) :
        ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : 
        ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca),
        kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {
    }
    void PromijeniKupca(const Kupac &novi_kupac) {
        kupac_stana = novi_kupac;
    }
    void PromijeniStan(const Stan &novi_stan) {
        kupljeni_stan = novi_stan;
    }
    void PromijeniDatumKupovine(const Datum &novi_datum) {
        datum_prodaje = novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        cijena_stana = nova_cijena;
    }
    void PomjeriDanUnaprijed() {
        // broj dana u mjesecu
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int g, m, d;
        g = datum_prodaje.DajGodinu();
        m = datum_prodaje.DajMjesec();
        d = datum_prodaje.DajDan();
        // prestupne godine
        if( (g%4==0 && g%100==0) || g%400==0) 
        broj_dana[1]++;
        d++;
        if(d>broj_dana[m-1]) { d = 1; m++; }
        if(m > 12) { m = 1; g++; }
        datum_prodaje.Postavi(d,m,g);
    }
    void PomjeriDanUnazad() {
        // broj dana u mjesecu
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int g, m, d;
        g = datum_prodaje.DajGodinu();
        m = datum_prodaje.DajMjesec();
        d = datum_prodaje.DajDan();
        // prestupne godine
        if( (g%4==0 && g%100==0) || g%400==0) 
        broj_dana[1]++;
        d--;
        if(d==0) { d = broj_dana[m-1] ; m--; }
        if(m<1) { m = 12; g--; }
        datum_prodaje.Postavi(d,m,g);
    }
    std::string DajImeAgenta() const {
        return ime_agenta_prodaje;
    }
    std::string DajImeKupca() const {
        return kupac_stana.DajImePrezime();
    }
    Datum DajDatumProdaje() const {
        return datum_prodaje;
    }
    double DajCijenuStana() const {
        return cijena_stana;
    }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
        
        // ako su prodani iste godine
        if(p1.datum_prodaje.DajGodinu()==p2.datum_prodaje.DajGodinu()) {
            // ako su prodani u različitim mjesecima
            if(p1.datum_prodaje.DajMjesec()<p2.datum_prodaje.DajMjesec()) return true;
            else return false;
            // ako su prodani iste godine u istom mjesecu
            if(p1.datum_prodaje.DajMjesec()==p2.datum_prodaje.DajMjesec()) {
                if(p1.datum_prodaje.DajDan()<p2.datum_prodaje.DajDan()) return true;
                else return false;
            }
        }
        // ako su prodani u razlicitim godinama
        if(p1.datum_prodaje.DajGodinu()<p2.datum_prodaje.DajGodinu()) return true;
        else return false;
    }
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
        if(p1.cijena_stana>p2.cijena_stana) return true;
        else return false;
    }
    void Ispisi() const {
        std::cout << std::setw(28) << std::left << "Ime agenta:" << std::setw(10) << ime_agenta_prodaje << std::endl;
        std::cout << std::setw(28) << std::left << "Ime kupca:" << std::setw(10);
        kupac_stana.Ispisi();
        std::cout << std::endl;
        std::cout << std::setw(28) << std::left << "Zakazani datum prodaje:" << std::setw(10);
        datum_prodaje.Ispisi();
        std::cout << std::endl << std::setw(28) << std::left << "Cijena stana:" << std::setw(10) << cijena_stana << std::endl;
        std::cout << std::setw(28) << std::left << "Informacije o stanu:" << std::endl;
        kupljeni_stan.Ispisi();
    }
};

class Prodaje {
    int max_broj_prodaja;
    
public:

    // implementirati izvan klase
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje &&prodaje);
    
    // throw std::range_error("Dostignut maksimalni broj prodaja");
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, 
    const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
   
    // count_if iz bibiloteke algorithm
    int DajBrojProdaja() const;
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    
    // min_element i max_element iz bibiloteke algorithm - throw std::domain_error("Nema registriranih prodaja");
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    
    // throw std::range_error("Prazna kolekcija");
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    
    // sortirati u rastućem poretku po datumu - ako ih ima više na isti datum sortirati po imenu kupca
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

int main() {
     
   
}