#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <string>

class Datum {
    int d, m, g;
public:
    Datum (int dan, int mjesec, int godina) {
        Postavi(dan, mjesec, godina);
    }
    void Postavi (int dan, int mjesec, int godina) {
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
        if (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
            throw std::domain_error("Neispravan datum");
        d = dan; m = mjesec; g = godina;
    }
    int DajDan() const {return d;}
    int DajMjesec() const {return m;}
    int DajGodinu() const {return g;}
    void Ispisi() const {
        std::cout << DajDan() << "/" << DajMjesec() << "/" << DajGodinu();
    }
};

class Kupac {
    std::string name_surname;
    Datum date_of_birth;
    static bool ValidirajIme (const std::string &ime_i_prezime) {
        auto it(ime_i_prezime.begin());
        while (it!=ime_i_prezime.end()) {
            if (!((std::toupper(*it)>='A' && std::toupper(*it)<='Z') || (*it >= '0' && *it <= '9') || *it==' ' || *it == '-' || *it == '\''))
                return false;
            it++;
        }
        return true;
    } 
public:
    Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja) : date_of_birth({1,1,1980}) {
        Postavi(ime_i_prezime, datum_rodjenja);
    }
    void Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
        if (!ValidirajIme(ime_i_prezime)) throw std::domain_error("Neispravno ime i prezime");
        name_surname = ime_i_prezime;
        date_of_birth = datum_rodjenja;
    }
    std::string DajImePrezime() const {return name_surname;}
    Datum DajDatumRodjenja() const {return date_of_birth;}
    void Ispisi() const {
        std::cout << DajImePrezime() << " (";
        DajDatumRodjenja().Ispisi(); std::cout << ")";
    }
};

class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    static bool NotTeen (int num) {
        if (num>=12 && num<=14) return false;
        else return true;
    }
public:
    Stan (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if (sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
        Stan::adresa = adresa;
        Stan::sprat = sprat;
        Stan::broj_soba = broj_soba;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
    }
    std::string DajAdresu() const {return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const {return broj_soba;}
    bool DajNamjesten() const {return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const {
        std::cout << "Stan se nalazi na adresi " << DajAdresu() << " na " << DajSprat() << ". spratu i ima " << DajBrojSoba();
        if ((DajBrojSoba()%10 == 2 || DajBrojSoba() % 10 == 3 || DajBrojSoba() % 10 == 4) && NotTeen(DajBrojSoba())) std::cout << " sobe." << std::endl;
        else std::cout << " soba." << std::endl;
        std::cout << "Kvadratura stana je " << std::fixed << std::setprecision(2) << DajKvadraturu() << " (m^2) i stan ";
        if (DajNamjesten()) std::cout << "je ";
        else std::cout << "nije ";
        std::cout << "namjesten.";
    }
};

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : 
    datum_prodaje({1,1,1980}), kupac_stana({"inicijalizacija", {1,1,1980}}), kupljeni_stan({"inicijalizacija", 1,1,false,1}) {
        Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
        Prodaja::cijena_stana = cijena_stana;
        Prodaja::datum_prodaje = datum_prodaje;
        Prodaja::kupac_stana = kupac_stana;
        Prodaja::kupljeni_stan = kupljeni_stan;
    }
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
             const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : 
             datum_prodaje({1,1,1980}), kupac_stana({"inicijalizacija", {1,1,1980}}), kupljeni_stan({"inicijalizacija", 1,1,false,1}) {
        Prodaja::ime_agenta_prodaje = ime_agenta_prodaje;
        Prodaja::cijena_stana = cijena_stana;
        Prodaja::datum_prodaje = Datum(dan_prodaje, mjesec_prodaje, godina_prodaje);
        Prodaja::kupac_stana = Kupac(ime_kupca, datum_rodjenja_kupca);
        Prodaja::kupljeni_stan = Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    }
    void PromijeniKupca (const Kupac &novi_kupac) {kupac_stana = novi_kupac;}
    void PromijeniStan (const Stan &novi_stan) {kupljeni_stan = novi_stan;}
    void PromijeniDatumKupovine (const Datum &novi_datum) {datum_prodaje = novi_datum;}
    void PromijeniCijenuProdaje (const double &nova_cijena) {cijena_stana = nova_cijena;}
    //void PomjeriDanUnaprijed() {
      //  Datum d = DajDatumProdaje();
        ////////////////////////////////////
    //}
    //void PomjeriDanUnazad() {
        ////////////////////////////////////
    //}
    std::string DajImeAgenta() const {return ime_agenta_prodaje;}
    std::string DajImeKupca() const {return kupac_stana.DajImePrezime();}
    Datum DajDatumProdaje() const {return datum_prodaje;}
    double DajCijenuStana() const {return cijena_stana;}
    //friend bool ProdatPrije (const Prodaja &p1, const Prodaja &p2); //////////////////////////////
    friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};
/*
bool ProdatPrije (const Prodaja &p1, const Prodaja &p2) { ///////////////////////////////////////////
    Datum d1(p1.DajDatumProdaje());
    Datum d2(p2.DajDatumProdaje());
    //if d1 prije d2 return true else return false
}
*/
bool SkupljiStan (const Prodaja &p1, const Prodaja &p2) {
    if (p1.DajCijenuStana() > p2.DajCijenuStana()) return true;
    else return false;
}

class Prodaje {

public:
    explicit Prodaje (int max_broj_prodaja);
    Prodaje (std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje (const Prodaje &prodaje);
    Prodaje (Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju (const std::string &ime_agenta_prodaje, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
                             const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
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
    void ObrisiProdajeAgenta (const std::string &ime_agenta);
    void ObrisiProdajeNaDatum (const Datum &datum);
    void IspisiProdajeNaDatum (const Datum &datum) const;
    void IspisiSveProdaje() const;
};


int main () {
    std::cout << "Dobrodosli!" << std::endl << std::endl;
    /*
    while (1) {
        char znak;
        std::cout << "Izaberite opciju:" << std::endl;
        std::cout << " 0 - kraj" << std::endl;
        std::cout << " 1 - uredjivanje stanova" << std::endl;
        std::cout << " 2 - uredjivanje kupaca" << std::endl;
        std::cout << " 3 - uredjivanje prodaja" << std::endl;
        int prompt;
        std::cin >> prompt;
        if (prompt == 0) break;
        else if (prompt == 1) {
            std::cout << "Izaberite opciju:" << std::endl;
            std::cout << " 0 - nazad" << std::endl;
            std::cout << " 1 - dodavanje stana" << std::endl;
            std::cout << " 2 - uredjivanje stanova" << std::endl;
            std::cout << " 3 - ispis svih stanova" << std::endl;
            std::cout << " 4 - kraj" << std::endl;
            std::cin >> prompt;
            if (prompt == 0) {
                ////////////////////////////////
            } else if (prompt == 1) {
                std::string adresa;
                int sprat, broj_soba;
                bool namjesten;
                double kvadratura;
                std::cin >> znak;
                std::cout << "Unesite adresu: ";
                std::getline(std::cin, adresa);
                std::cout << "Unesite sprat: ";
                std::cin >> sprat;
                std::cout << "Unesite broj soba: ";
                std::cin >> broj_soba;
                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                std::cin >> namjesten;
                std::cout >> "Unesite kvadraturu: ";
                std::cin >> kvadratura;
                try {
                    
                } catch() {
                    
                }
                std::cout << "Stan je uspjesno dodan!" << std::endl;
            } else if (prompt == 2) {
                //////////////////////////////
            } else if (prompt == 3) {
                ////////////////////////////
            } else if (prompt == 4) {
                ////////////////////////////
            } else {
                ////////////////////////////
            }
        } else if (prompt == 2) {
            /////////////////////////////
        } else if (prompt == 3) {
            ///////////////////////////
        } else {
            //////////////////////////////
        }
    }
    */
    std::cout << std::endl << std::endl << "Dovidjenja!";
	return 0;
}








