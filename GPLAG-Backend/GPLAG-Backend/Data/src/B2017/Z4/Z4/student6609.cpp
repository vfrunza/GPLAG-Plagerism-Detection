/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <tuple>
#include <utility>
#include <string>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>

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
    static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
   public:
    Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda){}
    Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda): ime_pacijenta(ime_pacijenta), datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda){}
    void PromijeniPacijenta (const std::string &ime_pacijenta);
    void PromijeniDatum (const Datum &novi_datum);
    void PromijeniVrijeme (const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    //static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};
/*
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
}*/

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
    std::tuple<int,int, int> dat;
    dat=datum_pregleda.Ocitaj();
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

bool DolaziPrije (const Pregled &p1, const Pregled &p2) {
    std::tuple<int, int, int> dat1 = p1.DajDatumPregleda().Ocitaj(), dat2 = p2.DajDatumPregleda().Ocitaj();
    int dan_1 = std::get<0>(dat1), mj_1 = std::get<1>(dat1), god_1 = std::get<2>(dat1);
    int dan_2 = std::get<0>(dat2), mj_2 = std::get<1>(dat2), god_2 = std::get<2>(dat2);
    std::pair<int, int> v1 = p1.DajVrijemePregleda().Ocitaj(), v2 = p2.DajVrijemePregleda().Ocitaj();
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
    std::cout << std::left << std::setw(30) << std::setfill(' ') << Pregled::ime_pacijenta;
    Pregled::datum_pregleda.Ispisi();
    std::cout << " ";
    Pregled::vrijeme_pregleda.Ispisi();
    std::cout << std::endl;
}






class Pregledi {
    std::vector<std::shared_ptr<Pregled>> termini;
   public:
    explicit Pregledi ();
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    //~Pregledi();
    Pregledi (const Pregledi &pregledi);
    Pregledi (Pregledi &&pregledi);
    Pregledi &operator = (const Pregledi &pregledi);
    Pregledi &operator = (Pregledi &&pregledi);
    void RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled (std::shared_ptr<Pregled> pregled);
    int DajBrojPregleda() const { return termini.size(); }
    int DajBrojPregledaNaDatum (const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta (const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum (const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi () { 
    termini.resize(0);
}

Pregledi::Pregledi (std::initializer_list<Pregled> spisak_pregleda) {
    for (auto it=spisak_pregleda.begin(); it!=spisak_pregleda.end(); it++) {
        std::shared_ptr<Pregled> pom = std::make_shared<Pregled> (*it);
        termini.push_back(pom);
    }
}

/*Pregledi::~Pregledi() {
    for (int i=0; i<termini.size(); i++) termini[i] = nullptr;
    termini.resize(0);
}*/

Pregledi::Pregledi (const Pregledi &pregledi) {
    for (int i=0; i<pregledi.termini.size(); i++) {
        std::shared_ptr<Pregled> pom = std::make_shared<Pregled> (*pregledi.termini[i]);
        termini.push_back(pom);
    }
}

Pregledi::Pregledi (Pregledi &&pregledi) {
    for (int i=0; i<termini.size(); i++) termini[i] = nullptr;
    termini.resize(0);
}

Pregledi &Pregledi::operator = (const Pregledi &pregledi) {
    if (&pregledi != this) {
        if (pregledi.termini.size() > termini.size()) {
            termini.resize(pregledi.termini.size());
            for (int i=0; i<termini.size(); i++) termini[i] = pregledi.termini[i];
            for (int i=0; i<termini.size(); i++) termini[i] = std::make_shared<Pregled> (*pregledi.termini[i]);
        }
        else termini.resize(pregledi.termini.size());
        for (int i=0; i<termini.size(); i++) termini[i] = pregledi.termini[i];
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    if (&pregledi == this) return *this;
    std::swap (termini, pregledi.termini);
    pregledi.termini.resize(0);
    return *this;
}

void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    try {
        termini.push_back(std::make_shared<Pregled> (ime_pacijenta, datum_pregleda, vrijeme_pregleda));
    }
    catch (...) {
        for (int i=0; i<termini.size(); i++) termini[i] = nullptr;
        termini.resize(0);
        throw;
    }
}
void Pregledi::RegistrirajPregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    try {
        termini.push_back(std::make_shared<Pregled> (ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
    }
    catch (...) {
        for (int i=0; i<termini.size(); i++) termini[i] = nullptr;
        termini.resize(0);
        throw;
    }
}
void Pregledi::RegistrirajPregled (std::shared_ptr<Pregled> pregled) {
    try {
        std::shared_ptr<Pregled> pomocni;
        pomocni=std::make_shared<Pregled>(*pregled);
        termini.push_back(pomocni);
    }
    catch (...) {
        for (int i=0; i<termini.size(); i++) termini[i] = nullptr;
        termini.resize(0);
        throw;
    }
}


int Pregledi::DajBrojPregledaNaDatum (const Datum &datum) const {
    return std::count_if (termini.begin(), termini.end(), [datum] (std::shared_ptr<Pregled> p1)->bool {
                                                            std::tuple<int, int, int> pom = datum.Ocitaj();
                                                            Datum dat(p1->DajDatumPregleda());
                                                            std::tuple<int, int, int> pom2 = dat.Ocitaj();
                                                            return (pom==pom2);
                                                        });
}

Pregled &Pregledi::DajNajranijiPregled() {
    if (termini.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element (termini.begin(), termini.end(), [] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) { return DolaziPrije(*p1, *p2); });
}

Pregled Pregledi::DajNajranijiPregled() const {
    if (termini.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element (termini.begin(), termini.end(), [] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) { return DolaziPrije(*p1, *p2); });
}

void Pregledi::IsprazniKolekciju() {
    for (int i=0; i<termini.size(); i++) termini[i] = nullptr;
    termini.resize(0);
}

void Pregledi::ObrisiNajranijiPregled() {
    if (termini.size()==0) throw std::domain_error ("Nema registriranih pregleda!");
    Pregled dajNajraniji(DajNajranijiPregled());
    Datum poredimDatum=dajNajraniji.DajDatumPregleda();
    std::tuple<int,int, int> dat=poredimDatum.Ocitaj();
    
    Vrijeme pomVrijeme=dajNajraniji.DajVrijemePregleda();
    std::pair<int, int> vrijeme1=pomVrijeme.Ocitaj();
    
    int dokleIdem(termini.size());
    for(int i=0; i<dokleIdem; i++){
        Datum saCimPoredim=termini[i]->DajDatumPregleda();
        std::tuple<int, int, int> dat2=saCimPoredim.Ocitaj();
        Vrijeme vrijemePoredim=termini[i]->DajVrijemePregleda();
        std::pair<int, int> vrijeme2=vrijemePoredim.Ocitaj();
        if(dat==dat2 && vrijeme1==vrijeme2){
            termini[i]=nullptr;
            for(int j=i; j<dokleIdem-1; j++){
                termini[j]=termini[j+1];
            }
            termini.resize(dokleIdem-1);
            break;
        }
    }
}

void Pregledi::ObrisiPregledePacijenta (const std::string &ime_pacijenta) {
    if (termini.size()==0) throw std::domain_error("Nema registriranih pregleda!");
    for(int i=0; i<termini.size(); i++){
        std::string porediti;
        porediti=termini[i]->DajImePacijenta();
        if(porediti==ime_pacijenta){
            termini[i]=nullptr;
            for(int j=i; j<termini.size()-1; j++)
                termini[j]=termini[j+1];
            //termini[broj_pregleda-1]=nullptr;
            termini.resize(termini.size()-1);
            i--;
        }
    }
    
}

void Pregledi::IspisiPregledeNaDatum (const Datum &datum) const {
    std::vector<std::shared_ptr<Pregled>> v(termini.size());
    for (int i=0; i<termini.size(); i++) v[i]=termini[i];
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {return DolaziPrije(*p1, *p2);});
    for(int i=0; i<termini.size(); i++)
        if((v[i]->DajDatumPregleda()).Ocitaj()==datum.Ocitaj()) v[i]->Ispisi();
}

void Pregledi::IspisiSvePreglede() const {
    std::vector<std::shared_ptr<Pregled>> v(termini.size());
    for (int i=0; i<termini.size(); i++) v[i] = termini[i];
    std::sort(v.begin(), v.end(), [] (std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {return DolaziPrije(*p1, *p2);});
    for (int i=0; i<termini.size(); i++) v[i]->Ispisi();
}


int main ()
{
    Pregledi pregledi;
    std::vector<Pregled> v;
    for (int i=0;; i++) {
        
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
        std::cin.ignore(10000, '\n');
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
