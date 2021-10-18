/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include "tuple"
#include "stdexcept"
#include "utility"
#include "cstdio"
#include "string"
#include "iomanip"
#include "initializer_list"
#include "algorithm"
using std::string;

class Datum {
    int d, m, y;
    public:
    Datum(int dan, int mjesec, int godina) {
        if(dan <= 0 || dan > 31 || mjesec <= 0 || mjesec > 12) throw std::domain_error("Neispravan datum");
        this->d = dan;
        this->m = mjesec;
        this->y = godina;
    }
    
    void Postavi(int dan, int mjesec, int godina) {
        if(dan <= 0 || dan > 31 || mjesec <= 0 || mjesec > 12) throw std::domain_error("Neispravan datum");
        d = dan;
        m = mjesec;
        y = godina;
    }
    
    std::tuple<int, int, int> Ocitaj() const {
        return std::make_tuple(d, m, y);
    }
    
    void Ispisi() const {
        std::cout << d << "/" << m << "/" << y;
    }
};

class Vrijeme {
  int hr, min;
  public:
  Vrijeme(int sati, int minute) {
      if(sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
      this->hr = sati;
      this->min = minute;
  }
  
  void Postavi(int sati, int minute) {
      if(sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
      hr = sati;
      min = minute;
  }
  
  std::pair<int, int> Ocitaj() const {
      return std::make_pair(hr, min);
  }
  
  void Ispisi() const {
      std::printf("%02d:%02d", hr, min);
  }
};

class Pregled {
    string ime;
    Datum datum;
    Vrijeme vrijeme;
    public:
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): 
    datum(std::get<0>(datum_pregleda.Ocitaj()), std::get<1>(datum_pregleda.Ocitaj()), std::get<2>(datum_pregleda.Ocitaj())),
    vrijeme(std::get<0>(vrijeme_pregleda.Ocitaj()), std::get<1>(vrijeme_pregleda.Ocitaj())) {
        this->ime = ime_pacijenta;
    }
    
    Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda): datum(dan_pregleda, mjesec_pregleda, godina_pregleda),
    vrijeme(sati_pregleda, minute_pregleda) {
        this->ime = ime_pacijenta;
    }
    
    void PromijeniPacijenta(const string &ime_pacijenta) { ime = ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { datum = novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme = novo_vrijeme; }
    void PomjeriDanUnaprijed() { 
        int dan, mjesec, godina;
        std::tie(dan, mjesec, godina) = datum.Ocitaj();
        dan++;
        if(dan > 31) { mjesec++; dan = 1; }
        if(mjesec > 12) { godina++; mjesec = 1; }
        
        datum = Datum(dan, mjesec, godina);
    }
    
    void PomjeriDanUnazad() {
        int dan, mjesec, godina;
        std::tie(dan, mjesec, godina) = datum.Ocitaj();
        dan--;
        if(dan <= 0) { mjesec--; dan = 31; }
        if(mjesec <= 0) { godina--; mjesec = 12; }
        if(godina < 0) godina = 0;
        
        datum = Datum(dan, mjesec, godina);
    }
    
    string DajImePacijenta() const { return ime; }
    Datum DajDatumPregleda() const { return datum; }
    Vrijeme DajVrijemePregleda() const { return vrijeme; }
    
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    
    void Ispisi() {
        std::cout << std::left << std::setw(30) << ime;
        DajDatumPregleda().Ispisi();
        std::cout << " ";
        DajVrijemePregleda().Ispisi();
        std::cout << std::endl;
    }
};
Pregled **pregggled;
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    int dan1, dan2, god1, god2, mj1, mj2;
    std::pair<int, int> v1, v2;
    
    std::tie(dan1, mj1, god1) = p1.DajDatumPregleda().Ocitaj();
    std::tie(dan2, mj2, god2) = p2.DajDatumPregleda().Ocitaj();
    
    v1 = p1.DajVrijemePregleda().Ocitaj();
    v2 = p2.DajVrijemePregleda().Ocitaj();
    
    if (dan1 < dan2 && mj1 < mj2 && god1 < god2) return (std::get<0>(v1) < std::get<0>(v2) && std::get<1>(v1) < std::get<1>(v2));
    else return false;
}

class Pregledi {
    int maxx;
    Pregled **pregled;
    public:
    explicit Pregledi(int max_broj_pregleda): maxx(max_broj_pregleda), pregled(new Pregled*[max_broj_pregleda]{}) {
        
    }
    
    Pregledi(std::initializer_list<Pregled> spisak_pregleda): maxx(spisak_pregleda.size()), pregled(new Pregled*[spisak_pregleda.size()]{}) {
        int i(0);
        try {
            for(auto it = spisak_pregleda.begin(); it != spisak_pregleda.end(); it++) {
                pregled[i] = new Pregled(*it);
                i++;
            }
        } catch(...) {
            for(int j = 0; j < maxx; j++)
                delete pregled[j];
            delete[] pregled;
        }
    }
    
    ~Pregledi() {
        for(int i = 0; i < maxx; i++)
            delete pregled[i];
        delete[] pregled;
    }
    
    Pregledi(const Pregledi &pregledi): maxx(pregledi.maxx), pregled(new Pregled*[pregledi.maxx]{}) {
        try {
            for(int i = 0; i < maxx; i++) {
                pregled[i] = new Pregled(*pregledi.pregled[i]);
            }
        } catch(...) {
            for(int i = 0; i < maxx; i++)
                delete pregled[i];
            delete[] pregled;
        }
    }
    
    Pregledi(Pregledi &&pregledi): maxx(pregledi.maxx), pregled(new Pregled*[pregledi.maxx]{}) {
        try {
            for(int i = 0; i < maxx; i++) {
                pregled[i] = new Pregled(*pregledi.pregled[i]);
            }
        } catch(...) {
            for(int i = 0; i < maxx; i++)
                delete pregled[i];
            delete[] pregled;
        }
    }
    
    Pregledi &operator =(const Pregledi &pregledi) {
        maxx = pregledi.maxx;
        try {
            for(int i = 0; i < maxx; i++) {
                pregled[i] = new Pregled(*pregledi.pregled[i]);
            }
        } catch(...) {
            for(int i = 0; i < maxx; i++)
                delete pregled[i];
            delete[] pregled;
        }
        return *this;
    }
    
    Pregledi &operator =(Pregledi &&pregledi) {
        maxx = pregledi.maxx;
        try {
            for(int i = 0; i < maxx; i++) {
                pregled[i] = new Pregled(*pregledi.pregled[i]);
            }
        } catch(...) {
            for(int i = 0; i < maxx; i++)
                delete pregled[i];
            delete[] pregled;
        }
        return *this;
    }
    
    void RegistrirajPregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        int current(0);
        for(; current < maxx; current++)
            if(pregled[current] == nullptr) break;
        if(current + 1 >= maxx) throw std::range_error("Dostignut maksimalan broj pregleda");
        pregled[current] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda);
    }
    
    void RegistrirajPregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        int current(0);
        for(; current < maxx; current++)
            if(pregled[current] == nullptr) break;
        if(current + 1 >= maxx) throw std::range_error("Dostignut maksimalan broj pregleda");
        pregled[current] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    }
    
    void RegistrirajPregled(Pregled *pregled) {
        int current(0);
        for(; current < maxx; current++)
            if(this->pregled[current] == nullptr) break;
        if(current >= maxx) throw std::range_error("Dostignut maksimalan broj pregleda");
        this->pregled[current] = new Pregled(*pregled);
    }
    
    int DajBrojPregleda() const { return maxx; }
    int DajBrojPregledaNaDatum(const Datum &datum) const {
        int d2, m2, g2; std::tie(d2, m2, g2) = datum.Ocitaj();
        int broj(std::count_if(pregled, pregled + maxx, [datum, d2, m2, g2](Pregled *p)->bool{if(p == nullptr) return false; 
        int d1, m1, g1; std::tie(d1, m1, g1) = p->DajDatumPregleda().Ocitaj(); return(d1 == d2 && m1 == m2 && g1 == g2);}));
        return broj;
    }
    
    Pregled &DajNajranijiPregled() {
        int count(0); pregggled = new Pregled*[maxx]{};
        try {
        for(int i = 0; i < maxx; i++) {
                if(pregled[i] == nullptr) continue;
                pregggled[count] = new Pregled(*pregled[i]);
                count++;
            }
        } catch(...) {
            for(int i = 0; i < maxx; i++)
                delete pregggled[i];
            delete[] pregggled;
            return **pregled;
        }
        if(count == 0) throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(pregggled, pregggled + count, [](Pregled *preg1, Pregled *preg2)->bool{int curhr(std::get<0>(preg1->DajVrijemePregleda().Ocitaj())), 
            curmin(std::get<1>(preg1->DajVrijemePregleda().Ocitaj())), 
            temphr(std::get<0>(preg2->DajVrijemePregleda().Ocitaj())), 
            tempmin(std::get<1>(preg2->DajVrijemePregleda().Ocitaj())), curyear, curmon, curday, tempyear, tempday, tempmon;
            std::tie(curday, curmon, curyear) = preg1->DajDatumPregleda().Ocitaj();
            std::tie(tempday, tempmon, tempyear) = preg2->DajDatumPregleda().Ocitaj();
            if(curyear == tempyear && curmon == tempmon && curday == tempday && curhr == temphr && curmin > tempmin)return false;
            else if (curyear == tempyear && curmon == tempmon && curday == tempday && curhr > temphr)return false;
            else if(curyear == tempyear && curmon == tempmon && curday > tempday)return false;
            else if(curyear == tempyear && curmon > tempmon)return false;
            else if(curyear > tempyear) return false;
            return true;
        });
    }
    
    Pregled DajNajranijiPregled() const {
        int count(0); Pregled **p = new Pregled*[maxx]{};
        try {
        for(int i = 0; i < maxx; i++) {
                if(pregled[i] == nullptr) continue;
                p[count] = new Pregled(*pregled[i]);
                count++;
            }
        } catch(...) {
            for(int i = 0; i < maxx; i++)
                delete p[i];
            delete[] p;
            return **pregled;
        }
        if(count == 0) throw std::domain_error("Nema registriranih pregleda");
        return **std::min_element(p, p + count, [](Pregled *preg1, Pregled *preg2)->bool{int curhr(std::get<0>(preg1->DajVrijemePregleda().Ocitaj())), 
            curmin(std::get<1>(preg1->DajVrijemePregleda().Ocitaj())), 
            temphr(std::get<0>(preg2->DajVrijemePregleda().Ocitaj())), 
            tempmin(std::get<1>(preg2->DajVrijemePregleda().Ocitaj())), curyear, curmon, curday, tempyear, tempday, tempmon;
            std::tie(curday, curmon, curyear) = preg1->DajDatumPregleda().Ocitaj();
            std::tie(tempday, tempmon, tempyear) = preg2->DajDatumPregleda().Ocitaj();
            if(curyear == tempyear && curmon == tempmon && curday == tempday && curhr == temphr && curmin > tempmin)return false;
            else if (curyear == tempyear && curmon == tempmon && curday == tempday && curhr > temphr)return false;
            else if(curyear == tempyear && curmon == tempmon && curday > tempday)return false;
            else if(curyear == tempyear && curmon > tempmon)return false;
            else if(curyear > tempyear) return false;
            return true; 
        });
        
    }
    
    void IsprazniKolekciju() {
        for(int i = 0; i < maxx; i++) { delete pregled[i]; pregled[i] = nullptr; }
    }
    
    void ObrisiNajranijiPregled() {
        int count(0); Pregled **p = new Pregled*[maxx]{};
        try{
            for(int i = 0; i < maxx; i++) {
                if(pregled[i] == nullptr) continue;
                p[count] = new Pregled(*pregled[i]);
                count++;
            }
        }catch(...) {
            for(int i = 0; i < maxx; i++)
                delete p[i];
            delete[] p;
            return;
        }
        if(count == 0) throw std::domain_error("Nema registriranih pregleda");
        auto tjt = *std::min_element(p, p + count, [](Pregled *p1, Pregled *p2)->bool{int curhr(std::get<0>(p1->DajVrijemePregleda().Ocitaj())), 
            curmin(std::get<1>(p1->DajVrijemePregleda().Ocitaj())), 
            temphr(std::get<0>(p2->DajVrijemePregleda().Ocitaj())), 
            tempmin(std::get<1>(p2->DajVrijemePregleda().Ocitaj())), curyear, curmon, curday, tempyear, tempday, tempmon;
            std::tie(curday, curmon, curyear) = p1->DajDatumPregleda().Ocitaj();
            std::tie(tempday, tempmon, tempyear) = p2->DajDatumPregleda().Ocitaj();
            if(curyear == tempyear && curmon == tempmon && curday == tempday && curhr == temphr && curmin > tempmin)return false;
            else if (curyear == tempyear && curmon == tempmon && curday == tempday && curhr > temphr)return false;
            else if(curyear == tempyear && curmon == tempmon && curday > tempday)return false;
            else if(curyear == tempyear && curmon > tempmon)return false;
            else if(curyear > tempyear) return false;
            return true; 
        });
        int curhr(std::get<0>(tjt->DajVrijemePregleda().Ocitaj())), 
            curmin(std::get<1>(tjt->DajVrijemePregleda().Ocitaj())), 
            curyear, curmon, curday;
            std::tie(curday, curmon, curyear) = tjt->DajDatumPregleda().Ocitaj();
            
        for(int i = 0; i < maxx; i++) { if(pregled[i] != nullptr) {
            int temphr(std::get<0>(pregled[i]->DajVrijemePregleda().Ocitaj())), 
            tempmin(std::get<1>(pregled[i]->DajVrijemePregleda().Ocitaj())), tempday, tempmon, tempyear; 
            std::tie(tempday, tempmon, tempyear) = pregled[i]->DajDatumPregleda().Ocitaj();
            if(curday == tempday && curmon == tempmon && curyear == tempyear && curhr == temphr && curmin == tempmin) { delete pregled[i]; pregled[i] = nullptr; }
        }
                delete p[i];
        }
            delete[] p;
    }
    
    void ObrisiPregledePacijenta(const string &ime_pacijenta) {
        int brojpac(0);
        for(int i = 0; i < maxx; i++)
            if(pregled[i] != nullptr)
                if(ime_pacijenta.compare(pregled[i]->DajImePacijenta()) == 0) { delete pregled[i]; pregled[i] = nullptr; brojpac++;}
        std::cout << "Uspjesno obrisano "<< brojpac <<" pregleda\n";
    }
    
    void IspisiPregledeNaDatum(const Datum &datum) const {
        int d, m, g, count(0); std::tie(d, m, g) = datum.Ocitaj(); Pregled **p = new Pregled*[maxx]{}; 
        try {
            for(int i = 0; i < maxx; i++) {
                if(pregled[i] == nullptr) continue;
                    int d1, m1, g1; std::tie(d1, m1, g1) = pregled[i]->DajDatumPregleda().Ocitaj();
                    if(d == d1 && m == m1 && g == g1) { p[count] = new Pregled(*pregled[i]); count++; }
                
            }
        } catch(...) {
            for(int i = 0; i < maxx; i++)
                delete p[i];
            delete[] p;
            return;
        }
        if(count == 0) { delete[] p; return; }
        std::sort(p, p+count, [](Pregled *preg1, Pregled *preg2)->bool{
            int h(std::get<0>(preg1->DajVrijemePregleda().Ocitaj())), 
            m(std::get<1>(preg1->DajVrijemePregleda().Ocitaj())), 
            h1(std::get<0>(preg2->DajVrijemePregleda().Ocitaj())), 
            m1(std::get<1>(preg2->DajVrijemePregleda().Ocitaj())); 
            return (h >= h1 && m >= m1); //checkX
        });
        for(int i = 0; i < count; i++) p[i]->Ispisi();
        for(int i = 0; i < maxx; i++)
            delete p[i];
        delete[] p;
    }
    
    void IspisiSvePreglede() const {
        if(maxx == 0) return;
        Pregled **p = new Pregled*[maxx]{};
        int count(0);
        try {
            for(int i = 0; i < maxx; i++) {
                if(pregled[i] == nullptr) continue;
                p[count] = new Pregled(*pregled[i]);
                count++;
            }
        } catch(...) {
            for(int i = 0; i < maxx; i++)
                delete p[i];
            delete[] p;
            return;
        }
        
        std::sort(p, p+count, [](Pregled *preg1, Pregled *preg2)->bool{
            int curhr(std::get<0>(preg1->DajVrijemePregleda().Ocitaj())), 
            curmin(std::get<1>(preg1->DajVrijemePregleda().Ocitaj())), 
            temphr(std::get<0>(preg2->DajVrijemePregleda().Ocitaj())), 
            tempmin(std::get<1>(preg2->DajVrijemePregleda().Ocitaj())), curyear, curmon, curday, tempyear, tempday, tempmon;
            std::tie(curday, curmon, curyear) = preg1->DajDatumPregleda().Ocitaj();
            std::tie(tempday, tempmon, tempyear) = preg2->DajDatumPregleda().Ocitaj();
            if(curyear == tempyear && curmon == tempmon && curday == tempday && curhr == temphr && curmin > tempmin)return false;
            else if (curyear == tempyear && curmon == tempmon && curday == tempday && curhr > temphr)return false;
            else if(curyear == tempyear && curmon == tempmon && curday > tempday)return false;
            else if(curyear == tempyear && curmon > tempmon)return false;
            else if(curyear > tempyear) return false;
            return true;
        });
        for(int i = 0; i < maxx; i++) { if(p[i] != nullptr) p[i]->Ispisi(); delete p[i]; }
        delete[] p;
    }
};

bool comp(Datum &da1, Datum &da2) {
    int d1, d2, m1, m2, g1, g2;
    std::tie(d1, m1, g1) = da1.Ocitaj();
    std::tie(d2, m2, g2) = da2.Ocitaj();
    return (d1 == d2 && m1 == m2 && g1 == g2);
}

int main ()
{
    string ende;
    int max(0);
    std::cout << "Unesite maksimalan broj pregleda: ";
    std::cin >> max;
    Pregledi preg(max);
    string ime;
    int dan, mjesec, godina;
    int sahat, minute;
    std::cin.clear(); std::cin.ignore(10000, '\n');
    try {
        for(int i = 0; i < max; i++) {
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::getline(std::cin, ime);
            if(ime == "kraj") break;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            std::cin >> dan >> mjesec >> godina; std::cin.get();
            Datum dat(dan, mjesec, godina);
            std::cout << "Unesite sate i minute pregleda: ";
            std::cin >> sahat >> minute;std::cin.get();
            Vrijeme vr(sahat, minute);
            Pregled pre(ime, dat, vr);
            preg.RegistrirajPregled(&pre);
        }
    } catch(...) {
        std::cout << "error";
    }
    std::cout << "Trenutno su registrovani sljedeci pregledi\n";
    preg.IspisiSvePreglede();
    std::cout << std::endl;
    int dec(0);
    
    while(dec != 7) {
        int dan, mj, god;
        std::cout << "Odaberite jednu od sljedecih opcija" << std::endl << "1 - Broj pregleda na datum" << std::endl << "2 - Najraniji pregled" << std::endl 
        << "3 - Obrisi pregled pacijenta" << std::endl <<"4 - Obrisi najraniji pregled" << std::endl << "5 - Ispisi sve pregleda na datum"<< std::endl 
        << "6 - Ispisi sve preglede" << std::endl << "7 - Kraj programa\n";
        std::cin >> dec;
        switch(dec) {
            case 1: std::cout << "Unesite dan mjesec i godinu : "; 
                    std::cin >> dan >> mj >> god;  std::cout << "Broj pregleda na datum " << dan << " " << mj << " " << god << " je: " << preg.DajBrojPregledaNaDatum(Datum(dan, mj, god));
                    std::cout << std::endl; break;
            case 2: std::cout << "Najraniji pregled je:\n"; preg.DajNajranijiPregled().Ispisi();
            for(int i = 0; i < max; i++) 
            delete pregggled[i]; 
            delete[] pregggled; break;
            case 3: std::cout << "Unesite ime pacijenta: "; std::cin >> ende; preg.ObrisiPregledePacijenta(ende); break;
            case 4: preg.ObrisiNajranijiPregled(); std::cout << "Najraniji pregled uspjesno obrisan\n"; break;
            case 5: std::cout << "Unesite dan mjesec i godinu : ";
                    std::cin >> dan >> mj >> god;
                    std::cout << "Pregledi na datum " << dan << " " << mj << " " << god << " su:\n";
                    preg.IspisiPregledeNaDatum(Datum(dan, mj, god)); break;
            case 6: preg.IspisiSvePreglede(); break;
            case 7: return 0;
            default: break;
        }
        std::cout << std::endl;
        
    }
	return 0;
}
