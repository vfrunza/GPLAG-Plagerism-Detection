/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <utility>
#include <stdexcept>
#include <string>
#include <tuple>
#include <iomanip> 
#include <initializer_list>
#include <algorithm>

class Datum {
private:
    int dan, mjesec, godina;
public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan, mjesec, godina);
    }
    void Ispisi() const {
        std::cout<<dan<<"/"<<mjesec<<"/"<<godina;
    }
};

Datum::Datum(int dan, int mjesec, int godina) {
    int brojDana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) brojDana[1]++;
    if (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > brojDana[mjesec-1])
        throw std::domain_error("Neispravan datum");
    this->dan = dan; this->mjesec = mjesec; this->godina = godina;
}

void Datum::Postavi(int dan, int mjesec, int godina) {
    int brojDana[12] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (godina % 4 == 0 && godina % 100 != 0 || godina % 400 == 0) brojDana[1]++;
    if (godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > brojDana[mjesec-1])
        throw std::domain_error("Neispravan datum");
        this->dan = dan; this->mjesec = mjesec; this->godina = godina;
}

class Vrijeme {
private:
    int sati, minute;
public: 
    Vrijeme(int sati, int minute);
    void Postavi(int sati, int minute);
    std::pair<int, int>Ocitaj() const {
        return std::make_pair(sati, minute);
    }
    void Ispisi() const {
        if (sati >= 0 && sati < 10) std::cout<<0;
        std::cout<<sati<<":";
        if (minute >= 0 && minute < 10)  std::cout<<0;
        std::cout<<minute;
    }
};

void Vrijeme::Postavi(int sati, int minute) {
    if (sati < 0 || sati > 23 || minute < 0 || minute > 59)
        throw std::domain_error("Neispravno vrijeme");
    this->sati = sati;  this->minute = minute;
}

Vrijeme::Vrijeme(int sati, int minute) {
    Postavi(sati, minute);
}

class Pregled {
private:
    std::string imePacijenta;
    Datum datumPregleda;
    Vrijeme vrijemePregleda;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void PromijeniPacijenta(const std::string &ime_pacijenta) {
        imePacijenta = ime_pacijenta;
    }
    void PromijeniDatum(const Datum &novi_datum) {
        std::tuple<int, int, int> d = novi_datum.Ocitaj();
        datumPregleda.Postavi(std::get<0>(d), std::get<1>(d), std::get<2>(d));
    }
    
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) {
        std::pair<int, int> v = novo_vrijeme.Ocitaj();
        vrijemePregleda.Postavi(v.first, v.second);
    }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return imePacijenta; }
    Datum DajDatumPregleda() const { return datumPregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijemePregleda; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const;
    
};

Pregled::Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) :
        imePacijenta(ime_pacijenta), datumPregleda(datum_pregleda), vrijemePregleda(vrijeme_pregleda) {}

Pregled::Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) :
     imePacijenta(ime_pacijenta), datumPregleda(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijemePregleda(sati_pregleda, minute_pregleda) {}

void Pregled::PomjeriDanUnaprijed() {
    int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::tuple<int, int, int> d = datumPregleda.Ocitaj();
    if (std::get<2>(d) % 4 == 0 && std::get<2>(d) % 100 != 0 || std::get<2>(d) % 400 == 0) brojDana[1]++;
    if (std::get<0>(d) < brojDana[std::get<1>(d)-1]) 
        datumPregleda.Postavi(std::get<0>(d)+1, std::get<1>(d), std::get<2>(d));
    else if (std::get<0>(d) == brojDana[std::get<1>(d)-1] && std::get<1>(d) != 12) {
        datumPregleda.Postavi(1, std::get<1>(d)+1, std::get<2>(d));
    }
    else if (std::get<0>(d) == brojDana[std::get<1>(d)-1] && std::get<1>(d) == 12) {
        datumPregleda.Postavi(1, 1, std::get<2>(d)+1);
    }
}

void Pregled::PomjeriDanUnazad() {
    int brojDana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    std::tuple<int, int, int> d = datumPregleda.Ocitaj();
    if (std::get<2>(d) % 4 == 0 && std::get<2>(d) % 100 != 0 || std::get<2>(d) % 400 == 0) brojDana[1]++;
    if (std::get<0>(d) > 1) datumPregleda.Postavi(std::get<0>(d)-1, std::get<1>(d), std::get<2>(d));
    else if (std::get<0>(d) == 1 && std::get<1>(d) != 1)
        datumPregleda.Postavi(brojDana[std::get<1>(d)-2], std::get<1>(d)-1, std::get<2>(d));
    else if (std::get<0>(d) == 1 && std::get<1>(d) == 1)
        datumPregleda.Postavi(brojDana[11], 12, std::get<2>(d)-1);
} 

bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    std::tuple<int, int, int> d1 = p1.datumPregleda.Ocitaj();
    std::tuple<int, int, int> d2 = p2.datumPregleda.Ocitaj();
    if (std::get<2>(d1) <= std::get<2>(d2)) {
        if (std::get<1>(d1) < std::get<1>(d2)) return true;
        else if (std::get<1>(d1) == std::get<1>(d2)) {
            if (std::get<0>(d1) < std::get<1>(d2)) return true;
            else return false;
        }
        else return false;
    }
    else return false;
}

void Pregled::Ispisi() const {
    std::cout<<std::left<<std::setw(30)<<DajImePacijenta();
    DajDatumPregleda().Ispisi();
    std::cout<<" ";
    DajVrijemePregleda().Ispisi();
    std::cout<<std::endl;
}

class Pregledi {
private:
    Pregled **p;
    int kapacitet, broj_pregleda;
    static bool DolaziPrijeVrijeme (Pregled p1, Pregled p2) {
        std::pair<int, int> v1 = p1.DajVrijemePregleda().Ocitaj();
        std::pair<int, int> v2 = p2.DajVrijemePregleda().Ocitaj();
        if (v1.first < v2.first) {
            if (v1.second < v2.second) return true;
            else return false;
        }
        else return false;
    }
    
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
    int DajBrojPregleda() const { return broj_pregleda; }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi(int max_broj_pregleda) : kapacitet(max_broj_pregleda), broj_pregleda(0), p(new Pregled*[max_broj_pregleda]{}) {}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) {
    kapacitet = spisak_pregleda.size();
    broj_pregleda = 0;
    p = nullptr;
    try {
        p = new Pregled*[kapacitet]{};
        try {
            for (int i=0; i<kapacitet; i++)
                p[i] = new Pregled(spisak_pregleda.begin()[i]);
        }
        catch(std::bad_alloc) {
            for (int i=0; i<kapacitet; i++) delete p[i];
            delete[] p;
            p = nullptr;
            throw;
        }
    }
    catch(...) {
        throw std::domain_error("Alokacija nije uspjela");
    }
}

Pregledi::~Pregledi() {
    if (p != nullptr) {
        for (int i=0; i<kapacitet; i++) delete p[i];
        delete[] p;
        p = nullptr;
    }
}

Pregledi::Pregledi(const Pregledi &pregledi) {
    kapacitet = pregledi.kapacitet;
    broj_pregleda = pregledi.broj_pregleda;
    p = nullptr;
    try {
        p = new Pregled*[kapacitet]{};
        try {
            for (int i=0; i<kapacitet; i++) 
                p[i] = new Pregled(*pregledi.p[i]);
        }
        catch(std::bad_alloc) {
            for (int i=0; i<kapacitet; i++) delete p[i];
            delete[] p;
            p = nullptr;
            throw;
        }
    }
    catch(...) {
        throw std::domain_error("Alokacija nije uspjela");
    }
}

Pregledi::Pregledi(Pregledi &&pregledi) {
    broj_pregleda = pregledi.broj_pregleda;
    kapacitet = pregledi.kapacitet;
    p = pregledi.p;
    pregledi.p = nullptr;
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
    if (&pregledi == this) return *this;
    
    for (int i=0; i<broj_pregleda; i++) delete p[i];
    delete[] p;
    
    broj_pregleda = pregledi.broj_pregleda;
    kapacitet = pregledi.kapacitet;
    p = nullptr;
    
    try {
        p = new Pregled*[kapacitet]{};
        try {
            for (int i=0; i<kapacitet; i++) 
                p[i] = new Pregled(*pregledi.p[i]);
        }
        catch(std::bad_alloc) {
            for (int i=0; i<kapacitet; i++) delete p[i];
            delete[] p;
            p = nullptr;
            throw;
        }
    }
    catch(...) {
        throw std::domain_error("Alokacija nije uspjela");
    }
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    if (&pregledi == this) return *this;
    broj_pregleda = pregledi.broj_pregleda;
    kapacitet = pregledi.kapacitet;
    for (int i=0; i<kapacitet; i++) delete p[i];
         delete[] p;
    p = pregledi.p;
    for (int i=0; i<broj_pregleda; i++)
        p[i] = pregledi.p[i];
    pregledi.p = nullptr;
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if (broj_pregleda >= kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
    *p[broj_pregleda++] = Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
    if (broj_pregleda >= kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
    *p[broj_pregleda++] = Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
}

void Pregledi::RegistrirajPregled(Pregled *pregled) {
    if (broj_pregleda >= kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
    p[broj_pregleda++] = pregled;
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return std::count_if(p, p+broj_pregleda, [&datum](Pregled *pregled){
        std::tuple<int, int, int> d1 = datum.Ocitaj();
        std::tuple<int, int, int> d2 = pregled->DajDatumPregleda().Ocitaj();
        if (std::get<0>(d1) == std::get<0>(d2) && std::get<1>(d1) == std::get<1>(d2) && std::get<2>(d1) == std::get<2>(d2)) return true;
        else return false;
    });
}

Pregled &Pregledi::DajNajranijiPregled() {
    if (broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(p, p+broj_pregleda, [](Pregled *pregled1, Pregled *pregled2) {
        return Pregled::DolaziPrije(*pregled1, *pregled2);
    });
}

Pregled Pregledi::DajNajranijiPregled() const {
    if (broj_pregleda == 0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(p, p+broj_pregleda, [](Pregled *pregled1, Pregled *pregled2) {
        return Pregled::DolaziPrije(*pregled1, *pregled2);
    });
}

void Pregledi::IsprazniKolekciju() {
    for (int i=0; i<broj_pregleda; i++) delete p[i];
    delete[] p;
    p = nullptr;
    try {
         p = new Pregled*[kapacitet]{};
    }
    catch(...) {
        throw std::domain_error("Alokacija nije uspjela");
    }
    broj_pregleda = 0;
}

void Pregledi::ObrisiNajranijiPregled() {
    if (broj_pregleda == 0) throw std::range_error("Prazna kolekcija");
    Pregled pregled = DajNajranijiPregled();
    for (int i=0; i<broj_pregleda; i++) {
        if (p[i] != nullptr) {
            if (p[i]->DajImePacijenta() == pregled.DajImePacijenta()) {
                delete p[i];
                broj_pregleda--;
             //   p[i] = nullptr;
                break;
            }
        }
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for (int i=0; i<broj_pregleda; i++) {
        if (p[i] != nullptr) {
            if (p[i]->DajImePacijenta() == ime_pacijenta) {
                delete p[i];
                broj_pregleda--;
             //   p[i] = nullptr;
            }
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    Pregled ** novi = new Pregled*[broj_pregleda];
    for (int i=0; i<broj_pregleda; i++)
        novi[i] = p[i];
    Pregled ** novi2 = new Pregled*[broj_pregleda];
    int a{};
    for (int i=0; i<broj_pregleda; i++) {
         std::tuple<int, int, int> d1 = novi[i]->DajDatumPregleda().Ocitaj();
        std::tuple<int, int, int> d = datum.Ocitaj();
        if (std::get<0>(d1) == std::get<0>(d)  && std::get<1>(d1) == std::get<1>(d) && std::get<2>(d1) == std::get<2>(d)) novi2[a++] = novi[i];
    }
       
    std::sort(novi2, novi2+a, [](Pregled *pregled1, Pregled *pregled2) {
            return Pregledi::DolaziPrijeVrijeme(*pregled1, *pregled2);
    });     
   // int a = DajBrojPregledaNaDatum(datum);
    //Pregled **novi2 = new Pregled*[a];
  //  int pom{};
    //while (pom != a) {
      //  novi2[pom] = novi[pom];
        //pom++;
    //}
    
        
    for (int i=0; i<a; i++)
        novi2[i]->Ispisi();
    for (int i=0; i<a; i++) novi2[i] = nullptr;
    delete[] novi2;
    novi2 = nullptr;
    for (int i=0; i<broj_pregleda; i++)  novi[i] = nullptr;
    delete[] novi;
    novi = nullptr;
}

void Pregledi::IspisiSvePreglede() const {
    Pregled ** novi = new Pregled*[broj_pregleda];
    for (int i=0; i<broj_pregleda; i++) novi[i] = p[i];
    std::sort(novi, novi+broj_pregleda, [&novi](Pregled *p1, Pregled *p2) {
       
        return Pregled::DolaziPrije(*p1, *p2);
        
    });
    std::sort(novi, novi+broj_pregleda, [&novi](Pregled *p3, Pregled *p4) {
            return Pregledi::DolaziPrijeVrijeme(*p3, *p4);
        });
   
    for (int i=0; i<broj_pregleda; i++)
        novi[i]->Ispisi();
    for (int i=0; i<broj_pregleda; i++) novi[i] = nullptr;
    delete[] novi;
    novi = nullptr;
}

int main ()
{
    try {
    int n{};
    std::cout<<"Unesite maksimalan broj pregleda: ";
    std::cin>>n;
    std::cin.ignore(10000, '\n');
    int br{};
    std::string s;
    int d{}, m{}, g{}, h{}, min{};
    Pregledi pregledi(n);
    
        do {
            Pregled *pregled(nullptr);
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::getline(std::cin, s);
            if (s == "kraj") break;
            std::cin.clear();
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            std::cin>>d>>m>>g;
            std::cout<<"Unesite sate i minute pregleda: ";
            std::cin>>h>>min;
            std::cin.ignore(10000, '\n');
            pregled = new Pregled(s, d, m, g, h, min);
            pregledi.RegistrirajPregled(pregled);
            br++;
        }
        while (br < n && s != "kraj");
        std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
        pregledi.IspisiSvePreglede();
        int x{};
        do {
            std::cout<<"\nOdaberite jednu od sljedecih opcija\n";
            std::cout<<"1 - Broj pregleda na datum\n";
            std::cout<<"2 - Najraniji pregled\n";
            std::cout<<"3 - Obrisi pregled pacijenta\n";
            std::cout<<"4 - Obrisi najraniji pregled\n";
            std::cout<<"5 - Ispisi sve pregleda na datum\n";
            std::cout<<"6 - Ispisi sve preglede\n";
            std::cout<<"7 - Kraj programa\n";
            std::cin>>x;
            switch(x) {
                case 1: {
                    std::cout<<"Unesite dan mjesec i godinu : ";
                    int a{}, b{}, c{};
                    std::cin>>a>>b>>c;
                    std::cout<<"Broj pregleda na datum "<<a<<" "<<b<<" "<<c<<" je: "<<pregledi.DajBrojPregledaNaDatum(Datum(a, b, c))<<std::endl;
                    break;
                }
                case 2: {
                    std::cout<<"Najraniji pregled je:\n";
                    pregledi.DajNajranijiPregled().Ispisi();
                    break;
                }
                case 3: {
                    std::string ime;
                    std::cin.ignore(10000, '\n');
                    std::cout<<"Unesite ime pacijenta: ";
                    std::getline(std::cin, ime);
                    pregledi.ObrisiPregledePacijenta(ime);
                    std::cout<<"Uspjesno obrisano 1 pregleda\n";
                    break;
                }
                case 4: {
                    pregledi.ObrisiNajranijiPregled();
                    std::cout<<"Najraniji pregled uspjesno obrisan\n";
                    break;
                }
                case 5: {
                    std::cout<<"Unesite dan mjesec i godinu : ";
                    int a{}, b{}, c{};
                    std::cin>>a>>b>>c;
                    std::cout<<"Pregledi na datum "<<a<<" "<<b<<" "<<c<<" su:\n";
                    pregledi.IspisiPregledeNaDatum(Datum(a, b, c));
                    break;
                }
                case 6: {
                    pregledi.IspisiSvePreglede();
                    break;
                }
                case 7: {
                    break;
                }
            }
        }
        while (x != 7);
    }
    catch(std::domain_error e) {
        std::cout<<e.what()<<std::endl;
    }
   
  
	return 0;
}
