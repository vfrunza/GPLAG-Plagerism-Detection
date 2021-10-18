/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

class Datum
{
    int d, mj, g;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const {
        return d;
    }
    int DajMjesec() const {
        return mj;
    }
    int DajGodinu() const {
        return g;
    }
    void Ispisi() const {
        std::cout << DajDan() <<"/"<<DajMjesec() <<"/"<<DajGodinu();
    }
};

Datum::Datum(int dan, int mjesec, int godina)
{
    int brdana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brdana[1]++;
    if(godina<1 || dan <1 || mjesec<1 || mjesec > 12 || dan>brdana[mjesec-1]) throw std::domain_error("Neispravan datum");
    d = dan;
    mj =mjesec;
    g = godina;
}

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int brdana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brdana[1]++;
    if(godina<1 || dan <1 || mjesec<1 || mjesec > 12 || dan>brdana[mjesec-1]) throw std::domain_error("Neispravan datum");
    d = dan;
    mj =mjesec;
    g = godina;
}

class Kupac
{
    std::string imeip;
    Datum datrodj;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const {
        return imeip;
    }
    Datum DajDatumRodjenja() const {
        return datrodj;
    }
    void Ispisi() const {
        std::cout << imeip << " (";
        datrodj.Ispisi();
        std::cout << ")";
    }

};

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja):datrodj(datum_rodjenja)
{
    for(int i(0); i<ime_i_prezime.length(); i++) {
        if(!((ime_i_prezime[i] >='A' && ime_i_prezime[i] <='Z') || (ime_i_prezime[i] >='a' && ime_i_prezime[i] <='z') || (ime_i_prezime[i] >='0' && ime_i_prezime[i] <='9') || ime_i_prezime[i] == '-' || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == 39))
            throw std::domain_error("Neispravno ime i prezime");
    }
    imeip = ime_i_prezime;
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
{
    for(int i(0); i<ime_i_prezime.length(); i++) {
        if(!((ime_i_prezime[i] >='A' && ime_i_prezime[i] <='Z') || (ime_i_prezime[i] >='a' && ime_i_prezime[i] <='z') || (ime_i_prezime[i] >='0' && ime_i_prezime[i] <='9') || ime_i_prezime[i] == '-' || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == 39))
            throw std::domain_error("Neispravno ime i prezime");
    }
    imeip = ime_i_prezime;
    datrodj.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
}

class Stan
{
    std::string adress;
    int kat,brsoba;
    bool namjesteni;
    double kvadrati;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura);
    std::string DajAdresu() const {
        return adress;
    }
    int DajSprat() const {
        return kat;
    }
    int DajBrojSoba() const {
        return brsoba;
    }
    bool DajNamjesten() const {
        return namjesteni;
    }
    double DajKvadraturu() const {
        return kvadrati;
    }
    void Ispisi() const;
};

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten,double kvadratura)
{
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    adress = adresa;
    kat = sprat;
    brsoba = broj_soba;
    namjesteni = namjesten;
    kvadrati = kvadratura;
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba,bool namjesten, double kvadratura)
{
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    adress = adresa;
    kat = sprat;
    brsoba = broj_soba;
    namjesteni = namjesten;
    kvadrati = kvadratura;
}

void Stan::Ispisi() const
{
    if(DajNamjesten()) {
        if(brsoba%10 == 1 && brsoba!=11) std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobu.";
        if((brsoba%10 == 2 || brsoba%10 == 3 || brsoba%10==4) && (brsoba<11 || brsoba > 20)) std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobe.";
        else std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba.";
        std::cout << " Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan je namjesten."<<std::endl;
    } else {
        if(brsoba%10 == 1 && brsoba!=11) std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobu.";
        if((brsoba%10 == 2 || brsoba%10 == 3 || brsoba%10==4) && (brsoba<11 || brsoba > 20)) std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobe.";
        else std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba.";
        std::cout << " Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan nije namjesten."<<std::endl;
    }
}

class Prodaja
{
    std::string ime_agenta;
    double cijenas;
    Datum datprodaje;
    Kupac kupac;
    Stan kupljenist;
public:

    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) {
        kupac.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja());
    }

    void PromijeniStan(const Stan &novi_stan) {
        kupljenist.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu());
    }
    void PromijeniDatumKupovine(const Datum &novi_datum) {
        datprodaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu());
    }
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        cijenas = nova_cijena;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const {
        return ime_agenta;
    }
    std::string DajImeKupca() const {
        return kupac.DajImePrezime();
    }
    Datum DajDatumProdaje() const {
        return datprodaje;
    }
    double DajCijenuStana() const {
        return cijenas;
    }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan)
    :datprodaje(datum_prodaje.DajDan(),datum_prodaje.DajMjesec(),datum_prodaje.DajGodinu()), kupac(kupac_stana.DajImePrezime(),kupac_stana.DajDatumRodjenja()),
     kupljenist(kupljeni_stan.DajAdresu(),kupljeni_stan.DajSprat(),kupljeni_stan.DajBrojSoba(),kupljeni_stan.DajNamjesten(),kupljeni_stan.DajKvadraturu())
{
    ime_agenta = ime_agenta_prodaje;
    cijenas = cijena_stana;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje, int mjesec_prodaje, int godina_prodaje,std::string &ime_kupca, const Datum &datum_rodjenja_kupca,const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata)
    :datprodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac(ime_kupca,datum_rodjenja_kupca), kupljenist(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)
{
    ime_agenta = ime_agenta_prodaje;
    cijenas = cijena_stana;
}

void Prodaja::PomjeriDanUnaprijed()
{
    int brdana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(datprodaje.DajGodinu()%4==0 && (datprodaje.DajGodinu()%100!=0 || datprodaje.DajGodinu()%400==0)) brdana[1]++;
    if(datprodaje.DajDan() == 31 && datprodaje.DajMjesec() == 12) datprodaje.Postavi(1,1,datprodaje.DajGodinu()+1);
    if(datprodaje.DajDan() == brdana[datprodaje.DajMjesec()-1]) datprodaje.Postavi(1,datprodaje.DajMjesec()+1,datprodaje.DajGodinu());
    else datprodaje.Postavi(datprodaje.DajDan()+1, datprodaje.DajMjesec(), datprodaje.DajGodinu());
}

void Prodaja::PomjeriDanUnazad()
{
    int brdana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(datprodaje.DajGodinu()%4==0 && (datprodaje.DajGodinu()%100!=0 || datprodaje.DajGodinu()%400==0)) brdana[1]++;
    if(datprodaje.DajDan() == 1 && datprodaje.DajMjesec() == 1) datprodaje.Postavi(31,12,datprodaje.DajGodinu()-1);
    if(datprodaje.DajDan() == brdana[datprodaje.DajMjesec()-1]) datprodaje.Postavi(31,datprodaje.DajMjesec()-1,datprodaje.DajGodinu());
    else datprodaje.Postavi(datprodaje.DajDan()-1, datprodaje.DajMjesec(), datprodaje.DajGodinu());
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.datprodaje.DajGodinu() < p2.datprodaje.DajGodinu()) return true;
    else {
        if(p1.datprodaje.DajMjesec() < p2.datprodaje.DajMjesec()) return true;
        else {
            if(p1.datprodaje.DajDan() < p2.datprodaje.DajDan()) return true;
        }
    }
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.cijenas > p2.cijenas) return true;
    return false;
}
void Prodaja::Ispisi() const
{
    std::cout << std::setw(30) << std::left << "Ime agenta: ";
    std::cout << ime_agenta << std::endl;
    std::cout << std::setw(30) << std::left << "Ime kupca: ";
    kupac.Ispisi();
    std::cout << std::endl;
    std::cout << std::setw(30) << std::left << "Zakazani datum prodaje: ";
    datprodaje.Ispisi();
    std::cout << std::endl;
    std::cout << std::setw(30) << std::left << "Cijena stana: ";
    std::cout <<cijenas<<std::endl;
    std::cout <<"Informacije o stanu: " << std::endl;
    kupljenist.Ispisi();
}
class Prodaje
{
    Prodaja** p;
    int broj_prodaja;
    const int maxbr;
    void OslobodiMemoriju();
public:

    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const {
        return broj_prodaja;
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
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;

};
void Prodaje::OslobodiMemoriju()
{
    if(p == nullptr) return;
    for(int i(0); i<broj_prodaja; i++)
        delete p[i];
    delete[] p;
}
Prodaje::Prodaje(int max_broj_prodaja) : broj_prodaja(0), maxbr(max_broj_prodaja)
{
    p = nullptr;
    try {
        p = new Prodaja *[maxbr];
    } catch(...) {
        OslobodiMemoriju();
        throw;
    }
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) :broj_prodaja(spisak_prodaja.size()), maxbr(spisak_prodaja.size())
{
    p = nullptr;
    try {
        p = new Prodaja *[maxbr];
    } catch(...) {
        OslobodiMemoriju();
        throw;
    }
    auto it = spisak_prodaja.begin();
    try {
        for(int i(0); i<broj_prodaja; i++) p[i] = new Prodaja(*it++);
    } catch(...) {
        OslobodiMemoriju();
        throw;
    }

}
Prodaje::~Prodaje()
{
    for(int i(0); i<broj_prodaja; i++) delete p[i];
    delete[] p;
}

Prodaje::Prodaje(const Prodaje &prodaje) : broj_prodaja(prodaje.broj_prodaja), maxbr(prodaje.maxbr)
{
    p = nullptr;
    try {
        p = new Prodaja*[maxbr];
    } catch(...) {
        OslobodiMemoriju();
        throw;
    }

    try {
        for(int i(0); i<broj_prodaja; i++)
            this->p[i] = new Prodaja(*prodaje.p[i]);
    } catch(...) {
        OslobodiMemoriju();
        throw;
    }
}

Prodaje::Prodaje(Prodaje &&prodaje):broj_prodaja(prodaje.broj_prodaja), maxbr(prodaje.maxbr)
{
    p = prodaje.p;
    prodaje.p = nullptr;
}

Prodaje &Prodaje::operator =(const Prodaje &prodaje)
{
    if(&prodaje==this) return *this;
    for(int i(0); i<broj_prodaja; i++) delete p[i];
    broj_prodaja = prodaje.broj_prodaja;

    try {
        for(int i(0); i<broj_prodaja; i++)
            p[i] = new Prodaja(*prodaje.p[i]);
    } catch(...) {
        OslobodiMemoriju();
        throw;
    }
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje)
{
    if(&prodaje==this) return *this;
    p = prodaje.p;
    broj_prodaja = prodaje.broj_prodaja;
    prodaje.p = nullptr;
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,const Stan &kupljeni_stan)
{
    if(broj_prodaja >= maxbr) throw std::range_error("Dostignut maksimalni broj prodaja");
    try {
        p[broj_prodaja++] = new Prodaja({ime_agenta_prodaje,cijena_stana,datum_prodaje,kupac_stana,kupljeni_stan});
    } catch(std::bad_alloc) {
        broj_prodaja--;
        throw std::domain_error("Problemi sa memorijom");
    } catch(...) {
        broj_prodaja--;
        throw;
    }
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,int dan_prodaje,int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if(broj_prodaja >= maxbr) throw std::range_error("Dostignut maksimalni broj prodaja");
    try {
        p[broj_prodaja++] = new Prodaja({ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata});
    } catch(std::bad_alloc) {
        broj_prodaja--;
        throw std::domain_error("Problemi sa memorijom");
    } catch(...) {
        broj_prodaja--;
        throw;
    }
}

void Prodaje::RegistrirajProdaju(Prodaja *prodaja)
{
    if(broj_prodaja >= maxbr) throw std::range_error("Dostignut maksimalni broj prodaja");
    p[broj_prodaja++] = prodaja;
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const
{
    int broj = std::count_if(p,p+broj_prodaja, [datum] (Prodaja *pok) {
        Datum pom = pok->DajDatumProdaje();
        if(datum.DajDan() == pom.DajDan() && datum.DajMjesec() == pom.DajMjesec() && datum.DajGodinu() == pom.DajGodinu()) return true;
        return false;
    });
    return broj;
}

int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const
{
    int broj = std::count_if(p,p+broj_prodaja, [ime_agenta] (Prodaja *pok) {
        std::string pom = pok->DajImeAgenta();
        if(pom == ime_agenta) return true;
        return false;
    });
    return broj;
}

Prodaja Prodaje::DajNajranijuProdaju() const
{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najraniji = **(std::min_element(p,p+broj_prodaja,[](Prodaja *pok1,Prodaja *pok2) {
        Datum datum1 = pok1->DajDatumProdaje();
        Datum datum2 = pok2->DajDatumProdaje();
        if(datum1.DajGodinu() == datum2.DajGodinu()) {
            if(datum1.DajMjesec() == datum2.DajMjesec()) {
                return datum1.DajDan() < datum2.DajDan();
            }
            return datum1.DajMjesec() < datum2.DajMjesec();
        }
        return (datum1.DajGodinu() < datum2.DajGodinu());
        return false;
    }));
    return najraniji;
}

Prodaja &Prodaje::DajNajranijuProdaju()
{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najraniji = std::min_element(p,p+broj_prodaja,[](Prodaja *pok1,Prodaja *pok2) {
        Datum datum1 = pok1->DajDatumProdaje();
        Datum datum2 = pok2->DajDatumProdaje();
        if(datum1.DajGodinu() == datum2.DajGodinu()) {
            if(datum1.DajMjesec() == datum2.DajMjesec()) {
                return datum1.DajDan() < datum2.DajDan();
            }
            return datum1.DajMjesec() < datum2.DajMjesec();
        }
        return (datum1.DajGodinu() < datum2.DajGodinu());
        return false;
    });
    auto q = p;
    while(q!=(q+broj_prodaja)) {
        if(q==najraniji) {
            p=q;
            return **p;
        }
        q++;
    }
}

Prodaja Prodaje::DajNajskupljuProdaju() const
{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najskuplja = **(std::max_element(p,p+broj_prodaja, [](Prodaja *pok1,Prodaja *pok2) {
        double stan1 = pok1->DajCijenuStana();
        double stan2 = pok2->DajCijenuStana();
        if(stan1>stan2) return true;
        return false;
    }));
    return najskuplja;
}
Prodaja &Prodaje::DajNajskupljuProdaju()
{
    if(broj_prodaja==0) throw std::domain_error("Nema registriranih prodaja");
    auto najskuplja = std::max_element(p,p+broj_prodaja, [](Prodaja *pok1,Prodaja *pok2) {
        double stan1 = pok1->DajCijenuStana();
        double stan2 = pok2->DajCijenuStana();
        if(stan1>stan2) return true;
        return false;
    });
    auto q = p;
    while(q!=(q+broj_prodaja)) {
        if(q==najskuplja) {
            p=q;
            return **p;
        }
        q++;
    }
}

void Prodaje::IsprazniKolekciju()
{
    OslobodiMemoriju();
    broj_prodaja=0;
}

void Prodaje::ObrisiNajranijuProdaju()
{
    if(broj_prodaja == 0) throw std::range_error("Prazna kolekcija");
    Prodaja najranija = DajNajranijuProdaju();
    for(int i(0); i<broj_prodaja; i++) {
        if(&najranija == p[i]) {
            delete p[i];
            p[i]=nullptr;
        }
    }
}

void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta)
{
    if(broj_prodaja == 0) throw std::range_error("Prazna kolekcija");
    for(int i(0); i<broj_prodaja; i++) {
        if(ime_agenta == p[i]->DajImeAgenta()) {
            delete p[i];
            p[i] = nullptr;
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    if(broj_prodaja == 0) throw std::range_error("Prazna kolekcija");
    for(int i(0); i<broj_prodaja; i++) {
        Datum pomocni = p[i]->DajDatumProdaje();
        if(pomocni.DajDan() == datum.DajDan() && pomocni.DajMjesec() == datum.DajMjesec() && pomocni.DajGodinu() == datum.DajGodinu()) {
            delete p[i];
            p[i] = nullptr;
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    Prodaja **pok = nullptr;
    pok = new Prodaja*[broj_prodaja];
    int k(0);
    for(int i(0); i<broj_prodaja; i++) {
        if(datum.DajDan() == p[i]->DajDatumProdaje().DajDan() && datum.DajMjesec() == p[i]->DajDatumProdaje().DajMjesec() && datum.DajGodinu() == p[i]->DajDatumProdaje().DajGodinu()) {
            pok[k] = new Prodaja(*p[i]);
        }
    }
    std::sort(pok, pok+k, [](Prodaja *p1, Prodaja *p2) {
        if(p1->DajImeKupca() < p2->DajImeKupca()) return true;
        return false;
    });
    for(int i(0); i<k; i++) {
        pok[i]->Ispisi();
        std::cout << std::endl;
    }
}

void Prodaje::IspisiSveProdaje() const
{
    std::sort(p, p+broj_prodaja, [](Prodaja *p1, Prodaja *p2) {
        Datum datum1 = p1->DajDatumProdaje();
        Datum datum2 = p2->DajDatumProdaje();
        if(datum1.DajGodinu() == datum2.DajGodinu()) {
            if(datum1.DajMjesec() == datum2.DajMjesec()) {
                return datum1.DajDan() < datum2.DajDan();
            }
            return datum1.DajMjesec() < datum2.DajMjesec();
        }
        return (datum1.DajGodinu() < datum2.DajGodinu());
        return false;
    });
    for(int i(0); i<broj_prodaja; i++) {
        p[i]->Ispisi();
        std::cout << std::endl;
    }
}

int main ()
{
    std::vector<Stan> stanovi;
    std::vector<Kupac>kupci;
    std::vector<Prodaja> prodaje;
    std::cout << "Dobrodosli!"<<std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    while(1) {
        original: std::cout << "Izaberite opciju:" << std::endl;
        std::cout << " 0 - kraj" <<std::endl<< 
        " 1 - uredjivanje stanova" << std::endl <<
        " 2 - uredjivanje kupaca" << std::endl <<
        " 3 - uredjivanje prodaja"<<std::endl;
        int opcija;
        std::cin >> opcija;
        //std::cin.ignore(10000, '\n');
        if(opcija == 1) {
            while (1) {
                opet1: std::cout << "Izaberite opciju:" << std::endl;
                std::cout << " 0 - nazad" <<std::endl<< 
                " 1 - dodavanje stana" << std::endl <<
                " 2 - uredjivanje stanova" << std::endl <<
                " 3 - ispis svih stanova" << std::endl <<
                " 4 - kraj"<<std::endl;
                int opcija2;
                std::cin >> opcija2;
                //std::cin.ignore(10000, '\n');
                if(opcija2 == 1) {
                    opet2:
                    try {
                    std::cin.ignore(10000, '\n');
                    std::cout <<"Unesite adresu: ";
                    std::string imestana;
                    std::getline(std::cin, imestana);
                    
                    std::cout << "Unesite sprat: ";
                    int spratst;
                    std::cin >> spratst;
                    //std::cin.ignore(10000, '\n');
                    std::cout<< "Unesite broj soba: ";
                    int brsb;
                    std::cin >> brsb;
                    //std::cin.ignore(10000, '\n');
                    std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                    int nam;
                    std::cin >> nam;
                    //std::cin.ignore(10000, '\n');
                    bool nams;
                    if(nam == 1) nams=true;
                    else nams = false;
                    std::cout << "Unesite kvadraturu: ";
                    double kv;
                    std::cin >> kv;
                    //std::cin.ignore(10000, '\n');
                    if(nam<0 || nam>1) throw std::domain_error("Pogresan bool");
                    Stan a(imestana, spratst, brsb, nams, kv);
                    stanovi.push_back(a);
                    }
                    catch(...) {
                        std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet."<<std::endl;
                        goto opet2;
                    }
                    std::cout << "Stan je uspjesno dodan!"<<std::endl;
                    std::cout << std::endl;
                    goto opet1;
                }
                if(opcija2 == 3) {
                    for(int i(0); i<stanovi.size(); i++) {
                        std::cout << i+1 <<". ";
                        stanovi[i].Ispisi();
                    }
                    std::cout << std::endl;
                    goto opet1;
                }
                if(opcija2 == 2) {
                    std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                    for(int i(0); i<stanovi.size(); i++) {
                        std::cout <<" "<< i+1 <<" - ";
                        stanovi[i].Ispisi();
                    }
                    std::cout << std::endl;
                    int indexstana;
                    std::cin >> indexstana;
                    //std::cin.ignore(10000, '\n');
                    std::cout << "Odaberite polje koje zelite urediti:" << std::endl<<
                                 " 0 - nazad" << std::endl <<
                                 " 1 - adresa" << std::endl <<
                                 " 2 - sprat" << std::endl <<
                                 " 3 - broj soba" << std::endl <<
                                 " 4 - da li je stan namjesten" <<std::endl <<
                                 " 5 - kvadratura" << std::endl <<
                                  " 6 - sve";
                                  std::cout << std::endl;
                    int opcija3;
                    std::cin >> opcija3;
                    //std::cin.ignore(10000, '\n');
                    if(opcija3 == 0) {
                        
                    }
                    if(opcija3 == 1) {
                        std::cin.ignore(10000, '\n');
                        opet5:
                            std::cout << "Unesite adresu: ";
                            std::string imestana;
                            std::getline(std::cin, imestana);
                            try {
                            stanovi[indexstana-1].Postavi(imestana, stanovi[indexstana-1].DajSprat(), stanovi[indexstana-1].DajBrojSoba(), stanovi[indexstana-1].DajNamjesten(), stanovi[indexstana-1].DajKvadraturu());
                        }
                        catch(...) {
                            std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.";
                            std::cout << std::endl;
                            goto opet5;
                        }
                        std::cout << "Stan je uspjesno izmijenjen! ";
                        std::cout << std::endl;
                        goto opet1;
                    }
                    if(opcija3 == 2) {
                        opet6:
                            std::cout << "Unesite sprat: ";
                            int spratst;
                            std::cin >> spratst;
                            //std::cin.ignore(10000, '\n');
                            try {
                            stanovi[indexstana-1].Postavi(stanovi[indexstana-1].DajAdresu(), spratst, stanovi[indexstana-1].DajBrojSoba(), stanovi[indexstana-1].DajNamjesten(), stanovi[indexstana-1].DajKvadraturu());
                        }
                        catch(...) {
                            std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.";
                            std::cout << std::endl;
                            goto opet6;
                        }
                        std::cout << "Stan je uspjesno izmijenjen! ";
                        std::cout << std::endl;
                        goto opet1;
                    }
                    if(opcija3 == 3) {
                        opet7:
                             std::cout<< "Unesite broj soba: ";
                             int brsb;
                             std::cin >> brsb;
                             //std::cin.ignore(10000, '\n');
                             try {
                             stanovi[indexstana-1].Postavi(stanovi[indexstana-1].DajAdresu(),stanovi[indexstana-1].DajSprat(), brsb, stanovi[indexstana-1].DajNamjesten(), stanovi[indexstana-1].DajKvadraturu());
                        }
                        catch(...) {
                            std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.";
                            std::cout << std::endl;
                            goto opet7;
                        }
                        std::cout << "Stan je uspjesno izmijenjen! ";
                        std::cout << std::endl;
                        goto opet1;
                    }
                    if(opcija3 == 4) {
                        opet8:
                        try{
                             std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                             int nam;
                             std::cin >> nam;
                             //std::cin.ignore(10000, '\n');
                             if(nam<0 || nam>1) throw std::domain_error("Pogresan bool");
                             bool nams;
                             if(nam == 1) nams=true;
                             else nams = false;
                             
                             stanovi[indexstana-1].Postavi(stanovi[indexstana-1].DajAdresu(),stanovi[indexstana-1].DajSprat(), stanovi[indexstana-1].DajBrojSoba(), nams, stanovi[indexstana-1].DajKvadraturu());
                        }
                        catch(...) {
                            std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.";
                            std::cout << std::endl;
                            goto opet8;
                        }
                        std::cout << "Stan je uspjesno izmijenjen! ";
                        std::cout << std::endl;
                        goto opet1;
                    }
                    if(opcija3 == 5) {
                        opet3:
                            std::cout << "Unesite kvadraturu: ";
                            double novakvadratura;
                            std::cin >> novakvadratura;
                            //std::cin.ignore(10000, '\n');
                            try {
                            stanovi[indexstana-1].Postavi(stanovi[indexstana-1].DajAdresu(), stanovi[indexstana-1].DajSprat(), stanovi[indexstana-1].DajBrojSoba(), stanovi[indexstana-1].DajNamjesten(), novakvadratura);
                        }
                        catch(...) {
                            std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.";
                            std::cout << std::endl;
                            goto opet3;
                        }
                        std::cout << "Stan je uspjesno izmijenjen! ";
                        std::cout << std::endl;
                        goto opet1;
                    }
                    if(opcija3 == 6) {
                        std::cin.ignore(10000, '\n');
                        opet4: 
                        try{
                        std::cout << "Unesite adresu: ";
                        std::string imestana;
                        std::getline(std::cin, imestana);
                        //std::cin.ignore(10000, '\n');
                        std::cout << "Unesite sprat: ";
                        int spratst;
                        std::cin >> spratst;
                        //std::cin.ignore(10000, '\n');
                        std::cout<< "Unesite broj soba: ";
                        int brsb;
                        std::cin >> brsb;
                        //std::cin.ignore(10000, '\n');
                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                        int nam;
                        std::cin >> nam;
                        
                        //std::cin.ignore(10000, '\n');
                        bool nams;
                        if(nam == 1) nams=true;
                        else nams = false;
                        std::cout << "Unesite kvadraturu: ";
                        double kv;
                        std::cin >> kv;
                        //std::cin.ignore(10000, '\n');
                        if(nam<0 || nam>1) throw std::domain_error("Pogresan bool");
                        stanovi[indexstana-1].Postavi(imestana,spratst,brsb,nams,kv);
                        }
                        catch(...) {
                            std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.";
                            std::cout << std::endl;
                            goto opet4;
                        }
                        std::cout << "Stan je uspjesno izmijenjen! ";
                        std::cout << std::endl;
                        goto opet1;
                    }
                    
                }
                if(opcija2 == 0) {
                    goto original;
                }
                if(opcija2 == 4) {
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "Dovidjenja!";
                    return 0;
                }
            }
        }
        if(opcija == 2) {
            while (1) {
                opet9: std::cout <<"Izaberite opciju:" << std::endl;
                std::cout << " 0 - nazad" <<std::endl<< 
                " 1 - dodavanje kupca" << std::endl <<
                " 2 - uredjivanje kupaca" << std::endl <<
                " 3 - ispis svih kupaca" << std::endl <<
                " 4 - kraj"<<std::endl;
                int opcija4;
                std::cin >> opcija4;
                //std::cin.ignore(10000, '\n');
                if(opcija4 == 0) goto original;
                if(opcija4 == 4) {
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "Dovidjenja!";
                    return 0;
                }
                if(opcija4 == 1) {
                    
                    std::cin.ignore(10000, '\n');
                    opet10:
                    std::cout << "Unesite ime i prezime kupca: ";
                    std::string imekupca;
                    std::getline(std::cin, imekupca);
                    std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                    std::string datum;
                    std::getline(std::cin, datum);
                    //std::cin.ignore(10000, '\n');
                    int dan=0,mjesec=0,godina=0;
                        for(int i(0); i<datum.length(); i++) {
                                if(i==0) {
                                    if(datum[i+1]=='/') {
                                        dan = datum[i]-'0';
                                        i++;
                                    }
                                    else {
                                    int n=10;
                                    while(datum[i] !='/') {
                                        dan += (datum[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    }
                                    }
                                }
                                if(datum[i] == '/' && datum[i+3] =='/') {
                                    i++;
                                     int n=10;
                                    while(datum[i] !='/') {
                                        mjesec += (datum[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    }   
                                }
                                if(datum[i] == '/' && datum[i+2] == '/') {
                                    i++;
                                    mjesec = datum[i]-'0';
                                }
                                else {
                                    i++;
                                    int n=1000;
                                    while(i!=datum.length()) {
                                        godina += (datum[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    } 
                                
                                }
                                if(i>=datum.length())i--;
                            }
                           
                        try {
                        Datum d(dan,mjesec,godina);
                        Kupac k(imekupca,d);
                        kupci.push_back(k);
                    }
                    catch(std::domain_error izuzetak) {
                        std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet."<<std::endl;
                        goto opet10;
                    }
                    std::cout << "Kupac je uspjesno dodan!"<<std::endl;
                    std::cout <<std::endl;
                    goto opet9;
                }
                if(opcija4 == 3) {
                    for(int i(0); i<kupci.size(); i++) {
                        kupci[i].Ispisi();
                        std::cout << std::endl;
                    }
                    std::cout <<std::endl;
                    goto opet9;
                }
                if(opcija4 == 2) {
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<std::endl;
                    for(int i(0); i<kupci.size(); i++) {
                        std::cout<<" " << i+1 << " - ";
                        kupci[i].Ispisi();
                        std::cout << std::endl;
                    }
                    int indexkupca;
                    std::cin >> indexkupca;
                    std::cin.ignore(10000, '\n');
                    opet11:
                    std::cout << "Unesite ime i prezime kupca: ";
                    std::string imekupca;
                    std::getline(std::cin, imekupca);
                    //std::cin.ignore(10000, '\n');
                    std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                    std::string datum;
                    std::getline(std::cin, datum);
                    //std::cin.ignore(10000, '\n');
                    int dan=0,mjesec=0,godina=0;
                        for(int i(0); i<datum.length(); i++) {
                                if(i==0) {
                                    if(datum[i+1]=='/') {
                                        dan = datum[i]-'0';
                                        i++;
                                    }
                                    else {
                                    int n=10;
                                    while(datum[i] !='/') {
                                        dan += (datum[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    }
                                    }
                                }
                                if(datum[i] == '/' && datum[i+3] =='/') {
                                    i++;
                                     int n=10;
                                    while(datum[i] !='/') {
                                        mjesec += (datum[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    }   
                                }
                                if(datum[i] == '/' && datum[i+2] == '/') {
                                    i++;
                                    mjesec = datum[i]-'0';
                                }
                                else {
                                    i++;
                                    int n=1000;
                                    while(i!=datum.length()) {
                                        godina += (datum[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    } 
                                
                                }
                                if(i>=datum.length())i--;
                            }
                            try {
                            Datum d(dan,mjesec,godina);
                            kupci[indexkupca-1].Postavi(imekupca,d);
                    }
                    catch(std::domain_error izuzetak) {
                        std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.";
                        goto opet11;
                    }
                    std::cout << "Kupac je uspjesno izmijenjen!" << std::endl;
                    goto opet9;
                }
            }
        }
        if(opcija == 3) {
            while(1) {
                previous: std::cout << "Izaberite opciju:" << std::endl <<
                              " 0 - nazad" << std::endl <<
                              " 1 - dodavanje prodaje" << std::endl <<
                              " 2 - uredjivanje prodaje" << std::endl <<
                              " 3 - ispis prodaja" << std::endl <<
                              " 4 - brisanje prodaja" << std::endl <<
                              " 5 - kraj" << std::endl;
                
                int no1;
                std::cin >> no1;
                
                if(no1 == 0) {
                    goto original;
                }
                if(no1 == 1) {
                    previous1: std::cout << "Izaberite opciju:" << std::endl <<
                              " 0 - nazad" << std::endl <<
                              " 1 - dodavanje potpuno nove prodaje" << std::endl <<
                              " 2 - dodavanje nove prodaje na osnovu arhive" << std::endl <<
                              " 3 - kraj" << std::endl;
                    int no2;
                    std::cin >> no2;
                    if(no2 == 0) {
                        goto previous;
                    }
                    if(no2 == 1) {
                        try { std::cout << "Unesite ime i prezime agenta prodaje: ";
                        std::string imeagenta;
                        std::getline(std::cin, imeagenta);
                        std::cout << "Unesite datum prodaje (formata d/m/g): ";
                        std::string datum;
                        std::getline(std::cin, datum);
                        int dan=0,mjesec=0,godina=0;
                        for(int i(0); i<datum.length(); i++) {
                                if(i==0) {
                                    if(datum[i+1]=='/') {
                                        dan = datum[i]-'0';
                                        i++;
                                    }
                                    else {
                                    int n=10;
                                    while(datum[i] !='/') {
                                        dan += (datum[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    }
                                    }
                                }
                                if(datum[i] == '/' && datum[i+3] =='/') {
                                    i++;
                                     int n=10;
                                    while(datum[i] !='/') {
                                        mjesec += (datum[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    }   
                                }
                                if(datum[i] == '/' && datum[i+2] == '/') {
                                    i++;
                                    mjesec = datum[i]-'0';
                                }
                                else {
                                    i++;
                                    int n=1000;
                                    while(i!=datum.length()) {
                                        godina += (datum[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    } 
                                
                                }
                                if(i>=datum.length())i--;
                            }
                        std::cout << "Unesite cijenu stana: ";
                        double cijenas;
                        std::cin>> cijenas;
                        std::cout << "Unesite ime kupca: ";
                        std::string imekupca;
                        std::getline(std::cin,imekupca);
                        std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                        std::string datum1;
                        std::getline(std::cin, datum1);
                        int dan1=0,mjesec1=0,godina1=0;
                        for(int i(0); i<datum1.length(); i++) {
                                if(i==0) {
                                    if(datum1[i+1]=='/') {
                                        dan1 = datum1[i]-'0';
                                        i++;
                                    }
                                    else {
                                    int n=10;
                                    while(datum1[i] !='/') {
                                        dan1 += (datum1[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    }
                                    }
                                }
                                if(datum1[i] == '/' && datum1[i+3] =='/') {
                                    i++;
                                     int n=10;
                                    while(datum1[i] !='/') {
                                        mjesec1 += (datum1[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    }   
                                }
                                if(datum1[i] == '/' && datum1[i+2] == '/') {
                                    i++;
                                    mjesec1 = datum1[i]-'0';
                                }
                                else {
                                    i++;
                                    int n=1000;
                                    while(i!=datum1.length()) {
                                        godina1 += (datum1[i]-'0')*n;
                                        n/=10;
                                        i++;
                                    } 
                                
                                }
                                if(i>=datum1.length())i--;
                            }
                            std::cin.ignore(10000, '\n');
                            std::cout <<"Unesite adresu: ";
                            std::string imestana;
                            std::getline(std::cin, imestana);
                    
                    std::cout << "Unesite sprat: ";
                    int spratst;
                    std::cin >> spratst;
                    //std::cin.ignore(10000, '\n');
                    std::cout<< "Unesite broj soba: ";
                    int brsb;
                    std::cin >> brsb;
                    //std::cin.ignore(10000, '\n');
                    std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                    int nam;
                    std::cin >> nam;
                    //std::cin.ignore(10000, '\n');
                    bool nams;
                    if(nam == 1) nams=true;
                    else nams = false;
                    std::cout << "Unesite kvadraturu: ";
                    double kv;
                    std::cin >> kv;
                    //std::cin.ignore(10000, '\n');
                    if(nam<0 || nam>1) throw std::domain_error("Pogresan bool");
                        Datum d(dan,mjesec,godina);
                        Stan a(imestana, spratst, brsb, nams, kv);
                        Datum d1(dan1,mjesec1,godina1);
                        Kupac k(imekupca, d1);
                        Prodaja p(imeagenta, cijenas, d, k, a);
                        prodaje.push_back(p);
                        }
                        catch(...) {
                            
                        }
                        std::cout << "Prodaja uspjesno dodana!"<<std::endl;
                        std::cout << std::endl;
                        goto previous1;
                    }
                    if(no2 == 2) {
                        
                    }
                    if(no2 == 3) {
                        std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "Dovidjenja!";
                        return 0;
                    }
                }
                if(no1 == 2) {
                    
                }
                if(no1 == 3) {
                    
                }
                if(no1 == 4) {
                    
                }
                if(no1 == 5) {
                    std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "Dovidjenja!";
                    return 0;
                }
            }
        }
        if(opcija == 0) {
            std::cout << std::endl;
            std::cout << std::endl;
            std::cout << "Dovidjenja!";
            return 0;
        }
    }
    return 0;
}