/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cstring>

class Datum {
    int dan,mjesec,godina;
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
};

Datum::Datum(int dan, int mjesec, int godina) {
    int brdana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brdana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>brdana[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}
void Datum::Postavi(int dan, int mjesec, int godina) {
    int brdana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brdana[1]++;
    if(godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>brdana[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja = Datum(11,1,1998);
    void TestImena(const std::string &ime_i_prezime) {
        for(int i=0;i<ime_i_prezime.length();i++) {
            if(!((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || int(ime_i_prezime[i])==39)) throw std::domain_error("Neispravno ime i prezime");
        }
        
    }
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const { std::cout << ime_i_prezime << " ("; datum_rodjenja.Ispisi(); std::cout << ")"; }
};
Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    TestImena(ime_i_prezime);
    Kupac::datum_rodjenja=datum_rodjenja;
    Kupac::ime_i_prezime=ime_i_prezime;
}
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    TestImena(ime_i_prezime);
    Kupac::datum_rodjenja=datum_rodjenja;
    Kupac::ime_i_prezime=ime_i_prezime;
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

Stan::Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error ("Neispravan unos podataka");
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba;
    Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if(sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error ("Neispravan unos podataka");
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba;
    Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}
void Stan::Ispisi() const {
    std::string DaLiJe;
    if(namjesten) DaLiJe="je";
    else DaLiJe="nije";
    std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << broj_soba << " soba." << std::endl;
    std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan " << DaLiJe << " namjesten.";
}

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje = Datum(11,1,1998);
    Kupac kupac_stana = Kupac("x",{11,1,1998});
    Stan kupljeni_stan = Stan("x",0,0,0,0);
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) { kupac_stana=novi_kupac; }
    void PromijeniStan(const Stan &novi_stan) { kupljeni_stan=novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datum_prodaje=novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena_stana=nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const { return kupac_stana.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) { if(p1.cijena_stana>p2.cijena_stana) return true; return false; }
    void Ispisi() const { std::cout << ime_agenta_prodaje << std::endl << cijena_stana << std::endl; datum_prodaje.Ispisi(); std::cout << std::endl; kupac_stana.Ispisi(); std::cout << std::endl; kupljeni_stan.Ispisi(); } 
};

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana; Prodaja::datum_prodaje=datum_prodaje;
    Prodaja::kupac_stana=kupac_stana; Prodaja::kupljeni_stan=kupljeni_stan;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : 
datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac_stana(ime_kupca,datum_rodjenja_kupca), kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana; Prodaja::datum_prodaje=datum_prodaje;
        Prodaja::kupac_stana=kupac_stana; Prodaja::kupljeni_stan=kupljeni_stan;
}
void Prodaja::PomjeriDanUnaprijed() {
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    int brdana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brdana[1]++;
    dan++;
    if(dan>brdana[mjesec-1]) { dan=1; mjesec++; }
    if(mjesec>12) { mjesec=1; godina++; }
    datum_prodaje.Postavi(dan,mjesec,godina);
}
void Prodaja::PomjeriDanUnazad() {
    int dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec()), godina(datum_prodaje.DajGodinu());
    int brdana[12] {31,28,31,30,31,30,31,31,30,31,30,31};
    if(godina%4==0 && (godina%100!=0 || godina%400==0)) brdana[1]++;
    dan--;
    if(dan<1) { mjesec--; dan=brdana[mjesec]; }
    if(mjesec<1) {godina--; mjesec=12; }
    datum_prodaje.Postavi(dan,mjesec,godina);
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    int dan1(p1.datum_prodaje.DajDan()), mjesec1(p1.datum_prodaje.DajMjesec()), godina1(p1.datum_prodaje.DajGodinu());
    int dan2(p2.datum_prodaje.DajDan()), mjesec2(p2.datum_prodaje.DajMjesec()), godina2(p2.datum_prodaje.DajGodinu());
    if(godina1<godina2) return true;
    else if(godina1>godina2) return false;
    else if(godina1==godina2) {
        if(mjesec1<mjesec2) return true;
        else if(mjesec1>mjesec2) return false;
        else if(mjesec1==mjesec2) {
            if(dan1<dan2) return true;
            return false;
        }
    }
}

class Prodaje {
    Prodaja **prodaja;
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
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje,
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


int main ()
{
    try {
        Datum d(11,1,1998),d2(31,12,2919);
        Kupac k("Belmin Divjan", d), k2("Konjo Konjic",d2);
        Stan s("Rakovicka cesta 99",5,9,false,70);
        Prodaja p("Hasim",123,d,k,s);
        p.Ispisi();
        p.PromijeniKupca(k2); p.PromijeniCijenuProdaje(450); p.PromijeniDatumKupovine(d2);
        std::cout << std::endl;
        p.Ispisi();
        p.PomjeriDanUnaprijed();
        std::cout << std::endl;
        p.Ispisi();
        std::cout << std::endl;
        p.DajDatumProdaje().Ispisi();
        std::cout << std::endl;
        p.PomjeriDanUnazad();
        p.Ispisi();
    }
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what() << std::endl;
    }
	return 0;
}