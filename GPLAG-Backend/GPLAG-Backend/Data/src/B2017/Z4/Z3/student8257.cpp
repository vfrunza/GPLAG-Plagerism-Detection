/B2017/2018: Zadaća 4, Zadatak 3
#include <iostream>
#include <tuple>
#include <utility>
#include <iomanip>
#include <string>
#include <algorithm>
#include <utility>

using std::string;

// DATUM

class Datum {
    int dan,mjesec,godina;
    
  public:
    Datum(int dan, int mjesec, int godina) { Postavi(dan, mjesec, godina); }
    void Postavi(int d, int m, int g);
    std::tuple<int, int, int> Ocitaj() const { return std::make_tuple(dan,mjesec,godina); }
    void Ispisi() const { std::cout << dan << "/" << mjesec << "/" << godina; }
    friend class Pregled;
};

void Datum::Postavi(int d, int m, int g) {
    int broj_dana[12]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(g % 4 == 0 && g % 100 != 0 || g % 400 == 0) broj_dana[1]++;
    if(g < 1 || d < 1 || m < 1 || m > 12 || d > broj_dana[m - 1])
        throw std::domain_error("Neispravan datum!");
    dan = d; mjesec = m; godina = g;

}

// VRIJEME

class Vrijeme {
    int sati,minute;
    static bool DaLiJeIspravno(int h, int m) {
	    return (h>=0 && h<=23 && m>=0 && m<=59);
    }
 public:
    Vrijeme(int sati, int minute) { Postavi(sati, minute); }
    void Postavi(int sati, int minute) {
   		if(!DaLiJeIspravno(sati,minute))
   			throw std::domain_error("Neispravno vrijeme");
   		Vrijeme::sati = sati; Vrijeme::minute = minute; 
   	}
    std::pair<int, int> Ocitaj () const { return {sati,minute}; }
    void Ispisi() const { std::cout<<std::setfill('0')<<std::right<<std::setw(2)<<sati<<":"<<std::setw(2)<<minute<<std::setfill(' ');}
    friend class Pregled;
};

// PREGLED 

class Pregled {
    string ime_pacijenta;
    Datum datum_pregleda;
    Vrijeme vrijeme_pregleda;
  
 public:
    // Konstruktori 
    Pregled(const string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) :
        ime_pacijenta(ime_pacijenta), datum_pregleda(datum_pregleda), vrijeme_pregleda(vrijeme_pregleda) { };

    Pregled(const string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda,
        int godina_pregleda, int sati_pregleda, int minute_pregleda) : 
            ime_pacijenta(ime_pacijenta), datum_pregleda({dan_pregleda,mjesec_pregleda,godina_pregleda}), vrijeme_pregleda({sati_pregleda,minute_pregleda}) {};
    
    // Mutatori 
    void PromijeniPacijenta(const string &ime_pacijenta) { this->ime_pacijenta = ime_pacijenta; }
    void PromijeniDatum(const Datum &novi_datum) { datum_pregleda = novi_datum; }
    void PromijeniVrijeme(const Vrijeme &novo_vrijeme) { vrijeme_pregleda = novo_vrijeme; }
    void PomjeriDanUnaprijed();
    void PomjeriDanUnazad();

    // Inspektori 
    string DajImePacijenta() const { return ime_pacijenta; }
    Datum DajDatumPregleda() const { return datum_pregleda; }
    Vrijeme DajVrijemePregleda() const { return vrijeme_pregleda; }
    void Ispisi() const { 
        std::cout<<std::left<<std::setw(30)<<ime_pacijenta; datum_pregleda.Ispisi(); std::cout<<" "; vrijeme_pregleda.Ispisi();
    }
    static bool DolaziPrije(const Pregled &p1, const Pregled &p2);
};

void Pregled::PomjeriDanUnaprijed() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(datum_pregleda.godina % 4 == 0 && datum_pregleda.godina % 100 != 0 || datum_pregleda.godina % 400 == 0)
        broj_dana[1]++;
    datum_pregleda.dan++;
    if(datum_pregleda.dan > broj_dana[datum_pregleda.mjesec - 1]) datum_pregleda.dan = 1, datum_pregleda.mjesec++;
    if(datum_pregleda.mjesec > 12) datum_pregleda.mjesec = 1, datum_pregleda.godina++;
}
void Pregled::PomjeriDanUnazad() {
    int broj_dana[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(datum_pregleda.godina % 4 == 0 && datum_pregleda.godina % 100 != 0 || datum_pregleda.godina % 400 == 0)
        broj_dana[1]++;
    datum_pregleda.dan--;
    if(datum_pregleda.dan < 1 ) datum_pregleda.mjesec--;
    if(datum_pregleda.mjesec < 1 ) datum_pregleda.mjesec = 12, datum_pregleda.godina--;
    datum_pregleda.dan = broj_dana[datum_pregleda.mjesec];
}
bool Pregled::DolaziPrije(const Pregled &p1, const Pregled &p2) {
    int dan1,dan2,mjesec1,mjesec2,godina1,godina2;
    Vrijeme v1 = p1.vrijeme_pregleda, v2 = p2.vrijeme_pregleda;
    std::tie(dan1,mjesec1,godina1) = p1.datum_pregleda.Ocitaj();
    std::tie(dan2,mjesec2,godina2) = p2.datum_pregleda.Ocitaj();
    
    if(godina1 == godina2) {
        if(mjesec1 == mjesec2) {
            if(dan1==dan2) {
                if(v1.sati == v2.sati) {
                    if(v1.minute == v2.minute)
                        return false ;         // Ako je došlo čak dovde to znači da se termini poklapaju
                    else
                        return v1.minute<v2.minute;
                }
                else 
                    return v1.sati<v2.sati;
            }
            else 
                return dan1<dan2;
        }
        else 
            return mjesec1<mjesec2;
    }
    else
        return godina1<godina2;

}

// PREGLEDI!!


class Pregledi {
    int max_broj_pregleda;
    int broj_evidentiranih;
    Pregled** pregledi;
    
  public:
  
    // Konstruktori
    explicit Pregledi(int max_broj_pregleda) : max_broj_pregleda(max_broj_pregleda) , 
        broj_evidentiranih(0), pregledi(new Pregled*[max_broj_pregleda]{}) {} 
    Pregledi(std::initializer_list<Pregled> spisak_pregleda);
    Pregledi(const Pregledi &pregledi);
    Pregledi(Pregledi &&pregledi);
    
    // Destruktor
    ~Pregledi() { for(int i=0;i<broj_evidentiranih;i++) delete pregledi[i]; delete[] pregledi; }
    
    // Operatori dodjele
    Pregledi &operator =(const Pregledi &pregledi);
    Pregledi &operator =(Pregledi &&pregledi);
    
    // Mutatori
    void RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda);
    void RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda,
            int godina_pregleda, int sati_pregleda, int minute_pregleda);
    void RegistrirajPregled(Pregled *pregled);
    void IsprazniKolekciju() { for(int i=0;i<broj_evidentiranih;i++) {delete pregledi[i]; pregledi[i] = nullptr; } }
    void ObrisiNajranijiPregled();
    void ObrisiPregledePacijenta(const std::string &ime_pacijenta);
    
    
    // Inspektori
    int DajBrojPregleda() const { return broj_evidentiranih; }
    int DajBrojPregledaNaDatum(const Datum &datum) const {
        return std::count_if(pregledi, pregledi+broj_evidentiranih, [datum](Pregled* p)->bool {
            return p->DajDatumPregleda().Ocitaj() == datum.Ocitaj();
        });
    }
    Pregled &DajNajranijiPregled();
    Pregled DajNajranijiPregled() const;
    void IspisiPregledeNaDatum(const Datum &datum) const;
    void IspisiSvePreglede() const;
    
    
    
};

Pregledi::Pregledi(std::initializer_list<Pregled> spisak_pregleda) : max_broj_pregleda(spisak_pregleda.size()), 
        broj_evidentiranih(0) , pregledi(new Pregled*[spisak_pregleda.size()]{}) {
            try {
                auto it = spisak_pregleda.begin();
                for(int i=0;i<spisak_pregleda.size();i++) {
                    pregledi[i] = new Pregled(*it++);
                }
            }
            catch(...) {
                for(int i=0;i<spisak_pregleda.size();i++) delete pregledi[i];
                delete[] pregledi;
                throw;
            }
           
        }
    
    // Kopirajuci konstruktor
Pregledi::Pregledi(const Pregledi &pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda),   
    broj_evidentiranih(pregledi.broj_evidentiranih) , pregledi(new Pregled*[max_broj_pregleda]{}) {
        try {
            for(int i=0;i<pregledi.broj_evidentiranih;i++) 
                this->pregledi[i] = new Pregled(*(pregledi.pregledi[i]));
        }
        catch(...) {
            for(int i=0;i<pregledi.broj_evidentiranih;i++) delete this->pregledi[i];
            delete[] this->pregledi;
            throw;
        }
}
// Pomjerajuci konstruktor
Pregledi::Pregledi(Pregledi &&pregledi) : max_broj_pregleda(pregledi.max_broj_pregleda),
    broj_evidentiranih(pregledi.broj_evidentiranih) , pregledi(pregledi.pregledi) {
        pregledi.broj_evidentiranih = 0; pregledi.pregledi = nullptr; 
    }
   
// Kopirajuci operator dodjele 
Pregledi &Pregledi::operator =(const Pregledi &pregledi) {
    Pregled** novi_prostor = new Pregled*[pregledi.max_broj_pregleda]{};
    for(int i=0;i<pregledi.broj_evidentiranih;i++) 
        novi_prostor[i] = new Pregled(*(pregledi.pregledi[i]));
        
    for(int i=0;i<max_broj_pregleda;i++) delete this->pregledi[i];
    delete[] this->pregledi;
    
    max_broj_pregleda = pregledi.max_broj_pregleda; broj_evidentiranih = pregledi.broj_evidentiranih;
    this->pregledi = novi_prostor;
    return *this;
}

// Pomjerajuci operator dodjele
Pregledi &Pregledi::operator =(Pregledi &&pregledi) {
    for(int i=0;i<broj_evidentiranih;i++) delete this->pregledi[i];
    delete[] this->pregledi;
    broj_evidentiranih = pregledi.broj_evidentiranih;
    max_broj_pregleda = pregledi.max_broj_pregleda;
    this->pregledi = pregledi.pregledi;  pregledi.pregledi = nullptr; 
    pregledi.broj_evidentiranih = 0;
    return *this;
}

void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta,const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda) {
    if(broj_evidentiranih>=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_evidentiranih++] = new Pregled(ime_pacijenta,datum_pregleda,vrijeme_pregleda);
}
void Pregledi::RegistrirajPregled(const std::string &ime_pacijenta, int dan_pregleda,int mjesec_pregleda, 
    int godina_pregleda, int sati_pregleda,int minute_pregleda)  {
        if(broj_evidentiranih>=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
        pregledi[broj_evidentiranih++] = new Pregled(ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda);
    }
void Pregledi::RegistrirajPregled(Pregled *pregled) {
    if(broj_evidentiranih>=max_broj_pregleda) throw std::range_error("Dostignut maksimalni broj pregleda");
    pregledi[broj_evidentiranih++] = pregled;
} 

Pregled &Pregledi::DajNajranijiPregled() {
    if(broj_evidentiranih<=0) throw std::domain_error("Nema registriranih");
    return **(std::min_element(pregledi, pregledi+broj_evidentiranih, [](Pregled* p1, Pregled* p2)->bool{
        return Pregled::DolaziPrije(*p1,*p2);
    }));
}
Pregled Pregledi::DajNajranijiPregled() const {
    if(broj_evidentiranih<=0) throw std::domain_error("Nema registriranih");
        return **(std::min_element(pregledi, pregledi+broj_evidentiranih, [](Pregled* p1, Pregled* p2)->bool{
            return Pregled::DolaziPrije(*p1,*p2);
        }));
}
void Pregledi::ObrisiNajranijiPregled() {
    if(broj_evidentiranih<=0) throw std::range_error("Prazna kolekcija");
    auto p_min = std::min_element(pregledi, pregledi+broj_evidentiranih, [](Pregled* p1, Pregled* p2)->bool{
        return Pregled::DolaziPrije(*p1,*p2);
    });
    delete *p_min; *p_min = nullptr;
    for(auto p = p_min; p<pregledi+broj_evidentiranih-1; p++) {
        std::swap(*p, *(p+1));          // Pomjeram sve elemente unazad da popunim rupu kad se izbrise pregled
    }
    broj_evidentiranih--;
}
void Pregledi::ObrisiPregledePacijenta(const std::string &ime_pacijenta) {
    for(int i=0;i<broj_evidentiranih;i++) {
        if(pregledi[i]==nullptr)
            continue;
        if(pregledi[i]->DajImePacijenta() == ime_pacijenta) {
            delete pregledi[i]; pregledi[i] = nullptr;
            for(auto p = &pregledi[i]; p<pregledi+broj_evidentiranih-1; p++) {
                std::swap(*p, *(p+1));          // Pomjeram sve elemente unazad da popunim rupu kad se izbrise pregled
            }
            broj_evidentiranih--;
            i--;
        }
    }
}
void Pregledi::IspisiPregledeNaDatum(const Datum &datum) const {
    auto kopijaPregleda = *this;
    std::sort(kopijaPregleda.pregledi, kopijaPregleda.pregledi+broj_evidentiranih, [](Pregled* p1, Pregled* p2){
       return Pregled::DolaziPrije(*p1,*p2); 
    });
    std::for_each(kopijaPregleda.pregledi , kopijaPregleda.pregledi+broj_evidentiranih, [datum](Pregled* p)->void {
        if(p->DajDatumPregleda().Ocitaj()== datum.Ocitaj()) {
            p->Ispisi();
            std::cout<<std::endl;
        }
    });
}
void Pregledi::IspisiSvePreglede() const {
    auto kopijaPregleda = *this;
    std::sort(kopijaPregleda.pregledi, kopijaPregleda.pregledi+broj_evidentiranih, [](Pregled* p1, Pregled* p2){
       return Pregled::DolaziPrije(*p1,*p2); 
    });
    for(int i=0;i<broj_evidentiranih;i++) {
        kopijaPregleda.pregledi[i]->Ispisi();
        std::cout<<std::endl;
    }
}


int main ()
{
    
    std::cout<<"Unesite maksimalan broj pregleda: ";
    int n;
    std::cin>>n;
    Pregledi pregledi(n);
    for(int i=0;i<n;i++) {
        std::cin.ignore(10000,'\n');
        std::cout<<"Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: ";
        string ime;
        std::getline(std::cin, ime);
        if(ime=="kraj") break;
        std::cout<<"Unesite dan mjesec i godinu pregleda: ";
        int d,m,g;
        std::cin>>d>>m>>g;
        std::cout<<"Unesite sate i minute pregleda: ";
        int sati,minute;
        std::cin>>sati>>minute;
        pregledi.RegistrirajPregled(ime,d,m,g,sati,minute);
    }
    std::cout<<"Trenutno su registrovani sljedeci pregledi\n";
    pregledi.IspisiSvePreglede();
    int izbor=0;
    while(true) {
        std::cout<<"Odaberite jednu od sljedecih opcija\n";
        std::cout<<"1 - Broj pregleda na datum\n"
            <<"2 - Najraniji pregled\n"
            <<"3 - Obrisi pregled pacijenta\n"
            <<"4 - Obrisi najraniji pregled\n"
            <<"5 - Ispisi sve pregleda na datum\n"
            <<"6 - Ispisi sve preglede\n"
            <<"7 - Kraj programa\n";
        std::cin>>izbor;
        if(izbor==1) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int dan,mjes,god; std::cin>>dan>>mjes>>god;
            std::cout<<"Broj pregleda na datum "<<dan<<" "<<
            mjes<<" "<<god<<" je: "<<pregledi.DajBrojPregledaNaDatum({dan,mjes,god})<<"\n";
        }
        else if(izbor==2) {
            std::cout<<"Najraniji pregled je:\n";
            pregledi.DajNajranijiPregled().Ispisi();
            std::cout<<"\n";
        }
        else if(izbor==3) {
            int brojPrijeBrisanja = pregledi.DajBrojPregleda();
            std::cout<<"Unesite ime pacijenta: ";
            string ime;
            std::cin.ignore(10000,'\n');
            std::getline(std::cin, ime);
            pregledi.ObrisiPregledePacijenta(ime);
            std::cout<<"Uspjesno obrisano "<<brojPrijeBrisanja-pregledi.DajBrojPregleda()<<" pregleda\n";
        }
        else if(izbor==4) {
            pregledi.ObrisiNajranijiPregled();
            std::cout<<"Najraniji pregled uspjesno obrisan\n";
        }
        else if(izbor==5) {
            std::cout<<"Unesite dan mjesec i godinu : ";
            int dan,mjes,god; std::cin>>dan>>mjes>>god;
            std::cout<<"Pregledi na datum 18 12 2018 su:\n";
            pregledi.IspisiPregledeNaDatum({dan,mjes,god});
        }
        else if(izbor==6) {
            pregledi.IspisiSvePreglede();
        }
        else 
            break;
    }
	return 0;
}
