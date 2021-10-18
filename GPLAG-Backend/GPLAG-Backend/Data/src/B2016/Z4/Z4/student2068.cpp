#include <iostream>
#include <stdexcept>
#include <string>
#include <new>
#include <algorithm>
#include <utility>
#include <vector>
#include <memory>

class Stan; class Kupac; class Prodaja; class Prodaje;
void UredjivanjeStanova(std::vector<Stan>&stanovi);
void UredjivanjeKupaca(std::vector<Kupac>&kupci);
void UredjivanjeProdaja(Prodaje &sve, std::vector<Kupac>&kupci, std::vector<Stan>&stanovi);
Stan DodajStan();
void IspisiSveStanove(const std::vector<Stan>&stanovi);
void IzmijeniStan(Stan& s);
void IspisiSveKupce(const std::vector<Kupac>&kupci);
void IzmijeniKupca(Kupac &k);
Kupac DodajKupca();
void DodajProdaju(Prodaje &sve, std::vector<Kupac>&kupci, std::vector<Stan>&stanovi);
void IzmijeniProdaju(Prodaja &p, std::vector<Kupac>&kupci, std::vector<Stan>&stanovi);
void RazniIspisiProdaja(Prodaje &sve);
void BrisanjaProdaja(Prodaje &sve);
void IspisiProdajeZaOdabir(Prodaje &sve);
Kupac dajmikupca(Prodaja &p);
Stan dajmistan(Prodaja &p);
void IspisiKupceZaOdabir(const std::vector<Kupac>&kupci);
void IspisiStanoveZaOdabir(const std::vector<Stan>&stanovi, int mod);

class Datum {
    int d, m, g;
    static void TestDatuma(int d, int m, int g);
public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina) { TestDatuma(dan, mjesec, godina); d=dan; m=mjesec; g=godina; }
    int DajDan() const { return d; }
    int DajMjesec() const { return m; }
    int DajGodinu() const { return g; }
    void Ispisi() const { std::cout << d << "/" << m << "/" << g; } 
};
void Datum::TestDatuma(int d, int m, int g) {
    if(g<1 || m<1 || m>12 || d<1) throw std::domain_error("Neispravan datum");
    int dani[12]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if(g%400==0 || (g%100 && g%4==0)) dani[1]++;
    if(d>dani[m-1]) throw std::domain_error("Neispravan datum");
}

class Kupac {
    Datum dat; std::string ime;
    static void TestImena(const std::string &ime);
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : dat(datum_rodjenja), ime(ime_i_prezime) { TestImena(ime_i_prezime); }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) { TestImena(ime_i_prezime); dat=datum_rodjenja; ime=ime_i_prezime; } 
    std::string DajImePrezime() const { return ime; }
    Datum DajDatumRodjenja() const { return dat; }
    void Ispisi() const { std::cout << ime << " ("; dat.Ispisi(); std::cout << ")"; }
};
void Kupac::TestImena(const std::string &ime) {
    for(auto x : ime) if( !( (x>='A' && x<='Z') || (x>='a' && x<='z') || (x>='0' && x<='9') || x=='-' || x==' ' || x==39) ) throw std::domain_error("Neispravno ime i prezime");
}

class Stan {
    std::string ad;
    int sprat, broj_soba;
    double kvadratura;
    bool namjesten;
    static void TestParametara(int a, int b, double c) { if(a<0 || b<0 || c<0) throw std::domain_error("Neispravan unos podataka"); }
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) { Postavi(adresa, sprat, broj_soba, namjesten, kvadratura); }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura);
    std::string DajAdresu() const { return ad; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    double DajKvadraturu() const { return kvadratura; }
    void Ispisi() const;
};
void Stan::Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
    TestParametara(sprat, broj_soba, kvadratura);
    ad=adresa;
    this->sprat=sprat; this->broj_soba=broj_soba; this->namjesten=namjesten; this->kvadratura=kvadratura;
}
void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << ad << " na " << sprat << ". spratu i ima " << broj_soba;
    if(broj_soba%10==1) std::cout << " sobu.";
    else if(broj_soba%10 < 5) std::cout << " sobe.";
    else std::cout << " soba.";
    std::cout << " Kvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(!namjesten) std::cout << "ni";
    std::cout << "je namjesten.";
}

class Prodaja {
    std::string ime;
    double cijena;
    Datum dat_prod;
    Kupac kupac;
    Stan stan;
    friend Kupac dajmikupca(Prodaja &p);
    friend Stan dajmistan(Prodaja &p);
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) : ime(ime_agenta_prodaje), cijena(cijena_stana), dat_prod(datum_prodaje), kupac(kupac_stana), stan(kupljeni_stan) {}
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void PromijeniKupca(const Kupac &novi_kupac) { kupac=novi_kupac; }
    void PromijeniStan(const Stan &novi_stan) { stan=novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { dat_prod=novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijena=nova_cijena; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const { return ime; }
    std::string DajImeKupca() const { return kupac.DajImePrezime(); }
    Datum DajDatumProdaje() const { return dat_prod; }
    double DajCijenuStana() const { return cijena; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};
Prodaja::Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : ime(ime_agenta_prodaje), cijena(cijena_stana), dat_prod(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac(ime_kupca, datum_rodjenja_kupca), stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}
void Prodaja::PomjeriDanUnaprijed() {
    int d=dat_prod.DajDan(), m=dat_prod.DajMjesec(), g=dat_prod.DajGodinu();
    int dani[12]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if(g%400==0 || (g%100 && g%4==0)) dani[1]++;
    d++; 
    if(d>dani[m-1]) { d=1; m++; }
    if(m>12) { m=1; g++; }
    dat_prod.Postavi(d, m, g);
}
void Prodaja::PomjeriDanUnazad() {
    int d=dat_prod.DajDan(), m=dat_prod.DajMjesec(), g=dat_prod.DajGodinu();
    int dani[12]={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if(g%400==0 || (g%100 && g%4==0)) dani[1]++;
    d--; 
    if(d==0) {
        m--;
        if(m==0) { m=12; g--; }
        d=dani[m-1];
    }
    dat_prod.Postavi(d, m, g);
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    int ad=p1.dat_prod.DajDan(), am=p1.dat_prod.DajMjesec(), ag=p1.dat_prod.DajGodinu(); 
    int bd=p2.dat_prod.DajDan(), bm=p2.dat_prod.DajMjesec(), bg=p2.dat_prod.DajGodinu();
    if(ag!=bg) return ag<bg;
    if(am!=bm) return am<bm;
    return ad<bd;
}
bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
    return p1.cijena>p2.cijena;
}
void Prodaja::Ispisi() const {
    std::cout << "Ime agenta:                     " << ime << "\n";
    std::cout << "Ime kupca:                      " << DajImeKupca() << " (";
    kupac.DajDatumRodjenja().Ispisi(); std::cout << ")\n";
    std::cout << "Zakazani datum prodaje:         ";
    DajDatumProdaje().Ispisi();
    std::cout << "\nCijena stana:                   " << cijena << "\n" << "Informacije o stanu:            " << "\n";
    stan.Ispisi();
}

class Prodaje {
    std::vector<std::shared_ptr<Prodaja>>niz;
public:
    Prodaje() {} //
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja); //
    Prodaje(const Prodaje &p); //
    Prodaje(Prodaje &&p); //
    Prodaje &operator =(const Prodaje &p); // 
    Prodaje &operator =(Prodaje &&p); //
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *p); //
    int DajBrojProdaja() const { return niz.size(); } //
    int DajBrojProdajaNaDatum(const Datum &datum) const; //
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const; //
    Prodaja &DajNajranijuProdaju(); //
    Prodaja DajNajranijuProdaju() const; //
    Prodaja &DajNajskupljuProdaju(); // 
    Prodaja DajNajskupljuProdaju() const; //
    void IsprazniKolekciju(); //
    void ObrisiNajranijuProdaju(); //
    void ObrisiProdajeAgenta(const std::string &ime_agenta); //
    void ObrisiProdajeNaDatum(const Datum &datum); //
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const; //
    Prodaja& DajProdaju(int indeks) {
        if(indeks<0 || indeks>=niz.size()) throw std::range_error("...");
        return *niz[indeks];
    }
};

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
    for(auto x : spisak_prodaja) 
        niz.emplace_back(std::make_shared<Prodaja>(x));
}
Prodaje::Prodaje(const Prodaje &p) {
    for(int i=0; i<p.niz.size(); i++) {
        niz.emplace_back(std::make_shared<Prodaja>(*p.niz[i]));
    }
}
Prodaje::Prodaje(Prodaje &&p) {
    std::swap(niz, p.niz);
}
Prodaje& Prodaje::operator =(const Prodaje &p) {
    niz.resize(0);
    for(int i=0; i<p.niz.size(); i++) {
        niz.emplace_back(std::make_shared<Prodaja>(*p.niz[i]));
    }
    return *this;
}
Prodaje& Prodaje::operator =(Prodaje &&p) {
    std::swap(niz, p.niz);
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    niz.emplace_back(std::make_shared<Prodaja>(Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan)));
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    niz.emplace_back(std::make_shared<Prodaja>(Prodaja(ime_agenta_prodaje, cijena_stana, Datum(dan_prodaje, mjesec_prodaje, godina_prodaje), Kupac(ime_kupca, datum_rodjenja_kupca), Stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata))));
}
void Prodaje::RegistrirajProdaju(Prodaja *p) {
    niz.emplace_back(std::make_shared<Prodaja>(*p));
}

int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    return std::count_if(niz.begin(), niz.end(), [datum](std::shared_ptr<Prodaja>p1) {
        auto x=p1->DajDatumProdaje();
        if(x.DajDan()==datum.DajDan() && x.DajMjesec()==datum.DajMjesec() && x.DajGodinu()==datum.DajGodinu()) return true;
        return false;
    });
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    return std::count_if(niz.begin(), niz.end(), [ime_agenta](std::shared_ptr<Prodaja>p1) {
        return p1->DajImeAgenta()==ime_agenta;
    });
}

Prodaja &Prodaje::DajNajranijuProdaju() {
    auto x=std::min_element(niz.begin(), niz.end(), [](std::shared_ptr<Prodaja>p1, std::shared_ptr<Prodaja>p2) {
       return ProdatPrije(*p1, *p2); 
    });
    if(x==niz.end()) throw std::domain_error("Nema registriranih prodaja");
    return **x;
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    auto x=std::min_element(niz.begin(), niz.end(), [](std::shared_ptr<Prodaja>p1, std::shared_ptr<Prodaja>p2) {
       return ProdatPrije(*p1, *p2); 
    });
    if(x==niz.end()) throw std::domain_error("Nema registriranih prodaja");
    return **x;
}
Prodaja &Prodaje::DajNajskupljuProdaju() {
    auto x=std::max_element(niz.begin(), niz.end(), [](std::shared_ptr<Prodaja>p1, std::shared_ptr<Prodaja>p2) {
       return SkupljiStan(*p1, *p2); 
    });
    if(x==niz.end()) throw std::domain_error("Nema registriranih prodaja");
    return **x;
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    auto x=std::max_element(niz.begin(), niz.end(), [](std::shared_ptr<Prodaja>p1, std::shared_ptr<Prodaja>p2) {
       return SkupljiStan(*p1, *p2); 
    });
    if(x==niz.end()) throw std::domain_error("Nema registriranih prodaja");
    return **x;
}

void Prodaje::IsprazniKolekciju() {
    niz.resize(0);
}

void Prodaje::ObrisiNajranijuProdaju() {
    auto x=std::min_element(niz.begin(), niz.end(), [](std::shared_ptr<Prodaja>p1, std::shared_ptr<Prodaja>p2) {
       return ProdatPrije(*p1, *p2); 
    });
    if(x==niz.end()) throw std::range_error("Prazna kolekcija");
    niz.erase(x);
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    for(auto i=niz.begin(); i!=niz.end(); ) {
        if((*i)->DajImeAgenta()==ime_agenta) {
            i=niz.erase(i);
        }
        else i++;
    }
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    for(auto i=niz.begin(); i!=niz.end(); ) {
        auto x=(*i)->DajDatumProdaje();
        if(x.DajDan()==datum.DajDan() && x.DajMjesec()==datum.DajMjesec() && x.DajGodinu()==datum.DajGodinu()) {
            i=niz.erase(i);
        }
        else i++;
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    std::vector<Prodaja*>pomocni; for(auto x : niz) {
        pomocni.emplace_back(x.get());
    }
    std::sort(pomocni.begin(), pomocni.end(), [](Prodaja *p1, Prodaja *p2) {
        auto d1=p1->DajDatumProdaje(), d2=p2->DajDatumProdaje();
        if(d1.DajGodinu()!=d2.DajGodinu()) return d1.DajGodinu()<d2.DajGodinu();
        if(d1.DajMjesec()!=d2.DajMjesec()) return d1.DajMjesec()<d2.DajMjesec();
        if(d1.DajDan()!=d2.DajDan()) return d1.DajDan()<d2.DajDan();
        return p1->DajImeKupca()<p2->DajImeKupca();
    });
    for(int i=0; i<niz.size(); i++) {
        auto x=pomocni[i]->DajDatumProdaje();
        if(x.DajDan()==datum.DajDan() && x.DajMjesec()==datum.DajMjesec() && x.DajGodinu()==datum.DajGodinu()) pomocni[i]->Ispisi();
    }
}
void Prodaje::IspisiSveProdaje() const {
    std::vector<Prodaja*>pomocni; for(auto x : niz) {
        pomocni.emplace_back(x.get());
    }
    std::sort(pomocni.begin(), pomocni.end(), [](Prodaja *p1, Prodaja *p2) {
        auto d1=p1->DajDatumProdaje(), d2=p2->DajDatumProdaje();
        if(d1.DajGodinu()!=d2.DajGodinu()) return d1.DajGodinu()<d2.DajGodinu();
        if(d1.DajMjesec()!=d2.DajMjesec()) return d1.DajMjesec()<d2.DajMjesec();
        if(d1.DajDan()!=d2.DajDan()) return d1.DajDan()<d2.DajDan();
        return p1->DajImeKupca()<p2->DajImeKupca();
    });
    for(int i=0; i<niz.size(); i++) {
        pomocni[i]->Ispisi();
    }
}



int main () {
    Prodaje sve; std::vector<Stan>stanovi; std::vector<Kupac>kupci;
	std::cout << "Dobrodosli!\n\n";
	for(;;) {
	    std::cout << "\nIzaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja";
    	int opcija; std::cin >> opcija;
    	if(opcija==0) { std::cout << "\n\nDovidjenja"; return 0; }
    	if(opcija==1) UredjivanjeStanova(stanovi); 
    	else if(opcija==2) UredjivanjeKupaca(kupci);
    	else if(opcija==3) UredjivanjeProdaja(sve, kupci, stanovi);
	}
}

void UredjivanjeStanova(std::vector<Stan>&stanovi) {
    for(;;) {
        std::cout << "\n\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj";
        int opcija; std::cin >> opcija;
        if(opcija<0 || opcija>4) { std::cout <<"\n"; continue; }
        if(opcija==0) return;
        if(opcija==1) { 
            std::cout << "\n";
            stanovi.emplace_back(DodajStan());
            std::cout << "Stan je uspjesno dodan!";
        } 
        else if(opcija==2) {
            std::cout << "\nOdaberite stan. Dostupni stanovi su:";
            IspisiStanoveZaOdabir(stanovi, 0);
            int n; std::cin >> n;
            if(n<1 || n>stanovi.size()) {} // IZUZETAK ?
            IzmijeniStan(stanovi[n-1]);
            std::cout << "Stan je uspjesno izmijenjen!";
        }
        else if(opcija==3) { IspisiStanoveZaOdabir(stanovi, 1); }
        else std::exit(0);
    }
}
Stan DodajStan() {
    for(;;) {
        std::string s; int sprat, broj_soba; bool namjesten; double kvadratura;
        std::cout << "Unesite adresu: "; std::cin.ignore(10000, '\n'); std::getline(std::cin, s);
        std::cout << "Unesite sprat: "; std::cin >> sprat;
        std::cout << "Unesite broj soba: "; std::cin >> broj_soba;
        int pomocna;
        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): "; std::cin >> pomocna;
        std::cout << "Unesite kvadraturu: "; std::cin >> kvadratura;
        if(pomocna<0 || pomocna>1) { std::cout << "Izuzetak: Neispravan unos podataka. Molimo unesite opet.\n"; continue; }
        namjesten=pomocna;
        try { return Stan(s, sprat, broj_soba, namjesten, kvadratura); }
        catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
    }
}
void IspisiSveStanove(const std::vector<Stan>&stanovi) {
    for(auto x : stanovi) {
        x.Ispisi();
    }
}
void IzmijeniStan(Stan& s) {
    std::cout << "\n\nOdaberite polje koje zelite urediti:\n 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve";
    int opcija; std::cin >> opcija;
    if(opcija==0) return;
    if(opcija==1) {
        for(;;) {
            std::cout << "\nUnesite adresu: ";
            std::cin.ignore(10000, '\n');
            std::string k; std::getline(std::cin, k);
            try { s.Postavi(k, s.DajSprat(), s.DajBrojSoba(), s.DajNamjesten(), s.DajKvadraturu()); return; }
            catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
        }
    }
    else if(opcija==2) {
        for(;;) {
            std::cout << "\nUnesite sprat: ";
            int k; std::cin >> k;
            try { s.Postavi(s.DajAdresu(), k, s.DajBrojSoba(), s.DajNamjesten(), s.DajKvadraturu()); return; }
            catch(std::domain_error izuzetak){ std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
        }
    }
    else if(opcija==3) {
        for(;;) {
            std::cout << "\nUnesite broj soba: ";
            int k; std::cin >> k;
            try { s.Postavi(s.DajAdresu(), s.DajSprat(), k, s.DajNamjesten(), s.DajKvadraturu()); return; }
            catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
        }
    }
    else if(opcija==4) {
        for(;;) {
            std::cout << "\nDa li je stan namjesten? ";
            int k; std::cin >> k;
            if(k<0 || k>1) { std::cout << "Izuzetak: Neispravan unos podataka"; continue; }
            try { s.Postavi(s.DajAdresu(), s.DajSprat(), s.DajBrojSoba(), k, s.DajKvadraturu()); return; }
            catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
        }
    }
    else if(opcija==5) {
        for(;;) {
            std::cout << "\nUnesite kvadraturu: ";
            double k; std::cin >> k;
            try { s.Postavi(s.DajAdresu(), s.DajSprat(), s.DajBrojSoba(), s.DajNamjesten(), k); return; }
            catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
        }
    }
    else if(opcija==6) {
        for(;;) {
            std::cout << "\n";
            auto novi=DodajStan();
            try { s.Postavi(novi.DajAdresu(), novi.DajSprat(), novi.DajBrojSoba(), novi.DajNamjesten(), novi.DajKvadraturu()); return; }
            catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
        }
    }
}


void UredjivanjeKupaca(std::vector<Kupac>&kupci) {
    for(;;) {
        std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj";
        int opcija=0; std::cin >> opcija;
        if(opcija<0 || opcija>4) { std::cout << "\n"; continue; }
        if(opcija==0) return;
        else if(opcija==1) {
            kupci.emplace_back(DodajKupca());
            std::cout << "Kupac je uspjesno dodan!\n";
        }
        else if(opcija==2) {
            std::cout << "\nOdaberite kupca kojeg zelite urediti. Dostupni kupci su:";
            IspisiKupceZaOdabir(kupci); std::cout << "\n";
            int n; std::cin >> n;
            if(n<1 || n>kupci.size()) {  } // IZUZETAK ?
            IzmijeniKupca(kupci[n-1]);
            std::cout << "Kupac je uspjesno izmijenjen!\n";
        }
        else if(opcija==3) {
            std::cout << "\n";
            IspisiSveKupce(kupci);
            std::cout << "\n";
        }
    }
}
Kupac DodajKupca() {
    for(;;) {
        std::cout << "\nUnesite ime i prezime kupca: ";
        std::cin.ignore(10000, '\n');
        std::string k; std::getline(std::cin, k);
        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
        int d, m, g;
        char c; std::cin >> d >> c >> m >> c >> g;
        try { return (Kupac(k, Datum(d, m, g))); }
        catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet."; }
    }
}
void IspisiSveKupce(const std::vector<Kupac>&kupci) {
    for(auto x : kupci) { 
        x.Ispisi();
        std::cout << "\n";
    }
}
void IzmijeniKupca(Kupac &kup) {
    for(;;) {
        std::cout << "Unesite ime i prezime kupca: ";
        std::cin.ignore(10000, '\n');
        std::string k; std::getline(std::cin, k);
        std::cout << "Unesite datum rodjenja (formata d/m/g): ";
        int d, m, g;
        char c; std::cin >> d >> c >> m >> c >> g;
        try { kup.Postavi(k, Datum(d, m, g)); return; }
        catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
    }
}

void UredjivanjeProdaja(Prodaje &sve, std::vector<Kupac>&kupci, std::vector<Stan>&stanovi) {
    for(;;) {
        std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj";
        int opcija=0; std::cin >> opcija;
        if(opcija<0 || opcija>=sve.DajBrojProdaja()) { } // IZUZETAK ? 
        if(opcija==0) return;
        if(opcija==1) {
            DodajProdaju(sve, kupci, stanovi);
        }
        else if(opcija==2) {
            std::cout << "\nOdaberite prodaju koju želite urediti. Dostupne prodaje su:";
            IspisiProdajeZaOdabir(sve);
            int koja; std::cin >> koja;
            if(koja<1 || koja>sve.DajBrojProdaja()) {} // IZUZETAK ?
            IzmijeniProdaju(sve.DajProdaju(koja-1), kupci, stanovi);
            std::cout << "Prodaja je uspjesno izmijenjena!\n";
        }
        else if(opcija==3) {
            RazniIspisiProdaja(sve);
        }
        else if(opcija==4) {
            BrisanjaProdaja(sve);
        }
        else std::exit(0);
    }   
}

void DodajProdaju(Prodaje &sve, std::vector<Kupac>&kupci, std::vector<Stan>&stanovi) {
    for(;;) {
        std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj";
        int opcija; std::cin >> opcija;
        if(opcija<0 || opcija>3) { } // IZUZETAK ?
        if(opcija==0) return;
        if(opcija==1) {
            std::cout << "\nUnesite ime i prezime agenta prodaje: ";
            std::cin.ignore(10000,'\n');
            std::string imeagenta; std::getline(std::cin, imeagenta);
            std::cout << "Unesite datum prodaje (formata d/m/g): ";
            int d1, m1, g1; char c;
            std::cin >> d1 >> c >> m1 >> c >> g1;
            std::cout << "Unesite cijenu stana: ";
            double cijena; std::cin >> cijena;
            std::cout << "Unesite ime kupca: ";
            std::cin.ignore(10000,'\n');
            std::string imekupca; std::getline(std::cin, imekupca);
            std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
            int d2, m2, g2;
            std::cin >> d2 >> c >> m2 >> c >> g2;
            auto st=DodajStan(); stanovi.emplace_back(st); 
            try {
                Kupac novi(imekupca, Datum(d2, m2, g2)); kupci.emplace_back(novi);
                sve.RegistrirajProdaju(imeagenta, cijena, Datum(d1, m1, g1), novi, st); std::cout << "Prodaja uspjesno dodana!\n"; 
            }
            catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
            catch(std::range_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
        }
        else if(opcija==2) {
            std::cout << "\nUnesite ime i prezime agenta prodaje: ";
            std::cin.ignore(10000,'\n');
            std::string imeagenta; std::getline(std::cin, imeagenta);
            std::cout << "Unesite datum prodaje (formata d/m/g): ";
            int d, m, g; char c;
            std::cin >> d >> c >> m >> c >> g;
            std::cout << "Unesite cijenu stana: ";
            double cijena; std::cin >> cijena;
            std::cout << "Odaberite kupca. Dostupni kupci su:";
            IspisiKupceZaOdabir(kupci);
            int brojkupca; std::cin >> brojkupca;
            if(brojkupca<1 || brojkupca>kupci.size()) {} // IZUZETAK ?
            std::cout << "\nOdaberite stan. Dostupni stanovi su:";
            IspisiStanoveZaOdabir(stanovi, 0); // doovdje
            int brojstana; std::cin >> brojstana;
            if(brojstana<1 || brojstana>stanovi.size()) {} // IZUZETAK ?
            try { sve.RegistrirajProdaju(imeagenta, cijena, Datum(d, m, g), kupci[brojkupca-1], stanovi[brojstana-1]);  std::cout << "\nProdaja uspjesno dodana!\n"; }
            catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
            catch(std::range_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; } 
        }
        else std::exit(0);
    }
}

void IzmijeniProdaju(Prodaja &p, std::vector<Kupac>&kupci, std::vector<Stan>&stanovi) {
    std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca\n 4 - izmjena stana\n 5 - izmjena cijene stana";
    int opcija; std::cin >> opcija;
    if(opcija<0 || opcija>5) {} // IZUZETAK ?
    if(opcija==0) return;
    if(opcija==1) {
        std::cout << "\nUnesite ime i prezime agenta prodaje: ";
        std::cin.ignore(10000, '\n');
        std::string ime; std::getline(std::cin, ime);
        p=Prodaja(ime, p.DajCijenuStana(), p.DajDatumProdaje(), dajmikupca(p), dajmistan(p) );
    } // NEIZVEDIVO ! ! !
    else if(opcija==2) {
        for(;;) {
            std::cout << "\nUnesite datum prodaje (formata d/m/g): ";
            int d, m, g; char c; std::cin >> d >> c >> m >> c >> g;
            try { p.PromijeniDatumKupovine(Datum(d, m, g)); break; }
            catch(std::domain_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet.\n"; }
        }
    }
    else if(opcija==3) {
        std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg kupca\n 2 - dodavanje novog kupca";
        int nova; std::cin >> nova;
        if(nova<0 || nova>2) {}  // IZUZETAK ?
        if(nova==1) {
            std::cout << "Odaberite kupca. Dostupni kupci su:";
            IspisiSveKupce(kupci);
            int brojkupca; std::cin >> brojkupca;
            if(brojkupca<1 || brojkupca>kupci.size()) {} // IZUZETAK ?
            p.PromijeniKupca(kupci[brojkupca-1]);
        }
        else if(nova==2) {
            auto a=DodajKupca(); kupci.emplace_back(a);
            p.PromijeniKupca(a);
        }
    }
    else if(opcija==4) {
        std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg stana\n 2 - dodavanje novog stana";
        int nova; std::cin >> nova;
        if(nova<0 || nova>2) {} // IZUZETAK ?
        if(nova==1) {
            std::cout << "Odaberite stan. Dostupni stanovi su:";
            IspisiSveStanove(stanovi);
            int kojistan; std::cin >> kojistan;
            if(kojistan<1 || kojistan>stanovi.size()) {} // IZUZETAK ?
            p.PromijeniStan(stanovi[kojistan-1]);
        }
        else if(opcija==2) {
            auto a=DodajStan(); stanovi.emplace_back(a);
            p.PromijeniStan(a);
        }
    }
    else if(opcija==5) {
        std::cout << "Unesite cijenu stana: ";
        double c; std::cin >> c;
        p.PromijeniCijenuProdaje(c);
    }
}

void RazniIspisiProdaja(Prodaje &sve) {
    for(;;) {
        std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - ispis svih prodaja\n 2 - ispis prodaja na datum\n 3 - ispis najranije prodaje\n 4 - ispis najskuplje prodaje\n 5 - ispis broja prodaja\n 6 - ispis broja prodaja po datumu\n 7 - ispis broja prodaja po agentu\n 8 - kraj";
        int opcija; std::cin >> opcija;
        if(opcija<0 || opcija>8) {} // IZUZETAK ?
        if(opcija==0) return;
        if(opcija==1) {
            std::cout << "\n";
            sve.IspisiSveProdaje();
        }
        else if(opcija==2) {
            std::cout << "Unesite datum (d/m/g): ";
            int d, m, g; char c; std::cin >> d >> c >> m >> c >> g;
            std::cout << "Prodaje na datum " << d << "/" << m << "/" << g << " su:\n";
            sve.IspisiProdajeNaDatum(Datum(d, m, g));
        }
        else if(opcija==3) {
            sve.DajNajranijuProdaju().Ispisi();
        }
        else if(opcija==4) {
            sve.DajNajskupljuProdaju().Ispisi();
        }
        else if(opcija==5) {
            std::cout << "Broj prodaja: " << sve.DajBrojProdaja();
        }
        else if(opcija==6) {
            std::cout << "Unesite datum (d/m/g): ";
            int d, m, g; char c; std::cin >> d >> c >> m >> c >> g;
            std::cout << "Broj prodaja na uneseni datum: " << sve.DajBrojProdajaNaDatum(Datum(d, m, g));
        }
        else if(opcija==7) {
            std::cout << "Unesite ime agenta: "; std::string ime;
            std::cin.ignore(10000, '\n'); std::getline(std::cin, ime);
            std::cout << "Broj prodaja: " << sve.DajBrojProdajaOdAgenta(ime);
        }
        else std::exit(0);
    }
} 

void BrisanjaProdaja(Prodaje &sve) {
    for(;;) {
        std::cout << "\nIzaberite opciju:\n 0 - nazad\n 1 - brisanje najranije prodaje\n 2 - brisanje prodaja agenta\n 3 - brisanje prodaja po datumu\n 4 - brisanje svih prodaja";
        int opcija; std::cin >> opcija;
        if(opcija<0 || opcija>4) {} // IZUZETAK ?
        if(opcija==0) return;
        if(opcija==1) {
            try {
                sve.ObrisiNajranijuProdaju();
                std::cout << "Najranija prodaja je obrisana!";
            }
            catch(std::range_error izuzetak) { std::cout << "Izuzetak: " << izuzetak.what() << ". Molimo unesite opet."; }
        }
        else if(opcija==2) {
            std::cout << "Unesite ime agenta: ";
            std::cin.ignore(10000, '\n'); std::string ime;
            std::getline(std::cin, ime);
            sve.ObrisiProdajeAgenta(ime);
            std::cout << "Sve prodaje tog agenta su obrisane.";
        }
        else if(opcija==3) {
            std::cout << "Unesite datum: ";
            int d, m, g; char c; std::cin >> d >> c >> m >> c >> g;
            sve.ObrisiProdajeNaDatum(Datum(d, m, g));
            std::cout << "Sve prodaje na taj datum su obrisane.";
        }
        else {
            sve.IsprazniKolekciju();
        }
    }
} 

void IspisiProdajeZaOdabir(Prodaje &sve) {
    for(int i=0; i<sve.DajBrojProdaja(); i++) {
        std::cout << "\n" << i+1 << ".\n";
        sve.DajProdaju(i).Ispisi();
        if(i<sve.DajBrojProdaja()-1) std::cout << "\n";
    }
}

void IspisiKupceZaOdabir(const std::vector<Kupac>&kupci) {
    for(int i=0; i<kupci.size(); i++) {
        std::cout << "\n " << i+1 << " - ";
        kupci[i].Ispisi();
    }
}

void IspisiStanoveZaOdabir(const std::vector<Stan>&stanovi, int mod) {
    for(int i=0; i<stanovi.size(); i++) {
        if(mod==0) std::cout << "\n " << i+1 << " - ";
        else std::cout << "\n" << i+1 << ". ";
        stanovi[i].Ispisi();
    }
}

Kupac dajmikupca(Prodaja &p) { return p.kupac; }
Stan dajmistan(Prodaja &p) { return p.stan; }
//