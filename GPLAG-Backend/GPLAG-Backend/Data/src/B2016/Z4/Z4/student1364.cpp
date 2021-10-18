/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <memory>

using std::cin; using std::cout; using std::endl;

class Datum {
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const { cout << dan << "/" << mjesec << "/" << godina; }
    friend class Kupac;
};

//Metode za klasu Datum
void Datum::Postavi(int d, int m, int g) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m-1])
    throw std::domain_error("Neispravan datum");
    dan = d; mjesec = m; godina = g;
}

class Kupac {
    std::string i_i_p;
    Datum dat_rodj;
    public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja): 
    dat_rodj(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()) 
    { Postavi(ime_i_prezime, datum_rodjenja); }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja);
    std::string DajImePrezime() const { return i_i_p; }
    Datum DajDatumRodjenja() const { return dat_rodj; }
    void Ispisi() const { cout << i_i_p << "("; dat_rodj.Ispisi(); cout<< ")"; }
};

//Metode za klasu Kupac
void Kupac::Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja)  {
    for (int i=0; i<ime_i_prezime.size(); i++) {
        if (!((ime_i_prezime[i]>='a' && ime_i_prezime[i]<='z') || (ime_i_prezime[i]>='A' && ime_i_prezime[i]<='Z') || (ime_i_prezime[i]>='0' && ime_i_prezime[i]<='9') || ime_i_prezime[i]==' ' || ime_i_prezime[i]=='-' || ime_i_prezime[i]=='\'' ))
        throw std::domain_error ("Neispravno ime i prezime");
    }
    i_i_p=ime_i_prezime;
    dat_rodj=datum_rodjenja;
}

class Stan {
    std::string adresa;
    int sprat, br_soba;
    bool namjesten;
    double kvadratura;
    public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa, sprat, broj_soba, namjesten, kvadratura); }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return br_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const { 
        //Je li nova recenica u novom redu?
        cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima ";
        if (br_soba==1) cout << br_soba << " sobu."; //Ako je zadnja cifra jedan
        if (br_soba==2 || br_soba==3 || br_soba==4) cout << br_soba << " sobe."; //Da li ce biti prko 20 soba?
        if (br_soba>=5) cout << br_soba << " soba.";
        cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan "; //Provjeri ovo!
        if (DajNamjesten()) cout <<"je namjesten.";
        else cout << "nije namjesten.";
    }
};

//Metode za klasu Stan
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    if (sprat<0 || broj_soba<0 || kvadratura<0) throw std::domain_error ("Neispravan unos podataka");
    Stan::adresa=adresa; Stan::sprat=sprat; br_soba=broj_soba; Stan::namjesten=namjesten; Stan::kvadratura=kvadratura;
}

class Prodaja {
    std::string ime_agenta;
    double cijena;
    Datum dat_pr;
    Kupac kupac;
    Stan stan;
    public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata); 
    void PromijeniKupca(const Kupac &novi_kupac) { kupac =novi_kupac; }
    void PromijeniStan(const Stan &novi_stan) { stan = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { dat_pr=novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena = nova_cijena;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime_agenta; }
    std::string DajImeKupca() const { return kupac.DajImePrezime(); }
    Datum DajDatumProdaje() const { return dat_pr; }
    double DajCijenuStana() const { return cijena; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

//Metode za klasu Prodaja
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : 
    dat_pr(datum_prodaje.DajDan(), datum_prodaje.DajMjesec(), datum_prodaje.DajGodinu()), kupac(kupac_stana.DajImePrezime(), kupac_stana.DajDatumRodjenja()),
    stan(kupljeni_stan.DajAdresu(), kupljeni_stan.DajSprat(), kupljeni_stan.DajBrojSoba(), kupljeni_stan.DajNamjesten(), kupljeni_stan.DajKvadraturu()) {
        //Da li iz konstruktora smijemo pozivati konstruktor?
        ime_agenta=ime_agenta_prodaje; cijena=cijena_stana;
}
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana,
    int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
    std::string &ime_kupca, const Datum &datum_rodjenja_kupca,
    const std::string &adresa_stana, int sprat_stana, int broj_soba,
    bool namjesten_stan, double broj_kvadrata) : dat_pr(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac(ime_kupca, datum_rodjenja_kupca), 
    stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {
        ime_agenta=ime_agenta_prodaje; cijena=cijena_stana;
}
  // treba podržati i funkcije “PomjeriDanUnaprijed” i “PomjeriDanUnazad” koje pomjeraju zakazani datum prodaje za jedan dan unaprijed odnosno unazad.   
void Prodaja::PomjeriDanUnaprijed() {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    auto dat(this->DajDatumProdaje());
    auto dan(dat.DajDan());
    auto mjesec(dat.DajMjesec());
    auto godina(dat.DajGodinu());
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++; //Ako je prestupna
    if (dan==broj_dana[mjesec-1]) {
        dan=1; 
        if (mjesec==12) {
            mjesec=1; godina++;
        }
        else mjesec++;
    }
    else dan++;
    this->PromijeniDatumKupovine(Datum(dan, mjesec, godina));
}
void Prodaja::PomjeriDanUnazad() {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    auto dat(this->DajDatumProdaje());
    auto dan(dat.DajDan());
    auto mjesec(dat.DajMjesec());
    auto godina(dat.DajGodinu());
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++; //Ako je prestupna
    if (dan==1) {
        if (mjesec==1) { mjesec=12; godina--; }
        else mjesec--;
        dan=broj_dana[mjesec-1];
    }
    else dan--;
    this->PromijeniDatumKupovine(Datum(dan, mjesec, godina));
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    //vraća “true” ukoliko je prva prodaja zakazana prije druge
    if (p1.DajDatumProdaje().DajGodinu() < p2.DajDatumProdaje().DajGodinu()) return true;
    if (p1.DajDatumProdaje().DajGodinu() == p2.DajDatumProdaje().DajGodinu()) {
        if (p1.DajDatumProdaje().DajMjesec() < p2.DajDatumProdaje().DajMjesec()) return true;
        if (p1.DajDatumProdaje().DajMjesec() == p2.DajDatumProdaje().DajMjesec()) {
            if (p1.DajDatumProdaje().DajDan() < p2.DajDatumProdaje().DajDan()) return true; //Ako je ista godina i mjesec
        }
    }
    return false;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    if (p1.cijena>p2.cijena) return true;
    return false;
}
void Prodaja::Ispisi() const {
    cout << std::setw(30) << "Ime agenta: " << ime_agenta << endl;
    cout << std::setw(30) << "Ime kupca: ";  kupac.Ispisi(); cout << endl;
    cout << std::setw(30) << "Zakazani datum prodaje: "; dat_pr.Ispisi() ; cout << endl;
    cout << std::setw(30) << "Cijena stana: " << cijena << endl;
    cout << std::setw(30) << "Informacije o stanu: " << endl; stan.Ispisi(); cout << endl;
}

class Prodaje {
    std::vector<std::shared_ptr<Prodaja>>prodaje_pok;
    static bool JednakDatum(Datum dat1, Datum dat2);
    public:
    explicit Prodaje(int max_broj_prodaja) { prodaje_pok.resize(max_broj_prodaja); }
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    //~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje) = default;
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje) = default;
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje,
    double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
    int DajBrojProdaja() const { return prodaje_pok.size(); }
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

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
    prodaje_pok.resize(spisak_prodaja.size());
    std::initializer_list<Prodaja>::iterator it{spisak_prodaja.begin()};
	int i(0);
	while (it!=spisak_prodaja.end()) {
		prodaje_pok[i]=std::make_shared<Prodaja>(*it);
		it++; i++;
    }
}
Prodaje::Prodaje(const Prodaje &prodaje) {
    prodaje_pok.resize(prodaje.prodaje_pok.size());
	for (int i=0; i<prodaje.prodaje_pok.size(); i++) 
	 prodaje_pok[i]= std::make_shared<Prodaja>(*prodaje.prodaje_pok[i]);
}
Prodaje &Prodaje::operator =(const Prodaje &prodaje) {
    prodaje_pok.resize(prodaje.prodaje_pok.size());
    for (int i=0; i<prodaje.prodaje_pok.size(); i++) {
        prodaje_pok[i]=std::make_shared<Prodaja>(*prodaje.prodaje_pok[i]);
    }
	return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
    const Stan &kupljeni_stan) {
        //Kreiramo novu prodaju
        auto pnp(std::make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan));
        prodaje_pok.push_back(pnp);
    }
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
    int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana,
    int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
        auto pnp(std::make_shared<Prodaja>(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana,
        sprat_stana, broj_soba, namjesten_stan, broj_kvadrata));
        prodaje_pok.push_back(pnp);
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    auto pnp (std::make_shared<Prodaja>(*prodaja));
    prodaje_pok.push_back(pnp);

}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(prodaje_pok.begin(), prodaje_pok.end(), [datum] (std::shared_ptr<Prodaja> p) -> bool {
        Datum d(p->DajDatumProdaje());
        if (d.DajDan()==datum.DajDan() && d.DajMjesec()==datum.DajMjesec() && d.DajGodinu()==datum.DajGodinu()) return true;
        return false;
    });
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return std::count_if(prodaje_pok.begin(), prodaje_pok.end(), [ime_agenta] (std::shared_ptr<Prodaja> p) -> bool {
        auto i_a(p->DajImeAgenta());
        if (i_a==ime_agenta) return true;
        return false;
    });
}
Prodaja &Prodaje::DajNajranijuProdaju() { //Pazi gdje stavljas &!
    if (prodaje_pok.size()==0) throw std::domain_error ("Nema registriranih prodaja");
    return **(std::min_element(prodaje_pok.begin(), prodaje_pok.end(), [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) -> bool {
        auto dat1(p1->DajDatumProdaje()), dat2(p2->DajDatumProdaje());
        if (dat1.DajGodinu()==dat2.DajGodinu()) {
            if (dat1.DajMjesec()==dat2.DajMjesec()) {
                return dat1.DajDan()<dat2.DajDan();
            }
            else return dat1.DajMjesec()<dat2.DajMjesec();
        }
        else return dat1.DajGodinu()<dat2.DajGodinu();
    }));
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    if (prodaje_pok.size()==0) throw std::domain_error ("Nema registriranih prodaja");
    auto p(std::min_element(prodaje_pok.begin(), prodaje_pok.end(), [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) -> bool {
        auto dat1(p1->DajDatumProdaje()), dat2(p2->DajDatumProdaje());
        if (dat1.DajGodinu()==dat2.DajGodinu()) {
            if (dat1.DajMjesec()==dat2.DajMjesec()) {
                return dat1.DajDan()<dat2.DajDan();
            }
            else return dat1.DajMjesec()<dat2.DajMjesec();
        }
        else return dat1.DajGodinu()<dat2.DajGodinu();
    }));
    return **p; 
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    if (prodaje_pok.size()==0) throw std::domain_error ("Nema registriranih prodaja");
    auto p(std::max_element(prodaje_pok.begin(), prodaje_pok.end(), [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) -> bool {
        auto c1(p1->DajCijenuStana()), c2(p2->DajCijenuStana());
        return c1<c2;
    }));
    return **p; 
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    if (prodaje_pok.size()==0) throw std::domain_error ("Nema registriranih prodaja");
    auto p(std::max_element(prodaje_pok.begin(), prodaje_pok.end(), [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) -> bool {
        auto c1(p1->DajCijenuStana()), c2(p2->DajCijenuStana());
        return c1<c2;
    }));
    return **p; 
}
void Prodaje::IsprazniKolekciju() {
    for (int i=prodaje_pok.size()-1; i>=0; i--) {
        prodaje_pok[i]=nullptr;
        prodaje_pok.erase(prodaje_pok.begin()+i);
    }
}
void Prodaje::ObrisiNajranijuProdaju() {
    if (prodaje_pok.size()==0) throw std::range_error("Prazna kolekcija");
    for (int i=0; i<prodaje_pok.size(); i++) {
        if (JednakDatum(prodaje_pok[i]->DajDatumProdaje(), DajNajranijuProdaju().DajDatumProdaje())) {
            prodaje_pok.erase(prodaje_pok.begin()+i);
            return;
        }
    }
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
     if (prodaje_pok.size()==0) return;
     for (int i=0; i<prodaje_pok.size(); i++) {
        if (prodaje_pok[i]->DajImeAgenta()==ime_agenta) {
            prodaje_pok.erase(prodaje_pok.begin()+i); 
        }
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    if (prodaje_pok.size()==0) return;
    for (int i=0; i<prodaje_pok.size(); i++) {
        if (JednakDatum(prodaje_pok[i]->DajDatumProdaje(), datum)) {
            prodaje_pok.erase(prodaje_pok.begin()+i);
        }
    }
}
bool Prodaje::JednakDatum(Datum dat1, Datum dat2) {
    if (dat1.DajGodinu()==dat2.DajGodinu() && dat1.DajMjesec()==dat2.DajMjesec() && dat1.DajDan()==dat2.DajDan())
    return true;
    return false;
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    int broj_prodaja_na_datum(DajBrojProdajaNaDatum(datum));
    std::vector<std::shared_ptr<Prodaja>> pomocni(broj_prodaja_na_datum);
    for (int i=0; i<broj_prodaja_na_datum; i++) {
        if (JednakDatum(prodaje_pok[i]->DajDatumProdaje(), datum))
        pomocni[i]=std::make_shared<Prodaja>(*(prodaje_pok[i]));
    }
    std::sort(pomocni.begin(), pomocni.end(), [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) -> bool {
        return p1->DajImeKupca()<p2->DajImeKupca();
    });
    //Ispisimo
    for (int i=0; i<broj_prodaja_na_datum; i++) {
        pomocni[i]->Ispisi();
    }
}
void Prodaje::IspisiSveProdaje() const { //Ne smij promijeniti sadrzaj objekta nad kojim se poziva
    //Sortirajmo
    std::vector<std::shared_ptr<Prodaja>> pomocni(prodaje_pok.size());
    for (int i=0; i<prodaje_pok.size(); i++) {
        pomocni[i]=std::make_shared<Prodaja>(*(prodaje_pok[i]));
    }
    std::sort(pomocni.begin(), pomocni.end(), [] (std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) -> bool {
        auto dat1(p1->DajDatumProdaje()), dat2(p2->DajDatumProdaje());
        if (dat1.DajGodinu()==dat2.DajGodinu()) {
            if (dat1.DajMjesec()==dat2.DajMjesec()) {
                if (dat1.DajDan()==dat2.DajDan()) {
                    return p1->DajImeKupca()<p2->DajImeKupca();
                }
                return dat1.DajDan()<dat2.DajDan();
            }
            return dat1.DajMjesec()<dat2.DajMjesec();
        }
        return dat1.DajGodinu()<dat2.DajGodinu();
    });
    //Ispisimo
    for (int i=0; i<prodaje_pok.size(); i++) {
        pomocni[i]->Ispisi();
    }
}

int main () {
    std::vector<Stan> stanovi; std::vector<Kupac> kupci; std::vector<Prodaja> v_prodaja;
    cout << "Dobrodosli!" << endl << " " << endl << " " << endl;
    int opcija1(-1);
    do {
        cout << "Izaberite opciju:" << endl;
        cout << " 0 - kraj" << endl << " 1 - uredjivanje stanova" << endl << " 2 - uredjivanje kupaca" << endl <<
        " 3 - uredjivanje prodaja" << endl; 
        cin >> opcija1;
        if (opcija1==0) break;
        if (opcija1==1) {
            int opcija_s(-1);
            do {
            cout << "Izaberite opciju:" << endl;
            cout << " 0 - nazad" << endl << " 1 - dodavanje stana" << endl << " 2 - uredjivanje stanova" << endl <<
            " 3 - ispis svih stanova" << endl << " 4 - kraj" << endl;
            cin >> opcija_s;
            if (opcija_s==0) break;
            if (opcija_s==1) {
                //Dodajemo stan
                bool unos(false);
                do {
                    std::string adresa;
                    cout << "Unesite adresu: ";
                    cin.ignore(10000, '\n');
                    getline (cin, adresa);
                    int sprat(-1), broj_soba(-1);
                    cout << "Unesite sprat: ";
                    cin >> sprat;
                    cout << "Unesite broj soba: ";
                    cin >> broj_soba;
                    int namj(0); bool namjesten(false);
                    cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                    cin >> namj;
                    if (namj==1) namjesten = true;
                    if (namj==0) namjesten = false;
                    double kvadratura;
                    cout << "Unesite kvadraturu: ";
                    cin >> kvadratura;
                    try {
                        if (namj!=0 && namj!=1) throw std::domain_error("Neispravan unos podataka");
                        Stan stan(adresa, sprat, broj_soba, namjesten, kvadratura);
                        stanovi.push_back(stan);
                        cout << "Stan je uspjesno dodan!" << endl << " " << endl;
                        unos=true;
                    }
                    catch (std::domain_error izuzetak) {
                        cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet."<< endl;
                    }
                }
                while(!unos);
                cout << endl;
            }
            if (opcija_s==2) {
                cout << "Odaberite stan. Dostupni stanovi su:" << endl;
                for (int i=0; i<stanovi.size(); i++) {
                    cout << " " << i+1 << " - ";
                    stanovi[i].Ispisi();
                }
                cout << endl << " " << endl;
                int odabir(0);
                cin >> odabir;
                cout << "Odaberite polje koje zelite urediti:" << endl;
                cout <<" 0 - nazad" << endl << " 1 - adresa" << endl << " 2 - sprat" << endl << " 3 - broj soba" << endl <<
                " 4 - da li je stan namjesten" << endl << " 5 - kvadratura" << endl << " 6 - sve" << endl;
                int opcija;
                cin >> opcija;
                if (opcija==0) break; //?
                if (opcija ==1 || opcija==6) {
                    bool unos(false);
                    do {
                        try {
                            cout << "Unesite adresu: ";
                            std::string adresa;
                            cin.ignore(10000, '\n');
                            std::getline(cin, adresa); 
                            stanovi[odabir-1].Postavi(adresa, stanovi[odabir-1].DajSprat(), stanovi[odabir-1].DajBrojSoba(), stanovi[odabir-1].DajNamjesten(), stanovi[odabir-1].DajKvadraturu());
                            unos=true;
                        }
                        catch (std::domain_error izuzetak) {
                            cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                        }
                    }
                    while (!unos);
                }
                 if (opcija==2 || opcija==6)  {
                    bool unos(false);
                    do {
                        try {
                            cout << "Unesite sprat: ";
                            int sprat;
                            cin >> sprat;
                            stanovi[odabir-1].Postavi(stanovi[odabir-1].DajAdresu(), sprat, stanovi[odabir-1].DajBrojSoba(), stanovi[odabir-1].DajNamjesten(), stanovi[odabir-1].DajKvadraturu());
                            unos=true;
                        }
                        catch (std::domain_error izuzetak) {
                            cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                        }
                    }
                    while (!unos);
                 }  
                 if (opcija==3 || opcija==6) {
                    bool unos(false);
                    do {
                        try {
                            cout << "Unesite broj soba: ";
                            int broj_soba;
                            cin >> broj_soba;
                            stanovi[odabir-1].Postavi(stanovi[odabir-1].DajAdresu(), stanovi[odabir-1].DajSprat() , broj_soba, stanovi[odabir-1].DajNamjesten(), stanovi[odabir-1].DajKvadraturu());
                            unos=true;
                        }
                        catch (std::domain_error izuzetak) {
                            cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                        }
                    }
                    while (!unos);
                 }
                 if (opcija==4 || opcija==6) {
                    bool unos(false);
                    do {
                        try {
                            cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            int namjesten;
                            cin >> namjesten;
                            stanovi[odabir-1].Postavi(stanovi[odabir-1].DajAdresu(), stanovi[odabir-1].DajSprat(), stanovi[odabir-1].DajBrojSoba(), bool(namjesten), stanovi[odabir-1].DajKvadraturu());
                            unos=true;
                        }
                        catch (std::domain_error izuzetak) {
                            cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                        }
                    }
                    while (!unos);
                 }
                 if (opcija==5 || opcija==6) {
                     bool unos(false);
                     do {
                        try {
                            cout << "Unesite kvadraturu: ";
                            double kv;
                            cin >> kv;
                            stanovi[odabir-1].Postavi(stanovi[odabir-1].DajAdresu(), stanovi[odabir-1].DajSprat(), stanovi[odabir-1].DajBrojSoba(), stanovi[odabir-1].DajNamjesten(), kv);
                            unos=true;
                        }
                        catch (std::domain_error izuzetak) {
                            cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                        }
                 }
                while (!unos);
                cout << "Stan je uspjesno izmijenjen!" << endl << " " << endl;
                }
            }
            if (opcija_s==3) {
                for (int i=0; i<stanovi.size(); i++) {
                    cout << i+1 << ". ";
                    stanovi[i].Ispisi();
                }
                cout << endl << " " << endl;
            }
            if (opcija_s==4) { cout << endl; break; }
            }
            while (opcija_s!=4);
        }
        if (opcija1==2) {
            int opcija_k(0);
            do {
                cout << "Izaberite opciju:" << endl;
                cout << " 0 - nazad" << endl << " 1 - dodavanje kupca" << endl << " 2 - uredjivanje kupaca" << endl <<
                " 3 - ispis svih kupaca" << endl << " 4 - kraj" << endl; 
                cin >> opcija_k;
                if (opcija_k==0) {
                    break;
                }
                if (opcija_k==1) {
                    bool unos(false); 
                    do {
                        try {
                            std::string ime_i_prezime;
                            cout << "Unesite ime i prezime kupca: "; 
                            cin.ignore(10000, '\n');
                            std::getline(cin, ime_i_prezime);
                            cout << "Unesite datum rodjenja (formata d/m/g): ";
                            int d(0), m(0), g(0);
                            char znak1, znak2;
                            cin  >> d >> znak1 >> m  >> znak2 >> g;
                            Datum dat(d, m, g);
                            kupci.push_back(Kupac(ime_i_prezime, dat));
                            cout << "Kupac je uspjesno dodan!" << endl << endl;
                            unos = true;
                        }
                        catch (std::domain_error izuzetak) {
                            cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet." << endl;
                        }
                    }
                    while (!unos); 
                }
                if (opcija_k==2) {
                    cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:" << endl;
                    for (int i=0; i<kupci.size(); i++) {
                        cout << " " << i+1 << " - ";
                        kupci[i].Ispisi();
                        cout << endl;
                    }
                    int odabir(0);
                    cin >> odabir;
                    bool unos(false);
                    do {
                        try {
                            std::string ime_i_prezime;
                            cout << "Unesite ime i prezime kupca: "; 
                            cin.ignore(10000, '\n');
                            std::getline(cin, ime_i_prezime);
                            cout << "Unesite datum rodjenja (formata d/m/g): ";
                            int d(0), m(0), g(0);
                            char znak1, znak2;
                            cin >> d >> znak1 >> m >> znak2 >> g;
                            Datum dat(d, m, g);
                            kupci[odabir-1].Postavi(ime_i_prezime, dat);
                            cout << "Kupac je uspjesno izmijenjen!" << endl;
                            unos = true; 
                        }
                        catch (std::domain_error izuzetak) {
                            cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.";
                        }
                    }
                    while(!unos);
                }
                if (opcija_k==3) {
                    for (int i=0; i< kupci.size(); i++) {
                        kupci[i].Ispisi();
                        cout << endl;
                    }
                }
                if (opcija_k==4) {
                    cout << "\n\nDovidjenja!";
	                return 0;
                }
            }
            while (opcija_k!=0);
        }
        if (opcija1==3) {
            int opcija_p(0);
            do {
                cout << "Izaberite opciju:" << endl;
                cout << " 0 - nazad" << endl << " 1 - dodavanje prodaje" << endl << " 2 - uredjivanje prodaje" << endl <<
                " 3 - ispis prodaja" << endl << " 4 - brisanje prodaja" << endl << " 5 - kraj" << endl; 
                cin >> opcija_p;
                if (opcija_p==0) {
                    break;
                }
                if (opcija_p==1) {
                    int o(0);
                    cout << "Izaberite opciju:" << endl;
                    cout << " 0 - nazad" << endl << " 1 - dodavanje potpuno nove prodaje" << endl << " 2 - dodavanje nove prodaje na osnovu arhive" << endl <<
                    " 3 - kraj" << endl;
                    cin >> o;
                    if (o==0) {
                    break;
                    }
                    if (o==1) {
                        bool unos(false);
                        do {
                        try {
                            std::string i_i_p;
                            cout << "Unesite ime i prezime agenta prodaje: "; 
                            cin.ignore(1000, '\n');
                            std::getline(cin, i_i_p);
                            cout <<"Unesite datum prodaje (formata d/m/g): ";
                            int d(0), m(0), g(0);
                            char znak1, znak2;
                            cin >> d >> znak1 >> m >> znak2 >> g;
                            Datum dat_p(d, m, g);
                            cout << "Unesite cijenu stana: ";
                            int cijena;
                            cin >> cijena;
                            std::string ime_k;
                            cout << "Unesite ime kupca: ";
                            cin.ignore(1000, '\n');
                            std::getline(cin, ime_k);
                            cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                            int d1(0), m1(0), g1(0);
                            char z1, z2;
                            cin >> d1 >> z1 >> m1 >> z2 >> g1;
                            Datum dat_k(d1, m1, g1);
                            cout << "Unesite adresu: ";
                            std::string adresa;
                            cin.ignore(1000, '\n');
                            std::getline(cin, ime_k);
                            int sprat, sobe , namjesten;
                            cout << "Unesite sprat: ";
                            cin >> sprat;
                            cout << "Unesite broj soba: ";
                            cin >> sobe;
                            cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            cin >> namjesten;
                            if (namjesten != 0 && namjesten != 1) throw std::domain_error ("Neispravan unos podataka");
                            double kvadratura;
                            cout << "Unesite kvadraturu: ";
                            cin >> kvadratura;
                            v_prodaja.push_back(Prodaja(i_i_p, cijena, dat_p.DajDan(), dat_p.DajMjesec(), dat_p.DajGodinu(), ime_k, dat_k, adresa, sprat, sobe, bool(namjesten), kvadratura));
                            cout << "Prodaja uspjesno dodana!" << endl; 
                            unos=true;
                        }
                        catch (std::domain_error izuzetak) {
                            cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.";
                        }
                        }
                        while (!unos);
                    }
                    if (o==2) {
                        bool unos(false);
                        do {
                            try {
                                std::string i_i_p;
                                cout << "Unesite ime i prezime agenta prodaje:"; 
                                cin.ignore(1000, '\n');
                                std::getline(cin, i_i_p);
                                cout <<" Unesite datum prodaje (formata d/m/g): ";
                                int d(0), m(0), g(0);
                                char znak1, znak2;
                                cin >> d >> znak1 >> m >> znak2 >> g;
                                Datum dat_p(d, m, g);
                                cout << "Unesite cijenu stana: ";
                                int cijena;
                                cin >> cijena;
                                cout << "Odaberite kupca. Dostupni kupci su:" << endl;
                                for (int i=0; i<kupci.size(); i++) {
                                    cout << " " << i+1 << " - ";
                                    kupci[i].Ispisi();
                                    cout << endl;
                                }
                                int k(0);
                                cin >> k;
                                cout << "Odaberite stan. Dostupni stanovi su:" << endl;
                                for (int i=0; i<stanovi.size(); i++) {
                                    cout << " " << i+1 << " - ";
                                    stanovi[i].Ispisi();
                                    cout << endl;
                                }
                                int s(0);
                                cin >> s;
                                Kupac kupac_stana=kupci[k-1];
                                Stan kupljeni_stan=stanovi[s-1];
                                v_prodaja.push_back(Prodaja(i_i_p, cijena, dat_p, kupac_stana, kupljeni_stan));
                                cout << "Prodaja uspjesno dodana!" << endl;
                                unos=true;
                            }
                            catch (std::domain_error izuzetak) {
                                cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.";
                            }
                        }
                        while (!unos);
                    }
                    if (o==3) {
                        return 0;
                    }
                }
                if (opcija_p==2) {
                    return 0;
                }
                if (opcija_p==3) {
                    return 0;
                }
                if (opcija_p==4) {
                    return 0;
                }
                if (opcija_p==5) {
                    return 0;
                }
            }
            while (opcija_p!=0);
        }
    }
    while (opcija1!= 0);
    cout << "\n\nDovidjenja!";
	return 0;
}
