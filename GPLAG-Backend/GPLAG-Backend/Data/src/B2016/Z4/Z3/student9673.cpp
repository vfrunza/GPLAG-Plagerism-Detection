#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>

bool JeLiLegalno(char znak){
    return ((znak>='a' and znak<='z') or (znak>='A' and znak<='Z')) or znak == '\'' or znak == '-' or znak == ' ';
}

class Datum {
    int dan, mjesec, godina;                                                                // prekopirano sa predavanja 9_a
public:
    Datum(int dan, int mjesec, int godina);

    void Postavi(int d, int m, int g);
    int DajDan() const { return dan; };
    int DajMjesec() const { return mjesec; };
    int DajGodinu() const { return godina; };
    void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
};

Datum::Datum(int dan, int mjesec, int godina){
    try{
        Postavi(dan, mjesec, godina);
    }
    catch(std::domain_error e){
        throw e;
    }
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 and godina % 100 != 0) or godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 or dan < 1 or mjesec < 1 or mjesec > 12 or dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum!");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);

    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImeIPrezime() const { return ime_i_prezime; }
    void Ispisi() const { std::cout << ime_i_prezime << " ("; datum_rodjenja.Ispisi(); std::cout << ")"; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
};

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum_rodjenja(1,1,2000){
    for(int i = 0; i < ime_i_prezime.length(); i++){
        if(!JeLiLegalno(ime_i_prezime[i])) throw std::domain_error("Neispravno ime i prezime");
    }
    this -> ime_i_prezime = ime_i_prezime;
    try{
        this -> datum_rodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
    }
    catch(std::domain_error e){
        throw e;
    }
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    try{
        this -> datum_rodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
        for(int i = 0; i < ime_i_prezime.length(); i++){
            if(!JeLiLegalno(ime_i_prezime[i])) throw std::domain_error("Neispravno ime i prezime");
        }
        this -> ime_i_prezime = ime_i_prezime;
    }
    catch(std::domain_error e){
        throw e;
    }
}

class Stan{
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);

    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
};

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat < 0 or broj_soba < 0 or kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    this -> adresa = adresa;
    this -> sprat = sprat;
    this -> broj_soba = broj_soba;
    this -> namjesten = namjesten;
    this -> kvadratura = kvadratura;
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat < 0 or broj_soba < 0 or kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    this -> adresa = adresa;
    this -> sprat = sprat;
    this -> broj_soba = broj_soba;
    this -> namjesten = namjesten;
    this -> kvadratura = kvadratura;
}

void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
    if(broj_soba == 2 or broj_soba == 3 or broj_soba == 4) std::cout << " sobe.";
    else std::cout << " soba.";
    std::cout << std::endl << "Kvadratura stana je " << kvadratura << " (m^2) i stan";
    if(namjesten) std::cout << " je namjesten.";
    else std::cout << " nije namjesten.";
}

class Prodaja{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
    const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,                              // konstruktori
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);

    void PromijeniStan(const Stan &novi_stan) { kupljeni_stan = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum){ datum_prodaje = novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena){ cijena_stana = nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();

    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const { return kupac_stana.DajImeIPrezime(); }
    Datum DajDatumProdaje() const { return datum_prodaje; }                                                                         // inspektori
    double DajCijenuStana() const { return cijena_stana; }
    void Ispisi() const;

    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);                                              // prijateljske funkcije
};

void Prodaja::PomjeriDanUnaprijed(){
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d(datum_prodaje.DajDan()), m(datum_prodaje.DajMjesec()), g(datum_prodaje.DajGodinu());

    if((g % 4 == 0 and g % 100 != 0) or g % 400 == 0) broj_dana[1]++;
    d++;
    if(d > broj_dana[m - 1]) m++, d = 1;
    if(m > 12) g++, m = 1;
    datum_prodaje.Postavi(d, m, g);
}

void Prodaja::PomjeriDanUnazad(){
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int d(datum_prodaje.DajDan()), m(datum_prodaje.DajMjesec()), g(datum_prodaje.DajGodinu());

    if((g % 4 == 0 and g % 100 != 0) or g % 400 == 0) broj_dana[1]++;
    d--;

    if(d < 1) m--;
    if(m == 0) d = 31;
    else d = broj_dana[m-1];
    if(m < 1) m = 12, g--;

    datum_prodaje.Postavi(d, m, g);
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
    const Kupac &kupac_stana, const Stan &kupljeni_stan) : datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan){

    try{
        for(int i = 0; i < ime_agenta_prodaje.length(); i++) if(!JeLiLegalno(ime_agenta_prodaje[i])) throw std::domain_error("Neispravno ime i prezime");
        this -> ime_agenta_prodaje = ime_agenta_prodaje;

        if(cijena_stana < 0) throw std::domain_error("Neispravan unos podataka");
        this -> cijena_stana = cijena_stana;

        this -> datum_prodaje.Postavi(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu());
        this -> kupac_stana = kupac_stana;
        this -> kupljeni_stan = kupljeni_stan;
    }
    catch(std::domain_error e){
        throw e;
    }
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.DajCijenuStana() > p2.DajCijenuStana();
}
                                                                        // prijateljske funkcije
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    Datum d1(p1.DajDatumProdaje()), d2(p2.DajDatumProdaje());

    if(d1.DajGodinu() == d2.DajGodinu()){
        if(d1.DajMjesec() == d2.DajMjesec()){
            return d1.DajDan() < d2.DajDan();
        }
        return d1.DajMjesec() < d2.DajMjesec();
    }
    return d1.DajGodinu() < d2.DajGodinu();
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,                              // konstruktori
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
    datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca),
    kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata){}

void Prodaja::Ispisi() const {
    std::cout << std::left << std::setw(35) << "Ime agenta: " << ime_agenta_prodaje << std::endl <<
    std::left << std::setw(35) << "Ime kupca: ";
    kupac_stana.Ispisi();
    std::cout << std::endl << std::left << std::setw(35) << "Zakazani datum prodaje: ";
    datum_prodaje.Ispisi();
    std::cout << std::endl << std::left << std::setw(35) << "Cijena stana: " << cijena_stana << std::endl << "Informacije o stanu:" << std::endl;
    kupljeni_stan.Ispisi();

}

class Prodaje{
    Prodaja **niz = nullptr;
    int max_br_prodaja, br_prodaja;
    int brojac_registriranih = 0;
public:
    explicit Prodaje(int max_br_prodaja) : max_br_prodaja(max_br_prodaja), br_prodaja(0){  niz = new Prodaja*[max_br_prodaja]{}; }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
                                                                                                                                        // konstruktori i desktruktor implementirani unutar klase
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator= (const Prodaje &prodaje);
    Prodaje &operator= (Prodaje &&prodaje);

    void IspisiSveProdaje() const;
    int DajBrojProdaja() const { return br_prodaja; }
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum); 
    void IspisiProdajeNaDatum(const Datum &datum) const;
    
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja &DajProdaju(int redni_broj);
    
    void ObrisiNajranijuProdaju();
    void IsprazniKolekciju();
    
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
    const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,                              
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
};


Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : niz(new Prodaja*[spisak_prodaja.size()]), max_br_prodaja(spisak_prodaja.size()), br_prodaja(spisak_prodaja.size()) {
    int i(0);
    for(auto it = spisak_prodaja.begin(); it != spisak_prodaja.end(); it++) niz[i++] = new Prodaja(*it);
}

Prodaje::~Prodaje(){
    for(int i = 0; i < max_br_prodaja; i++) delete niz[i], niz[i] = nullptr;
    delete[] niz; niz = nullptr;
}

Prodaje::Prodaje(const Prodaje &prodaje){
    niz = prodaje.niz; max_br_prodaja = prodaje.max_br_prodaja; br_prodaja = prodaje.br_prodaja;
}

Prodaje &Prodaje::operator= (const Prodaje &prodaje){
    for(int i = 0; i < max_br_prodaja; i++) delete niz[i], niz[i] = nullptr;
    delete[] niz;

    max_br_prodaja = prodaje.max_br_prodaja;
    br_prodaja = prodaje.br_prodaja;                                                                                    // operator dodjele sa postojecim primjerkom klase
    niz = new Prodaja*[max_br_prodaja]{};
    for(int i = 0; i < max_br_prodaja; i++) niz[i] = new Prodaja(*prodaje.niz[i]);
    return *this;
}

Prodaje &Prodaje::operator= (Prodaje &&prodaje){
    for(int i = 0; i < max_br_prodaja; i++) delete niz[i], niz[i] = nullptr;
    delete[] niz;
    
    max_br_prodaja = prodaje.max_br_prodaja; br_prodaja = prodaje.br_prodaja;
    niz = new Prodaja*[max_br_prodaja]{};                                                                                   // dodjela na r vrijednost
    for(int i = 0; i < max_br_prodaja; i++) niz[i] = new Prodaja(*prodaje.niz[i]);
    return *this;
}

Prodaje::Prodaje(Prodaje &&prodaje) :  niz(prodaje.niz), max_br_prodaja(prodaje.max_br_prodaja), br_prodaja(prodaje.br_prodaja){
    prodaje.niz = nullptr;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const{
    int brojac(0);
    for(int i = 0; i < br_prodaja; i++) if(niz[i] -> DajImeAgenta() == ime_agenta) brojac++;
    return brojac;
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta){
    for(int i = 0; i < br_prodaja; i++){
        if(niz[i] -> DajImeAgenta() == ime_agenta){
            delete niz[i], niz[i] = nullptr;
            br_prodaja--;
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum){
    for(int i = 0; i < br_prodaja; i++){
        Datum d(niz[i] -> DajDatumProdaje());
        if(d.DajDan() == datum.DajDan() and d.DajMjesec() == datum.DajMjesec() and d.DajGodinu() == datum.DajGodinu()){
            delete niz[i], niz[i] = nullptr;
            br_prodaja--;
        }
    }
}

Prodaja Prodaje::DajNajranijuProdaju() const{
    if(br_prodaja == 0) throw std::domain_error("Nema registriranih prodaja");
    
    auto p(std::min_element(niz, niz + br_prodaja, [](Prodaja *p1, Prodaja *p2) -> bool{
        return ProdatPrije(*p1, *p2);
    }));
    return **p;
}

Prodaja &Prodaje::DajNajranijuProdaju(){
    if(br_prodaja == 0) throw std::domain_error("Nema registriranih prodaja");
    
    auto p(std::min_element(niz, niz + br_prodaja , [](Prodaja *p1, Prodaja *p2) -> bool{
        return ProdatPrije(*p1, *p2);
    }));
    return **p;
}

Prodaja &Prodaje::DajNajskupljuProdaju(){
    if(br_prodaja == 0) throw std::domain_error("Nema registriranih prodaja");
    
    auto p(std::min_element(niz, niz + br_prodaja, [](Prodaja *p1, Prodaja *p2) -> bool{
        return SkupljiStan(*p1, *p2);
    }));
    return **p; 
}

Prodaja Prodaje::DajNajskupljuProdaju() const{
    if(br_prodaja == 0) throw std::domain_error("Nema registriranih prodaja");
    
    auto p(std::max_element(niz, niz + br_prodaja, [](Prodaja *p1, Prodaja *p2) -> bool{
        return SkupljiStan(*p1, *p2);
    }));
    return **p;
}

Prodaja &Prodaje::DajProdaju(int redni_broj){
    if(redni_broj < 0 or redni_broj > br_prodaja) throw std::range_error("Belaj");
    return *niz[redni_broj];
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja){
    if(br_prodaja == max_br_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
    
    for(int i = 0; i < br_prodaja; i++){
        if(niz[i] == nullptr){ niz[i] = prodaja; break; }
    }
    br_prodaja++;
    brojac_registriranih++;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
    const Kupac &kupac_stana, const Stan &kupljeni_stan){
        if(br_prodaja == max_br_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja");
        
        for(int i = 0; i < br_prodaja; i++){
            if(niz[i] == nullptr){
                niz[i] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
                br_prodaja++;
                brojac_registriranih++;
                break;
            }
        }
    };

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,                              
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata){
              
         if(br_prodaja == max_br_prodaja) throw std::range_error("Dostignut maksimalan broj prodaja"); 
         for(int i = 0; i < br_prodaja; i++){
             if(niz[i] == nullptr){
                 niz[i] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje,
                 ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
                 br_prodaja++;
                 brojac_registriranih++;
                 break;
             }
         }
    }

void Prodaje::IsprazniKolekciju(){
    for(int i = br_prodaja - brojac_registriranih; i < br_prodaja; i++){
        delete niz[i]; niz[i] = nullptr;
    }
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(br_prodaja == 0) throw std::range_error("Prazna kolekcija");
    
    auto p(DajNajranijuProdaju());
    for(int i = 0; i < br_prodaja; i++) {
        if(niz[i] -> DajCijenuStana() == p.DajCijenuStana() and niz[i] -> DajImeAgenta() == p.DajImeAgenta()){
            delete niz[i], niz[i] = nullptr;
            br_prodaja--;
        }
    }
}


void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const{
    std::sort(niz, niz + br_prodaja, [](Prodaja *p1, Prodaja *p2) -> bool{
        return p1 -> DajImeKupca() < p2 -> DajImeKupca();
    });
    
    for(int i = 0; i < br_prodaja; i++){
        Datum d(niz[i] -> DajDatumProdaje());
        if(d.DajDan() == datum.DajDan() and d.DajMjesec() == datum.DajMjesec() and d.DajGodinu() == datum.DajGodinu()) niz[i] -> Ispisi(); std::cout << std::endl << std::endl;
    }
}

void Prodaje::IspisiSveProdaje() const {
    std::sort(niz, niz + br_prodaja, [](Prodaja *p1, Prodaja *p2) -> bool{
        if(p1 == nullptr) return false;
        if(p2 == nullptr) return true;
        Datum dat1(p1 -> DajDatumProdaje()), dat2(p2 -> DajDatumProdaje());
        int d1(dat1.DajDan()), m1(dat1.DajMjesec()), g1(dat1.DajGodinu());
        int d2(dat2.DajDan()), m2(dat2.DajMjesec()), g2(dat2.DajGodinu());
        if(d1 == d2 and m1 == m2 and g1 == g2) return p1 -> DajImeKupca() < p2 -> DajImeKupca();
        return ProdatPrije(*p1, *p2);
    }); 
    for(int i = 0; i < br_prodaja; i++) if(niz[i]) niz[i] -> Ispisi(), std::cout << std::endl << std::endl;
}

int main ()
{
	return 0;
}


    /*
	try{
	    Datum dat(31, 12, 2017), dat1(1, 1, 2017);
	    Stan s("Hamdije Cemerlica 14", 5, 5, true, 35.45), s1("Mustafe Behmena 24", 3, 2, false, 52.2);
	    Kupac k("Mujo Mujic", {21, 9, 1982}), t("Ahmed Ahmedic", {22, 10, 1981});
	    Prodaja p("Niko Nikic", 78985, dat, k, s);
	    p.PomjeriDanUnaprijed();
	    p.PomjeriDanUnazad();
	    Prodaje p1{{"Niko Nikic", 78985, dat, k, s}};
	    
	    Prodaje p2{{"Neko", 89382, dat, k, s}, {"Niko", 32132, dat1, t, s1}};
	    p1 = std::move(p2);
	    p1.IspisiSveProdaje();  std::cout << std::endl;
	    
	    std::cout << "Evo najranije: " << std::endl;
        auto pe(p1.DajNajranijuProdaju()); pe.Ispisi(); std::cout << std::endl << std::endl;
        std::cout << "Evo najskuplje: " << std::endl;
        auto pec(p1.DajNajskupljuProdaju()); pec.Ispisi();  std::cout << std::endl;
        p1.ObrisiNajranijuProdaju(); p1.IspisiSveProdaje();
	}
	catch(std::domain_error e){
	    std::cout << e.what() << std::endl;
	}
	*/