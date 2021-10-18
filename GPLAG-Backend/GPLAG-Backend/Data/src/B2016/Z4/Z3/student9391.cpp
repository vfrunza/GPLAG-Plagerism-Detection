/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <vector>
#include<string>

using namespace std;

class Datum {
    int dan, mjesec, godina;
public:
    Datum();//napisano
    Datum(int dan, int mjesec, int godina);//napisano
    void Postavi(int dan, int mjesec, int godina);//napisano
    int DajDan() const;//napisano
    int DajMjesec() const;//napisano
    int DajGodinu() const;//napisano
    void Ispisi() const;//napisano
};


Datum::Datum() {Datum::dan=0; Datum::mjesec=0; Datum::godina=0;}

Datum::Datum(int dan, int mjesec, int godina) {
    std::vector<int> broj_dana {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && godina%100!=0 && godina%400==0) broj_dana.at(1)++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana.at(mjesec-1)) throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    std::vector<int> broj_dana {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina %4 ==0 && godina%100!=0 && godina%400==0) broj_dana.at(1)++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana.at(mjesec-1)) throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
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
    cout << dan << "/" << mjesec << "/" << godina;
}

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac();//napisano
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);//napisano
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);//napisano
    std::string DajImePrezime() const;//napisano
    void Ispisi() const;//napisano
};

Kupac::Kupac() {
    Kupac::ime_i_prezime="Hamo Hapic"; Kupac::datum_rodjenja=datum_rodjenja;
}

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    Kupac::ime_i_prezime=ime_i_prezime; Kupac::datum_rodjenja=datum_rodjenja;
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    Kupac::ime_i_prezime=ime_i_prezime; Kupac::datum_rodjenja=datum_rodjenja;
}

std::string Kupac::DajImePrezime() const {
    return ime_i_prezime;
}

void Kupac::Ispisi() const {
    cout << ime_i_prezime << "(";
    datum_rodjenja.Ispisi();
    cout<<")";
}



class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten; 
    double kvadratura;
public:
    Stan();
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);//napisano
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);//napisano
    std::string DajAdresu() const;//napisano
    int DajSprat() const;//napisano
    int DajBrojSoba() const;//napisano
    bool DajNamjesten() const;//napisano
    double DajKvadraturu() const;//napisano
    void Ispisi() const;//napisano
};

Stan::Stan() {
    Stan::adresa="Adresa"; Stan::sprat=0; Stan::broj_soba=1; Stan::namjesten=true; Stan::kvadratura=52;
}

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
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
    if(DajBrojSoba()<0 || DajSprat()<0 || DajKvadraturu()<0) throw domain_error("Neispravan unos podataka");
    if (DajBrojSoba()==1) { cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobu."; }
    else if ((DajBrojSoba()>1)&&(DajBrojSoba()<5)) { cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobe."; }
    else { cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba."; }
    
    if (DajNamjesten()) { cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan " << DajNamjesten() << " je namjesten."; }
    else { cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan nije namjesten."; } 
}



class Prodaja {
    std::string ime_agenta_prodaje;
    std::string ime_kupca;
    std::string adresa_stana;
    Datum datum_prodaje;
    Datum datum_rodjenja_kupca;
    Datum novi_datum;
    Kupac novi_kupac, kupac_stana;
    Stan kupljeni_stan,novi_stan;
    /*Kupac novi_kupac=Kupac(const std::string ime_i_prezime, Datum datum_rodjenja);
    Kupac kupac_stana=Kupac(const std::string ime_i_prezime, Datum datum_rodjenja);
    Stan kupljeni_stan=Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    Stan novi_stan=Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);*/
    bool namjesten_stan;
    int sprat_stana, broj_soba, dan_prodaje, mjesec_prodaje, godina_prodaje;
    double cijena_stana, broj_kvadrata, nova_cijena;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);//napisano
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);//napisano
    void PromijeniKupca(const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje(const double &nova_cijena);
    void PomjeriDanUnaprijed();//napisano
    void PomjeriDanUnazad();//napisano? (provjeriti logiku ovog minusa malo)
    std::string DajImeAgenta() const;//napisano
    std::string DajImeKupca() const;//napisano
    Datum DajDatumProdaje() const;//napisano
    double DajCijenuStana() const;//napisano
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
    Prodaja::cijena_stana=cijena_stana;
    Prodaja::datum_prodaje=datum_prodaje;
    Prodaja::kupac_stana=kupac_stana;
    Prodaja::kupljeni_stan=kupljeni_stan;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
    Prodaja::cijena_stana=cijena_stana;
    Prodaja::dan_prodaje=dan_prodaje;
    Prodaja::mjesec_prodaje=mjesec_prodaje;
    Prodaja::godina_prodaje=godina_prodaje;
    Prodaja::ime_kupca=ime_kupca;
    Prodaja::datum_rodjenja_kupca=datum_rodjenja_kupca;
    Prodaja::adresa_stana=adresa_stana;
    Prodaja::sprat_stana=sprat_stana;
    Prodaja::broj_soba=broj_soba;
    Prodaja::namjesten_stan=namjesten_stan;
    Prodaja::broj_kvadrata=broj_kvadrata;
}

void Prodaja::PomjeriDanUnaprijed() {
    std::vector<int> broj_dana {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina_prodaje%4==0) && (godina_prodaje%100!=0) || (godina_prodaje%400==0)) broj_dana.at(1)++;
    dan_prodaje++;
    if(dan_prodaje>broj_dana.at(mjesec_prodaje-1)) dan_prodaje=1, mjesec_prodaje++;
    if(mjesec_prodaje>12) mjesec_prodaje=1, godina_prodaje++;
}

void Prodaja::PomjeriDanUnazad() {
    std::vector<int> broj_dana {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina_prodaje%4==0) && (godina_prodaje%100!=0) || (godina_prodaje%400==0)) broj_dana.at(1)++;
    dan_prodaje--;
    if(dan_prodaje<1) dan_prodaje=broj_dana.at(mjesec_prodaje-2), mjesec_prodaje--;
    if(mjesec_prodaje<1) mjesec_prodaje=12, godina_prodaje--;
}

std::string Prodaja::DajImeAgenta() const {
    return ime_agenta_prodaje;
}

std::string Prodaja::DajImeKupca() const {
    return ime_kupca;
}

Datum Prodaja::DajDatumProdaje() const {
    return datum_prodaje;
}

double Prodaja::DajCijenuStana () const {
    return cijena_stana;
}


class Prodaje {
    
public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
                            const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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



int main () {
    int dan,mjesec,godina;
    cout << "Unesi datum:";
    cin >> dan >> mjesec >> godina;
    Datum dat1(dan, mjesec, godina);
    dat1.Ispisi();
    cout << dat1.DajDan() << endl;
    cout << dat1.DajMjesec() << endl;
    cout << dat1.DajGodinu() << endl;
	return 0;
}