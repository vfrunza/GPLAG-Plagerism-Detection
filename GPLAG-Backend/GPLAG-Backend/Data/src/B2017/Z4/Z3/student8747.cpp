/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>

class Datum{
    friend class Pregled;
    friend class Pregledi;
    int dan, mjesec, godina;
public:
    explicit Datum(){}
    Datum(int dan, int mjesec, int godina){
        int broj_dana[]{31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
        if((godina % 4 == 0 && godina % 100 != 0) || godina %400 == 0) broj_dana[1]++;
        if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum!");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    void Postavi(int dan, int mjesec, int godina){
        int broj_dana[]{31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
        if((godina % 4 == 0 && godina % 100 != 0) || godina %400 == 0) broj_dana[1]++;
        if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1]) throw std::domain_error("Neispravan datum!");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    std::tuple<int, int, int> Ocitaj() const{
        return std::make_tuple(dan, mjesec, godina);
    }
    void Ispisi() const{
        std::cout << dan << "/" << mjesec << "/" << godina; //<< std::endl;
    }

};

class Vrijeme{
    friend class Pregled;
    friend class Pregledi;
    int sati, minute;
public:
    explicit Vrijeme(){}
    Vrijeme(int sati, int minute){
        if(sati<0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati; Vrijeme::minute = minute;
    }
    void Postavi(int sati, int minute){
        if(sati<0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati; Vrijeme::minute = minute;
    }
    std::pair<int, int> Ocitaj() const{
        return std::make_pair(sati, minute);
    }
    void Ispisi() const{
        std::cout << std::setw(2) << std::setfill('0') << sati << ":" << std::setw(2) << std::setfill('0') << minute;
    }
};

class Pregled{
    //friend class Vrijeme;
    //friend class Datum;
    friend class Pregledi;
    std::string ime_pacijenta;
    Datum datum;
    Vrijeme vrijeme;
public:
    explicit Pregled(){}
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        Pregled::ime_pacijenta = ime_pacijenta; Pregled::datum = datum_pregleda; Pregled::vrijeme = vrijeme_pregleda;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime_pacijenta(ime_pacijenta){
        datum.Postavi(dan_pregleda, mjesec_pregleda, godina_pregleda);
        vrijeme.Postavi(sati_pregleda, minute_pregleda);
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta);
    void PromijeniDatum(const Datum &novi_datum);
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda() const;
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta){
    Pregled::ime_pacijenta = ime_pacijenta;
}

void Pregled::PromijeniDatum(const Datum &novi_datum){
    Pregled::datum = novi_datum;
}

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme){
    Pregled::vrijeme = novo_vrijeme;
}

void Pregled::PomjeriDanUnaprijed(){
    int broj_dana[]{31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
    if(datum.godina % 4 == 0 && datum.godina % 100 != 0 || datum.godina %400 == 0) broj_dana[1]++;
    datum.dan++;
    if(datum.dan > broj_dana[datum.mjesec - 1]){
        if(datum.mjesec - 1 == 11){
            datum.mjesec = 1; datum.godina++; datum.dan = 1; 
        }
        else{
            datum.dan = 1;
            datum.mjesec++;
        }
    }
}

void Pregled::PomjeriDanUnazad(){
    int broj_dana[]{31, 28, 31, 30, 31, 31, 30, 31, 30, 31, 30, 31};
    if(datum.godina % 4 == 0 && datum.godina % 100 != 0 || datum.godina %400 == 0) broj_dana[1]++;
    datum.dan--;
    if(datum.dan == 0){
        if(datum.mjesec - 1 == 0){
            datum.mjesec = 12; datum.godina--; datum.dan = broj_dana[datum.mjesec - 1]; 
        }
        else{
            datum.mjesec--;
            datum.dan = broj_dana[datum.mjesec - 1];
        }
    }
}

std::string Pregled::DajImePacijenta() const{
    return ime_pacijenta;
}

Datum Pregled::DajDatumPregleda() const{
    return datum;
}

Vrijeme Pregled::DajVrijemePregleda() const{
    return vrijeme;
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    return (p1.datum.dan < p2.datum.dan && p1.datum.mjesec < p2.datum.mjesec && p1.datum.godina < p2.datum.godina);
}

void Pregled::Ispisi() const{
    std::cout << std::left << std::setw(30) << ime_pacijenta << " "; datum.Ispisi(); std::cout << " "; vrijeme.Ispisi(); std::cout << std::endl;
}

class Pregledi{
    friend class Pregled;
    Pregled **elementi;
    int broj_pregleda;
public:
    explicit Pregledi(int max_broj_pregleda) : broj_pregleda(max_broj_pregleda), elementi(new Pregled*[max_broj_pregleda]{}){
        try{
            for(int i = 0; i < broj_pregleda; i++) elementi[i] = new Pregled;
        }
        catch(...){ throw; }
    }
    Pregledi(std::initializer_list<Pregled> spisak_pregleda) : broj_pregleda(spisak_pregleda.size()), elementi(new Pregled*[broj_pregleda]{}){
        try{
            for(int i = 0; i < spisak_pregleda.size(); i++) elementi[i] = new Pregled;
        }
        catch(...){ throw; }
        std::copy(spisak_pregleda.begin(), spisak_pregleda.end(), *elementi);
    }
    ~Pregledi(){
        for(int i = 0; i < broj_pregleda; i++) delete elementi[i];
        delete[] elementi;
    }
    Pregledi(const Pregledi &pregledi) : broj_pregleda(pregledi.broj_pregleda), elementi(new Pregled*[broj_pregleda]{}){
        try{
            for(int i = 0; i < broj_pregleda; i++) elementi[i] = new Pregled;
        }
        catch(...){ throw; }
        std::copy(pregledi.elementi, pregledi.elementi + pregledi.broj_pregleda, elementi);
    }
    Pregledi(Pregledi &&pregledi) : broj_pregleda(pregledi.broj_pregleda), elementi(pregledi.elementi){
        for(int i = 0; i < broj_pregleda; i++) pregledi.elementi[i] = nullptr;
    }
    Pregledi &operator = (const Pregledi &pregledi){
        if(&pregledi != this){
            delete[] elementi;
            broj_pregleda = pregledi.broj_pregleda; elementi = new Pregled*[broj_pregleda]{};
            std::copy(pregledi.elementi, pregledi.elementi + pregledi.broj_pregleda, elementi );
        }
        return *this;
    }
    Pregledi &operator = (Pregledi &&pregledi){
        if(&pregledi != this){
            delete[] elementi; elementi = pregledi.elementi;
            broj_pregleda = pregledi.broj_pregleda; pregledi.elementi = nullptr;
        }
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    (*elementi)->ime_pacijenta = ime_pacijenta; (*elementi)->datum = datum_pregleda; (*elementi)->vrijeme = vrijeme_pregleda;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
    (*elementi)->ime_pacijenta = ime_pacijenta; (*elementi)->datum.Postavi(dan_pregleda, mjesec_pregleda, godina_pregleda); (*elementi)->vrijeme.Postavi(sati_pregleda, minute_pregleda);
}

void Pregledi::RegistrirajPregled(Pregled *pregled){
    *(Pregledi::elementi) = pregled;
}

int Pregledi::DajBrojPregleda() const{
    return broj_pregleda;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    int i = 0;
    i = std::count_if(elementi[0],elementi[broj_pregleda],
    [&](const Pregled &novo){
        return (novo.datum.dan == datum.dan && novo.datum.mjesec == datum.mjesec && novo.datum.godina == datum.godina);
    });
    return i;
}

Pregled &Pregledi::DajNajranijiPregled(){
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return (*std::min_element(elementi[0], elementi[broj_pregleda],
        [](const Pregled &prvi, const Pregled &drugi){
            return (prvi.datum.dan < drugi.datum.dan &&prvi.datum.mjesec < drugi.datum.mjesec &&prvi.datum.godina < drugi.datum.godina && prvi.vrijeme.sati < drugi.vrijeme.sati && prvi.vrijeme.minute < drugi.vrijeme.minute);
        }));
}
Pregled Pregledi::DajNajranijiPregled() const{
    if(broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return (*std::min_element(elementi[0], elementi[broj_pregleda],
        [](const Pregled &prvi, const Pregled &drugi){
            return (prvi.datum.dan < drugi.datum.dan &&prvi.datum.mjesec < drugi.datum.mjesec &&prvi.datum.godina < drugi.datum.godina && prvi.vrijeme.sati < drugi.vrijeme.sati && prvi.vrijeme.minute < drugi.vrijeme.minute);
        }));
}
void Pregledi::IsprazniKolekciju(){
    for(int i = 0; i < broj_pregleda; i++){
        delete elementi[i];
    }
    delete[] elementi;
}
void Pregledi::ObrisiNajranijiPregled(){
    for(int i = broj_pregleda-1; i >= 0; i--){
        if(elementi[i] != nullptr){
            delete elementi[i];
            break;
        }
    }
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    for(int i = 0; i < broj_pregleda; i++){
        if((*elementi[i]).ime_pacijenta == ime_pacijenta && (elementi[i])!=nullptr) delete elementi[i];
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    std::sort(elementi[0], elementi[broj_pregleda],
        [](const Pregled &prvi, const Pregled &drugi){
            int prva(0),druga(0);
            if(prvi.datum.dan<drugi.datum.dan) prva++;
            else if(prvi.datum.dan>drugi.datum.dan) druga++;
            if(prvi.datum.mjesec<drugi.datum.mjesec) prva++;
            else if(prvi.datum.mjesec>drugi.datum.mjesec) druga++;
            if(prvi.datum.godina<drugi.datum.godina) prva++;
            else if(prvi.datum.godina>drugi.datum.godina) druga++;
            if(prvi.vrijeme.minute<drugi.vrijeme.minute) prva++;
            else if(prvi.vrijeme.minute>drugi.vrijeme.minute) druga++;
            if(prvi.vrijeme.sati<drugi.vrijeme.sati) prva++;
            else if(prvi.vrijeme.sati>drugi.vrijeme.sati) druga++;
            return prva>druga;
        });
    for(int i = 0; i < broj_pregleda; i++){
        if((*elementi[i]).datum.dan == datum.dan && (*elementi[i]).datum.mjesec == datum.mjesec && (*elementi[i]).datum.godina == datum.godina) (*elementi[i]).Ispisi();
    }
}
void Pregledi::IspisiSvePreglede() const{
    std::sort(elementi[0], elementi[broj_pregleda],
        [](const Pregled &prvi, const Pregled &drugi){
            int prva(0),druga(0);
            if(prvi.datum.dan<drugi.datum.dan) prva++;
            else if(prvi.datum.dan>drugi.datum.dan) druga++;
            if(prvi.datum.mjesec<drugi.datum.mjesec) prva++;
            else if(prvi.datum.mjesec>drugi.datum.mjesec) druga++;
            if(prvi.datum.godina<drugi.datum.godina) prva++;
            else if(prvi.datum.godina>drugi.datum.godina) druga++;
            if(prvi.vrijeme.minute<drugi.vrijeme.minute) prva++;
            else if(prvi.vrijeme.minute>drugi.vrijeme.minute) druga++;
            if(prvi.vrijeme.sati<drugi.vrijeme.sati) prva++;
            else if(prvi.vrijeme.sati>drugi.vrijeme.sati) druga++;
            return prva>druga;
        });
    for(int i = 0; i < broj_pregleda; i++){
        (*elementi[i]).Ispisi();
    }
}
    
    int main ()
{
    int broj_pregleda(0), dan, mjesec, godina, broj, sati, minute; 
    std::string ime;
    std::cout << "Unesite maksimalan broj pregleda: ";
    std::cin >> broj_pregleda;
    try{
        Pregledi pregledi(broj_pregleda);
        for(int i = 0; i < broj_pregleda; i++){
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::cin >> ime;
            if(ime == "kraj") break;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            std::cin >> dan >> mjesec >> godina;
            std::cout << "Unesite sate i minute pregleda: ";
            std::cin >> sati >> minute;
            pregledi.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);
        }
        pregledi.IspisiSvePreglede();
    }
    catch(const std::exception &greska){
        std::cout << greska.what();
    }




	return 0;
}
