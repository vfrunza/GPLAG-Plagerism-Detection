/B2017/2018: Zadaća 4, Zadatak 3
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <string>

class Datum
{
    int dan, mjesec, godina;
public:

    Datum(int dan, int mjesec, int godina)
    {
        Postavi(dan, mjesec, godina);
    }
    void Postavi(int dan, int mjesec, int godina);
    
    std::tuple<int, int, int> Ocitaj() const
    {
        return std::make_tuple(dan, mjesec, godina);
    }
    
    void Ispisi() const
    {
        std::cout << dan << '/' << mjesec << '/' << godina;
    }
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
        ++broj_dana[1];
        
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1] || godina < 1)
        throw std::domain_error("Neispravan datum");
        
    this->dan = dan;
    this->mjesec = mjesec;
    this->godina = godina;
}

class Vrijeme
{
    int sati, minute;
public:

    Vrijeme(int sati, int minute)
    {
        Postavi(sati, minute);
    }
    void Postavi(int sati, int minute); 
    
    std::pair<int, int> Ocitaj () const
    {
        return std::make_pair(sati, minute);
    }
    
    void Ispisi() const;
};

void Vrijeme::Postavi(int sati, int minute)
{
    if(sati < 0 || minute < 0 || sati > 23 || minute > 59)
        throw std::domain_error("Neispravno vrijeme");
        
    this->sati = sati;
    this->minute = minute;
}

void Vrijeme::Ispisi() const
{
    if(sati < 10)
        std::cout << '0';
    std::cout << sati << ':'; 
    if(minute < 10)
        std::cout << '0';
    std::cout << minute;
}


class Pregled
{
    std::string ime;
    Datum d;
    Vrijeme v;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda,  const Vrijeme &vrijeme_pregleda) : ime(ime_pacijenta), d(datum_pregleda), v (vrijeme_pregleda){}
    
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)   
        : ime(ime_pacijenta), d(dan_pregleda, mjesec_pregleda, godina_pregleda), v(sati_pregleda, minute_pregleda) {}
    
    
    void PromijeniPacijenta(const std::string &ime_pacijenta)
    {
        ime = ime_pacijenta;
    }
    
    void PromijeniDatum(const Datum &novi_datum)
    {
        auto o = novi_datum.Ocitaj();
        d.Postavi(std::get<0>(o), std::get<1>(o), std::get<2>(o));
    }
    
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme)
    {
        auto o = novo_vrijeme.Ocitaj();
        v.Postavi(o.first, o.second);
    }
    
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    
    std::string DajImePacijenta() const
    {
        return ime;
    }
    Datum DajDatumPregleda() const
    {
        return d;
    }
    Vrijeme DajVrijemePregleda() const
    {
        return v;
    }
    
    void Ispisi() const;
    
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2)
    {
        auto o1 = p1.DajDatumPregleda().Ocitaj(), o2 = p2.DajDatumPregleda().Ocitaj();
        if(o1 == o2){
            return p1.DajVrijemePregleda().Ocitaj() < p2.DajVrijemePregleda().Ocitaj();
        }
        if(std::get<2>(o1) == std::get<2>(o2)){
            if(std::get<1>(o1) == std::get<1>(o2)){
                return std::get<0>(o1) < std::get<0>(o2);
            }
            return std::get<1>(o1) < std::get<1>(o2);
        }
        return std::get<2>(o1) < std::get<2>(o2);
    }
};

void Pregled::Ispisi() const
{
    std::cout << std::setw(30) << std::left << ime;
    d.Ispisi();
    std::cout << ' '; 
    v.Ispisi();
    std::cout << '\n';
        
}

void Pregled::PomjeriDanUnaprijed()
{
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    auto d = this->d.Ocitaj();
    
    int godina = std::get<2>(d);
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
        ++broj_dana[1];
    
    if(d == std::make_tuple(31, 12, godina)){
        this->d.Postavi(1, 1, godina + 1);
        return;
    }
    
    int m = std::get<1>(d);
    
    if(d == std::make_tuple(broj_dana[m - 1], m, godina)){
        this->d.Postavi(1, m + 1, godina);
        return;
    }
    
    this->d.Postavi(std::get<0>(d) + 1, m, godina);
    
}
void Pregled::PomjeriDanUnazad()
{
    int broj_dana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    auto d = this->d.Ocitaj();
    
    int godina = std::get<2>(d);
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0)
        ++broj_dana[1];
    
    if(d == std::make_tuple(1, 1, godina)){
        this->d.Postavi(31, 12, godina - 1);
        return;
    }
    
    int m = std::get<1>(d);
    
    if(d == std::make_tuple(1, m, godina)){
        this->d.Postavi(broj_dana[m - 2], m - 1, godina);
        return;
    }
    
    this->d.Postavi(std::get<0>(d) - 1, m, godina);
}


class Pregledi
{
    Pregled** pr;
    int br_pr;
    int max_br;
public:
    explicit Pregledi(int max_broj_pregleda) : pr(new Pregled* [max_broj_pregleda]), br_pr(0), max_br(max_broj_pregleda) {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda); 
    ~Pregledi(); 
    Pregledi(const Pregledi &pregledi);  
    Pregledi(Pregledi &&pregledi);   
    Pregledi &operator=(const Pregledi &pregledi); 
    Pregledi &operator=(Pregledi &&pregledi);  
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
    {
        if(br_pr == max_br){
            throw std::range_error("Dostignut maksimalni broj pregleda");
        }
        pr[br_pr++] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
    {
        RegistrirajPregled(ime_pacijenta, {dan_pregleda, mjesec_pregleda, godina_pregleda}, {sati_pregleda, minute_pregleda});
    }
    void RegistrirajPregled(Pregled *pregled)
    {
        if(br_pr == max_br){
            throw std::range_error("Dostignut maksimalni broj pregleda");
        }
        pr[br_pr++] = pregled;
    }
    int DajBrojPregleda() const
    {
        return br_pr;
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

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : pr(new Pregled* [spisak_pregleda.size()]{}), br_pr(spisak_pregleda.size()), max_br(br_pr)
{
    try{
        auto it = spisak_pregleda.begin();
        
        for(int i = 0; i < spisak_pregleda.size(); ++i, ++it){
            pr[i] = new Pregled(*it);    
        }
        
    }catch(std::bad_alloc){
        for(int i = 0; i < br_pr; ++i){
            delete pr[i];
        }
        delete [] pr;
        throw;
    }
}

Pregledi::Pregledi(const Pregledi& p) : pr(new Pregled* [p.max_br]{}), br_pr(0), max_br(p.max_br)
{
    try{
        br_pr = p.br_pr;
        max_br = p.br_pr;
        
        for(int i = 0; i < p.br_pr; ++i){
            pr[i] = new Pregled(*p.pr[i]);
        }
       
    } catch(std::bad_alloc){
        for(int i = 0; i < br_pr; ++i){
            delete pr[i];
        }
        delete [] pr;
        throw;
    }
}


Pregledi &Pregledi::operator=(const Pregledi &p)
{
    if(this == &p)
        return *this;
        
    for(int i = 0; i < br_pr; ++i){
        delete pr[i];
    }
    delete [] pr;
    
    pr = new Pregled*[p.max_br]{};
    br_pr = 0;
    
    try{
        br_pr = p.br_pr;
        max_br = p.br_pr;
        
        for(int i = 0; i < p.br_pr; ++i){
            pr[i] = new Pregled(*p.pr[i]);
        }
        
    } catch(std::bad_alloc){
        for(int i = 0; i < br_pr; ++i){
            delete pr[i];
        }
        delete [] pr;
        throw;
    }
    return *this;
}

Pregledi &Pregledi::operator=(Pregledi &&p)
{
    if(this == &p)
        return *this;
        
    for(int i = 0; i < br_pr; ++i){
        delete pr[i];
    }
    delete [] pr;
    
    pr = p.pr;
    br_pr = p.br_pr;
    max_br = p.max_br;
    
    p.br_pr = p.max_br = 0;
    p.pr = nullptr;
    
    return *this;
}

Pregledi::Pregledi(Pregledi&& p)
{
    pr = p.pr;
    br_pr = p.br_pr;
    max_br = p.max_br;
    
    p.br_pr = p.max_br = 0;
    p.pr = nullptr;
}

void Pregledi::IsprazniKolekciju()
{
    for(int i = 0; i < br_pr; ++i){
        delete pr[i];
    }
    std::fill(pr, pr + br_pr, nullptr);
    br_pr = 0;
}

Pregledi::~Pregledi()
{
    for(int i = 0; i < br_pr; ++i){
        delete pr[i];
    }
    delete [] pr;
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    auto p = std::partition(pr, pr + br_pr, [&ime_pacijenta](Pregled* p){
        return p->DajImePacijenta() != ime_pacijenta;
    });
    auto end = pr + br_pr;
    for(; p < end; ++p, --br_pr)
        delete *p;
}

void Pregledi::ObrisiNajranijiPregled()
{
    if(br_pr == 0)
        throw std::range_error("Prazna kolekcija");
    auto p = &DajNajranijiPregled();
    std::remove(pr, pr + br_pr, p);
    --br_pr;
    delete p;
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(br_pr == 0)
        throw std::domain_error("Nema registriranih pregleda");
        
    return **std::min_element(pr, pr + br_pr, [](Pregled* p1, Pregled* p2){
       return Pregled::DolaziPrije(*p1, *p2); 
    });
}
Pregled Pregledi::DajNajranijiPregled() const
{
    if(br_pr == 0)
        throw std::domain_error("Nema registriranih pregleda");
    
    return **std::min_element(pr, pr + br_pr, [](Pregled* p1, Pregled* p2){
        return Pregled::DolaziPrije(*p1, *p2); 
    });
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    if(br_pr == 0){
        throw std::domain_error("Nema registriranih pregleda");
    }
    return std::count_if(pr, pr + br_pr, [&datum](Pregled* p) {
        return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj();
    });
}


void Pregledi::IspisiSvePreglede() const
{
    auto pok = new Pregled* [br_pr];
    std::copy(pr, pr + br_pr, pok);
    
    std::sort(pok, pok + br_pr, [](Pregled* p1, Pregled* p2){
        return Pregled::DolaziPrije(*p1, *p2); 
    });
    
    for(int i = 0; i < br_pr; ++i){
        pok[i]->Ispisi();
    }
    
    delete [] pok;
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    auto d = datum.Ocitaj();
    auto pok = new Pregled* [br_pr];
    int j = 0;
    for(int i = 0; i < br_pr; ++i){
        if(d == pr[i]->DajDatumPregleda().Ocitaj()){
            pok[j++] = pr[i];
        }
    }
    if(j == 0){
        delete [] pok;
        return;
    }
        
        
    std::sort(pok, pok + j, [](Pregled* p1, Pregled* p2){
       return Pregled::DolaziPrije(*p1, *p2); 
    });
    
    for(int i = 0; i < j; ++i){
        pok[i]->Ispisi();
    }
    
    delete [] pok;
}

int main ()
{
    std::cout << "Unesite maksimalan broj pregleda: ";
    int n ;
    std::cin >> n;
    try {
        Pregledi p(n);
        for(int i = 0; i < n; ++i){
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime;
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, ime);
            if(ime == "kraj"){
                break;
            }
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            int d, m, g;
            std::cin >> d >> m >> g;
            std::cout << "Unesite sate i minute pregleda: ";
            int s, min;
            std::cin >> s >> min;
            try {
                p.RegistrirajPregled(ime, d, m, g, s, min);
            }
            catch (std::range_error e) {
                std::cout << e.what() << std::endl;
            }
            catch(std::domain_error e) {
                std::cout << e.what() << std::endl;
            }
            catch(std::bad_alloc ){
                std::cout << "Problemi sa memorijom\n";
            }
        }
        
        std::cout << "Trenutno su registrovani sljedeci pregledi\n";
        p.IspisiSvePreglede();
        std::cout << '\n';
        
        for(;;){
            std::cout << "Odaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n";
            std::cout << "4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
            
            int izbor = -1;
            std::cin >> izbor;
            
            if(izbor == 1){
                std::cout << "Unesite dan mjesec i godinu : ";
                int d, m, g;
                std::cin >> d >> m >> g;
                try {
                    Datum dat(d, m, g);
                    std::cout << "Broj pregleda na datum " << d << " " << m << " " << g << " je: " << p.DajBrojPregledaNaDatum(dat) << "\n";
                }
                catch (std::domain_error e) {
                    std::cout << e.what() << std::endl;
                }
                
                
            }
            
            else if(izbor == 2){
                try {
                    std::cout << "Najraniji pregled je:\n";
                    p.DajNajranijiPregled().Ispisi();
                }
                catch (std::domain_error e) {
                    std::cout << e.what() << std::endl;
                }
                
                
            }
            
            else if(izbor == 3){
                std::cout << "Unesite ime pacijenta: ";
                std::string ime;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, ime);
                int br_pregleda = p.DajBrojPregleda();
                p.ObrisiPregledePacijenta(ime);
                std::cout << "Uspjesno obrisano " << br_pregleda - p.DajBrojPregleda() << " pregleda\n";
            }
            
            else if(izbor == 4){
                try {
                    p.ObrisiNajranijiPregled();
                    std::cout << "Najraniji pregled uspjesno obrisan\n"; 
                }
                catch (std::range_error e) {
                    std::cout << e.what() << std::endl;
                }
            }
            
            else if(izbor == 5){
                std::cout << "Unesite dan mjesec i godinu : ";
                int d, m, g;
                std::cin >> d >> m >> g;
                try {
                    Datum dat(d, m, g);
                    std::cout << "Pregledi na datum " << d << " " << m << " " << g << " su:\n";
                    p.IspisiPregledeNaDatum(dat);
                }
                catch (std::domain_error e) {
                    std::cout << e.what() << std::endl;
                }
                
                
            }
            
            else if(izbor == 6){
                p.IspisiSvePreglede();
            }
            
            else if(izbor == 7){
                return 0;
            }
            else{
                return 0;
            }
            
        }
        
    }
    catch (std::bad_alloc ) {
        std::cout << "Problemi sa memorijom\n";
    }
	return 0;
}
