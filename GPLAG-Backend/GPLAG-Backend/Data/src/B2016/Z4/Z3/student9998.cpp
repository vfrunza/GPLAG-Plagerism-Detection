#include <iostream>

class Datum{
    int dan, mjesec, godina;
    
    public:
    Datum(int dan, int mjesec, int godina){
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina){
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    int DajDan() const {return dan;}
    int DajMjesec() const {return mjesec;}
    int DajGodinu() const {return godina;}
    void Ispisi() const {std::cout<<dan<<"/"<<mj<<"/"<<god;};
};

class Kupac{
   std::string ime_prezime;
   Datum dat;
   public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        //izuzetak
        Kupac::ime_prezima=ime_i_prezime;
        Kupac::dat.dan=datum_rodjenja.dan; Kupac::dat.mj=datum_rodjenja.mj; Kupac::dat.god=datum_rodjenja.god;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        //izuzetak
        Kupac::ime_prezima=ime_i_prezime;
        Kupac::dat.dan=datum_rodjenja.dan; Kupac::dat.mj=datum_rodjenja.mj; Kupac::dat.god=datum_rodjenja.god;
    }
    std::string DajImePrezime() const{return ime_prezime;}
    Datum DajDatumRodjenja() const{return dat;}
    void Ispisi() const {
    std::cout<<DajImePrezime()<<" ("<<DajDatumRodjenja<<")";}
};

class Stan{
   std::string adresa;
   int sprat, soba, kvadratura;
   bool namjesten;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        Stan::adresa=adresa;
        Stan::sprat=sprat;
        Stan::soba=broj_soba;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        Stan::adresa=adresa;
        Stan::sprat=sprat;
        Stan::soba=broj_soba;
        Stan::namjesten=namjesten;
        Stan::kvadratura=kvadratura;
    }
    std::string DajAdresu() const {return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const {return soba;}
    bool DajNamjesten() const {return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const{
    std::cout<<"Stan se nalazi na adresi "<<adresa<<" na <<sprat<<" spratu i ima "<<broj_soba <<" soba. Kvadratura stana je "<<kvadratura <<" i stan je_ili_nije "<<namjesten;
    }
};


class Prodaja{
    Datum dat;
    Stan stan;
    Kupac kup;

    public:
        Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
        Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
        void PromijeniKupca (const Kupac &novi_kupac);
        void PromijeniStan (const Stan &novi_stan);
        void PromijeniDatumKupovine (const Datum &novi_datum);
        void PromijeniCijenuProdaje (const double &nova_cijena);
        void PomjeriDanUnaprijed();
        void PomjeriDanUnazad();
        std::string DajImeAgenta() const;
        std::string DajImeKupca() const;
        Datum DajDatumProdaje() const;
        double DajCijenuStana() const;
        friend bool ProdatPrije (const Prodaja &p1, const Prodaja &p2);
        friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2);
        void Ispisi() const;
        explicit Prodaje(int max_broj_prodaja);
    Prodaje (std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje (const Prodaje &prodaje);
    Prodaje (Prodaje &&prodaje);
    Prodaje &operator = (const Prodaje &prodaje);
    Prodaje &operator = (Prodaje &&prodaje);
    void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stn &kupljeni_stan);
    void RegistrirajProdaju (const std::string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju (Prodaja *prodaja);
    int DajBrojProdaja() const;
    int DajBrojProdajaNaDatum (const Datum &datum) const;
    int DajBrojProdajaOdAgenta (const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta (const std::string &ime_agenta);void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum (const Datum &datum) const;
    void IspisiSveProdaje() const;
};



int main ()
{
	return 0;
}