#include <iostream>

class Datum{
    private:
        int dan,mjesec,godina;
        static int BrojDana(int mjesec, int godina);
    public:
        Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
        void Postavi(int dan, int mjesec, int mjesec);
        int DajDan() const { return Datum::dan; }
        int DajMjesec() const { return Datum::mjesec; }
        int DajGodinu() const { return Datum::godina; }
        void Ispisi() const;
};

class Kupac{
    private:
        std::string ime_i_prezime;
        Datum datum_rodjenja;
    public:
        Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
            Postavi(ime_i_prezime,datum_rodjenja);
        }
        void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
        std::string DajImePrezime() const { return Kupac::ime_i_prezime; }
        Datum DajDatumRodjenja() const { return Kupac::datum_rodjenja; }
        void Ispisi() const;
};

class Stan{
    private:
        std::string adresa;
        int sprat, broj_soba;
        bool namjesten;
        double kvadratura;
    public:
        Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
            Postavi(adresa,sprat,broj_soba,namjesten,kvadratura);
        }
        void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
        std::string DajAdresu() const { return Stan::adresa; }
        int DajSprat() const { return Stan::sprat; }
        int DajBrojSoba() const { return Stan::broj_soba; }
        bool DajNamjesten() const { return Stan::namjesten; }
        double DajKvadraturu() const { return Stan::kvadratura; }
        void Ispisi() const;
};

class Prodaja(){
    private:
        std::string agent;
        double cijena;
        Datum datum_prodaje;
        Kupac kupac_stana;
        Stan kupljeni_stan;
    public:
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
        Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, 
            const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
        void PromijeniKupca(const Kupac &novi_kupac) { Prodaja::kupac_stana = novi_kupac; }
        void PromijeniStan(const Stan &novi_stan) { Prodaja::kupljeni_stan = novi_stan; }
        void PromijeniDatumKupovine(const Datum &novi_datum) { Prodaja::datum_prodaje = novi_datum; }
        void PromijeniCijenuProdaje(const double &nova_cijena) { Prodaja::cijena = nova_cijena;
        void PomjeriDanUnaprijed();
        void PomjeriDanUnazad();
        std::string DajImeAgenta() const;
        std::string DajImeKupca() const;
        Datum DajDatumProdaje() const;
        double DajCijenuStana() const;
        friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
        friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
        void Ispisi() const;
};

int Datum::BrojDana(int mjesec, int godina) {
    int broj dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj dana[1]++;
    return broj dana[mjesec - 1];
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > BrojDana(mjesec, godina)){
        throw std::domain_error("Neispravan datum");
    }
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

void Datum::Ispisi() const{
    std::cout << Datum::dan << "/" << Datum::mjesec << "/" << Datum::godina << std::endl;
}

void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja){
    std::string s(ime_i_prezime);
    for(int i = 0 ; i < s.length(); i++){
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z' ))){
            if(s[i] != ' ' || s[i] != '-' || s[i] != '\'' || (s[i] >= '0' && s[i] <= '9')){
                throw std::domain_error("Neispravno ime i prezime");
            }
        }
    }
    Kupac::ime_i_prezime = s;
    Kupac::datum_rodjenja = datum_rodjenja;
}

void Kupac::Ispisi() const{
    std::cout << Kupac::ime_i_prezime << " (";
    Kupac::datum_rodjenja.Ispisi();
    std::cout << ")" << std::endl;
}

void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
    if(sprat < 0 || broj_soba < 0 || kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
    Stan::adresa = adresa;
    Stan:: broj_soba = broj_soba;
    Stan::kvadratura = kvadratura;
    Stan::namjesten = namjesten;
    Stan::sprat = sprat;
}

void Stan::Ispisi() const{
    std::cout << "Stan se nalazi na adresi " << Stan::adresa << " na " << Stan::sprat << " spratu";
    std::cout << " i ima " << Stan::broj_soba << " sob";
    if(Stan::broj_soba % 100 > 10 && Stan::broj_soba % 100 < 20){
        std::cout << "a.";
    }
    else{
        if(Stan::broj_soba % 10 == 2 || Stan::broj_soba % 10 == 3 || Stan::broj_soba % 10 == 4 ){
            std::cout << "e.";
        }
        else std::cout << "a.";
    }
    std::cout << std::endl;
    std::cout << "Kvadratura stana je " << Stan::kvadratura << " (m^2) i stan " ;
    if(namjesten) std::cout << "je namjesten.";
    else std::cout << "nije namjesten.";
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, 
    const Stan &kupljeni_stan) : datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {
        Prodaja::cijena = cijena_stana;
        Prodaja::agent = ime_agenta_prodaje;
}

Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, 
    int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, 
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje),
    kupac_stana(ime_kupca,datum_rodjenja_kupca), kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata){
        Prodaja::cijena = cijena_stana;
        Prodaja::agent = ime_agenta_prodaje;
}

void Prodaja::PomjeriDanUnaprijed(){
    int dan(Prodaja::datum_prodaje.DajDan());
    int mjesec(Prodaja::datum_prodaje.DajMjesec());
    int godina(Prodaja::datum_prodaje.DajGodinu());
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    dan++;
    if(dan > broj_dana[mjesec]) dan = 1, mjesec++;
    if(mjesec > 12) mjesec = 1, godina++;
    Prodaja::datum_prodaje.Postavi(dan,mjesec,godina);
}

void Prodaja::PomjeriDanUnazad(){
    int dan(Prodaja::datum_prodaje.DajDan());
    int mjesec(Prodaja::datum_prodaje.DajMjesec());
    int godina(Prodaja::datum_prodaje.DajGodinu());
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    dan--;
    if(dan < 1) dan = broj_dana[--mjesec];
    if(mjesec < 1) mjesec = 12, godina--;
    Prodaja::datum_prodaje.Postavi(dan,mjesec,godina);
}

void Prodaja::Ispisi() const{
    std::cout << std::left << std::setw(30) << "Ime agenta:";
    std::cout << Prodaja::agent << std::endl;
    std::cout << std::left << std::setw(30) << "Ime kupca:";
    Prodaja::kupac_stana.Ispisi();
    std::cout << std::endl;
    std::cout << std::left << std::setw(30) << "Zakazani datum prodaje:";
    Prodaja::datum_prodaje.Ispisi();
    std::cout << std::endl;
    std::cout << std::left << std::setw(30) << "Cijena stana:";
    std::cout << Prodaja::cijena_stana << std::endl;
    std::cout << "Informacije o stanu:" << std::endl;
    Prodaja::kupljeni_stan.Ispisi();
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2){
    int dan1(p1.DajDatumProdaje().DajDan());
    int mjesec1(p1.DajDatumProdaje().DajMjesec());
    int godina1(p1.DajDatumProdaje().DajGodinu());
    int dan2(p2.DajDatumProdaje().DajDan());
    int mjesec2(p2.DajDatumProdaje().DajMjesec());
    int godina2(p2.DajDatumProdaje().DajGodinu());
    if(godina1 == godina2){
        if(mjesec1 == mjesec2){
            return dan1 < dan2;
        }
        else return mjesec1 < mjesec2;
    }
    else return godina1 < godina2;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.DajCijenuStana() > p2.DajCijenuStana();
}


int main ()
{
	return 0;
}