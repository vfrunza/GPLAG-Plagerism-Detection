/B 2016/2017, Zadaća 4, Zadatak 4
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
#include <memory>

using namespace std;

class Datum {
    int dan, mjesec, godina;
    void ProvjeraDatuma(int dan, int mjesec, int godina);
public:
    Datum(int dan, int mjesec, int godina) : dan(dan), mjesec(mjesec), godina(godina) {
        ProvjeraDatuma(dan, mjesec, godina);
    };
    void Postavi(int dan, int mjesec, int godina) {
        ProvjeraDatuma(dan, mjesec, godina);
        this->dan = dan; this->mjesec = mjesec;
        this->godina = godina;
    };
    int DajDan() const { return dan; }
    int DajMjesec() const { return mjesec; }
    int DajGodinu() const { return godina; }
    void Ispisi() const {
        cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme {
    int sati, minute;
    void ProvjeraVremena(int sati, int minute);
public:
    Vrijeme(int sati, int minute) : sati(sati), minute(minute) {
        ProvjeraVremena(sati, minute);
    };
    void Postavi(int sati, int minute) {
        ProvjeraVremena(sati, minute);
        this->sati = sati; this->minute = minute;
    }
    int DajSate() const { return sati; }
    int DajMinute() const { return minute; }
    void Ispisi() const {
        cout << setfill('0') << setw(2) << right << sati << ":" << setw(2) << minute;
    }
};

class Pregled {
    string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
        const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta),
        datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {};
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
        int godina_pregleda, int sati_pregleda, int minute_pregleda) :
        ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda),
        vrijeme_pregleda(sati_pregleda, minute_pregleda) {};
    void PromijeniPacijenta(const std::string &ime_pacijenta) { this->ime_pacijenta = ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { datum_pregleda = novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme_pregleda = novo_vrijeme; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    friend bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        cout << left << setw(30) << setfill(' ') << ime_pacijenta;
        datum_pregleda.Ispisi(); cout << " "; vrijeme_pregleda.Ispisi();
        cout << endl;
    }
};

class Pregledi {
    vector<shared_ptr<Pregled>> niz_pregleda;
    bool JednakiDatumi(const Datum &d1, const Datum &d2) {
        return d1.DajDan() == d2.DajDan() && d1.DajMjesec() == d2.DajMjesec()
           && d1.DajGodinu() == d2.DajGodinu();
    }
    bool JednakoVrijeme(const Vrijeme &v1, const Vrijeme &v2) {
        return v1.DajSate() == v2.DajSate()
        && v1.DajMinute() == v2.DajMinute();
    }
public:
    explicit Pregledi() = default;
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi() = default;
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta,
     const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
     int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
     int minute_pregleda);
    void RegistrirajPregled(shared_ptr<Pregled> pregled);
    int DajBrojPregleda() const { return niz_pregleda.size(); };
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(Datum &datum) const;
    void IspisiSvePreglede() const;
};

void Datum::ProvjeraDatuma(int dan, int mjesec, int godina) {
    int dani_u_mjesecu[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
        dani_u_mjesecu[1]++;
    if(godina < 0 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > dani_u_mjesecu[mjesec - 1])
        throw domain_error("Neispravan datum");
}

void Vrijeme::ProvjeraVremena(int sati, int minute) {
    if(sati < 0 || sati > 23 || minute < 0 || minute > 59)
        throw domain_error("Neispravno vrijeme");
}

void Pregled::PomjeriDanUnaprijed() {
    try {
        datum_pregleda.Postavi(datum_pregleda.DajDan() + 1,
            datum_pregleda.DajMjesec(), datum_pregleda.DajGodinu());
    }
    catch(...) {
        try {
            datum_pregleda.Postavi(1,
                datum_pregleda.DajMjesec() + 1, datum_pregleda.DajGodinu());
        }
        catch(...) {
            datum_pregleda.Postavi(1, 1, datum_pregleda.DajGodinu() + 1);
        }
    }
}

void Pregled::PomjeriDanUnazad() {
    if(datum_pregleda.DajDan() == 1) {
        if(datum_pregleda.DajMjesec() == 1)
            datum_pregleda.Postavi(31, 12, datum_pregleda.DajGodinu() - 1);
        else {
            int max_dana(31);
            bool uspjelo(false);
            while(!uspjelo) {
                try {
                    datum_pregleda.Postavi(max_dana--,
                        datum_pregleda.DajMjesec() - 1, datum_pregleda.DajGodinu());
                    uspjelo = true;
                }
                catch(...) {}
            }
        }
    }
    else
        datum_pregleda.Postavi(datum_pregleda.DajDan() - 1,
            datum_pregleda.DajMjesec(), datum_pregleda.DajGodinu());
}

bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
    auto d1(p1.DajDatumPregleda()), d2(p2.DajDatumPregleda());
    auto v1(p1.DajVrijemePregleda()), v2(p2.DajVrijemePregleda());
    if(d1.DajGodinu() < d2.DajGodinu()) return true;
    else if(d1.DajGodinu() > d2.DajGodinu()) return false;
    else {
        if(d1.DajMjesec() < d2.DajMjesec()) return true;
        else if(d1.DajMjesec() > d2.DajMjesec()) return false;
        else {
            if(d1.DajDan() < d2.DajDan()) return true;
            else if(d1.DajDan() > d2.DajDan()) return false;
            else {
                if(v1.DajSate() < v2.DajSate()) return true;
                else if(v1.DajSate() > v2.DajSate()) return false;
                else return v1.DajMinute() < v2.DajMinute();
            }
        }
    }
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) :
    niz_pregleda(spisak_pregleda.size()) {
    for(int i = 0; i < niz_pregleda.size(); i++)
        niz_pregleda[i] = make_shared<Pregled>(*(spisak_pregleda.begin() + i));
}

Pregledi::Pregledi(const Pregledi &pregledi) : niz_pregleda(pregledi.DajBrojPregleda()) {
    for(int i = 0; i < niz_pregleda.size(); i++)
        niz_pregleda[i] = make_shared<Pregled>(*niz_pregleda[i]);
}

Pregledi::Pregledi(Pregledi &&pregledi) : niz_pregleda(pregledi.niz_pregleda) {}

Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
    if(&pregledi != this) {
        niz_pregleda.resize(pregledi.DajBrojPregleda());
        for(int i = 0; i < niz_pregleda.size(); i++)
            niz_pregleda[i] = make_shared<Pregled>(*pregledi.niz_pregleda[i]);
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    niz_pregleda = pregledi.niz_pregleda;
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,
    const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    niz_pregleda.push_back(make_shared<Pregled>(ime_pacijenta,
        datum_pregleda, vrijeme_pregleda));
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda,
    int minute_pregleda) {
    niz_pregleda.push_back(make_shared<Pregled>(ime_pacijenta, dan_pregleda,
        mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
}

void Pregledi::RegistrirajPregled(shared_ptr<Pregled> pregled) {
    niz_pregleda.push_back(make_shared<Pregled>(*pregled));
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return count_if(niz_pregleda.begin(), niz_pregleda.end(),
        [datum, this](shared_ptr<Pregled> p) {
            return JednakiDatumi(datum, p->DajDatumPregleda());
        });
}

Pregled &Pregledi::DajNajranijiPregled() {
    if(DajBrojPregleda() == 0) throw domain_error("Nema registriranih pregleda");
    return **min_element(niz_pregleda.begin(), niz_pregleda.end(),
    [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2) { return DolaziPrije(*p1, *p2); });

}

Pregled Pregledi::DajNajranijiPregled() const {
    if(DajBrojPregleda() == 0) throw domain_error("Nema registriranih pregleda");
    return **min_element(niz_pregleda.begin(), niz_pregleda.end(),
    [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2) { return DolaziPrije(*p1, *p2); });
}

void Pregledi::IsprazniKolekciju() {
    niz_pregleda.resize(0);
}

void Pregledi::ObrisiNajranijiPregled() {
    if(DajBrojPregleda() == 0)
        throw domain_error("Prazna kolekcija");
    auto najraniji(DajNajranijiPregled());
    for(int i = 0; i < niz_pregleda.size(); i++) {
        if(JednakiDatumi(najraniji.DajDatumPregleda(), niz_pregleda[i]->DajDatumPregleda())
           && JednakoVrijeme(najraniji.DajVrijemePregleda(), niz_pregleda[i]->DajVrijemePregleda())
           && najraniji.DajImePacijenta() == niz_pregleda[i]->DajImePacijenta()) {
            niz_pregleda.erase(niz_pregleda.begin() + i);
            break;
        }
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for(int i = 0; i < DajBrojPregleda(); i++)
        if(niz_pregleda[i]->DajImePacijenta() == ime_pacijenta) {
            niz_pregleda.erase(niz_pregleda.begin() + i); i--;
        }
}

void Pregledi::IspisiPregledeNaDatum(Datum &datum) const {
    vector<shared_ptr<Pregled>> pregledi;
    copy_if(niz_pregleda.begin(), niz_pregleda.end(), back_inserter(pregledi),
        [datum, this](shared_ptr<Pregled> p) { return JednakiDatumi(p->DajDatumPregleda(), datum); });
    sort(pregledi.begin(), pregledi.end(),
         [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2) { return DolaziPrije(*p1, *p2); });
    for(auto i : pregledi)
        i->Ispisi();
}

void Pregledi::IspisiSvePreglede() const {
    vector<shared_ptr<Pregled>> pregledi(niz_pregleda);
    sort(pregledi.begin(), pregledi.end(),
         [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2) { return DolaziPrije(*p1, *p2); });
    for(auto i : pregledi)
        i->Ispisi();
}

int main() {
    return 0;
}