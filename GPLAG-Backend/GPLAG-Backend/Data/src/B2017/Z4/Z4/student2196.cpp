/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <utility>
#include <tuple>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>


//Sve klase u programu

class Datum
{
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina) {
        this->Postavi(dan,mjesec,godina);
    }
    void Postavi(int dan, int mjesec, int godina) {
        int broj_dana[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(godina<0) throw std::domain_error("Neispravan datum");
        else if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
        if(mjesec>12 || mjesec<1 || dan>broj_dana[mjesec-1] || dan<1) throw std::domain_error("Neispravan datum");
        Datum::dan=dan;
        Datum::mjesec=mjesec;
        Datum::godina=godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan, mjesec, godina);
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme
{
    int sati, minute;
public:
    Vrijeme(int sati, int minute) {
        this->Postavi(sati, minute);
    }
    void Postavi(int sati, int minute) {
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati=sati;
        Vrijeme::minute=minute;
    }
    std::pair<int, int> Ocitaj () const {
        return std::make_pair(sati,minute);
    }
    void Ispisi() const {
        if(sati<10) std::cout << '0';
        std::cout << sati << ":";
        if(minute<10) std::cout <<'0';
        std::cout << minute;
    }
};

class Pregled
{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) :
        datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {
        Pregled::ime_pacijenta = ime_pacijenta;
    }
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) :
        datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda),  vrijeme_pregleda(sati_pregleda, minute_pregleda) {
        Pregled::ime_pacijenta = ime_pacijenta;
    }
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        Pregled::ime_pacijenta = ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        datum_pregleda = novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        vrijeme_pregleda = novo_vrijeme;
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const {
        return ime_pacijenta;
    }
    Datum DajDatumPregleda() const {
        return datum_pregleda;
    }
    Vrijeme DajVrijemePregleda() const {
        return vrijeme_pregleda;
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {
        std::cout << std::left << std::setw(30) << ime_pacijenta;
        datum_pregleda.Ispisi();
        std::cout << " ";
        vrijeme_pregleda.Ispisi();
        std::cout << std::endl;
    }
};

class Pregledi
{
    std::vector<std::shared_ptr<Pregled>> svi_pregledi;
public:
    explicit Pregledi() : svi_pregledi() {
    }
    Pregledi (std::initializer_list<Pregled> spisak_pregleda) : svi_pregledi(spisak_pregleda.size()) {
        auto it(spisak_pregleda.begin());
        for(int i(0); i<int(spisak_pregleda.size()); i++) svi_pregledi.at(i)=std::make_shared<Pregled>(*it++);
    }
    Pregledi(const Pregledi &pregledi) : svi_pregledi(pregledi.svi_pregledi.size()) {
        for(int i(0); i<int(pregledi.svi_pregledi.size()); i++) svi_pregledi.at(i)=std::make_shared<Pregled>(*pregledi.svi_pregledi.at(i));
    }
    Pregledi(Pregledi &&pregledi) : svi_pregledi(pregledi.svi_pregledi.size()) {
        std::swap(svi_pregledi, pregledi.svi_pregledi);
        pregledi.svi_pregledi.resize(0);
    }
    Pregledi &operator =(const Pregledi &pregledi) {
        if(&pregledi==this) return *this;
        if(svi_pregledi.size()<pregledi.svi_pregledi.size())
            for(int i(svi_pregledi.size()); i<int(pregledi.svi_pregledi.size()); i++)
                svi_pregledi.push_back(std::make_shared<Pregled>(*pregledi.svi_pregledi.at(i)));
        svi_pregledi.resize(pregledi.svi_pregledi.size());
        for(int i(0); i<int(pregledi.svi_pregledi.size()); i++) *svi_pregledi.at(i)=*pregledi.svi_pregledi.at(i);
        return *this;
    }
    Pregledi &operator =(Pregledi &&pregledi) {
        std::swap(svi_pregledi, pregledi.svi_pregledi);
        pregledi.svi_pregledi.resize(0);
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        svi_pregledi.push_back(std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
        svi_pregledi.push_back(std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
    }
    void RegistrirajPregled(Pregled *pregled){
        svi_pregledi.push_back(std::make_shared<Pregled>(*pregled));
    }
    int DajBrojPregleda() const {
        return svi_pregledi.size();
    }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;

};

void Pregled::PomjeriDanUnaprijed()
{
    int dan, mjesec, godina;
    std::tie(dan, mjesec, godina) = DajDatumPregleda().Ocitaj();
    int broj_dana[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    dan++;
    if(dan>broj_dana[mjesec-1]) {
        dan=1;
        mjesec++;
        if(mjesec>12) {
            mjesec=1;
            godina++;
        }
    }
    PromijeniDatum(Datum(dan,mjesec, godina));
}

void Pregled::PomjeriDanUnazad()
{
    int dan, mjesec, godina;
    std::tie(dan, mjesec, godina) = DajDatumPregleda().Ocitaj();

    int broj_dana[12]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana[1]++;
    dan--;
    if(dan<1) {
        mjesec--;
        if(mjesec<1) {
            mjesec=12;
            godina--;
        }
        dan=broj_dana[mjesec-1];
    }
    PromijeniDatum(Datum(dan,mjesec,godina));

}


bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    int dan1,dan2,mjesec1,mjesec2,godina1, godina2;
    std::tie(dan1,mjesec1,godina1) = p1.DajDatumPregleda().Ocitaj();
    std::tie(dan2,mjesec2,godina2) = p2.DajDatumPregleda().Ocitaj();
    std::pair<int,int> vrijeme1(p1.DajVrijemePregleda().Ocitaj()), vrijeme2(p2.DajVrijemePregleda().Ocitaj());
    if(godina1<godina2 || (godina1==godina2 && (mjesec1<mjesec2 || (mjesec1==mjesec2 && (dan1<dan2 ||
                           (dan1==dan2 && (vrijeme1.first<vrijeme2.first || (vrijeme1.first==vrijeme2.first && vrijeme1.second<vrijeme2.second))))))))
        return true;

    return false;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    if(svi_pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    int dan1, mjesec1, godina1;
    std::tie(dan1,mjesec1,godina1) = datum.Ocitaj();
    int broj_pregleda(std::count_if(svi_pregledi.begin(), svi_pregledi.end(), [dan1, mjesec1, godina1](std::shared_ptr<Pregled> p1) {
        int dan2, mjesec2, godina2;
        std::tie(dan2,mjesec2,godina2) = p1->DajDatumPregleda().Ocitaj();
        if(dan1==dan2 && mjesec1==mjesec2 && godina1==godina2) return true;
        return false;
    }));
    return broj_pregleda;
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(svi_pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(svi_pregledi.begin(), svi_pregledi.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
    });
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if(svi_pregledi.size()==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(svi_pregledi.begin(), svi_pregledi.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
    });
}

void Pregledi::IsprazniKolekciju()
{
    if(svi_pregledi.size()==0) throw std::range_error("Prazna kolekcija");
    for(int i(0); i<int(svi_pregledi.size()); i++) svi_pregledi.at(i)=nullptr;
}


void Pregledi::ObrisiNajranijiPregled()
{
    if(svi_pregledi.size()==0) throw std::range_error("Prazna kolekcija");
    const Pregled pregled(DajNajranijiPregled());
    for(int i(0); i<int(svi_pregledi.size()); i++) {
        std::pair<int, int> vrijme1(svi_pregledi.at(i)->DajVrijemePregleda().Ocitaj()), vrijeme2(pregled.DajVrijemePregleda().Ocitaj());
        std::tuple <int, int, int> datum1(svi_pregledi.at(i)->DajDatumPregleda().Ocitaj()), datum2(pregled.DajDatumPregleda().Ocitaj());
        if(svi_pregledi.at(i)->DajImePacijenta()==pregled.DajImePacijenta() && vrijme1==vrijeme2 && datum1==datum2) {
            svi_pregledi.erase(svi_pregledi.begin()+i);
            break;
        }
    }

}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    if(svi_pregledi.size()==0) throw std::range_error("Prazna kolekcija");
    for(int i(0); i<int(svi_pregledi.size()); i++) {
        if(svi_pregledi.at(i)->DajImePacijenta()==ime_pacijenta) {
            svi_pregledi.erase(svi_pregledi.begin()+i);
            i--;
        }
    }
}


void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    Pregledi pregledi(*this);
    std::sort(pregledi.svi_pregledi.begin(), pregledi.svi_pregledi.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
    });
    for(int i(0); i<int(svi_pregledi.size()); i++)
        if(datum.Ocitaj()==pregledi.svi_pregledi.at(i)->DajDatumPregleda().Ocitaj()) pregledi.svi_pregledi.at(i)->Ispisi();
}

void Pregledi::IspisiSvePreglede() const{
    Pregledi pregledi(*this);
    std::sort(pregledi.svi_pregledi.begin(), pregledi.svi_pregledi.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
    });
    for(int i(0); i<int(svi_pregledi.size()); i++) pregledi.svi_pregledi.at(i)->Ispisi();
}


int main ()
{
     Pregledi pregledi;
     for(;;){
         std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
         std::string ime_pacijenta;
         std::getline(std::cin, ime_pacijenta);
         if(ime_pacijenta=="kraj") break;
         try{
             int dan, mjesec, godina;
             std::cout << "Unesite dan mjesec i godinu pregleda: ";
             std::cin >> dan >> mjesec >> godina;
             int sati, minute;
             std::cout << "Unesite sate i minute pregleda: ";
             std::cin >> sati >> minute;
             pregledi.RegistrirajPregled(ime_pacijenta, dan, mjesec, godina, sati, minute);
         }
         catch(std::range_error e){
             std::cout << e.what() << std::endl;
         }
         catch(std::domain_error e){
             std::cout << e.what() << std::endl;
         }
         std::cin.ignore(10000, '\n');
     }
     std::cout << "Trenutno su registrovani sljedeci pregledi\n";
     pregledi.IspisiSvePreglede();
     for(;;){
         int opcija;
         std::cout << "\nOdaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n" <<
             "4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
         std::cin >> opcija;
         if(opcija==1){
             std::cout << "Unesite dan mjesec i godinu : ";
             int dan, mjesec, godina;
             std::cin >> dan >> mjesec >> godina;
             try{
                 std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: "
                     << pregledi.DajBrojPregledaNaDatum(Datum(dan,mjesec,godina)) << std::endl;
             }
             catch(std::domain_error e){
                 std::cout << e.what() << std::endl;
             }
         }
         else if(opcija==2){
             std::cout << "Najraniji pregled je:" << std::endl;
             try{
                 pregledi.DajNajranijiPregled().Ispisi();
             }
             catch(std::domain_error e){
                 std::cout << e.what() << std::endl;
             }
         }
         else if(opcija==3){
             std::cout << "Unesite ime pacijenta: ";
             std::cin.ignore(10000,'\n');
             std::string ime_pacijenta;
             std::getline(std::cin, ime_pacijenta);
             try{
                 int broj_pregleda_prije(pregledi.DajBrojPregleda());
                 pregledi.ObrisiPregledePacijenta(ime_pacijenta);
                 int broj_pregleda_poslije(pregledi.DajBrojPregleda());
                 std::cout << "Uspjesno obrisano " << broj_pregleda_prije-broj_pregleda_poslije << " pregleda\n";
             }
             catch(std::range_error e){
                 std::cout << e.what() << std::endl;
             }
         }
         else if(opcija==4){
             try{
                 pregledi.ObrisiNajranijiPregled();
                 std::cout << "Najraniji pregled uspjesno obrisan\n";
             }
             catch(std::range_error e){
                 std::cout << e.what() << std::endl;
             }
         }
         else if(opcija==5){
             std::cout << "Unesite dan mjesec i godinu : ";
             int dan, mjesec, godina;
             std::cin >> dan >> mjesec >> godina;
             try{
                 std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:\n";
                 pregledi.IspisiPregledeNaDatum(Datum(dan,mjesec,godina));
             }
             catch(std::domain_error e){
                 std::cout << e.what() << std::endl;
             }
         }
         else if(opcija==6) pregledi.IspisiSvePreglede();
         else if(opcija==7) break;
     }
    return 0;
}
