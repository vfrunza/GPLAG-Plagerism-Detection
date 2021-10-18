#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <algorithm>

class Datum {
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina){ Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
};

void Datum::Postavi(int d, int m, int g){
    int br_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) ++br_dana[1];
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > br_dana[m - 1])
        throw std::domain_error("Neispravan datum");
    dan = d; mjesec = m; godina = g;
}

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    static bool Ispravnost(std::string iip);
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjena() const { return datum_rodjenja; }
    void Ispisi() const{ std::cout << ime_i_prezime << " ("; datum_rodjenja.Ispisi(); std::cout << ")"; }
    
};

Kupac::Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : datum_rodjenja(datum_rodjenja){
    if(Ispravnost(ime_i_prezime))
        Kupac::ime_i_prezime = ime_i_prezime;
    else
        throw std::domain_error("Neispravno ime i prezime");
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    if(Ispravnost(ime_i_prezime)){
        Kupac::ime_i_prezime = ime_i_prezime;
        Kupac::datum_rodjenja = datum_rodjenja;
    }
    else
        throw std::domain_error("Neispravno ime i prezime");
}

inline bool Kupac::Ispravnost(std::string iip){
    
    for(int i(0); i < iip.length(); i++)
        if(!((iip[i] >= 'A' && iip[i] <= 'Z') || (iip[i] >= 'a' && iip[i] <= 'z') || iip[i] == ' ' || iip[i] == 39 || iip[i] == '-' || (iip[i] >= '0' && iip[i] <= '9')))
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
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){ Postavi(adresa, sprat, broj_soba, namjesten, kvadratura); }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
    
};

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat < 0 || broj_soba <= 0 || kvadratura <=0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa = adresa; Stan::sprat = sprat; Stan::broj_soba = broj_soba; Stan::namjesten = namjesten; Stan::kvadratura = kvadratura;
}

void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
    int cifra = broj_soba % 10;
    if(broj_soba > 10 && broj_soba < 20) std::cout << " soba.";
    else{
        if(cifra >= 2 && cifra <= 4) std::cout << " sobe.";
        else if(cifra == 1) std::cout << " sobu.";
        else std::cout << " soba.";
    }
    std::cout << " Kvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(!namjesten) std::cout << "ni";
    std::cout << "je namjesten.";
}

class Prodaja {
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan):
    ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan){};
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, 
    double broj_kvadrata) : ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), 
    kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata){};
    void PromijeniKupca(const Kupac &novi_kupac){ kupac_stana = novi_kupac; }
    void PromijeniStan(const Stan &novi_stan){ kupljeni_stan = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum){ datum_prodaje = novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena){ cijena_stana = nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta_prodaje; }
    std::string DajImeKupca() const { return kupac_stana.DajImePrezime(); }
    Datum DajDatumProdaje() const { return datum_prodaje; }
    double DajCijenuStana() const { return cijena_stana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
    
};

void Prodaja::PomjeriDanUnaprijed(){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((datum_prodaje.DajGodinu() % 4 == 0 && datum_prodaje.DajGodinu() % 100 != 0) || datum_prodaje.DajGodinu() % 400 == 0) ++broj_dana[1];
    int dan = datum_prodaje.DajDan() + 1;
    int mjesec = datum_prodaje.DajMjesec();
    if(dan > broj_dana[mjesec - 1]){  dan = 1;  mjesec +=1;  }
    int godina = datum_prodaje.DajGodinu();
    if(mjesec > 12){  mjesec = 1;  godina++; }
    datum_prodaje.Postavi(dan,mjesec,godina);
}

void Prodaja::PomjeriDanUnazad(){
    int broj_dana[12]{31,28,31,30,31,30,31,31,30,31,30,31};
    if((datum_prodaje.DajGodinu() % 4 == 0 && datum_prodaje.DajGodinu() % 100 != 0) || datum_prodaje.DajGodinu() % 400 == 0) ++broj_dana[1];
    int dan = datum_prodaje.DajDan() - 1;
    int mjesec = datum_prodaje.DajMjesec();
    int godina = datum_prodaje.DajGodinu();
    if(dan < 1 && mjesec == 1){ dan = 31;  mjesec = 12; --godina;  }
    else if(dan < 1){ dan = broj_dana[mjesec-2];  --mjesec; }
    datum_prodaje.Postavi(dan,mjesec,godina);
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    Datum datum1(p1.DajDatumProdaje()); Datum datum2(p2.DajDatumProdaje());
    if(datum1.DajGodinu() < datum2.DajGodinu()) return true;
    else if(datum1.DajGodinu() > datum2.DajGodinu()) return false;
    else if(datum1.DajMjesec() < datum2.DajMjesec()) return true;
    else if(datum2.DajMjesec() > datum2.DajMjesec()) return false;
    else if(datum1.DajDan() < datum2.DajDan()) return true;
    return false;
}

void Prodaja::Ispisi() const {
    std::cout << std::setw(32) << std::left << "Ime agenta:"; std::cout << DajImeAgenta() << std::endl; 
    std::cout << std::setw(32) << "Ime kupca:"; kupac_stana.Ispisi(); std::cout << std::endl;
    std::cout << std::setw(32) << "Zakazani datum prodaje:"; datum_prodaje.Ispisi(); std::cout << std::endl;
    std::cout << std::setw(32) << "Cijena stana:"; std::cout << cijena_stana << std::endl;
    std::cout << "Informacije o stanu:" << std::endl;
    kupljeni_stan.Ispisi();
    
}


class Prodaje {
    Prodaja *prodaje;
    int dimenzija;
    public:
    explicit Prodaje(int max_broj_prodaja);
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
};

Prodaje::Prodaje(int max_broj_prodaja) : dimenzija(max_broj_prodaja), prodaje(new Prodaja[dimenzija]){};
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja);

int main ()
{
    try{
        std::string ime_agenta{"Agent Agentic"};
        double cijena{87985};
        Datum datum_prodaje{29,5,2017};
        Kupac kupac_stana{"Neko Nekic", {19,3,1988}};
        Stan kupljeni_stan{"Hamdije Cemerlica 14",3,4,1,87.9};
        
        Prodaja s(ime_agenta, cijena, datum_prodaje, kupac_stana, kupljeni_stan);
        s.Ispisi();
    
    }catch(std::domain_error iz){
        std::cout << iz.what() << std::endl;
    }
	return 0;
}