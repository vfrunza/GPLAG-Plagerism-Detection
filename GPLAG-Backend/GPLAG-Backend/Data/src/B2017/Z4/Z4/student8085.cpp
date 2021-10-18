/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

class Datum {
    int Dan, Mjesec, Godina;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const { return make_tuple(Dan, Mjesec, Godina); }
    void Ispisi() const { cout << Dan << "/" << Mjesec << "/" << Godina; }
};

Datum::Datum(int dan, int mjesec, int godina) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw domain_error("Neispravno vrijeme");
        
    Dan = dan;
    Mjesec = mjesec;
    Godina = godina;
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
        throw domain_error("Neispravno vrijeme");
        
    Dan = dan;
    Mjesec = mjesec;
    Godina = godina;
}

class Vrijeme {
    int Sati, Minute;
public:
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj () const { return make_pair(Sati, Minute); }
    void Ispisi() const;
};

Vrijeme::Vrijeme(int sati, int minute) {
    if(sati < 0 || minute < 0 || sati > 23 || minute > 59)
        throw domain_error("Neispravno vrijeme");
        
    Sati = sati;
    Minute = minute;
}

void Vrijeme::Postavi(int sati, int minute) {
    if(sati < 0 || minute < 0 || sati > 23 || minute > 59)
        throw domain_error("Neispravno vrijeme");
        
    Sati = sati;
    Minute = minute;
}

void Vrijeme::Ispisi() const {
    if(Sati < 10) cout << "0";
    cout << Sati << ":";
    if(Minute < 10) cout << "0";
    cout << Minute;
}

class Pregled {
    string ime;
    Datum datum;
    Vrijeme vrijeme;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,
        const Vrijeme &vrijeme_pregleda) : ime(ime_pacijenta), datum(get<0>(datum_pregleda.Ocitaj()), get<1>(datum_pregleda.Ocitaj()), get<2>(datum_pregleda.Ocitaj())),
        vrijeme(vrijeme_pregleda.Ocitaj().first, vrijeme_pregleda.Ocitaj().second) {}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
        int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime(ime_pacijenta), datum(dan_pregleda, mjesec_pregleda, godina_pregleda), 
        vrijeme(sati_pregleda, minute_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta) { ime = ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime; }
    Datum DajDatumPregleda() const { return datum; }
    Vrijeme DajVrijemePregleda() const { return vrijeme; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

void Pregled::PromijeniDatum(const Datum &novi_datum) {
    tuple<int, int, int> d = novi_datum.Ocitaj();
    datum.Postavi(get<0>(d), get<1>(d), get<2>(d));
}

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
    pair<int, int> v = novo_vrijeme.Ocitaj();
    vrijeme.Postavi(v.first, v.second);
}

void Pregled::PomjeriDanUnaprijed() {
    int d1, m1, g1;
    
    tuple<int, int, int> d = datum.Ocitaj();
    d1 = get<0>(d);
    m1 = get<1>(d);
    g1 = get<2>(d);
    
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g1 % 4 == 0 && g1 % 100 != 0 || g1 % 400 == 0) broj_dana[1]++;
    d1++;
    if(d1 == broj_dana[m1 - 1] + 1) {
        d1 = 1;
        m1++;
    }
    if(m1 = 13) {
        m1 = 1;
        g1++;
    }
    
    datum.Postavi(d1, m1, g1);
}

void Pregled::PomjeriDanUnazad() {
    int d1, m1, g1;
    
    tuple<int, int, int> d = datum.Ocitaj();
    d1 = get<0>(d);
    m1 = get<1>(d);
    g1 = get<2>(d);
    
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g1 % 4 == 0 && g1 % 100 != 0 || g1 % 400 == 0) broj_dana[1]++;
    d1--;
    if(d1 == 0) {
        if(m1 == 1) {
            m1 = 12;
            g1--;
        } else m1--;
        d1 = broj_dana[m1 - 1];
    }
    datum.Postavi(d1, m1, g1);
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    bool dolazi = false;
    int d1, d2, m1, m2, g1, g2, s1, s2, mi1, mi2;
    
    tuple<int, int, int> dp1 = p1.datum.Ocitaj();
    d1 = get<0>(dp1);
    m1 = get<1>(dp1);
    g1 = get<2>(dp1);
    
    pair<int, int> vp1 = p1.vrijeme.Ocitaj();
    s1 = vp1.first;
    mi1 = vp1.second;
    
    tuple<int, int, int> dp2 = p2.datum.Ocitaj();
    d2 = get<0>(dp2);
    m2 = get<1>(dp2);
    g2 = get<2>(dp2);
    
    pair<int, int> vp2 = p2.vrijeme.Ocitaj();
    s2 = vp2.first;
    mi2 = vp2.second;
    
    if(g1 < g2) dolazi = true;
    else if(g1 == g2) {
        if(m1 < m2) dolazi = true;
        else if(m1 == m2) {
            if(d1 < d2) dolazi = true;
            else if(d1 == d2) {
                if(s1 < s2) dolazi = true;
                else if(s1 == s2) {
                    if(mi1 < mi2) dolazi = true;
                }
            }
        }
    }
    
    return dolazi;
}

void Pregled::Ispisi() const {
    cout << setw(29) << setfill(' ') << left << DajImePacijenta() << " ";
    datum.Ispisi();
    cout << " ";
    vrijeme.Ispisi();
    cout << endl;
    
}

class Pregledi {
    vector<shared_ptr<Pregled>> svi_pregledi;
public:
    explicit Pregledi();
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(shared_ptr<Pregled> pregled);
    int DajBrojPregleda() const { return svi_pregledi.size(); }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi() {
    svi_pregledi.resize(0);
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
    svi_pregledi.resize(spisak_pregleda.size());
    
    auto it = spisak_pregleda.begin();
    for(int i = 0; i < spisak_pregleda.size(); i++) {
        svi_pregledi[i] = make_shared<Pregled>(*it);
        it++;
    }
}

Pregledi::Pregledi(const Pregledi &pregledi) : svi_pregledi(pregledi.svi_pregledi.size()) {
    for(int i = 0; i < svi_pregledi.size(); i++) svi_pregledi[i] = make_shared<Pregled>(*pregledi.svi_pregledi[i]);
}

Pregledi::Pregledi(Pregledi &&pregledi) : svi_pregledi(move(pregledi.svi_pregledi)) {}

Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
    if(&pregledi != this) {
        svi_pregledi.resize(pregledi.svi_pregledi.size());
        for(int i = 0; i < pregledi.svi_pregledi.size(); i++) {
            svi_pregledi[i] = make_shared<Pregled>(*pregledi.svi_pregledi[i]);
        }
    }
    
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    if(&pregledi != this) {
        svi_pregledi = move(pregledi.svi_pregledi);
    }
    
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    
    shared_ptr<Pregled> pregled(make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
    svi_pregledi.push_back(pregled);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    shared_ptr<Pregled> pregled(make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
    svi_pregledi.push_back(pregled);
}

void Pregledi::RegistrirajPregled(shared_ptr<Pregled> pregled) {
    svi_pregledi.push_back(pregled);
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    int brojac = count_if(svi_pregledi.begin(), svi_pregledi.end(), [&](shared_ptr<Pregled> p) { return (get<0>(p->DajDatumPregleda().Ocitaj()) == get<0>(datum.Ocitaj()) &&
        get<1>(p->DajDatumPregleda().Ocitaj()) == get<1>(datum.Ocitaj()) && get<2>(p->DajDatumPregleda().Ocitaj()) == get<2>(datum.Ocitaj()));  });
        
    return brojac;
}

Pregled &Pregledi::DajNajranijiPregled() {
    if(svi_pregledi.size() == 0)
        throw domain_error("Nema registriranih pregleda");
        
    auto naj = min_element(svi_pregledi.begin(), svi_pregledi.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2) 
    { 
        bool dolazi = false;
        int d1, d2, m1, m2, g1, g2, s1, s2, mi1, mi2;
    
        tuple<int, int, int> dp1 = p1->DajDatumPregleda().Ocitaj();
        d1 = get<0>(dp1);
        m1 = get<1>(dp1);
        g1 = get<2>(dp1);
    
        pair<int, int> vp1 = p1->DajVrijemePregleda().Ocitaj();
        s1 = vp1.first;
        mi1 = vp1.second;
    
        tuple<int, int, int> dp2 = p2->DajDatumPregleda().Ocitaj();
        d2 = get<0>(dp2);
        m2 = get<1>(dp2);
        g2 = get<2>(dp2);
    
        pair<int, int> vp2 = p2->DajVrijemePregleda().Ocitaj();
        s2 = vp2.first;
        mi2 = vp2.second;
    
        if(g1 < g2) dolazi = true;
        else if(g1 == g2) {
            if(m1 < m2) dolazi = true;
            else if(m1 == m2) {
                if(d1 < d2) dolazi = true;
                else if(d1 == d2) {
                    if(s1 < s2) dolazi = true;
                    else if(s1 == s2) {
                        if(mi1 < mi2) dolazi = true;
                    }
                }
            }
        }
    
    return dolazi; });
    
    return **naj;
}

Pregled Pregledi::DajNajranijiPregled() const {
    if(svi_pregledi.size() == 0)
        throw domain_error("Nema registriranih pregleda");
        
    auto naj = min_element(svi_pregledi.begin(), svi_pregledi.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2) 
    { 
        bool dolazi = false;
        int d1, d2, m1, m2, g1, g2, s1, s2, mi1, mi2;
    
        tuple<int, int, int> dp1 = p1->DajDatumPregleda().Ocitaj();
        d1 = get<0>(dp1);
        m1 = get<1>(dp1);
        g1 = get<2>(dp1);
    
        pair<int, int> vp1 = p1->DajVrijemePregleda().Ocitaj();
        s1 = vp1.first;
        mi1 = vp1.second;
    
        tuple<int, int, int> dp2 = p2->DajDatumPregleda().Ocitaj();
        d2 = get<0>(dp2);
        m2 = get<1>(dp2);
        g2 = get<2>(dp2);
    
        pair<int, int> vp2 = p2->DajVrijemePregleda().Ocitaj();
        s2 = vp2.first;
        mi2 = vp2.second;
    
        if(g1 < g2) dolazi = true;
        else if(g1 == g2) {
            if(m1 < m2) dolazi = true;
            else if(m1 == m2) {
                if(d1 < d2) dolazi = true;
                else if(d1 == d2) {
                    if(s1 < s2) dolazi = true;
                    else if(s1 == s2) {
                        if(mi1 < mi2) dolazi = true;
                    }
                }
            }
        }
    
    return dolazi; });
    
    return **naj;
}

void Pregledi::IsprazniKolekciju() {
    svi_pregledi.resize(0);
}

void Pregledi::ObrisiNajranijiPregled() {
    if(svi_pregledi.size() == 0)
        throw range_error("Prazna kolekcija");
        
    Pregled izbaci = DajNajranijiPregled();
    
    for(int i = 0; i < svi_pregledi.size(); i++) 
    {
        if(get<0>(svi_pregledi[i]->DajDatumPregleda().Ocitaj()) == get<0>(izbaci.DajDatumPregleda().Ocitaj()) &&
            get<1>(svi_pregledi[i]->DajDatumPregleda().Ocitaj()) == get<1>(izbaci.DajDatumPregleda().Ocitaj()) &&
            get<2>(svi_pregledi[i]->DajDatumPregleda().Ocitaj()) == get<2>(izbaci.DajDatumPregleda().Ocitaj()) &&
            svi_pregledi[i]->DajVrijemePregleda().Ocitaj().first == izbaci.DajVrijemePregleda().Ocitaj().first &&
            svi_pregledi[i]->DajVrijemePregleda().Ocitaj().second == izbaci.DajVrijemePregleda().Ocitaj().second) 
            {
                svi_pregledi.erase(svi_pregledi.begin() + i);
            }
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for(int i = 0; i < svi_pregledi.size(); i++) {
        string ime = svi_pregledi[i]->DajImePacijenta();
        if(ime_pacijenta == ime) {
            svi_pregledi.erase(svi_pregledi.begin() + i);
            i--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    vector<shared_ptr<Pregled>> temp = svi_pregledi;
    sort(temp.begin(), temp.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2) 
    { bool dolazi = false;
        int d1, d2, m1, m2, g1, g2, s1, s2, mi1, mi2;
        
        
    
        //tuple<int, int, int> dp1 = p1->DajDatumPregleda().Ocitaj();
        d1 = get<0>(p1->DajDatumPregleda().Ocitaj());
        m1 = get<1>(p1->DajDatumPregleda().Ocitaj());
        g1 = get<2>(p1->DajDatumPregleda().Ocitaj());
    
        //pair<int, int> vp1 = p1->DajVrijemePregleda().Ocitaj();
        s1 = p1->DajVrijemePregleda().Ocitaj().first;
        mi1 = p1->DajVrijemePregleda().Ocitaj().second;
    
        //tuple<int, int, int> dp2 = p2->DajDatumPregleda().Ocitaj();
        d2 = get<0>(p2->DajDatumPregleda().Ocitaj());
        m2 = get<1>(p2->DajDatumPregleda().Ocitaj());
        g2 = get<2>(p2->DajDatumPregleda().Ocitaj());
    
        //pair<int, int> vp2 = p2->DajVrijemePregleda().Ocitaj();
        s2 = p2->DajVrijemePregleda().Ocitaj().first;
        mi2 = p2->DajVrijemePregleda().Ocitaj().second;
    
        if(g1 < g2) dolazi = true;
        else if(g1 == g2) {
            if(m1 < m2) dolazi = true;
            else if(m1 == m2) {
                if(d1 < d2) dolazi = true;
                else if(d1 == d2) {
                    if(s1 < s2) dolazi = true;
                    else if(s1 == s2) {
                        if(mi1 < mi2) dolazi = true;
                    }
                }
            }
        }
    
    return dolazi; });
    
    for(int i = 0; i < temp.size(); i++) {
        if(get<0>(temp[i]->DajDatumPregleda().Ocitaj()) == get<0>(datum.Ocitaj()) &&
            get<1>(temp[i]->DajDatumPregleda().Ocitaj()) == get<1>(datum.Ocitaj()) &&
            get<2>(temp[i]->DajDatumPregleda().Ocitaj()) == get<2>(datum.Ocitaj())) {
                temp[i]->Ispisi();
            }
    }
}

void Pregledi::IspisiSvePreglede() const {
    vector<shared_ptr<Pregled>> temp = svi_pregledi;
    sort(temp.begin(), temp.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2) 
    { 
        bool dolazi = false;
        int d1, d2, m1, m2, g1, g2, s1, s2, mi1, mi2;
        
        
    
        //tuple<int, int, int> dp1 = p1->DajDatumPregleda().Ocitaj();
        d1 = get<0>(p1->DajDatumPregleda().Ocitaj());
        m1 = get<1>(p1->DajDatumPregleda().Ocitaj());
        g1 = get<2>(p1->DajDatumPregleda().Ocitaj());
    
        //pair<int, int> vp1 = p1->DajVrijemePregleda().Ocitaj();
        s1 = p1->DajVrijemePregleda().Ocitaj().first;
        mi1 = p1->DajVrijemePregleda().Ocitaj().second;
    
        //tuple<int, int, int> dp2 = p2->DajDatumPregleda().Ocitaj();
        d2 = get<0>(p2->DajDatumPregleda().Ocitaj());
        m2 = get<1>(p2->DajDatumPregleda().Ocitaj());
        g2 = get<2>(p2->DajDatumPregleda().Ocitaj());
    
        //pair<int, int> vp2 = p2->DajVrijemePregleda().Ocitaj();
        s2 = p2->DajVrijemePregleda().Ocitaj().first;
        mi2 = p2->DajVrijemePregleda().Ocitaj().second;
    
        if(g1 < g2) dolazi = true;
        else if(g1 == g2) {
            if(m1 < m2) dolazi = true;
            else if(m1 == m2) {
                if(d1 < d2) dolazi = true;
                else if(d1 == d2) {
                    if(s1 < s2) dolazi = true;
                    else if(s1 == s2) {
                        if(mi1 < mi2) dolazi = true;
                    }
                }
            }
        }
    
    return dolazi; });
    
    for(int i = 0; i < temp.size(); i++) {
        temp[i]->Ispisi();
    }
}

int main ()
{
    Pregledi pregledi;
    for(;;)
    {
        string ime;
        int dan, mjesec, godina, sati, minute;
        cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        cin >> ime;
        if(ime == "kraj") break;
        cout << "Unesite dan mjesec i godinu pregleda: ";
        cin >> dan >> mjesec >> godina;
        cout << "Unesite sate i minute pregleda: ";
        cin >> sati >> minute;
        try {
            pregledi.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);   
        } catch(domain_error e) {
            cout << e.what();
        }
    }
    cout << "Trenutno su registrovani sljedeci pregledi" << endl;
    pregledi.IspisiSvePreglede();
    int izbor;
    for(;;) {
        string ime;
        int dan, mjesec, godina, sati, minute;
        cout << "Odaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
        cin >> izbor;
        if(izbor == 1) {
            cout << "Unesite dan mjesec i godinu :"; 
            cin >> dan >> mjesec >> godina;
            Datum d(dan, mjesec, godina);
            cout << " Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: " << pregledi.DajBrojPregledaNaDatum(d) << endl;
        }
        else if(izbor == 2) {
            cout << "Najraniji pregled je:" << endl;
            pregledi.DajNajranijiPregled().Ispisi();
        }
        else if(izbor == 3) {
            int broj_pregleda = pregledi.DajBrojPregleda();
            cout << "Unesite ime pacijenta: ";
            cin >> ime;
            pregledi.ObrisiPregledePacijenta(ime);
            cout << "Uspjesno obrisano " << broj_pregleda - pregledi.DajBrojPregleda() << " pregleda" << endl;
        }
        else if(izbor == 4) {
            pregledi.ObrisiNajranijiPregled();
            cout << "Najraniji pregled uspjesno obrisan" << endl;
        }
        else if(izbor == 5) {
            cout << "Unesite dan mjesec i godinu : ";
            cin >> dan >> mjesec >> godina;
            Datum d(dan, mjesec, godina);
            cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:" << endl;
            pregledi.IspisiPregledeNaDatum(d);
        }
        else if(izbor == 6) {
            pregledi.IspisiSvePreglede();
        }
        else if(izbor == 7) {
            break;
        }
    }
    
	return 0;
}
