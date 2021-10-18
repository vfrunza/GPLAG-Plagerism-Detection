/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>

class Datum{
    int dan, mjesec, godina;
    public: 
    Datum(int datum, int mjesec, int godina){Postavi(dan,mjesec,godina);}
    void Postavi(int dan, int mjesec, int godina){
        int broj_dana[]{31, 28, 31, 30, 31, 31, 30, 31, 30, 31};
        if((godina %4==0 && godina%100!=0 )|| godina%400==0) broj_dana[1]++;
        if(godina<1  || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum!");
        Datum::dan=dan; Datum::mjesec=mjesec; Datum::godina=godina;
    }
    int DajDan() const{return dan;}
    int DajMjesec() const{return mjesec;}
    int DajGodinu() const{return godina;}
    void Ispisi() const{std::cout<<dan<<"/"<<mjesec<<"/"<<godina;}
};

class Kupac{
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
        for(auto c: ime_i_prezime) 
            if(!(c>='0' && c<='9') && !(c>='A' && c<='Z') && !(c>='a' && c<='z') && c!=' ' && c!='-' && c!=39)
            throw std::domain_error("Neispravno ime i prezime");
        Kupac::ime_i_prezime=ime_i_prezime; Kupac::datum_rodjenja=datum_rodjenja;
    }
    std::string DajImePrezime() const{return ime_i_prezime;}
    Datum DajDatumRodjenja() const{return datum_rodjenja;}
    void Ispisi() const {std::cout<<ime_i_prezime<<"(";
    datum_rodjenja.Ispisi();
    std::cout<<")";}
};

class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        if (sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error("Neispravan unos podataka");
        Stan::adresa=adresa; Stan::sprat=sprat; Stan::broj_soba=broj_soba; Stan::namjesten=namjesten;Stan::kvadratura=kvadratura;
    }
    std::string DajAdresu() const {return adresa;}
    int DajSprat() const{return sprat;}
    int DajBrojSoba() const{return broj_soba;}
    bool DajNamjesten() const{return namjesten;}
    double DajKvadraturu() const{return kvadratura;}
    void Ispisi() const {
        std::cout<<"Stan se nalazi na adresi "<<adresa<<" na "<<sprat<<". spratu i ima "<<broj_soba<<" soba."<<std::endl;
        std::cout<<"Kvadratura stana je "<<kvadratura<<" (m^2) i stan ";
        if(!namjesten) std::cout<<"ni";
        std::cout<<"je namjesten.";
    }
};

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
    datum_prodaje(datum_prodaje), kupac_stana(kupac_stana),kupljeni_stan(kupljeni_stan){
        Prodaja::cijena_stana=cijena_stana; Prodaja::ime_agenta_prodaje=ime_agenta_prodaje;
        Prodaja::kupac_stana=kupac_stana; Prodaja::datum_prodaje=datum_prodaje;
        Prodaja::kupljeni_stan=kupljeni_stan;
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, 
    bool namjesten_stan, double broj_kvadrata): datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),
    kupac_stana(ime_kupca,datum_rodjenja_kupca), kupljeni_stan(adresa_stana,sprat_stana, broj_soba, namjesten_stan, broj_kvadrata){
        Prodaja::ime_agenta_prodaje=ime_agenta_prodaje; Prodaja::cijena_stana=cijena_stana;
        datum_prodaje.Postavi(dan_prodaje,mjesec_prodaje,godina_prodaje);
        kupljeni_stan.Postavi(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata);
        kupac_stana.Postavi(ime_kupca,datum_rodjenja_kupca);
    }
    void PromijeniKupca(const Kupac &novi_kupac) {kupac_stana=novi_kupac;}
    void PromijeniStan(const Stan &novi_stan) {kupljeni_stan=novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum) {datum_prodaje=novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena) {cijena_stana=nova_cijena;}
    void PomjeriDanUnaprijed(){
        int d(datum_prodaje.DajDan()), m(datum_prodaje.DajMjesec()), g(datum_prodaje.DajGodinu());
        int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0)|| g%400==0) broj_dana[1]++;
        d++;
        if(d>broj_dana[m-1]) {
            d=1;
            m++;
        }
        if(m>12){
            m=1;
            g++;
        }
        datum_prodaje.Postavi(d,m,g);
    }
    void PomjeriDanUnazad(){
        int d(datum_prodaje.DajDan()), m(datum_prodaje.DajMjesec()), g(datum_prodaje.DajGodinu());
        int broj_dana[]{31,28,31,30,31,30,31,31,30,31,30,31};
        if((g%4==0 && g%100!=0) || g%400==0) broj_dana[1]++;
        d--;
        if(d<1) {
            m--;
            if(m<0){
                m=12;
                g--;
            }
            d=broj_dana[m-1];
        }
        datum_prodaje.Postavi(d,m,g);
    }
    std::string DajImeAgenta() const {return ime_agenta_prodaje;}
    std::string DajImeKupca() const {return kupac_stana.DajImePrezime();}
    Datum DajDatumProdaje() const{return datum_prodaje;}
    double DajCijenuStana() const {return cijena_stana;}
    friend bool ProdatPrije (const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const{
        std::cout<<std::setw(30)<<"Ime agenta:"<<ime_agenta_prodaje<<std::endl
        <<std::setw(30)<<"Ime kupca:";
        kupac_stana.Ispisi();
        std::cout<<std::endl<<std::setw(30)<<"Zakazani datum prodaje: ";
        datum_prodaje.Ispisi();
        std::cout<<std::endl<<std::setw(30)<<"Cijena stana: "<<cijena_stana<<std::endl
        <<"Informacije o stanu:"<<std::endl;
        kupljeni_stan.Ispisi();
    }
    
};

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    Datum dat1(p1.DajDatumProdaje()), dat2(p2.DajDatumProdaje());
    if(dat2.DajGodinu()>dat1.DajGodinu()) return true;
    if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()<dat2.DajMjesec()) return true;
    if(dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajDan()<dat2.DajDan()) return true;
    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    if(p1.DajCijenuStana()<p2.DajCijenuStana()) return true;
    return false;
}

class Prodaje{
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer:list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje (Prodaje &&prodaje);
    Prodaje &operator = (const Prodaje &prodaje);
    Prodaje &operator = (Prodaje &&prodaje);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
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