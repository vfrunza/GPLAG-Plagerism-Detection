/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <initializer_list>
#include <stdexcept>
//Klasa datum
class Datum {
    int dan, mjesec, godina;
    public:
    Datum (int dan, int mjesec, int godina);
    void Postavi (int dan, int mjesec, int godina);
    int DajDan () const {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    }
    int DajGodinu () const {
        return godina;
    }
    void Ispisi () const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
    void PomjeriDanNaprijed();
    void PomjeriDanNazad();
};
void Datum::Postavi (int dan, int mjesec, int godina) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina%4==0 && godina%100!=0 || godina%400==0)
        broj_dana[1]++;
    if (godina<1 || mjesec<1 || dan<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error ("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
}
Datum::Datum (int dan, int mjesec, int godina) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina%4==0 && godina%100!=0 || godina%400==0)
        broj_dana[1]++;
    if (godina<1 || mjesec<1 || dan<1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error ("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
}
void Datum::PomjeriDanNaprijed() {
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if (godina%4==0 && godina%100!=0 || godina%400==0)
        broj_dana[1]++;
    dan++;
    if (dan>broj_dana[mjesec-1]) {
        dan=1;
        mjesec++;
    }
    if (mjesec>12) {
        mjesec=1;
        godina++;
    }
}
void Datum::PomjeriDanNazad() {
    int broj_dana [] {31,28,31,30,31,30,31,31,30,31,30,31};
    if (godina%4==0 && godina%100!=0 || godina%400==0) 
        broj_dana[1]++;
    dan--;
    if (dan==0) {
        mjesec--;
        dan=broj_dana[mjesec-1];
        
    }
    if (mjesec==0) {
        godina--;
        mjesec=12;
    }
    //STA AKO JE GODINA=0???
}

//Klasa kupac
class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImeIPrezime() const {
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja ()const {
        return datum_rodjenja;
    }
    void Ispisi() const {
        std::cout<<DajImeIPrezime();
        std::cout<<"("<<datum_rodjenja.DajDan()<<"/"<<datum_rodjenja.DajMjesec()<<"/"<<datum_rodjenja.DajGodinu()<<")";
    }
};
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    std::string s(ime_i_prezime);
    for (int i=0; i<s.size(); i++) {
        if ((s[i]<'a' || s[i]>'z') && (s[i]<'A' || s[i]>'Z') && (s[i]!=' ') && (s[i]<'0' || s[i]>'9') && (s[i]!=39) )
        throw std::domain_error ("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime=ime_i_prezime;
    Kupac::datum_rodjenja=datum_rodjenja;
}
Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodjenja(datum_rodjenja) {
    std::string s(ime_i_prezime);
    for (int i=0; i<s.size(); i++) {
        if ((s[i]<'a' || s[i]>'z') && (s[i]<'A' || s[i]>'Z') && (s[i]!=' ') && (s[i]<'0' || s[i]>'9') && (s[i]!=39))
            throw std::domain_error ("Neispravno ime i prezime");
    }
    Kupac::ime_i_prezime=ime_i_prezime;
    }

//Klasa Stan
class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    public:
    Stan (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu()const {
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
Stan::Stan (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat<0 || broj_soba<0 || kvadratura<0) 
        throw std::domain_error ("Neispravan unos podataka");
    Stan::adresa=adresa;
    Stan::sprat=sprat;
    Stan::broj_soba=broj_soba;
    Stan::namjesten=namjesten;
    Stan::kvadratura=kvadratura;
}
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat<0 || broj_soba<0 || kvadratura<0)
        throw std::domain_error ("Neispravan unos podataka");
        Stan::adresa=adresa;
        Stan::sprat=sprat;
        Stan::broj_soba=broj_soba;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
}
void Stan::Ispisi() const {
    int broj;
    broj=broj_soba%100;
    if (broj==1) {
        if (namjesten)
            std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" soba. Kvadratura stana je "<<kvadratura<<" (m^2) i stan je namjesten.";
        else 
            std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" soba. Kvadratura stana je "<<kvadratura<<" (m^2) i stan nije namjesten";
    }
    else {
        broj=broj_soba%10;
        if (broj==2 || broj==3 || broj==4) {
            if (namjesten) {
                std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" sobe. Kvadratura stana je "<<kvadratura<<" (m^2) i stan je namjesten.";
            }
            else 
                std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" sobe. Kvadratura stana je "<<kvadratura<<" (m^2) i stan nije namjesten.";
        }
        else if (broj>=5) {
            if (namjesten) {
                std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" soba. Kvadratura stana je "<<kvadratura<<" (m^2) i stan je namjesten.";
            }
            else 
                std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" soba. Kvadratura stana je "<<kvadratura<<" (m^2) i stan nije namjesten.";
        }
        else if (broj==1) {
            if (namjesten) {
                std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" sobu. Kvadratura stana je "<<kvadratura<<" (m^2) i stan je namjesten.";
            }
            else 
               std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" sobu. Kvadratura stana je "<<kvadratura<<" (m^2) i stan nije namjesten.";
        }
    }
}

//Klasa prodaja
class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca (const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje (const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjerDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const {return kupac_stana.DajImeIPrezime();}
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2);
    friend bool ProdatPrije (const Prodaja &p1, const Prodaja &p2);
    void Ispisi();
};
Prodaja::Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
    Prodaja::cijena_stana=cijena_stana;
}
Prodaja::Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,int sprat_stana, int broj_soba, bool namjesten_stan,
    double broj_kvadrata): datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca),kupljeni_stan(adresa_stana,sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {
    Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
    Prodaja::cijena_stana=cijena_stana;
}
void Prodaja::PromijeniKupca(const Kupac &novi_kupac) {
    Prodaja::kupac_stana=novi_kupac;
}
void Prodaja::PromijeniStan(const Stan&novi_stan) {
    Prodaja::kupljeni_stan=novi_stan;
}
void Prodaja::PromijeniDatumKupovine(const Datum &novi_datum) {
    datum_prodaje=novi_datum;
}
void Prodaja::PromijeniCijenuProdaje(const double &nova_cijena) {
    cijena_stana=nova_cijena;
}
void Prodaja::PomjeriDanUnaprijed() {
    datum_prodaje.PomjeriDanNaprijed();
}
void Prodaja::PomjerDanUnazad() {
    datum_prodaje.PomjeriDanNazad();
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    double cijena1, cijena2;
    cijena1=p1.DajCijenuStana();
    cijena2=p2.DajCijenuStana();
    if (cijena1>cijena2) return true;
    else return false;
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    int godina1,godina2,mjesec1,mjesec2,dan1,dan2;
    Datum g1(p1.DajDatumProdaje());
    Datum g2(p2.DajDatumProdaje());
    godina1=g1.DajGodinu(); godina2=g2.DajGodinu();
    mjesec1=g1.DajMjesec(); mjesec2=g2.DajMjesec();
    dan1=g1.DajDan(); dan2=g2.DajDan();
    if (godina1<godina2) return true;
    if (godina1>godina2) return false;
    if (mjesec1<mjesec2) return true;
    if (mjesec1>mjesec2) return false;
    if (dan1<dan2) return true;
    if (dan1>dan2) return false;
   return false; 
}
void Prodaja::Ispisi() {
    std::cout<<"Ime agenta: "<<std::setprecision(10)<<DajImeAgenta()<<std::endl;
    std::cout<<"Ime kupca: "<<std::setprecision(10)<<DajImeKupca()<<std::endl;
    Datum d(DajDatumProdaje());
    std::cout<<"Zakazani datm prodaje: "<<std::setprecision(10);
    d.Ispisi();
    std::cout<<std::endl;
    //std::cout<<"Zakazani datum prodaje: "<<std::setprecision(10)<<d.Ispisi()<<std::endl;
    std::cout<<"Cijena stana: "<<std::setprecision(10)<<DajCijenuStana()<<std::endl;
    std::cout<<"Informacije o stanu: "<<std::endl;
    kupljeni_stan.Ispisi();
}

//Klasa Prodaje
class Prodaje {
    int broj_prodaja, max_broj_prodaja;
    Prodaja **pokazivac;
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje (const Prodaje &prodaje);
    Prodaje (Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju (Prodaja *prodaja);
    int DajBrojProdaja () const { return broj_prodaja; }
    int DajBrojProdajaNaDatum (const Datum &datum) const;
    int DajBrojProdajaOdAgenta (const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju()const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
    //int *begin () const { return pokazivac; }
   // int *end () const {return pokazivac+broj_prodaja; }
};
Prodaje::Prodaje (int max_broj_prodaja):max_broj_prodaja(max_broj_prodaja) {
        broj_prodaja=0;
        pokazivac=new Prodaja*[max_broj_prodaja] {};
}
Prodaje::Prodaje (std::initializer_list<Prodaja> spisak_prodaja):max_broj_prodaja(spisak_prodaja.size()), pokazivac(new Prodaja*[max_broj_prodaja]) {
    auto spisak(spisak_prodaja.begin());
    for (int i=0; i<spisak_prodaja.size(); i++) {
        pokazivac[i]=new Prodaja(*spisak);
        spisak++;
    }
    broj_prodaja=max_broj_prodaja;
}
Prodaje::~Prodaje () {
    for (int i=0; i<broj_prodaja; i++) 
        delete pokazivac[i];
    delete[] pokazivac;
}
Prodaje::Prodaje (const Prodaje &prodaje): broj_prodaja(prodaje.broj_prodaja), max_broj_prodaja(prodaje.max_broj_prodaja),pokazivac (new Prodaja *[max_broj_prodaja]) {
    try {
        for (int i=0; i<broj_prodaja; i++)
            pokazivac[i]=new Prodaja(*prodaje.pokazivac[i]);
    } catch(...) {
        for (int i=0; i<broj_prodaja; i++)
            delete pokazivac[i];
        delete [] pokazivac;
        throw;
    }
}
Prodaje::Prodaje(Prodaje &&prodaje):broj_prodaja(prodaje.broj_prodaja), max_broj_prodaja(prodaje.max_broj_prodaja), pokazivac(prodaje.pokazivac) {
    prodaje.pokazivac=nullptr;
    prodaje.broj_prodaja=0;
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje) {
    if (max_broj_prodaja!=prodaje.max_broj_prodaja) throw std::domain_error ("bla bla");
    if (prodaje.max_broj_prodaja>max_broj_prodaja) {
        try {
            for (int i=broj_prodaja; i<prodaje.broj_prodaja; i++) {
                pokazivac[i]=new Prodaja(*prodaje.pokazivac[i]);
            }
        } catch (...) {
            for (int i=broj_prodaja; i<prodaje.broj_prodaja; i++) {
                delete pokazivac[i];
                pokazivac[i]=nullptr;
            }
            throw;
        }
    }
    else {
        for (int i=prodaje.broj_prodaja; i<broj_prodaja; i++) {
            delete pokazivac[i];
            pokazivac[i]=nullptr;
        }
    }
    broj_prodaja=prodaje.broj_prodaja;
    for (int i=0; i<broj_prodaja; i++) {
        *pokazivac[i]=*prodaje.pokazivac[i];
    }
    return *this;
}
Prodaje &Prodaje::operator=(Prodaje &&prodaje) {
    if (prodaje.max_broj_prodaja!=max_broj_prodaja) throw ("bla bla");
    std::swap (broj_prodaja, prodaje.broj_prodaja);
    std::swap(pokazivac, prodaje.pokazivac);
    return *this;
}
/*void Prodaje::RegistrirajProdaju(const std::string ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
        const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
            if (broj_prodaja==max_broj_prodaja) throw std::range_error ("Dostignut maksimalni broj prodaja");
}*/

int Prodaje::DajBrojProdajaNaDatum (const Datum &datum) const {
   int brojac(0);
    for (int i=0; i<broj_prodaja; i++) {
        if (pokazivac[i]->DajDatumProdaje().DajDan()==datum.DajDan() && pokazivac[i]->DajDatumProdaje().DajMjesec()==datum.DajMjesec() && pokazivac[i]->DajDatumProdaje().DajGodinu()==datum.DajGodinu())
            brojac++;
    }
    return brojac;
}
int Prodaje::DajBrojProdajaOdAgenta (const std::string &ime_agenta) const {
    int brojac(0);
    for (int i=0; i<broj_prodaja; i++) {
        if (pokazivac[i]->DajImeAgenta()==ime_agenta)
             brojac++;
    }
    return brojac;
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    auto pok(pokazivac[0]);
    for (int i=0; i<broj_prodaja; i++) {
        if (ProdatPrije(*pokazivac[i], *pok)) pok=pokazivac[i];
    }
    return *pok;
}
Prodaja& Prodaje::DajNajranijuProdaju () {
     auto pok(pokazivac[0]);
     for (int i=0; i<broj_prodaja; i++) {
         if (ProdatPrije(*pokazivac[i],*pok)) pok=pokazivac[i];
     }
     return *pok;
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    auto pok(pokazivac[0]);
    for (int i=0; i<broj_prodaja; i++) {
        if (SkupljiStan(*pokazivac[i], *pok)) pok=pokazivac[i];
    }
    return *pok;
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    auto pok(pokazivac[0]);
    for (int i=0; i<broj_prodaja; i++) {
        if (SkupljiStan(*pokazivac[i], *pok)) pok=pokazivac[i];
    }
    return *pok;
}
void Prodaje::IsprazniKolekciju() {
    for (int i=0; i<broj_prodaja; i++) {
        delete pokazivac[i];
    }
    delete [] pokazivac;
}

void Prodaje::ObrisiNajranijuProdaju() {
    if (broj_prodaja==0) throw std::range_error("Prazna kolekcija");
       
}
int main ()
{
  
	return 0;
}