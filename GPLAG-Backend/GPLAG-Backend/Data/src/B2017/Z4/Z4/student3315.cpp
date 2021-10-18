/B2017/2018: Zadaća 4, Zadatak 4
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <string>
#include <vector>
#include <memory>

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
    std::vector<std::shared_ptr<Pregled>> pr;
public:
    Pregledi() {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda); //
    ~Pregledi(); 
    Pregledi(const Pregledi &pregledi);  
    Pregledi(Pregledi &&pregledi);   
    Pregledi &operator=(const Pregledi &pregledi); 
    Pregledi &operator=(Pregledi &&pregledi);  
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
    {
        pr.push_back(std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
    }
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
    {
        RegistrirajPregled(ime_pacijenta, {dan_pregleda, mjesec_pregleda, godina_pregleda}, {sati_pregleda, minute_pregleda});
    }
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled)
    {
        pr.push_back(pregled);
    }
    int DajBrojPregleda() const
    {
        return pr.size();
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

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda)
{
    pr.reserve(spisak_pregleda.size());
    for(auto it = spisak_pregleda.begin(); it != spisak_pregleda.end(); ++it)
        pr.push_back(std::make_shared<Pregled>(*it));
}

Pregledi::Pregledi(const Pregledi& p) 
{
    pr.reserve(p.pr.size());
    for(auto it = p.pr.begin(); it != p.pr.end(); ++it)
        pr.push_back(std::make_shared<Pregled>(**it));
}


Pregledi &Pregledi::operator=(const Pregledi &p)
{
    if(this == &p)
        return *this;
        
    pr.clear();
    pr.reserve(p.pr.size());
    for(auto it = p.pr.begin(); it != p.pr.end(); ++it)
        pr.push_back(std::make_shared<Pregled>(**it));
        
    return *this;
}

Pregledi &Pregledi::operator=(Pregledi &&p)
{
    if(this == &p)
        return *this;
        
    pr.clear();
    pr = std::move(p.pr);
    p.pr.clear();
    
    return *this;
}

Pregledi::Pregledi(Pregledi&& p)
{
    pr = std::move(p.pr);
    p.pr.clear();
}

void Pregledi::IsprazniKolekciju()
{
    pr.clear();
}

Pregledi::~Pregledi() {}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    pr.erase(std::remove_if(pr.begin(), pr.end(), [&ime_pacijenta](const std::shared_ptr<Pregled>& p){
       return p->DajImePacijenta() == ime_pacijenta; 
    }), pr.end());
    
}

void Pregledi::ObrisiNajranijiPregled()
{
    if(pr.size() == 0)
        throw std::range_error("Prazna kolekcija");
    auto p = &DajNajranijiPregled();
    pr.erase(std::remove_if(pr.begin(), pr.end(), [&p](const std::shared_ptr<Pregled>& pr){
       return p == pr.get(); 
    }), pr.end());
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(pr.size() == 0)
        throw std::domain_error("Nema registriranih pregleda");
        
    return **std::min_element(pr.begin(), pr.end(), [](const std::shared_ptr<Pregled>& p1, const std::shared_ptr<Pregled>& p2){
       return Pregled::DolaziPrije(*p1, *p2); 
    });
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if(pr.size() == 0)
        throw std::domain_error("Nema registriranih pregleda");
        
    return **std::min_element(pr.begin(), pr.end(), [](const std::shared_ptr<Pregled>& p1, const std::shared_ptr<Pregled>& p2){
       return Pregled::DolaziPrije(*p1, *p2); 
    });
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const
{
    return std::count_if(pr.begin(), pr.end(), [&datum](const std::shared_ptr<Pregled>& p) {
        return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj();
    });
}


void Pregledi::IspisiSvePreglede() const
{
    auto pok = pr;
    
    std::sort(pok.begin(), pok.end(), [](const std::shared_ptr<Pregled>& p1, const std::shared_ptr<Pregled>& p2){
       return Pregled::DolaziPrije(*p1, *p2); 
    });
    
    for(int i = 0; i < pok.size(); ++i){
        pok[i]->Ispisi();
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    auto pok = pr;
    
    auto kraj = std::partition(pok.begin(), pok.end(), [&datum](const std::shared_ptr<Pregled>& p){
        return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj();
    });
    
    std::sort(pok.begin(), kraj, [](const std::shared_ptr<Pregled>& p1, const std::shared_ptr<Pregled>& p2){
       return Pregled::DolaziPrije(*p1, *p2); 
    });
    
    for(auto it = pok.begin(); it != kraj; ++it){
        (*it)->Ispisi();
    }
}

int main ()
{
    Pregledi p;
    for(;;){
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
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
        std::cin.ignore(1000, '\n');
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
    
    
	return 0;
}
