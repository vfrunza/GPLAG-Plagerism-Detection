/B2017/2018: Zadaća 4, Zadatak 3
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <tuple>
#include <iomanip>

class Datum{
    int d, m, g;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const;
    void Ispisi() const;
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    if(dan < 1 || mjesec < 1 || godina < 1 || mjesec > 12)
        throw std::domain_error("Neispravan datum");
    
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1] = 29;
        
    if(dan > broj_dana[mjesec - 1])
        throw std::domain_error("Neispravan datum");
    
    d = dan;
    m = mjesec;
    g = godina;
}

Datum::Datum(int dan, int mjesec, int godina)
{
    Postavi(dan, mjesec, godina);
}

std::tuple<int, int, int> Datum::Ocitaj() const
{
    return std::tuple<int, int, int>{d, m, g};
}

void Datum::Ispisi() const
{
    std::cout << d << '/' << m << '/' << g;
}


class Vrijeme
{
    int h, m;
public:
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    void Ispisi()const;
    std::pair<int, int> Ocitaj() const;
};

void Vrijeme::Postavi(int sati, int minute)
{
    if(sati < 0 || sati > 23 || minute < 0 || minute > 59)
        throw std::domain_error("Neispravno vrijeme");
        
    h = sati;
    m = minute;
}

Vrijeme::Vrijeme(int sati, int minute)
{
    Postavi(sati, minute);
}

std::pair<int, int> Vrijeme::Ocitaj() const
{
    return std::pair<int, int>{h, m};
}

void Vrijeme::Ispisi() const
{
    std::cout << std::right << std::setw(2) << std::setfill('0') << h << ':' << std::setw(2) << m;
    std::cout << std::setfill(' ');
}

class Pregled
{
    std::string ime;
    Datum d;
    Vrijeme v;
public:
    Pregled(const std::string& ime, const Datum& d, const Vrijeme& v);
    Pregled(const std::string& ime, int dan, int mj, int g, int h, int m);
    void PromijeniPacijenta(const std::string& ime);
    void PromijeniDatum(const Datum& dat);
    void PromijeniVrijeme(const Vrijeme& vr);
    void PomjeriDanUnaprijed(); //
    void PomjeriDanUnazad(); //
    std::string DajImePacijenta() const;
    Datum DajDatumPregleda() const;
    Vrijeme DajVrijemePregleda()const;
    void Ispisi() const;
    
    static bool DolaziPrije(const Pregled& p1, const Pregled& p2);
};

void Pregled::PomjeriDanUnaprijed()
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int dan, m, g;
    std::tie(dan, m, g) = d.Ocitaj();
    
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)
        broj_dana[1] = 29;
        
    if(dan == 31 || m == 12){
        d.Postavi(1, 1, g+ 1);
    }
    
    else if(dan == broj_dana[m - 1]){
        d.Postavi(1, m + 1, g);
    }
    else {
        d.Postavi(dan + 1, m, g);    
    }
    
    
}

void Pregled::PomjeriDanUnazad()
{
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int dan, m, g;
    std::tie(dan, m, g) = d.Ocitaj();
    
    if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)
        broj_dana[1] = 29;
        
    if(dan == 1 || m == 1){
        d.Postavi(31, 12, g - 1);
    }
    
    else if(dan == 1){
        d.Postavi(broj_dana[m - 2], m - 1, g);
    }
    else {
        d.Postavi(dan - 1, m, g);
    }
        
}

bool Pregled::DolaziPrije(const Pregled& p1, const Pregled& p2)
{
    int d1, m1, g1, d2, m2, g2;
    std::tie(d1, m1, g1) = p1.DajDatumPregleda().Ocitaj();
    std::tie(d2, m2, g2) = p2.DajDatumPregleda().Ocitaj();
    
    if(d1 == d2 && m1 == m2 && g1 == g2){
        return p1.DajVrijemePregleda().Ocitaj() < p2.DajVrijemePregleda().Ocitaj();
    }
    
    if(g1 == g2){
        if(m1 == m2){
            return d1 < d2;
        }
        return m1 < m2;
    }
    return g1 < g2;
}

void Pregled::Ispisi()const
{
    std::cout << std::setw(30) <<  std::left << ime;
    d.Ispisi();
    std::cout << " ";
    v.Ispisi();
    std::cout << std::endl;
}

Pregled::Pregled(const std::string& ime, const Datum& d, const Vrijeme& v) : ime(ime), d(d), v(v){}
Pregled::Pregled(const std::string& ime, int dan, int mj, int g, int h, int m) : ime(ime), d(dan, mj, g), v(h, m) {}

void Pregled::PromijeniPacijenta(const std::string& ime)
{
    this->ime = ime;
}

void Pregled::PromijeniDatum(const Datum& dat)
{
    d = dat;
}

void Pregled::PromijeniVrijeme(const Vrijeme& vr)
{
    v = vr;
}


std::string Pregled::DajImePacijenta() const
{
    return ime;
}

Datum Pregled::DajDatumPregleda() const
{
    return this->d;
}

Vrijeme Pregled::DajVrijemePregleda()const
{
    return v;
}

class Pregledi
{
    Pregled** pregledi = nullptr;
    int broj_pr;
    int max_broj_pr;
    void OslobodiMemoriju();
    Pregledi() : pregledi(nullptr), broj_pr(0), max_broj_pr(0) {}
    
public:
    explicit Pregledi(int max_pr);
    Pregledi(std::initializer_list<Pregled> sp);
    ~Pregledi();
    Pregledi(const Pregledi& pr);
    Pregledi(Pregledi&& pr);
    Pregledi& operator=(const Pregledi& pr);
    Pregledi& operator=(Pregledi&& pr);
    void RegistrirajPregled(const std::string& ime, const Datum& dat, const Vrijeme& vr);
    void RegistrirajPregled(const std::string& ime, int dat, int mj, int g, int s, int m);
    void RegistrirajPregled(Pregled* pr);
    int DajBrojPregleda() const;
    int DajBrojPregledaNaDatum(const Datum& dat) const;
    
    Pregled& DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string& ime);
    
    void IspisiPregledeNaDatum(const Datum& dat)const;
    void IspisiSvePreglede() const;
};

typedef const Pregled* PokNaPregled;

void Pregledi::IspisiSvePreglede() const
{
    auto new_pok = new Pregled*[broj_pr];
    
    std::copy(pregledi, pregledi + broj_pr, new_pok);
    
    std::sort(new_pok, new_pok + broj_pr, [](PokNaPregled p1, PokNaPregled p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    for(auto start = new_pok; start != new_pok + broj_pr; ++start){
        (*start)->Ispisi();
    }
    
    delete [] new_pok;
}

void Pregledi::IspisiPregledeNaDatum(const Datum& dat)const
{
    const auto new_pok = new Pregled*[broj_pr]{};
    const auto kraj = std::copy_if(pregledi, pregledi + broj_pr, new_pok, [&dat](PokNaPregled p){
        return p->DajDatumPregleda().Ocitaj() == dat.Ocitaj();
    });
    
    std::sort(new_pok, kraj, [](PokNaPregled p1, PokNaPregled p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    for(auto start = new_pok; start != kraj; ++start){
        (*start)->Ispisi();
    }
    
    delete [] new_pok;
}

void Pregledi::ObrisiPregledePacijenta(const std::string& ime)
{
    const auto kraj = std::remove_if(pregledi, pregledi + broj_pr, [&ime](PokNaPregled p){
        if(p->DajImePacijenta() == ime){
            delete p;
            return true;
        }
        return false;
    } );
    
    broj_pr = kraj - pregledi; 
}

void Pregledi::ObrisiNajranijiPregled()
{
    if(broj_pr == 0)
        throw std::range_error("Prazna kolekcija");
        
    auto p = &DajNajranijiPregled();
    std::remove(pregledi, pregledi + broj_pr, p);
    delete p;
    broj_pr--;
}

void Pregledi::IsprazniKolekciju()
{
    for(int i= 0; i < broj_pr; ++i){
        delete pregledi[i];
        pregledi[i] = nullptr;
    }
    broj_pr = 0;
        
}

Pregled& Pregledi::DajNajranijiPregled()
{
    if(broj_pr == 0){
        throw std::domain_error("Nema registriranih pregleda");
    }
    return **std::min_element(pregledi, pregledi + broj_pr, [](PokNaPregled p1, PokNaPregled p2){
        return Pregled::DolaziPrije(*p1, *p2);
    } );
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if(broj_pr == 0){
        throw std::domain_error("Nema registriranih pregleda");
    }
    return **std::min_element(pregledi, pregledi + broj_pr, [](PokNaPregled p1, PokNaPregled p2){
        return Pregled::DolaziPrije(*p1, *p2);
    } );
}

int Pregledi::DajBrojPregledaNaDatum(const Datum& dat) const
{
    return std::count_if(pregledi, pregledi + broj_pr, [&dat](PokNaPregled p){
        return dat.Ocitaj() == p->DajDatumPregleda().Ocitaj();
    });
}

int Pregledi::DajBrojPregleda() const
{
    return broj_pr;
}

void Pregledi::RegistrirajPregled(const std::string& ime, const Datum& dat, const Vrijeme& vr)
{
    if(broj_pr == max_broj_pr){
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    pregledi[broj_pr] = new Pregled(ime, dat, vr);
    ++broj_pr;
}

void Pregledi::RegistrirajPregled(const std::string& ime, int dat, int mj, int g, int s, int m)
{
    if(broj_pr == max_broj_pr){
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    pregledi[broj_pr] = new Pregled(ime, {dat, mj, g}, {s, m});
    ++broj_pr;
}

void Pregledi::RegistrirajPregled(Pregled* pr)
{
    if(broj_pr == max_broj_pr){
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    pregledi[broj_pr] = pr;
    ++broj_pr;
}



Pregledi& Pregledi::operator=(const Pregledi& pr)
{
    if(this == &pr)
        return *this;
    OslobodiMemoriju();
    
    std::tie(broj_pr, max_broj_pr) = std::tie(pr.broj_pr, pr.max_broj_pr);
    
    pregledi = new Pregled* [max_broj_pr]{};
    for(int i = 0; i < pr.broj_pr; ++i){
        pregledi[i] = new Pregled(*pr.pregledi[i]);
    }
    
    return *this;
    
}

Pregledi& Pregledi::operator=(Pregledi&& pr)
{
    if(this == &pr)
        return *this;
    OslobodiMemoriju();
    
    std::tie(pregledi, broj_pr, max_broj_pr) = std::tie(pr.pregledi, pr.broj_pr, pr.max_broj_pr);
    std::tie(pr.pregledi, pr.broj_pr, pr.max_broj_pr) = std::make_tuple(nullptr, 0, 0);
    
    return *this;
}

Pregledi::Pregledi(const Pregledi& pr) : Pregledi()
{
    std::tie(broj_pr, max_broj_pr) = std::tie(pr.broj_pr, pr.max_broj_pr);
    
    pregledi = new Pregled* [pr.max_broj_pr]{};
    for(int i = 0; i < pr.broj_pr; ++i){
        pregledi[i] = new Pregled(*pr.pregledi[i]);
    }
}

Pregledi::Pregledi(Pregledi&& pr) : pregledi(pr.pregledi), broj_pr(pr.broj_pr), max_broj_pr(pr.max_broj_pr)
{
    pr.pregledi = nullptr;
    pr.broj_pr = 0;
    pr.max_broj_pr = 0;
}

Pregledi::~Pregledi()
{
    OslobodiMemoriju();
}

void Pregledi::OslobodiMemoriju()
{
    for(int i = 0; i < broj_pr; ++i){
        delete pregledi[i];
    }
    delete[] pregledi;
    pregledi = nullptr;
    broj_pr = 0;
}

Pregledi::Pregledi(int max_pr) : pregledi(new Pregled* [max_pr]{}), broj_pr(0), max_broj_pr(max_pr){}

Pregledi::Pregledi(std::initializer_list<Pregled> sp) : Pregledi()
{
    broj_pr = max_broj_pr = sp.size();
    pregledi = new Pregled* [broj_pr]{};
    int i = 0;
    for(auto it = sp.begin(); it != sp.end(); ++it, ++i){
        pregledi[i] = new Pregled(*it);
    }
}


int main ()
{
    std::cout << "Unesite maksimalan broj pregleda: ";
    int n;
    std::cin >> n;
    try {
        Pregledi pregledi(n);
        for(int i = 0; i < n; ++i){
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime_pac;
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, ime_pac);
            if(ime_pac == "kraj"){
                break;
            }
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            int dan, mjesec, godina;
            std::cin >> dan >> mjesec >> godina;
            std::cout << "Unesite sate i minute pregleda: ";
            int sati, minute;
            std::cin >> sati >> minute;
            
            pregledi.RegistrirajPregled(ime_pac, dan, mjesec, godina, sati, minute);
            
        }
        
        std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
        
        pregledi.IspisiSvePreglede();
        
        while(true){
            std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
            std::cout << "1 - Broj pregleda na datum" << std::endl;
            std::cout << "2 - Najraniji pregled" << std::endl;
            std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
            std::cout << "4 - Obrisi najraniji pregled" << std::endl;
            std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
            std::cout << "6 - Ispisi sve preglede" << std::endl;
            std::cout << "7 - Kraj programa" << std::endl;
            
            int izbor;
            std::cin >> izbor;
            switch (izbor){
                
            case 1:
                std::cout << "Unesite dan mjesec i godinu : ";
                int dan, mjesec, godina;
                std::cin >> dan >> mjesec >> godina;
                try {
                    std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina;
                    std::cout << " je: " << pregledi.DajBrojPregledaNaDatum(Datum(dan, mjesec, godina)) << std::endl;
                } 
                catch (std::domain_error e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 2:
                std::cout << "Najraniji pregled je:" << std::endl;
                try {
                    pregledi.DajNajranijiPregled().Ispisi();
                    std::cout  <<  std::endl;
                }
                catch (std::domain_error e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            
            case 3:{
                std::cout << "Unesite ime pacijenta: ";
                std::string ime_pac;
                std::cin.ignore(10000, '\n');
                std::getline(std::cin, ime_pac);
                const int preg_prije = pregledi.DajBrojPregleda();
                pregledi.ObrisiPregledePacijenta(ime_pac);
                std::cout << "Uspjesno obrisano " << preg_prije - pregledi.DajBrojPregleda() << " pregleda" << std::endl;
                break;
            }
            case 4:
                try {
                    pregledi.ObrisiNajranijiPregled();
                    std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
                }
                catch (std::range_error e) {
                    std::cout << e.what() << std::endl;
                }
                break;
                
            case 5:{
                std::cout << "Unesite dan mjesec i godinu : ";
                int dan, mjesec, godina;
                std::cin >> dan >> mjesec >> godina;
                try {
                    std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:" << std::endl;
                    pregledi.IspisiPregledeNaDatum(Datum(dan, mjesec, godina));
                    std::cout << std::endl;
                }
                catch (std::domain_error e) {
                    std::cout << e.what() << std::endl;
                }
                break;
            }
                
            case 6:
                pregledi.IspisiSvePreglede();
                std::cout << std::endl;
                break;
            case 7:
                return 0;
            default:
                return 0;
            }
        }
        
    }
    catch (std::bad_alloc ) {
        std::cout << "Problemi sa memorijom" << std::endl;
    }
    catch(std::domain_error e){
        std::cout << e.what() << std::endl;
    }
    catch(std::range_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}
