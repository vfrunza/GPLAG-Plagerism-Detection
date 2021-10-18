#include <iostream>
#include <stdexcept>
#include <cmath>

class Datum {
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina) {
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    int DajDan() const {
        return dan;
    }
    int DajMjesec() const {
        return mjesec;
    }
    int DajGodinu() const {
        return godina;
    }
    void Ispisi() const {
        std::cout << DajDan() << "/" << DajMjesec() << "/" << DajGodinu();
    }
}; 

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja)
         : ime_i_prezime(ime_i_prezime), datum_rodjenja(datum_rodjenja) {}
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
        Kupac::ime_i_prezime = ime_i_prezime;
        Kupac::datum_rodjenja = datum_rodjenja;
    }
    
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const {
        return datum_rodjenja;
    }
    void Ispisi() const {
        std::cout << DajImePrezime() << " ("; datum_rodjenja.Ispisi(); std::cout << ")";
    }
  
};


class Stan {
    std::string adresa;
    int sprat; 
    int broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if(sprat < 0 || broj_soba < 0 || kvadratura < 0)
            throw std::domain_error("Neispravan unos podataka");
        Stan::adresa = adresa;
        Stan::sprat = sprat;
        Stan::broj_soba = broj_soba;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
    }
    std::string DajAdresu() const {
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
    void Ispisi() const {
        if(DajBrojSoba() >= 1 && DajBrojSoba() <= 4) 
            std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " sobe.";
        else 
            std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba() << " soba.";
        if(DajNamjesten())
            std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan je namjesten.";
        else 
            std::cout << "Kvadratura stana je " << DajKvadraturu() << " (m^2) i stan nije namjesten.";
    }
};

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
        const Kupac &kupac_stana, const Stan &kupljeni_stan)
    : ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(datum_prodaje), 
    kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {} 
    
    void PromijeniStan(const Stan &novi_stan) {
        kupljeni_stan = novi_stan;
    }
    void PromijeniDatumKupovine(const Datum &novi_datum) {
        datum_prodaje = novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        cijena_stana = nova_cijena;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const {
        return ime_agenta_prodaje;
    }
    std::string DajImeKupca() const {
        return kupac_stana.DajImePrezime();
    }
    Datum DajDatumProdaje() const {
        return datum_prodaje;
    }
    double DajCijenuStana() const {
        return cijena_stana;
    }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
    

};

void Prodaja::Ispisi() const {
    std::cout << "Ime agenta: " << DajImeAgenta() << "\n";
    std::cout << "Ime kupca: " << DajImeKupca() << "\n";
    std::cout << "Zakazani datum prodaje: "; datum_prodaje.Ispisi();
    std::cout << "\nCijena stana: " << DajCijenuStana();
    std::cout << "\nInformacije o stanu: \n";
    kupljeni_stan.Ispisi();
}



int main ()
{
	return 0;
}



/*

RUZNI KONSTRUKTOR!! 

    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, 
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje, 
    const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, 
    const std::string &adresa_stana, int sprat_stana, int broj_soba, 
    bool namjesten_stan, double broj_kvadrata) {
        Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
        Prodaja::cijena_stana = cijena_stana;
        //datum_prodaje.Postavi(dan_prodaje, mjesec_prodaje, godina_prodaje);
        //kupac_stana.Postavi(ime_kupca, datum_rodjenja_kupca);
        //kupljeni_stan.Postavi(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    }
    
*/
    
    