/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Datum{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina): dan(dan), mjesec(mjesec), godina(godina) {} //ispravnost domain_error
    void Postavi(int dan, int mjesec, int godina){ //ispravnost domain_error
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    int DajDan() const { return dan;}
    int DajMjesec() const{ return mjesec;}
    int DajGodinu() const{ return godina;}
    void Ispisi() const{
        std::cout<<dan<<"."<<mjesec<<"."<<godina<<".";
    }
};

class Kupac{
    std::string ime_prezime;
    Datum date_birth;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): ime_prezime(ime_i_prezime), date_birth(datum_rodjenja) {}//ispravnost domain_error
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){ //ispravnost domain_error
        ime_prezime = ime_i_prezime;
        date_birth = datum_rodjenja;
    }
    std::string DajImePrezime() const{ return ime_prezime; }
    Datum DajDatumRodjenja() const{ return date_birth; }
    void Ispisi() const{
        std::cout<<ime_prezime;
        date_birth.Ispisi();
    }
};

class Stan{
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
public:
    // domain_error nekakav
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura): adresa(adresa), sprat(sprat), broj_soba(broj_soba), namjesten(namjesten), kvadratura(kvadratura){}
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        Stan::adresa = adresa; // domain_error nekakav
        Stan::sprat = sprat;
        Stan::broj_soba = broj_soba;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
    }
    std::string DajAdresu() const{ return adresa; }
    int DajSprat() const{ return sprat; }
    int DajBrojSoba() const{ return broj_soba; }
    bool DajNamjesten() const{ return namjesten; }
    double DajKvadraturu() const{ return kvadratura; }
    void Ispisi() const{
        //ti ispis sve redom
    }

};

int main ()
{
	return 0;
}