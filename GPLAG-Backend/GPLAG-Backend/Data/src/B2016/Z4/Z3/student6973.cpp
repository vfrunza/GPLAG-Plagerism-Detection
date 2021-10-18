/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <memory>
#include <algorithm>

class Datum {
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const;
    int DajMjesec() const;
    int DajGodinu() const;
    void Ispisi() const;
};

void Datum::Postavi(int dan, int mjesec, int godina) {
    int mjeseci[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) mjeseci[1]++;
    if(dan < 1 || dan > mjeseci[mjesec - 1] || mjesec < 1 || mjesec > 12 || godina < 1) throw std::domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

Datum::Datum(int dan, int mjesec, int godina) {
    Postavi(dan, mjesec, godina);
}

int Datum::DajDan() const {
    return dan;
}

int Datum::DajMjesec() const {
    return mjesec;
}

int Datum::DajGodinu() const {
    return godina;
}

void Datum::Ispisi() const {
    std::cout << dan << "/" << mjesec << "/" << godina << std::endl;
}

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const;
    Datum DajDatumRodjenja() const;
    void Ispisi() const;
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)  {
    for(int i = 0; i < ime_i_prezime.size(); i++) {
        if((ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z') || (ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z') ||
        (ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9') || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '-' ||
        ime_i_prezime[i] == 39 ) continue; 
        else throw std::domain_error("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime = ime_i_prezime;
    Kupac::datum_rodjenja = datum_rodjenja;
}

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodjenja(datum_rodjenja) {
    for(int i = 0; i < ime_i_prezime.size(); i++) {
        if((ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z') || (ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z') ||
        (ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9') || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '-' ||
        ime_i_prezime[i] == 39 ) continue; 
        else throw std::domain_error("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime = ime_i_prezime;
}

std::string Kupac::DajImePrezime() const {
    return ime_i_prezime;
}

Datum Kupac::DajDatumRodjenja() const {
    return datum_rodjenja;
}

void Kupac::Ispisi() const {
    std::cout << ime_i_prezime << "(" << datum_rodjenja.DajDan() << "/" << datum_rodjenja.DajMjesec() << "/" << datum_rodjenja.DajGodinu() << ")" << std::endl;
}

class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const;
    int DajSprat() const;
    int DajBrojSoba() const;
    bool DajNamjesten() const;
    double DajKvadraturu() const;
    void Ispisi() const;
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa = adresa; Stan::sprat = sprat; Stan::broj_soba = broj_soba; Stan::namjesten = namjesten; Stan::kvadratura = kvadratura;
}

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
}

std::string Stan::DajAdresu() const {
    return adresa;
}

int Stan::DajSprat() const {
    return sprat;
}

int Stan::DajBrojSoba() const {
    return broj_soba;
}

bool Stan::DajNamjesten() const {
    return namjesten;
}

double Stan::DajKvadraturu() const {
    return kvadratura;
}

void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
    if(broj_soba == 1) std::cout << " sobu.";
    else if(broj_soba == 2 || broj_soba == 3 || broj_soba == 4) std::cout << " sobe.";
    else std::cout << " soba.";
    std::cout << std::endl;
    std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(namjesten == true) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}

class Prodaja {
    std::string ime_agenta;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
const Kupac &kupac_stana, const Stan &kupljeni_stan):datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan){
    Prodaja::ime_agenta = ime_agenta_prodaje;
    Prodaja::cijena_stana =cijena_stana;
    
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata): datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca),
    kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
        ime_agenta = ime_agenta_prodaje;
    }
    
void Prodaja::PromijeniKupca(const Kupac &novi_kupac) {
    kupac_stana = novi_kupac;
}

void Prodaja::PromijeniStan(const Stan &novi_stan) {
    kupljeni_stan = novi_stan;
}

void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum){
    datum_prodaje = novi_datum;
}

void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena){
    cijena_stana = nova_cijena;
}

void Prodaja::PomjeriDanUnaprijed() {
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(datum_prodaje.DajGodinu() % 4 == 0 && datum_prodaje.DajGodinu() % 100 != 0 || datum_prodaje.DajGodinu() % 400 == 0)
    brojdana[1]++;
    int d(datum_prodaje.DajDan()), m(datum_prodaje.DajMjesec()), g(datum_prodaje.DajGodinu());
    d++;
    if(d > brojdana[m - 1]) d = 1, m++;
    if(m > 12) m = 1, g++;
    datum_prodaje.Postavi(d,m,g);
}

void Prodaja::PomjeriDanUnazad() {
    int brojdana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(datum_prodaje.DajGodinu() % 4 == 0 && datum_prodaje.DajGodinu() % 100 != 0 || datum_prodaje.DajGodinu() % 400 == 0)
    brojdana[1]++;
    int d(datum_prodaje.DajDan()), m(datum_prodaje.DajMjesec()), g(datum_prodaje.DajGodinu());
    d--;
    if(d < 1){
        m--;
        if(m > 0) d = brojdana[m - 1]; 
    } 
    if(m < 0) {
        m = 12; 
        g--;
        d = 31;
    }
    datum_prodaje.Postavi(d,m,g);
}

std::string Prodaja::DajImeAgenta() const {
    return ime_agenta;
}

std::string Prodaja::DajImeKupca() const {
    return kupac_stana.DajImePrezime();
}

Datum Prodaja::DajDatumProdaje() const {
    return datum_prodaje;
}

double Prodaja::DajCijenuStana() const {
    return cijena_stana;
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if(p1.datum_prodaje.DajGodinu() < p2.datum_prodaje.DajGodinu()) return true;
    else if(p1.datum_prodaje.DajGodinu() > p2.datum_prodaje.DajGodinu()) return false;
    else{
        if(p1.datum_prodaje.DajMjesec() < p2.datum_prodaje.DajMjesec()) return true;
        else if(p1.datum_prodaje.DajMjesec() > p2.datum_prodaje.DajMjesec()) return false;
        else{
            if(p1.datum_prodaje.DajDan() < p2.datum_prodaje.DajDan()) return true;
            else return false;
        }
    }
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    if(p1.cijena_stana > p2.cijena_stana) return true;
    else return false;
}

void Prodaja::Ispisi() const {
    std::cout << "Ime agenta: " << ime_agenta << std::endl;
    std::cout << "Ime kupca: "; kupac_stana.Ispisi();
    std::cout << "Zakazani datum prodaje: "; datum_prodaje.Ispisi();
    std::cout << "Cijena stana: " << cijena_stana << std::endl;
    std::cout << "Informacije o stanu: " << std::endl; kupljeni_stan.Ispisi();
}

class Prodaje {
    Prodaja** niz=nullptr;
    int velicina, max_velicina;
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana ,int dan_prodaje,
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
};

Prodaje::Prodaje(int max_broj_prodaja):niz(new Prodaja*[max_broj_prodaja]) {
    try{
        
        for(int i = 0; i < max_broj_prodaja; i++) {
            niz[i] = nullptr;
        }
        velicina = 0;
        max_velicina = max_broj_prodaja;
    }
    catch(...) {
        throw;
    }
}

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja){
    try{
        niz = new Prodaja*[spisak_prodaja.size()];
        velicina = spisak_prodaja.size();
        max_velicina = velicina;
        for(int i = 0; i < spisak_prodaja.size(); i++) {
            niz[i] = nullptr;
        }
        try{
            int brojac(0);
            for(auto it=spisak_prodaja.begin(); it != spisak_prodaja.end(); it++) {
                niz[brojac++] = new Prodaja(*it);
            }
        }
        catch(...) {
            for(int i = 0; i < spisak_prodaja.size(); i++) {
                delete niz[i];
            }
            delete[]  niz;
            niz = nullptr;
            velicina = 0;
            throw;
        }
    }
    catch(...) {
        throw;
    }
}

Prodaje::~Prodaje() {
    for(int i = 0; i < velicina; i++) {
        delete niz[i];
    }
    delete[]  niz;
}

Prodaje::Prodaje(const Prodaje &prodaje) {
    try{
        niz = new Prodaja*[prodaje.velicina];
        velicina = prodaje.velicina;
        max_velicina = prodaje.max_velicina;
        for(int i = 0; i < max_velicina; i++) {
            niz[i] = nullptr;
        }
        try{
            for(int i = 0; i < velicina; i++) {
                niz[i] = new Prodaja(*(prodaje.niz[i]));
            }
        }
        catch(...) {
            for(int i = 0; i < max_velicina; i++) {
                delete niz[i];
            }
            delete[] niz;
            niz = nullptr;
            velicina = 0;
            throw;
        }
    }
    catch(...) {
        throw;
    }
}

Prodaje::Prodaje(Prodaje &&prodaje) {
    niz = prodaje.niz;
    max_velicina = prodaje.max_velicina;
    velicina = prodaje.velicina;
}

Prodaje& Prodaje::operator =(const Prodaje &prodaje) {
    if(this == &prodaje) {
        return *this;
    }
    for(int i = 0; i < max_velicina; i++) {
        delete niz[i];
    }
    delete[] niz;
    niz = nullptr;
    try{
        niz = new Prodaja*[prodaje.max_velicina];
        velicina = prodaje.velicina;
        max_velicina = prodaje.max_velicina;
        for(int i = 0; i < max_velicina; i++) niz[i] = nullptr;
        try{
            for(int i = 0; i < velicina; i++) {
                niz[i] = new Prodaja(*(prodaje.niz[i]));
            }
        }
        catch(...) {
            for(int i = 0; i < max_velicina; i++) {
                delete niz[i];
            }
            delete[] niz;
            niz = nullptr;
            velicina = 0;
        }
    }
    catch(...) {
        throw;
    }
    return *this;
}

Prodaje& Prodaje::operator =(Prodaje &&prodaje) {
    if(this == &prodaje) {
        return *this;
    }
    for(int i = 0; i < max_velicina; i++) {
        delete niz[i];
    }
    delete[] niz;
    niz = nullptr;
    niz = prodaje.niz;
    velicina = prodaje.velicina;
    max_velicina = prodaje.max_velicina;
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,
 double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
const Stan &kupljeni_stan){
    /*if(velicina >= max_velicina) {
        Prodaja** novi;
        try{
            novi = new Prodaja*[++max_velicina];
            for(int i = 0; i < max_velicina; i++) {
                novi[i] = nullptr;
            }
            try{
                for(int i = 0; i < velicina; i++) {
                    novi[i] = new Prodaja(*niz[i]);
                }
                novi[velicina++] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
            }
            catch(...) {
                for(int i = 0; i < max_velicina; i++) {
                    delete novi[i];
                }
                delete[] novi;
                novi = nullptr;
            }
        }
        catch(...) {
            throw;
        }
        niz = novi;
        return;
    }*/
    if(velicina >= max_velicina) throw std::range_error("Dostignut maksimalni broj prodaja");
    niz[velicina++] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana ,int dan_prodaje,
int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
 const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
 int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
     /*if(velicina >= max_velicina) {
        Prodaja** novi;
        try{
            novi = new Prodaja*[++max_velicina];
            for(int i = 0; i < max_velicina; i++) {
                novi[i] = nullptr;
            }
            try{
                for(int i = 0; i < velicina; i++) {
                    novi[i] = new Prodaja(*niz[i]);
                }
                novi[velicina++] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje,
                ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
            }
            catch(...) {
                for(int i = 0; i < max_velicina; i++) {
                    delete novi[i];
                }
                delete[] novi;
                novi = nullptr;
            }
        }
        catch(...) {
            throw;
        }
        niz = novi;
        return;
    }*/
    if(velicina >= max_velicina) throw std::range_error("Dostignut maksimalni broj prodaja");
    niz[velicina++] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje,
    ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
 }

void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    if(velicina >= max_velicina) throw std::range_error("Dostignut maksimalni broj prodaja");
    niz[velicina++] = prodaja;
    prodaja = nullptr;
}

int Prodaje::DajBrojProdaja() const{
    return velicina;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(niz, niz + velicina, [datum](Prodaja* x)
    {
        if((*x).DajDatumProdaje().DajDan() == datum.DajDan() && (*x).DajDatumProdaje().DajMjesec() == datum.DajMjesec() && 
        (*x).DajDatumProdaje().DajGodinu() == datum.DajGodinu())
            return true;
        return false;
    });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return std::count_if(niz, niz + velicina, [ime_agenta](Prodaja* x)
    {
        if((*x).DajImeAgenta() == ime_agenta) return true;
        return false;
    });
}

/*Prodaja &Prodaje::DajNajranijuProdaju() {
    Datum najraniji = niz.DajDatumProdaje();
    for(int i = niz; i < niz + velicina; i++) {
        if(niz[i].DajDatumProdaje().DajGodinu() < najraniji.DajGodinu()) najraniji = niz[i].DajDatumProdaje();
        else if(niz[i].DajDatumProdaje().DajGodinu() == najraniji.DajGodinu() && niz[i].DajDatumProdaje().DajMjesec() < najraniji.DajMjesec()) 
            najraniji = niz[i].DajDatumProdaje();
        else if(niz[i].DajDatumProdaje().DajGodinu() == najraniji.DajGodinu() && niz[i].DajDatumProdaje().DajMjesec() == najraniji.DajMjesec() && 
        niz[i].DajDatumProdaje().DajDan() < najraniji.DajDan()) najraniji = niz[i].DajDatumProdaje();
    }
    return najraniji;
}*/

/*Prodaja Prodaje::DajNajranijuProdaju() const {
    Prodaja najraniji(*niz[0]);
    return std::min_element(niz, niz + velicina, [&najraniji](int x){
        if(x->DajDatumProdaje().DajGodinu() < najraniji.DajDatumProdaje().DajGodinu()) najraniji = *x;
        else if(x->DajDatumProdaje().DajGodinu() == najraniji.DajDatumProdaje().DajGodinu() && x->DajDatumProdaje().DajMjesec() < najraniji.DajDatumProdaje().DajMjesec()) 
            najraniji = *x;
        else if(x->DajDatumProdaje().DajGodinu() == najraniji.DajDatumProdaje().DajGodinu() && x->DajDatumProdaje().DajMjesec() == najraniji.DajDatumProdaje().DajMjesec() && 
        x->DajDatumProdaje().DajDan() < najraniji.DajDatumProdaje().DajDan()) najraniji = *x;
    })
        
    }
    return najraniji;
}*/

int main ()
{
    Stan s("Remze Ahmetovica" , 3, 3, true, 150);
    s.Ispisi();
	return 0;
}