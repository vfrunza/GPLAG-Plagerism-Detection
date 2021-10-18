/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

class Datum {
    int d, mj, god;
    public:
    Datum (int dan, int mjesec, int godina) { Postavi(dan,mjesec,godina); }
    void Postavi (int dan, int mjesec, int godina);
    int DajDan() const { return d; }
    int DajMjesec() const { return mj; }
    int DajGodinu() const { return god; }
    void PredjiNaSljedeciDan();
    void VratiZaJedanDan();
    void Ispisi() const { std::cout << d << "/" << mj << "/" << god; }
    friend class Kupac;
};

void Datum::Postavi (int dan, int mjesec, int godina) {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if (godina<1 || mjesec<1 || dan<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error ("Neispravan datum");
    d=dan; mj=mjesec; god=godina;
}

void Datum::PredjiNaSljedeciDan () {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((god%4==0 && god&100!=0) || god%400==0) broj_dana[1]++;
    d++;
    if (d>broj_dana[mj-1]) {
        d=1;
        mj++;
    }
    if (mj>12) {
        mj=1;
        god++;
    }
}

void Datum::VratiZaJedanDan() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((god%4==0 && god&100!=0) || god%400==0) broj_dana[1]++;
    d--;
    if (d==0 && mj!=1) {
        mj--;
        d=broj_dana[mj-1];
    }
    if (d==0 && mj==1) {
        mj=12;
        d=31;
        god--;
    }
}

class Kupac {
    std::string ime_i_prez;
    Datum datum_rodj;
    public:
    Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime_i_prez; }
    Datum DajDatumRodjenja() const { return datum_rodj; }
    void Ispisi() const { 
        std::cout << ime_i_prez << " (";
        datum_rodj.Ispisi();
        std::cout << ")";
    }
};

Kupac::Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja):datum_rodj(datum_rodjenja) {
    for (int i=0; i<ime_i_prezime.length(); i++) {
        if (!((tolower(ime_i_prezime[i])>='a' && tolower(ime_i_prezime[i])<='z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9')
        || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' || ime_i_prezime[i]==39)) throw std::domain_error ("Neispravno ime i prezime");
    }
    ime_i_prez=ime_i_prezime;
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    for (int i=0; i<ime_i_prezime.length(); i++) {
        if (!((tolower(ime_i_prezime[i])>='a' && tolower(ime_i_prezime[i])<='z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9')
        || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' || ime_i_prezime[i]==39)) throw std::domain_error ("Neispravno ime i prezime");
    }
    ime_i_prez=ime_i_prezime;
    datum_rodj.d=datum_rodjenja.d;
    datum_rodj.mj=datum_rodjenja.mj;
    datum_rodj.god=datum_rodjenja.god;
}

class Stan {
    std::string adr;
    int kat, br_soba;
    bool namjest;
    double kvdr;
    public:
    Stan (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adr; }
    int DajSprat() const { return kat; }
    int DajBrojSoba() const { return br_soba; }
    bool DajNamjesten() const { return namjest; }
    double DajKvadraturu() const { return kvdr; }
    void Ispisi() const;
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error ("Neispravan unos podataka");
    adr=adresa;
    kat=sprat;
    br_soba=broj_soba;
    namjest=namjesten;
    kvdr=kvadratura;
}

void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adr << " na " << kat << ". spratu i ima " << br_soba;
    if ((br_soba>=5 && br_soba<=20) || (br_soba>20 && br_soba%10>=5 && br_soba%10<=9)) std::cout << " soba.";
    if ((br_soba>=2 && br_soba<=4) || (br_soba>20 && br_soba%10>=2 && br_soba%10<=4)) std::cout << " sobe.";
    if (br_soba==1 || (br_soba>20 && br_soba%10==1)) std::cout << " sobu.";
    std::cout << " Kvadratura stana je " << kvdr << "(m^2) i stan ";
    if (namjest) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}

class Prodaja {
    std::string ime_ag_pr;
    double cijena_st;
    Datum datum_prod;
    Kupac kupac_st;
    Stan kupljeni_st;
    public:
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, 
    const Stan &kupljeni_stan):ime_ag_pr(ime_agenta_prodaje), cijena_st(cijena_stana), datum_prod(datum_prodaje),
    kupac_st(kupac_stana), kupljeni_st(kupljeni_stan) {};
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, 
    bool namjesten_stan, double broj_kvadrata):ime_ag_pr(ime_agenta_prodaje), cijena_st(cijena_stana), 
    datum_prod(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_st(ime_kupca, datum_rodjenja_kupca),
    kupljeni_st(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {};
    void PromijeniKupca (const Kupac &novi_kupac) { kupac_st=novi_kupac; }
    void PromijeniStan (const Stan &novi_stan) { kupljeni_st=novi_stan; }
    void PromijeniDatumKupovine (const Datum &novi_datum) { datum_prod=novi_datum; }
    void PromijeniCijenuProdaje (const double &nova_cijena) { cijena_st=nova_cijena; }
    void PomjeriDanUnaprijed () { datum_prod.PredjiNaSljedeciDan(); }
    void PomjeriDanUnazad () { datum_prod.VratiZaJedanDan(); }
    std::string DajImeAgenta () const { return ime_ag_pr; }
    std::string DajImeKupca () const { return kupac_st.DajImePrezime(); }
    Datum DajDatumProdaje () const { return datum_prod; }
    double DajCijenuStana () const { return cijena_st; }
    friend bool ProdatPrije (const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

bool ProdatPrije (const Prodaja &p1, const Prodaja &p2) {
    return p1.datum_prod.DajGodinu()<p2.datum_prod.DajGodinu() || p1.datum_prod.DajGodinu()==p2.datum_prod.DajGodinu() &&
    p1.datum_prod.DajMjesec()<p2.datum_prod.DajMjesec() || p1.datum_prod.DajGodinu()==p2.datum_prod.DajGodinu() &&
    p1.datum_prod.DajMjesec()==p2.datum_prod.DajMjesec() && p1.datum_prod.DajDan()<p2.datum_prod.DajDan();
}

bool SkupljiStan (const Prodaja &p1, const Prodaja &p2) {
    return p1.cijena_st>p2.cijena_st;
}

void Prodaja::Ispisi() const {
    std::cout << std::setw(30) << std::left << "Ime agenta: " << std::setw(30) << std::left << ime_ag_pr <<
    std::endl << std::setw(30) << std::left << "Ime kupca: " << std::setw(30) << std::left;
    kupac_st.Ispisi();
    std::cout << std::endl << std::setw(30) << std::left << "Zakazani datum prodaje:" << std::setw(30) << std::left;
    datum_prod.Ispisi();
    std::cout << std::endl << std::setw(30) << std::left << "Cijena stana: "<< std::setw(30) << std::left << cijena_st; 
    std::cout << std::endl << "Informacije o stanu: " << std::endl;
    kupljeni_st.Ispisi();
}

class Prodaje {
    int max_broj_prod, broj_prodaja;
    Prodaja** pok;
    public:
    explicit Prodaje (int max_broj_prodaja) {
        if (max_broj_prodaja<=0) throw std::domain_error ("Neispravan unos podataka");
        max_broj_prod=max_broj_prodaja;
        broj_prodaja=0;
        pok=new Prodaja*[max_broj_prodaja];
    }
    Prodaje (std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje() {
        for (int i=0; i<broj_prodaja; i++) delete pok[i];
        delete [] pok;
    }
    Prodaje (const Prodaje &prodaje);
    Prodaje (Prodaje &&prodaje);
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje && prodaje);
    void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
    const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju (const std::string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju (Prodaja* prodaja);
    int DajBrojProdaja() const {return broj_prodaja; }
    int DajBrojProdajaNaDatum (const Datum &datum) const;
    int DajBrojProdajaOdAgenta (const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta (const std::string &ime_agenta);
    void ObrisiProdajeNaDatum (const Datum &datum);
    void IspisiProdajeNaDatum (const Datum &datum) const;
    void IspisiSveProdaje() const;
};

Prodaje::Prodaje (std::initializer_list<Prodaja> spisak_prodaja) {
    max_broj_prod=spisak_prodaja.size();
    broj_prodaja=0;
    pok=new Prodaja*[max_broj_prod];
    for (Prodaja p:spisak_prodaja) {
        pok[broj_prodaja]=new Prodaja(p);
        broj_prodaja++;
    }
}

Prodaje::Prodaje (const Prodaje &prodaje) {
    broj_prodaja=prodaje.broj_prodaja;
    max_broj_prod=prodaje.max_broj_prod;
    pok=new Prodaja*[max_broj_prod];
    for (int i=0; i<broj_prodaja; i++) pok[i]=new Prodaja(*prodaje.pok[i]);
}

Prodaje::Prodaje (Prodaje &&prodaje) {
    broj_prodaja=prodaje.broj_prodaja;
    max_broj_prod=prodaje.max_broj_prod;
    pok=prodaje.pok;
    prodaje.pok=nullptr;
    prodaje.broj_prodaja=0;
}

Prodaje &Prodaje::operator= (const Prodaje &prodaje) {
    if (this==&prodaje) return *this;
    for (int i=0; i<broj_prodaja; i++) delete pok[i];
    delete [] pok;
    broj_prodaja=prodaje.broj_prodaja;
    max_broj_prod=prodaje.max_broj_prod;
    pok=new Prodaja*[max_broj_prod];
    for (int i=0; i<broj_prodaja; i++) pok[i]=new Prodaja(*prodaje.pok[i]);
    return *this;
}

Prodaje &Prodaje::operator= (Prodaje &&prodaje) {
    if (this==&prodaje) return *this;
    for (int i=0; i<broj_prodaja; i++) delete pok[i];
    delete [] pok;
    broj_prodaja=prodaje.broj_prodaja;
    max_broj_prod=prodaje.max_broj_prod;
    pok=prodaje.pok;
    prodaje.broj_prodaja=0;
    prodaje.pok=nullptr;
    return *this;
} 


int main ()
{
	return 0;
}