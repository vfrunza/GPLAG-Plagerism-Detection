/B 2016/2017, Zadaća 4, Zadatak 3
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <vector>

void IspravnostDatuma(int d, int m, int g) {
     if(d<=0 || d>31 || m<=0 || m>12 || g<=0 ) throw std::domain_error("Neispravan datum");
     int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      // prestupne godine
      if( (g%4==0 && g%100==0) || g%400==0) 
        broj_dana[1]++;
     if(d>broj_dana[m-1]) throw std::domain_error("Neispravan datum");
}

class Datum {
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) : dan(dan), mjesec(mjesec), godina(godina) {
        IspravnostDatuma(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina) {
        this->dan = dan;
        this->mjesec = mjesec;
        this->godina = godina;
        
        IspravnostDatuma(dan,mjesec,godina);
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
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

void IspravnostImenaIPrezimena (std::string ime_i_prezime) {
    
    if((char(ime_i_prezime[0]))==' ' || (char(ime_i_prezime[0]))=='\n') throw std::domain_error("Neispravno ime i prezime");
    for(int i=0; i<ime_i_prezime.length(); i++) {
        if(!( ( (char(ime_i_prezime[i]))>='a' && (char(ime_i_prezime[i]))<='z') || ((char(ime_i_prezime[i]))>='A' && (char(ime_i_prezime[i]))<='Z') || (char(ime_i_prezime[i]))==' '))
            throw std::domain_error("Neispravno ime i prezime");
    }
}

class Kupac {
    std::string ime_i_prezime;
    Datum datum_rodjenja;
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : ime_i_prezime(ime_i_prezime), datum_rodjenja(datum_rodjenja) {
        IspravnostImenaIPrezimena(ime_i_prezime);
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
        this->ime_i_prezime = ime_i_prezime;
        this->datum_rodjenja = datum_rodjenja;
        IspravnostImenaIPrezimena(ime_i_prezime);
    }
    std::string DajImePrezime() const {
        return ime_i_prezime;
    }
    Datum DajDatumRodjenja() const {
        return datum_rodjenja;
    }
    void Ispisi() const {
        std::cout << ime_i_prezime << " (";
        datum_rodjenja.Ispisi();
        std::cout << ")";
    }
};

class Stan {
    std::string adresa;
    int sprat;
    int broj_soba;
    bool namjesten;
    double kvadratura;
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) : adresa(adresa), sprat(sprat),
        broj_soba(broj_soba), namjesten(namjesten), kvadratura(kvadratura) {
            if(sprat<0 || broj_soba<0 || kvadratura<0 || namjesten<0) throw std::domain_error("Neispravan unos podataka");
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        this->adresa = adresa;
        this->sprat = sprat;
        this->broj_soba = broj_soba;
        this->namjesten = namjesten;
        this->kvadratura = kvadratura;
        if(sprat<0 || broj_soba<0 || kvadratura<0 || namjesten<0) throw std::domain_error("Neispravan unos podataka");
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
        
        if(broj_soba==1) 
        std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba << " sobu." << std::endl;
        else if(broj_soba==2 || broj_soba==3 || broj_soba==4)
        std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba << " sobe." << std::endl;
        else
        std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba << " soba." << std::endl;
        
        if(namjesten==true)
        std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan je namjesten." << std::endl;
        else std::cout << "Kvadratura stana je " << kvadratura << " (m^2) i stan nije namjesten." << std::endl;
    }
};

class Prodaja {
    
    friend class Prodaje;
    std::string ime_agenta_prodaje;
    double cijena_stana;
    Datum datum_prodaje;
    Kupac kupac_stana;
    Stan kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) :
        ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(datum_prodaje), kupac_stana(kupac_stana), kupljeni_stan(kupljeni_stan) {
    }
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca,
    const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) : 
        ime_agenta_prodaje(ime_agenta_prodaje), cijena_stana(cijena_stana), datum_prodaje(dan_prodaje,mjesec_prodaje,godina_prodaje), kupac_stana(ime_kupca, datum_rodjenja_kupca),
        kupljeni_stan(adresa_stana,sprat_stana,broj_soba,namjesten_stan,broj_kvadrata) {
    }
    void PromijeniKupca(const Kupac &novi_kupac) {
        kupac_stana = novi_kupac;
    }
    void PromijeniStan(const Stan &novi_stan) {
        kupljeni_stan = novi_stan;
    }
    void PromijeniDatumKupovine(const Datum &novi_datum) {
        datum_prodaje = novi_datum;
    }
    void PromijeniCijenuProdaje(const double &nova_cijena) {
        cijena_stana = nova_cijena;
    }
    void PomjeriDanUnaprijed() {
        // broj dana u mjesecu
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int g, m, d;
        g = datum_prodaje.DajGodinu();
        m = datum_prodaje.DajMjesec();
        d = datum_prodaje.DajDan();
        // prestupne godine
        if( (g%4==0 && g%100==0) || g%400==0) 
        broj_dana[1]++;
        d++;
        if(d>broj_dana[m-1]) { d = 1; m++; }
        if(m > 12) { m = 1; g++; }
        datum_prodaje.Postavi(d,m,g);
    }
    void PomjeriDanUnazad() {
        // broj dana u mjesecu
        int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int g, m, d;
        g = datum_prodaje.DajGodinu();
        m = datum_prodaje.DajMjesec();
        d = datum_prodaje.DajDan();
        // prestupne godine
        if( (g%4==0 && g%100==0) || g%400==0) 
        broj_dana[1]++;
        d--;
        if(d==0) { d = broj_dana[m-1] ; m--; }
        if(m<1) { m = 12; g--; }
        datum_prodaje.Postavi(d,m,g);
    }
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
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
        
        // ako su prodani iste godine
        if(p1.datum_prodaje.DajGodinu()==p2.datum_prodaje.DajGodinu()) {
            // ako su prodani u različitim mjesecima
            if(p1.datum_prodaje.DajMjesec()<p2.datum_prodaje.DajMjesec()) return true;
            else return false;
            // ako su prodani iste godine u istom mjesecu
            if(p1.datum_prodaje.DajMjesec()==p2.datum_prodaje.DajMjesec()) {
                if(p1.datum_prodaje.DajDan()<p2.datum_prodaje.DajDan()) return true;
                else return false;
            }
        }
        // ako su prodani u razlicitim godinama
        if(p1.datum_prodaje.DajGodinu()<p2.datum_prodaje.DajGodinu()) return true;
        else return false;
    }
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {
        if(p1.cijena_stana>p2.cijena_stana) return true;
        else return false;
    }
    void Ispisi() const {
        std::cout << std::setw(28) << std::left << "Ime agenta:" << std::setw(10) << ime_agenta_prodaje << std::endl;
        std::cout << std::setw(28) << std::left << "Ime kupca:" << std::setw(10);
        kupac_stana.Ispisi();
        std::cout << std::endl;
        std::cout << std::setw(28) << std::left << "Zakazani datum prodaje:" << std::setw(10);
        datum_prodaje.Ispisi();
        std::cout << std::endl << std::setw(28) << std::left << "Cijena stana:" << std::setw(10) << cijena_stana << std::endl;
        std::cout << std::setw(28) << std::left << "Informacije o stanu:" << std::endl;
        kupljeni_stan.Ispisi();
    }
};

class Prodaje {
    int max_broj_prodaja;
    int broj_prodaja;
    Prodaja **p;
    
public:

    // implementirati izvan klase
    explicit Prodaje(int max_broj_prodaja) : max_broj_prodaja(max_broj_prodaja), broj_prodaja(0), p(new Prodaja*[max_broj_prodaja]) {}
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    ~Prodaje();
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator=(const Prodaje &prodaje);
    Prodaje &operator=(Prodaje &&prodaje);
    
    // throw std::range_error("Dostignut maksimalni broj prodaja");
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, 
    const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(Prodaja *prodaja);
   
    // count_if iz bibiloteke algorithm
    int DajBrojProdaja() const;
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    
    // min_element i max_element iz bibiloteke algorithm - throw std::domain_error("Nema registriranih prodaja");
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    
    // throw std::range_error("Prazna kolekcija");
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    
    // sortirati u rastućem poretku po datumu - ako ih ima više na isti datum sortirati po imenu kupca
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) : max_broj_prodaja(spisak_prodaja.size()), broj_prodaja(spisak_prodaja.size()) {
    
    p = new Prodaja*[spisak_prodaja.size()];
    int i(0);
    for(auto it(spisak_prodaja.begin()); it!=spisak_prodaja.end(); it++) {
        p[i] = new Prodaja(*it);
        i++;
    }
}

Prodaje::~Prodaje() {
    
    for(int i=0; i<max_broj_prodaja; i++) {
        delete[] p[i];
    }
    delete[] p;
}

Prodaje::Prodaje(const Prodaje &prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), broj_prodaja(prodaje.broj_prodaja), p(new Prodaja*[prodaje.max_broj_prodaja]) {
    
    for(int i=0; i< prodaje.broj_prodaja; i++) {
        p[i] = new Prodaja(*prodaje.p[i]);
    }
}

Prodaje::Prodaje(Prodaje &&prodaje) : max_broj_prodaja(prodaje.max_broj_prodaja), broj_prodaja(prodaje.broj_prodaja) {
    
    p = prodaje.p;
    prodaje.broj_prodaja = 0;
    prodaje.p = nullptr;
}

Prodaje &Prodaje::operator=(const Prodaje &prodaje) {
    
    if(&prodaje != this) {
        
        for(int i=0; i<broj_prodaja; i++) {
            delete p[i];
        }
        
        broj_prodaja = prodaje.broj_prodaja;
        
        for(int i=0; i<prodaje.broj_prodaja; i++) {
            p[i] = new Prodaja(*prodaje.p[i]);
        }
    }
    
    return *this;
}

Prodaje &Prodaje::operator =(Prodaje &&prodaje) {
    
    if(&prodaje != this) {
        
        for(int i=0; i<broj_prodaja; i++) {
            delete p[i];
        }
        
        p=prodaje.p;
        broj_prodaja = prodaje.broj_prodaja;
        prodaje.p = nullptr;
        prodaje.broj_prodaja = 0;
    }
    
    return *this;
}

void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    
    if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    
    for(int i=0; i<broj_prodaja; i++) {
        p[i] = new Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
    }
}


void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
    
    if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    
    for(int i=0; i<broj_prodaja; i++) {
        p[i] = new Prodaja(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje, ime_kupca, datum_rodjenja_kupca, adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    }
}
void Prodaje::RegistrirajProdaju(Prodaja *prodaja) {
    
    if(broj_prodaja==max_broj_prodaja) throw std::range_error("Dostignut maksimalni broj prodaja");
    
    
}
int main ()
{
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
   std::cout << "Dobrodosli!" << std::endl << std::endl;
   
   GlavniMenu:
   std::cout << "Izaberite opciju:" << std::endl;
   std::cout << "0 - kraj" << std::endl;
   std::cout << "1 - uredjivanje stanova" << std::endl;
   std::cout << "2 - uredjivanje kupaca" << std::endl;
   std::cout << "3 - uredjivanje prodaja" << std::endl;
   int vel;
   std::cin >> vel;
   switch(vel) {
       
       case 0: {
           std::cout << "Dovidjenja!";
           return 0;
       }
       case 1: {
           
           PrviMenu:
           std::cout << "Izaberite opciju:" << std::endl;
           std::cout << "0 - nazad" << std::endl;
           std::cout << "1 - dodavanje stana" << std::endl;
           std::cout << "2 - uredjivanje stanova" << std::endl;
           std::cout << "3 - ispis svih stanova" << std::endl;
           std::cout << "4 - kraj" << std::endl;
           int vel1;
           std::cin >> vel1;
           
           switch(vel1) {
               
               case 0: goto GlavniMenu;
               case 1: {
                    
                    for(;;) {
                        std::string adresa; int sprat, broj_soba; bool namjesten; double kvadratura;
                        std::cout << "Unesite adresu: ";
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::getline(std::cin, adresa);
                        std::cout << "Unesite sprat: ";
                        std::cin >> sprat;
                        std::cout << "Unesite broj soba: ";
                        std::cin >> broj_soba;
                        std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                        std::cin >> namjesten;
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "Unesite kvadraturu: ";
                        std::cin >> kvadratura;
                    
                        try {
                            Stan s(adresa, sprat, broj_soba, namjesten, kvadratura);
                            stanovi.push_back(s);
                            std::cout << "Stan je uspjesno dodan!" << std::endl << std::endl;
                            goto PrviMenu;
                        }
                        catch(std::domain_error poruka) {
                            std::cout << "Izuzetak: " << poruka.what() << ". Molimo unesite opet." << std::endl << std::endl;
                        }
                    }
               }
               case 2: {
                   std::cout << "Odaberite stan. Dostupni stanovi su: ";  // ovo zavrsiti
                   return 0;
               }
               case 3: {
                   for(int i=0; i<stanovi.size(); i++) {
                       std::cout << i+1 << ". ";
                       stanovi[i].Ispisi();
                   }
                   std::cout << std::endl;
                   goto PrviMenu;
               }
               case 4: return 0;
           }
       }
       case 2: {
           
           DrugiMenu:
           std::cout << "Izaberite opciju:" << std::endl;
           std::cout << "0 - nazad" << std::endl;
           std::cout << "1 - dodavanje kupca" << std::endl;
           std::cout << "2 - uredjivanje kupaca" << std::endl;
           std::cout << "3 - ispis svih kupaca" << std::endl;
           std::cout << "4 - kraj" << std::endl;
           int vel2;
           std::cin >> vel2;
           switch(vel2) {
               
               case 0: goto GlavniMenu;
               case 1: {
                    
                    for(;;) {
                        std::string ime_i_prezime_kupca;
                        std::string datum;
                        std::cout << "Unesite ime i prezime kupca: ";
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::getline(std::cin, ime_i_prezime_kupca);
                        std::cout << "Unesite datum rodjenja (formata dan/mjesec/godina): ";
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::getline(std::cin, datum);
                        
        
                        int dan(0), mjesec(0), godina(0);
                        // uraditi datum
                        Datum datum_rodjenja_kupca(dan, mjesec, godina);
                    
                        try {
                            Kupac k(ime_i_prezime_kupca, datum_rodjenja_kupca); // popravi
                            kupci.push_back(k);
                            std::cout << "Kupac je uspjesno dodan!" << std::endl << std::endl;
                            goto DrugiMenu;
                        }
                        catch(std::domain_error poruka) {
                            std::cout << "Izuzetak: " << poruka.what() << ". Molimo unesite opet." << std::endl << std::endl;
                        }
                    }
               }
               case 2: {
                   std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su: ";  // ovo zavrsiti
                   return 0;
               }
               case 3: {
                   for(int i=0; i<kupci.size(); i++) {
                       std::cout << i+1 << ". ";
                       kupci[i].Ispisi();
                   }
                   std::cout << std::endl;
                   goto PrviMenu;
               }
               case 4: return 0;
           }
       }
       case 3: {
           
           TreciMenu:
           std::cout << "Izaberite opciju:" << std::endl;
           std::cout << "0 - nazad" << std::endl;
           std::cout << "1 - dodavanje prodaje" << std::endl;
           std::cout << "2 - uredjivanje prodaje" << std::endl;
           std::cout << "3 - ispis prodaja" << std::endl;
           std::cout << "4 - brisanje prodaja" << std::endl;
           std::cout << "5 - kraj" << std::endl;
           int vel3;
           std::cin >> vel3;
           switch(vel3) {
               
               case 0: goto GlavniMenu;
               case 1: {
                   
                   PomocniMenu3:
                   std::cout << "Izaberite opciju:" << std::endl;
                   std::cout << "0 - nazad" << std::endl;
                   std::cout << "1 - dodavanje potpuno nove prodaje" << std::endl;
                   std::cout << "2 - dodavanje nove prodaje na osnovu arhive" << std::endl;
                   std::cout << "3 - kraj" << std::endl;
                   int velpomocni3;
                   std::cin >> velpomocni3;
                   switch(velpomocni3) {
                        
                    case 0: goto TreciMenu;
                    case 1: {
                      /*  for(;;) {
                            std::string ime_i_prezime_agenta;
                            std::string datum;
                            int cijena;
                            std::cout << "Unesite ime i prezime agenta prodaje: ";
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            std::getline(std::cin, ime_i_prezime_agenta);
                            std::cout << "Unesite datum prodaje (formata dan/mjesec/godina): ";
                            std::cin.clear();
                            std::cin.ignore(1000, '\n');
                            std::getline(std::cin, datum);
                        
        
                           int dan(0), mjesec(0), godina(0);
                           // uraditi datum
                           Datum datum_rodjenja_kupca(dan, mjesec, godina);
                    
                            try {
                              Kupac k(ime_i_prezime_kupca, datum_rodjenja_kupca); // popravi
                              kupci.push_back(k);
                              std::cout << "Kupac je uspjesno dodan!" << std::endl << std::endl;
                              goto TreciMenu;
                            }
                            catch(std::domain_error poruka) {
                              std::cout << "Izuzetak: " << poruka.what() << ". Molimo unesite opet." << std::endl << std::endl;
                            }
                        }*/
                        
                        goto PomocniMenu3;
                   }
                   
                   case 2: return 0; // impmenetirati
                   case 3: return 0;
                   }
               }
               
               case 2: {
                   std::cout << "Odaberite prodaju koju zelite urediti. Dostupne prodaje su: ";  // ovo zavrsiti
                   return 0;
               }
               case 3: {
                   for(int i=0; i<kupci.size(); i++) {
                       std::cout << i+1 << ". ";
                       kupci[i].Ispisi();
                   }
                   std::cout << std::endl;
                   goto PrviMenu;
               }
               case 4: return 0;
           }
       }
   }
    return 0;
}