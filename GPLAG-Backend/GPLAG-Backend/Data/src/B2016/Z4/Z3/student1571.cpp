#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <iomanip>

class Datum {
    int dan, mjesec, godina;
    bool ispravan_datum (int d, int m, int g) {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
        if ((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
        if (g < 1 || m > 12 || m < 1 || d < 1 || d > broj_dana[m - 1]) 
            return false;
        return true;
    }
    public:
    Datum(int dan, int mjesec, int godina) { Postavi (dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina) { 
        if (!(ispravan_datum(dan,mjesec,godina))) throw std::domain_error ("Neispravan datum."); 
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
};
class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    bool da_li_je_ok (std::string s) {
        bool uslov(false); //POPRAVITI NECE
        for (int i=0; i<s.length(); i++) {
            uslov = false ;
            if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || s[i] == ' ' || s[i] == '\'' || s[i] == '-')) {
             return false;
            }
        }
        return true;
    }
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodjenja(datum_rodjenja) { Postavi (ime_i_prezime, datum_rodjenja); }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) { 
        if(!(da_li_je_ok(ime_i_prezime))) throw std::domain_error ("Neispravno ime i prezime.");
        Kupac::ime_i_prezime = ime_i_prezime; Kupac::datum_rodjenja = datum_rodjenja; 
    }
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const; //
};
void Kupac::Ispisi() const {
    Datum datum = this->DajDatumRodjenja();
    std::cout << ime_i_prezime << " (";
    datum.Ispisi();
    std::cout << ")";
}
class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa,sprat,broj_soba,namjesten,kvadratura); }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura); //
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const; //
};
void Stan::Ispisi() const { 
    std::string broj;
    broj = std::to_string (DajBrojSoba());
    bool jeste(false);
    if (broj[broj.length()-1] == 0) jeste = true;
    std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba();
    if (DajBrojSoba() % 10 == 1 && DajBrojSoba() != 11) std::cout << " sobu.";
    else if ((DajBrojSoba() % 10 == 2 || DajBrojSoba() % 10 == 3 || DajBrojSoba() % 10 == 4) && (DajBrojSoba() % 100 != 12 && DajBrojSoba() % 100 != 13 && DajBrojSoba() % 100 != 14)) std::cout << " sobe.";
    else std::cout << " soba.";
    std::cout << " Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan ";
    if (namjesten) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error ("Neispravan unos podataka.");
    Stan::adresa = adresa; Stan::sprat = sprat; Stan::broj_soba = broj_soba; Stan::namjesten = namjesten;
    Stan::kvadratura = kvadratura;
}
class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    int dan_prodaje, mjesec_prodaje, godina_prodaje;
    std::string ime_kupca;
    std::string adresa_stana;
    int sprat_stana, broj_soba;
    bool namjesten_stan;
    double broj_kvadrata;
    int broj_dana (int m, int g) {
        int b_d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if ((g % 4 == 0 && g % 100 != 0) || (g % 400 == 0)) b_d[1]++;
        return b_d[m - 1];
    }
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan); //
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata); //
    void PromijeniKupca(const Kupac &novi_kupac) { kupac_stana = novi_kupac; }
    void PromijeniStan(const Stan &novi_stan) { kupljeni_stan = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datum_prodaje = novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena_stana = nova_cijena; }
    void PromijeniImeAgenta (const std::string &novo_ime) { ime_agenta_prodaje = novo_ime; }
    void PomjeriDanUnaprijed(); //
    void PomjeriDanUnazad(); //
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const { return ime_kupca; }
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2); //
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) { return p1.DajCijenuStana() > p2.DajCijenuStana(); }
    void Ispisi() const; //
};
Prodaja::Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : 
datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan){
    Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
    Prodaja::cijena_stana = cijena_stana; 
}
Prodaja::Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata): 
datum_prodaje(Datum(dan_prodaje,mjesec_prodaje,godina_prodaje)), kupac_stana(Kupac(ime_kupca,datum_rodjenja_kupca)), kupljeni_stan(Stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata)){
    Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
    Prodaja::cijena_stana = cijena_stana;
    Prodaja::ime_kupca = ime_kupca;
    Prodaja::adresa_stana = adresa_stana;
    Prodaja::sprat_stana = sprat_stana;
    Prodaja::broj_soba = broj_soba;
    Prodaja::broj_kvadrata = broj_kvadrata;
    Prodaja::namjesten_stan = namjesten_stan;
}
void Prodaja::PomjeriDanUnaprijed () {
    dan_prodaje++;
    if (dan_prodaje > broj_dana(mjesec_prodaje, godina_prodaje)) {
        dan_prodaje = 1;
        mjesec_prodaje++;
    }
    if (mjesec_prodaje > 12) {
        mjesec_prodaje = 1;
        godina_prodaje++;
    }
}
void Prodaja::PomjeriDanUnazad () {
    dan_prodaje--;
    if (dan_prodaje > broj_dana(mjesec_prodaje, godina_prodaje)) {
        dan_prodaje = 1;
        mjesec_prodaje++;
    }
    if (mjesec_prodaje > 12) {
        mjesec_prodaje = 1;
        godina_prodaje++;
    }
}
void Prodaja::Ispisi() const { //POPRAVITI SIRINU ISPISA (SAZNATI KOJA JE)
    Datum dat_prodaje = this->DajDatumProdaje();
    Stan stan (adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    std::cout << std::setw(32) << std::left << "Ime agenta: " << DajImeAgenta() << std::endl;
    std::cout << std::setw(32) << std::left << "Ime kupca: "; kupac_stana.Ispisi(); std::cout << std::endl;
    std::cout << std::setw(32) << std::left <<"Zakazani datum prodaje: ";
    dat_prodaje.Ispisi(); std::cout << std::endl;
    std::cout << std::setw(32) << std::left << "Cijena stana: " << DajCijenuStana(); std::cout << std::endl;
    std::cout << std::setw(32) << std::left << "Informacije o stanu: " << std::endl;
    stan.Ispisi(); std::cout << std::endl;
}
bool ProdatPrije (const Prodaja &p1, const Prodaja &p2) {
    Datum dat1 = p1.DajDatumProdaje(), dat2 = p2.DajDatumProdaje();
    int d1, m1, g1, d2, m2, g2;
    d1 = dat1.DajDan(); m1 = dat1.DajMjesec(); g1 = dat1.DajGodinu();
    d2 = dat2.DajDan(); m2 = dat2.DajMjesec(); g2 = dat2.DajGodinu();
    int ukupno1, ukupno2;
    ukupno1 = d1 + m1*100 + g1*10000;
    ukupno2 = d2 + m2*100 + g2*10000;
    if (ukupno1 < ukupno2) return true;
    return false;
}
class Prodaje {
    const int max_broj_prodaja;
    int broj_prodaja;
    Prodaja **niz_pokazivaca = nullptr; // deklaracija niza OK
    public:
    explicit Prodaje(int max_broj_prodaja); // PROVJERITI
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja); //
    ~Prodaje(); // DONE
    Prodaje(const Prodaje &prodaje); // i guess it's ok KOPIRAJUCI
    Prodaje(Prodaje &&prodaje); // POMJERAJUCI DONE
    Prodaje &operator =(const Prodaje &prodaje);// GOTOVO OPERATOR DODJELE
    Prodaje &operator =(Prodaje &&prodaje); //POMJERAJUCI OP.DODJELE fin
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);//
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
        if (broj_prodaja >= max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
        niz_pokazivaca[broj_prodaja++] = new Prodaja(ime_agenta_prodaje,cijena_stana,dan_prodaje,mjesec_prodaje,godina_prodaje,ime_kupca,datum_rodjenja_kupca,adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
    }
    void RegistrirajProdaju(Prodaja *prodaja);//
    int DajBrojProdaja() const { return broj_prodaja; } //
    int DajBrojProdajaNaDatum(const Datum &datum) const; //
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();//
    Prodaja DajNajranijuProdaju() const; //
    Prodaja &DajNajskupljuProdaju(); //
    Prodaja DajNajskupljuProdaju() const; //
    Prodaja &DajProdaju (int broj);
    void IsprazniKolekciju(); //
    void ObrisiNajranijuProdaju();//
    void ObrisiProdajeAgenta(const std::string &ime_agenta); //
    void ObrisiProdajeNaDatum(const Datum &datum);//
    void IspisiProdajeNaDatum(const Datum &datum) const; //
    void IspisiSveProdaje() const ; //
};
Prodaje::Prodaje (int max_broj_prodaja): max_broj_prodaja(max_broj_prodaja) {
    broj_prodaja = 0;
    niz_pokazivaca = new Prodaja*[max_broj_prodaja]{};
}
Prodaje::Prodaje (std::initializer_list<Prodaja> spisak_prodaja): max_broj_prodaja(spisak_prodaja.size()), 
broj_prodaja(spisak_prodaja.size()),niz_pokazivaca(new Prodaja*[spisak_prodaja.size()]{}) {
    int i(0), temp(0);
    try {
        for (auto it=spisak_prodaja.begin(); it!=spisak_prodaja.end(); it++, i++) {
            niz_pokazivaca[i] = new Prodaja(*it);
            temp++;
        }
    }
    catch(...) {
        for (int j=0; j<temp; j++) delete[] niz_pokazivaca[j];
        delete[] niz_pokazivaca;
        throw;
    }
} 
Prodaje::~Prodaje() {
    if (niz_pokazivaca != nullptr) {
        for (int i=0; i<broj_prodaja; i++) delete niz_pokazivaca[i];
        delete[] niz_pokazivaca;
        niz_pokazivaca = nullptr;
    }
}
void Prodaje::IsprazniKolekciju() {
    for (int i=0; i<broj_prodaja; i++) delete niz_pokazivaca[i];
    broj_prodaja = 0;
}
Prodaje::Prodaje (const Prodaje &prodaje): max_broj_prodaja(prodaje.max_broj_prodaja) {
    try {
        broj_prodaja = prodaje.broj_prodaja;
        niz_pokazivaca = new Prodaja* [prodaje.max_broj_prodaja]{};
        for (int i=0; i<prodaje.broj_prodaja; i++) niz_pokazivaca[i] = new Prodaja(*prodaje.niz_pokazivaca[i]);
    }
    catch (...) {
        for (int i=0; i<prodaje.broj_prodaja; i++) delete niz_pokazivaca[i];
        delete[] niz_pokazivaca;
        throw;
    }
}
Prodaje::Prodaje (Prodaje &&prodaje): max_broj_prodaja(prodaje.max_broj_prodaja), niz_pokazivaca(prodaje.niz_pokazivaca) {
    broj_prodaja = prodaje.broj_prodaja;
    prodaje.niz_pokazivaca = nullptr;
    prodaje.broj_prodaja = 0;
}
Prodaje &Prodaje::operator = (const Prodaje &prodaje) {
    if (prodaje.broj_prodaja != broj_prodaja) {
        try {
            for (int i=broj_prodaja; i<prodaje.broj_prodaja; i++)
                niz_pokazivaca[i] = new Prodaja (*prodaje.niz_pokazivaca[i]);
        }
        catch (...) {
            for (int i=broj_prodaja; i<prodaje.broj_prodaja; i++) {
                delete niz_pokazivaca[i]; 
                niz_pokazivaca[i] = nullptr;
            }
            throw;
        }
    }
    else {
            for (int i=prodaje.broj_prodaja; i<broj_prodaja; i++) {
                delete niz_pokazivaca[i];
                niz_pokazivaca[i] = nullptr;
            }
        }
       broj_prodaja = prodaje.broj_prodaja;
        for (int i=0; i<broj_prodaja; i++)
            *niz_pokazivaca[i] = *prodaje.niz_pokazivaca[i];
        return *this;
}
Prodaje &Prodaje::operator =(Prodaje &&prodaje) {
    if (prodaje.broj_prodaja != broj_prodaja) throw ("Nisu iste velicine!");
    std::swap (broj_prodaja, prodaje.broj_prodaja);
    std::swap (niz_pokazivaca, prodaje.niz_pokazivaca);
    return *this;
}
void Prodaje::RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan){
    if (broj_prodaja >= max_broj_prodaja)
        throw std::range_error ("Dostignut maksimalni broj prodaja");
    niz_pokazivaca[broj_prodaja++] = new Prodaja (ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
}
void Prodaje::RegistrirajProdaju (Prodaja *prodaja) {
    if (broj_prodaja >= max_broj_prodaja)
        throw std::range_error ("Dostignut maksimalni broj prodaja");
    Prodaje::niz_pokazivaca[broj_prodaja++] = new Prodaja (*prodaja);
    delete prodaja;
}
int Prodaje::DajBrojProdajaNaDatum (const Datum &datum) const {
    if (broj_prodaja == 0) throw std::domain_error ("Nema registriranih prodaja");
    return std::count_if (niz_pokazivaca, niz_pokazivaca+broj_prodaja, [datum] (Prodaja *p1) {
        if (p1->DajDatumProdaje().DajDan() == datum.DajDan() && p1->DajDatumProdaje().DajMjesec() == datum.DajMjesec() 
        && p1->DajDatumProdaje().DajGodinu() == datum.DajGodinu()) return true;
        return false;
    });
}
Prodaja &Prodaje::DajNajranijuProdaju() {
    if (broj_prodaja == 0) throw std::domain_error ("Nema registriranih prodaja");
    auto min = std::min_element (niz_pokazivaca, niz_pokazivaca+broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        return (ProdatPrije(*p1, *p2));
    });
    return **min;
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    if (broj_prodaja == 0) throw std::domain_error ("Nema registriranih prodaja");
    auto min = std::min_element (niz_pokazivaca, niz_pokazivaca+broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        return (ProdatPrije(*p1, *p2));
    });
    return **min;
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    if (broj_prodaja == 0) throw std::domain_error ("Nema registriranih prodaja");
    auto max = std::max_element (niz_pokazivaca, niz_pokazivaca+broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        return (SkupljiStan(*p1, *p2));
    });
    return **max;
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    if (broj_prodaja == 0) throw std::domain_error ("Nema registriranih prodaja");
    auto max = std::max_element (niz_pokazivaca, niz_pokazivaca+broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        return (SkupljiStan(*p1, *p2));
    });
    return **max;
}
Prodaja &Prodaje::DajProdaju (int broj)  {
    if (broj < 0 || broj > broj_prodaja) throw std::domain_error ("RI NIJE KURS");
    auto nesto = niz_pokazivaca[broj - 1];
    return *nesto;
}
void Prodaje::ObrisiNajranijuProdaju() {
    if (broj_prodaja == 0) throw std::range_error ("Prazna kolekcija");
    std::sort (niz_pokazivaca, niz_pokazivaca+broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        return (ProdatPrije(*p1, *p2));
    });
    Prodaja prva = this->DajNajranijuProdaju();
    delete niz_pokazivaca[0];
    niz_pokazivaca[0] = nullptr;
    broj_prodaja--;
}
void Prodaje::ObrisiProdajeAgenta (const std::string &ime_agenta_prodaje) {
    for (int i=0; i<broj_prodaja; i++) {
        if (niz_pokazivaca[i]->DajImeAgenta() == ime_agenta_prodaje) {
            delete niz_pokazivaca[i];
            for (int j=i; j<broj_prodaja-1; j++)
                niz_pokazivaca[j] = niz_pokazivaca[j+1];
            broj_prodaja--;
            i--;
        }
        else return;
    }
}
void Prodaje::ObrisiProdajeNaDatum (const Datum &datum) {
    for (int i=0; i<broj_prodaja; i++) {
        if (niz_pokazivaca[i]->DajDatumProdaje().DajDan() == datum.DajDan() && niz_pokazivaca[i]->DajDatumProdaje().DajMjesec() == datum.DajMjesec() 
        && niz_pokazivaca[i]->DajDatumProdaje().DajGodinu() == datum.DajGodinu()) {
            delete niz_pokazivaca[i];
            for (int j=i; j<broj_prodaja-1; j++) 
                niz_pokazivaca[j] = niz_pokazivaca[j+1];
            broj_prodaja--;
            i--;
        }
        else return;
    }
}
void Prodaje::IspisiProdajeNaDatum (const Datum &datum) const {
    Prodaja **pomocni(niz_pokazivaca);
    for (int i=0; i<broj_prodaja; i++) pomocni[i] = niz_pokazivaca[i];
    std::sort (pomocni, pomocni+broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        return (p1->DajImeKupca() < p2->DajImeKupca());
    });
    for (int i=0; i<broj_prodaja; i++) {
        if (pomocni[i]->DajDatumProdaje().DajDan() == datum.DajDan() && pomocni[i]->DajDatumProdaje().DajMjesec() && pomocni[i]->DajDatumProdaje().DajGodinu() == datum.DajGodinu())
        pomocni[i]->Ispisi();
        std::cout << std::endl;
    }
}
void Prodaje::IspisiSveProdaje() const {
    Prodaja **pomocni(niz_pokazivaca);
    for (int i=0; i<broj_prodaja; i++) pomocni[i] = niz_pokazivaca[i];
    std::sort (pomocni, pomocni+broj_prodaja, [] (Prodaja *p1, Prodaja *p2) {
        if (p1->DajDatumProdaje().DajDan() == p2->DajDatumProdaje().DajDan() && p1->DajDatumProdaje().DajMjesec() == p2->DajDatumProdaje().DajMjesec() && p1->DajDatumProdaje().DajGodinu() == p2->DajDatumProdaje().DajGodinu())
            return p1->DajImeKupca() < p2->DajImeKupca();
        return ProdatPrije(*p1, *p2);
    });
    for (int i=0; i<broj_prodaja; i++) {
        pomocni[i]->Ispisi();
        std::cout << std::endl;
    }
}
int Prodaje::DajBrojProdajaOdAgenta (const std::string &ime_agenta_prodaje) const {
    if (broj_prodaja == 0) throw std::domain_error ("Nema registriranih prodaja");
    return std::count_if (niz_pokazivaca, niz_pokazivaca+broj_prodaja, [ime_agenta_prodaje] (Prodaja *p1) {
        if (p1->DajImeAgenta() == ime_agenta_prodaje) return true;
        return false;
    });
}
 int main() 
{
    int finito_izbor(0), zadnja_izbor(0), glupa_prodaja(0), glupi_kupac(0), glupi_stan(0), izbor(0), izbor1(0), izbor2(0), izbor3(0), izbor4(0), izbor_stana(0), izbor_kupca(0), izbor_prodaje(0);
    int  sprat, broj, namjesten, dan, mjesec, godina, dan_prodaja, mjesec_prodaja, godina_prodaja;
    std::string adresa, ime_prezime, ime_agenta, ime_kupca, adresa_prodaja;
    double kva, kvadratura, cijena_stana;
    int glupi_izbor, jos_gluplji_izbor, jos_gluplji_kupac;
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    int dan_rod, mjesec_rod, godina_rod, sprat_prodaja, soba_prodaja;
    bool namjesten_prodaja;
    Prodaje prodaja(20); // max vel prodaja
    std::cout << "Dobrodosli!";
    std::cout << std::endl << std::endl;
    do {
        petlja:
  
        std::cout << "Izaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja\n";
        std::cin >> izbor;
        if (izbor == 0) {
            std::cout << std::endl << std::endl << "Dovidjenja!";
            return 0;
        }
        switch (izbor) {
            case(0): {
                std::cout << std::endl << "Dovidjenja!";
                return 0;
            }
            case (1): {
                do {
                    arka:
                    std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj\n";
                    std::cin >> izbor1;
                    std::cin.ignore(10000,'\n');
                    if (izbor1 == 4) {
                        std::cout << std::endl << std::endl << "Dovidjenja!";
                        return 0;
                    }
                    switch (izbor1) {
                        case (0): {
                            goto petlja;
                            break;
                        }
                        case (1): {
                            spas:
                            try {
                                std::cout << "Unesite adresu: ";
                                std::getline (std::cin, adresa);
                                std::cout << "Unesite sprat: ";
                                std::cin >> sprat;
                                std::cout << "Unesite broj soba: ";
                                std::cin >> broj;
                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                std::cin >> namjesten;
                                //if (namjesten != 0 && namjesten != 1) throw std::domain_error("Neispravan unos podataka.");
                                std::cout << "Unesite kvadraturu: ";
                                std::cin >> kva;
                                if (namjesten != 0 && namjesten != 1) throw std::domain_error ("Neispravan unos podataka.");
                                stanovi.emplace_back (adresa, sprat, broj, namjesten, kva);
                                std::cout << "Stan je uspjesno dodan!" << std::endl;
                                std::cout << std::endl;
                                //break;
                            }
                            catch (std::domain_error kupus) {
                                std::cout << "Izuzetak: " << kupus.what() << " Molimo unesite opet." << std::endl;
                                std::cin.ignore(10000,'\n');
                                std::cin.clear();
                                goto spas;
                            }
                            break;
                        }
                        case (2): {
                            std::cout << "Odaberite stan. Dostupni stanovi su: " << std::endl;
                            for (int i=0; i<stanovi.size(); i++) {
                                std::cout << " " << i+1 << " - " ;
                                stanovi[i].Ispisi();
                                std::cout << std::endl;
                            }
                            std::cin >> izbor_stana;
                            std::cout << "Odaberite polje koje zelite urediti:" << std::endl;
                            std::cout << " 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve" << std::endl;
                            std::cin >> izbor2;
                            std::cin.ignore(10000,'\n');
                        
                            switch (izbor2) {
                                case(0): {
                                    goto petlja;
                                    break;
                                }
                                case(1): {
                                    std::cout << "Unesite adresu: ";
                                    std::string adresa1;
                                    std::getline (std::cin,adresa1);
                                    stanovi[izbor_stana - 1].Postavi(adresa1, stanovi[izbor_stana-1].DajSprat(),stanovi[izbor_stana-1].DajBrojSoba(),stanovi[izbor_stana-1].DajNamjesten(),stanovi[izbor_stana-1].DajKvadraturu());
                                    std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                    std::cout << std::endl;
                                    goto arka;
                                    break;
                                }
                                case(3): {
                                    luis:
                                    try {
                                        std::cout << "Unesite broj soba: ";
                                        int soba1;
                                        std::cin >> soba1;
                                        stanovi[izbor_stana - 1].Postavi(stanovi[izbor_stana-1].DajAdresu(),stanovi[izbor_stana-1].DajSprat(), soba1,stanovi[izbor_stana-1].DajNamjesten(),stanovi[izbor_stana-1].DajKvadraturu());
                                        std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                        std::cout << std::endl;
                                        goto arka;
                                        
                                    }
                                    catch (std::domain_error soba) {
                                        std::cout << "Izuzetak: " << soba.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore(10000,'\n');
                                        goto luis;
                                    }
                                    break;
                                }
                                case(2): {
                                    danse:
                                        try {
                                        std::cout << "Unesite sprat: ";
                                        int sprat1;
                                        std::cin >> sprat1;
                                        stanovi[izbor_stana - 1].Postavi(stanovi[izbor_stana-1].DajAdresu(), sprat1, stanovi[izbor_stana-1].DajBrojSoba(),stanovi[izbor_stana-1].DajNamjesten(), stanovi[izbor_stana-1].DajKvadraturu());
                                        std::cout << "Stan je uspjesno izmijenjen!"<< std::endl;
                                        std::cout << std::endl;
                                        goto arka;
                                    }
                                    catch (std::domain_error sprat) {
                                        std::cout << "Izuzetak: " << sprat.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore (10000,'\n');
                                        goto danse;
                                    }
                                    break;
                                }
                                case(4): {
                                    nou:
                                    try {
                                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                        int namjesten1;
                                        std::cin >> namjesten1;
                                        if (namjesten1 != 0 && namjesten1 != 1) throw std::domain_error ("Neispravan unos podataka.");
                                        stanovi[izbor_stana - 1].Postavi(stanovi[izbor_stana-1].DajAdresu(),stanovi[izbor_stana-1].DajSprat(),stanovi[izbor_stana-1].DajBrojSoba(), namjesten1,stanovi[izbor_stana-1].DajKvadraturu());
                                        std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                        std::cout << std::endl;
                                        goto arka;
                                    }
                                    catch (std::domain_error nam) {
                                        std::cout << "Izuzetak: " << nam.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore(10000,'\n');
                                        goto nou;
                                    }
                                    break;
                                }
                                case(5): {
                                    novo:
                                    std::cout << "Unesite kvadraturu: ";
                                    
                                    double kva1;
                                    try {
                                        std::cin >> kva1;
                                        stanovi[izbor_stana - 1].Postavi(stanovi[izbor_stana-1].DajAdresu(), stanovi[izbor_stana-1].DajSprat(),stanovi[izbor_stana-1].DajBrojSoba(), stanovi[izbor_stana-1].DajNamjesten(), kva1);
                                        std::cout << "Stan je uspjesno izmijenjen!" << std::endl;
                                        std::cout << std::endl;
                                        goto arka;
                                        break;
                                        
                                    }
                                    catch (std::domain_error por) {
                                        std::cout << "Izuzetak: " << por.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore(10000,'\n');
                                        goto novo;
                                    }
                                    
                                }
                                case(6): {
                                    pas:
                                    try {
                                        std::cout << "Unesite adresu: ";
                                        std::string adresa1;
                                        std::getline(std::cin, adresa1);
                                        std::cout << "Unesite sprat: ";
                                        int sprat1;
                                        std::cin >> sprat1;
                                        std::cout << "Unesite broj soba: ";
                                        int broj1; std::cin >> broj1;
                                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                        int namjesten1; std::cin >> namjesten1;
                                        std::cout << "Unesite kvadraturu: ";
                                        double kva1; std::cin >> kva1;
                                        if (namjesten1 !=0 && namjesten1 != 1) throw std::domain_error ("Neispravan unos podataka.");
                                        stanovi[izbor_stana - 1].Postavi(adresa1, sprat1, broj1, namjesten1, kva1);
                                        std::cout << "Stan je uspjesno izmijenjen!" <<std::endl;
                                        std::cout << std::endl;
                                        goto arka;
                                    }
                                    catch (std::domain_error jab) {
                                        std::cout << "Izuzetak: " << jab.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore(10000,'\n');
                                        goto pas;
                                    }
                                    break;
                                }
                            }
                        }
                        case (3): {
                            for (int i=0; i<stanovi.size(); i++) {
                                std::cout  << i+1 << ". ";
                                stanovi[i].Ispisi();
                                std::cout << std::endl;
                            }
                            goto arka;
                            break;
                        }
                        break;
                    } 
                } while (izbor1 != 4);
                break;
            }
            case(2): {
                do {
                    std::cout << "Izaberite opciju:\n";
                    std::cout << " 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj" << std::endl;
                    std::cin >> izbor4;
                    if (izbor4 == 4) {
                        std::cout << std::endl << std::endl << "Dovidjenja!";
                        return 0;
                    }
                    std::cin.ignore(10000,'\n');
                    switch(izbor4) {
                        case(0): {
                            goto petlja;
                            break;
                        }
                        case(1): {
                            majmun:
                            try {
                                std::cout << "Unesite ime i prezime kupca: ";
                                std::getline(std::cin, ime_prezime);
                                std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                char znak, znak1;
                                std::cin >> dan >> znak >> mjesec >> znak1 >> godina;
                                if (znak != '/' || znak1 != '/') throw std::domain_error ("Neispravan unos podataka.");
                                Datum dat(dan, mjesec, godina);
                                kupci.emplace_back (ime_prezime, dat);
                                std::cout << "Kupac je uspjesno dodan!"<< std::endl;
                                //break;
                            }
                            catch (std::domain_error paprika) {
                                std::cout << "Izuzetak: " << paprika.what() << " Molimo unesite opet." <<std::endl;
                                std::cin.ignore (10000,'\n');
                                goto majmun;
                            }
                            break;
                        }
                        case(3): {
                            for (int i=0; i<kupci.size(); i++) {
                                kupci[i].Ispisi();
                                std::cout << std::endl;
                            }
                            break;
                        }
                        case(2): {
                            std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << std::endl;
                            for (int i=0; i<kupci.size(); i++) {
                                std::cout << " " << i+1 << " - ";
                                kupci[i].Ispisi();
                                std::cout << std::endl;
                            }
                            macka:
                            try {
                                std::cin >> izbor_kupca;
                                std::cin.ignore(10000,'\n');
                                std::cout << "Unesite ime i prezime kupca: ";
                                std::string ime_i_prezime1;
                                std::getline (std::cin, ime_i_prezime1);
                                std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                int dan1,mjesec1,godina1;
                                char znak2,znak3;
                                std::cin >> dan1 >> znak2 >> mjesec1 >> znak3 >> godina1;
                                if (znak2 != '/' || znak3 != '/') throw std::domain_error ("Neispravan unos podataka.");
                                Datum dat1 (dan1, mjesec1, godina1);
                                kupci[izbor_kupca - 1].Postavi(ime_i_prezime1, dat1);
                                std::cout << "Kupac je uspjesno izmijenjen!" << std::endl << std::endl;
                               // break;
                            }
                            catch (std::domain_error hel) {
                                std::cout << "Izuzetak: " << hel.what() << " Molimo unesite opet." <<std::endl;
                                std::cin.ignore(10000,'\n');
                                goto macka;
                            }
                            break;
                        }
                    }
                } while (izbor4 != 4);
                break;
            }
            case(3): {
                do {
                    paun:
                    std::cout << "Izaberite opciju:" << std::endl;
                    std::cout << " 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj" << std::endl;
                    std::cin >> izbor3;
                    if (izbor3 == 5) {
                        std::cout << std::endl << std::endl << "Dovidjenja!";
                        return 0;
                    }
                    switch(izbor3) {
                        case(0): {
                            goto petlja;
                            break;
                        }
                        case(1): {
                            prodaja_izbor:
                            std::cout <<  "Izaberite opciju:" << std::endl;
                            std::cout << " 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj" << std::endl;
                            std::cin >> izbor_prodaje;
                            std::cin.ignore(10000,'\n');
                            if (izbor_prodaje == 3) {
                                std::cout << std::endl << std::endl << "Dovidjenja!";
                                return 0;
                            }
                            switch(izbor_prodaje) {
                                case(0): {
                                    goto paun;
                                    break;
                                }
                                case(3): {
                                    std::cout << std::endl << std::endl << "Dovidjenja!";
                                    return 0;
                                    break;
                                }
                                case(1): {
                                    mis:
                                    try {
                                        std::cout << "Unesite ime i prezime agenta prodaje: ";
                                        std::getline (std::cin, ime_agenta);
                                        std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                        char znak5, znak6;
                                        std::cin >> dan_prodaja >> znak5 >> mjesec_prodaja >> znak6 >> godina_prodaja;
                                        if (znak5 != '/' || znak6 != '/') throw std::domain_error ("Neispravan unos podataka.");
                                        Datum dat_pom (dan_prodaja, mjesec_prodaja, godina_prodaja);
                                        std::cout << "Unesite cijenu stana: ";
                                        std::cin >> cijena_stana;
                                        std::cin.ignore(10000,'\n');
                                        std::cout << "Unesite ime kupca: ";
                                        std::getline (std::cin, ime_kupca);
                                        std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                                        std::cin >> dan_rod >> znak5 >> mjesec_rod >> znak6 >> godina_rod;
                                        if (znak5 != '/' || znak6 != '/') throw std::domain_error ("Neispravan unos datuma.");
                                        Datum rodjenje (dan_rod, mjesec_rod, godina_rod);
                                        std::cin.ignore(10000,'\n');
                                        std::cout << "Unesite adresu: ";
                                        std::getline (std::cin, adresa_prodaja);
                                        std::cout << "Unesite sprat: ";
                                        std::cin >> sprat_prodaja;
                                        std::cout << "Unesite broj soba: ";
                                        std::cin >> soba_prodaja;
                                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                        std::cin >> namjesten_prodaja;
                                        if (namjesten_prodaja != 0 && namjesten_prodaja != 1) throw std::domain_error ("Neispravan unos podataka.");
                                        std::cout << "Unesite kvadraturu: ";
                                        std::cin >> kvadratura;
                                        Prodaja pom(ime_agenta,cijena_stana,dan_prodaja, mjesec_prodaja, godina_prodaja, ime_kupca, rodjenje, adresa_prodaja, sprat_prodaja, soba_prodaja, namjesten_prodaja, kvadratura);
                                        Prodaja *glavna = new Prodaja(pom);
                                        prodaja.RegistrirajProdaju(glavna);
                                        std::cout << "Prodaja uspjesno dodana!" << std::endl;
                                        kupci.emplace_back(ime_kupca, rodjenje);
                                        stanovi.emplace_back (adresa_prodaja, sprat_prodaja, soba_prodaja, namjesten_prodaja, kvadratura);
                                        //break;
                                    }
                                    catch (std::domain_error glu) {
                                        std::cout << "Izuzetak: " << glu.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore (10000,'\n');
                                        goto mis;
                                    }
                                    
                                    goto prodaja_izbor;
                                }
                                case(2): {
                                    harli:
                                    try {
                                        std::cout << "Unesite ime i prezime agenta prodaje: ";
                                        std::string novi_agent;
                                        std::getline (std::cin, novi_agent);
                                        std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                        char znak9, znak10;
                                        int novi_dan, novi_mjesec, novi_god;
                                        std::cin >> novi_dan >> znak9 >> novi_mjesec >> znak10 >> novi_god;
                                        if (znak9 != '/' || znak10 != '/') throw std::domain_error ("Neispravan unos podataka.");
                                        int nova_cijena;
                                        std::cout << "Unesite cijenu stana: ";
                                        std::cin >> nova_cijena;
                                        std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                                        for (int i=0; i<kupci.size(); i++) {
                                            std::cout << " " << i+1 << " - ";
                                            kupci[i].Ispisi();
                                            std::cout << std::endl;
                                        }
                                        std::cin >> glupi_kupac;
                                        std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                                        for (int i=0; i<stanovi.size(); i++) {
                                            std::cout << " " << i+1 << " - ";
                                            stanovi[i].Ispisi();
                                            std::cout << std::endl;
                                        }
                                        std::cin >> glupi_stan;
                                        std::string nova_adresa = stanovi[glupi_stan - 1].DajAdresu();
                                        int nova_sprat = stanovi[glupi_stan - 1].DajSprat();
                                        double nova_kvadratura = stanovi[glupi_stan - 1].DajKvadraturu();
                                        int nova_broj_soba = stanovi[glupi_stan - 1].DajBrojSoba();
                                        bool nova_namjesten = stanovi[glupi_stan - 1].DajNamjesten();
                                        std::string nova_ime_prezime = kupci[glupi_kupac - 1].DajImePrezime();
                                        Datum nova_datum = kupci[glupi_kupac - 1].DajDatumRodjenja();
                                        prodaja.RegistrirajProdaju(novi_agent, nova_cijena, novi_dan, novi_mjesec, novi_god, nova_ime_prezime, nova_datum, nova_adresa, nova_sprat, nova_broj_soba, nova_namjesten, nova_kvadratura);
                                        std::cout << "Prodaja uspjesno dodana!" << std::endl;
                                        goto prodaja_izbor;
                                       // break;
                                    }
                                    catch(std::domain_error nesto) {
                                        std::cout << "Izuzetak: "  << nesto.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore(10000,'\n');
                                        goto harli;
                                    }
                                    break;
                                }
                            }
                            break;
                        }
                        case(2): {
                            smak:
                            std::cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su:" << std::endl;
                            /*std::sort (prodaja, prodaja.DajBrojProdaja(), [prodaja] (Prodaja *p1, Prodaja *p2) {
                                return(p1->DajDatumProdaje() < p2->DajDatumProdaje());
                            });*/
                            /*Prodaje nesto(prodaja);
                            std::sort (nesto, prodaja.DajBrojProdaja(), ProdatPrije());*/
                            for (int i=0; i<prodaja.DajBrojProdaja(); i++) {
                                std::cout << i+1 << "." << std::endl;
                                Prodaja temp = prodaja.DajProdaju(i+1);
                                temp.Ispisi();
                                std::cout << std::endl;
                            }
                            std::cin >> glupa_prodaja;
                            glupost:
                            std::cout << "Izaberite opciju:" << std::endl;
                            std::cout << " 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca\n 4 - izmjena stana\n 5 - izmjena cijene stana" << std::endl;
                            std::cin >> glupi_izbor;
                            std::cin.ignore(10000,'\n');
                            switch(glupi_izbor) {
                                case(0): {
                                    goto smak;
                                    break;
                                }
                                case(1): {
                                    kvin:
                                    try {
                                        std::string najnovije_ime;
                                        std::cout << "Unesite ime i prezime agenta prodaje: ";
                                        std::getline (std::cin, najnovije_ime);
                                        Prodaja nova_neka = prodaja.DajProdaju(glupa_prodaja);
                                        prodaja.DajProdaju(glupa_prodaja).PromijeniImeAgenta(najnovije_ime);
                                        std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                        
                                        //break;
                                    }
                                    catch (std::domain_error poruka) {
                                        std::cout << "Izuzetak: " << poruka.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore(10000,'\n');
                                        goto kvin;
                                    }
                                    break;
                                }
                                case(2): {
                                    mreza:
                                    try {
                                        std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                        int najnoviji_dan, najn_mje, najn_god;
                                        char ji, ni;
                                        std::cin >> najnoviji_dan >> ji >> najn_mje >> ni >> najn_god;
                                        Datum krava (najnoviji_dan, najn_mje, najn_god);
                                        prodaja.DajProdaju(glupa_prodaja).PromijeniDatumKupovine(krava);
                                        std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                     //   break;
                                    }
                                    catch (std::domain_error oz) {
                                        std::cout << "Izuzetak: " << oz.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore(10000,'\n');
                                        goto mreza;
                                    }
                                    break;
                                }
                                case(3): {
                                    std::cout << "Izaberite opciju:"<<std::endl;
                                    std::cout <<" 0 - nazad\n 1 - odabir postojeceg kupca\n 2 - dodavanje novog kupca" << std::endl;
                                    std::cin >> jos_gluplji_izbor;
                                    std::cin.ignore(10000,'\n');
                                    switch(jos_gluplji_izbor) {
                                        case(0): {
                                            goto glupost;
                                            break;
                                        }
                                        case(1): {
                                            std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                                            for (int i=0; i<kupci.size(); i++) {
                                                std::cout << " "<< i+1 << " - ";
                                                kupci[i].Ispisi();
                                                std::cout << std::endl;
                                            } 
                                            std::cin >> jos_gluplji_kupac;
                                            std::cin.ignore(10000,'\n');
                                            prodaja.DajProdaju(glupa_prodaja).PromijeniKupca(kupci[jos_gluplji_kupac - 1]);
                                            std::cout << "Prodaja je uspjesno izmijenjena" << std::endl;
                                            break;
                                        }
                                        case(2): {
                                            be:
                                            try {
                                                std::cout << "Unesite ime i prezime kupca: ";
                                                std::string imeneko;
                                                std::getline(std::cin, imeneko);
                                                
                                                std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                                int nesto24,nesto13,nesto44;
                                                char zmija('a'), koza('a');
                                    
                                                std::cin >> nesto24 >> zmija >> nesto13 >> koza >> nesto44;
                                                if (zmija != '/' || koza != '/') throw std::domain_error ("Neispravan datum.");
                                                Datum lepidatum(nesto24, nesto13, nesto44);
                                                Kupac glavni (imeneko, lepidatum);
                                                prodaja.DajProdaju(glupa_prodaja).PromijeniKupca(glavni);
                                                std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                               // break;
                                            }
                                            catch (std::domain_error bat) {
                                                std::cout << "Izuzetak: " << bat.what() << " Molimo unesite opet" << std::endl;
                                                std::cout << std::endl;
                                                goto be;
                                            }
                                            break;
                                        }
                                        case(4): {
                                            std::cout << "Izaberite opciju:" << std::endl;
                                            std::cout << "0 - nazad\n1 - odabir postojeceg stana\n2 - dodavanje novog stana" << std::endl;
                                            int neki_izbor; std::cin >> neki_izbor;
                                            std::cin.ignore(10000,'\n');
                                            switch(neki_izbor) {
                                                case(0): {
                                                    goto glupost;
                                                    break;
                                                }
                                                case(1): {
                                                    std::cout << "Odaberite stan. Dostupni stanovi su:" << std::endl;
                                                    for (int i=0; i<stanovi.size(); i++) {
                                                        std::cout << " " << i+1 << " - " << std::endl;
                                                        stanovi[i].Ispisi();
                                                        std::cout << std::endl;
                                                    }
                                                    int izaberi_stan;
                                                    std::cin >> izaberi_stan;
                                                    prodaja.DajProdaju(glupa_prodaja).PromijeniStan(stanovi[izaberi_stan - 1]);
                                                    std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                                    break;
                                                }
                                                case(2): {
                                                    vukodlak:
                                                    try {
                                                        std::cout << "Unesite adresu: ";
                                                        std::string neka_adresa;
                                                        std::getline (std::cin, neka_adresa);
                                                        int neki_sprat, neka_soba;
                                                        bool neka_namjesten;
                                                        double neka_kvadratura;
                                                        std::cout << "Unesite sprat: ";
                                                        std::cin >> neki_sprat;
                                                        std::cout << "Unesite broj soba: ";
                                                        std::cin >> neka_soba;
                                                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                                        std::cin >> neka_namjesten;
                                                        if (neka_namjesten != 0 && neka_namjesten != 1) throw std::domain_error ("Neispravan unos podataka.");
                                                        std::cout << "Unesite kvadraturu: ";
                                                        std::cin >> neka_kvadratura;
                                                        Stan jeji (neka_adresa, neki_sprat, neka_soba, neka_namjesten, neka_kvadratura);
                                                        prodaja.DajProdaju(glupa_prodaja).PromijeniStan(jeji);
                                                        std::cout << "Prodaja je uspjesno izmijenjena!"<<std::endl;
                                                        //break;
                                                    }
                                                    catch (std::domain_error vampir) {
                                                        std::cout << "Izuzetak: " << vampir.what() << " Molimo unesite opet." << std::endl;
                                                        std::cin.ignore(10000,'\n');
                                                        goto vukodlak;
                                                    }
                                                   break;
                                                }
                                            }
                                            break;
                                        }
                                        case(5): {
                                            std::cout << "Unesite cijenu stana: ";
                                            int neka_cijena;
                                            std::cin >> neka_cijena;
                                            prodaja.DajProdaju(glupa_prodaja).PromijeniCijenuProdaje(neka_cijena);
                                            std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl;
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                            break;
                        }
                        case(3): {
                            zadnja:
                            //std::cin.ignore(10000,'\n');
                            std::cout << "Izaberite opciju:"<< std::endl;
                            std::cout << " 0 - nazad\n 1 - ispis svih prodaja\n 2 - ispis prodaja na datum\n 3 - ispis najranije prodaje\n";
                            std::cout << " 4 - ispis najskuplje prodaje\n 5 - ispis broja prodaja\n 6 - ispis broja prodaja po datumu\n 7 - ispis broja prodaja po agentu\n 8 - kraj"<<std::endl;
                            std::cin >> zadnja_izbor;
                           // std::cin.ignore(10000,'\n');
                            if (zadnja_izbor == 8) {
                                std::cout << std::endl << std::endl << "Dovidjenja!";
                                return 0;
                            }
                            switch(zadnja_izbor) {
                                case(0): {
                                    goto paun;
                                    break;
                                }
                                case(1): {
                                    prodaja.IspisiSveProdaje();
                                    //std::cin.ignore (10000,'\n');
                                    goto zadnja;
                                 //   break;
                                    
                                }
                                case(2): {
                                    lola:
                                    std::cin.ignore (10000,'\n');
                                    try {
                                        std::cout << "Unesite datum (d/m/g): ";
                                        int eci, peci, pec;
                                        char zeko, peko;
                                        std::cin >> eci >> zeko >> peci >> peko >> pec;
                                        if (zeko != '/' && peko != '/') throw std::domain_error ("Neispravan datum.");
                                        Datum magija (eci, peci, pec);
                                        std::cout << "Prodaje na datum ";
                                        magija.Ispisi();
                                        std::cout << "su" << std::endl;
                                        prodaja.IspisiProdajeNaDatum(magija);
                                       // break;
                                    }
                                    catch (std::domain_error vucko) {
                                        std::cout << "Izuzetak: " << vucko.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore(10000,'\n');
                                        goto lola;
                                    }
                                    break;
                                }
                                case(3): {
                                    prodaja.DajNajranijuProdaju().Ispisi();
                                    std::cout << std::endl;
                                    break;
                                }
                                case(4): {
                                    prodaja.DajNajskupljuProdaju().Ispisi();
                                    std::cout << std::endl;
                                    break;
                                }
                                case(5): {
                                    std::cout <<"Broj prodaja: " << prodaja.DajBrojProdaja();
                                    std::cout << std::endl;
                                    break;
                                }
                                case(6): {
                                    malibu:
                                    std::cin.ignore(10000,'\n');
                                    try {
                                        std::cout << "Unesite datum (d/m/g): ";
                                        int lol, wtf, wat;
                                        char pls, no;
                                        std::cin >> lol >> pls >> wtf >> no >> wat;
                                        if (pls != '/' && no != '/') throw std::domain_error ("Neispravan datum.");
                                        Datum emsi (lol, wtf, wat);
                                        std::cout << "Broj prodaja na uneseni datum: ";
                                        prodaja.DajBrojProdajaNaDatum(emsi);
                                        //break;
                                    }
                                    catch (std::domain_error ofc) {
                                        std::cout << "Izuzetak: " << ofc.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore(10000,'\n');
                                        goto malibu;
                                    }
                                   break;
                                }
                                case(7): {
                                    pls_stop:
                                    std::cin.ignore(10000,'\n');
                                    std::cout << "Unesite ime agenta: ";
                                    std::string budala;
                                    try {
                                        std::getline (std::cin, budala);
                                        std::cout << "Broj prodaja: ";
                                        prodaja.DajBrojProdajaOdAgenta(budala);
                                        //break;
                                    }
                                    catch (std::domain_error nemam_pojma_vise) {
                                        std::cout << "Izuzetak: " <<nemam_pojma_vise.what() << " Molimo unesite opet." << std::endl;
                                        std::cin.ignore(10000,'\n');
                                        goto pls_stop;
                                    }
                                  break;
                                }
                                case(8): {
                                    std::cout << std::endl << std::endl << "Dovidjenja!";
                                    return 0;
                                    break;
                                }
                            }
                            break;
                        } 
                       case(4): {
                           nema_ideja:
                           std::cout << "Izaberite opciju:" << std::endl;
                           std::cout << " 0 - nazad\n 1 - brisanje najranije prodaje\n 2 - brisanje prodaja agenta\n 3 - brisanje prodaja po datumu\n 4 - brisanje svih prodaja"; 
                           std::cout << std::endl;
                           std::cin >> finito_izbor; 
                           std::cin.ignore(10000,'\n');
                           switch(finito_izbor){
                               case(0): {
                                   goto paun;
                                   break;
                               }
                               case(1): {
                                   try {
                                       prodaja.ObrisiNajranijuProdaju();
                                       std::cout << "Najranija prodaja je obrisana!" << std::endl;
                                     //  break;
                                   }
                                   catch (std::range_error nema) {
                                       std::cout << "Izuzetak: " << nema.what() << " Molimo unesite opet." << std::endl;
                                       goto nema_ideja;
                                   }
                                   break;
                               }
                               case(2): {
                                   lila:
                                   try {
                                       std::cout << "Unesite ime agenta: ";
                                       std::string magarac;
                                       std::getline (std::cin, magarac);
                                       try {
                                           prodaja.ObrisiProdajeAgenta(magarac);
                                           std::cout << "Sve prodaje tog agenta su obrisane."<<std::endl;
                                         //  break;
                                       }
                                       catch (std::range_error nema) {
                                           std::cout << "Izuzetak: "<< nema.what() << " Molimo unesite opet." << std::endl;
                                           goto lila;
                                       }
                                      break;
                                   }
                                   catch(std::domain_error neko) {
                                       std::cout << "Izuzetak: " << neko.what() << " Molimo unesite opet." << std::endl;
                                       std::cin.ignore(10000,'\n');
                                       goto lila;
                                   }
                                   break;
                               }
                               case(3): {
                                   neon:
                                   try {
                                       std::cout << "Unesite datum: ";
                                       int mustang,camaro,dodge;
                                       char konj, viper;
                                       std::cin >> mustang >> konj >> camaro >> viper >> dodge;
                                       if (konj != '/' && viper != '/') throw std::domain_error ("Neispravan datum.");
                                       Datum car (mustang, camaro, dodge);
                                       try {
                                           prodaja.ObrisiProdajeNaDatum(car);
                                           std::cout << "Sve prodaje na taj datum su obrisane." << std::endl;
                                          // break;
                                       }
                                       catch (std::range_error nema) {
                                           std::cout << "Izuzetak: " << nema.what() << " Molimo unesite opet." << std::endl;
                                           goto neon;
                                       }
                                       break;
                                   }
                                   catch (std::domain_error datum) {
                                       std::cout << "Izuzetak: " << datum.what() << " Molimo unesite opet."<<std::endl;
                                       std::cin.ignore(10000,'\n');
                                       goto neon;
                                   }
                                   break;
                               }
                               case(4): {
                                   briga:
                                   try {
                                       prodaja.IsprazniKolekciju();
                                       std::cout << "Sve prodaje su obrisane" << std::endl;
                                      // break;
                                   }
                                   catch (std::range_error nema) {
                                       std::cout << "Izuzetak: " << nema.what() << " Molimo unesite opet."<<std::endl;
                                       goto briga;
                                   }
                                   break;
                               }
                           }
                           break;
                       }
                    }
                } while (izbor3 != 5);
                break;
            }
        }
    } while (izbor != 0);
    kraj:
   // std::cout << std::endl << std::endl << "Dovidjenja!";
	return 0;
}