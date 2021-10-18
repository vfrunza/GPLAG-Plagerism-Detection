/B2017/2018: Zadaća 4, Zadatak 3
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
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { auto Parametri = novo_vrijeme.Ocitaj(); vrijeme_pregleda.Postavi(Parametri.first, Parametri.second);} 
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
    int max_broj_pregleda;
    int broj_pregleda;
    Pregled **spisak;
public:
    explicit Pregledi (int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda), broj_pregleda(0), spisak(new Pregled*[max_broj_pregleda]{}){}
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi() {
        for(int i(0); i<broj_pregleda; i++)
            delete spisak[i];
        delete [] spisak;
    }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator=(const Pregledi &pregledi);
    Pregledi &operator=(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const { return broj_pregleda; }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda): broj_pregleda(spisak_pregleda.size()), max_broj_pregleda(spisak_pregleda.size()) {
    spisak = new Pregled*[spisak_pregleda.size()]{};
    int i(0);
    try {
        for (auto klizeci(spisak_pregleda.begin()); klizeci!=spisak_pregleda.end(); klizeci++) {
            spisak[i]=new Pregled(*klizeci); i++;
        }
    } catch(...) {
        for(int j(0); j<i; j++) 
            delete spisak[j];
        delete[] spisak;
        throw;
    }
}

Pregledi::Pregledi(const Pregledi &pregledi) : broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda), spisak(new Pregled*[pregledi.max_broj_pregleda]{}) {
    try {
    for (int i(0); i<pregledi.broj_pregleda; i++) 
        spisak[i] = new Pregled (*pregledi.spisak[i]);
    } catch(...) {
        for (int i(0); i<pregledi.broj_pregleda; i++)
            delete spisak[i];
        delete[] spisak;
        throw;
    }
}

Pregledi::Pregledi(Pregledi &&pregledi): max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda), spisak(pregledi.spisak) {
    pregledi.spisak = nullptr;
}

Pregledi& Pregledi::operator =(const Pregledi &pregledi) {
    if(&pregledi!=this) {
        if(max_broj_pregleda!=pregledi.max_broj_pregleda) {
            for (int i(0); i<broj_pregleda; i++) 
                delete spisak[i];
            delete[] spisak;
            spisak = new Pregled*[pregledi.max_broj_pregleda]{};
            try {
                for(int i(0); i<pregledi.broj_pregleda; i++) 
                    spisak[i] = new Pregled(*pregledi.spisak[i]);
            }catch(...) {
                for (int i(0); i<pregledi.broj_pregleda; i++) {
                    delete spisak[i];
                    spisak[i]=nullptr;
                }
                throw;
            }
            max_broj_pregleda=pregledi.max_broj_pregleda; broj_pregleda = pregledi.broj_pregleda; 
        }
        else {
            if(pregledi.broj_pregleda<broj_pregleda) {
                for(int i=pregledi.broj_pregleda; i<broj_pregleda; i++) {
                    delete spisak[i]; spisak[i]=nullptr;
                }
            }
            else {
                try {
                    for(int i=broj_pregleda; i<pregledi.broj_pregleda; i++)
                        spisak[i] = new Pregled(*pregledi.spisak[i]);
                } catch(...) {
                    for (int i=broj_pregleda; i<pregledi.broj_pregleda; i++) {
                        delete spisak[i];
                        spisak[i] = nullptr;
                    }
                throw;
                }
            }
            broj_pregleda = pregledi.broj_pregleda;
            for (int i(0); i<broj_pregleda; i++) 
                *spisak[i] = *pregledi.spisak[i];
        }
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    if(&pregledi!=this) {
        std::swap(pregledi.max_broj_pregleda, max_broj_pregleda);
        std::swap(pregledi.broj_pregleda, broj_pregleda);
        std::swap(pregledi.spisak, spisak);
    }
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
    broj_pregleda++;
    spisak[broj_pregleda-1] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
    broj_pregleda++;
    spisak[broj_pregleda-1] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
}

void Pregledi::RegistrirajPregled(Pregled *pregled) {
    if(broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalan broj pregleda");
    broj_pregleda++; 
    spisak[broj_pregleda-1] = pregled; 
   
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    int brojac(0);
    for(int i(0); i<broj_pregleda; i++) {
        if(spisak[i]->DajDatumPregleda().Ocitaj()==datum.Ocitaj()) brojac++; 
    }
    return brojac;
}

Pregled& Pregledi::DajNajranijiPregled() {
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto lokacija(std::min_element(spisak, spisak+broj_pregleda, [=](Pregled *p1, Pregled *p2) { return Pregled::DolaziPrije(*p1, *p2); }));
    return **lokacija;
}

Pregled Pregledi::DajNajranijiPregled() const {
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    auto lokacija(std::min_element(spisak, spisak+broj_pregleda, [=](Pregled *p1, Pregled *p2) { return Pregled::DolaziPrije(*p1, *p2); }));
    return **lokacija;
}

void Pregledi::IsprazniKolekciju () {
    for(int i(0); i<broj_pregleda; i++) {
        delete spisak[i];
        spisak[i] = nullptr;
    }
    broj_pregleda=0;
}


void Pregledi::ObrisiNajranijiPregled() {  
    if (broj_pregleda==0) throw std::range_error("Prazna kolekcija");
    auto lokacija(std::min_element(spisak, spisak+broj_pregleda, [=](Pregled *p1, Pregled *p2) { return Pregled::DolaziPrije(*p1, *p2); }));
    delete *lokacija;
    *lokacija = nullptr;
    std::swap(*lokacija, spisak[broj_pregleda-1]);
    broj_pregleda--;
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    int i(0);
    std::remove_copy_if(spisak, spisak+broj_pregleda, spisak, [&i, ime_pacijenta](Pregled *p){
        if(p->DajImePacijenta()==ime_pacijenta) { 
            delete p; p=nullptr; i++; return true; 
        } 
        return false; 
    });
    broj_pregleda-=i;
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    std::vector<Pregled*> PNTD (DajBrojPregledaNaDatum(datum));
    std::copy_if(spisak, spisak+broj_pregleda, PNTD.begin(), [=](Pregled *trenutni) { return datum.Ocitaj()==trenutni->DajDatumPregleda().Ocitaj(); });
    std::sort(PNTD.begin(), PNTD.end(), [=](Pregled *p1, Pregled *p2) { return Pregled::DolaziPrije(*p1, *p2); });
    std::for_each(PNTD.begin(), PNTD.end(), [](Pregled *nekipregled){ nekipregled->Ispisi(); });
}

void Pregledi::IspisiSvePreglede() const {
    std::vector<Pregled*> SP (broj_pregleda);
    std::copy(spisak, spisak+broj_pregleda, SP.begin());
    std::sort(SP.begin(), SP.end(), [](Pregled *p1, Pregled *p2) { return Pregled::DolaziPrije(*p1, *p2); });
    std::for_each(SP.begin(), SP.end(), [](Pregled *nekipregled){ nekipregled->Ispisi(); });
}

void IspisInterfejsa() {
    cout << endl << "Odaberite jednu od sljedecih opcija" << endl << "1 - Broj pregleda na datum" << endl << "2 - Najraniji pregled" << endl << "3 - Obrisi pregled pacijenta" << endl << "4 - Obrisi najraniji pregled" << endl << "5 - Ispisi sve pregleda na datum" << endl << "6 - Ispisi sve preglede" << endl << "7 - Kraj programa" << endl;
}

int main ()
{
    cout << "Unesite maksimalan broj pregleda: ";
    int max;
    cin >> max;
    Pregledi bazapregleda(max);
    for(int i(0); i<max; i++) {
        cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string ime; std::getline(cin, ime);
        if(ime=="kraj") break;
        int dan, mjesec, godina, sati, minute;
        cout << "Unesite dan mjesec i godinu pregleda: "; cin >> dan >> mjesec >> godina;
        cout << "Unesite sate i minute pregleda: "; cin >> sati >> minute;
        bazapregleda.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);
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
 