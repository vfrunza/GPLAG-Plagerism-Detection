/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>

class Datum {
    int dan, mjesec, godina;
   public:
    Datum (int dan, int mjesec, int godina);
    void Postavi (int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const;
};
Datum::Datum (int dan, int mjesec, int godina) {
    int broj_dana [12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error ("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}
void Datum::Postavi (int dan, int mjesec, int godina) {
    int broj_dana [12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((godina%4==0 && godina%100!=0 )|| godina%400==0) broj_dana[1]++;
    if (godina<1 || dan<1 || mjesec<1 || mjesec>12 || dan>broj_dana[mjesec-1]) throw std::domain_error ("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}
std::tuple<int, int, int> Datum::Ocitaj() const {
    std::tuple<int, int, int> dat = std::make_tuple(dan, mjesec, godina);
    return dat;
}
void Datum::Ispisi() const {
    std::cout << dan << "/" << mjesec << "/" << godina;
}



class Vrijeme {
    int sati, minute;
   public:
    Vrijeme (int sati, int minute);
    void Postavi (int sati, int minute);
    std::pair<int, int> Ocitaj() const;
    void Ispisi() const;
};
Vrijeme::Vrijeme (int sati, int minute) {
    if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error ("Neispravno vrijeme");
    Vrijeme::sati = sati;
    Vrijeme::minute = minute;
}
void Vrijeme::Postavi (int sat, int minute) {
    if (sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error ("Neispravno vrijeme");
    Vrijeme::sati = sati;
    Vrijeme::minute = minute;
}
std::pair<int, int> Vrijeme::Ocitaj() const {
    auto vr = std::make_pair(sati, minute);
    return vr;
}
void Vrijeme::Ispisi() const {
    std::cout << std::setw(2)<<std::setfill('0') <<std::right<< sati << ":"<<std::setw(2) << minute;
}




class Pregled {
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
   public:
    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta (const std::string &ime_pacijenta);
    void PromijeniDatum (const Datum &novi_datum);
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

Pregled::Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : 
  ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {
        Pregled::ime_pacijenta = ime_pacijenta;
        Pregled::datum_pregleda = datum_pregleda;
        Pregled::vrijeme_pregleda = vrijeme_pregleda;
}

Pregled::Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) :
  ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) {
        Pregled::ime_pacijenta = ime_pacijenta;
        Pregled::datum_pregleda = datum_pregleda;
        Pregled::vrijeme_pregleda = vrijeme_pregleda;
}

void Pregled::PromijeniPacijenta (const std::string &ime_pacijenta) {
    Pregled::ime_pacijenta = ime_pacijenta;
}
void Pregled::PromijeniDatum (const Datum &novi_datum) {
    Pregled::datum_pregleda = novi_datum;
}
void Pregled::PromijeniVrijeme (const Vrijeme &novo_vrijeme) {
    Pregled::vrijeme_pregleda = novo_vrijeme;
}

void Pregled::PomjeriDanUnaprijed() {
    int broj_dana [12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::tuple<int,int, int> dat=Pregled::datum_pregleda.Ocitaj();
    int dan=std::get<0>(dat), mjesec=std::get<1>(dat), godina=std::get<2>(dat);
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if (dan==broj_dana[mjesec-1]) {
        if (mjesec==12) {
            mjesec=1;
            godina++;
        }
        else mjesec++;
        dan = 1;
    }
    else dan++;
    Pregled::datum_pregleda.Postavi(dan, mjesec, godina);
}
void Pregled::PomjeriDanUnazad() {
    int broj_dana [12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    
    std::tuple<int, int, int> dat= Pregled::datum_pregleda.Ocitaj();
    int dan=std::get<0>(dat), mjesec=std::get<1>(dat), godina=std::get<2>(dat);
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    if (dan==1) {
        if (mjesec==1) {
            mjesec=12;
            godina--;
        }
        else mjesec--;
        dan = broj_dana[mjesec-1];
    }
    else dan--;
    Pregled::datum_pregleda.Postavi(dan, mjesec, godina);
}

bool Pregled::DolaziPrije (const Pregled &p1, const Pregled &p2) {
    std::tuple<int, int, int> dat1 = p1.datum_pregleda.Ocitaj(), dat2 = p2.datum_pregleda.Ocitaj();
    int dan_1 = std::get<0>(dat1), mj_1 = std::get<1>(dat1), god_1 = std::get<2>(dat1);
    int dan_2 = std::get<0>(dat2), mj_2 = std::get<1>(dat2), god_2 = std::get<2>(dat2);
    std::pair<int, int> v1 = p1.vrijeme_pregleda.Ocitaj(), v2 = p2.vrijeme_pregleda.Ocitaj();
    int h1 = v1.first, min1=v1.second, h2=v2.first, min2=v2.second;
    if (god_1 < god_2) return true;
    else if (god_1 == god_2) {
        if (mj_1 < mj_2) return true;
        else if (mj_1 == mj_2) {
            if (dan_1 < dan_2) return true;
            else if (dan_1 == dan_2) {
                if (h1 < h2) return true;
                else if (h1 == h2) {
                    if (min1 < min2) return true;
                }
            }
        }
    }
    return false;
}

void Pregled::Ispisi() const {
    std::cout << std::left << std::setw(30) <<std::setfill(' ')<< Pregled::ime_pacijenta;
    Pregled::datum_pregleda.Ispisi();
    std::cout << " ";
    Pregled::vrijeme_pregleda.Ispisi();
    std::cout << std::endl;
}





class Pregledi {
    int broj_pregleda;
    int max_broj_pregleda;
    Pregled **termini = nullptr;
   public:
    explicit Pregledi (int max_broj_pregleda);
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi();
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi);
    Pregledi &operator = (const Pregledi &pregledi);
    Pregledi &operator = (Pregledi &&pregledi);
    void RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled (Pregled *pregled);
    int DajBrojPregleda() const { return broj_pregleda; }
    int DajBrojPregledaNaDatum (const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta (const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum (const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi (int max_broj_pregleda) : broj_pregleda(0), max_broj_pregleda(max_broj_pregleda) {
    termini = new Pregled*[max_broj_pregleda];
}

Pregledi::Pregledi (std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()) {
    Pregledi::broj_pregleda = spisak_pregleda.size();
    termini = new Pregled*[max_broj_pregleda];
    int i(0);
    for (auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) {
        termini[i] = new Pregled(*it);
        i++;
    }
}

Pregledi::~Pregledi() {
    for (int i=0; i<broj_pregleda; i++) delete termini[i];
    delete[] termini;
}

Pregledi::Pregledi (const Pregledi &pregledi) : broj_pregleda(pregledi.broj_pregleda), max_broj_pregleda(pregledi.max_broj_pregleda), termini(new Pregled*[pregledi.max_broj_pregleda]{}) {
    try {
        for (int i=0; i<broj_pregleda; i++) termini[i] = new Pregled (*pregledi.termini[i]);
    }
    catch (...) {
        for (int i=0; i<broj_pregleda; i++) delete termini[i];
        delete[] termini;
        throw;
    }
}

Pregledi::Pregledi (Pregledi &&pregledi) : broj_pregleda(pregledi.broj_pregleda),max_broj_pregleda(pregledi.max_broj_pregleda), termini(pregledi.termini) {
    pregledi.termini = nullptr;
    pregledi.broj_pregleda = 0;
}

Pregledi &Pregledi::operator = (const Pregledi &pregledi) {
    if (max_broj_pregleda != pregledi.max_broj_pregleda) throw std::logic_error ("Nisu iste velicine");
    if (&pregledi != this) {
        for (int i=0; i<broj_pregleda; i++) {
            delete termini[i];
        }
        for (int i=0; i<pregledi.broj_pregleda; i++) {
            termini[i] = new Pregled (*pregledi.termini[i]);
        }
        broj_pregleda = pregledi.broj_pregleda;
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    if (&pregledi == this) return *this;
    std::swap (broj_pregleda, pregledi.broj_pregleda);
    std::swap (termini, pregledi.termini);
    return *this;
}

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if (broj_pregleda==max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
    try {
    //Pregled novi_pregled (ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    termini[broj_pregleda++] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    }
    catch (...) {
        broj_pregleda--;
        throw;
    }
}
void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    if (broj_pregleda==max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
    //Pregled novi_pregled (ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    Datum dat (dan_pregleda, mjesec_pregleda, godina_pregleda);
    Vrijeme vr (sati_pregleda, minute_pregleda);
    try {
        termini[broj_pregleda++] = new Pregled(ime_pacijenta, dat, vr);
    }
    catch (...) {
        broj_pregleda--;
        throw;
    }
}
void Pregledi::RegistrirajPregled (Pregled *pregled) {
    if (broj_pregleda==max_broj_pregleda) throw std::range_error ("Dostignut maksimalni broj pregleda");
    Datum dat (pregled->DajDatumPregleda());
    Vrijeme vr (pregled->DajVrijemePregleda());
    std::string s (pregled->DajImePacijenta());
    try {
        termini[broj_pregleda++] = new Pregled(s, dat, vr);
    }
    catch (...) {
        broj_pregleda--;
        throw;
    }
}

int Pregledi::DajBrojPregledaNaDatum (const Datum &datum) const {
    return std::count_if (termini, termini+broj_pregleda, [datum] (const Pregled *p1)->bool {
                                                            std::tuple<int, int, int> pom = datum.Ocitaj();
                                                            int dan1(std::get<0>(pom)), mjesec1(std::get<1>(pom)), godina1(std::get<2>(pom));
                                                            Datum dat(p1->DajDatumPregleda());
                                                            std::tuple<int, int, int> pom2 = dat.Ocitaj();
                                                            int dan2(std::get<0>(pom2)), mjesec2(std::get<1>(pom2)), godina2(std::get<2>(pom2));
                                                            return (dan1==dan2 && mjesec1==mjesec2 && godina1==godina2);
                                                        });
}

Pregled &Pregledi::DajNajranijiPregled() {
    if (broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element (termini, termini+broj_pregleda, [] (const Pregled *p1, const Pregled *p2) { return Pregled::DolaziPrije(*p1, *p2); });
}

Pregled Pregledi::DajNajranijiPregled() const {
    return **std::min_element (termini, termini+broj_pregleda, [] (const Pregled *p1, const Pregled *p2) { return Pregled::DolaziPrije(*p1, *p2); });
}

void Pregledi::IsprazniKolekciju() {
    for (int i=0; i<broj_pregleda; i++) {
        delete termini[i];
        termini[i]=nullptr;
    }
    broj_pregleda=0;
}

void Pregledi::ObrisiNajranijiPregled() {
    if (broj_pregleda==0) throw std::domain_error ("Nema registriranih pregleda!");
    DajNajranijiPregled() = *termini[broj_pregleda-1];
    delete termini[--broj_pregleda];
}

void Pregledi::ObrisiPregledePacijenta (const std::string &ime_pacijenta) {
    if (broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda!");
    /*for (int i=0; i<broj_pregleda; i++) {
        if (ime_pacijenta == termini[i]->DajImePacijenta()) {
            termini[i] = termini[broj_pregleda-1];
        }
        delete termini[--broj_pregleda];
    }*/
    for(int i=0; i<broj_pregleda; i++){
        std::string porediti;
        porediti=termini[i]->DajImePacijenta();
        if(porediti==ime_pacijenta){
            delete termini[i];
            termini[i]=nullptr;
            for(int j=i; j<broj_pregleda-1; j++)
                termini[j]=termini[j+1];
            termini[broj_pregleda-1]=nullptr;
            broj_pregleda--;
            i--;
        }
    }
    
}

void Pregledi::IspisiPregledeNaDatum (const Datum &datum) const {
    /*Pregledi pom = Pregledi(max_broj_pregleda);
    std::copy (termini, termini+broj_pregleda, pom.termini);
    std::sort(pom.termini, pom.termini+broj_pregleda, [] (const Pregled *p1, const Pregled *p2) {
                                                return Pregled::DolaziPrije(*p1, *p2);
                                            });
    std::tuple<int, int, int> datum_pregleda = datum.Ocitaj();
    int dan=std::get<0>(datum_pregleda), mjesec=std::get<1>(datum_pregleda), godina=std::get<2>(datum_pregleda);
    for (int i=0; i<broj_pregleda; i++) {
        Datum temp(termini[i]->DajDatumPregleda());
        std::tuple<int, int, int> dat = temp.Ocitaj();
        if (dan==std::get<0>(dat) && mjesec==std::get<1>(dat) && godina==std::get<2>(dat)) pom.termini[i]->Ispisi();
    }*/
    
    std::vector<Pregled*> v(broj_pregleda);
    for (int i=0; i<broj_pregleda; i++) v[i]=termini[i];
    std::sort(v.begin(), v.end(), [] (const Pregled *p1, const Pregled *p2) {return Pregled::DolaziPrije(*p1, *p2);});
    for(int i=0; i<broj_pregleda; i++)
        if((v[i]->DajDatumPregleda()).Ocitaj()==datum.Ocitaj()) v[i]->Ispisi();
}

void Pregledi::IspisiSvePreglede() const {
    /*Pregledi pom = Pregledi(max_broj_pregleda);
    std::copy (termini, termini+broj_pregleda, pom.termini);
    std::sort(pom.termini, pom.termini+broj_pregleda, [] (const Pregled *p1, const Pregled *p2) { return Pregled::DolaziPrije(*p1, *p2); });
    for (int i=0; i<broj_pregleda; i++) pom.termini[i]->Ispisi();*/
    std::vector<Pregled*> v(broj_pregleda);
    for (int i=0; i<broj_pregleda; i++) v[i] = termini[i];
    std::sort(v.begin(), v.end(), [] (const Pregled *p1, const Pregled *p2) {return Pregled::DolaziPrije(*p1, *p2);});
    for (int i=0; i<broj_pregleda; i++) v[i]->Ispisi();
}


int main ()
{
    std::cout << "Unesite maksimalan broj pregleda: ";
    int max_broj_pregleda;
    std::cin >> max_broj_pregleda;
    Pregledi pregledi(max_broj_pregleda);
    std::vector<Pregled> v;
    for (int i=0; i<max_broj_pregleda; i++) {
        std::cin.clear(); std::cin.ignore(10000, '\n');
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime_pacijenta;
        std::getline(std::cin, ime_pacijenta);
        if (ime_pacijenta=="kraj") break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan, mjesec, godina;
        std::cin >> dan >> mjesec >> godina;
        try {
            Datum datum_pregleda (dan, mjesec, godina);
        }
        catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            return 0;
        }
        std::cout << "Unesite sate i minute pregleda: ";
        int sati, minute;
        std::cin >> sati >> minute;
        try {
            Vrijeme vrijeme_pregleda (sati, minute);
        }
        catch (std::domain_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
            return 0;
        }
        try {
            pregledi.RegistrirajPregled(ime_pacijenta, dan, mjesec, godina, sati, minute);
        }
        catch (std::range_error izuzetak) {
            std::cout << izuzetak.what() << std::endl;
        }
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    pregledi.IspisiSvePreglede();
    int opcija, dan, mjesec, godina;
    std::string ime_pacijenta;
    for (;;) {
        std::cout << std::endl;
        std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
        std::cout << "1 - Broj pregleda na datum" << std::endl;
        std::cout << "2 - Najraniji pregled" << std::endl;
        std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
        std::cout << "4 - Obrisi najraniji pregled" << std::endl;
        std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
        std::cout << "6 - Ispisi sve preglede" << std::endl;
        std::cout << "7 - Kraj programa" << std::endl;
        std::cin >> opcija;
        if (opcija==7) return 0;
        else if (opcija==1) {
            std::cin.clear(); std::cin.ignore(10000, '\n');
            std::cout << "Unesite dan mjesec i godinu : ";
            std::cin >> dan >> mjesec >> godina;
            Datum datum_pregleda (dan, mjesec, godina);
            std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: " << pregledi.DajBrojPregledaNaDatum(datum_pregleda) << std::endl;
        }
        else if (opcija==2) {
            std::cout << "Najraniji pregled je:" << std::endl;
            Pregled najraniji = pregledi.DajNajranijiPregled();
            najraniji.Ispisi();
        }
        else if (opcija==3) {
            std::cin.clear(); std::cin.ignore(10000, '\n');
            std::cout << "Unesite ime pacijenta: ";
            std::getline(std::cin, ime_pacijenta);
            int br1 = pregledi.DajBrojPregleda();
            pregledi.ObrisiPregledePacijenta(ime_pacijenta);
            int br2 = pregledi.DajBrojPregleda();
            if (br1 != br2) std::cout << "Uspjesno obrisano " << br1-br2 << " pregleda" << std::endl;
        }
        else if (opcija==4) {
            pregledi.ObrisiNajranijiPregled();
            std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
        }
        else if (opcija==5) {
            std::cin.clear(); std::cin.ignore(10000, '\n');
            std::cout << "Unesite dan mjesec i godinu : ";
            std::cin >> dan >> mjesec >> godina;
            Datum datum_pregleda (dan, mjesec, godina);
            std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:" << std::endl;
            pregledi.IspisiPregledeNaDatum(datum_pregleda);
        }
        else if (opcija==6) {
            pregledi.IspisiSvePreglede();
        }
    }
	return 0;
}