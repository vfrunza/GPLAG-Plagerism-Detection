/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;

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
    vector<shared_ptr<Pregled>> pregledi;
    
    void Add(shared_ptr<Pregled> pregled);
public:
    explicit Pregledi() {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
        Add(std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
        // pregledi.emplace_back(std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda));
    }
    void RegistrirajPregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
        Add(std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
        // pregledi.emplace_back(std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda));
    }
    void RegistrirajPregled(shared_ptr<Pregled> &pregled){
        Add(pregled);
        // pregledi.emplace_back(pregled);
    }
    
    int DajBrojPregleda() const { return pregledi.size(); }
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
    Pregledi p;
    
    //Input
    for(;;){
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

void Pregledi::Add(shared_ptr<Pregled> pregled){
    pregledi.emplace_back(pregled);
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda){
    std::initializer_list<Pregled>::iterator it;
    for(it = spisak_pregleda.begin(); it != spisak_pregleda.end(); it++)
        Add(std::make_shared<Pregled>(*it));
        //pregledi.emplace_back(std::make_shared<Pregled>(*it));
}

Pregledi::Pregledi(const Pregledi &pregledi) {
    for(int i = 0; i < pregledi.pregledi.size(); i++)
        Add(std::make_shared<Pregled>(*pregledi.pregledi[i]));
        //Pregledi::pregledi.emplace_back(std::make_shared<Pregled>(*pregledi.pregledi[i]));
}

Pregledi::Pregledi(Pregledi &&pregledi) : pregledi(std::move(pregledi.pregledi)) {}

Pregledi& Pregledi::operator =(const Pregledi &pregledi){
    if(&pregledi == this) return *this;
    
    Pregledi::pregledi.clear();
    for(int i = 0; i < pregledi.pregledi.size(); i++)
        Add(std::make_shared<Pregled>(*pregledi.pregledi.at(i)));
        //Pregledi::pregledi.emplace_back(std::make_shared<Pregled>(*pregledi.pregledi.at(i)));
    
    return *this;
}

Pregledi& Pregledi::operator =(Pregledi &&pregledi){
    if(&pregledi == this) return *this;
    
    Pregledi::pregledi.clear();
    Pregledi::pregledi = std::move(pregledi.pregledi);
    
    return *this;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return std::count_if(pregledi.begin(), pregledi.end(), [&datum](shared_ptr<Pregled> pregled){
        return datum.Ocitaj() == pregled->DajDatumPregleda().Ocitaj();
    });
}

Pregled& Pregledi::DajNajranijiPregled(){
    vector<shared_ptr<Pregled>>::iterator it = std::min_element(pregledi.begin(), pregledi.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    if(it == pregledi.end())
        throw std::domain_error("Nema registriranih pregleda");
    
    return **it;
}

Pregled Pregledi::DajNajranijiPregled() const {
    vector<shared_ptr<Pregled>>::const_iterator it = std::min_element(pregledi.begin(), pregledi.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    if(it == pregledi.end())
        throw std::domain_error("Nema registriranih pregleda");
    
    return **it;
}

void Pregledi::IsprazniKolekciju(){
    pregledi.clear();
}

void Pregledi::ObrisiNajranijiPregled(){
    if(pregledi.empty())
        throw std::range_error("Prazna kolekcija");
    
    
    // Ne radi !!!!!!!!
    //
    // shared_ptr<Pregled> temp(&DajNajranijiPregled());
    // for(int i = 0; i < pregledi.size(); i++){
    //     if(pregledi.at(i) == temp){
    //         pregledi.erase(pregledi.begin()+i);
    //         break;
    //     }
    // }
    
    Pregled* rawptr = &DajNajranijiPregled();
    
    for(int i = 0; i < pregledi.size(); i++){
        if(pregledi.at(i).get() == rawptr){
            pregledi.erase(pregledi.begin()+i);
            break;
        }
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    for(int i = 0; i < pregledi.size(); i++){
        if(pregledi.at(i)->DajImePacijenta()==ime_pacijenta){
            pregledi.erase(pregledi.begin()+i);
            i--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    vector<shared_ptr<Pregled>> temp(DajBrojPregledaNaDatum(datum));
    
    std::copy_if(pregledi.begin(), pregledi.end(), temp.begin(), [&datum](shared_ptr<Pregled> p){
        return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj();
    });
    
    std::sort(temp.begin(), temp.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    for(int i = 0; i < temp.size(); i++)
        temp.at(i)->Ispisi();
}

void Pregledi::IspisiSvePreglede() const {
    vector<shared_ptr<Pregled>> temp(DajBrojPregleda());
    
    std::copy(pregledi.begin(), pregledi.end(), temp.begin());
    
    std::sort(temp.begin(), temp.end(), [](shared_ptr<Pregled> p1, shared_ptr<Pregled> p2){
        return Pregled::DolaziPrije(*p1, *p2);
    });
    
    for(int i = 0; i < temp.size(); i++)
        temp.at(i)->Ispisi();
}
