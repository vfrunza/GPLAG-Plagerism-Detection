/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!


#include < iostream > #include < stdexcept > #include < exception > #include < string > #include < iomanip > #include < algorithm > #include < memory > #include < vector >

    using std::cin;
using std::cout;
using std::endl;

// KLASA DATUM
class Datum {
    int dan, mjesec, godina;

    public:

        Datum(int dan, int mjesec, int godina) {
            Postavi(dan, mjesec, godina);
        }

    void Postavi(int dan, int mjesec, int godina);

    int DajDan() const

    {
        return dan;
    }

    int DajMjesec() const

    {
        return mjesec;
    }

    int DajGodinu() const

    {
        return godina;
    }

    void Ispisi() const

    {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};
// DATUM POSTAVI
void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[] {
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
    };
    if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
    if (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

/*********************************************************************/

// KLASA KUPAC
class Kupac {
    std::
        string ime_i_prezime;
    Datum datum_rodjenja;
    public:

        Kupac(const std::string & ime_i_prezime,
            const Datum & datum_rodjenja):

        ime_i_prezime(ime_i_prezime), datum_rodjenja(datum_rodjenja)

    {
        for (auto & i: ime_i_prezime) {
            if (!((i >= 'a'
                        and i <= 'z') or(i >= 'A'
                        and i <= 'Z') or(i >= '0'
                        and i <= '9') or i == '-'
                    or i == ' '
                    or i == '\''))
                throw std::domain_error("Neispravno ime i prezime");
        }
    }

    void Postavi(const std::string & ime_i_prezime,
        const Datum & datum_rodjenja) { * this = Kupac(ime_i_prezime, datum_rodjenja);
    }

    std::

        string DajImePrezime() const

    {
        return ime_i_prezime;
    }

    Datum DajDatumRodjenja() const

    {
        return datum_rodjenja;
    }

    void Ispisi() const

    {
        std::cout << ime_i_prezime << " " << "(";
        datum_rodjenja.Ispisi();
        std::cout << ")";
    }
};
/* POSTAVI KUPAC  */

/*********************************************/

// KLASA STAN
class Stan {
    std::
        string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    public:

        Stan(const std::string & adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
            Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
        }

    void Postavi(const std::string & adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);

    std::

        string DajAdresu() const

    {
        return adresa;
    }

    int DajSprat() const

    {
        return sprat;
    }

    int DajBrojSoba() const

    {
        return broj_soba;
    }

    bool DajNamjesten() const

    {
        return namjesten;
    }

    double DajKvadraturu() const

    {
        return kvadratura;
    }

    void Ispisi() const

    {
        std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
        if (broj_soba == 1) std::cout << " sobu.";
        else if (broj_soba == 2 or broj_soba == 3 or broj_soba == 4) std::cout << " sobe.";
        else std::cout << " soba.";
        std::cout << " Kvadratura stana je " << kvadratura << " (m^2) i stan ";
        if (namjesten) {
            std::cout << "je namjesten.";
        } else std::cout << "nije namjesten.";
        std::cout << std::endl;
    }
};

// STAN POSTAVI
void Stan::Postavi(const std::string & adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        if (sprat < 0o r broj_soba < 0o r namjesten < 0o r kvadratura < 0) throw std::domain_error("Neispravan unos podataka");
        Stan::adresa = adresa;
        Stan::sprat = sprat;
        Stan::broj_soba = broj_soba;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
    }
    //////////////////////////////////////

// KLASA PRODAJA
class Prodaja {
    std::
        string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    public:
        /// SVI IZUZECI KOJU BUDU BACENI PROVJERITI CE SE U INICIALIZACIOJ LISTI
        // Prvi Konstruktor koji prima cijelovite objektre ( kupac, stan, datum itd..)

        Prodaja(const std::string & ime_agenta_prodaje,
            double cijena_stana,
            const Datum & datum_prodaje,
                const Kupac & kupac_stana,
                    const Stan & kupljeni_stan):
        // Konstruktorska inicial. lista

        ime_agenta_prodaje(ime_agenta_prodaje),

        cijena_stana(cijena_stana),

        datum_prodaje(datum_prodaje),

        kupac_stana(kupac_stana),

        kupljeni_stan(kupljeni_stan) {}
        ///

    // Drugi Konstruktor koji prima pojedinacno atribute objekata

    Prodaja(const std::string & ime_agenta_prodaje, double cijena_stana,
            int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
            const std::string & ime_kupca,
                const Datum & datum_rodjenja_kupca,
                    const std::string & adresa_stana, int sprat_stana,
                        int broj_soba, bool namjesten_stan, double broj_kvadrata):
        // Konstruktorska inicial. lista

        ime_agenta_prodaje(ime_agenta_prodaje),

        cijena_stana(cijena_stana),

        datum_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje),

        kupac_stana(ime_kupca, datum_rodjenja_kupca),

        kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}

    ///
    void PromjeniAgenta(const std::string & novi_agent) {
        ime_agenta_prodaje = novi_agent;
    }

    void PromijeniKupca(const Kupac & novi_kupac) {
        kupac_stana = Kupac(novi_kupac);
    }

    void PromijeniStan(const Stan & novi_stan) {
        kupljeni_stan = Stan(novi_stan);
    }

    void PromijeniDatumKupovine(const Datum & novi_datum) {
        datum_prodaje = Datum(novi_datum);
    }

    void PromijeniCijenuProdaje(const double & nova_cijena) {
        cijena_stana = nova_cijena;
    }

    void PomjeriDanUnaprijed();

    void PomjeriDanUnazad();

    std::

        string DajImeAgenta() const

    {
        return ime_agenta_prodaje;
    }

    std::

        string DajImeKupca() const

    {
        return kupac_stana.DajImePrezime();
    }

    Datum DajDatumProdaje() const

    {
        return datum_prodaje;
    }

    double DajCijenuStana() const

    {
        return cijena_stana;
    }

    friend bool

    ProdatPrije(const Prodaja & p1,
        const Prodaja & p2);

    friend bool

    SkupljiStan(const Prodaja & p1,
        const Prodaja & p2);

    void Ispisi() const;
};

void Prodaja::Ispisi() const {
    std::cout << std::setw(32) << std::left << "Ime agenta: ";
    cout << ime_agenta_prodaje << std::endl;
    std::cout << std::setw(32) << std::left << "Ime kupca: ";
    kupac_stana.Ispisi();
    std::cout << std::endl;
    std::cout << std::setw(32) << std::left << "Zakazani datum prodaje: ";
    datum_prodaje.Ispisi();
    std::cout << std::endl;
    std::cout << std::setw(32) << std::left << "Cijena stana: " << cijena_stana << std::endl;
    std::cout << std::setw(32) << "Informacije o stanu: " << std::endl;
    kupljeni_stan.Ispisi();
}

bool ProdatPrije(const Prodaja & p1,
    const Prodaja & p2) {
    Datum d1(p1.DajDatumProdaje()), d2(p2.DajDatumProdaje());
    if (d1.DajGodinu() == d2.DajGodinu()) {
        if (d1.DajMjesec() == d2.DajMjesec()) {
            return d1.DajDan() < d2.DajDan();
        } else return d1.DajMjesec() < d2.DajMjesec();
    } else return d1.DajGodinu() < d2.DajGodinu();
}

bool SkupljiStan(const Prodaja & p1,
    const Prodaja & p2) {
    return p1.DajCijenuStana() > p2.DajCijenuStana();
}

void Prodaja::PomjeriDanUnaprijed() {
    int godina(datum_prodaje.DajGodinu());
    int mjesec(datum_prodaje.DajMjesec());
    int dan(datum_prodaje.DajDan());
    int broj_dana[] {
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
    };
    if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
    dan++;
    if (dan > broj_dana[mjesec - 1]) dan = 1, mjesec++;
    if (mjesec > 12) mjesec = 1, godina++;
    Prodaja::datum_prodaje.Postavi(dan, mjesec, godina);
}
void Prodaja::PomjeriDanUnazad() {
    int godina(datum_prodaje.DajGodinu());
    int mjesec(datum_prodaje.DajMjesec());
    int dan(datum_prodaje.DajDan());
    int broj_dana[] {
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
    };
    if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
    dan--;
    if (dan == 0) {
        mjesec--;
        if (mjesec == 0) {
            mjesec = 12;
            godina--;
        }
        dan = broj_dana[mjesec - 1];
    }
    Prodaja::datum_prodaje.Postavi(dan, mjesec, godina);
}

// KLASA PRODAJE
class Prodaje {
    // ATRIBUTI KLASE
    int max_broj_prodaja;
    int broj_prodaja;
    Prodaja * * prodaje_pok = nullptr;

    void OslobodiMem() {
        for (int i = 0; i < max_broj_prodaja; i++) {
            delete prodaje_pok[i];
        }
        delete[] prodaje_pok;
    }

    public:

        // GLAVNI MAIN KONSTRUKTOR SA MAX_BR_PRODAJA
        explicit Prodaje(int max_broj_prodaja):

        max_broj_prodaja(max_broj_prodaja), broj_prodaja(0),

        prodaje_pok(new Prodaja * [max_broj_prodaja] {})

    {}

    // SEKVENCIJALNI KONSTUKTOR
    Prodaje(std::initializer_list < Prodaja > spisak_prodaja):

        max_broj_prodaja(spisak_prodaja.size()),

        broj_prodaja(spisak_prodaja.size()),

        prodaje_pok(new Prodaja * [spisak_prodaja.size()]

            {})

    {
        auto j(spisak_prodaja.begin());
        try {
            for (int i = 0; i < broj_prodaja; i++) {
                prodaje_pok[i] = new Prodaja( * j);
                j++;
            }
        } catch (...) {
            OslobodiMem();
        }
    }
    // DESTRUKTOR
    ~

    Prodaje() {
        OslobodiMem();
    }

    Prodaje(const Prodaje & prodaje); // copy constructor

    // POMJERAJUCI KONSTRUKTOR
    Prodaje(Prodaje && prodaje):

        max_broj_prodaja(prodaje.max_broj_prodaja), broj_prodaja(prodaje.broj_prodaja),

        prodaje_pok(prodaje.prodaje_pok) {
            prodaje.prodaje_pok = nullptr;
            prodaje.broj_prodaja = 0;
        }

    Prodaje & operator = (
        Prodaje prodaje); // copy operator dodjele
    Prodaje & operator = (Prodaje && prodaje); // move operator dodjele

    void RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana,
        const Datum & datum_prodaje,
            const Kupac & kupac_stana,
                const Stan & kupljeni_stan);

    void RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
        int mjesec_prodaje, int godina_prodaje, std::string & ime_kupca,
        const Datum & datum_rodjenja_kupca,
            const std::string & adresa_stana,
                int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);

    void RegistrirajProdaju(Prodaja * prodaja) {
        if (broj_prodaja >= max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
        prodaje_pok[broj_prodaja] = prodaja;
        broj_prodaja++;
    }

    Prodaja &

        DajProdaju(int indeks) {
            if (indeks < 1 or indeks > broj_prodaja) throw "";
            return *prodaje_pok[indeks - 1];
        }

    int DajBrojProdaja() const

    {
        return broj_prodaja;
    }

    int DajBrojProdajaNaDatum(const Datum & datum) const;

    int DajBrojProdajaOdAgenta(const std::string & ime_agenta) const;
    Prodaja &

        DajNajranijuProdaju();

    Prodaja DajNajranijuProdaju() const;
    Prodaja &

        DajNajskupljuProdaju();

    Prodaja DajNajskupljuProdaju() const;

    void IsprazniKolekciju();

    void ObrisiNajranijuProdaju();

    void ObrisiProdajeAgenta(const std::string & ime_agenta);

    void ObrisiProdajeNaDatum(const Datum & datum);

    void IspisiProdajeNaDatum(const Datum & datum) const;

    void IspisiSveProdaje() const;

};

// KOPIRAJUCI KONSTRUKTOR
Prodaje::Prodaje(const Prodaje & prodaje): max_broj_prodaja(prodaje.max_broj_prodaja), broj_prodaja(prodaje.broj_prodaja), prodaje_pok(new Prodaja * [prodaje.max_broj_prodaja] {}) {
        try {
            for (int i = 0; i < prodaje.broj_prodaja; i++) {
                prodaje_pok[i] = new Prodaja( * prodaje.prodaje_pok[i]);
            }
        } catch (...) {
            OslobodiMem();
        }
    }
    // COPY OPERATOR DODJELE
Prodaje & Prodaje::operator = (Prodaje prodaje) {
        std::swap(max_broj_prodaja, prodaje.max_broj_prodaja);
        std::swap(broj_prodaja, prodaje.broj_prodaja);
        std::swap(prodaje_pok, prodaje.prodaje_pok);
        return *this;
    }
    //  MOVE OPERATOR DODJELE
Prodaje & Prodaje::operator = (Prodaje && prodaje) {
        std::swap(max_broj_prodaja, prodaje.max_broj_prodaja);
        std::swap(broj_prodaja, prodaje.broj_prodaja);
        std::swap(prodaje_pok, prodaje.prodaje_pok);
        return *this;
    }
    // REGISTRIRAJ PRODAJU
void Prodaje::RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana,
        const Datum & datum_prodaje,
            const Kupac & kupac_stana,
                const Stan & kupljeni_stan) {
        if (broj_prodaja >= max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
        prodaje_pok[broj_prodaja] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
        broj_prodaja++;
    }
    // REGISTRIRAJ PRODAJU
void Prodaje::RegistrirajProdaju(const std::string & ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string & ime_kupca,
        const Datum & datum_rodjenja_kupca,
            const std::string & adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
        if (broj_prodaja >= max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
        prodaje_pok[broj_prodaja] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
        broj_prodaja++;
    }
    // DAJ BROJ PRODAJA NA DATUM
int Prodaje::DajBrojProdajaNaDatum(const Datum & datum) const {
    return std::count_if(prodaje_pok, prodaje_pok + broj_prodaja, [datum](Prodaja * temp) {
        Datum d1(temp - > DajDatumProdaje());
        if (d1.DajGodinu() == datum.DajGodinu() and d1.DajMjesec() == datum.DajMjesec() and d1.DajDan() == datum.DajDan()) return true;
        return false;
    });
}

// DAJ BROJ PRODAJA OD AGENTA

int Prodaje::DajBrojProdajaOdAgenta(const std::string & ime_agenta) const {
    return std::count_if(prodaje_pok, prodaje_pok + broj_prodaja, [ime_agenta](Prodaja * temp) {
        if (ime_agenta == temp - > DajImeAgenta()) return true;
        return false;
    });
}

// DAJ NAJRANIJU PRODAJU

Prodaja & Prodaje::DajNajranijuProdaju() {
    if (broj_prodaja == 0) throw std::domain_error("Nema registriranih prodaja");
    return * * std::min_element(prodaje_pok, prodaje_pok + broj_prodaja, [](Prodaja * p1, Prodaja * p2) {
        if (ProdatPrije( * p1, * p2)) return true;
        return false;
    });
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    if (broj_prodaja == 0) throw std::domain_error("Nema registriranih prodaja");
    return * * std::min_element(prodaje_pok, prodaje_pok + broj_prodaja, [](Prodaja * p1, Prodaja * p2) {
        if (ProdatPrije( * p1, * p2)) return true;
        return false;
    });
}

// DAJ NAJSKUPJU PRODAJU

Prodaja & Prodaje::DajNajskupljuProdaju() {
        if (broj_prodaja == 0) throw std::domain_error("Nema registriranih prodaja");
        return * * std::max_element(prodaje_pok, prodaje_pok + broj_prodaja, [](Prodaja * p1, Prodaja * p2) {
            if (p1 - > DajCijenuStana() > p2 - > DajCijenuStana()) return true;
            return false;
        });
    }
    // ISPRAZNI KOLEKCIJU
void Prodaje::IsprazniKolekciju() {
        for (int i = 0; i < broj_prodaja; i++) {
            delete prodaje_pok[i];
            prodaje_pok[i] = nullptr;
        }
        broj_prodaja = 0;
    }
    // OBRISI NAJRANIJU PRODAJU
void Prodaje::ObrisiNajranijuProdaju() {
        if (broj_prodaja == 0) throw std::range_error("Prazna kolekcija");
        for (int i = 0; i < broj_prodaja; i++) {
            if (prodaje_pok[i] == & DajNajranijuProdaju()) {
                delete prodaje_pok[i];
                prodaje_pok[i] = nullptr;
                std::swap(prodaje_pok[i], prodaje_pok[broj_prodaja - 1]);
                broj_prodaja--;
                break;
            }
        }
    }
    // OBRISI PRODAJE AGENTA
void Prodaje::ObrisiProdajeAgenta(const std::string & ime_agenta) {
        for (int i = 0; i < broj_prodaja; i++) {
            if (prodaje_pok[i] - > DajImeAgenta() == ime_agenta) {
                delete prodaje_pok[i];
                prodaje_pok[i] = nullptr;
                std::swap(prodaje_pok[i], prodaje_pok[broj_prodaja - 1]);
                broj_prodaja--;
            }
        }
    }
    // OBRISI PRODAJE NA DATUM
void Prodaje::ObrisiProdajeNaDatum(const Datum & datum) {
        for (int i = 0; i < broj_prodaja; i++) {
            Datum d1(prodaje_pok[i] - > DajDatumProdaje());
            if (d1.DajGodinu() == datum.DajGodinu() and d1.DajMjesec() == datum.DajMjesec() and d1.DajDan() == datum.DajDan()) {
                delete prodaje_pok[i];
                prodaje_pok[i] = nullptr;
                std::swap(prodaje_pok[i], prodaje_pok[broj_prodaja - 1]);
                broj_prodaja--;
            }
        }
    }
    // ISPISI PRODAJE NA DATUM
void Prodaje::IspisiProdajeNaDatum(const Datum & datum) const {
    std::sort(prodaje_pok, prodaje_pok + broj_prodaja, [](Prodaja * pr1, Prodaja * pr2) {
        if (pr1 - > DajDatumProdaje().DajGodinu() == pr2 - > DajDatumProdaje().DajGodinu() and pr1 - > DajDatumProdaje().DajMjesec() == pr2 - > DajDatumProdaje().DajMjesec() and pr1 - > DajDatumProdaje().DajDan() == pr2 - > DajDatumProdaje().DajDan()) {
            return pr1 - > DajImeKupca() > pr2 - > DajImeKupca();
        }
        return ProdatPrije( * pr1, * pr2);
    });
    for (int i = 0; i < broj_prodaja; i++) {
        Datum d1(prodaje_pok[i] - > DajDatumProdaje());
        if (d1.DajGodinu() == datum.DajGodinu() and d1.DajMjesec() == datum.DajMjesec() and d1.DajDan() == datum.DajDan()) {
            prodaje_pok[i] - > Ispisi();
            std::cout << std::endl;
        }
    }
}
void Prodaje::IspisiSveProdaje() const {
    std::sort(prodaje_pok, prodaje_pok + broj_prodaja, [](Prodaja * pr1, Prodaja * pr2) {
        if (pr1 - > DajDatumProdaje().DajGodinu() == pr2 - > DajDatumProdaje().DajGodinu() and pr1 - > DajDatumProdaje().DajMjesec() == pr2 - > DajDatumProdaje().DajMjesec() and pr1 - > DajDatumProdaje().DajDan() == pr2 - > DajDatumProdaje().DajDan()) {
            return pr1 - > DajImeKupca() < pr2 - > DajImeKupca();
        }
        return ProdatPrije( * pr1, * pr2);
    });
    for (int i = 0; i < broj_prodaja; i++) {
        prodaje_pok[i] - > Ispisi();
        std::cout << std::endl;
    }
}

// MAIN CODE
int main() {

    Prodaje pr_test(20);
    std::vector < std::shared_ptr < Stan >> v1;
    std::vector < std::shared_ptr < Kupac >> v2;
    int opcija;
    int opcija2;
    bool nije_kraj(true);
    std::cout << "Dobrodosli!" << std::endl << std::endl << endl;
    do {
        std::cout << "Izaberite opciju:" << std::endl;
        std::cout << " 0 - kraj" << std::endl;
        std::cout << " 1 - uredjivanje stanova" << std::endl;
        std::cout << " 2 - uredjivanje kupaca" << std::endl;
        std::cout << " 3 - uredjivanje prodaja" << std::endl;
        std::cin >> opcija;
        switch (opcija) {
            // MAIN ZA KRAJ CASE 0;
        case 0:
            nije_kraj = false;
            break;
            // MAIN UREDJIVANJE STANOVA CASE 1
        case 1:
            {
                do {
                    std::cout << "Izaberite opciju:" << std::endl;
                    std::cout << " 0 - nazad" << std::endl;
                    std::cout << " 1 - dodavanje stana" << std::endl;
                    std::cout << " 2 - uredjivanje stanova" << std::endl;
                    std::cout << " 3 - ispis svih stanova" << std::endl;
                    std::cout << " 4 - kraj" << std::endl;
                    std::cin >> opcija2;
                    switch (opcija2) {
                        // UREDJIVANJE STANOVA NAZAD CASE 0
                    case 0:
                        break;
                        // DODOAVANJE STANA CASE 1
                    case 1:
                        {
                            bool unos(false);
                            std::string adresa;
                            int sprat,
                            broj_soba;
                            int namjesten;
                            double kvadratura;
                            do {
                                unos = false;
                                std::cout << "Unesite adresu: ";
                                cin.ignore(100, '\n');
                                std::getline(std::cin, adresa);
                                std::cout << "Unesite sprat: ";
                                std::cin >> sprat;
                                std::cout << "Unesite broj soba: ";
                                std::cin >> broj_soba;
                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                std::cin >> namjesten;

                                std::cout << "Unesite kvadraturu: ";
                                std::cin >> kvadratura;

                                try {
                                    if (namjesten < 0o r namjesten > 1) throw std::domain_error("Neispravan unos podataka");
                                    v1.push_back(std::make_shared < Stan > (adresa, sprat, broj_soba, namjesten, kvadratura));
                                    std::cout << "Stan je uspjesno dodan!" << std::endl << std::endl;
                                } catch (std::exception & e) {
                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                    unos = true;
                                    cin.clear();
                                }
                            } while (unos);
                        }
                        break;
                        // UREDJIVANJE STANOVA PROMJENA STANA
                    case 2:
                        {
                            if (v1.empty()) {
                                std::cout << "Nema dostupni stanova" << std::endl;
                                break;
                            }
                            std::cout << "Odaberite stan. Dostupni stanovi su: " << std::endl;
                            for (int i = 0; i < v1.size(); i++) {
                                std::cout << " " << i + 1 << " - ";
                                v1[i] - > Ispisi();
                                std::cout << std::endl;
                            }
                            int br_stana;
                            int opcija_ur_stan;
                            std::cin >> br_stana;
                            if (br_stana < 1 or br_stana > v1.size()) {
                                std::cout << "Neispravan broj stana" << std::endl;
                                break;
                            }
                            std::cout << "Odaberite polje koje zelite urediti:" << std::endl;
                            std::cout << " 0 - nazad" << std::endl;
                            std::cout << " 1 - adresa" << std::endl;
                            std::cout << " 2 - sprat" << std::endl;
                            std::cout << " 3 - broj soba" << std::endl;
                            std::cout << " 4 - da li je stan namjesten" << std::endl;
                            std::cout << " 5 - kvadratura" << std::endl;
                            std::cout << " 6 - sve" << std::endl;
                            std::cin >> opcija_ur_stan;
                            switch (opcija_ur_stan) {
                                // UREDJIVANJE STANOVA PROMJENA STANA NAZAD
                            case 0:
                                break;
                                // UREDJIVANJE STANOVA PROMJENA STANA ADRESA
                            case 1:
                                {
                                    std::string adresa;
                                    bool unos(false);
                                    do {
                                        std::cout << "Unesite adresu: ";
                                        cin.ignore(100, '\n');
                                        std::getline(cin, adresa);
                                        unos = false;
                                        try {
                                            v1[br_stana - 1] - > Postavi(adresa, v1[br_stana - 1] - > DajSprat(), v1[br_stana - 1] - > DajBrojSoba(), v1[br_stana - 1] - > DajNamjesten(), v1[br_stana - 1] - > DajKvadraturu());
                                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                            unos = true;
                                            cin.clear();
                                        }
                                    } while (unos);
                                }
                                break;
                                // UREDJIVANJE STANOVA PROMJENA STANA SPRAT
                            case 2:
                                {
                                    int sprat;
                                    bool unos(false);
                                    do {
                                        std::cout << "Unesite sprat: ";
                                        std::cin >> sprat;
                                        unos = false;
                                        try {
                                            v1[br_stana - 1] - > Postavi(v1[br_stana - 1] - > DajAdresu(), sprat, v1[br_stana - 1] - > DajBrojSoba(), v1[br_stana - 1] - > DajNamjesten(), v1[br_stana - 1] - > DajKvadraturu());
                                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                            unos = true;
                                            cin.clear();
                                        }
                                    } while (unos);
                                }
                                break;
                                // UREDJIVANJE STANOVA PROMJENA STANA BROJ SOBA
                            case 3:
                                {
                                    int broj_soba;
                                    bool unos(false);
                                    do {
                                        std::cout << "Unesite broj soba: ";
                                        std::cin >> broj_soba;
                                        unos = false;
                                        try {
                                            v1[br_stana - 1] - > Postavi(v1[br_stana - 1] - > DajAdresu(), v1[br_stana - 1] - > DajSprat(), broj_soba, v1[br_stana - 1] - > DajNamjesten(), v1[br_stana - 1] - > DajKvadraturu());
                                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                            unos = true;
                                            cin.clear();
                                        }
                                    } while (unos);
                                }
                                break;
                                // UREDJIVANJE STANOVA PROMJENA STANA NAMJESTEN
                            case 4:
                                {
                                    int namjesten;
                                    bool unos(false);
                                    do {
                                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                        std::cin >> namjesten;
                                        unos = false;
                                        try {
                                            if (namjesten < 0o r namjesten > 1) throw std::domain_error("Neispravan unos podataka");
                                            v1[br_stana - 1] - > Postavi(v1[br_stana - 1] - > DajAdresu(), v1[br_stana - 1] - > DajSprat(), v1[br_stana - 1] - > DajBrojSoba(), namjesten, v1[br_stana - 1] - > DajKvadraturu());
                                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                            unos = true;
                                            cin.clear();
                                        }
                                    } while (unos);
                                }
                                break;
                                // UREDJIVANJE STANOVA PROMJENA STANA KVADRATURA
                            case 5:
                                {
                                    double kvadratura;
                                    bool unos(false);
                                    do {
                                        std::cout << "Unesite kvadraturu: ";
                                        std::cin >> kvadratura;
                                        unos = false;
                                        try {
                                            v1[br_stana - 1] - > Postavi(v1[br_stana - 1] - > DajAdresu(), v1[br_stana - 1] - > DajSprat(), v1[br_stana - 1] - > DajBrojSoba(), v1[br_stana - 1] - > DajNamjesten(), kvadratura);
                                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                            unos = true;
                                            cin.clear();
                                        }
                                    } while (unos);
                                }
                                break;
                                // UREDJIVANJE STANOVA PROMJENA STANA SVE
                            case 6:
                                {
                                    bool unos(false);
                                    std::string adresa;
                                    int sprat,
                                    broj_soba;
                                    int namjesten;
                                    double kvadratura;
                                    do {
                                        unos = false;
                                        std::cout << "Unesite adresu: ";
                                        cin.ignore(100, '\n');
                                        std::getline(std::cin, adresa);
                                        std::cout << "Unesite sprat: ";
                                        std::cin >> sprat;
                                        std::cout << "Unesite broj soba: ";
                                        std::cin >> broj_soba;
                                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                        std::cin >> namjesten;
                                        std::cout << "Unesite kvadraturu: ";
                                        std::cin >> kvadratura;
                                        try {
                                            if (namjesten < 0o r namjesten > 1) throw std::domain_error("Neispravan unos podataka");
                                            v1[br_stana - 1] - > Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
                                            std::cout << "Stan je uspjesno izmijenjen!" << std::endl << std::endl;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                            unos = true;
                                            cin.clear();
                                        }
                                    } while (unos);
                                }
                                break;
                            }
                        }
                        break;
                        // CASE 3
                    case 3:
                        {
                            if (v1.empty()) {
                                std::cout << "Nema dostupni stanova" << std::endl;
                                break;
                            }
                            for (int i = 0; i < v1.size(); i++) {
                                std::cout << i + 1 << ". ";
                                v1[i] - > Ispisi();
                                std::cout << std::endl;
                            }
                        }
                        break;
                        // CASE 4
                    case 4:
                        nije_kraj = false;
                        break;
                    }
                } while (opcija2 != 0 and opcija2 != 4);
            }
            break;
            // CASE 2 UREDJIVANJE KUPACA
        case 2:
            {
                do {
                    std::cout << "Izaberite opciju:" << std::endl;
                    std::cout << " 0 - nazad" << std::endl;
                    std::cout << " 1 - dodavanje kupca" << std::endl;
                    std::cout << " 2 - uredjivanje kupaca" << std::endl;
                    std::cout << " 3 - ispis svih kupaca" << std::endl;
                    std::cout << " 4 - kraj" << std::endl;
                    std::cin >> opcija2;
                    switch (opcija2) {
                        // UREDJIVANJE KUPACA NAZAD CASE 0
                    case 0:
                        break;
                        // UREDJIVANJE KUPACA DODOAVANJE KUPCA CASE 1
                    case 1:
                        {
                            bool unos(false);
                            std::string ime_i_prezime;
                            int dan,
                            mjesec,
                            godina;
                            char temp;
                            do {
                                unos = false;
                                std::cout << "Unesite ime i prezime kupca: ";
                                cin.ignore(100, '\n');
                                std::getline(std::cin, ime_i_prezime);
                                std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                std::cin >> dan >> temp >> mjesec >> temp >> godina;
                                try {
                                    v2.push_back(std::make_shared < Kupac > (ime_i_prezime, Datum(dan, mjesec, godina)));
                                    std::cout << "Kupac je uspjesno dodan!" << std::endl << std::endl;
                                } catch (std::exception & e) {
                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                    unos = true;
                                    cin.clear();
                                }
                            } while (unos);
                        }
                        break;
                        // UREDJIVANJE KUPACA PROMJENA KUPCA
                    case 2:
                        {
                            if (v2.empty()) {
                                std::cout << "Nema dostupni kupaca" << std::endl;
                                break;
                            }
                            std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << std::endl;
                            for (int i = 0; i < v2.size(); i++) {
                                std::cout << " " << i + 1 << " - ";
                                v2[i] - > Ispisi();
                                std::cout << std::endl;
                            }
                            int br_kupca;
                            std::cin >> br_kupca;
                            if (br_kupca < 1 or br_kupca > v2.size()) {
                                std::cout << "Neispravan broj kupca" << std::endl;
                                break;
                            }
                            bool unos(false);
                            std::string ime_i_prezime;
                            int dan,
                            mjesec,
                            godina;
                            char temp;
                            do {
                                unos = false;

                                cin.ignore(100, '\n');
                                std::cout << "Unesite ime i prezime kupca: ";
                                std::getline(std::cin, ime_i_prezime);
                                std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                std::cin >> dan >> temp >> mjesec >> temp >> godina;
                                try {
                                    v2[br_kupca - 1] - > Postavi(ime_i_prezime, Datum(dan, mjesec, godina));
                                    std::cout << "Kupac je uspjesno izmijenjen!" << std::endl << std::endl;
                                } catch (std::exception & e) {
                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                    unos = true;
                                    cin.clear();
                                }
                            } while (unos);
                        }
                        break;
                        // CASE 3
                    case 3:
                        {
                            if (v2.empty()) {
                                std::cout << "Nema dostupni kupaca" << std::endl;
                                break;
                            }
                            for (int i = 0; i < v2.size(); i++) {
                                v2[i] - > Ispisi();
                                std::cout << std::endl;
                            }
                        }
                        break;
                        // CASE 4
                    case 4:
                        nije_kraj = false;
                        break;
                    }
                } while (opcija2 != 0 and opcija2 != 4);
            }
            break;
            // CASE 3 UREDJIVANJE PRODAJA
        case 3:
            {
                do {
                    std::cout << "Izaberite opciju:" << std::endl;
                    std::cout << " 0 - nazad" << std::endl;
                    std::cout << " 1 - dodavanje prodaje" << std::endl;
                    std::cout << " 2 - uredjivanje prodaje" << std::endl;
                    std::cout << " 3 - ispis prodaja" << std::endl;
                    std::cout << " 4 - brisanje prodaja" << std::endl;
                    std::cout << " 5 - kraj" << std::endl;
                    std::cin >> opcija2;
                    switch (opcija2) {
                        // NAZAD CASE 0
                    case 0:
                        break;
                        // DODAVANJE PRODAJE
                    case 1:
                        {
                            int opcija3;
                            do {
                                std::cout << "Izaberite opciju:" << std::endl;
                                std::cout << " 0 - nazad" << std::endl;
                                std::cout << " 1 - dodavanje potpuno nove prodaje" << std::endl;
                                std::cout << " 2 - dodavanje nove prodaje na osnovu arhive" << std::endl;
                                std::cout << " 3 - kraj" << std::endl;
                                std::cin >> opcija3;
                                switch (opcija3) {
                                    // NAZAD
                                case 0:
                                    break;
                                    // DODAVANJE POTPUNO NOVE PRODAJE
                                case 1:
                                    {
                                        std::string ime_agenta_prodaje;
                                        int dan1,
                                        dan2,
                                        mjesec1,
                                        mjesec2,
                                        godina1,
                                        godina2;
                                        int cijena_stana,
                                        sprat,
                                        broj_soba;
                                        int namjesten;
                                        double kvadratura;
                                        char t;
                                        std::string ime_kupca;
                                        std::string adresa;
                                        bool unos(false);
                                        do {
                                            unos = false;
                                            std::cout << "Unesite ime i prezime agenta prodaje: ";
                                            cin.ignore(100, '\n');
                                            std::getline(cin, ime_agenta_prodaje);
                                            std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                            std::cin >> dan1 >> t >> mjesec1 >> t >> godina1;
                                            std::cout << "Unesite cijenu stana: ";
                                            std::cin >> cijena_stana;
                                            std::cout << "Unesite ime kupca: ";
                                            cin.ignore(100, '\n');
                                            std::getline(cin, ime_kupca);
                                            std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                                            std::cin >> dan2 >> t >> mjesec2 >> t >> godina2;
                                            std::cout << "Unesite adresu: ";
                                            cin.ignore(100, '\n');
                                            std::getline(cin, adresa);
                                            std::cout << "Unesite sprat: ";
                                            std::cin >> sprat;
                                            std::cout << "Unesite broj soba: ";
                                            std::cin >> broj_soba;
                                            std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                            std::cin >> namjesten;
                                            std::cout << "Unesite kvadraturu: ";
                                            std::cin >> kvadratura;
                                            try {
                                                if (namjesten < 0o r namjesten > 1) throw std::domain_error("Neispravan unos podataka");
                                                v1.push_back(std::make_shared < Stan > (adresa, sprat, broj_soba, namjesten, kvadratura));
                                                v2.push_back(std::make_shared < Kupac > (ime_kupca, Datum(dan2, mjesec2, godina2)));
                                                pr_test.RegistrirajProdaju(ime_agenta_prodaje, cijena_stana, dan1, mjesec1, godina1, ime_kupca, Datum(dan2, mjesec2, godina2), adresa, sprat, broj_soba, namjesten, kvadratura);
                                                std::cout << "Prodaja uspjesno dodana!" << std::endl << std::endl;
                                            } catch (std::range_error e) {
                                                std::cout << "Izuzetak: " << e.what() << std::endl;
                                                break;
                                            } catch (std::exception & e) {
                                                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                unos = true;
                                                cin.clear();
                                            }
                                        } while (unos);
                                    }
                                    break;
                                    // CASE 2 DODAVANJE PRODAJE NA OSNOVU ARHIVA
                                case 2:
                                    {
                                        std::string ime_agenta_prodaje;
                                        int dan,
                                        mjesec,
                                        godina;
                                        double cijena_stana;
                                        char t;
                                        std::cout << "Unesite ime i prezime agenta prodaje: ";
                                        cin.ignore(100, '\n');
                                        std::getline(cin, ime_agenta_prodaje);
                                        std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                        std::cin >> dan >> t >> mjesec >> t >> godina;
                                        std::cout << "Unesite cijenu stana: ";
                                        std::cin >> cijena_stana;
                                        if (v2.empty()) {
                                            std::cout << "Nema dostupni kupaca" << std::endl;
                                            break;
                                        }
                                        std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                                        for (int i = 0; i < v2.size(); i++) {
                                            std::cout << " " << i + 1 << " - ";
                                            v2[i] - > Ispisi();
                                            std::cout << std::endl;
                                        }
                                        int br_kupca;
                                        std::cin >> br_kupca;
                                        if (br_kupca < 1 or br_kupca > v2.size()) {
                                            std::cout << "Neispravan broj kupca" << std::endl;
                                            break;
                                        }
                                        if (v1.empty()) {
                                            std::cout << "Nema dostupni stanova" << std::endl;
                                            break;
                                        }
                                        std::cout << "Odaberite stan. Dostupni stanovi su: " << std::endl;
                                        for (int i = 0; i < v1.size(); i++) {
                                            std::cout << " " << i + 1 << " - ";
                                            v1[i] - > Ispisi();
                                            std::cout << std::endl;
                                        }
                                        int br_stana;
                                        std::cin >> br_stana;
                                        if (br_stana < 1 or br_stana > v1.size()) {
                                            std::cout << "Neispravan broj stana" << std::endl;
                                            break;
                                        }
                                        try {
                                            pr_test.RegistrirajProdaju(ime_agenta_prodaje, cijena_stana, Datum(dan, mjesec, godina), * v2[br_kupca - 1], * v1[br_stana - 1]);
                                            std::cout << "Prodaja uspjesno dodana!" << std::endl;
                                        } catch (std::range_error e) {
                                            std::cout << "Izuzetak: " << e.what() << std::endl;
                                            break;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                            break;
                                            cin.clear();
                                        }
                                    }
                                    break;
                                    // CASE 3
                                case 3:
                                    nije_kraj = false;
                                    break;
                                }
                            } while (opcija3 != 3 and opcija3 != 0);
                        }
                        break;

                        // UREDJIVANJE PRODAJE
                    case 2:
                        {
                            std::cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su:" << std::endl;
                            if (pr_test.DajBrojProdaja() == 0) {
                                std::cout << "Nema dostupni prodaja" << std::endl;
                                break;
                            }
                            for (int i = 0; i < pr_test.DajBrojProdaja(); i++) {
                                std::cout << i + 1 << "." << std::endl;
                                pr_test.DajProdaju(i + 1).Ispisi();

                            }
                            int br_prodaje;
                            std::cin >> br_prodaje;
                            if (br_prodaje < 1 or br_prodaje > pr_test.DajBrojProdaja()) {
                                std::cout << "Neispravan broj prodaje" << std::endl;
                                break;
                            }
                            int opcija_izmjena_prodaje;
                            std::cout << "Izaberite opciju:" << std::endl;
                            std::cout << " 0 - nazad" << std::endl;
                            std::cout << " 1 - izmjena agenta" << std::endl;
                            std::cout << " 2 - izmjena datuma prodaje" << std::endl;
                            std::cout << " 3 - izmjena kupca" << std::endl;
                            std::cout << " 4 - izmjena stana" << std::endl;
                            std::cout << " 5 - izmjena cijene stana" << std::endl;
                            std::cin >> opcija_izmjena_prodaje;
                            switch (opcija_izmjena_prodaje) {

                            case 0:
                                break;
                                // UREDJIVANJE PRODAJA PROMJENA AGENT
                            case 1:
                                {
                                    std::string ime_agenta_prodaje;
                                    bool unos(false);
                                    do {
                                        std::cout << "Unesite ime i prezime agenta prodaje: ";
                                        cin.ignore(100, '\n');
                                        std::getline(cin, ime_agenta_prodaje);
                                        unos = false;
                                        try {
                                            pr_test.DajProdaju(br_prodaje).PromjeniAgenta(ime_agenta_prodaje);
                                            std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                            unos = true;
                                            cin.clear();
                                        }
                                    } while (unos);
                                }
                                break;
                                // UREDJIVANJE PRODAJE IZMJENA DATUMA PRODAJE
                            case 2:
                                {
                                    int dan,
                                    mjesec,
                                    godina;
                                    char t;
                                    bool unos(false);
                                    do {
                                        std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                        std::cin >> dan >> t >> mjesec >> t >> godina;
                                        unos = false;
                                        try {
                                            pr_test.DajProdaju(br_prodaje).PromijeniDatumKupovine(Datum(dan, mjesec, godina));
                                            std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                            unos = true;
                                            cin.clear();
                                        }
                                    } while (unos);
                                }
                                break;
                                // UREDJIVANJE PRODAJE IZMJENA KUPCA
                            case 3:
                                {
                                    std::cout << "Izaberite opciju:" << std::endl;
                                    std::cout << " 0 - nazad" << std::endl;
                                    std::cout << " 1 - odabir postojeceg kupca" << std::endl;
                                    std::cout << " 2 - dodavanje novog kupca" << std::endl;
                                    int opcija3;
                                    std::cin >> opcija3;
                                    switch (opcija3) {
                                    case 0:
                                        break;
                                    case 1:
                                        {
                                            if (v2.empty()) {
                                                std::cout << "Nema dostupni kupaca" << std::endl;
                                                break;
                                            }
                                            std::cout << "Odaberite kupca. Dostupni kupci su:" << std::endl;
                                            for (int i = 0; i < v2.size(); i++) {
                                                std::cout << i + 1 << " - ";
                                                v2[i] - > Ispisi();
                                                std::cout << std::endl;
                                            }
                                            int br_kupca;
                                            std::cin >> br_kupca;
                                            if (br_kupca < 1 or br_kupca > v2.size()) {
                                                std::cout << "Neispravan broj kupca" << std::endl;
                                                break;
                                            }
                                            try {
                                                pr_test.DajProdaju(br_prodaje).PromijeniKupca( * v2[br_kupca - 1]);
                                                std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                                            } catch (std::exception & e) {
                                                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                break;
                                                cin.clear();
                                            }

                                        }
                                        break;
                                        // CASE 2 DODAVANJE KUPCA
                                    case 2:
                                        {
                                            std::string ime_kupca;
                                            int dan,
                                            mjesec,
                                            godina;
                                            char t;
                                            bool unos(false);
                                            do {
                                                unos = false;
                                                std::cout << "Unesite ime i prezime kupca: ";
                                                cin.ignore(100, '\n');
                                                std::getline(cin, ime_kupca);
                                                std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                                std::cin >> dan >> t >> mjesec >> t >> godina;
                                                try {
                                                    pr_test.DajProdaju(br_prodaje).PromijeniKupca(Kupac(ime_kupca, Datum(dan, mjesec, godina)));
                                                    v2.push_back(std::make_shared < Kupac > (ime_kupca, Datum(dan, mjesec, godina)));
                                                    std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                                                } catch (std::exception & e) {
                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                    unos = true;
                                                    cin.clear();
                                                }
                                            } while (unos);
                                        }
                                        break;
                                    }
                                }
                                break;
                                // UREDJIVANJE PRODAJA IZMJENA STANA
                            case 4:
                                {
                                    std::cout << "Izaberite opciju:" << std::endl;
                                    std::cout << " 0 - nazad" << std::endl;
                                    std::cout << " 1 - odabir postojeceg kupca" << std::endl;
                                    std::cout << " 2 - dodavanje novog stana" << std::endl;
                                    int opcija3;
                                    std::cin >> opcija3;
                                    switch (opcija3) {
                                    case 0:
                                        break;
                                    case 1:
                                        {
                                            if (v1.empty()) {
                                                std::cout << "Nema dostupni stanova" << std::endl;
                                                break;
                                            }
                                            std::cout << "Odaberite stan. Dostupni stanovi su: " << std::endl;
                                            for (int i = 0; i < v1.size(); i++) {
                                                std::cout << i + 1 << " - ";
                                                v1[i] - > Ispisi();
                                                std::cout << std::endl;
                                            }
                                            int br_stana;
                                            std::cin >> br_stana;
                                            if (br_stana < 1 or br_stana > v1.size()) {
                                                std::cout << "Neispravan broj stana" << std::endl;
                                                break;
                                            }
                                            try {
                                                pr_test.DajProdaju(br_prodaje).PromijeniStan( * v1[br_stana - 1]);
                                                std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                                            } catch (std::exception & e) {
                                                break;
                                                cin.clear();
                                            }
                                        }
                                        break;
                                        // CASE 2 DODAVANJE KUPCA
                                    case 2:
                                        {
                                            bool unos(false);
                                            std::string adresa;
                                            int sprat,
                                            broj_soba;
                                            bool namjesten;
                                            double kvadratura;
                                            do {
                                                unos = false;
                                                std::cout << "Unesite adresu: ";
                                                cin.ignore(100, '\n');
                                                std::getline(std::cin, adresa);
                                                std::cout << "Unesite sprat: ";
                                                std::cin >> sprat;
                                                std::cout << "Unesite broj soba: ";
                                                std::cin >> broj_soba;
                                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                                std::cin >> namjesten;

                                                std::cout << "Unesite kvadraturu: ";
                                                std::cin >> kvadratura;
                                                try {
                                                    v1.push_back(std::make_shared < Stan > (adresa, sprat, broj_soba, namjesten, kvadratura));
                                                    pr_test.DajProdaju(br_prodaje).PromijeniStan(Stan(adresa, sprat, broj_soba, namjesten, kvadratura));
                                                    std::cout << "Prodaja uspjesno izmjenjena!" << std::endl << std::endl;
                                                } catch (std::exception & e) {
                                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                                    unos = true;
                                                    cin.clear();

                                                }
                                            } while (unos);
                                        }
                                    }
                                }
                                break;
                                // CASE 5 IZMJENA CIJENE STANA
                            case 5:
                                {
                                    double cijena_stana;
                                    bool unos(false);
                                    do {
                                        std::cout << "Unesite cijenu stana: ";
                                        cin >> cijena_stana;
                                        unos = false;
                                        try {
                                            pr_test.DajProdaju(br_prodaje).PromijeniCijenuProdaje(cijena_stana);
                                            std::cout << "Prodaja je uspjesno izmijenjena!" << std::endl << std::endl;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet." << std::endl;
                                            unos = true;
                                            cin.clear();
                                        }
                                    } while (unos);
                                }
                                break;
                            }
                        }
                        break;
                        // CASE 3 ISPIS PRODAJA
                    case 3:
                        {
                            int opcija3;
                            do {
                                std::cout << "Izaberite opciju:" << std::endl;
                                std::cout << " 0 - nazad" << std::endl;
                                std::cout << " 1 - ispis svih prodaja" << std::endl;
                                std::cout << " 2 - ispis prodaja na datum" << std::endl;
                                std::cout << " 3 - ispis najranije prodaje" << std::endl;
                                std::cout << " 4 - ispis najskuplje prodaje" << std::endl;
                                std::cout << " 5 - ispis broja prodaja" << std::endl;
                                std::cout << " 6 - ispis broja prodaja po datumu" << std::endl;
                                std::cout << " 7 - ispis broja prodaja po agentu" << std::endl;
                                std::cout << " 8 - kraj" << std::endl;
                                cin >> opcija3;
                                switch (opcija3) {
                                    // CASE 0 NAZAD
                                case 0:
                                    break;
                                    // CASE 1 ISPIS SVIH PRODAJA
                                case 1:
                                    {
                                        pr_test.IspisiSveProdaje();
                                    }
                                    break;
                                    // CASE 2 ISPIS PRODAJA NA DATUM
                                case 2:
                                    {
                                        char t;
                                        int dan,
                                        mjesec,
                                        godina;
                                        bool unos(false);
                                        do {
                                            unos = false;
                                            std::cout << "Unesite datum (d/m/g): ";
                                            cin >> dan >> t >> mjesec >> t >> godina;
                                            try {
                                                pr_test.IspisiProdajeNaDatum(Datum(dan, mjesec, godina));
                                            } catch (std::exception & e) {
                                                std::cout << "Izuzetak: " << e.what() << ".Molimo unesite ponovo." << std::endl;
                                                unos = true;
                                            }
                                        } while (unos);
                                    }
                                    break;
                                    // CASE 3 ISPIS NAJRANIJE PRODAJE
                                case 3:
                                    {
                                        pr_test.DajNajranijuProdaju().Ispisi();
                                        std::cout << std::endl;
                                    }
                                    break;
                                    // CASE 4 ISPIS NAJSKUPLJE PRODAJE
                                case 4:
                                    {
                                        pr_test.DajNajskupljuProdaju().Ispisi();
                                        std::cout << std::endl;
                                    }
                                    break;
                                    // CASE 5 ISPIS BROJA PRODAJA
                                case 5:
                                    {
                                        std::cout << pr_test.DajBrojProdaja() << std::endl;
                                    }
                                    break;
                                    // CASE 6 ISPIS BROJA PRODAJA PO DATUMU
                                case 6:
                                    {
                                        char t;
                                        int dan,
                                        mjesec,
                                        godina;
                                        bool unos(false);
                                        do {
                                            unos = false;
                                            std::cout << "Unesite datum (d/m/g): ";
                                            cin >> dan >> t >> mjesec >> t >> godina;
                                            try {
                                                std::cout << pr_test.DajBrojProdajaNaDatum(Datum(dan, mjesec, godina)) << std::endl;
                                            } catch (std::exception & e) {
                                                std::cout << "Izuzetak: " << e.what() << ".Molimo unesite ponovo." << std::endl;
                                                unos = true;
                                            }
                                        } while (unos);
                                    }
                                    break;
                                    // CASE 7 ISPIS BROJA PRODAJA PO AGENTU
                                case 7:
                                    {
                                        std::string ime_agenta;
                                        bool unos(false);
                                        do {
                                            unos = false;
                                            std::cout << "Unesite ime agenta: ";
                                            cin.ignore(100, '\n');
                                            std::getline(cin, ime_agenta);
                                            try {
                                                std::cout << pr_test.DajBrojProdajaOdAgenta(ime_agenta) << std::endl;
                                            } catch (std::exception & e) {
                                                std::cout << "Izuzetak: " << e.what() << ".Molimo unesite ponovo." << std::endl;
                                                unos = true;
                                            }
                                        } while (unos);
                                    }
                                    break;
                                    // CASE 8 KRAJ
                                case 8:
                                    {
                                        nije_kraj = false;
                                        break;
                                    }
                                    break;
                                }
                            } while (opcija3 != 0 and opcija3 != 8);
                        }
                        break;
                        // CASE 4 BRISANJE PRODAJA
                    case 4:
                        {
                            int opcija3;
                            do {
                                std::cout << "Izaberite opciju:" << std::endl;
                                std::cout << " 0 - nazad" << std::endl;
                                std::cout << " 1 - brisanje najranije prodaje" << std::endl;
                                std::cout << " 2 - brisanje prodaja agenta" << std::endl;
                                std::cout << " 3 - brisanje prodaja po datumu" << std::endl;
                                std::cout << " 4 - brisanje svih prodaja" << std::endl;
                                cin >> opcija3;
                                switch (opcija3) {
                                    // CASE 0
                                case 0:
                                    break;
                                    // CASE 1
                                case 1:
                                    {
                                        try {
                                            pr_test.ObrisiNajranijuProdaju();
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak : " << e.what() << std::endl;
                                        }
                                    }
                                    break;
                                    // CASE 2
                                case 2:
                                    {
                                        std::string ime_agenta;
                                        std::cout << "Unesite ime agenta: ";
                                        cin.ignore(100, '\n');
                                        std::getline(cin, ime_agenta);
                                        try {
                                            pr_test.ObrisiProdajeAgenta(ime_agenta);
                                            std::cout << "Sve prodaje tog agenta su obrisane." << std::endl;
                                        } catch (std::exception & e) {
                                            std::cout << "Izuzetak: " << e.what() << ".Molimo unesite ponovo." << std::endl;

                                        }
                                    }
                                    break;
                                    // CASE 3
                                case 3:
                                    {
                                        char t;
                                        int dan,
                                        mjesec,
                                        godina;
                                        bool unos(false);
                                        do {
                                            unos = false;
                                            std::cout << "Unesite datum (d/m/g): ";
                                            cin >> dan >> t >> mjesec >> t >> godina;
                                            try {
                                                pr_test.ObrisiProdajeNaDatum(Datum(dan, mjesec, godina));
                                                std::cout << "Sve prodaje na taj datum su obrisane." << std::endl;
                                            } catch (std::exception & e) {
                                                std::cout << "Izuzetak: " << e.what() << ".Molimo unesite ponovo." << std::endl;
                                                unos = true;
                                            }
                                        } while (unos);
                                    }
                                    break;
                                    // CASE 4
                                case 4:
                                    {
                                        pr_test.IsprazniKolekciju();
                                        std::cout << "Sve prodaje su obrisane." << std::endl;
                                    }
                                    break;
                                }
                            } while (opcija3 != 0);
                        }
                        break;
                        // CASE 5 KRAJ
                    case 5:
                        {

                        }
                        break;
                    }
                } while (opcija2 != 0 and opcija2 != 4);
            }
            break;
        }
    } while (nije_kraj);
    std::cout << std::endl;
    std::cout << "Dovidjenja!" << std::endl;

    return 0;

}