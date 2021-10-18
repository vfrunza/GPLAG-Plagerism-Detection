/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>
class Datum {
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina);
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
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};
void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum");
    this->dan = dan; this->mjesec = mjesec; this->godina = godina;
}
class Kupac {
    std::string i_i_p;
    Datum datum_rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) 
    : datum_rodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()) {
        this->i_i_p = ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const {
        return i_i_p;
    }
    Datum DajDatumRodjenja() const {
        return datum_rodjenja;
    }
    void Ispisi() const {
        std::cout<<i_i_p<<" (";
        datum_rodjenja.Ispisi(); std::cout<<")";
    }
    friend bool Ime(char a);
};
bool Ime(char a)
{
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ' || a == '-' || a == '\'') return true;
    return false;
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) 
{
    for(int i = 0; i < ime_i_prezime.size(); i++)
        if(!Ime(ime_i_prezime[i])) throw std::domain_error("Neispravno ime i prezime");
    this->i_i_p = ime_i_prezime;
    this->datum_rodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
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
    void Ispisi() const;
};

void Stan::Ispisi() const {
        std::string dali = "je";
        std::string sobica = "soba";
        if(broj_soba == 1) sobica = "sobu";
        if(broj_soba == 2 || broj_soba == 3 || broj_soba == 4) sobica ="sobe";
        if(!namjesten) dali = "nije";
        std::cout<<"Stan se nalazi na adresi "<<adresa<<" na spratu "<<sprat<<" i ima "<<broj_soba<<" "<<sobica<<". Kvadratura stana je "
        <<kvadratura<<" (m^2) i stan "<<dali<<" namjesten";
    }
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    this->adresa = adresa; this->sprat = sprat; this->broj_soba = broj_soba; this->namjesten = namjesten; this->kvadratura = kvadratura;
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
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const {
        return ime_agenta;
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
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;

};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, 
std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
    : datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
    {
        ime_agenta = ime_agenta_prodaje;
        Prodaja::cijena_stana = cijena_stana;
    }
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
: datum_prodaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()), kupac_stana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
kupljeni_stan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu())
{
    this->ime_agenta = ime_agenta_prodaje;
    this->cijena_stana = cijena_stana;
}
void Prodaja::PomjeriDanUnaprijed()
{
    int broj_dana[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int d = datum_prodaje.DajDan();
    int m = datum_prodaje.DajMjesec();
    int g = datum_prodaje.DajGodinu();
    d++;
    if(d > 0 && d <= broj_dana[m - 1])  {
        Datum novi(d, m, g);
        PromijeniDatumKupovine(novi);
    }
    else if(d > broj_dana[m-1]) {
        d -= broj_dana[m-1]; 
        m++;
        if(m > 12) {
            g++;
            m = 1;
        }
        Datum novi(d, m, g);
        PromijeniDatumKupovine(novi);
    }
}
void Prodaja::PomjeriDanUnazad()
{
    int broj_dana[12] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int d = datum_prodaje.DajDan();
    int m = datum_prodaje.DajMjesec();
    int g = datum_prodaje.DajGodinu();
    d--;
    if(d > 0 && d <= broj_dana[m-1])
    {
        Datum novi(d, m, g);
        PromijeniDatumKupovine(novi);
    }
    else if(d < 1) {
        if(m > 1) d = broj_dana[m-2];
        else {
            m = 12; 
            g--;
            d = broj_dana[11];
        } Datum novi(d, m, g);
        PromijeniDatumKupovine(novi);
    }
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    Datum prvi = p1.DajDatumProdaje();
    Datum drugi = p2.DajDatumProdaje();
    if(prvi.DajGodinu() > drugi.DajGodinu()) return false;
    else if(prvi.DajGodinu() < drugi.DajGodinu()) return true;
    else if(prvi.DajMjesec() > drugi.DajMjesec()) return false;
    else if(prvi.DajMjesec() < prvi.DajMjesec()) return true;
    else if(prvi.DajDan() < drugi.DajDan()) return true;
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    return p1.DajCijenuStana() > p2.DajCijenuStana();
}
void Prodaja::Ispisi() const 
{
    std::cout<<std::setw(30)<<"Ime agenta: "<<DajImeAgenta()<<std::endl;
    std::cout<<std::setw(30)<<"Ime kupca: "<<DajImeKupca()<<std::endl;
    std::cout<<std::setw(30)<<"Zakazani datum prodaje: ";
    datum_prodaje.Datum::Ispisi();
    std::cout<<std::endl;
    std::cout<<std::setw(30)<<"Cijena stana: "<<DajCijenuStana()<<std::endl;
    std::cout<<std::setw(30)<<"Informacije o stanu: "<<std::endl;
    kupljeni_stan.Stan::Ispisi();
} 
class Prodaje {
    int max_broj_prodaja;
    Prodaja **prodaje2;
    int broj_reg;
    public:
    explicit Prodaje(int max_broj_prodaja) : prodaje2(new Prodaja* [max_broj_prodaja]) { Prodaje::max_broj_prodaja = max_broj_prodaja; broj_reg = 0; }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const {
        return broj_reg;
    }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta); 
    Prodaja &DajProdaju(int n);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};
void Prodaje::IspisiSveProdaje() const {
    std::sort(prodaje2, prodaje2 + broj_reg, [this](Prodaja *p, Prodaja *q) {
        auto a = p->DajDatumProdaje(); auto b = q->DajDatumProdaje();
        if(ProdatPrije(*p, *q)) return true;
        else if(a.DajDan() == b.DajDan() && a.DajMjesec() == b.DajMjesec() && a.DajGodinu() == b.DajGodinu()) {
            return p->DajImeKupca() < q->DajImeKupca();
        } return false;
    });
    for(int i = 0; i < broj_reg; i++) prodaje2[i] -> Ispisi();
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    std::sort(prodaje2, prodaje2 + broj_reg, [](Prodaja *p, Prodaja *q) {
        return p->DajImeKupca() > q->DajImeKupca();
    }); for(int i = 0; i < broj_reg; i++) {
        auto p = prodaje2[i]->DajDatumProdaje();
        if(p.DajDan() == datum.DajDan() && p.DajMjesec() == datum.DajMjesec() && p.DajGodinu() == datum.DajGodinu())
            prodaje2[i]->Ispisi();
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    auto p = std::remove_if(prodaje2, prodaje2 + broj_reg, [datum](Prodaja *pok) { auto p = pok->DajDatumProdaje(); 
    return (datum.DajDan() == p.DajDan() && datum.DajMjesec() == p.DajMjesec() && datum.DajGodinu() == p.DajGodinu());});
    broj_reg = prodaje2 + broj_reg - p;
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
   auto p = std::remove_if(prodaje2, prodaje2 + broj_reg, [ime_agenta](Prodaja *pok) { return pok->DajImeAgenta() == ime_agenta;});
   broj_reg = prodaje2 + broj_reg - p;
}
void Prodaje::ObrisiNajranijuProdaju() {
    if(broj_reg == 0) throw std::range_error("Prazna kolekcija");
    std::remove_if(prodaje2, prodaje2 + broj_reg,  [this](Prodaja *pok) { return pok == &DajNajranijuProdaju();});
    broj_reg--;
}
void Prodaje::IsprazniKolekciju() {
    for(int i = 0; i < broj_reg; i++) delete prodaje2 [i];
    delete [] prodaje2; prodaje2 = nullptr;
    broj_reg = 0;
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(broj_reg == 0) throw std::domain_error("Nema registriranih prodaja");
    return **(std::max_element(prodaje2, prodaje2 + broj_reg, [](Prodaja *p, Prodaja *q) { return p->DajCijenuStana() > q->DajCijenuStana();}));
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    if(broj_reg == 0) throw std::domain_error("Nema registriranih prodaja");
    Prodaja &a = **(std::max_element(prodaje2, prodaje2 + broj_reg, [](Prodaja *p, Prodaja *q) {
        return p->DajCijenuStana() > q->DajCijenuStana();
    })); return a;
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    if(broj_reg == 0) throw std::domain_error("Nema registriranih prodaja");
    return **(std::min_element(prodaje2, prodaje2 + broj_reg, [](Prodaja *p, Prodaja *q) {
        return ProdatPrije(*p, *q);
    }));
}
Prodaja &Prodaje::DajNajranijuProdaju() {
    if(broj_reg == 0) throw std::domain_error("Nema registriranih prodaja");
    Prodaja &a = **(std::min_element(prodaje2, prodaje2 + broj_reg, [](Prodaja *p, Prodaja *q) {
        return ProdatPrije(*p, *q);
    })); return a;
}
Prodaja &Prodaje::DajProdaju(int n) {
    if(n > broj_reg || n < 0) throw std::domain_error("Neispravan indeks prodaje");
    Prodaja &a = *prodaje2[n - 1];
    return a;
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return std::count_if(prodaje2, prodaje2 + broj_reg, [ime_agenta](Prodaja *pok) {
        return (pok->DajImeAgenta() == ime_agenta);
    });
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(prodaje2, prodaje2 + broj_reg, [datum](Prodaja *pok) { auto pom = pok->DajDatumProdaje(); 
    return (pom.DajDan() == datum.DajDan() && pom.DajMjesec() == datum.DajMjesec() && pom.DajGodinu() == datum.DajGodinu()); });
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje) {
    max_broj_prodaja = prodaje.max_broj_prodaja;
    broj_reg = prodaje.broj_reg;
    prodaje2 = std::move(prodaje.prodaje2);
    return *this;
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje) {
    if(&prodaje != this) {
        for(int i = 0; i < broj_reg; i++)
            delete prodaje2[i];
        broj_reg = prodaje.broj_reg;
    } return *this;
}
Prodaje::Prodaje(Prodaje &&prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), prodaje2(new Prodaja*[max_broj_prodaja]{})
{
    broj_reg = prodaje.broj_reg;
    try {
        for(int i = 0; i < broj_reg; i++)
            prodaje2[i] = new Prodaja(*prodaje.prodaje2[i]);
    }
    catch(...) {
        for(int i = 0; i < broj_reg; i++)
            delete prodaje2[i];
        delete [] prodaje2;
    }
}
Prodaje::Prodaje(const Prodaje &prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), prodaje2(new Prodaja*[max_broj_prodaja]) {
    broj_reg = prodaje.broj_reg;
    for(int i = 0; i < broj_reg; i++)
        prodaje2[i] = new Prodaja(*prodaje.prodaje2[i]);
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()), prodaje2(new Prodaja*[max_broj_prodaja])
{
    int brojac(0);
    broj_reg = max_broj_prodaja;
    try {
        for(const auto &pok: spisak_prodaja)
            prodaje2[brojac++] = new Prodaja(pok);
    } catch (...) {
        for(int i = 0; i < brojac; i++)
            delete prodaje2[i];
    }
}    
void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    if(broj_reg == max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodaje2[broj_reg++] = new Prodaja(*prodaja);
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if(broj_reg == max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodaje2[broj_reg++] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca,
    adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
const Stan &kupljeni_stan) {
    if(broj_reg == max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    prodaje2[++broj_reg] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
}
Prodaje::~Prodaje() {
    for(int i = 0; i < max_broj_prodaja; i++) delete prodaje2[i];
    delete [] prodaje2;
}
int main ()
{
	return 0;
}