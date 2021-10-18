/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>

class Datum {
    int dan,mjesec,godina;
public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan,mjesec,godina); }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const {
        std::cout << DajDan() << "/" << DajMjesec() << "/" << DajGodinu();
    }
};

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    this->dan=dan; this->mjesec=mjesec; this->godina=godina;
}

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum_rodjenja(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu()) { 
        Postavi(ime_i_prezime,datum_rodjenja); }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const {
        std::cout << DajImePrezime() << " ("; datum_rodjenja.Ispisi(); std::cout << ")";
    }
};

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    for (int i=0; i<ime_i_prezime.size(); i++)
        if (!((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') ||
        (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]=='-' || ime_i_prezime[i]==' ' || ime_i_prezime[i]==39))
            throw std::domain_error("Neispravno ime i prezime");
    this->ime_i_prezime=ime_i_prezime; this->datum_rodjenja=Datum(datum_rodjenja.DajDan(),datum_rodjenja.DajMjesec(),datum_rodjenja.DajGodinu());
}

class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa,sprat,broj_soba,namjesten,kvadratura); }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
};

void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba();
    if ((DajBrojSoba()/10)%10==1) std::cout << " soba. ";
    else {
        if (DajBrojSoba()%10==1) std::cout << " sobu. ";
        else if (DajBrojSoba()%10==2 || DajBrojSoba()%10==3 || DajBrojSoba()%10==4) std::cout << " sobe. ";
        else std::cout << " soba. ";
    }
    std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan ";
    if (DajNamjesten()) std::cout << "je ";
    else std::cout << "nije ";
    std::cout << "namjesten." << std::endl;
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat<0 || broj_soba<0 || kvadratura<0)
        throw std::domain_error("Neispravan unos podataka");
    this->adresa=adresa; this->sprat=sprat; this->broj_soba=broj_soba; this->namjesten=namjesten; this->kvadratura=kvadratura;
}

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, 
        const Stan &kupljeni_stan) : datum_prodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()), 
            kupac_stana(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()),
            kupljeni_stan(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu()) {
                for (int i=0; i<ime_agenta_prodaje.size(); i++) {
                    if (!((ime_agenta_prodaje[i]>='a' && ime_agenta_prodaje[i]<='z') || (ime_agenta_prodaje[i]>='A' && ime_agenta_prodaje[i]<='Z') ||
                    (ime_agenta_prodaje[i]>='0' && ime_agenta_prodaje[i]<='9') || ime_agenta_prodaje[i]=='-' || ime_agenta_prodaje[i]==' ' || ime_agenta_prodaje[i]==39))
                        throw std::domain_error("Neispravno ime i prezime");
                }
                if (cijena_stana<0) throw std::domain_error("Neispravan unos podataka");
                Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana;
            }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
        const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana,
        int broj_soba, bool namjesten_stan, double broj_kvadrata) : datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac_stana(ime_kupca,datum_rodjenja_kupca),
            kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {
                for (int i=0; i<ime_agenta_prodaje.size(); i++) {
                    if (!((ime_agenta_prodaje[i]>='a' && ime_agenta_prodaje[i]<='z') || (ime_agenta_prodaje[i]>='A' && ime_agenta_prodaje[i]<='Z') ||
                    (ime_agenta_prodaje[i]>='0' && ime_agenta_prodaje[i]<='9') || ime_agenta_prodaje[i]=='-' || ime_agenta_prodaje[i]==' ' || ime_agenta_prodaje[i]==39))
                        throw std::domain_error("Neispravno ime i prezime");
                }
                if (cijena_stana<0) throw std::domain_error("Neispravan unos podataka");
                Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana;
            }
    void PromijeniAgentaProdaje(const std::string &ime_agenta) {
        for (int i=0; i<ime_agenta.size(); i++)
            if (!((ime_agenta[i]>='a' && ime_agenta[i]<='z') || (ime_agenta[i]>='A' && ime_agenta[i]<='Z') ||
            (ime_agenta[i]>='0' && ime_agenta[i]<='9') || ime_agenta[i]==' ' || ime_agenta[i]=='-' || ime_agenta[i]==39))
                throw std::domain_error("Neispravno ime i prezime");
        ime_agenta_prodaje=ime_agenta;
    }
    void PromijeniKupca(const Kupac &novi_kupac) {
        kupac_stana.Postavi(novi_kupac.DajImePrezime(),novi_kupac.DajDatumRodjenja());
    }
    void PromijeniStan(const Stan &novi_stan) {
        kupljeni_stan.Postavi(novi_stan.DajAdresu(),novi_stan.DajSprat(),novi_stan.DajBrojSoba(),novi_stan.DajNamjesten(),novi_stan.DajKvadraturu());
    }
    void PromijeniDatumKupovine(const Datum &novi_datum) {
        datum_prodaje.Postavi(novi_datum.DajDan(),novi_datum.DajMjesec(),novi_datum.DajGodinu());
    }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena_stana=nova_cijena; }
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

void Prodaja::PomjeriDanUnaprijed() {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) || datum_prodaje.DajGodinu()%400==0) broj_dana[1]++;
    bool zadnji_dan_u_mjesecu=false;
    for (int i=0; i<12; i++) {
        if (datum_prodaje.DajDan()==broj_dana[i]) {
            zadnji_dan_u_mjesecu=true;
            if (datum_prodaje.DajMjesec()==12) datum_prodaje.Postavi(1,1,datum_prodaje.DajGodinu()+1);
            else datum_prodaje.Postavi(1,datum_prodaje.DajMjesec()+1,datum_prodaje.DajGodinu());
            break;
        }
    }
    if (!zadnji_dan_u_mjesecu) datum_prodaje.Postavi(datum_prodaje.DajDan()+1,datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());
}

void Prodaja::PomjeriDanUnazad() {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((datum_prodaje.DajGodinu()%4==0 && datum_prodaje.DajGodinu()%100!=0) || datum_prodaje.DajGodinu()%400==0) broj_dana[1]++;
    bool prvi_dan_u_mjesecu=false;
    int tmp=0;
    for (int i=11; i>=0; i--) {
        if (datum_prodaje.DajMjesec()==i+1) {
            if (i+1!=1 && datum_prodaje.DajDan()==1) {
                datum_prodaje.Postavi(broj_dana[i-1],datum_prodaje.DajMjesec()-1,datum_prodaje.DajGodinu());
                prvi_dan_u_mjesecu=true;
                break;
            }
            else if (i+1==1 && datum_prodaje.DajDan()==1) {
                datum_prodaje.Postavi(broj_dana[tmp],tmp+1,datum_prodaje.DajGodinu()-1);
                prvi_dan_u_mjesecu=true;
                break;
            }
        }
        tmp++;
    }
    if (!prvi_dan_u_mjesecu) datum_prodaje.Postavi(datum_prodaje.DajDan()-1,datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu());
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if (p1.DajDatumProdaje().DajGodinu()!=p2.DajDatumProdaje().DajGodinu()) return p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu();
    else if (p1.DajDatumProdaje().DajMjesec()!=p2.DajDatumProdaje().DajMjesec()) return p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec();
    return p1.DajDatumProdaje().DajDan()<p2.DajDatumProdaje().DajDan();
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    return p1.DajCijenuStana()<p2.DajCijenuStana();
}

void Prodaja::Ispisi() const {
    std::cout << std::setw(32) << std::left << "Ime agenta:" << std::right << DajImeAgenta() << std::endl;
    std::cout << std::setw(32) << std::left << "Ime kupca:"; kupac_stana.Ispisi();
    std::cout << std::endl << std::setw(32) << std::left << "Zakazani datum prodaje:"; DajDatumProdaje().Ispisi();
    std::cout << std::endl << std::setw(32) << std::left << "Cijena stana:" << std::right << DajCijenuStana();
    std::cout << std::endl << std::setw(32) << std::left << "Informacije o stanu:" << std::endl;
    kupljeni_stan.Ispisi();
}

class Prodaje {
    const int kapacitet;
    int broj_evidentiranih;
    Prodaja **prodaje_priv;
public:
    explicit Prodaje(int max_broj_prodaja) : kapacitet(max_broj_prodaja), broj_evidentiranih(0), prodaje_priv(new Prodaja*[max_broj_prodaja]{}) {}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
        std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
        bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    Prodaja &DajProdaju(int indeks);
    int DajBrojProdaja() const { return broj_evidentiranih; }
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

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : kapacitet(spisak_prodaja.size()), broj_evidentiranih(spisak_prodaja.size()),
    prodaje_priv(new Prodaja*[spisak_prodaja.size()]) {
        int i=0;
        for (auto it=spisak_prodaja.begin(); it!=spisak_prodaja.end(); it++) {
            try {
                prodaje_priv[i]=new Prodaja(*it);
                i++;
            }
            catch(std::bad_alloc) {
                for (int i=0; i<spisak_prodaja.size(); i++) delete prodaje_priv[i];
                delete[] prodaje_priv;
                throw;
            }
        }
}

Prodaje::~Prodaje() {
    for (int i=0; i<broj_evidentiranih; i++) delete prodaje_priv[i];
    delete[] prodaje_priv;
}

Prodaje::Prodaje(const Prodaje &prodaje) : kapacitet(prodaje.kapacitet), 
    broj_evidentiranih(prodaje.broj_evidentiranih), prodaje_priv(new Prodaja*[prodaje.kapacitet]{}) {
        try {
            for (int i=0; i<prodaje.broj_evidentiranih; i++)
                prodaje_priv[i]=new Prodaja(*prodaje.prodaje_priv[i]);
        }
        catch(...) {
            for (int i=0; i<prodaje.broj_evidentiranih; i++) delete prodaje_priv[i];
            delete prodaje_priv; 
            throw;
        }
}

Prodaje::Prodaje(Prodaje &&prodaje) : kapacitet(prodaje.kapacitet), broj_evidentiranih(prodaje.broj_evidentiranih),
    prodaje_priv(prodaje.prodaje_priv) {
        prodaje.prodaje_priv=nullptr;
        prodaje.broj_evidentiranih=0;
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje) {
    if (prodaje.kapacitet!=kapacitet)
        throw std::logic_error("Prodaje nesaglasnih kapaciteta");
    if (prodaje.broj_evidentiranih>broj_evidentiranih) {
        try {
            for (int i=broj_evidentiranih; i<prodaje.broj_evidentiranih; i++)
                prodaje_priv[i]=new Prodaja(*prodaje.prodaje_priv[i]);
        }
        catch(...) {
            for (int i=broj_evidentiranih; i<prodaje.broj_evidentiranih; i++) {
                delete prodaje_priv[i]; prodaje_priv[i]=nullptr;
            }
            throw;
        }
    }
    else {
        for (int i=prodaje.broj_evidentiranih; i<broj_evidentiranih; i++) {
            delete prodaje_priv[i]; prodaje_priv[i]=nullptr;
        }
    }
    broj_evidentiranih=prodaje.broj_evidentiranih;
    for (int i=0; i<broj_evidentiranih; i++) *prodaje_priv[i]=*prodaje.prodaje_priv[i];
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje) {
    if (prodaje.kapacitet!=kapacitet)
        throw std::logic_error("Prodaje nesaglasnih kapaciteta");
    std::swap(broj_evidentiranih, prodaje.broj_evidentiranih);
    std::swap(prodaje_priv, prodaje.prodaje_priv);
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
    const Kupac &kupac_stana, const Stan &kupljeni_stan) {
        if (broj_evidentiranih>=kapacitet) throw std::range_error("Dostignut maksimalan broj prodaja");
        Prodaja *prodaja=nullptr;
        try {
            prodaja=new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
        }
        catch(...) {
            throw;
        }
        RegistrirajProdaju(prodaja);
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double kvadratura) {
        if (broj_evidentiranih>=kapacitet) throw std::range_error("Dostignut maksimalan broj prodaja");
        Prodaja *prodaja=nullptr;
        try {    
            prodaja=new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, 
                datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, kvadratura);
        }
        catch(...) {
            throw;
        }
        RegistrirajProdaju(prodaja);
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    if (broj_evidentiranih>=kapacitet) throw std::range_error("Dostignut maksimalan broj prodaja");
    prodaje_priv[broj_evidentiranih++]=prodaja;
}

Prodaja &Prodaje::DajProdaju(int indeks) {
    if (indeks>broj_evidentiranih || indeks<0) throw std::range_error("Neispravan indeks");
    for (int i=0; i<broj_evidentiranih; i++)
        if (i==indeks) return *prodaje_priv[i];
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(prodaje_priv, prodaje_priv+broj_evidentiranih, [datum](Prodaja *p1){
        return p1->DajDatumProdaje().DajDan()==datum.DajDan() && p1->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
            p1->DajDatumProdaje().DajGodinu()==datum.DajGodinu(); });
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return std::count_if(prodaje_priv, prodaje_priv+broj_evidentiranih, [ime_agenta](const Prodaja *p1){
        return p1->DajImeAgenta()==ime_agenta; });
}

Prodaja &Prodaje::DajNajranijuProdaju() {
    if (broj_evidentiranih==0) throw std::domain_error("Nema registriranih podataka");
    return **(std::min_element(prodaje_priv, prodaje_priv+broj_evidentiranih, [](Prodaja *p1, Prodaja *p2){ return ProdatPrije(*p2,*p1); }));
}

Prodaja Prodaje::DajNajranijuProdaju() const {
    if (broj_evidentiranih==0) throw std::domain_error("Nema registriranih podataka");
    return **(std::min_element(prodaje_priv, prodaje_priv+broj_evidentiranih, [](Prodaja *p1, Prodaja *p2){ return ProdatPrije(*p1,*p2); }));
}

Prodaja &Prodaje::DajNajskupljuProdaju() {
    if (broj_evidentiranih==0) throw std::domain_error("Nema registriranih podataka");
    return **(std::max_element(prodaje_priv, prodaje_priv+broj_evidentiranih, [](Prodaja *p1, Prodaja *p2){ return SkupljiStan(*p1,*p2); }));
}

Prodaja Prodaje::DajNajskupljuProdaju() const {
    if (broj_evidentiranih==0) throw std::domain_error("Nema registriranih podataka");
    return **(std::max_element(prodaje_priv, prodaje_priv+broj_evidentiranih, [](Prodaja *p1, Prodaja *p2){ return SkupljiStan(*p1,*p2); }));
}

void Prodaje::IsprazniKolekciju() {
    for (int i=0; i<broj_evidentiranih; i++) {
        delete prodaje_priv[i];
        prodaje_priv[i]=nullptr;
    }
    broj_evidentiranih=0;
}

void Prodaje::ObrisiNajranijuProdaju() {
    if (broj_evidentiranih==0) throw std::range_error("Prazna kolekcija");
    ObrisiProdajeNaDatum(DajNajranijuProdaju().DajDatumProdaje());
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    if (broj_evidentiranih==0) throw std::range_error("Prazna kolekcija");
    int broj_prodaja_od_agenta=DajBrojProdajaOdAgenta(ime_agenta);
    if (broj_prodaja_od_agenta==0) return;
    for (int i=0; i<broj_evidentiranih; i++) {
        if (prodaje_priv[i]->DajImeAgenta()==ime_agenta) {
            delete prodaje_priv[i];
            prodaje_priv[i]=nullptr;
        }
    }
    Prodaja **novo_mjesto=new Prodaja*[kapacitet]{};
    int j=0;
    for (int i=0; i<broj_evidentiranih; i++) {
        if (prodaje_priv[i]!=nullptr) {
            novo_mjesto[j]=prodaje_priv[i];
            j++;
        }
    }
    delete[] prodaje_priv; 
    prodaje_priv=novo_mjesto;
    broj_evidentiranih-=broj_prodaja_od_agenta;
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    if (broj_evidentiranih==0) throw std::range_error("Prazna kolekcija");
    int broj_prodaja_na_datum=DajBrojProdajaNaDatum(datum);
    if (broj_prodaja_na_datum==0) return;
    for (int i=0; i<broj_evidentiranih; i++) {
        if (prodaje_priv[i]->DajDatumProdaje().DajDan()==datum.DajDan() &&
            prodaje_priv[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
            prodaje_priv[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) {
                delete prodaje_priv[i];
                prodaje_priv[i]=nullptr;
            }
    }
    Prodaja **novo_mjesto=new Prodaja*[kapacitet]{};
    int j=0;
    for (int i=0; i<broj_evidentiranih; i++) {
        if (prodaje_priv[i]!=nullptr) {
            novo_mjesto[j]=prodaje_priv[i];
            j++;
        }
    }
    delete[] prodaje_priv;
    prodaje_priv=novo_mjesto;
    broj_evidentiranih-=broj_prodaja_na_datum;
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    if (broj_evidentiranih==0) throw std::range_error("Prazna kolekcija");
    int broj_prodaja_na_datum=DajBrojProdajaNaDatum(datum);
    if (broj_prodaja_na_datum==0) return;
    std::vector<Prodaja> vektor_prodaja;
    for (int i=0; i<broj_evidentiranih; i++) {
        if (prodaje_priv[i]->DajDatumProdaje().DajDan()==datum.DajDan() &&
            prodaje_priv[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() &&
            prodaje_priv[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu()) vektor_prodaja.push_back(*prodaje_priv[i]);
    }
    std::sort(vektor_prodaja.begin(),vektor_prodaja.end(), [](Prodaja p1,Prodaja p2){ return p1.DajImeKupca()<p2.DajImeKupca(); });
    for (int i=0; i<broj_prodaja_na_datum; i++) {
        vektor_prodaja[i].Ispisi();
        std::cout << std::endl;
    }
}

void Prodaje::IspisiSveProdaje() const {
    if (broj_evidentiranih==0) throw std::range_error("Prazna kolekcija");
    std::vector<Prodaja> vektor_prodaja;
    for (int i=0; i<broj_evidentiranih; i++)
        vektor_prodaja.push_back(*prodaje_priv[i]);
    std::sort(vektor_prodaja.begin(),vektor_prodaja.end(), [](Prodaja p1,Prodaja p2){ 
        if(p1.DajDatumProdaje().DajDan()==p2.DajDatumProdaje().DajDan() && p1.DajDatumProdaje().DajMjesec()==p2.DajDatumProdaje().DajMjesec() &&
        p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu()) return p1.DajImeKupca()<p2.DajImeKupca(); 
        return ProdatPrije(p1,p2); });
    for (int i=0; i<vektor_prodaja.size(); i++) {
        vektor_prodaja[i].Ispisi();
        std::cout << std::endl;
    }
}

int main () {
    std::cout << "Dobrodosli!" << std::endl << std::endl << std::endl;
    std::vector<Stan> vektor_stanova;
    std::vector<Kupac> vektor_kupaca;
    Prodaje prodaje(20);
    int opcija1;
    do {
        std::cout << "Izaberite opciju:" << std::endl
        << " 0 - kraj" << std::endl << " 1 - uredjivanje stanova" << std::endl
        << " 2 - uredjivanje kupaca" << std::endl << " 3 - uredjivanje prodaja" << std::endl;
        std::cin >> opcija1;
        if (opcija1==1) {
            int opcija2;
            do {
                std::cout << "Izaberite opciju:" << std::endl
                << " 0 - nazad" << std::endl << " 1 - dodavanje stana" << std::endl
                << " 2 - uredjivanje stanova" << std::endl << " 3 - ispis svih stanova"
                << std::endl << " 4 - kraj" << std::endl;
                std::cin >> opcija2;
                if (opcija2==0) break;
                else if (opcija2==1) {
                    std::string adresa;
                    int sprat, broj_soba, namjesten;
                    bool da_li_je_kraj_unosa(false);
                    double kvadratura;
                    do {
                        std::cin.ignore(10000,'\n');
                        std::cout << "Unesite adresu: ";
                        std::getline(std::cin,adresa);
                        std::cout << "Unesite sprat: ";
                        std::cin >> sprat;
                        std::cout << "Unesite broj soba: ";
                        std::cin >> broj_soba;
                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                        std::cin >> namjesten;
                        std::cout << "Unesite kvadraturu: ";
                        std::cin >> kvadratura;
                        try {
                            if (namjesten!=1 && namjesten!=0) throw std::domain_error("Neispravan unos podataka");
                            Stan s(adresa,sprat,broj_soba,namjesten,kvadratura);
                            vektor_stanova.push_back(s);
                            da_li_je_kraj_unosa=true;
                            std::cout << "Stan je uspjesno dodan!" << std::endl << std::endl;
                        }
                        catch(std::domain_error izuzetak) {
                            std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                        }
                    } while(!da_li_je_kraj_unosa);
                }
                else if (opcija2==2) {
                    std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                    for (int i=0; i<vektor_stanova.size(); i++) {
                        std::cout << " " << i+1 << " - ";
                        vektor_stanova[i].Ispisi();
                    }
                    int dodatna_opcija1, dodatna_opcija2;
                    std::cin >> dodatna_opcija1;
                    std::cout << std::endl << "Odaberite polje koje zelite urediti:" << std::endl
                    << " 0 - nazad" << std::endl << " 1 - adresa" << std::endl 
                    << " 2 - sprat" << std::endl << " 3 - broj soba" << std::endl
                    << " 4 - da li je stan namjesten" << std::endl << " 5 - kvadratura"
                    << std::endl << " 6 - sve" << std::endl;
                    std::cin >> dodatna_opcija2;
                    if (dodatna_opcija2==1) {
                        std::cin.ignore(10000,'\n');
                        std::string nova_adresa;
                        std::cout << "Unesite adresu: ";
                        std::getline(std::cin,nova_adresa);
                        vektor_stanova[dodatna_opcija1-1].Postavi(nova_adresa,vektor_stanova[dodatna_opcija1-1].DajSprat(),
                            vektor_stanova[dodatna_opcija1-1].DajBrojSoba(),vektor_stanova[dodatna_opcija1-1].DajNamjesten(),
                            vektor_stanova[dodatna_opcija1-1].DajKvadraturu());
                        std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                    }
                    else if (dodatna_opcija2==2) {
                        bool da_li_je_kraj_unosa1=false;
                        do {
                            int novi_sprat;
                            std::cout << "Unesite sprat: ";
                            std::cin >> novi_sprat;
                            try {
                                vektor_stanova[dodatna_opcija1-1].Postavi(vektor_stanova[dodatna_opcija1-1].DajAdresu(),novi_sprat,
                                    vektor_stanova[dodatna_opcija1-1].DajBrojSoba(),vektor_stanova[dodatna_opcija1-1].DajNamjesten(),
                                    vektor_stanova[dodatna_opcija1-1].DajKvadraturu());
                                da_li_je_kraj_unosa1=true;
                                std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                            }
                            catch(std::domain_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                        } while(!da_li_je_kraj_unosa1);
                    }
                    else if (dodatna_opcija2==3) {
                        bool da_li_je_kraj_unosa1=false;
                        do {
                            int novi_broj_soba;
                            std::cout << "Unesite broj soba: ";
                            std::cin >> novi_broj_soba;
                            try {
                                vektor_stanova[dodatna_opcija1-1].Postavi(vektor_stanova[dodatna_opcija1-1].DajAdresu(),vektor_stanova[dodatna_opcija1-1].DajSprat(),
                                    novi_broj_soba,vektor_stanova[dodatna_opcija1-1].DajNamjesten(),vektor_stanova[dodatna_opcija1-1].DajKvadraturu());
                                da_li_je_kraj_unosa1=true;
                                std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                            }
                            catch(std::domain_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                        } while(!da_li_je_kraj_unosa1);
                    }
                    else if (dodatna_opcija2==4) {
                        bool da_li_je_kraj_unosa1=false;
                        do {
                            int novi_namjesten;
                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            std::cin >> novi_namjesten;
                            try {
                                if (novi_namjesten!=1 && novi_namjesten!=0) throw std::domain_error("Neispravan unos podataka");
                                vektor_stanova[dodatna_opcija1-1].Postavi(vektor_stanova[dodatna_opcija1-1].DajAdresu(),vektor_stanova[dodatna_opcija1-1].DajSprat(),
                                    vektor_stanova[dodatna_opcija1-1].DajBrojSoba(),novi_namjesten,vektor_stanova[dodatna_opcija1-1].DajKvadraturu());
                                da_li_je_kraj_unosa1=true;
                                std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                            }
                            catch(std::domain_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                        } while (!da_li_je_kraj_unosa1);
                    }
                    else if (dodatna_opcija2==5) {
                        bool da_li_je_kraj_unosa1=false;
                        do {
                            double nova_kvadratura;
                            std::cout << "Unesite kvadraturu: ";
                            std::cin >> nova_kvadratura;
                            try {
                                vektor_stanova[dodatna_opcija1-1].Postavi(vektor_stanova[dodatna_opcija1-1].DajAdresu(),vektor_stanova[dodatna_opcija1-1].DajSprat(),
                                    vektor_stanova[dodatna_opcija1-1].DajBrojSoba(),vektor_stanova[dodatna_opcija1-1].DajNamjesten(),nova_kvadratura);
                                da_li_je_kraj_unosa1=true;
                                std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                            }
                            catch(std::domain_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                        } while (!da_li_je_kraj_unosa1);
                    }
                    else if (dodatna_opcija2==6) {
                        bool da_li_je_kraj_unosa1=false;
                        do {
                            std::string nova_adresa;
                            int novi_sprat, novi_broj_soba, novi_namjesten;
                            double nova_kvadratura;
                            std::cin.ignore(10000,'\n');
                            std::cout << "Unesite adresu: ";
                            std::getline(std::cin,nova_adresa);
                            std::cout << "Unesite sprat: ";
                            std::cin >> novi_sprat;
                            std::cout << "Unesite broj soba: ";
                            std::cin >> novi_broj_soba;
                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            std::cin >> novi_namjesten;
                            std::cout << "Unesite kvadraturu: ";
                            std::cin >> nova_kvadratura;
                            try {
                                if (novi_namjesten!=0 && novi_namjesten!=1) throw std::domain_error("Neispravan unos podataka");
                                vektor_stanova[dodatna_opcija1-1].Postavi(nova_adresa,novi_sprat,novi_broj_soba,novi_namjesten,nova_kvadratura);
                                da_li_je_kraj_unosa1=true;
                                std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                            }
                            catch(std::domain_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                        } while (!da_li_je_kraj_unosa1);
                    }
                    else if (dodatna_opcija2==0) std::cout << std::endl;
                }
                else if (opcija2==3) {
                    for (int i=0; i<vektor_stanova.size(); i++) {
                        std::cout << i+1 << ". ";
                        vektor_stanova[i].Ispisi();
                    }
                    std::cout << std::endl;
                }
                else if (opcija2==4) {
                    std::cout << std::endl << std::endl << "Dovidjenja!";
                    return 0;
                }
            } while (opcija2!=0);
        } 
        else if (opcija1==2) {
            int opcija2;
            do {
                std::cout << "Izaberite opciju:" << std::endl
                << " 0 - nazad" << std::endl << " 1 - dodavanje kupca" << std::endl
                << " 2 - uredjivanje kupaca" << std::endl << " 3 - ispis svih kupaca"
                << std::endl << " 4 - kraj" << std::endl;
                std::cin >> opcija2;
                if (opcija2==0) break;
                else if (opcija2==1) {
                    bool da_li_je_kraj_unosa1=false;
                    do {
                        std::cin.ignore(10000,'\n');
                        std::string ime_i_prezime;
                        std::cout << "Unesite ime i prezime kupca: ";
                        std::getline(std::cin,ime_i_prezime);
                        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                        char znak;
                        int dan,mjesec,godina;
                        std::cin >> dan >> znak >> mjesec >> znak >> godina;
                        try {
                            Datum datum(dan,mjesec,godina);
                            Kupac kupac(ime_i_prezime,datum);
                            vektor_kupaca.push_back(kupac);
                            da_li_je_kraj_unosa1=true;
                            std::cout << "Kupac je uspjesno dodan!" << std::endl << std::endl;
                        }
                        catch(std::domain_error izuzetak) {
                            std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                        }
                    } while(!da_li_je_kraj_unosa1);
                }
                else if (opcija2==2) {
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << std::endl;
                    for (int i=0; i<vektor_kupaca.size(); i++) {
                        std::cout << " " << i+1 << " - ";
                        vektor_kupaca[i].Ispisi();
                        std::cout << std::endl;
                    }
                    int dodatna_opcija1;
                    std::cin >> dodatna_opcija1;
                    bool da_li_je_kraj_unosa2=false;
                    do {
                        std::cin.ignore(10000,'\n');
                        std::string novo_ime_i_prezime_kupca;
                        std::cout << "Unesite ime i prezime kupca: ";
                        std::getline(std::cin,novo_ime_i_prezime_kupca);
                        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                        char znak;
                        int dan,mjesec,godina;
                        std::cin >> dan >> znak >> mjesec >> znak >> godina;
                        try {
                            Datum novi_datum(dan,mjesec,godina);
                            vektor_kupaca[dodatna_opcija1-1].Postavi(novo_ime_i_prezime_kupca,novi_datum);
                            da_li_je_kraj_unosa2=true;
                            std::cout << "Kupac je uspjesno izmijenjen!" << std::endl << std::endl;
                        }
                        catch(std::domain_error izuzetak) {
                            std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                        }
                    } while (!da_li_je_kraj_unosa2);
                }
                else if (opcija2==3) {
                    for (int i=0; i<vektor_kupaca.size(); i++) {
                        vektor_kupaca[i].Ispisi();
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;
                }
                else if (opcija2==4) {
                    std::cout << std::endl << std::endl << "Dovidjenja!";
                    return 0;
                }
            } while (opcija2!=0);
        } 
        else if (opcija1==3) {
            int opcija2;
            do {
                std::cout << "Izaberite opciju:" << std::endl
                << " 0 - nazad" << std::endl << " 1 - dodavanje prodaje" << std::endl
                << " 2 - uredjivanje prodaje" << std::endl << " 3 - ispis prodaja" << std::endl
                << " 4 - brisanje prodaja" << std::endl << " 5 - kraj" << std::endl;
                std::cin >> opcija2;
                if (opcija2==0) break;
                else if (opcija2==1) {
                    int opcija3;
                    do {
                        std::cout << "Izaberite opciju:" << std::endl
                        << " 0 - nazad" << std::endl << " 1 - dodavanje potpuno nove prodaje"
                        << std::endl << " 2 - dodavanje nove prodaje na osnovu arhive" << std::endl
                        << " 3 - kraj" << std::endl;
                        std::cin >> opcija3;
                        if (opcija3==0) break;
                        else if (opcija3==1) {
                            bool da_li_je_kraj_unosa2=false;
                            do {
                                std::cin.ignore(10000,'\n');
                                std::cout << "Unesite ime i prezime agenta prodaje: ";
                                std::string ime_i_prezime_agenta_prodaje;
                                std::getline(std::cin,ime_i_prezime_agenta_prodaje);
                                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                char znak1;
                                int dan1,mjesec1,godina1;
                                std::cin >> dan1 >> znak1 >> mjesec1 >> znak1 >> godina1;
                                int cijena_stana;
                                std::cout << "Unesite cijenu stana: ";
                                std::cin >> cijena_stana;
                                std::cin.ignore(10000,'\n');
                                std::cout << "Unesite ime kupca: ";
                                std::string ime_kupca;
                                std::getline(std::cin,ime_kupca);
                                char znak2;
                                int dan2,mjesec2,godina2;
                                std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                                std::cin >> dan2 >> znak2 >> mjesec2 >> znak2 >> godina2;
                                std::string adresa;
                                std::cin.ignore(10000,'\n');
                                std::cout << "Unesite adresu: ";
                                std::getline(std::cin,adresa);
                                int sprat;
                                std::cout << "Unesite sprat: ";
                                std::cin >> sprat;
                                int broj_soba;
                                std::cout << "Unesite broj soba: ";
                                std::cin >> broj_soba;
                                int namjesten;
                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                std::cin >> namjesten;
                                double kvadratura;
                                std::cout << "Unesite kvadraturu: ";
                                std::cin >> kvadratura;
                                try {
                                    if (namjesten!=0 && namjesten!=1) throw std::domain_error("Neispravan unos podataka");
                                    Datum datum1(dan1,mjesec1,godina1);
                                    Datum datum2(dan2,mjesec2,godina2);
                                    Kupac kupac(ime_kupca,datum2);
                                    vektor_kupaca.push_back(kupac);
                                    Stan stan(adresa,sprat,broj_soba,namjesten,kvadratura);
                                    vektor_stanova.push_back(stan);
                                    prodaje.RegistrirajProdaju(ime_i_prezime_agenta_prodaje,cijena_stana,datum1,kupac,stan);
                                    da_li_je_kraj_unosa2=true;
                                    std::cout << "Prodaja uspjesno dodana!" << std::endl << std::endl;
                                }
                                catch(std::domain_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                }
                            } while(!da_li_je_kraj_unosa2);
                        }
                        else if (opcija3==2) {
                            bool da_li_je_kraj_unosa2=false;
                            do {
                                std::cin.ignore(10000,'\n');
                                std::string ime_i_prezime_agenta_prodaje;
                                std::cout << "Unesite ime i prezime agenta prodaje: ";
                                std::getline(std::cin,ime_i_prezime_agenta_prodaje);
                                char znak;
                                int dan,mjesec,godina;
                                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                std::cin >> dan >> znak >> mjesec >> znak >> godina;
                                int cijena_stana;
                                std::cout << "Unesite cijenu stana: ";
                                std::cin >> cijena_stana;
                                std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                                for (int i=0; i<vektor_kupaca.size(); i++) {
                                    std::cout << " " << i+1 << " - ";
                                    vektor_kupaca[i].Ispisi();
                                    std::cout << std::endl;
                                }
                                int dodatna_opcija1;
                                std::cin >> dodatna_opcija1;
                                std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                                for (int i=0; i<vektor_stanova.size(); i++) {
                                    std::cout << " " << i+1 << " - ";
                                    vektor_stanova[i].Ispisi();
                                }
                                int dodatna_opcija2;
                                std::cin >> dodatna_opcija2;
                                try {
                                    Datum datum(dan,mjesec,godina);
                                    prodaje.RegistrirajProdaju(ime_i_prezime_agenta_prodaje,cijena_stana,datum,
                                        vektor_kupaca[dodatna_opcija1-1],vektor_stanova[dodatna_opcija2-1]);
                                    da_li_je_kraj_unosa2=true;
                                    std::cout << "Prodaja uspjesno dodana!" << std::endl << std::endl;
                                }
                                catch(std::domain_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                }
                            } while(!da_li_je_kraj_unosa2);
                        }
                        else if (opcija3==3) {
                            std::cout << std::endl << std::endl << "Dovidjenja!";
                            return 0;
                        }
                    } while (opcija3!=0);
                }
                else if (opcija2==2) {
                    std::cout << "Odaberite prodaju koju zelite urediti. Dostupne prodaje su:" << std::endl;
                    for (int i=0; i<prodaje.DajBrojProdaja(); i++) {
                        std::cout << i+1 << "." << std::endl;
                        prodaje.DajProdaju(i).Ispisi();
                        if (i!=prodaje.DajBrojProdaja()-1) 
                            std::cout << std::endl;
                    }
                    int dodatna_opcija1;
                    std::cin >> dodatna_opcija1;
                    std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl
                    << " 1 - izmjena agenta" << std::endl << " 2 - izmjena datuma prodaje"
                    << std::endl << " 3 - izmjena kupca" << std::endl << " 4 - izmjena stana"
                    << std::endl << " 5 - izmjena cijene stana" << std::endl;
                    int dodatna_opcija2;
                    std::cin >> dodatna_opcija2;
                    if (dodatna_opcija2==0) break;
                    else if (dodatna_opcija2==1) {
                        bool da_li_je_kraj_unosa2=false;
                        do {
                            std::cin.ignore(10000,'\n');
                            std::string novo_ime_agenta;
                            std::cout << "Unesite ime i prezime agenta prodaje: ";
                            std::getline(std::cin,novo_ime_agenta);
                            try {
                                prodaje.DajProdaju(dodatna_opcija1-1).PromijeniAgentaProdaje(novo_ime_agenta);
                                da_li_je_kraj_unosa2=true;
                                std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                            }
                            catch(std::range_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                            catch(std::domain_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                        } while (!da_li_je_kraj_unosa2);
                    }
                    else if (dodatna_opcija2==2) {
                        bool da_li_je_kraj_unosa2=false;
                        do {
                            char znak;
                            int dan,mjesec,godina;
                            std::cout << "Unesite datum prodaje (formata d/m/g): ";
                            std::cin >> dan >> znak >> mjesec >> znak >> godina;
                            try {
                                Datum novi_datum(dan,mjesec,godina);
                                prodaje.DajProdaju(dodatna_opcija1-1).PromijeniDatumKupovine(novi_datum);
                                da_li_je_kraj_unosa2=true;
                                std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl; 
                            }
                            catch(std::range_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                            catch(std::domain_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                        } while (!da_li_je_kraj_unosa2);
                    }
                    else if (dodatna_opcija2==3) {
                        std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl
                        << " 1 - odabir postojeceg kupca" << std::endl << " 2 - dodavanje novog kupca" << std::endl;
                        int dodatna_opcija3;
                        std::cin >> dodatna_opcija3;
                        if (dodatna_opcija3==0) break;
                        else if (dodatna_opcija3==1) {
                            std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                            for (int i=0; i<vektor_kupaca.size(); i++) {
                                std::cout << " " << i+1 << " - ";
                                vektor_kupaca[i].Ispisi();
                                if(i!=vektor_kupaca.size()-1) std::cout << std::endl;
                            }
                            int dodatna_opcija4;
                            std::cin >> dodatna_opcija4;
                            try {
                                prodaje.DajProdaju(dodatna_opcija1-1).PromijeniKupca(vektor_kupaca[dodatna_opcija4-1]);
                                std::cout << std::endl << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                            }
                            catch(std::range_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                        }
                        else if (dodatna_opcija3==2) {
                            bool da_li_je_kraj_unosa3=false;
                            do {
                                std::cin.ignore(10000,'\n');
                                std::string novo_ime_kupca;
                                std::cout << "Unesite ime i prezime kupca: ";
                                std::getline(std::cin,novo_ime_kupca);
                                char znak;
                                int dan,mjesec,godina;
                                std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                std::cin >> dan >> znak >> mjesec >> znak >> godina;
                                try {
                                    Datum novi_datum(dan,mjesec,godina);
                                    Kupac novi_kupac(novo_ime_kupca,novi_datum);
                                    prodaje.DajProdaju(dodatna_opcija1-1).PromijeniKupca(novi_kupac);
                                    da_li_je_kraj_unosa3=true;
                                    std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                                }
                                catch(std::range_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                }
                                catch(std::domain_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                }
                            } while(!da_li_je_kraj_unosa3);
                        }
                    }
                    else if (dodatna_opcija2==4) {
                        std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad" << std::endl
                        << " 1 - odabir postojeceg stana" << std::endl << " 2 - dodavanje novog stana" << std::endl;
                        int dodatna_opcija3;
                        std::cin >> dodatna_opcija3;
                        if (dodatna_opcija3==0) break;
                        else if (dodatna_opcija3==1) {
                            std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                            for (int i=0; i<vektor_stanova.size(); i++) {
                                std::cout << " " << i+1 << " - ";
                                vektor_stanova[i].Ispisi();
                            }
                            int dodatna_opcija4;
                            std::cin >> dodatna_opcija4;
                            try {
                                prodaje.DajProdaju(dodatna_opcija4-1).PromijeniStan(vektor_stanova[dodatna_opcija4-1]);
                                std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                            }
                            catch(std::range_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                        }
                        else if (dodatna_opcija3==2) {
                            bool da_li_je_kraj_unosa3=false;
                            do {
                                std::cin.ignore(10000,'\n');
                                std::string nova_adresa;
                                std::cout << "Unesite adresu: ";
                                std::getline(std::cin,nova_adresa);
                                int novi_sprat;
                                std::cout << "Unesite sprat: ";
                                std::cin >> novi_sprat;
                                int novi_broj_soba;
                                std::cout << "Unesite broj soba: ";
                                std::cin >> novi_broj_soba;
                                int novi_namjesten;
                                std::cout << "Da li je namjesten (1 - da, 0 - ne): ";
                                std::cin >> novi_namjesten;
                                double nova_kvadratura;
                                std::cout << "Unesite kvadraturu: ";
                                std::cin >> nova_kvadratura;
                                try {
                                    if (novi_namjesten!=0 && novi_namjesten!=1) throw std::domain_error("Neispravan unos podataka");
                                    Stan novi_stan(nova_adresa,novi_sprat,novi_broj_soba,novi_namjesten,nova_kvadratura);
                                    prodaje.DajProdaju(dodatna_opcija1-1).PromijeniStan(novi_stan);
                                    da_li_je_kraj_unosa3=true;
                                    std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                }
                                catch(std::range_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                }
                                catch(std::domain_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                }
                            } while (!da_li_je_kraj_unosa3);
                        }
                    }
                    else if (dodatna_opcija2==5) {
                        bool da_li_je_kraj_unosa3=false;
                        do {
                            int nova_cijena;
                            std::cout << "Unesite cijenu stana: ";
                            std::cin >> nova_cijena;
                            try {
                                if (nova_cijena<0) throw std::domain_error("Neispravan unos podataka");
                                prodaje.DajProdaju(dodatna_opcija1-1).PromijeniCijenuProdaje(nova_cijena);
                                da_li_je_kraj_unosa3=true;
                                std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                            }
                            catch(std::range_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                            }
                            catch (std::domain_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl; 
                            }
                        } while (!da_li_je_kraj_unosa3);
                    }
                }
                else if (opcija2==3) {
                    int opcija3;
                    do {
                        std::cout << "Izaberite opciju:" << std::endl << " 0 - nazad"
                        << std::endl << " 1 - ispis svih prodaja" << std::endl << " 2 - ispis prodaja na datum" << std::endl
                        << " 3 - ispis najranije prodaje" << std::endl << " 4 - ispis najskuplje prodaje" << std::endl
                        << " 5 - ispis broja prodaja" << std::endl << " 6 - ispis broja prodaja po datumu" << std::endl
                        << " 7 - ispis broja prodaja po agentu" << std::endl << " 8 - kraj" << std::endl;
                        std::cin >> opcija3;
                        if (opcija3==0) break;
                        else if (opcija3==1) {
                            try {
                                prodaje.IspisiSveProdaje();
                            }
                            catch(std::range_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
                            }
                        }
                        else if (opcija3==2) {
                            bool da_li_je_kraj_unosa4=false;
                            do {
                                char znak;
                                int dan,mjesec,godina;
                                std::cout << "Unesite datum (d/m/g): ";
                                std::cin >> dan >> znak >> mjesec >> znak >> godina;
                                try {
                                    Datum datum(dan,mjesec,godina);
                                    da_li_je_kraj_unosa4=true;
                                    std::cout << "Prodaje na datum "; datum.Ispisi();
                                    std::cout << " su:" << std::endl;
                                    prodaje.IspisiProdajeNaDatum(datum);
                                }
                                catch(std::range_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
                                }
                                catch(std::domain_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                }
                            } while(!da_li_je_kraj_unosa4);
                        }
                        else if (opcija3==3) {
                            try {
                                prodaje.DajNajranijuProdaju().Ispisi();
                                std::cout << std::endl;
                            }
                            catch(std::domain_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
                            }
                        }
                        else if (opcija3==4) {
                            try {
                                prodaje.DajNajskupljuProdaju().Ispisi();
                                std::cout << std::endl;
                            }
                            catch(std::domain_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << std::endl;
                            }
                        }
                        else if (opcija3==5) {
                            std::cout << "Broj prodaja: " << prodaje.DajBrojProdaja() 
                            << std::endl << std::endl;
                        }
                        else if (opcija3==6) {
                            bool da_li_je_kraj_unosa4=false;
                            do {
                                char znak;
                                int dan,mjesec,godina;
                                std::cout << "Unesite datum (d/m/g): ";
                                std::cin >> dan >> znak >> mjesec >> znak >> godina;
                                try {
                                    Datum datum(dan,mjesec,godina);
                                    da_li_je_kraj_unosa4=true;
                                    std::cout << "Broj prodaja na uneseni datum: "
                                    << prodaje.DajBrojProdajaNaDatum(datum) << std::endl << std::endl;
                                }
                                catch(std::domain_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                }
                            } while (!da_li_je_kraj_unosa4);
                        }
                        else if (opcija3==7) {
                            std::cin.ignore(10000,'\n');
                            std::string ime_agenta;
                            std::cout << "Unesite ime agenta: ";
                            std::getline(std::cin,ime_agenta);
                            std::cout << "Broj prodaja unesenog agenta: " << prodaje.DajBrojProdajaOdAgenta(ime_agenta) 
                            << std::endl << std::endl;
                        }
                        else if (opcija3==8) {
                            std::cout << std::endl << std::endl << "Dovidjenja!";
                            return 0;
                        }
                    } while (opcija3!=0);
                }
                else if (opcija2==4) {
                    int opcija3;
                    do {
                        std::cout << "Izaberite opciju:" << std::endl
                        << " 0 - nazad" << std::endl << " 1 - brisanje najranije prodaje" << std::endl
                        << " 2 - brisanje prodaje agenta" << std::endl << " 3 - brisanje prodaja po datumu"
                        << std::endl << " 4 - brisanje svih prodaja" << std::endl;
                        std::cin >> opcija3;
                        if (opcija3==0) break;
                        else if (opcija3==1) {
                            try {
                                prodaje.ObrisiNajranijuProdaju();
                                std::cout << "Najranija prodaja je obrisana!" << std::endl << std::endl;
                            }
                            catch(std::range_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << std::endl << std::endl;
                            }
                        }
                        else if (opcija3==2) {
                            std::cin.ignore(10000,'\n');
                            std::string ime_agenta;
                            std::cout << "Unesite ime agenta: ";
                            std::getline(std::cin,ime_agenta);
                            try {
                                prodaje.ObrisiProdajeAgenta(ime_agenta);
                                std::cout << "Sve prodaje tog agenta su obrisane." << std::endl << std::endl;
                            }
                            catch(std::range_error izuzetak) {
                                std::cout << "Izuzetak: " << izuzetak.what() << std::endl << std::endl;
                            }
                        }
                        else if (opcija3==3) {
                            bool da_li_je_kraj_unosa4=false;
                            do {
                                char znak;
                                int dan,mjesec,godina;
                                std::cout << "Unesite datum: ";
                                std::cin >> dan >> znak >> mjesec >> znak >> godina;
                                try {
                                    Datum datum(dan,mjesec,godina);
                                    da_li_je_kraj_unosa4=true;
                                    prodaje.ObrisiProdajeNaDatum(datum);
                                    std::cout << "Sve prodaje na taj datum su obrisane." << std::endl << std::endl;
                                }
                                catch(std::range_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << std::endl << std::endl;
                                }
                                catch(std::domain_error izuzetak) {
                                    std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << std::endl;
                                }
                            } while(!da_li_je_kraj_unosa4);
                        }
                        else if (opcija3==4) {
                            prodaje.IsprazniKolekciju();
                            std::cout << "Sve prodaje su obrisane." << std::endl << std::endl;
                        }
                    } while(opcija3!=0);
                }
                else if (opcija2==5) {
                    std::cout << std::endl << std::endl << "Dovidjenja!";
                    return 0;
                }
            } while (opcija2!=0);
        } 
        else if (opcija1==0) std::cout << std::endl << std::endl << "Dovidjenja!";
    } while(opcija1!=0);
	return 0;
}