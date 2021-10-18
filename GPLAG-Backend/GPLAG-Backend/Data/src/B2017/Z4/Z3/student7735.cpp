#include <iostream>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

class Datum{
  int dan, mjesec, godina;
public:
  Datum(int dan, int mjesec, int godina){ Postavi(dan,mjesec,godina); }
  void Postavi(int dan, int mjesec, int godina);
  std::tuple<int, int, int> Ocitaj() const{ return std::make_tuple(dan,mjesec,godina); }
  void Ispisi() const{ std::cout << dan << "/" << mjesec << "/" << godina; }
};

class Vrijeme{
  int sati,minute;
public:
  Vrijeme(int sati, int minute){ Postavi(sati,minute); }
  void Postavi(int sati, int minute);
  std::pair<int, int> Ocitaj () const{ return std::make_pair(sati,minute); }
  void Ispisi() const;
};

class Pregled{
  std::string ime_pacijenta;
  Datum datum_pregleda;
  Vrijeme vrijeme_pregleda;
public:
  Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
  Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
  void PromijeniPacijenta(const std::string &ime_pacijenta){ Pregled::ime_pacijenta = ime_pacijenta; }
  void PromijeniDatum(const Datum &novi_datum);
  void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
  void PomjeriDanUnaprijed();
  void PomjeriDanUnazad();
  std::string DajImePacijenta() const { return Pregled::ime_pacijenta; }
  Datum DajDatumPregleda() const { return Pregled::datum_pregleda; }
  Vrijeme DajVrijemePregleda() const { return Pregled::vrijeme_pregleda; }
  static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
  void Ispisi() const;  
};

class Pregledi{
  Pregled **svi_pregledi;
  int broj_pregleda;
  int max_pregleda;
public:
  explicit Pregledi(int max_broj_pregleda);
  Pregledi(std::initializer_list<Pregled> spisak_pregleda);
  ~Pregledi();
  Pregledi(const Pregledi &pregledi);
  Pregledi(Pregledi &&pregledi);
  Pregledi &operator =(const Pregledi &pregledi);
  Pregledi &operator =(Pregledi &&pregledi);
  void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
  void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
  void RegistrirajPregled(Pregled *pregled);
  int DajBrojPregleda() const{ return broj_pregleda; }
  int DajBrojPregledaNaDatum(const Datum &datum) const;
  Pregled &DajNajranijiPregled();
  Pregled DajNajranijiPregled() const;
  void IsprazniKolekciju();
  void ObrisiNajranijiPregled();
  void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
  void IspisiPregledeNaDatum(const Datum &datum) const;
  void IspisiSvePreglede() const;
};

void Datum::Postavi(int dan, int mjesec, int godina){
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
    if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1]){
        throw std::domain_error("Neispravan datum");
    }
    Datum::dan = dan;
    Datum::mjesec = mjesec;
    Datum::godina = godina;
}

void Vrijeme::Postavi(int sati, int minute){
    if(sati < 0 || sati > 23 || minute < 0 || minute > 59){
        throw std::domain_error("Neispravno vrijeme");
    }
    Vrijeme::sati = sati;
    Vrijeme::minute = minute;
}

void Vrijeme::Ispisi() const{
    if(Vrijeme::sati < 10) std::cout << "0";
    std::cout << Vrijeme::sati << ":";
    if(Vrijeme::minute < 10) std::cout << "0";
    std::cout << Vrijeme::minute;
}

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
    :datum_pregleda(1,1,1), vrijeme_pregleda(1,1){
    int dan, mjesec, godina, sati, minute;
    Pregled::ime_pacijenta = ime_pacijenta;
    std::tie(dan, mjesec, godina) = datum_pregleda.Ocitaj();
    Pregled::datum_pregleda.Postavi(dan, mjesec, godina);
    std::tie(sati, minute) = vrijeme_pregleda.Ocitaj();
    Pregled::vrijeme_pregleda.Postavi(sati, minute);
}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
    : datum_pregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme_pregleda(sati_pregleda, minute_pregleda) {
    Pregled::ime_pacijenta = ime_pacijenta;
}

void Pregled::PromijeniDatum(const Datum &novi_datum){
    int dan, mjesec, godina;
    std::tie(dan, mjesec, godina) = datum_pregleda.Ocitaj();
    Pregled::datum_pregleda.Postavi(dan, mjesec, godina);
}

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme){
    int sati, minute;
    std::tie(sati, minute) = vrijeme_pregleda.Ocitaj();
    Pregled::vrijeme_pregleda.Postavi(sati, minute);
}

void Pregled::PomjeriDanUnazad(){
    int dan, mjesec, godina;
      int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      std::tie(dan, mjesec, godina) = Pregled::datum_pregleda.Ocitaj();
      dan--;
      if(dan == 0){
          mjesec--;
          if(mjesec == 0){
              mjesec = 12;
              godina--;
          }
          dan = broj_dana[mjesec - 1];
      }
      Pregled::datum_pregleda.Postavi(dan, mjesec, godina);
}

void Pregled::PomjeriDanUnaprijed(){
    int dan, mjesec, godina;
      int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      std::tie(dan, mjesec, godina) = Pregled::datum_pregleda.Ocitaj();
      dan++;
      if(dan > broj_dana[mjesec - 1]) {
          dan = 1;
          mjesec++;
      }
      if(mjesec > 12){
          mjesec = 1;
          godina++;
      }
      Pregled::datum_pregleda.Postavi(dan, mjesec, godina);
}

void Pregled::Ispisi() const{
    std::cout << std::left << std::setw(30) << Pregled::ime_pacijenta;
    Pregled::datum_pregleda.Ispisi();
    std::cout << " ";
    Pregled::vrijeme_pregleda.Ispisi();
    std::cout << std::endl;
}

static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
    int dan1,dan2,mj1,mj2,god1,god2,sat1,sat2,min1,min2;
    std::tie(dan1,mj1,god1) = p1.DajDatumPregleda().Ocitaj();
    std::tie(dan2,mj2,god2) = p2.DajDatumPregleda().Ocitaj();
    std::tie(sat1,min1) = p1.DajVrijemePregleda().Ocitaj();
    std::tie(sat2,min2) = p2.DajVrijemePregleda().Ocitaj();
    if(god1 < god2) return true;
    else if(god1 == god2){
        if(mj1 < mj2) return true;
        else if(mj1 == mj2){
            if(dan1 < dan2) return true;
            else if(dan1 == dan2){
                if(sat1 < sat2) return true;
                else if(sat1 == sat2) return min1 < min2;
                else return false;
            }
            else return false;
        }
        else return false;
    }
    else return false;
    
}

Pregledi::Pregledi(int max_broj_pregleda){
    try{
        svi_pregledi = new Pregled*[max_broj_pregleda]{};
        broj_pregleda = 0;
        max_pregleda = max_broj_pregleda;
    }
    catch(...){
        throw std::bad_alloc();
    }
}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : svi_pregledi(new Pregled*[spisak_pregleda.size()]{}){
    for(int i = 0; i < spisak_pregleda.size(); i++){
        auto it = spisak_pregleda.begin();
        std::string ime_pacijenta = it->DajImePacijenta();
        Datum datum_pregleda = it->DajDatumPregleda();
        Vrijeme vrijeme_pregleda = it->DajVrijemePregleda();
        try{
            svi_pregledi[i] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
            it++;
        }
        catch(...){
            for(int j = 0; j < spisak_pregleda.size(); j++) delete svi_pregledi[j];
            delete[] svi_pregledi;
            throw std::bad_alloc();
        }
    }
    broj_pregleda = spisak_pregleda.size();
    max_pregleda = spisak_pregleda.size();
}

Pregledi::~Pregledi(){
    for(int i = 0; i < broj_pregleda; i++) delete svi_pregledi[i];
    delete[] svi_pregledi;
}

Pregledi::Pregledi(const Pregledi &pregledi){
    svi_pregledi = new Pregled*[pregledi.DajBrojPregleda()];
    for(int i = 0; i < pregledi.broj_pregleda; i++){
        std::string ime_pacijenta = pregledi.svi_pregledi[i]->DajImePacijenta();
        Datum datum_pregleda = pregledi.svi_pregledi[i]->DajDatumPregleda();
        Vrijeme vrijeme_pregleda = pregledi.svi_pregledi[i]->DajVrijemePregleda();
        try{
            svi_pregledi[i] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        }
        catch(...){
            for(int j = 0; j < pregledi.broj_pregleda; j++) delete svi_pregledi[j];
            delete[] svi_pregledi;
            throw std::bad_alloc();
        }
    }
    broj_pregleda = pregledi.broj_pregleda;
    max_pregleda = pregledi.max_pregleda;
}

Pregledi::Pregledi(Pregledi &&pregledi){
    svi_pregledi = pregledi.svi_pregledi;
    broj_pregleda = pregledi.broj_pregleda;
    max_pregleda = pregledi.max_pregleda;
    for(int i = 0; i < pregledi.broj_pregleda; i++) delete pregledi.svi_pregledi[i];
    delete[] pregledi.svi_pregledi;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi){
    if(&pregledi != this){
        for(int j = 0; j < pregledi.broj_pregleda; j++) delete svi_pregledi[j];
        delete[] svi_pregledi;
        svi_pregledi = new Pregled*[pregledi.DajBrojPregleda()];
        for(int i = 0; i < pregledi.broj_pregleda; i++){
            std::string ime_pacijenta = pregledi.svi_pregledi[i]->DajImePacijenta();
            Datum datum_pregleda = pregledi.svi_pregledi[i]->DajDatumPregleda();
            Vrijeme vrijeme_pregleda = pregledi.svi_pregledi[i]->DajVrijemePregleda();
            try{
                svi_pregledi[i] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
            }
            catch(...){
                for(int j = 0; j < pregledi.broj_pregleda; j++) delete svi_pregledi[j];
                delete[] svi_pregledi;
                throw std::bad_alloc();
            }
        }
        broj_pregleda = pregledi.broj_pregleda;
        max_pregleda = pregledi.max_pregleda;
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi){
    if(&pregledi != this){
        for(int i = 0; i < broj_pregleda; i++) delete svi_pregledi[i];
        delete[] svi_pregledi;
        svi_pregledi = pregledi.svi_pregledi;
        broj_pregleda = pregledi.broj_pregleda;
        max_pregleda = pregledi.max_pregleda;
        for(int i = 0; i < pregledi.broj_pregleda; i++) delete pregledi.svi_pregledi[i];
        delete[] pregledi.svi_pregledi;
    }
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if(Pregledi::broj_pregleda + 1 > Pregledi::max_pregleda){
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    try{
        svi_pregledi[broj_pregleda] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        broj_pregleda++;
    }
    catch(...){
        for(int j = 0; j < max_pregleda; j++) delete svi_pregledi[j];
        delete[] svi_pregledi;
        throw std::bad_alloc();
    }
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
    if(Pregledi::broj_pregleda + 1 > Pregledi::max_pregleda){
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    try{
        svi_pregledi[broj_pregleda++] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    }
    catch(...){
        for(int j = 0; j < max_pregleda; j++) delete svi_pregledi[j];
        delete[] svi_pregledi;
        throw std::bad_alloc();
    }
}

void Pregledi::RegistrirajPregled(Pregled *pregled){
    if(Pregledi::broj_pregleda + 1 > Pregledi::max_pregleda){
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    std::string ime_pacijenta = pregled->DajImePacijenta();
    Datum datum_pregleda = pregled->DajDatumPregleda();
    Vrijeme vrijeme_pregleda = pregled->DajVrijemePregleda();
    try{
        svi_pregledi[broj_pregleda] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
        broj_pregleda++;
    }
    catch(...){
        for(int j = 0; j < max_pregleda; j++) delete svi_pregledi[j];
        delete[] svi_pregledi;
        delete pregled;
        throw std::bad_alloc();
    }
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    int dan1,mj1,god1,rezultat = 0;
    std::tie(dan1,mj1,god1) = datum.Ocitaj();
    rezultat = std::count_if(svi_pregledi, svi_pregledi + broj_pregleda, [&](Pregled *p){
        Datum d = p->DajDatumPregleda();
        int dan2,mj2,god2;
        std::tie(dan2,mj2,god2) = d.Ocitaj();
        return(dan1 == dan2 && mj1 == mj2 && god1 == god2);
    });
    return rezultat;
}

Pregled &Pregledi::DajNajranijiPregled(){
    if(broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    auto rezultat = std::min_element(svi_pregledi, svi_pregledi + broj_pregleda,[](Pregled *p1, Pregled *p2){
        return DolaziPrije(*p1,*p2);
    });
    return **rezultat;
}

Pregled Pregledi::DajNajranijiPregled() const{
    if(broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    auto rezultat = std::min_element(svi_pregledi, svi_pregledi + broj_pregleda,[](Pregled *p1, Pregled *p2){
        return DolaziPrije(*p1,*p2);
    });
    std::string ime_pacijenta = (*rezultat)->DajImePacijenta();
    Datum d1 = (*rezultat)->DajDatumPregleda();
    Vrijeme v1 = (*rezultat)->DajVrijemePregleda();
    Pregled rez(ime_pacijenta, d1, v1);
    return rez;
}

void Pregledi::IsprazniKolekciju(){
    for(int i = 0; i < broj_pregleda; i++){
        delete svi_pregledi[i];
    }
    broj_pregleda = 0;
}

void Pregledi::ObrisiNajranijiPregled(){
    if(broj_pregleda == 0) throw std::range_error("Prazna kolekcija");
    auto rezultat = std::min_element(svi_pregledi, svi_pregledi + broj_pregleda,[](Pregled *p1, Pregled *p2){
        return DolaziPrije(*p1,*p2);
    });
    int poz = rezultat - svi_pregledi;
    delete svi_pregledi[poz];
    for(int i = poz; i < broj_pregleda - 1; i++){
        svi_pregledi[i] = svi_pregledi[i+1];
    } 
    svi_pregledi[broj_pregleda-1] = nullptr;
    broj_pregleda--;
    std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    int br = 0;
    while(true){
        auto rezultat = std::find_if(svi_pregledi, svi_pregledi + broj_pregleda,[&](Pregled *p1){
            return (ime_pacijenta == p1->DajImePacijenta());
        });
        int poz = rezultat - svi_pregledi;
        if(poz == broj_pregleda) break;
        delete svi_pregledi[poz];
        for(int i = poz; i < broj_pregleda - 1; i++) svi_pregledi[i] = svi_pregledi[i+1];
        svi_pregledi[broj_pregleda-1] = nullptr;
        broj_pregleda--;
        br++;
    }
    std::cout << "Uspjesno obrisano " << br << " pregleda" << std::endl;
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    Pregledi pomocni(*this);
    while(true){
        auto rezultat = std::find_if(pomocni.svi_pregledi, pomocni.svi_pregledi + pomocni.broj_pregleda,[&](Pregled *p1){
            int d1,m1,g1,d2,m2,g2;
            std::tie(d1,m1,g1) = datum.Ocitaj();
            std::tie(d2,m2,g2) = p1->DajDatumPregleda().Ocitaj();
            return (d1 != d2 || m1 != m2 || g1 != g2);
        });
        int poz = rezultat - pomocni.svi_pregledi;
        if(poz == pomocni.broj_pregleda) break;
        delete pomocni.svi_pregledi[poz];
        for(int i = poz; i < pomocni.broj_pregleda - 1; i++) pomocni.svi_pregledi[i] = pomocni.svi_pregledi[i+1];
        pomocni.svi_pregledi[pomocni.broj_pregleda-1] = nullptr;
        pomocni.broj_pregleda--;
    }
    pomocni.IspisiSvePreglede();
    
}

void Pregledi::IspisiSvePreglede() const{
    Pregledi pomocni(*this);
    std::sort(pomocni.svi_pregledi, pomocni.svi_pregledi + pomocni.broj_pregleda, [] (Pregled *p1, Pregled *p2){
        return DolaziPrije(*p1,*p2); 
    });
    for(int i = 0; i < pomocni.broj_pregleda; i++){
        pomocni.svi_pregledi[i]->Ispisi();
    }
}

int main (){
    std::cout << "Unesite maksimalan broj pregleda: ";
    int max;
    std::cin >> max;
    Pregledi p1(max);
    for(;;){
        std::string ime_pacijenta;
        int dan,mjesec,godina,sat,minute;
        std::cin.ignore(10000,'\n');
        std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        getline(std::cin,ime_pacijenta);
        if(ime_pacijenta == "kraj") break;
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        std::cin >> dan >> mjesec >> godina;
        std::cout << "Unesite sate i minute pregleda: ";
        std::cin >> sat >> minute;
        try{
            p1.RegistrirajPregled(ime_pacijenta, dan, mjesec, godina, sat, minute);
            if(p1.DajBrojPregleda() == max) break;
        }
        catch(std::exception &e){
            std::cout << e.what();
            break;
        }
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
    p1.IspisiSvePreglede();
    for(;;){
        int izbor;
        std::cout << std::endl;
        std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
        std::cout << "1 - Broj pregleda na datum" << std::endl;
        std::cout << "2 - Najraniji pregled" << std::endl;
        std::cout << "3 - Obrisi pregled pacijenta" << std::endl;
        std::cout << "4 - Obrisi najraniji pregled" << std::endl;
        std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
        std::cout << "6 - Ispisi sve preglede" << std::endl;
        std::cout << "7 - Kraj programa" << std::endl;
        std::cin >> izbor;
        std::cin.ignore(10000,'\n');
        if(izbor == 1){
            std::cout << "Unesite dan mjesec i godinu : ";
            int dan, mjesec, godina;
            std::cin >> dan >> mjesec >> godina;
            Datum d1(dan,mjesec,godina);
            std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina;
            std::cout << " je: " << p1.DajBrojPregledaNaDatum(d1) << std::endl;
        }
        else if(izbor == 2){
            auto najraniji = p1.DajNajranijiPregled();
            std::cout << "Najraniji pregled je:" << std::endl;
            najraniji.Ispisi();
        }
        else if(izbor == 3){
            std::string ime;
            std::cout << "Unesite ime pacijenta: ";
            getline(std::cin, ime);
            p1.ObrisiPregledePacijenta(ime);
        }
        else if(izbor == 4){
            p1.ObrisiNajranijiPregled();
        }
        else if(izbor == 5){
            std::cout << "Unesite dan mjesec i godinu : ";
            int dan, mjesec, godina;
            std::cin >> dan >> mjesec >> godina;
            Datum d1(dan,mjesec,godina);
            std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina;
            std::cout << " su: " << std::endl;
            p1.IspisiPregledeNaDatum(d1);
        }
        else if(izbor == 6){
            p1.IspisiSvePreglede();
        }
        else break;
    }
    
	return 0;
}