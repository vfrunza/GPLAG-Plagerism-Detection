#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>

class Datum {
    int dan, mjesec, godina;
public:
    Datum () {};
    Datum (int d, int m, int g) { Postavi(d, m, g); }
    void Postavi (int d, int m, int g);
    int DajDan () const { return dan; }
    int DajMjesec () const { return mjesec; }
    int DajGodinu () const { return godina; }
    void Ispisi () const { std::cout << dan << "/" << mjesec << "/" << godina; }
    friend class Kupac;
};
void Datum::Postavi (int d, int m, int g) {
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (g%4==0 && (g%100!=0 || g%400==0) ) broj_dana[1]++;
    if (d < 1 || m < 1 || g < 1 || m > 12 || d > broj_dana[m-1]) {
        throw std::domain_error ("Neispravan datum");
    }
    dan=d; mjesec=m; godina=g;
}
class Kupac {
   std::string ime_prezime;
   Datum datum_rodjenja;
public:
   Kupac (const std::string &ime, const Datum &dat)  {
    datum_rodjenja.dan=dat.DajDan(); datum_rodjenja.mjesec=dat.DajMjesec(); datum_rodjenja.godina=dat.DajGodinu();
    ime_prezime=ime;
   }
   void Postavi (const std::string &ime, const Datum &dat);
   std::string DajImePrezime () const { return ime_prezime; }
   Datum DajDatumRodjenja () const { return datum_rodjenja; }
   void Ispisi () const { std::cout << ime_prezime << " ("; datum_rodjenja.Ispisi(); std::cout<<")"; }
};
void Kupac::Postavi (const std::string &ime, const Datum &dat) {
    /*int broj_dana[12] {31, 28, 31, 30, 31 ,30, 31, 31, 30, 31, 30, 31};
    if (g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
    if (d<1 || g<1 || m<1 || m>12 || d>broj_dana[m-1]) {
        throw std::domain_error ("Neispravan datum");
    }*/
    for (int i=0; i<ime.length(); i++) {
        if (!((toupper (ime[i])>='A' && toupper (ime[i])<='Z') || (ime[i]>=1 && ime[i]<=9) || ime[i]=='-' || ime[i]==39 )) {
            throw std::domain_error ("Nesipravno ime i prezime");
        }
    }
    ime_prezime=ime;
    datum_rodjenja.dan=dat.DajDan(); datum_rodjenja.mjesec=dat.DajMjesec(); datum_rodjenja.godina=dat.DajGodinu();
}
class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan (const std::string &adr, int spr, int br_s, bool namj, double kvad) { Postavi (adr, spr, br_s, namj, kvad); }
    void Postavi(const std::string &adr, int spr, int br_s, bool namj, double kvad);
    std::string DajAdresu () const { return adresa; }
    int DajSprat () const {return sprat;}
    int DajBrojSoba () const { return broj_soba; }
    bool DajNamjesten () const { if (namjesten) return true; if (namjesten==false) return false; }
    double DajKvadraturu () const { return kvadratura; }
    void Ispisi () const {
        std::string s="";
        if (broj_soba==1) s="u";
        else if (broj_soba==2 || broj_soba==3 || broj_soba==4) s="e";
        else s="a";
        std::string s1="";
        if (namjesten) s1="je";
        else s1="nije";
        std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sob" <<s <<". Kvadratura stana je " << DajKvadraturu()<<" (m^2) i stan "<<s1<<" namjesten";
    }
    
    
};
void Stan::Postavi (const std::string &adr, int spr, int br_s, bool namj, double kvad) {
    if (spr < 0 || br_s < 0 || kvad < 0) {
        throw std::domain_error ("Neispravan unos podataka");
    }
    adresa=adr;
    sprat=spr;
    broj_soba=br_s;
    kvadratura=kvad;
    namjesten=namj;
}
class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    int dan_prodaje, mjesec_prodaje, godina_prodaje;
    Kupac ime_kupca;
    Datum datum_rodjenja_kupca;
    std::string adresa_stana;
    int sprat_stana, broj_soba;
    bool namjesten_stan;
    double broj_kvadrata;
public:
    Prodaja (const std::string &ime_agenta, double cijena, const Datum &datum_pr, const Kupac &kupac, const Stan &kupljeni) {
        ime_agenta_prodaje=ime_agenta; cijena_stana=cijena; datum_prodaje.dan=datum_pr.DajDan(); datum_prodaje.mjesec=datum_pr.DajMjesec(); datum_prodaje.godina=datum_pr.DajGodinu(); 
    }
    Prodaja (const std::string &ime_agenta, double cijena, int dan_pr, int mjesec_pr, int godina_pr, std::string &ime_ku, const Datum &datum_rodjenja, const std::string &adresa, int sprat_st, int br_so, bool namjesten_st, double br_kvad) {
        
    }
    void PromijeniKupca (const Kupac &novi_kupac) { kupac_stana=novi_kupac; }
    void PromijeniStan (const Stan &novi_stan) { kupljeni_stan=novi_stan; }
    void PromijeniDatumKupovine (const Datum &novi_datum) { datum_prodaje=novi_datum; }
    void PromijeniCijenuProdaje (const double &nova_cijena) { cijena_stana=nova_cijena;}
    void PomjeriDanUnaprijed () { dan_prodaje++; }
    void PomjeriDanUnazad () {dan_prodaje--; }
    std::string DajImeAgenta () const { return ime_agenta_prodaje; }
    std::string DajImeKupca () const { return kupac_stana.DajImePrezime(); }
    Datum DajDatumProdaje () const { return datum_prodaje; }
    double DajCijenuStana () const { return cijena_stana; }
    friend bool ProdatPrije (const Prodaja &p1, const Prodaja &p2) {
        if (p1.datum_prodaje<p2.datum_prodaje) return true;
        else return false;
    }
    friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2) {
        if (p1.cijena_stana<p2.cijena_stana) return true;
        else return false;
    }
    void Ispisi() const {
        std::cout << "Ime agenta:" << std::right << ime_agenta_prodaje<< std::endl <<"Ime kupca:"<<std::right <<ime_kupca <<" ("<<datum_rodjenja_kupca.DajDan()<<"/"<<datum_rodjenja_kupca.DajMjesec()<<"/"<<datum_rodjenja_kupca.DajGodinu()<<")"<<std::endl<<
        "Zakazani datum prodaje:"<<std::right<<datum_prodaje.DajDan()<<"/"<<datum_prodaje.DajMjesec()<<"/"<<datum_prodaje.DajGodinu()<<std::endl<<"Cijena stana:"<<std::right<<cijena_stana<<std::endl<<
        "Informacije o stanu:"<<std::endl<<"Stan se nalazi na adresi " << adresa_stana << " na " << sprat_stana << ". spratu i ima " << broj_soba << " sob" <<s <<"."<<std::endl<<"Kvadratura stana je " << broj_kvadrata<<" (m^2) i stan "<<s1<<" namjesten.";
        
    }
    
};

int main ()
{
    try {
        Stan stan (Hamdije Cemerlica, 4, 2, false, 35 );
      
        
        stan.Ispisi();
    }
    catch (std::domain_error izuzetak) {
        std::cout << izuzetak.what();
    }
	return 0;
}