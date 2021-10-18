/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <utility>
#include <tuple>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>



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
    Pregled** svi_pregledi = nullptr;
    int max_broj_pregleda, treuntni_broj_pregleda;
public:
    explicit Pregledi(int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda), treuntni_broj_pregleda(0) {
        svi_pregledi = new Pregled*[max_broj_pregleda] {};
    }
    Pregledi (std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi() {
        for(int i(0); i<treuntni_broj_pregleda; i++) delete svi_pregledi[i];
        delete[] svi_pregledi;
    }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), treuntni_broj_pregleda(pregledi.treuntni_broj_pregleda) {
        std::swap(svi_pregledi, pregledi.svi_pregledi);
    }
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi) {
        max_broj_pregleda=pregledi.max_broj_pregleda;
        treuntni_broj_pregleda=pregledi.treuntni_broj_pregleda;
        std::swap(svi_pregledi, pregledi.svi_pregledi);
        return *this;
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const {
        return treuntni_broj_pregleda;
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



Pregledi::Pregledi (std::initializer_list<Pregled> spisak_pregleda) :
    max_broj_pregleda(spisak_pregleda.size()), treuntni_broj_pregleda(spisak_pregleda.size())
{
    svi_pregledi = new Pregled*[max_broj_pregleda] {};
    try {
        auto it(spisak_pregleda.begin());
        for(int i(0); i<max_broj_pregleda; i++) svi_pregledi[i]=new Pregled(*it++);
    } catch(...) {
        for(int i(0); i<max_broj_pregleda; i++) delete svi_pregledi[i];
        delete[] svi_pregledi;
        svi_pregledi=nullptr;
        throw;
    }
}

Pregledi::Pregledi(const Pregledi &pregledi) :
    max_broj_pregleda(pregledi.max_broj_pregleda), treuntni_broj_pregleda(pregledi.treuntni_broj_pregleda)
{
    svi_pregledi=new Pregled*[max_broj_pregleda] {};
    try {
        for(int i(0); i<treuntni_broj_pregleda; i++) svi_pregledi[i]=new Pregled(*(pregledi.svi_pregledi[i]));
    } catch(...) {
        for(int i(0); i<treuntni_broj_pregleda; i++) delete svi_pregledi[i];
        delete[] svi_pregledi;
        svi_pregledi=nullptr;
        throw;
    }
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi)
{
    if(&pregledi==this) return *this;
    Pregled **dodatni_prostor;
    if(max_broj_pregleda<pregledi.max_broj_pregleda) {
        dodatni_prostor = new Pregled*[pregledi.max_broj_pregleda] {};
        try {
            for(int i(0); i<pregledi.max_broj_pregleda; i++) dodatni_prostor[i]=new Pregled(*(pregledi.svi_pregledi[i]));
            for(int i(0); i<max_broj_pregleda; i++) delete svi_pregledi[i];
            delete[] svi_pregledi;
        } catch(...) {
            for(int i(0); i<max_broj_pregleda; i++) delete dodatni_prostor[i];
            delete[] dodatni_prostor;
            throw;
        }
    }
    treuntni_broj_pregleda=pregledi.treuntni_broj_pregleda;
    max_broj_pregleda=pregledi.max_broj_pregleda;
    std::copy(dodatni_prostor, dodatni_prostor+max_broj_pregleda, svi_pregledi);
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    if(treuntni_broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    svi_pregledi[treuntni_broj_pregleda]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    treuntni_broj_pregleda++;
}

void Pregledi::RegistrirajPregled(const std::string & ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    if(treuntni_broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    svi_pregledi[treuntni_broj_pregleda]=new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    treuntni_broj_pregleda++;
}

void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    if(treuntni_broj_pregleda==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    svi_pregledi[treuntni_broj_pregleda]=new Pregled(*pregled);
    treuntni_broj_pregleda++;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    if(treuntni_broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    int dan1, mjesec1, godina1;
    std::tie(dan1,mjesec1,godina1) = datum.Ocitaj();
    int broj_pregleda(std::count_if(svi_pregledi, svi_pregledi+treuntni_broj_pregleda, [dan1, mjesec1, godina1](Pregled *p1) {
        int dan2, mjesec2, godina2;
        std::tie(dan2,mjesec2,godina2) = p1->DajDatumPregleda().Ocitaj();
        if(dan1==dan2 && mjesec1==mjesec2 && godina1==godina2) return true;
        return false;
    }));
    return broj_pregleda;
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(treuntni_broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(svi_pregledi, svi_pregledi+treuntni_broj_pregleda, [](Pregled* p1, Pregled* p2) {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
    });
}


Pregled Pregledi::DajNajranijiPregled() const
{
    if(treuntni_broj_pregleda==0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(svi_pregledi, svi_pregledi+treuntni_broj_pregleda, [](Pregled* p1, Pregled* p2) {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
    });
}

void Pregledi::IsprazniKolekciju()
{
    if(treuntni_broj_pregleda==0) throw std::range_error("Prazna kolekcija");
    for(int i(0); i<treuntni_broj_pregleda; i++) {
        delete svi_pregledi[i];
        svi_pregledi[i]=nullptr;
    }
}


void Pregledi::ObrisiNajranijiPregled()
{
    if(treuntni_broj_pregleda==0) throw std::range_error("Prazna kolekcija");
   const Pregled pregled(DajNajranijiPregled());
    for(int i(0); i<treuntni_broj_pregleda; i++) {
        std::pair<int, int> vrijme1(svi_pregledi[i]->DajVrijemePregleda().Ocitaj()), vrijeme2(pregled.DajVrijemePregleda().Ocitaj());
        std::tuple <int, int, int> datum1(svi_pregledi[i]->DajDatumPregleda().Ocitaj()), datum2(pregled.DajDatumPregleda().Ocitaj());
        if(svi_pregledi[i]->DajImePacijenta()==pregled.DajImePacijenta() && vrijme1==vrijeme2 && datum1==datum2) {
            delete svi_pregledi[i];
            svi_pregledi[i]=nullptr;
            for(int j(i); j<treuntni_broj_pregleda-1; j++) {
                svi_pregledi[j]=svi_pregledi[j+1];
            }
            treuntni_broj_pregleda--;
            svi_pregledi[treuntni_broj_pregleda]=nullptr;
            break;
        }
    }

}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    if(treuntni_broj_pregleda==0) throw std::range_error("Prazna kolekcija");
    for(int i(0); i<treuntni_broj_pregleda; i++) {
        if(svi_pregledi[i]->DajImePacijenta()==ime_pacijenta) {
            delete svi_pregledi[i];
            svi_pregledi[i]=nullptr;
            for(int j(i); j<treuntni_broj_pregleda-1; j++) {
                svi_pregledi[j]=svi_pregledi[j+1];
            }
            treuntni_broj_pregleda--;
            svi_pregledi[treuntni_broj_pregleda]=nullptr;
            i--;
        }
    }
}


void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    Pregledi pregledi(*this);
    std::sort(pregledi.svi_pregledi, pregledi.svi_pregledi+treuntni_broj_pregleda, [](Pregled *p1, Pregled *p2) {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
    });
    for(int i(0); i<treuntni_broj_pregleda; i++)
        if(datum.Ocitaj()==pregledi.svi_pregledi[i]->DajDatumPregleda().Ocitaj()) pregledi.svi_pregledi[i]->Ispisi();
}

void Pregledi::IspisiSvePreglede() const{
    Pregledi pregledi(*this);
    std::sort(pregledi.svi_pregledi, pregledi.svi_pregledi+treuntni_broj_pregleda, [](Pregled *p1, Pregled *p2) {
        if(Pregled::DolaziPrije(*p1,*p2)) return true;
        return false;
    });
    for(int i(0); i<treuntni_broj_pregleda; i++)
        pregledi.svi_pregledi[i]->Ispisi();
}



int main ()
{
    int max_broj_pregleda;
    std::cout << "Unesite maksimalan broj pregleda: ";
    std::cin >> max_broj_pregleda;
    Pregledi pregledi(max_broj_pregleda);
    for(int i(0); i<max_broj_pregleda; i++){
        std::cin.ignore(10000,'\n');
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
