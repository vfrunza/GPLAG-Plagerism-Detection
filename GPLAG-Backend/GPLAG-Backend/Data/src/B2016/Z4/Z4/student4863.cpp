/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <new>
#include <memory>

class Datum {
    int d, m, g;
    void valjan(int dan, int mj, int god) const{
        int br_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(god % 4 == 0 && god % 100 != 0 || god % 400 == 0) br_dana[1]++;
        if(god < 1 || dan < 1 || mj < 1 || mj > 12 || dan > br_dana[mj-1]) throw std::domain_error("Neispravan datum");
    }
public:
    Datum(int dan, int mjesec,int godina) {Postavi(dan, mjesec, godina);}
    void Postavi(int dan, int mjesec, int godina)  {
        valjan(dan, mjesec, godina);
        d = dan, m = mjesec; g = godina;
    }
    int DajDan() const {return d;}
    int DajMjesec() const {return m;}
    int DajGodinu() const {return g;}
    void Ispisi() const {std::cout << d << "/" << m << "/" << g;}
};

class Kupac {
    std::string ip;
    Datum dat_rodjenja;
    void valjano(const std::string &s) const {
        for(int i = 0; i < s.length(); i++)
            if(!(s[i] >='A' && s[i] <='Z' || s[i] >='a' && s[i] <= 'z' || s[i] == '\'' || s[i] == '-' || s[i] == ' ' || s[i]>='0' && s[i] <= '9'))
                throw std::domain_error("Neispravno ime i prezime");
    }
public:
    Kupac(const std::string &ime_i_prezime, const Datum &datum_rodjenja) : dat_rodjenja(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu()){
    valjano(ime_i_prezime);
    ip = ime_i_prezime;
    }
    void Postavi(const std::string &ime_i_prezime, const Datum &datum_rodjenja) {
        valjano(ime_i_prezime);
        ip = ime_i_prezime;
        dat_rodjenja.Postavi(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu());
        
    }
    std::string DajImePrezime() const {return ip;}
    Datum DajDatumRodjenja() const{return dat_rodjenja;}
    void Ispisi() const {
        std::cout << ip << " (";
        dat_rodjenja.Ispisi();
        std::cout << ")";
    }
};

class Stan {
    std::string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    void valjani_parametri(int s, bool brs,  double kvad) {
        if(s < 0 || brs < 0 || kvad < 0) throw std::domain_error("Neispravan unos podataka");
    }
public:
    Stan(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        valjani_parametri(broj_soba, namjesten, kvadratura);
        Postavi(adresa, sprat, broj_soba, namjesten, kvadratura);
    }
    void Postavi(const std::string &adresa, int sprat, int broj_soba, bool namjesten, double kvadratura) {
        valjani_parametri(sprat, broj_soba, kvadratura);
        Stan::adresa = adresa; Stan::sprat = sprat; Stan::broj_soba = broj_soba; Stan::namjesten = namjesten; Stan::kvadratura = kvadratura;
    }
    std::string DajAdresu() const {return adresa;}
    int DajSprat() const {return sprat;}
    int DajBrojSoba() const {return broj_soba;}
    bool DajNamjesten() const {return namjesten;}
    double DajKvadraturu() const {return kvadratura;}
    void Ispisi() const;
};

void Stan::Ispisi() const {
    std::cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba;
    if(broj_soba %10 == 1 && broj_soba %100 != 11) std::cout <<" sobu.";
    else if(broj_soba % 10 >= 2 & broj_soba % 10 <= 4 && !(broj_soba %100 >= 12 & broj_soba %100 <= 14)) std::cout << " sobe.";
    else std::cout << " soba.";
    std::cout << " Kvadratura stana je " << kvadratura << " (m^2) i stan ";
    if(namjesten) std::cout << "je ";
    else std::cout << "nije ";
    std::cout << "namjesten.";
}

class Prodaja {
    std::string agent;
    double cijena;
    Datum dat_prodaje;
    Kupac kupac;
    Stan kupljeni_stan;
public:
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kup_stan) :
        dat_prodaje(datum_prodaje), kupac(kupac_stana), kupljeni_stan(kup_stan), agent(ime_agenta_prodaje), cijena(cijena_stana) {}
    Prodaja(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
        const std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba,
        bool namjesten_stan, double broj_kvadrata) : dat_prodaje(dan_prodaje, mjesec_prodaje, godina_prodaje), kupac(ime_kupca, datum_rodjenja_kupca),
                kupljeni_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata), agent(ime_agenta_prodaje), cijena(cijena_stana) {}
    void PromijeniKupca(const Kupac &novi_kupac) {kupac = novi_kupac;}
    void PromijeniStan(const Stan &novi_stan) {kupljeni_stan = novi_stan;}
    void PromijeniDatumKupovine(const Datum &novi_datum) {dat_prodaje = novi_datum;}
    void PromijeniCijenuProdaje(const double &nova_cijena) {cijena = nova_cijena;}
    void PromijeniAgentaProdaje(const std::string &novi_agent) {agent = novi_agent;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImeAgenta() const {return agent;}
    std::string DajImeKupca() const {return kupac.DajImePrezime();}
    Datum DajDatumProdaje() const {return dat_prodaje;}
    double DajCijenuStana() const {return cijena;}
    
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2) {return p1.cijena > p2.cijena;}
    void Ispisi() const;
};
void Prodaja::PomjeriDanUnaprijed() {
    int d(dat_prodaje.DajDan()+1), m(dat_prodaje.DajMjesec()), g(dat_prodaje.DajGodinu());
    int br_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) br_dana[1]++;
    if(d > br_dana[m-1]) {d = 1; m++;}
    if(m > 12) {m = 1; g++;}
    dat_prodaje.Postavi(d, m, g);
}

void Prodaja::PomjeriDanUnazad() {
    int d(dat_prodaje.DajDan()-1), m(dat_prodaje.DajMjesec()), g(dat_prodaje.DajGodinu());
    int br_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) br_dana[1]++;
    if(d == 0) {
        m--; 
        if(m == 0) g--; 
        d = br_dana[m-1];
    }
    dat_prodaje.Postavi(d, m, g);
}

void Prodaja::Ispisi() const {
    std::cout << std::setw(32) << std::left << "Ime agenta:" << DajImeAgenta() << "\n";
    std::cout << std::setw(32) << std::left << "Ime kupca:";
    kupac.Ispisi();
    std::cout << std::endl;
    std::cout << std::setw(32) << std::left << "Zakazani datum prodaje:";
    DajDatumProdaje().Ispisi();
    std::cout << std::endl << std::setw(32) << std::left << "Cijena stana:" << DajCijenuStana();
    std::cout << "\nInformacije o stanu:\n";
    kupljeni_stan.Ispisi();
}
bool ProdatPrije(const Prodaja &p1, const Prodaja &p2) {
    if(p1.dat_prodaje.DajGodinu() < p2.dat_prodaje.DajGodinu()) return true;
    if(p1.dat_prodaje.DajGodinu() > p2.dat_prodaje.DajGodinu()) return false;
    if(p1.dat_prodaje.DajMjesec() < p2.dat_prodaje.DajMjesec()) return true;
    if(p1.dat_prodaje.DajMjesec() > p2.dat_prodaje.DajMjesec()) return false;
    if(p1.dat_prodaje.DajDan() < p2.dat_prodaje.DajDan()) return true;
    return false;
}
class Prodaje {
    std::vector<std::shared_ptr<Prodaja>> prodaje;
    static bool PorediDatum(const Datum &d1, const Datum &d2) {
        return(d1.DajDan() == d2.DajDan() && d1.DajMjesec() == d2.DajMjesec() && d1.DajGodinu() == d2.DajGodinu());
    }
    void Realociraj();
public:
    explicit Prodaje() = default;
    Prodaje(std::initializer_list<Prodaja> spisak_prodaja);
    Prodaje(const Prodaje &prodaje2) {
        prodaje.resize(prodaje2.DajBrojProdaja());
        try{
            for(int i = 0; i < prodaje.size(); i++)
                prodaje[i] = std::make_shared<Prodaja>(*prodaje2.prodaje[i]);
            }
        catch(std::bad_alloc) {
            throw;
        }
    }
    Prodaje(Prodaje &&prodaje2) : prodaje(std::move(prodaje2.prodaje)) {}
    Prodaje &operator = (const Prodaje &prodaje2);
    Prodaje &operator = (Prodaje &&prodaje2){
        prodaje = std::move(prodaje2.prodaje);
        return *this;
    }
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan);
    void RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
        std::string &ime_kupca, const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, 
        int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja);
    int DajBrojProdaja() const;
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const std::string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    Prodaja &DajProdaju(int indeks);
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const std::string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

void Prodaje::Realociraj() {
    std::vector<std::shared_ptr<Prodaja>> novo_prodaje;
    try{
        for(int i = 0; i < prodaje.size(); i++)
            if(prodaje[i]) {
                novo_prodaje.push_back(std::make_shared<Prodaja>(*prodaje[i]));
                prodaje[i] = nullptr;
            }
        prodaje.resize(0);
        prodaje = novo_prodaje;
    }
    catch(std::bad_alloc) {
        throw;
    }
}
Prodaje::Prodaje(std::initializer_list<Prodaja> spisak_prodaja) {
    try{
    prodaje.resize(spisak_prodaja.size());
    int br(0);
    for(auto x : spisak_prodaja)
        prodaje[br++] = std::make_shared<Prodaja>(Prodaja(x));
    }
    catch(std::bad_alloc) {
        throw;
    }
}
Prodaje &Prodaje::operator=(const Prodaje &prodaje2) {
    prodaje.resize(prodaje2.prodaje.size());
    for(int i = 0; i < prodaje.size(); i++)
        prodaje[i] = std::make_shared<Prodaja>(*prodaje2.prodaje[i]);
    return *this;
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana, const Stan &kupljeni_stan) {
    prodaje.push_back(std::make_shared<Prodaja>(Prodaja(Prodaja(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan))));
}
void Prodaje::RegistrirajProdaju(const std::string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje, std::string &ime_kupca,
        const Datum &datum_rodjenja_kupca, const std::string &adresa_stana, int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata) {
            Datum tmp_datum(dan_prodaje, mjesec_prodaje, godina_prodaje);
            Kupac tmp_kupac(ime_kupca, datum_rodjenja_kupca);
            Stan tmp_stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
            prodaje.push_back(std::make_shared<Prodaja>(Prodaja(Prodaja(ime_agenta_prodaje, cijena_stana, tmp_datum, tmp_kupac, tmp_stan))));
}
void Prodaje::RegistrirajProdaju(std::shared_ptr<Prodaja> prodaja) {
    prodaje.push_back(std::make_shared<Prodaja>(Prodaja(*prodaja)));
}
int Prodaje::DajBrojProdaja() const {
    return prodaje.size();
    
}
int Prodaje::DajBrojProdajaNaDatum(const Datum &datum) const {
    if (!DajBrojProdaja()) throw std::domain_error("Nema registriranih prodaja");
    return std::count_if(prodaje.begin(), prodaje.end(), [datum](std::shared_ptr<Prodaja> pr){
        if(datum.DajDan() != pr->DajDatumProdaje().DajDan() || datum.DajMjesec() != pr->DajDatumProdaje().DajMjesec() || datum.DajGodinu() != pr->DajDatumProdaje().DajGodinu()) return false;
        return true;});
}
int Prodaje::DajBrojProdajaOdAgenta(const std::string &ime_agenta) const {
    if(!DajBrojProdaja()) throw std::domain_error("Nema registriranih prodaja");
    return std::count_if(prodaje.begin(), prodaje.end(), [ime_agenta] (std::shared_ptr<Prodaja> pr) { return pr->DajImeAgenta() == ime_agenta;});
}
Prodaja& Prodaje::DajNajranijuProdaju() {
    if(!DajBrojProdaja()) throw std::domain_error("Nema registriranih prodaja");
    auto  prod (std::min_element(prodaje.begin(), prodaje.end(), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2){return ProdatPrije(*p1, *p2);}));
    return **prod;
}
Prodaja Prodaje::DajNajranijuProdaju() const {
    if(!DajBrojProdaja()) throw std::domain_error("Nema registriranih prodaja");
    auto prod (std::min_element(prodaje.begin(), prodaje.end(), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2){return ProdatPrije(*p1, *p2);}));
    return **prod;
}
Prodaja& Prodaje::DajNajskupljuProdaju() {
    if(!DajBrojProdaja()) throw std::domain_error("Nema registriranih prodaja");
    auto prod (std::max_element(prodaje.begin(), prodaje.end(), [](std::shared_ptr<Prodaja> p1,std::shared_ptr<Prodaja> p2){return p2->DajCijenuStana() > p1->DajCijenuStana();}));
    return **prod;
}
Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(!DajBrojProdaja()) throw std::domain_error("Nema registriranih prodaja");
    auto prod (std::max_element(prodaje.begin(), prodaje.end(), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2){return p2->DajCijenuStana() > p1->DajCijenuStana();}));
    return **prod;
}
Prodaja& Prodaje::DajProdaju(int indeks) {
    if(indeks < 1 || indeks > prodaje.size() || !prodaje[indeks-1]) throw std::logic_error("Redni broj nije ispravan;");
    return *prodaje[indeks-1];
}
void Prodaje::IsprazniKolekciju() {
    if(!DajBrojProdaja()) throw std::range_error("Prazna kolekcija");
    prodaje.resize(0);   
}
void Prodaje::ObrisiNajranijuProdaju() {
    if(!DajBrojProdaja()) throw std::range_error("Prazna kolekcija");
    auto prod(std::min_element(prodaje.begin(), prodaje.end(), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2){return ProdatPrije(*p1, *p2);}));
    *prod = nullptr;
    Realociraj();
}
void Prodaje::ObrisiProdajeAgenta(const std::string &ime_agenta) {
    if(!DajBrojProdaja()) throw std::range_error("Prazna kolekcija");
    int br(DajBrojProdaja());
    for(int i = 0; i <br; i++)
        if(prodaje[i] && prodaje[i]->DajImeAgenta() == ime_agenta) {
            prodaje[i] = nullptr;
        }
    Realociraj();
}
void Prodaje::ObrisiProdajeNaDatum(const Datum &datum) {
    if(!DajBrojProdaja()) throw std::range_error("Prazna kolekcija");
    int br(DajBrojProdaja());
    for(int i = 0; i < br; i++)
        if(prodaje[i] && PorediDatum(prodaje[i]->DajDatumProdaje(), datum)) {
            prodaje[i] = nullptr;
        }
    Realociraj();
}
void Prodaje::IspisiProdajeNaDatum(const Datum &datum) const {
    auto prodaje2 = prodaje;
    std::sort(prodaje2.begin(), prodaje2.end(), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {return p1->DajImeKupca() < p2->DajImeKupca();});
    for(int i = 0; i < prodaje.size(); i++)
        if(prodaje2[i] && PorediDatum(prodaje2[i]->DajDatumProdaje(), datum)) { prodaje2[i]->Ispisi(); std::cout << std::endl << std::endl;}
}
void Prodaje::IspisiSveProdaje() const {
    auto prodaje2 = prodaje;
    std::sort(prodaje2.begin(), prodaje2.end(), [](std::shared_ptr<Prodaja> p1, std::shared_ptr<Prodaja> p2) {
        if(ProdatPrije(*p1, *p2)) return true;                                                         
        else if(!PorediDatum(p1->DajDatumProdaje(), p2->DajDatumProdaje())) return false;             
        else return p1->DajImeKupca() < p2->DajImeKupca();});
    for(int i = 0; i < prodaje.size(); i++)
        if(prodaje2[i]) {
            prodaje2[i]->Ispisi();
            std::cout << std::endl << std::endl;
        }
}

Stan UnesiPodatkeStan(bool &ispravno) {
    std::cout << "Unesite adresu: ";
    std::string adresa;
    getline(std::cin, adresa);
    std::cout << "Unesite sprat: ";
    int sprat;
    std::cin >> sprat;
    std::cout << "Unesite broj soba: ";
    int broj_soba;
    std::cin >> broj_soba;
    std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
    int namjesten;
    std::cin >> namjesten;
    std::cout << "Unesite kvadraturu: ";
    double kvadratura;
    std::cin >> kvadratura;
    std::cin.ignore(1000, '\n');
    if(namjesten != 0 && namjesten != 1) throw std::domain_error("Neispravan unos podataka");
    Stan tmp_stan(adresa, sprat, broj_soba, namjesten, kvadratura);
    ispravno = true;
    return tmp_stan;
}

int main ()
{
    Prodaje prodaje;
    std::vector<Stan> stanovi;
    std::vector<Kupac> kupci;
    std::cout << "Dobrodosli!\n\n\n";
    int opcija(1);
    while(opcija != 0) {
        std::cout << "Izaberite opciju:\n 0 - kraj\n 1 - uredjivanje stanova\n 2 - uredjivanje kupaca\n 3 - uredjivanje prodaja\n";
        std::cin >> opcija;
        std::cin.ignore(10000, '\n');
        if(opcija == 0) {
            break;
        }
        if(opcija == 1) {
            int opcija2(0);
            bool ispravno(true);
            while(opcija2 != 4) {
                if(ispravno) {
                    std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje stana\n 2 - uredjivanje stanova\n 3 - ispis svih stanova\n 4 - kraj\n";
                    std::cin >> opcija2;
                    std::cin.ignore(10000,'\n');
                }
                if(opcija2 == 0)
                    break;
                if(opcija2 == 1) {
                    try{
                        Stan tmp_stan(UnesiPodatkeStan(ispravno));
                        stanovi.push_back(tmp_stan);
                        std::cout << "Stan je uspjesno dodan!\n\n";
                        ispravno = true;
                    }
                    catch(std::domain_error e) {
                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                        ispravno = false;
                    }
                }
                if(opcija2 == 2) {
                    std::cout << "Odaberite stan. Dostupni stanovi su:\n";
                    int brojac(1);
                    std::for_each(stanovi.begin(), stanovi.end(), [&brojac] (Stan stan) {std::cout <<" " << brojac <<" - "; stan.Ispisi(); std::cout << std::endl; brojac++;});
                    int broj_stana(0);
                    std::cin >> broj_stana;
                    std::cin.ignore(1000, '\n');
                    std::cout << "Odaberite polje koje zelite urediti:\n";
                    std::cout << " 0 - nazad\n 1 - adresa\n 2 - sprat\n 3 - broj soba\n 4 - da li je stan namjesten\n 5 - kvadratura\n 6 - sve\n";
                    int opcija3(0);
                    std::cin >> opcija3;
                    std::cin.ignore(10000, '\n');
                    if(opcija3 == 0) continue;
                    if(opcija3 == 1) {
                        std::cout << "Unesite adresu: ";
                        std::string tmp_adresa;
                        getline(std::cin, tmp_adresa);
                        stanovi[broj_stana-1] = Stan(tmp_adresa, stanovi[broj_stana-1].DajSprat(), stanovi[broj_stana-1].DajBrojSoba(), stanovi[broj_stana-1].DajNamjesten(), stanovi[broj_stana-1].DajKvadraturu());
                        std::cout << "Stan uspjesno izmijenjen!\n\n";
                    }
                    if(opcija3 == 2) {
                        std::cout << "Unesite sprat: ";
                        int tmp_sprat;
                        std::cin >> tmp_sprat;
                        std::cin.ignore(1000, '\n');
                        stanovi[broj_stana-1] = Stan(stanovi[broj_stana-1].DajAdresu(), tmp_sprat, stanovi[broj_stana-1].DajBrojSoba(), stanovi[broj_stana-1].DajNamjesten(), stanovi[broj_stana-1].DajKvadraturu());
                        std::cout << "Stan uspjesno izmijenjen!\n\n";
                    }
                    if(opcija3 == 3) {
                        bool nije_ispravan(true);
                        while(nije_ispravan) {
                            std::cout << "Unesite broj soba: ";
                            int tmp_broj_soba;
                            std::cin >> tmp_broj_soba;
                            std::cin.ignore(1000, '\n');
                            try{
                                Stan tmp_stan(stanovi[broj_stana].DajAdresu(), stanovi[broj_stana].DajSprat(), tmp_broj_soba, stanovi[broj_stana-1].DajNamjesten(), stanovi[broj_stana-1].DajKvadraturu());
                                nije_ispravan = false;
                                stanovi[broj_stana-1] = tmp_stan;
                                std::cout << "Stan je uspjesno izmijenjen!\n\n";
                            }
                            catch(std::domain_error e) {
                                std::cout << "Izuzetak: " << e.what() <<". Molimo unesite opet.\n";
                                nije_ispravan = true;
                            }
                        }
                        
                    }
                    if(opcija3 == 4) {
                        bool nije_ispravan(true);
                        while(nije_ispravan) {
                            try{
                                std::cout << "Unesite da li je stan namjesten: ";
                                int namjesten;
                                std::cin >> namjesten;
                                std::cin.ignore();
                                if(namjesten != 0 && namjesten != 1) throw std::domain_error("Neispravan unos podataka");
                                stanovi[broj_stana-1] = Stan(stanovi[broj_stana-1].DajAdresu(), stanovi[broj_stana-1].DajSprat(), stanovi[broj_stana-1].DajBrojSoba(), namjesten, stanovi[broj_stana-1].DajKvadraturu());
                                nije_ispravan = false;
                            }
                            catch(std::domain_error e) {
                                std::cout << e.what() << ". Molimo unesite opet.\n";
                                nije_ispravan = true;
                            }
                        }
                    }
                    if(opcija3 == 5) {
                        bool nije_ispravan(true);
                        while(nije_ispravan) {
                            std::cout << "Unesite kvadraturu: ";
                            double kvadratura;
                            std::cin >> kvadratura;
                            std::cin.ignore(1000, '\n');
                            try{
                                Stan tmp_stan(stanovi[broj_stana-1].DajAdresu(), stanovi[broj_stana-1].DajSprat(), stanovi[broj_stana-1].DajBrojSoba(), stanovi[broj_stana-1].DajNamjesten(), kvadratura);
                                nije_ispravan = false;
                                stanovi[broj_stana-1] = tmp_stan;
                                std::cout << "Stan je uspjesno izmijenjen!\n\n";
                            }
                            catch(std::domain_error e) {
                                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                                nije_ispravan = true;
                            }
                        }
                    }
                    if(opcija3 == 6) {
                        bool ispravan(false);
                        while(!ispravan) {
                            try{
                                Stan tmp_stan(UnesiPodatkeStan(ispravan));
                                stanovi[broj_stana-1] = tmp_stan;
                                std::cout << "Stan je uspjesno izmijenjen!\n\n";
                            }
                            catch(std::domain_error e) {
                                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                            }
                        }
                    }
                }
                if(opcija2 == 3) {
                    int brojac(1);
                    std::for_each(stanovi.begin(), stanovi.end(), [&brojac] (Stan stan) {std::cout << brojac << ". "; stan.Ispisi(); std::cout << std::endl; brojac++;});
                    std::cout << std::endl;
                }
                if(opcija2 == 4) {
                    opcija = 0;
                    break;
                }
            }
        }
        if(opcija == 2) {
            int opcija2(0);
            bool ispravno(true);
            while(opcija2 != 4){
                if(ispravno) {
                    std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje kupca\n 2 - uredjivanje kupaca\n 3 - ispis svih kupaca\n 4 - kraj\n";
                    std::cin >> opcija2;
                    std::cin.ignore(1000, '\n');
                }
                if(opcija2 == 0)
                    break;
                if(opcija2 == 1) {
                    std::cout << "Unesite ime i prezime kupca: ";
                    std::string ime_kupca;
                    getline(std::cin, ime_kupca);
                    std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                    int d, m, g;
                    char c;
                    std::cin >> d >> c >> m >> c >> g;
                    std::cin.ignore(1000, '\n');
                    try{
                        Kupac tmp_kupac(ime_kupca, Datum(d,m,g));
                        ispravno = true;
                        std::cout << "Kupac je uspjesno dodan!\n\n";
                        kupci.push_back(tmp_kupac);
                    }
                    catch(std::domain_error e) {
                        std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                        ispravno = false;
                    }
                }
                if(opcija2 == 2) {
                    std::cout << "Odaberite kupca kojeg zelite urediti. Dostupni kupci su:\n";
                    int brojac(1);
                    std::for_each(kupci.begin(), kupci.end(), [&brojac](Kupac k) {std::cout << " " << brojac++ << " - "; k.Ispisi(); std::cout << std::endl;});
                    int broj_kupca;
                    std::cin >> broj_kupca;
                    std::cin.ignore(1000, '\n');
                    bool ispravan(false);
                    while(!ispravan) {
                        try{
                            std::cout << "Unesite ime i prezime kupca: ";
                            std::string ime_kupca;
                            getline(std::cin, ime_kupca);
                            std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                            int d,m,g;
                            char c;
                            std::cin >> d >> c >> m >> c >> g;
                            std::cin.ignore(1000, '\n');
                            Kupac tmp_kupac(ime_kupca, Datum(d,m,g));
                            ispravan = true;
                            std::cout << "Kupac je uspjesno izmijenjen!\n\n";
                            kupci[broj_kupca-1] = tmp_kupac;
                        }
                        catch(std::domain_error e) {
                            std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                            ispravan = false;
                        }
                    }
                }
                if(opcija2 == 3) {
                    std::for_each(kupci.begin(), kupci.end(), [] (Kupac k) {k.Ispisi(); std::cout << std::endl;});
                    std::cout << std::endl;
                }
                if(opcija2 == 4) {
                    opcija = 0;
                    break;
                }
            }
        }
        if(opcija == 3) {
            int opcija2(0);
            while(opcija2 != 5) {
                std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje prodaje\n 2 - uredjivanje prodaje\n 3 - ispis prodaja\n 4 - brisanje prodaja\n 5 - kraj\n";
                std::cin >> opcija2;
                std::cin.ignore(1000, '\n');
                if(opcija2 == 0) break;
                if(opcija2 == 1) {
                    bool ispravno(true);
                    int opcija3(0);
                    while(opcija3 != 3) {
                        if(ispravno) {
                            std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - dodavanje potpuno nove prodaje\n 2 - dodavanje nove prodaje na osnovu arhive\n 3 - kraj\n";
                            std::cin >> opcija3;
                            std::cin.ignore(1000, '\n');
                        }
                        if(opcija3 == 0) break;
                        if(opcija3 == 1) {
                            try{
                                std::cout << "Unesite ime i prezime agenta prodaje: ";
                                std::string agent, adresa, kupac;
                                getline(std::cin, agent);
                                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                int d,m,g;
                                char c;
                                std::cin >> d >> c >> m >> c >> g;
                                std::cout << "Unesite cijenu stana: ";
                                double cijena;
                                std::cin >> cijena;
                                std::cin.ignore();
                                std::cout << "Unesite ime kupca: ";
                                getline(std::cin, kupac);
                                std::cout << "Unesite datum rodjenja kupca (formata d/m/g): ";
                                int kd, km, kg;
                                std::cin >> kd >> c >> km >> c >> kg;
                                std::cin.ignore(1000, '\n');
                                std::cout << "Unesite adresu: ";
                                getline(std::cin, adresa);
                                int sprat, broj_soba, namjesten;
                                std::cout << "Unesite sprat: ";
                                std::cin >> sprat;
                                std::cout << "Unesite broj soba: ";
                                std::cin >> broj_soba;
                                std::cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                std::cin >> namjesten;
                                std::cout << "Unesite kvadraturu: ";
                                double kvadratura;
                                std::cin >> kvadratura;
                                std::cin.ignore(1000,'\n');
                                if(namjesten != 0 && namjesten != 1) throw std::domain_error("Neispravan unos podataka");
                                stanovi.push_back(Stan(adresa, sprat, broj_soba, namjesten, kvadratura));
                                kupci.push_back(Kupac(kupac, Datum(kd, km, kg)));
                                prodaje.RegistrirajProdaju(agent, cijena, d,m,g, kupac, Datum(kd,km,kg), adresa, sprat, broj_soba, namjesten, kvadratura);
                                ispravno = true;
                                std::cout << "Prodaja uspjesno dodana!\n\n";
                            }
                            catch(std::domain_error e) {
                                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                                ispravno = false;
                            }
                        }
                        if(opcija3 == 2) {
                            try{
                                std::cout << "Unesite ime i prezime agenta prodaje: ";
                                std::string agent;
                                getline(std::cin, agent);
                                std::cout << "Unesite datum prodaje (formata d/m/g): ";
                                int d,m,g;
                                char c;
                                std::cin >> d >> c >> m >> c >> g;
                                std::cout << "Unesite cijenu stana: ";
                                double cijena;
                                std::cin >> cijena;
                                std::cin.ignore(1000, '\n');
                                std::cout << "Odaberite kupca. Dostupni kupci su:\n";
                                int brojac(1);
                                std::for_each(kupci.begin(), kupci.end(), [&brojac](Kupac k) {std::cout << " " << brojac++ << " - "; k.Ispisi(); std::cout << std::endl;});
                                int broj_kupca;
                                std::cin >> broj_kupca;
                                std::cout << "Odaberite stan. Dostupni stanovi su:\n";
                                brojac = 1;
                                std::for_each(stanovi.begin(), stanovi.end(), [&brojac] (Stan s) {std::cout << " " << brojac++ << " - "; s.Ispisi(); std::cout << std::endl;});
                                int broj_stana;
                                std::cin >> broj_stana;
                                std::cin.ignore(1000, '\n');
                                prodaje.RegistrirajProdaju(agent, cijena, Datum(d,m,g), kupci[broj_kupca-1], stanovi[broj_stana-1]);
                                std::cout << "Prodaja uspjesno dodana!\n\n";
                            }
                            catch(std::domain_error e) {
                                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                                ispravno = false;
                            }
                        }
                        if(opcija3 == 3) {
                            opcija2 = 5; break;
                        }
                    }
                }
                if(opcija2 == 2) {
                    std::cout << "Odaberite prodaju koju želite urediti. Dostupne prodaje su:\n";
                    //prodaje.IspisiSveProdaje();
                    for(int i = 1; i <= prodaje.DajBrojProdaja(); i++) {
                        std::cout << i << ".\n";
                        prodaje.DajProdaju(i).Ispisi();
                        std::cout << std::endl << std::endl;
                    }
                    int broj_prodaje(0);
                    std::cin >> broj_prodaje;
                    std::cin.ignore(1000, '\n');
                    int opcija3(0);
                    std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - izmjena agenta\n 2 - izmjena datuma prodaje\n 3 - izmjena kupca\n 4 - izmjena stana\n 5 - izmjena cijene stana\n";
                    std::cin >> opcija3;
                    std::cin.ignore(1000, '\n');
                    if(opcija3 == 0) break;
                    if(opcija3 == 1) {
                        std::cout << "Unesite ime i prezime agenta prodaje: ";
                        std::string agent;
                        getline(std::cin, agent);
                        prodaje.DajProdaju(broj_prodaje).PromijeniAgentaProdaje(agent);
                        std::cout << "Prodaja je uspjesno izmijenjena!\n\n";
                    }
                    if(opcija3 == 2) {
                        bool nije_ispravan(true);
                        while(nije_ispravan){
                            std::cout<< "Unesite datum prodaje (formata d/m/g): ";
                            int d,m,g;
                            char c;
                            std::cin >> d >> c >> m >> c >> g;
                            std::cin.ignore(1000,'\n');
                            try{
                                prodaje.DajProdaju(broj_prodaje).PromijeniDatumKupovine(Datum(d,m,g));
                                nije_ispravan = false;
                                std::cout << "Prodaja je uspjesno izmijenjena!\n\n";
                            }
                            catch(std::domain_error e) {
                                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                            }
                        }
                    }
                    if(opcija3 == 3) {
                        std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg kupca\n 2 - dodavanje novog kupca\n";
                        int opcija4(0);
                        std::cin >> opcija4;
                        std::cin.ignore(1000,'\n');
                        if(opcija4 == 0) break;
                        if(opcija4 == 1) {
                            int brojac(1), broj_kupca(0);
                            std::cout << "Odaberite kupca. Dostupni kupci su:\n";
                            std::for_each(kupci.begin(), kupci.end(), [&brojac](Kupac k) {std::cout << " " << brojac++ << " - "; k.Ispisi(); std::cout << std::endl;});
                            std::cin >> broj_kupca;
                            std::cin.ignore(1000, '\n');
                            prodaje.DajProdaju(broj_prodaje).PromijeniKupca(kupci[broj_kupca-1]);
                            std::cout << "Prodaja je uspjesno izmijenjena!\n\n";
                        }
                        if(opcija4 == 2) {
                            bool nije_ispravan(true);
                            while(nije_ispravan){
                                try{
                                    std::cout << "Unesite ime i prezime kupca: ";
                                    std::string ime;
                                    getline(std::cin, ime);
                                    std::cout << "Unesite datum rodjenja (formata d/m/g): ";
                                    int d,m,g;
                                    char c;
                                    std::cin >> d >> c >> m >> c >> g;
                                    std::cin.ignore(1000, '\n');
                                    Kupac tmp_kupac(ime, Datum(d,m,g));
                                    kupci.push_back(tmp_kupac);
                                    prodaje.DajProdaju(broj_prodaje).PromijeniKupca(tmp_kupac);
                                    nije_ispravan = false;
                                    std::cout << "Prodaja je uspjesno izmijenjena!\n\n";
                                }
                                catch(std::domain_error e) {
                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                                }
                            }
                        }
                    }
                    if(opcija3 == 4) {
                        std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - odabir postojeceg stana\n 2 - dodavanje novog stana\n";
                        int opcija4;
                        std::cin >> opcija4;
                        std::cin.ignore(1000, '\n');
                        if(opcija4 == 0) break;
                        if(opcija4 == 1) {
                            std::cout << "Odaberite stan. Dostupni stanovi su:\n";
                            int brojac(1);
                            std::for_each(stanovi.begin(), stanovi.end(), [&brojac] (Stan s) {std::cout << " " << brojac++ << " - "; s.Ispisi(); std::cout << std::endl;});
                            int broj_stana;
                            std::cin >> broj_stana;
                            std::cin.ignore(1000, '\n');
                            prodaje.DajProdaju(broj_prodaje).PromijeniStan(stanovi[broj_stana-1]);
                            std::cout << "Prodaja je uspjesno izmijenjena!\n\n";
                        }
                        if(opcija4 == 2) {
                            bool nije_ispravan(true);
                            while(nije_ispravan) {
                                try{
                                    Stan tmp_stan (UnesiPodatkeStan(nije_ispravan));
                                    nije_ispravan = false;
                                    stanovi.push_back(tmp_stan);
                                    std::cout << "Prodaja je uspjesno izmijenjena!\n\n";
                                }
                                catch(std::domain_error e) {
                                    std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                                }
                            }
                        }
                    }
                    if(opcija3 == 5) {
                        bool nije_ispravan(true);
                        while(nije_ispravan) {
                            std::cout << "Unesite cijenu stana: ";
                            double cijena;
                            std::cin >> cijena;
                            std::cin.ignore();
                            try{
                                prodaje.DajProdaju(broj_prodaje).PromijeniCijenuProdaje(cijena);
                                nije_ispravan=false;
                                std::cout << "Prodaja je uspjesno izmijenjena!\n\n";
                            }
                            catch(std::domain_error e) {
                                std::cout << "Izuzetak: " << e.what() << ". Molimo unesite opet.\n";
                            }
                        }
                    }
                }
                if(opcija2 == 3) {
                    int opcija3(0);
                    while(opcija3 != 8) {
                        std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - ispis svih prodaja\n 2 - ispis prodaja na datum\n 3 - ispis najranije prodaje\n 4 - ispis najskuplje prodaje\n 5 - ispis broja prodaja\n 6 - ispis broja prodaja po datumu\n 7 - ispis broja prodaja po agentu\n 8 - kraj\n";
                        std::cin >> opcija3;
                        std::cin.ignore(1000,'\n');
                        if(opcija3 == 0) break;
                        if(opcija3 == 1) prodaje.IspisiSveProdaje();
                        if(opcija3 == 2) {
                            int d, m, g;
                            char c;
                            std::cout << "Unesite datum (d/m/g): ";
                            std::cin >> d >> c >> m >> c >> g;
                            std::cout << "Prodaje na datum ";
                            Datum(d,m,g).Ispisi();
                            std::cout << " su:\n\n";
                            prodaje.IspisiProdajeNaDatum(Datum(d,m,g));
                        }
                        if(opcija3 == 3) {
                           prodaje.DajNajranijuProdaju().Ispisi();
                           std::cout << std::endl << std::endl;
                        }
                        if(opcija3 == 4) {
                            prodaje.DajNajskupljuProdaju().Ispisi();
                            std::cout << std::endl << std::endl;
                        }
                        if(opcija3 == 5) std::cout << "Broj prodaja: " << prodaje.DajBrojProdaja() << std::endl << std::endl;
                        if(opcija3 == 6) {
                            std::cout <<"Unesite datum (d/m/g): ";
                            int d,m,g;
                            char c;
                            std::cin >> d >> c >> m >> c >> g;
                            std::cout << "Broj prodaja na uneseni datum: " << prodaje.DajBrojProdajaNaDatum(Datum(d,m,g)) << std::endl << std::endl;
                        }
                        if(opcija3 == 7) {
                            std::string agent;
                            std::cout << "Unesite ime agenta: ";
                            getline(std::cin, agent);
                            std::cout << "Broj prodaja unesenog agenta: " << prodaje.DajBrojProdajaOdAgenta(agent) << std::endl << std::endl;
                        }
                        if(opcija3 == 8) {
                            opcija2 = 5; break;
                        }
                    }
                }
                if(opcija2 == 4) {
                    int opcija3(1);
                    while(opcija3 != 0) {
                        std::cout << "Izaberite opciju:\n 0 - nazad\n 1 - brisanje najranije prodaje\n 2 - brisanje prodaja agenta\n 3 - brisanje prodaja po datumu\n 4 - brisanje svih prodaja\n";
                        std::cin >> opcija3;
                        std::cin.ignore(1000, '\n');
                        if(opcija3 == 0) break;
                        if(opcija3 == 1) {
                            try{
                                prodaje.ObrisiNajranijuProdaju();
                                std::cout << "Najranija prodaja je obrisana!\n\n";
                            }
                            catch(std::range_error e) {
                                std::cout << "Izuzetak: " << e.what() << ".\n\n";
                            }
                        }
                        if(opcija3 == 2) {
                            try{
                                std::cout << "Unesite ime agenta: ";
                                std::string agent;
                                getline(std::cin, agent);
                                prodaje.ObrisiProdajeAgenta(agent);
                                std::cout << "Sve prodaje tog agenta su obrisane.\n\n";
                            }
                            catch(std::range_error e) {
                                std::cout << "Izuzetak: " << e.what() << ".\n\n";
                            }
                        }
                        if(opcija3 == 3) {
                                try{
                                std::cout << "Unesite datum: ";
                                int d, m, g;
                                char c;
                                std::cin >> d >> c >> m >> c >> g;
                                prodaje.ObrisiProdajeNaDatum(Datum(d,m,g));
                                std::cout << "Sve prodaje na taj datum su obrisane.\n\n";
                            }
                            catch(std::range_error e) {
                                std::cout << "Izuzetak: " << e.what() << ".\n\n";
                            }
                        }
                        if(opcija3 == 4) {
                            try{
                                prodaje.IsprazniKolekciju();
                                std::cout << "Sve prodaje su obrisane.\n\n";
                            }
                            catch(std::range_error e) {
                                std::cout << "Izuzetak: " << e.what() << ".\n\n";
                            }
                        }
                    }
                }
                if(opcija2 == 5) {
                    opcija = 0; break;
                }
            }
        }
    }
    
    std::cout << "\n\nDovidjenja!";
    
	return 0;
}