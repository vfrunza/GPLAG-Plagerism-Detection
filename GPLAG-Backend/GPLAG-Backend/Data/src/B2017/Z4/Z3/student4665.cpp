/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include<stdexcept>
#include<string>
#include<iomanip>
#include<algorithm>
#include<initializer_list>
class Datum {
    int dan,mjesec,godina;
    public:
    Datum(int dan, int mjesec, int godina){ Postavi(dan,mjesec,godina);}
    void Postavi(int dan, int mjesec, int godina);
    int DajDan() const {return dan;}
    int DajMjesec() const{ return mjesec;}
    int DajGodinu() const{ return godina;}
    void Ispisi() const{ std::cout<< dan << "/" << mjesec << "/" << godina;}
    
};
class Vrijeme {
    int sati, minute;
    public:
    Vrijeme(int sati, int minute){ Postavi(sati, minute);}
    void Postavi(int sati, int minute);
    int DajSate() const { return sati;}
    int DajMinute() const{ return minute;}
    void Ispisi() const { if (sati<10) std::cout << "0" << sati << ":"; else std::cout << sati << ":";
    if(minute <10) std::cout << "0" << minute; else std::cout << minute;}
    
};
class Pregled {
    std::string ime;
    Datum datum;
    Vrijeme vrijeme;
public:
    Pregled(const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda): ime(ime_pacijenta), datum(datum_pregleda), vrijeme(vrijeme_pregleda) {}
    Pregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda): 
    ime(ime_pacijenta), datum(dan_pregleda, mjesec_pregleda, godina_pregleda), vrijeme(sati_pregleda, minute_pregleda) {}
    void PromijeniPacijenta(const std::string &ime_pacijenta) { ime = ime_pacijenta;}
    void PromijeniDatum(const Datum &novi_datum) { datum = novi_datum;}
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme = novo_vrijeme;}
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();
    std::string DajImePacijenta() const { return ime; }
    Datum DajDatumPregleda() const{ return datum; }
    Vrijeme DajVrijemePregleda() const{ return vrijeme;}
    friend bool DolaziPrije(const Pregled &p1, const Pregled &p2);
    void Ispisi() const {  
        if(datum.DajDan() > 10) {
            std::cout << ime << " "; std::cout.width(31 - ime.size());datum.Ispisi(); std::cout << " "; vrijeme.Ispisi(); std::cout << std::endl;
        }
        else {
            std::cout << ime << " "; std::cout.width(30 - ime.size());datum.Ispisi(); std::cout << " "; vrijeme.Ispisi(); std::cout << std::endl;
        }

    }
};
class Pregledi {
    int kapacitet;
    int evidentirani;
    Pregled **pregledi;
    public:
    explicit Pregledi(int max_broj_pregleda): kapacitet(max_broj_pregleda), evidentirani(0), pregledi(new Pregled*[max_broj_pregleda]) {}
    Pregledi(std::initializer_list<Pregled> spisak_pregleda): kapacitet(spisak_pregleda.size()), evidentirani(spisak_pregleda.size()), pregledi(new Pregled*[spisak_pregleda.size()]) {int j(0);for(auto i = std::begin(spisak_pregleda); i != std::end(spisak_pregleda); i++) this -> pregledi[j++] = new Pregled(*i);}
    ~Pregledi();
    
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    void RegistrirajPregled(const std::string &ime_pacijenta,
    const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,
    int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    int DajBrojPregleda() const { return evidentirani; }
    int DajBrojPregledaNaDatum(const Datum &datum) const;
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IsprazniKolekciju();
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    void IspisiPregledeNaDatum(Datum &datum) const;
    void IspisiSvePreglede() const;
};



int main (){
    try {
        std::cout << "Unesite maksimalan broj pregleda: ";
        int max_br_pregleda;
        std::cin >> max_br_pregleda;
        Pregledi pregledi(max_br_pregleda);
        int j= 0;
        do {
            std::string ime;
            std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
            std::cin >> ime;
            if(ime == "kraj") break;
            std::cout << "Unesite dan mjesec i godinu pregleda: ";
            int dan, mjesec, godina;
            std::cin >> dan >> mjesec >> godina;
            Datum datum(dan, mjesec, godina);
            std::cout << "Unesite sate i minute pregleda: ";
            int sati, minute;
            std::cin >> sati >> minute;
            Vrijeme vrijeme(sati, minute);
            Pregled pregled(ime, datum, vrijeme);
            pregledi.RegistrirajPregled(ime, datum, vrijeme);
            j++;
        } while (max_br_pregleda > j);
        std::cout << "Trenutno su registrovani sljedeci pregledi" << std::endl;
        pregledi.IspisiSvePreglede();
        int i;
        do {
            std::cout << "Odaberite jednu od sljedecih opcija" << std::endl; 
            std::cout << "1 - Broj pregleda na datum" << std::endl;
            std::cout << "2 - Najraniji pregled" << std::endl;
            std::cout << "3 - Obrisi pregled pacijenta" << std::endl;           
            std::cout << "4 - Obrisi najraniji pregled" << std::endl;
            std::cout << "5 - Ispisi sve pregleda na datum" << std::endl;
            std::cout << "6 - Ispisi sve preglede" << std::endl;
            std::cout << "7 - Kraj programa" << std::endl;
            std::cin >> i;
            if(i == 1) {
                std::cout << "Unesite dan mjesec i godinu : ";
                int dan, mjesec, godina;
                std::cin >> dan >> mjesec >> godina;
                Datum datum(dan, mjesec, godina);
                std::cout << "Broj pregleda na datum " << dan << " " << mjesec << " " << godina;
                std:: cout << " je: " << pregledi.DajBrojPregledaNaDatum(datum) << std::endl;
            } else if (i == 2) {
              Pregled najraniji = pregledi.DajNajranijiPregled();
              std::cout << "Najraniji pregled je:" << std::endl; 
              najraniji.Ispisi();
              std::cout << std::endl;
            } else if (i == 3) {
                std::string ime;
                std::cout << "Unesite ime pacijenta: ";
                std::cin >> ime;
                int stari = pregledi.DajBrojPregleda();
                pregledi.ObrisiPregledePacijenta(ime);
                std::cout <<"Uspjesno obrisano "<< stari - pregledi.DajBrojPregleda() << " pregleda" << std::endl;
            } else if(i == 4) {
                pregledi.ObrisiNajranijiPregled();
                std::cout << "Najraniji pregled uspjesno obrisan" << std::endl;
            } else if(i == 5) {
                std::cout << "Unesite dan mjesec i godinu : ";
                int dan, mjesec, godina;
                std::cin >> dan >> mjesec >> godina;
                Datum datum(dan, mjesec, godina);
                std::cout << "Pregledi na datum " << dan << " " << mjesec << " " << godina << " su:" << std::endl;
                pregledi.IspisiPregledeNaDatum(datum);
                std::cout << std::endl;
            } else if(i == 6) {
                pregledi.IspisiSvePreglede();
                std::cout << std::endl;
            } else {
                break;
            }
        }while (i != 7);
    }catch(std::range_error e) {
        std::cout << e.what();
    }
    catch(std::domain_error e) {
        std::cout << e.what();
        
    }
	return 0;
}
void Datum::Postavi(int dan, int mjesec, int godina) {
      int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      if((godina % 4 == 0 && godina % 100 != 0) || (godina % 400 == 0)) broj_dana[1]++;
      if(godina < 1 || dan < 1 || mjesec < 1 || mjesec > 12 || dan > broj_dana[mjesec - 1])
         throw std::domain_error("Neispravan datum");
      this->dan = dan; this->mjesec = mjesec; this->godina = godina;
}
void Vrijeme::Postavi(int sati, int minute) {
     if(sati < 0 || sati > 23 || minute < 0 || minute > 59) throw std::domain_error("Neispravno vrijeme");
     this->sati = sati; this->minute = minute;
}
void Pregled::PomjeriDanUnaprijed() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((datum.DajGodinu() % 4 == 0 && datum.DajGodinu() % 100 != 0) || (datum.DajGodinu() % 400 == 0)) broj_dana[1]++;
    int pseudodan(datum.DajDan()), pseudomjesec(datum.DajMjesec()), pseudogodina(datum.DajGodinu()); 
    pseudodan++;
    if(pseudodan > broj_dana[datum.DajMjesec() - 1]) { pseudodan = 1; pseudomjesec++;}
    if(pseudomjesec > 12) { pseudogodina++; pseudomjesec = 1;}
    datum.Postavi(pseudodan, pseudomjesec, pseudogodina);
}
void Pregled::PomjeriDanUnazad() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((datum.DajGodinu() % 4 == 0 && datum.DajGodinu() % 100 != 0) || (datum.DajGodinu() % 400 == 0)) broj_dana[1]++;
    int pseudodan(datum.DajDan()), pseudomjesec(datum.DajMjesec()), pseudogodina(datum.DajGodinu()); 
    pseudodan--;
    if(!pseudodan) {
        if(pseudomjesec - 2 < 0) { pseudodan = 31; pseudomjesec = 12; pseudogodina--;}
        else { pseudodan = broj_dana[pseudomjesec - 2]; pseudomjesec--; }
    }
    datum.Postavi(pseudodan, pseudomjesec, pseudogodina);
}
bool DolaziPrije(const Pregled &p1, const Pregled &p2) {
    if (p1.datum.DajGodinu() < p2.datum.DajGodinu()) return true;
    if (p1.datum.DajMjesec() < p2.datum.DajMjesec() && p1.datum.DajGodinu() == p2.datum.DajGodinu()) return true;
    if (p1.datum.DajDan() < p2.datum.DajDan() && p1.datum.DajMjesec() == p2.datum.DajMjesec() && p1.datum.DajGodinu() == p2.datum.DajGodinu())return true;
    if (p1.vrijeme.DajSate() < p2.vrijeme.DajSate() && p1.datum.DajDan() == p2.datum.DajDan() && p1.datum.DajMjesec() == p2.datum.DajMjesec() && p1.datum.DajGodinu() == p2.datum.DajGodinu()) return true;
    if (p1.vrijeme.DajMinute() < p2.vrijeme.DajMinute() && p1.vrijeme.DajSate() == p2.vrijeme.DajSate() && p1.datum.DajDan() == p2.datum.DajDan() && p1.datum.DajMjesec() == p2.datum.DajMjesec() && p1.datum.DajGodinu() == p2.datum.DajGodinu()) return true;
    return false;
}
Pregledi::~Pregledi() {
    for (int i = 0; i < evidentirani; i++) delete pregledi[i];
    delete[] pregledi;
}
Pregledi::Pregledi(const Pregledi &pregledi): kapacitet(pregledi.kapacitet), evidentirani(pregledi.evidentirani), pregledi(new Pregled*[kapacitet]) {
    for (int i = 0; i < pregledi.kapacitet; i++) this -> pregledi[i] = new Pregled(*pregledi.pregledi[i]);
}
Pregledi::Pregledi(Pregledi &&pregledi): kapacitet(pregledi.kapacitet), evidentirani(pregledi.evidentirani), pregledi(pregledi.pregledi) { pregledi.pregledi =  nullptr;}
Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
    if (pregledi.evidentirani > evidentirani) {
        for (int i = 0; i < evidentirani; i++)  *this -> pregledi[i] = *pregledi.pregledi[i];
        for (int i = evidentirani; i < pregledi.evidentirani; i++) this -> pregledi[i] = new Pregled(*pregledi.pregledi[i]);
    } else {
        for (int i = 0; i < pregledi.evidentirani; i++)  *this -> pregledi[i] = *pregledi.pregledi[i];
        for (int i = pregledi.evidentirani; i < evidentirani; i++) delete this ->pregledi[i];
    }
    evidentirani = pregledi.evidentirani; kapacitet = pregledi.kapacitet;
    return *this;
}
Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    if (&pregledi != this) {
        for (int i = 0; i < evidentirani; i++)  delete this -> pregledi[i];
        delete[] this -> pregledi;
        this -> pregledi = pregledi.pregledi;
        evidentirani = pregledi.evidentirani; kapacitet = pregledi.kapacitet;
        pregledi.pregledi = nullptr; pregledi.evidentirani = 0;
    }
    return *this;
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
        if(evidentirani >= kapacitet) throw std::range_error("Dostingut maksimalni broj pregleda");
        pregledi[evidentirani++] = new Pregled(ime_pacijenta, datum_pregleda, vrijeme_pregleda); 
 }
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda) {
        if(evidentirani >= kapacitet) throw std::range_error("Dostingut maksimalni broj pregleda");
         this -> pregledi[evidentirani++] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
 }
void Pregledi::RegistrirajPregled(Pregled *pregled) {
    int indikator(0);
    for (int i = 0; i < evidentirani; i++)
        if(this -> pregledi[i])
        if((*this -> pregledi[i]).DajImePacijenta() == pregled->DajImePacijenta() && 
        (*this -> pregledi[i]).DajDatumPregleda().DajDan() == pregled->DajDatumPregleda().DajDan() &&
        (*this -> pregledi[i]).DajDatumPregleda().DajMjesec() == pregled->DajDatumPregleda().DajMjesec() &&
        (*this -> pregledi[i]).DajDatumPregleda().DajGodinu() == pregled->DajDatumPregleda().DajGodinu() &&
        (*this -> pregledi[i]).DajVrijemePregleda().DajSate() == pregled->DajVrijemePregleda().DajSate() &&
        (*this -> pregledi[i]).DajVrijemePregleda().DajMinute() == pregled->DajVrijemePregleda().DajMinute()) indikator++;
    if(!indikator) {
        if(evidentirani >= kapacitet) throw std::range_error("Dostingut maksimalni broj pregleda");
         pregledi[evidentirani++] = new Pregled(*pregled);
    }    
} 
int Pregledi::DajBrojPregledaNaDatum(const Datum &datum) const{
    return std::count_if(pregledi, pregledi + evidentirani,[datum] (Pregled *p) { return p->DajDatumPregleda().DajDan() == datum.DajDan()
    && p->DajDatumPregleda().DajMjesec() ==  datum.DajMjesec() && p->DajDatumPregleda().DajGodinu() ==  datum.DajGodinu();});   
}
Pregled &Pregledi::DajNajranijiPregled() {
   if(!evidentirani) throw std::domain_error("Nema registriranih pregleda");
   return (*std::min_element(pregledi, pregledi + evidentirani,[] (Pregled *p, Pregled *p1) {return DolaziPrije(*p, *p1);}))[0];
}
Pregled Pregledi::DajNajranijiPregled() const {
    if(!evidentirani) throw std::domain_error("Nema registriranih pregleda");
    return (*std::min_element(pregledi, pregledi + evidentirani, [] (Pregled *p, Pregled *p1) {return DolaziPrije(*p, *p1);}))[0];
}
void Pregledi::IsprazniKolekciju() {
    if(evidentirani) {
        for (int i = 0; i < evidentirani; i++) delete this -> pregledi[i];
        delete[] pregledi; pregledi = nullptr;
        pregledi = new Pregled*[kapacitet];
        for(int i = 0; i < kapacitet; i++) this -> pregledi[i] = nullptr;
        evidentirani = 0;
    }
}
void Pregledi::ObrisiNajranijiPregled() {
    if(!evidentirani) throw std::range_error("Prazna kolekcija");
    Datum novi(this -> DajNajranijiPregled().DajDatumPregleda());
    Vrijeme novo(this -> DajNajranijiPregled().DajVrijemePregleda());
    for (int i = 0; i < evidentirani; i++) 
        if((*this -> pregledi[i]).DajDatumPregleda().DajDan() == novi.DajDan() && (*this -> pregledi[i]).DajDatumPregleda().DajMjesec() == novi.DajMjesec() &&
        (*this -> pregledi[i]).DajDatumPregleda().DajGodinu() == novi.DajGodinu() && (*this -> pregledi[i]).DajVrijemePregleda().DajSate() == novo.DajSate() &&
        (*this -> pregledi[i]).DajVrijemePregleda().DajMinute() == novo.DajMinute()){ delete this -> pregledi[i];  pregledi[i] = nullptr; break;}
    for (int i = 0; i < evidentirani; i++) {
        if (this -> pregledi[i] == nullptr && i != evidentirani - 1) {
            this -> pregledi[i] = this -> pregledi[i + 1];  this -> pregledi[i + 1] = nullptr;
        }
    } 
        
    this->evidentirani--;
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    bool obriasni = false;
    int stari = this->DajBrojPregleda();
    do {
        stari = this->DajBrojPregleda();
        obriasni = false;
        for (int i = 0; i < evidentirani; i++) 
        if(ime_pacijenta == (*this -> pregledi[i]).DajImePacijenta()) { 
            delete this -> pregledi[i]; this -> pregledi[i] = nullptr;
            obriasni = true;
            break;
        }
         for (int j = 0; j < evidentirani; j++) {
            if (this -> pregledi[j] == nullptr && j != evidentirani - 1) {
                this -> pregledi[j] = this -> pregledi[j + 1];  this -> pregledi[j + 1] = nullptr;
            } 
         }
         if(obriasni) evidentirani--;
    } while(stari != this->DajBrojPregleda());
}

void Pregledi::IspisiPregledeNaDatum(Datum &datum) const {
    if (this) {
        Pregledi eh(this -> DajBrojPregledaNaDatum(datum));
        for (int i = 0; i < evidentirani; i++)
        if(this-> pregledi[i])
        
         if (this -> pregledi[i])
        if ((*this -> pregledi[i]).DajDatumPregleda().DajDan() == datum.DajDan() &&
        (*this -> pregledi[i]).DajDatumPregleda().DajMjesec() == datum.DajMjesec() &&
        (*this -> pregledi[i]).DajDatumPregleda().DajGodinu() == datum.DajGodinu()) eh.RegistrirajPregled(this -> pregledi[i]);
        std::sort(eh.pregledi, eh.pregledi + eh.evidentirani, [] (Pregled *p, Pregled *p1) {return DolaziPrije(*p, *p1);});
        for (int i = 0; i < eh.evidentirani; i++) eh.pregledi[i] -> Ispisi();
        
        
    }   
}


void Pregledi::IspisiSvePreglede() const {
    if(this) {
        Pregledi p(this -> evidentirani);
        p = *this;
        std::sort(p.pregledi, p.pregledi + evidentirani, [] (Pregled *p, Pregled *p1) {return DolaziPrije(*p, *p1);});
        for (int i = 0; i < evidentirani; i++) p.pregledi[i] -> Ispisi();
    }
}




