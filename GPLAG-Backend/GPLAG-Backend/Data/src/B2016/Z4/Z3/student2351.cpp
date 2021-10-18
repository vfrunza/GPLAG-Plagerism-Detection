/B 2016/2017, Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <string>
using std::cin;
using std::cout;
using std::endl;

class Datum {
    int dan, mjesec, godina;
    friend class Kupac;
    friend class Prodaja;
    public:
    Datum (int dan, int mjesec, int godina) {
        int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31 };
        if ((godina % 4 == 0 && godina % 100 !=0) || godina % 400 == 0) broj_dana[1]++;
        if (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec-1])
        throw std::domain_error ("Neispravan datum");
        this->dan = dan; this->mjesec = mjesec; this->godina = godina;
    }
    void Postavi (int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

void Datum::Postavi (int dan, int mjesec, int godina) {
    int broj_dana[] {31,28,31,30,31,30,31,31,30,31,30,31};
    if ((godina % 4 == 0 && godina % 100 !=0) || godina % 400 == 0) broj_dana[1]++;
    if (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec-1])
    throw std::domain_error ("Neispravan datum");
    this->dan = dan; this->mjesec = mjesec; this->godina = godina;
}


class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
    friend class Prodaja;
    public:
    Kupac (const std::string &ime_i_prezime, const Datum &datum_rodjenja): datum_rodjenja(datum_rodjenja) {
        int i=0, length=ime_i_prezime.length();
        while (i<length)
        {
            while (!((ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z') || (ime_i_prezime[i] >= 'A' && ime_i_prezime[i] <= 'Z') || ime_i_prezime[i] == ' '|| ime_i_prezime[i] == '\n'))
            {
                throw std::domain_error ("Neispravno ime i prezime"); std::cin.clear();
            }
            i++;
        }
        this->ime_i_prezime=ime_i_prezime; this->datum_rodjenja = datum_rodjenja;
    }
    void Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum_rodjenja; }
    void Ispisi() const {
        std::cout << ime_i_prezime << " " << datum_rodjenja.dan << "/" << datum_rodjenja.mjesec << "/" << datum_rodjenja.godina;
    }
};
void Kupac::Postavi (const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
    
    int i=0, length =ime_i_prezime.length();
    while (i<length)
    {
        while (!((ime_i_prezime[i] >= 'a' && ime_i_prezime[i] <= 'z') || (ime_i_prezime[i] >='A' && ime_i_prezime[i] <= 'Z') || ime_i_prezime[i] == ' ' || ime_i_prezime[i] == '\n')) 
        {
            throw std::domain_error ("Neispravno ime i prezime"); std::cin.clear();
        }
        i++;
    }
    this->ime_i_prezime = ime_i_prezime; this->datum_rodjenja = datum_rodjenja;
};

class Stan {
    std::string adresa;
    int sprat, broj_soba;
    double kvadratura;
    bool namjesten;
    friend class Prodaja;
    public:
    Stan (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if (sprat<0 || broj_soba<0) throw std::domain_error ("Neispravan unos podataka");
    }
    void Postavi (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat () const { return sprat; }
    int DajBrojSoba () const { return broj_soba; }
    bool DajNamjesten () const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
};
void Stan::Postavi (const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat<0 || broj_soba<0) throw std::domain_error ("Neispravan unos podataka");
    this->adresa=adresa; this->sprat=sprat; this->broj_soba=broj_soba; this->kvadratura=kvadratura; this->namjesten=namjesten;
}
void Stan::Ispisi () const {
    if ((broj_soba%10 == 3) || (broj_soba%10 == 2) || (broj_soba%10 == 4)) {
    cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << "." << "spratu " << "i ima " << broj_soba << " sobe. " << endl;
      }
    else  {
        cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << "." << "spratu " << "i ima " << broj_soba << " soba. " << endl;
       
    }
    if (namjesten == 1) cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan je namjesten.";
    if (namjesten == 0) cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan nije namjesten.";
}

class Prodaja {
    std::string ime_agenta_prodaje,ime_kupca,adresa_stana;
    double cijena_stana,broj_kvadrata;
    int dan_prodaje,mjesec_prodaje,godina_prodaje,sprat_stana;
    bool namjesten_stan;
    Datum &datum_prodaje;
    Stan &kupljeni_stan;
    Kupac &kupac_stana;
    public:
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca (const Kupac &novi_kupac);
    void PromijeniStan(const Stan &novi_stan);
    void PromijeniDatumKupovine(const Datum &novi_datum);
    void PromijeniCijenuProdaje (const double &nova_cijena);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta () const { return ime_agenta_prodaje; }
    std::string DajImeKupca () const { return ime_kupca; }
    Datum DajDatumProdaje () const { return datum_prodaje; }
    friend bool ProdatPrije (const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan (const Prodaja &p1, const Prodaja &p2);
    void Ispisi () const;
};


int main ()
{
    int sprat,broj_soba,broj;
    double kvadratura;
    cout << "Dobrodosli!";
    cout << endl;
    cout << endl;
    cout << "Izaberite opciju:" << endl;
    cout << " 0 - kraj" << endl << " 1 - uredjivanje stanova" << endl << " 2 - uredjivanje kupca" << endl << " 3 - uredjivanje prodaja" << endl;
    
    cout << "Izaberite opciju: " << endl;
    cout << " 0 - nazad" << endl << " 1 - dodavanje stana" << endl << " 2 - uredjivanje stanova" << endl << " 3 - ispis svih stanova" << endl << " 4 - kraj" << endl;
    
    while(1) 
    {
        int opcije;
        std::string ulica;
        cin >> opcije; 
        try {
            if (opcije == 1) {
            cout << "Unesite adresu: ";
            std::getline(std::cin, ulica); 
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            cout << "Unesite sprat: "; cin >> sprat;
            cout << "Unesite broj soba: "; cin >> broj_soba; 
            cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
            cin >> broj; 
            cout << "Unesite kvadraturu: "; cin >> kvadratura; 
            }
        }
         catch (std::domain_error e) {
            cout << e.what(); 
        } return 0;
    }

//std::string s2;
//s2 = "Hamdije Cemerlica 14";
//Stan s1(s2,5,5,0,35.54);
//s1.Postavi(s2,5,102,0,35.54);
//s1.Ispisi();

while (1) {
    int opcija;
    cin >> opcija;
    if (opcija == 0) return 0;
}
	return 0;
}