/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>

using std::string;

typedef std::tuple<int, int, int> t3i;

class Datum{
    int dan, mjesec, godina;
    void CheckDate(int d, int m, int g){
        int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
        if(((g % 4 == 0 && g % 100 != 0) || g % 400 == 0)) brojDana[1]++;
        if(g < 1 || d < 1 || m < 1 || m > 12 || d > brojDana[m-1])
            throw std::domain_error("Neispravan datum");
    }
public:
    Datum(int dan, int mjesec, int godina){
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina){
        CheckDate(dan, mjesec, godina);
        Datum::dan = dan;
        Datum::mjesec = mjesec;
        Datum::godina = godina;
    }
    t3i Ocitaj() const{
        return std::make_tuple(dan, mjesec, godina);
    }
    void Ispisi() const{
        std::cout << dan << "/" << mjesec << "/" << godina;
    }
};

class Vrijeme{
    int sati, minute;
    void CheckTime(int h, int m){
        if(h < 0 || m < 0 || h > 23 || m > 59)
            throw std::domain_error("Neispravno vrijeme");
    }
public:
    Vrijeme(int sati, int minute){
        Postavi(sati, minute);
    }
    void Postavi(int sati, int minute){
        CheckTime(sati, minute);
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }
    std::pair<int, int> Ocitaj() const {
        return std::make_pair(sati, minute);
    }
    void Ispisi() const {
        std::cout << std::setfill('0') << std::setw(2) << std::right << sati << ":" << std::setw(2) << std::right << minute << std::left;
        std::cout << std::setfill(' ');
    }
};

class Pregled{
    string pacijent;
    Datum datum;
    Vrijeme vrijeme;
public:
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
    : pacijent(ime_pacijenta), datum(datum_pregleda), vrijeme(vrijeme_pregleda) {}
    Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
    : pacijent(ime_pacijenta), datum(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme(sati_pregleda, minute_pregleda) {}
    
    void PromijeniPacijenta(const string &ime_pacijenta) { pacijent = ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { datum = novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme = novo_vrijeme; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    string DajImePacijenta() const { return pacijent; }
    Datum DajDatumPregleda() const { return datum; }
    Vrijeme DajVrijemePregleda() const { return vrijeme; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

class Pregledi{
    int max_br;
    Pregled** pregledi = nullptr;
    int br_pregleda;
    
    Pregled** Alloc(int max_br);
    void DeAlloc();
    void Add(Pregled *pregled);
    void ObrisiPregled(Pregled *pregled, int);
public:
    explicit Pregledi(int max_broj_pregleda) : max_br(max_broj_pregleda), pregledi(Alloc(max_br)), br_pregleda(0) {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    ~Pregledi(){ DeAlloc(); }
    
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        Add(new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
    }
    void RegistrirajPregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
        Add(new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
    }
    void RegistrirajPregled(Pregled *pregled){
        Add(pregled);
    }
    
    int DajBrojPregleda() const { return br_pregleda; }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    
    Pregled& DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

int main () {
    int n;
    std::cout << "Unesite maksimalan broj pregleda: ";
    std::cin >> n;
    
    Pregledi p(n);
    
    //Input
    for(int i = 0; i < n; i++){
        std::string s;
        int d,m,g,h,min;
        
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::cin >> s;
        if(s == "kraj") break;
        
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        std::cin >> d >> m >> g;
        std::cout << "Unesite sate i minute pregleda: ";
        std::cin >> h >> min;
        try{
            p.RegistrirajPregled(s, d, m, g, h, min);
        }catch(std::exception &err){
            std::cout << err.what() << std::endl;
            i--;
            continue;
        }
    }
    
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    p.IspisiSvePreglede();
    std::cout << std::endl;
    
    while(true){
        int opt;
        std::cout << "Odaberite jednu od sljedecih opcija" << std::endl
            << "1 - Broj pregleda na datum" << std::endl
            << "2 - Najraniji pregled" << std::endl
            << "3 - Obrisi pregled pacijenta" << std::endl
            << "4 - Obrisi najraniji pregled" << std::endl
            << "5 - Ispisi sve pregleda na datum" << std::endl
            << "6 - Ispisi sve preglede" << std::endl
            << "7 - Kraj programa" << std::endl;
        
        std::cin >> opt;
        
        try{
            if(opt < 1 || opt > 7)
                throw std::domain_error("Neispravna komanda");
            
            if(opt == 1){
                int d,m,g;
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> d >> m >> g;
                Datum dt(d, m, g);
                std::cout << "Broj pregleda na datum " << d << " " << m << " " << g  << " je: " << p.DajBrojPregledaNaDatum(dt);
                std::cout << std::endl;
            }else if(opt == 2){
                std::cout << "Najraniji pregled je:" << std::endl;
                p.DajNajranijiPregled().Ispisi();
            }else if(opt == 3){
                std::string s;
                std::cout << "Unesite ime pacijenta: ";
                std::cin >> s;
                int br = p.DajBrojPregleda();
                p.ObrisiPregledePacijenta(s);
                std::cout << "Uspjesno obrisano " << br-p.DajBrojPregleda() << " pregleda";
                std::cout << std::endl;
            }else if(opt == 4){
                p.ObrisiNajranijiPregled();
                std::cout << "Najraniji pregled uspjesno obrisan";
                std::cout << std::endl;
            }else if(opt == 5){
                int d,m,g;
                std::cout << "Unesite dan mjesec i godinu : ";
                std::cin >> d >> m >> g;
                Datum dt(d,m,g);
                std::cout << "Pregledi na datum 18 12 2018 su:" << std::endl;
                p.IspisiPregledeNaDatum(dt);
            }else if(opt == 6){
                p.IspisiSvePreglede();
            }else
                break;
            
            std::cout << std::endl;
        }catch(std::exception &err){
            std::cout << err.what() << std::endl;
        }
    }
    
	return 0;
}

void Pregled::PomjeriDanUnaprijed() {
    int dan, mjesec, godina;
    std::tie(dan, mjesec, godina) = datum.Ocitaj();
    int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
    if(((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)) brojDana[1]++;
    dan++;
    if(dan > brojDana[mjesec-1]){
        dan = 1;
        mjesec++;
        if(mjesec > 12){
            mjesec = 1;
            godina++;
        }
    }
    datum.Postavi(dan, mjesec, godina);
}

void Pregled::PomjeriDanUnazad() {
    int dan, mjesec, godina;
    std::tie(dan, mjesec, godina) = datum.Ocitaj();
    int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30 ,31, 30, 31};
    if(((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)) brojDana[1]++;
    dan--;
    if(dan < 1){
        mjesec--;
        if(mjesec < 1){
            mjesec = 12;
            godina--;
        }
        dan = brojDana[mjesec-1];
    }
    datum.Postavi(dan, mjesec, godina);
}

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2){
    int d1, m1, g1, d2, m2, g2;
    std::tie(d1, m1, g1) = p1.DajDatumPregleda().Ocitaj();
    std::tie(d2, m2, g2) = p2.DajDatumPregleda().Ocitaj();
    
    if(g1 > g2) return false;
    else if(g1 == g2){
        if(m1 > m2) return false;
        else if(m1 == m2){
            if(d1 > d2) return false;
            else if(d1 == d2){
                int h1, m1, h2, m2;
                std::tie(h1, m1) = p1.DajVrijemePregleda().Ocitaj();
                std::tie(h2, m2) = p2.DajVrijemePregleda().Ocitaj();
                if(h1 > h2) return false;
                else if(h1 == h2){
                    if(m1 >= m2) return false;
                    return true;
                }
                return true;
            }
            return true;
        }
        return true;
    }
    return true;
}

void Pregled::Ispisi() const {
    std::cout << std::setw(30) << std::left << pacijent;
    datum.Ispisi();
    std::cout << " ";
    vrijeme.Ispisi();
    std::cout << std::endl;
}

Pregled** Pregledi::Alloc(int max_br){
    return new Pregled*[max_br]{};
}

void Pregledi::DeAlloc(){
    if(pregledi){
        for(int i = 0; i < max_br; i++){
            delete pregledi[i];
        }
        delete[] pregledi;
        pregledi = nullptr;
    }
}

void Pregledi::Add(Pregled *pregled){
    //Moguca greska!!!!!!!!!
    if(br_pregleda >= max_br){
        delete pregled;
        pregled = nullptr;
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    
    //Nadji prvi nullptr (prazno mjesto) te preusmjeri taj pokazivac
    //na novododani objekat
    for(int i = 0; i < max_br; i++){
        if(pregledi[i] == nullptr){
            pregledi[i] = pregled;
            br_pregleda++;
            break;
        }
    }
}

void Pregledi::ObrisiPregled(Pregled *pregled, int idx = 0){
    for(int i = idx; i < br_pregleda; i++){
        if(pregled == pregledi[i]){
            delete pregled;
            //Nakon brisanja, suzbiti sve pokazivace
            for(int j = i; j < br_pregleda-1; j++){
                pregledi[j] = pregledi[j+1];
            }
            pregledi[br_pregleda-1] = nullptr;
            br_pregleda--;
            break;
        }
    }
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : max_br(spisak_pregleda.size()), pregledi(Alloc(max_br)){
    std::initializer_list<Pregled>::iterator it;
    int i = 0;
    try{
        for(it = spisak_pregleda.begin(); it != spisak_pregleda.end(); it++, i++)
            pregledi[i] = new Pregled(*it);
    }catch(...){
        for(int j = 0; j < i; j++)
            delete pregledi[j];
        delete[] pregledi;
        throw;
    }
    br_pregleda = i;
}

Pregledi::Pregledi(const Pregledi &pregledi) : max_br(pregledi.max_br), pregledi(Alloc(max_br)), br_pregleda(pregledi.br_pregleda){
    try{
        for(int i = 0; i < br_pregleda; i++)
            Pregledi::pregledi[i] = new Pregled(*pregledi.pregledi[i]);
    }catch(...){
        for(int j = 0; j < br_pregleda; j++)
            delete Pregledi::pregledi[j];
        delete[] Pregledi::pregledi;
        throw;
    }
}

Pregledi::Pregledi(Pregledi &&pregledi) : max_br(pregledi.max_br), pregledi(pregledi.pregledi), br_pregleda(pregledi.br_pregleda){
    pregledi.pregledi = nullptr;
}

Pregledi& Pregledi::operator =(const Pregledi &pregledi){
    if(&pregledi == this) return *this;
    
    DeAlloc();
    max_br = pregledi.max_br;
    br_pregleda = pregledi.br_pregleda;
    Pregledi::pregledi = Alloc(max_br);
    for(int i = 0; i < br_pregleda; i++){
        Pregledi::pregledi[i] = new Pregled(*pregledi.pregledi[i]);
    }
    
    return *this;
}

Pregledi& Pregledi::operator =(Pregledi &&pregledi){
    if(&pregledi == this) return *this;
    
    DeAlloc();
    max_br = pregledi.max_br;
    br_pregleda = pregledi.br_pregleda;
    Pregledi::pregledi = pregledi.pregledi;
    pregledi.pregledi = nullptr;
    
    return *this;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return std::count_if(pregledi, pregledi+br_pregleda, [&datum](const Pregled *pregled){
        return datum.Ocitaj() == pregled->DajDatumPregleda().Ocitaj();
    });
}

Pregled& Pregledi::DajNajranijiPregled(){
    Pregled* it = *std::min_element(pregledi, pregledi+br_pregleda, [](Pregled* p1, Pregled* p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    if(it == *pregledi+br_pregleda)
        throw std::domain_error("Nema registriranih pregleda");
    
    return *it;
}

Pregled Pregledi::DajNajranijiPregled() const {
    Pregled* it = *std::min_element(pregledi, pregledi+br_pregleda, [](Pregled* p1, Pregled* p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    if(it == *(pregledi+br_pregleda))
        throw std::domain_error("Nema registriranih pregleda");
    
    return *it;
}

void Pregledi::IsprazniKolekciju(){
    DeAlloc();
    max_br = br_pregleda = 0;
}

void Pregledi::ObrisiNajranijiPregled(){
    if(br_pregleda == 0)
        throw std::range_error("Prazna kolekcija");
    
    Pregled* it = &DajNajranijiPregled();
    ObrisiPregled(it);
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    for(int i = 0; i < br_pregleda; i++){
        if(pregledi[i]->DajImePacijenta()==ime_pacijenta){
            ObrisiPregled(pregledi[i], i);
            i--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    //Pravi se novi niz pokazivaca velik tacno onoliko koliko
    //ima pregleda na zadani datum
    Pregled** temp = new Pregled*[DajBrojPregledaNaDatum(datum)]{};
    int j = 0;
    
    for(int i = 0; i < br_pregleda; i++){
        if(pregledi[i]->DajDatumPregleda().Ocitaj() == datum.Ocitaj()){
            temp[j] = pregledi[i];
            j++;
        }
    }
    
    std::sort(temp, temp+j, [](Pregled* p1, Pregled* p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    for(int i = 0; i < j; i++)
        temp[i]->Ispisi();
    
    delete[] temp;
}

void Pregledi::IspisiSvePreglede() const {
    Pregled** temp = new Pregled*[br_pregleda]{};
    
    std::copy(pregledi, pregledi+br_pregleda, temp);
    
    std::sort(temp, temp+br_pregleda, [](Pregled* p1, Pregled* p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    for(int i = 0; i < br_pregleda; i++)
        temp[i]->Ispisi();
        
    delete[] temp;
}