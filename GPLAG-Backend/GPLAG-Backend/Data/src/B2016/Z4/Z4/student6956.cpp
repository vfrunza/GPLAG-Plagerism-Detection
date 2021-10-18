/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

class Datum {
private:
    int dan, mjesec, godina;
    bool ProvjeraDatuma(int, int, int) const;
public:
    Datum(int dan, int mjesec, int godina) {
        !ProvjeraDatuma(dan, mjesec, godina) ? throw domain_error("Neispravan datum") : this->dan = dan, this->mjesec = mjesec, this->godina = godina;
    }
    void Postavi(int dan, int mjesec, int godina){
        !ProvjeraDatuma(dan, mjesec, godina) ? throw domain_error("Neispravan datum") : this->dan = dan, this->mjesec = mjesec, this->godina = godina;
    }
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi(bool ispisZaIme = false) const {
        !ispisZaIme ? cout << dan << "/" << mjesec << "/" << godina << endl
         : cout << "(" << dan << "/" << mjesec << "/" << godina << ")" << endl;
    }
    void PomjeriZaDan(string);
    bool operator==(const Datum& d);
};

bool Datum::ProvjeraDatuma(int dan, int mjesec, int godina) const {
    //mozda dodati basic provjeru (negativna godina npr)
    int mjeseci[12] { 31, (godina % 4 == 0 || (godina % 100 == 0 && godina % 400 == 0) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(mjesec < 1 || mjesec > 12) return false;
    if(dan < 1 || dan > mjeseci[mjesec - 1]) return false;
    return true;
}

void Datum::PomjeriZaDan(string gdje){
    int mjeseci[12] { 31, (godina % 4 == 0 || (godina % 100 == 0 && godina % 400 == 0) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(gdje == "naprijed"){
        dan++;
        if(dan > mjeseci[mjesec - 1]) dan = 1, mjesec++;
        if(mjesec > 12) mjesec = 1, godina++;
    }
    else if(gdje == "nazad"){
        dan--;
        if(dan < 1){
            mjesec--;
            if(mjesec == 0) godina--, mjesec = 12;
            dan = mjeseci[mjesec - 1];
        }
    }
}

bool Datum::operator==(const Datum& d){
    return dan == d.DajDan() && mjesec == d.DajMjesec() && godina == d.DajGodinu();
}

// KLASA KUPAC KLASA KUPAC KLASA KUPAC KLASA KUPAC KLASA KUPAC KLASA KUPAC KLASA KUPAC KLASA KUPAC KLASA KUPAC KLASA KUPAC

class Kupac {
private:
    string ime_i_prezime;
    Datum datum;
    bool ProvjeraImena(string) const;
public:
    Kupac(const string& ime_i_prezime, const Datum& datum_rodjenja) : datum(datum_rodjenja.DajDan(), datum_rodjenja.DajMjesec(), datum_rodjenja.DajGodinu())
    {
        ProvjeraImena(ime_i_prezime) ? this->ime_i_prezime = ime_i_prezime : throw domain_error("Neispravno ime i prezime");
    }
    void Postavi(const string& ime_i_prezime, const Datum& datum_rodjenja){
        datum = datum_rodjenja;
        ProvjeraImena(ime_i_prezime) ? this->ime_i_prezime = ime_i_prezime : throw domain_error("Neispravno ime i prezime");
    }
    string DajImeIPrezime() const { return ime_i_prezime; }
    Datum DajDatumRodjenja() const { return datum; }
    void Ispisi() const { cout << ime_i_prezime << " "; datum.Ispisi(true); }
};

bool Kupac::ProvjeraImena(string ime_i_prezime) const {
    for(char c : ime_i_prezime){
        if((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9') && c != ' ' && c != '\'' && c != '-') return false;
    }
    return true;
}

// KLASA STAN KLASA STAN KLASA STAN KLASA STAN KLASA STAN KLASA STAN KLASA STAN KLASA STAN KLASA STAN KLASA STAN KLASA STAN KLASA STAN KLASA STAN

class Stan {
private:
    string adresa;
    int sprat, broj_soba;
    bool namjesten;
    double kvadratura;
    bool ProvjeraStana(int sprat, int broj_soba, double kvadratura) const { return !(sprat < 0 || broj_soba < 0 || kvadratura < 0); }
public:
    Stan(const string& adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        ProvjeraStana(sprat, broj_soba, kvadratura) ? this->sprat = sprat, this->broj_soba = broj_soba, this->kvadratura = kvadratura, this->adresa = adresa, this->namjesten = namjesten : throw domain_error("Neispravan unos podataka.");
    }
    void Postavi(const string& adresa, int sprat, int broj_soba, bool namjesten, double kvadratura){
        ProvjeraStana(sprat, broj_soba, kvadratura) ? this->sprat = sprat, this->broj_soba = broj_soba, this->kvadratura = kvadratura, this->adresa = adresa, this->namjesten = namjesten : throw domain_error("Neispravan unos podataka.");
    }
    string DajAdresu() const { return adresa; }
    int DajSprat() const { return sprat; }
    int DajBrojSoba() const { return broj_soba; }
    bool DajNamjesten() const { return namjesten; }
    bool DajKvadraturu() const { return kvadratura; }
    void Ispisi() const {
        cout << "Stan se nalazi na adresi " << adresa << " na " << sprat << ". spratu i ima " << broj_soba << " ";
        cout << ( (broj_soba == 1 || broj_soba % 10 == 1) && broj_soba != 11 ? "sobu" : ((broj_soba == 2 || broj_soba == 3 | broj_soba == 4 || broj_soba % 10 == 2 || broj_soba % 10 == 3 || broj_soba % 10 == 4) && broj_soba != 12 && broj_soba != 13 && broj_soba != 14 ? "sobe" : "soba"));
        cout << ". Kvadratura stana je " << /*setprecision(2) <<*/ kvadratura << " (m^2) i stan ";
        cout << (namjesten ? "je" : "nije") << " namjesten." << endl;
    }
};

// KLASA PRODAJA KLASA PRODAJA KLASA PRODAJA KLASA PRODAJA KLASA PRODAJA KLASA PRODAJA KLASA PRODAJA KLASA PRODAJA KLASA PRODAJA KLASA PRODAJA

class Prodaja{
private:
    string agent;
    double cijenaStana;
    Datum datumProdaje;
    Kupac kupac;
    Stan stan;
public:
    Prodaja(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
            const Kupac &kupac_stana, const Stan &kupljeni_stan) :
                agent(ime_agenta_prodaje), cijenaStana(cijena_stana), datumProdaje(datum_prodaje),
                kupac(kupac_stana), stan(kupljeni_stan) {}
    Prodaja(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje,
            int godina_prodaje, const string &ime_kupca, const Datum &datum_rodjenja_kupca,
            const string &adresa_stana, int sprat_stana, int broj_soba,
            bool namjesten_stan, double broj_kvadrata)
        : agent(ime_agenta_prodaje), cijenaStana(cijena_stana), datumProdaje(dan_prodaje, mjesec_prodaje, godina_prodaje),
        kupac(ime_kupca, datum_rodjenja_kupca), stan(adresa_stana, sprat_stana, broj_soba, namjesten_stan, broj_kvadrata) {}
    void PromijeniKupca(const Kupac &novi_kupac) { kupac = novi_kupac; }
    void PromijeniStan(const Stan &novi_stan) { stan = novi_stan; }
    void PromijeniDatumKupovine(const Datum &novi_datum) { datumProdaje = novi_datum; }
    void PromijeniCijenuProdaje(const double &nova_cijena) { cijenaStana = nova_cijena; }
    void PomjeriDanUnaprijed() { datumProdaje.PomjeriZaDan("naprijed"); }
    void PomjeriDanUnazad() { datumProdaje.PomjeriZaDan("nazad"); }
    string DajImeAgenta() const { return agent; }
    string DajImeKupca() const { return kupac.DajImeIPrezime(); }
    Datum DajDatumProdaje() const { return datumProdaje; }
    double DajCijenuStana() const { return cijenaStana; }
    friend bool ProdatPrije(const Prodaja &p1, const Prodaja &p2);
    friend bool SkupljiStan(const Prodaja &p1, const Prodaja &p2);
    void Ispisi() const;
};

bool ProdatiPrije(const Prodaja& p1, const Prodaja& p2){
    if(p1.DajDatumProdaje().DajGodinu() == p2.DajDatumProdaje().DajGodinu()){
        if(p1.DajDatumProdaje().DajMjesec() == p2.DajDatumProdaje().DajMjesec())
            return p1.DajDatumProdaje().DajDan() < p2.DajDatumProdaje().DajDan();
        return p1.DajDatumProdaje().DajMjesec() < p2.DajDatumProdaje().DajMjesec();
    }
    return p1.DajDatumProdaje().DajGodinu() < p2.DajDatumProdaje().DajGodinu();
}

bool SkupljiStan(const Prodaja &p1, const Prodaja &p2){
    return p1.DajCijenuStana() > p2.DajCijenuStana();
}

void Prodaja::Ispisi() const {
    cout << setw(30) << left << "Ime agenta: " << agent << endl;
    cout << setw(30) << left << "Ime kupca: "; kupac.Ispisi();
    cout << setw(30) << left << "Zakazani datum prodaje: "; datumProdaje.Ispisi();
    cout << setw(30) << left << "Cijena stana: " << cijenaStana << endl;
    cout << "Informacije o stanu:" << endl;
    stan.Ispisi();
}

//

class Prodaje {
private:
    vector<shared_ptr<Prodaja>> niz;
public:
    explicit Prodaje() { }
    Prodaje(initializer_list<Prodaja> spisak_prodaja);
    Prodaje(const Prodaje &prodaje);
    Prodaje(Prodaje &&prodaje);
    Prodaje &operator =(const Prodaje &prodaje);
    Prodaje &operator =(Prodaje &&prodaje);
    void RegistrirajProdaju(const string &ime_agenta_prodaje,
        double cijena_stana, const Datum &datum_prodaje, const Kupac &kupac_stana,
        const Stan &kupljeni_stan);
    void RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje,
        int mjesec_prodaje, int godina_prodaje, string &ime_kupca,
        const Datum &datum_rodjenja_kupca, const string &adresa_stana,
        int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata);
    void RegistrirajProdaju(shared_ptr<Prodaja> prodaja);
    int DajBrojProdaja() const { return (int)niz.size(); }
    int DajBrojProdajaNaDatum(const Datum &datum) const;
    int DajBrojProdajaOdAgenta(const string &ime_agenta) const;
    Prodaja &DajNajranijuProdaju();
    Prodaja DajNajranijuProdaju() const;
    Prodaja &DajNajskupljuProdaju();
    Prodaja DajNajskupljuProdaju() const;
    void IsprazniKolekciju();
    void ObrisiNajranijuProdaju();
    void ObrisiProdajeAgenta(const string &ime_agenta);
    void ObrisiProdajeNaDatum(const Datum &datum);
    void IspisiProdajeNaDatum(const Datum &datum) const;
    void IspisiSveProdaje() const;
};

Prodaje::Prodaje(initializer_list<Prodaja> spisak_prodaja){
    for(Prodaja p : spisak_prodaja){
        niz.push_back(make_shared<Prodaja>(p));
    }
}

Prodaje::Prodaje(const Prodaje& prodaje){
    niz.clear();
    for(shared_ptr<Prodaja> p : prodaje.niz)
        niz.push_back(make_shared<Prodaja> (*p));
}

Prodaje& Prodaje::operator=(const Prodaje& prodaje){
    if(this != &prodaje){
        niz.clear();
        for(shared_ptr<Prodaja> p : prodaje.niz)
            niz.push_back(make_shared<Prodaja> (*p));
    }
    return *this;
}

Prodaje::Prodaje(Prodaje&& prodaje){
    niz.clear();
    for(shared_ptr<Prodaja> p : prodaje.niz)
        niz.push_back(make_shared<Prodaja> (*p));
    prodaje.niz.clear();
}

Prodaje& Prodaje::operator=(Prodaje&& prodaje){
    if(this != &prodaje){
        niz.clear();
        for(shared_ptr<Prodaja> p : prodaje.niz)
            niz.push_back(make_shared<Prodaja> (*p));
        prodaje.niz.clear();
    }
    return *this;
}


void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, const Datum &datum_prodaje,
                                 const Kupac &kupac_stana, const Stan &kupljeni_stan)
{
    Prodaja p(ime_agenta_prodaje, cijena_stana, datum_prodaje, kupac_stana, kupljeni_stan);
    niz.push_back(make_shared<Prodaja> (p));
}

void Prodaje::RegistrirajProdaju(const string &ime_agenta_prodaje, double cijena_stana, int dan_prodaje, int mjesec_prodaje, int godina_prodaje,
                        string &ime_kupca, const Datum &datum_rodjenja_kupca, const string &adresa_stana,
                        int sprat_stana, int broj_soba, bool namjesten_stan, double broj_kvadrata)
{
    Prodaja p(ime_agenta_prodaje, cijena_stana, dan_prodaje, mjesec_prodaje, godina_prodaje,
              ime_kupca, datum_rodjenja_kupca, adresa_stana,
              sprat_stana, broj_soba, namjesten_stan, broj_kvadrata);
    niz.push_back(make_shared<Prodaja> (p));
}

void Prodaje::RegistrirajProdaju(shared_ptr<Prodaja> prodaja){
    niz.push_back(prodaja);
}

int Prodaje::DajBrojProdajaNaDatum(const Datum& datum) const {
    return count_if(niz.begin(), niz.end(), [datum](shared_ptr<Prodaja> p){
       return p->DajDatumProdaje() == datum;
    });
}

int Prodaje::DajBrojProdajaOdAgenta(const string& ime_agenta) const {
    int rez(0);
    for(auto p : niz)
        if(p->DajImeAgenta() == ime_agenta) rez++;
    return rez;
}

Prodaja& Prodaje::DajNajranijuProdaju(){
    if(niz.empty()) throw domain_error("Nema registriranih prodaja");
    return **min_element(niz.begin(), niz.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2){
        return ProdatiPrije(*p1, *p2);
    });
}

Prodaja Prodaje::DajNajranijuProdaju() const {
    if(niz.empty()) throw domain_error("Nema registriranih prodaja");
    return **min_element(niz.begin(), niz.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2){
        return ProdatiPrije(*p1, *p2);
    });
}

Prodaja& Prodaje::DajNajskupljuProdaju(){
    if(niz.empty()) throw domain_error("Nema registriranih prodaja");
    return **max_element(niz.begin(), niz.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2){
        return SkupljiStan(*p1, *p2);
    });
}

Prodaja Prodaje::DajNajskupljuProdaju() const {
    if(niz.empty()) throw domain_error("Nema registriranih prodaja");
    return **max_element(niz.begin(), niz.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2){
        return SkupljiStan(*p1, *p2);
    });
}

void Prodaje::IsprazniKolekciju(){
    niz.clear();
}

void Prodaje::ObrisiNajranijuProdaju(){
    if(niz.empty()) throw range_error("Prazna kolekcija");
    Prodaja p = DajNajranijuProdaju();
    niz.erase(find_if(niz.begin(), niz.end(), [p](shared_ptr<Prodaja> prodaja) { return prodaja->DajDatumProdaje() == p.DajDatumProdaje(); }));
}

void Prodaje::ObrisiProdajeAgenta(const string& ime_agenta){
    for(auto it(niz.begin()); it != niz.end(); it++)
        if(it->get()->DajImeAgenta() == ime_agenta) niz.erase(it);
}

void Prodaje::ObrisiProdajeNaDatum(const Datum& datum){
    for(auto it(niz.begin()); it != niz.end(); it++)
        if(it->get()->DajDatumProdaje() == datum) niz.erase(it);
}

void Prodaje::IspisiProdajeNaDatum(const Datum& datum) const {
    vector<shared_ptr<Prodaja>> v(niz);
    sort(v.begin(), v.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2){
        return p1->DajImeKupca() < p2->DajImeKupca();
    });
    for(shared_ptr<Prodaja> p : v)
        if(p->DajDatumProdaje() == datum) p->Ispisi();
}

void Prodaje::IspisiSveProdaje() const {
    vector<shared_ptr<Prodaja>> v(niz);
    sort(v.begin(), v.end(), [](shared_ptr<Prodaja> p1, shared_ptr<Prodaja> p2){
        if(p1->DajDatumProdaje() == p2->DajDatumProdaje())
            return p1->DajImeKupca() < p2->DajImeKupca();
        return ProdatiPrije(*p1, *p2);
    });
    for(shared_ptr<Prodaja> p : v) p->Ispisi();
}

int main(){
    return 0;
}

int main2 ()
{
    try{
        bool kraj(false);
        Prodaje prodaje;
        vector<Stan> stanovi;
        vector<Kupac> kupci;
        cout << "Dobrodosli!" << endl << endl << endl;
        while(!kraj){
            int input;
            cout << "Izaberite opciju:" << endl;
            cout << " 0 - kraj" << endl;
            cout << " 1 - uredjivanje stanova" << endl; 
            cout << " 2 - uredjivanje kupaca" << endl;
            cout << " 3 - uredjivanje prodaja" << endl;
            cin >> input;
            if(input == 0) break;
            if(input == 1){
                while(1){
                    cout << "Izaberite opciju:" << endl;
                    cout << " 0 - nazad" << endl;
                    cout << " 1 - dodavanje stana" << endl; 
                    cout << " 2 - uredjivanje stanova" << endl;
                    cout << " 3 - ispis svih stanova" << endl;
                    cout << " 4 - kraj" << endl;
                    cin >> input;
                    if(input == 0) break;
                    if(input == 1){
                        bool dobar(false);
                        while(!dobar){
                            string adresa;
                            int sprat, brojSoba, namjesten;
                            double kvadratura;
                            cout << "Unesite adresu: ";
                            getline(cin, adresa);
                            cout << "Unesite sprat: ";
                            cin >> sprat;
                            cout << "Unesite broj soba: ";
                            cin >> brojSoba;
                            cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                            cin >> namjesten;
                            cout << "Unesite kvadraturu: ";
                            cin >> kvadratura;
                            try{
                                Stan s(adresa, sprat, brojSoba, namjesten, kvadratura);
                                stanovi.push_back(s);
                                cout << "Stan je uspjesno dodan!" << endl;
                                dobar = true;
                            }catch(exception &e){
                                cout << "Izuzetak: " << e.what() << " Molimo unesite opet." << endl;
                            }
                        }
                    }
                    else if(input == 2){
                        cout << "Odaberite stan. Dostupni stanovi su:" << endl;
                        for(int i(0); i < (int)stanovi.size(); i++)
                            cout << " " << i + 1 << " - ", stanovi[i].Ispisi();
                        cout << endl;
                        int indexStana, polje;
                        cin >> indexStana;
                        indexStana--;
                        while(1){
                        cout << "Odaberite polje koje zelite urediti:" << endl;
                        vector<string> meni { "nazad", "adresa", "sprat", "broj soba", "da li je stan namjesten", "kvadratura", "sve"};
                        for(int i(0); i < 7; i++)
                            cout << " " << i << " - " << meni[i] << endl;
                        cin >> polje;
                        if(polje == 0) break;
                        bool dobar(false);
                        while(!dobar){
                            try{
                                if (polje == 1){
                                    string adresa;
                                    cout << "Unesite adresu: ";
                                    getline(cin, adresa);
                                    stanovi[indexStana].Postavi(adresa, stanovi[indexStana].DajSprat(), stanovi[indexStana].DajBrojSoba(), stanovi[indexStana].DajNamjesten(), stanovi[indexStana].DajKvadraturu());
                                    cout << "Stan je uspjesno izmjenjen!" << endl;
                                    dobar = true;
                                }
                                else if(polje == 2){
                                    int sprat;
                                    cout << "Unesite sprat: ";
                                    cin >> sprat;
                                    stanovi[indexStana].Postavi(stanovi[indexStana].DajAdresu(), sprat, stanovi[indexStana].DajBrojSoba(), stanovi[indexStana].DajNamjesten(), stanovi[indexStana].DajKvadraturu());
                                    cout << "Stan je uspjesno izmjenjen!" << endl;
                                    dobar = true;
                                }
                                else if(polje == 3){
                                    int brojSoba;
                                    cout << "Unesite broj soba: ";
                                    cin >> brojSoba;
                                    stanovi[indexStana].Postavi(stanovi[indexStana].DajAdresu(), stanovi[indexStana].DajSprat(), brojSoba, stanovi[indexStana].DajNamjesten(), stanovi[indexStana].DajKvadraturu());
                                    cout << "Stan je uspjesno izmjenjen!" << endl;
                                    dobar = true;
                                }
                                else if(polje == 4){
                                    int namjesten;
                                    cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                    cin >> namjesten;
                                    stanovi[indexStana].Postavi(stanovi[indexStana].DajAdresu(), stanovi[indexStana].DajSprat(), stanovi[indexStana].DajBrojSoba(), namjesten, stanovi[indexStana].DajKvadraturu());
                                    cout << "Stan je uspjesno izmjenjen!" << endl;
                                    dobar = true;
                                }
                                else if(polje == 5){
                                    double kvadratura;
                                    cout << "Unesite kvadraturu: ";
                                    cin >> kvadratura;
                                    stanovi[indexStana].Postavi(stanovi[indexStana].DajAdresu(), stanovi[indexStana].DajSprat(), stanovi[indexStana].DajBrojSoba(), stanovi[indexStana].DajNamjesten(), kvadratura);
                                    cout << "Stan je uspjesno izmjenjen!" << endl;
                                    dobar = true;
                                }
                                else if(polje == 6){
                                    string adresa;
                                    int sprat, brojSoba, namjesten;
                                    double kvadratura;
                                    cout << "Unesite adresu: ";
                                    getline(cin, adresa);
                                    cout << "Unesite sprat: ";
                                    cin >> sprat;
                                    cout << "Unesite broj soba: ";
                                    cin >> brojSoba;
                                    cout << "Da li je stan namjesten (1 - da, 0 - ne): ";
                                    cin >> namjesten;
                                    cout << "Unesite kvadraturu: ";
                                    cin >> kvadratura;
                                    stanovi[indexStana].Postavi(adresa, sprat, brojSoba, namjesten, kvadratura);
                                    cout << "Stan je uspjesno izmjenjen!" << endl;
                                    dobar = true;
                                }
                            }catch(exception &e){
                                cout << "Izuzetak: " << e.what() << " Molimo unesite opet." << endl;
                            }
                        }
                        }
                    }
                    else if(input == 3){
                        for(int i(0); i < (int)stanovi.size(); i++)
                            cout << i + 1 << ". ", stanovi[i].Ispisi();
                    }
                    else if(input == 4) break;
                    cout << endl;
                }
            }
        }
    }catch(exception &e){
        cout << e.what();
    }
	return 0;
}

