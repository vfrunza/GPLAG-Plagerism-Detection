/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <iomanip>
#include <initializer_list>
#include <algorithm>

//                      Datum

class Datum{
    int dan, mjesec, godina;
    public:
    Datum(int dan, int mjesec, int godina){
        int broj_dana_u_mjesecu[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};
        if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana_u_mjesecu[1]++;
        if(godina<1 || mjesec<1 || mjesec>12 || dan<1 || dan>broj_dana_u_mjesecu[mjesec-1]) throw std::domain_error("Neispravan datum");
        this->dan=dan; this->mjesec=mjesec; this->godina=godina;
    }
    void Postavi(int dan, int mjesec, int godina){
        *this=Datum(dan, mjesec, godina);
    }
    std::tuple<int, int, int> Ocitaj() const { return std::tuple<int, int, int>(dan, mjesec, godina);}
    void Ispisi() const {std::cout << dan << "/" << mjesec << "/" << godina;}
};

//                      Vrijeme

class Vrijeme{
    int sati, minute;
    public:
    Vrijeme(int sati, int minute){
        if(sati<0 || sati>23 || minute<0 || minute>59) throw std::domain_error("Neispravno vrijeme");
        this->sati=sati; this->minute=minute;
    }
    void Postavi(int sati, int minute){
        *this=Vrijeme(sati, minute);
    }
    std::pair<int, int> Ocitaj() const {return {sati, minute};}
    void Ispisi() const { std::cout << std::right << std::setw(2) << std::setfill('0') << sati << ":" << std::setw(2) << std::setfill('0') << minute;}
};

//                      Pregled

class Pregled{
  std::string ime_pacijenta;
  Datum datum_pregleda;
  Vrijeme vrijeme_pregleda;
  public: 
  Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
  Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
  void PromijeniPacijenta(const std::string &ime_pacijenta);
  void PromijeniDatum(const Datum &novi_datum);
  void PromijeniVrijeme(const Vrijeme &novo_vrijeme);
  void PomjeriDanUnaprijed();
  void PomjeriDanUnazad();
  std::string DajImePacijenta() const { return ime_pacijenta;}
  Datum DajDatumPregleda() const { return datum_pregleda;}
  Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda;}
  static bool DolaziPrije(const Pregled &p1, const Pregled &p2){
      std::tuple<int, int, int> prvi_dat(p1.DajDatumPregleda().Datum::Ocitaj()), drugi_dat(p2.DajDatumPregleda().Datum::Ocitaj());
      std::pair<int, int> prvo_vr(p1.DajVrijemePregleda().Vrijeme::Ocitaj()), drugo_vr(p2.DajVrijemePregleda().Vrijeme::Ocitaj());
      return std::get<2>(prvi_dat)<std::get<2>(drugi_dat) || (std::get<2>(prvi_dat)==std::get<2>(drugi_dat) && (std::get<1>(prvi_dat)<std::get<1>(drugi_dat) || 
      (std::get<1>(prvi_dat)==std::get<1>(drugi_dat) && (std::get<0>(prvi_dat)<std::get<0>(drugi_dat) || (std::get<0>(prvi_dat)==std::get<0>(drugi_dat) && 
      (std::get<1>(prvo_vr)<std::get<1>(drugo_vr) || (std::get<1>(prvo_vr)==std::get<1>(drugo_vr) && std::get<0>(prvo_vr)<std::get<0>(drugo_vr))))))));
  }
  void Ispisi() const;
};

//                      Pregledi

class Pregledi{
    const int max_broj_pregleda;
    int broj_unesenih;
    Pregled **pregledi;
    public:
    explicit Pregledi(int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda), broj_unesenih(0), pregledi(new Pregled*[max_broj_pregleda]) {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    ~Pregledi(){
        for(int i(0); i<broj_unesenih; i++) delete pregledi[i];
        delete[] pregledi;
    }
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
        int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const { return broj_unesenih;}
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

//                      implementacija Pregled

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime_pacijenta(ime_pacijenta),
    datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) {}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) :
    ime_pacijenta(ime_pacijenta), datum_pregleda(Datum(dan_pregleda, mjesec_pregleda, godina_pregleda)), vrijeme_pregleda(Vrijeme(sati_pregleda, minute_pregleda)) {}

void Pregled::PromijeniPacijenta(const std::string &ime_pacijenta){ this->ime_pacijenta=ime_pacijenta;}

void Pregled::PromijeniDatum(const Datum &novi_datum){ this->datum_pregleda=novi_datum;}

void Pregled::PromijeniVrijeme(const Vrijeme &novo_vrijeme){ this->vrijeme_pregleda=novo_vrijeme;}

void Pregled::PomjeriDanUnaprijed(){
    int dan, mjesec, godina;
    std::tie(dan, mjesec, godina)=datum_pregleda.Ocitaj();
    int broj_dana_u_mjesecu[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana_u_mjesecu[1]++;
    dan++;
    if(dan>broj_dana_u_mjesecu[mjesec-1]){
        dan=1; mjesec++;
        if(mjesec>12){
            mjesec=1; godina++;
        }
    }
    this->datum_pregleda=Datum(dan, mjesec, godina);
}

void Pregled::PomjeriDanUnazad(){
    int dan, mjesec, godina;
    std::tie(dan, mjesec, godina)=datum_pregleda.Ocitaj();
    int broj_dana_u_mjesecu[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31};
    if((godina%4==0 && godina%100!=0) || godina%400==0) broj_dana_u_mjesecu[1]++;
    dan--;
    if(dan<1 && mjesec==1){
        dan=31;
        mjesec=12;
        godina--;
    }
    else if(dan<1 && mjesec!=1){
        dan=broj_dana_u_mjesecu[mjesec-2];
        mjesec--;
    }
    this->datum_pregleda=Datum(dan, mjesec, godina);
}

void Pregled::Ispisi() const{
    std::cout << std::setw(30) << std::setfill(' ') << std::left << ime_pacijenta;
    datum_pregleda.Datum::Ispisi();
    std::cout << " ";
    vrijeme_pregleda.Vrijeme::Ispisi();
    std::cout << std::endl;
}

//                      implementacija Pregledi

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()), broj_unesenih(0),
pregledi(new Pregled*[max_broj_pregleda]) {
    try{
        for(auto a: spisak_pregleda){
            pregledi[broj_unesenih]=new Pregled(a.DajImePacijenta(), a.DajDatumPregleda(), a.DajVrijemePregleda());
            broj_unesenih++;
        }
    } catch(...){
        for(int i(0); i<broj_unesenih; i++) delete pregledi[i];
        delete[] pregledi;
    }
}

Pregledi::Pregledi(const Pregledi &pregledi1) : max_broj_pregleda(pregledi1.max_broj_pregleda), broj_unesenih(0), pregledi(new Pregled*[pregledi1.broj_unesenih]) {
    try{
        for(int i(0); i<pregledi1.broj_unesenih; i++){
            pregledi[broj_unesenih]=new Pregled(pregledi1.pregledi[i]->DajImePacijenta(), pregledi1.pregledi[i]->DajDatumPregleda(),
                pregledi1.pregledi[i]->DajVrijemePregleda());
            broj_unesenih++;
        }
    }
    catch(...){
        for(int i(0); i<broj_unesenih; i++) delete pregledi[i];
        delete[] pregledi;
    }
}

Pregledi::Pregledi(Pregledi &&pregledi1) : max_broj_pregleda(pregledi1.max_broj_pregleda), broj_unesenih(pregledi1.broj_unesenih), 
pregledi(pregledi1.pregledi) {
    pregledi1.pregledi=nullptr;
    pregledi1.broj_unesenih=0;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi1){
    if(this->max_broj_pregleda!=pregledi1.max_broj_pregleda) throw std::logic_error("Nesaglasni");
    if(pregledi1.broj_unesenih>this->broj_unesenih){
        try{
            for(int i(this->broj_unesenih); i<pregledi1.broj_unesenih; i++){
                this->pregledi[i]=new Pregled(pregledi1.pregledi[i]->DajImePacijenta(), pregledi1.pregledi[i]->DajDatumPregleda(),
                    pregledi1.pregledi[i]->DajVrijemePregleda());
                this->broj_unesenih++;
            }
        } catch(...){
            throw;
        }
        
    }
    else{
        for(int i(pregledi1.broj_unesenih); i<this->broj_unesenih; i++){
            delete this->pregledi[i];
            this->pregledi[i]=nullptr;
        }
        this->broj_unesenih=pregledi1.broj_unesenih;
    }
    for(int i(0); i<broj_unesenih; i++) *(this->pregledi[i])=*(pregledi1.pregledi[i]);
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi1){
    if(this->max_broj_pregleda!=pregledi1.max_broj_pregleda) throw std::logic_error("Nesaglasni");
    std::swap(this->broj_unesenih, pregledi1.broj_unesenih);
    std::swap(this->pregledi, pregledi1.pregledi);
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda){
    if(broj_unesenih==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_unesenih++]=new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda){
    if(broj_unesenih==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_unesenih++]=new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
}

void Pregledi::RegistrirajPregled(Pregled *pregled){
    if(broj_unesenih==max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_unesenih++]=pregled;
}


int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return std::count_if(pregledi, pregledi+broj_unesenih, [datum](Pregled *a){ return a->DajDatumPregleda().Datum::Ocitaj()==datum.Datum::Ocitaj();});
}

Pregled &Pregledi::DajNajranijiPregled(){
    if(broj_unesenih==0) throw std::domain_error("Nema registriranih pregleda");
    return **(std::min_element(pregledi, pregledi+broj_unesenih, [](Pregled *a, Pregled *b){ return Pregled::DolaziPrije(*a, *b);}));
}

Pregled Pregledi::DajNajranijiPregled() const {
    if(broj_unesenih==0) throw std::domain_error("Nema registriranih pregleda");
    return **(std::min_element(pregledi, pregledi+broj_unesenih, [](Pregled *a, Pregled *b){ return Pregled::DolaziPrije(*a, *b);}));
}

void Pregledi::IsprazniKolekciju(){
    for(int i(0); i<broj_unesenih; i++) delete pregledi[i];
    broj_unesenih=0;
}

void Pregledi::ObrisiNajranijiPregled(){
    if(broj_unesenih==0) throw std::range_error("Prazna kolekcija");
    Pregled pom=Pregledi::DajNajranijiPregled();
    for(int i(0); i<broj_unesenih; i++){
        if(pregledi[i]->DajImePacijenta()==pom.DajImePacijenta() && pregledi[i]->DajDatumPregleda().Ocitaj()==pom.DajDatumPregleda().Ocitaj() &&
        pregledi[i]->DajVrijemePregleda().Ocitaj()==pom.DajVrijemePregleda().Ocitaj()){
            for(int j(i); j<broj_unesenih-1; j++){
                *(pregledi[j])=*(pregledi[j+1]);
            }
            delete pregledi[broj_unesenih-1];
            this->broj_unesenih--;
            break;
        }   
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta){
    if(broj_unesenih==0) return;
    for(int i(0); i<broj_unesenih; i++){
        if(pregledi[i]->DajImePacijenta()==ime_pacijenta){
            for(int j(i); j<broj_unesenih-1; j++){
                *(pregledi[j])=*(pregledi[j+1]);
            }
            delete pregledi[broj_unesenih-1];
            this->broj_unesenih--;
            i--;
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const{
    int broj=Pregledi::DajBrojPregledaNaDatum(datum);
    if(broj==0) return;
    try{
        Pregled **pom=new Pregled*[broj];
        int i(0);
        std::for_each(pregledi, pregledi+broj_unesenih, [pom, &i, datum](Pregled *a){
           if(datum.Datum::Ocitaj()==a->DajDatumPregleda().Datum::Ocitaj()){
               pom[i]=a; i++;
           }
        });
        std::sort(pom, pom+broj, [](Pregled *a, Pregled *b){ return Pregled::DolaziPrije(*a, *b);});
        std::for_each(pom, pom+broj, [](Pregled *a){ a->Ispisi();});
        delete[] pom;
    }
    catch(...){
        throw;
    }
}

void Pregledi::IspisiSvePreglede() const {
    if(broj_unesenih==0) return;
    try{
        Pregled **pom=new Pregled*[broj_unesenih];
        int i(0);
        std::for_each(pregledi, pregledi+broj_unesenih, [pom, &i](Pregled *a){ pom[i]=a; i++;});
        std::sort(pom, pom+broj_unesenih, [](Pregled *a, Pregled *b){ return Pregled::DolaziPrije(*a, *b);});
        std::for_each(pom, pom+broj_unesenih, [](Pregled *a){ a->Ispisi();});
        delete[] pom;
    }
    catch(...){
        throw;
    }
}

//              pomocne za main

void IspisiPoruku(){
    std::cout << "\nOdaberite jednu od sljedecih opcija\n1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n" <<
    "4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n7 - Kraj programa\n";
}

int main ()
{
    std::cout << "Unesite maksimalan broj pregleda: ";
    int n;
    while(!(std::cin >> n) && n<0) std::cout << "Unesite ponovo\n";
    try{
        Pregledi raspored(n);
        for(int i(0); i<n; i++){
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::string ime;
            std::cin.ignore(10, '\n');
            std::getline(std::cin, ime);
            if(ime=="kraj") break;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            int dan, mjesec, godina;
            std::cin >> dan >> mjesec >> godina;
            std::cout << "Unesite sate i minute pregleda: ";
            int sat, minuta;
            std::cin >> sat >> minuta;
            raspored.RegistrirajPregled(ime, dan, mjesec, godina, sat, minuta);
        }
        std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
        raspored.IspisiSvePreglede();
        while(true){
            IspisiPoruku();
            int br;
            std::cin >> br;
            if(br==7) break;
            else if(br==1){
                std::cout << "Unesite dan mjesec i godinu : ";
                int dan, mjesec, godina;
                std::cin >> dan >> mjesec >> godina;
                try{
                    int a=raspored.DajBrojPregledaNaDatum(Datum(dan, mjesec, godina));
                    std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " <<  godina << " je: " << a << std::endl;;
                }
                catch(std::domain_error p){
                    std::cout << p.what() << std::endl;
                }
            }
            else if(br==2){
                std::cout << "Najraniji pregled je:\n";
                raspored.DajNajranijiPregled().Pregled::Ispisi();
            }
            else if(br==3){
                std::cout << "Unesite ime pacijenta: ";
                std::cin.ignore(1000, '\n');
                std::string a;
                std::getline(std::cin, a);
                int brojp(raspored.DajBrojPregleda());
                raspored.ObrisiPregledePacijenta(a);
                std::cout << "Uspjesno obrisano " << brojp-raspored.DajBrojPregleda() << " pregleda\n";
            }
            else if(br==4){
                try{
                    raspored.ObrisiNajranijiPregled();
                    std::cout << "Najraniji pregled uspjesno obrisan\n";
                }
                catch(std::domain_error p){
                    std::cout << p.what() << std::endl;
                }
            }
            else if(br==5){
                std::cout << "Unesite dan mjesec i godinu : ";
                int dan, mjesec, godina;
                std::cin >> dan >> mjesec >> godina;
                try{
                    Datum a(dan, mjesec, godina);
                    std::cout << "Pregledi na datum " << dan << " " << mjesec << " " <<  godina << " su:\n";
                    raspored.IspisiPregledeNaDatum(a);
                }
                catch(std::domain_error p){
                    std::cout << p.what() << std::endl;
                }
            }
            else if(br==6){
                raspored.IspisiSvePreglede();
            }
        }
    }catch(std::bad_alloc){
        std::cout << "Problemi sa momorijom";
    }catch(std::domain_error p){
        std::cout << p.what();
    }catch(std::logic_error p){
        std::cout << p.what();
    }catch(std::range_error p){
        std::cout << p.what();
    }
	return 0;
}
