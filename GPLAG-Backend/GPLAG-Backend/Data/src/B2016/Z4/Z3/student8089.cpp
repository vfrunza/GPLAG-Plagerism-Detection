#include <iostream>
#include <stdexcept>
#include <string>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <memory>
#include <vector>

class Datum
{
    int dan, mjesec, godina;
    bool DaLiJeValidanDatum(int dan, int mjesec, int godina);
public:
    Datum(int dan, int mjesec, int godina) {
        if (!(DaLiJeValidanDatum(dan, mjesec, godina))) throw std::domain_error ("Neispravan datum");
        Datum::dan = dan;
        Datum::mjesec=mjesec;
        Datum::godina = godina;
    }
    void Postavi(int dan, int mjesec, int godina) {
        if (!(DaLiJeValidanDatum(dan, mjesec, godina))) throw std::domain_error ("Neispravan datum");
        Datum::dan = dan;
        Datum::mjesec=mjesec;
        Datum::godina = godina;
    }
    int DajDan() const {
        return dan;
    }
    int DajMjesec () const {
        return mjesec;
    }
    int DajGodinu () const {
        return godina;
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Kupac
{
    std::string ime_i_prezime;
    Datum datumRodjenja;
    bool DaLiJeValidnoIme (const std::string &s);
public:
    Kupac (const std::string &ime_i_prezime, const Datum &datumRodjenja) : datumRodjenja(datumRodjenja.DajDan(), datumRodjenja.DajMjesec(), datumRodjenja.DajGodinu()) {
        if (!(DaLiJeValidnoIme(ime_i_prezime))) throw std::domain_error("Neispravno ime i prezime");

        Kupac::ime_i_prezime = ime_i_prezime;
    }
    void Postavi (const std::string &ime_i_prezime, const Datum &datumRodjenja) {

        if (!(DaLiJeValidnoIme(ime_i_prezime))) throw std::domain_error("Neispravno ime i prezime");

        Kupac::ime_i_prezime = ime_i_prezime;
        Kupac::datumRodjenja = datumRodjenja;
    }
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const {
        return datumRodjenja;
    }
    void Ispisi() const {
        std::cout << ime_i_prezime << " ";
        datumRodjenja.Ispisi();
    }
};

class Stan
{
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan (const std::string &adresa, int sprat, int broj_sobe, bool namjesten, double kvadratura) {
        if (sprat < 0 || broj_sobe < 0 || kvadratura < 0) throw std::domain_error ("Neispravan unos podataka.");

        Stan::adresa = adresa;
        broj_soba = broj_sobe;
        Stan::sprat = sprat;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
    }
    void Postavi(const std::string &adresa, int sprat, int broj_sobe, bool namjesten, double kvadratura) {
        if (sprat < 0 || broj_sobe < 0 || kvadratura < 0) throw std::domain_error ("Neispravan unos podataka.");

        Stan::adresa = adresa;
        broj_soba = broj_sobe;
        Stan::sprat = sprat;
        Stan::namjesten = namjesten;
        Stan::kvadratura = kvadratura;
    }
    std::string DajAdresu() const {
        return adresa;
    }
    int DajSprat() const {
        return sprat;
    }
    int DajBrojSobe() const {
        return broj_soba;
    }
    bool DajNamjesten() const {
        return namjesten;
    }
    double DajKvadraturu() const {
        return kvadratura;
    }
    void Ispisi() const;
};

class Prodaja
{
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datumProdaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
    void PomjeriDan(bool yesNo);
public:
    //Konstruktori
    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_Prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan)
        : ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datumProdaje(datum_Prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {}

    Prodaja (const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
             const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
        : ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datumProdaje(dan_prodaje, mjesec_prodaje, godina_prodaje),
          kupac_stana(ime_kupca, datum_rodjenja_kupca), kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}

    void PromijeniKupca(const Kupac &novi_kupac) {
        kupac_stana = novi_kupac;
    }
    void PromijeniStan (const Stan &novi_stan) {
        kupljeni_stan = novi_stan;
    }
    void PromijeniDatumKupovine (const Datum &novi_datum) {
        datumProdaje = novi_datum;
    }
    void PromijeniCijenuProdaje (const double &nova_cijena) {
        cijena_stana = nova_cijena;
    }

    void PomjeriDanUnaprijed() {
        PomjeriDan(true);
    }
    void PomjeriDanUnazad() {
        PomjeriDan(false);
    }

    std::string DajImeAgenta() const {
        return ime_agenta_prodaje;
    }
    std::string DajImeKupca() const {
        return kupac_stana.DajImePrezime();
    }
    Datum DajDatumProdaje() const {
        return datumProdaje;
    }
    double DajCijenuStana() const {
        return cijena_stana;
    }

    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);

    void Ispisi() const {
        std::cout << "Ime agenta: " << ime_agenta_prodaje << std::endl;
        std::cout << "Ime kupca: ";
        kupac_stana.Ispisi();
        std::cout << std::endl;
        std::cout << "Zakazani datum prodaje: ";
        datumProdaje.Ispisi();
        std::cout << std::endl;
        std::cout << "Cijena stana: " << cijena_stana << std::endl;
        std::cout << "Informacije o stanu: " << std::endl;
        kupljeni_stan.Ispisi();
    }
};

class Prodaje
{
    std::vector<std::shared_ptr<Prodaja>> pProdaje;
public:
    //Vasionske stvari
    explicit Prodaje (){}

    Prodaje (std::initializer_list<Prodaja> spisak_prodaja){
        pProdaje.resize(spisak_prodaja.size());
        
        int brojac(0);
        for (auto i : spisak_prodaja) pProdaje[brojac++] = std::make_shared<Prodaja> (Prodaja(i));
    }

    ~Prodaje() {}

    Prodaje(const Prodaje &prodaje) {
        pProdaje.resize(prodaje.pProdaje.size());
        
        for (int i = 0; i < prodaje.pProdaje.size(); i++) pProdaje[i] = std::make_shared<Prodaja> (*(prodaje.pProdaje[i])); 

    }
    
    Prodaje(Prodaje &&prodaje){
        pProdaje.resize(prodaje.pProdaje.size());
        pProdaje = prodaje.pProdaje;
        prodaje.pProdaje.resize(0);
    }

    Prodaje &operator =(const Prodaje &prodaje) {
        pProdaje.resize(prodaje.pProdaje.size());
        
        for (int i = 0; i < prodaje.pProdaje.size(); i++) {
            pProdaje[i] = pProdaje[i] = std::make_shared<Prodaja> (*(prodaje.pProdaje[i])); 
        }

        return *this;
    }
    
    Prodaje &operator =(Prodaje &&prodaje) {
        pProdaje.resize(prodaje.pProdaje.size());
        std::swap(pProdaje, prodaje.pProdaje);
        prodaje.pProdaje.resize(0);
        return *this;
    }

    //Ovozemaljske stvari
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_Prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
        try {
            pProdaje.push_back(std::make_shared<Prodaja> (ime_agenta_prodaje, cijena_stana, datum_Prodaje, kupac_stana, kupljeni_stan));
        } catch (...) {
            throw;
        }
    }

    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
                            const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
       
        try {
            pProdaje.push_back(std::make_shared<Prodaja> (ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca,
                                                   datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata));
        } catch (...) {
        
            throw;
        }
    }

    void RegistrirajProdaju(Prodaja *prodaja) {
        try {
            pProdaje.push_back(std::make_shared<Prodaja>(prodaja));
        } catch (...) {
            
            throw;
        }
    }

    int DajBrojProdaja() const {
        return pProdaje.size();
    }
    int DajBrojProdajaNaDatum (const Datum &datum) const {
        return std::count_if(std::begin(pProdaje), std::end(pProdaje), [datum](Prodaja* p1) {
            if (datum.DajDan() == p1->DajDatumProdaje().DajDan() && datum.DajMjesec() == p1->DajDatumProdaje().DajMjesec() && datum.DajGodinu() == p1->DajDatumProdaje().DajGodinu()) return true;

            return false;
        });

    }

    int DajBrojProdajaOdAgenta (const std::string ime_agenta) const {
        return std::count_if(std::begin(pProdaje), std::end(pProdaje), [ime_agenta](Prodaja* p1) {
            if (ime_agenta == p1->DajImeAgenta()) return true;

            return false;
        });
    }

    Prodaja &DajProdaju(int redniBrojProdaje) const {
        if (pProdaje.size() < redniBrojProdaje || redniBrojProdaje < 1) throw std::range_error ("Neispravan redni broj");

        return *(pProdaje[redniBrojProdaje-1]);
    }

    Prodaja &DajNajranijuProdaju() {
        if (pProdaje.size() == 0) throw std::domain_error("Nema registriranih prodaja");

        return **(std::min_element(std::begin(pProdaje), std::end(pProdaje), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
            return ProdatPrije(*p1,*p2);
        }));
    }
    Prodaja DajNajranijuProdaju() const {
        if (pProdaje.size() == 0) throw std::domain_error("Nema registriranih prodaja");

        return **(std::min_element(std::begin(pProdaje), std::end(pProdaje), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
            return ProdatPrije(*p1,*p2);
        }));
    }


    Prodaja &DajNajskupljuProdaju() {
        if (pProdaje.size() == 0) throw std::domain_error("Nema registriranih prodaja");

        return **(std::max_element(std::begin(pProdaje), std::end(pProdaje), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
            return SkupljiStan(*p1,*p2);
        }));
    }
    Prodaja DajNajskupljuProdaju() const {
        if (pProdaje.size() == 0) throw std::domain_error("Nema registriranih prodaja");

        return **(std::max_element(std::begin(pProdaje), std::end(pProdaje), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
            return SkupljiStan(*p1,*p2);
        }));
    }

    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();


    void ObrisiProdajeagenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);

    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

int main ()
{/*
    Prodaje testneProdaje(20);
    
    std::cout << "Dobrodosli!" << std::endl << std::endl;

    std::cout << "Izaberite opciju:" << std::endl;
    std::cout << " 0 - kraj" << std::endl;
    std::cout << " 1 - uredjivanje stanova" << std::endl;
    std::cout << " 2 - uredjivanje kupaca" << std::endl;
    std::cout << " 3 - uredjivanje prodaja" << std::endl;
    
    int n; std::cin >> n;
    
    if(n==1){
        int p(-60);
        while (p != 0){
            std::cout << "Izaberite opciju:" << std::endl;
            std::cout << " 0 - nazad" << std::endl;
            std::cout << " 1 - dodavanje stana" << std::endl;
            std::cout << " 2 - uredjivanje stanova" << std::endl;
            std::cout << " 3 - ispis svih stanova" << std::endl;
            std::cout << " 4 - kraj" << std::endl;
            
            std::cin >> p;
            
            if (p == 1) {
                int i=0;
                while(i != 1){
                    bool bilaGreska(false);
                    std::cout << "Unesite adresu: "; std::string adresa; std::getline(std::cin, adresa); std::cin.ignore(10000, '\n');
                    std::cout << "Unesite sprat: "; int sprat; std::cin >> sprat;
                    std::cout << "Unesite broj soba: "; int brSoba; std::cin >> brSoba;
                    std::cout << "Da li je stan namjesten (1 - da, 0 - ne): "; int input; std::cin >> input; bool namjesten; if(input == 1) namjesten =true; else if(input == 0) namjesten =true; else bilaGreska=true;
                    std::cout << "Unesite kvadraturu: "; double kvadratura; std::cin >> kvadratura; std::cin.ignore(10000, '\n');
                    
                    try{
                        if (bilaGreska) throw std::domain_error ("Neispravan unos podataka.");
                        
                        Stan noviStan(adresa, sprat, brSoba, namjesten, kvadratura);
                        
                        i=1;
                    }
                    catch(std::domain_error e){
                        std::cout << "Izuzetak: " << e.what() << " Molimo unesite opet." << std::endl << std::endl;
                    }
                }
                std::cout << "Stan je uspjesno dodan!" << std::endl << std::endl;
            }
        
        }
    }*/
    return 0;
}


bool Datum::DaLiJeValidanDatum(int dan, int mjesec, int godina)
{
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina % 4 == 0 && (godina %100 !=0 || godina %400 == 0)) broj_dana[1]++; //Ako prestupna
    if (godina < 1 || mjesec< 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec-1]) return false; //Ako neispravno

    return true;
}

bool Kupac::DaLiJeValidnoIme (const std::string &s)
{

    for (int i = 0; i < s.length(); i++) {
        //     Ako je malo slovo                Ili veliko slovo                ako je broj                     ili crtica          ili razmak  ili apostrof
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == ' ' ||s[i] == '\'')) return false;
    }
    return true;
}

void Stan::Ispisi() const
{
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << " spratu i ima " << broj_soba;
    if (broj_soba == 1) std::cout << " sobu";
    else if (broj_soba >= 2 && broj_soba <= 4) std::cout << " sobe";
    else if (broj_soba >= 5) std::cout << " soba";
    //Pazi na br decimala
    std::cout << ". Kvadratura stana je " << kvadratura << " (m^2) i stan ";

    if (namjesten) std::cout << "je namjesten.";
    else std::cout << "nije namjesten." << std::endl;
}

void Prodaja::PomjeriDan(bool yesNo)
{
    int n(-1);
    if (yesNo) n *=1;

    try {
        Datum noviDatum(datumProdaje.DajDan() + n, datumProdaje.DajMjesec(), datumProdaje.DajGodinu()); // Uvecao sam dan za 1
        datumProdaje = noviDatum;
    } catch(std::domain_error e) { // Ovaj izuzetak ce biti uhvacen ako je prekoracen max broj dana u mjeseci
        try { //To znaci da ce biti 1 u novom mjesecu
            Datum noviDatum(1, datumProdaje.DajMjesec()+n, datumProdaje.DajGodinu());
            datumProdaje = noviDatum;
        } catch (std::domain_error e) { //Moguce da smo prekoracili max broj mjeseci. Ako se ovo desilo, treba povecati godinu
            try { //To znaci da ce godina se povecati za 1
                Datum noviDatum(1, 1, datumProdaje.DajGodinu()+n);
                datumProdaje = noviDatum;
            } catch (std::domain_error e) { // Neocekivana greska
                std::cout << "Neocekivana greska" << std::endl;
            }
        }
    }
}

bool ProdatPrije(const Prodaja &p1, const Prodaja &p2)
{
    if (p1.DajDatumProdaje().DajGodinu() < p2.DajDatumProdaje().DajGodinu()) return true;

    else if (p1.DajDatumProdaje().DajGodinu() == p2.DajDatumProdaje().DajGodinu()) {
        if (p1.DajDatumProdaje().DajMjesec() < p2.DajDatumProdaje().DajMjesec()) return true;
        else if (p1.DajDatumProdaje().DajMjesec() == p2.DajDatumProdaje().DajMjesec()) {
            if (p1.DajDatumProdaje().DajDan() < p2.DajDatumProdaje().DajDan()) return true;
            else if (p1.DajDatumProdaje().DajDan() == p2.DajDatumProdaje().DajDan()) return true;
        }
    }


    return false;
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2)
{
    if (p1.DajCijenuStana() > p2.DajCijenuStana()) {
        return true;
    }

    return false;
}


void Prodaje::IsprazniKolekciju()
{
    pProdaje.resize(0);
}
/*
void Prodaje::ObrisiNajranijuProdaju()
{
    if (pProdaje.size() == 0) throw std::range_error("Prazna kolekcija");

    int index(0);
    
    for (auto i : pProdaje) {
        if (i->DajCijenuStana() == (DajNajranijuProdaju().DajCijenuStana())) {
            break;
        }
        index++;
    }
  
    pProdaje.erase(pProdaje.begin()+index);
    

}*/

void Prodaje::ObrisiProdajeagenta(const std::string &ime_agenta)
{
    for (int i = 0; i < pProdaje.size(); i++) {
        if (pProdaje[i]->DajImeAgenta() == ime_agenta) {
            pProdaje.erase(pProdaje.begin()+i);
            
        }
    }
}

void Prodaje::ObrisiProdajeNaDatum(const Datum &datum)
{
    for (int i = 0; i < pProdaje.size(); i++) {
        if (datum.DajDan() == pProdaje[i]->DajDatumProdaje().DajDan() && datum.DajMjesec() == pProdaje[i]->DajDatumProdaje().DajMjesec() && datum.DajGodinu() == pProdaje[i]->DajDatumProdaje().DajGodinu()) {
            pProdaje.erase(pProdaje.begin()+i);
        }
    }
}

void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const
{
    std::sort(std::begin(pProdaje), std::end(pProdaje), []( Prodaja* p1,  Prodaja* p2) {
        std::string s1(p1->DajImeKupca()), s2(p2->DajImeKupca());
        for (char &c : s1) c = std::toupper(c);
        for (char &c : s2) c = std::toupper(c);

        return s1 > s2;
    });

    for (int i = 0; i < pProdaje.size(); i++) {
        pProdaje[i]->Ispisi();
    }
}

void Prodaje::IspisiSveProdaje() const
{
    std::sort(std::begin(pProdaje), std::end(pProdaje), []( Prodaja* p1,  Prodaja* p2) {
        if (p1->DajDatumProdaje().DajDan() == p2->DajDatumProdaje().DajDan() && p1->DajDatumProdaje().DajMjesec() == p2->DajDatumProdaje().DajMjesec() && p1->DajDatumProdaje().DajGodinu() == p2->DajDatumProdaje().DajGodinu()) {
            std::string s1(p1->DajImeKupca()), s2(p2->DajImeKupca());
            for (char &c : s1) c = std::toupper(c);
            for (char &c : s2) c = std::toupper(c);

            return s1 > s2;
        }


        return ProdatPrije(*p1,*p2);



    });
}