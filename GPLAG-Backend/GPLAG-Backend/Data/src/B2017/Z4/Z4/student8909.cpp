/B2017/2018: Zadaća 4, Zadatak 4

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <tuple>
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
        std::tuple<int, int, int> a;
        a = std::make_tuple(Datum::dan, Datum::mjesec, Datum::godina);
        return a;
    }
    void Ispisi() const 
    {
        std::cout << Datum::dan << "/" << Datum::mjesec << "/" << Datum::godina;
    }
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) 
        broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1])  
        throw std::domain_error ("Neispravan datum");
        
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

class Vrijeme
{
    int sati, minute;
    
    public:
    
    Vrijeme(int sati, int minute)
    {
        Postavi(sati, minute);
    }
    
    void Postavi(int sati, int minute)
    {
        if(sati < 0 || sati > 23 || minute < 0 || minute > 59)
            throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati;
        Vrijeme::minute = minute;
    }
    
    std::pair<int, int> Ocitaj() const
    {
        std::pair<int, int> b;
        b = std::make_pair(Vrijeme::sati, Vrijeme::minute);
        
        return b;
    }
    
    void Ispisi() const
    {
        std::cout << std::setfill('0') << std::setw(2) << Vrijeme::sati << ":" << std::setw(2) << Vrijeme::minute << std::setfill(' ');
        
    }
};

class Pregled
{
    std::string ImePrezime;
    Datum DatumPregleda;
    Vrijeme VrijemePregleda;
    
    public:
    
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ImePrezime(ime_pacijenta), DatumPregleda(datum_pregleda), VrijemePregleda(vrijeme_pregleda){};
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
   
    void PromijeniPacijenta(const std::string &ime_pacijenta)
    {
        ImePrezime = ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum)
    {
        DatumPregleda = novi_datum;
    }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme)
    {
        VrijemePregleda = novo_vrijeme;
    }
    
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    
    std::string DajImePacijenta() const
    {
        return ImePrezime;
    }
    Datum DajDatumPregleda() const
    {
        return DatumPregleda;
    }
    Vrijeme DajVrijemePregleda() const
    {
        return VrijemePregleda;
    }
    friend bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
};

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : ImePrezime(ime_pacijenta), 
                    DatumPregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), VrijemePregleda(sati_pregleda, minute_pregleda){};
                        
void Pregled::PomjeriDanUnaprijed()
{
    int dan = std::get<0>(DatumPregleda.Ocitaj()), mjesec = std::get<1>(DatumPregleda.Ocitaj()), godina = std::get<2>(DatumPregleda.Ocitaj());
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 ==0)
        broj_dana[1]++;
    dan++;
    
    if(dan > broj_dana[mjesec - 1])
    {
        dan = 1;
        mjesec++;
        if(mjesec > 12)
        {
            mjesec = 1;
            godina++;
        }
    }
    DatumPregleda.Postavi(dan, mjesec, godina);
}

void Pregled::PomjeriDanUnazad()
{
    int dan = std::get<0>(DatumPregleda.Ocitaj()), mjesec = std::get<1>(DatumPregleda.Ocitaj()), godina = std::get<2>(DatumPregleda.Ocitaj());
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
        broj_dana[1]++;
        
        dan--;
        
        if(dan < 1)
        {
            mjesec--;
            if(mjesec != 0) dan = broj_dana[mjesec - 1];
            else dan = 31;
            
            if(mjesec < 1)
            {
                mjesec = 12;
                godina--;
            }
        }
        DatumPregleda.Postavi(dan, mjesec, godina);
}

bool DolaziPrije(const Pregled &p1, const Pregled &p2)
{
    if(std::get<2>(p1.DatumPregleda.Ocitaj()) > std::get<2>(p2.DatumPregleda.Ocitaj()))
        return false;
    else if(std::get<1>(p1.DatumPregleda.Ocitaj()) > std::get<1>(p2.DatumPregleda.Ocitaj()))
        return false;
    else if(std::get<0>(p1.DatumPregleda.Ocitaj()) > std::get<0>(p2.DatumPregleda.Ocitaj()))
        return false;
    else if(p1.VrijemePregleda.Ocitaj().first > p2.VrijemePregleda.Ocitaj().first)
        return false;
    else if(p1.VrijemePregleda.Ocitaj().second > p2.VrijemePregleda.Ocitaj().second)
        return false;
        
        return true;
}

void Pregled::Ispisi() const
{
    std::cout << std::left << std::setw(30) << DajImePacijenta() << std::right;
    DatumPregleda.Ispisi();
    std::cout << " ";
    VrijemePregleda.Ispisi();
    std::cout << std::endl;
}

class Pregledi
{
    //int MaxBrojPregleda, Stanje;
    std::vector<std::shared_ptr<Pregled>> PokPregled;
    
    public:
    Pregledi() { PokPregled.resize(0);}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi()
    {
        PokPregled.resize(0);
    }
    
    Pregledi(Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator=(Pregledi &pregledi)
    {
        if(this == &pregledi) return *this;
        
        //kod destruktora
        PokPregled.resize(0);
        
        //kod konstruktora kopije
        for(int i=0; i<PokPregled.size(); i++)
            PokPregled.push_back(std::make_shared<Pregled> (*pregledi.PokPregled[i]));
    }
    
    Pregledi &operator=(Pregledi &&pregledi)
    {
        if(this == &pregledi) return *this;
        
        for(int i = 0; i < PokPregled.size(); i++) PokPregled[i] = nullptr;
        
        PokPregled = pregledi.PokPregled;
        pregledi.PokPregled.resize(0);
           
        return *this;
    }
    
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
   
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled)
    {
        PokPregled.push_back(pregled);
    }
   
    int DajBrojPregleda() const
        {
            if(PokPregled.size() == 0) throw std::domain_error("Nema registriranih pregleda");
            return PokPregled.size();
        }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    
    Pregled &DajNajranijiPregled(){
        return **std::min_element(PokPregled.begin(), PokPregled.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2)
        {
            int datum1 = std::get<0>(p1->DajDatumPregleda().Ocitaj()) + std::get<1>(p1->DajDatumPregleda().Ocitaj())*100 + std::get<2>(p1->DajDatumPregleda().Ocitaj())*1000;
            int datum2 = std::get<0>(p2->DajDatumPregleda().Ocitaj()) + std::get<1>(p2->DajDatumPregleda().Ocitaj())*100 + std::get<2>(p2->DajDatumPregleda().Ocitaj())*1000;
            int vrijeme1 = p1->DajVrijemePregleda().Ocitaj().second*60 + p1->DajVrijemePregleda().Ocitaj().first*3600;
            int vrijeme2 = p2->DajVrijemePregleda().Ocitaj().second*60 + p2->DajVrijemePregleda().Ocitaj().first*3600;
            if(datum1 < datum2)
                return true;
            else if(datum1 == datum2 && vrijeme1 < vrijeme2)
                return true;
            return false;
        });
    }
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenata(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) 
{
    PokPregled.resize(spisak_pregleda.size());
    
    for(auto it = spisak_pregleda.begin(); it != spisak_pregleda.end(); it++)
    {
        PokPregled.push_back(std::make_shared<Pregled> (*it));
    }
}

Pregledi::Pregledi(Pregledi &pregledi)
{
   for(int i=0; i<pregledi.PokPregled.size(); i++)
    PokPregled.push_back(std::make_shared<Pregled> (*pregledi.PokPregled[i]));
}

Pregledi::Pregledi(Pregledi &&pregledi)
{
    PokPregled = pregledi.PokPregled;
    pregledi.PokPregled.resize(0);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    std::shared_ptr<Pregled> pregled;
    pregled = std::make_shared<Pregled> (ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    RegistrirajPregled(pregled);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    std::shared_ptr<Pregled> pregled;
    Vrijeme v {sati_pregleda, minute_pregleda};
    Datum d {dan_pregleda, mjesec_pregleda, godina_pregleda};
    pregled = std::make_shared<Pregled>(ime_pacijenta, d, v);
    RegistrirajPregled(pregled);
    
}

Pregled Pregledi::DajNajranijiPregled() const
{
    return **(std::min_element(PokPregled.begin(), PokPregled.end(), [](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2)
    {
        int datum1 = std::get<0>(p1->DajDatumPregleda().Ocitaj()) + std::get<1>(p1->DajDatumPregleda().Ocitaj())*100 + std::get<2>(p1->DajDatumPregleda().Ocitaj())*1000;
        int datum2 = std::get<0>(p2->DajDatumPregleda().Ocitaj()) + std::get<1>(p2->DajDatumPregleda().Ocitaj())*100 + std::get<2>(p2->DajDatumPregleda().Ocitaj())*1000;
        int vrijeme1 = p1->DajVrijemePregleda().Ocitaj().second*60 + p1->DajVrijemePregleda().Ocitaj().first*3600;
        int vrijeme2 = p2->DajVrijemePregleda().Ocitaj().second*60 + p2->DajVrijemePregleda().Ocitaj().first*3600;
        if(datum1 < datum2)
            return true;
        else if(datum1 == datum2 && vrijeme1 < vrijeme2)
            return true;
        return false;
    }));
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const 
{
    return std::count_if(PokPregled.begin(), PokPregled.end(), [&datum](std::shared_ptr<Pregled> pregledi)
    {
       Datum dat(pregledi->DajDatumPregleda());
       if(std::get<0>(dat.Ocitaj()) == std::get<0>(datum.Ocitaj()) && std::get<1>(dat.Ocitaj()) == std::get<1>(datum.Ocitaj()) && std::get<2>(dat.Ocitaj()) == std::get<2>(datum.Ocitaj())) return true;
    
            return false;
    });
}

void Pregledi::IsprazniKolekciju()
{
    PokPregled.resize(0);
}

void Pregledi::ObrisiNajranijiPregled()
{
    if(PokPregled.size() == 0) throw std::range_error("Prazna kolekcija");
    /*
    Pregled Brisem = DajNajranijiPregled();
    
    int datum1 = std::get<0>(Brisem.DajDatumPregleda().Ocitaj()) + std::get<1>(Brisem.DajDatumPregleda().Ocitaj())*100 + std::get<2>(Brisem.DajDatumPregleda().Ocitaj())*1000;

        for(int i = 0; i < PokPregled.size(); i++)
        {
            int datum2 = std::get<0>(PokPregled[i]->DajDatumPregleda().Ocitaj()) + std::get<1>(PokPregled[i]->DajDatumPregleda().Ocitaj())*100 + std::get<2>(PokPregled[i]->DajDatumPregleda().Ocitaj())*1000;
            if (datum1 == datum2)
            {
                PokPregled[i] = nullptr;
                PokPregled.resize(PokPregled.size()-1);
            }
        }*/
        
        PokPregled.erase(std::min_element(PokPregled.begin(), PokPregled.end(), [](const std::shared_ptr<Pregled> p1, const std::shared_ptr<Pregled> p2)
        {
            return DolaziPrije(*p1, *p2);
        }));
}

void Pregledi::ObrisiPregledePacijenata(const std::string &ime_pacijenta)
{
    int brojac(0);
    if(PokPregled.size() == 0) return;
    for(int i=0; i<PokPregled.size(); i++)
    {
        if(ime_pacijenta == PokPregled[i]->DajImePacijenta())
        {
            //PokPregled[i] = nullptr;
            //PokPregled.resize(PokPregled.size()-1);
            this->PokPregled.erase(PokPregled.begin()+i);
            i--;
            brojac++;
        }
    }
    std::cout << "Uspjesno obrisano " << brojac << " pregleda" << std::endl;
}

void Pregledi::IspisiPregledeNaDatum(Datum &datum) const
{
    std::vector<std::shared_ptr<Pregled>> v;
    for(int i=0; i<PokPregled.size(); i++)
    {
        if(std::get<0>(PokPregled[i]-> DajDatumPregleda().Ocitaj()) == std::get<0>(datum.Ocitaj()) && std::get<1>(PokPregled[i]->DajDatumPregleda().Ocitaj()) == std::get<1>(datum.Ocitaj()) && std::get<2>(PokPregled[i]->DajDatumPregleda().Ocitaj()) == std::get<2>(datum.Ocitaj()))
            v.emplace_back(PokPregled[i]);
    }
    
    if(v.size() > 0)
    {
        for(int i = 0; i < v.size(); i++)
        {
            for(int j=i; j<v.size()-1; j++)
            {
                int vrijeme2 = v[i]->DajVrijemePregleda().Ocitaj().second*60 + v[i]->DajVrijemePregleda().Ocitaj().first*3600;
                int vrijeme1 = v[j]->DajVrijemePregleda().Ocitaj().second*60 + v[j]->DajVrijemePregleda().Ocitaj().first*3600;
                if(vrijeme1 < vrijeme2)
                {
                   std::swap(*v[i], *v[j]);
                }
            }
        }
        for(int i=0; i<v.size(); i++)
        v[i]->Ispisi();
    }
}

void Pregledi::IspisiSvePreglede() const
{
    for(int i=0; i<PokPregled.size(); i++)
    {
        for(int j=i+1; j<PokPregled.size(); j++)
        {
            long int datum1 = std::get<2>(PokPregled[j]->DajDatumPregleda().Ocitaj())*1000 + std::get<1>(PokPregled[j]->DajDatumPregleda().Ocitaj())*100 + std::get<0>(PokPregled[j]->DajDatumPregleda().Ocitaj());
            int vrijeme2 = PokPregled[i]->DajVrijemePregleda().Ocitaj().second*60 + PokPregled[i]->DajVrijemePregleda().Ocitaj().first*3600;
            long int datum2 = std::get<2>(PokPregled[i]->DajDatumPregleda().Ocitaj())*1000 + std::get<1>(PokPregled[i]->DajDatumPregleda().Ocitaj())*100 + std::get<0>(PokPregled[i]->DajDatumPregleda().Ocitaj());
            int vrijeme1 = PokPregled[j]-> DajVrijemePregleda().Ocitaj().second*60 + PokPregled[j]->DajVrijemePregleda().Ocitaj().first*3600;
            if(datum1 < datum2)
            {
                std::swap(*PokPregled[i], *PokPregled[j]);
            }
            else if(datum1 == datum2 && vrijeme1 < vrijeme2)
            {
                std::swap(*PokPregled[i], *PokPregled[j]);
            }
        }
    }
    for(int i = 0; i < PokPregled.size(); i++)
        PokPregled[i]->Ispisi();
}


int main ()
{
    int opcija;
    
   // std::cout << "Unesite maksimalan broj pregleda: ";
    //std::cin >> br_pregleda;
    
    Pregledi pregledi;
    
    for(;;)
    {
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        
        std::cin >> ime;
        
        if(ime == "kraj") break;
        
        
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int d, m, g;
        std::cin >> d >> m >> g;
        
        
        std::cout << "Unesite sate i minute pregleda: ";
        int sat, minut;
        
        std::cin >> sat >> minut;
        
        pregledi.RegistrirajPregled(ime, d, m, g, sat, minut);
        
    }
    
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    
    pregledi.IspisiSvePreglede();
    std::cout << std::endl;
    
    
    
    for(;;)
    {
        std::cout << std::endl << "Odaberite jednu od sljedecih opcija" << std::endl;
        std::cout << "1 - Broj pregleda na datum" << std::endl;
        std::cout << "2 - Najraniji pregled" << std::endl;
        std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
        std::cout << "4 - Obrisi najraniji pregled" << std::endl;
        std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
        std::cout << "6 - Ispisi sve preglede" << std::endl;
        std::cout << "7 - Kraj programa" << std::endl;
        
        std::cin >> opcija;
        
        if(opcija == 1)
        {
            //Datum dat;
            int d, m, g;
            std::cout << "Unesite dan mjesec i godinu : ";
            std::cin >> d >> m >> g;
            
            Datum dat(d, m, g);
           // dat.Postavi(d, m, g);
            
            std::cout << "Broj pregleda na datum " << d << " " << m << " " << g << " je: " << pregledi.DajBrojPregledaNaDatum(dat) << std::endl;
        }
        else if(opcija == 2)
        {
            std::cout << "Najraniji pregled je: " << std::endl;
            Pregled pr = pregledi.DajNajranijiPregled();
            pr.Ispisi();
            std::cout << std::endl;
        }
        else if(opcija == 3)
        {
            std::cout << "Unesite ime pacijenta: ";
            std::string ime;
            
            std::cin >> ime;
            
            pregledi.ObrisiPregledePacijenata(ime);
            
        }
        else if(opcija == 4)
        {
           pregledi.ObrisiNajranijiPregled();
            std::cout << "Najraniji pregled uspjesno obrisan" << std::endl; 
        }
        else if(opcija == 5)
        {
           // Datum dat;
            int d, m, g;
            
            std::cout << "Unesite dan mjesec i godinu : ";
            std::cin >> d >> m >> g;
            
            Datum dat(d, m, g);
            
            std::cout << "Pregledi na datum " << d << " " << m << " " << g << " su: " << std::endl;
            pregledi.IspisiPregledeNaDatum(dat);
        }
        else if(opcija == 6)
        {
            pregledi.IspisiSvePreglede();
        }
        else if(opcija == 7)
        {
            return 0;
        }
    }
	return 0;
}
