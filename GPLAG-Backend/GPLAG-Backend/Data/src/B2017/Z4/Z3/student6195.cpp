/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <algorithm>
#include <initializer_list>
#include <iterator>

class Datum {
    int dan, mjesec, godina;
    public:
      Datum (int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
      void Postavi (int dan, int mjesec, int godina);
      std::tuple<int, int, int> Ocitaj () const;
      void Ispisi() const;
};

void Datum::Postavi (int dan, int mjesec, int godina) {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec-1]) throw std::domain_error("Neispravan datum");
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

std::tuple<int, int, int> Datum::Ocitaj () const {
    return std::make_tuple (dan, mjesec, godina);
}

void Datum::Ispisi () const {
    std::cout<<""<<dan<<"/"<<mjesec<<"/"<<godina;
}

class Vrijeme {
    int sati, minute;
    public: 
      Vrijeme (int sati, int minute) { Postavi(sati, minute); }
      void Postavi (int sati, int minute);
      std::pair<int, int> Ocitaj () const;
      void Ispisi () const;
};

void Vrijeme::Postavi (int sati, int minute) {
    if(sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
    Vrijeme::sati = sati;
    Vrijeme::minute = minute;
}

std::pair<int, int> Vrijeme:: Ocitaj () const {
    return std::make_pair(sati, minute);  
}

void Vrijeme::Ispisi () const {
    if(sati < 10) std::cout<<"0"<<sati<<":";
    else if(sati >= 10) std::cout<<sati<<":";
    if(minute < 10) std::cout<<"0"<<minute;
    else if(minute >= 10) std::cout<<minute;
}

class Pregled {
      std::string ime_pacijenta;
      Datum datum;
      Vrijeme vrijeme;
      public:
        Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
        Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
        void PromijeniPacijenta (const std::string &ime_pacijenta) { Pregled::ime_pacijenta = ime_pacijenta; }
        void PromijeniDatum (const Datum &novi_datum) { datum = novi_datum; }
        void PromijeniVrijeme (const Vrijeme &novo_vrijeme) { vrijeme = novo_vrijeme; }
        void PomjeriDanUnaprijed ();
        void PomjeriDanUnazad ();
        std::string DajImePacijenta () const { return ime_pacijenta; }
        Datum DajDatumPregleda () const { return datum; }
        Vrijeme DajVrijemePregleda () const {return vrijeme; }
        static bool DolaziPrije (const Pregled &p1, const Pregled &p2);
        void Ispisi () const;
};

Pregled::Pregled (const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta), datum(datum_pregleda), vrijeme(vrijeme_pregleda) { }

Pregled::Pregled (const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime_pacijenta(ime_pacijenta), datum(Datum(dan_pregleda, mjesec_pregleda, godina_pregleda)), vrijeme(Vrijeme(sati_pregleda, minute_pregleda)) { }

void Pregled::PomjeriDanUnaprijed () {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::tuple<int, int, int> dat = datum.Ocitaj();
    std::get<0>(dat)++;
    if(std::get<0>(dat) > broj_dana[std::get<1>(dat) - 1]) std::get<0>(dat) = 1; std::get<1>(dat)++;
    if(std::get<1>(dat) > 12) std::get<1>(dat) = 1; std::get<2>(dat)++;
}

void Pregled::PomjeriDanUnazad () {
    int broj_dana[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::tuple<int, int, int> dat = datum.Ocitaj();
    std::get<0>(dat)--;
    if(std::get<0>(dat) < 1 && std::get<1>(dat) == 1) std::get<0>(dat) = broj_dana[11]; 
    else if(std::get<0>(dat) < 1) std::get<0>(dat) = broj_dana[std::get<1>(dat) - 1]; std::get<1>(dat)--;
    if(std::get<1>(dat) < 1) std::get<1>(dat) = 12; std::get<2>(dat)--;
}

bool Pregled::DolaziPrije (const Pregled &p1, const Pregled &p2) {
    std::tuple<int, int, int> date_first(p1.datum.Ocitaj());
    std::tuple<int, int, int> date_second(p2.datum.Ocitaj());
    std::pair<int, int> time_first(p1.vrijeme.Ocitaj());
    std::pair<int, int> time_second(p2.vrijeme.Ocitaj());
    if(std::get<2>(date_first) > std::get<2>(date_second)) return false;
    else if(std::get<2>(date_first) == std::get<2>(date_second) && std::get<1>(date_first) > std::get<1>(date_second)) return false;
    else if(std::get<2>(date_first) == std::get<2>(date_second) && std::get<1>(date_first) == std::get<1>(date_second) && std::get<0>(date_first) > std::get<0>(date_second)) return false;
    else if(std::get<2>(date_first) == std::get<2>(date_second) && std::get<1>(date_first) == std::get<1>(date_second) && std::get<0>(date_first) == std::get<0>(date_second) && time_first.first > time_second.first) return false;
    else if(std::get<2>(date_first) == std::get<2>(date_second) && std::get<1>(date_first) == std::get<1>(date_second) && std::get<0>(date_first) == std::get<0>(date_second) && time_first.first == time_second.first && time_first.second > time_second.second) return false;
    return true;
}

void Pregled::Ispisi () const {
    std::cout<<std::left<<std::setw(30)<<ime_pacijenta<<std::right;datum.Ispisi();std::cout<<" ";vrijeme.Ispisi();std::cout<<std::endl;
}

class Pregledi {
     int max_broj_pregleda;
    int broj_pregleda;
    Pregled **izvrseni_pregledi;
    public:
      explicit Pregledi (int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda), broj_pregleda(0), izvrseni_pregledi(new Pregled*[max_broj_pregleda]{}){ }
      Pregledi (std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()), izvrseni_pregledi(new Pregled*[spisak_pregleda.size()]{}) {
          int i(0);
          for(auto it(spisak_pregleda.begin()); it != spisak_pregleda.end(); it++) {
              izvrseni_pregledi[i] = new Pregled(Pregled(*it));
              i++;
          }
      }
      ~Pregledi () {
          for(int i(0); i < max_broj_pregleda; i++) delete izvrseni_pregledi[i];
          delete []izvrseni_pregledi;
      }
      Pregledi (const Pregledi &pregledi);
      Pregledi (Pregledi &&pregledi);
      Pregledi &operator = (const Pregledi &pregledi);
      Pregledi &operator = (Pregledi &&pregledi);
      void RegistrirajPregled (std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
      void RegistrirajPregled (std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
      void RegistrirajPregled (Pregled *pregled);
      int DajBrojPregleda () const {return broj_pregleda;}
      int DajBrojPregledaNaDatum (const Datum &datum) const;
      Pregled &DajNajranijiPregled ();
      Pregled DajNajranijiPregled () const;
      void IsprazniKolekciju ();
      void ObrisiNajranijiPregled ();
      void ObrisiPregledePacijenta (const std::string &ime_pacijenta);
      void IspisiPregledeNaDatum (const Datum &datum) const;
      void IspisiSvePreglede () const;
};

Pregledi::Pregledi (const Pregledi &pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda), izvrseni_pregledi(new Pregled*[pregledi.max_broj_pregleda]{}) {
    try{
        for(int i(0); i < pregledi.broj_pregleda; i++)  izvrseni_pregledi[i] = new Pregled (*pregledi.izvrseni_pregledi[i]);
    }catch(...){
        for(int i(0); i < pregledi.broj_pregleda; i++) delete izvrseni_pregledi[i];
        delete []izvrseni_pregledi;
        throw;
    }
}

Pregledi::Pregledi(Pregledi &&pregledi) : izvrseni_pregledi(pregledi.izvrseni_pregledi), max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda) {
    pregledi.izvrseni_pregledi = nullptr;
    pregledi.broj_pregleda = 0;
    pregledi.max_broj_pregleda=0;
}   

Pregledi &Pregledi::operator = (const Pregledi &pregledi) {
    if(pregledi.broj_pregleda > broj_pregleda) {
        try{
            for(int i(broj_pregleda); i < pregledi.broj_pregleda; i++) izvrseni_pregledi[i] = new Pregled(*pregledi.izvrseni_pregledi[i]);
        }catch(...){
            for(int i(broj_pregleda); i < pregledi.broj_pregleda; i++) {
                delete izvrseni_pregledi[i];
                izvrseni_pregledi[i] = nullptr;
            }
            throw;
        }
    }else{
        for(int i(pregledi.broj_pregleda); i < broj_pregleda; i++) {
            delete izvrseni_pregledi[i];
            izvrseni_pregledi[i] = nullptr;
        }
    }
    broj_pregleda = pregledi.broj_pregleda;
    for(int i(0); i < broj_pregleda; i++) *izvrseni_pregledi[i] = *pregledi.izvrseni_pregledi[i];
    return *this;
}

Pregledi &Pregledi::operator = (Pregledi &&pregledi) {
    std::swap(broj_pregleda, pregledi.broj_pregleda);
    std::swap(izvrseni_pregledi, pregledi.izvrseni_pregledi);
    return *this;
}

void Pregledi::RegistrirajPregled (std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if(max_broj_pregleda <= broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    izvrseni_pregledi[broj_pregleda++] = new Pregled(Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda)); 
}

void Pregledi::RegistrirajPregled (std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    if(max_broj_pregleda <= broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    izvrseni_pregledi[broj_pregleda++] = new Pregled(Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda)); 
}

void Pregledi::RegistrirajPregled (Pregled *pregled) {
    if(max_broj_pregleda <= broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    izvrseni_pregledi[broj_pregleda++] = pregled;
}

int Pregledi::DajBrojPregledaNaDatum (const Datum &datum) const {
    int broj = std::count_if(izvrseni_pregledi, izvrseni_pregledi+broj_pregleda, [datum](Pregled *p) {
        return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj();
    });
    return broj;
}

Pregled &Pregledi::DajNajranijiPregled () {
    if(broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    return(**std::min_element(izvrseni_pregledi, izvrseni_pregledi+broj_pregleda, [] (Pregled *p1, Pregled *p2) {
        return Pregled::DolaziPrije(*p1, *p2);
    }));
}

Pregled Pregledi::DajNajranijiPregled () const {
    if(broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    return(**std::min_element(izvrseni_pregledi, izvrseni_pregledi+broj_pregleda, [] (Pregled *pregled1, Pregled *pregled2) {
        return Pregled::DolaziPrije(*pregled1, *pregled2);
    }));
}

void Pregledi::IsprazniKolekciju () {
    for(int i(0); i < broj_pregleda; i++) { 
        delete izvrseni_pregledi[i];
        izvrseni_pregledi[i] = nullptr;
    }
    broj_pregleda = 0;
}

void Pregledi::ObrisiNajranijiPregled () {
    if(broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    auto it(std::min_element(izvrseni_pregledi, izvrseni_pregledi+broj_pregleda, [] (Pregled* p1,Pregled*p2) { return Pregled::DolaziPrije(*p1,*p2);}));
    std::copy(it+1,izvrseni_pregledi+broj_pregleda,it);
    delete izvrseni_pregledi[broj_pregleda-1];
    izvrseni_pregledi[broj_pregleda-1]=nullptr;
    broj_pregleda--;
}

void Pregledi::ObrisiPregledePacijenta (const std::string &ime_pacijenta) {
    if(broj_pregleda == 0) throw std::range_error("Prazna kolekcija");
    for(int i(0); i < broj_pregleda; i++) {
        if(izvrseni_pregledi[i]->DajImePacijenta() == ime_pacijenta) {
            delete izvrseni_pregledi[i];
            izvrseni_pregledi[i] = nullptr;
            for(int j(i); j < broj_pregleda-1; j++) izvrseni_pregledi[j] = izvrseni_pregledi[j+1];
            i--;
            broj_pregleda--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum (const Datum &datum) const {
    int velicina(0);
    
     if(broj_pregleda!=0){  
        Pregled** ispisni = new Pregled*[broj_pregleda]{};
        try{
            for(int i(0); i < broj_pregleda; i++) {
                
                if(izvrseni_pregledi[i]->DajDatumPregleda().Ocitaj() == datum.Ocitaj()) {
                    ispisni[i] = new Pregled(*izvrseni_pregledi[i]);
                    int a(i);
                    while (a>0 && ispisni[a-1]==nullptr) {
                        ispisni[a-1]=ispisni[a];
                        a--;
                    }
                     velicina++;
                }       
            }
        }catch(...){
            for(int i(0); i < velicina; i++) {
                delete ispisni[i];
                ispisni[i] = nullptr;
            }
            delete [] ispisni;
            throw;
        }
        std::sort(ispisni, ispisni+velicina, [](Pregled *p1, Pregled *p2) {
            return Pregled::DolaziPrije(*p1,*p2);});
        for(int i(0); i < velicina; i++) (ispisni[i])->Ispisi();
        for(int i(0); i < broj_pregleda; i++) delete ispisni[i];
        delete []ispisni;
     }
}

void Pregledi::IspisiSvePreglede () const {
    if(broj_pregleda!=0){
        Pregled **ispisni = new Pregled*[broj_pregleda]{};
        try{
            for(int i(0); i < broj_pregleda; i++) ispisni[i] = new Pregled(*izvrseni_pregledi[i]);
        }catch(...){
            for(int i(0); i < broj_pregleda; i++) {
                delete ispisni[i];
                ispisni[i] = nullptr;
            }
            delete[] ispisni;
            throw;
        }
       
        std::sort(ispisni, ispisni+broj_pregleda, [](Pregled *p1, Pregled *p2) {
            return Pregled::DolaziPrije(*p1,*p2);});
        for(int i(0); i < broj_pregleda; i++) ispisni[i]->Ispisi();
        for(int i(0); i < broj_pregleda; i++) delete ispisni[i];
        delete []ispisni;
    }
}

int main ()
{
    int maksimalan_broj_pregleda;
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>maksimalan_broj_pregleda;
    Pregledi pregledi(maksimalan_broj_pregleda);
    for(int i(0); i < maksimalan_broj_pregleda; i++) {
        std::cin.ignore(10000,'\n');
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        std::string ime;
        std::getline(std::cin, ime);
        if(ime == "kraj") break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int dan, mjesec, godina;
        std::cin>>dan>>mjesec>>godina;
        std::cout<<"Unesite sate i minute pregleda: ";
	    int sati, minute;
	    std::cin>>sati>>minute;
	    try{
	        pregledi.RegistrirajPregled(ime, dan, mjesec, godina, sati, minute);
	    }catch(std::range_error e) {
	        std::cout<<e.what()<<std::endl;
	        i--;
	    }
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi:"<<std::endl;
    pregledi.IspisiSvePreglede();
    std::cout<<std::endl;
    int option;
    do{
        std::cout<<"Odaberite jednu od sljedecih opcija"<<std::endl;
        std::cout<<"1 - Broj pregleda na datum"<<std::endl;
        std::cout<<"2 - Najraniji pregled"<<std::endl;
        std::cout<<"3 - Obrisi pregled pacijenta"<<std::endl;
        std::cout<<"4 - Obrisi najraniji pregled"<<std::endl;
        std::cout<<"5 - Ispisi sve pregleda na datum"<<std::endl;
        std::cout<<"6 - Ispisi sve preglede"<<std::endl;
        std::cout<<"7 - Kraj programa"<<std::endl;
        std::cin>>option;
        if(option == 1) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int dan, mjesec, godina;
            std::cin>>dan>>mjesec>>godina;
            std::cout<<"Broj pregleda na datum "<<dan<<" "<<mjesec<<" "<<godina<<" je: "<<pregledi.DajBrojPregledaNaDatum(Datum(dan, mjesec, godina));
            std::cout<<std::endl;
        }
        else if(option == 2) {
            std::cout<<"Najraniji pregled je:"<<std::endl;
            pregledi.IspisiPregledeNaDatum(pregledi.DajNajranijiPregled().DajDatumPregleda());
            std::cout<<std::endl;
        }
        else if(option == 3) {
            int broj_pregleda(pregledi.DajBrojPregleda());
            std::string ime_pacijenta;
            std::cout<<"Unesite ime pacijenta: ";
            std::getline(std::cin, ime_pacijenta);
            try{
                pregledi.ObrisiPregledePacijenta(ime_pacijenta);
            }catch(std::range_error e){
                std::cout<<e.what()<<std::endl;
            }
            std::cout<<"Uspjesno obrisano "<<broj_pregleda - pregledi.DajBrojPregleda()<<" pregleda"<<std::endl;
        }
        else if(option == 4) {
            try{
                pregledi.ObrisiNajranijiPregled();
            }catch(std::range_error e){
                std::cout<<e.what()<<std::endl;
            }catch(std::domain_error d){
                std::cout<<d.what()<<std::endl;
            }
            std::cout<<"Najraniji pregled uspjesno obrisan"<<std::endl;
        }
        else if(option == 5) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int dan, mjesec, godina;
            std::cin>>dan>>mjesec>>godina;
            std::cout<<"Pregledi na datum "<<dan<<" "<<mjesec<<" "<<godina<<" su : "<<std::endl;
            pregledi.IspisiPregledeNaDatum(Datum(dan, mjesec, godina));
            std::cout<<std::endl;
        }
        else if(option == 6) {
            pregledi.IspisiSvePreglede();
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }while(option != 7);
    return 0;
}
