#include <iostream>
#include <stdexcept>
#include <tuple>
#include <iomanip>
#include <string>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>

class Datum
{
    int dan, mjesec, godina;

public:
    Datum (int dan, int mjesec, int godina) { Postavi (dan, mjesec, godina); }
    
    void Postavi (int dan, int mjesec, int godina); 
    
    std::tuple<int, int, int> Ocitaj() const {  return std::make_tuple (dan,mjesec,godina); }
    
    void Ispisi() const { std::cout<<dan<<"/"<<mjesec<<"/"<<godina; }
};

class Vrijeme
{
    int sati, minute;
    public:
    Vrijeme(int sati, int minute){ Postavi(sati, minute);}
    void Postavi(int sati, int minute);
    std::pair<int, int> Ocitaj() const{ return {sati,minute};}
    void Ispisi() const{ 
        if(sati < 10) std::cout<< "0";
        std::cout<< sati;
        std::cout<<":";
        if(minute < 10) std::cout<< "0";
        std::cout<< minute;
    }
        //std::cout<<std::setfill('0')<<std::setw(2)<<sati<<":"<<std::setw(2)<<minute<<std::setfill(' ');}
};

void Datum::Postavi(int dan, int mjesec, int godina)
{
    int brojdana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0)) brojdana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > brojdana[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}
void Vrijeme::Postavi(int sati, int minute){
    if(sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati = sati;
    Vrijeme::minute = minute;
}
class Pregled{
    std::string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
    static int numofdays(int mjesec, int godina);
  
    public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda){}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime_pacijenta(ime_pacijenta),
    datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda){}
    void PromijeniPacijenta(const std::string &ime_pacijenta){ Pregled::ime_pacijenta = ime_pacijenta;}
    void PromijeniDatum (const Datum &novi_datum){ datum_pregleda = novi_datum; } 
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme){ vrijeme_pregleda = novo_vrijeme;}
    
    void PomjeriDanUnaprijed(){ 
        auto pom = datum_pregleda.Ocitaj(); 
        std::get<0>(pom)++; 
        if(std::get<0>(pom) > numofdays(std::get<1>(pom), std::get<2>(pom))){ std::get<0>(pom) = 1; std::get<1>(pom) ++;}
        if(std::get<1>(pom) > 12){ std::get<1>(pom) = 1; std::get<2>(pom) ++;}
        datum_pregleda.Postavi(std::get<0>(pom),std::get<1>(pom), std::get<2>(pom));}
        
    void PomjeriDanUnazad(){ 
        auto pom = datum_pregleda.Ocitaj();
        std::get<0>(pom)--;
        if(std::get<0>(pom) < 1) {
            std::get<1>(pom)--;
            if(std::get<1>(pom) < 1) {
                std::get<1>(pom) = 12;
                std::get<2>(pom)--;
            }
            std::get<0>(pom) = numofdays(std::get<1>(pom), std::get<2>(pom));
        }
        datum_pregleda.Postavi(std::get<0>(pom), std::get<1>(pom), std::get<2>(pom));
    }
        
    std::string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const{ return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const{ return vrijeme_pregleda; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const{ std::cout<<std::left<<std::setw(30)<<DajImePacijenta()<<std::left;
    datum_pregleda.Ispisi();
    std::cout<<" ";
    vrijeme_pregleda.Ispisi();
    std::cout<<std::endl;}
};

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    auto prvi(p1.DajDatumPregleda().Ocitaj()), drugi(p2.DajDatumPregleda().Ocitaj());
    if(std::get<2>(prvi) < std::get<2>(drugi)) return true;
    else if(std::get<2>(prvi) == std::get<2>(drugi)) {
        if(std::get<1>(prvi) < std::get<1>(drugi)) return true;
        else if(std::get<1>(prvi) == std::get<1>(drugi)) {
            if(std::get<0>(prvi) < std::get<0>(drugi)) return true;
            else if(std::get<0>(prvi) == std::get<0>(drugi)) {
                auto vrijemePrvog(p1.DajVrijemePregleda().Ocitaj()), vrijemeDrugog(p2.DajVrijemePregleda().Ocitaj());
                if(vrijemePrvog.first < vrijemeDrugog.first) return true;
                else if(vrijemePrvog.first == vrijemeDrugog.first) {
                    if(vrijemePrvog.second < vrijemeDrugog.second) return true;
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
    }
    return false;
}

int Pregled::numofdays(int mjesec, int godina){
    int brojdana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && (godina % 100 != 0 || godina % 400 == 0))
    brojdana[1]++;
    return brojdana[mjesec-1];
}
class Pregledi{
    std::vector<std::shared_ptr<Pregled>>pregledi;
    
    public:
    
    explicit Pregledi() = default; 
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator = (const Pregledi &pregledi);
    Pregledi &operator = (Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda );
    void RegistrirajPregled(std::shared_ptr<Pregled>pregled);
    int DajBrojPregleda()const{ 
        int brojac (0);
        for(int i = 0; i < pregledi.size(); i++)
        if(pregledi[i] != nullptr) brojac++;
        return brojac;}
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenata(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : pregledi(spisak_pregleda.size()){

   int i = 0;
    for(auto it = spisak_pregleda.begin(); it != spisak_pregleda.end(); it++){
            pregledi[i] = std::make_shared<Pregled>(*it);
            i++;
    }
}

//kopirajuci konstruktor
Pregledi::Pregledi(const Pregledi &pregledi) : pregledi(pregledi.pregledi.size()){
        for(int i = 0; i < pregledi.pregledi.size(); i++)
        Pregledi::pregledi[i] = std::make_shared<Pregled>(*pregledi.pregledi[i]);
}

//pomjerajuci kopirajuci konstr
Pregledi::Pregledi(Pregledi &&pregledi) = default;

//kopirajuci operator dodjele
Pregledi &Pregledi::operator = (const Pregledi &pregledi){
    if(this == &pregledi) return *this;
   Pregledi::pregledi.resize(pregledi.pregledi.size());
   for( int i = 0 ; i < pregledi.pregledi.size(); i++)
   Pregledi::pregledi[i] = std::make_shared<Pregled>(*pregledi.pregledi[i]);
   return *this;
}

//pomjerajuci operator dodjele
Pregledi &Pregledi::operator = (Pregledi &&pregledi) = default;

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    std::shared_ptr<Pregled>pregled;
        
        pregled = std::make_shared<Pregled>(ime_pacijenta, datum_pregleda, vrijeme_pregleda);

        pregledi.push_back(pregled);
    }

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda ){
    std::shared_ptr<Pregled>pregled;
    
        pregled = std::make_shared<Pregled>(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
        pregledi.push_back(pregled);
    }

void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled){
    pregledi.push_back(pregled);
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    return std::count_if(pregledi.begin(), pregledi.end(), [datum](const std::shared_ptr<Pregled> p){
        auto prvi(datum.Ocitaj()), drugi(p->DajDatumPregleda().Ocitaj());
        return std::get<0>(prvi) == std::get<0>(drugi) && std::get<1>(prvi) == std::get<1>(drugi) && std::get<2>(prvi) == std::get<2>(drugi);
    });
}

Pregled& Pregledi::DajNajranijiPregled(){
    if((*this).DajBrojPregleda() == 0) throw std::domain_error("Nema registriranih pregleda");
    if(this->DajBrojPregleda() == 1) {
        for(int i(0); i < this->pregledi.size(); i++) {
            if(pregledi[i] != nullptr) return *pregledi[i];
        }
    }
    auto min = std::min_element(pregledi.begin(), pregledi.end(), [](const std::shared_ptr<Pregled> p, const std::shared_ptr<Pregled> p2){
        if( p != nullptr && p2 != nullptr){
        auto prvi(p->DajDatumPregleda().Ocitaj()), drugi(p2->DajDatumPregleda().Ocitaj());
            if(std::get<2>(prvi) < std::get<2>(drugi)) return true;
            else if(std::get<2>(prvi) == std::get<2>(drugi)) {
                if(std::get<1>(prvi) < std::get<1>(drugi)) return true;
                else if(std::get<1>(prvi) == std::get<1>(drugi)) {
                    if(std::get<0>(prvi) < std::get<0>(drugi)) return true;
                    else if(std::get<0>(prvi) == std::get<0>(drugi)) {
                        auto vrijemePrvog(p->DajVrijemePregleda().Ocitaj()), vrijemeDrugog(p2->DajVrijemePregleda().Ocitaj());
                        if(vrijemePrvog.first < vrijemeDrugog.first) return true;
                        else if(vrijemePrvog.first == vrijemeDrugog.first) {
                            if(vrijemePrvog.second < vrijemeDrugog.second) return true;
                                return false;
                            }
                            return false;
                        }
                        return false;
                    }
                     return false;
                    }
                    return false;
                }
        else if(p != nullptr && p2 == nullptr) return true;
        return false;
    });
    return *(*min);
}

Pregled Pregledi::DajNajranijiPregled() const {
    if((*this).DajBrojPregleda() == 0) throw std::domain_error("Nema registriranih pregleda");
    if(this->DajBrojPregleda() == 1) {
        for(int i(0); i < this->pregledi.size(); i++) {
            if(pregledi[i] != nullptr) return *pregledi[i];
        }
    }
    auto min = std::min_element(pregledi.begin(), pregledi.end(), [](const std::shared_ptr<Pregled>p, const std::shared_ptr<Pregled>p2){
        if( p != nullptr && p2 !=nullptr){
            auto prvi(p->DajDatumPregleda().Ocitaj()), drugi(p2->DajDatumPregleda().Ocitaj());
            if(std::get<2>(prvi) < std::get<2>(drugi)) return true;
            else if(std::get<2>(prvi) == std::get<2>(drugi)){
                if(std::get<1>(prvi) < std::get<1>(drugi)) return true;
                else if(std::get<1>(prvi) == std::get<1>(drugi)){
                    if(std::get<0>(prvi) < std::get<0>(drugi)) return true;
                    else if(std::get<0>(prvi) == std::get<0>(drugi)){
                        auto vrijemePrvog(p->DajVrijemePregleda().Ocitaj()), vrijemeDrugog(p2->DajVrijemePregleda().Ocitaj());
                        if(vrijemePrvog.first < vrijemeDrugog.first) return true;
                        else if(vrijemePrvog.first == vrijemeDrugog.first){
                            if(vrijemePrvog.second < vrijemeDrugog.second) return true;
                            return false;
                        }
                      return false;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        else if(p != nullptr && p2 == nullptr) return true;
        return false;
    });
    return *(*min);
}

void Pregledi::IsprazniKolekciju(){
    /*for(int i = 0; i < pregledi.size(); i++){
       // delete pregledi[i] ;
       pregledi[i] = nullptr;
    }*/
    pregledi.resize(0);
}

void Pregledi::ObrisiNajranijiPregled(){
    if((*this).DajBrojPregleda() == 0) throw std::range_error("Prazna kolekcija");
    Pregled p = DajNajranijiPregled();
    for(int i = 0; i < pregledi.size(); i++) {
        if(pregledi[i] == nullptr) continue;
        if(pregledi[i]->DajImePacijenta() == p.DajImePacijenta()) {
            auto prviDatum(pregledi[i]->DajDatumPregleda().Ocitaj()), drugiDatum(p.DajDatumPregleda().Ocitaj());
            auto prvoVrijeme(pregledi[i]->DajVrijemePregleda().Ocitaj()), drugoVrijeme(p.DajVrijemePregleda().Ocitaj());
            if(std::get<0>(prviDatum) == std::get<0>(drugiDatum) && std::get<1>(prviDatum) == std::get<1>(drugiDatum) && std::get<2>(prviDatum) == std::get<2>(drugiDatum) && prvoVrijeme.first == drugoVrijeme.first && prvoVrijeme.second == drugoVrijeme.second) {
                //delete pregledi[i];
               //pregledi[i] = nullptr;
               pregledi.erase(pregledi.begin() + i);
               i--;
            }
        }
    }
}

void Pregledi::ObrisiPregledePacijenata(const std::string &ime_pacijenta) {
    for(int i = 0; i < pregledi.size(); i++) {
        if(pregledi[i] == nullptr) continue;
        if(pregledi[i]->DajImePacijenta() == ime_pacijenta) {
            //delete pregledi[i];
            //pregledi[i] = nullptr;
            pregledi.erase(pregledi.begin() + i);
            i--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &d) const {
    std::vector<Pregled> preglediNaDatum;
    for(int i = 0; i < pregledi.size(); i++) {
        if(pregledi[i] == nullptr) continue;
        auto prviDatum(pregledi[i]->DajDatumPregleda().Ocitaj()), drugiDatum(d.Ocitaj());
        if(std::get<0>(prviDatum) == std::get<0>(drugiDatum) && std::get<1>(prviDatum) == std::get<1>(drugiDatum) && std::get<2>(prviDatum) == std::get<2>(drugiDatum)) {
            preglediNaDatum.push_back(*pregledi[i]);
        }
    }
    std::sort(preglediNaDatum.begin(), preglediNaDatum.end(), Pregled::DolaziPrije);
    for(int i = 0; i < preglediNaDatum.size(); i++) {
        preglediNaDatum[i].Ispisi();
    }
}

void Pregledi::IspisiSvePreglede() const {
    std::vector<Pregled> sviPregledi;
    for (int i = 0; i < pregledi.size(); i++){
        if(pregledi[i] == nullptr) continue;
        sviPregledi.push_back(*pregledi[i]);
    }
    std::sort(sviPregledi.begin(), sviPregledi.end(), Pregled::DolaziPrije);
    for(int i = 0; i < sviPregledi.size(); i++) {
        sviPregledi[i].Ispisi();
    }
}

int main ()
{
   try{
        Pregledi pregledi;
        std::string ime ;
        while(ime != "kraj"){
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::getline(std::cin, ime);
        if(ime == "kraj") break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        int dan, mjesec, godina;
        std::cin >> dan >> mjesec >> godina;
        std::cout << "Unesite sate i minute pregleda: ";
        int sati, minute;
        std::cin >> sati >> minute;
        pregledi.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);
        std::cin.ignore(10000, '\n');
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    pregledi.IspisiSvePreglede();
    std::cout << std::endl;
    int izbor(0);
    while(izbor != 7) {
        std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
        std::cout << "1 - Broj pregleda na datum" << std::endl;
        std::cout << "2 - Najraniji pregled" << std::endl;
        std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
        std::cout << "4 - Obrisi najraniji pregled" << std::endl;
        std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
        std::cout << "6 - Ispisi sve preglede" << std::endl;
        std::cout << "7 - Kraj programa" << std::endl;
        std::cin >> izbor;
        if(izbor == 1) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int dan, mjesec, godina;
            std::cin >> dan >> mjesec >> godina;
            Datum d(dan, mjesec, godina);
            std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina << " je: " << pregledi.DajBrojPregledaNaDatum(d) << std::endl;
        }
        else if(izbor == 2) {
            std::cout << "Najraniji pregled je:" << std::endl;
            pregledi.DajNajranijiPregled().Ispisi();
            std::cout << std::endl;
        }
        else if(izbor == 3) {
            std::cout << "Unesite ime pacijenta: ";
            std::cin.ignore(10000, '\n');
            std::string ime_pacijenta;
            std::getline(std::cin, ime_pacijenta);
            int broj_pregleda = pregledi.DajBrojPregleda();
            pregledi.ObrisiPregledePacijenata(ime_pacijenta);
            int novi_broj_pregleda = pregledi.DajBrojPregleda();
            std::cout << "Uspjesno obrisano " << broj_pregleda - novi_broj_pregleda << " pregleda" << std::endl;
        }
        else if(izbor == 4) {
            pregledi.ObrisiNajranijiPregled();
            std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
        }
        else if(izbor == 5) {
            std::cout << "Unesite dan mjesec i godinu : ";
            int dan, mjesec, godina;
            std::cin >> dan >> mjesec >> godina;
            Datum d(dan, mjesec, godina);
            std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:" << std::endl;
            pregledi.IspisiPregledeNaDatum(d);
        }
        else if(izbor == 6) {
            pregledi.IspisiSvePreglede();
        }
        std::cout << std::endl;
    }
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    catch(std::range_error e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}