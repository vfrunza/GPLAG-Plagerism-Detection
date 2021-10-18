/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>

static const double eps(1e-10);

class Datum {
    int dan, mjesec, godina;
    bool ProvjeriDatum(int dan, int mjesec, int godina) const;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
};
Datum::Datum(int dan, int mjesec, int godina) {
    if (!ProvjeriDatum(dan, mjesec, godina)) throw std::domain_error ("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
void Datum::Postavi(int dan, int mjesec, int godina) {
    if (!ProvjeriDatum(dan, mjesec, godina)) throw std::domain_error ("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}
bool Datum::ProvjeriDatum(int dan, int mjesec, int godina) const {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if (godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1])
        return false;
    return true;
}
class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const { std::cout << ime_i_prezime << " (" << datum_rodjenja.DajDan() << "/" << datum_rodjenja.DajMjesec() << "/" << datum_rodjenja.DajGodinu() << ")"; }
};
bool ProvjeriIme(std::string ime_i_prezime) {
    for (int i = 0; i < ime_i_prezime.size(); i++) {
        if (!(std::tolower(ime_i_prezime[i]) >= 'a' && std::tolower(ime_i_prezime[i]) <= 'z')
        && !(ime_i_prezime[i] >= '0' && ime_i_prezime[i] <= '9') && ime_i_prezime[i] != ' ' &&
        ime_i_prezime[i] != 39 && ime_i_prezime[i] != '-') return false;
    }
    return true;
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    if (!ProvjeriIme(ime_i_prezime)) throw std::domain_error ("Neispravno ime i prezime");
    Kupac::ime_i_prezime = ime_i_prezime;
    Kupac::datum_rodjenja = datum_rodjenja;
}
Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum_rodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()) {
    if (!ProvjeriIme(ime_i_prezime)) throw std::domain_error ("Neispravno ime i prezime");
    Kupac::ime_i_prezime = ime_i_prezime;
}
class Stan {
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
void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << Stan::DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba();
    if (broj_soba == 1) std::cout << " sobu.";
    else if (broj_soba == 2 || broj_soba == 3 || broj_soba == 4) std::cout << " sobe.";
    else std::cout << " soba.";
    std::cout << " Kvadratura stana je " << DajKvadraturu() << "(m^2) i stan ";
    if (DajNamjesten()) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat < 0 || broj_soba < 0 || std::fabs(kvadratura) < eps) throw std::domain_error ("Neispravan unos podataka");
    Stan::adresa = adresa; Stan::sprat = sprat; Stan::broj_soba = broj_soba; Stan::kvadratura = kvadratura;
    Stan::namjesten = namjesten;
}
Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat < 0 || broj_soba < 0 || std::fabs(kvadratura) < eps) throw std::domain_error ("Neispravan unos podataka");
    Stan::adresa = adresa; Stan::sprat = sprat; Stan::broj_soba = broj_soba; Stan::kvadratura = kvadratura;
    Stan::namjesten = namjesten;
}

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
    const Kupac &kupac_stana, const Stan &kupljeni_stan);//
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, 
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);//
    void PromijeniKupca(const Kupac &novi_kupac) { kupac_stana = novi_kupac; }//
    void PromijeniStan(const Stan &novi_stan) { kupljeni_stan = novi_stan; }//
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena_stana = nova_cijena; }//
    void PomjeriDanUnaprijed();//
    void PomjeriDanUnazad();//
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }//
    std::string DajImeKupca() const { return kupac_stana.DajImePrezime(); }//
    Datum DajDatumProdaje() const { return datum_prodaje; }//
    double DajCijenuStana() const { return cijena_stana; }//
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);//
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);//
    void Ispisi() const;
};
void Prodaja::Ispisi() const {
    std::cout << std::setw(32) << std::left << "Ime agenta:" << Prodaja::DajImeAgenta() << std::setw(27) << std::right << Prodaja::DajImeKupca() << " ("; kupac_stana.DajDatumRodjenja().Ispisi(); std::cout << ")" << std::endl;
    std::cout << std::setw(32) << std::left << "Zakazani datum prodaje:"; std::cout << std::setw(27) << datum_prodaje.DajDan() << "/" << datum_prodaje.DajMjesec() << "/" << datum_prodaje.DajGodinu() << std::endl;
    std::cout << std::setw(32) << std::left << "Cijena stana:" << std::setw(27) << Prodaja::DajCijenuStana() << std::endl;
    std::cout << "Informacije o stanu:" << std::endl; kupljeni_stan.Ispisi(); std::cout << std::endl;
} 
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    return p1.cijena_stana > p2.cijena_stana;
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if (p1.datum_prodaje.DajGodinu() < p2.datum_prodaje.DajGodinu()) return true;
    if (p1.datum_prodaje.DajGodinu() > p2.datum_prodaje.DajGodinu()) return false;
    if (p1.datum_prodaje.DajMjesec() < p2.datum_prodaje.DajMjesec()) return true;
    if (p1.datum_prodaje.DajMjesec() > p2.datum_prodaje.DajMjesec()) return false;
    return p1.datum_prodaje.DajDan() < p2.datum_prodaje.DajDan();
}
void Prodaja::PomjeriDanUnaprijed() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int godina(datum_prodaje.DajGodinu()), mjesec(datum_prodaje.DajMjesec()), dan(datum_prodaje.DajDan() + 1);
    if (datum_prodaje.DajGodinu() % 4 == 0 && datum_prodaje.DajGodinu() % 100 != 0 || datum_prodaje.DajGodinu() % 400 == 0) broj_dana[1]++;
    if (dan > broj_dana[mjesec-1]) dan = 1, mjesec += 1;
    if (mjesec > 12) mjesec = 1, godina += 1;
    datum_prodaje.Postavi(dan, mjesec, godina);
}
void Prodaja::PomjeriDanUnazad() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int godina(datum_prodaje.DajGodinu()), mjesec(datum_prodaje.DajMjesec()), dan(datum_prodaje.DajDan() - 1);
    if (datum_prodaje.DajGodinu() % 4 == 0 && datum_prodaje.DajGodinu() % 100 != 0 || datum_prodaje.DajGodinu() % 400 == 0) broj_dana[1]++;
    if (dan == 0) mjesec--;
    if (mjesec == 0) mjesec = 12, godina--;
    dan = broj_dana[mjesec - 1];
    datum_prodaje.Postavi(dan, mjesec, godina);
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana,
broj_soba, namjesten_stan, broj_kvadrata) {
    if (!ProvjeriIme(ime_agenta_prodaje)) throw std::domain_error ("Neispravno ime i prezime");
    Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
    Prodaja::cijena_stana = cijena_stana;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
const Kupac &kupac_stana, const Stan &kupljeni_stan) : datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {
    if (!ProvjeriIme(ime_agenta_prodaje)) throw std::domain_error ("Neispravno ime i prezime");
    Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
    Prodaja::cijena_stana = cijena_stana;
}

class Prodaje {
    int max_broj_prodaja;
    int broj_prodaja;
    Prodaja **sve_prodaje;
    public:
    explicit Prodaje(int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja), broj_prodaja(0), sve_prodaje(new Prodaja*[max_broj_prodaja] {}) {};//
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);//
    ~Prodaje();//
    Prodaje(const Prodaje &prodaje);//
    Prodaje(Prodaje &&prodaje);//
    Prodaje &operator = (const Prodaje &prodaje);//
    Prodaje &operator = (Prodaje &&prodaje);//
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
    const Kupac &kupac_stana, const Stan &kupljeni_stan);//
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana,  int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, 
    bool namjesten_stan, double broj_kvadrata);//
    void RegistrirajProdaju(Prodaja *prodaja);//
    int DajBrojProdaja() const { return broj_prodaja; }//
    int DajBrojProdajaNaDatum(const Datum &datum) const;//
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;//
    Prodaja &DajNajranijuProdaju();//
    Prodaja DajNajranijuProdaju() const;//
    Prodaja &DajNajskupljuProdaju();//
    Prodaja DajNajskupljuProdaju() const;//
    void IsprazniKolekciju();//
    void ObrisiNajranijuProdaju();//
    void ObrisiProdajeAgenta(const std::string &ime_agenta);//
    void ObrisiProdajeNaDatum(const Datum &datum);//
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    Prodaja &DajProdaju(int redni_broj_prodaje);
};
void Prodaje::IspisiSveProdaje() const {
    std::vector<Prodaja> v;
    for (int i = 0; i < broj_prodaja; i++) 
        v.push_back(*sve_prodaje[i]);
    std::sort(v.begin(), v.end(), [](Prodaja p1, Prodaja p2) {
       if (p1.DajDatumProdaje().DajDan() == p2.DajDatumProdaje().DajDan() && p1.DajDatumProdaje().DajMjesec() == p2.DajDatumProdaje().DajMjesec() 
       && p1.DajDatumProdaje().DajGodinu() == p2.DajDatumProdaje().DajGodinu()) return p1.DajImeKupca() < p2.DajImeKupca();
       if (p1.DajDatumProdaje().DajGodinu() < p2.DajDatumProdaje().DajGodinu()) return true;
       if (p1.DajDatumProdaje().DajMjesec() < p2.DajDatumProdaje().DajMjesec()) return true;
       if (p1.DajDatumProdaje().DajDan() < p2.DajDatumProdaje().DajDan()) return true;
       return false;
    });
    for (int i = 0; i < v.size(); i++) v[i].Ispisi(), std::cout << std::endl;
};
Prodaja &Prodaje::DajProdaju(int redni_broj_prodaje) {
    if (redni_broj_prodaje < 1 || redni_broj_prodaje > broj_prodaja) throw std::domain_error ("Neispravan parametar");
    return *sve_prodaje[redni_broj_prodaje];
};
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    std::vector<Prodaja> v;
    for (int i = 0; i < broj_prodaja; i++) {
        if (sve_prodaje[i]->DajDatumProdaje().DajDan() == datum.DajDan() && sve_prodaje[i]->DajDatumProdaje().DajMjesec() == datum.DajMjesec() && 
        sve_prodaje[i]->DajDatumProdaje().DajGodinu() == datum.DajGodinu()) v.push_back(*sve_prodaje[i]);
    }
    std::sort(v.begin(), v.end(), [](Prodaja p1, Prodaja p2) {
        return p1.DajImeKupca() < p2.DajImeKupca();
    });
    for (int i = 0; i < v.size(); i++) v[i].Ispisi(), std::cout << std::endl;
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    if (!broj_prodaja) throw std::range_error ("Prazna kolekcija");
    for (int i = 0; i < broj_prodaja; i++) 
        if (sve_prodaje[i]->DajDatumProdaje().DajGodinu() == datum.DajGodinu())
            if (sve_prodaje[i]->DajDatumProdaje().DajMjesec() == datum.DajMjesec())
                if (sve_prodaje[i]->DajDatumProdaje().DajDan() == datum.DajDan()) delete sve_prodaje[i], sve_prodaje[i] = nullptr;
    for (int i = 0; i < broj_prodaja; i++) {
        if (sve_prodaje[i] == nullptr) 
            for (int j = i; j < broj_prodaja - 1; j++) sve_prodaje[j] = sve_prodaje[j + 1]; 
        broj_prodaja--;
    }
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    if (!broj_prodaja) throw std::range_error ("Prazna kolekcija");
    for (int i = 0; i < broj_prodaja; i++) if (sve_prodaje[i]->DajImeAgenta() == ime_agenta) delete sve_prodaje[i], sve_prodaje[i] = nullptr;
    for (int i = 0; i < broj_prodaja; i++) {
        if (sve_prodaje[i] == nullptr) 
            for (int j = i; j < broj_prodaja - 1; j++) sve_prodaje[j] = sve_prodaje[j + 1];
        broj_prodaja--;
    }
}
void Prodaje::ObrisiNajranijuProdaju() {
    Prodaja a(Prodaje::DajNajranijuProdaju());
    Prodaja *temp(&a);
    for (int i = 0; i < broj_prodaja; i++) if (sve_prodaje[i] == temp) delete sve_prodaje[i], sve_prodaje[i] = nullptr, temp = nullptr;
    for (int i = 0; i < broj_prodaja; i++) {
        if (sve_prodaje[i] == nullptr)
            for (int j = i; j < broj_prodaja - 1; j++) sve_prodaje[j] = sve_prodaje[j + 1];
        broj_prodaja--;
    }
}
void Prodaje::IsprazniKolekciju() {
    if (!broj_prodaja) throw std::range_error ("Prazna kolekcija");
    for (int i = 0; i < broj_prodaja; i++) delete sve_prodaje[i];
    broj_prodaja = 0;
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    if (!broj_prodaja) throw std::domain_error ("Nema registriranih prodaja");
    auto a(std::min_element(sve_prodaje, sve_prodaje + broj_prodaja, [](Prodaja *p1, Prodaja *p2) {
        if (p1->DajDatumProdaje().DajGodinu() < p2->DajDatumProdaje().DajGodinu()) return true;
        if (p1->DajDatumProdaje().DajMjesec() < p2->DajDatumProdaje().DajMjesec()) return true;
        return p1->DajDatumProdaje().DajDan() < p2->DajDatumProdaje().DajDan();
    }));
    return **a;
}
Prodaja &Prodaje::DajNajranijuProdaju() {
    if (!broj_prodaja) throw std::domain_error ("Nema registriranih prodaja");
    auto a(std::min_element(sve_prodaje, sve_prodaje + broj_prodaja, [](Prodaja *p1, Prodaja *p2) {
        if (p1->DajDatumProdaje().DajGodinu() < p2->DajDatumProdaje().DajGodinu()) return true;
        if (p1->DajDatumProdaje().DajMjesec() < p2->DajDatumProdaje().DajMjesec()) return true;
        return p1->DajDatumProdaje().DajDan() < p2->DajDatumProdaje().DajDan();
    }));
    return **a;
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    if (!broj_prodaja) throw std::domain_error ("Nema registriranih prodaja");
    auto a(std::max_element(sve_prodaje, sve_prodaje + broj_prodaja, [](Prodaja *p1, Prodaja *p2) {
        return p1->DajCijenuStana() > p2->DajCijenuStana();
    }));
    return **a;
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    if (!broj_prodaja) throw std::domain_error ("Nema registriranih prodaja");
    auto a(std::max_element(sve_prodaje, sve_prodaje + broj_prodaja, [](Prodaja *p1, Prodaja *p2) {
        return p1->DajCijenuStana() > p2->DajCijenuStana();
    }));
    return **a;
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return (std::count_if(sve_prodaje, sve_prodaje + broj_prodaja, [ime_agenta](Prodaja *p) {
       return (p->DajImeAgenta() == ime_agenta); 
    }));
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    auto a(std::count_if(sve_prodaje, sve_prodaje + broj_prodaja, [datum](Prodaja *p) {
        return (p->DajDatumProdaje().DajDan() == datum.DajDan() && p->DajDatumProdaje().DajMjesec() == datum.DajMjesec() && p->DajDatumProdaje().DajGodinu() == datum.DajGodinu());
    }));
    return a;
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    if (broj_prodaja == max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
    sve_prodaje[++broj_prodaja] = prodaja; 
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    if (broj_prodaja == max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
    if (!ProvjeriIme(ime_agenta_prodaje)) throw std::domain_error ("Neispravno ime i prezime");
    Datum *datum_prodaje(new Datum(dan_prodaje, mjesec_prodaje, godina_prodaje));
    Kupac *kupac_stana(new Kupac(ime_kupca, datum_rodjenja_kupca));
    Stan *kupljeni_stan(new Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata));
    Prodaja *prodaja(new Prodaja(ime_agenta_prodaje, cijena_stana, *datum_prodaje, *kupac_stana, *kupljeni_stan));
    sve_prodaje[++broj_prodaja] = prodaja;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    if (broj_prodaja == max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
    if (!ProvjeriIme(ime_agenta_prodaje)) throw std::domain_error ("Neispravno ime i prezime");
    Prodaja *prodaja(new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan));
    sve_prodaje[++broj_prodaja] = prodaja;
}
Prodaje &Prodaje::operator = (Prodaje &&prodaje) {
    if (&prodaje != this) {
        for (int i = 0; i < broj_prodaja; i++) delete sve_prodaje[i];
        delete[] sve_prodaje;
        sve_prodaje = prodaje.sve_prodaje;
        prodaje.sve_prodaje = nullptr;
        broj_prodaja = prodaje.broj_prodaja;
        max_broj_prodaja = prodaje.max_broj_prodaja;
        prodaje.broj_prodaja = 0;
    }
    return *this;
}
Prodaje::Prodaje(Prodaje &&prodaje) {
    if (&prodaje != this) {
        sve_prodaje = prodaje.sve_prodaje;
        broj_prodaja = prodaje.broj_prodaja;
        max_broj_prodaja = prodaje.max_broj_prodaja;
        prodaje.sve_prodaje = nullptr;
        prodaje.broj_prodaja = 0;
    }
}
Prodaje &Prodaje::operator = (const Prodaje &prodaje) {
    if (&prodaje != this) {
        for (int i = 0; i < broj_prodaja; i++) delete sve_prodaje[i];
        delete[] sve_prodaje;
        max_broj_prodaja = prodaje.max_broj_prodaja;
        broj_prodaja = prodaje.broj_prodaja;
        sve_prodaje = new Prodaja*[max_broj_prodaja] {};
        for (int i = 0; i < broj_prodaja; i++) 
            sve_prodaje[i] = new Prodaja(*prodaje.sve_prodaje[i]);
    }
    return *this;
}
Prodaje::Prodaje(const Prodaje &prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), 
broj_prodaja(prodaje.broj_prodaja), sve_prodaje(new Prodaja*[prodaje.max_broj_prodaja] {}) {
        try {
            for (int i = 0; i < prodaje.broj_prodaja; i++) sve_prodaje[i] = new Prodaja(*prodaje.sve_prodaje[i]);
        }
        catch(...) {
            for (int i = 0; i < prodaje.broj_prodaja; i++) delete sve_prodaje[i];
            delete[] sve_prodaje; throw;
        }
}
Prodaje::~Prodaje() {
    for (int i = 0; i < broj_prodaja; i++) delete sve_prodaje[i];
    delete[] sve_prodaje;
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()), broj_prodaja(spisak_prodaja.size()) {
    auto it(spisak_prodaja.begin());
    for (int i = 0; i < spisak_prodaja.size(); i++) {
        sve_prodaje[i] = new Prodaja(*it++);
    }
}
int main ()
{
    return 0;
}