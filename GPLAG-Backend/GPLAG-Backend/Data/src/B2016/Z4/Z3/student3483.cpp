/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>

class Datum{
    int d, m,g;
public:
    Datum(int dan, int mjesec, int godina)
    {
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina%4 == 0 && godina%100 != 0) || godina%400 == 0)
            broj_dana[1]++;
        if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
            throw std::domain_error("Neispravan datum");
        d = dan; m = mjesec; g = godina;
    }
    void Postavi(int dan, int mjesec, int godina)
    {
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina%4 == 0 && godina%100 != 0) || godina%400 == 0)
            broj_dana[1]++;
        if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
            throw std::domain_error("Neispravan datum");
        d = dan; m = mjesec; g = godina;
    }
    int DajDan() const {return d;}
    int DajMjesec() const {return m;}
    int DajGodinu() const {return g;}
    void Ispisi() const {std::cout<<d<<"/"<<m<<"/"<<g;}
};

class Kupac{
    std::string iip;
    Datum datum;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum(datum_rodjenja)
    {
        for(int i = 0; i < ime_i_prezime.size(); i++)
            if((i<'a' || i>'z') && (i<'A' || i>'Z') && (i<'0' || i>'9') && i!=' ' && i!='-' && i!=39)
                throw std::domain_error("Neispravno ime i prezime");
        iip = ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
    {
        for(int i = 0; i < ime_i_prezime.size(); i++)
            if((i<'a' || i>'z') && (i<'A' || i>'Z') && (i<'0' || i>'9') && i!=' ' && i!='-' && i!=39)
                throw std::domain_error("Neispravno ime i prezime");
        iip = ime_i_prezime;
        datum = datum_rodjenja;
    }
    std::string DajImePrezime() const {return iip;}
    Datum DajDatumRodjenja() const {return datum;}
    void Ispisi() const {std::cout<<iip<<"("; datum.Ispisi(); std::cout<<")";};
};

class Stan{
    std::string Adresa;
    int  Sprat, Broj_soba;
    bool Namjesten;
    double Kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
    {
        if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
            throw std::domain_error("Neispravan unos podataka");
        Adresa = adresa;
        Sprat = sprat;
        Broj_soba = broj_soba;
        Namjesten = namjesten;
        Kvadratura = kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura)
    {
        if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
            throw std::domain_error("Neispravan unos podataka");
        Adresa = adresa;
        Sprat = sprat;
        Broj_soba = broj_soba;
        Namjesten = namjesten;
        Kvadratura = kvadratura;
    }
    std::string DajAdresu() const {return Adresa;}
    int DajSprat() const {return Sprat;}
    int DajBrojSoba() const {return Broj_soba;}
    bool DajNamjesten() const {return Namjesten;}
    double DajKvadraturu() const {return Kvadratura;}
    void Ispisi() const 
    {
        std::cout<<"Stan se nalazi na adresi "<<Adresa<<" na "<<Sprat<<". spratu i ima "<<Broj_soba<<".";
        if(Broj_soba >= 10 && Broj_soba <= 20)
            std::cout<<" soba";
        else if(Broj_soba%10 == 2 || Broj_soba%10 == 3 || Broj_soba%10 == 4)
            std::cout<<" sobe";
        else
            std::cout<<" soba";
        if(Namjesten == true)
            std::cout<<"je namjesten";
        else
            std::cout<<"nije namjesten";
    }
};

class Prodaja{
    std::string iap;
    double Cijena_stana;
    Datum Datum_prodaje;
    Kupac Kupac_stana;
    Stan Kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, 
        const Stan &kupljeni_stan) : Datum_prodaje(datum_prodaje), Kupac_stana(kupac_stana), Kupljeni_stan(kupljeni_stan)
    {
        iap = ime_agenta_prodaje;
        Cijena_stana = cijena_stana;
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, 
        std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, 
        bool namjesten_stan, double broj_kvadrata) : Datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), 
        Kupac_stana(ime_kupca, Datum(dan_prodaje, mjesec_prodaje, godina_prodaje)), Kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata)
    {
        iap = ime_agenta_prodaje;
        Cijena_stana = cijena_stana;
    }
    void PromijeniKupca(const Kupac &novi_kupac) {Kupac_stana = novi_kupac;}
    void PromijeniStan(const Stan &novi_stan) {Kupljeni_stan = novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum) {Datum_prodaje = novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena) {Cijena_stana = nova_cijena;}
    void PomjeriDanUnaprijed() 
    {
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((Datum_prodaje.DajGodinu()%4 == 0 && Datum_prodaje.DajGodinu()%100 != 0) || Datum_prodaje.DajGodinu()%400 == 0)
            broj_dana[1]++;
        Datum_prodaje.Postavi(Datum_prodaje.DajDan()+1, Datum_prodaje.DajMjesec(), Datum_prodaje.DajGodinu());
        if(Datum_prodaje.DajDan() > broj_dana[Datum_prodaje.DajMjesec()-1])
            Datum_prodaje.Postavi(1, Datum_prodaje.DajMjesec()+1, Datum_prodaje.DajGodinu());
        if(Datum_prodaje.DajMjesec() > 12)
            Datum_prodaje.Postavi(Datum_prodaje.DajDan(), 1, Datum_prodaje.DajGodinu()+1);
    }
    void PomjeriDanUnazad()
    {
        int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if((Datum_prodaje.DajGodinu()%4 == 0 && Datum_prodaje.DajGodinu()%100 != 0) || Datum_prodaje.DajGodinu()%400 == 0)
            broj_dana[1]++;
        Datum_prodaje.Postavi(Datum_prodaje.DajDan()-1, Datum_prodaje.DajMjesec(), Datum_prodaje.DajGodinu());
        if(Datum_prodaje.DajDan() < 1)
            Datum_prodaje.Postavi(broj_dana[Datum_prodaje.DajMjesec()-2], Datum_prodaje.DajMjesec()-1, Datum_prodaje.DajGodinu());
        if(Datum_prodaje.DajMjesec() < 1)
            Datum_prodaje.Postavi(Datum_prodaje.DajDan(), 12, Datum_prodaje.DajGodinu()-1);
    }
    std::string DajImeAgenta() const {return iap;}
    std::string DajImeKupca() const {return Kupac_stana.DajImePrezime();}
    Datum DajDatumProdaje() const {return Datum_prodaje;}
    double DajCijenuStana() const {return Cijena_stana;}
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const
    {
        std::cout<<"Ime agenta: "<<iap<<std::endl;
        std::cout<<"Ime kupca: ";
        Kupac_stana.Ispisi();
        std::cout<<std::endl;
        std::cout<<"Zakatani datum prodaje: ";
        Datum_prodaje.Ispisi();
        std::cout<<std::endl;
        std::cout<<"Cijena stana: "<<Cijena_stana<<std::endl;
        std::cout<<"Informacije o stanu: "<<std::endl;
        Kupljeni_stan.Ispisi();
    }
};

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.DajDatumProdaje().DajGodinu() < p2.DajDatumProdaje().DajGodinu())
        return true;
    if(p1.DajDatumProdaje().DajGodinu() == p2.DajDatumProdaje().DajGodinu() && p1.DajDatumProdaje().DajMjesec() < p2.DajDatumProdaje().DajMjesec())
        return true;
    if(p1.DajDatumProdaje().DajGodinu() == p2.DajDatumProdaje().DajGodinu() && p1.DajDatumProdaje().DajMjesec() == p2.DajDatumProdaje().DajMjesec() && p1.DajDatumProdaje().DajDan() < p2.DajDatumProdaje().DajDan())
        return true;
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    if(p1.DajCijenuStana() > p2.DajCijenuStana())
        return true;
    return false;
}

class Prodaje{
   GradjaninBiH *prodaje[100];
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
    const Stn &kupljeni_stan);
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
	return 0;
}