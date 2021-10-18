/B 2016/2017, Zadaća 4, Zadatak 3
/*
    Napomena: 
        Postovani,
        
        Autor programa je pokusao uskladiti ispis tako da odgovara prvom postavljenom autotestu,
        ali je uocio da postoji par neusaglasenosti sa onim sto bi, po logici programa, trebalo biti ispisano
        (993 umjesto 1993 prilikom ispisa datuma rodjenja kupaca), te zbog kojih uz svo nastojanje ipak nije
        uspio postici da mu prolaze svi javni autotestovi.
        
        Ilma Okanovic
*/
#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <cstdio>

class Datum {
        int dan, mjesec, godina;
    public: 
        Datum (int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
        Datum (const Datum& datum) :
        dan(datum.dan), mjesec(datum.mjesec), godina(datum.godina)
        {}
        void Postavi (int dan, int mjesec, int godina);
        int DajDan () const {return dan;}
        int DajMjesec () const {return mjesec;}
        int DajGodinu () const {return godina;}
        void Ispisi () const {
            std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
        }
};

void Datum::Postavi (int dan, int mjesec, int godina)
{
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if (godina<1 || dan<1 || mjesec <1 || mjesec>12 || dan>broj_dana[mjesec-1])
        throw std::domain_error ("Neispravan datum.");
    Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
}

class Kupac {
        std::string ime_i_prezime;
        Datum datum_rodjenja;
        bool TestIspravnostiImena(std::string ime_i_prezime);
    public:
        Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja):
        datum_rodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()) {
            if(!TestIspravnostiImena(ime_i_prezime))
                throw std::domain_error ("Neispravno ime i prezime.");
            Kupac::ime_i_prezime=ime_i_prezime;
        } 
        void Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja)
        {
            if (!TestIspravnostiImena(ime_i_prezime))
                throw std::domain_error ("Neispravno ime i prezime.");
            Kupac::datum_rodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
            Kupac::ime_i_prezime=ime_i_prezime;
        }
        std::string DajImePrezime () const { return ime_i_prezime; }
        Datum DajDatumRodjenja () const { return datum_rodjenja; }
        void Ispisi() const {
            std::cout<<ime_i_prezime<<" (";
            datum_rodjenja.Ispisi();
            std::cout<<")"<<std::endl;
        }
};

bool Kupac::TestIspravnostiImena (std::string ime_i_prezime)
{
    bool pogresan(false);
    for (char znak: ime_i_prezime)
    {
        if ((znak>='a' && znak<='z') || (znak>='A' && znak<='Z') || (znak>='0' && znak<='9') || znak=='\'' || znak=='-' || znak==' ')
            continue;
        else
        {
            pogresan=true;
            break;
        }
    }
    if(pogresan)
        return false;
    return true;
}

class Stan {
        std::string adresa;
        int sprat;
        int broj_soba;
        bool namjesten;
        double kvadratura;
    public: 
        Stan (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
            Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);   
        }
        Stan (const Stan &stan) :
        adresa(stan.adresa), sprat(stan.sprat), broj_soba(stan.broj_soba), namjesten(stan.namjesten), kvadratura(stan.kvadratura) {}
        void Postavi (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
        std::string DajAdresu () const { return adresa; }
        int DajSprat () const { return sprat; }
        int DajBrojSoba () const { return broj_soba; }
        bool DajNamjesten () const { return namjesten; } 
        double DajKvadraturu () const { return kvadratura; }
        void Ispisi() const;
};

void Stan::Postavi (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
{   
    if (sprat<0 || broj_soba<0 || kvadratura<0)
        throw std::domain_error ("Neispravan unos podataka.");
    Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}

void Stan::Ispisi () const
{
    std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" ";
    if (broj_soba==1)
        std::cout<<"sobu. ";
    else if (broj_soba==2 || broj_soba==3 || broj_soba==4)
        std::cout<<"sobe. ";
    else 
        std::cout<<"soba. ";
    std::cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
    if (namjesten)
        std::cout<<"je namjesten."<<std::endl;
    else
        std::cout<<"nije namjesten."<<std::endl;
}

class Prodaja {
        std::string ime_agenta_prodaje;
        double cijena_stana;
        Datum datum_prodaje;
        Kupac kupac_stana;
        Stan kupljeni_stan;
    public:
        Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, 
        const Kupac &kupac_stana, const Stan &kupljeni_stan) :
        datum_prodaje(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()),
        kupac_stana(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
        kupljeni_stan (kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu()) {
            Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana;   
        }
        
        Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
        int godina_prodaje, const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, 
        int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) :
        datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje),
        kupac_stana(ime_kupca, datum_rodjenja_kupca),
        kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {
            Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana;
        }
        Prodaja (const Prodaja &prodaja) : 
        ime_agenta_prodaje(prodaja.ime_agenta_prodaje), cijena_stana(prodaja.cijena_stana), 
        datum_prodaje(prodaja.datum_prodaje.DajDan(), prodaja.datum_prodaje.DajMjesec(), prodaja.datum_prodaje.DajGodinu()),
        kupac_stana(prodaja.kupac_stana.DajImePrezime(), prodaja.kupac_stana.DajDatumRodjenja()), 
        kupljeni_stan(prodaja.kupljeni_stan.DajAdresu(), prodaja.kupljeni_stan.DajSprat(), prodaja.kupljeni_stan.DajBrojSoba(), prodaja.kupljeni_stan.DajNamjesten(), prodaja.kupljeni_stan.DajKvadraturu())
        {}
        void PromijeniKupca (const Kupac &novi_kupac) {
            kupac_stana.Postavi(novi_kupac.DajImePrezime(), novi_kupac.DajDatumRodjenja());
        }
        void PromijeniStan (const Stan &novi_stan) {
            kupljeni_stan.Postavi(novi_stan.DajAdresu(), novi_stan.DajSprat(), novi_stan.DajBrojSoba(), novi_stan.DajNamjesten(), novi_stan.DajKvadraturu());
        }
        void PromijeniDatumKupovine (const Datum &novi_datum) {
            datum_prodaje.Postavi(novi_datum.DajDan(), novi_datum.DajMjesec(), novi_datum.DajGodinu());
        }
        void PromijeniCijenuProdaje ( const double &nova_cijena) {
            cijena_stana=nova_cijena;
        }
        void PromijeniImeAgenta (const std::string &ime_agenta){
            ime_agenta_prodaje=ime_agenta;
        }
        void PomjeriDanUnaprijed ();
        void PomjeriDanUnazad ();
        std::string DajImeAgenta () const { return ime_agenta_prodaje; }
        std::string DajImeKupca () const { return kupac_stana.DajImePrezime(); };
        Datum DajDatumProdaje () const { return datum_prodaje; }
        double DajCijenuStana () const { return cijena_stana; }
        friend bool ProdatiPrije (const Prodaja &p1, const Prodaja &p2);
        friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2);
        void Ispisi () const;
        friend class Prodaje;
};

void Prodaja::PomjeriDanUnaprijed () {
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int godina(datum_prodaje.DajGodinu()), dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec());
    if ((godina%4==0 && godina%100!=0) && godina%400==0) 
        broj_dana[1]++;
    // Da li treba dodati Postavi tako da se samo dan moze promijeniti 
    dan++;
    if (dan>broj_dana[mjesec-1]) dan=1, mjesec++;
    if (mjesec>12) mjesec=1, godina++;
    datum_prodaje.Postavi(dan, mjesec, godina);
}

void Prodaja::PomjeriDanUnazad() {
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int godina(datum_prodaje.DajGodinu()), dan(datum_prodaje.DajDan()), mjesec(datum_prodaje.DajMjesec());
    if ((godina%4==0 && godina%100!=0) && godina%400==0) 
        broj_dana[1]++;
    dan--;
    if(dan<1) {
        mjesec--;
        if (mjesec<1) mjesec=12, godina--;
        dan=broj_dana[mjesec-1];
    }
    datum_prodaje.Postavi(dan, mjesec, godina);
}

bool ProdatiPrije (const Prodaja &p1, const Prodaja &p2)
{
    //generisao bi se konstruktor
    if (p1.DajDatumProdaje().DajGodinu()<p2.DajDatumProdaje().DajGodinu())
        return true;
    else if (p1.DajDatumProdaje().DajGodinu()==p2.DajDatumProdaje().DajGodinu())
    {
        if (p1.DajDatumProdaje().DajMjesec()<p2.DajDatumProdaje().DajMjesec())
            return true;
        else if (p1.DajDatumProdaje().DajMjesec()==p2.DajDatumProdaje().DajMjesec())
        {
            // ako su isti skroz provjeriti sta treba uciniti u tom slucaju
            if (p1.DajDatumProdaje().DajDan()<=p2.DajDatumProdaje().DajDan())
                return true;
        }
    }
    return false;
}

bool SkupljiStan (const Prodaja &p1, const Prodaja &p2)
{
    //ako su iste cijene???
    if (p1.DajCijenuStana()>=p2.DajCijenuStana())
        return true;
    return false;
}

void Prodaja::Ispisi() const {
    std::cout<<"Ime agenta:                     "<<DajImeAgenta()<<std::endl;
    std::cout<<"Ime kupca:                      ";
    kupac_stana.Ispisi();
    std::cout<<"Zakazani datum prodaje:         ";
    datum_prodaje.Ispisi();
    std::cout<<std::endl;
    std::cout<<"Cijena stana:                   "<<DajCijenuStana()<<std::endl;
    std::cout<<"Informacije o stanu:            "<<std::endl;
    kupljeni_stan.Ispisi();
}

class Prodaje {
        int max_broj_prodaja;
        int broj_registriranih_prodaja;
        // pokazivac na niz pokazivaca na tip Prodaja
        Prodaja **prodaje; 
    public:
        explicit Prodaje (int max_broj_prodaja);
        Prodaje (std::initializer_list<Prodaja> spisak_prodaja);
        ~Prodaje();
        Prodaje (const Prodaje &prodaje);
        Prodaje (Prodaje &&prodaje);
        Prodaje &operator = (const Prodaje &prodaje);
        Prodaje &operator = (Prodaje &&prodaje);
        void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, 
        const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
        void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
        int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
        const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
        void RegistrirajProdaju (Prodaja *prodaja);
        int DajBrojProdaja () const { return broj_registriranih_prodaja; }
        int DajBrojProdajaNaDatum (const Datum &datum) const;
        int DajBrojProdajaOdAgenta (const std::string &ime_agenta) const;
        Prodaja &DajNajranijiuProdaju ();
        Prodaja DajNajranijiuProdaju () const;
        Prodaja &DajNajskupljuProdaju ();
        Prodaja DajNajskupljuProdaju () const;
        Prodaja &DajProdaju (int indeks);
        void IsprazniKolekciju ();
        void ObrisiNajranijuProdaju();
        void ObrisiProdajeAgenta (const std::string &ime_agenta);
        void ObrisiProdajeNaDatum (const Datum &datum);
        void IspisiProdajeNaDatum (const Datum &datum) const;
        void IspisiSveProdaje() const;
        void SortirajProdaje();
        friend class Prodaja;
};

// svrha viticastih zagrada jeste da se svi pokazivaci inicijaliziraju na nullprt
Prodaje::Prodaje (int max_broj_prodaja) : 
    max_broj_prodaja(max_broj_prodaja), broj_registriranih_prodaja(0), prodaje(new Prodaja*[max_broj_prodaja]{}) {}

// sta uraditi za max_broj_prodaja
Prodaje::Prodaje (std::initializer_list<Prodaja> spisak_prodaja) :
broj_registriranih_prodaja(spisak_prodaja.size()), prodaje(new Prodaja*[spisak_prodaja.size()]{}), max_broj_prodaja(spisak_prodaja.size()) 
{
    int i(0);
    try {
        for (auto pok=spisak_prodaja.begin(); pok!=spisak_prodaja.end(); pok++)
        {
            prodaje[i]=new Prodaja(*pok);
            i++;
        }
    }
    catch (...)
    {
        for (int i=0; i<spisak_prodaja.size(); i++)
            delete[] prodaje[i];
        delete[] prodaje;
        throw;
    }
}

Prodaje::~Prodaje ()
{
    for (int i=0; i<broj_registriranih_prodaja; i++)
        delete prodaje[i];
    delete[] prodaje;
}

//poslana prodaja ce biti unistena sa destruktorom same klase Prodaje
Prodaje::Prodaje (const Prodaje &prodaje) :
    prodaje (new Prodaja*[prodaje.max_broj_prodaja]{}), max_broj_prodaja (prodaje.max_broj_prodaja), 
    broj_registriranih_prodaja (prodaje.broj_registriranih_prodaja)
{
    try {
        for (int i=0; i<prodaje.broj_registriranih_prodaja; i++)
            Prodaje::prodaje[i]=new Prodaja(*prodaje.prodaje[i]); //moram promijeniti naziv
    }
    catch (...)
    {
        for (int i=0; i<max_broj_prodaja; i++)
            delete Prodaje::prodaje[i];
        delete[] Prodaje::prodaje;
        throw;
    }
}

// treba samo da "ukrade" podatke od poslanog primjerka klase
Prodaje::Prodaje (Prodaje &&prodaje) :
    prodaje(prodaje.prodaje),
    max_broj_prodaja(prodaje.max_broj_prodaja), broj_registriranih_prodaja(prodaje.broj_registriranih_prodaja)
{
    prodaje.prodaje=nullptr;
    prodaje.broj_registriranih_prodaja=0;
    prodaje.max_broj_prodaja=0;
}

// uz mijenjanje dimenzija u zavisnosti od poslanog primjerka
Prodaje &Prodaje::operator = (const Prodaje &prodaje)
{
    // Da li im kapacitet smije biti razlicit???
    if (prodaje.max_broj_prodaja!=max_broj_prodaja)
        throw std::domain_error("Nesaglasni kapaciteti!");
    if (prodaje.broj_registriranih_prodaja>broj_registriranih_prodaja)
    {
        try{
            for (int i=broj_registriranih_prodaja; i<prodaje.broj_registriranih_prodaja; i++)
                Prodaje::prodaje[i]=new Prodaja(*prodaje.prodaje[i]); //konstruktor za Prodaja se poziva, moguca greska
        }
        catch (...)
        {
            for (int i=broj_registriranih_prodaja; i<prodaje.broj_registriranih_prodaja; i++) {
                delete Prodaje::prodaje[i];
                Prodaje::prodaje[i]=nullptr;
            }
        }
    }
    else {
        for (int i=prodaje.broj_registriranih_prodaja; i<broj_registriranih_prodaja; i++) {
            delete Prodaje::prodaje[i];
            Prodaje::prodaje[i]=nullptr;
        }
    }
    broj_registriranih_prodaja=prodaje.broj_registriranih_prodaja;
    // prekopira ostale clanove
    for (int i=0; i<broj_registriranih_prodaja; i++)
        *Prodaje::prodaje[i]=*prodaje.prodaje[i];
    return *this;
    
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje)
{
    if (prodaje.max_broj_prodaja!=max_broj_prodaja)
        throw std::domain_error("Nesaglasan kapacitet");
    std::swap(broj_registriranih_prodaja, prodaje.broj_registriranih_prodaja);
    std::swap(Prodaje::prodaje, prodaje.prodaje);
    return *this;
}

//ovdje moram popraviti koju poruku treba poslati
void Prodaje::RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, 
    const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) 
{
        if (max_broj_prodaja<broj_registriranih_prodaja+1)
            throw std::domain_error ("Previse registriranih prodaja ili kako vec");
        prodaje[broj_registriranih_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
        broj_registriranih_prodaja++;
        //ovo je uslijedilo na osnovu prvog postavljenog ispisa
        /*std::sort(prodaje, prodaje+broj_registriranih_prodaja, [] (const Prodaja* p1, const Prodaja* p2) 
        {
            if(ProdatiPrije(*p1,*p2))
                return false;
            return true;
        });*/
}

void Prodaje::RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
        int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
        const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    if (max_broj_prodaja<broj_registriranih_prodaja+1)
        throw std::domain_error ("Nedovoljan kapacitet");
    prodaje[broj_registriranih_prodaja]=new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    broj_registriranih_prodaja++;
    /*std::sort(prodaje, prodaje+broj_registriranih_prodaja, [] (const Prodaja* p1, const Prodaja* p2) 
    {
        if(ProdatiPrije(*p1,*p2))
            return false;
        return true;
    })*/
}

void Prodaje::RegistrirajProdaju (Prodaja *prodaja)
{
    if (max_broj_prodaja<broj_registriranih_prodaja+1)
        throw std::domain_error ("Nedovoljan kapacitet");
    prodaje[broj_registriranih_prodaja]=prodaja;
    broj_registriranih_prodaja++;    
    /*std::sort(prodaje, prodaje+broj_registriranih_prodaja, [] (const Prodaja* p1, const Prodaja* p2) 
    {
        if(ProdatiPrije(*p1,*p2))
            return false;
        return true;
    });*/
}

int Prodaje::DajBrojProdajaNaDatum (const Datum &datum) const 
{
    int broji(0);
    broji=std::count_if(prodaje, prodaje+broj_registriranih_prodaja, [datum] (const Prodaja* prodaja) { 
        if ((*prodaja).datum_prodaje.DajDan()==datum.DajDan() && (*prodaja).datum_prodaje.DajMjesec()==datum.DajMjesec() && (*prodaja).datum_prodaje.DajGodinu()==datum.DajGodinu())
            return true;
        return false;
    });
    return broji;
}

int Prodaje::DajBrojProdajaOdAgenta (const std::string &ime_agenta) const 
{
    int broji(0);
    for (int i=0; i<broj_registriranih_prodaja; i++)
        if (prodaje[i]->ime_agenta_prodaje==ime_agenta)
            broji++;
    return broji;
}

Prodaja &Prodaje::DajNajranijiuProdaju ()
{
    if (!broj_registriranih_prodaja)
        throw std::domain_error ("Nema registriranih prodaja");
    return (**(std::min_element(prodaje, prodaje+broj_registriranih_prodaja, [] (const Prodaja* p1, const Prodaja *p2)
    {
        if (ProdatiPrije(*p1,*p2))
            return true;
        return false;
    })));
}

Prodaja Prodaje::DajNajranijiuProdaju () const 
{
    if (!broj_registriranih_prodaja)
        throw std::domain_error ("Nema registriranih prodaja");
    Prodaja najranija (**(std::min_element(prodaje, prodaje+broj_registriranih_prodaja, [] (const Prodaja* p1, const Prodaja *p2)
    {
        if (ProdatiPrije(*p1,*p2))
            return true;
        return false;
    })));
    return najranija;
}

Prodaja &Prodaje::DajNajskupljuProdaju () 
{
    if (!broj_registriranih_prodaja)
        throw std::domain_error ("Nema registriranih prodaja"); 
    return **(std::max_element(prodaje, prodaje+broj_registriranih_prodaja, [] (const Prodaja* p1, const Prodaja* p2) 
    {
        if ((*p1).cijena_stana<(*p2).cijena_stana)
            return true;
        return false;
    }));
}

Prodaja Prodaje::DajNajskupljuProdaju() const 
{
    if (!broj_registriranih_prodaja)
        throw std::domain_error ("Nema registriranih prodaja");
    Prodaja najskuplja(**(std::max_element(prodaje, prodaje+broj_registriranih_prodaja, [] (const Prodaja* p1, const Prodaja* p2) 
    {
        if ((*p1).cijena_stana<(*p2).cijena_stana)
            return true;
        return false;
    })));
    return najskuplja;
}

void Prodaje::IsprazniKolekciju ()
{
    for (int i=0; i<broj_registriranih_prodaja; i++)
    {
        delete[] prodaje[i];
        prodaje[i]=nullptr;
    }
    broj_registriranih_prodaja=0;
}

void Prodaje::ObrisiNajranijuProdaju () 
{
    if (!broj_registriranih_prodaja)
        throw std::range_error ("Prazna kolekcija.");
    Datum pomocni (DajNajranijiuProdaju().DajDatumProdaje());
    for (int i=0; i<broj_registriranih_prodaja; i++)
    {
        if (prodaje[i]->datum_prodaje.DajDan()==pomocni.DajDan() && prodaje[i]->datum_prodaje.DajMjesec()==pomocni.DajMjesec() && prodaje[i]->datum_prodaje.DajGodinu()==pomocni.DajGodinu())
        {
            delete prodaje[i];
            prodaje[i]=nullptr;
        }
    }
    
    Prodaja **nove_prodaje=new Prodaja*[max_broj_prodaja]{};
    int j(0);
    for (int i=0; i<broj_registriranih_prodaja; i++)
    {
        if (prodaje[i]!=nullptr)
        {
            nove_prodaje[j]=new Prodaja (*prodaje[i]);
            j++;
        }
    }
    
    std::swap (nove_prodaje, prodaje);
    for (int i=0; i<broj_registriranih_prodaja; i++)
        delete nove_prodaje[i];
    delete[] nove_prodaje;
    broj_registriranih_prodaja=j;
}

void Prodaje::IspisiSveProdaje () const 
{
    Prodaje nove_prodaje(*this);
    std::sort(nove_prodaje.prodaje, nove_prodaje.prodaje+broj_registriranih_prodaja, [] (const Prodaja *p1, const Prodaja *p2) 
    {
        if(ProdatiPrije(*p1,*p2))
            return false;
        return true;
    });
    std::sort (nove_prodaje.prodaje, nove_prodaje.prodaje+broj_registriranih_prodaja, [] (const Prodaja *p1, const Prodaja *p2)
    {
        if (p1->DajDatumProdaje().DajDan()!=p2->DajDatumProdaje().DajDan() || p1->DajDatumProdaje().DajMjesec()!=p2->DajDatumProdaje().DajMjesec() || p1->DajDatumProdaje().DajGodinu()!=p2->DajDatumProdaje().DajGodinu())
            return true;
        else 
            if (p1->DajImeKupca()<p2->DajImeKupca())
                return true;
        return false;
    });
    for (int i=0; i<broj_registriranih_prodaja; i++)
    {
        nove_prodaje.prodaje[i]->Ispisi();
    }
    
}

void Prodaje::ObrisiProdajeAgenta (const std::string &ime_agenta)
{
    if (!broj_registriranih_prodaja)
        throw std::range_error("Prazna kolekcija.");
    bool obrisan(false);
    for (int i=0; i<broj_registriranih_prodaja; i++)
    {
        if (prodaje[i]->ime_agenta_prodaje==ime_agenta)
        {
            delete prodaje[i];
            prodaje[i]=nullptr;
            obrisan=true;
        }
    }
    if(obrisan)
    {
        Prodaja **nove_prodaje=new Prodaja*[max_broj_prodaja]{};
        int j(0);
        for (int i=0; i<broj_registriranih_prodaja; i++)
        {
            if (prodaje[i]!=nullptr)
            {
                nove_prodaje[j]=new Prodaja (*prodaje[i]);
                j++;
            }
        }
        std::swap (nove_prodaje, prodaje);
        for (int i=0; i<broj_registriranih_prodaja; i++)
            delete nove_prodaje[i];
        delete[] nove_prodaje;
        broj_registriranih_prodaja=j;
    }
}

void Prodaje::ObrisiProdajeNaDatum (const Datum &datum)
{
    if (!broj_registriranih_prodaja)
        throw std::range_error("Prazna kolekcija.");
    bool obrisan(false);
    for (int i=0; i<broj_registriranih_prodaja; i++)
    {
        if (prodaje[i]->datum_prodaje.DajDan()==datum.DajDan() && prodaje[i]->datum_prodaje.DajMjesec()==datum.DajMjesec() && prodaje[i]->datum_prodaje.DajGodinu()==datum.DajGodinu())
        {
            delete prodaje[i];
            prodaje[i]=nullptr;
            obrisan=true;
        }
    }
    if(obrisan)
    {
        Prodaja **nove_prodaje=new Prodaja*[max_broj_prodaja]{};
        int j(0);
        for (int i=0; i<broj_registriranih_prodaja; i++)
        {
            if (prodaje[i]!=nullptr)
            {
                nove_prodaje[j]=new Prodaja (*prodaje[i]);
                j++;
            }
        }
        std::swap (nove_prodaje, prodaje);
        for (int i=0; i<broj_registriranih_prodaja; i++)
            delete nove_prodaje[i];
        delete[] nove_prodaje;
        broj_registriranih_prodaja=j;
    }
}

void Prodaje::IspisiProdajeNaDatum (const Datum &datum) const 
{
    Prodaje prodaje_na_datum (max_broj_prodaja);
    for (int i=0; i<broj_registriranih_prodaja; i++)
    {
        if (prodaje[i]->datum_prodaje.DajDan()==datum.DajDan() && prodaje[i]->datum_prodaje.DajMjesec()==datum.DajMjesec() && prodaje[i]->datum_prodaje.DajGodinu()==datum.DajGodinu())
            prodaje_na_datum.RegistrirajProdaju(new Prodaja(*prodaje[i]));
    }
    prodaje_na_datum.IspisiSveProdaje();
}

Prodaja &Prodaje::DajProdaju (int indeks)
{
    if (indeks>broj_registriranih_prodaja)
        throw std::domain_error ("Neispravan broj prodaje.");
    return *prodaje[indeks-1];
}

void Prodaje::SortirajProdaje() 
{
    std::sort(prodaje, prodaje+broj_registriranih_prodaja, [] (const Prodaja* p1, const Prodaja* p2) 
    {
        if(ProdatiPrije(*p1,*p2))
            return false;
        return true;
    });
}

Datum FormatiraniDatum (std::string datum)
{
    std::string dan_s(datum.substr(0,2)), mjesec_s(datum.substr(3,2)), godina_s(datum.substr(6,4));
    int dan(std::stoi(dan_s, nullptr, 10)), mjesec(std::stoi(mjesec_s, nullptr, 10)), godina(std::stoi(godina_s,nullptr,10));
    Datum pomocni(dan, mjesec, godina);
    return pomocni;
}

int main ()
{
    // o - opcija
    std::cout<<"Dobrodosli!"<<std::endl<<std::endl<<std::endl;
    std::vector<Stan*> stanovi;
    std::vector<Kupac*> kupci;
    Prodaje prodaje(20);
    for (;;)
    {
        int o1;
        std::cout<<"Izaberite opciju:"<<std::endl<<" 0 - kraj"<<std::endl<<" 1 - uredjivanje stanova"<<std::endl<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - uredjivanje prodaja";
        std::cin>>o1;
        
        if(o1==1)
        {
            for (;;)
            {
                int o2;
                std::cout<<std::endl<<"Izaberite opciju:"<<std::endl<<" 0 - nazad"<<std::endl<<" 1 - dodavanje stana"<<std::endl<<" 2 - uredjivanje stanova"<<std::endl<<" 3 - ispis svih stanova";
                std::cout<<std::endl<<" 4 - kraj"<<std::endl;
                std::cin>>o2;
                if (o2==0)
                    break;
                else if (o2==1)
                {
                    for (;;)
                    {
                    try 
                    {
                        std::cin.ignore(1000,'\n');
                        std::string adresa;
                        std::cout<<"Unesite adresu: ";
                        std::getline(std::cin, adresa);
                        int sprat;
                        std::cout<<"Unesite sprat: ";
                        std::cin>>sprat;
                        int broj_soba;
                        std::cout<<"Unesite broj soba: ";
                        std::cin>>broj_soba;
                        int namjesten;
                        std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                        std::cin>>namjesten;
                        double kvadratura;
                        std::cout<<"Unesite kvadraturu: ";
                        std::cin>>kvadratura;
                        if (namjesten!=0 && namjesten!=1)
                        {
                            throw std::domain_error ("Neispravan unos podataka.");
                        }
                        Stan stan(adresa, sprat, broj_soba, namjesten, kvadratura);
                        stanovi.push_back(new Stan(stan));
                        std::cout<<"Stan je uspjesno dodan!"<<std::endl;
                        break;
                    }
                    catch (std::domain_error e)
                    {
                        std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                    }
                }
                }
                else if (o2==2)
                {
                    std::cout<<"Odaberite stan. Dostupni stanovi su:"<<std::endl;
                    for (int i=0; i<stanovi.size(); i++)
                    {
                        std::cout<<" "<<i+1<<" - ";
                        stanovi[i]->Ispisi();
                    }
                    int indeks_stana;
                    std::cin>>indeks_stana;
                    std::cout<<std::endl<<"Odaberite polje koje zelite urediti:"<<std::endl;
                    int polje;
                    std::cout<<" 0 - nazad"<<std::endl<<" 1 - adresa"<<std::endl<<" 2 - sprat"<<std::endl;
                    std::cout<<" 3 - broj soba"<<std::endl<<" 4 - da li je stan namjesten"<<std::endl;
                    std::cout<<" 5 - kvadratura"<<std::endl<<" 6 - sve"<<std::endl;
                    std::cin>>polje;
                    if (polje==0)
                     break;
                    else if (polje==1)
                    {
                        std::string adresa;
                        std::cin.ignore(10000,'\n');
                        std::cout<<"Unesite adresu: ";
                        std::getline(std::cin, adresa);
                        stanovi[indeks_stana-1]->Postavi(adresa, stanovi[indeks_stana-1]->DajSprat(), stanovi[indeks_stana-1]->DajBrojSoba(), stanovi[indeks_stana-1]->DajNamjesten(), stanovi[indeks_stana-1]->DajKvadraturu());
                        std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                        break;
                    }
                    else if (polje==2)
                    {
                        for (;;)
                        {
                            int sprat;
                            std::cout<<"Unesite sprat: ";
                            std::cin>>sprat;
                            try{
                                stanovi[indeks_stana-1]->Postavi(stanovi[indeks_stana-1]->DajAdresu(), sprat, stanovi[indeks_stana-1]->DajBrojSoba(), stanovi[indeks_stana-1]->DajNamjesten(), stanovi[indeks_stana-1]->DajKvadraturu());
                                std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                                break;
                            }
                            catch (std::domain_error e)
                            {
                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            }
                        }
                    }
                    else if (polje==3)
                    {
                        for (;;)
                        {
                            int broj_soba;
                            std::cout<<"Unesite broj soba: ";
                            std::cin>>broj_soba;
                            try{
                                stanovi[indeks_stana-1]->Postavi(stanovi[indeks_stana-1]->DajAdresu(), stanovi[indeks_stana-1]->DajSprat(), broj_soba, stanovi[indeks_stana-1]->DajNamjesten(), stanovi[indeks_stana-1]->DajKvadraturu());
                                std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                                break;
                            }
                            catch (std::domain_error e)
                            {
                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            }
                        }
                    }
                    else if (polje==4)
                    {
                        for (;;)
                        {
                            int namjesten;
                            std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                            std::cin>>namjesten;
                            try 
                            {
                                if (namjesten!=0 && namjesten!=1)
                                    throw std::domain_error ("Pogresan unos podataka.");
                                stanovi[indeks_stana-1]->Postavi(stanovi[indeks_stana-1]->DajAdresu(), stanovi[indeks_stana-1]->DajSprat(), stanovi[indeks_stana-1]->DajBrojSoba(), namjesten, stanovi[indeks_stana-1]->DajKvadraturu());
                                std::cout<<"Stan uspjesno izmijenjen!"<<std::endl;
                                break;
                            }
                            catch (std::domain_error e)
                            {
                                std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                            }
                        }
                    }
                    else if (polje==5)
                    {
                        for (;;)
                        {
                            double kvadratura;
                            std::cout<<"Unesite kvadraturu: ";
                            std::cin>>kvadratura;
                            try{
                                stanovi[indeks_stana-1]->Postavi(stanovi[indeks_stana-1]->DajAdresu(), stanovi[indeks_stana-1]->DajSprat(), stanovi[indeks_stana-1]->DajBrojSoba(), stanovi[indeks_stana-1]->DajNamjesten(), kvadratura);
                                std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                                break;
                            }
                            catch (std::domain_error e)
                            {
                                std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                            }
                                
                        }
                    }
                    else if (polje==6)
                    {
                        std::string adresa;
                        int sprat, broj_soba;
                        int namjesten;
                        double kvadratura;
                        for (;;)
                        {
                            std::cin.ignore(10000,'\n');
                            std::cout<<"Unesite adresu: ";
                            std::getline(std::cin, adresa);
                            std::cout<<"Unesite sprat: ";
                            std::cin>>sprat;
                            std::cout<<"Unesite broj soba: ";
                            std::cin>>broj_soba;
                            std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                            std::cin>>namjesten;
                            std::cout<<"Unesite kvadraturu: ";
                            std::cin>>kvadratura;
                            try{
                                if (namjesten!=0 && namjesten!=1)
                                    throw std::domain_error("Pogresan unos podataka");
                                stanovi[indeks_stana-1]->Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
                                std::cout<<"Stan je uspjesno izmijenjen!"<<std::endl;
                                break;
                            }
                            catch (std::domain_error e)
                            {
                                std::cout<<"Izuzetak: "<<e.what()<<". Molimo unesite opet."<<std::endl;
                            }
                        }
                    }
                }
                else if (o2==3)
                {
                    for (int i=0; i<stanovi.size(); i++)
                    {
                        std::cout<<i+1<<". ";
                        stanovi[i]->Ispisi();
                    }
                }
                else if (o2==4)
                {
                    for (int i=0; i<stanovi.size(); i++)
                        delete stanovi[i];
                    for (int i=0; i<kupci.size(); i++)
                        delete kupci[i];
                    return 0;
                }
            
            }
        }
        else if (o1==2)
        {
            for (;;)
            {
                int o2;
                std::cout<<std::endl<<"Izaberite opciju:"<<std::endl;
                std::cout<<" 0 - nazad"<<std::endl<<" 1 - dodavanje kupca"<<std::endl;
                std::cout<<" 2 - uredjivanje kupaca"<<std::endl<<" 3 - ispis svih kupaca"<<std::endl;
                std::cout<<" 4 - kraj"<<std::endl;
                std::cin>>o2;
                if (o2==0)
                    break;
                else if (o2==1)
                {
                    for (;;)
                    {
                        std::string ime_i_prezime;
                        std::cin.ignore(10000,'\n');
                        std::cout<<"Unesite ime i prezime kupca: ";
                        std::getline(std::cin, ime_i_prezime);
                        try {
                            int dan, mjesec, godina;
                            std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                            fflush( stdout );
                            std::scanf("%2d/%2d/%4d",&dan,&mjesec,&godina);
                            Datum datum_rodjenja(dan, mjesec, godina);
                            kupci.push_back(new Kupac(ime_i_prezime, datum_rodjenja));
                            std::cout<<"Kupac je uspjesno dodan!"<<std::endl;
                            break;
                        }
                        catch (std::domain_error e)
                        {
                            std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                        }
                    }
                }
                else if (o2==2)
                {  
                    std::cout<<"Odaberite kupca kojeg zelite urediti. Dostupni kupci su:"<<std::endl;
                    for (int i=0; i<kupci.size(); i++)
                    {
                        std::cout<<" "<<i+1<<" - ";
                        kupci[i]->Ispisi();
                    }
                    int indeks_kupca;
                    std::cin>>indeks_kupca;
                    for (;;)
                    {
                        std::string ime_i_prezime;
                        std::cin.ignore(10000,'\n');
                        std::cout<<"Unesite ime i prezime kupca: ";
                        std::getline(std::cin, ime_i_prezime);
                        try {
                            std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                            fflush( stdout );
                            int dan, mjesec, godina;
                            std::scanf("%2d/%2d/%4d",&dan,&mjesec,&godina);
                            Datum datum_rodjenja(dan, mjesec, godina);
                            kupci[indeks_kupca-1]->Postavi(ime_i_prezime, datum_rodjenja);
                            std::cout<<"Kupac je uspjesno izmijenjen!"<<std::endl;
                            break;
                        }
                        catch (std::domain_error e)
                        {
                            std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                        }
                    }
                }
                else if (o2==3)
                {
                    for (int i=0; i<kupci.size(); i++)
                        kupci[i]->Ispisi();
                }
                else if (o2==4)
                {
                    //da je velicina 0 nece se ni pokrenuti
                    for (int i=0; i<stanovi.size(); i++)
                        delete stanovi[i];
                    for (int i=0; i<kupci.size(); i++)
                        delete kupci[i];
                    return 0;
                }
            }
        }
        else if (o1==3)
        {
            for (;;)
            {
                std::cout<<std::endl<<"Izaberite opciju:"<<std::endl;
                std::cout<<" 0 - nazad"<<std::endl<<" 1 - dodavanje prodaje"<<std::endl;
                std::cout<<" 2 - uredjivanje prodaje"<<std::endl<<" 3 - ispis prodaja"<<std::endl;
                std::cout<<" 4 - brisanje prodaja"<<std::endl<<" 5 - kraj"<<std::endl;
                int o2;
                std::cin>>o2;
                if (o2==0)
                    break;
                else if (o2==1)
                {
                    for (;;) {
                        int o3;
                        std::cout<<"Izaberite opciju:"<<std::endl;
                        std::cout<<" 0 - nazad"<<std::endl<<" 1 - dodavanje potpuno nove prodaje"<<std::endl;
                        std::cout<<" 2 - dodavanje nove prodaje na osnovu arhive"<<std::endl;
                        std::cout<<" 3 - kraj"<<std::endl;
                        std::cin>>o3;
                        if (o3==0)
                            break;
                        else if (o3==1)
                        {
                            for (;;)
                            {
                                try{
                                    std::string ime_agenta_prodaje;
                                    std::cin.ignore(10000,'\n');
                                    std::cout<<"Unesite ime i prezime agenta prodaje: ";
                                    std::getline(std::cin, ime_agenta_prodaje);
                                    std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                    fflush( stdout );
                                    int dan, mjesec, godina;
                                    std::scanf("%2d/%2d/%4d",&dan,&mjesec,&godina);
                                    Datum datum_prodaje(dan, mjesec, godina);
                                    double cijena_stana;
                                    std::cout<<"Unesite cijenu stana: ";
                                    std::cin>>cijena_stana;
                                    std::string ime_kupca;
                                    std::cin.ignore(1000,'\n');
                                    std::cout<<"Unesite ime kupca: ";
                                    std::getline(std::cin, ime_kupca);
                                    std::cout<<"Unesite datum rodjenja kupca (formata d/m/g): ";
                                    fflush( stdout );
                                    std::scanf("%2d/%2d/%4d",&dan,&mjesec,&godina);
                                    Datum datum_rodjenja(dan, mjesec, godina);
                                    //fflush( stdout );
                                    std::cin.ignore(1000,'\n');
                                    std::string adresa;
                                    std::cout<<"Unesite adresu: ";
                                    std::getline(std::cin, adresa);
                                    int sprat;
                                    std::cout<<"Unesite sprat: ";
                                    std::cin>>sprat;
                                    int broj_soba;
                                    std::cout<<"Unesite broj soba: ";
                                    std::cin>>broj_soba;
                                    int namjesten;
                                    std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                    std::cin>>namjesten;
                                    double kvadratura;
                                    std::cout<<"Unesite kvadraturu: ";
                                    std::cin>>kvadratura;
                                    if (namjesten!=0 && namjesten!=1)
                                        throw std::domain_error("Pogresan unos podataka.");
                                    Kupac kupac_stana (ime_kupca, datum_rodjenja);
                                    kupci.push_back(new Kupac(ime_kupca, datum_rodjenja));
                                    Stan stan (adresa,sprat,broj_soba, namjesten, kvadratura);
                                    stanovi.push_back(new Stan(stan));
                                    prodaje.RegistrirajProdaju(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, stan);
                                    std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
                                    break;
                                }
                                catch (std::domain_error e)
                                {
                                    std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                                }
                            }
                        }
                        else if (o3==2)
                        {
                            for (;;){
                                try{
                                std::string ime_agenta_prodaje;
                                std::cin.ignore(10000,'\n');
                                std::cout<<"Unesite ime i prezime agenta prodaje: ";
                                std::getline(std::cin, ime_agenta_prodaje);
                                std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                fflush( stdout );
                                int dan, mjesec, godina;
                                std::scanf("%2d/%2d/%4d",&dan,&mjesec,&godina);
                                Datum datum_prodaje(dan, mjesec, godina);
                                double cijena_stana;
                                std::cout<<"Unesite cijenu stana: ";
                                std::cin>>cijena_stana;
                                int indeks_kupca;
                                std::cout<<"Odaberite kupca. Dostupni kupci su: "<<std::endl;
                                for (int i=0; i<kupci.size(); i++)
                                {
                                    std::cout<<" "<<i+1<<" - ";
                                    kupci[i]->Ispisi();
                                }   
                                std::cin>>indeks_kupca;
                                int indeks_stana;
                                std::cout<<"Odaberite stan. Dostupni stanovi su: "<<std::endl;
                                for (int i=0; i<stanovi.size(); i++)
                                {
                                    std::cout<<" "<<i+1<<" - ";
                                    stanovi[i]->Ispisi();
                                }
                                std::cin>>indeks_stana;
                                prodaje.RegistrirajProdaju(ime_agenta_prodaje, cijena_stana, datum_prodaje, *kupci[indeks_kupca-1], *stanovi[indeks_stana-1]);
                                std::cout<<"Prodaja uspjesno dodana!"<<std::endl<<std::endl;
                                break;
                                }
                                catch (std::domain_error e)
                                {
                                    std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                                }
                            }
                        }
                        else if (o3==3)
                        {
                            for (int i=0; i<kupci.size(); i++)
                                delete kupci[i];
                            for (int i=0; i<stanovi.size(); i++)
                                delete stanovi[i];
                            return 0;
                        }
                    }
                }
                else if (o2==2)
                {
                    int indeks_prodaje;
                    std::cout<<"Odaberite prodaju koju želite urediti. Dostupne prodaje su:"<<std::endl;
                    for (int i=0; i<prodaje.DajBrojProdaja(); i++)
                    {
                        std::cout<<i+1<<"."<<std::endl;
                        prodaje.DajProdaju(i+1).Ispisi();
                        std::cout<<std::endl;
                    }
                    std::cin>>indeks_prodaje;
                    std::cout<<std::endl<<"Izaberite opciju:"<<std::endl;
                    std::cout<<" 0 - nazad"<<std::endl<<" 1 - izmjena agenta"<<std::endl;
                    std::cout<<" 2 - izmjena datuma prodaje"<<std::endl<<" 3 - izmjena kupca"<<std::endl;
                    std::cout<<" 4 - izmjena stana"<<std::endl<<" 5 - izmjena cijene stana"<<std::endl;
                    int o3;
                    std::cin>>o3;
                    if (o3==0)
                        continue;
                    else if (o3==1)
                    {
                        //ne treba for je nema nikakvih testova za ispravnost imena agenta
                        std::cin.ignore(10000,'\n');
                        std::string ime_agenta;
                        std::cout<<"Unesite ime i prezime agenta prodaje: ";
                        std::getline(std::cin, ime_agenta);
                        prodaje.DajProdaju(indeks_prodaje).PromijeniImeAgenta(ime_agenta);
                        std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                    }
                    else if (o3==2)
                    {
                        for (;;)
                        {
                            try{
                                std::cout<<"Unesite datum prodaje (formata d/m/g): ";
                                fflush( stdout );
                                int dan, mjesec, godina;
                                std::scanf("%2d/%2d/%4d",&dan,&mjesec,&godina);
                                Datum datum_prodaje(dan, mjesec, godina);
                                prodaje.DajProdaju(indeks_prodaje).PromijeniDatumKupovine(datum_prodaje);
                                //takoder nece biti vise potrebna
                                //prodaje.SortirajProdaje();
                                std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                                break;
                            }
                            catch (std::domain_error e)
                            {
                                std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                            }
                        }
                    }
                    else if (o3==3)
                    {
                        int o4;
                        std::cout<<"Izaberite opciju:"<<std::endl;
                        // mislim da je ovdje jedna neusaglasenos sa ispisom autotesta, izgleda kao da nema petlje, ali moze se sa continue
                        std::cout<<" 0 - nazad"<<std::endl<<" 1 - odabir postojeceg kupca"<<std::endl<<" 2 - dodavanje novog kupca"<<std::endl;
                        std::cin>>o4;
                        //if (o4==0)
                          //  continue;
                        if (o4==1)
                        {
                            int indeks_kupca;
                            std::cout<<"Odaberite kupca. Dostupni kupci su:"<<std::endl;
                            for (int i=0; i<kupci.size(); i++)
                            {
                                std::cout<<" "<<i+1<<" - ";
                                kupci[i]->Ispisi();
                            }
                            std::cin>>indeks_kupca;
                            prodaje.DajProdaju(indeks_prodaje).PromijeniKupca(*kupci[indeks_kupca-1]);
                            std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                        }
                        else if (o4==2)
                        {
                            for (;;)
                            {
                                try{
                                    std::cin.ignore(10000,'\n');                                    std::string ime_kupca;
                                    std::cout<<"Unesite ime i prezime kupca: ";
                                    std::getline(std::cin, ime_kupca);
                                    std::cout<<"Unesite datum rodjenja (formata d/m/g): ";
                                    fflush( stdout );
                                    int dan, mjesec, godina;
                                    std::scanf("%2d/%2d/%4d",&dan,&mjesec,&godina);
                                    Datum datum_rodjenja(dan,mjesec,godina);
                                    Kupac kupac(ime_kupca, datum_rodjenja);
                                    kupci.push_back(new Kupac(ime_kupca, datum_rodjenja));
                                    prodaje.DajProdaju(indeks_prodaje).PromijeniKupca(kupac);
                                    std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                                    break;
                                }
                                catch (std::domain_error e)
                                {
                                    std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                                }
                            }
                        }
                    }
                    else if (o3==4)
                    {
                        int o4;
                        std::cout<<"Izaberite opciju: "<<std::endl;
                        std::cout<<" 0 - nazad"<<std::endl<<" 1 - odabir postojeceg stana"<<std::endl;
                        std::cout<<" 2 - dodavanje novog stana"<<std::endl;
                        std::cin>>o4;
                        //if (o4==0)
                          //  continue;
                        if (o4==1)
                        {
                            int indeks_stana;
                            std::cout<<"Odaberite stan. Dostupni stanovi su: "<<std::endl;
                            for (int i=0; i<stanovi.size(); i++)
                            {
                                std::cout<<" "<<i+1<<" - ";
                                stanovi[i]->Ispisi();
                            }
                            std::cin>>indeks_stana;
                               prodaje.DajProdaju(indeks_prodaje).PromijeniStan(*stanovi[indeks_stana-1]);
                               std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                        }
                        else if (o4==2)
                        {
                            for (;;)
                            {
                                try{
                                    std::string adresa;
                                    std::cin.ignore(1000,'\n');
                                    std::cout<<"Unesite adresu: ";
                                    std::getline(std::cin, adresa);
                                    int sprat;
                                    std::cout<<"Unesite sprat: ";
                                    std::cin>>sprat;
                                    int broj_soba;
                                    std::cout<<"Unesite broj soba: ";
                                    std::cin>>broj_soba;
                                    int namjesten;
                                    std::cout<<"Da li je stan namjesten (1 - da, 0 - ne): ";
                                    std::cin>>namjesten;
                                    double kvadratura;
                                    std::cout<<"Unesite kvadraturu: ";
                                    std::cin>>kvadratura;
                                    if (namjesten!=0 && namjesten!=1)
                                        throw std::domain_error("Pogresan unos podataka.");
                                    Stan stan(adresa, sprat, broj_soba, namjesten, kvadratura);
                                    stanovi.push_back(new Stan(adresa, sprat, broj_soba, namjesten, kvadratura));
                                    prodaje.DajProdaju(indeks_prodaje).PromijeniStan(stan);
                                    std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                                    break;
                                }
                                catch (std::domain_error e)
                                {
                                        std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                                }
                            }
                        }
                    }
                    else if (o3==5)
                    {
                        for (;;)
                        {
                            try
                            {
                                double cijena_stana;
                                std::cout<<"Unesite cijenu stana: ";
                                std::cin>>cijena_stana;
                                prodaje.DajProdaju(indeks_prodaje).PromijeniCijenuProdaje(cijena_stana);
                                std::cout<<"Prodaja je uspjesno izmijenjena!"<<std::endl;
                                break;
                            }
                            catch (std::domain_error e)
                            {
                                std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                            }
                        }
                    }
                }
                else if (o2==3)
                {
                    for (;;)
                    {
                        int o3;
                        std::cout<<std::endl<<"Izaberite opciju:"<<std::endl;
                        std::cout<<" 0 - nazad"<<std::endl<<" 1 - ispis svih prodaja"<<std::endl;
                        std::cout<<" 2 - ispis prodaja na datum"<<std::endl<<" 3 - ispis najranije prodaje"<<std::endl;
                        std::cout<<" 4 - ispis najskuplje prodaje"<<std::endl<<" 5 - ispis broja prodaja"<<std::endl;
                        std::cout<<" 6 - ispis broja prodaja po datumu"<<std::endl<<" 7 - ispis broja prodaja po agentu"<<std::endl;
                        std::cout<<" 8 - kraj"<<std::endl;
                        std::cin>>o3;
                        if (o3==0)
                            break;
                        else if (o3==1)
                            prodaje.IspisiSveProdaje();
                        else if (o3==2)
                        {
                            for (;;)
                            {
                                try
                                {
                                    std::cout<<"Unesite datum (d/m/g): ";
                                    fflush( stdout );
                                    int dan, mjesec, godina;
                                    std::scanf("%2d/%2d/%4d",&dan,&mjesec,&godina);
                                    Datum datum(dan,mjesec,godina);
                                    std::cout<<"Prodaje na datum ";
                                    datum.Ispisi();
                                    std::cout<<" su: "<<std::endl;
                                    prodaje.IspisiProdajeNaDatum(datum);
                                    break;
                                }
                                catch (std::domain_error e)
                                {
                                    std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                                }
                            }
                        }
                        else if (o3==3)
                            prodaje.DajNajranijiuProdaju().Ispisi();
                        else if (o3==4)
                            prodaje.DajNajskupljuProdaju().Ispisi();
                        else if (o3==5)
                            std::cout<<"Broj prodaja: "<<prodaje.DajBrojProdaja()<<std::endl;
                        else if (o3==6)
                        {
                            for (;;)
                            {
                                try
                                {
                                    int dan, mjesec, godina;
                                    std::cout<<"Unesite datum (d/m/g): ";
                                    fflush( stdout );
                                    std::scanf("%2d/%2d/%4d",&dan,&mjesec,&godina);
                                    Datum datum(dan,mjesec,godina);
                                    std::cout<<"Broj prodaja na uneseni datum: "<<prodaje.DajBrojProdajaNaDatum(datum)<<std::endl;
                                    break;
                                }
                                catch (std::domain_error e)
                                {
                                    std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                                }
                            }
                        }
                        else if (o3==7)
                        {
                            std::cin.ignore(1000,'\n');
                            std::cout<<"Unesite ime agenta: ";
                            std::string ime_agenta;
                            std::getline(std::cin, ime_agenta);
                            std::cout<<"Broj prodaja: "<<prodaje.DajBrojProdajaOdAgenta(ime_agenta)<<std::endl;
                        }
                        else if (o3==8)
                        {
                            for (int i=0; i<kupci.size(); i++)
                                delete kupci[i];
                            for (int i=0; i<stanovi.size(); i++)
                                delete stanovi[i];
                            return 0;
                        }
                    }
                }
                else if (o2==4)
                {
                    for (;;)
                    {
                        int o3;
                        std::cout<<std::endl<<"Izaberite opciju: "<<std::endl;
                        std::cout<<" 0 - nazad"<<std::endl<<" 1 - brisanje najranije prodaje"<<std::endl<<" 2 - brisanje prodaja agenta"<<std::endl;
                        std::cout<<" 3 - brisanje prodaja po datumu"<<std::endl<<" 4 - brisanje svih podataka"<<std::endl;
                        std::cin>>o3;
                        if (o3==0)
                            break;
                        else if (o3==1)
                        {
                            try {
                                prodaje.ObrisiNajranijuProdaju();
                                std::cout<<"Najranija prodaja je obrisana."<<std::endl;
                            }
                            catch (std::range_error e)
                            {
                                std::cout<<"Izuzetak: "<<e.what()<<std::endl;
                            }
                        }
                        else if (o3==3)
                        {
                            for (;;)
                            {
                                try{
                                int dan,mjesec,godina;
                                std::cout<<"Unesite datum: ";
                                fflush( stdout );
                                std::scanf("%2d/%2d/%4d",&dan,&mjesec,&godina);
                                Datum datum(dan,mjesec,godina);
                                prodaje.ObrisiProdajeNaDatum(datum);
                                std::cout<<"Sve prodaje na taj datum su obrisane."<<std::endl;
                                break;
                                }
                                catch (std::domain_error e)
                                {
                                    std::cout<<"Izuzetak: "<<e.what()<<" Molimo unesite opet."<<std::endl;
                                }
                                catch (std::range_error e)
                                {
                                    std::cout<<"Izuzetak: "<<e.what()<<std::endl;
                                }
                            }
                        }
                        else if (o3==2)
                        {
                            try {
                                std::cin.ignore(1000,'\n');
                                std::string ime_agenta;
                                std::cout<<"Unesite ime agenta: ";
                                std::getline(std::cin, ime_agenta);
                                prodaje.ObrisiProdajeAgenta(ime_agenta);
                                std::cout<<"Sve prodaje tog agenta su obrisane."<<std::endl;
                            }
                            catch (std::range_error e)
                            {
                                std::cout<<"Izuzetak: "<<e.what()<<std::endl;
                            }
                        }
                        else if (o3==4)
                        {
                           prodaje.IsprazniKolekciju();
                           std::cout<<"Sve prodaje su obrisane."<<std::endl;
                        }
                    }
                }
                else if (o2==5)
                {
                    for (int i=0; i<stanovi.size(); i++)
                        delete stanovi[i];
                    for (int i=0; i<kupci.size(); i++)
                        delete kupci[i];
                    return 0;
                }
            }
        }
        else if (o1==0)
        {
            std::cout<<std::endl<<std::endl<<std::endl<<"Dovidjenja!"<<std::endl;
            break;
        }
    }
    for (int i=0; i<stanovi.size(); i++)
        delete stanovi[i];
    for (int i=0; i<kupci.size(); i++)
        delete kupci[i];
        
    /*std::string proba;
    std::cin>>proba;
    Datum datum (FormatiraniDatum(proba));
    datum.Ispisi();*/
	return 0;
}