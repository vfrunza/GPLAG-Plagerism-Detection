/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <stdexcept>
#include <vector>
#include <tuple>
#include <cmath>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <utility>
#include <string>

bool ProvjeraVremena(int sati,int minute)
{
    if(sati < 0 || sati > 23 || minute < 0 || minute > 59) return false;
    return true;
}

bool ProvjeraDatuma(int dan, int mjesec, int godina) 
{
     int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     if((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0) broj_dana[1]++;
     if(godina < 1 || mjesec < 1 || mjesec > 12 || dan < 1 || dan > broj_dana[mjesec - 1])  return false;
     return true;
}

class Datum {
    int dan,mjesec,godina;
  public:    
    Datum(int dan, int mjesec, int godina) : dan(dan), mjesec(mjesec), godina(godina) {
        if(!ProvjeraDatuma(dan,mjesec,godina)) throw std::domain_error("Neispravan datum");
    }
    void Postavi(int dan, int mjesec, int godina) {
        if(!ProvjeraDatuma(dan,mjesec,godina)) throw std::domain_error("Neispravan datum");
        Datum::dan = dan; Datum::mjesec = mjesec; Datum::godina = godina;
    }
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(dan,mjesec,godina);
    }
    void Ispisi() const {
        std::cout << dan << "/" << mjesec << "/" << godina;;
    }    
};

class Vrijeme {
    int sati,minute;
  public:        
    Vrijeme(int sati, int minute) : sati(sati), minute(minute) {
        if(!ProvjeraVremena(sati,minute)) throw std::domain_error("Neispravno vrijeme");
    }
    void Postavi(int sati, int minute) {
        if(!ProvjeraVremena(sati,minute)) throw std::domain_error("Neispravno vrijeme");
        Vrijeme::sati = sati; Vrijeme::minute = minute;
    }
    std::pair<int, int> Ocitaj () const {
        return std::make_pair(sati,minute);
    }
    void Ispisi() const { std::cout << std::setw(2) << std::right << std::setfill('0') << sati << ":" << std::setw(2) << std::setfill('0') << minute; }  
};


class Pregled {
  std::string ime;
  Vrijeme vrijeme;
  Datum datum;
  public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) : ime(ime_pacijenta), vrijeme(vrijeme_pregleda), datum(datum_pregleda) {}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) : ime(ime_pacijenta), 
        vrijeme(sati_pregleda, minute_pregleda), datum(dan_pregleda, mjesec_pregleda, godina_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta) { ime = ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { datum = novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme = novo_vrijeme; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime; }
    Datum DajDatumPregleda() const { return datum; }
    Vrijeme DajVrijemePregleda() const { return vrijeme; }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const { std::cout << std::setw(29) << std::left << std::setfill(' ') << ime << " "; datum.Ispisi(); std::cout << " "; vrijeme.Ispisi(); std::cout << std::endl; }
};
 
 void Pregled::PomjeriDanUnaprijed() 
 {
     int d,m,g;
     int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
     std::tuple<int,int,int> t(datum.Ocitaj());
     std::tie(d,m,g) = t;
     if(d == broj_dana[m - 1]) {
         d = 1; m++;
         if(m == 13) {
             m = 1; g++;
         }
     } else { d++; }
     datum.Postavi(d,m,g);
 }
 
 void Pregled::PomjeriDanUnazad() 
 {
     int d,m,g;
     int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     if((g % 4 == 0 && g % 100 != 0) || g % 400 == 0) broj_dana[1]++;
     std::tuple<int,int,int> t(datum.Ocitaj());
     std::tie(d,m,g) = t;
     if(d == 1) {
        if(--m = 0) {
            m = 12; g--;
        }
        d = broj_dana[m - 1];
     } else { d--; }
     datum.Postavi(d,m,g);
 }
 
 bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) 
 {
     int d1,m1,g1,s1,min1,d2,m2,g2,s2,min2;
     std::tie(s1,min1) = p1.vrijeme.Ocitaj();
     std::tie(s2,min2) = p2.vrijeme.Ocitaj();
     std::tie(d1,m1,g1) = p1.datum.Ocitaj();
     std::tie(d2,m2,g2) = p2.datum.Ocitaj();
     if(g1 < g2) return true;
     else if(g1 == g2 && m1 < m2) return true;
     else if(g1 == g2 && m1 == m2 && d1 < d2) return true;
     else if(g1 == g2 && m1 == m2 && d1 == d2 && s1 < s2) return true;
     else if(g1 == g2 && m1 == m2 && d1 == d2 && s1 == s2 && min1 < min2) return true;
     else return false;
 }
 
class Pregledi {
    int max_broj_pregleda;
    int broj_pregleda;
    Pregled **pregledii;
    int brojac = 0;
  public:
  explicit Pregledi(int max_broj_pregleda) : broj_pregleda(0), pregledii(new Pregled*[max_broj_pregleda] {}), max_broj_pregleda(max_broj_pregleda) {}
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
    int DajBrojObrisanihPregleda() { return brojac; }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;

};
 
Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()), broj_pregleda(spisak_pregleda.size()), pregledii(new Pregled*[spisak_pregleda.size()] {})
{
     int i(0);
		try {
			for(auto x : spisak_pregleda) pregledii[i++] = new Pregled(x);
		} catch(...) {
			for(int i = 0; i < broj_pregleda; i++) delete pregledii[i];
			delete[] pregledii;
			throw;
		}
}

Pregledi::~Pregledi() 
{
    for(int i = 0; i < broj_pregleda; i++) delete pregledii[i];
		delete[] pregledii; broj_pregleda = 0;
}

Pregledi::Pregledi(const Pregledi &pregledi) : pregledii(new Pregled*[pregledi.broj_pregleda] {}), max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda)
{
    try {
        for(int i = 0; i < broj_pregleda; i++) {
            pregledii[i] = new Pregled(*pregledi.pregledii[i]);
        }
    } catch (...) {
        for(int i = 0; i < broj_pregleda; i++) delete pregledii[i];
		delete[] pregledii; throw;
    }
}

Pregledi &Pregledi::operator =(const Pregledi &pregledi)
{
	if(max_broj_pregleda != pregledi.max_broj_pregleda) throw; 
	if(broj_pregleda < pregledi.broj_pregleda) {
		try {
			for(int i = 0; i < broj_pregleda; i++) delete pregledii[i];
			for(int i = 0; i < pregledi.broj_pregleda; i++) {
				pregledii[i] = new Pregled(*pregledi.pregledii[i]);
			}
		} catch(...) {
			for(int i = 0; i < broj_pregleda; i++) delete pregledii[i];
			delete[] pregledii;
		}
	} else {
		for(int i = pregledi.broj_pregleda; i < broj_pregleda; i++) {
			delete pregledii[i];
			pregledii[i] = nullptr;
		}
	}
	broj_pregleda = pregledi.broj_pregleda;
	for(int i = 0; i < broj_pregleda; i++) {
		*pregledii[i] = *pregledi.pregledii[i];
	}
	return *this;

}

Pregledi::Pregledi(Pregledi &&pregledi) : pregledii(pregledi.pregledii), max_broj_pregleda(pregledi.max_broj_pregleda), broj_pregleda(pregledi.broj_pregleda)
{
    pregledi.pregledii = nullptr;
    pregledi.broj_pregleda = 0;
}
 
Pregledi &Pregledi::operator =(Pregledi &&pregledi)
{
    if(max_broj_pregleda != pregledi.max_broj_pregleda) throw;
    std::swap(broj_pregleda, pregledi.broj_pregleda);
    std::swap(pregledii, pregledi.pregledii);
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda)
{
    broj_pregleda++;
    if(broj_pregleda > max_broj_pregleda) {
        broj_pregleda--;
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    try {
        pregledii[broj_pregleda - 1] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    } catch(...) {
        throw;
    }
}
 
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda)
{
    broj_pregleda++;
    if(broj_pregleda > max_broj_pregleda) {
        broj_pregleda--;
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    try {
        pregledii[broj_pregleda - 1] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    } catch(...) {
       throw;
    }
}

void Pregledi::RegistrirajPregled(Pregled *pregled)
{
    broj_pregleda++;
    if(broj_pregleda > max_broj_pregleda) {
        broj_pregleda--;
        delete pregled;
        throw std::range_error("Dostignut maksimalni broj pregleda");
    }
    try {
        pregledii[broj_pregleda - 1] = new Pregled(pregled->DajImePacijenta(), pregled->DajDatumPregleda(), pregled->DajVrijemePregleda());
        delete pregled;
    } catch(...) {
        throw;
    }
    
}

int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const 
{
    int d1,m1,g1;
    std::tie(d1,m1,g1) = datum.Ocitaj();
    return std::count_if(pregledii, pregledii + broj_pregleda, [&datum,&d1,&m1,&g1] (Pregled *pok) {
        int d,m,g;
        std::tie(d,m,g) = pok->DajDatumPregleda().Ocitaj();
        
        return (d == d1 && m1 == m && g == g1);
    });
}

Pregled &Pregledi::DajNajranijiPregled()
{
    if(!broj_pregleda) throw std::domain_error("Nema registriranih pregleda");
    return (**std::min_element(pregledii, pregledii + broj_pregleda, [] (Pregled *pok, Pregled *pok1){
        int d,m,g,d1,m1,g1,s,min,s1,min1;
        std::tie(d,m,g) = pok->DajDatumPregleda().Ocitaj();
        std::tie(d1,m1,g1) = pok1->DajDatumPregleda().Ocitaj();
        std::tie(s,min) = pok->DajVrijemePregleda().Ocitaj();
        std::tie(s1,min1) = pok1->DajVrijemePregleda().Ocitaj();
        if(g < g1) return true;
        else if(g == g1 && m < m1) return true;
        else if(g == g1 && m == m1 && d < d1) return true;
        else if(g == g1 && m == m1 && d == d1 && s < s1) return true;
        else if(g == g1 && m == m1 && d == d1 && s == s1 && min < min1) return true;
        return false;
    }));
}

Pregled Pregledi::DajNajranijiPregled() const
{
    if(!broj_pregleda) throw std::domain_error("Nema registriranih pregleda");
    return (**std::min_element(pregledii, pregledii + broj_pregleda, [] (Pregled *pok, Pregled *pok1){
        int d,m,g,d1,m1,g1,s,min,s1,min1;
        std::tie(d,m,g) = pok->DajDatumPregleda().Ocitaj();
        std::tie(d1,m1,g1) = pok1->DajDatumPregleda().Ocitaj();
        std::tie(s,min) = pok->DajVrijemePregleda().Ocitaj();
        std::tie(s1,min1) = pok1->DajVrijemePregleda().Ocitaj();
        if(g < g1) return true;
        else if(g == g1 && m < m1) return true;
        else if(g == g1 && m == m1 && d < d1) return true;
        else if(g == g1 && m == m1 && d == d1 && s < s1) return true;
        else if(g == g1 && m == m1 && d == d1 && s == s1 && min < min1) return true;
        return false;
    }));
}

void Pregledi::IsprazniKolekciju()
{
     for(int i = 0; i < broj_pregleda; i++) {
        delete pregledii[i];
        pregledii[i] = nullptr;
     }
	broj_pregleda = 0;	
}

void Pregledi::ObrisiNajranijiPregled()
{
    if(broj_pregleda == 0) throw std::domain_error("Prazna kolekcija");
    int d,m,g,d1,m1,g1,s,min,s1,min1;
    int brojac(0);
    std::tie(d,m,g) = DajNajranijiPregled().DajDatumPregleda().Ocitaj();
    std::tie(s,min) = DajNajranijiPregled().DajVrijemePregleda().Ocitaj();
    for(int i = 0; i < broj_pregleda; i++) {
        std::tie(d1,m1,g1) = pregledii[i]->DajDatumPregleda().Ocitaj();
        std::tie(s1,min1) = pregledii[i]->DajVrijemePregleda().Ocitaj();
       if(g == g1 && m == m1 && d == d1 && s == s1 && min == min1) {
           delete pregledii[i]; pregledii[i] = nullptr; brojac++;
       }
    }
    std::remove_copy(pregledii, pregledii + broj_pregleda, pregledii, nullptr);
    broj_pregleda -= brojac;
}

void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta)
{
    int brojac(0);
    for(int i = 0; i < broj_pregleda; i++) {
        if(pregledii[i]->DajImePacijenta() == ime_pacijenta) {
            delete pregledii[i]; pregledii[i] = nullptr; brojac++; Pregledi::brojac++;
        }
    }
    std::remove_copy(pregledii, pregledii + broj_pregleda, pregledii, nullptr);
    broj_pregleda -= brojac;
}

void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const
{
    int brojac(0),d,m,g,d1,m1,g1;
    std::tie(d,m,g) = datum.Ocitaj();
    for(int i = 0; i < broj_pregleda; i++) {
        std::tie(d1,m1,g1) = pregledii[i]->DajDatumPregleda().Ocitaj();
        if(d == d1 && m == m1 && g == g1) brojac++;
    }
    std::vector<Pregled*> pregledi_tmp(brojac);
    brojac = 0;
    try {
        for(int i = 0; i < broj_pregleda; i++) {
            std::tie(d1,m1,g1) = pregledii[i]->DajDatumPregleda().Ocitaj();
            if(d == d1 && m == m1 && g == g1) {
                pregledi_tmp[brojac] = new Pregled(*pregledii[i]);
                brojac++;
            }
        }
    } catch(...) {
        throw;
    }
    std::sort(pregledi_tmp.begin(), pregledi_tmp.end(), [] (Pregled * pok, Pregled *pok1) {
        return Pregled::DolaziPrije(*pok, *pok1);
    });
    
    for(int i = 0; i < brojac; i++) {
         pregledi_tmp[i]->Ispisi();
     }
    for(int i = 0; i < brojac; i++) delete pregledi_tmp[i];
}

void Pregledi::IspisiSvePreglede() const
{
    std::vector<Pregled*> pregledi_tmp(broj_pregleda);
    try {
        for(int i = 0; i < broj_pregleda; i++) {
                pregledi_tmp[i] = new Pregled(*pregledii[i]);
            }
    } catch(...) {
        throw;
    }
    std::sort(pregledi_tmp.begin(), pregledi_tmp.end(), [] (Pregled *pok, Pregled *pok1) {
        return Pregled::DolaziPrije(*pok, *pok1);
    });
    for(int i = 0; i < pregledi_tmp.size(); i++) {
         pregledi_tmp[i]->Ispisi();
     }
    for(int i = 0; i < pregledi_tmp.size(); i++) delete pregledi_tmp[i];   
}

int main ()
{
   int n,d,m,g,s,min;
   std::cout << "Unesite maksimalan broj pregleda: ";
   std::cin >> n;
   std::cin.ignore(10000,'\n');
   Pregledi pregledi(n);
   for(int i = 0; i < n; i++) {
       std::string s1;
       std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
       std::getline (std::cin,s1);
       if(s1 == "kraj") {
           break;
       }
       std::cout << "Unesite dan mjesec i godinu pregleda: ";
       std::cin >> d >> m >> g;
       std::cout << "Unesite sate i minute pregleda: ";
       std::cin >> s >> min;
       try {
          pregledi.RegistrirajPregled(s1,d,m,g,s,min);
       } catch (std::range_error iz) {
         std::cout << iz.what() << std::endl;   
       }
       std::cin.ignore(10000,'\n');
   }
   std::cout << "Trenutno su registrovani sljedeci pregledi \n";
   pregledi.IspisiSvePreglede();
   std::cout << std::endl;
   
   int k;
   do {
       std::cout << "Odaberite jednu od sljedecih opcija" << std::endl;
       std::cout << "1 - Broj pregleda na datum\n" <<  "2 - Najraniji pregled\n" << "3 - Obrisi pregled pacijenta\n" << "4 - Obrisi najraniji pregled\n" << "5 - Ispisi sve pregleda na datum\n" << "6 - Ispisi sve preglede\n"
       << "7 - Kraj programa\n";
       std::cin >> k;
       if(k == 1) {
           std::cout << "Unesite dan mjesec i godinu : ";
           std:: cin >> d >> m >> g;
           std::cout << "Broj pregleda na datum " << d << " " << m << " " << g << " je: " << pregledi.DajBrojPregledaNaDatum(Datum(d,m,g));  std::cout << std::endl;
           std::cout << std::endl;
       } else if(k == 2){
           std::cout << "Najraniji pregled je: \n"; pregledi.DajNajranijiPregled().Ispisi(); std::cout << std::endl;
       } else if(k == 3){
           std::cout << "Unesite ime pacijenta: ";
           std::string s2;
           std::cin.ignore(10000,'\n');
           std::getline(std::cin, s2);
           pregledi.ObrisiPregledePacijenta(s2);
           std::cout << "Uspjesno obrisano " << pregledi.DajBrojObrisanihPregleda() << " pregleda";
           std::cout << std::endl;
       } else if(k == 4){
           try {
              pregledi.ObrisiNajranijiPregled();
              std::cout << "Najraniji pregled uspjesno obrisan\n";
              std::cout << std::endl;
           } catch(std::range_error izuzetak) {
               std::cout << izuzetak.what() << std::endl;
           }
       } else if(k == 5){
           std::cout << "Unesite dan mjesec i godinu : ";
           std:: cin >> d >> m >> g;
           std::cout << "Pregledi na datum " << d << " " << m << " " << g << " su:\n"; pregledi.IspisiPregledeNaDatum(Datum(d,m,g)); std::cout << std::endl;
       } else if(k == 6) {
           pregledi.IspisiSvePreglede();
           std::cout << std::endl;
       }  
   } while(k != 7);
   
	return 0;
}
