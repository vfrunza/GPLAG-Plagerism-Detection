#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <algorithm>

class Datum {
    int d, m, g;
public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return d; }
    int DajMjesec() const { return m; }
    int DajGodinu() const { return g; }
    void Ispisi() const { std::cout << d << "/" << m << "/" << g; }
};
void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 4 != 0) || (godina % 400 == 0)) broj_dana[mjesec-1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    d = dan; m = mjesec; g = godina;
}
bool Prije(const Datum &dat1, const Datum &dat2) {
    if(dat1.DajGodinu() == dat2.DajGodinu()) {
        if(dat1.DajMjesec() == dat2.DajMjesec()) return dat1.DajDan() < dat2.DajDan();
        return dat1.DajMjesec() < dat2.DajMjesec();
    }
    return dat1.DajGodinu() < dat2.DajGodinu();
}

class Kupac {
    std::string ime;
    Datum dat;
    static void TestImena(const std::string &s);
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : dat(datum_rodjenja) {
        TestImena(ime_i_prezime);
        ime = ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime; }
    Datum DajDatumRodjenja() const { return dat; }
    void Ispisi() const {
        std::cout << ime << " (";
        dat.Ispisi();
        std::cout << ")";
    }
};
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    TestImena(ime_i_prezime);
    ime = ime_i_prezime;
    dat.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
}
void Kupac::TestImena(const std::string &s) {
    for(char c : s) {
        c = std::toupper(c);
        if(!((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '-' || c == ' ' || c == '\''))
            throw std::domain_error("Neispravno ime i prezime");
    }
}
class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, 
        double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten,
        double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
};
Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, 
    double kvadratura) : adresa(adresa) {
        if(sprat < 0 || broj_soba < 0 || kvadratura < 0) 
            throw std::domain_error("Neispravan unos podataka");
        Stan::sprat = sprat; Stan::broj_soba = broj_soba; 
        Stan::namjesten = namjesten; Stan::kvadratura = kvadratura;
    }
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
        throw std::domain_error("Neispravan unos podataka");
    Stan::sprat = sprat; Stan::broj_soba = broj_soba;
    Stan::namjesten = namjesten; Stan::kvadratura = kvadratura;
}
void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima ";
    if(broj_soba == 1) std::cout << " sobu." << std::endl;
    if(broj_soba == 2 || broj_soba == 3 || broj_soba == 4) std::cout << " sobe" << std::endl;
    else std::cout << " soba" << std::endl;
    std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(namjesten) std::cout << "nije namjesten";
    else std::cout << "je namjesten";
}
class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
        const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : 
        ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(datum_prodaje), 
        kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {}
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, 
        int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
        const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) { kupac_stana = novi_kupac; }
    void PromijeniStan(const Stan &novi_stan) { kupljeni_stan = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datum_prodaje = novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena_stana = nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const { return kupac_stana.DajImePrezime(); }
    Datum DajDatumProdaje() const { return {datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()}; }
    double DajCijenuStana() const { return cijena_stana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) { return Prije(p1.datum_prodaje, p2.datum_prodaje); }
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) { return p1.cijena_stana > p2.cijena_stana; }
    void Ispisi() const;
};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, 
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : 
    ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje),
    kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}
    
void Prodaja::PomjeriDanUnaprijed() {
    int godina(datum_prodaje.DajGodinu()), mjesec(datum_prodaje.DajMjesec()), dan(datum_prodaje.DajDan());
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    dan++;
    if(dan > broj_dana[mjesec - 1]) { dan = 1; mjesec++; }
    if(mjesec > 12) { mjesec = 1; godina++; }
    datum_prodaje.Postavi(dan, mjesec, godina);
}
void Prodaja::PomjeriDanUnazad() {
    int godina(datum_prodaje.DajGodinu()), mjesec(datum_prodaje.DajMjesec()), dan(datum_prodaje.DajDan());
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    dan--;
    if(dan < 1 || dan < broj_dana[mjesec - 1]) {
        mjesec--;
        if(mjesec < 1) { mjesec = 1; godina--; } 
        dan = broj_dana[mjesec - 1];
    }
    datum_prodaje.Postavi(dan, mjesec, godina);
}
   
void Prodaja::Ispisi() const {
    std::cout << std::left << "Ime agenta: " << std::right << ime_agenta_prodaje << std::endl << std::left << "Ime kupca: ";
    kupac_stana.Ispisi();
    std::cout << "Zakazani datum prodaje: " << std::right;
    datum_prodaje.Ispisi();
    std::cout << "Cijena stana: " << std::right << cijena_stana << std::endl 
    << "Informacije o stanu: " << std::endl; kupljeni_stan.Ispisi();
}

class Prodaje {
    int stanje;
    std::vector<std::shared_ptr<Prodaja>> pok;
public:
    explicit Prodaje() : stanje(0) {};
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, 
        const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, 
        int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
        const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata); 
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const { return stanje; }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajProdaju(int redni_broj);
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
    Prodaja *begin() const { return *pok; }
    Prodaja *end() const { return *pok + stanje; }
};
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : stanje(spisak_prodaja.size()) {
    for(Prodaja x : spisak_prodaja) pok.push_back(std::make_shared<Prodaja>(x));
}
Prodaje::~Prodaje() {
    for(int i=0; i<stanje; i++) delete pok[i];
    delete[] pok;
}
Prodaje::Prodaje(const Prodaje &prodaje) {
    stanje = prodaje.stanje;
    kapacitet = prodaje.kapacitet;
    pok = new Prodaja*[kapacitet];
    for(int i=0; i<stanje; i++) pok[i] = new Prodaja(*prodaje.pok[i]);
}
Prodaje::Prodaje(Prodaje &&prodaje) {
    stanje = prodaje.stanje;
    kapacitet = prodaje.kapacitet;
    pok = prodaje.pok;
    prodaje.pok = nullptr; prodaje.stanje = 0;
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje) {
    if(&prodaje != this) {
        for(int i=0; i<stanje; i++) delete pok[i];
        delete[] pok;
        stanje = prodaje.stanje; 
        pok = new Prodaja*[kapacitet];
        for(int i=0; i<stanje; i++) pok[i] = new Prodaja(*prodaje.pok[i]);
        
    }
    return *this;
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje) {
    if(&prodaje != this) {
        for(int i=0; i<stanje; i++) delete pok[i];
        delete[] pok;
        stanje = prodaje.stanje;
        kapacitet = prodaje.kapacitet;
        pok = prodaje.pok;
        prodaje.pok = nullptr; prodaje.stanje = 0;
    }
    return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, 
    const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    pok[stanje++] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, 
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
    const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    pok[stanje++] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca,
    datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    pok[stanje++] = prodaja;   
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(this->begin(), this->end(), [datum] (const Prodaja p) {
        return  p.DajDatumProdaje().DajDan() == datum.DajDan() && 
        p.DajDatumProdaje().DajMjesec() == datum.DajMjesec() && 
        p.DajDatumProdaje().DajGodinu() == datum.DajGodinu();
    });
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    return *std::min(this->begin(), this->end(), [] (const Prodaja *p1, const Prodaja *p2) { 
        return Prije(p1->DajDatumProdaje(), p2->DajDatumProdaje()); });
}
Prodaja &Prodaje::DajNajranijuProdaju() {
    return *std::min(this->begin(), this->end(), [] (const Prodaja *p1, const Prodaja *p2) { 
        return Prije(p1->DajDatumProdaje(), p2->DajDatumProdaje()); });
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    if(stanje == 0) throw std::domain_error("Nema registriranih prodaja");
    return *std::max(this->begin(), this->end(), [] (const Prodaja *p1, const Prodaja *p2) { 
        return p1->DajCijenuStana() > p2->DajCijenuStana(); });
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(stanje == 0) throw std::domain_error("Nema registriranih prodaja");
    return *std::max(this->begin(), this->end(), [] (const Prodaja *p1, const Prodaja *p2) { 
        return p1->DajCijenuStana() > p2->DajCijenuStana(); });
}
Prodaja &Prodaje::DajProdaju(int redni_broj) { 
    if(redni_broj < 0 || redni_broj > stanje) throw "Izuzetak";
    return *pok[redni_broj-1];
}
void Prodaje::IsprazniKolekciju() {
    for(int i=0; i<stanje; i++) delete pok[i];
    for(int i=0; i<stanje; i++) pok[i] = nullptr;
}
void Prodaje::ObrisiNajranijuProdaju() {
    if(stanje == 0) throw std::range_error("Prazna kolekcija");
    int mini(0);
    for(int i=1; i<stanje; i++) 
        if(Prije(pok[mini]->DajDatumProdaje(), pok[i]->DajDatumProdaje())) mini = i;
    delete pok[mini];
    pok[mini] = nullptr;
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    for(int i=0; i<stanje; i++)
        if(pok[i]->DajImeAgenta() ==  ime_agenta) {
            delete pok[i]; pok[i] = nullptr;
        }   
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    for(int i=0; i<stanje; i++) {
        int d(pok[i]->DajDatumProdaje().DajDan()), m(pok[i]->DajDatumProdaje().DajMjesec()),
        g(pok[i]->DajDatumProdaje().DajGodinu());
        if(d == datum.DajDan() && m == datum.DajMjesec() && g == datum.DajGodinu()) {
            delete pok[i]; pok[i] = nullptr;
        }
    }
}
bool Isti(const Datum &dat1, const Datum &dat2) {
    int d1(dat1.DajDan()), m1(dat1.DajMjesec()),
        g1(dat1.DajGodinu()), d2(dat2.DajDan()), 
        m2(dat2.DajMjesec()), g2(dat2.DajGodinu());
    return d1 == d2 && m1 == m2 && g1 == g2;
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    Prodaje temp(*this);
    std::sort(this->begin(), this->end(), [] (Prodaja p1, Prodaja p2) { return p1.DajImeKupca() < p2.DajImeKupca(); });
    for(int i=0; i<stanje; i++)
        if(Isti(temp.pok[i]->DajDatumProdaje(), datum)) temp.pok[i]->Ispisi();
}
void Prodaje::IspisiSveProdaje() const {
    Prodaje temp(*this);
    for(int i=0; i<stanje; i++) pok[i]->Ispisi();
}
void DodavanjeStana(std::string &adresa, int &sprat, int &broj_soba, bool &namjesten, double &kvadratura) {
    std::cout << "Unesite adresu: " << std::endl;
    std::getline(std::cin, adresa);
    std::cin.ignore(1000, '\n');
    std::cout << "Unesite sprat: " << std::endl;
    std::cin >> sprat;
    std::cout << "Unesite broj_soba" << std::endl;
    std::cin >> broj_soba;
    std::cout << "Da li je stan namjesten (1 - da, 0 - ne)" << std::endl;
    std::cin >> namjesten;
    std::cout << "Unesite kvadraturu: " << std::endl;
    std::cin >> kvadratura;
}
int main () {
   /* int opcija;
    std::cout << "Dobrodosli!" << std::endl << std::endl << "Izaberite opciju: " << std::endl 
    << "0 - kraj" << std::endl << "1 - uredjivanje stanova" << std::endl << "3 - uredjivanje prodaja" << std::endl;
    std::cin >> opcija;
    while(opcija == 1) {
        int opcija1;
        std::cout << "Izaberite opciju: " << std::endl << "0 - nazad" << std::endl << "1 - dodavanje stana" << std::endl
        << "2 - uredjivanje stanova" << std::endl << "ispis svih stanova" << std::endl << "4 - kraj" << std::endl;
        std::cin >> opcija1;
        if(opcija1 == 1) {
            for(;;) {
            try {
                std::string adresa;
                int sprat, broj_soba;
                bool namjesten;
                double kvadratura;
                DodavanjeStana(adresa, sprat, broj_soba, namjesten, kvadratura);
                Stan stan1(adresa, sprat, broj_soba, namjesten, kvadratura);
                std::cout << "Stan je uspjesno dodan!" << std::endl;
                break;
            }
            catch(std::domain_error e) {
                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.";
            }
            }
        }
    }
    */
    
    return 0;
}