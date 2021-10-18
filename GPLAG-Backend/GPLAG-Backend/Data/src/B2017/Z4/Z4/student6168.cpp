/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <tuple>
#include <stdexcept>
#include <initializer_list>
#include <string> 
#include <vector>
#include <iterator>
#include <memory>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::get;

class Datum {
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const { return std::make_tuple(dan, mjesec, godina); }
    void Ispisi() const { cout << dan << "/" << mjesec << "/" << godina; }
};

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina%4==0 && godina%100!=0 || godina%400==0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
}

class Vrijeme {
    int sati, minute;
public:
    Vrijeme (int sati, int minute) { Postavi(sati, minute); }
    void Postavi (int sati, int minute);
    std::pair<int, int> Ocitaj () const { return std::make_pair(sati, minute); }
    void Ispisi() const { cout << std::setw(2) << std::setfill('0') << std::right << sati << ":" << std::setw(2) << minute << std::setfill(' '); } 
};

void Vrijeme::Postavi (int sati, int minute) {
    if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati = sati; Vrijeme::minute = minute;
}

class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {} 
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda): ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta) { Pregled::ime_pacijenta = ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { auto Parametri = novi_datum.Ocitaj(); datum_pregleda.Postavi(get<0>(Parametri), get<1>(Parametri), get<2>(Parametri));}
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { auto Parametri = novo_vrijeme.Ocitaj(); vrijeme_pregleda.Postavi(get<0>(Parametri), get<1>(Parametri));} 
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda () const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const { cout << std::left << std::setw(30) << ime_pacijenta; datum_pregleda.Ispisi(); cout << " "; vrijeme_pregleda.Ispisi(); cout << endl; }
};

void Pregled::PomjeriDanUnaprijed() {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    auto Parametri = datum_pregleda.Ocitaj();
    int d = get<0>(Parametri), m = get<1>(Parametri), g = get<2>(Parametri);
    if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
    d++;
    if(d>broj_dana[m-1]) {
        if(m<12) { d=1; m+=1; }
        else { d=1; m=1; g+=1; }
    }
    Pregled::datum_pregleda.Postavi(d, m, g);
}

void Pregled::PomjeriDanUnazad() {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    auto Parametri = datum_pregleda.Ocitaj();
    int d = get<0>(Parametri), m = get<1>(Parametri), g = get<2>(Parametri);
    if(g%4==0 && (g%100!=0 || g%400==0)) broj_dana[1]++;
    d--;
    if(d==0) {
        if(m>1) { m-=1; d=broj_dana[m-1]; }
        else { g-=1; m=12; d=broj_dana[m-1];  }
    }
    Pregled::datum_pregleda.Postavi(d, m, g);
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    auto p1_datum = p1.datum_pregleda.Ocitaj(); auto p2_datum = p2.datum_pregleda.Ocitaj();
    auto p1_vrijeme = p1.vrijeme_pregleda.Ocitaj(); auto p2_vrijeme = p2.vrijeme_pregleda.Ocitaj();
    if(get<2>(p1_datum)<get<2>(p2_datum)) return true; 
    if(get<2>(p1_datum)==get<2>(p2_datum)){
        if(get<1>(p1_datum)<get<1>(p2_datum)) return true;
        if(get<1>(p1_datum)==get<1>(p2_datum)) {
            if(get<0>(p1_datum)<get<0>(p2_datum)) return true;
            if(get<0>(p1_datum)==get<0>(p2_datum)) {
                if(p1_vrijeme.first<p2_vrijeme.first) return true;
                if(p1_vrijeme.first==p2_vrijeme.first) {
                    if(p1_vrijeme.second<p2_vrijeme.second) return true;
                }
            }
        }
    }
    return false;
}

class Pregledi {
    std::vector<std::shared_ptr<Pregled>> spisak;
public:
    explicit Pregledi () {};
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi() {
        for(int i(0); i<spisak.size(); i++)
           spisak[i]=nullptr;
    }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const { return spisak.size(); }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
    int i(0);
    for (auto klizeci(spisak_pregleda.begin()); klizeci!=spisak_pregleda.end(); klizeci++) {
        spisak.push_back(std::make_shared<Pregled>(*klizeci)); i++;
    } 
}

Pregledi::Pregledi(const Pregledi &pregledi) {
    for (int i(0); i<pregledi.spisak.size(); i++) 
        spisak.push_back(std::make_shared<Pregled>(*pregledi.spisak[i]));
}

Pregledi::Pregledi(Pregledi &&pregledi) {
    spisak = std::move(pregledi.spisak);
}

Pregledi& Pregledi::operator =(const Pregledi &pregledi) {
    spisak.clear();
    for(int i(0); i<pregledi.spisak.size(); i++)
        spisak.push_back(std::make_shared<Pregled>(*pregledi.spisak[i]));
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    if(&pregledi!=this) {
        spisak.clear();
        spisak = std::move(pregledi.spisak);
    }
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    spisak.push_back(std::make_shared<Pregled>(Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda)));
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    spisak.push_back(std::make_shared<Pregled>(Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda)));
}

void Pregledi::RegistrirajPregled(Pregled *pregled) {
    spisak.push_back(std::make_shared<Pregled>(*pregled)); 
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    int brojac(0);
    for(int i(0); i<spisak.size(); i++) {
        if(spisak[i]->DajDatumPregleda().Ocitaj()==datum.Ocitaj()) brojac++; 
    }
    return brojac;
}

Pregled& Pregledi::DajNajranijiPregled() {
    if(!spisak.size()) throw std::domain_error("Nema registriranih pregleda");
    auto lokacija(std::min_element(spisak.begin(), spisak.end(), [=](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) { return Pregled::DolaziPrije(*p1, *p2); }));
    return **lokacija;
}

Pregled Pregledi::DajNajranijiPregled() const {
    if(!spisak.size()) throw std::domain_error("Nema registriranih pregleda");
    auto lokacija(std::min_element(spisak.begin(), spisak.end(), [=](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) { return Pregled::DolaziPrije(*p1, *p2); }));
    return **lokacija;
}

void Pregledi::IsprazniKolekciju () {
    for(int i(0); i<spisak.size(); i++)
        spisak[i] = nullptr;
    spisak.resize(0);
}


void Pregledi::ObrisiNajranijiPregled() {  
    if (!spisak.size()) throw std::range_error("Prazna kolekcija");
    auto lokacija(std::min_element(spisak.begin(), spisak.end(), [=](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) { return Pregled::DolaziPrije(*p1, *p2); }));
    *lokacija = nullptr;
    std::swap(*lokacija, spisak[spisak.size()-1]);
    int trenutna = spisak.size();
    spisak.resize(trenutna-1);
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    if (spisak.size()>0) {
        std::vector<std::shared_ptr<Pregled>> Krajnji;
        std::copy_if(spisak.begin(), spisak.end(), back_inserter(Krajnji), [=](std::shared_ptr<Pregled> p) { return p->DajImePacijenta()!=ime_pacijenta; });
        IsprazniKolekciju();
        std::copy(Krajnji.begin(), Krajnji.end(), back_inserter(spisak));
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    std::vector<std::shared_ptr<Pregled>> PNTD (DajBrojPregledaNaDatum(datum));
    std::copy_if(spisak.begin(), spisak.end(), PNTD.begin(), [=](std::shared_ptr<Pregled> trenutni) { return datum.Ocitaj()==trenutni->DajDatumPregleda().Ocitaj(); });
    std::sort(PNTD.begin(), PNTD.end(), [=](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) { return Pregled::DolaziPrije(*p1, *p2); });
    std::for_each(PNTD.begin(), PNTD.end(), [](std::shared_ptr<Pregled> nekipregled){ nekipregled->Ispisi(); });
}

void Pregledi::IspisiSvePreglede() const {
    std::vector<std::shared_ptr<Pregled>> SP (spisak.size());
    std::copy(spisak.begin(), spisak.end(), SP.begin());
    std::sort(SP.begin(), SP.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) { return Pregled::DolaziPrije(*p1, *p2); });
    std::for_each(SP.begin(), SP.end(), [](std::shared_ptr<Pregled> nekipregled){ nekipregled->Ispisi(); });
}

void IspisInterfejsa() {
    cout << endl << "Odaberite jednu od sljedecih opcija" << endl << "1 - Broj pregleda na datum" << endl << "2 - Najraniji pregled" << endl << "3 - Obrisi pregled pacijenta" << endl << "4 - Obrisi najraniji pregled" << endl << "5 - Ispisi sve pregleda na datum" << endl << "6 - Ispisi sve preglede" << endl << "7 - Kraj programa" << endl;
}

int main ()
{
    Pregledi bazapregleda;
    for(;;) {
        cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime; std::getline(cin, ime);
        if(ime=="kraj") break;
        int dan, mjesec, godina, sati, minute;
        cout << "Unesite dan mjesec i godinu pregleda: ";
        cin >> dan >> mjesec >> godina;
        cout << "Unesite sate i minute pregleda: ";
        cin >> sati >> minute;
        bazapregleda.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);
        cin.ignore(5, '\n');
    }
    cout << "Trenutno su registrovani sljedeci pregledi" << endl;
    bazapregleda.IspisiSvePreglede();
    for (;;) {  
        IspisInterfejsa();
        int izbor; cin >> izbor;
        try {
            switch(izbor) {
                case 1: {
                    cout << "Unesite dan mjesec i godinu : ";
                    int d, m, g; cin>>d>>m>>g; 
                    cout<<"Broj pregleda na datum "<<d<<" "<<m<<" "<<g<<" je: "<<bazapregleda.DajBrojPregledaNaDatum(Datum(d, m, g));
                    break; }
                case 2: {
                    Pregled najraniji_pregled(bazapregleda.DajNajranijiPregled());
                    cout << "Najraniji pregled je: " << endl; najraniji_pregled.Ispisi();
                    break; }
                case 3: {
                    cout << endl << "Unesite ime pacijenta: ";
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::string ime2;
                    std::getline(cin, ime2);
                    int BrojPregledaPrijeBrisanja = bazapregleda.DajBrojPregleda();
                    bazapregleda.ObrisiPregledePacijenta(ime2);
                    int BrojObrisanih = BrojPregledaPrijeBrisanja-bazapregleda.DajBrojPregleda();
                    cout << "Uspjesno obrisano " << BrojObrisanih << " pregleda" << endl;
                    break; }
                case 4: {
                    bazapregleda.ObrisiNajranijiPregled();
                    cout << "Najraniji pregled uspjesno obrisan";
                    break; }
                case 5: {
                    cout << "Unesite dan mjesec i godinu : ";
                    int d2, m2, g2; cin >> d2 >> m2 >> g2;
                    cout << "Pregledi na datum " << d2 << " " << m2 << " " << g2 << " su: " << endl;
                    bazapregleda.IspisiPregledeNaDatum(Datum(d2, m2, g2));
                    break; }
                case 6:
                    bazapregleda.IspisiSvePreglede();
                    break; 
                case 7:
                    break;
            }
            if(izbor==7) break;
            if(izbor!=6) cout << endl;
        } catch(std::exception &izuzetak) {
            cout << izuzetak.what() << endl;
        }
    }
	return 0;
}
 