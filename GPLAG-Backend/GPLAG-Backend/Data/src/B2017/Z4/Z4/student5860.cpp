/B2017/2018: Zadaća 4, Zadatak 4
#include <iostream>
#include <utility>
#include <stdexcept>
#include <string>
#include <tuple>
#include <iomanip> 
#include <initializer_list>
#include <algorithm>
#include <memory>
#include <vector>

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
    std::vector<std::shared_ptr<Pregled>> p;
    
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
    explicit Pregledi();
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(std::shared_ptr<Pregled> pregled);
    int DajBrojPregleda() const { return p.size(); }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
};

Pregledi::Pregledi() {}

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda): p(spisak_pregleda.size()) {
  
   
        
            for (int i=0; i<spisak_pregleda.size(); i++)
                p[i] = std::make_shared<Pregled>(spisak_pregleda.begin()[i]);
      
       
}



Pregledi::Pregledi(const Pregledi &pregledi) : p(pregledi.p.size()){
   for (int i=0; i<pregledi.p.size(); i++)
    p[i] = std::make_shared<Pregled>(*pregledi.p[i]);
}

Pregledi::Pregledi(Pregledi &&pregledi) : p(std::move(pregledi.p)) {}

Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
 //   if (&pregledi == this) return *this;
    
   p.resize(pregledi.p.size());
   for (int i=0; i<pregledi.p.size(); i++)
    p[i] = std::make_shared<Pregled>(*pregledi.p[i]);
    return *this;
}

Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    p = std::move(pregledi.p);
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
  //  if (broj_pregleda >= kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
   p.push_back(std::make_shared<Pregled>(Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda)));
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
 //   if (broj_pregleda >= kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
    p.push_back(std::make_shared<Pregled>(Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda)));
}

void Pregledi::RegistrirajPregled(std::shared_ptr<Pregled> pregled) {
  //  if (broj_pregleda >= kapacitet) throw std::range_error("Dostignut maksimalni broj pregleda");
  p.push_back(pregled);
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const {
    return std::count_if(p.begin(), p.end(), [&datum](std::shared_ptr<Pregled> pregled){
        std::tuple<int, int, int> d1 = datum.Ocitaj();
        std::tuple<int, int, int> d2 = pregled->DajDatumPregleda().Ocitaj();
        if (std::get<0>(d1) == std::get<0>(d2) && std::get<1>(d1) == std::get<1>(d2) && std::get<2>(d1) == std::get<2>(d2)) return true;
        else return false;
    });
}

Pregled &Pregledi::DajNajranijiPregled() {
    if (p.size() == 0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(p.begin(), p.end(), [](std::shared_ptr<Pregled> pregled1, std::shared_ptr<Pregled> pregled2) {
        return Pregled::DolaziPrije(*pregled1, *pregled2);
    });
}

Pregled Pregledi::DajNajranijiPregled() const {
    if (p.size() == 0) throw std::domain_error("Nema registriranih pregleda");
    return **std::min_element(p.begin(), p.end(), [](std::shared_ptr<Pregled> pregled1, std::shared_ptr<Pregled> pregled2) {
        return Pregled::DolaziPrije(*pregled1, *pregled2);
    });
}

void Pregledi::IsprazniKolekciju() {
    
 /*  for (int i=0; i<p.size(); i++) delete p[i];
    
   
         p = new std::make_shared<Pregled>{};*/
   
}

void Pregledi::ObrisiNajranijiPregled() {
    if (p.size() == 0) throw std::range_error("Prazna kolekcija");
    Pregled pregled = DajNajranijiPregled();
    for (int i=0; i<p.size(); i++) {
        if (p[i] != nullptr) {
               auto it = std::find_if(p.begin(), p.end(), [&pregled](std::shared_ptr<Pregled> p1) {
                   if (pregled.DajImePacijenta() == p1->DajImePacijenta()) return true;
                   else return false;
               });
               // delete p[i];
               p.erase(it);
               
             //   p[i] = nullptr;
                break;
           
        }
    }
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for (int i=0; i<p.size(); i++) {
        if (p[i] != nullptr) {
          auto it = std::find_if(p.begin(), p.end(), [&ime_pacijenta](std::shared_ptr<Pregled> p1) {
                   if (p1->DajImePacijenta() == ime_pacijenta) return true;
                   else return false;
               });
           p.erase(it);
        }
    }
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    std::vector<std::shared_ptr<Pregled>> novi;// = std::make_shared<Pregled>(p.size());
   
    for (int i=0; i<p.size(); i++) {
         std::tuple<int, int, int> d1 = novi[i]->DajDatumPregleda().Ocitaj();
        std::tuple<int, int, int> d = datum.Ocitaj();
        if (std::get<0>(d1) == std::get<0>(d)  && std::get<1>(d1) == std::get<1>(d) && std::get<2>(d1) == std::get<2>(d)) novi[i] = p[i];
    }
       
    std::sort(novi.begin(), novi.end(), [](std::shared_ptr<Pregled> pregled1, std::shared_ptr<Pregled> pregled2) {
            return Pregledi::DolaziPrijeVrijeme(*pregled1, *pregled2);
            
    });     
     for (int i=0; i<novi.size(); i++)
        novi[i]->Ispisi();
/*   // int a = DajBrojPregledaNaDatum(datum);
    //Pregled **novi2 = new Pregled*[a];
  //  int pom{};
    //while (pom != a) {
      //  novi2[pom] = novi[pom];
        //pom++;
    //}
    
        
   
    for (int i=0; i<a; i++) novi2[i] = nullptr;
    delete[] novi2;
    novi2 = nullptr;
    for (int i=0; i<broj_pregleda; i++)  novi[i] = nullptr;
    delete[] novi;
    novi = nullptr;*/
    
    
}

void Pregledi::IspisiSvePreglede() const {
    std::vector<std::shared_ptr<Pregled>> novi;// = std::make_shared<Pregled>(p.size());
    for (int i=0; i<p.size(); i++) novi[i] = p[i];
    std::sort(novi.begin(), novi.end(), [&novi](std::shared_ptr<Pregled> p1, std::shared_ptr<Pregled> p2) {
       
        return Pregled::DolaziPrije(*p1, *p2);
        
    });
    std::sort(novi.begin(), novi.end(), [&novi](std::shared_ptr<Pregled> p3, std::shared_ptr<Pregled> p4) {
            return Pregledi::DolaziPrijeVrijeme(*p3, *p4);
        });
   
    for (int i=0; i<novi.size(); i++)
        novi[i]->Ispisi();
   
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
    Pregledi pregledi;
    
        do {
            std::shared_ptr<Pregled> pregled;
            std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::getline(std::cin, s);
            if (s == "kraj") break;
            std::cin.clear();
            std::cout<<"Unesite dan mjesec i godinu pregleda: ";
            std::cin>>d>>m>>g;
            std::cout<<"Unesite sate i minute pregleda: ";
            std::cin>>h>>min;
            std::cin.ignore(10000, '\n');
            pregled = std::make_shared<Pregled>(Pregled(s, d, m, g, h, min));
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

